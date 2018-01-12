/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    dspi_564xl_library.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   DSPI module support.
*    @details Implementation of DSPI module functions.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		23-May-2011
*   Author:                         B14423
* 
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/
 
#include "dspi_564xL_library.h"

static volatile DSPI_tag* DSPI[]={ &DSPI_0, &DSPI_1, &DSPI_2};
/******************************************************************************
*                   Global functions
******************************************************************************/

/******************************************************************************
*   Function:  dspi_564xl_read_master
@brief    Reads the data from DSPI module  - master. 
@details   Reads the data from DSPI module
    
@param[in]     dspi_num     DSPI number
   
@return Data from DSPI module
*/

uint16_t dspi_564xl_read_master(uint8_t dspi_num){

	uint16_t ret = 0U;
	
	while (DSPI[dspi_num]->SR.B.RFDF != 1){}                /* Wait for Receive FIFO Drain Flag = 1 */
	ret = (uint16_t)DSPI[dspi_num]->POPR.R;                 /* Read data received by master SPI */
	DSPI[dspi_num]->SR.R = 0x00020000;                      /* Clear RDRF flags*/

	return ret;
}

/******************************************************************************
*   Function:  dspi_564xl_read_slave
@brief    Reads the data from DSPI module - Slave . 
@details   Reads the data from DSPI module
    
@param[in]     dspi_num     DSPI number
   
@return Data from DSPI module
*/

uint16_t dspi_564xl_read_slave(uint8_t dspi_num){

	uint16_t ret = 0U;
	
	while (DSPI[dspi_num]->SR.B.RFDF != 1){}             /* Wait for Receive FIFO Drain Flag = 1 */
	ret = (uint16_t)DSPI[dspi_num]->POPR.R;              /* Read data received by slave SPI */
	DSPI[dspi_num]->SR.R = 0x00020000;                   /* Clear RDRF flags*/			
	
	return ret;
}

/******************************************************************************
*   Function:  dspi_564xl_send
@brief    Send the data from DSPI module 
@details   Send  the data from DSPI module
    
@param[in]     dspi_num     DSPI number
@param[in]     pushr_data     data
   
@return none

*/

void dspi_564xl_send(uint8_t dspi_num, DSPI_PUSHR_32B_tag pushr_data){
// volatile int i=0;
// int j=0;
//   for(i=0;i<1800;i++){
//     //j = i+1;
//   }
	DSPI[dspi_num]->SR.R = DSPI_ISR_TCF_RE | DSPI_ISR_EOQF_RE;   /* TCF EOQF */
	DSPI[dspi_num]->PUSHR.R = pushr_data.R;
  
	return;
}

/******************************************************************************
*   Function:  dspi_564xl_config
@brief    Configure DSPI module . 
@details   Configure DSPI module 
    
@param[in]     dspi_num     DSPI number
@param[in]     dspi_MCR              DSPI Module Configuration Register settings
@param[in]     dspi_CTAR             DSPI Clock and Transfer Attributes Register
   
@return none
*/
void dspi_564xl_config(uint8_t dspi_num, uint32_t dspi_MCR, uint32_t dspi_CTAR){

	uint32_t mcr = dspi_MCR;
	uint32_t ctar = dspi_CTAR;

  DSPI[dspi_num]->MCR.R = mcr;
	DSPI[dspi_num]->CTAR[0].R = ctar;
	DSPI[dspi_num]->MCR.B.HALT = 0x0;
	
	return;
}


/******************************************************************************
*   Function:  dspi_564xl_pin_init
@brief    Configure DSPI module  pins. 
@details   Configure DSPI module  pins
    
@param[in]     pcr_num     pin selection
@param[in]     in_out          direction (in/out)
@param[in]     dspi_num     DSPI number
   
@return none
*/
void dspi_564xl_pin_init(uint8_t pcr_num, uint8_t in_out, uint8_t dspi_num)
{
	if (pcr_num == 0){					/*  PCR[0] 	DSPI_2 SCK ALT2 SCK PSMI[1]; PADSEL=0   */
		if(in_out == 0)
		{ 				/*   in    */
			SIU.PCR[pcr_num].R = 0x0100;
			SIU.PSMI[1].B.PADSEL = 0;
		}
		else if( in_out == 1)
		{			/*   out    */
			SIU.PCR[pcr_num].R = 0x0A00;
		}
	} 
	else if (pcr_num == 1)
	{			/* PCR[1]	DSPI_2 SOUT ALT2 — —  */
		SIU.PCR[pcr_num].R = 0x0A00; /*   out    */
	} 
	else if (pcr_num == 2)
	{			/* PCR[2]	DSPI_2 — — SIN PSMI[2]; PADSEL=0  */
		SIU.PCR[pcr_num].R = 0x0100; /*   in    */
		SIU.PSMI[2].B.PADSEL = 0;
	}
	else if (pcr_num == 3)
	{			/*  PCR[3]	DSPI_2 CS0 ALT2 CS0 PSMI[3]; PADSEL=0  */
		if (in_out == 0)
		{		/*   in    */
			SIU.PCR[pcr_num].R = 0x0100; /*   in    */
			SIU.PSMI[3].B.PADSEL = 0;
		}
		else if (in_out == 1)
		{		/*   out    */
			SIU.PCR[pcr_num].R = 0x0A00; /*   out    */
		}
	}
	else if (pcr_num == 4)
	{			/*  PCR[4]	DSPI_2 CS1 ALT2 — — */
		SIU.PCR[pcr_num].R = 0x0A00; /*   out    */	
	}
	else if (pcr_num == 5)
	{			
		if (dspi_num == 0)
		{		/*  PCR[5]	DSPI_0 CS7 ALT3 — — */
			SIU.PCR[pcr_num].R = 0x0E00; /*   out    */	
		}
		else if (dspi_num == 1)
		{		/*  PCR[5]	DSPI_1 CS0 ALT1 CS0 — */
			if ( in_out == 0)
			{
				SIU.PCR[pcr_num].R = 0x0100; /*   in    */	
			}
			else if (in_out == 1)
			{
				SIU.PCR[pcr_num].R = 0x0600; /*   out    */	
			}
		}
	}
	else if (pcr_num == 6)
	{		/*  PCR[6]	DSPI_1 SCK ALT1 SCK — */
		if (in_out == 0)
		{	/*   in    */
			SIU.PCR[pcr_num].R = 0x0100; 
		}
		else if (in_out == 1)
		{	/*   out    */
			SIU.PCR[pcr_num].R = 0x0600; 
		}
	}
	else if (pcr_num == 7)
	{		/*  PCR[7]	DSPI_1 SOUT ALT1 — — */
		SIU.PCR[pcr_num].R = 0x0600; /*   out    */
	}
	else if (pcr_num == 8)
	{		/*  PCR[8]	DSPI_1 — — SIN — */
		SIU.PCR[pcr_num].R = 0x0100; /*   in    */
	}
	else if (pcr_num == 9)
	{		/*  PCR[9]	DSPI_2 CS1 ALT1 — — */
		SIU.PCR[pcr_num].R = 0x0600; /*   out    */
	}
	else if (pcr_num == 10)
	{		/*  PCR[10]	DSPI_2 CS0 ALT1 CS0 PSMI[3]; PADSEL=1 */
		if (in_out == 0)
		{	/*   in    */
			SIU.PCR[pcr_num].R = 0x0100;
			SIU.PSMI[3].B.PADSEL = 1;
		}
		else if (in_out == 1)
		{	/*   out    */
			SIU.PCR[pcr_num].R = 0x0600;
		}
	}
	else if (pcr_num == 11)
	{		/*  PCR[11]	DSPI_2 SCK ALT1 SCK PSMI[1]; PADSEL=1  */
		if (in_out == 0)
		{	/*   in    */
			SIU.PCR[pcr_num].R = 0x0100;
			SIU.PSMI[1].B.PADSEL = 1;
		}
		else if (in_out == 1)
		{	/*   out    */
			SIU.PCR[pcr_num].R = 0x0600;
		}
	}
	else if (pcr_num == 12)
	{		/*  PCR[12]	DSPI_2 SOUT ALT1 — —   */
		SIU.PCR[pcr_num].R = 0x0600;
	}
	else if (pcr_num == 13)
	{		/*  PCR[13]	DSPI_2 — — SIN PSMI[2]; PADSEL=1   */
		SIU.PCR[pcr_num].R = 0x0100;
		SIU.PSMI[2].B.PADSEL = 1;
	}
	else if (pcr_num == 22)
	{		/*  PCR[22]	DSPI_2 CS2 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 36)
	{		/*  PCR[36]	DSPI_0 CS0 ALT1 CS0 —   */
		if (in_out == 0)
		{	/*   in    */
			SIU.PCR[pcr_num].R = 0x0100;
		}
		else if (in_out == 1)
		{	/*   out    */
			SIU.PCR[pcr_num].R = 0x0600;
		}
	}
	else if (pcr_num == 37)
	{		/*  PCR[37]	DSPI_0 SCK ALT1 SCK —   */
		if (in_out == 0)
		{	/*   in    */
			SIU.PCR[pcr_num].R = 0x0100;
		}
		else if (in_out == 1)
		{	/*   out    */
			SIU.PCR[pcr_num].R = 0x0600;
		}
	}
	else if (pcr_num == 38)
	{		/*  PCR[38]	DSPI_0 SOUT ALT1 — —   */
		SIU.PCR[pcr_num].R = 0x0600;
	}
	else if (pcr_num == 39)
	{		/*  PCR[39]	DSPI_0 — — SIN —   */
		SIU.PCR[pcr_num].R = 0x0100;
	}
	else if (pcr_num == 42)
	{		/*  PCR[42]	DSPI_2 CS2 ALT1 — —   */
		SIU.PCR[pcr_num].R = 0x0600;
	}
	else if (pcr_num == 43)
	{		/*  PCR[43]	DSPI_2 CS2 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 44)
	{		/*  PCR[44]	DSPI_2 CS3 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 53)
	{		/*  PCR[53]	DSPI_0 CS3 ALT1 — —   */
		SIU.PCR[pcr_num].R = 0x0600;
	}
	else if (pcr_num == 54)
	{		/*  PCR[54]	DSPI_0 CS2 ALT1 — —   */
		SIU.PCR[pcr_num].R = 0x0600;
	}
	else if (pcr_num == 55)
	{
		if (dspi_num == 0)
		{		/*  PCR[55]	DSPI_0 CS4 ALT3 — —   */
			SIU.PCR[pcr_num].R = 0x0E00; /*   out    */	
		}
		else if (dspi_num == 1)
		{		/*  PCR[55]	DSPI_1 CS3 ALT1 — —   */
			SIU.PCR[pcr_num].R = 0x0600; /*   out    */	
		}
	}
	else if (pcr_num == 56)
	{
		if (dspi_num == 0)
		{		/*  PCR[56]	DSPI_0 CS5 ALT3 — —   */
			SIU.PCR[pcr_num].R = 0x0E00; /*   out    */	
		}
		else if (dspi_num == 1)
		{		/*  PCR[56]	DSPI_1 CS2 ALT1 — —   */
			SIU.PCR[pcr_num].R = 0x0600; /*   out    */	
		}
	}
	else if (pcr_num == 77)
	{			/*  PCR[77]	DSPI_2 CS3 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 79 )
	{		/*  PCR[79]	DSPI_0 CS1 ALT1 — —   */
		SIU.PCR[pcr_num].R = 0x0600;
	}
	else if (pcr_num == 83)
	{		/*  PCR[83]	DSPI_0 CS6 ALT1 — —   */
		SIU.PCR[pcr_num].R = 0x0600;
	}
	else if (pcr_num == 98)
	{		/*  PCR[98]	DSPI_1 CS1 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 101)
	{		/*  PCR[101]	DSPI_2 CS3 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 104)
	{		/*  PCR[104]	DSPI_0 CS1 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 105)
	{		/*  PCR[105]	DSPI_1 CS1 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 106)
	{		/*  PCR[106]	DSPI_2 CS3 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 117)
	{		/*  PCR[117]	DSPI_0 CS4 ALT3 — —   */
		SIU.PCR[pcr_num].R = 0x0E00;
	}
	else if (pcr_num == 118)
	{		/*  PCR[118]	DSPI_0 CS5 ALT3 — —   */
		SIU.PCR[pcr_num].R = 0x0E00;
	}
	else if (pcr_num == 120)
	{		/*  PCR[120]	DSPI_0 CS6 ALT3 — —   */
		SIU.PCR[pcr_num].R = 0x0E00;
	}
	else if (pcr_num == 121)
	{		/*  PCR[121]	DSPI_0 CS7 ALT3 — —   */
		SIU.PCR[pcr_num].R = 0x0E00;
	}
	else if (pcr_num == 128)
	{		/*  PCR[128]	DSPI_0 CS4 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 129)
	{		/*  PCR[129]	DSPI_0 CS5 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 130)
	{		/*  PCR[130]	DSPI_0 CS6 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	else if (pcr_num == 131)
	{		/*  PCR[131]	DSPI_0 CS7 ALT2 — —   */
		SIU.PCR[pcr_num].R = 0x0A00;
	}
	
	return;
}

/******************************************************************************
*   Function:  dspi_564xl_interrupt_set
@brief    Configure DSPI module  interrupt. 
@details   Configure DSPI module interrupt
    
@param[in]     dspiNum     DSPI number
@param[in]     flag          flag
   
@return none
*/
void dspi_564xl_interrupt_set(uint8_t dspiNum, uint32_t flag){
	
	DSPI[dspiNum]->RSER.R |= flag;
	
	return;
}

/******************************************************************************
*   Function:  dspi_564xl_interrupt_clr
@brief    Configure DSPI module  interrupt. 
@details   Configure DSPI module interrupt
    
@param[in]     dspiNum     DSPI number
@param[in]     flag          flag
   
@return none
*/
void dspi_564xl_interrupt_clr(uint8_t dspiNum, uint32_t flag){
	
	DSPI[dspiNum]->RSER.R &= ~flag;

	return;
}

/******************************************************************************
*   Function:  dspi_564xl_get_status
@brief    Return DSPI module  status. 
@details   Return DSPI module  status
    
@param[in]     dspiNum     DSPI number
   
@return status
*/
uint32_t dspi_564xl_get_status(uint8_t dspiNum){

	uint32_t out = 0U;
	
	out = DSPI[dspiNum]->SR.R;
	
	return out;
}

#ifdef __cplusplus
}
#endif


/*
 *######################################################################
 *                           End of File
 *######################################################################
*/