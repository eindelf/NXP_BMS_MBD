/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: sysclk.h
 *
 * Code generated for Simulink model 'can_simple_block_bu11142'.
 *
 * Model version                  : 1.1257
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Jan 02 13:58:39 2018
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sysclk_h_
#define RTW_HEADER_sysclk_h_

/*                                    Parameters for 40Mhz XTAL 120Mhz Clk   */
#define IDF_0                          4 - 1                     /* Input Division Factor: 4   */
#define ODF_0                          1                         /* Output Division Factor: 4   */
#define NDIV_0                         48                        /* Loop Division Factor: 48    */

/* XTAL_40MHz / 4 / 4 * 48 = 120MHz  */
#define IDF_1                          4 - 1                     /* Input Division Factor: 4   */
#define ODF_1                          1                         /* Output Division Factor: 4   */
#define NDIV_1                         48                        /* Loop Division Factor: 48    */

/* XTAL_40MHz / 4 / 4 * 48 = 120MHz  */
#define MC_DIV                         11                        /* Motor Control Clock Divider Value: (11 + 1), Frequency 10000000 Hz */
#define SW_DIV                         5                         /* Sinewave Generator Clock Divider Value: (5 + 1), Frequency 20000000 Hz */
#define MC_CLOCK                       10000000                  /* Motor Control Clock */
#define SWG_CLOCK                      20000000                  /* Sinewave Generator Clock */
#endif                                 /* RTW_HEADER_sysclk_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
