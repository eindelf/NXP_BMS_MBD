/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Extended.h
 *
 * Code generated for Simulink model 'Extended'.
 *
 * Model version                  : 1.1572
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Jan 02 13:13:31 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->MPC55xx
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. Traceability
 * Validation result: Not run
 */
#include "target.h"

#ifndef RTW_HEADER_Extended_h_
#define RTW_HEADER_Extended_h_
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef Extended_COMMON_INCLUDES_
# define Extended_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Extended_COMMON_INCLUDES_ */

/* Child system includes */
#include "Extended.h"
#include "Extended.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Custom Type definition for MATLAB Function: '<S13>/Correct' */
#ifndef struct_tag_scxndYM7OYO4w1HoE8FKFpE
#define struct_tag_scxndYM7OYO4w1HoE8FKFpE

struct tag_scxndYM7OYO4w1HoE8FKFpE
{
  char_T FcnName[21];
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_scxndYM7OYO4w1HoE8FKFpE*/

#ifndef typedef_scxndYM7OYO4w1HoE8FKFpE
#define typedef_scxndYM7OYO4w1HoE8FKFpE

typedef struct tag_scxndYM7OYO4w1HoE8FKFpE scxndYM7OYO4w1HoE8FKFpE;

#endif                                 /*typedef_scxndYM7OYO4w1HoE8FKFpE*/

/* Custom Type definition for MATLAB Function: '<S15>/Predict' */
#ifndef struct_tag_sFKE8rssoF0K4aXjRjhZCFG
#define struct_tag_sFKE8rssoF0K4aXjRjhZCFG

struct tag_sFKE8rssoF0K4aXjRjhZCFG
{
  char_T FcnName[15];
  real_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sFKE8rssoF0K4aXjRjhZCFG*/

#ifndef typedef_sFKE8rssoF0K4aXjRjhZCFG
#define typedef_sFKE8rssoF0K4aXjRjhZCFG

typedef struct tag_sFKE8rssoF0K4aXjRjhZCFG sFKE8rssoF0K4aXjRjhZCFG;

#endif                                 /*typedef_sFKE8rssoF0K4aXjRjhZCFG*/

/* Custom Type definition for MATLAB Function: '<S34>/Correct' */
#ifndef struct_tag_sjHMwlQwsKjeklylkLkVdsH
#define struct_tag_sjHMwlQwsKjeklylkLkVdsH

struct tag_sjHMwlQwsKjeklylkLkVdsH
{
  char_T FcnName[21];
  boolean_T HasAdditiveNoise;
  real_T Alpha;
  real_T Beta;
  real_T Kappa;
};

#endif                                 /*struct_tag_sjHMwlQwsKjeklylkLkVdsH*/

#ifndef typedef_sjHMwlQwsKjeklylkLkVdsH
#define typedef_sjHMwlQwsKjeklylkLkVdsH

typedef struct tag_sjHMwlQwsKjeklylkLkVdsH sjHMwlQwsKjeklylkLkVdsH;

#endif                                 /*typedef_sjHMwlQwsKjeklylkLkVdsH*/

/* Custom Type definition for MATLAB Function: '<S36>/Predict' */
#ifndef struct_tag_swDHwngkV09umpvRH3XXilD
#define struct_tag_swDHwngkV09umpvRH3XXilD

struct tag_swDHwngkV09umpvRH3XXilD
{
  char_T FcnName[15];
  boolean_T HasAdditiveNoise;
  real_T Alpha;
  real_T Beta;
  real_T Kappa;
};

#endif                                 /*struct_tag_swDHwngkV09umpvRH3XXilD*/

#ifndef typedef_swDHwngkV09umpvRH3XXilD
#define typedef_swDHwngkV09umpvRH3XXilD

typedef struct tag_swDHwngkV09umpvRH3XXilD swDHwngkV09umpvRH3XXilD;

#endif                                 /*typedef_swDHwngkV09umpvRH3XXilD*/

/* Block signals and states (auto storage) for system '<S1>/Extended Kalman Filter1' */
typedef struct {
  real_T P_g[9];                       /* '<S2>/DataStoreMemory - P' */
  real_T x[3];                         /* '<S2>/DataStoreMemory - x' */
} DW_ExtendedKalmanFilter1;

/* Block signals and states (auto storage) for system '<S1>/Extended Kalman Filter2' */
typedef struct {
  real_T P_c[9];                       /* '<S3>/DataStoreMemory - P' */
  real_T x[3];                         /* '<S3>/DataStoreMemory - x' */
} DW_ExtendedKalmanFilter2;

/* Block signals and states (auto storage) for system '<S1>/Unscented Kalman Filter1' */
typedef struct {
  real_T P_c[9];                       /* '<S8>/DataStoreMemory - P' */
  real_T x[3];                         /* '<S8>/DataStoreMemory - x' */
} DW_UnscentedKalmanFilter1;

/* Block signals and states (auto storage) for system '<S1>/Unscented Kalman Filter4' */
typedef struct {
  real_T P_f[9];                       /* '<S11>/DataStoreMemory - P' */
  real_T x[3];                         /* '<S11>/DataStoreMemory - x' */
} DW_UnscentedKalmanFilter4;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  DW_UnscentedKalmanFilter4 UnscentedKalmanFilter5;/* '<S1>/Unscented Kalman Filter5' */
  DW_UnscentedKalmanFilter4 UnscentedKalmanFilter4_n;/* '<S1>/Unscented Kalman Filter4' */
  DW_UnscentedKalmanFilter1 UnscentedKalmanFilter3;/* '<S1>/Unscented Kalman Filter3' */
  DW_UnscentedKalmanFilter1 UnscentedKalmanFilter1_g;/* '<S1>/Unscented Kalman Filter1' */
  DW_ExtendedKalmanFilter1 ExtendedKalmanFilter4;/* '<S1>/Extended Kalman Filter4' */
  DW_ExtendedKalmanFilter2 ExtendedKalmanFilter3;/* '<S1>/Extended Kalman Filter3' */
  DW_ExtendedKalmanFilter2 ExtendedKalmanFilter2_i;/* '<S1>/Extended Kalman Filter2' */
  DW_ExtendedKalmanFilter1 ExtendedKalmanFilter1_g;/* '<S1>/Extended Kalman Filter1' */
} DW;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  int16_T I;                           /* '<Root>/I' */
  uint16_T signal1;                    /* '<Root>/signal1' */
  uint16_T signal2;                    /* '<Root>/signal2' */
  uint16_T signal3;                    /* '<Root>/signal3' */
  uint16_T signal4;                    /* '<Root>/signal4' */
  uint16_T signal5;                    /* '<Root>/signal5' */
  uint16_T signal6;                    /* '<Root>/signal6' */
  uint16_T signal7;                    /* '<Root>/signal7' */
  uint16_T signal8;                    /* '<Root>/signal8' */
  int16_T Temperature;                 /* '<Root>/Temperature' */
  uint16_T Cq;                         /* '<Root>/Cq' */
  boolean_T signal1_h;                 /* '<Root>/signal1b' */
  boolean_T signal2_p;                 /* '<Root>/signal2b' */
  boolean_T signal3_c;                 /* '<Root>/signal3b' */
  boolean_T signal4_g;                 /* '<Root>/signal4b' */
  boolean_T signal5_d;                 /* '<Root>/signal5b' */
  boolean_T signal6_a;                 /* '<Root>/signal6b' */
  boolean_T signal7_n;                 /* '<Root>/signal7b' */
  boolean_T signal8_a;                 /* '<Root>/signal8b' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T y;                            /* '<Root>/y' */
  real_T OCV_esti;                     /* '<Root>/OCV_esti' */
  real_T signal1a[9];                  /* '<Root>/signal1a' */
  real_T signal2a[9];                  /* '<Root>/signal2a' */
  real_T signal3a[9];                  /* '<Root>/signal3a' */
  real_T signal4a[9];                  /* '<Root>/signal4a' */
  real_T signal5a[9];                  /* '<Root>/signal5a' */
  real_T signal6a[9];                  /* '<Root>/signal6a' */
  real_T signal7a[9];                  /* '<Root>/signal7a' */
  real_T signal8a[9];                  /* '<Root>/signal8a' */
  real_T signal1c[3];                  /* '<Root>/signal1c' */
  real_T signal2c[3];                  /* '<Root>/signal2c' */
  real_T signal3c[3];                  /* '<Root>/signal3c' */
  real_T signal4c[3];                  /* '<Root>/signal4c' */
  real_T signal5c[3];                  /* '<Root>/signal5c' */
  real_T signal6c[3];                  /* '<Root>/signal6c' */
  real_T signal7c[3];                  /* '<Root>/signal7c' */
  real_T signal8c[3];                  /* '<Root>/signal8c' */
  uint16_T signal1d;                   /* '<Root>/signal1d' */
  uint16_T signal2d;                   /* '<Root>/signal2d' */
  uint16_T signal3d;                   /* '<Root>/signal3d' */
  uint16_T signal4d;                   /* '<Root>/signal4d' */
  uint16_T signal5d;                   /* '<Root>/signal5d' */
  uint16_T signal6d;                   /* '<Root>/signal6d' */
  uint16_T signal7d;                   /* '<Root>/signal7d' */
  uint16_T signal8d;                   /* '<Root>/signal8d' */
  int16_T signal1e;                    /* '<Root>/signal1e' */
  int16_T signal2e;                    /* '<Root>/signal2e' */
  int16_T signal3e;                    /* '<Root>/signal3e' */
  int16_T signal4e;                    /* '<Root>/signal4e' */
  int16_T signal5e;                    /* '<Root>/signal5e' */
  int16_T signal6e;                    /* '<Root>/signal6e' */
  int16_T signal7e;                    /* '<Root>/signal7e' */
  int16_T signal8e;                    /* '<Root>/signal8e' */
  real_T signal1f;                     /* '<Root>/signal1f' */
  real_T signal2f;                     /* '<Root>/signal2f' */
  real_T signal3f;                     /* '<Root>/signal3f' */
  real_T signal4f;                     /* '<Root>/signal4f' */
  real_T signal5f;                     /* '<Root>/signal5f' */
  real_T signal6f;                     /* '<Root>/signal6f' */
  real_T signal7f;                     /* '<Root>/signal7f' */
  real_T signal8f;                     /* '<Root>/signal8f' */
  real_T signal1g;                     /* '<Root>/signal1g' */
  real_T signal2g;                     /* '<Root>/signal2g' */
  real_T signal3g;                     /* '<Root>/signal3g' */
  real_T signal4g;                     /* '<Root>/signal4g' */
  real_T signal5g;                     /* '<Root>/signal5g' */
  real_T signal6g;                     /* '<Root>/signal6g' */
  real_T signal7g;                     /* '<Root>/signal7g' */
  real_T signal8g;                     /* '<Root>/signal8g' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (auto storage) */
extern DW rtDW_Sfcn;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU_Sfcn;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY_Sfcn;

/* Model entry point functions */
extern void Extended_initialize(void);
extern void Extended_step(void);
extern void Extended_step_SFcn(const int *I, const uint16_t *V8, const int16_t *T, const uint16_t *Enable8, uint16_t *SOCEsti, uint16_t *Vt);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S13>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S2>/DataTypeConversion_uMeas1' : Unused code path elimination
 * Block '<S2>/DataTypeConversion_uState' : Unused code path elimination
 * Block '<S2>/MeasurementFcn1Inputs' : Unused code path elimination
 * Block '<S15>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S2>/StateTransitionFcnInputs' : Unused code path elimination
 * Block '<S2>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S2>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S18>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S3>/DataTypeConversion_uMeas1' : Unused code path elimination
 * Block '<S3>/DataTypeConversion_uState' : Unused code path elimination
 * Block '<S3>/MeasurementFcn1Inputs' : Unused code path elimination
 * Block '<S20>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S3>/StateTransitionFcnInputs' : Unused code path elimination
 * Block '<S3>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S3>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S23>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S4>/DataTypeConversion_uMeas1' : Unused code path elimination
 * Block '<S4>/DataTypeConversion_uState' : Unused code path elimination
 * Block '<S4>/MeasurementFcn1Inputs' : Unused code path elimination
 * Block '<S25>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S4>/StateTransitionFcnInputs' : Unused code path elimination
 * Block '<S4>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S4>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S28>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S5>/DataTypeConversion_uMeas1' : Unused code path elimination
 * Block '<S5>/DataTypeConversion_uState' : Unused code path elimination
 * Block '<S5>/MeasurementFcn1Inputs' : Unused code path elimination
 * Block '<S30>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S5>/StateTransitionFcnInputs' : Unused code path elimination
 * Block '<S5>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S5>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S34>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S8>/DataTypeConversion_uMeas1' : Unused code path elimination
 * Block '<S8>/DataTypeConversion_uState' : Unused code path elimination
 * Block '<S8>/MeasurementFcn1Inputs' : Unused code path elimination
 * Block '<S36>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S8>/StateTransitionFcnInputs' : Unused code path elimination
 * Block '<S8>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S8>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S44>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S10>/DataTypeConversion_uMeas1' : Unused code path elimination
 * Block '<S10>/DataTypeConversion_uState' : Unused code path elimination
 * Block '<S10>/MeasurementFcn1Inputs' : Unused code path elimination
 * Block '<S46>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S10>/StateTransitionFcnInputs' : Unused code path elimination
 * Block '<S10>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S10>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S49>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S11>/DataTypeConversion_uMeas1' : Unused code path elimination
 * Block '<S11>/DataTypeConversion_uState' : Unused code path elimination
 * Block '<S11>/MeasurementFcn1Inputs' : Unused code path elimination
 * Block '<S51>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S11>/StateTransitionFcnInputs' : Unused code path elimination
 * Block '<S11>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S11>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S54>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S12>/DataTypeConversion_uMeas1' : Unused code path elimination
 * Block '<S12>/DataTypeConversion_uState' : Unused code path elimination
 * Block '<S12>/MeasurementFcn1Inputs' : Unused code path elimination
 * Block '<S56>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S12>/StateTransitionFcnInputs' : Unused code path elimination
 * Block '<S12>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S12>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S2>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S3>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S3>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S3>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S3>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S4>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S4>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S4>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S4>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S8>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S8>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S8>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S8>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S10>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S10>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S10>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S10>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S11>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S11>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S11>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S11>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator')    - opens subsystem test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator
 * hilite_system('test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test_2_1227/SOC Kalman filter'
 * '<S1>'   : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator'
 * '<S2>'   : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter1'
 * '<S3>'   : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter2'
 * '<S4>'   : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter3'
 * '<S5>'   : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter4'
 * '<S6>'   : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Simulink Function - Measurement Function'
 * '<S7>'   : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Simulink Function - State Transition Function1'
 * '<S8>'   : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter1'
 * '<S9>'   : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter2'
 * '<S10>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter3'
 * '<S11>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter4'
 * '<S12>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter5'
 * '<S13>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter1/Correct1'
 * '<S14>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter1/Output'
 * '<S15>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter1/Predict'
 * '<S16>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter1/Correct1/Correct'
 * '<S17>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter1/Predict/Predict'
 * '<S18>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter2/Correct1'
 * '<S19>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter2/Output'
 * '<S20>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter2/Predict'
 * '<S21>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter2/Correct1/Correct'
 * '<S22>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter2/Predict/Predict'
 * '<S23>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter3/Correct1'
 * '<S24>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter3/Output'
 * '<S25>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter3/Predict'
 * '<S26>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter3/Correct1/Correct'
 * '<S27>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter3/Predict/Predict'
 * '<S28>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter4/Correct1'
 * '<S29>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter4/Output'
 * '<S30>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter4/Predict'
 * '<S31>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter4/Correct1/Correct'
 * '<S32>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Extended Kalman Filter4/Predict/Predict'
 * '<S33>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Simulink Function - State Transition Function1/f(x,u)'
 * '<S34>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter1/Correct1'
 * '<S35>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter1/Output'
 * '<S36>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter1/Predict'
 * '<S37>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter1/Correct1/Correct'
 * '<S38>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter1/Predict/Predict'
 * '<S39>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter2/Correct1'
 * '<S40>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter2/Output'
 * '<S41>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter2/Predict'
 * '<S42>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter2/Correct1/Correct'
 * '<S43>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter2/Predict/Predict'
 * '<S44>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter3/Correct1'
 * '<S45>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter3/Output'
 * '<S46>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter3/Predict'
 * '<S47>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter3/Correct1/Correct'
 * '<S48>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter3/Predict/Predict'
 * '<S49>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter4/Correct1'
 * '<S50>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter4/Output'
 * '<S51>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter4/Predict'
 * '<S52>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter4/Correct1/Correct'
 * '<S53>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter4/Predict/Predict'
 * '<S54>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter5/Correct1'
 * '<S55>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter5/Output'
 * '<S56>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter5/Predict'
 * '<S57>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter5/Correct1/Correct'
 * '<S58>'  : 'test_2_1227/SOC Kalman filter/Extended Kalman SOC estimator/Unscented Kalman Filter5/Predict/Predict'
 */

/*-
 * Requirements for '<Root>': Extended
 */
#endif                                 /* RTW_HEADER_Extended_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
