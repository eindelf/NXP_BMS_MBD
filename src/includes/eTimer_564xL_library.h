/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    sine_wave_library.h
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   Declarations for eTimer_564xL_library.c file.
*    @details Declarations for eTimer_564xL_library.c file
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		2-Aug-2011
*   Author:                         b13508
* 
*/

#ifndef _ETIMER_564xL_LIBRARY_H
#define _ETIMER_564xL_LIBRARY_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/

#include "target.h"

/******************************************************************************
*                   Global function prototypes
******************************************************************************/

void etimer_init_pcr_in_out_564xL(uint8_t, uint8_t, uint8_t);

void etimer_init_564xL(uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t);
  
void etimer_564xL_update(uint16_t,uint16_t,uint16_t,uint16_t,uint16_t);  
  
void etimer_564xL_capture(uint16_t,uint16_t,uint16_t*,uint16_t*,uint16_t*,uint16_t*);  
  
#ifdef __cplusplus
}
#endif
 
#endif /* _ETIMER_564xL_LIBRARY_H  */

/*
*######################################################################
*                           End of File
*######################################################################
*/

