/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: can_simple_block_bu1114_private.h
 *
 * Code generated for Simulink model 'can_simple_block_bu1114'.
 *
 * Model version                  : 1.1239
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Jan 02 17:26:53 2018
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_can_simple_block_bu1114_private_h_
#define RTW_HEADER_can_simple_block_bu1114_private_h_
#include "rtwtypes.h"
#include "gpio_564xl_library.h"
#include "flexcan_564xl_library.h"
#include "dspi1_2_isr.h"
#include "dspi_564xl_library.h"
#include "dspi_564xl_library.h"
#include "can0_buf4_7_isr.h"
#include "pit_ch1_isr.h"
#include "pit_timer_564xl_library.h"
#include "adc0_config.h"
#include "can_simple_block_bu1114.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern void SPIRead_Outputs_wrapper(uint32_T *Vc1,
  uint32_T *Vc2,
  uint32_T *Vc3,
  uint32_T *PEC);
extern void SPITask_Outputs_wrapper(const uint8_T *CMD32,
  uint8_T *y0,
  uint8_T *PecChk);
extern void DMA_init_Outputs_wrapper();
extern real_T rt_roundd(real_T u);
extern void Subsystem_Reset(rtDW_Subsystem *localDW);
extern void Subsystem_i(rtDW_Subsystem *localDW, uint16_T rtd_CellV_1_104[104]);
extern void Subsystem(void);
extern void Subsystem2_Init(void);
extern void Subsystem2_Reset(void);
extern void Subsystem2_Start(void);
extern void Subsystem2(void);
extern void FunctionCallSubsystem_Init(void);
extern void FunctionCallSubsystem_Reset(void);
extern void FunctionCallSubsystem_Start(void);
extern void FunctionCallSubsystem(void);
extern void can_simple_block_bu1114_step0(void);
extern void can_simple_block_bu1114_step1(void);

#endif                                 /* RTW_HEADER_can_simple_block_bu1114_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
