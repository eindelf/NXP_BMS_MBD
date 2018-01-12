/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: rtGetNaN.c
 *
 * Code generated for Simulink model 'BMS_SOC_ESTIMATION'.
 *
 * Model version                  : 1.418
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu May 25 14:26:47 2017
 */

/*
 * Abstract:
 *      Function to initialize non-finite, NaN
 */
#include "rtGetNaN.h"
#define NumBitsPerChar                 8U

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      BigEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FFFFFFFU;
    tmpVal.bitVal.words.wordL = 0xFFFFFFFFU;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0x7FFFFFFFU;
  return nanF.wordL.wordLreal;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
