/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_ControllerPIr.h
*
* @version  1.0.10.0
*
* @date     Aug-15-2011
*
* @brief    Header file for #GFLIB_ControllerPIr function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_CONTROLLER_PIR_H
#define _GFLIB_CONTROLLER_PIR_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef  _MATLAB_BAM_CREATE
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Inlines.h"
#include "SWLIBS_Defines.h"
#endif

/******************************************************************************
| Defines and macros            (scope: module-local)
-----------------------------------------------------------------------------*/
/*! Function alias for the #GFLIB_ControllerPIrANSIC function.*/
#define GFLIB_ControllerPIr(s32InErr,pParam)\
        GFLIB_ControllerPIrANSIC(s32InErr, pParam)

/*! Macro containing default values of the recurrent form PI controller structure.*/
#define GFLIB_CONTROLLER_PI_R_DEFAULT   {0,0,0,0}


/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_CONTROLLER_PI_R_T "\GFLIB_ControllerPIr.h"

@brief  Structure containing parameters and states of the recurrent form PI controller.
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGFLIB00045 */
typedef struct{
/** @remarks Implements DGFLIB00044  *//*! \t*/
    tFloat s32CC1sc;       /*!< CC1 coefficient, single precision floating point format */
/** @remarks Implements DGFLIB00214 *//*! \t*/
    tFloat s32CC2sc;       /*!< CC2 coefficient, single precision floating point format */
/** @remarks Implements DGFLIB00215 *//*! \t*/
    tFloat s32Acc;         /*!< Internal controller accumulator, single precision floating point format */
/** @remarks Implements DGFLIB00216 *//*! \t*/
    tFloat s32InErrK1;     /*!< Controller input from the previous calculation step, single precision floating point format */
}GFLIB_CONTROLLER_PI_R_T;


/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/

/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/
/*!
* @ingroup GFLIB_GROUP
*/

extern tMclib GFLIB_ControllerPIrANSIC(tMclib s32InErr,
                                        GFLIB_CONTROLLER_PI_R_T *pParam);

/******************************************************************************
| Inline functions
-----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* _GFLIB_CONTROLLER_PIR_H */
