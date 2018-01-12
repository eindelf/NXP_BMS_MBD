/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    sine_wave_library.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   Sine wave module support.
*    @details Implementation of Sine wave module functions.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		2-Aug-2011
*   Author:                         b13508
* 
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/

#include "sine_wave_library.h"
#include "SWG_frequency.h"
	
/******************************************************************************
*                  Static variables
******************************************************************************/

static double divider = 0;
static uint16_t currentIOFREQ = 0;

/******************************************************************************
*                  Local function prototypes
******************************************************************************/
uint16_t calculateIOFREQ (uint16_t frequency); 

/******************************************************************************
*                  Local functions
******************************************************************************/

uint16_t calculateIOFREQ (uint16_t frequency) 
{
	uint16_t f = (uint16_t)(frequency * divider);
	
	if (f < IOFREQmin)
		f = IOFREQmin;
	if (f > IOFREQmax)
		f = IOFREQmax;

	return f;
}

/******************************************************************************
*                   Global functions
******************************************************************************/
/******************************************************************************
*   Function:  sine_wave_init_564xL
@brief    Sine wave init . 
@details   Sine wave init
    
@param[in]     frequency     frequency
@param[in]     IOAMPL     IOAMPL 
   
@return none
*/
void sine_wave_init_564xL (uint16_t frequency, uint8_t IOAMPL)
{
	divider = (double)0x100000 / sysClk;
	
	SGENDIG.CTRL.B.PDS = 0;
	SGENDIG.CTRL.B.IOAMPL = IOAMPL;
	
	currentIOFREQ = calculateIOFREQ(frequency);
	SGENDIG.CTRL.B.LDOS = 0;
	while (SGENDIG.CTRL.B.LDOS) ;                        /* Ensure that CTRL[LDOS] = 0 */
	SGENDIG.CTRL.B.IOFREQ = currentIOFREQ;
	SGENDIG.CTRL.B.LDOS = 1;
}

/******************************************************************************
*   Function:  sine_wave_update_564xL
@brief    Sine wave update . 
@details   Sine wave update
    
@param[in]     frequency     frequency
   
@return none
*/
void sine_wave_update_564xL (uint16_t frequency)
{
	uint16_t newIOFREQ = calculateIOFREQ(frequency);
	
	if (newIOFREQ != currentIOFREQ) {
		currentIOFREQ = newIOFREQ;
		SGENDIG.CTRL.B.LDOS = 0;
		while (SGENDIG.CTRL.B.LDOS) ;                    /* Ensure that CTRL[LDOS] = 0 */
		SGENDIG.CTRL.B.IOFREQ = currentIOFREQ;
		SGENDIG.CTRL.B.LDOS = 1;
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
