/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    FlexPWM_564xL_library.h
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   Declarations for FlexPWM_library.c  FlexPWM  library file for 564xL.
*    @details Declarations for FlexPWM_library.c  FlexPWM  library file for 564xL.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		7-May-2011
*   Author:                         B13508
* 
*/

#ifndef _FlexPWM_564xL_LIBRARY_H
#define _FlexPWM_564xL_LIBRARY_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                Includes
******************************************************************************/

#include "target.h"
#include "sysclk.h"

/******************************************************************************
*                Definitions
******************************************************************************/
typedef struct {
    uint16_t init; 
	uint16_t val[6];
    uint16_t prescaler;
	uint16_t mask;
} FlexPWMparams_type;

/******************************************************************************
*                   Global function prototypes
******************************************************************************/

/* FlexPWM Channel Pin Configuration Setup */
void pwm_init_pcr_out_564xL(uint8_t pwmMod, uint8_t subMod, uint8_t outAB, uint8_t pcrNum);

/* FlexPWM Init function for completmentary mode */
void pwm_init_564xL_comp(uint8_t pwmMod, uint8_t subMod, uint32_t Freq, uint16_t resolution, uint16_t Duty, uint16_t DeadTime, uint16_t outTrig,
                          uint8_t masterSync, uint8_t pwm45en, uint16_t DutyB, uint16_t OCTRL);

/* FlexPWM Update function for completmentary mode */
void pwm_update_564xL_comp(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t Duty, uint16_t DeadTimeLead,  uint16_t DeadTimeLag);
void pwm_update_564xL_comp2(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint16_t DeadTimeLead,  uint16_t DeadTimeLag);

/* FlexPWM Init function for simple mode */
void pwm_init_564xL_simple(uint8_t pwmMod, uint8_t subMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint8_t centered, uint16_t ShiftA,  
                           uint16_t ShiftB, uint16_t outTrig, uint8_t masterSync, uint8_t doubleSw, uint16_t OCTRL);

/* FlexPWM Update function for simple mode */
void pwm_update_564xL_simple_B_phase_shift(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint16_t ShiftB );
void pwm_update_564xL_simple_centered(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB);
void pwm_update_564xL_simple_edge_align(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB); 
void pwm_update_564xL_simple_phase_shift(uint8_t pwmMod, uint8_t SubMod, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint16_t ShiftA, uint16_t ShiftB);

/* FlexPWM Init function for three phase mode */
void pwm_init_564xL_three_phase(uint8_t pwmMod, uint8_t subModB, uint8_t  subModC, uint32_t Freq, uint16_t resolution, uint16_t DutyA, uint16_t DutyB, uint16_t DutyC,
								uint16_t outTrigA, uint16_t outTrigB, uint16_t outTrigC, uint16_t DeadTime, uint16_t OCTRL_A, uint16_t OCTRL_B, uint16_t OCTRL_C);

/* FlexPWM Update function for three phase mode */
void pwm_update_564xL_three_phase(uint8_t pwmMod, uint8_t subModB, uint8_t  subModC, uint32_t Freq, uint16_t resolution,  
                                  uint16_t DutyA, uint16_t DutyB, uint16_t DutyC, uint16_t DeadTimeLead,  uint16_t DeadTimeLag);

#ifdef __cplusplus
}
#endif

#endif  /*  _FlexPWM_564xL_LIBRARY_H  */

/*
*######################################################################
*                           End of File
*######################################################################
*/


