/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2006-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name:       DSPI.c$
* @file             DSPI.c
*
* $Date:            Mar-01-2012$
* @date             Mar-01-2012
*
* $Version:         1.0$
* @version          1.0
*
* Description      DSPI driver source file
* @brief            DSPI driver source file
*
* --------------------------------------------------------------------
* $Name:  $
*******************************************************************************/
/****************************************************************************//*!
*
*  @mainpage DSPI driver for MPC5643L
*
*  @section Intro Introduction
*
*	This package contains DSPI driver for MPC5643L allowing to 
*	initialize/configure DSPI module and process SPI communication.
*
*  The key features of this package are the following:
*  - Initialize DSPI module with the desired parameters
*  - Configure DSPI parameters
*  - Process SPI communication (reading/writing)
*  For more information about the functions and configuration items see these documents: 
*
*******************************************************************************
*
* @attention 
*            
*******************************************************************************/
/*==================================================================================================
*   Project              : PowerSBC
*   Platform             : MPC5643L
*   Dependencies         : MPC5643L - Basic SW drivers.
*   All Rights Reserved.
==================================================================================================*/

/*==================================================================================================
Revision History:
                             Modification     Function
Author (core ID)              Date D/M/Y       Name		  Description of Changes
B35993		 				  01/03/2012 	   ALL		  Driver created

---------------------------   ----------    ------------  ------------------------------------------
==================================================================================================*/

//#include "EXTGLOBALS.h"
#include "gpio_564xl_library.h"
#include "target.h"
#include "DMA.h"
#include "dspi_564xl_library.h"

// macros for SSIZE, DSIZE
#define SIZE_1_byte  0
#define SIZE_2_byte  1 
#define SIZE_4_byte  2
#define SIZE_8_byte  3
#define SIZE_16_byte 4
#define SIZE_32_byte 5

/***************************************************************************//*!
*   @brief Computes register contents and initializes DSPIx.
*	@par Include 
*					DSPI.h
* 	@par Description 
*					Function initializes DSPIx in specified mode (Master or Slave), 
*					computes register configuration to achieve the desired baud rate 
*					(if possible) and sets interruption mask. By default data are changed 
*					on a leading edge of DSPI clock and captured on a falling edge (CPHA=1). 
*					Inactive state of DSPI clock is set to low by default (CPOL=0). Both 
*					parameters are changeable after the init phase using other functions 
*					(see setPhaseSPIx and setPolaritySPIx functions for additional information). 
* 	@param[in] DspiNumber - Number of DSPI module (0 or 1 or 2).
*	@param[in] mode - DSPIx mode configuration (Master or Slave).
*					Predefined values:
*					- MASTER	DSPIx will handle communication as a Master.
*					- SLAVE	DSPIx will listen to the incoming commands as a Slave.
*	@param[in] sysClk
*					System clock frequency [Hz].
*	@param[in] baudRate
*					Desired baud rate [b/s]. Maximal and minimal Baud rate depends on 
*						the actual system clock frequency and on the limits of the PBR and 
*						BR registers. Maximal and minimal values for fsys = 16 MHz are shown 
*						in the table below, for other frequencies see the external excel file.
*						Predefined values:
*						- min baudRate = 70 b/s for fsys = 16 MHz
*						- max baudRate = 4 000 000 b/s for fsys = 16MHz
*	@param[in] intMask
*					32bit mask allowing us to choose which interruption we want to activate. 
*						If no interruption is necessary, please add simply 0 instead of the whole 
*						mask. Predefined iterruption masks can be combined arbitrarily using 
*						logical OR (|) operator.
*						Predefined value:
*						- TCFRE - Transmission Complete Request Enable flag mask
*						- EOQFRE - Finished Request Enable flag mask
*						- TFUFRE - Transmit FIFO Underflow Request Enable flag mask
*						- TFFFRE - Transmit FIFO Fill Request Enable flag mask
*						- RFOFRE - Receive FIFO Overflow Request Enable flag mask
*						- RFDFRE - Receive FIFO Drain Request Enable flag mask
*	@remarks 	System clock frequency should be added in multiples of the basic units 
*				(e.g. in kHz, MHz), but everytime with respect to the units of a baud rate.
*	@par Code sample1
*			DSPI_Init(0, MASTER, 16000000, 4000000, TCFRE);
*			- Command initializes DSPI no. 0 in Master mode with desired baud rate     
*			4 Mbit/s (more exactly 3.81Mbit/s, because 1 Mb/s = 1 048 576 b/s) and 
*			activated interruption when transmission is completed. System clock 
*			frequency is 16 MHz.
*	@par Code sample2
*			DSPI_Init(2, SLAVE, 16, 4, TCFRE | EOQFRE);
*			- Command initializes DSPI no. 2 in Slave mode with desired baud rate         
*			4 Mb/s and activated interruption when transmission is completed and 
*			when request is finished.
********************************************************************************/
#define EDMA_SAMPLES_AMOUNT (50)
/*
vuint32_t  TransmitBuffer[EDMA_SAMPLES_AMOUNT]=
{
	DSPI_PUSHR_PCS0 | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_CONT | DSPI_PUSHR_TXDATA(0),
	DSPI_PUSHR_PCS0 | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_CONT | DSPI_PUSHR_TXDATA(0),
	DSPI_PUSHR_PCS0 | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_CONT | DSPI_PUSHR_TXDATA(0),
	DSPI_PUSHR_PCS0 | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_CONT | DSPI_PUSHR_TXDATA(0),
	DSPI_PUSHR_PCS0 | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_CONT | DSPI_PUSHR_TXDATA(0),
	DSPI_PUSHR_PCS0 | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_CONT | DSPI_PUSHR_TXDATA(0),
	DSPI_PUSHR_PCS0 | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_CONT | DSPI_PUSHR_TXDATA(0),
	DSPI_PUSHR_PCS0 | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_CONT | DSPI_PUSHR_TXDATA(0)
};
*/


vuint32_t  TransmitBuffer[EDMA_SAMPLES_AMOUNT] = {0};
vuint32_t  ReceiveBuffer[EDMA_SAMPLES_AMOUNT] = {1};

vuint16_t Transmit_data_len = sizeof(TransmitBuffer);  /*initialize data len*/
vuint16_t Receive_data_len = sizeof(ReceiveBuffer);    /*initialize data len*/

uint16_t number_of_citer = 0;
uint16_t number_of_biter = 0;
uint16_t citer_count = 0;
uint16_t DMA_active = 0;

void DMA_channel_arbitration(void)
{
	/* Init eDMA engine */
    //EDMA.CR.R = 0x00000400; /* Use fixed priority arbitration for DMA groups and channels */ 
    //EDMA.CPR[0].R = 0x1;    /* Channel 0 priorites: channel priority = 0 */
    //EDMA.CPR[1].R = 0x0;    /* Channel 1 priorites: channel priority = 1 */
       
    EDMA.DMACR.B.ERCA = 1;    /*Round robin arbitration*/ 
    //EDMA.DCHPRI[0].B.CHPRI = 0x0F;
    //EDMA.DCHPRI[7].B.CHPRI = 0x04;
    EDMA.DMAERQL.B.ERQ &= ~0x00000001;   // disable channel 0 EDMA request (waiting for software to initiate transmit)

}


/******************* Prototype function for DMA_receive_init*****************************/


void DMA_receive_Init(void)
{
	#define DSPI_1_CHNL 7 // DMA channel 0 to be assigned
    #define DSPI_1_SOURCE 2 // DMA source number (SW must assign to DMA channel)
    
    
    // Clear DMA_MUX for DMA channel
    DMAMUX.CHCONFIG[DSPI_1_CHNL].R = 0x0;
	
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD0_.B.SADDR = (vuint32_t) &DSPI_0.POPR.R;       // Source address
    //EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD0_.B.SADDR = (vuint32_t) &TransmitBuffer[0]; // Test Source address
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD4_.B.SSIZE = SIZE_4_byte;                      // Source data transfer size
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD4_.B.SOFF = 4;                                 // Source address signed offset
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD12_.B.SLAST = -Transmit_data_len;              // Last source address adjustment
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD4_.B.SMOD = 0;                                 // Source address module

    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD16_.B.DADDR = ((vuint32_t) &ReceiveBuffer[0]); // Destination pushr DATA address
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD4_.B.DSIZE = SIZE_4_byte;                      // Destination data transfer size
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD20_.B.DOFF = 0;                                // Destination address signed offset
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD24_.B.DLAST_SGA = 0;                           // Last Distination address adjustment
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD4_.B.DMOD = 0;                                 // Destination address module
 
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD8_.B.SMLOE = 0;                                // Source minor loop offset enable 
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD8_.B.DMLOE = 0;                                // Destination minor loop offset enable
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD8_.B.MLOFF = 0;
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD8_.B.NBYTES = 4;        //minor byte count     // Number of bytes to be transfered in each request         

    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.BITER = ((vuint16_t) Receive_data_len/4);// Begining major iteration count          
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD20_.B.CITER = ((vuint16_t) Receive_data_len/4);// Current major iteration count            
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD20_.B.CITER_LINKCH = 0;                        // Link channel number

    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.D_REQ = 0;                               // disable channel when major loop is done                     
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.INT_HALF = 0;                            // no interrupt when half major count complete   
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.INT_MAJ = 1;                             // set interrupt when major count complete
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD20_.B.CITER_E_LINK = 0;				  
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.BITER_E_LINK = 0;
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.MAJOR_E_LINK = 0;
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.E_SG = 0;
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.BWC = 0;
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.START = 0;
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.DONE = 0;
    EDMA.CHANNEL[DSPI_1_CHNL].TCDWORD28_.B.ACTIVE = 0;
    
    DMAMUX.CHCONFIG[DSPI_1_CHNL].R = 0x80 + DSPI_1_SOURCE; // ENBL + TRIG + source#1    
}



/*******************************************************************************************/

void DMA_send_Init(void)  /* this is for DSPI_0 Transmit */
{
	
	
	#define DSPI_0_CHNL 0 // DMA channel 7 to be assigned
    #define DSPI_0_SOURCE 1 // DMA source number (SW must assign to DMA channel)
  	
	/* Clear DMA_MUX for DMA channel */
    DMAMUX.CHCONFIG[DSPI_0_CHNL].R = 0x0;
	
	
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD0_.B.SADDR = (vuint32_t) &TransmitBuffer[0];         // Source address
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD4_.B.SSIZE = SIZE_4_byte;                      // Source data transfer size
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD4_.B.SOFF = 4;                                 // Source address signed offset
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD12_.B.SLAST = -Transmit_data_len;                               // Last source address adjustment
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD4_.B.SMOD = 0;                                 // Source address module
   
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD16_.B.DADDR = ((vuint32_t) &DSPI_0.PUSHR.R);   // Destination pushr DATA address
    
    //EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD16_.B.DADDR = ((vuint32_t) &Destination[0]); // Test Destination address
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD4_.B.DSIZE = SIZE_4_byte;                      // Destination data transfer size
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.DOFF = 0;                                // Destination address signed offset
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD24_.B.DLAST_SGA = 0;                           // Last Distination address adjustment
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD4_.B.DMOD = 0;                                 // Destination address module
 
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD8_.B.SMLOE = 0;                                // Source minor loop offset enable 
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD8_.B.DMLOE = 0;                                // Destination minor loop offset enable
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD8_.B.MLOFF = 0;
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD8_.B.NBYTES = 4;        //minor byte count     // Number of bytes to be transfered in each request         

    //EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.BITER = ((vuint16_t) Transmit_data_len/4); // Begining major iteration count          
    //EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.CITER = ((vuint16_t) Transmit_data_len/4); // Current major iteration count            
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.CITER_LINKCH = 0;                          // Link channel number

    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.D_REQ = 0;                               //disable channel when major loop is done                     
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.INT_HALF = 0;                            // no interrupt when major count half complete
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.INT_MAJ = 1;                             // set interrupt when major count complete
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.CITER_E_LINK = 0;				  
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.BITER_E_LINK = 0;
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.MAJOR_E_LINK = 0;
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.E_SG = 0;
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.BWC = 0;
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.START = 0;
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.DONE = 0;
    EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.ACTIVE = 0;
       
    DMAMUX.CHCONFIG[DSPI_0_CHNL].R = 0x80 + DSPI_0_SOURCE; /* ENBL + TRIG + source#1 */
}


#define DSPI_PUSHR_CONT_EN_BITMASK  0x80000000
#define DSPI_PUSHR_EOQ_BITMASK  	0x08000000
#define DSPI_PUSHR_CONT_DIS_BITMASK 0x7FFFFFFF
#define DSPI_PUSHR_CS6_BITMASK      0x00400000
#define DSPI_PUSHR_CS1_BITMASK      0x00010000

void SPI_DMA_Send_Message(uint8_t *data , vuint16_t len)
{
  uint16_t i;
  for (i = 0;i < len; i++)
  {
  	if(i == len - 1)
  	{
  	    //TransmitBuffer[i] = DSPI_PUSHR_PCS0 | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_TXDATA(data[i]);
		TransmitBuffer[i] = DSPI_PUSHR_CS1_BITMASK | DSPI_PUSHR_CONT_EN_BITMASK | DSPI_PUSHR_TXDATA(data[i]);
  	}
  	else
  	{
  		//TransmitBuffer[i] = DSPI_PUSHR_PCS0 | DSPI_PUSHR_CONT | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_TXDATA(data[i]);
		TransmitBuffer[i] = DSPI_PUSHR_CS1_BITMASK | DSPI_PUSHR_CONT_EN_BITMASK | DSPI_PUSHR_CTAS(0) | DSPI_PUSHR_TXDATA(data[i]);
  	}
  }
  
  EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.BITER = len; // Begining major iteration count          
  EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.CITER = len; // Current major iteration count
  EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD12_.B.SLAST = -len*4; // Last source address adjustment 
  
  
  for (i = 0;i < len; i++)
  {
  	 int j = 8;
  	 
  	 citer_count = EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.CITER;
  	 EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD28_.B.START = 1;
     
     
     /* wait until minor loop complete */
     if(EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.CITER == 1) // if it is the last minor loop
     {
     	while(EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.CITER == 1){}
     }
     while(citer_count == EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.CITER && EDMA.CHANNEL[DSPI_0_CHNL].TCDWORD20_.B.CITER !=1){};
     
  }
  
}


void DMA0_isr(void)
{
    /* toggle LED */
    SIU.GPDO[52].R ^= 1;
    EDMA.DMAINTL.B.INT |= (vuint32_t)0x00000001;    // set to 1 to clear channel 0 interrupt request    	
}



void delayDMAms(int ms) {
	  int delayval;
	  delayval = ms * 8400;   // 8400 are about 1ms
	  while(delayval--);
}


