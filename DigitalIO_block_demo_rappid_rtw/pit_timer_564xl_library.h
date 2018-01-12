/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    pit_timer_564xl_library.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   PIR module support.
 *    @details Implementation ofPIT module functions.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		28-Oct-2010
 *   Author:                         r61406
 *
 */

#ifndef _PIT_TIMER_564xL_LIBRARY_H
#define _PIT_TIMER_564xL_LIBRARY_H
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
  void pit_timer_init_564xl( uint8_t chan, uint32_t timeout);

#ifdef __cplusplus

}
#endif
#endif                                 /*_PIT_TIMER_564xL_LIBRARY_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
