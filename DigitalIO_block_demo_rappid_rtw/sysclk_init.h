/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    sysclk_init.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   Declarations  for Mode Entry, System Clock,  CMU initialization functions
 *    @details The file contains declaration for Mode Entry, System Clock,
 *                          CMU initialization functions.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		7-May-2011
 *   Author:                         B13508
 *
 */

#ifndef _SYSCLK_INIT_H
#define _SYSCLK_INIT_H
#ifdef __cplusplus

extern "C"{

#endif

  /******************************************************************************
   *                Includes
   ******************************************************************************/
#include "target.h"
#include "sysclk.h"

  /******************************************************************************
   *                   Defines and Macros
   ******************************************************************************/

  /*
     Parameters shall be defined for specific configuration in sysclk_init*.c file
     IDF_0       Input Division Factor
     ODF_0      Output Division Factor
     NDIV_0    Loop Division Factor
   */
#define PLL_IDF_0                      (unsigned long)(((unsigned long)IDF_0) << 26)
#define PLL_ODF_0                      (unsigned long)(((unsigned long)ODF_0) << 24)
#define PLL_NDIV_0                     (unsigned long)(((unsigned long)NDIV_0) << 16)
#define PLL_VALUE_0                    PLL_IDF_0 | PLL_ODF_0 | PLL_NDIV_0

  /*
     Parameters shall be defined for specific configuration in sysclk_init*.c file
     IDF_1  Input Division Factor
     ODF_1  Output Division Factor
     NDIV_1  Loop Division Factor
   */
#define PLL_IDF_1                      (unsigned long)(((unsigned long)IDF_1) << 26)
#define PLL_ODF_1                      (unsigned long)(((unsigned long)ODF_1) << 24)
#define PLL_NDIV_1                     (unsigned long)(((unsigned long)NDIV_1) << 16)
#define PLL_VALUE_1                    PLL_IDF_1 | PLL_ODF_1 | PLL_NDIV_1

  /******************************************************************************
   * Global functions
   ******************************************************************************/
  void sysclk_module_init_fnc(void);
  void Mode_Entry_init_fnc(void);
  void mode_entry_post_config_fnc(void);
  void sysclk_init_fnc(void);
  void cmu_init_fnc (void);
  void mode_entry_post_config_fnc (void);

#ifdef __cplusplus

}
#endif
#endif                                 /*_SYSCLK_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
