/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "Extended.h"
#include "look2_binlx.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_roundd_snf.h"
#include "rtwtypes.h"

/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width                        1
#define y_width                        1

/*
 * Create external references here.
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void SOCEstimationTask_Outputs_wrapper(const int32_T *I,
  const uint16_T *V8,
  const int16_T *T,
  const uint16_T *Enable8,
  uint16_T *SOC,
  uint16_T *Vt)
{
  /* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
  /* This sample sets the output equal to the input
     y0[0] = u0[0];
     For complex signals use: y0[0].re = u0[0].re;
     y0[0].im = u0[0].im;
     y1[0].re = u1[0].re;
     y1[0].im = u1[0].im;
   */
  Extended_step_SFcn(I,V8,T,Enable8,SOC,Vt);

  /* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
