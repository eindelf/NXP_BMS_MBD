/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_ControllerPIrAW.h
*
* @version  1.0.10.0
*
* @date     Aug-15-2011
*
* @brief    Header file for #GFLIB_ControllerPIrAW function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_CONTROLLER_PIRAW_H
#define _GFLIB_CONTROLLER_PIRAW_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef  _MATLAB_BAM_CREATE
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

/******************************************************************************
| Defines and macros            (scope: module-local)
-----------------------------------------------------------------------------*/
/*! Function alias for the #GFLIB_ControllerPIrAWANSIC function.*/
#define GFLIB_ControllerPIrAW(s32InErr,pParam)\
                            GFLIB_ControllerPIrAWANSIC(s32InErr, pParam)

/*! Macro containing default values of the recurrent form PI controller with anti\--windup.*/
#define GFLIB_CONTROLLER_PIAW_R_DEFAULT   {0,0,0,0,FLOAT_MIN,FLOAT_MAX}


/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_CONTROLLER_PIAW_R_T "\GFLIB_ControllerPIrAW.h"

@brief  Structure containing parameters and states of the recurrent form PI controller
        with anti\--windup
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGFLIB00055 */
typedef struct{
/** @remarks Implements DGFLIB00221 */
/*! CC1 coefficient, single precision floating point format */
    tFloat s32CC1sc;   
/** @remarks Implements DGFLIB00222 */
/*! CC2 coefficient, single precision floating point format */
    tFloat s32CC2sc;   
/** @remarks Implements DGFLIB00223 */
/*! Internal controller accumulator, single precision floating point format */
    tFloat s32Acc;     
/** @remarks Implements DGFLIB00224 */
/*! Controller input from the previous calculation step, single precision floating point format */
    tFloat s32InErrK1; 
/** @remarks Implements DGFLIB00217 */
/*! Upper Limit of the controller, single precision floating point format */
    tFloat s32UpperLimit; 
/** @remarks Implements DGFLIB00056 */
/*! Lower Limit of the controller, single precision floating point format */
    tFloat s32LowerLimit; 
}GFLIB_CONTROLLER_PIAW_R_T;
 

/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/

/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/
/*!
* @ingroup GFLIB_GROUP
*/

extern tMclib GFLIB_ControllerPIrAWANSIC(tMclib s32InErr,
                                          GFLIB_CONTROLLER_PIAW_R_T *pParam);

/******************************************************************************
| Inline functions
-----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* _GFLIB_CONTROLLER_PIRAW_H */
