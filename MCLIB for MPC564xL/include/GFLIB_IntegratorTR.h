/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_IntegratorTR.h
*
* @version  1.0.8.0
*
* @date     Aug-15-2011
*
* @brief    Header file for #GFLIB_IntegratorTR function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GFLIB_INTEGRATOR_TR_H
#define _GFLIB_INTEGRATOR_TR_H

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
/*! Function alias for the #GFLIB_IntegratorTRANSIC function.*/
#define GFLIB_IntegratorTR(in, pParam)  GFLIB_IntegratorTRANSIC(in, pParam)

/*! Macro containing default values of the integrator structure.*/
#define GFLIB_INTEGRATOR_TR_DEFAULT   {0,0,0}

/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_INTEGRATOR_TR_T "\GFLIB_IntegratorTR.h"

@brief  Structure containing integrator parameters and coefficients.
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGFLIB00184 */
typedef struct
{
/*! integrator state value, single precision floating point format */
    tFloat s32State;
/*! input value in step k-1, single precision floating point format */           
    tFloat s32InK1;
/*! integrator coefficient, single precision floating point format */           
    tFloat s32C1;
}GFLIB_INTEGRATOR_TR_T;

/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/

/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/
/*! 
* @ingroup GFLIB_GROUP 
*/

extern tMclib GFLIB_IntegratorTRANSIC(tMclib s32In, GFLIB_INTEGRATOR_TR_T *pParam);

/******************************************************************************
| Inline functions
-----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* _GFLIB_INTEGRATOR_TR_H */
