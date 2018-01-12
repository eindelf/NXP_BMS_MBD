/***************************************************************************************************
* SF Motors Confidential – Copyright [2017], all rights reserved.
* Author: deepak.agarwal@sfmotors.com
* Date: 2017-06-28
* Description: BMU interface and data collection (LTC6811-1)
***************************************************************************************************/

#include "BMU_Driver.h"
#include "DMA.h"
#include <stdbool.h>

// Macros and variable definitions
#define BMU_RESET		1
#define BMU_INIT		2
#define BMU_CONFIG		3
#define BMU_NORMAL		4
#define BMU_CONVERT     5
#define BMU_MEASURE		6

#define DSPI_PUSHR_CONT_EN_BITMASK  0x80000000
#define DSPI_PUSHR_EOQ_BITMASK  	0x08000000
#define DSPI_PUSHR_CONT_DIS_BITMASK 0x7FFFFFFF
#define DSPI_PUSHR_CS6_BITMASK      0x00400000
#define DSPI_PUSHR_CS2_BITMASK      0x00010000
#define DSPI_PUSHR_CS1_BITMASK      0x00020000

#define CMD_LEN         2

uint8_t bmuState = BMU_RESET;
uint8_t var1 = 1;
uint8_t spiDataTx = 0;

static volatile DSPI_tag* DSPI[]= { &DSPI_1, &DSPI_0, &DSPI_2 };

// Function prototypes
static void SPI_Send_Message(uint8_t *data , uint8_t len);
static void SPI_WakeUp(int SPICh, int CS);
static void SPI_Tx_Message(int SPICh, int CS, uint8_t *data , uint8_t len, uint16_t delay, uint8_t EndCs);
static void SPI_Tx_Dummy(int SPICh, int CS, uint8_t *data, uint8_t len, uint8_t *rcv_data, uint8_t rcv_len, uint16_t delay, uint8_t EndCs);
static uint16_t Calculate_PEC15(uint8_t *data , uint8_t len);
static void Command_LTC(uint8_t tx_cmd[2]);
//extern void SPI_Read_Master_Onecell(uint32_t* ret);
//extern void SPI_Read_Master_PEC(uint32_t* ret);

uint16_t IsrCount = 0;



/******************************************************************************
*   Function:  dspi_564xl_read_master
@brief    Reads the data from DSPI module  - master. 
@details   Reads the data from DSPI module
    
@param[in]     dspi_num     DSPI number
   
@return Data from DSPI module
*/
void SPI_Read_Master_Onecell(unsigned int * ret){
	uint16_t ret1 = 0U;
	uint16_t ret2 = 0U;
	//uint32_t* ret = 0U;
	//ret = (uint32_t*)malloc(sizeof(uint32_t));

	while (DSPI[0]->SR.B.RFDF != 1){}                /* Wait for Receive FIFO Drain Flag = 1 */
	ret1 = (uint16_t)DSPI[0]->POPR.R;                 /* Read data received by master SPI */
	//while (DSPI[0]->SR.B.RFDF != 1){}                /* Wait for Receive FIFO Drain Flag = 1 */
	//ret2 = (uint16_t)DSPI[0]->POPR.R;                 /* Read data received by master SPI */
	//ret2 = 1;                 /* Read data received by master SPI */
	
	ret[0] = (((unsigned int)ret1)<<16);
	//ret[0] = (((unsigned int)ret1)<<16) | ((unsigned int)ret2);
}

void SPI_Read_Master_PEC(unsigned int* ret){
	uint16_t ret1 = 0U;
	uint16_t ret2 = 0U;
	//uint32_t* ret = 0U;
	//ret = (uint32_t*)malloc(sizeof(uint32_t));
	
	//while (DSPI[0]->SR.B.RFDF != 1){}                /* Wait for Receive FIFO Drain Flag = 1 */
	//ret1 = (uint16_t)DSPI[0]->POPR.R;                 /* Read data received by master SPI */
	//while (DSPI[0]->SR.B.RFDF != 1){}                /* Wait for Receive FIFO Drain Flag = 1 */
	//ret2 = (uint16_t)DSPI[0]->POPR.R;                 /* Read data received by master SPI */
	
	//ret[0] = (((unsigned int)ret1)<<16) | ((unsigned int)ret2);
	
	DSPI[0]->SR.R = 0x00020000;                      /* Clear RDRF flags*/
}




// Function implementation
/******************************************************************************
 * Function name:   SPI_Send_Message
 *
 * Inputs:          uint8_t *data - pointer to data
 *                  uint8_t len - number of bytes to transmit
 *
 * Outputs:         None
 *
 * Description:     Transmits specified number of bytes with continuous
 *                  chip select
 *****************************************************************************/
static void SPI_Send_Message(uint8_t *data , uint8_t len)
{
    DSPI_PUSHR_32B_tag pushr;
    uint8_t i;
    
    pushr.R = 0U;
    
    // Keep chip select enabled
    for(i = 0; i < len-1; i++)
    {
        pushr.B.TXDATA = data[i];
        pushr.R |= DSPI_PUSHR_CS6_BITMASK;
        pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
        DSPI[0]->PUSHR.R = pushr.R;
    }
    
    // Disable chip select after last data byte
    pushr.B.TXDATA = data[i];
    pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
    DSPI[0]->PUSHR.R = pushr.R;
    
    // Indicate end of queue
    DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
}
#define CLR_RXF_FLAG (0x00000400)

/*****************************************************************************/
static void SPI_WakeUp(int SPICh, int CS)
{
    DSPI_PUSHR_32B_tag pushr;
    uint8_t i;
	volatile int ii=0;
	int j=0;
    
    pushr.R = 0U;    
    // Keep chip select enabled
	if (CS == 0) pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	else pushr.R |= DSPI_PUSHR_CS2_BITMASK;
	
	for(ii=0;ii<500;ii++);
    // Disable chip select after last data byte
    pushr.B.TXDATA = 0;
	if (CS == 0) pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	else pushr.R |= DSPI_PUSHR_CS2_BITMASK;	//pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
    pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
    DSPI[0]->PUSHR.R = pushr.R;
    // Indicate end of queue
    DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
    while (DSPI[0]->SR.B.TCF != 1);
	for(ii=0;ii<1800*2;ii++){
		//j = i+1;
	}
}

static void SPI_Tx_Message(int SPICh, int CS, uint8_t *data , uint8_t len, uint16_t delay, uint8_t EndCs)
{
    DSPI_PUSHR_32B_tag pushr;
    uint8_t i;
	volatile uint16_t ii=0;
	//uint16_t j=0;
    pushr.R = 0U;
    
    // Keep chip select enabled
	if (CS == 0) pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	else pushr.R |= DSPI_PUSHR_CS2_BITMASK;	
	
	//for(ii=0;ii<1800;ii++);
    for(i = 0; i < len-1; i++)
    {
        pushr.B.TXDATA = data[i];
        pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
        DSPI[0]->PUSHR.R = pushr.R;
        // Indicate end of queue
        //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
		for(ii=0;ii<delay;ii++);
        while (DSPI[0]->SR.B.TCF != 1);
    }
    
    // Disable chip select after last data byte
    pushr.B.TXDATA = data[i];
	if (CS == 0) pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	else pushr.R |= DSPI_PUSHR_CS2_BITMASK;	
	
	if (EndCs == 1) pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
	//else pushr.R |= (DSPI_PUSHR_CONT_EN_BITMASK | DSPI_PUSHR_EOQ_BITMASK);
	else pushr.R |= (DSPI_PUSHR_CONT_EN_BITMASK);
	
    DSPI[0]->PUSHR.R = pushr.R;
	for(ii=0;ii<delay;ii++);
    // Indicate end of queue
    //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
	//for(ii=0;ii<500;ii++);
    while (DSPI[0]->SR.B.TCF != 1);
}


static void SPI_Tx_Dummy(int SPICh, int CS, uint8_t *data, uint8_t len, uint8_t *rcv_data, uint8_t rcv_len, uint16_t delay, uint8_t EndCs)
{
    DSPI_PUSHR_32B_tag pushr;
    uint8_t i;
	uint16_t temp;
	volatile uint16_t ii=0;
	//uint16_t j=0;
    
    pushr.R = 0U;
    DSPI[0]->MCR.R |= CLR_RXF_FLAG;
    // Keep chip select enabled
	if (CS == 0) pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	else pushr.R |= DSPI_PUSHR_CS2_BITMASK;	
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;	
		
	//DSPI[0]->SR.R = 0x00020000;                      /* Clear RDRF flags*/
	//while (DSPI[0]->SR.B.RFDF != 1){rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;} 
//	DSPI[0]->SR.R = 0x00020000;                      /* Clear RDRF flags*/
	
	//for(ii=0;ii<1800;ii++);
    for(i = 0; i < len-1; i++)
    {
        pushr.B.TXDATA = data[i];
        pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
		DSPI[0]->MCR.R |= CLR_RXF_FLAG;
        DSPI[0]->PUSHR.R = pushr.R;
        // Indicate end of queue
        //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE | DSPI_ISR_RFDF_RE;
		for(ii=0;ii<delay;ii++);
        while (DSPI[0]->SR.B.TCF != 1);
		while (DSPI[0]->SR.B.RFDF != 1 || DSPI[0]->SR.B.RXCTR == 0){}                /* Wait for Receive FIFO Drain Flag = 1 */
			//rcv_data[i] = (uint16_t)DSPI[0]->SR.B.RXCTR;                 /* Read data received by master SPI */
			//temp = DSPI[0]->POPR.R;                 /* Read data received by master SPI */
			rcv_data[i] = (uint16_t)DSPI[0]->POPR.R;                 /* Read data received by master SPI */
		DSPI[0]->SR.R = 0x00020000;                      /* Clear RDRF flags*/	
    }
    
    // Disable chip select after last data byte
    pushr.B.TXDATA = data[len-1];
	if (CS == 0) pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	else pushr.R |= DSPI_PUSHR_CS2_BITMASK;	
	
	if (EndCs == 1) pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
	else pushr.R |= (DSPI_PUSHR_CONT_EN_BITMASK);
    DSPI[0]->MCR.R |= CLR_RXF_FLAG;
	DSPI[0]->PUSHR.R = pushr.R;
    // Indicate end of queue
    //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE | DSPI_ISR_RFDF_RE;
	
    while (DSPI[0]->SR.B.TCF != 1);
	while (DSPI[0]->SR.B.RFDF != 1){}                /* Wait for Receive FIFO Drain Flag = 1 */
		rcv_data[len-1] = (uint16_t)DSPI[0]->POPR.R;                 /* Read data received by master SPI */
		
	for(ii=0;ii<1500;ii++);
		
}

static void SPI_WakeUp_ch1(int SPICh)
{
    DSPI_PUSHR_32B_tag pushr;
    uint8_t i;
	volatile int ii=0;
	int j=0;
    
    pushr.R = 0U;    
    // Keep chip select enabled
    pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	
	for(ii=0;ii<500;ii++);
    // Disable chip select after last data byte
    pushr.B.TXDATA = 0;
    pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	//pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
    pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
    DSPI[1]->PUSHR.R = pushr.R;
    // Indicate end of queue
    DSPI[1]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
    while (DSPI[1]->SR.B.TCF != 1);
	for(ii=0;ii<1800*2;ii++){
		//j = i+1;
	}
}

static void SPI_Tx_Message_ch1(int SPICh, uint8_t *data , uint8_t len, uint16_t delay, uint8_t EndCs)
{
    DSPI_PUSHR_32B_tag pushr;
    uint8_t i;
	volatile uint16_t ii=0;
	//uint16_t j=0;
    pushr.R = 0U;
    
    // Keep chip select enabled
    pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	//for(ii=0;ii<1800;ii++);
    for(i = 0; i < len-1; i++)
    {
        pushr.B.TXDATA = data[i];
        pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
        DSPI[1]->PUSHR.R = pushr.R;
        // Indicate end of queue
        //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
		for(ii=0;ii<delay;ii++);
        while (DSPI[1]->SR.B.TCF != 1);
    }
    
    // Disable chip select after last data byte
    pushr.B.TXDATA = data[i];
    pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	if (EndCs == 1) pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
	//else pushr.R |= (DSPI_PUSHR_CONT_EN_BITMASK | DSPI_PUSHR_EOQ_BITMASK);
	else pushr.R |= (DSPI_PUSHR_CONT_EN_BITMASK);
	
    DSPI[1]->PUSHR.R = pushr.R;
	for(ii=0;ii<delay;ii++);
    // Indicate end of queue
    //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
	//for(ii=0;ii<500;ii++);
    while (DSPI[1]->SR.B.TCF != 1);
}


static void SPI_Tx_Dummy_ch1(int SPICh, uint8_t *data, uint8_t len, uint8_t *rcv_data, uint8_t rcv_len, uint16_t delay, uint8_t EndCs)
{
    DSPI_PUSHR_32B_tag pushr;
    uint8_t i;
	uint16_t temp;
	volatile uint16_t ii=0;
	//uint16_t j=0;
    
    pushr.R = 0U;
    DSPI[1]->MCR.R |= CLR_RXF_FLAG;
    // Keep chip select enabled
    pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;
	//rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;	
		
	//DSPI[0]->SR.R = 0x00020000;                      /* Clear RDRF flags*/
	//while (DSPI[0]->SR.B.RFDF != 1){rcv_data[0] = (uint16_t)DSPI[0]->POPR.R;} 
//	DSPI[0]->SR.R = 0x00020000;                      /* Clear RDRF flags*/
	
	//for(ii=0;ii<1800;ii++);
    for(i = 0; i < len-1; i++)
    {
        pushr.B.TXDATA = data[i];
        pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
		DSPI[1]->MCR.R |= CLR_RXF_FLAG;
        DSPI[1]->PUSHR.R = pushr.R;
        // Indicate end of queue
        //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE | DSPI_ISR_RFDF_RE;
		for(ii=0;ii<delay;ii++);
        while (DSPI[1]->SR.B.TCF != 1);
		while (DSPI[1]->SR.B.RFDF != 1 || DSPI[1]->SR.B.RXCTR == 0){}                /* Wait for Receive FIFO Drain Flag = 1 */
			//rcv_data[i] = (uint16_t)DSPI[0]->SR.B.RXCTR;                 /* Read data received by master SPI */
			//temp = DSPI[0]->POPR.R;                 /* Read data received by master SPI */
			rcv_data[i] = (uint16_t)DSPI[1]->POPR.R;                 /* Read data received by master SPI */
		DSPI[1]->SR.R = 0x00020000;                      /* Clear RDRF flags*/	
    }
    
    // Disable chip select after last data byte
    pushr.B.TXDATA = data[len-1];
    pushr.R |= DSPI_PUSHR_CS1_BITMASK;
	if (EndCs == 1) pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
	else pushr.R |= (DSPI_PUSHR_CONT_EN_BITMASK);
    DSPI[1]->MCR.R |= CLR_RXF_FLAG;
	DSPI[1]->PUSHR.R = pushr.R;
    // Indicate end of queue
    //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE | DSPI_ISR_RFDF_RE;
	
    while (DSPI[1]->SR.B.TCF != 1);
	while (DSPI[1]->SR.B.RFDF != 1){}                /* Wait for Receive FIFO Drain Flag = 1 */
		rcv_data[len-1] = (uint16_t)DSPI[1]->POPR.R;                 /* Read data received by master SPI */
		
	for(ii=0;ii<1500;ii++);
		
}


/******************************************************************************
 * Function name:   Command_LTC
 *
 * Inputs:
 *
 * Outputs:         16 bit PEC
 *
 * Description:     Calculate PEC based on input data
 *****************************************************************************/
static void Command_LTC(uint8_t tx_cmd[2])
{
  uint8_t cmd[4];
  uint16_t cmd_pec;

  cmd[0] = tx_cmd[0];
  cmd[1] =  tx_cmd[1];
  cmd_pec = Calculate_PEC15(cmd, CMD_LEN);
  cmd[2] = (uint8_t)(cmd_pec >> 8);
  cmd[3] = (uint8_t)(cmd_pec);
  
  SPI_Send_Message(cmd, 4);
}

/******************************************************************************
 * Function name:   Calculate_PEC15
 *
 * Inputs:          uint8_t *data - pointer to data
 *                  uint8_t len - number of data bytes
 *
 * Outputs:         16 bit PEC
 *
 * Description:     Calculate PEC based on input data
 *****************************************************************************/
static uint16_t Calculate_PEC15(uint8_t *data, uint8_t len)
{
    uint16_t rem, addr;
    uint8_t i;
    
    // PEC Seed
    rem = 16;
    
    for (i = 0; i < len; i++)
    {
        addr = ((rem >> 7) ^ data[i]) & 0xFF; //calculate PEC table address
        rem = (rem << 8 ) ^ PEC15Table[addr];
        rem &= 0xFFFF;
    }
    return ((rem << 1) & 0xFFFF);
}

void Calculate_PEC15_SFun(uint8_t *data, uint8_t *len, uint16_t *res)
{
    uint16_t rem, addr;
    uint8_t i;	
	int lenn = len[0];
    
    // PEC Seed
    rem = 16;
    
    for (i = 0; i < lenn; i++)
    {
        addr = ((rem >> 7) ^ data[i]) & 0xFF; //calculate PEC table address
        rem = (rem << 8 ) ^ PEC15Table[addr];
        rem &= 0xFFFF;
    }
	
    res[0] = ((rem << 1) & 0xFFFF);
}

/******************************************************************************
 * Function name:   BMU_Process
 *
 * Inputs:          None
 *
 * Outputs:         None
 *
 * Description:     BMU state machine
 *****************************************************************************/
void BMU_Process(const uint8_t *CMD32, uint8_t *rcv_data, uint8_t *PecChk)
{
    static uint8_t BMUcmd[2] = {0, 0};
	uint8_t pec16_rcv_8[2];
    static uint16_t count = 0;
    uint8_t i, Command[12];
	uint16_t pec16,pec16_rcv,rcv_dly;
	volatile int ii;
    
	switch(bmuState)
    {
        case BMU_RESET:
        {
            // PEC15_Table_Init();
            bmuState = BMU_INIT;
            break;
        }
        case BMU_INIT:
        {
            
            bmuState = BMU_CONFIG;
            break;
        }
        case BMU_CONFIG:
        {
            
            bmuState = BMU_NORMAL;
            break;
        }
        case BMU_CONVERT:
        {
            
            bmuState = BMU_NORMAL;
            break;
        }
        case BMU_MEASURE:
        {
            
            bmuState = BMU_NORMAL;
            break;
        }
        case BMU_NORMAL:
        {
            // count++;
            // if(count > 3000)
            // {
                // count = 0;
                // BMUcmd[0]++;
            // }

            
            for(i = 0; i < 12; i++)
            {
                Command[i] = 0;
            }			

			// ADC cell voltage conversion
//			Command[0] = 0x00;
#define CS0 0
#define CS1 1

			SPI_WakeUp(0,CS0);
			
			Command[0] = CMD32[0];
			Command[1] = CMD32[1];
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message(0,CS0, Command, 4,300, 0);
			
			for(ii=0;ii<1500;ii++);
			//SPI_Tx_Message(&Command[4], 8,500, 1);
            // Command_LTC(BMUcmd) Cell voltage (VC1-VC3);
            for(i = 0; i < 12; i++){ Command[i] = 0; }			
			SPI_WakeUp(0,CS0);
			Command[0] = CMD32[2];
			Command[1] = CMD32[3];
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message(0,CS0, Command, 4,300, 0);			
			for(ii=0;ii<300;ii++);
			
			rcv_dly = 100;
			SPI_Tx_Dummy(0,CS0, &Command[4], 8, rcv_data, 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);
			// 2 cell group
			SPI_Tx_Dummy(0,CS0, &Command[4], 8, &rcv_data[8], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[8],6);
			PecChk[2] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[3] = (uint8_t)(pec16_rcv&0xFF);
			// 3 cell group
			SPI_Tx_Dummy(0,CS0, &Command[4], 8, &rcv_data[16], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[16],6);
			PecChk[4] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[5] = (uint8_t)(pec16_rcv&0xFF);
			// 4 cell group
			SPI_Tx_Dummy(0,CS0, &Command[4], 8, &rcv_data[24], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[24],6);
			PecChk[6] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[7] = (uint8_t)(pec16_rcv&0xFF);
			// 5 cell group
			SPI_Tx_Dummy(0,CS0, &Command[4], 8, &rcv_data[32], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[32],6);
			PecChk[8] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[9] = (uint8_t)(pec16_rcv&0xFF);
			// 6 cell group
			SPI_Tx_Dummy(0,CS0, &Command[4], 8, &rcv_data[40], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[40],6);
			PecChk[10] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[11] = (uint8_t)(pec16_rcv&0xFF);
			// 7 cell group
			SPI_Tx_Dummy(0,CS0, &Command[4], 8, &rcv_data[48], 8, rcv_dly, 1);
			pec16_rcv = Calculate_PEC15(&rcv_data[48],6);
			PecChk[12] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[13] = (uint8_t)(pec16_rcv&0xFF);
			
			
			
			
			SPI_WakeUp(0,CS1);
			
			Command[0] = CMD32[0];
			Command[1] = CMD32[1];
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message(0,CS1, Command, 4,300, 0);
			
			for(ii=0;ii<1500;ii++);
			//SPI_Tx_Message(&Command[4], 8,500, 1);
            // Command_LTC(BMUcmd) Cell voltage (VC1-VC3);
            for(i = 0; i < 12; i++){ Command[i] = 0; }			
			SPI_WakeUp(0,CS1);
			Command[0] = CMD32[2];
			Command[1] = CMD32[3];
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message(0,CS1, Command, 4,300, 0);			
			for(ii=0;ii<300;ii++);
			
			rcv_dly = 100;
			SPI_Tx_Dummy(0,CS1, &Command[4], 8, &rcv_data[56], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[56],6);
			PecChk[14] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[15] = (uint8_t)(pec16_rcv&0xFF);
			// 2 cell group
			SPI_Tx_Dummy(0,CS1, &Command[4], 8, &rcv_data[64], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[64],6);
			PecChk[16] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[17] = (uint8_t)(pec16_rcv&0xFF);
			// 3 cell group
			SPI_Tx_Dummy(0,CS1, &Command[4], 8, &rcv_data[72], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[72],6);
			PecChk[18] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[19] = (uint8_t)(pec16_rcv&0xFF);
			// 4 cell group
			SPI_Tx_Dummy(0,CS1, &Command[4], 8, &rcv_data[80], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[80],6);
			PecChk[20] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[21] = (uint8_t)(pec16_rcv&0xFF);
			// 5 cell group
			SPI_Tx_Dummy(0,CS1, &Command[4], 8, &rcv_data[88], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[88],6);
			PecChk[22] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[23] = (uint8_t)(pec16_rcv&0xFF);
			// 6 cell group
			SPI_Tx_Dummy(0,CS1, &Command[4], 8, &rcv_data[96], 8, rcv_dly, 1);
			pec16_rcv = Calculate_PEC15(&rcv_data[96],6);
			PecChk[24] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[25] = (uint8_t)(pec16_rcv&0xFF);

			
			
			
/*             // Command_LTC(BMUcmd) Cell voltage (VC4-VC6);
            for(i = 0; i < 12; i++){ Command[i] = 0; }			
			Command[0] = 0x00;
			SPI_WakeUp();
			Command[0] = 0x00;
			Command[1] = 0x06;
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message(Command, 4,1800, 0);			
			for(ii=0;ii<500;ii++);
			SPI_Tx_Dummy(&Command[4], 8, rcv_data, 8, 500, 0);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);
			// Second Cell
			//for(ii=0;ii<500;ii++);
			SPI_Tx_Dummy(&Command[4], 8, rcv_data, 8, 500, 1);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);
			
            // Command_LTC(BMUcmd) Cell voltage (VC7-VC9);
            for(i = 0; i < 12; i++){ Command[i] = 0; }			
			Command[0] = 0x00;
			SPI_WakeUp();
			Command[0] = 0x00;
			Command[1] = 0x08;
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message(Command, 4,1800, 0);			
			for(ii=0;ii<500;ii++);
			SPI_Tx_Dummy(&Command[4], 8, rcv_data, 8, 500, 0);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);
			// Second Cell
			//for(ii=0;ii<500;ii++);
			SPI_Tx_Dummy(&Command[4], 8, rcv_data, 8, 500, 1);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);

			
			
		
			
			// ADC GPIO conversion
			Command[0] = 0x00;
			SPI_WakeUp();				
			Command[0] = 0x04;
			Command[1] = 0x60;
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);
            SPI_Tx_Message(Command, 4,1800, 0);
			for(ii=0;ii<2500;ii++);

            // Command_LTC(BMUcmd) Cell voltage (GPIO1-GPIO3);
            for(i = 0; i < 12; i++){ Command[i] = 0; }			
			Command[0] = 0x00;
			SPI_WakeUp();
			Command[0] = 0x00;
			Command[1] = 0x0C;
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message(Command, 4,1800, 0);			
			for(ii=0;ii<500;ii++);
			SPI_Tx_Dummy(&Command[4], 8, rcv_data, 8, 500, 0);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);
			// Second Cell
			//for(ii=0;ii<500;ii++);
			SPI_Tx_Dummy(&Command[4], 8, rcv_data, 8, 500, 1);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);
			
			// Command_LTC(BMUcmd) Cell voltage (GPIO4-GPIO5, VREF);
            for(i = 0; i < 12; i++){ Command[i] = 0; }			
			Command[0] = 0x00;
			SPI_WakeUp();
			Command[0] = 0x00;
			Command[1] = 0x0E;
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message(Command, 4,1800, 0);			
			for(ii=0;ii<500;ii++);
			SPI_Tx_Dummy(&Command[4], 8, rcv_data, 8, 500, 0);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);
			// Second Cell
			//for(ii=0;ii<500;ii++);
			SPI_Tx_Dummy(&Command[4], 8, rcv_data, 8, 500, 1);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);			
 */			
			
			//pec16_rcv_8[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			//pec16_rcv_8[1] = (uint8_t)(pec16_rcv&0xFF);				
			//if(pec16_rcv_8[0] == rcv_data[6] && pec16_rcv_8[1] == rcv_data[7]) PecChk[0] = 1;
			//else PecChk[0] = 0;
            
            bmuState = BMU_NORMAL;
            break;
        }
        default:
            break;       
    }
}
/*
void BMU_Process2(const uint8_t *CMD32, uint8_t *rcv_data, uint8_t *PecChk)
{
    static uint8_t BMUcmd[2] = {0, 0};
	uint8_t pec16_rcv_8[2];
    static uint16_t count = 0;
    uint8_t i, Command[12];
	uint16_t pec16,pec16_rcv,rcv_dly;
	volatile int ii;
    
	switch(bmuState)
    {
        case BMU_RESET:
        {
            // PEC15_Table_Init();
            bmuState = BMU_INIT;
            break;
        }
        case BMU_INIT:
        {
            
            bmuState = BMU_CONFIG;
            break;
        }
        case BMU_CONFIG:
        {
            
            bmuState = BMU_NORMAL;
            break;
        }
        case BMU_CONVERT:
        {
            
            bmuState = BMU_NORMAL;
            break;
        }
        case BMU_MEASURE:
        {
            
            bmuState = BMU_NORMAL;
            break;
        }
        case BMU_NORMAL:
        {
            // count++;
            // if(count > 3000)
            // {
                // count = 0;
                // BMUcmd[0]++;
            // }

            
            for(i = 0; i < 12; i++)
            {
                Command[i] = 0;
            }			

			// ADC cell voltage conversion
//			Command[0] = 0x00;
			SPI_WakeUp_ch1(1);
			
			Command[0] = CMD32[0];
			Command[1] = CMD32[1];
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message_ch1(1, Command, 4,300, 0);
			
			for(ii=0;ii<1500;ii++);
			//SPI_Tx_Message(&Command[4], 8,500, 1);
            // Command_LTC(BMUcmd) Cell voltage (VC1-VC3);
            for(i = 0; i < 12; i++){ Command[i] = 0; }			
			SPI_WakeUp_ch1(1);
			Command[0] = CMD32[2];
			Command[1] = CMD32[3];
			pec16 = Calculate_PEC15(Command,2);
			Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
			Command[3] = (uint8_t)(pec16&0xFF);			
            SPI_Tx_Message_ch1(1, Command, 4,300, 0);			
			for(ii=0;ii<300;ii++);
			
			rcv_dly = 100;
			SPI_Tx_Dummy_ch1(1, &Command[4], 8, rcv_data, 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(rcv_data,6);
			PecChk[0] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[1] = (uint8_t)(pec16_rcv&0xFF);
			// 2 cell group
			SPI_Tx_Dummy_ch1(1, &Command[4], 8, &rcv_data[8], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[8],6);
			PecChk[2] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[3] = (uint8_t)(pec16_rcv&0xFF);
			// 3 cell group
			SPI_Tx_Dummy_ch1(1, &Command[4], 8, &rcv_data[16], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[16],6);
			PecChk[4] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[5] = (uint8_t)(pec16_rcv&0xFF);
			// 4 cell group
			SPI_Tx_Dummy_ch1(1, &Command[4], 8, &rcv_data[24], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[24],6);
			PecChk[6] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[7] = (uint8_t)(pec16_rcv&0xFF);
			// 5 cell group
			SPI_Tx_Dummy_ch1(1, &Command[4], 8, &rcv_data[32], 8, rcv_dly, 0);
			pec16_rcv = Calculate_PEC15(&rcv_data[32],6);
			PecChk[8] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[9] = (uint8_t)(pec16_rcv&0xFF);
			// 6 cell group
			SPI_Tx_Dummy_ch1(1, &Command[4], 8, &rcv_data[40], 8, rcv_dly, 1);
			pec16_rcv = Calculate_PEC15(&rcv_data[40],6);
			PecChk[10] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			PecChk[11] = (uint8_t)(pec16_rcv&0xFF);
			// 7 cell group
			//SPI_Tx_Dummy(1, &Command[4], 8, &rcv_data[48], 8, rcv_dly, 1);
			//pec16_rcv = Calculate_PEC15(&rcv_data[48],6);
			//PecChk[12] = (uint8_t)((pec16_rcv&0xFF00)>>8)&0xFF;
			//PecChk[13] = (uint8_t)(pec16_rcv&0xFF);
            
            bmuState = BMU_NORMAL;
            break;
        }
        default:
            break;       
    }
}
*/
