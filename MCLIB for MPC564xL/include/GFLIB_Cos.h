/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Cos.h
*
* @version  1.0.12.0
*
* @date     Aug-15-2011
*
* @brief    Header file for #GFLIB_Cos function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_COS_H
#define _GFLIB_COS_H

#ifndef  _MATLAB_BAM_CREATE
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif
/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
/*! Function alias for the #GFLIB_CosANSIC function.*/
#define GFLIB_Cos(s32In) GFLIB_CosANSIC(s32In, &gflibCosCoef)

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!

@struct GFLIB_COSTLR_T "\GFLIB_Cos.h"

@cond MPC564xL
@brief      Structure containing one array of three single precision floating point
            coefficients for floating point optimized minimax approximation.
@endcond
            
@details    By calling the function alias #GFLIB_Cos, default values of the coefficients
            are used. Polynomial coefficients can be modified by the user
            and in such a case the full function call shall be used, i.e. #GFLIB_CosANSIC.

*//*-------------------------------------------------------------------------*/
typedef struct
{
    tFloat  s32A[3];  /*!< Array of three single precision floating point elements
                           for storing coefficients of the floating point optimized 
                           minimax approximation polynomial. */
}GFLIB_COSTLR_T;


/******************************************************************************
* Exported Variables
******************************************************************************/
extern const GFLIB_COSTLR_T gflibCosCoef;

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*!
* @ingroup GFLIB_GROUP
*/
extern tMclib GFLIB_CosANSIC(tMclib s32In, const GFLIB_COSTLR_T * const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/

#endif /* _GFLIB_COS_H */
