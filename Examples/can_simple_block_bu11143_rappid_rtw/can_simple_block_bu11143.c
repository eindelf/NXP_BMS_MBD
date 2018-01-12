/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: can_simple_block_bu11143.c
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

#include "can_simple_block_bu11143.h"
#include "can_simple_block_bu11143_private.h"

/* Named constants for Chart: '<S9>/Chart' */
#define IN_A                           ((uint8_T)1U)
#define IN_A1                          ((uint8_T)2U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)

/* Named constants for Chart: '<S4>/Chart' */
#define IN_A1_c                        ((uint8_T)2U)
#define IN_A2                          ((uint8_T)3U)
#define IN_A_j                         ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD_j           ((uint8_T)0U)

/* Named constants for Chart: '<S4>/Data collection chart' */
#define IN_GPIO123                     ((uint8_T)1U)
#define IN_GPIO45_Vref                 ((uint8_T)2U)
#define IN_Vol_C123                    ((uint8_T)3U)
#define IN_Vol_C456                    ((uint8_T)4U)
#define IN_Vol_C789                    ((uint8_T)5U)

/* Named constants for Chart: '<S2>/Chart1' */
#define IN_A1_j                        ((uint8_T)2U)
#define IN_A_f                         ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD_g           ((uint8_T)0U)

/* Block signals and states (auto storage) */
D_Work rtDWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs rtY;
void Double2MultiWord(real_T u1, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T currExp;
  int32_T prevExp;
  int32_T msl;
  real_T yn;
  real_T yd;
  boolean_T isNegative;
  uint32_T u1i;
  uint32_T cb;
  isNegative = (u1 < 0.0);
  yn = frexp(u1, &currExp);
  msl = currExp <= 0 ? -1 : (currExp - 1) / 32;
  cb = 1U;
  for (i = msl + 1; i < n; i++) {
    y[i] = 0U;
  }

  yn = isNegative ? -yn : yn;
  prevExp = 32 * msl;
  for (i = msl; i >= 0; i--) {
    yn = ldexp(yn, currExp - prevExp);
    yd = floor(yn);
    yn -= yd;
    if (i < n) {
      y[i] = (uint32_T)yd;
    }

    currExp = prevExp;
    prevExp -= 32;
  }

  if (isNegative) {
    for (i = 0; i < n; i++) {
      u1i = ~y[i];
      cb += u1i;
      y[i] = cb;
      cb = (uint32_T)(cb < u1i);
    }
  }
}

void uMultiWord2uMultiWordSat(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n)
{
  int32_T i;
  boolean_T doSaturation = false;
  int32_T nc;
  i = n1 - 1;
  while ((!doSaturation) && (i >= n)) {
    doSaturation = (u1[i] != 0U);
    i--;
  }

  if (doSaturation) {
    for (i = 0; i < n; i++) {
      y[i] = MAX_uint32_T;
    }
  } else {
    nc = n1 < n ? n1 : n;
    for (i = 0; i < nc; i++) {
      y[i] = u1[i];
    }

    while (i < n) {
      y[i] = 0U;
      i++;
    }
  }
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  uint32_T yi;
  uint32_T u1i;
  uint32_T carry = 0U;
  int32_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0U ? (uint32_T)(yi <= u1i) : (uint32_T)(yi < u1i);
  }
}

void uMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[], int32_T
  n)
{
  int32_T nm;
  int32_T i;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    for (i = nm; i < n; i++) {
      y[i] = 0U;
    }
  }
}

void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T nc;
  int32_T i;
  uint32_T ys;
  uint32_T u1i;
  uint32_T yi;
  uint32_T nr;
  uint32_T nl;
  nb = (int32_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  nc = nb > n ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    nl = n2 - ((uint32_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      nr = 32U - nl;
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> nr;
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> nr | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  y[0] = u;
  for (i = 1; i < n; i++) {
    y[i] = 0U;
  }
}

uint32_T uMultiWord2uLongSat(const uint32_T u1[], int32_T n1)
{
  uint32_T ret;
  uMultiWord2uMultiWordSat(u1, n1, &ret, 1);
  return ret;
}

void MultiWordAnd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  for (i = 0; i < n; i++) {
    y[i] = u1[i] & u2[i];
  }
}

void uMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T i;
  uint32_T yi;
  uint32_T u1i;
  int32_T nc;
  uint32_T nr;
  uint32_T nl;
  int32_T i1;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      nl = 32U - nr;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << nl | yi;
        i++;
      }

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << nl;
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0U;
    i++;
  }
}

/* Output and update for function-call system: '<Root>/Subsystem' */
void Subsystem(void)
{
  int32_T i;

  /* Inport: '<S7>/In3' */
  for (i = 0; i < 8; i++) {
    rtDWork.In3[i] = rtDWork.CANReceiveDataTrigger1_o4[i];
  }

  /* End of Inport: '<S7>/In3' */
}

/* System initialize for function-call system: '<Root>/Subsystem2' */
void Subsystem2_Init(void)
{
  /* SystemInitialize for Chart: '<S9>/Chart' */
  rtDWork.A_m = false;
}

/* System reset for function-call system: '<Root>/Subsystem2' */
void Subsystem2_Reset(void)
{
  /* SystemReset for Chart: '<S9>/Chart' */
  rtDWork.is_active_c1_can_simple_block_b = 0U;
  rtDWork.is_c1_can_simple_block_bu11143 = IN_NO_ACTIVE_CHILD;
  rtDWork.count_k = 0U;
  rtDWork.A_m = false;
}

/* Start for function-call system: '<Root>/Subsystem2' */
void Subsystem2_Start(void)
{
  /* Start for S-Function (gpio_564xl_output): '<S9>/Digital Output 4' */

  /* Initialize Pad Configuration Register 12 as Output */
  gpo_init_pcr_out_564xl_fnc( 12 );
}

/* Output and update for function-call system: '<Root>/Subsystem2' */
void Subsystem2(void)
{
  /* S-Function (SPIRead): '<S9>/S-Function Builder1' */
  SPIRead_Outputs_wrapper( &rtDWork.SFunctionBuilder1_o1,
    &rtDWork.SFunctionBuilder1_o2, &rtDWork.SFunctionBuilder1_o3,
    &rtDWork.SFunctionBuilder1_o4 );

  /* Chart: '<S9>/Chart' */
  /* Gateway: Subsystem2/Chart */
  /* During: Subsystem2/Chart */
  if (rtDWork.is_active_c1_can_simple_block_b == 0U) {
    /* Entry: Subsystem2/Chart */
    rtDWork.is_active_c1_can_simple_block_b = 1U;

    /* Entry Internal: Subsystem2/Chart */
    /* Transition: '<S80>:1' */
    rtDWork.count_k = 0U;
    rtDWork.is_c1_can_simple_block_bu11143 = IN_A;
    rtDWork.A_m = true;
  } else if (rtDWork.is_c1_can_simple_block_bu11143 == IN_A) {
    /* During 'A': '<S80>:3' */
    /* Transition: '<S80>:7' */
    rtDWork.A_m = false;
    rtDWork.is_c1_can_simple_block_bu11143 = IN_A1;
  } else {
    /* During 'A1': '<S80>:6' */
    /* Transition: '<S80>:8' */
    rtDWork.count_k++;
    rtDWork.is_c1_can_simple_block_bu11143 = IN_A;
    rtDWork.A_m = true;
  }

  /* End of Chart: '<S9>/Chart' */

  /* S-Function (gpio_564xl_output): '<S9>/Digital Output 4' */

  /* Pin Data Output Signal Update PCR[12]. */
  gpo_pin_update_564xl_fnc(12, rtDWork.A_m);/* GPO Pin Data Output Register Update */
}

/* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
void FunctionCallSubsystem_Init(void)
{
  /* SystemInitialize for Chart: '<S4>/Chart' */
  rtDWork.A = false;
}

/* System reset for function-call system: '<Root>/Function-Call Subsystem' */
void FunctionCallSubsystem_Reset(void)
{
  /* SystemReset for Chart: '<S4>/Chart' */
  rtDWork.is_active_c7_can_simple_block_b = 0U;
  rtDWork.is_c7_can_simple_block_bu11143 = IN_NO_ACTIVE_CHILD_j;
  rtDWork.count_a = 0.0;
  rtDWork.A = false;

  /* SystemReset for Chart: '<S4>/Data collection chart' */
  rtDWork.is_active_c15_can_simple_block_ = 0U;
  rtDWork.is_c15_can_simple_block_bu11143 = IN_NO_ACTIVE_CHILD_j;
  rtDWork.count_c = 0.0;
  rtDWork.CMD32[0] = 0U;
  rtDWork.CMD32[1] = 0U;
  rtDWork.CMD32[2] = 0U;
  rtDWork.CMD32[3] = 0U;
}

/* Start for function-call system: '<Root>/Function-Call Subsystem' */
void FunctionCallSubsystem_Start(void)
{
  /* Start for Chart: '<S4>/Chart' incorporates:
   *  Start for SubSystem: '<S4>/Subsystem3'
   */
  /* Start for S-Function (dspi_564xl_transmit): '<S61>/DSPI Transmit' */
  dspi_564xl_pin_init(105, 1, 1);
  dspi_564xl_pin_init(8, 0, 1);
  dspi_564xl_pin_init(7, 1, 1);
  dspi_564xl_pin_init(6, 1, 1);

  /* Start for S-Function (dspi_564xl_transmit): '<S61>/DSPI Transmit1' */
  dspi_564xl_pin_init(5, 1, 1);
  dspi_564xl_pin_init(8, 0, 1);
  dspi_564xl_pin_init(7, 1, 1);
  dspi_564xl_pin_init(6, 1, 1);

  /* Start for S-Function (gpio_564xl_output): '<S4>/Digital Output 1' */

  /* Initialize Pad Configuration Register 78 as Output */
  gpo_init_pcr_out_564xl_fnc( 78 );
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
void FunctionCallSubsystem(void)
{
  uint16_T v_aux;
  uint16_T y;
  boolean_T b_x[231];
  int32_T b_ii;
  static const real_T thermistor_ohm_table[231] = { 3.685E+6, 3.371E+6, 3.086E+6,
    2.827E+6, 2.592E+6, 2.378E+6, 2.182E+6, 2.005E+6, 1.843E+6, 1.695E+6,
    1.56E+6, 1.436E+6, 1.323E+6, 1.22E+6, 1.126E+6, 1.039E+6, 959900.0, 887200.0,
    820500.0, 759200.0, 702900.0, 651100.0, 603500.0, 559700.0, 519400.0,
    482200.0, 447900.0, 416300.0, 387100.0, 360200.0, 335300.0, 312300.0,
    291000.0, 271300.0, 253000.0, 236200.0, 220500.0, 205900.0, 192500.0,
    180000.0, 239800.0, 226000.0, 213200.0, 201100.0, 189800.0, 179200.0,
    169300.0, 160000.0, 151200.0, 143000.0, 135200.0, 127900.0, 121100.0,
    114600.0, 108600.0, 102900.0, 97490.0, 92430.0, 87660.0, 83160.0, 78910.0,
    74910.0, 71130.0, 67570.0, 64200.0, 61020.0, 58010.0, 55170.0, 52480.0,
    49940.0, 47540.0, 45270.0, 43110.0, 41070.0, 39140.0, 37310.0, 35570.0,
    33930.0, 32370.0, 30890.0, 29490.0, 28150.0, 26890.0, 25690.0, 24550.0,
    23460.0, 22430.0, 21450.0, 20520.0, 19630.0, 18790.0, 17980.0, 17220.0,
    16490.0, 15790.0, 15130.0, 14500.0, 13900.0, 13330.0, 12790.0, 12260.0,
    11770.0, 11290.0, 10840.0, 10410.0, 10000.0, 9605.0, 9227.0, 8867.0, 8523.0,
    8194.0, 7880.0, 7579.0, 7291.0, 7016.0, 6752.0, 6500.0, 6258.0, 6026.0,
    5805.0, 5592.0, 5389.0, 5193.0, 5006.0, 4827.0, 4655.0, 4489.0, 4331.0,
    4179.0, 4033.0, 3893.0, 3758.0, 3629.0, 3504.0, 3385.0, 3270.0, 3160.0,
    3054.0, 2952.0, 2854.0, 2760.0, 2669.0, 2582.0, 2497.0, 2417.0, 2339.0,
    2264.0, 2191.0, 2122.0, 2055.0, 1990.0, 1928.0, 1868.0, 1810.0, 1754.0,
    1700.0, 1648.0, 1598.0, 1549.0, 1503.0, 1458.0, 1414.0, 1372.0, 1332.0,
    1293.0, 1255.0, 1218.0, 1183.0, 1140.0, 1116.0, 1084.0, 1053.0, 1023.0,
    994.2, 966.30000000000007, 939.30000000000007, 913.2, 887.90000000000009,
    863.40000000000009, 839.7, 816.80000000000007, 794.6, 773.1,
    752.30000000000007, 732.1, 712.6, 693.6, 675.30000000000007, 657.5,
    640.30000000000007, 623.5, 607.30000000000007, 591.6, 576.4, 561.6,
    547.30000000000007, 533.4, 519.9, 506.8, 494.1, 481.8, 469.8,
    458.20000000000005, 446.90000000000003, 435.90000000000003, 425.3,
    414.90000000000003, 404.90000000000003, 395.1, 385.6, 376.40000000000003,
    367.40000000000003, 358.70000000000005, 350.3, 342.0, 334.0, 326.3,
    318.70000000000005, 311.3, 304.2, 297.2, 290.40000000000003, 283.8,
    277.40000000000003, 271.2, 265.1, 259.2, 253.4, 247.8, 242.3, 237.0 };

  int32_T rtb_STATE;
  int32_T ii_data_idx_0;
  int16_T tmp;
  uint32_T qY;
  uint32_T tmp_0;
  boolean_T exitg1;
  boolean_T exitg2;

  /* Chart: '<S4>/Chart' */
  /* Gateway: Function-Call
     Subsystem/Chart */
  /* During: Function-Call
     Subsystem/Chart */
  if (rtDWork.is_active_c7_can_simple_block_b == 0U) {
    /* Entry: Function-Call
       Subsystem/Chart */
    rtDWork.is_active_c7_can_simple_block_b = 1U;

    /* Entry Internal: Function-Call
       Subsystem/Chart */
    /* Transition: '<S44>:1' */
    rtDWork.count_a = 0.0;
    rtDWork.is_c7_can_simple_block_bu11143 = IN_A_j;
    rtDWork.A = true;
  } else {
    switch (rtDWork.is_c7_can_simple_block_bu11143) {
     case IN_A_j:
      /* Outputs for Function Call SubSystem: '<S4>/Subsystem3' */

      /* During 'A': '<S44>:3' */
      /* Transition: '<S44>:7' */
      /* Event: '<S44>:13' */

      /* S-Function (dspi_564xl_transmit): '<S61>/DSPI Transmit' */
      {
        DSPI_PUSHR_32B_tag pushr;
        pushr.R = 0U;
        pushr.B.TXDATA = rtConstB.DataTypeConversion;
        pushr.R |= (uint32_t)2<<16;
        dspi_564xl_send(1,pushr);
      }

      /* S-Function (dspi_564xl_transmit): '<S61>/DSPI Transmit1' */
      {
        DSPI_PUSHR_32B_tag pushr;
        pushr.R = 0U;
        pushr.B.TXDATA = rtConstB.DataTypeConversion1;
        pushr.R |= (uint32_t)1<<16;
        dspi_564xl_send(1,pushr);
      }

      /* End of Outputs for SubSystem: '<S4>/Subsystem3' */
      rtDWork.A = false;
      rtDWork.is_c7_can_simple_block_bu11143 = IN_A1_c;
      break;

     case IN_A1_c:
      /* During 'A1': '<S44>:6' */
      /* Transition: '<S44>:8' */
      rtDWork.count_a++;
      rtDWork.is_c7_can_simple_block_bu11143 = IN_A2;
      break;

     default:
      /* During 'A2': '<S44>:11' */
      /* Transition: '<S44>:12' */
      rtDWork.is_c7_can_simple_block_bu11143 = IN_A1_c;
      break;
    }
  }

  /* End of Chart: '<S4>/Chart' */

  /* S-Function (gpio_564xl_output): '<S4>/Digital Output 1' */

  /* Pin Data Output Signal Update PCR[78]. */
  gpo_pin_update_564xl_fnc(78, rtDWork.A);/* GPO Pin Data Output Register Update */

  /* Chart: '<S4>/Data collection chart' */
  /* Gateway: Function-Call
     Subsystem/Data collection chart */
  /* During: Function-Call
     Subsystem/Data collection chart */
  if (rtDWork.is_active_c15_can_simple_block_ == 0U) {
    /* Entry: Function-Call
       Subsystem/Data collection chart */
    rtDWork.is_active_c15_can_simple_block_ = 1U;

    /* Entry Internal: Function-Call
       Subsystem/Data collection chart */
    /* Transition: '<S50>:1' */
    rtDWork.count_c = 0.0;
    rtDWork.is_c15_can_simple_block_bu11143 = IN_Vol_C123;

    /* Entry 'Vol_C123': '<S50>:3' */
    rtDWork.CMD32[0] = (uint8_T)0x03;
    rtDWork.CMD32[1] = (uint8_T)0x70;
    rtDWork.CMD32[2] = (uint8_T)0x00;
    rtDWork.CMD32[3] = (uint8_T)0x04;
    rtb_STATE = 0;
  } else {
    switch (rtDWork.is_c15_can_simple_block_bu11143) {
     case IN_GPIO123:
      /* During 'GPIO123': '<S50>:12' */
      /* Transition: '<S50>:15' */
      /* Exit 'GPIO123': '<S50>:12' */
      /* Event: '<S50>:26' */
      rtDWork.is_c15_can_simple_block_bu11143 = IN_GPIO45_Vref;

      /* Entry 'GPIO45_Vref': '<S50>:13' */
      rtDWork.CMD32[0] = (uint8_T)0x04;
      rtDWork.CMD32[1] = (uint8_T)0x60;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x0E;
      rtb_STATE = 4;
      break;

     case IN_GPIO45_Vref:
      /* During 'GPIO45_Vref': '<S50>:13' */
      /* Transition: '<S50>:16' */
      rtDWork.count_c++;

      /* Exit 'GPIO45_Vref': '<S50>:13' */
      /* Event: '<S50>:27' */
      rtDWork.is_c15_can_simple_block_bu11143 = IN_Vol_C123;

      /* Entry 'Vol_C123': '<S50>:3' */
      rtDWork.CMD32[0] = (uint8_T)0x03;
      rtDWork.CMD32[1] = (uint8_T)0x70;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x04;
      rtb_STATE = 0;
      break;

     case IN_Vol_C123:
      /* During 'Vol_C123': '<S50>:3' */
      /* Transition: '<S50>:7' */
      /* Exit 'Vol_C123': '<S50>:3' */
      /* Event: '<S50>:25' */
      rtDWork.is_c15_can_simple_block_bu11143 = IN_Vol_C456;

      /* Entry 'Vol_C456': '<S50>:6' */
      rtDWork.CMD32[0] = (uint8_T)0x03;
      rtDWork.CMD32[1] = (uint8_T)0x70;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x06;
      rtb_STATE = 1;
      break;

     case IN_Vol_C456:
      /* During 'Vol_C456': '<S50>:6' */
      /* Transition: '<S50>:8' */
      /* Exit 'Vol_C456': '<S50>:6' */
      /* Event: '<S50>:28' */
      rtDWork.is_c15_can_simple_block_bu11143 = IN_Vol_C789;

      /* Entry 'Vol_C789': '<S50>:11' */
      rtDWork.CMD32[0] = (uint8_T)0x03;
      rtDWork.CMD32[1] = (uint8_T)0x70;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x08;
      rtb_STATE = 2;
      break;

     default:
      /* During 'Vol_C789': '<S50>:11' */
      /* Transition: '<S50>:14' */
      /* Exit 'Vol_C789': '<S50>:11' */
      /* Event: '<S50>:29' */
      rtDWork.is_c15_can_simple_block_bu11143 = IN_GPIO123;

      /* Entry 'GPIO123': '<S50>:12' */
      rtDWork.CMD32[0] = (uint8_T)0x04;
      rtDWork.CMD32[1] = (uint8_T)0x60;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x0C;
      rtb_STATE = 3;
      break;
    }
  }

  /* End of Chart: '<S4>/Data collection chart' */

  /* S-Function (SPITask): '<S4>/S-Function Builder' */
  SPITask_Outputs_wrapper(&rtDWork.CMD32[0], &rtDWork.SFunctionBuilder_o1[0],
    &rtDWork.SFunctionBuilder_o2[0] );

  /* MATLAB Function: '<S4>/RawData to StoreData' */
  /* MATLAB Function 'Function-Call Subsystem/RawData to StoreData': '<S54>:1' */
  /* '<S54>:1:6' DataFault =  zeros(1,13); */
  /*  const int thermistor_ohm_table[231] = {//unit = 0.1Ohm */
  /*                  36850000, 33710000, 30860000, 28270000, 25920000, 23780000, 21820000, 20050000, 18430000, 16950000, // -80 to -71 degC */
  /*                  15600000, 14360000, 13230000, 12200000, 11260000, 10390000,  9599000,  8872000,  8205000,  7592000, // -70 to -61 degC */
  /*                  7029000,  6511000,  6035000,  5597000,  5194000,  4822000,  4479000,  4163000,  3871000,  3602000, // -60 to -51 degC */
  /*                  3353000,  3123000,  2910000,  2713000,  2530000,  2362000,  2205000,  2059000,  1925000,  1800000, // -50 to -41 degC */
  /*                  2398000,  2260000,  2132000,  2011000,  1898000,  1792000,  1693000,  1600000,  1512000,  1430000, // -40 to -31 degC */
  /*                  1352000,  1279000,  1211000,  1146000,  1086000,  1029000,   974900,   924300,   876600,   831600, // -30 to -21 degC */
  /*                    789100,   749100,   711300,   675700,   642000,   610200,   580100,   551700,   524800,   499400, // -20 to -11 degC */
  /*                    475400,   452700,   431100,   410700,   391400,   373100,   355700,   339300,   323700,   308900, // -10 to  -1 degC */
  /*                    294900,   281500,   268900,   256900,   245500,   234600,   224300,   214500,   205200,   196300, //   0 to   9 degC */
  /*                    187900,   179800,   172200,   164900,   157900,   151300,   145000,   139000,   133300,   127900, //  10 to  19 degC */
  /*                    122600,   117700,   112900,   108400,   104100,   100000,    96050,    92270,    88670,    85230, //  20 to  29 degC */
  /*                     81940,    78800,    75790,    72910,    70160,    67520,    65000,    62580,    60260,    58050, //  30 to  39 degC */
  /*                     55920,    53890,    51930,    50060,    48270,    46550,    44890,    43310,    41790,    40330, //  40 to  49 degC */
  /*                     38930,    37580,    36290,    35040,    33850,    32700,    31600,    30540,    29520,    28540, //  50 to  59 degC */
  /*                     27600,    26690,    25820,    24970,    24170,    23390,    22640,    21910,    21220,    20550, //  60 to  69 degC */
  /*                     19900,    19280,    18680,    18100,    17540,    17000,    16480,    15980,    15490,    15030, //  70 to  79 degC */
  /*                     14580,    14140,    13720,    13320,    12930,    12550,    12180,    11830,    11400,    11160, //  80 to  89 degC */
  /*                     10840,    10530,    10230,     9942,     9663,     9393,     9132,     8879,     8634,     8397, //  90 to  99 degC */
  /*                      8168,     7946,     7731,     7523,     7321,     7126,     6936,     6753,     6575,     6403, // 100 to 109 degC */
  /*                      6235,     6073,     5916,     5764,     5616,     5473,     5334,     5199,     5068,     4941, // 110 to 119 degC */
  /*                      4818,     4698,     4582,     4469,     4359,     4253,     4149,     4049,     3951,     3856, // 120 to 129 degC */
  /*                      3764,     3674,     3587,     3503,     3420,     3340,     3263,     3187,     3113,     3042, // 130 to 139 degC */
  /*                      2972,     2904,     2838,     2774,     2712,     2651,     2592,     2534,     2478,     2423, // 140 to 149 degC */
  /*                      2370                                                                                                                                                                                                                                                                                                                                                                  // 150        degC */
  /*  }; */
  /* // -80 to -71 degC */
  /* // -70 to -61 degC */
  /* // -60 to -51 degC */
  /* // -50 to -41 degC */
  /* // -40 to -31 degC */
  /* // -30 to -21 degC */
  /* // -20 to -11 degC */
  /* // -10 to  -1 degC */
  /* //   0 to   9 degC */
  /* //  10 to  19 degC */
  /* //  20 to  29 degC */
  /* //  30 to  39 degC */
  /* //  40 to  49 degC */
  /* //  50 to  59 degC */
  /* //  60 to  69 degC */
  /* //  70 to  79 degC */
  /* //  80 to  89 degC */
  /* //  90 to  99 degC */
  /* // 100 to 109 degC */
  /* // 110 to 119 degC */
  /* // 120 to 129 degC */
  /* // 130 to 139 degC */
  /* // 140 to 149 degC */
  /* '<S54>:1:35' thermistor_ohm_table = 0.1*[ */
  /* '<S54>:1:36'                 36850000, 33710000, 30860000, 28270000, 25920000, 23780000, 21820000, 20050000, 18430000, 16950000, ...// -80 to -71 degC */
  /* '<S54>:1:37'                 15600000, 14360000, 13230000, 12200000, 11260000, 10390000,  9599000,  8872000,  8205000,  7592000, ...// -70 to -61 degC */
  /* '<S54>:1:38'                 7029000,  6511000,  6035000,  5597000,  5194000,  4822000,  4479000,  4163000,  3871000,  3602000, ...// -60 to -51 degC */
  /* '<S54>:1:39'                 3353000,  3123000,  2910000,  2713000,  2530000,  2362000,  2205000,  2059000,  1925000,  1800000, ...// -50 to -41 degC */
  /* '<S54>:1:40'                 2398000,  2260000,  2132000,  2011000,  1898000,  1792000,  1693000,  1600000,  1512000,  1430000, ...// -40 to -31 degC */
  /* '<S54>:1:41'                 1352000,  1279000,  1211000,  1146000,  1086000,  1029000,   974900,   924300,   876600,   831600, ...// -30 to -21 degC */
  /* '<S54>:1:42'                   789100,   749100,   711300,   675700,   642000,   610200,   580100,   551700,   524800,   499400, ...// -20 to -11 degC */
  /* '<S54>:1:43'                   475400,   452700,   431100,   410700,   391400,   373100,   355700,   339300,   323700,   308900, ...// -10 to  -1 degC */
  /* '<S54>:1:44'                   294900,   281500,   268900,   256900,   245500,   234600,   224300,   214500,   205200,   196300, ...//   0 to   9 degC */
  /* '<S54>:1:45'                   187900,   179800,   172200,   164900,   157900,   151300,   145000,   139000,   133300,   127900, ...//  10 to  19 degC */
  /* '<S54>:1:46'                   122600,   117700,   112900,   108400,   104100,   100000,    96050,    92270,    88670,    85230,  ...//  20 to  29 degC */
  /* '<S54>:1:47'                    81940,    78800,    75790,    72910,    70160,    67520,    65000,    62580,    60260,    58050, ...//  30 to  39 degC */
  /* '<S54>:1:48'                    55920,    53890,    51930,    50060,    48270,    46550,    44890,    43310,    41790,    40330, ...//  40 to  49 degC */
  /* '<S54>:1:49'                    38930,    37580,    36290,    35040,    33850,    32700,    31600,    30540,    29520,    28540, ...//  50 to  59 degC */
  /* '<S54>:1:50'                    27600,    26690,    25820,    24970,    24170,    23390,    22640,    21910,    21220,    20550, ...//  60 to  69 degC */
  /* '<S54>:1:51'                    19900,    19280,    18680,    18100,    17540,    17000,    16480,    15980,    15490,    15030, ...//  70 to  79 degC */
  /* '<S54>:1:52'                    14580,    14140,    13720,    13320,    12930,    12550,    12180,    11830,    11400,    11160, ...//  80 to  89 degC */
  /* '<S54>:1:53'                    10840,    10530,    10230,     9942,     9663,     9393,     9132,     8879,     8634,     8397, ...//  90 to  99 degC */
  /* '<S54>:1:54'                     8168,     7946,     7731,     7523,     7321,     7126,     6936,     6753,     6575,     6403, ...// 100 to 109 degC */
  /* '<S54>:1:55'                     6235,     6073,     5916,     5764,     5616,     5473,     5334,     5199,     5068,     4941, ...// 110 to 119 degC */
  /* '<S54>:1:56'                     4818,     4698,     4582,     4469,     4359,     4253,     4149,     4049,     3951,     3856, ...// 120 to 129 degC */
  /* '<S54>:1:57'                     3764,     3674,     3587,     3503,     3420,     3340,     3263,     3187,     3113,     3042, ...// 130 to 139 degC */
  /* '<S54>:1:58'                     2972,     2904,     2838,     2774,     2712,     2651,     2592,     2534,     2478,     2423, ...// 140 to 149 degC */
  /* '<S54>:1:59'                      2370   ]; */
  /*  // 150        degC */
  /* '<S54>:1:63' switch STATE */
  switch (rtb_STATE) {
   case 0:
    /* '<S54>:1:64' case 0 % VC123 */
    /*  VC123 */
    /* '<S54>:1:65' for i=1:13 */
    for (rtb_STATE = 0; rtb_STATE < 13; rtb_STATE++) {
      /* '<S54>:1:66' CellV_1_104(i*8-7) = uint16(SPIData(i*8-7))+uint16(SPIData(i*8-6))*256; */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 8] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 7] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 8]);

      /* '<S54>:1:67' CellV_1_104(i*8-6) = uint16(SPIData(i*8-5))+uint16(SPIData(i*8-4))*256; */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 7] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 5] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 6]);

      /* '<S54>:1:68' CellV_1_104(i*8-5) = uint16(SPIData(i*8-3))+uint16(SPIData(i*8-2))*256; */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 6] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 3] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 4]);

      /* '<S54>:1:69' if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
    }
    break;

   case 1:
    /* '<S54>:1:75' case 1 % VC456 */
    /*  VC456 */
    /* '<S54>:1:76' for i=1:13 */
    for (rtb_STATE = 0; rtb_STATE < 13; rtb_STATE++) {
      /* '<S54>:1:77' CellV_1_104(i*8-4) = uint16(SPIData(i*8-7))+uint16(SPIData(i*8-6))*256; */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 5] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 7] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 8]);

      /* '<S54>:1:78' CellV_1_104(i*8-3) = uint16(SPIData(i*8-5))+uint16(SPIData(i*8-4))*256; */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 4] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 5] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 6]);

      /* '<S54>:1:79' CellV_1_104(i*8-2) = uint16(SPIData(i*8-3))+uint16(SPIData(i*8-2))*256; */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 3] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 3] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 4]);

      /* '<S54>:1:80' if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
    }
    break;

   case 2:
    /* '<S54>:1:86' case 2 % VC78 */
    /*  VC78 */
    /* '<S54>:1:87' for i=1:13 */
    for (rtb_STATE = 0; rtb_STATE < 13; rtb_STATE++) {
      /* '<S54>:1:88' CellV_1_104(i*8-1) = uint16(SPIData(i*8-7))+uint16(SPIData(i*8-6))*256; */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 2] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 7] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 8]);

      /* '<S54>:1:89' CellV_1_104(i*8-0) = uint16(SPIData(i*8-5))+uint16(SPIData(i*8-4))*256; */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 1] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 5] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 6]);

      /*        CellV_1_104(i*8-2) = uint16(SPIData(i*8-3))+uint16(SPIData(i*8-2))*256; */
      /* '<S54>:1:91' if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
    }
    break;

   case 3:
    /* '<S54>:1:97' case 3 % GP123 */
    /*  GP123 */
    /* '<S54>:1:98' V_REF_AUX = uint16(30000); */
    rtDWork.V_REF_AUX = 30000U;

    /* '<S54>:1:99' for i=1:13 */
    for (rtb_STATE = 0; rtb_STATE < 13; rtb_STATE++) {
      /*        v_aux  = int16(uint16(SPIData(i*8-7))+uint16(SPIData(i*8-6))*256); */
      /* '<S54>:1:101' v_aux  = (uint16(SPIData(i*8-7))+uint16(SPIData(i*8-6))*256); */
      /* '<S54>:1:102' r_tm = (10000*v_aux)/(V_REF_AUX - v_aux); */
      /*         V_REF_AUX = uint16(30000); */
      /* '<S54>:1:104' temperature = (find(thermistor_ohm_table<r_tm,1))-81; */
      /* '<S54>:1:105' CellGP_1_78(i*6-5) = v_aux; */
      rtDWork.CellGP_1_78[(1 + rtb_STATE) * 6 - 6] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 7] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 8]);

      /* '<S54>:1:107' v_aux  = (uint16(SPIData(i*8-5))+uint16(SPIData(i*8-4))*256); */
      /* '<S54>:1:108' r_tm = (10000*v_aux)/(V_REF_AUX - v_aux); */
      /* '<S54>:1:109' temperature = (find(thermistor_ohm_table<r_tm,1))-81; */
      /*         v_aux  = uint16(16000);        */
      /* '<S54>:1:111' CellGP_1_78(i*6-4) = v_aux; */
      rtDWork.CellGP_1_78[(1 + rtb_STATE) * 6 - 5] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 5] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 6]);

      /* '<S54>:1:113' v_aux  = (uint16(SPIData(i*8-3))+uint16(SPIData(i*8-2))*256); */
      /* '<S54>:1:114' r_tm = (10000*v_aux) / (V_REF_AUX - v_aux); */
      /* '<S54>:1:115' temperature = (find(thermistor_ohm_table<r_tm,1))-81; */
      /* '<S54>:1:116' CellGP_1_78(i*6-3) = v_aux; */
      rtDWork.CellGP_1_78[(1 + rtb_STATE) * 6 - 4] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 3] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 4]);

      /* '<S54>:1:117' if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
    }
    break;

   case 4:
    /* '<S54>:1:123' case 4 % GP45 */
    /*  GP45 */
    /* '<S54>:1:124' for i=1:13 */
    for (rtb_STATE = 0; rtb_STATE < 13; rtb_STATE++) {
      /* '<S54>:1:125' v_aux  = (uint16(SPIData(i*8-7))+uint16(SPIData(i*8-6))*256); */
      v_aux = (uint16_T)((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 7]
                          << 8) + rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) <<
        3) - 8]);

      /* '<S54>:1:126' r_tm = (10000*v_aux)/(V_REF_AUX - v_aux); */
      tmp_0 = 10000U * v_aux;
      if (tmp_0 > 65535U) {
        tmp_0 = 65535U;
      }

      qY = (uint32_T)rtDWork.V_REF_AUX - /*MW:OvSatOk*/ v_aux;
      if (qY > rtDWork.V_REF_AUX) {
        qY = 0U;
      }

      if ((uint16_T)qY == 0) {
        if ((uint16_T)tmp_0 == 0) {
          v_aux = 0U;
        } else {
          v_aux = MAX_uint16_T;
        }
      } else {
        v_aux = (uint16_T)((uint32_T)(uint16_T)tmp_0 / (uint16_T)qY);
        y = (uint16_T)((uint32_T)(uint16_T)tmp_0 - (uint16_T)((uint32_T)v_aux *
          (uint16_T)qY));
        if ((y > 0) && (y >= (int32_T)((uint32_T)(uint16_T)qY >> 1) + ((uint16_T)
              qY & 1))) {
          v_aux++;
        }
      }

      /* '<S54>:1:127' temperature = (find(thermistor_ohm_table<r_tm,1))-81; */
      for (b_ii = 0; b_ii < 231; b_ii++) {
        b_x[b_ii] = (thermistor_ohm_table[b_ii] < v_aux);
      }

      b_ii = 1;
      exitg2 = false;
      while ((!exitg2) && (b_ii < 232)) {
        if (b_x[b_ii - 1]) {
          ii_data_idx_0 = b_ii;
          exitg2 = true;
        } else {
          b_ii++;
        }
      }

      /* '<S54>:1:128' CellGP_1_78(i*6-2) = temperature; */
      tmp = (int16_T)(ii_data_idx_0 - 81);
      if (tmp < 0) {
        tmp = 0;
      }

      rtDWork.CellGP_1_78[(1 + rtb_STATE) * 6 - 3] = (uint16_T)tmp;

      /* '<S54>:1:130' v_aux  = (uint16(SPIData(i*8-5))+uint16(SPIData(i*8-4))*256); */
      v_aux = (uint16_T)((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 5]
                          << 8) + rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) <<
        3) - 6]);

      /* '<S54>:1:131' r_tm = (10000*v_aux)/(V_REF_AUX - v_aux); */
      tmp_0 = 10000U * v_aux;
      if (tmp_0 > 65535U) {
        tmp_0 = 65535U;
      }

      qY = (uint32_T)rtDWork.V_REF_AUX - /*MW:OvSatOk*/ v_aux;
      if (qY > rtDWork.V_REF_AUX) {
        qY = 0U;
      }

      if ((uint16_T)qY == 0) {
        if ((uint16_T)tmp_0 == 0) {
          v_aux = 0U;
        } else {
          v_aux = MAX_uint16_T;
        }
      } else {
        v_aux = (uint16_T)((uint32_T)(uint16_T)tmp_0 / (uint16_T)qY);
        y = (uint16_T)((uint32_T)(uint16_T)tmp_0 - (uint16_T)((uint32_T)v_aux *
          (uint16_T)qY));
        if ((y > 0) && (y >= (int32_T)((uint32_T)(uint16_T)qY >> 1) + ((uint16_T)
              qY & 1))) {
          v_aux++;
        }
      }

      /* '<S54>:1:132' temperature = (find(thermistor_ohm_table<r_tm,1))-81; */
      for (b_ii = 0; b_ii < 231; b_ii++) {
        b_x[b_ii] = (thermistor_ohm_table[b_ii] < v_aux);
      }

      b_ii = 1;
      exitg1 = false;
      while ((!exitg1) && (b_ii < 232)) {
        if (b_x[b_ii - 1]) {
          ii_data_idx_0 = b_ii;
          exitg1 = true;
        } else {
          b_ii++;
        }
      }

      /* '<S54>:1:133' CellGP_1_78(i*6-1) = temperature; */
      tmp = (int16_T)(ii_data_idx_0 - 81);
      if (tmp < 0) {
        tmp = 0;
      }

      rtDWork.CellGP_1_78[(1 + rtb_STATE) * 6 - 2] = (uint16_T)tmp;

      /* '<S54>:1:135' CellGP_1_78(i*6-0) = uint16(uint16(SPIData(i*8-3))+uint16(SPIData(i*8-2))*256); */
      rtDWork.CellGP_1_78[(1 + rtb_STATE) * 6 - 1] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 3] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 4]);

      /* '<S54>:1:137' V_REF_AUX = (uint16(SPIData(i*8-3))+uint16(SPIData(i*8-2))*256); */
      rtDWork.V_REF_AUX = (uint16_T)((rtDWork.SFunctionBuilder_o1[((1 +
        rtb_STATE) << 3) - 3] << 8) + rtDWork.SFunctionBuilder_o1[((1 +
        rtb_STATE) << 3) - 4]);

      /* '<S54>:1:139' if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
    }
    break;

   default:
    /* '<S54>:1:145' otherwise */
    /*  ERROR     */
    break;
  }

  /* End of MATLAB Function: '<S4>/RawData to StoreData' */
  /*  CellV_1_104(1) = uint16(1); */
  /*  SPIDataStore = uint16(zeros(1,21)); */
  /*  DataFault =  zeros(1,7); */
  /*  */
  /*  for i=1:7 */
  /*    SPIDataStore(i*3-2) = SPIData(i*8-7)+SPIData(i*8-6)*256; */
  /*    SPIDataStore(i*3-1) = SPIData(i*8-5)+SPIData(i*8-4)*256; */
  /*    SPIDataStore(i*3   ) = SPIData(i*8-3)+SPIData(i*8-2)*256; */
  /*    if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
  /*      DataFault(i) = 1; */
  /*    else */
  /*      DataFault(i) = 0; */
  /*    end */
  /*  end */
  /*  onemask8 = uint16(hex2dec('00FF')); */
  /*  onemask8_8sft = uint16(hex2dec('FF00')); */
  /*  onemask88 = uint8(hex2dec('FF')); */
  /*  onemask16 = uint16(hex2dec('FFFF')); */
  /*  */
  /*  % data_test = zeros(1,2); */
  /*  remainder = uint16(16); */
  /*  */
  /*  for i=1:len */
  /*      ii = uint16(i); */
  /*  %     data_test(1,i) = data(ii); */
  /*  %     address = 2; */
  /*      address = bitand( ... */
  /*          bitxor( ... */
  /*          uint8(bitsra(remainder,7)),data(ii) ), ... */
  /*          onemask88); */
  /*      remainder = bitxor(bitshift(remainder,8,'uint16'),pec15Table(address+1)); */
  /*  end */
  /*  pec15 = uint16(bitand(bitshift(remainder,1,'uint16'),onemask16)); */
  /*  pec0 = uint8(bitand(pec15,onemask8)); */
  /*  pec1 = uint8(bitsra(bitand(pec15,onemask8_8sft),8)); */
}

real_T rt_roundd(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* System reset for function-call system: '<Root>/DataDumpFast' */
void DataDumpFast_Reset(void)
{
  /* SystemReset for Chart: '<S2>/Chart1' */
  rtDWork.is_active_c48_can_simple_block_ = 0U;
  rtDWork.is_c48_can_simple_block_bu11143 = IN_NO_ACTIVE_CHILD_g;
  rtDWork.count = 0.0;
}

/* Output and update for function-call system: '<Root>/DataDumpFast' */
void DataDumpFast(void)
{
  uint64m_T VTDataCAN_64b;
  int32_T i;
  int32_T tmp;
  int32_T tmp_0;
  uint32_T tmp_1;
  uint64m_T tmp_2;
  int32_T tmp_3;
  int32_T tmp_4;
  uint96m_T tmp_5;
  uint96m_T tmp_6;
  uint64m_T tmp_7;
  uint96m_T tmp_8;
  uint96m_T tmp_9;
  uint64m_T tmp_a;
  uint96m_T tmp_b;
  uint96m_T tmp_c;
  uint64m_T tmp_d;
  uint96m_T tmp_e;
  uint96m_T tmp_f;
  uint96m_T tmp_g;
  uint64m_T tmp_h;
  uint64m_T tmp_i;
  uint64m_T tmp_j;
  uint64m_T tmp_k;
  uint96m_T tmp_l;
  uint64m_T tmp_m;
  uint96m_T tmp_n;
  uint96m_T tmp_o;
  uint96m_T tmp_p;
  uint64m_T tmp_q;
  static uint64m_T tmp_r = { { 3U, 0U }/* chunks */
  };

  static uint64m_T tmp_s = { { 255U, 0U }/* chunks */
  };

  /* Chart: '<S2>/Chart1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  /* Gateway: DataDumpFast/Chart1 */
  /* During: DataDumpFast/Chart1 */
  if (rtDWork.is_active_c48_can_simple_block_ == 0U) {
    /* Entry: DataDumpFast/Chart1 */
    rtDWork.is_active_c48_can_simple_block_ = 1U;

    /* Entry Internal: DataDumpFast/Chart1 */
    /* Transition: '<S12>:1' */
    rtDWork.count = 0.0;
    rtDWork.is_c48_can_simple_block_bu11143 = IN_A_f;

    /* Entry 'A': '<S12>:3' */
    rtDWork.count++;
  } else if (rtDWork.is_c48_can_simple_block_bu11143 == IN_A_f) {
    /* During 'A': '<S12>:3' */
    if (rtDWork.count >= 26.0) {
      /* Transition: '<S12>:7' */
      rtDWork.is_c48_can_simple_block_bu11143 = IN_A1_j;

      /* Entry 'A1': '<S12>:6' */
      rtDWork.count = 1.0;
    } else {
      rtDWork.count++;
    }
  } else {
    /* During 'A1': '<S12>:6' */
    /* Transition: '<S12>:8' */
    rtDWork.is_c48_can_simple_block_bu11143 = IN_A_f;

    /* Entry 'A': '<S12>:3' */
    rtDWork.count++;
  }

  /* End of Chart: '<S2>/Chart1' */

  /* MATLAB Function: '<S2>/RawData to StoreData' */
  /* MATLAB Function 'DataDumpFast/RawData to StoreData': '<S14>:1' */
  /* '<S14>:1:3' onemask8 = uint16(hex2dec('00FF')); */
  /* '<S14>:1:4' onemask8_8sft = uint16(hex2dec('FF00')); */
  /* '<S14>:1:5' onemask8_56sft = uint64(hex2dec('FF')); */
  /*  yl = uint8(bitand(u,onemask8)); */
  /*  yh = uint8(bitsra(bitand(u,onemask8_8sft),8)); */
  /*  bitshift(remainder,8)  shift left */
  /*  bitsra(remainder,8)  shift right */
  /* '<S14>:1:13' VTDataCAN_8b =  uint8(zeros(1,8)); */
  for (i = 0; i < 8; i++) {
    rtDWork.VTDataCAN_8b_a[i] = 0U;
  }

  /* '<S14>:1:14' VTDataCAN_64b =  uint64(zeros(1,1)); */
  /* '<S14>:1:15' VTDataCAN_4data =  uint8(zeros(1,4)); */
  /*  VTDataCAN_4data(1) = fix(CellV_1_104(StrCell*4-3)/4); */
  /*  VTDataCAN_4data(2) = fix(CellV_1_104(StrCell*4-2)/4); */
  /*  VTDataCAN_4data(3) = fix(CellV_1_104(StrCell*4-1)/4); */
  /*  VTDataCAN_4data(4) = fix(CellV_1_104(StrCell*4-0)/4); */
  /* '<S14>:1:22' Bid = StrCell; */
  /* '<S14>:1:23' VTDataCAN_64b = uint64( Bid ) + ... */
  /* '<S14>:1:24'                             uint64( bitshift(uint64(CellV_1_104(StrCell*4-3)/4),8 ) ) + ... */
  /* '<S14>:1:25'                             uint64( bitshift(uint64(CellV_1_104(StrCell*4-2)/4),8+14 ))  + ... */
  /* '<S14>:1:26'                             uint64( bitshift(uint64(CellV_1_104(StrCell*4-1)/4),8+14+14)  )  + ... */
  /* '<S14>:1:27'                             uint64( bitshift(uint64(CellV_1_104(StrCell*4-0)/4),8+14+14+14) ) ; */
  Double2MultiWord((int32_T)rt_roundd(rtDWork.count), &tmp_2.chunks[0U], 2);
  i = (int32_T)rt_roundd((real_T)rtDWork.CellV_1_104[(int32_T)(rtDWork.count *
    4.0 - 2.0) - 1] / 4.0);
  tmp_3 = (int32_T)rt_roundd((real_T)rtDWork.CellV_1_104[(int32_T)(rtDWork.count
    * 4.0 - 1.0) - 1] / 4.0);
  tmp_4 = (int32_T)rt_roundd((real_T)rtDWork.CellV_1_104[(int32_T)(rtDWork.count
    * 4.0) - 1] / 4.0);
  uMultiWord2MultiWord(&tmp_2.chunks[0U], 2, &tmp_f.chunks[0U], 3);
  uLong2MultiWord((uint16_T)(int32_T)rt_roundd((real_T)rtDWork.CellV_1_104
    [(int32_T)(rtDWork.count * 4.0 - 3.0) - 1] / 4.0), &tmp_i.chunks[0U], 2);
  uMultiWordShl(&tmp_i.chunks[0U], 2, 8U, &tmp_h.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_h.chunks[0U], 2, &tmp_g.chunks[0U], 3);
  MultiWordAdd(&tmp_f.chunks[0U], &tmp_g.chunks[0U], &tmp_e.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_e.chunks[0U], 3, &tmp_d.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_d.chunks[0U], 2, &tmp_c.chunks[0U], 3);
  uLong2MultiWord((uint16_T)i, &tmp_h.chunks[0U], 2);
  uMultiWordShl(&tmp_h.chunks[0U], 2, 22U, &tmp_d.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_d.chunks[0U], 2, &tmp_e.chunks[0U], 3);
  MultiWordAdd(&tmp_c.chunks[0U], &tmp_e.chunks[0U], &tmp_b.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_b.chunks[0U], 3, &tmp_a.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_a.chunks[0U], 2, &tmp_9.chunks[0U], 3);
  uLong2MultiWord((uint16_T)tmp_3, &tmp_d.chunks[0U], 2);
  uMultiWordShl(&tmp_d.chunks[0U], 2, 36U, &tmp_a.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_a.chunks[0U], 2, &tmp_b.chunks[0U], 3);
  MultiWordAdd(&tmp_9.chunks[0U], &tmp_b.chunks[0U], &tmp_8.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_8.chunks[0U], 3, &tmp_7.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_7.chunks[0U], 2, &tmp_6.chunks[0U], 3);
  uLong2MultiWord((uint16_T)tmp_4, &tmp_a.chunks[0U], 2);
  uMultiWordShl(&tmp_a.chunks[0U], 2, 50U, &tmp_7.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_7.chunks[0U], 2, &tmp_8.chunks[0U], 3);
  MultiWordAdd(&tmp_6.chunks[0U], &tmp_8.chunks[0U], &tmp_5.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_5.chunks[0U], 3, &VTDataCAN_64b.chunks[0U], 2);

  /* '<S14>:1:29' VTDataCAN_8b(1) = uint8( bitand(VTDataCAN_64b,onemask8_56sft) ); */
  tmp_a = tmp_s;
  MultiWordAnd(&VTDataCAN_64b.chunks[0U], &tmp_a.chunks[0U], &tmp_7.chunks[0U],
               2);
  tmp_1 = uMultiWord2uLongSat(&tmp_7.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b_a[0] = (uint8_T)tmp_1;

  /* '<S14>:1:30' VTDataCAN_8b(2) = uint8( bitand(bitsra(VTDataCAN_64b,8*1),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 8U, &tmp_d.chunks[0U], 2);
  tmp_h = tmp_s;
  MultiWordAnd(&tmp_d.chunks[0U], &tmp_h.chunks[0U], &tmp_a.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_a.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b_a[1] = (uint8_T)tmp_1;

  /* '<S14>:1:31' VTDataCAN_8b(3) = uint8( bitand(bitsra(VTDataCAN_64b,8*2),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 16U, &tmp_h.chunks[0U], 2);
  tmp_i = tmp_s;
  MultiWordAnd(&tmp_h.chunks[0U], &tmp_i.chunks[0U], &tmp_d.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_d.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b_a[2] = (uint8_T)tmp_1;

  /* '<S14>:1:32' VTDataCAN_8b(4) = uint8( bitand(bitsra(VTDataCAN_64b,8*3),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 24U, &tmp_i.chunks[0U], 2);
  tmp_2 = tmp_s;
  MultiWordAnd(&tmp_i.chunks[0U], &tmp_2.chunks[0U], &tmp_h.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_h.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b_a[3] = (uint8_T)tmp_1;

  /* '<S14>:1:33' VTDataCAN_8b(5) = uint8( bitand(bitsra(VTDataCAN_64b,8*4),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 32U, &tmp_2.chunks[0U], 2);
  tmp_h = tmp_s;
  MultiWordAnd(&tmp_2.chunks[0U], &tmp_h.chunks[0U], &tmp_i.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_i.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b_a[4] = (uint8_T)tmp_1;

  /* '<S14>:1:34' VTDataCAN_8b(6) = uint8( bitand(bitsra(VTDataCAN_64b,8*5),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 40U, &tmp_h.chunks[0U], 2);
  tmp_i = tmp_s;
  MultiWordAnd(&tmp_h.chunks[0U], &tmp_i.chunks[0U], &tmp_2.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_2.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b_a[5] = (uint8_T)tmp_1;

  /* '<S14>:1:35' VTDataCAN_8b(7) = uint8( bitand(bitsra(VTDataCAN_64b,8*6),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 48U, &tmp_i.chunks[0U], 2);
  tmp_2 = tmp_s;
  MultiWordAnd(&tmp_i.chunks[0U], &tmp_2.chunks[0U], &tmp_h.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_h.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b_a[6] = (uint8_T)tmp_1;

  /* '<S14>:1:36' VTDataCAN_8b(8) = uint8( bitand(bitsra(VTDataCAN_64b,8*7),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 56U, &tmp_2.chunks[0U], 2);
  tmp_h = tmp_s;
  MultiWordAnd(&tmp_2.chunks[0U], &tmp_h.chunks[0U], &tmp_i.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_i.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b_a[7] = (uint8_T)tmp_1;

  /* End of MATLAB Function: '<S2>/RawData to StoreData' */
  /*  VTDataCAN_8b(1) = Bid; */
  /*  VTDataCAN_8b(2) = VTDataCAN_4data(1)/(2^8); */
  /*  VTDataCAN_8b(3) = 4*fix(mod(CellV_1_104(StrCell*4-3),2^8)/4); */
  /*  VTDataCAN_8b(3) = VTDataCAN_8b(3) + CellV_1_104(StrCell*4-2)/(2^14); */
  /*  VTDataCAN_8b(4) = mod(CellV_1_104(StrCell*4-2),2^14) / (2^8); */
  /*  VTDataCAN_8b(5) =  * fix(mod(CellV_1_104(StrCell*4-2),2^6)); */
  /* '<S14>:1:45' 4*fix(CellV_1_104(StrCell*4-3)/4); */
  /*  VTDataCAN_8b(1) =         CellV_1_104(StrCell*4-3)/256; */
  /*  VTDataCAN_8b(2) = mod(CellV_1_104(StrCell*4-3),256); */
  /*  VTDataCAN_8b(3) =         CellV_1_104(StrCell*4-2)/256; */
  /*  VTDataCAN_8b(4) = mod(CellV_1_104(StrCell*4-2),256); */
  /*  VTDataCAN_8b(5) =         CellV_1_104(StrCell*4-1)/256; */
  /*  VTDataCAN_8b(6) = mod(CellV_1_104(StrCell*4-1),256); */
  /*  VTDataCAN_8b(7) =         CellV_1_104(StrCell*4   )/256; */
  /*  VTDataCAN_8b(8) = mod(CellV_1_104(StrCell*4   ),256); */
  /*  VTDataCAN_8b(1) =         CellV_1_104(1)/256; */
  /*  VTDataCAN_8b(2) = mod(CellV_1_104(1),256); */
  /*  VTDataCAN_8b(3) =         CellV_1_104(2)/256; */
  /*  VTDataCAN_8b(4) = mod(CellV_1_104(2),256); */
  /*  VTDataCAN_8b(5) =         CellV_1_104(9)/256; */
  /*  VTDataCAN_8b(6) = mod(CellV_1_104(9),256); */
  /*  VTDataCAN_8b(7) =         CellV_1_104(10)/256; */
  /*  VTDataCAN_8b(8) = mod(CellV_1_104(10),256); */
  /*  VTDataCAN_8b(1) =         uint16(30000)/256; */
  /*  VTDataCAN_8b(2) = mod(uint16(30000),256); */
  /*  VTDataCAN_8b(3) =         uint16(35000)/256; */
  /*  VTDataCAN_8b(4) = mod(uint16(35000),256); */
  /*  VTDataCAN_8b(5) =         uint16(33000)/256; */
  /*  VTDataCAN_8b(6) = mod(uint16(33000),256); */
  /*  VTDataCAN_8b(7) =         uint16(20000)/256; */
  /*  VTDataCAN_8b(8) = mod(uint16(20000),256); */
  /*  CellV_1_104(1) = uint16(1); */
  /*  SPIDataStore = uint16(zeros(1,21)); */
  /*  DataFault =  zeros(1,7); */
  /*  */
  /*  for i=1:7 */
  /*    SPIDataStore(i*3-2) = SPIData(i*8-7)+SPIData(i*8-6)*256; */
  /*    SPIDataStore(i*3-1) = SPIData(i*8-5)+SPIData(i*8-4)*256; */
  /*    SPIDataStore(i*3   ) = SPIData(i*8-3)+SPIData(i*8-2)*256; */
  /*    if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
  /*      DataFault(i) = 1; */
  /*    else */
  /*      DataFault(i) = 0; */
  /*    end */
  /*  end */
  /*  onemask8 = uint16(hex2dec('00FF')); */
  /*  onemask8_8sft = uint16(hex2dec('FF00')); */
  /*  onemask88 = uint8(hex2dec('FF')); */
  /*  onemask16 = uint16(hex2dec('FFFF')); */
  /*  */
  /*  % data_test = zeros(1,2); */
  /*  remainder = uint16(16); */
  /*  */
  /*  for i=1:len */
  /*      ii = uint16(i); */
  /*  %     data_test(1,i) = data(ii); */
  /*  %     address = 2; */
  /*      address = bitand( ... */
  /*          bitxor( ... */
  /*          uint8(bitsra(remainder,7)),data(ii) ), ... */
  /*          onemask88); */
  /*      remainder = bitxor(bitshift(remainder,8,'uint16'),pec15Table(address+1)); */
  /*  end */
  /*  pec15 = uint16(bitand(bitshift(remainder,1,'uint16'),onemask16)); */
  /*  pec0 = uint8(bitand(pec15,onemask8)); */
  /*  pec1 = uint8(bitsra(bitand(pec15,onemask8_8sft),8)); */

  /* S-Function (can_564xl_transmit): '<S2>/CAN Transmit1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    uint8_t* data = &rtDWork.VTDataCAN_8b_a[0];
    uint8_t datalen = ((uint8_T)8U);
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    ptr_FLEXCAN_MsgBufferStructure->length = datalen;
    if (522&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 522;
    for (i=0;i<datalen;i++) {
      ptr_FLEXCAN_MsgBufferStructure->data[i] = *(data++);
    }

    ptr_FLEXCAN_MsgBufferStructure->code = CAN_TX_MSG;
    flexcan_564xl_buffer_transmit(ptr_FLEXCAN_MsgBufferStructure,26,0);
    flexcan_564xl_release_mb_lock(0);
    flexcan_564xl_clear_mask(0, 26);
  }

  /* MATLAB Function: '<S2>/RawData to StoreData1' incorporates:
   *  Constant: '<S2>/Constant4'
   */
  /*  global CellV_1_104; */
  /* MATLAB Function 'DataDumpFast/RawData to StoreData1': '<S15>:1' */
  /* '<S15>:1:5' VTDataCAN_8b =  uint8(zeros(1,8)); */
  /*   */
  /*  StrCell_2 = fix((StrCell+1)/2); */
  /*   */
  /*  if mod(StrCell,2)==1 */
  /*  VTDataCAN_8b(1) =         CellGP_1_78(StrCell_2*6-5)/256; */
  /*  VTDataCAN_8b(2) = mod(CellGP_1_78(StrCell_2*6-5),256); */
  /*  VTDataCAN_8b(3) =         CellGP_1_78(StrCell_2*6-4)/256; */
  /*  VTDataCAN_8b(4) = mod(CellGP_1_78(StrCell_2*6-4),256); */
  /*  VTDataCAN_8b(5) =         CellGP_1_78(StrCell_2*6-3)/256; */
  /*  VTDataCAN_8b(6) = mod(CellGP_1_78(StrCell_2*6-3),256); */
  /*  VTDataCAN_8b(7) =         CellGP_1_78(StrCell_2*6-2 )/256; */
  /*  VTDataCAN_8b(8) = mod(CellGP_1_78(StrCell_2*6-2),256); */
  /*  else  */
  /*  VTDataCAN_8b(1) =         CellGP_1_78(StrCell_2*6-1 )/256; */
  /*  VTDataCAN_8b(2) = mod(CellGP_1_78(StrCell_2*6-1 ),256); */
  /*  VTDataCAN_8b(3) =         CellGP_1_78(StrCell_2*6-0 )/256; */
  /*  VTDataCAN_8b(4) = mod(CellGP_1_78(StrCell_2*6-0 ),256); */
  /*  end */
  /* '<S15>:1:24' onemask8 = uint16(hex2dec('00FF')); */
  /* '<S15>:1:25' onemask8_8sft = uint16(hex2dec('FF00')); */
  /* '<S15>:1:26' onemask8_56sft = uint64(hex2dec('FF')); */
  /* '<S15>:1:27' VTDataCAN_8b =  uint8(zeros(1,8)); */
  for (i = 0; i < 8; i++) {
    rtDWork.VTDataCAN_8b[i] = 0U;
  }

  /* '<S15>:1:28' VTDataCAN_64b =  uint64(zeros(1,1)); */
  /* '<S15>:1:29' VTDataCAN_4data =  uint8(zeros(1,4)); */
  /* '<S15>:1:31' Bid = StrCell; */
  /* '<S15>:1:32' VTDataCAN_64b = uint64( Bid ) + ... */
  /* '<S15>:1:33'                             uint64( bitshift(uint64(CellGP_1_78(StrCell*6-5)/64),8 ) ) + ... */
  /* '<S15>:1:34'                             uint64( bitshift(uint64(CellGP_1_78(StrCell*6-4)/64),8+10*1 ) )  + ... */
  /* '<S15>:1:35'                             uint64( bitshift(uint64(CellGP_1_78(StrCell*6-3)/64),8+10*2 ) )  + ... */
  /* '<S15>:1:36'                             uint64( bitshift(uint64(CellGP_1_78(StrCell*6-2)/64),8+10*3 ) ) + ... */
  /* '<S15>:1:37'                             uint64( bitshift(uint64(CellGP_1_78(StrCell*6-1)/64),8+10*4 ) ) + ... */
  /* '<S15>:1:38'                             uint64( bitshift(uint64(CellGP_1_78(StrCell*6-0)/1024),8+10*5 ) ) ; */
  i = (int32_T)rt_roundd((real_T)rtDWork.CellGP_1_78[13] / 64.0);
  tmp_3 = (int32_T)rt_roundd((real_T)rtDWork.CellGP_1_78[14] / 64.0);
  tmp_4 = (int32_T)rt_roundd((real_T)rtDWork.CellGP_1_78[15] / 64.0);
  tmp = (int32_T)rt_roundd((real_T)rtDWork.CellGP_1_78[16] / 64.0);
  tmp_0 = (int32_T)rt_roundd((real_T)rtDWork.CellGP_1_78[17] / 1024.0);
  tmp_i = tmp_r;
  uMultiWord2MultiWord(&tmp_i.chunks[0U], 2, &tmp_o.chunks[0U], 3);
  uLong2MultiWord((uint16_T)(int32_T)rt_roundd((real_T)rtDWork.CellGP_1_78[12] /
    64.0), &tmp_q.chunks[0U], 2);
  uMultiWordShl(&tmp_q.chunks[0U], 2, 8U, &tmp_i.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_i.chunks[0U], 2, &tmp_p.chunks[0U], 3);
  MultiWordAdd(&tmp_o.chunks[0U], &tmp_p.chunks[0U], &tmp_n.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_n.chunks[0U], 3, &tmp_m.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_m.chunks[0U], 2, &tmp_l.chunks[0U], 3);
  uLong2MultiWord((uint16_T)i, &tmp_i.chunks[0U], 2);
  uMultiWordShl(&tmp_i.chunks[0U], 2, 18U, &tmp_m.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_m.chunks[0U], 2, &tmp_n.chunks[0U], 3);
  MultiWordAdd(&tmp_l.chunks[0U], &tmp_n.chunks[0U], &tmp_g.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_g.chunks[0U], 3, &tmp_k.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_k.chunks[0U], 2, &tmp_f.chunks[0U], 3);
  uLong2MultiWord((uint16_T)tmp_3, &tmp_m.chunks[0U], 2);
  uMultiWordShl(&tmp_m.chunks[0U], 2, 28U, &tmp_k.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_k.chunks[0U], 2, &tmp_g.chunks[0U], 3);
  MultiWordAdd(&tmp_f.chunks[0U], &tmp_g.chunks[0U], &tmp_e.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_e.chunks[0U], 3, &tmp_j.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_j.chunks[0U], 2, &tmp_c.chunks[0U], 3);
  uLong2MultiWord((uint16_T)tmp_4, &tmp_k.chunks[0U], 2);
  uMultiWordShl(&tmp_k.chunks[0U], 2, 38U, &tmp_j.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_j.chunks[0U], 2, &tmp_e.chunks[0U], 3);
  MultiWordAdd(&tmp_c.chunks[0U], &tmp_e.chunks[0U], &tmp_b.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_b.chunks[0U], 3, &tmp_h.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_h.chunks[0U], 2, &tmp_9.chunks[0U], 3);
  uLong2MultiWord((uint16_T)tmp, &tmp_j.chunks[0U], 2);
  uMultiWordShl(&tmp_j.chunks[0U], 2, 48U, &tmp_h.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_h.chunks[0U], 2, &tmp_b.chunks[0U], 3);
  MultiWordAdd(&tmp_9.chunks[0U], &tmp_b.chunks[0U], &tmp_8.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_8.chunks[0U], 3, &tmp_2.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_2.chunks[0U], 2, &tmp_6.chunks[0U], 3);
  uLong2MultiWord((uint16_T)tmp_0, &tmp_h.chunks[0U], 2);
  uMultiWordShl(&tmp_h.chunks[0U], 2, 58U, &tmp_2.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_2.chunks[0U], 2, &tmp_8.chunks[0U], 3);
  MultiWordAdd(&tmp_6.chunks[0U], &tmp_8.chunks[0U], &tmp_5.chunks[0U], 3);
  uMultiWord2uMultiWordSat(&tmp_5.chunks[0U], 3, &VTDataCAN_64b.chunks[0U], 2);

  /* '<S15>:1:40' VTDataCAN_8b(1) = uint8( bitand(VTDataCAN_64b,onemask8_56sft) ); */
  tmp_h = tmp_s;
  MultiWordAnd(&VTDataCAN_64b.chunks[0U], &tmp_h.chunks[0U], &tmp_2.chunks[0U],
               2);
  tmp_1 = uMultiWord2uLongSat(&tmp_2.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b[0] = (uint8_T)tmp_1;

  /* '<S15>:1:41' VTDataCAN_8b(2) = uint8( bitand(bitsra(VTDataCAN_64b,8*1),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 8U, &tmp_j.chunks[0U], 2);
  tmp_k = tmp_s;
  MultiWordAnd(&tmp_j.chunks[0U], &tmp_k.chunks[0U], &tmp_h.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_h.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b[1] = (uint8_T)tmp_1;

  /* '<S15>:1:42' VTDataCAN_8b(3) = uint8( bitand(bitsra(VTDataCAN_64b,8*2),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 16U, &tmp_k.chunks[0U], 2);
  tmp_m = tmp_s;
  MultiWordAnd(&tmp_k.chunks[0U], &tmp_m.chunks[0U], &tmp_j.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_j.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b[2] = (uint8_T)tmp_1;

  /* '<S15>:1:43' VTDataCAN_8b(4) = uint8( bitand(bitsra(VTDataCAN_64b,8*3),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 24U, &tmp_m.chunks[0U], 2);
  tmp_i = tmp_s;
  MultiWordAnd(&tmp_m.chunks[0U], &tmp_i.chunks[0U], &tmp_k.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_k.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b[3] = (uint8_T)tmp_1;

  /* '<S15>:1:44' VTDataCAN_8b(5) = uint8( bitand(bitsra(VTDataCAN_64b,8*4),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 32U, &tmp_i.chunks[0U], 2);
  tmp_q = tmp_s;
  MultiWordAnd(&tmp_i.chunks[0U], &tmp_q.chunks[0U], &tmp_m.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_m.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b[4] = (uint8_T)tmp_1;

  /* '<S15>:1:45' VTDataCAN_8b(6) = uint8( bitand(bitsra(VTDataCAN_64b,8*5),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 40U, &tmp_q.chunks[0U], 2);
  tmp_2 = tmp_s;
  MultiWordAnd(&tmp_q.chunks[0U], &tmp_2.chunks[0U], &tmp_i.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_i.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b[5] = (uint8_T)tmp_1;

  /* '<S15>:1:46' VTDataCAN_8b(7) = uint8( bitand(bitsra(VTDataCAN_64b,8*6),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 48U, &tmp_2.chunks[0U], 2);
  tmp_i = tmp_s;
  MultiWordAnd(&tmp_2.chunks[0U], &tmp_i.chunks[0U], &tmp_q.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_q.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b[6] = (uint8_T)tmp_1;

  /* '<S15>:1:47' VTDataCAN_8b(8) = uint8( bitand(bitsra(VTDataCAN_64b,8*7),onemask8_56sft) ); */
  uMultiWordShr(&VTDataCAN_64b.chunks[0U], 2, 56U, &tmp_i.chunks[0U], 2);
  tmp_h = tmp_s;
  MultiWordAnd(&tmp_i.chunks[0U], &tmp_h.chunks[0U], &tmp_2.chunks[0U], 2);
  tmp_1 = uMultiWord2uLongSat(&tmp_2.chunks[0U], 2);
  if (tmp_1 > 255U) {
    tmp_1 = 255U;
  }

  rtDWork.VTDataCAN_8b[7] = (uint8_T)tmp_1;

  /* End of MATLAB Function: '<S2>/RawData to StoreData1' */
  /*  VTDataCAN_8b(1) =         CellV_1_104(1)/256; */
  /*  VTDataCAN_8b(2) = mod(CellV_1_104(1),256); */
  /*  VTDataCAN_8b(3) =         CellV_1_104(2)/256; */
  /*  VTDataCAN_8b(4) = mod(CellV_1_104(2),256); */
  /*  VTDataCAN_8b(5) =         CellV_1_104(9)/256; */
  /*  VTDataCAN_8b(6) = mod(CellV_1_104(9),256); */
  /*  VTDataCAN_8b(7) =         CellV_1_104(10)/256; */
  /*  VTDataCAN_8b(8) = mod(CellV_1_104(10),256); */
  /*  VTDataCAN_8b(1) =         uint16(30000)/256; */
  /*  VTDataCAN_8b(2) = mod(uint16(30000),256); */
  /*  VTDataCAN_8b(3) =         uint16(35000)/256; */
  /*  VTDataCAN_8b(4) = mod(uint16(35000),256); */
  /*  VTDataCAN_8b(5) =         uint16(33000)/256; */
  /*  VTDataCAN_8b(6) = mod(uint16(33000),256); */
  /*  VTDataCAN_8b(7) =         uint16(20000)/256; */
  /*  VTDataCAN_8b(8) = mod(uint16(20000),256); */
  /*  CellV_1_104(1) = uint16(1); */
  /*  SPIDataStore = uint16(zeros(1,21)); */
  /*  DataFault =  zeros(1,7); */
  /*  */
  /*  for i=1:7 */
  /*    SPIDataStore(i*3-2) = SPIData(i*8-7)+SPIData(i*8-6)*256; */
  /*    SPIDataStore(i*3-1) = SPIData(i*8-5)+SPIData(i*8-4)*256; */
  /*    SPIDataStore(i*3   ) = SPIData(i*8-3)+SPIData(i*8-2)*256; */
  /*    if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
  /*      DataFault(i) = 1; */
  /*    else */
  /*      DataFault(i) = 0; */
  /*    end */
  /*  end */
  /*  onemask8 = uint16(hex2dec('00FF')); */
  /*  onemask8_8sft = uint16(hex2dec('FF00')); */
  /*  onemask88 = uint8(hex2dec('FF')); */
  /*  onemask16 = uint16(hex2dec('FFFF')); */
  /*  */
  /*  % data_test = zeros(1,2); */
  /*  remainder = uint16(16); */
  /*  */
  /*  for i=1:len */
  /*      ii = uint16(i); */
  /*  %     data_test(1,i) = data(ii); */
  /*  %     address = 2; */
  /*      address = bitand( ... */
  /*          bitxor( ... */
  /*          uint8(bitsra(remainder,7)),data(ii) ), ... */
  /*          onemask88); */
  /*      remainder = bitxor(bitshift(remainder,8,'uint16'),pec15Table(address+1)); */
  /*  end */
  /*  pec15 = uint16(bitand(bitshift(remainder,1,'uint16'),onemask16)); */
  /*  pec0 = uint8(bitand(pec15,onemask8)); */
  /*  pec1 = uint8(bitsra(bitand(pec15,onemask8_8sft),8)); */

  /* S-Function (can_564xl_transmit): '<S2>/CAN Transmit2' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    uint8_t* data = &rtDWork.VTDataCAN_8b[0];
    uint8_t datalen = ((uint8_T)8U);
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    ptr_FLEXCAN_MsgBufferStructure->length = datalen;
    if (523&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 523;
    for (i=0;i<datalen;i++) {
      ptr_FLEXCAN_MsgBufferStructure->data[i] = *(data++);
    }

    ptr_FLEXCAN_MsgBufferStructure->code = CAN_TX_MSG;
    flexcan_564xl_buffer_transmit(ptr_FLEXCAN_MsgBufferStructure,27,0);
    flexcan_564xl_release_mb_lock(0);
    flexcan_564xl_clear_mask(0, 27);
  }
}

/* Model step function */
void can_simple_block_bu11143_step(void)
{
  /* S-Function (can_564xl_receive_data): '<Root>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 7)) {
      rtY.Out3 = flexcan_564xl_get_id(0, 7);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 7);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&rtY.Out1[0])[i] = ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      rtY.Out2 = flexcan_564xl_get_idtype(0, 7);
      rtY.Out4 = flexcan_564xl_get_ts(0, 7);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 7);
    }
  }

  /* Outport: '<Root>/Out5' */
  rtY.Out5 = rtDWork.In3[0];
}

/* Model initialize function */
void can_simple_block_bu11143_initialize(void)
{
  /* Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' incorporates:
   *  Start for SubSystem: '<Root>/Subsystem2'
   */
  Subsystem2_Start();

  /* End of Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' */

  /* Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' */
  {
    uint32_t flag = 0U;
    flag |= DSPI_ISR_EOQF_RE;
    dspi_564xl_interrupt_set(1, flag);
  }

  /* Start for S-Function (can_564xl_config): '<Root>/CAN Config' */
  flexcan_564xl_init( 0, 1342177343, 81461382);
  flexcan_564xl_pin_init( 0);

  /* Start for S-Function (dspi_564xl_config): '<Root>/DSPI Config' */
  dspi_564xl_config( 1, -2130759679, 1053390630);

  /* Start for S-Function (dspi_564xl_config): '<Root>/DSPI Config1' */
  dspi_564xl_config( 0, -2130759679, 1053390630);

  /* Start for S-Function (can_564xl_receive_data): '<Root>/CAN_Receive_data1' */
  {
    if ((1010U & 0x1FFFF800) != 0x0) { //extended tag
      flexcan_564xl_set_filter_id(0, 7, 1010U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 7, 1010U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data_trigger): '<Root>/CAN Receive Data Trigger1' */
  flexcan_564xl_set_filter_id(0, 5, 1021, 0);
  CAN_0.IMASK1.R |= 1<<5;

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' incorporates:
   *  Start for SubSystem: '<Root>/Function-Call Subsystem'
   */
  FunctionCallSubsystem_Start();

  /* End of Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' */

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' */
  pit_timer_init_564xl(1,5999999);

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer1' */
  pit_timer_init_564xl(2,1199999);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  rtDWork.V_REF_AUX = 3U;

  /* ConstCode for Outport: '<Root>/Out7' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtY.Out7 = 8U;

  /* SystemInitialize for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Subsystem2'
   */
  Subsystem2_Init();

  /* End of SystemInitialize for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' */

  /* SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Function-Call Subsystem'
   */
  FunctionCallSubsystem_Init();

  /* End of SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' */
}

/* Model terminate function */
void can_simple_block_bu11143_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
