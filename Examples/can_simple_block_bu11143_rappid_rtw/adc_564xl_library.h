/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    adc_564xl_library.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   Declarations for adc_564xl_library.c file and ADC Registers.
 *    @details Detailed description.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		23-May-2011
 *   Author:             B14423
 *
 */

#ifndef _ADC_564xL_LIBRARY_H
#define _ADC_564xL_LIBRARY_H
#ifdef __cplusplus

extern "C"{

#endif

  /******************************************************************************
   *                Includes
   ******************************************************************************/
#include "target.h"

#pragma dont_inline off

  /******************************************************************************
   *                   Defines and Macros
   ******************************************************************************/
#define ADC_ISR_IMR_MSKEOCTU           0x10U
#define ADC_ISR_IMR_MSKJEOC            0x8U
#define ADC_ISR_IMR_MSKJECH            0x4U
#define ADC_ISR_IMR_MSKEOC             0x2U
#define ADC_ISR_IMR_MSKECH             0x1U

  /******************************************************************************
   *                   Global function prototypes
   ******************************************************************************/
  void adc_wdg_init(uint8_t, uint8_t, uint16_t, uint16_t);

  /* ADC Read Data function */
  uint16_t adc_read_chan(uint8_t adc_num, uint8_t adc_chan_in);

  /* ADC Channel Pin Configuration Setup */
  void adc_pin_init( uint8_t adc_num, uint8_t adc_chan_in );
  void adc_channelmode_setup(uint8_t adc_num, uint8_t adc_chan, uint8_t adc_mode);
  void adc_presample( uint8_t adc_num, uint8_t adc_chan, uint8_t adc_presample);
  void adc_singleshot_set(uint8_t adc_num);
  void adc_scanmode_set(uint8_t adc_num);
  void adc_normal_start( uint8_t adc_num );
  void adc_normal_stop( uint8_t adc_num );
  void adc_injected_start(uint8_t adc_num);

  /* ADC interrupt configuration */
  void adc_interrupt_set_imr( uint8_t adc_num, uint8_t adc_isr_mode);
  void adc_interrupt_set_channel( uint8_t adc_num, uint8_t adc_chan);
  void adc_interrupt_clear_channel( uint8_t adc_num, uint8_t adc_chan);

#endif

  /*
   *######################################################################
   *                           End of File
   *######################################################################
   */
