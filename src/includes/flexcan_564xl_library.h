/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    flexcan_564xl_library.h
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   FlexCAN module support.
*    @details FlexCAN module support.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		2-Aug-2011
*   Author:                         b13508
* 
*/

#ifndef _FLEXCAN_564xL_LIBRARY_H
#define _FLEXCAN_564xL_LIBRARY_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/
#include "target.h"

/******************************************************************************
*                   Defines and Macros 
******************************************************************************/

#define FLEXCAN_0 	0
#define FLEXCAN_1	1

#define CAN_RX_EMPTY (0x04)
#define CAN_TX_MSG (0x0C)

#define TX_CODE_INACTIVE (0x8)
#define RX_CODE_INACTIVE (0x0)

/******************************************************************************
*                  Types definition - sturctures, enums, typedefs, etc
******************************************************************************/

typedef struct
{
	uint32_t	id;
	uint8_t		length;
	uint8_t		code;	
	uint8_t		ext;
	uint8_t		data[8];		/* 8 bytes of data */	
}FLEXCAN_MsgBufferStructure;

/******************************************************************************
*                   Global function prototypes
******************************************************************************/

uint8_t 	flexcan_564xl_init(uint8_t flex_can, uint32_t MCR, uint32_t CR);
uint8_t 	flexcan_564xl_init_FM(uint8_t flex_can, uint32_t MCR, uint32_t CR);
void 		flexcan_564xl_pin_init(uint8_t flex_can);
void 		flexcan_564xl_buffer_init(const FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure,uint8_t BufferNo,uint8_t flex_can);
void 		flexcan_564xl_buffer_transmit(const FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure,uint8_t BufferNo,uint8_t flex_can);
uint8_t 	flexcan_564xl_rxbuffull(uint8_t flex_can, uint8_t mb);
void 		flexcan_564xl_buffer_lock(uint8_t flex_can,uint8_t BufferNo);
uint8_t 	flexcan_564xl_buffer_rxbusy(uint8_t flex_can, uint8_t BufferNo);
uint32_t 	flexcan_564xl_get_id(uint8_t flex_can, uint8_t BufferNo);
void 		flexcan_564xl_get_mb(FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure, uint8_t flex_can, uint8_t BufferNo);
uint8_t 	flexcan_564xl_get_idtype(uint8_t flex_can, uint8_t BufferNo);
void 		flexcan_564xl_release_mb_lock(uint8_t flexcan);
void 		flexcan_564xl_clear_isr_flag(uint8_t flex_can, uint8_t BufferNo, uint32_t IFR_Mask);
void 		flexcan_564xl_clear_mask(uint8_t flex_can, uint8_t mb);
void 		flexcan_564xl_set_filter_id(uint8_t flex_can, uint8_t mb, uint32_t id, uint8_t ext);
void 		flexcan_564xl_readytoreceive(uint8_t flex_can, uint8_t BufferNo);
uint16_t 	flexcan_564xl_get_ts(uint8_t flex_can, uint8_t BufferNo);
uint8_t     flexcan_564xl_init_CCP(uint8_t flex_can, uint32_t MCR, uint32_t CR, uint8_t mb0, uint8_t mb1);
uint8_t     flexcan_564xl_init_CCP_FM(uint8_t flex_can, uint32_t MCR, uint32_t CR, uint8_t mb0, uint8_t mb1);

#ifdef __cplusplus
}
#endif

#endif  /*  _FLEXCAN_564xL_LIBRARY_H */

/*
*######################################################################
*                           End of File
*######################################################################
*/



