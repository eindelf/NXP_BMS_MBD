/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    sys_init.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   initialization.
 *    @details initialization.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		2-Aug-2011
 *   Author:                         b13508
 *
 */

#ifndef _SYS_INIT_H
#define _SYS_INIT_H
#ifdef __cplusplus

extern "C"{

#endif

  /******************************************************************************
   *                  Includes
   ******************************************************************************/
#include "sysclk_init.h"

  /******************************************************************************
   *                   Defines and Macros
   ******************************************************************************/

  /*-----------------------------------------------------------*/
  /*        FCCU CF Key Register (FCCU_CFK)                    */
  /*-----------------------------------------------------------*/
#define FCCU_CFK_Key                   0x618B7A50                /* Critical fault key */

  /*-----------------------------------------------------------*/
  /*        FCCU NCF Key Register (FCCU_NCFK)                  */
  /*-----------------------------------------------------------*/
#define FCCU_NCFK_Key                  0xAB3498FE                /* Non-Critical fault key */

  /******************************************************************************
   *                   Global function prototypes
   ******************************************************************************/
  void sys_init_fnc(void);

#ifdef __cplusplus

}
#endif
#endif                                 /*_SYS_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
