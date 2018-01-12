/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    FlexPWM_564xL_library.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   FlexPWM  library file for 564xL.
*    @details FlexPWM library file for 564xL.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		7-May-2011
*   Author:                         B13508
* 
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/
#include "FlexPWM_564xL_library.h"

/******************************************************************************
*                  Static variables
******************************************************************************/

static uint32_t sysClk = MC_CLOCK;     /* Motor Control Input clock 10MHz: System PLL 120MHz divided by 12 */

static volatile mcPWM_tag* FlexPWM_module[2] = { &FLEXPWM_0, &FLEXPWM_1 };

/******************************************************************************
*                  Local functions prototype
******************************************************************************/

static uint16_t pwm_prescaler (uint32_t Freq, uint32_t* period);

/******************************************************************************
*                  Local functions
******************************************************************************/

/******************************************************************************
*   Function:  pwm_prescaler
@brief    calculate prescaler . 
@details  calculate prescaler
    
@param[in]     Freq   - 
@param[in]     period      -  

@return  prescaler value
*/
static uint16_t pwm_prescaler (uint32_t Freq, uint32_t* period)
{
  uint8_t presDiv;
  uint8_t mask = 1U;

  for (presDiv = 0U; presDiv < 8U; presDiv++) {
    *period = (sysClk / mask) / Freq;
    if (*period <= 0xFFFF) {
      break;
    }

    mask = mask << 1U;
  }

  return (((uint16_t)presDiv)  << 4);
}


/******************************************************************************
*                   Global functions
******************************************************************************/

/******************************************************************************
*   Function:  pwm_init_pcr_out_564xL
@brief    FlexPWM Channel Pin Configuration Setup . 
@details  FlexPWM Channel Pin Configuration Setup
    
@param[in]     subMod   - 
@param[in]     outAB      -  
@param[in]     pcrNum      -
  
@return none
*/

void pwm_init_pcr_out_564xL(uint8_t pwmMod, uint8_t subMod, uint8_t outAB, uint8_t pcrNum)
{
    /* Output Buffers : Enabled          */
    /* Input Buffers : Disabled          */
    /* Output Drain : Disabled           */
    /* Slew Rate Control : Minimum       */
    /* Weak Pull Up/Down : Disabled      */
    /* Weak Pull Up/Down Select : Down   */
	
  if (pwmMod == 0) {
	if (subMod == 0) {
		if (outAB == 0) {					/* FlexPWM_0 A[0] */ 
			if (pcrNum == 11) {						/* PCR[10] A[11]  */
				SIU.PCR[11].R = 0x0800;						/* ALT[2] */
				SIU.PSMI[20].B.PADSEL = 0;
			} else if (pcrNum == 58) {				/* PCR[58] D[10]  */
				SIU.PCR[58].R = 0x0400;						/* ALT[1] */
				SIU.PSMI[20].B.PADSEL = 1;
			}
		} else if (outAB == 1) { 			/* FlexPWM_0 B[0] */
			if (pcrNum == 10) {						/* PCR[10] A[10]  */
				SIU.PCR[10].R = 0x0800;						/* ALT[2] */
				SIU.PSMI[24].B.PADSEL = 0;
			} else if (pcrNum == 59) {				/* PCR[59] D[11]  */
				SIU.PCR[59].R = 0x0400;						/* ALT[1] */
				SIU.PSMI[24].B.PADSEL = 1;
			}
		} else {							/* FlexPWM_0 X[0] */
			if (pcrNum == 57) {						/* PCR[57] D[9]   */
				SIU.PCR[57].R = 0x0400;						/* ALT[1] */
			}
		}
	} else if (subMod == 1) {
		if (outAB == 0) {					/* FlexPWM_0 A[1] */ 
			if (pcrNum == 39) {						/* PCR[39] C[7]   */
				SIU.PCR[39].R = 0x0800;						/* ALT[2] */
				SIU.PSMI[21].B.PADSEL = 0;
			} else if (pcrNum == 47) {				/* PCR[47] C[15]  */
				SIU.PCR[47].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[21].B.PADSEL = 1;
			} else if (pcrNum == 80) {				/* PCR[80] F[0]   */
				SIU.PCR[80].R = 0x0400;						/* ALT[1] */
				SIU.PSMI[21].B.PADSEL = 2;
			}
		} else if (outAB == 1) { 			/* FlexPWM_0 B[1] */
			if (pcrNum == 38) {						/* PCR[38] C[6]   */
				SIU.PCR[38].R = 0x0800;						/* ALT[2] */
				SIU.PSMI[25].B.PADSEL = 0;
			} else if (pcrNum == 48) {				/* PCR[48] D[0]   */
				SIU.PCR[48].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[25].B.PADSEL = 1;
			} else if (pcrNum == 62) {				/* PCR[62] D[14]  */
				SIU.PCR[62].R = 0x0400;						/* ALT[1] */
				SIU.PSMI[25].B.PADSEL = 2;
			}
		} else {							/* FlexPWM_0 X[1] */
			if (pcrNum == 36) {						/* PCR[36] C[4]   */
				SIU.PCR[36].R = 0x0800;						/* ALT[2] */
				SIU.PSMI[28].B.PADSEL = 0;
			} else if (pcrNum == 60) {				/* PCR[60] D[12]  */
				SIU.PCR[60].R = 0x0400;						/* ALT[1] */
				SIU.PSMI[28].B.PADSEL = 1;
			}
		}
	} else if (subMod == 2) {
		if (outAB == 0) {					/* FlexPWM_0 A[2] */ 
			if (pcrNum == 11) {						/* PCR[11] A[11]  */
				SIU.PCR[11].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[22].B.PADSEL = 0;
			} else if (pcrNum == 12) {				/* PCR[12] A[12]  */
				SIU.PCR[12].R = 0x0800;						/* ALT[2] */
				SIU.PSMI[22].B.PADSEL = 1;
			} else if (pcrNum == 99) {				/* PCR[99] G[3]   */
				SIU.PCR[99].R = 0x0400;						/* ALT[1] */
				SIU.PSMI[22].B.PADSEL = 2;
			}
		} else if (outAB == 1) { 			/* FlexPWM_0 B[2] */
			if (pcrNum == 12) {						/* PCR[12] A[12]  */
				SIU.PCR[12].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[26].B.PADSEL = 0;
			} else if (pcrNum == 13) {				/* PCR[13] A[13]  */
				SIU.PCR[13].R = 0x0800;						/* ALT[2] */
				SIU.PSMI[26].B.PADSEL = 1;
			} else if (pcrNum == 100) {				/* PCR[100] G[4]  */
				SIU.PCR[100].R = 0x0400;					/* ALT[1] */
				SIU.PSMI[26].B.PADSEL = 2;
			}
		} else {							/* FlexPWM_0 X[2] */
			if (pcrNum == 10) {						/* PCR[10] A[10]  */
				SIU.PCR[10].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[29].B.PADSEL = 0;
			} else if (pcrNum == 98) {				/* PCR[98] G[2]   */
				SIU.PCR[98].R = 0x0400;						/* ALT[1] */
				SIU.PSMI[29].B.PADSEL = 1;
			}
		}
	} else if (subMod == 3) {
		if (outAB == 0) {					/* FlexPWM_0 A[3] */ 
			if (pcrNum == 2) {						/* PCR[2] A[2]    */
				SIU.PCR[2].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[23].B.PADSEL = 0;
			} else if (pcrNum == 42) {				/* PCR[42] C[10]  */
				SIU.PCR[42].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[23].B.PADSEL = 1;
			} else if (pcrNum == 51) {				/* PCR[51] D[3]   */ 
				SIU.PCR[51].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[23].B.PADSEL = 2;
			} else if (pcrNum == 102) {				/* PCR[102] G[6]  */
				SIU.PCR[102].R = 0x0400;					/* ALT[1] */
				SIU.PSMI[23].B.PADSEL = 3;
			}
		} else if (outAB == 1) { 			/* FlexPWM_0 B[3] */
			if (pcrNum == 3) {						/* PCR[3] A[3]    */
				SIU.PCR[3].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[27].B.PADSEL = 0;
			} else if (pcrNum == 9) {				/* PCR[9] A[9]    */
				SIU.PCR[9].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[27].B.PADSEL = 1;
			} else if (pcrNum == 52) {				/* PCR[52] D[4]   */
				SIU.PCR[52].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[27].B.PADSEL = 2;
			} else if (pcrNum == 103) {				/* PCR[103] G[7]  */	
				SIU.PCR[103].R = 0x0400;					/* ALT[1] */
				SIU.PSMI[27].B.PADSEL = 3;
			}
		} else {							/* FlexPWM_0 X[3] */
			if (pcrNum == 50) {						/* PCR[50] D[2]   */
				SIU.PCR[50].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[30].B.PADSEL = 0;
			} else if (pcrNum == 54) {				/* PCR[54] D[6]   */
				SIU.PCR[54].R = 0x0C00;						/* ALT[3] */
				SIU.PSMI[30].B.PADSEL = 1;
			} else if (pcrNum == 101) {				/* PCR[101] G[5]  */
				SIU.PCR[101].R = 0x0400;					/* ALT[1] */
				SIU.PSMI[30].B.PADSEL = 2;
			}
		}
	}
  } else if (pwmMod == 1) {
	if (subMod == 0) {
		if (outAB == 0) {					/* FlexPWM_1 A[0] */ 
			if (pcrNum == 117) {					/* PCR[117] H[5]   */
				SIU.PCR[117].R = 0x0400;					/* ALT[1] */
			}
		} else if (outAB == 1) { 			/* FlexPWM_1 B[0] */
			if (pcrNum == 118) {					/* PCR[118] H[6]   */
				SIU.PCR[118].R = 0x0400;					/* ALT[1] */
			}
		} else {							/* FlexPWM_1 X[0] */
			if (pcrNum == 116) {					/* PCR[116] H[4]   */
				SIU.PCR[116].R = 0x0400;					/* ALT[1] */
			}
		}
	} else if (subMod == 1) {
		if (outAB == 0) {					/* FlexPWM_1 A[0] */ 
			if (pcrNum == 120) {					/* PCR[120] H[8]   */
				SIU.PCR[120].R = 0x0400;					/* ALT[1] */
			}
		} else if (outAB == 1) { 			/* FlexPWM_1 B[0] */
			if (pcrNum == 121) {					/* PCR[121] H[9]   */
				SIU.PCR[121].R = 0x0400;					/* ALT[1] */
			}
		} else {							/* FlexPWM_1 X[0] */
			if (pcrNum == 119) {					/* PCR[120] H[7]   */
				SIU.PCR[119].R = 0x0400;					/* ALT[1] */
			}
		}
	} else if (subMod == 2) {
		if (outAB == 0) {					/* FlexPWM_1 A[0] */ 
			if (pcrNum == 123) {					/* PCR[123] H[11]   */
				SIU.PCR[123].R = 0x0400;					/* ALT[1] */
			}
		} else if (outAB == 1) { 			/* FlexPWM_1 B[0] */
			if (pcrNum == 124) {					/* PCR[124] H[12]   */
				SIU.PCR[124].R = 0x0400;					/* ALT[1] */
			}
		} else {							/* FlexPWM_1 X[0] */
			if (pcrNum == 122) {					/* PCR[122] H[10]   */
				SIU.PCR[122].R = 0x0400;					/* ALT[1] */
			}
		}
	} else if (subMod == 3) {
		if (outAB == 0) {					/* FlexPWM_1 A[0] */ 
			if (pcrNum == 126) {					/* PCR[126] H[14]   */
				SIU.PCR[126].R = 0x0400;					/* ALT[1] */
			}
		} else if (outAB == 1) { 			/* FlexPWM_1 B[0] */
			if (pcrNum == 127) {					/* PCR[127] H[15]   */
				SIU.PCR[127].R = 0x0400;					/* ALT[1] */
			}
		} else {							/* FlexPWM_1 X[0] */
			if (pcrNum == 125) {					/* PCR[125] H[13]   */
				SIU.PCR[125].R = 0x0400;					/* ALT[1] */
			}
		}
	}
  }
}


/******************************************************************************
*   Function:  pwm_init_564xL_comp
@brief    FlexPWM Init function for compltmentary mode . 
@details  FlexPWM Init function for compltmentary mode
    
@param[in]     subMod   - 
@param[in]     Freq      -  
@param[in]     Duty      -  
@param[in]     DeadTime      -  

@return  none
*/
void pwm_init_564xL_comp(uint8_t pwmMod, uint8_t subMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DeadTime, uint16_t outTrig, 
                         uint8_t masterSync, uint8_t pwm45en, uint16_t DutyB, uint16_t OCTRL)
{
	volatile mcPWM_tag* FlexPWM = FlexPWM_module[pwmMod];
    uint16_t val[6] = { 0U };
    uint16_t init, mask, prescaler;
    uint32_t period = 0U;
	uint8_t i, iMax;
	uint32_t DutyMax = 100 * resolution;

    mask = (uint16_t)(0x1U << subMod);
	prescaler = pwm_prescaler (Freq, &period);
	
	val[0] = 0;
    val[1] = (uint16_t)(period / 2);
    init = 0 - val[1];
	
	if (DutyA >= DutyMax) {
		val[2] = init;
		val[3] = val[1]+1;
	} else {
		val[3] = (uint16_t)((DutyA * val[1])/DutyMax);
		val[2] = 0 - val[3];
	}
	if (pwm45en) {
		if (DutyB >= DutyMax) {
			val[4] = init;
			val[5] = val[1]+1;
		} else {
			val[5] = (uint16_t)((DutyB * val[1])/DutyMax);
			val[4] = 0 - val[5];
		}
		iMax = 6;
	} else {
		iMax = 4;
	}
	
	if (masterSync) {
		FlexPWM->SUB[subMod].CTRL2.R = 0x9A00;   /* Master sync from submodule 0 */
	} else {
		FlexPWM->SUB[subMod].CTRL2.R = 0x9800;   /* Local sync */
	}
	FlexPWM->SUB[subMod].INIT.R   = init;
	for (i = 0; i < iMax; i++) {
		FlexPWM->SUB[subMod].VAL[i].R = val[i];
	}
	FlexPWM->SUB[subMod].DTCNT0.R = DeadTime;
	FlexPWM->SUB[subMod].DTCNT1.R = DeadTime;
	FlexPWM->SUB[subMod].CTRL.R   = prescaler | 0x0400;
	FlexPWM->SUB[subMod].TCTRL.B.OUT_TRIG_EN = outTrig;
	FlexPWM->SUB[subMod].OCTRL.R = OCTRL;

	FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | mask;         /* LDOK */
	FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | (mask << 8);  /* RUN  */
}

/******************************************************************************
*   Function:  pwm_update_564xL_comp
@brief    FlexPWM Update function for complimentary mode . 
@details  FlexPWM Update function for complimentary mode
    
@param[in]     subMod   - 
@param[in]     Freq      -  
@param[in]     Duty      -  
@param[in]     DeadTime      -  
@param[in]     DeadTimeLag      -  

@return  none
*/
void pwm_update_564xL_comp(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t Duty, uint16_t DeadTimeLead,  uint16_t DeadTimeLag)
{
	volatile mcPWM_tag* FlexPWM = FlexPWM_module[pwmMod];
    uint16_t val1, val2, val3;
    uint16_t init, mask, prescaler;
    uint32_t period = 0U;
	uint32_t DutyMax = 100 * resolution;

    mask = (uint16_t)(0x1U << SubMod);
	prescaler = pwm_prescaler (Freq, &period);
	
    val1 = (uint16_t)(period / 2);
    init = 0 - val1;
	if (Duty >= DutyMax) {
		val2 = init;
		val3 = val1+1;
	} else {
		val3 = (uint16_t)((Duty * val1)/DutyMax);
		val2 = 0 - val3;
	}

    FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | (mask << 4);  /* CLDOK */

    FlexPWM->SUB[SubMod].INIT.R   = init;
    FlexPWM->SUB[SubMod].VAL[1].R = val1;
    FlexPWM->SUB[SubMod].VAL[2].R = val2;
    FlexPWM->SUB[SubMod].VAL[3].R = val3;
    FlexPWM->SUB[SubMod].DTCNT0.R = DeadTimeLead;
    FlexPWM->SUB[SubMod].DTCNT1.R = DeadTimeLag;
    FlexPWM->SUB[SubMod].CTRL.R   = prescaler | 0x0400;
	 
    FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | mask;        /* LDOK */
}

  void pwm_update_564xL_comp2(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint16_t DeadTimeLead, uint16_t DeadTimeLag)
  {
 	volatile mcPWM_tag* FlexPWM = FlexPWM_module[pwmMod];
    uint16_t val1, val2, val3, val4, val5;
    uint16_t init, mask, prescaler;
    uint32_t period = 0U;
	uint32_t DutyMax = 100 * resolution;
	
    mask = (uint16_t)(0x1U << SubMod);
    prescaler = pwm_prescaler (Freq, &period);
	
    val1 = (uint16_t)(period / 2);
    init = 0 - val1;
	if (DutyA >= DutyMax) {
		val2 = init;
		val3 = val1+1;
	} else {
		val3 = (uint16_t)((DutyA * val1)/DutyMax);
		val2 = 0 - val3;
	}
	if (DutyB >= DutyMax) {
		val4 = init;
		val5 = val1+1;
	} else {
		val5 = (uint16_t)((DutyB * val1)/DutyMax);
		val4 = 0 - val5;
	}
	
    FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | (uint16_t)(mask << 4); /* CLDOK */
	
    FlexPWM->SUB[SubMod].INIT.R   = init;
    FlexPWM->SUB[SubMod].VAL[1].R = val1;
    FlexPWM->SUB[SubMod].VAL[2].R = val2;
    FlexPWM->SUB[SubMod].VAL[3].R = val3;
    FlexPWM->SUB[SubMod].VAL[4].R = val4;
    FlexPWM->SUB[SubMod].VAL[5].R = val5;
    FlexPWM->SUB[SubMod].DTCNT0.R = DeadTimeLead;
    FlexPWM->SUB[SubMod].DTCNT1.R = DeadTimeLag;
    FlexPWM->SUB[SubMod].CTRL.R   = prescaler | 0x0400;
	
    FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | mask;   /* LDOK */
  }

/******************************************************************************
*   Function:  pwm_init_564xL_simple
@brief    FlexPWM Init function for simple mode . 
@details  FlexPWM Init function for simple mode
    
@param[in]     subMod     - 
@param[in]     Freq       -  
@param[in]     DutyA      -  
@param[in]     DutyB      -  
@param[in]     centered   -
@param[in]     ShiftA     -  
@param[in]     ShiftB     -  
@param[in]     outTrig    -
@param[in]     masterSync -
@param[in]     doubleSw   -  

@return  none
*/
void pwm_init_564xL_simple(uint8_t pwmMod, uint8_t subMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint8_t centered, uint16_t ShiftA, 
                           uint16_t ShiftB, uint16_t outTrig, uint8_t masterSync, uint8_t doubleSw, uint16_t OCTRL)
{
 	volatile mcPWM_tag* FlexPWM = FlexPWM_module[pwmMod];
    uint16_t init, val0, val1, val2, val3, val4, val5;
    uint16_t prescaler, mask, shift_lag = 0U;
    uint32_t period = 0U;
	uint32_t DutyMax = 100 * resolution;
	uint32_t DutyMaxHalf = 50 * resolution;
	
    mask = (uint16_t)(0x1U << subMod);
    prescaler = pwm_prescaler (Freq, &period);
	
    val1 = (uint16_t)(period / 2);
    init = 0 - val1;          
	val0 = 0;
	
	if (DutyA >= DutyMax) {
		val2 = init;
		val3 = val1+1;                             /* +1 */
	} else if (centered) {                         /* center aligned PWMs */
		val3 = (uint16_t)((DutyA * val1)/DutyMax);
		val2 = 0 - val3;
	} else {                                       /* phase shifted anf edge aligned */
		if (ShiftA == 0) {
			val2 = init;
	} else {
			while (ShiftA > DutyMax) {
				ShiftA = ShiftA - DutyMax;
			}
			if (ShiftA >= DutyMaxHalf) {
				val2 = (uint16_t)((val1 * ShiftA) / DutyMaxHalf) - val1;
			} else {
				val2 = 0 - (val1 - (uint16_t)((val1 * ShiftA) / DutyMaxHalf));
			}
		}
		shift_lag = ShiftA + DutyA;
		if (shift_lag > DutyMax) {
			shift_lag = shift_lag - DutyMax;
		}
		if (shift_lag >= DutyMaxHalf) {
			val3 = (uint16_t)((val1 * shift_lag) / DutyMaxHalf) - val1;
		} else {
			val3 = 0 - (val1 - (uint16_t)((val1 * shift_lag) / DutyMaxHalf));
		}
	}
	
	if (DutyB >= DutyMax) {
		val4 = init;
		val5 = val1+1;                             /* +1 */
	} else if (centered) {                         /* center aligned PWMs */
		val5 = (uint16_t)((DutyB * val1)/DutyMax);
		val4 = 0 - val5;
	} else {                                       /* phase shifted anf edge aligned */
		if (ShiftB == 0) {
			val4 = init;
		} else {
			while (ShiftB > DutyMax) {
				ShiftB = ShiftB - DutyMax;
			}
			if (ShiftB >= DutyMaxHalf) {
				val4 = (uint16_t)((val1 * ShiftB) / DutyMaxHalf) - val1;
			} else {
				val4 = 0 - (val1 - (uint16_t)((val1 * ShiftB) / DutyMaxHalf));
			}
		}
		shift_lag = ShiftB + DutyB;
		if (shift_lag > DutyMax) {
			shift_lag = shift_lag - DutyMax;
		}
		if (shift_lag >= DutyMaxHalf) {
			val5 = (uint16_t)((val1 * shift_lag) / DutyMaxHalf) - val1;
		} else {
			val5 = 0 - (val1 - (uint16_t)((val1 * shift_lag) / DutyMaxHalf));
		}
	}

    /* Independent PWMs */
    /* Initial value for PWM23, PWM45 : 1 */
	if (masterSync) {
		FlexPWM->SUB[subMod].CTRL2.R = 0xBA00;   /* Master sync from submodule 0 */
	} else {
		FlexPWM->SUB[subMod].CTRL2.R = 0xB800;   /* Local sync */
	}
    FlexPWM->SUB[subMod].INIT.R = init;
    FlexPWM->SUB[subMod].VAL[0].R = val0;
    FlexPWM->SUB[subMod].VAL[1].R = val1;
    FlexPWM->SUB[subMod].VAL[2].R = val2;
    FlexPWM->SUB[subMod].VAL[3].R = val3;
    FlexPWM->SUB[subMod].VAL[4].R = val4;
    FlexPWM->SUB[subMod].VAL[5].R = val5;

    if (doubleSw) {
        FlexPWM->SUB[subMod].CTRL.R = prescaler | 0x0401;  /* double switching enabled  */
    } else {
        FlexPWM->SUB[subMod].CTRL.R = prescaler | 0x0400;  /* double switching disabled */
    }

    FlexPWM->SUB[subMod].TCTRL.B.OUT_TRIG_EN = outTrig;
	FlexPWM->SUB[subMod].OCTRL.R = OCTRL;
    FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | mask;        /* LDOK */
    FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | (uint16_t)(mask << 8); /* RUN  */
}

  static void pwm_update_564xL_simple(uint8_t pwmMod, uint8_t subMod, FlexPWMparams_type const* params)
  {
 	volatile mcPWM_tag* FlexPWM = FlexPWM_module[pwmMod];
	uint8_t i;
	
    FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | (uint16_t)(params->mask << 4); /* CLDOK */
    FlexPWM->SUB[subMod].INIT.R = params->init;
	for (i = 0; i < 6; i++) {
		FlexPWM->SUB[subMod].VAL[i].R = params->val[i];
	}
    FlexPWM->SUB[subMod].CTRL.R = params->prescaler | 0x0400 | (FlexPWM->SUB[subMod].CTRL.R & 0x0001); /* double switching */
    FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | params->mask;  /* LDOK */
  }

/******************************************************************************
*   Function:  pwm_update_564xL_simple_B_phase_shift
@brief    FlexPWM Update function for simple mode . 
@details  FlexPWM Update function for simple mode
    
@param[in]     subMod   - 
@param[in]     Freq     -  
@param[in]     DutyA    -  
@param[in]     DutyB    -  
@param[in]     ShiftB   -  

@return  none
*/
void pwm_update_564xL_simple_B_phase_shift(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint16_t ShiftB )
{
    FlexPWMparams_type params = { 0U };
    uint32_t period = 0U;
    uint16_t shift_lag;
	uint32_t DutyMax = 100 * resolution;
	uint32_t DutyMaxHalf = 50 * resolution;

	params.mask = (uint16_t)(0x1U << SubMod);
	params.prescaler = pwm_prescaler (Freq, &period);
	
	params.val[0] = 0;
	params.val[1] = (uint16_t) (period / 2);
	params.init = 0 - params.val[1];
	params.val[2] = params.init;                 /* val2 = init */
  
	if (DutyA >= DutyMax) {
		params.val[3] = params.val[1]+1;         /* +1 */
	} else if (DutyA >= DutyMaxHalf) {
		params.val[3] = (uint16_t)((params.val[1] * DutyA) / DutyMaxHalf) - params.val[1];
	} else {  
		params.val[3] = 0 - (params.val[1] - (uint16_t)((params.val[1] * DutyA) / DutyMaxHalf));
	}
	if (DutyB >= DutyMax) {
		params.val[4] = params.init;
		params.val[5] = params.val[1]+1;
	} else {
		while (ShiftB > DutyMax) {
			ShiftB = ShiftB - DutyMax;
		}
		if (ShiftB >= DutyMaxHalf) {
			params.val[4] = (uint16_t)((params.val[1] * ShiftB) / DutyMaxHalf) - params.val[1];
		} else {
			params.val[4] = 0 - (params.val[1] - (uint16_t)((params.val[1] * ShiftB) / DutyMaxHalf));
		}
		shift_lag = ShiftB + DutyB;
		if (shift_lag > DutyMax) {
			shift_lag = shift_lag - DutyMax;
		}
		if (shift_lag >= DutyMaxHalf) {
			params.val[5] = (uint16_t)((params.val[1] * shift_lag) / DutyMaxHalf) - params.val[1];
		} else {
			params.val[5] = 0 - (params.val[1] - (uint16_t)((params.val[1] * shift_lag) / DutyMaxHalf));
		}
	}

	pwm_update_564xL_simple (pwmMod, SubMod, &params);
}

void pwm_update_564xL_simple_centered(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB) 
{
    FlexPWMparams_type params = { 0U };
    uint32_t period = 0U;
	uint32_t DutyMax = 100 * resolution;

    params.mask = (uint16_t)(0x1U << SubMod);
    params.prescaler = pwm_prescaler (Freq, &period);
	
	params.val[0] = 0;
    params.val[1] = (uint16_t) (period / 2);
    params.init = 0 - params.val[1];          
	if (DutyA >= DutyMax) {
		params.val[2] = params.init;
		params.val[3] = params.val[1]+1;
	} else {
		params.val[3] = (uint16_t)((DutyA * params.val[1])/DutyMax);
		params.val[2] = 0 - params.val[3];
	}
	if (DutyB >= DutyMax) {
		params.val[4] = params.init;
		params.val[5] = params.val[1]+1;
	} else {
		params.val[5] = (uint16_t)((DutyB * params.val[1])/DutyMax);
		params.val[4] = 0 - params.val[5];
	}

	pwm_update_564xL_simple (pwmMod, SubMod, &params);
}

void pwm_update_564xL_simple_edge_align(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB) 
{
    FlexPWMparams_type params = { 0U };
    uint32_t period = 0U;
	uint32_t DutyMax = 100 * resolution;
	uint32_t DutyMaxHalf = 50 * resolution;

    params.mask = (uint16_t)(0x1U << SubMod);
    params.prescaler = pwm_prescaler (Freq, &period);
	
	params.val[0] = 0;
    params.val[1] = (uint16_t) (period / 2);
    params.init = 0 - params.val[1];        
	params.val[2] = params.init;
	if (DutyA >= DutyMax) {
		params.val[3] = params.val[1]+1;
	} else if (DutyA >= DutyMaxHalf) {
		params.val[3] = (uint16_t)((params.val[1] * DutyA) / DutyMaxHalf) - params.val[1];
	} else {
		params.val[3] = 0 - (params.val[1] - (uint16_t)((params.val[1] * DutyA) / DutyMaxHalf));
	}
	params.val[4] = params.init;
	if (DutyB >= DutyMax) {
		params.val[5] = params.val[1]+1;
	} else if (DutyB >= DutyMaxHalf) {
		params.val[5] = (uint16_t)((params.val[1] * DutyB) / DutyMaxHalf) - params.val[1];
	} else {
		params.val[5] = 0 - (params.val[1] - (uint16_t)((params.val[1] * DutyB) / DutyMaxHalf));
	}

	pwm_update_564xL_simple (pwmMod, SubMod, &params);
}

void pwm_update_564xL_simple_phase_shift(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint16_t ShiftA, uint16_t ShiftB) 
{
    FlexPWMparams_type params = { 0U };
    uint32_t period = 0U;
    uint16_t shift_lag;
	uint32_t DutyMax = 100 * resolution;
	uint32_t DutyMaxHalf = 50 * resolution;
 
    params.mask = (uint16_t)(0x1U << SubMod);
    params.prescaler = pwm_prescaler (Freq, &period);
	
	params.val[0] = 0;
    params.val[1] = (uint16_t) (period / 2);
    params.init = 0 - params.val[1];          
	if (DutyA >= DutyMax) {
		params.val[2] = params.init;
		params.val[3] = params.val[1]+1;
	} else {
		while (ShiftA > DutyMax) {
			ShiftA = ShiftA - DutyMax;
		}
		if (ShiftA >= DutyMaxHalf) {
			params.val[2] = (uint16_t)((params.val[1] * ShiftA) / DutyMaxHalf) - params.val[1];
		} else {
			params.val[2] = 0 - (params.val[1] - (uint16_t)((params.val[1] * ShiftA) / DutyMaxHalf));
		}
		shift_lag = ShiftA + DutyA;
		if (shift_lag > DutyMax) {
			shift_lag = shift_lag - DutyMax;
		}
		if (shift_lag >= DutyMaxHalf) {
			params.val[3] = (uint16_t)((params.val[1] * shift_lag) / DutyMaxHalf) - params.val[1];
		} else {
			params.val[3] = 0 - (params.val[1] - (uint16_t)((params.val[1] * shift_lag) / DutyMaxHalf));
		}
	}
	if (DutyB >= DutyMax) {
		params.val[4] = params.init;
		params.val[5] = params.val[1]+1;
	} else {
		while (ShiftB > DutyMax) {
			ShiftB = ShiftB - DutyMax;
		}
		if (ShiftB >= DutyMaxHalf) {
			params.val[4] = (uint16_t)((params.val[1] * ShiftB) / DutyMaxHalf) - params.val[1];
		} else {
			params.val[4] = 0 - (params.val[1] - (uint16_t)((params.val[1] * ShiftB) / DutyMaxHalf));
		}
		shift_lag = ShiftB + DutyB;
		if (shift_lag > DutyMax) {
			shift_lag = shift_lag - DutyMax;
		}
		if (shift_lag >= DutyMaxHalf) {
			params.val[5] = (uint16_t)((params.val[1] * shift_lag) / DutyMaxHalf) - params.val[1];
		} else {
			params.val[5] = 0- (params.val[1] - (uint16_t)((params.val[1] * shift_lag) / DutyMaxHalf));
		}
	}

	pwm_update_564xL_simple (pwmMod, SubMod, &params);
}

/******************************************************************************
*   Function:  pwm_init_564xL_three_phase
@brief    FlexPWM Init function for three phase mode . 
@details  FlexPWM Init function for three phase mode
    
@param[in]     subMod   - 
@param[in]     Freq      -  
@param[in]     DutyA      -  
@param[in]     DutyB      -  
@param[in]     DutyC      -  
@param[in]     DeadTime      -  

@return  none
*/
void pwm_init_564xL_three_phase(uint8_t pwmMod, uint8_t subModB, uint8_t  subModC, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint16_t DutyC, 
								uint16_t outTrigA, uint16_t outTrigB, uint16_t outTrigC, uint16_t DeadTime, uint16_t OCTRL_A, 
								uint16_t OCTRL_B, uint16_t OCTRL_C) 
{
    uint16_t prescaler, mask, maskA, maskB, maskC;
    uint16_t init, val1, val2_A, val3_A, val2_B, val3_B, val2_C, val3_C;
    uint32_t period = 0U;
	volatile mcPWM_tag* FlexPWM = FlexPWM_module[pwmMod];
	uint32_t DutyMax = 100 * resolution;
				
	maskA = 0x1U;
	maskB = (uint16_t)(0x1U << subModB);
	maskC = (uint16_t)(0x1U << subModC);
	mask = maskA | maskB | maskC;
	prescaler = pwm_prescaler (Freq, &period);
  
	val1 = (uint16_t) (period / 2);
	init = 0 - val1 ;
	if (DutyA >= DutyMax) {
		val2_A = init;
		val3_A = val1+1;
	} else {
		val3_A = (uint16_t)((DutyA * val1)/DutyMax);
		val2_A = 0 - val3_A;
	}
	if (DutyB >= DutyMax) {
		val2_B = init;
		val3_B = val1+1;
	} else {
		val3_B = (uint16_t)((DutyB * val1)/DutyMax);
		val2_B = 0 - val3_B;
	}
	if (DutyC >= DutyMax) {
		val2_C = init;
		val3_C = val1+1;
	} else {
		val3_C = (uint16_t)((DutyC * val1)/DutyMax);
		val2_C = 0 - val3_C;
	}
	
	FlexPWM->SUB[0].INIT.R = init;
	FlexPWM->SUB[0].VAL[1].R = val1;
	FlexPWM->SUB[0].VAL[2].R = val2_A;
	FlexPWM->SUB[0].VAL[3].R = val3_A;
	FlexPWM->SUB[0].DTCNT0.R = DeadTime;
	FlexPWM->SUB[0].DTCNT1.R = DeadTime;
	FlexPWM->SUB[0].CTRL.R = prescaler | 0x0400;
	FlexPWM->SUB[0].TCTRL.B.OUT_TRIG_EN = outTrigA;
	FlexPWM->SUB[0].OCTRL.R = OCTRL_A;

	FlexPWM->SUB[subModB].INIT.R = init;
	FlexPWM->SUB[subModB].VAL[2].R = val2_B;
	FlexPWM->SUB[subModB].VAL[3].R = val3_B;
	FlexPWM->SUB[subModB].DTCNT0.R = DeadTime;
	FlexPWM->SUB[subModB].DTCNT1.R = DeadTime;
	FlexPWM->SUB[subModB].CTRL.R = prescaler | 0x0400;
	FlexPWM->SUB[subModB].TCTRL.B.OUT_TRIG_EN = outTrigB;
	FlexPWM->SUB[subModB].OCTRL.R = OCTRL_B;

	FlexPWM->SUB[subModC].INIT.R = init;
	FlexPWM->SUB[subModC].VAL[2].R = val2_C;
	FlexPWM->SUB[subModC].VAL[3].R = val3_C;
	FlexPWM->SUB[subModC].DTCNT0.R = DeadTime;
	FlexPWM->SUB[subModC].DTCNT1.R = DeadTime;
	FlexPWM->SUB[subModC].CTRL.R = prescaler | 0x0400;
	FlexPWM->SUB[subModC].TCTRL.B.OUT_TRIG_EN = outTrigC;
	FlexPWM->SUB[subModC].OCTRL.R = OCTRL_C;
	
	FlexPWM->SUB[subModB].CTRL2.R = 0x9200;
            /* Initialization Control: Master sync    */
	FlexPWM->SUB[subModC].CTRL2.R = 0x9200;
            /* Initialization Control: Master sync    */
	FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | mask;         /* LDOK */
	FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | (mask << 8);  /* RUN  */
}

/*  */
/******************************************************************************
*   Function:  pwm_update_564xL_three_phase
@brief    FlexPWM Update function for three phase mode . 
@details  FlexPWM Update function for three phase mode
    
@param[in]     subMod   - 
@param[in]     Freq      -  
@param[in]     DutyA      -  
@param[in]     DutyB      -  
@param[in]     DutyC      -  
@param[in]     DeadTimeLead      -  
@param[in]     DeadTimeLag      -  

@return  none
*/
void pwm_update_564xL_three_phase(uint8_t pwmMod, uint8_t subModB, uint8_t  subModC, uint32_t Freq, uint16_t resolution, 
                                  uint16_t DutyA, uint16_t DutyB, uint16_t DutyC, uint16_t DeadTimeLead,  uint16_t DeadTimeLag) 
{
    uint16_t prescaler, mask, maskA, maskB, maskC;
    uint16_t init, val1, val2_A, val3_A, val2_B, val3_B, val2_C, val3_C;
    uint32_t period = 0U;
	volatile mcPWM_tag* FlexPWM = FlexPWM_module[pwmMod];
	uint32_t DutyMax = 100 * resolution;
				
	maskA = 0x1U;
	maskB = (uint16_t)(0x1U << subModB);
	maskC = (uint16_t)(0x1U << subModC);
	mask = maskA | maskB | maskC;
	prescaler = pwm_prescaler (Freq, &period);
  
	val1 = (uint16_t) (period / 2);
	init = 0 - val1;
  
	if (DutyA >= DutyMax) {
		val2_A = init;
		val3_A = val1+1;
	} else {
		val3_A = (uint16_t)((DutyA * val1)/DutyMax);
		val2_A = 0 - val3_A;
	}
	if (DutyB >= DutyMax) {
		val2_B = init;
		val3_B = val1+1;
	} else {
		val3_B = (uint16_t)((DutyB * val1)/DutyMax);
		val2_B = 0 - val3_B;
	}
	if (DutyC >= DutyMax) {
		val2_C = init;
		val3_C = val1+1;
	} else {
		val3_C = (uint16_t)((DutyC * val1)/DutyMax);
		val2_C = 0 - val3_C;
	}
	FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | (mask << 4);  /* CLDOK */

	FlexPWM->SUB[0].INIT.R = init;
	FlexPWM->SUB[0].VAL[1].R = val1;
	FlexPWM->SUB[0].VAL[2].R = val2_A;
	FlexPWM->SUB[0].VAL[3].R = val3_A;
	FlexPWM->SUB[0].DTCNT0.R = DeadTimeLead;
	FlexPWM->SUB[0].DTCNT1.R = DeadTimeLag;
	FlexPWM->SUB[0].CTRL.R = prescaler | 0x0400;

	FlexPWM->SUB[subModB].INIT.R = init;
	FlexPWM->SUB[subModB].VAL[2].R = val2_B;
	FlexPWM->SUB[subModB].VAL[3].R = val3_B;
	FlexPWM->SUB[subModB].DTCNT0.R = DeadTimeLead;
	FlexPWM->SUB[subModB].DTCNT1.R = DeadTimeLag;
	FlexPWM->SUB[subModB].CTRL.R = prescaler | 0x0400;

	FlexPWM->SUB[subModC].INIT.R = init;
	FlexPWM->SUB[subModC].VAL[2].R = val2_C;
	FlexPWM->SUB[subModC].VAL[3].R = val3_C;
	FlexPWM->SUB[subModC].DTCNT0.R = DeadTimeLead;
	FlexPWM->SUB[subModC].DTCNT1.R = DeadTimeLag;
	FlexPWM->SUB[subModC].CTRL.R = prescaler | 0x0400;

	FlexPWM->MCTRL.R = FlexPWM->MCTRL.R | mask;         /* LDOK */
}

#ifdef __cplusplus
}
#endif

/*
*######################################################################
*                           End of File
*######################################################################
*/
