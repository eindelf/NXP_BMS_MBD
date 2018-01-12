/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    intc_init.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   This file contains the function prototype for intc source file.
 *    @details This file contains the function prototype for intc source file.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		2-Aug-2011
 *   Author:                         b13508
 *
 */

#ifndef _INTC_INIT_H
#define _INTC_INIT_H
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
  extern void intc_init_fnc (void);
  extern void en_int_fnc (vuint32_t priority);
  extern const uint32_t ISRVectorTable[];

#ifdef __cplusplus

}
#endif
#endif                                 /*_INTC_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
