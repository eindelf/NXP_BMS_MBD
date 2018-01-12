/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    siu_init.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   This File contains functions declaration of SIU code file.
 *    @details This File contains functions declaration of SIU code file.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		2-Aug-2011
 *   Author:                         b13508
 *
 */

#ifndef _SIU_INIT_H
#define _SIU_INIT_H
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
  void siu_init_fnc(void);
  void siu_portA_init_fnc(void);
  void siu_portB_init_fnc(void);
  void siu_portC_init_fnc(void);
  void siu_portD_init_fnc(void);
  void siu_portE_init_fnc(void);
  void siu_portF_init_fnc(void);
  void siu_portG_init_fnc(void);
  void siu_portH_init_fnc(void);
  void siu_portI_init_fnc(void);
  void siu_general_init_fnc(void);
  void siu_parallel_port_init_fnc(void);
  void siu_unused_pins_init_fnc(void);
  void siu_psmi_init_fnc(void);

#ifdef __cplusplus

}
#endif
#endif                                 /*_SIU_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
