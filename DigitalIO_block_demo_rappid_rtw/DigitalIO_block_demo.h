/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: DigitalIO_block_demo.h
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

#ifndef RTW_HEADER_DigitalIO_block_demo_h_
#define RTW_HEADER_DigitalIO_block_demo_h_
#include <string.h>
#ifndef DigitalIO_block_demo_COMMON_INCLUDES_
# define DigitalIO_block_demo_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DigitalIO_block_demo_COMMON_INCLUDES_ */

#include "DigitalIO_block_demo_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct {
  real_T count_d;                      /* '<S4>/Chart' */
  real_T count_k;                      /* '<S3>/Chart' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
  boolean_T DigitalInput1;             /* '<S2>/Digital Input1' */
  boolean_T LogicalOperator_d;         /* '<S2>/Logical Operator' */
  boolean_T DigitalInput1_n;           /* '<S4>/Digital Input1' */
  boolean_T LogicalOperator_df;        /* '<S4>/Logical Operator' */
  boolean_T DigitalInput1_h;           /* '<S3>/Digital Input1' */
  boolean_T LogicalOperator_n;         /* '<S3>/Logical Operator' */
} BlockIO_DigitalIO_block_demo;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c2_DigitalIO_block_de;/* '<S2>/Chart' */
  uint8_T is_c2_DigitalIO_block_demo;  /* '<S2>/Chart' */
  uint8_T is_active_c4_DigitalIO_block_de;/* '<S4>/Chart' */
  uint8_T is_c4_DigitalIO_block_demo;  /* '<S4>/Chart' */
  uint8_T is_active_c3_DigitalIO_block_de;/* '<S3>/Chart' */
  uint8_T is_c3_DigitalIO_block_demo;  /* '<S3>/Chart' */
  uint8_T is_active_c1_DigitalIO_block_de;/* '<Root>/Chart' */
  uint8_T is_A;                        /* '<Root>/Chart' */
  uint8_T is_active_A;                 /* '<Root>/Chart' */
  uint8_T is_active_A1;                /* '<Root>/Chart' */
} D_Work_DigitalIO_block_demo;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In2;                          /* '<Root>/In2' */
  real_T In3;                          /* '<Root>/In3' */
  real_T In4;                          /* '<Root>/In4' */
} ExternalInputs_DigitalIO_block_;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out3;                         /* '<Root>/Out3' */
  real_T Out4;                         /* '<Root>/Out4' */
  real_T Out5;                         /* '<Root>/Out5' */
  boolean_T Out7;                      /* '<Root>/Out7' */
} ExternalOutputs_DigitalIO_block;

/* Block signals (auto storage) */
extern BlockIO_DigitalIO_block_demo DigitalIO_block_demo_B;

/* Block states (auto storage) */
extern D_Work_DigitalIO_block_demo DigitalIO_block_demo_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_DigitalIO_block_ DigitalIO_block_demo_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_DigitalIO_block DigitalIO_block_demo_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T In;                      /* '<Root>/In1' */
extern real_T Out;                     /* '<Root>/Gain' */
extern real_T count;                   /* '<Root>/Chart' */
extern real32_T countX;                /* '<S2>/Chart' */
extern boolean_T StateA;               /* '<S2>/Chart' */

/* Model entry point functions */
extern void DigitalIO_block_demo_initialize(void);
extern void DigitalIO_block_demo_step(void);
extern void DigitalIO_block_demo_terminate(void);

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
 * '<Root>' : 'DigitalIO_block_demo'
 * '<S1>'   : 'DigitalIO_block_demo/Chart'
 * '<S2>'   : 'DigitalIO_block_demo/Function-Call Subsystem'
 * '<S3>'   : 'DigitalIO_block_demo/Function-Call Subsystem1'
 * '<S4>'   : 'DigitalIO_block_demo/Function-Call Subsystem2'
 * '<S5>'   : 'DigitalIO_block_demo/Function-Call Subsystem/Chart'
 * '<S6>'   : 'DigitalIO_block_demo/Function-Call Subsystem1/Chart'
 * '<S7>'   : 'DigitalIO_block_demo/Function-Call Subsystem2/Chart'
 */
#endif                                 /* RTW_HEADER_DigitalIO_block_demo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
