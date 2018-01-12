/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Extended.c
 *
 * Code generated for Simulink model 'Extended'.
 *
 * Model version                  : 1.1564
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Jan 02 11:51:11 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->MPC55xx
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. Traceability
 * Validation result: Not run
 */

#include "Extended.h"
#include "look2_binlx.h"
#include "rt_roundd_snf.h"
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

/* Block signals and states (auto storage) */
static DW rtDW;

/* External inputs (root inport signals with auto storage) */
static ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
static ExtY rtY;

/* Block signals and states (auto storage) */
DW rtDW_Sfcn;

/* External inputs (root inport signals with auto storage) */
ExtU rtU_Sfcn;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY_Sfcn;

/* Real-time Model object */
static RT_MODEL *const rtM;

// /* Block signals and states (auto storage) */
// DW rtDW;

// /* External inputs (root inport signals with auto storage) */
// ExtU rtU;

// /* External outputs (root outports fed by signals with auto storage) */
// ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
static RT_MODEL *const rtM = &rtM_;
extern const real_T rtCP_pooled_rFW4lfGVm8rJ[9];
extern const real_T rtCP_pooled_OQlVGFk6oGfp[9];
extern const real_T rtCP_pooled_CG61tKUzmeLS[9];
extern const real_T rtCP_pooled_K773cLdrmIFA[9];
extern const real_T rtCP_pooled_xtq3OKlJuddY[9];
extern const real_T rtCP_pooled_PKbHGIP0O8eJ[9];
extern const real_T rtCP_pooled_a6L7ndLxigX3[303];
extern const real_T rtCP_pooled_4fM691GgZUSu[101];
extern const real_T rtCP_pooled_W0IzKmlzUeUt[3];
extern const real_T rtCP_pooled_lVroTJDsNAMC[303];
extern const real_T rtCP_pooled_kWUVdc3rMrPE[303];
extern const real_T rtCP_pooled_hLEAQxIjMJwa[303];
extern const real_T rtCP_pooled_SK8h9SU8mvf7[303];
extern const real_T rtCP_pooled_o3byshPzw2wb[303];
extern const real_T rtCP_pooled_A4G6YOyGmwGa[303];
extern const real_T rtCP_pooled_HCYl94LlA8fl[303];
extern const real_T rtCP_pooled_hfBI6666aB5y[303];
extern const real_T rtCP_pooled_S6IfbvyNiQG3[303];
extern const real_T rtCP_pooled_VIXiKHaIKGUo[303];
extern const real_T rtCP_pooled_5O8WBI0I05sb[303];
extern const uint32_T rtCP_pooled_z2b48KvfGf64[2];

#define rtCP_Q_Value                   rtCP_pooled_rFW4lfGVm8rJ  /* Expression: p.Q
                                                                  * Referenced by: '<S2>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_InitialVa rtCP_pooled_OQlVGFk6oGfp /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S2>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_b                 rtCP_pooled_CG61tKUzmeLS  /* Expression: p.Q
                                                                  * Referenced by: '<S3>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_e rtCP_pooled_K773cLdrmIFA /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S3>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_l                 rtCP_pooled_xtq3OKlJuddY  /* Expression: p.Q
                                                                  * Referenced by: '<S8>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_b rtCP_pooled_PKbHGIP0O8eJ /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S8>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_i2                rtCP_pooled_xtq3OKlJuddY  /* Expression: p.Q
                                                                  * Referenced by: '<S11>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_d rtCP_pooled_PKbHGIP0O8eJ /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S11>/DataStoreMemory - P'
                                                                  */
#define rtCP_Em_disTable_tableData     rtCP_pooled_a6L7ndLxigX3  /* Expression: E_dis
                                                                  * Referenced by: '<S6>/Em_dis Table'
                                                                  */
#define rtCP_Em_disTable_bp01Data      rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S6>/Em_dis Table'
                                                                  */
#define rtCP_Em_disTable_bp02Data      rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S6>/Em_dis Table'
                                                                  */
#define rtCP_EmTable1_tableData        rtCP_pooled_lVroTJDsNAMC  /* Expression: Em_LUT
                                                                  * Referenced by: '<S6>/Em Table1'
                                                                  */
#define rtCP_EmTable1_bp01Data         rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S6>/Em Table1'
                                                                  */
#define rtCP_EmTable1_bp02Data         rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S6>/Em Table1'
                                                                  */
#define rtCP_R0_disTable_tableData     rtCP_pooled_kWUVdc3rMrPE  /* Expression: R0_dis
                                                                  * Referenced by: '<S6>/R0_dis Table'
                                                                  */
#define rtCP_R0_disTable_bp01Data      rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S6>/R0_dis Table'
                                                                  */
#define rtCP_R0_disTable_bp02Data      rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S6>/R0_dis Table'
                                                                  */
#define rtCP_R0Table1_tableData        rtCP_pooled_hLEAQxIjMJwa  /* Expression: R0_LUT
                                                                  * Referenced by: '<S6>/R0 Table1'
                                                                  */
#define rtCP_R0Table1_bp01Data         rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S6>/R0 Table1'
                                                                  */
#define rtCP_R0Table1_bp02Data         rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S6>/R0 Table1'
                                                                  */
#define rtCP_R2_disTable2_tableData    rtCP_pooled_SK8h9SU8mvf7  /* Expression: R2_dis
                                                                  * Referenced by: '<S7>/R2_dis Table2'
                                                                  */
#define rtCP_R2_disTable2_bp01Data     rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S7>/R2_dis Table2'
                                                                  */
#define rtCP_R2_disTable2_bp02Data     rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S7>/R2_dis Table2'
                                                                  */
#define rtCP_R2Table1_tableData        rtCP_pooled_o3byshPzw2wb  /* Expression: R2_LUT
                                                                  * Referenced by: '<S7>/R2 Table1'
                                                                  */
#define rtCP_R2Table1_bp01Data         rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S7>/R2 Table1'
                                                                  */
#define rtCP_R2Table1_bp02Data         rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S7>/R2 Table1'
                                                                  */
#define rtCP_C2_disTable1_tableData    rtCP_pooled_A4G6YOyGmwGa  /* Expression: C2_dis
                                                                  * Referenced by: '<S7>/C2_dis Table1'
                                                                  */
#define rtCP_C2_disTable1_bp01Data     rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S7>/C2_dis Table1'
                                                                  */
#define rtCP_C2_disTable1_bp02Data     rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S7>/C2_dis Table1'
                                                                  */
#define rtCP_C2Table2_tableData        rtCP_pooled_HCYl94LlA8fl  /* Expression: C2_LUT
                                                                  * Referenced by: '<S7>/C2 Table2'
                                                                  */
#define rtCP_C2Table2_bp01Data         rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S7>/C2 Table2'
                                                                  */
#define rtCP_C2Table2_bp02Data         rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S7>/C2 Table2'
                                                                  */
#define rtCP_R1_disTable1_tableData    rtCP_pooled_hfBI6666aB5y  /* Expression: R1_dis
                                                                  * Referenced by: '<S7>/R1_dis Table1'
                                                                  */
#define rtCP_R1_disTable1_bp01Data     rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S7>/R1_dis Table1'
                                                                  */
#define rtCP_R1_disTable1_bp02Data     rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S7>/R1_dis Table1'
                                                                  */
#define rtCP_R1Table_tableData         rtCP_pooled_S6IfbvyNiQG3  /* Expression: R1_LUT
                                                                  * Referenced by: '<S7>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data          rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S7>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data          rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S7>/R1 Table'
                                                                  */
#define rtCP_C1_disTable_tableData     rtCP_pooled_VIXiKHaIKGUo  /* Expression: C1_dis
                                                                  * Referenced by: '<S7>/C1_dis Table'
                                                                  */
#define rtCP_C1_disTable_bp01Data      rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S7>/C1_dis Table'
                                                                  */
#define rtCP_C1_disTable_bp02Data      rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S7>/C1_dis Table'
                                                                  */
#define rtCP_C1Table1_tableData        rtCP_pooled_5O8WBI0I05sb  /* Expression: C1_LUT
                                                                  * Referenced by: '<S7>/C1 Table1'
                                                                  */
#define rtCP_C1Table1_bp01Data         rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S7>/C1 Table1'
                                                                  */
#define rtCP_C1Table1_bp02Data         rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S7>/C1 Table1'
                                                                  */
#define rtCP_Em_disTable_maxIndex      rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_Em_disTable_maxIndex
                                                                  * Referenced by: '<S6>/Em_dis Table'
                                                                  */
#define rtCP_EmTable1_maxIndex         rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_EmTable1_maxIndex
                                                                  * Referenced by: '<S6>/Em Table1'
                                                                  */
#define rtCP_R0_disTable_maxIndex      rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R0_disTable_maxIndex
                                                                  * Referenced by: '<S6>/R0_dis Table'
                                                                  */
#define rtCP_R0Table1_maxIndex         rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R0Table1_maxIndex
                                                                  * Referenced by: '<S6>/R0 Table1'
                                                                  */
#define rtCP_R2_disTable2_maxIndex     rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R2_disTable2_maxIndex
                                                                  * Referenced by: '<S7>/R2_dis Table2'
                                                                  */
#define rtCP_R2Table1_maxIndex         rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R2Table1_maxIndex
                                                                  * Referenced by: '<S7>/R2 Table1'
                                                                  */
#define rtCP_C2_disTable1_maxIndex     rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_C2_disTable1_maxIndex
                                                                  * Referenced by: '<S7>/C2_dis Table1'
                                                                  */
#define rtCP_C2Table2_maxIndex         rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_C2Table2_maxIndex
                                                                  * Referenced by: '<S7>/C2 Table2'
                                                                  */
#define rtCP_R1_disTable1_maxIndex     rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R1_disTable1_maxIndex
                                                                  * Referenced by: '<S7>/R1_dis Table1'
                                                                  */
#define rtCP_R1Table_maxIndex          rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R1Table_maxIndex
                                                                  * Referenced by: '<S7>/R1 Table'
                                                                  */
#define rtCP_C1_disTable_maxIndex      rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_C1_disTable_maxIndex
                                                                  * Referenced by: '<S7>/C1_dis Table'
                                                                  */
#define rtCP_C1Table1_maxIndex         rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_C1Table1_maxIndex
                                                                  * Referenced by: '<S7>/C1 Table1'
                                                                  */

extern void Correct1(boolean_T rtu_Enable, real_T rtu_yMeas, real_T rtu_R,
                     real_T rtd_P_g[9], real_T rtd_x[3]);
extern void Predict(const real_T rtu_Q[9], real_T rtd_P_g[9], real_T rtd_x[3]);
extern void ExtendedKalmanFilter1_Start(DW_ExtendedKalmanFilter1 *localDW);
extern void ExtendedKalmanFilter1(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[3], real_T rty_P[9], DW_ExtendedKalmanFilter1 *localDW);
extern void ExtendedKalmanFilter2_Start(DW_ExtendedKalmanFilter2 *localDW);
extern void ExtendedKalmanFilter2(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[3], real_T rty_P[9], DW_ExtendedKalmanFilter2 *localDW);
extern void UnscentedKalmanFilter1_Start(DW_UnscentedKalmanFilter1 *localDW);
extern void UnscentedKalmanFilter1(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[3], real_T rty_P[9], DW_UnscentedKalmanFilter1 *localDW);
extern void UnscentedKalmanFilter4_Start(DW_UnscentedKalmanFilter4 *localDW);
extern void UnscentedKalmanFilter4(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[3], real_T rty_P[9], DW_UnscentedKalmanFilter4 *localDW);
extern void batteryMeasurementFcn(const real_T rtu_x[3], real_T *rty_y);
extern void batteryStateFcn(const real_T rtu_x[3], real_T rty_xNext[3]);

/*
 * Output and update for enable system:
 *    '<S2>/Correct1'
 *    '<S3>/Correct1'
 *    '<S4>/Correct1'
 *    '<S5>/Correct1'
 */
void Correct1(boolean_T rtu_Enable, real_T rtu_yMeas, real_T rtu_R, real_T
              rtd_P_g[9], real_T rtd_x[3])
{
  real_T dHdx[3];
  real_T zEstimated;
  real_T b_z;
  real_T imvec[3];
  real_T imz;
  int32_T j;
  real_T imvec_0[9];
  real_T tmp[9];
  int32_T i;

  /* Outputs for Enabled SubSystem: '<S2>/Correct1' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (rtu_Enable) {
    /* MATLAB Function: '<S13>/Correct' incorporates:
     *  DataStoreWrite: '<S13>/Data Store WriteP'
     */
    /* MATLAB Function 'Extras/EKFCorrect_SLFcn_0Input/Correct': '<S16>:1' */
    /* '<S16>:1:2' MeasurementFcn = coder.const(str2func(pM.FcnName)); */
    /* '<S16>:1:3' if pM.HasJacobian */
    /* '<S16>:1:7' xNew = zeros(size(x),'like',x); */
    /* '<S16>:1:8' PNew = zeros(size(P),'like',x); */
    /* '<S16>:1:9' if pM.HasAdditiveNoise */
    /* '<S16>:1:10' if pM.HasJacobian */
    /* '<S16>:1:13' else */
    /* '<S16>:1:14' [xNew,PNew] = matlabshared.tracking.internal.EKFCorrectorAdditive.correct(... */
    /* '<S16>:1:15'             yMeas,R,x,P,@(xx)MeasurementFcn(xx),[]); */
    batteryMeasurementFcn(rtd_x, &b_z);
    for (j = 0; j < 3; j++) {
      imvec[0] = rtd_x[0];
      imvec[1] = rtd_x[1];
      imvec[2] = rtd_x[2];
      zEstimated = 1.4901161193847656E-8 * fabs(rtd_x[j]);
      if ((1.4901161193847656E-8 > zEstimated) || rtIsNaN(zEstimated)) {
        zEstimated = 1.4901161193847656E-8;
      }

      imvec[j] = rtd_x[j] + zEstimated;
      batteryMeasurementFcn(imvec, &imz);
      dHdx[j] = (imz - b_z) / zEstimated;
    }

    b_z = 0.0;
    for (j = 0; j < 3; j++) {
      b_z += (rtd_P_g[3 * j + 2] * dHdx[2] + (rtd_P_g[3 * j + 1] * dHdx[1] +
               rtd_P_g[3 * j] * dHdx[0])) * dHdx[j];
    }

    b_z += rtu_R;
    batteryMeasurementFcn(rtd_x, &zEstimated);
    zEstimated = rtu_yMeas - zEstimated;
    for (j = 0; j < 3; j++) {
      imz = ((rtd_P_g[j + 3] * dHdx[1] + rtd_P_g[j] * dHdx[0]) + rtd_P_g[j + 6] *
             dHdx[2]) / b_z;
      imvec_0[j] = imz * dHdx[0];
      imvec_0[j + 3] = imz * dHdx[1];
      imvec_0[j + 6] = imz * dHdx[2];
      for (i = 0; i < 3; i++) {
        tmp[j + 3 * i] = rtd_P_g[3 * i + j] - ((rtd_P_g[3 * i + 1] * imvec_0[j +
          3] + rtd_P_g[3 * i] * imvec_0[j]) + rtd_P_g[3 * i + 2] * imvec_0[j + 6]);
      }

      imvec[j] = imz;
    }

    for (j = 0; j < 3; j++) {
      /* DataStoreWrite: '<S13>/Data Store WriteP' incorporates:
       *  MATLAB Function: '<S13>/Correct'
       */
      rtd_P_g[3 * j] = tmp[3 * j];
      rtd_P_g[1 + 3 * j] = tmp[3 * j + 1];
      rtd_P_g[2 + 3 * j] = tmp[3 * j + 2];

      /* DataStoreWrite: '<S13>/Data Store WriteX' incorporates:
       *  MATLAB Function: '<S13>/Correct'
       */
      rtd_x[j] += imvec[j] * zEstimated;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/Correct1' */
}

/*
 * Output and update for atomic system:
 *    '<S2>/Predict'
 *    '<S3>/Predict'
 *    '<S4>/Predict'
 *    '<S5>/Predict'
 */
void Predict(const real_T rtu_Q[9], real_T rtd_P_g[9], real_T rtd_x[3])
{
  real_T xNew[3];
  real_T PNew[9];
  real_T Jacobian[9];
  real_T z[3];
  real_T imvec[3];
  real_T imz[3];
  int32_T j;
  real_T imvec_0[3];
  real_T Jacobian_0[9];
  int32_T i;
  real_T u1;

  /* MATLAB Function: '<S15>/Predict' */
  /* MATLAB Function 'Extras/EKFPredict_SLFcn_0Input/Predict': '<S17>:1' */
  /* '<S17>:1:2' StateTransitionFcn = coder.const(str2func(pS.FcnName)); */
  /* '<S17>:1:3' if pS.HasJacobian */
  /* '<S17>:1:7' xNew = zeros(size(x),'like',x); */
  /* '<S17>:1:8' PNew = zeros(size(P),'like',x); */
  /* '<S17>:1:9' if pS.HasAdditiveNoise */
  /* '<S17>:1:10' if pS.HasJacobian */
  /* '<S17>:1:13' else */
  /* '<S17>:1:14' [xNew,PNew] = matlabshared.tracking.internal.EKFPredictorAdditive.predict(... */
  /* '<S17>:1:15'             Q,x,P,@(xx)StateTransitionFcn(xx), []); */
  memcpy(&PNew[0], &rtd_P_g[0], 9U * sizeof(real_T));
  xNew[0] = rtd_x[0];
  xNew[1] = rtd_x[1];
  xNew[2] = rtd_x[2];
  imvec[0] = rtd_x[0];
  imvec[1] = rtd_x[1];
  imvec[2] = rtd_x[2];
  batteryStateFcn(imvec, z);
  for (j = 0; j < 3; j++) {
    imvec[0] = xNew[0];
    imvec[1] = xNew[1];
    imvec[2] = xNew[2];
    u1 = 1.4901161193847656E-8 * fabs(xNew[j]);
    if ((1.4901161193847656E-8 > u1) || rtIsNaN(u1)) {
      u1 = 1.4901161193847656E-8;
    }

    imvec[j] = xNew[j] + u1;
    imvec_0[0] = imvec[0];
    imvec_0[1] = imvec[1];
    imvec_0[2] = imvec[2];
    batteryStateFcn(imvec_0, imz);
    Jacobian[3 * j] = (imz[0] - z[0]) / u1;
    Jacobian[1 + 3 * j] = (imz[1] - z[1]) / u1;
    Jacobian[2 + 3 * j] = (imz[2] - z[2]) / u1;
  }

  z[0] = xNew[0];
  z[1] = xNew[1];
  z[2] = xNew[2];
  batteryStateFcn(z, xNew);

  /* DataStoreWrite: '<S15>/Data Store WriteX' incorporates:
   *  MATLAB Function: '<S15>/Predict'
   */
  rtd_x[0] = xNew[0];
  rtd_x[1] = xNew[1];
  rtd_x[2] = xNew[2];
  for (j = 0; j < 3; j++) {
    /* MATLAB Function: '<S15>/Predict' */
    for (i = 0; i < 3; i++) {
      Jacobian_0[j + 3 * i] = 0.0;
      Jacobian_0[j + 3 * i] += PNew[3 * i] * Jacobian[j];
      Jacobian_0[j + 3 * i] += PNew[3 * i + 1] * Jacobian[j + 3];
      Jacobian_0[j + 3 * i] += PNew[3 * i + 2] * Jacobian[j + 6];
    }

    /* DataStoreWrite: '<S15>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S15>/Predict'
     */
    for (i = 0; i < 3; i++) {
      rtd_P_g[j + 3 * i] = ((Jacobian_0[j + 3] * Jacobian[i + 3] + Jacobian_0[j]
        * Jacobian[i]) + Jacobian_0[j + 6] * Jacobian[i + 6]) + rtu_Q[3 * i + j];
    }

    /* End of DataStoreWrite: '<S15>/Data Store WriteP' */
  }
}

/*
 * Start for atomic system:
 *    '<S1>/Extended Kalman Filter1'
 *    '<S1>/Extended Kalman Filter4'
 */
void ExtendedKalmanFilter1_Start(DW_ExtendedKalmanFilter1 *localDW)
{
  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - P' */
  memcpy(&localDW->P_g[0], &rtCP_DataStoreMemoryP_InitialVa[0], 9U * sizeof
         (real_T));

  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - x' */
  localDW->x[0] = 0.51;
  localDW->x[1] = 0.01;
  localDW->x[2] = 0.01;
}

/*
 * Output and update for atomic system:
 *    '<S1>/Extended Kalman Filter1'
 *    '<S1>/Extended Kalman Filter4'
 */
void ExtendedKalmanFilter1(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[3], real_T rty_P[9], DW_ExtendedKalmanFilter1 *localDW)
{
  int32_T i;

  /* Outputs for Enabled SubSystem: '<S2>/Correct1' */

  /* Constant: '<S2>/R1' */
  Correct1(rtu_Enable1, rtu_y1, 0.07432, localDW->P_g, localDW->x);

  /* End of Outputs for SubSystem: '<S2>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S2>/Output' */
  /* DataStoreRead: '<S14>/Data Store Read' */
  rty_xhat[0] = localDW->x[0];
  rty_xhat[1] = localDW->x[1];
  rty_xhat[2] = localDW->x[2];

  /* DataStoreRead: '<S14>/Data Store Read1' */
  for (i = 0; i < 9; i++) {
    rty_P[i] = localDW->P_g[i];
  }

  /* End of DataStoreRead: '<S14>/Data Store Read1' */
  /* End of Outputs for SubSystem: '<S2>/Output' */

  /* Outputs for Atomic SubSystem: '<S2>/Predict' */

  /* Constant: '<S2>/Q' */
  Predict(rtCP_Q_Value, localDW->P_g, localDW->x);

  /* End of Outputs for SubSystem: '<S2>/Predict' */
}

/*
 * Start for atomic system:
 *    '<S1>/Extended Kalman Filter2'
 *    '<S1>/Extended Kalman Filter3'
 */
void ExtendedKalmanFilter2_Start(DW_ExtendedKalmanFilter2 *localDW)
{
  /* Start for DataStoreMemory: '<S3>/DataStoreMemory - P' */
  memcpy(&localDW->P_c[0], &rtCP_DataStoreMemoryP_Initial_e[0], 9U * sizeof
         (real_T));

  /* Start for DataStoreMemory: '<S3>/DataStoreMemory - x' */
  localDW->x[0] = 0.51;
  localDW->x[1] = 0.0;
  localDW->x[2] = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S1>/Extended Kalman Filter2'
 *    '<S1>/Extended Kalman Filter3'
 */
void ExtendedKalmanFilter2(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[3], real_T rty_P[9], DW_ExtendedKalmanFilter2 *localDW)
{
  int32_T i;

  /* Outputs for Enabled SubSystem: '<S3>/Correct1' */

  /* Constant: '<S3>/R1' */
  Correct1(rtu_Enable1, rtu_y1, 0.08432, localDW->P_c, localDW->x);

  /* End of Outputs for SubSystem: '<S3>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S3>/Output' */
  /* DataStoreRead: '<S19>/Data Store Read' */
  rty_xhat[0] = localDW->x[0];
  rty_xhat[1] = localDW->x[1];
  rty_xhat[2] = localDW->x[2];

  /* DataStoreRead: '<S19>/Data Store Read1' */
  for (i = 0; i < 9; i++) {
    rty_P[i] = localDW->P_c[i];
  }

  /* End of DataStoreRead: '<S19>/Data Store Read1' */
  /* End of Outputs for SubSystem: '<S3>/Output' */

  /* Outputs for Atomic SubSystem: '<S3>/Predict' */

  /* Constant: '<S3>/Q' */
  Predict(rtCP_Q_Value_b, localDW->P_c, localDW->x);

  /* End of Outputs for SubSystem: '<S3>/Predict' */
}

/*
 * Start for atomic system:
 *    '<S1>/Unscented Kalman Filter1'
 *    '<S1>/Unscented Kalman Filter3'
 */
void UnscentedKalmanFilter1_Start(DW_UnscentedKalmanFilter1 *localDW)
{
  /* Start for DataStoreMemory: '<S8>/DataStoreMemory - P' */
  memcpy(&localDW->P_c[0], &rtCP_DataStoreMemoryP_Initial_b[0], 9U * sizeof
         (real_T));

  /* Start for DataStoreMemory: '<S8>/DataStoreMemory - x' */
  localDW->x[0] = 0.005;
  localDW->x[1] = 0.0;
  localDW->x[2] = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S1>/Unscented Kalman Filter1'
 *    '<S1>/Unscented Kalman Filter3'
 */
void UnscentedKalmanFilter1(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[3], real_T rty_P[9], DW_UnscentedKalmanFilter1 *localDW)
{
  real_T PNew[9];
  real_T Y2[6];
  real_T tempY;
  real_T X1[3];
  real_T X2[18];
  real_T sqrtP[9];
  int32_T jmax;
  int32_T jj;
  real_T ajj;
  int32_T j;
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T Y2_0[18];
  real_T tempY_0[3];
  real_T c;
  int32_T b_iy;
  int32_T e;
  int32_T ia;
  real_T X1_0[3];
  real_T Y2_1[9];
  real_T Y2_2;
  boolean_T exitg1;

  /* Outputs for Enabled SubSystem: '<S8>/Correct1' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  if (rtu_Enable1) {
    /* MATLAB Function: '<S34>/Correct' */
    /* MATLAB Function 'Extras/UKFCorrect_SLFcn_0Input/Correct': '<S37>:1' */
    /* '<S37>:1:2' MeasurementFcn = coder.const(str2func(pM.FcnName)); */
    /* '<S37>:1:4' xNew = zeros(size(x),'like',x); */
    /* '<S37>:1:5' PNew = zeros(size(P),'like',x); */
    /* '<S37>:1:6' if pM.HasAdditiveNoise */
    /* '<S37>:1:7' [xNew, PNew] = matlabshared.tracking.internal.UKFCorrectorAdditive.correct(... */
    /* '<S37>:1:8'         yMeas,R,x,P,... */
    /* '<S37>:1:9'         pM.Alpha, pM.Beta, pM.Kappa,... */
    /* '<S37>:1:10'         @(xx)MeasurementFcn(xx)); */
    X1[0] = localDW->x[0];
    X1[1] = localDW->x[1];
    X1[2] = localDW->x[2];
    memcpy(&PNew[0], &localDW->P_c[0], 9U * sizeof(real_T));
    memcpy(&sqrtP[0], &localDW->P_c[0], 9U * sizeof(real_T));
    jmax = 0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j + 1 < 4)) {
      jj = j * 3 + j;
      ajj = 0.0;
      if (!(j < 1)) {
        ix = j;
        iy = j;
        for (k = 1; k <= j; k++) {
          ajj += sqrtP[ix] * sqrtP[iy];
          ix += 3;
          iy += 3;
        }
      }

      ajj = sqrtP[jj] - ajj;
      if (ajj > 0.0) {
        ajj = sqrt(ajj);
        sqrtP[jj] = ajj;
        if (j + 1 < 3) {
          if (j != 0) {
            ix = j;
            iy = ((j - 1) * 3 + j) + 2;
            for (k = j + 2; k <= iy; k += 3) {
              c = -sqrtP[ix];
              b_iy = jj + 1;
              e = (k - j) + 1;
              for (ia = k; ia <= e; ia++) {
                sqrtP[b_iy] += sqrtP[ia - 1] * c;
                b_iy++;
              }

              ix += 3;
            }
          }

          ajj = 1.0 / ajj;
          ix = (jj - j) + 3;
          for (jj++; jj + 1 <= ix; jj++) {
            sqrtP[jj] *= ajj;
          }
        }

        j++;
      } else {
        sqrtP[jj] = ajj;
        jmax = j + 1;
        exitg1 = true;
      }
    }

    if (jmax == 0) {
      jmax = 4;
    }

    jmax--;
    for (j = 1; j + 1 <= jmax; j++) {
      for (jj = 1; jj <= j; jj++) {
        sqrtP[(jj + 3 * j) - 1] = 0.0;
      }
    }

    for (jmax = 0; jmax < 9; jmax++) {
      ajj = 1.7320508075688772 * sqrtP[jmax];
      X2[jmax] = ajj;
      X2[jmax + 9] = -ajj;
    }

    for (jmax = 0; jmax < 6; jmax++) {
      X2[3 * jmax] += localDW->x[0];
      X2[1 + 3 * jmax] += localDW->x[1];
      X2[2 + 3 * jmax] += localDW->x[2];
    }

    for (jmax = 0; jmax < 6; jmax++) {
      X1_0[0] = X2[3 * jmax];
      X1_0[1] = X2[3 * jmax + 1];
      X1_0[2] = X2[3 * jmax + 2];
      batteryMeasurementFcn(X1_0, &tempY);
      Y2[jmax] = tempY;
    }

    X1_0[0] = X1[0];
    X1_0[1] = X1[1];
    X1_0[2] = X1[2];
    batteryMeasurementFcn(X1_0, &tempY);
    ajj = tempY * 0.0;
    for (jmax = 0; jmax < 6; jmax++) {
      ajj += Y2[jmax] * 0.16666666666666666;
    }

    tempY -= ajj;
    c = 0.0;
    for (jmax = 0; jmax < 6; jmax++) {
      Y2_2 = Y2[jmax] - ajj;
      X2[3 * jmax] -= X1[0];
      X2[1 + 3 * jmax] -= X1[1];
      X2[2 + 3 * jmax] -= X1[2];
      c += Y2_2 * Y2_2;
      Y2[jmax] = Y2_2;
    }

    tempY = (tempY * tempY * 2.0 + 0.16666666666666666 * c) + 0.08432;
    for (jmax = 0; jmax < 3; jmax++) {
      X1_0[jmax] = 0.0;
      for (j = 0; j < 6; j++) {
        X1_0[jmax] += X2[3 * j + jmax] * Y2[j];
      }

      localDW->x[jmax] = X1_0[jmax] * 0.16666666666666666 / tempY;
    }

    ajj = rtu_y1 - ajj;

    /* DataStoreWrite: '<S34>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S34>/Correct'
     */
    for (jmax = 0; jmax < 3; jmax++) {
      localDW->P_c[jmax] = PNew[jmax] - localDW->x[jmax] * tempY * localDW->x[0];
      localDW->P_c[jmax + 3] = PNew[jmax + 3] - localDW->x[jmax] * tempY *
        localDW->x[1];
      localDW->P_c[jmax + 6] = PNew[jmax + 6] - localDW->x[jmax] * tempY *
        localDW->x[2];
    }

    /* End of DataStoreWrite: '<S34>/Data Store WriteP' */

    /* DataStoreWrite: '<S34>/Data Store WriteX' incorporates:
     *  MATLAB Function: '<S34>/Correct'
     */
    localDW->x[0] = localDW->x[0] * ajj + X1[0];
    localDW->x[1] = localDW->x[1] * ajj + X1[1];
    localDW->x[2] = localDW->x[2] * ajj + X1[2];
  }

  /* End of Outputs for SubSystem: '<S8>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S8>/Output' */
  /* DataStoreRead: '<S35>/Data Store Read' */
  rty_xhat[0] = localDW->x[0];
  rty_xhat[1] = localDW->x[1];
  rty_xhat[2] = localDW->x[2];

  /* DataStoreRead: '<S35>/Data Store Read1' */
  for (jmax = 0; jmax < 9; jmax++) {
    rty_P[jmax] = localDW->P_c[jmax];
  }

  /* End of DataStoreRead: '<S35>/Data Store Read1' */
  /* End of Outputs for SubSystem: '<S8>/Output' */

  /* Outputs for Atomic SubSystem: '<S8>/Predict' */
  /* MATLAB Function: '<S36>/Predict' incorporates:
   *  Constant: '<S8>/Q'
   */
  /* MATLAB Function 'Extras/UKFPredict_SLFcn_0Input/Predict': '<S38>:1' */
  /* '<S38>:1:2' StateTransitionFcn = coder.const(str2func(pS.FcnName)); */
  /* '<S38>:1:4' xNew = zeros(size(x),'like',x); */
  /* '<S38>:1:5' PNew = zeros(size(P),'like',x); */
  /* '<S38>:1:6' if pS.HasAdditiveNoise */
  /* '<S38>:1:7' [xNew,PNew] = matlabshared.tracking.internal.UKFPredictorAdditive.predict(... */
  /* '<S38>:1:8'         Q,x,P,... */
  /* '<S38>:1:9'         pS.Alpha, pS.Beta, pS.Kappa,... */
  /* '<S38>:1:10'         @(xx)StateTransitionFcn(xx)); */
  X1[0] = localDW->x[0];
  X1[1] = localDW->x[1];
  X1[2] = localDW->x[2];
  memcpy(&PNew[0], &rtCP_Q_Value_l[0], 9U * sizeof(real_T));
  memcpy(&sqrtP[0], &localDW->P_c[0], 9U * sizeof(real_T));
  jmax = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j + 1 < 4)) {
    jj = j * 3 + j;
    ajj = 0.0;
    if (!(j < 1)) {
      ix = j;
      iy = j;
      for (k = 1; k <= j; k++) {
        ajj += sqrtP[ix] * sqrtP[iy];
        ix += 3;
        iy += 3;
      }
    }

    ajj = sqrtP[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      sqrtP[jj] = ajj;
      if (j + 1 < 3) {
        if (j != 0) {
          ix = j;
          iy = ((j - 1) * 3 + j) + 2;
          for (k = j + 2; k <= iy; k += 3) {
            c = -sqrtP[ix];
            b_iy = jj + 1;
            e = (k - j) + 1;
            for (ia = k; ia <= e; ia++) {
              sqrtP[b_iy] += sqrtP[ia - 1] * c;
              b_iy++;
            }

            ix += 3;
          }
        }

        tempY = 1.0 / ajj;
        ix = (jj - j) + 3;
        for (jj++; jj + 1 <= ix; jj++) {
          sqrtP[jj] *= tempY;
        }
      }

      j++;
    } else {
      sqrtP[jj] = ajj;
      jmax = j + 1;
      exitg1 = true;
    }
  }

  if (jmax == 0) {
    jmax = 4;
  }

  jmax--;
  for (j = 1; j + 1 <= jmax; j++) {
    for (jj = 1; jj <= j; jj++) {
      sqrtP[(jj + 3 * j) - 1] = 0.0;
    }
  }

  for (jmax = 0; jmax < 9; jmax++) {
    ajj = 1.7320508075688772 * sqrtP[jmax];
    X2[jmax] = ajj;
    X2[jmax + 9] = -ajj;
  }

  for (jmax = 0; jmax < 6; jmax++) {
    X2[3 * jmax] += localDW->x[0];
    X2[1 + 3 * jmax] += localDW->x[1];
    X2[2 + 3 * jmax] += localDW->x[2];
  }

  for (jmax = 0; jmax < 6; jmax++) {
    X1_0[0] = X2[3 * jmax];
    X1_0[1] = X2[3 * jmax + 1];
    X1_0[2] = X2[3 * jmax + 2];
    batteryStateFcn(X1_0, tempY_0);
    Y2_0[3 * jmax] = tempY_0[0];
    Y2_0[1 + 3 * jmax] = tempY_0[1];
    Y2_0[2 + 3 * jmax] = tempY_0[2];
  }

  batteryStateFcn(X1, tempY_0);
  localDW->x[0] = tempY_0[0] * 0.0;
  localDW->x[1] = tempY_0[1] * 0.0;
  localDW->x[2] = tempY_0[2] * 0.0;
  for (jmax = 0; jmax < 6; jmax++) {
    localDW->x[0] += Y2_0[3 * jmax] * 0.16666666666666666;
    localDW->x[1] += Y2_0[3 * jmax + 1] * 0.16666666666666666;
    localDW->x[2] += Y2_0[3 * jmax + 2] * 0.16666666666666666;
  }

  tempY_0[0] -= localDW->x[0];
  tempY_0[1] -= localDW->x[1];
  tempY_0[2] -= localDW->x[2];
  for (jmax = 0; jmax < 6; jmax++) {
    Y2_0[3 * jmax] -= localDW->x[0];
    Y2_0[1 + 3 * jmax] -= localDW->x[1];
    Y2_0[2 + 3 * jmax] -= localDW->x[2];
  }

  for (jmax = 0; jmax < 3; jmax++) {
    sqrtP[jmax] = tempY_0[jmax] * tempY_0[0];
    sqrtP[jmax + 3] = tempY_0[jmax] * tempY_0[1];
    sqrtP[jmax + 6] = tempY_0[jmax] * tempY_0[2];
  }

  for (jmax = 0; jmax < 3; jmax++) {
    for (j = 0; j < 3; j++) {
      Y2_1[jmax + 3 * j] = 0.0;
      for (jj = 0; jj < 6; jj++) {
        Y2_1[jmax + 3 * j] += Y2_0[3 * jj + jmax] * Y2_0[3 * jj + j];
      }
    }
  }

  for (jmax = 0; jmax < 3; jmax++) {
    /* DataStoreWrite: '<S36>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S36>/Predict'
     */
    localDW->P_c[3 * jmax] = (sqrtP[3 * jmax] * 2.0 + Y2_1[3 * jmax] *
      0.16666666666666666) + PNew[3 * jmax];
    localDW->P_c[1 + 3 * jmax] = (sqrtP[3 * jmax + 1] * 2.0 + Y2_1[3 * jmax + 1]
      * 0.16666666666666666) + PNew[3 * jmax + 1];
    localDW->P_c[2 + 3 * jmax] = (sqrtP[3 * jmax + 2] * 2.0 + Y2_1[3 * jmax + 2]
      * 0.16666666666666666) + PNew[3 * jmax + 2];
  }

  /* End of Outputs for SubSystem: '<S8>/Predict' */
}

/*
 * Start for atomic system:
 *    '<S1>/Unscented Kalman Filter4'
 *    '<S1>/Unscented Kalman Filter5'
 */
void UnscentedKalmanFilter4_Start(DW_UnscentedKalmanFilter4 *localDW)
{
  /* Start for DataStoreMemory: '<S11>/DataStoreMemory - P' */
  memcpy(&localDW->P_f[0], &rtCP_DataStoreMemoryP_Initial_d[0], 9U * sizeof
         (real_T));

  /* Start for DataStoreMemory: '<S11>/DataStoreMemory - x' */
  localDW->x[0] = 0.005;
  localDW->x[1] = 0.0;
  localDW->x[2] = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S1>/Unscented Kalman Filter4'
 *    '<S1>/Unscented Kalman Filter5'
 */
void UnscentedKalmanFilter4(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[3], real_T rty_P[9], DW_UnscentedKalmanFilter4 *localDW)
{
  real_T PNew[9];
  real_T Y2[6];
  real_T tempY;
  real_T X1[3];
  real_T X2[18];
  real_T sqrtP[9];
  int32_T jmax;
  int32_T jj;
  real_T ajj;
  int32_T j;
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T Y2_0[18];
  real_T tempY_0[3];
  real_T c;
  int32_T b_iy;
  int32_T e;
  int32_T ia;
  real_T X1_0[3];
  real_T Y2_1[9];
  real_T Y2_2;
  boolean_T exitg1;

  /* Outputs for Enabled SubSystem: '<S11>/Correct1' incorporates:
   *  EnablePort: '<S49>/Enable'
   */
  if (rtu_Enable1) {
    /* MATLAB Function: '<S49>/Correct' */
    /* MATLAB Function 'Extras/UKFCorrect_SLFcn_0Input/Correct': '<S52>:1' */
    /* '<S52>:1:2' MeasurementFcn = coder.const(str2func(pM.FcnName)); */
    /* '<S52>:1:4' xNew = zeros(size(x),'like',x); */
    /* '<S52>:1:5' PNew = zeros(size(P),'like',x); */
    /* '<S52>:1:6' if pM.HasAdditiveNoise */
    /* '<S52>:1:7' [xNew, PNew] = matlabshared.tracking.internal.UKFCorrectorAdditive.correct(... */
    /* '<S52>:1:8'         yMeas,R,x,P,... */
    /* '<S52>:1:9'         pM.Alpha, pM.Beta, pM.Kappa,... */
    /* '<S52>:1:10'         @(xx)MeasurementFcn(xx)); */
    X1[0] = localDW->x[0];
    X1[1] = localDW->x[1];
    X1[2] = localDW->x[2];
    memcpy(&PNew[0], &localDW->P_f[0], 9U * sizeof(real_T));
    memcpy(&sqrtP[0], &localDW->P_f[0], 9U * sizeof(real_T));
    jmax = 0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j + 1 < 4)) {
      jj = j * 3 + j;
      ajj = 0.0;
      if (!(j < 1)) {
        ix = j;
        iy = j;
        for (k = 1; k <= j; k++) {
          ajj += sqrtP[ix] * sqrtP[iy];
          ix += 3;
          iy += 3;
        }
      }

      ajj = sqrtP[jj] - ajj;
      if (ajj > 0.0) {
        ajj = sqrt(ajj);
        sqrtP[jj] = ajj;
        if (j + 1 < 3) {
          if (j != 0) {
            ix = j;
            iy = ((j - 1) * 3 + j) + 2;
            for (k = j + 2; k <= iy; k += 3) {
              c = -sqrtP[ix];
              b_iy = jj + 1;
              e = (k - j) + 1;
              for (ia = k; ia <= e; ia++) {
                sqrtP[b_iy] += sqrtP[ia - 1] * c;
                b_iy++;
              }

              ix += 3;
            }
          }

          ajj = 1.0 / ajj;
          ix = (jj - j) + 3;
          for (jj++; jj + 1 <= ix; jj++) {
            sqrtP[jj] *= ajj;
          }
        }

        j++;
      } else {
        sqrtP[jj] = ajj;
        jmax = j + 1;
        exitg1 = true;
      }
    }

    if (jmax == 0) {
      jmax = 4;
    }

    jmax--;
    for (j = 1; j + 1 <= jmax; j++) {
      for (jj = 1; jj <= j; jj++) {
        sqrtP[(jj + 3 * j) - 1] = 0.0;
      }
    }

    for (jmax = 0; jmax < 9; jmax++) {
      ajj = 1.3336791218280355 * sqrtP[jmax];
      X2[jmax] = ajj;
      X2[jmax + 9] = -ajj;
    }

    for (jmax = 0; jmax < 6; jmax++) {
      X2[3 * jmax] += localDW->x[0];
      X2[1 + 3 * jmax] += localDW->x[1];
      X2[2 + 3 * jmax] += localDW->x[2];
    }

    for (jmax = 0; jmax < 6; jmax++) {
      X1_0[0] = X2[3 * jmax];
      X1_0[1] = X2[3 * jmax + 1];
      X1_0[2] = X2[3 * jmax + 2];
      batteryMeasurementFcn(X1_0, &tempY);
      Y2[jmax] = tempY;
    }

    X1_0[0] = X1[0];
    X1_0[1] = X1[1];
    X1_0[2] = X1[2];
    batteryMeasurementFcn(X1_0, &tempY);
    ajj = tempY;
    for (jmax = 0; jmax < 6; jmax++) {
      ajj += Y2[jmax] * -0.40939981986407931;
    }

    ajj *= -0.68662506324843986;
    tempY -= ajj;
    c = 0.0;
    for (jmax = 0; jmax < 6; jmax++) {
      Y2_2 = Y2[jmax] - ajj;
      X2[3 * jmax] -= X1[0];
      X2[1 + 3 * jmax] -= X1[1];
      X2[2 + 3 * jmax] -= X1[2];
      c += Y2_2 * Y2_2;
      Y2[jmax] = Y2_2;
    }

    tempY = (tempY * tempY * -1.7774983787767134 + -0.40939981986407931 * c) *
      -0.68662506324843986 + 0.08432;
    for (jmax = 0; jmax < 3; jmax++) {
      X1_0[jmax] = 0.0;
      for (j = 0; j < 6; j++) {
        X1_0[jmax] += X2[3 * j + jmax] * Y2[j];
      }

      localDW->x[jmax] = X1_0[jmax] * 0.28110417720807335 / tempY;
    }

    ajj = rtu_y1 - ajj;

    /* DataStoreWrite: '<S49>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S49>/Correct'
     */
    for (jmax = 0; jmax < 3; jmax++) {
      localDW->P_f[jmax] = PNew[jmax] - localDW->x[jmax] * tempY * localDW->x[0];
      localDW->P_f[jmax + 3] = PNew[jmax + 3] - localDW->x[jmax] * tempY *
        localDW->x[1];
      localDW->P_f[jmax + 6] = PNew[jmax + 6] - localDW->x[jmax] * tempY *
        localDW->x[2];
    }

    /* End of DataStoreWrite: '<S49>/Data Store WriteP' */

    /* DataStoreWrite: '<S49>/Data Store WriteX' incorporates:
     *  MATLAB Function: '<S49>/Correct'
     */
    localDW->x[0] = localDW->x[0] * ajj + X1[0];
    localDW->x[1] = localDW->x[1] * ajj + X1[1];
    localDW->x[2] = localDW->x[2] * ajj + X1[2];
  }

  /* End of Outputs for SubSystem: '<S11>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S11>/Output' */
  /* DataStoreRead: '<S50>/Data Store Read' */
  rty_xhat[0] = localDW->x[0];
  rty_xhat[1] = localDW->x[1];
  rty_xhat[2] = localDW->x[2];

  /* DataStoreRead: '<S50>/Data Store Read1' */
  for (jmax = 0; jmax < 9; jmax++) {
    rty_P[jmax] = localDW->P_f[jmax];
  }

  /* End of DataStoreRead: '<S50>/Data Store Read1' */
  /* End of Outputs for SubSystem: '<S11>/Output' */

  /* Outputs for Atomic SubSystem: '<S11>/Predict' */
  /* MATLAB Function: '<S51>/Predict' incorporates:
   *  Constant: '<S11>/Q'
   */
  /* MATLAB Function 'Extras/UKFPredict_SLFcn_0Input/Predict': '<S53>:1' */
  /* '<S53>:1:2' StateTransitionFcn = coder.const(str2func(pS.FcnName)); */
  /* '<S53>:1:4' xNew = zeros(size(x),'like',x); */
  /* '<S53>:1:5' PNew = zeros(size(P),'like',x); */
  /* '<S53>:1:6' if pS.HasAdditiveNoise */
  /* '<S53>:1:7' [xNew,PNew] = matlabshared.tracking.internal.UKFPredictorAdditive.predict(... */
  /* '<S53>:1:8'         Q,x,P,... */
  /* '<S53>:1:9'         pS.Alpha, pS.Beta, pS.Kappa,... */
  /* '<S53>:1:10'         @(xx)StateTransitionFcn(xx)); */
  X1[0] = localDW->x[0];
  X1[1] = localDW->x[1];
  X1[2] = localDW->x[2];
  memcpy(&PNew[0], &rtCP_Q_Value_i2[0], 9U * sizeof(real_T));
  memcpy(&sqrtP[0], &localDW->P_f[0], 9U * sizeof(real_T));
  jmax = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j + 1 < 4)) {
    jj = j * 3 + j;
    ajj = 0.0;
    if (!(j < 1)) {
      ix = j;
      iy = j;
      for (k = 1; k <= j; k++) {
        ajj += sqrtP[ix] * sqrtP[iy];
        ix += 3;
        iy += 3;
      }
    }

    ajj = sqrtP[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      sqrtP[jj] = ajj;
      if (j + 1 < 3) {
        if (j != 0) {
          ix = j;
          iy = ((j - 1) * 3 + j) + 2;
          for (k = j + 2; k <= iy; k += 3) {
            c = -sqrtP[ix];
            b_iy = jj + 1;
            e = (k - j) + 1;
            for (ia = k; ia <= e; ia++) {
              sqrtP[b_iy] += sqrtP[ia - 1] * c;
              b_iy++;
            }

            ix += 3;
          }
        }

        tempY = 1.0 / ajj;
        ix = (jj - j) + 3;
        for (jj++; jj + 1 <= ix; jj++) {
          sqrtP[jj] *= tempY;
        }
      }

      j++;
    } else {
      sqrtP[jj] = ajj;
      jmax = j + 1;
      exitg1 = true;
    }
  }

  if (jmax == 0) {
    jmax = 4;
  }

  jmax--;
  for (j = 1; j + 1 <= jmax; j++) {
    for (jj = 1; jj <= j; jj++) {
      sqrtP[(jj + 3 * j) - 1] = 0.0;
    }
  }

  for (jmax = 0; jmax < 9; jmax++) {
    ajj = 1.3336791218280355 * sqrtP[jmax];
    X2[jmax] = ajj;
    X2[jmax + 9] = -ajj;
  }

  for (jmax = 0; jmax < 6; jmax++) {
    X2[3 * jmax] += localDW->x[0];
    X2[1 + 3 * jmax] += localDW->x[1];
    X2[2 + 3 * jmax] += localDW->x[2];
  }

  for (jmax = 0; jmax < 6; jmax++) {
    X1_0[0] = X2[3 * jmax];
    X1_0[1] = X2[3 * jmax + 1];
    X1_0[2] = X2[3 * jmax + 2];
    batteryStateFcn(X1_0, tempY_0);
    Y2_0[3 * jmax] = tempY_0[0];
    Y2_0[1 + 3 * jmax] = tempY_0[1];
    Y2_0[2 + 3 * jmax] = tempY_0[2];
  }

  batteryStateFcn(X1, tempY_0);
  localDW->x[0] = tempY_0[0];
  localDW->x[1] = tempY_0[1];
  localDW->x[2] = tempY_0[2];
  for (jmax = 0; jmax < 6; jmax++) {
    localDW->x[0] += Y2_0[3 * jmax] * -0.40939981986407931;
    localDW->x[1] += Y2_0[3 * jmax + 1] * -0.40939981986407931;
    localDW->x[2] += Y2_0[3 * jmax + 2] * -0.40939981986407931;
  }

  localDW->x[0] *= -0.68662506324843986;
  localDW->x[1] *= -0.68662506324843986;
  localDW->x[2] *= -0.68662506324843986;
  tempY_0[0] -= localDW->x[0];
  tempY_0[1] -= localDW->x[1];
  tempY_0[2] -= localDW->x[2];
  for (jmax = 0; jmax < 6; jmax++) {
    Y2_0[3 * jmax] -= localDW->x[0];
    Y2_0[1 + 3 * jmax] -= localDW->x[1];
    Y2_0[2 + 3 * jmax] -= localDW->x[2];
  }

  for (jmax = 0; jmax < 3; jmax++) {
    sqrtP[jmax] = tempY_0[jmax] * tempY_0[0];
    sqrtP[jmax + 3] = tempY_0[jmax] * tempY_0[1];
    sqrtP[jmax + 6] = tempY_0[jmax] * tempY_0[2];
  }

  for (jmax = 0; jmax < 3; jmax++) {
    for (j = 0; j < 3; j++) {
      Y2_1[jmax + 3 * j] = 0.0;
      for (jj = 0; jj < 6; jj++) {
        Y2_1[jmax + 3 * j] += Y2_0[3 * jj + jmax] * Y2_0[3 * jj + j];
      }
    }
  }

  for (jmax = 0; jmax < 3; jmax++) {
    /* DataStoreWrite: '<S51>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S51>/Predict'
     */
    localDW->P_f[3 * jmax] = (sqrtP[3 * jmax] * -1.7774983787767134 + Y2_1[3 *
      jmax] * -0.40939981986407931) * -0.68662506324843986 + PNew[3 * jmax];
    localDW->P_f[1 + 3 * jmax] = (sqrtP[3 * jmax + 1] * -1.7774983787767134 +
      Y2_1[3 * jmax + 1] * -0.40939981986407931) * -0.68662506324843986 + PNew[3
      * jmax + 1];
    localDW->P_f[2 + 3 * jmax] = (sqrtP[3 * jmax + 2] * -1.7774983787767134 +
      Y2_1[3 * jmax + 2] * -0.40939981986407931) * -0.68662506324843986 + PNew[3
      * jmax + 2];
  }

  /* End of Outputs for SubSystem: '<S11>/Predict' */
}

/* Output and update for Simulink Function: '<S1>/Simulink Function - Measurement Function' */
void batteryMeasurementFcn(const real_T rtu_x[3], real_T *rty_y)
{
  real_T rtb_Gain_0;

  /* Switch: '<S6>/Switch1' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Gain: '<S6>/Gain'
   *  Inport: '<Root>/I'
   *  Inport: '<Root>/Temperature'
   *  Lookup_n-D: '<S6>/R0 Table1'
   *  Lookup_n-D: '<S6>/R0_dis Table'
   *  SignalConversion: '<S6>/TmpSignal ConversionAtxOutport1'
   *  Switch: '<S6>/Switch'
   */
  if (-32768 * rtU.I >= 0) {
    /* Outport: '<Root>/OCV_esti' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     *  Inport: '<Root>/Temperature'
     *  Lookup_n-D: '<S6>/Em Table1'
     *  SignalConversion: '<S6>/TmpSignal ConversionAtxOutport1'
     */
    rtY.OCV_esti = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_EmTable1_bp01Data,
      rtCP_EmTable1_bp02Data, rtCP_EmTable1_tableData, rtCP_EmTable1_maxIndex,
      101U);
    rtb_Gain_0 = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_R0Table1_bp01Data,
      rtCP_R0Table1_bp02Data, rtCP_R0Table1_tableData, rtCP_R0Table1_maxIndex,
      101U);
  } else {
    /* Outport: '<Root>/OCV_esti' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     *  Inport: '<Root>/Temperature'
     *  Lookup_n-D: '<S6>/Em_dis Table'
     *  SignalConversion: '<S6>/TmpSignal ConversionAtxOutport1'
     */
    rtY.OCV_esti = look2_binlx(rtu_x[0], rtU.Temperature,
      rtCP_Em_disTable_bp01Data, rtCP_Em_disTable_bp02Data,
      rtCP_Em_disTable_tableData, rtCP_Em_disTable_maxIndex, 101U);
    rtb_Gain_0 = look2_binlx(rtu_x[0], rtU.Temperature,
      rtCP_R0_disTable_bp01Data, rtCP_R0_disTable_bp02Data,
      rtCP_R0_disTable_tableData, rtCP_R0_disTable_maxIndex, 101U);
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Outport: '<Root>/y' incorporates:
   *  Inport: '<Root>/I'
   *  Outport: '<Root>/OCV_esti'
   *  Product: '<S6>/Product'
   *  SignalConversion: '<S6>/TmpSignal ConversionAtxOutport1'
   *  Sum: '<S6>/Add1'
   */
  rtY.y = ((rtY.OCV_esti - rtb_Gain_0 * (real_T)rtU.I) - rtu_x[1]) - rtu_x[2];

  /* SignalConversion: '<S6>/TmpSignal ConversionAtyInport1' incorporates:
   *  Outport: '<Root>/y'
   */
  *rty_y = rtY.y;
}

/* Output and update for Simulink Function: '<S1>/Simulink Function - State Transition Function1' */
void batteryStateFcn(const real_T rtu_x[3], real_T rty_xNext[3])
{
  real_T rtb_Switch_c;
  real_T rtb_Switch2;
  int32_T rtb_Gain_l;
  real_T tmp;
  int32_T tmp_0;
  real_T rtb_Gain_g;
  int16_T tmp_1;

  /* Gain: '<S7>/Gain' incorporates:
   *  Inport: '<Root>/I'
   */
  rtb_Gain_l = -32768 * rtU.I;

  /* Switch: '<S7>/Switch' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Inport: '<Root>/Temperature'
   *  Lookup_n-D: '<S7>/C1 Table1'
   *  Lookup_n-D: '<S7>/C1_dis Table'
   *  Lookup_n-D: '<S7>/C2 Table2'
   *  Lookup_n-D: '<S7>/C2_dis Table1'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   *  Switch: '<S7>/Switch2'
   */
  if (rtb_Gain_l >= 0) {
    rtb_Switch_c = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_C1Table1_bp01Data,
      rtCP_C1Table1_bp02Data, rtCP_C1Table1_tableData, rtCP_C1Table1_maxIndex,
      101U);
    rtb_Switch2 = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_C2Table2_bp01Data,
      rtCP_C2Table2_bp02Data, rtCP_C2Table2_tableData, rtCP_C2Table2_maxIndex,
      101U);
  } else {
    rtb_Switch_c = look2_binlx(rtu_x[0], rtU.Temperature,
      rtCP_C1_disTable_bp01Data, rtCP_C1_disTable_bp02Data,
      rtCP_C1_disTable_tableData, rtCP_C1_disTable_maxIndex, 101U);
    rtb_Switch2 = look2_binlx(rtu_x[0], rtU.Temperature,
      rtCP_C2_disTable1_bp01Data, rtCP_C2_disTable1_bp02Data,
      rtCP_C2_disTable1_tableData, rtCP_C2_disTable1_maxIndex, 101U);
  }

  /* End of Switch: '<S7>/Switch' */

  /* MATLAB Function: '<S7>/f(x,u)' incorporates:
   *  Inport: '<Root>/Cq'
   *  Inport: '<Root>/I'
   */
  /* MATLAB Function 'Extended Kalman SOC estimator/Simulink Function - State Transition Function1/f(x,u)': '<S33>:1' */
  /* '<S33>:1:2' xdot = zeros(size(x)); */
  /* '<S33>:1:3' U1 = x(2); */
  /* '<S33>:1:4' U2 = x(3); */
  /*  U3 = x(4); */
  /* '<S33>:1:6' xdot(1) = -I/(3600*double(Cq)); */
  tmp_0 = -rtU.I;
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  }

  tmp = rt_roundd_snf((real_T)tmp_0 / (3600.0 * (real_T)rtU.Cq));
  if (tmp < 32768.0) {
    if (tmp >= -32768.0) {
      rty_xNext[0] = (int16_T)tmp;
    } else {
      rty_xNext[0] = -32768.0;
    }
  } else {
    rty_xNext[0] = 32767.0;
  }

  /* '<S33>:1:7' xdot(2) = -1/(R1*C1)*U1 + I/C1; */
  tmp = rt_roundd_snf((real_T)rtU.I / rtb_Switch_c);

  /* Switch: '<S7>/Switch1' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Inport: '<Root>/Temperature'
   *  Lookup_n-D: '<S7>/R1 Table'
   *  Lookup_n-D: '<S7>/R1_dis Table1'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  if (rtb_Gain_l >= 0) {
    rtb_Gain_g = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_R1Table_bp01Data,
      rtCP_R1Table_bp02Data, rtCP_R1Table_tableData, rtCP_R1Table_maxIndex, 101U);
  } else {
    rtb_Gain_g = look2_binlx(rtu_x[0], rtU.Temperature,
      rtCP_R1_disTable1_bp01Data, rtCP_R1_disTable1_bp02Data,
      rtCP_R1_disTable1_tableData, rtCP_R1_disTable1_maxIndex, 101U);
  }

  /* End of Switch: '<S7>/Switch1' */

  /* MATLAB Function: '<S7>/f(x,u)' incorporates:
   *  Inport: '<Root>/I'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  if (tmp < 32768.0) {
    if (tmp >= -32768.0) {
      tmp_1 = (int16_T)tmp;
    } else {
      tmp_1 = MIN_int16_T;
    }
  } else {
    tmp_1 = MAX_int16_T;
  }

  tmp = rt_roundd_snf(-1.0 / (rtb_Gain_g * rtb_Switch_c) * rtu_x[1] + (real_T)
                      tmp_1);
  if (tmp < 32768.0) {
    if (tmp >= -32768.0) {
      rty_xNext[1] = (int16_T)tmp;
    } else {
      rty_xNext[1] = -32768.0;
    }
  } else {
    rty_xNext[1] = 32767.0;
  }

  /* '<S33>:1:8' xdot(3) = -1/(R2*C2)*U2 + I/C2; */
  tmp = rt_roundd_snf((real_T)rtU.I / rtb_Switch2);

  /* Switch: '<S7>/Switch3' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Inport: '<Root>/Temperature'
   *  Lookup_n-D: '<S7>/R2 Table1'
   *  Lookup_n-D: '<S7>/R2_dis Table2'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  if (rtb_Gain_l >= 0) {
    rtb_Gain_g = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_R2Table1_bp01Data,
      rtCP_R2Table1_bp02Data, rtCP_R2Table1_tableData, rtCP_R2Table1_maxIndex,
      101U);
  } else {
    rtb_Gain_g = look2_binlx(rtu_x[0], rtU.Temperature,
      rtCP_R2_disTable2_bp01Data, rtCP_R2_disTable2_bp02Data,
      rtCP_R2_disTable2_tableData, rtCP_R2_disTable2_maxIndex, 101U);
  }

  /* End of Switch: '<S7>/Switch3' */

  /* MATLAB Function: '<S7>/f(x,u)' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  if (tmp < 32768.0) {
    if (tmp >= -32768.0) {
      tmp_1 = (int16_T)tmp;
    } else {
      tmp_1 = MIN_int16_T;
    }
  } else {
    tmp_1 = MAX_int16_T;
  }

  tmp = rt_roundd_snf(-1.0 / (rtb_Gain_g * rtb_Switch2) * rtu_x[2] + (real_T)
                      tmp_1);
  if (tmp < 32768.0) {
    if (tmp >= -32768.0) {
      rty_xNext[2] = (int16_T)tmp;
    } else {
      rty_xNext[2] = -32768.0;
    }
  } else {
    rty_xNext[2] = 32767.0;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtxNextInport1' incorporates:
   *  Constant: '<S7>/Constant'
   *  Product: '<S7>/Product'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   *  Sum: '<S7>/Add'
   */
  /*  xdot(4) = -1/(R3*C3)*U3 + I/C3; */
  rty_xNext[0] = rty_xNext[0] * 0.1 + rtu_x[0];
  rty_xNext[1] = rty_xNext[1] * 0.1 + rtu_x[1];
  rty_xNext[2] = rty_xNext[2] * 0.1 + rtu_x[2];
}

/* Model step function */
void Extended_step(void)
{
  real_T rtb_DataStoreRead_e[3];
  real_T rtb_DataStoreRead_f[3];
  real_T rtb_DataStoreRead_o[3];
  real_T rtb_DataStoreRead[3];
  real_T rtb_DataStoreRead_p[3];
  real_T rtb_DataStoreRead_iz[3];
  real_T rtb_DataStoreRead_nz[3];
  real_T rtb_DataStoreRead_d[3];

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter1' */

  /* Inport: '<Root>/signal1b' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Inport: '<Root>/signal1'
   *  Outport: '<Root>/signal1a'
   */
  UnscentedKalmanFilter1(rtU.signal1_h, (real_T)rtU.signal1, rtb_DataStoreRead_e,
    rtY.signal1a, &rtDW.UnscentedKalmanFilter1_g);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter1' */

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter3' */

  /* Inport: '<Root>/signal2b' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  Inport: '<Root>/signal2'
   *  Outport: '<Root>/signal2a'
   */
  UnscentedKalmanFilter1(rtU.signal2_p, (real_T)rtU.signal2, rtb_DataStoreRead_f,
    rtY.signal2a, &rtDW.UnscentedKalmanFilter3);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter3' */

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter4' */

  /* Inport: '<Root>/signal3b' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Inport: '<Root>/signal3'
   *  Outport: '<Root>/signal3a'
   */
  UnscentedKalmanFilter4(rtU.signal3_c, (real_T)rtU.signal3, rtb_DataStoreRead_o,
    rtY.signal3a, &rtDW.UnscentedKalmanFilter4_n);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter4' */

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter5' */

  /* Inport: '<Root>/signal4b' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Inport: '<Root>/signal4'
   *  Outport: '<Root>/signal4a'
   */
  UnscentedKalmanFilter4(rtU.signal4_g, (real_T)rtU.signal4, rtb_DataStoreRead,
    rtY.signal4a, &rtDW.UnscentedKalmanFilter5);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter5' */

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter4' */

  /* Inport: '<Root>/signal5b' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   *  Inport: '<Root>/signal5'
   *  Outport: '<Root>/signal5a'
   */
  ExtendedKalmanFilter1(rtU.signal5_d, (real_T)rtU.signal5, rtb_DataStoreRead_p,
                        rtY.signal5a, &rtDW.ExtendedKalmanFilter4);

  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter4' */

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter1' */

  /* Inport: '<Root>/signal6b' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   *  Inport: '<Root>/signal6'
   *  Outport: '<Root>/signal6a'
   */
  ExtendedKalmanFilter1(rtU.signal6_a, (real_T)rtU.signal6, rtb_DataStoreRead_iz,
                        rtY.signal6a, &rtDW.ExtendedKalmanFilter1_g);

  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter1' */

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter2' */

  /* Inport: '<Root>/signal7b' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion6'
   *  Inport: '<Root>/signal7'
   *  Outport: '<Root>/signal7a'
   */
  ExtendedKalmanFilter2(rtU.signal7_n, (real_T)rtU.signal7, rtb_DataStoreRead_nz,
                        rtY.signal7a, &rtDW.ExtendedKalmanFilter2_i);

  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter2' */

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter3' */

  /* Inport: '<Root>/signal8b' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   *  Inport: '<Root>/signal8'
   *  Outport: '<Root>/signal8a'
   */
  ExtendedKalmanFilter2(rtU.signal8_a, (real_T)rtU.signal8, rtb_DataStoreRead_d,
                        rtY.signal8a, &rtDW.ExtendedKalmanFilter3);

  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter3' */

  /* Outport: '<Root>/signal1c' */
  rtY.signal1c[0] = rtb_DataStoreRead_e[0];

  /* Outport: '<Root>/signal2c' */
  rtY.signal2c[0] = rtb_DataStoreRead_f[0];

  /* Outport: '<Root>/signal3c' */
  rtY.signal3c[0] = rtb_DataStoreRead_o[0];

  /* Outport: '<Root>/signal4c' */
  rtY.signal4c[0] = rtb_DataStoreRead[0];

  /* Outport: '<Root>/signal5c' */
  rtY.signal5c[0] = rtb_DataStoreRead_p[0];

  /* Outport: '<Root>/signal6c' */
  rtY.signal6c[0] = rtb_DataStoreRead_iz[0];

  /* Outport: '<Root>/signal7c' */
  rtY.signal7c[0] = rtb_DataStoreRead_nz[0];

  /* Outport: '<Root>/signal8c' */
  rtY.signal8c[0] = rtb_DataStoreRead_d[0];

  /* Outport: '<Root>/signal1c' */
  rtY.signal1c[1] = rtb_DataStoreRead_e[1];

  /* Outport: '<Root>/signal2c' */
  rtY.signal2c[1] = rtb_DataStoreRead_f[1];

  /* Outport: '<Root>/signal3c' */
  rtY.signal3c[1] = rtb_DataStoreRead_o[1];

  /* Outport: '<Root>/signal4c' */
  rtY.signal4c[1] = rtb_DataStoreRead[1];

  /* Outport: '<Root>/signal5c' */
  rtY.signal5c[1] = rtb_DataStoreRead_p[1];

  /* Outport: '<Root>/signal6c' */
  rtY.signal6c[1] = rtb_DataStoreRead_iz[1];

  /* Outport: '<Root>/signal7c' */
  rtY.signal7c[1] = rtb_DataStoreRead_nz[1];

  /* Outport: '<Root>/signal8c' */
  rtY.signal8c[1] = rtb_DataStoreRead_d[1];

  /* Outport: '<Root>/signal1c' */
  rtY.signal1c[2] = rtb_DataStoreRead_e[2];

  /* Outport: '<Root>/signal2c' */
  rtY.signal2c[2] = rtb_DataStoreRead_f[2];

  /* Outport: '<Root>/signal3c' */
  rtY.signal3c[2] = rtb_DataStoreRead_o[2];

  /* Outport: '<Root>/signal4c' */
  rtY.signal4c[2] = rtb_DataStoreRead[2];

  /* Outport: '<Root>/signal5c' */
  rtY.signal5c[2] = rtb_DataStoreRead_p[2];

  /* Outport: '<Root>/signal6c' */
  rtY.signal6c[2] = rtb_DataStoreRead_iz[2];

  /* Outport: '<Root>/signal7c' */
  rtY.signal7c[2] = rtb_DataStoreRead_nz[2];

  /* Outport: '<Root>/signal8c' */
  rtY.signal8c[2] = rtb_DataStoreRead_d[2];

  /* Outport: '<Root>/signal1d' incorporates:
   *  Gain: '<S1>/Gain'
   */
  rtY.signal1d = (uint16_T)(10000.0 * rtb_DataStoreRead_e[0]);

  /* Outport: '<Root>/signal2d' incorporates:
   *  Gain: '<S1>/Gain2'
   */
  rtY.signal2d = (uint16_T)(10000.0 * rtb_DataStoreRead_f[0]);

  /* Outport: '<Root>/signal3d' incorporates:
   *  Gain: '<S1>/Gain3'
   */
  rtY.signal3d = (uint16_T)(10000.0 * rtb_DataStoreRead_o[0]);

  /* Outport: '<Root>/signal4d' incorporates:
   *  Gain: '<S1>/Gain4'
   */
  rtY.signal4d = (uint16_T)(10000.0 * rtb_DataStoreRead[0]);

  /* Outport: '<Root>/signal5d' incorporates:
   *  Gain: '<S1>/Gain6'
   */
  rtY.signal5d = (uint16_T)(10000.0 * rtb_DataStoreRead_p[0]);

  /* Outport: '<Root>/signal6d' incorporates:
   *  Gain: '<S1>/Gain5'
   */
  rtY.signal6d = (uint16_T)(10000.0 * rtb_DataStoreRead_iz[0]);

  /* Outport: '<Root>/signal7d' incorporates:
   *  Gain: '<S1>/Gain7'
   */
  rtY.signal7d = (uint16_T)(10000.0 * rtb_DataStoreRead_nz[0]);

  /* Outport: '<Root>/signal8d' incorporates:
   *  Gain: '<S1>/Gain8'
   */
  rtY.signal8d = (uint16_T)(10000.0 * rtb_DataStoreRead_d[0]);

  /* Outport: '<Root>/signal1e' incorporates:
   *  Gain: '<S1>/Gain9'
   */
  rtY.signal1e = (int16_T)floor(1000.0 * rtb_DataStoreRead_e[1]);

  /* Outport: '<Root>/signal2e' incorporates:
   *  Gain: '<S1>/Gain10'
   */
  rtY.signal2e = (int16_T)floor(1000.0 * rtb_DataStoreRead_f[1]);

  /* Outport: '<Root>/signal3e' incorporates:
   *  Gain: '<S1>/Gain11'
   */
  rtY.signal3e = (int16_T)floor(1000.0 * rtb_DataStoreRead_o[1]);

  /* Outport: '<Root>/signal4e' incorporates:
   *  Gain: '<S1>/Gain12'
   */
  rtY.signal4e = (int16_T)floor(1000.0 * rtb_DataStoreRead[1]);

  /* Outport: '<Root>/signal5e' incorporates:
   *  Gain: '<S1>/Gain13'
   */
  rtY.signal5e = (int16_T)floor(1000.0 * rtb_DataStoreRead_p[1]);

  /* Outport: '<Root>/signal6e' incorporates:
   *  Gain: '<S1>/Gain14'
   */
  rtY.signal6e = (int16_T)floor(1000.0 * rtb_DataStoreRead_iz[1]);

  /* Outport: '<Root>/signal7e' incorporates:
   *  Gain: '<S1>/Gain15'
   */
  rtY.signal7e = (int16_T)floor(1000.0 * rtb_DataStoreRead_nz[1]);

  /* Outport: '<Root>/signal8e' incorporates:
   *  Gain: '<S1>/Gain16'
   */
  rtY.signal8e = (int16_T)floor(1000.0 * rtb_DataStoreRead_d[1]);

  /* Outport: '<Root>/signal1f' */
  rtY.signal1f = rtb_DataStoreRead_e[1];

  /* Outport: '<Root>/signal2f' */
  rtY.signal2f = rtb_DataStoreRead_f[1];

  /* Outport: '<Root>/signal3f' */
  rtY.signal3f = rtb_DataStoreRead_o[1];

  /* Outport: '<Root>/signal4f' */
  rtY.signal4f = rtb_DataStoreRead[1];

  /* Outport: '<Root>/signal5f' */
  rtY.signal5f = rtb_DataStoreRead_p[1];

  /* Outport: '<Root>/signal6f' */
  rtY.signal6f = rtb_DataStoreRead_iz[1];

  /* Outport: '<Root>/signal7f' */
  rtY.signal7f = rtb_DataStoreRead_nz[1];

  /* Outport: '<Root>/signal8f' */
  rtY.signal8f = rtb_DataStoreRead_d[1];

  /* Outport: '<Root>/signal1g' */
  rtY.signal1g = rtb_DataStoreRead_e[0];

  /* Outport: '<Root>/signal2g' */
  rtY.signal2g = rtb_DataStoreRead_f[0];

  /* Outport: '<Root>/signal3g' */
  rtY.signal3g = rtb_DataStoreRead_o[0];

  /* Outport: '<Root>/signal4g' */
  rtY.signal4g = rtb_DataStoreRead[0];

  /* Outport: '<Root>/signal5g' */
  rtY.signal5g = rtb_DataStoreRead_p[0];

  /* Outport: '<Root>/signal6g' */
  rtY.signal6g = rtb_DataStoreRead_iz[0];

  /* Outport: '<Root>/signal7g' */
  rtY.signal7g = rtb_DataStoreRead_nz[0];

  /* Outport: '<Root>/signal8g' */
  rtY.signal8g = rtb_DataStoreRead_d[0];
}

/* Model step function */
void Extended_step_SFcn(const int *I, const uint16_t *V8, const int16_t *T,
  const uint16_t *Enable8, uint16_t *SOCEsti, uint16_t *Vt)
{
  real_T rtb_DataStoreRead_e[3];
  real_T rtb_DataStoreRead_f[3];
  real_T rtb_DataStoreRead_o[3];
  real_T rtb_DataStoreRead[3];
  real_T rtb_DataStoreRead_p[3];
  real_T rtb_DataStoreRead_iz[3];
  real_T rtb_DataStoreRead_nz[3];
  real_T rtb_DataStoreRead_d[3];
  rtU.I = I[0];
  rtU.Temperature = T[0];
  rtU.signal1_h = Enable8[0];
  rtU.signal1 = V8[0];
  rtU.signal2_p = Enable8[1];
  rtU.signal2 = V8[1];
  rtU.signal3_c = 0;
  rtU.signal3 = 0;
  rtU.signal4_g = 0;
  rtU.signal4 = 0;
  UnscentedKalmanFilter1(rtU.signal1_h, (real_T)rtU.signal1, rtb_DataStoreRead_e,
    rtY.signal1a, &rtDW.UnscentedKalmanFilter1_g);
  UnscentedKalmanFilter1(rtU.signal2_p, (real_T)rtU.signal2, rtb_DataStoreRead_f,
    rtY.signal2a, &rtDW.UnscentedKalmanFilter3);
  UnscentedKalmanFilter4(rtU.signal3_c, (real_T)rtU.signal3, rtb_DataStoreRead_o,
    rtY.signal3a, &rtDW.UnscentedKalmanFilter4_n);
  UnscentedKalmanFilter4(rtU.signal4_g, (real_T)rtU.signal4, rtb_DataStoreRead,
    rtY.signal4a, &rtDW.UnscentedKalmanFilter5);
  ExtendedKalmanFilter1(rtU.signal5_d, (real_T)rtU.signal5, rtb_DataStoreRead_p,
                        rtY.signal5a, &rtDW.ExtendedKalmanFilter4);
  ExtendedKalmanFilter1(rtU.signal6_a, (real_T)rtU.signal6, rtb_DataStoreRead_iz,
                        rtY.signal6a, &rtDW.ExtendedKalmanFilter1_g);
  ExtendedKalmanFilter2(rtU.signal7_n, (real_T)rtU.signal7, rtb_DataStoreRead_nz,
                        rtY.signal7a, &rtDW.ExtendedKalmanFilter2_i);
  ExtendedKalmanFilter2(rtU.signal8_a, (real_T)rtU.signal8, rtb_DataStoreRead_d,
                        rtY.signal8a, &rtDW.ExtendedKalmanFilter3);
  rtY.signal1c[0] = rtb_DataStoreRead_e[0];
  rtY.signal2c[0] = rtb_DataStoreRead_f[0];
  rtY.signal3c[0] = rtb_DataStoreRead_o[0];
  rtY.signal4c[0] = rtb_DataStoreRead[0];
  rtY.signal5c[0] = rtb_DataStoreRead_p[0];
  rtY.signal6c[0] = rtb_DataStoreRead_iz[0];
  rtY.signal7c[0] = rtb_DataStoreRead_nz[0];
  rtY.signal8c[0] = rtb_DataStoreRead_d[0];
  rtY.signal1c[1] = rtb_DataStoreRead_e[1];
  rtY.signal2c[1] = rtb_DataStoreRead_f[1];
  rtY.signal3c[1] = rtb_DataStoreRead_o[1];
  rtY.signal4c[1] = rtb_DataStoreRead[1];
  rtY.signal5c[1] = rtb_DataStoreRead_p[1];
  rtY.signal6c[1] = rtb_DataStoreRead_iz[1];
  rtY.signal7c[1] = rtb_DataStoreRead_nz[1];
  rtY.signal8c[1] = rtb_DataStoreRead_d[1];
  rtY.signal1c[2] = rtb_DataStoreRead_e[2];
  rtY.signal2c[2] = rtb_DataStoreRead_f[2];
  rtY.signal3c[2] = rtb_DataStoreRead_o[2];
  rtY.signal4c[2] = rtb_DataStoreRead[2];
  rtY.signal5c[2] = rtb_DataStoreRead_p[2];
  rtY.signal6c[2] = rtb_DataStoreRead_iz[2];
  rtY.signal7c[2] = rtb_DataStoreRead_nz[2];
  rtY.signal8c[2] = rtb_DataStoreRead_d[2];
  rtY.signal1d = (uint16_T)(10000.0 * rtb_DataStoreRead_e[0]);
  rtY.signal2d = (uint16_T)(10000.0 * rtb_DataStoreRead_f[0]);
  rtY.signal3d = (uint16_T)(10000.0 * rtb_DataStoreRead_o[0]);
  rtY.signal4d = (uint16_T)(10000.0 * rtb_DataStoreRead[0]);
  rtY.signal5d = (uint16_T)(10000.0 * rtb_DataStoreRead_p[0]);
  rtY.signal6d = (uint16_T)(10000.0 * rtb_DataStoreRead_iz[0]);
  rtY.signal7d = (uint16_T)(10000.0 * rtb_DataStoreRead_nz[0]);
  rtY.signal8d = (uint16_T)(10000.0 * rtb_DataStoreRead_d[0]);
  SOCEsti[0] = rtU.signal1;
  SOCEsti[1] = rtU.signal2;
  SOCEsti[2] = rtY.signal1d;
  SOCEsti[3] = rtY.signal2d;
  rtY.signal1e = (int16_T)floor(1000.0 * rtb_DataStoreRead_e[1]);
  rtY.signal2e = (int16_T)floor(1000.0 * rtb_DataStoreRead_f[1]);
  rtY.signal3e = (int16_T)floor(1000.0 * rtb_DataStoreRead_o[1]);
  rtY.signal4e = (int16_T)floor(1000.0 * rtb_DataStoreRead[1]);
  rtY.signal5e = (int16_T)floor(1000.0 * rtb_DataStoreRead_p[1]);
  rtY.signal6e = (int16_T)floor(1000.0 * rtb_DataStoreRead_iz[1]);
  rtY.signal7e = (int16_T)floor(1000.0 * rtb_DataStoreRead_nz[1]);
  rtY.signal8e = (int16_T)floor(1000.0 * rtb_DataStoreRead_d[1]);
  Vt[0] = rtY.signal1e;
  Vt[1] = rtY.signal2e;
  rtY.signal1f = rtb_DataStoreRead_e[1];
  rtY.signal2f = rtb_DataStoreRead_f[1];
  rtY.signal3f = rtb_DataStoreRead_o[1];
  rtY.signal4f = rtb_DataStoreRead[1];
  rtY.signal5f = rtb_DataStoreRead_p[1];
  rtY.signal6f = rtb_DataStoreRead_iz[1];
  rtY.signal7f = rtb_DataStoreRead_nz[1];
  rtY.signal8f = rtb_DataStoreRead_d[1];
  rtY.signal1g = rtb_DataStoreRead_e[0];
  rtY.signal2g = rtb_DataStoreRead_f[0];
  rtY.signal3g = rtb_DataStoreRead_o[0];
  rtY.signal4g = rtb_DataStoreRead[0];
  rtY.signal5g = rtb_DataStoreRead_p[0];
  rtY.signal6g = rtb_DataStoreRead_iz[0];
  rtY.signal7g = rtb_DataStoreRead_nz[0];
  rtY.signal8g = rtb_DataStoreRead_d[0];
}

/* Model initialize function */
void Extended_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter1' */
  UnscentedKalmanFilter1_Start(&rtDW.UnscentedKalmanFilter1_g);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter1' */

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter3' */
  UnscentedKalmanFilter1_Start(&rtDW.UnscentedKalmanFilter3);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter3' */

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter4' */
  UnscentedKalmanFilter4_Start(&rtDW.UnscentedKalmanFilter4_n);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter4' */

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter5' */
  UnscentedKalmanFilter4_Start(&rtDW.UnscentedKalmanFilter5);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter5' */

  /* Start for Atomic SubSystem: '<S1>/Extended Kalman Filter4' */
  ExtendedKalmanFilter1_Start(&rtDW.ExtendedKalmanFilter4);

  /* End of Start for SubSystem: '<S1>/Extended Kalman Filter4' */

  /* Start for Atomic SubSystem: '<S1>/Extended Kalman Filter1' */
  ExtendedKalmanFilter1_Start(&rtDW.ExtendedKalmanFilter1_g);

  /* End of Start for SubSystem: '<S1>/Extended Kalman Filter1' */

  /* Start for Atomic SubSystem: '<S1>/Extended Kalman Filter2' */
  ExtendedKalmanFilter2_Start(&rtDW.ExtendedKalmanFilter2_i);

  /* End of Start for SubSystem: '<S1>/Extended Kalman Filter2' */

  /* Start for Atomic SubSystem: '<S1>/Extended Kalman Filter3' */
  ExtendedKalmanFilter2_Start(&rtDW.ExtendedKalmanFilter3);

  /* End of Start for SubSystem: '<S1>/Extended Kalman Filter3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
