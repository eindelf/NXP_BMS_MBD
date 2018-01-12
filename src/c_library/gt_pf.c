/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    gt_pf.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   profiler support.
*    @details profiler support.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		23-May-2011
*   Author:                         r61406
* 
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/
 
#include "gt_pf.h"
#ifdef __MWERKS__                      /* CodeWarrior Compiler VLE */

uint32_t gt_pf(void)
{
  vuint32_t tmp1;
  asm("e_li r0, 0x4000");
  asm("mthid0 r0");
  asm("mftbl r12");
  asm("e_stw r12,tmp1");
  return tmp1;
}

#endif

#ifdef __DCC__                         /* Diab Compiler */

asm uint32_t gt_pf_macro(void)
{
  e_li r0, 0x4000
  mthid0 r0
  mftbl r3
} uint32_t gt_pf(void)
{
  return(gt_pf_macro());
}

#endif

#ifdef __ghs__                         /* Greenhills Compiler */

asm uint32_t gt_pf_macro(void)
{
  e_li r0, 0x4000;
  mthid0 r0;
  mftbl r3
} uint32_t gt_pf(void)
{
  return(gt_pf_macro());
}

#endif

#ifdef __cplusplus
}
#endif

/*
*######################################################################
*                           End of File
*######################################################################
*/
