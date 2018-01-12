/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Asin.h
* 
* @version  1.0.15.0
* 
* @date     Aug-15-2011
* 
* @brief    Header file for #GFLIB_Asin function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef GFLIB_ASIN_H_
#define GFLIB_ASIN_H_

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif
/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
/*!
  \def GFLIB_Asin
  Function alias.
*/
#define GFLIB_Asin(x) GFLIB_AsinANSIC((x), &gflibAsinCoef)

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/*------------------------------------------------------------------------*//*!
*//*-------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*//*!

@cond MPC564xL
@struct GFLIB_ASIN_TAYLOR_T "\GFLIB_Asin.h"

@brief      Structure containing approximation coefficients for calculation of 
            the arcsin function.

@details    The polynomial approximation is done using the square root function of 
            the input parameter. The essential assumption of this approach is a 
            fast H/W based calculation of the square root operation. The approximation
            polynomial coefficients assume an input argument in the
            \f$\left[-pi,pi\right]\f$ interval.

            \par
            By calling the function alias #GFLIB_Asin, default values of the
            coefficients are used. Polynomial coefficients can be modified by
            the user and in such a case the full function call shall be used, i.e.
            #GFLIB_AsinANSIC
@endcond
*//*-------------------------------------------------------------------------*/
typedef struct
{
    tFloat  s32a[8]; /*!< Array of approximation coefficients*/
} GFLIB_ASIN_TAYLOR_T;



/******************************************************************************
* Exported Variables
******************************************************************************/

extern const GFLIB_ASIN_TAYLOR_T gflibAsinCoef;

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GFLIB_GROUP 
*/ 
extern tMclib GFLIB_AsinANSIC(tMclib s32In, const GFLIB_ASIN_TAYLOR_T *const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/ 

#endif /*GFLIB_ASIN_H_*/
