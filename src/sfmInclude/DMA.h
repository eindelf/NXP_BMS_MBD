/*******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2006-2012 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
********************************************************************************
*
* $File Name:       DSPI.h$
* @file             DSPI.h
*
* $Date:            Mar-01-2012$
* @date             Mar-01-2012
*
* $Version:         1.0$
* @version          1.0
*
* Description      DSPI driver header file
* @brief            DSPI driver header file
*
* --------------------------------------------------------------------
* $Name:  $
*******************************************************************************/
/****************************************************************************//*!
*
*  @mainpage DSPI driver for MPC5643L
*
*  @section Intro Introduction
*
*	This package contains DSPI driver for MPC5643L allowing to 
*	initialize/configure DSPI module and process SPI communication.
*
*  The key features of this package are the following:
*  - Initialize DSPI module with the desired parameters
*  - Configure DSPI parameters
*  - Process SPI communication (reading/writing)
*  For more information about the functions and configuration items see these documents: 
*
*******************************************************************************
*
* @attention 
*            
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

#ifndef _DMA_H_
#define _DMA_H_


//#include "DEFINES.h"
#include "target.h"

/*==================================================================================================
*   Configurable parameters
*	User shall change configuration in this section regarding needs of the application.
==================================================================================================*/

/*==================================================================================================
*   NON - configurable parameters
*	User should not modify configuration in this section.
==================================================================================================*/
///DSPI basic defines


/*==================================================================================================
*   Function prototypes
==================================================================================================*/

//void DMA_Init();

void DMA_send_Init();
void DMA0_isr();
void delayDMAms(volatile int);

#endif