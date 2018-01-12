/*
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED. 
 *######################################################################
 *
 * Project Name           : N/A
 *
 * @Revision Number       : 1.0
 * 
 * @File Name             : ccp_comm_api.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : N/A
 *
 * Part Errata Fixes      : none
 *
 * Created By             : RAppID Team
 *
 * Created on Date        : 18-Feb-2011 14:57:10
 * 
 * @Brief Description     : Source file CCP Application Interface File
 ***********************************************************************
 *
 *   Revision History
 *
 *   Date          Author           Description
 *   ----------    ------           ------------------------------------
 *   02-18-2011    RAppID Team      Added user def funcs ccpSend & ccpGetPointer
 *
 *######################################################################
*/
/******************************************************************************
* Includes
******************************************************************************/
#include "ccp_comm_cfg.h"
#include "ssd_types.h"
/******************************************************************************
* Constants
******************************************************************************/


/******************************************************************************
* Macros 
******************************************************************************/
#define CCP_PROTOCOL_BUF_SIZE 	20
#define CFLASH_BOUND_SIZE 8
#define CFLASH_DATA_BUF_SIZE 24 /* must be integer multiple of 6 and 8 */
#define CCP_INTER_BYTE_TIMEOUT 500000 /* 0.5 sec */ 

#define STD_ID (0)

#if defined ( CCP_CALPAGE )
  CCP_BYTE ccpCalPage = 0;
#endif

#if defined ( CCP_WRITE_EEPROM )
  void ccpCheckPendingEEPROM( void );
#endif

/******************************************************************************
* Types
******************************************************************************/
void progSetupAndUnlock(void);

/******************************************************************************
* Local Functions
******************************************************************************/
uint8_t CcpRxBufGetData(uint32_t *, uint32_t);
uint8_t CcpRxBufFull(void);

/******************************************************************************
* Global variables
******************************************************************************/
uint8_t CcpRxDataBuf[CCP_PROTOCOL_BUF_SIZE];
uint32_t CcpInterByteTime;
uint8_t CAN_BusActive;

can_msg_struct RxCanData;


/******************************************************************************
* Static variables
******************************************************************************/


/******************************************************************************
* Global functions
******************************************************************************/

/******************************************************************************
*   Function: InitCCP_Comm
*
*   Description: Initialize variables and drivers for CCP communications and programming.
*                
*   Caveats:
*
******************************************************************************/
void InitCCP_Comm()
{
    SetCanRxFilter(CCP_TESTER_ID, CCP_TESTER_MB, STD_ID);
    CcpInterByteTime = 0;
    CAN_BusActive = FALSE;      
}

/******************************************************************************
*   Function: ProcessCCP
*
*   Description: Check if RX buffer is fill to start processes CCP message
*                
*   Caveats:
*
******************************************************************************/

void ProcessCCP(uint32_t dt)
{
    uint32_t temp;
    
    if(CcpRxBufGetData(&temp, dt) > 0)
    {
        ccpCommand((uint8_t*)temp); /* Receive CCP CRO */
    } 
}


/******************************************************************************
*   Function: ccpSend
*
*   Description: Transmit request of a DTO CAN message to the CAN driver
*                
*   Caveats:
*
******************************************************************************/

void ccpSend(CCP_BYTEPTR msg)
{
    if (CAN_BusActive == TRUE)
    {
//    	if(CanTxMbEmpty(CCP_TX_MB) == TRUE)
//    	{
		while(CanTxMbEmpty(CCP_TX_MB) == FALSE){}
    	CanTxMsg (CCP_TX_ID, CCP_TX_MB, 8, (CCP_BYTE *)msg, STD_ID);	
//    	}	
    }

    ccpSendCallBack();

}

/******************************************************************************
*   Function: ccpGetPointer
*
*   Description: This function converts a memory address from CCP format
*				(32-bit address plus 8-bit address extension) to a C style 
*               pointer. 
*   Caveats:
*
******************************************************************************/

CCP_MTABYTEPTR ccpGetPointer( CCP_BYTE addr_ext, CCP_DWORD addr )   
{ 
	return (CCP_MTABYTEPTR) addr;
}

/******************************************************************************
*   Function: CcpRxBufGetData
*
*   Description: This function will receive 8 byte of Data packet for CCP
*
*   Caveats:
*
******************************************************************************/
uint8_t CcpRxBufGetData(uint32_t* bufAddr, uint32_t dt)
{
	uint32_t dataCnt = 0;
	uint8_t newData = FALSE;
	
    if (CanRxMbFull(CCP_TESTER_MB))
    {
        RxCanData = CanRxMsg (CCP_TESTER_MB);
		*bufAddr = (uint32_t)&RxCanData.data[0];/* Get the CCP UART Buf Address */
    	newData = TRUE; 
    	CAN_BusActive = TRUE;       
    }
	 
	return (newData); /* Send back if 8-byte Data packet is available */
}


/* Stub Function */
void ccpUserBackground( ){
}

void JumpToBootSector(){
}