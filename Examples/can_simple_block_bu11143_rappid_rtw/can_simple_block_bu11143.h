/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: can_simple_block_bu11143.h
 *
 * Code generated for Simulink model 'can_simple_block_bu11143'.
 *
 * Model version                  : 1.1706
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Jan 11 15:01:28 2018
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_can_simple_block_bu11143_h_
#define RTW_HEADER_can_simple_block_bu11143_h_
#include <math.h>
#ifndef can_simple_block_bu11143_COMMON_INCLUDES_
# define can_simple_block_bu11143_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* can_simple_block_bu11143_COMMON_INCLUDES_ */

#include "can_simple_block_bu11143_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T count;                        /* '<S2>/Chart1' */
  real_T count_c;                      /* '<S4>/Data collection chart' */
  real_T count_a;                      /* '<S4>/Chart' */
  int32_T PackI;                       /* '<Root>/Data Store Memory2' */
  uint32_T SFunctionBuilder1_o1;       /* '<S9>/S-Function Builder1' */
  uint32_T SFunctionBuilder1_o2;       /* '<S9>/S-Function Builder1' */
  uint32_T SFunctionBuilder1_o3;       /* '<S9>/S-Function Builder1' */
  uint32_T SFunctionBuilder1_o4;       /* '<S9>/S-Function Builder1' */
  int16_T CellSOP_1_104[104];          /* '<Root>/Data Store Memory4' */
  uint16_T CellV_1_104[104];           /* '<Root>/Data Store Memory' */
  uint16_T CellGP_1_78[78];            /* '<Root>/Data Store Memory1' */
  uint16_T CellSOC_1_104[104];         /* '<Root>/Data Store Memory3' */
  uint16_T CANReceiveDataTrigger1_o5;  /* '<Root>/CAN Receive Data Trigger1' */
  uint16_T count_k;                    /* '<S9>/Chart' */
  uint16_T V_REF_AUX;                  /* '<Root>/Data Store Memory5' */
  uint8_T CANReceiveDataTrigger1_o4[8];/* '<Root>/CAN Receive Data Trigger1' */
  uint8_T VTDataCAN_8b[8];             /* '<S2>/RawData to StoreData1' */
  uint8_T VTDataCAN_8b_a[8];           /* '<S2>/RawData to StoreData' */
  uint8_T SFunctionBuilder_o1[104];    /* '<S4>/S-Function Builder' */
  uint8_T SFunctionBuilder_o2[26];     /* '<S4>/S-Function Builder' */
  uint8_T CMD32[4];                    /* '<S4>/Data collection chart' */
  uint8_T In3[8];                      /* '<S7>/In3' */
  uint8_T CANReceiveDataTrigger1_o2;   /* '<Root>/CAN Receive Data Trigger1' */
  uint8_T CANReceiveDataTrigger1_o3;   /* '<Root>/CAN Receive Data Trigger1' */
  uint8_T is_active_c48_can_simple_block_;/* '<S2>/Chart1' */
  uint8_T is_c48_can_simple_block_bu11143;/* '<S2>/Chart1' */
  uint8_T is_active_c15_can_simple_block_;/* '<S4>/Data collection chart' */
  uint8_T is_c15_can_simple_block_bu11143;/* '<S4>/Data collection chart' */
  uint8_T is_active_c7_can_simple_block_b;/* '<S4>/Chart' */
  uint8_T is_c7_can_simple_block_bu11143;/* '<S4>/Chart' */
  uint8_T is_active_c1_can_simple_block_b;/* '<S9>/Chart' */
  uint8_T is_c1_can_simple_block_bu11143;/* '<S9>/Chart' */
  boolean_T A;                         /* '<S4>/Chart' */
  boolean_T A_m;                       /* '<S9>/Chart' */
} D_Work;

/* Invariant block signals (auto storage) */
typedef struct {
  const uint16_T DataTypeConversion;   /* '<S61>/Data Type Conversion' */
  const uint16_T DataTypeConversion1;  /* '<S61>/Data Type Conversion1' */
} ConstBlockIO;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T var1;                         /* '<Root>/In1' */
} ExternalInputs;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint8_T Out1[8];                     /* '<Root>/Out1' */
  uint8_T Out2;                        /* '<Root>/Out2' */
  uint8_T Out3;                        /* '<Root>/Out3' */
  uint16_T Out4;                       /* '<Root>/Out4' */
  uint8_T Out5;                        /* '<Root>/Out5' */
  uint16_T Out7;                       /* '<Root>/Out7' */
} ExternalOutputs;

/* Block signals and states (auto storage) */
extern D_Work rtDWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs rtY;
extern const ConstBlockIO rtConstB;    /* constant block i/o */

/* Model entry point functions */
extern void can_simple_block_bu11143_initialize(void);
extern void can_simple_block_bu11143_step(void);
extern void can_simple_block_bu11143_terminate(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion4' : Unused code path elimination
 * Block '<S4>/Gain' : Unused code path elimination
 */

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
 * '<Root>' : 'can_simple_block_bu11143'
 * '<S1>'   : 'can_simple_block_bu11143/Chart'
 * '<S2>'   : 'can_simple_block_bu11143/DataDumpFast'
 * '<S3>'   : 'can_simple_block_bu11143/DataDumpFast1'
 * '<S4>'   : 'can_simple_block_bu11143/Function-Call Subsystem'
 * '<S5>'   : 'can_simple_block_bu11143/MATLAB Function'
 * '<S6>'   : 'can_simple_block_bu11143/MATLAB Function2'
 * '<S7>'   : 'can_simple_block_bu11143/Subsystem'
 * '<S8>'   : 'can_simple_block_bu11143/Subsystem1'
 * '<S9>'   : 'can_simple_block_bu11143/Subsystem2'
 * '<S10>'  : 'can_simple_block_bu11143/Subsystem3'
 * '<S11>'  : 'can_simple_block_bu11143/Subsystem4'
 * '<S12>'  : 'can_simple_block_bu11143/DataDumpFast/Chart1'
 * '<S13>'  : 'can_simple_block_bu11143/DataDumpFast/Chart2'
 * '<S14>'  : 'can_simple_block_bu11143/DataDumpFast/RawData to StoreData'
 * '<S15>'  : 'can_simple_block_bu11143/DataDumpFast/RawData to StoreData1'
 * '<S16>'  : 'can_simple_block_bu11143/DataDumpFast1/Chart2'
 * '<S17>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData'
 * '<S18>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData1'
 * '<S19>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData10'
 * '<S20>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData11'
 * '<S21>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData12'
 * '<S22>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData13'
 * '<S23>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData14'
 * '<S24>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData15'
 * '<S25>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData16'
 * '<S26>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData17'
 * '<S27>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData18'
 * '<S28>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData19'
 * '<S29>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData2'
 * '<S30>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData20'
 * '<S31>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData21'
 * '<S32>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData22'
 * '<S33>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData23'
 * '<S34>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData24'
 * '<S35>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData25'
 * '<S36>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData26'
 * '<S37>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData3'
 * '<S38>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData4'
 * '<S39>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData5'
 * '<S40>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData6'
 * '<S41>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData7'
 * '<S42>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData8'
 * '<S43>'  : 'can_simple_block_bu11143/DataDumpFast1/RawData to StoreData9'
 * '<S44>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Chart'
 * '<S45>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Chart2'
 * '<S46>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Chart3'
 * '<S47>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Chart4'
 * '<S48>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Chart5'
 * '<S49>'  : 'can_simple_block_bu11143/Function-Call Subsystem/DMA_Init'
 * '<S50>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Data collection chart'
 * '<S51>'  : 'can_simple_block_bu11143/Function-Call Subsystem/MATLAB Function1'
 * '<S52>'  : 'can_simple_block_bu11143/Function-Call Subsystem/MATLAB Function2'
 * '<S53>'  : 'can_simple_block_bu11143/Function-Call Subsystem/PEC generation'
 * '<S54>'  : 'can_simple_block_bu11143/Function-Call Subsystem/RawData to StoreData'
 * '<S55>'  : 'can_simple_block_bu11143/Function-Call Subsystem/RawData to StoreData (SPICh1)'
 * '<S56>'  : 'can_simple_block_bu11143/Function-Call Subsystem/SOCKF_Init1'
 * '<S57>'  : 'can_simple_block_bu11143/Function-Call Subsystem/SOCKF_Run'
 * '<S58>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem'
 * '<S59>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem1'
 * '<S60>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem2'
 * '<S61>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem3'
 * '<S62>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem4'
 * '<S63>'  : 'can_simple_block_bu11143/Function-Call Subsystem/T_DUMP_CAN'
 * '<S64>'  : 'can_simple_block_bu11143/Function-Call Subsystem/V_DUMP_CAN'
 * '<S65>'  : 'can_simple_block_bu11143/Function-Call Subsystem/SOCKF_Run/Chart1'
 * '<S66>'  : 'can_simple_block_bu11143/Function-Call Subsystem/SOCKF_Run/RawData to StoreData'
 * '<S67>'  : 'can_simple_block_bu11143/Function-Call Subsystem/SOCKF_Run/RawData to StoreData1'
 * '<S68>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem/Chart1'
 * '<S69>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem/RawData to StoreData'
 * '<S70>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem1/Chart1'
 * '<S71>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem1/RawData to StoreData'
 * '<S72>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem2/Chart1'
 * '<S73>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem2/RawData to StoreData'
 * '<S74>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem4/Chart1'
 * '<S75>'  : 'can_simple_block_bu11143/Function-Call Subsystem/Subsystem4/RawData to StoreData'
 * '<S76>'  : 'can_simple_block_bu11143/Subsystem1/Chart'
 * '<S77>'  : 'can_simple_block_bu11143/Subsystem1/SPI_SEND_SYSTEM'
 * '<S78>'  : 'can_simple_block_bu11143/Subsystem1/SPI_SEND_SYSTEM/PEC generation'
 * '<S79>'  : 'can_simple_block_bu11143/Subsystem1/SPI_SEND_SYSTEM/SPI_SEND_STATE_FLOW'
 * '<S80>'  : 'can_simple_block_bu11143/Subsystem2/Chart'
 * '<S81>'  : 'can_simple_block_bu11143/Subsystem3/Chart'
 * '<S82>'  : 'can_simple_block_bu11143/Subsystem4/Chart'
 */
#endif                                 /* RTW_HEADER_can_simple_block_bu11143_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
