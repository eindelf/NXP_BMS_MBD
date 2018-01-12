/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    adc_init.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   ADC  module init support.
 *    @details This file contains function declaration for ADC code File
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		2-Aug-2011
 *   Author:                         b13508
 *
 */

#ifndef _ADC_INIT_H
#define _ADC_INIT_H
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
  void adc_init_fnc(void);
  void adc_channel_setup_fnc(void);
  void adc_general_setup_fnc(void);
  void adc_sampling_setup_fnc(void);
  void adc_ctu_fnc(void);
  void adc_interrupt_setup_fnc(void);
  void adc_trigger_setup_fnc(void);
  void adc_dma_setup_fnc(void);

#ifdef __cplusplus

}
#endif
#endif                                 /*_ADC_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
