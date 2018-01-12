/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: linflex_siu_init.c
 *
 * Code generated for Simulink model 'dspi_block'.
 *
 * Model version                  : 1.103
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Dec 21 14:43:43 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/********************  Dependent Include files here **********************/
#include "target.h"

/**********************  Initialization Function(s) *************************/
void linflex_siu_init(void)
{
  /* ----------------------------------------------------------------------- */

  /*      Pad Configuration Register PCR[18]  LIN_TXD */

  /* ----------------------------------------------------------------------- */
  SIU.PCR[18].R = 0x400;

  /*	Selected Function : LIN_TXD_0        */

  /*	Output Buffers : Enabled          */

  /*	Input Buffers : Disabled          */

  /*	Output Drain : Disabled           */

  /*	Slew Rate Control : Minimum       */

  /*	Weak Pull Up/Down : Disabled      */

  /*	Weak Pull Up/Down Select : Down   */

  /* ----------------------------------------------------------- */

  /*      Pad Configuration Register PCR[19]  LIN_RXD */

  /* ----------------------------------------------------------- */
  SIU.PCR[19].R = 0x0100;

  /*	Selected Function : PB[3] I        */

  /*	Output Buffers : Disabled         */

  /*	Input Buffers : Enabled           */

  /*	Output Drain : Disabled           */

  /*	Slew Rate Control : Minimum       */

  /*	Weak Pull Up/Down : Disabled      */

  /*	Weak Pull Up/Down Select : Down   */
  SIU.PSMI[31].B.PADSEL = 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
