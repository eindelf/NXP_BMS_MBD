/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: dspi_block.h
 *
 * Code generated for Simulink model 'dspi_block'.
 *
 * Model version                  : 1.100
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Dec 07 16:06:36 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_dspi_block_h_
#define RTW_HEADER_dspi_block_h_
#include <math.h>
#include <string.h>
#ifndef dspi_block_COMMON_INCLUDES_
# define dspi_block_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* dspi_block_COMMON_INCLUDES_ */

#include "dspi_block_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals for system '<S2>/Chart' */
typedef struct {
  real_T count;                        /* '<S2>/Chart' */
  boolean_T A;                         /* '<S2>/Chart' */
} rtB_Chart_dspi_block;

/* Block states (auto storage) for system '<S2>/Chart' */
typedef struct {
  uint8_T is_active_c5_dspi_block;     /* '<S2>/Chart' */
  uint8_T is_c5_dspi_block;            /* '<S2>/Chart' */
} rtDW_Chart_dspi_block;

/* Block signals (auto storage) */
typedef struct {
  uint16_T DataTypeConversion;         /* '<Root>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<Root>/Data Type Conversion1' */
  rtB_Chart_dspi_block sf_Chart_h;     /* '<S1>/Chart' */
  rtB_Chart_dspi_block sf_Chart_c;     /* '<S3>/Chart' */
  rtB_Chart_dspi_block sf_Chart;       /* '<S2>/Chart' */
} BlockIO_dspi_block;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int32_T clockTickCounter_l;          /* '<Root>/Pulse Generator1' */
  rtDW_Chart_dspi_block sf_Chart_h;    /* '<S1>/Chart' */
  rtDW_Chart_dspi_block sf_Chart_c;    /* '<S3>/Chart' */
  rtDW_Chart_dspi_block sf_Chart;      /* '<S2>/Chart' */
} D_Work_dspi_block;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint16_T Out2;                       /* '<Root>/Out2' */
  uint16_T Out1;                       /* '<Root>/Out1' */
} ExternalOutputs_dspi_block;

/* Block signals (auto storage) */
extern BlockIO_dspi_block dspi_block_B;

/* Block states (auto storage) */
extern D_Work_dspi_block dspi_block_DWork;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_dspi_block dspi_block_Y;

/* Model entry point functions */
extern void dspi_block_initialize(void);
extern void dspi_block_step(void);
extern void dspi_block_terminate(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'dspi_block'
 * '<S1>'   : 'dspi_block/Subsystem'
 * '<S2>'   : 'dspi_block/Subsystem1'
 * '<S3>'   : 'dspi_block/Subsystem2'
 * '<S4>'   : 'dspi_block/Subsystem/Chart'
 * '<S5>'   : 'dspi_block/Subsystem1/Chart'
 * '<S6>'   : 'dspi_block/Subsystem2/Chart'
 */
#endif                                 /* RTW_HEADER_dspi_block_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
