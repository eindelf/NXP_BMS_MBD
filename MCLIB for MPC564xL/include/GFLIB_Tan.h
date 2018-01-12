/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Tan.h
*
* @version  1.0.10.0
*
* @date     Aug-15-2011
*
* @brief    Header file for #GFLIB_Tan function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef GFLIB_TAN_H_
#define GFLIB_TAN_H_

#ifndef  _MATLAB_BAM_CREATE
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
/*! Function alias for the #GFLIB_TanANSIC function.*/
#define GFLIB_Tan(s32In) GFLIB_TanANSIC(s32In, &gflibTanCoef)

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!
*//*-------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*//*!

@cond MPC564xL
@struct GFLIB_TANTLR_T "\GFLIB_Tan.h"

@brief      Structure containing four rational polynomial coefficients.

@details    By calling the function alias #GFLIB_Tan, default values of the coefficients
            are used. Approximation coefficients can be modified by the user
            and in such a case the full function call shall be used, i.e. #GFLIB_TanANSIC.
@endcond
*//*-------------------------------------------------------------------------*/
typedef struct
{
    tFloat  s32A[4]; /*!< Polynomial coefficient for fractional approximation in single precision floating point format */
}GFLIB_TANTLR_T;



/******************************************************************************
* Exported Variables
******************************************************************************/
extern const GFLIB_TANTLR_T gflibTanCoef;

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*!
* @ingroup GFLIB_GROUP
*/
extern tMclib GFLIB_TanANSIC(tMclib s32In, const GFLIB_TANTLR_T * const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/

#endif /*GFLIB_TAN_H_*/
