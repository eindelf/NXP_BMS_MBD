/***************************************************************************************************
 * SF Motors Confidential – Copyright [2017], all rights reserved.
 * Author: deepak.agarwal@sfmotors.com
 * Date: 2017-06-28
 * Description: BMU interface and data collection (LTC6811-1)
 ***************************************************************************************************/

#include "BMU_Driver.h"

// Macros and variable definitions
#define BMU_RESET                      1
#define BMU_INIT                       2
#define BMU_CONFIG                     3
#define BMU_NORMAL                     4
#define BMU_CONVERT                    5
#define BMU_MEASURE                    6
#define DSPI_PUSHR_CONT_EN_BITMASK     0x80000000
#define DSPI_PUSHR_CONT_DIS_BITMASK    0x7FFFFFFF
#define DSPI_PUSHR_CS6_BITMASK         0x00400000
#define DSPI_PUSHR_CS1_BITMASK         0x00010000
#define CMD_LEN                        2

uint8_t bmuState = BMU_RESET;
uint8_t var1 = 1;
uint8_t spiDataTx = 0;
static volatile DSPI_tag* DSPI[]= { &DSPI_1, &DSPI_0, &DSPI_2 };

// Function prototypes
static void SPI_Send_Message(uint8_t *data , uint8_t len);
static void SPI_WakeUp();
static void SPI_Tx_Message(uint8_t *data , uint8_t len, uint16_t delay, uint8_t
  EndCs);
static uint16_t Calculate_PEC15(uint8_t *data , uint8_t len);
static void Command_LTC(uint8_t tx_cmd[2]);
uint16_t IsrCount = 0;

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
  for (i = 0; i < len-1; i++) {
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

/*****************************************************************************/
static void SPI_WakeUp()
{
  DSPI_PUSHR_32B_tag pushr;
  uint8_t i;
  volatile int ii= 0;
  int j= 0;
  pushr.R = 0U;

  // Keep chip select enabled
  pushr.R |= DSPI_PUSHR_CS1_BITMASK;
  for (ii=0;ii<1800;ii++) ;

  // Disable chip select after last data byte
  pushr.B.TXDATA = 0;
  pushr.R |= DSPI_PUSHR_CS1_BITMASK;

  //pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
  pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
  DSPI[0]->PUSHR.R = pushr.R;

  // Indicate end of queue
  DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
  while (DSPI[0]->SR.B.TCF != 1) ;
}

static void SPI_Tx_Message(uint8_t *data , uint8_t len, uint16_t delay, uint8_t
  EndCs)
{
  DSPI_PUSHR_32B_tag pushr;
  uint8_t i;
  volatile uint16_t ii= 0;

  //uint16_t j=0;
  pushr.R = 0U;

  // Keep chip select enabled
  pushr.R |= DSPI_PUSHR_CS1_BITMASK;

  //for(ii=0;ii<1800;ii++);
  for (i = 0; i < len-1; i++) {
    pushr.B.TXDATA = data[i];
    pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
    DSPI[0]->PUSHR.R = pushr.R;

    // Indicate end of queue
    //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
    for (ii=0;ii<delay;ii++) ;
    while (DSPI[0]->SR.B.TCF != 1) ;
  }

  // Disable chip select after last data byte
  pushr.B.TXDATA = data[i];
  pushr.R |= DSPI_PUSHR_CS1_BITMASK;
  if (EndCs == 1)
    pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
  else
    pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
  DSPI[0]->PUSHR.R = pushr.R;

  // Indicate end of queue
  DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;

  //for(ii=0;ii<500;ii++);
  while (DSPI[0]->SR.B.TCF != 1) ;
}

static void SPI_Rx_after_Tx_Message(uint8_t *data , uint8_t len, uint16_t delay,
  uint8_t EndCs)
{
  DSPI_PUSHR_32B_tag pushr;
  uint8_t i;
  volatile uint16_t ii= 0;

  //uint16_t j=0;
  pushr.R = 0U;

  // Keep chip select enabled
  pushr.R |= DSPI_PUSHR_CS1_BITMASK;

  //for(ii=0;ii<1800;ii++);
  for (i = 0; i < len-1; i++) {
    pushr.B.TXDATA = data[i];
    pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
    DSPI[0]->PUSHR.R = pushr.R;

    // Indicate end of queue
    //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
    for (ii=0;ii<delay;ii++) ;
    while (DSPI[0]->SR.B.TCF != 1) ;
  }

  // Disable chip select after last data byte
  pushr.B.TXDATA = data[i];
  pushr.R |= DSPI_PUSHR_CS1_BITMASK;
  if (EndCs == 1)
    pushr.R &= DSPI_PUSHR_CONT_DIS_BITMASK;
  else
    pushr.R |= DSPI_PUSHR_CONT_EN_BITMASK;
  DSPI[0]->PUSHR.R = pushr.R;

  // Indicate end of queue
  //DSPI[0]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;
  //for(ii=0;ii<500;ii++);
  while (DSPI[0]->SR.B.TCF != 1) ;
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
  cmd[1] = tx_cmd[1];
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
  for (i = 0; i < len; i++) {
    addr = ((rem >> 7) ^ data[i]) & 0xFF;//calculate PEC table address
    rem = (rem << 8 ) ^ PEC15Table[addr];
    rem &= 0xFFFF;
  }

  return ((rem << 1) & 0xFFFF);
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
void BMU_Process(void)
{
  static uint8_t BMUcmd[2] = { 0, 0 };

  static uint16_t count = 0;
  uint8_t i, Command[12];
  uint16_t pec16;
  volatile int ii;
  switch (bmuState)
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
      for (i = 0; i < 12; i++) {
        Command[i] = 0;
      }

      Command[0] = 0x00;
      SPI_WakeUp();
      for (ii=0;ii<1800*2;ii++) {
        //j = i+1;
      }

      Command[0] = 0x03;
      Command[1] = 0x70;
      pec16 = Calculate_PEC15(Command,2);
      Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
      Command[3] = (uint8_t)(pec16&0xFF);
      SPI_Tx_Message(Command, 4,1800, 0);
      for (ii=0;ii<2500;ii++) ;

      //SPI_Tx_Message(&Command[4], 8,500, 1);

      // Command_LTC(BMUcmd);
      for (i = 0; i < 12; i++) {
        Command[i] = 0;
      }

      Command[0] = 0x00;
      SPI_WakeUp();
      for (ii=0;ii<1800*2;ii++) {
        //j = i+1;
      }

      Command[0] = 0x00;
      Command[1] = 0x04;
      pec16 = Calculate_PEC15(Command,2);
      Command[2] = (uint8_t)((pec16&0xFF00)>>8)&0xFF;
      Command[3] = (uint8_t)(pec16&0xFF);
      SPI_Tx_Message(Command, 4,1800, 0);
      for (ii=0;ii<500;ii++) ;
      SPI_Tx_Message(&Command[4], 8,500, 1);
      SPI_Rx_after_Tx_Message(&Command[4], 8,500, 1);
      bmuState = BMU_NORMAL;
      break;
    }

   default:
    break;
  }
}
