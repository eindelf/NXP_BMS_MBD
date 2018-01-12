/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    rtiostream_utils.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   ADC module support.
*    @details Implementation of ADC module functions.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		23-May-2011
*   Author:                         B13508
* 
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/

#include "target.h"
#include "xil_interface_lib.h"

/******************************************************************************
*                  Macros 
******************************************************************************/

#define BUF_MASK                       0x3F
#define BUF_SIZE                       (BUF_MASK+1)              /* power of 2 */

/******************************************************************************
*                  Static variables
******************************************************************************/

static uint8_t recBuf[BUF_SIZE];
static volatile uint8_t recNum = 0;
static uint8_t recBufStart = 0;
static volatile uint8_t txReady = 0;
static uint32_t status = 0;

/******************************************************************************
*                  Global functions prototype
******************************************************************************/

void LIN0_Rx_ISR_handler (void);
int rtIOStreamOpen(int argc, void const* argv[]);
int rtIOStreamClose(int streamID);
int rtIOStreamSend(int streamID, const void *src, int size, int *sizeSent);
int rtIOStreamRecv(int streamID, void * dst, int size, int * sizeRecvd);
void hw_init_fnc(void);
void MC_Cleanup (void);

/******************************************************************************
*                   Global functions
******************************************************************************/
/******************************************************************************
*   Function:  LIN0_Rx_ISR_handler
@brief    LIN0 Rx ISR handler . 
@details   LIN0 Rx ISR handler
  
   
@return none
*/
void LIN0_Rx_ISR_handler (void)
{
  status = LINFLEX_0.UARTSR.R;
  if (status & 0x2) {                  /* if DTF */
    txReady = 1;
    LINFLEX_0.UARTSR.R = 0x2;          /* Clear DTF */
  }

  recBuf[(recBufStart+recNum)&BUF_MASK] = LINFLEX_0.BDRM.B.DATA4;
  recNum++;
  LINFLEX_0.UARTSR.R = 0x4;            /* Clear DRF */
}

/******************************************************************************
*                   Global functions
******************************************************************************/
/******************************************************************************
*   Function:  rtIOStreamOpen
@brief    rtIOStreamOpen . 
@details   rtIOStreamOpen
    
@param[in]     argc
@param[in]     argv 
   
@return  always 1
*/
int rtIOStreamOpen(int argc, void const* argv[])
{
  hw_init_fnc();

  LINFLEX_0.UARTCR.B.RXEN = 1;         /* Receiver Enable */
  LINFLEX_0.UARTCR.B.TXEN = 1;         /* Transmitter Enable */
  LINFLEX_0.LINIER.B.DRIE = 1;         /* Enable Receiver interrupt */
  txReady = 1;
  return 1;
}

/******************************************************************************
*   Function:  rtIOStreamClose
@brief    rtIOStreamClose . 
@details   rtIOStreamClose
    
@param[in]     streamID     streamID
   
@return  always 0
*/
int rtIOStreamClose(int streamID)
{
	uint32_t resetReady = 0;

	LINFLEX_0.UARTCR.B.RXEN = 0;         /* Receiver Disable */
	LINFLEX_0.UARTCR.B.TXEN = 0;         /* Transmitter Disable */
	LINFLEX_0.LINIER.B.DRIE = 0;         /* Disable Receiver interrupt */
	txReady = 0;

	while((LINFLEX_0.UARTSR.B.DTF_TFF == 0) && (resetReady < 10000))/* Wait for any Data left to get trasmitted */
	{
		resetReady++;
	}
	MC_Cleanup(); /* reset MCU since PIL simulation is complete */

    return 0;
}

/******************************************************************************
*   Function:  rtIOStreamSend
@brief    rtIOStreamSend . 
@details   rtIOStreamSend
    
@param[in]     streamID     streamID
@param[in]     src     pointer to data
@param[in]     size     size
@param[out]     sizeSent     sizeSent
   
@return  always 0
*/
int rtIOStreamSend(
                   int streamID,
                   const void *src,
                   int size,
                   int *sizeSent)
{
  int i;
  uint8_t* buf = (uint8_t*)src;
  for (i = 0; i < size; i++) {
    if (txReady == 0) {
      while (LINFLEX_0.UARTSR.B.DTF_TFF == 0) ;
      LINFLEX_0.UARTSR.R = 0x2;         /* Clear DTF */
    }

    LINFLEX_0.BDRL.B.DATA0 = *buf;
    buf++;
    txReady = 0;
  }

  *sizeSent = size;
  return 0;
}

/******************************************************************************
*   Function:  rtIOStreamBlockingSend
@brief    rtIOStreamBlockingSend . 
@details   rtIOStreamBlockingSend
    
@param[in]     streamID     streamID
@param[in]     src     pointer to data
@param[in]     size     size
   
@return  always 0
*/
int rtIOStreamBlockingSend(
                   int streamID,
                   const void *src,
                   int size)
{
	int sizeSent;
	return rtIOStreamSend (streamID, src, size, &sizeSent);
}

/******************************************************************************
*   Function:  rtIOStreamRecv
@brief    rtIOStreamRecv . 
@details   rtIOStreamRecv
    
@param[in]     streamID     streamID
@param[in]     src     pointer to data
@param[in]     size     size
@param[out]     sizeRecvd     sizeRecvd
   
@return  always 0
*/
int rtIOStreamRecv(
                   int streamID,
                   void * dst,
                   int size,
                   int * sizeRecvd)
{
  int i;
  uint8_t* buf = (uint8_t*)dst;
  LINFLEX_0.LINIER.B.DRIE = 0;         /* Disable Receiver interrupt */
  if (recNum > size) {
    *sizeRecvd = size;
  } else {
    *sizeRecvd = recNum;
  }

  for (i = 0; i < *sizeRecvd; i++) {
    *buf = recBuf[recBufStart];
    buf++;
    recBufStart = (recBufStart+1)&BUF_MASK;
  }

  recNum -= (uint8_t)(*sizeRecvd);
  LINFLEX_0.LINIER.B.DRIE = 1;         /* Enable Receiver interrupt */
  return 0;
}

/******************************************************************************
*   Function:  rtIOStreamBlockingRecv
@brief    rtIOStreamBlockingRecv . 
@details   rtIOStreamBlockingRecv
    
@param[in]     streamID     streamID
@param[in]     src     pointer to data
@param[in]     size     size
   
@return  always 0
*/
int rtIOStreamBlockingRecv(
                   int streamID,
                   void * dst,
                   int size)
{
	int sizeRecvd;
	int sizeLeft = size;
    uint8_t* buf = (uint8_t*)dst;
	while (sizeLeft) {
		rtIOStreamRecv (streamID, (void *)buf, sizeLeft, &sizeRecvd);
		sizeLeft -= sizeRecvd;
		buf += sizeRecvd;
	}
  return 0;
}

/******************************************************************************
*   Function:  MC_Cleanup
@brief    MC_Cleanup . 
@details   MC_Cleanup
*/
void MC_Cleanup (void)
{
    void (*BamStartup)(void); /* Application function call */

        /* Re-enter in SAFE mode to update the configuration and disable peripherals */
    ME.MCTL.R = 0x20005AF0;    
        /* Mode & Key */
    ME.MCTL.R = 0x2000A50F;    
        /* Mode & Key  Inverted */
    while(0x1 == ME.GS.B.S_MTRANS){};    
        /* Wait for mode entry to complete */
    while(0x2 != ME.GS.B.S_CURRENT_MODE){};    
    /* Check SAFE mode has been entered  */
        
        /* Disable PLL0 clock */
    ME.DRUN_MC.R = 0x001F0030;
    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: Enabled    */
    /* Code Flash Power Down Control: Normal    */
    /* Secondary PLL (PLL1): OFF    */
    /* System PLL0: OFF    */
    /* Crystal Oscillator: ON    */
    /* 16MHz IRC:  ON    */  
    /* System Clock Source: 16MHz internal RC oscillator     */
    
    RGM.FESS.B.SS_EXR = 1;
    RGM.FBRE.B.BE_EXR = 1;
    
    /* ----------------------------------------------------------- */
    /*                     RESET Entry                    */
    /* ----------------------------------------------------------- */
        /* Re-enter in DRUN mode to update the configuration*/
    ME.MCTL.R = 0xF0005AF0;    
        /* Mode & Key */
    ME.MCTL.R = 0xF000A50F;    
        /* Mode & Key  Inverted */
    while(0x1 == ME.GS.B.S_MTRANS){};    
        /* Wait for mode entry to complete */
    while(0xF != ME.GS.B.S_CURRENT_MODE){};    
        /* Check RESET mode has been entered  */    
}

/* 
 * File: pil_main.c
 *
 * PIL main
 *
 */ 

int main(void) {
   XIL_INTERFACE_LIB_ERROR_CODE errorCode = XIL_INTERFACE_LIB_SUCCESS;
   /* avoid warnings about infinite loops */
   volatile int loop = 1;
   /* XIL initialization */   
   const int argc = 0;
   void * argv = (void *) 0;
   errorCode = xilInit(argc, argv);
   if (errorCode != XIL_INTERFACE_LIB_SUCCESS) {
      /* trap error with infinite loop */
      while (loop) {
      }
   }
   /* main XIL loop */
   while(loop) {
      errorCode = xilRun();
      if (errorCode != XIL_INTERFACE_LIB_SUCCESS) {
          if (errorCode == XIL_INTERFACE_LIB_TERMINATE) {
              int exitCode;
              /* orderly shutdown of rtiostream */
              exitCode = xilTerminateComms(); 
              if (exitCode == XIL_INTERFACE_LIB_SUCCESS) {
				  /* trap exit with infinite loop */
				  while (loop){
				  }
				   /* PIL terminate */
              }
			  /* trap PIL exit error with infinite loop */
			  while (loop){
			  }
          } 
		  /* trap PIL run error with infinite loop */
		  while (loop){
		  }
      }
   } 
   return errorCode;
}


#ifdef __cplusplus
}
#endif

/*
*######################################################################
*                           End of File
*######################################################################
*/
