/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    flexpwm_init.h
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   FlexPWM module support.
*    @details This file contains declaration of functions 
 *                          present in FlexPWM Source File.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		2-Aug-2011
*   Author:                         b13508
* 
*/

#ifndef  _FLEXPWM_INIT_H
#define  _FLEXPWM_INIT_H

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

void flexpwm_init_fnc(void);
void flexpwm_sub0_init_fnc(uint8_t pwmMod);
void flexpwm_sub1_init_fnc(uint8_t pwmMod);
void flexpwm_sub2_init_fnc(uint8_t pwmMod);
void flexpwm_sub3_init_fnc(uint8_t pwmMod);
void flexpwm_GenConfig_fnc(uint8_t pwmMod);

#ifdef __cplusplus
}
#endif

#endif  /*_FLEXPWM_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

