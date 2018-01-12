/**
*######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
*######################################################################
*
*    @file    gpio_564xl_library.h
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   Declarations for gpio_564xl_library.c file and GPIO Registers.
*    @details Declarations for gpio_564xl_library.c file and GPIO Registers..
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		
*   Author:               b14714
* 
*/

#ifndef _GPIO_564xL_LIBRARY_H
#define _GPIO_564xL_LIBRARY_H

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                Includes
******************************************************************************/
#include "target.h"

#define PCR_INPUT_ENABLE       0x0100U         /*  IBE */
#define PCR_OUTPUT_ENABLE      0x0303U         /* OBE | IBE |  WPE | WPS */


/******************************************************************************
*                   Global function prototypes
******************************************************************************/

/* GPI Read Data function */
uint8_t gpi_pin_read_564xl_fnc(uint8_t pcr_num );

/* GPO Write Data function */
void gpo_pin_update_564xl_fnc(uint8_t pcr_num , uint8_t data);

/* GPI Init Pcr as Input function */
void gpi_init_pcr_in_564xl_fnc( uint8_t pcr_num );

/* GPO Init Pcr as Output function */
void gpo_init_pcr_out_564xl_fnc( uint8_t pcr_num );

#ifdef __cplusplus
}
#endif

#endif /*_GPIO_564xL_LIBRARY_H*/

/*
*######################################################################
*                           End of File
*######################################################################
*/
