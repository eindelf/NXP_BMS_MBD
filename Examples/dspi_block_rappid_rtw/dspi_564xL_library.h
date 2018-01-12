/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    dspi_564xL_library.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   DSPI module support.
 *    @details Declarations for dspi_564xL_library.c file.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		2-Aug-2011
 *   Author:                         b13508
 *
 */

#ifndef _DSPI_564xL_LIBRARY_H
#define _DSPI_564xL_LIBRARY_H
#ifdef __cplusplus

extern "C"{

#endif

  /******************************************************************************
   *                  Includes
   ******************************************************************************/
#include "target.h"

  /******************************************************************************
   *                   Defines and Macros
   ******************************************************************************/
#define DSPI0                          0
#define DSPI1                          1
#define DSPI2                          2
#define DSPI_ISR_TCF_RE                0x80000000
#define DSPI_ISR_EOQF_RE               0x10000000
#define DSPI_ISR_TFUF_RE               0x08000000
#define DSPI_ISR_TFFF_RE               0x02000000
#define DSPI_ISR_TFFF_DIRS             0x01000000
#define DSPI_ISR_SPEF_RE               0x00200000
#define DSPI_ISR_RFOF_RE               0x00080000
#define DSPI_ISR_RFDF_RE               0x00020000
#define DSPI_ISR_RFDF_DIRS             0x00010000

  /******************************************************************************
   *                   Global function prototypes
   ******************************************************************************/
  uint16_t dspi_564xl_read_master(uint8_t dspi_num);
  uint16_t dspi_564xl_read_slave(uint8_t dspi_num);
  uint32_t dspi_564xl_get_status(uint8_t dspiNum);
  void dspi_564xl_send(uint8_t dspi_num, DSPI_PUSHR_32B_tag pushr_data);
  void dspi_564xl_config(uint8_t, uint32_t, uint32_t);
  void dspi_564xl_pin_init(uint8_t pcr_num, uint8_t in_out, uint8_t dspi_num);
  void dspi_564xl_interrupt_set(uint8_t dspiNum, uint32_t flag);
  void dspi_564xl_interrupt_clr(uint8_t dspiNum, uint32_t flag);

#ifdef __cplusplus

}
#endif
#endif                                 /* _DSPI_564xL_LIBRARY_H */

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
