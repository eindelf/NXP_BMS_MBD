/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: intc_init.c
 *
 * Code generated for Simulink model 'can_simple_block'.
 *
 * Model version                  : 1.83
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Wed Oct 11 15:09:29 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/********************  Dependent Include files here **********************/
#include "rappid_ref.h"
#include "intc_init.h"

extern uint32_t IntcIsrVectorTable [];

/*********************  Initialization Function(s) ************************/
void intc_init_fnc (void)
{
  e200zX_Interrupt_Setup();
  INTC.MCR.B.HVEN_PRC0 = 0;            /* Initialize INTC for software vector mode */
  INTC.MCR.B.VTES_PRC0 = 0;            /* Use default vector table entry offsets of 4 B */
  INTC.IACKR.R = (uint32_t) &ISRVectorTable[0];/* Set INTC ISR vector table base address */
  INTC.PSR[79].R = 14;                 /* LIN_0 Rx for PIL */
  INTC.PSR[59].R = 0x0C;
  INTC.PSR[60].R = 0x00;
  INTC.PSR[61].R = 0x00;
  INTC.PSR[127].R = 0x00;
  INTC.PSR[62].R = 0x00;
  INTC.PSR[64].R = 0x00;
  INTC.PSR[82].R = 0x00;
  INTC.PSR[84].R = 0x00;
  INTC.PSR[78].R = 0x00;
  INTC.PSR[98].R = 0x00;
  INTC.PSR[118].R = 0x00;
  INTC.PSR[74].R = 0x00;
  INTC.PSR[75].R = 0x00;
  INTC.PSR[76].R = 0x00;
  INTC.PSR[77].R = 0x00;
  INTC.PSR[94].R = 0x00;
  INTC.PSR[95].R = 0x00;
  INTC.PSR[96].R = 0x00;
  INTC.PSR[97].R = 0x00;
  INTC.PSR[114].R = 0x00;
  INTC.PSR[115].R = 0x00;
  INTC.PSR[116].R = 0x00;
  INTC.PSR[117].R = 0x00;
  INTC.PSR[65].R = 0x00;
  INTC.PSR[85].R = 0x00;
  INTC.PSR[66].R = 0x00;
  INTC.PSR[86].R = 0x00;
  INTC.PSR[68].R = 0x00;
  INTC.PSR[69].R = 0x0E;
  INTC.PSR[70].R = 0x00;
  INTC.PSR[71].R = 0x00;
  INTC.PSR[72].R = 0x00;
  INTC.PSR[88].R = 0x00;
  INTC.PSR[89].R = 0x00;
  INTC.PSR[90].R = 0x00;
  INTC.PSR[91].R = 0x00;
  INTC.PSR[92].R = 0x00;
  INTC.PSR[157].R = 0x00;
  INTC.PSR[158].R = 0x00;
  INTC.PSR[159].R = 0x00;
  INTC.PSR[160].R = 0x00;
  INTC.PSR[161].R = 0x00;
  INTC.PSR[162].R = 0x00;
  INTC.PSR[168].R = 0x00;
  INTC.PSR[169].R = 0x00;
  INTC.PSR[170].R = 0x00;
  INTC.PSR[171].R = 0x00;
  INTC.PSR[172].R = 0x00;
  INTC.PSR[173].R = 0x00;
  INTC.PSR[222].R = 0x00;
  INTC.PSR[223].R = 0x00;
  INTC.PSR[224].R = 0x00;
  INTC.PSR[225].R = 0x00;
  INTC.PSR[226].R = 0x00;
  INTC.PSR[227].R = 0x00;
  INTC.PSR[180].R = 0x00;
  INTC.PSR[179].R = 0x00;
  INTC.PSR[183].R = 0x00;
  INTC.PSR[182].R = 0x00;
  INTC.PSR[186].R = 0x00;
  INTC.PSR[185].R = 0x00;
  INTC.PSR[189].R = 0x00;
  INTC.PSR[188].R = 0x00;
  INTC.PSR[192].R = 0x00;
  INTC.PSR[193].R = 0x00;
  INTC.PSR[194].R = 0x00;
  INTC.PSR[195].R = 0x00;
  INTC.PSR[196].R = 0x00;
  INTC.PSR[197].R = 0x00;
  INTC.PSR[198].R = 0x00;
  INTC.PSR[199].R = 0x00;
  INTC.PSR[200].R = 0x00;
  INTC.PSR[201].R = 0x00;
  INTC.PSR[206].R = 0x00;
  INTC.PSR[207].R = 0x00;
  INTC.PSR[234].R = 0x00;
  INTC.PSR[233].R = 0x00;
  INTC.PSR[237].R = 0x00;
  INTC.PSR[236].R = 0x00;
  INTC.PSR[240].R = 0x00;
  INTC.PSR[239].R = 0x00;
  INTC.PSR[243].R = 0x00;
  INTC.PSR[242].R = 0x00;
  INTC.PSR[246].R = 0x00;
}

/*

 *######################################################################

 *                           End of File

 *######################################################################

 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
