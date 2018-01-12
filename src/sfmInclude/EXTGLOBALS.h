/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2006-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name:       EXTGLOBALS.h$
* @file             EXTGLOBALS.h
*
* $Date:            Mar-01-2012$
* @date             Mar-01-2012
*
* $Version:         1.0$
* @version          1.0
*
* Description:      Extern global structures - header file
* @brief            Extern global structures - header file
*
* --------------------------------------------------------------------
* $Name:  $
*******************************************************************************/
/****************************************************************************//*!
*
*  @mainpage Extern global defines used by the PwSBC driver.
*
*  @section Intro Introduction
*
*	This package contains extern global structures.
*	The key features of this package are the following:
*  - Define extern global structures 
*
*  For more information about the functions and configuration items see these documents: 
*
*******************************************************************************
*
* @attention 
*	This file shall be included in all source files that use PwSBC driver 
*	(excluding main).            
*******************************************************************************/
/*==================================================================================================
*   Project              : PowerSBC
*   Platform             : MPC5643L
*   Dependencies         : MPC5643L - Basic SW drivers.
*   All Rights Reserved.
==================================================================================================*/

/*==================================================================================================
Revision History:
                             Modification     Function
Author (core ID)              Date D/M/Y       Name		  Description of Changes
B35993		 				  01/03/2012 	   ALL		  Driver created

---------------------------   ----------    ------------  ------------------------------------------
==================================================================================================*/

#ifndef _EXT_GLOBALS_H_
#define _EXT_GLOBALS_H_

//#include "PwSBC.h"
#include "typedefs.h"

/*==================================================================================================
*   Structures/Type defines
==================================================================================================*/

extern struct {
	union {
		vuint32_t R;
		struct {										///mask for ADC conversion
			vuint32_t				:24;			///reserved bits 
			vuint32_t	Vref	:	1;			///reference voltage mask 
			vuint32_t	VsnsW	:	1;			///battery voltage mask - Wide range
			vuint32_t	IO0W	:	1;			///IO0 voltage mask - Wide range
			vuint32_t	IO1W	:	1;			///IO1 voltage mask - Wide range
			vuint32_t	VsnsT	:	1;			///battery voltage mask - Tight range
			vuint32_t	IO0T	:	1;			///IO0 voltage mask - Tight range 
			vuint32_t	IO1T	:	1;			///IO1 voltage mask - Tight range
			vuint32_t	Temp	:	1;			///die temperature sensor voltage mask 
		} B;
	} scanVoltage;
	struct {											///last sampled voltages
		float	Vref;									///last sampled value of Vref 
		float	VsnsW;								///last sampled value of Vsns - Wide range
		float	IO0W;									///last sampled value of IO0 - Wide range
		float	IO1W;									///last sampled value of IO1 - Wide range
		float	VsnsT;								///last sampled value of Vsns - Tight range
		float	IO0T;									///last sampled value of IO0 - Tight range 
		float	IO1T;									///last sampled value of IO1 - Tight range 
		float	Temp;									///last sampled value of die temperature sensor 
	} actualVoltage;
} ADCstruct;

extern struct {
	uint32_t				writeCmd;					///last write command		
	uint32_t				readCmd;					///last read command
	uint32_t				stateSPI;					///actual state of the state machine
	Status_32B_tag	statusPwSBC;			///actual PwSBC status
	uint32_t				response;					///last PwSBC response
	uint32_t				FSdelayDisabled;	///disables delay 3.5 us after a secure command, 1 - disabled, 0 - enabled
} SPIstruct;

extern struct {
	uint32_t	WD_answer;							///actual content of the WD_answer register
	register32_struct currentLFSR;		///last LFSR state
} PITstruct;


extern struct{
	INIT_Vreg1_32B_tag								INIT_Vreg1;					///last received state of the INIT_Vreg1 register 
	INIT_Vreg2_32B_tag								INIT_Vreg2;					///last received state of the INIT_Vreg2 register 
	INIT_CAN_LIN_32B_tag							INIT_CAN_LIN;				///last received state of the INIT_CAN_LIN register 
	INIT_IO_WU1_32B_tag								INIT_IO_WU1;				///last received state of the INIT_IO_WU1 register 
	INIT_IO_WU2_32B_tag								INIT_IO_WU2;				///last received state of the INIT_IO_WU2 register 
	INIT_INT_32B_tag									INIT_INT;				///last received state of the INIT_INT register 
	HW_Config_Rx_32B_tag							HW_Config;					///last received state of the HW_Config register 
	WU_source_Rx_32B_tag							WU_source;					///last received state of the WU_source register 
	IO_input_state_Rx_32B_tag					IO_input_state;			///last received state of the IO_input_state register 
	Status_Vreg1_Rx_32B_tag						Status_Vreg1;				///last received state of the Status_32B_tag_Vreg1 register 
	Status_Vreg2_Rx_32B_tag						Status_Vreg2;				///last received state of the Status_32B_tag_Vreg2 register 
	Diag_Vreg1_Rx_32B_tag							Diag_Vreg1;					///last received state of the Diag_Vreg1 register 
	Diag_Vreg2_Rx_32B_tag							Diag_Vreg2;					///last received state of the Diag_Vreg2 register 
	Diag_Vreg3_Rx_32B_tag							Diag_Vreg3;					///last received state of the Diag_Vreg3 register 
	Diag_CAN_Rx_32B_tag								Diag_CAN;						///last received state of the Diag_CAN register 
	Diag_CAN_LIN_Rx_32B_tag						Diag_CAN_LIN;				///last received state of the Diag_CAN_LIN register 
	Diag_SPI_Rx_32B_tag								Diag_SPI;						///last received state of the Diag_SPI register 
	MODE_Rx_32B_tag										MODE;								///last received state of the MODE register 
	Vreg_mode_Rx_32B_tag							Vreg_mode;					///last received state of the Vreg_mode register 
	IO_OUT_AMUX_32B_tag								IO_OUT_AMUX;				///last received state of the IO_OUT_AMUX register 
	CAN_LIN_mode_Rx_32B_tag						CAN_LIN_mode;				///last received state of the CAN_LIN_mode register 
	Vreg_LPON_Rx_32B_tag							Vreg_LPON;					///last received state of the Vreg_LPON register 
	INIT_Supervisor1_Rx_32B_tag				INIT_Supervisor1;		///last received state of the INIT_Supervisor1 register 
	INIT_Supervisor2_Rx_32B_tag				INIT_Supervisor2;		///last received state of the INIT_Supervisor2 register 
	INIT_Supervisor3_Rx_32B_tag				INIT_Supervisor3;		///last received state of the INIT_Supervisor3 register 
	INIT_FSSM1_Rx_32B_tag							INIT_FSSM1;					///last received state of the INIT_FSSM1 register 
	INIT_FSSM2_Rx_32B_tag							INIT_FSSM2;					///last received state of the INIT_FSSM2 register 
	WD_window_Rx_32B_tag							WD_window;					///last received state of the WD_window register 
	WD_LFSR_Rx_32B_tag								WD_LFSR;						///last received state of the WD_LFSR register 
	WD_answer_Rx_32B_tag							WD_answer;					///last received state of the WD_answer register 
	Diag_FS1_Rx_32B_tag								Diag_FS1;						///last received state of the Diag_FS1 register 
	WD_counter_Rx_32B_tag							WD_counter;					///last received state of the WD_counter register 
	Diag_FS2_Rx_32B_tag								Diag_FS2;						///last received state of the Diag_FS2 register
}INTstruct;

extern struct{
	INIT_Vreg1_32B_tag								INIT_Vreg1;					///last received state of the INIT_Vreg1 register 
	INIT_Vreg2_32B_tag								INIT_Vreg2;					///last received state of the INIT_Vreg2 register 
	INIT_CAN_LIN_32B_tag							INIT_CAN_LIN;				///last received state of the INIT_CAN_LIN register 
	INIT_IO_WU1_32B_tag								INIT_IO_WU1;				///last received state of the INIT_IO_WU1 register 
	INIT_IO_WU2_32B_tag								INIT_IO_WU2;				///last received state of the INIT_IO_WU2 register 
	INIT_INT_32B_tag									INIT_INT;				///last received state of the INIT_INT register 
	HW_Config_Rx_32B_tag							HW_Config;					///last received state of the HW_Config register 
	WU_source_Rx_32B_tag							WU_source;					///last received state of the WU_source register 
	IO_input_state_Rx_32B_tag					IO_input_state;			///last received state of the IO_input_state register 
	Status_Vreg1_Rx_32B_tag						Status_Vreg1;				///last received state of the Status_32B_tag_Vreg1 register 
	Status_Vreg2_Rx_32B_tag						Status_Vreg2;				///last received state of the Status_32B_tag_Vreg2 register 
	Diag_Vreg1_Rx_32B_tag							Diag_Vreg1;					///last received state of the Diag_Vreg1 register 
	Diag_Vreg2_Rx_32B_tag							Diag_Vreg2;					///last received state of the Diag_Vreg2 register 
	Diag_Vreg3_Rx_32B_tag							Diag_Vreg3;					///last received state of the Diag_Vreg3 register 
	Diag_CAN_Rx_32B_tag								Diag_CAN;						///last received state of the Diag_CAN register 
	Diag_CAN_LIN_Rx_32B_tag						Diag_CAN_LIN;				///last received state of the Diag_CAN_LIN register 
	Diag_SPI_Rx_32B_tag								Diag_SPI;						///last received state of the Diag_SPI register 
	MODE_Rx_32B_tag										MODE;								///last received state of the MODE register 
	Vreg_mode_Rx_32B_tag							Vreg_mode;					///last received state of the Vreg_mode register 
	IO_OUT_AMUX_32B_tag								IO_OUT_AMUX;				///last received state of the IO_OUT_AMUX register 
	CAN_LIN_mode_Rx_32B_tag						CAN_LIN_mode;				///last received state of the CAN_LIN_mode register 
	Vreg_LPON_Rx_32B_tag							Vreg_LPON;					///last received state of the Vreg_LPON register 
	INIT_Supervisor1_Rx_32B_tag				INIT_Supervisor1;		///last received state of the INIT_Supervisor1 register 
	INIT_Supervisor2_Rx_32B_tag				INIT_Supervisor2;		///last received state of the INIT_Supervisor2 register 
	INIT_Supervisor3_Rx_32B_tag				INIT_Supervisor3;		///last received state of the INIT_Supervisor3 register 
	INIT_FSSM1_Rx_32B_tag							INIT_FSSM1;					///last received state of the INIT_FSSM1 register 
	INIT_FSSM2_Rx_32B_tag							INIT_FSSM2;					///last received state of the INIT_FSSM2 register 
	WD_window_Rx_32B_tag							WD_window;					///last received state of the WD_window register 
	WD_LFSR_Rx_32B_tag								WD_LFSR;						///last received state of the WD_LFSR register 
	WD_answer_Rx_32B_tag							WD_answer;					///last received state of the WD_answer register 
	Diag_FS1_Rx_32B_tag								Diag_FS1;						///last received state of the Diag_FS1 register 
	WD_counter_Rx_32B_tag							WD_counter;					///last received state of the WD_counter register 
	Diag_FS2_Rx_32B_tag								Diag_FS2;						///last received state of the Diag_FS2 register
}INTstructPrevious;


//*************GUI variables*********************
extern struct{
	INIT_Vreg1_32B_tag								INIT_Vreg1;					///init configuration of the INIT_Vreg1 register 
	INIT_Vreg2_32B_tag								INIT_Vreg2;					///init configuration of the INIT_Vreg2 register 
	INIT_CAN_LIN_32B_tag							INIT_CAN_LIN;				///init configuration of the INIT_CAN_LIN register 
	INIT_IO_WU1_32B_tag								INIT_IO_WU1;				///init configuration of the INIT_IO_WU1 register 
	INIT_IO_WU2_32B_tag								INIT_IO_WU2;				///init configuration of the INIT_IO_WU2 register 
	INIT_INT_32B_tag								INIT_INT;					///init configuration of the INIT_INT register 
	INIT_Supervisor1_Rx_32B_tag						INIT_Supervisor1;			///init configuration of the INIT_Supervisor1 register 
	INIT_Supervisor2_Rx_32B_tag						INIT_Supervisor2;			///init configuration of the INIT_Supervisor2 register 
	INIT_Supervisor3_Rx_32B_tag						INIT_Supervisor3;			///init configuration of the INIT_Supervisor3 register 
	INIT_FSSM1_Rx_32B_tag							INIT_FSSM1;					///init configuration of the INIT_FSSM1 register 
	INIT_FSSM2_Rx_32B_tag							INIT_FSSM2;					///init configuration of the INIT_FSSM2 register 
	WD_window_Tx_32B_tag							WD_window;					///init configuration of the WD_window register 
	WD_LFSR_Tx_32B_tag								WD_LFSR;					///init configuration of the WD_LFSR register 
}INITstruct;

//extern struct {
//	uint8_t WDwinChangeRequest;
//	uint8_t WDwinDisabled;
 	//uint8_t RSTcounterStartup;	
 	//uint8_t PwSBCconfigLoaded;
 	//uint8_t GUIdetected;
 	//uint8_t SendFrames;
 	//uint8_t WDwinNb;
	//float 	WDwinPeriod;	
	//uint8_t SendFramesOnce;
//}GUIstruct;

//*************GUI end***************************

#endif