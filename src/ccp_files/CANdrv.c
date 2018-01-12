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
 * @File Name             : CANdrv.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : N/A
 *
 * Part Errata Fixes      : none
 *
 * Created By             : John H. Floros
 *
 * Created on Date        : 11-Jan-2011 14:57:10
 * 
 * @Brief Description     : Source file for Flex CAN driver
 ***********************************************************************
 *
 *   Revision History
 *
 *   Date          Author           Description
 *   ----------    ------           ------------------------------------
 *   mm-dd-yyyy    X. Z.            File Created
 *
 *######################################################################
*/
/******************************************************************************
* Includes
******************************************************************************/
#include "CANcfg.h" 
#include "target.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define CAN_RX_EMPTY (0x04)
#define CAN_TX_MSG (0x0C)

#define TX_CODE_INACTIVE (0x8)
#define RX_CODE_INACTIVE (0x0)

/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Local Functions
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Static variables
******************************************************************************/
volatile static FLEXCAN_tag* CAN[] = { &CAN_0, &CAN_1};

/******************************************************************************
* Global functions
******************************************************************************/

/******************************************************************************
*   Function: SetCanRxFilter
*
*   Description: This function is called to set up the mailboxes on the specified
*                CAN channel and works for standard and extended IDs.
*   Caveats:
*
******************************************************************************/
void SetCanRxFilter(uint32_t id, uint8_t mb, uint8_t ext) 
{
    if (ext)
    {
        CAN[FLEXCAN_NUM]->BUF[mb].CS.B.IDE = 1;/* MB for extended ID */
        CAN[FLEXCAN_NUM]->BUF[mb].ID.R = id;   /* MB ID */
    }
    else
    {
        CAN[FLEXCAN_NUM]->BUF[mb].CS.B.IDE = 0; /* MB for standard ID */
        CAN[FLEXCAN_NUM]->BUF[mb].ID.B.STD_ID = (uint16_t)id; /* MB ID */
    }
    CAN[FLEXCAN_NUM]->BUF[mb].CS.B.CODE = CAN_RX_EMPTY; /* Set rx MB empty */
}

/******************************************************************************
*   Function: CanTxMsg
*
*   Description: This function is called to transmit a CAN message.
*
*   Caveats:
*
******************************************************************************/
void CanTxMsg (uint32_t id, uint8_t mb, uint8_t dlc, uint8_t data[], uint8_t ext)
{
    uint8_t	i;

    if (ext)
    {
        CAN[FLEXCAN_NUM]->BUF[mb].CS.B.IDE = 1; /* extended ID */
        CAN[FLEXCAN_NUM]->BUF[mb].ID.R = id;    /* Tx ID extended */
    }
    else
    {
        CAN[FLEXCAN_NUM]->BUF[mb].CS.B.IDE = 0; /* standard ID */
        CAN[FLEXCAN_NUM]->BUF[mb].ID.B.STD_ID = (uint16_t)id; /* Tx ID standard */
    }
    CAN[FLEXCAN_NUM]->BUF[mb].CS.B.RTR = 0;      /* no remote Tx request frame */
    CAN[FLEXCAN_NUM]->BUF[mb].CS.B.LENGTH = dlc; /* # bytes to Tx */
    for (i = 0; i < dlc; i++) 
    {
        CAN[FLEXCAN_NUM]->BUF[mb].DATA.B[i] = data[i]; /* Data to Tx */
    }
    CAN[FLEXCAN_NUM]->BUF[mb].CS.B.SRR = 1;            /* Tx frame */
    CAN[FLEXCAN_NUM]->BUF[mb].CS.B.CODE = CAN_TX_MSG;  /* Send msg */ 
}

/******************************************************************************
*   Function: CanRxMsg
*
*   Description: This function is called to receive a CAN message.
*
*   Caveats:
*
******************************************************************************/
can_msg_struct CanRxMsg (uint8_t mb)
{
	uint8_t	i;
	uint32_t dummy;
	uint32_t flagIFRL = 0;
	uint32_t flagIFRH = 0;
	can_msg_struct msg;

	if (mb < 32)
	{
    	flagIFRL = ((uint32_t)(0x00000001 << mb));
	}
	else
	{
    	flagIFRH = ((uint32_t)(0x00000001 << (mb - 32)));
	}

    msg.code   = (uint8_t)CAN[FLEXCAN_NUM]->BUF[mb].CS.B.CODE;
    if (CAN[FLEXCAN_NUM]->BUF[0].CS.B.IDE) /* if extended ID */
    {
        msg.id  = CAN[FLEXCAN_NUM]->BUF[mb].ID.R;
    }
    else /* if standard ID */
    {
        msg.id  = (uint16_t)CAN[FLEXCAN_NUM]->BUF[mb].ID.B.STD_ID;
    }
    msg.length = (uint8_t)CAN[FLEXCAN_NUM]->BUF[mb].CS.B.LENGTH;
    for (i = 0; i < msg.length; i++) 
    { 
        msg.data[i] = CAN[FLEXCAN_NUM]->BUF[mb].DATA.B[i];
    }
    dummy = CAN[FLEXCAN_NUM]->TIMER.R;  /* Read TIMER to unlock MB */    
    CAN[FLEXCAN_NUM]->IFRL.R = flagIFRL; /* Clear MB flag */
    CAN[FLEXCAN_NUM]->IFRH.R = flagIFRH; /* Clear MB flag */
    return (msg);
}
/******************************************************************************
*   Function: CanRxMbFull
*
*   Description: This function is called to determine if CAN Mail box is full.
*
*   Caveats:
*
******************************************************************************/
uint8_t CanRxMbFull (uint8_t mb)
{
	uint8_t	temp = 0;
	uint32_t flagIFRL = 0;
	uint32_t flagIFRH = 0;

	if (mb < 32)
	{
    	flagIFRL = ((uint32_t)(0x00000001 << mb));
	}
	else
	{
    	flagIFRH = ((uint32_t)(0x00000001 << (mb - 32)));
	}
    if (mb < 32)
    {
		if (CAN[FLEXCAN_NUM]->IFRL.R & flagIFRL)
		{
			temp = 1;
		}
    }
    else
    {
		if (CAN[FLEXCAN_NUM]->IFRH.R & flagIFRH)
		{
			temp = 1;
		}
    }
	return (temp);
}
/******************************************************************************
*   Function: CanTxMbEmpty
*
*   Description: This function is called to determine if CAN Mail box is empty.
*
*   Caveats:
*
******************************************************************************/
uint8_t CanTxMbEmpty (uint8_t mb)
{
    uint8_t	temp = 0;

    if (CAN[FLEXCAN_NUM]->BUF[mb].CS.B.CODE == TX_CODE_INACTIVE ||
        CAN[FLEXCAN_NUM]->BUF[mb].CS.B.CODE == RX_CODE_INACTIVE) 
    {
        temp = 1;    
    }
    return (temp);
}


