/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    eTimer_564xL_library.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   ADC module support.
*    @details Implementation of ADC module functions.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		05/20/05
*   Author:                         r61406
* 
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/
#include "eTimer_564xL_library.h"


/******************************************************************************
*   Function:  etimer_init_pcr_in_out_564xL
@brief    eTimer Channel Pin Configuration Setup . 
@details  eTimer Channel Pin Configuration Setup
    
@param[in]     subMod     
@param[in]     channel  channel 
 @param[in]     pcrNum  pcrNum 
   
@return none
*/
void etimer_init_pcr_in_out_564xL(uint8_t subMod, uint8_t channel, uint8_t pcrNum)
{
	if (subMod == 0) {
		if (channel == 0) {					/* eTimer 0 channel 0		*/			
			if (pcrNum == 0) {						/* PCR[0] A[0]  ETC[0] input/output  */
				SIU.PCR[0].R = 0x0500;						/* ALT[1]   */
				SIU.PSMI[35].B.PADSEL = 0;
			} else if (pcrNum == 58) {				/* PCR[59] D[10]  ETC[0] input  */
				SIU.PSMI[35].B.PADSEL = 1;
			}
		} else if (channel == 1) {			/*   eTimer 0 channel 1   */
			if (pcrNum == 1) {						/*   PCR[1] A[1]  ETC[1] input/output   */
				SIU.PCR[1].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[36].B.PADSEL = 0;
			} else if (pcrNum == 59) {				/*   PCR[59] D[11]  ETC[1] input   */
				SIU.PSMI[36].B.PADSEL = 1;
			}
		} else if (channel == 2) {			/*   eTimer 0 channel 2   */
			if (pcrNum == 2) {						/*   PCR[2] A[2]  ETC[2] input/output   */
				SIU.PCR[2].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[37].B.PADSEL = 0;
			} else if (pcrNum == 80) {				/*   PCR[80] F[0]  ETC[2] input   */
				SIU.PSMI[37].B.PADSEL = 1;
			}
		} else if (channel == 3) {			/*   eTimer 0 channel 3   */
			if (pcrNum == 3) {						/*   PCR[3] A[3]  ETC[3] input/output   */
				SIU.PCR[3].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[38].B.PADSEL = 0;
			} else if (pcrNum == 62) {				/*   PCR[80] D[14]  ETC[3] input   */
				SIU.PSMI[38].B.PADSEL = 1;
			}
		} else if (channel == 4) {			/*   eTimer 0 channel 4   */
			if (pcrNum == 4) {						/*   PCR[4] A[4]  ETC[4] input/output   */
				SIU.PCR[4].R = 0x0D00;						/*   ALT[3]   */
				SIU.PSMI[7].B.PADSEL = 0;
			} else if (pcrNum == 43) {				/*   PCR[43] C[11]  ETC[4] input/output   */
				SIU.PCR[43].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[7].B.PADSEL = 1;
			} else if (pcrNum == 30) {				/*   PCR[30] B[14]  ETC[4] input   */
				SIU.PSMI[7].B.PADSEL = 2;
			} else if (pcrNum == 99) {				/*   PCR[99] G[3]  ETC[4] input   */
				SIU.PSMI[7].B.PADSEL = 3;
			}
		} else if (channel == 5) {			/*   eTimer 0 channel 5   */
			if (pcrNum == 44) {						/*   PCR[44] C[12]  ETC[5] input/output   */
				SIU.PCR[44].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[8].B.PADSEL = 0;
			} else if (pcrNum == 77) {				/*   PCR[77] E[13]  ETC[5] input/output   */
				SIU.PCR[77].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[8].B.PADSEL = 1;
			} else if (pcrNum == 24) {				/*   PCR[24] B[8]  ETC[5] input   */
				SIU.PSMI[8].B.PADSEL = 2;
			} else if (pcrNum == 100) {				/*   PCR[100] G[4]  ETC[5] input   */
				SIU.PSMI[8].B.PADSEL = 3;
			}
		}
	} else if (subMod == 1) {
		if (channel == 0) {					/*   eTimer 1 channel 0	   */				
			if (pcrNum == 4) {						/*   PCR[4] A[4]  ETC[0] input/output   */
				SIU.PCR[4].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[9].B.PADSEL = 0;
			} else if (pcrNum == 47) {				/*   PCR[47] C[15]  ETC[0] input/output   */
				SIU.PCR[47].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[9].B.PADSEL = 1;
			}
		} else if (channel == 1) {			/*   eTimer 1 channel 1   */
			if (pcrNum == 45) {						/*   PCR[45] C[13]  ETC[1] input/output   */
				SIU.PCR[45].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[10].B.PADSEL = 0;
			} else if (pcrNum == 48) {				/*   PCR[48] D[0]  ETC[1] input/output   */
				SIU.PCR[48].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[10].B.PADSEL = 1;
			}
		} else if (channel == 2) {			/*   eTimer 1 channel 2   */
			if (pcrNum == 16) {						/*   PCR[16] B[0]  ETC[2] input/output   */
				SIU.PCR[16].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[11].B.PADSEL = 0;
			} else if (pcrNum == 46) {				/*   PCR[46] C[14]  ETC[2] input/output   */
				SIU.PCR[46].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[11].B.PADSEL = 1;
			} else if (pcrNum == 49) {				/*   PCR[49] D[1]  ETC[2] input/output   */
				SIU.PCR[49].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[11].B.PADSEL = 2;
			}
		} else if (channel == 3) {			/*   eTimer 1 channel 3   */
			if (pcrNum == 17) {						/*   PCR[17] B[1]  ETC[3] input/output   */
				SIU.PCR[17].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[12].B.PADSEL = 0;
			} else if (pcrNum == 50) {				/*   PCR[50] D[2]  ETC[3] input/output   */
				SIU.PCR[50].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[12].B.PADSEL = 1;
			} else if (pcrNum == 92) {				/*   PCR[92] F[12]  ETC[3] input/output   */
				SIU.PCR[92].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[12].B.PADSEL = 2;
			}
		} else if (channel == 4) {			/*   eTimer 1 channel 4   */
			if (pcrNum == 14) {						/*   PCR[14] A[15]  ETC[4] input/output   */
				SIU.PCR[14].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[13].B.PADSEL = 0;
			} else if (pcrNum == 51) {				/*   PCR[51] D[3]  ETC[4] input/output   */
				SIU.PCR[51].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[13].B.PADSEL = 1;
			} else if (pcrNum == 56) {				/*   PCR[56] D[8]  ETC[4] input/output   */
				SIU.PCR[56].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[13].B.PADSEL = 2;
			} else if (pcrNum == 93) {				/*   PCR[93] F[13]  ETC[4] input/output   */
				SIU.PCR[93].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[13].B.PADSEL = 3;
			}
		} else if (channel == 5) {			/*   eTimer 1 channel 5   */
			if (pcrNum == 5) {						/*   PCR[5] A[5]  ETC[5] input/output   */
				SIU.PCR[5].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[14].B.PADSEL = 0;
			} else if (pcrNum == 15) {				/*   PCR[15] A[15]  ETC[5] input/output   */
				SIU.PCR[15].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[14].B.PADSEL = 1;
			} else if (pcrNum == 52) {				/*   PCR[52] D[4]  ETC[5] input/output   */
				SIU.PCR[52].R = 0x0900;						/*   ALT[2]   */
				SIU.PSMI[14].B.PADSEL = 2;
			} else if (pcrNum == 78) {				/*   PCR[78] E[14]  ETC[5] input/output   */
				SIU.PCR[78].R = 0x0500;						/*   ALT[1]   */
				SIU.PSMI[14].B.PADSEL = 3;
			}
		}
	} else if (subMod == 2) {
		if (channel == 0) {					/*   eTimer 2 channel 0   */
			if (pcrNum == 116) {					/*   PCR[116] H[4]  ETC[0] input/output   */
				SIU.PCR[116].R = 0x0900;					/*   ALT[2]   */
				SIU.PSMI[39].B.PADSEL = 0;
			} else if (pcrNum == 128) {				/*   PCR[128] I[0]  ETC[0] input/output   */
				SIU.PCR[128].R = 0x0500;					/*   ALT[1]   */
				SIU.PSMI[39].B.PADSEL = 1;
			}
		} else if (channel == 1) {			/*   eTimer 2 channel 1   */
			if (pcrNum == 119) {					/*   PCR[119] H[7]  ETC[1] input/output   */
				SIU.PCR[119].R = 0x0900;					/*   ALT[2]   */
				SIU.PSMI[40].B.PADSEL = 0;
			} else if (pcrNum == 129) {				/*   PCR[129] I[1]  ETC[1] input/output   */
				SIU.PCR[129].R = 0x0500;					/*   ALT[1]   */
				SIU.PSMI[40].B.PADSEL = 1;
			}
		} else if (channel == 2) {			/*   eTimer 2 channel 2   */
			if (pcrNum == 122) {					/*   PCR[122] H[10]  ETC[2] input/output   */
				SIU.PCR[122].R = 0x0900;					/*   ALT[2]   */
				SIU.PSMI[41].B.PADSEL = 0;
			} else if (pcrNum == 130) {				/*   PCR[130] I[2]  ETC[2] input/output   */
				SIU.PCR[130].R = 0x0500;					/*   ALT[1]   */
				SIU.PSMI[41].B.PADSEL = 1;
			}
		} else if (channel == 3) {			/*   eTimer 2 channel 3   */
			if (pcrNum == 125) {					/*   PCR[125] H[13]  ETC[3] input/output   */
				SIU.PCR[125].R = 0x0900;					/*   ALT[2]   */
				SIU.PSMI[42].B.PADSEL = 0;
			} else if (pcrNum == 131) {				/*   PCR[131] I[3]  ETC[3] input/output   */
				SIU.PCR[131].R = 0x0500;					/*   ALT[1]   */
				SIU.PSMI[42].B.PADSEL = 1;
			}
		} else if (channel == 4) {			/*   eTimer 2 channel 4   */
			if (pcrNum == 126) {					/*   PCR[126] H[14]  ETC[4] input/output   */
				SIU.PCR[126].R = 0x0900;					/*   ALT[2]   */
			}
		} else if (channel == 5) {			/*   eTimer 2 channel 5   */
			if (pcrNum == 127) {					/*   PCR[127] H[15]  ETC[5] input/output   */
				SIU.PCR[127].R = 0x0900;					/*   ALT[2]   */
			}
		}
	}
}

/******************************************************************************
*   Function:  etimer_init_564xL
@brief    eTimer Channel Pin Configuration Setup . 
@details  eTimer Channel Pin Configuration Setup
    
@param[in]     subMod     
@param[in]     channel  channel 
 @param[in]     CNTMODE  CNTMODE 
......   
@return none
*/
void etimer_init_564xL(
	uint16_t subMod, uint16_t channel,  uint16_t CNTMODE,   uint16_t OUTMODE,   uint16_t ONCE,
	uint16_t LENGTH, uint16_t DIR,      uint16_t OEN,       uint16_t COINIT,    uint16_t STPEN,
	uint16_t ROC,    uint16_t PRISRC,   uint16_t SECSRC,    uint16_t PIPS,      uint16_t SIPS,
	uint16_t OPS,    uint16_t MSTR,     uint16_t VAL,       uint16_t COFRC,     uint16_t CLC1,
	uint16_t CLC2,   uint16_t CMPMODE,  uint16_t CPT1MODE,  uint16_t CPT2MODE,  uint16_t ONESHOT,
	uint16_t CFWM,   uint16_t CNTRinit, uint16_t COMP1init, uint16_t COMP2init, uint16_t FILT,
	uint16_t INTDMA
)
{
	volatile mcTIMER_tag* eTimer;
	volatile mcTIMER_CHANNEL_tag* eTimerChannel;

	if (subMod == 2) {
		eTimer = &mcTIMER2;
	} else if (subMod == 1) {
		eTimer = &mcTIMER1;
	} else {
		eTimer = &mcTIMER0;
	}
	eTimerChannel = &(eTimer->CHANNEL[channel]);

	eTimerChannel->CTRL1.B.CNTMODE = 0;
	
	eTimerChannel->COMP1.R  = COMP1init;
	eTimerChannel->CMPLD1.R = COMP1init;
	eTimerChannel->COMP2.R  = COMP2init;
	eTimerChannel->CMPLD2.R = COMP2init;
	eTimerChannel->CNTR.R   = CNTRinit;
	eTimerChannel->LOAD.R   = CNTRinit;
	
	eTimerChannel->CTRL1.B.PRISRC = PRISRC;
	eTimerChannel->CTRL1.B.ONCE   = ONCE;
	eTimerChannel->CTRL1.B.LENGTH = LENGTH;
	eTimerChannel->CTRL1.B.DIR    = DIR;
	eTimerChannel->CTRL1.B.SECSRC = SECSRC;
	
    eTimerChannel->CTRL2.B.OEN     = OEN;
    eTimerChannel->CTRL2.B.RDNT    = 0;
    eTimerChannel->CTRL2.B.VAL     = VAL;
    eTimerChannel->CTRL2.B.COFRC   = COFRC;
    eTimerChannel->CTRL2.B.COINIT  = COINIT;
    eTimerChannel->CTRL2.B.SIPS    = SIPS;
    eTimerChannel->CTRL2.B.PIPS    = PIPS;
    eTimerChannel->CTRL2.B.OPS     = OPS;
    eTimerChannel->CTRL2.B.MSTR    = MSTR;
    eTimerChannel->CTRL2.B.OUTMODE = OUTMODE;
	
	eTimerChannel->CTRL3.B.STPEN   = STPEN;
	eTimerChannel->CTRL3.B.ROC     = ROC;
	eTimerChannel->CTRL3.B.DBGEN   = 0;
	
	eTimerChannel->CCCTRL.B.CLC2     = CLC2;
	eTimerChannel->CCCTRL.B.CLC1     = CLC1;
	eTimerChannel->CCCTRL.B.CMPMODE  = CMPMODE;
	eTimerChannel->CCCTRL.B.CPT2MODE = CPT2MODE;
	eTimerChannel->CCCTRL.B.CPT1MODE = CPT1MODE;
	eTimerChannel->CCCTRL.B.CFWM     = CFWM;
	eTimerChannel->CCCTRL.B.ONESHOT  = ONESHOT;
	eTimerChannel->CCCTRL.B.ARM      = 1;
	
	eTimerChannel->INTDMA.R = INTDMA;
	eTimerChannel->FILT.R   = FILT;
	
	eTimerChannel->CTRL1.B.CNTMODE = CNTMODE;
}

/******************************************************************************
*   Function:  etimer_564xL_update
@brief    eTimer Channel Pin Configuration Setup . 
@details  eTimer Channel Pin Configuration Setup
    
@param[in]     subMod     
@param[in]     channel  channel 
 @param[in]     LOAD  LOAD 
......   
@return none
*/
void etimer_564xL_update(uint16_t subMod, uint16_t channel,
                         uint16_t LOAD, uint16_t CMPLD1, uint16_t CMPLD2)
{
	volatile mcTIMER_tag* eTimer;
	volatile mcTIMER_CHANNEL_tag* eTimerChannel;

	if (subMod == 2) {
		eTimer = &mcTIMER2;
	} else if (subMod == 1) {
		eTimer = &mcTIMER1;
	} else {
		eTimer = &mcTIMER0;
	}
	eTimerChannel = &(eTimer->CHANNEL[channel]);

	eTimerChannel->LOAD.R   = LOAD;
	eTimerChannel->CMPLD1.R = CMPLD1;
	eTimerChannel->CMPLD2.R = CMPLD2;
}

/******************************************************************************
*   Function:  etimer_564xL_capture
@brief    eTimer Channel Pin Configuration Setup . 
@details  eTimer Channel Pin Configuration Setup
    
@param[in]     subMod     
@param[in]     channel  channel 
 @param[in]     Capture1cnt  Capture1cnt 
......   
@return none
*/ 
void etimer_564xL_capture(uint16_t subMod, uint16_t channel, 
                          uint16_t* Capture1cnt,uint16_t* Capture1,
						  uint16_t* Capture2cnt,uint16_t* Capture2)
{
	volatile mcTIMER_tag* eTimer;
	volatile mcTIMER_CHANNEL_tag* eTimerChannel;
	uint16_t i;

	if (subMod == 2) {
		eTimer = &mcTIMER2;
	} else if (subMod == 1) {
		eTimer = &mcTIMER1;
	} else {
		eTimer = &mcTIMER0;
	}
	eTimerChannel = &(eTimer->CHANNEL[channel]);

	*Capture1cnt = eTimerChannel->CTRL3.B.C1FCNT;
	for (i = 0; i < *Capture1cnt; i++)
	{
		Capture1[i] = eTimerChannel->CAPT1.R;
	}

	*Capture2cnt = eTimerChannel->CTRL3.B.C2FCNT;
	for (i = 0; i < *Capture2cnt; i++)
	{
		Capture2[i] = eTimerChannel->CAPT2.R;
	}
}						  


#ifdef __cplusplus
}
#endif

/*
*######################################################################
*                           End of File
*######################################################################
*/
