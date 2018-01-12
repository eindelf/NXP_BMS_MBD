/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: can_spi_simple_block_bu.h
 *
 * Code generated for Simulink model 'can_spi_simple_block_bu'.
 *
 * Model version                  : 1.96
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Nov 30 16:25:28 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_can_spi_simple_block_bu_h_
#define RTW_HEADER_can_spi_simple_block_bu_h_
#include <string.h>
#ifndef can_spi_simple_block_bu_COMMON_INCLUDES_
# define can_spi_simple_block_bu_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* can_spi_simple_block_bu_COMMON_INCLUDES_ */

#include "can_spi_simple_block_bu_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct {
  uint16_T CANReceiveDataTrigger1_o5;  /* '<Root>/CAN Receive Data Trigger1' */
  uint8_T CANReceiveDataTrigger1_o2;   /* '<Root>/CAN Receive Data Trigger1' */
  uint8_T CANReceiveDataTrigger1_o3;   /* '<Root>/CAN Receive Data Trigger1' */
  uint8_T CANReceiveDataTrigger1_o4[8];/* '<Root>/CAN Receive Data Trigger1' */
  uint8_T TmpSignalConversionAtCANTransmi[8];
  uint8_T In3[8];                      /* '<S1>/In3' */
} BlockIO_can_spi_simple_block_bu;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint8_T Out1[8];                     /* '<Root>/Out1' */
  uint8_T Out2;                        /* '<Root>/Out2' */
  uint8_T Out3;                        /* '<Root>/Out3' */
  uint16_T Out4;                       /* '<Root>/Out4' */
  uint8_T Out5;                        /* '<Root>/Out5' */
} ExternalOutputs_can_spi_simple_;

/* Block signals (auto storage) */
extern BlockIO_can_spi_simple_block_bu can_spi_simple_block_bu_B;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_can_spi_simple_ can_spi_simple_block_bu_Y;

/* Model entry point functions */
extern void can_spi_simple_block_bu_initialize(void);
extern void can_spi_simple_block_bu_step(void);
extern void can_spi_simple_block_bu_terminate(void);

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
 * '<Root>' : 'can_spi_simple_block_bu'
 * '<S1>'   : 'can_spi_simple_block_bu/Subsystem'
 */
#endif                                 /* RTW_HEADER_can_spi_simple_block_bu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
