/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED.
 *######################################################################
*
*    @file    CTU_564xL_library.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   CTU library file for 564xL.
*    @details CTU library file for 564xL.
*
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		23-May-2011
*   Author:                         B13508
*
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/

#include "CTU_564xL_library.h"

/******************************************************************************
*                  Static variables
******************************************************************************/

static uint32_t sysClk = MC_CLOCK;            /* Motor Control Input clock 10MHz: System PLL 120MHz divided by 12 */
static uint32_t sysClk_mhz = (MC_CLOCK/1000000);              /* sysClk divided by 1000000 */

/**/
/******************************************************************************
*                   Global functions
******************************************************************************/
/******************************************************************************
*   Function:  ctu_disable_isr_564xL
@brief    disable CTU ISRs .
@details  disable CTU ISRs

@return none
*/

/* disable CTU ISRs */
void ctu_disable_isr_564xL(void)
{
   CTU.CTUIR.R = 0;
}



/******************************************************************************
*   Function:  ctu_init_pcr_out_564xL
@brief    CTU Channel Pin Configuration Setup .
@details  CTU Channel Pin Configuration Setup

@return none
*/
void ctu_init_pcr_out_564xL (uint8_t pcrNumTgr, uint8_t pcrNumIn)
{
							/* CTU external trigger */
	if (pcrNumTgr == 46) {
		SIU.PCR[46].R = 0x0800;          /* PCR[46] C[14] ALT2 */ 
 	} else if (pcrNumTgr == 49) {
		SIU.PCR[49].R = 0x0C00;          /* PCR[49] D[1]  ALT3 */
 	} else if (pcrNumTgr == 131) {
		SIU.PCR[131].R = 0x0C00;         /* PCR[131] I[3] ALT3 */
	}
							/* CTU external input */
	if (pcrNumIn == 45) {
		SIU.PCR[45].R = 0x0100;          /* PCR[45] C[13] input */
		SIU.PSMI[0].B.PADSEL = 0;
 	} else if (pcrNumTgr == 47) {
		SIU.PCR[47].R = 0x0100;          /* PCR[47] C[15] input */
		SIU.PSMI[0].B.PADSEL = 1;
	}
}

/******************************************************************************
*   Function:  ctu_init_564xL
@brief    CTU initialization .
@details  CTU initialization

@param[in]     Mode   - Trigger Generator subunit Mode (0: Triggered Mode - 1: Sequential Mode)
@param[in]     InputSelection      -  Trigger generator subunit input selection register (TGSISR)
@param[in]     TriggerOutput[2]      - Trigger handler control registers (THCR1 and THCR2)
@param[in]      MRS     MRS Selection in Sequential Mode
@param[in]      MaxDelay_mks
@param[in]      triggerDelay_mks[8]
@param[in]      ADC_CmdIndex[2]
@param[in]      ADC_Commands[24]

@return none
*/
void ctu_init_564xL (uint8_t Mode, uint32_t InputSelection, uint32_t const* TriggerOutput,
                     uint8_t MRS, uint16_t MaxDelay_mks, uint16_t const* triggerDelay_mks,
					 uint32_t const* ADC_CmdIndex, uint16_t const* ADC_Commands)
{
	uint8_t i;
	uint8_t prescaler;
	uint16_t counter_reload_value;
	uint16_t counter_compare_value;
	uint16_t trigger_compare_value[8];
	uint32_t value;
	uint16_t ctuisr;

	ctuisr = CTU.CTUIR.R;

	CTU.CTUCR.B.CTU_ODIS = 1;            /* disable output */
	CTU.CTUCR.B.CGRE = 1;                /* Clear GRE */

	/* prescaler, counter_reload_value,counter_compare_value, trigger_compare_value */
	counter_reload_value = 0;
	for (prescaler = 0; prescaler < 4; prescaler++) {
		value = (MaxDelay_mks * sysClk_mhz) / (prescaler+1);
		if (value < 0x10000) {
			break;
		}
	}
	counter_compare_value = (uint16_t)value;
	for (i = 0; i < 8; i++)
	{
		trigger_compare_value[i] = (triggerDelay_mks[i] * sysClk_mhz) / (prescaler+1);
	}

	CTU.TGSCR.B.PRES   = prescaler;
	CTU.TGSCR.B.MRS_SM = MRS;
	CTU.TGSCR.B.ET_TM  = 1;                  /* external trigger toggle mode */
	CTU.TGSCR.B.TGS_M  = Mode;

	CTU.TGSCRR.R = counter_reload_value;
	CTU.TGSCCR.R = counter_compare_value;
	for (i = 0; i < 8; i++)
	{
		CTU.TCR[i].R = trigger_compare_value[i];
	}

	CTU.THCR1.R = TriggerOutput[0];
	CTU.THCR2.R = TriggerOutput[1];

	for (i = 0; i < 24; i++)
	{
		CTU.CLR[i].R = ADC_Commands[i];
	}
	CTU.CLCR1.R = ADC_CmdIndex[0];
	CTU.CLCR2.R = ADC_CmdIndex[1];

	CTU.COTR.B.COTR_COTR =  0xFF;        /* on-time for external trigger */

	CTU.FILTER.B.FILTER_VALUE = 0;       /* digital_filter */
	CTU.CTUCR.B.FILTER_EN = 1;           /* Synchronize Filter Register value */

	CTU.TGSISR.R = InputSelection;
	CTU.CTUCR.B.TGSISR_RE = 1;           /* TGSISR Reload Enable */

	CTU.CTUCR.B.GRE = 1;                 /* General Reload Enabl */
	CTU.CTUCR.B.CTU_ODIS = 0;            /* enable output */

    CTU.CTUIR.R = ctuisr;

}

#ifdef __cplusplus
}
#endif

/*
*######################################################################
*                           End of File
*######################################################################
*/
