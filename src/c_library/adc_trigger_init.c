/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    adc_564xl_library.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   This File contains the utility function used to trigger ADC Sampling.
*    @details  File contains utility function which can trigger Normal &
 *                          Injected Sampling and Abort Normal Sampling. This function are
 *                          never called by RAppID
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		23-May-2011
*   Author:                         B14423
* 
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/
#include "adc_trigger_init.h"

/*********************  Normal Software Trigger Function ************************/
/******************************************************************************
*   Function:  adc_normal_start_fnc
@brief    Normal Software Trigger Function . 
@details   Normal Software Trigger Function
   
@return none
*/

void adc_normal_start_fnc(void)

{
    
        /*ADC 0*/
        ADC_0.MCR.B.NSTART = 1; 
            /* Starts The Normal ADC Conversion */

        /*ADC 1*/
        ADC_1.MCR.B.NSTART = 1; 
            /* Starts The Normal ADC Conversion */

}

/*********************  Injected Software Trigger Function ************************/
/******************************************************************************
*   Function:  adc_injected_start_fnc
@brief    Injected Software Trigger Function . 
@details   Injected Software Trigger Function
   
@return none
*/
void adc_injected_start_fnc(void)
{
        /*ADC 0*/
        ADC_0.MCR.B.JSTART = 1;
            /* Starts The Injected ADC Conversion */
        /*ADC 1*/
        ADC_1.MCR.B.JSTART = 1;
            /* Starts The Injected ADC Conversion */

}

/*********************  Normal Software Conversion  Stop Function ************************/
/******************************************************************************
*   Function:  adc_normal_stop_fnc
@brief    Normal Software Conversion  Stop Function. 
@details   Normal Software Conversion  Stop Function
   
@return none
*/
void adc_normal_stop_fnc(void)
{
        /*ADC 0*/
        ADC_0.MCR.B.ABORT = 1; 
            /*  Stops The Normal ADC Conversion */
        /*ADC 1*/
        ADC_1.MCR.B.ABORT = 1; 
            /*  Stops The Normal ADC Conversion */

}

/*********************  Enter Powedown Mode Function ************************/
/******************************************************************************
*   Function:  adc_enter_powerdownmode_fnc
@brief    Enter Powedown Mode Function. 
@details   Enter Powedown Mode Function
   
@return none
*/
void adc_enter_powerdownmode_fnc(void)
{
        /*ADC 0*/
        ADC_0.MCR.B.NSTART = 1; 
            /*  Enter Power down state */
        /*ADC 1*/
        ADC_1.MCR.B.NSTART = 1; 
            /*  Enter Power down state */

}

/*********************  Exit from Powedown Mode Function ************************/
/******************************************************************************
*   Function:  adc_exit_powerdownmode_fnc
@brief    Exit from Powedown Mode Function. 
@details   Exit from Powedown Mode Function
   
@return none
*/
void adc_exit_powerdownmode_fnc(void)
{
        /*ADC 0*/
        ADC_0.MCR.B.PWDN = 0; 
            /*  Exit Power down state */
        /*ADC 1*/
        ADC_1.MCR.B.PWDN = 0; 
            /*  Exit Power down state */

}

#ifdef __cplusplus
}
#endif

 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

