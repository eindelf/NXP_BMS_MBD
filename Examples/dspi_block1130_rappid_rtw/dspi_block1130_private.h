/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: dspi_block1130_private.h
 *
 * Code generated for Simulink model 'dspi_block1130'.
 *
 * Model version                  : 1.97
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Dec 21 13:59:05 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_dspi_block1130_private_h_
#define RTW_HEADER_dspi_block1130_private_h_
#include "rtwtypes.h"
#include "gpio_564xl_library.h"
#include "dspi_564xl_library.h"
#include "dspi1_isr.h"
#include "dspi0_4_isr.h"
#include "dspi_block1130.h"

extern void dspi_block1130_Chart_Init(rtB_Chart_dspi_block1130 *localB,
  rtDW_Chart_dspi_block1130 *localDW);
extern void dspi_block1130_Chart_Reset(rtB_Chart_dspi_block1130 *localB,
  rtDW_Chart_dspi_block1130 *localDW);
extern void dspi_block1130_Chart(rtB_Chart_dspi_block1130 *localB,
  rtDW_Chart_dspi_block1130 *localDW);
extern void dspi_block1130_Subsystem1_Init(void);
extern void dspi_block1130_Subsystem1_Reset(void);
extern void dspi_block1130_Subsystem1_Start(void);
extern void dspi_block1130_Subsystem1(void);
extern void dspi_block1130_Subsystem2_Init(void);
extern void dspi_block1130_Subsystem2_Reset(void);
extern void dspi_block1130_Subsystem2_Start(void);
extern void dspi_block1130_Subsystem2(void);
extern void dspi_block1130_Subsystem_Init(void);
extern void dspi_block1130_Subsystem_Reset(void);
extern void dspi_block1130_Subsystem_Start(void);
extern void dspi_block1130_Subsystem(void);

#endif                                 /* RTW_HEADER_dspi_block1130_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
