/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: DigitalIO_block_demo_private.h
 *
 * Code generated for Simulink model 'DigitalIO_block_demo'.
 *
 * Model version                  : 1.173
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Jul 27 15:22:07 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DigitalIO_block_demo_private_h_
#define RTW_HEADER_DigitalIO_block_demo_private_h_
#include "rtwtypes.h"
#include "gpio_564xl_library.h"
#include "gt_pf.h"
#include "profile_buffer.h"
#include "pit_ch1_isr.h"
#include "pit_timer_564xl_library.h"
#include "DigitalIO_block_demo.h"

extern void Dig_FunctionCallSubsystem1_Init(void);
extern void Di_FunctionCallSubsystem1_Reset(void);
extern void Di_FunctionCallSubsystem1_Start(void);
extern void DigitalI_FunctionCallSubsystem1(void);
extern void Dig_FunctionCallSubsystem2_Init(void);
extern void Di_FunctionCallSubsystem2_Reset(void);
extern void Di_FunctionCallSubsystem2_Start(void);
extern void DigitalI_FunctionCallSubsystem2(void);
extern void Digi_FunctionCallSubsystem_Init(void);
extern void Dig_FunctionCallSubsystem_Reset(void);
extern void Dig_FunctionCallSubsystem_Start(void);
extern void DigitalIO_FunctionCallSubsystem(void);

#endif                                 /* RTW_HEADER_DigitalIO_block_demo_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
