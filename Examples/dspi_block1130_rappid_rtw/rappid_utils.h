/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    rappid_utils.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   utility functions.
 *    @details utility functions.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		23-May-2011
 *   Author:                         B14423
 *
 */

#ifndef _RAPPID_UTIL_H
#define _RAPPID_UTIL_H
#ifdef __cplusplus

extern "C"{

#endif

  /********************  Dependent Include files here **********************/
#include "typedefs.h"

  /******************************************************************************
   *                   Defines and Macros
   ******************************************************************************/
#define SIZE_32BITS                    4
#define SIZE_16BITS                    2
#define SIZE_8BITS                     1

  /******************************************************************************
   *                   Global function prototypes
   ******************************************************************************/
  extern void IVOR4Handler(void);      /* defined in sw_handlers.s */
  extern void EnableExternalInterrupts (void);
  extern void DisableExternalInterrupts (void);
  extern void fs_clearmem(vuint8_t* address , uint8_t size, uint8_t fillbyte);

#ifdef __cplusplus

}
#endif

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
#endif                                 /* _RAPPID_UTIL_H */
