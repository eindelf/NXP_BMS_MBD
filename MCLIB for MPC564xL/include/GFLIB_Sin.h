/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Sin.h
*
* @version  1.0.14.0
*
* @date     Aug-15-2011
*
* @brief    Header file for #GFLIB_Sin function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_SIN_H
#define _GFLIB_SIN_H

#ifndef  _MATLAB_BAM_CREATE
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
/*! Function alias for the #GFLIB_SinANSIC function.*/
#define GFLIB_Sin(s32In) GFLIB_SinANSIC(s32In, &gflibSinCoef)

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_SINTLR_T "\GFLIB_Sin.h"

@cond MPC564xL
@brief      Structure containing one array of three single precision floating point
            coefficients for floating point optimized minimax approximation.
@endcond

@details    By calling the function alias #GFLIB_Sin, default values of the coefficients
            are used. Polynomial coefficients can be modified by the user
            and in such a case the full function call shall be used, i.e. #GFLIB_SinANSIC.
*//*-------------------------------------------------------------------------*/
typedef struct
{
    tFloat  s32A[3];  /*!< Array of three single precision floating point elements for storing
                           coefficients of the approximation polynomial. */
}GFLIB_SINTLR_T;


/******************************************************************************
* Exported Variables
******************************************************************************/
extern const GFLIB_SINTLR_T gflibSinCoef;

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*!
* @ingroup GFLIB_GROUP
*/
extern tMclib GFLIB_SinANSIC(tMclib s32In, const GFLIB_SINTLR_T * const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/

#endif /* _GFLIB_SIN_H */
