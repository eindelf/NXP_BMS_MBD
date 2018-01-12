/******************************************************************************
*
* (c) Copyright 2010, Freescale
*
***************************************************************************//*!
*
* @file     GFLIB_Atan.h
* 
* @version  1.0.11.0
* 
* @date     Aug-15-2011
* 
* @brief    Header file for #GFLIB_Atan function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef GFLIB_ATAN_H_
#define GFLIB_ATAN_H_

//#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
//#endif
/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
/*!
  \def GFLIB_Atan
  Function alias.
*/
#define GFLIB_Atan(x) GFLIB_AtanANSIC((x), &gflibAtanCoef)

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/*------------------------------------------------------------------------*//*!
*//*-------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*//*!

@cond MPC564xL
@struct GFLIB_ATAN_TAYLOR_T "\GFLIB_Atan.h"

@brief      Structure containing the approximation coefficients.

@details    The approximation uses the rational polynomial approximation which is 
            based on the division of two rational polynomials. The essential assumption 
            of this approach is the fast calculation of a two floating point values division.
            The approximation polynomial coefficients assume the input argument in the interval
            \f$ \left(-2^{128}, 2^{128} \right) \f$. 
            \par            
            
            By calling the function alias #GFLIB_Atan, default values of the
            coefficients are used. Approximation coefficients can be modified by
            the user and in such a case the full function call shall be used, i.e.
            #GFLIB_AtanANSIC
@endcond             
*//*-------------------------------------------------------------------------*/
typedef struct{
    const tFloat  s32a[6];     /*!< Array of coeficients for polynomial approximation */
} GFLIB_ATAN_TAYLOR_T;


/******************************************************************************
* Exported Variables
******************************************************************************/

extern const GFLIB_ATAN_TAYLOR_T gflibAtanCoef;

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GFLIB_GROUP 
*/ 
extern tMclib GFLIB_AtanANSIC(tMclib s32In, const GFLIB_ATAN_TAYLOR_T *const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/ 

#endif /*GFLIB_ATAN_H_*/
