/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    sine_wave_library.h
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   Sine wave module support.
*    @details Declarations for sine_wave_library.c file.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		2-Aug-2011
*   Author:                         b13508
* 
*/


#ifndef _SINEWAVE_564xL_LIBRARY_H
#define _SINEWAVE_564xL_LIBRARY_H

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

void sine_wave_init_564xL (uint16_t frequency, uint8_t IOAMPL);

void sine_wave_update_564xL (uint16_t frequency);

#ifdef __cplusplus
}
#endif
 
#endif /* _SINEWAVE_564xL_LIBRARY_H */

/*
*######################################################################
*                           End of File
*######################################################################
*/
