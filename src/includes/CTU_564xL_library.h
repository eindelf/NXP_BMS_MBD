/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    CTU_564xL_library.h
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   Declarations for CTU_564xL_library.c file.
*    @details Declarations for CTU_564xL_library.c file.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		23-May-2011
*   Author:                         B13508
* 
*/

 
#ifndef _CTU_564xL_LIBRARY_H
#define _CTU_564xL_LIBRARY_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                Includes
******************************************************************************/

#include "target.h"
#include "sysclk.h"

/******************************************************************************
*                   Global function prototypes
******************************************************************************/

void ctu_init_pcr_out_564xL (uint8_t pcrNumTgr, uint8_t pcrNumIn);

void ctu_init_564xL (uint8_t Mode, uint32_t InputSelection, uint32_t const* TriggerOutput, 
                     uint8_t MRS, uint16_t MaxDelay_mks, uint16_t const* triggerDelay_mks,
					 uint32_t const* ADC_CmdIndex, uint16_t const* ADC_Commands);

void ctu_disable_isr_564xL(void);
  
#ifdef __cplusplus
}
#endif

#endif /* _CTU_564xL_LIBRARY_H */

/*
*######################################################################
*                           End of File
*######################################################################
*/
