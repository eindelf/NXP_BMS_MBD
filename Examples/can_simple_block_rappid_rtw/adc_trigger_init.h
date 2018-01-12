/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    adc_trigger_init.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   This file contains functions declaration of ADC Trigger code file.
 *    @details This file contains functions declaration of ADC Trigger code file
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		2-Aug-2011
 *   Author:                         b13508
 *
 */

#ifndef _ADC_TRIGGER_INIT_H
#define _ADC_TRIGGER_INIT_H
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
  void adc_normal_start_fnc(void);
  void adc_injected_start_fnc(void);
  void adc_normal_stop_fnc(void);
  void adc_enter_powerdownmode_fnc(void);
  void adc_exit_powerdownmode_fnc(void);

#ifdef __cplusplus

}
#endif
#endif                                 /*_ADC_TRIGGER_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
