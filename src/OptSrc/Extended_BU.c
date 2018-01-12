/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Extended.c
 *
 * Code generated for Simulink model 'Extended'.
 *
 * Model version                  : 1.1309
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Wed Dec 13 23:59:38 2017
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

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern const real_T rtCP_pooled_a6L7ndLxigX3[303];
extern const real_T rtCP_pooled_4fM691GgZUSu[101];
extern const real_T rtCP_pooled_W0IzKmlzUeUt[3];
extern const real_T rtCP_pooled_lVroTJDsNAMC[303];
extern const real_T rtCP_pooled_kWUVdc3rMrPE[303];
extern const real_T rtCP_pooled_hLEAQxIjMJwa[303];
extern const real_T rtCP_pooled_hfBI6666aB5y[303];
extern const real_T rtCP_pooled_S6IfbvyNiQG3[303];
extern const real_T rtCP_pooled_VIXiKHaIKGUo[303];
extern const real_T rtCP_pooled_5O8WBI0I05sb[303];
extern const uint32_T rtCP_pooled_z2b48KvfGf64[2];

#define rtCP_Em_disTable_tableData     rtCP_pooled_a6L7ndLxigX3  /* Expression: E_dis
                                                                  * Referenced by: '<S3>/Em_dis Table'
                                                                  */
#define rtCP_Em_disTable_bp01Data      rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S3>/Em_dis Table'
                                                                  */
#define rtCP_Em_disTable_bp02Data      rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S3>/Em_dis Table'
                                                                  */
#define rtCP_EmTable1_tableData        rtCP_pooled_lVroTJDsNAMC  /* Expression: Em_LUT
                                                                  * Referenced by: '<S3>/Em Table1'
                                                                  */
#define rtCP_EmTable1_bp01Data         rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S3>/Em Table1'
                                                                  */
#define rtCP_EmTable1_bp02Data         rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S3>/Em Table1'
                                                                  */
#define rtCP_R0_disTable_tableData     rtCP_pooled_kWUVdc3rMrPE  /* Expression: R0_dis
                                                                  * Referenced by: '<S3>/R0_dis Table'
                                                                  */
#define rtCP_R0_disTable_bp01Data      rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S3>/R0_dis Table'
                                                                  */
#define rtCP_R0_disTable_bp02Data      rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S3>/R0_dis Table'
                                                                  */
#define rtCP_R0Table1_tableData        rtCP_pooled_hLEAQxIjMJwa  /* Expression: R0_LUT
                                                                  * Referenced by: '<S3>/R0 Table1'
                                                                  */
#define rtCP_R0Table1_bp01Data         rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S3>/R0 Table1'
                                                                  */
#define rtCP_R0Table1_bp02Data         rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S3>/R0 Table1'
                                                                  */
#define rtCP_R1_disTable1_tableData    rtCP_pooled_hfBI6666aB5y  /* Expression: R1_dis
                                                                  * Referenced by: '<S4>/R1_dis Table1'
                                                                  */
#define rtCP_R1_disTable1_bp01Data     rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S4>/R1_dis Table1'
                                                                  */
#define rtCP_R1_disTable1_bp02Data     rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S4>/R1_dis Table1'
                                                                  */
#define rtCP_R1Table_tableData         rtCP_pooled_S6IfbvyNiQG3  /* Expression: R1_LUT
                                                                  * Referenced by: '<S4>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data          rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S4>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data          rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S4>/R1 Table'
                                                                  */
#define rtCP_C1_disTable_tableData     rtCP_pooled_VIXiKHaIKGUo  /* Expression: C1_dis
                                                                  * Referenced by: '<S4>/C1_dis Table'
                                                                  */
#define rtCP_C1_disTable_bp01Data      rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_dis
                                                                  * Referenced by: '<S4>/C1_dis Table'
                                                                  */
#define rtCP_C1_disTable_bp02Data      rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S4>/C1_dis Table'
                                                                  */
#define rtCP_C1Table1_tableData        rtCP_pooled_5O8WBI0I05sb  /* Expression: C1_LUT
                                                                  * Referenced by: '<S4>/C1 Table1'
                                                                  */
#define rtCP_C1Table1_bp01Data         rtCP_pooled_4fM691GgZUSu  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S4>/C1 Table1'
                                                                  */
#define rtCP_C1Table1_bp02Data         rtCP_pooled_W0IzKmlzUeUt  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S4>/C1 Table1'
                                                                  */
#define rtCP_Em_disTable_maxIndex      rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_Em_disTable_maxIndex
                                                                  * Referenced by: '<S3>/Em_dis Table'
                                                                  */
#define rtCP_EmTable1_maxIndex         rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_EmTable1_maxIndex
                                                                  * Referenced by: '<S3>/Em Table1'
                                                                  */
#define rtCP_R0_disTable_maxIndex      rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R0_disTable_maxIndex
                                                                  * Referenced by: '<S3>/R0_dis Table'
                                                                  */
#define rtCP_R0Table1_maxIndex         rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R0Table1_maxIndex
                                                                  * Referenced by: '<S3>/R0 Table1'
                                                                  */
#define rtCP_R1_disTable1_maxIndex     rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R1_disTable1_maxIndex
                                                                  * Referenced by: '<S4>/R1_dis Table1'
                                                                  */
#define rtCP_R1Table_maxIndex          rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_R1Table_maxIndex
                                                                  * Referenced by: '<S4>/R1 Table'
                                                                  */
#define rtCP_C1_disTable_maxIndex      rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_C1_disTable_maxIndex
                                                                  * Referenced by: '<S4>/C1_dis Table'
                                                                  */
#define rtCP_C1Table1_maxIndex         rtCP_pooled_z2b48KvfGf64  /* Computed Parameter: rtCP_C1Table1_maxIndex
                                                                  * Referenced by: '<S4>/C1 Table1'
                                                                  */

extern void UnscentedKalmanFilter1_Start(DW_UnscentedKalmanFilter1 *localDW);
extern void UnscentedKalmanFilter1(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[2], real_T rty_P[4], DW_UnscentedKalmanFilter1 *localDW);
extern void batteryMeasurementFcn(const real_T rtu_x[2], real_T *rty_y);
extern void batteryStateFcn(const real_T rtu_x[2], real_T rty_xNext[2]);

/*
 * Start for atomic system:
 *    '<S1>/Unscented Kalman Filter1'
 *    '<S1>/Unscented Kalman Filter2'
 *    '<S1>/Unscented Kalman Filter3'
 *    '<S1>/Unscented Kalman Filter4'
 *    '<S1>/Unscented Kalman Filter5'
 *    '<S1>/Unscented Kalman Filter6'
 *    '<S1>/Unscented Kalman Filter7'
 *    '<S1>/Unscented Kalman Filter8'
 */
void UnscentedKalmanFilter1_Start(DW_UnscentedKalmanFilter1 *localDW)
{
  /* Start for DataStoreMemory: '<S5>/DataStoreMemory - P' */
  localDW->P_c[0] = 0.01;
  localDW->P_c[1] = 0.0;
  localDW->P_c[2] = 0.0;
  localDW->P_c[3] = 0.001;

  /* Start for DataStoreMemory: '<S5>/DataStoreMemory - x' */
  localDW->x[0] = 0.005;
  localDW->x[1] = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S1>/Unscented Kalman Filter1'
 *    '<S1>/Unscented Kalman Filter2'
 *    '<S1>/Unscented Kalman Filter3'
 *    '<S1>/Unscented Kalman Filter4'
 *    '<S1>/Unscented Kalman Filter5'
 *    '<S1>/Unscented Kalman Filter6'
 *    '<S1>/Unscented Kalman Filter7'
 *    '<S1>/Unscented Kalman Filter8'
 */
void UnscentedKalmanFilter1(boolean_T rtu_Enable1, real_T rtu_y1, real_T
  rty_xhat[2], real_T rty_P[4], DW_UnscentedKalmanFilter1 *localDW)
{
  real_T Y2[4];
  real_T tempY;
  real_T X2[8];
  real_T sqrtP[4];
  int32_T jmax;
  int32_T jj;
  real_T ajj;
  int32_T j;
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T gain[2];
  real_T Y2_0[8];
  real_T tempY_0[2];
  real_T gain_0[2];
  real_T tempY_idx_1;
  real_T tempY_idx_3;
  boolean_T exitg1;

  /* Outputs for Enabled SubSystem: '<S5>/Correct1' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (rtu_Enable1) {
    /* MATLAB Function: '<S19>/Correct' incorporates:
     *  Constant: '<S5>/R1'
     *  DataStoreRead: '<S19>/Data Store ReadP'
     *  DataStoreRead: '<S19>/Data Store ReadX'
     */
    /* MATLAB Function 'Extras/UKFCorrect_SLFcn_0Input/Correct': '<S22>:1' */
    /* '<S22>:1:2' MeasurementFcn = coder.const(str2func(pM.FcnName)); */
    /* '<S22>:1:4' xNew = zeros(size(x),'like',x); */
    /* '<S22>:1:5' PNew = zeros(size(P),'like',x); */
    /* '<S22>:1:6' if pM.HasAdditiveNoise */
    /* '<S22>:1:7' [xNew, PNew] = matlabshared.tracking.internal.UKFCorrectorAdditive.correct(... */
    /* '<S22>:1:8'         yMeas,R,x,P,... */
    /* '<S22>:1:9'         pM.Alpha, pM.Beta, pM.Kappa,... */
    /* '<S22>:1:10'         @(xx)MeasurementFcn(xx)); */
    sqrtP[0] = localDW->P_c[0];
    sqrtP[1] = localDW->P_c[1];
    sqrtP[2] = localDW->P_c[2];
    sqrtP[3] = localDW->P_c[3];
    jmax = 0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j + 1 < 3)) {
      jj = (j << 1) + j;
      ajj = 0.0;
      if (!(j < 1)) {
        ix = j;
        iy = j;
        k = 1;
        while (k <= j) {
          ajj += sqrtP[ix] * sqrtP[iy];
          ix += 2;
          iy += 2;
          k = 2;
        }
      }

      ajj = sqrtP[jj] - ajj;
      if (ajj > 0.0) {
        ajj = sqrt(ajj);
        sqrtP[jj] = ajj;
        if (j + 1 < 2) {
          ajj = 1.0 / ajj;
          for (ix = jj + 1; ix + 1 <= jj + 2; ix++) {
            sqrtP[ix] *= ajj;
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
      jmax = 3;
    }

    jmax--;
    j = 2;
    while (j <= jmax) {
      sqrtP[2] = 0.0;
      j = 3;
    }

    ajj = 1.4142135623730951 * sqrtP[0]; // SQRT(2) * sqrtP[0]
    X2[0] = ajj;
    X2[4] = -ajj;
    ajj = 1.4142135623730951 * sqrtP[1];
    X2[1] = ajj;
    X2[5] = -ajj;
    ajj = 1.4142135623730951 * sqrtP[2];
    X2[2] = ajj;
    X2[6] = -ajj;
    ajj = 1.4142135623730951 * sqrtP[3];
    X2[3] = ajj;
    X2[7] = -ajj;
    for (jmax = 0; jmax < 4; jmax++) {
      X2[jmax << 1] += localDW->x[0];
      X2[1 + (jmax << 1)] += localDW->x[1];
    }

    batteryMeasurementFcn(&X2[0], &tempY);
    Y2[0] = tempY;
    batteryMeasurementFcn(&X2[2], &tempY);
    Y2[1] = tempY;
    batteryMeasurementFcn(&X2[4], &tempY);
    Y2[2] = tempY;
    batteryMeasurementFcn(&X2[6], &tempY);
    Y2[3] = tempY;
    batteryMeasurementFcn(localDW->x, &tempY);
    ajj = (((tempY * 0.0 + Y2[0] * 0.25) + Y2[1] * 0.25) + Y2[2] * 0.25) + Y2[3]
      * 0.25;
    tempY -= ajj;
    tempY_idx_1 = 0.0;
    for (jmax = 0; jmax < 4; jmax++) {
      tempY_idx_3 = Y2[jmax] - ajj;
      X2[jmax << 1] -= localDW->x[0];
      X2[1 + (jmax << 1)] -= localDW->x[1];
      tempY_idx_1 += tempY_idx_3 * tempY_idx_3;
      Y2[jmax] = tempY_idx_3;
    }

    tempY = (tempY * tempY * 2.0 + 0.25 * tempY_idx_1) + 0.08432;
    for (jmax = 0; jmax < 2; jmax++) {
      tempY_idx_1 = X2[jmax + 6] * Y2[3] + (X2[jmax + 4] * Y2[2] + (X2[jmax + 2]
        * Y2[1] + X2[jmax] * Y2[0]));
      gain[jmax] = tempY_idx_1 * 0.25 / tempY;
    }

    ajj = rtu_y1 - ajj;

    /* DataStoreWrite: '<S19>/Data Store WriteP' incorporates:
     *  DataStoreRead: '<S19>/Data Store ReadP'
     *  MATLAB Function: '<S19>/Correct'
     */
    localDW->P_c[0] -= gain[0] * tempY * gain[0];
    localDW->P_c[2] -= gain[0] * tempY * gain[1];

    /* DataStoreWrite: '<S19>/Data Store WriteX' incorporates:
     *  DataStoreRead: '<S19>/Data Store ReadX'
     *  MATLAB Function: '<S19>/Correct'
     */
    localDW->x[0] += gain[0] * ajj;

    /* DataStoreWrite: '<S19>/Data Store WriteP' incorporates:
     *  DataStoreRead: '<S19>/Data Store ReadP'
     *  MATLAB Function: '<S19>/Correct'
     */
    localDW->P_c[1] -= gain[1] * tempY * gain[0];
    localDW->P_c[3] -= gain[1] * tempY * gain[1];

    /* DataStoreWrite: '<S19>/Data Store WriteX' incorporates:
     *  DataStoreRead: '<S19>/Data Store ReadX'
     *  MATLAB Function: '<S19>/Correct'
     */
    localDW->x[1] += gain[1] * ajj;
  }

  /* End of Outputs for SubSystem: '<S5>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S5>/Output' */
  /* DataStoreRead: '<S20>/Data Store Read' */
  rty_xhat[0] = localDW->x[0];
  rty_xhat[1] = localDW->x[1];

  /* DataStoreRead: '<S20>/Data Store Read1' */
  rty_P[0] = localDW->P_c[0];
  rty_P[1] = localDW->P_c[1];
  rty_P[2] = localDW->P_c[2];
  rty_P[3] = localDW->P_c[3];

  /* End of Outputs for SubSystem: '<S5>/Output' */

  /* Outputs for Atomic SubSystem: '<S5>/Predict' */
  /* MATLAB Function: '<S21>/Predict' incorporates:
   *  DataStoreRead: '<S21>/Data Store ReadP'
   *  DataStoreRead: '<S21>/Data Store ReadX'
   */
  /* MATLAB Function 'Extras/UKFPredict_SLFcn_0Input/Predict': '<S23>:1' */
  /* '<S23>:1:2' StateTransitionFcn = coder.const(str2func(pS.FcnName)); */
  /* '<S23>:1:4' xNew = zeros(size(x),'like',x); */
  /* '<S23>:1:5' PNew = zeros(size(P),'like',x); */
  /* '<S23>:1:6' if pS.HasAdditiveNoise */
  /* '<S23>:1:7' [xNew,PNew] = matlabshared.tracking.internal.UKFPredictorAdditive.predict(... */
  /* '<S23>:1:8'         Q,x,P,... */
  /* '<S23>:1:9'         pS.Alpha, pS.Beta, pS.Kappa,... */
  /* '<S23>:1:10'         @(xx)StateTransitionFcn(xx)); */
  gain[0] = localDW->x[0];
  gain[1] = localDW->x[1];
  sqrtP[0] = localDW->P_c[0];
  sqrtP[1] = localDW->P_c[1];
  sqrtP[2] = localDW->P_c[2];
  sqrtP[3] = localDW->P_c[3];
  jmax = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j + 1 < 3)) {
    jj = (j << 1) + j;
    ajj = 0.0;
    if (!(j < 1)) {
      ix = j;
      iy = j;
      k = 1;
      while (k <= j) {
        ajj += sqrtP[ix] * sqrtP[iy];
        ix += 2;
        iy += 2;
        k = 2;
      }
    }

    ajj = sqrtP[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      sqrtP[jj] = ajj;
      if (j + 1 < 2) {
        ajj = 1.0 / ajj;
        for (ix = jj + 1; ix + 1 <= jj + 2; ix++) {
          sqrtP[ix] *= ajj;
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
    jmax = 3;
  }

  jmax--;
  j = 2;
  while (j <= jmax) {
    sqrtP[2] = 0.0;
    j = 3;
  }

  ajj = 1.4142135623730951 * sqrtP[0];
  X2[0] = ajj;
  X2[4] = -ajj;
  ajj = 1.4142135623730951 * sqrtP[1];
  X2[1] = ajj;
  X2[5] = -ajj;
  ajj = 1.4142135623730951 * sqrtP[2];
  X2[2] = ajj;
  X2[6] = -ajj;
  ajj = 1.4142135623730951 * sqrtP[3];
  X2[3] = ajj;
  X2[7] = -ajj;
  for (jmax = 0; jmax < 4; jmax++) {
    X2[jmax << 1] += localDW->x[0];
    X2[1 + (jmax << 1)] += localDW->x[1];
  }

  for (jmax = 0; jmax < 4; jmax++) {
    gain_0[0] = X2[jmax << 1];
    gain_0[1] = X2[(jmax << 1) + 1];
    batteryStateFcn(gain_0, tempY_0);
    Y2_0[jmax << 1] = tempY_0[0];
    Y2_0[1 + (jmax << 1)] = tempY_0[1];
  }

  gain_0[0] = gain[0];
  gain_0[1] = gain[1];
  batteryStateFcn(gain_0, tempY_0);
  gain[0] = tempY_0[0] * 0.0;
  gain[1] = tempY_0[1] * 0.0;
  for (jmax = 0; jmax < 4; jmax++) {
    gain[0] += Y2_0[jmax << 1] * 0.25;
    gain[1] += Y2_0[(jmax << 1) + 1] * 0.25;
  }

  tempY_0[0] -= gain[0];
  tempY_0[1] -= gain[1];
  for (jmax = 0; jmax < 4; jmax++) {
    Y2_0[jmax << 1] -= gain[0];
    Y2_0[1 + (jmax << 1)] -= gain[1];
  }

  ajj = tempY_0[0] * tempY_0[0];
  tempY = tempY_0[0] * tempY_0[1];
  tempY_idx_1 = tempY_0[1] * tempY_0[0];
  tempY_idx_3 = tempY_0[1] * tempY_0[1];
  for (jmax = 0; jmax < 2; jmax++) {
    for (j = 0; j < 2; j++) {
      Y2[jmax + (j << 1)] = 0.0;
      Y2[jmax + (j << 1)] += Y2_0[jmax] * Y2_0[j];
      Y2[jmax + (j << 1)] += Y2_0[jmax + 2] * Y2_0[j + 2];
      Y2[jmax + (j << 1)] += Y2_0[jmax + 4] * Y2_0[j + 4];
      Y2[jmax + (j << 1)] += Y2_0[jmax + 6] * Y2_0[j + 6];
    }
  }

  /* DataStoreWrite: '<S21>/Data Store WriteP' incorporates:
   *  MATLAB Function: '<S21>/Predict'
   */
  localDW->P_c[0] = (2.0 * ajj + 0.25 * Y2[0]) + 8.432E-8;
  localDW->P_c[1] = 2.0 * tempY_idx_1 + 0.25 * Y2[1];

  /* DataStoreWrite: '<S21>/Data Store WriteX' */
  localDW->x[0] = gain[0];

  /* DataStoreWrite: '<S21>/Data Store WriteP' incorporates:
   *  MATLAB Function: '<S21>/Predict'
   */
  localDW->P_c[2] = 2.0 * tempY + 0.25 * Y2[2];
  localDW->P_c[3] = (2.0 * tempY_idx_3 + 0.25 * Y2[3]) + 0.0008432;

  /* DataStoreWrite: '<S21>/Data Store WriteX' */
  localDW->x[1] = gain[1];

  /* End of Outputs for SubSystem: '<S5>/Predict' */
}

/* Output and update for Simulink Function: '<S1>/Simulink Function - Measurement Function' */
void batteryMeasurementFcn(const real_T rtu_x[2], real_T *rty_y)
{
  real_T rtb_Switch;

  /* Switch: '<S3>/Switch1' incorporates:
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/I'
   *  Inport: '<Root>/Temperature'
   *  Lookup_n-D: '<S3>/R0 Table1'
   *  Lookup_n-D: '<S3>/R0_dis Table'
   *  SignalConversion: '<S3>/TmpSignal ConversionAtxOutport1'
   *  Switch: '<S3>/Switch'
   */
  if (-rtU.I >= 0.0) {
    /* Outport: '<Root>/OCV_esti' incorporates:
     *  Inport: '<Root>/Temperature'
     *  Lookup_n-D: '<S3>/Em Table1'
     *  SignalConversion: '<S3>/TmpSignal ConversionAtxOutport1'
     */
    rtY.OCV_esti = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_EmTable1_bp01Data,
      rtCP_EmTable1_bp02Data, rtCP_EmTable1_tableData, rtCP_EmTable1_maxIndex,
      101U);
    rtb_Switch = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_R0Table1_bp01Data,
      rtCP_R0Table1_bp02Data, rtCP_R0Table1_tableData, rtCP_R0Table1_maxIndex,
      101U);
  } else {
    /* Outport: '<Root>/OCV_esti' incorporates:
     *  Inport: '<Root>/Temperature'
     *  Lookup_n-D: '<S3>/Em_dis Table'
     *  SignalConversion: '<S3>/TmpSignal ConversionAtxOutport1'
     */
    rtY.OCV_esti = look2_binlx(rtu_x[0], rtU.Temperature,
      rtCP_Em_disTable_bp01Data, rtCP_Em_disTable_bp02Data,
      rtCP_Em_disTable_tableData, rtCP_Em_disTable_maxIndex, 101U);
    rtb_Switch = look2_binlx(rtu_x[0], rtU.Temperature,
      rtCP_R0_disTable_bp01Data, rtCP_R0_disTable_bp02Data,
      rtCP_R0_disTable_tableData, rtCP_R0_disTable_maxIndex, 101U);
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Outport: '<Root>/y' incorporates:
   *  Inport: '<Root>/I'
   *  Outport: '<Root>/OCV_esti'
   *  Product: '<S3>/Product'
   *  SignalConversion: '<S3>/TmpSignal ConversionAtxOutport1'
   *  Sum: '<S3>/Add1'
   */
  rtY.y = (rtY.OCV_esti - rtb_Switch * rtU.I) - rtu_x[1];

  /* SignalConversion: '<S3>/TmpSignal ConversionAtyInport1' incorporates:
   *  Outport: '<Root>/y'
   */
  *rty_y = rtY.y;
}

/* Output and update for Simulink Function: '<S1>/Simulink Function - State Transition Function1' */
void batteryStateFcn(const real_T rtu_x[2], real_T rty_xNext[2])
{
  real_T rtb_Switch;
  real_T tmp;

  /* Switch: '<S4>/Switch' incorporates:
   *  Gain: '<S4>/Gain'
   *  Inport: '<Root>/I'
   *  Inport: '<Root>/Temperature'
   *  Lookup_n-D: '<S4>/C1 Table1'
   *  Lookup_n-D: '<S4>/C1_dis Table'
   *  SignalConversion: '<S4>/TmpSignal ConversionAtxOutport1'
   */
  if (-rtU.I >= 0.0) {
    rtb_Switch = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_C1Table1_bp01Data,
      rtCP_C1Table1_bp02Data, rtCP_C1Table1_tableData, rtCP_C1Table1_maxIndex,
      101U);
  } else {
    rtb_Switch = look2_binlx(rtu_x[0], rtU.Temperature,
      rtCP_C1_disTable_bp01Data, rtCP_C1_disTable_bp02Data,
      rtCP_C1_disTable_tableData, rtCP_C1_disTable_maxIndex, 101U);
  }

  /* End of Switch: '<S4>/Switch' */

  /* SignalConversion: '<S4>/TmpSignal ConversionAtxNextInport1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Inport: '<Root>/Cq'
   *  Inport: '<Root>/I'
   *  MATLAB Function: '<S4>/f(x,u)'
   *  Product: '<S4>/Product'
   *  SignalConversion: '<S4>/TmpSignal ConversionAtxOutport1'
   *  Sum: '<S4>/Add'
   */
  /* MATLAB Function 'Extended Kalman SOC estimator/Simulink Function - State Transition Function1/f(x,u)': '<S18>:1' */
  /* '<S18>:1:2' xdot = zeros(size(x)); */
  /* '<S18>:1:3' U1 = x(2); */
  /* '<S18>:1:4' xdot(1) = -I/(3600*Cq); */
  /* '<S18>:1:5' xdot(2) = -1/(R1*C1)*U1 + I/C1; */
  rty_xNext[0] = -rtU.I / (3600.0 * rtU.Cq) * 0.1 + rtu_x[0];

  /* Switch: '<S4>/Switch1' incorporates:
   *  Gain: '<S4>/Gain'
   *  Inport: '<Root>/I'
   *  Inport: '<Root>/Temperature'
   *  Lookup_n-D: '<S4>/R1 Table'
   *  Lookup_n-D: '<S4>/R1_dis Table1'
   *  SignalConversion: '<S4>/TmpSignal ConversionAtxOutport1'
   */
  if (-rtU.I >= 120000.0) {
    tmp = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_R1Table_bp01Data,
                      rtCP_R1Table_bp02Data, rtCP_R1Table_tableData,
                      rtCP_R1Table_maxIndex, 101U);
  } else {
    tmp = look2_binlx(rtu_x[0], rtU.Temperature, rtCP_R1_disTable1_bp01Data,
                      rtCP_R1_disTable1_bp02Data, rtCP_R1_disTable1_tableData,
                      rtCP_R1_disTable1_maxIndex, 101U);
  }

  /* End of Switch: '<S4>/Switch1' */

  /* SignalConversion: '<S4>/TmpSignal ConversionAtxNextInport1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Inport: '<Root>/I'
   *  MATLAB Function: '<S4>/f(x,u)'
   *  Product: '<S4>/Product'
   *  SignalConversion: '<S4>/TmpSignal ConversionAtxOutport1'
   *  Sum: '<S4>/Add'
   */
  rty_xNext[1] = (-1.0 / (tmp * rtb_Switch) * rtu_x[1] + rtU.I / rtb_Switch) *
    0.1 + rtu_x[1];
}

/* Model step function */
double Extended_step(double V8[8])
{
  real_T xNew[2];
  real_T PNew[4];
  real_T z;
  real_T zEstimated;
  real_T b_z;
  real_T imvec[2];
  real_T imz;
  real_T Q[4];
  real_T Jacobian[4];
  real_T z_0[2];
  real_T imz_0[2];
  real_T rtb_DataStoreRead_e[2];
  real_T rtb_DataStoreRead[2];
  real_T rtb_DataStoreRead_m[2];
  real_T rtb_DataStoreRead_oe[2];
  real_T rtb_DataStoreRead_l[2];
  real_T rtb_DataStoreRead_nl[2];
  real_T rtb_DataStoreRead_f[2];
  real_T rtb_DataStoreRead_om[2];
  real_T Jacobian_0[4];
  int32_T i;
  real_T b_f1_idx_1;
  real_T dHdx_idx_0;
  real_T dHdx_idx_1;
  real_T u1;

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter1' */

  /* Inport: '<Root>/signal1b' incorporates:
   *  Inport: '<Root>/signal1'
   *  Outport: '<Root>/signal1d'
   */
  UnscentedKalmanFilter1(rtU.signal1_a, rtU.signal1, rtb_DataStoreRead_e,
    rtY.signal1d, &rtDW.UnscentedKalmanFilter1_g);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter1' */

  /* Outport: '<Root>/signal1a' */
  rtY.signal1a = rtb_DataStoreRead_e[0];

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter8' */

  /* Inport: '<Root>/signal2b' incorporates:
   *  Inport: '<Root>/signal2'
   *  Outport: '<Root>/signal2d'
   */
  UnscentedKalmanFilter1(rtU.signal2_a, rtU.signal2, rtb_DataStoreRead,
    rtY.signal2d, &rtDW.UnscentedKalmanFilter8);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter8' */

  /* Outport: '<Root>/signal2a' */
  rtY.signal2a = rtb_DataStoreRead[0];

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter7' */

  /* Inport: '<Root>/signal3b' incorporates:
   *  Inport: '<Root>/signal3'
   *  Outport: '<Root>/signal3d'
   */
  UnscentedKalmanFilter1(rtU.signal3_b, rtU.signal3, rtb_DataStoreRead_m,
    rtY.signal3d, &rtDW.UnscentedKalmanFilter7);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter7' */

  /* Outport: '<Root>/signal3a' */
  rtY.signal3a = rtb_DataStoreRead_m[0];

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter6' */

  /* Inport: '<Root>/signal4b' incorporates:
   *  Inport: '<Root>/signal4'
   *  Outport: '<Root>/signal4d'
   */
  UnscentedKalmanFilter1(rtU.signal4_b, rtU.signal4, rtb_DataStoreRead_oe,
    rtY.signal4d, &rtDW.UnscentedKalmanFilter6);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter6' */

  /* Outport: '<Root>/signal4a' */
  rtY.signal4a = rtb_DataStoreRead_oe[0];

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter5' */

  /* Inport: '<Root>/signal5b' incorporates:
   *  Inport: '<Root>/signal5'
   *  Outport: '<Root>/signal5d'
   */
  UnscentedKalmanFilter1(rtU.signal5_c, rtU.signal5, rtb_DataStoreRead_l,
    rtY.signal5d, &rtDW.UnscentedKalmanFilter5);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter5' */

  /* Outport: '<Root>/signal5a' */
  rtY.signal5a = rtb_DataStoreRead_l[0];

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter4' */

  /* Inport: '<Root>/signal6b' incorporates:
   *  Inport: '<Root>/signal6'
   *  Outport: '<Root>/signal6d'
   */
  UnscentedKalmanFilter1(rtU.signal6_e, rtU.signal6, rtb_DataStoreRead_nl,
    rtY.signal6d, &rtDW.UnscentedKalmanFilter4);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter4' */

  /* Outport: '<Root>/signal6a' */
  rtY.signal6a = rtb_DataStoreRead_nl[0];

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter3' */

  /* Inport: '<Root>/signal7b' incorporates:
   *  Inport: '<Root>/signal7'
   *  Outport: '<Root>/signal7d'
   */
  UnscentedKalmanFilter1(rtU.signal7_m, rtU.signal7, rtb_DataStoreRead_f,
    rtY.signal7d, &rtDW.UnscentedKalmanFilter3);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter3' */

  /* Outport: '<Root>/signal7a' */
  rtY.signal7a = rtb_DataStoreRead_f[0];

  /* Outputs for Atomic SubSystem: '<S1>/Unscented Kalman Filter2' */

  /* Inport: '<Root>/signal8b' incorporates:
   *  Inport: '<Root>/signal8'
   *  Outport: '<Root>/signal8d'
   */
  UnscentedKalmanFilter1(rtU.signal8_k, rtU.signal8, rtb_DataStoreRead_om,
    rtY.signal8d, &rtDW.UnscentedKalmanFilter2);

  /* End of Outputs for SubSystem: '<S1>/Unscented Kalman Filter2' */

  /* Outport: '<Root>/signal8a' */
  rtY.signal8a = rtb_DataStoreRead_om[0];

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter1' */
  /* Outputs for Enabled SubSystem: '<S2>/Correct1' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  /* Inport: '<Root>/signal8b' */
  if (rtU.signal8_k) {
    /* MATLAB Function: '<S13>/Correct' incorporates:
     *  DataStoreRead: '<S13>/Data Store ReadP'
     *  DataStoreRead: '<S13>/Data Store ReadX'
     *  Inport: '<Root>/signal8'
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
    z = rtU.signal8;
    PNew[0] = rtDW.P_p[0];
    PNew[1] = rtDW.P_p[1];
    PNew[2] = rtDW.P_p[2];
    PNew[3] = rtDW.P_p[3];
    xNew[0] = rtDW.x[0];
    xNew[1] = rtDW.x[1];
    dHdx_idx_1 = rtDW.x[0];

    /* DataStoreRead: '<S13>/Data Store ReadX' */
    imvec[0] = rtDW.x[0];

    /* MATLAB Function: '<S13>/Correct' incorporates:
     *  DataStoreRead: '<S13>/Data Store ReadX'
     */
    b_f1_idx_1 = rtDW.x[1];

    /* DataStoreRead: '<S13>/Data Store ReadX' */
    imvec[1] = rtDW.x[1];

    /* MATLAB Function: '<S13>/Correct' */
    batteryMeasurementFcn(imvec, &b_z);
    u1 = 1.4901161193847656E-8 * fabs(dHdx_idx_1);
    if ((1.4901161193847656E-8 > u1) || rtIsNaN(u1)) {
      u1 = 1.4901161193847656E-8;
    }

    imz_0[0] = dHdx_idx_1 + u1;
    imz_0[1] = b_f1_idx_1;
    batteryMeasurementFcn(imz_0, &imz);
    dHdx_idx_0 = (imz - b_z) / u1;
    u1 = 1.4901161193847656E-8 * fabs(b_f1_idx_1);
    if ((1.4901161193847656E-8 > u1) || rtIsNaN(u1)) {
      u1 = 1.4901161193847656E-8;
    }

    imz_0[0] = dHdx_idx_1;
    imz_0[1] = b_f1_idx_1 + u1;
    batteryMeasurementFcn(imz_0, &imz);
    dHdx_idx_1 = (imz - b_z) / u1;
    b_f1_idx_1 = (dHdx_idx_0 * PNew[0] + dHdx_idx_1 * PNew[1]) * dHdx_idx_0 +
      (dHdx_idx_0 * PNew[2] + dHdx_idx_1 * PNew[3]) * dHdx_idx_1;
    imz_0[0] = xNew[0];
    imz_0[1] = xNew[1];
    batteryMeasurementFcn(imz_0, &zEstimated);
    imvec[0] = (PNew[0] * dHdx_idx_0 + PNew[2] * dHdx_idx_1) / (b_f1_idx_1 +
      0.08432);
    imvec[1] = (PNew[1] * dHdx_idx_0 + PNew[3] * dHdx_idx_1) / (b_f1_idx_1 +
      0.08432);
    z -= zEstimated;
    for (i = 0; i < 2; i++) {
      Jacobian[i] = imvec[i] * dHdx_idx_0;
      Jacobian[i + 2] = imvec[i] * dHdx_idx_1;

      /* DataStoreWrite: '<S13>/Data Store WriteP' */
      rtDW.P_p[i] = PNew[i] - (Jacobian[i + 2] * PNew[1] + Jacobian[i] * PNew[0]);
      rtDW.P_p[i + 2] = PNew[i + 2] - (Jacobian[i + 2] * PNew[3] + Jacobian[i] *
        PNew[2]);
    }

    /* DataStoreWrite: '<S13>/Data Store WriteX' incorporates:
     *  MATLAB Function: '<S13>/Correct'
     */
    rtDW.x[0] = imvec[0] * z + xNew[0];
    rtDW.x[1] = imvec[1] * z + xNew[1];
  }

  /* End of Outputs for SubSystem: '<S2>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S2>/Predict' */
  /* MATLAB Function: '<S15>/Predict' incorporates:
   *  Constant: '<S2>/Q'
   *  DataStoreRead: '<S15>/Data Store ReadP'
   *  DataStoreRead: '<S15>/Data Store ReadX'
   */
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
  Q[0] = 8.432E-8;
  PNew[0] = rtDW.P_p[0];
  Q[1] = 0.0;
  PNew[1] = rtDW.P_p[1];
  Q[2] = 0.0;
  PNew[2] = rtDW.P_p[2];
  Q[3] = 0.0008432;
  PNew[3] = rtDW.P_p[3];
  xNew[0] = rtDW.x[0];
  xNew[1] = rtDW.x[1];
  dHdx_idx_1 = rtDW.x[0];

  /* DataStoreRead: '<S15>/Data Store ReadX' */
  imvec[0] = rtDW.x[0];

  /* MATLAB Function: '<S15>/Predict' incorporates:
   *  DataStoreRead: '<S15>/Data Store ReadX'
   */
  b_f1_idx_1 = rtDW.x[1];

  /* DataStoreRead: '<S15>/Data Store ReadX' */
  imvec[1] = rtDW.x[1];

  /* MATLAB Function: '<S15>/Predict' */
  batteryStateFcn(imvec, z_0);
  u1 = 1.4901161193847656E-8 * fabs(dHdx_idx_1);
  if ((1.4901161193847656E-8 > u1) || rtIsNaN(u1)) {
    u1 = 1.4901161193847656E-8;
  }

  imvec[0] = dHdx_idx_1 + u1;
  imvec[1] = b_f1_idx_1;
  batteryStateFcn(imvec, imz_0);
  Jacobian[0] = (imz_0[0] - z_0[0]) / u1;
  Jacobian[1] = (imz_0[1] - z_0[1]) / u1;
  u1 = 1.4901161193847656E-8 * fabs(b_f1_idx_1);
  if ((1.4901161193847656E-8 > u1) || rtIsNaN(u1)) {
    u1 = 1.4901161193847656E-8;
  }

  imvec[0] = dHdx_idx_1;
  imvec[1] = b_f1_idx_1 + u1;
  batteryStateFcn(imvec, imz_0);
  Jacobian[2] = (imz_0[0] - z_0[0]) / u1;
  Jacobian[3] = (imz_0[1] - z_0[1]) / u1;
  imz_0[0] = xNew[0];
  imz_0[1] = xNew[1];
  batteryStateFcn(imz_0, xNew);

  /* DataStoreWrite: '<S15>/Data Store WriteX' incorporates:
   *  MATLAB Function: '<S15>/Predict'
   */
  rtDW.x[0] = xNew[0];
  rtDW.x[1] = xNew[1];

  /* End of Outputs for SubSystem: '<S2>/Predict' */
  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter1' */

  /* Outport: '<Root>/signal1c' */
  rtY.signal1c = rtb_DataStoreRead_e[1];

  /* Outport: '<Root>/signal2c' */
  rtY.signal2c = rtb_DataStoreRead[1];

  /* Outport: '<Root>/signal3c' */
  rtY.signal3c = rtb_DataStoreRead_m[1];

  /* Outport: '<Root>/signal4c' */
  rtY.signal4c = rtb_DataStoreRead_oe[1];

  /* Outport: '<Root>/signal5c' */
  rtY.signal5c = rtb_DataStoreRead_l[1];

  /* Outport: '<Root>/signal6c' */
  rtY.signal6c = rtb_DataStoreRead_nl[1];

  /* Outport: '<Root>/signal7c' */
  rtY.signal7c = rtb_DataStoreRead_f[1];

  /* Outport: '<Root>/signal8c' */
  rtY.signal8c = rtb_DataStoreRead_om[1];

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter1' */
  /* Outputs for Atomic SubSystem: '<S2>/Predict' */
  for (i = 0; i < 2; i++) {
    /* MATLAB Function: '<S15>/Predict' */
    Jacobian_0[i] = 0.0;
    Jacobian_0[i] += Jacobian[i] * PNew[0];
    Jacobian_0[i] += Jacobian[i + 2] * PNew[1];
    Jacobian_0[i + 2] = 0.0;
    Jacobian_0[i + 2] += Jacobian[i] * PNew[2];
    Jacobian_0[i + 2] += Jacobian[i + 2] * PNew[3];

    /* DataStoreWrite: '<S15>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S15>/Predict'
     */
    rtDW.P_p[i] = (Jacobian_0[i + 2] * Jacobian[2] + Jacobian_0[i] * Jacobian[0])
      + Q[i];
    rtDW.P_p[i + 2] = (Jacobian_0[i + 2] * Jacobian[3] + Jacobian_0[i] *
                       Jacobian[1]) + Q[i + 2];

    /* Outport: '<Root>/signal1e' */
    rtY.signal1e[i] = rtb_DataStoreRead_e[i];

    /* Outport: '<Root>/signal2e' */
    rtY.signal2e[i] = rtb_DataStoreRead[i];

    /* Outport: '<Root>/signal3e' */
    rtY.signal3e[i] = rtb_DataStoreRead_m[i];

    /* Outport: '<Root>/signal4e' */
    rtY.signal4e[i] = rtb_DataStoreRead_oe[i];

    /* Outport: '<Root>/signal5e' */
    rtY.signal5e[i] = rtb_DataStoreRead_l[i];

    /* Outport: '<Root>/signal6e' */
    rtY.signal6e[i] = rtb_DataStoreRead_nl[i];

    /* Outport: '<Root>/signal7e' */
    rtY.signal7e[i] = rtb_DataStoreRead_f[i];

    /* Outport: '<Root>/signal8e' */
    rtY.signal8e[i] = rtb_DataStoreRead_om[i];
	
	
  }
	return (double)rtY.signal8a;
  /* End of Outputs for SubSystem: '<S2>/Predict' */
  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter1' */
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

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter8' */
  UnscentedKalmanFilter1_Start(&rtDW.UnscentedKalmanFilter8);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter8' */

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter7' */
  UnscentedKalmanFilter1_Start(&rtDW.UnscentedKalmanFilter7);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter7' */

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter6' */
  UnscentedKalmanFilter1_Start(&rtDW.UnscentedKalmanFilter6);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter6' */

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter5' */
  UnscentedKalmanFilter1_Start(&rtDW.UnscentedKalmanFilter5);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter5' */

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter4' */
  UnscentedKalmanFilter1_Start(&rtDW.UnscentedKalmanFilter4);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter4' */

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter3' */
  UnscentedKalmanFilter1_Start(&rtDW.UnscentedKalmanFilter3);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter3' */

  /* Start for Atomic SubSystem: '<S1>/Unscented Kalman Filter2' */
  UnscentedKalmanFilter1_Start(&rtDW.UnscentedKalmanFilter2);

  /* End of Start for SubSystem: '<S1>/Unscented Kalman Filter2' */

  /* Start for Atomic SubSystem: '<S1>/Extended Kalman Filter1' */
  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - P' */
  rtDW.P_p[0] = 0.01;
  rtDW.P_p[1] = 0.0;
  rtDW.P_p[2] = 0.0;
  rtDW.P_p[3] = 0.001;

  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - x' */
  rtDW.x[0] = 0.5;
  rtDW.x[1] = 0.0;

  /* End of Start for SubSystem: '<S1>/Extended Kalman Filter1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
