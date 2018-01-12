/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Acos.h
* 
* @version  1.0.15.0
* 
* @date     Aug-15-2011
* 
* @brief    Header file for #GFLIB_Acos function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef GFLIB_ACOS_H_
#define GFLIB_ACOS_H_

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif
/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
/*!
  \def GFLIB_Acos
  Function alias.
*/
#define GFLIB_Acos(x) GFLIB_AcosANSIC((x), &gflibAcosCoef)

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/*------------------------------------------------------------------------*//*!
*//*-------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*//*!

@cond MPC564xL
@struct GFLIB_ACOS_TAYLOR_T "\GFLIB_Acos.h"

@brief      Structure containing approximation coefficients for calculation of 
            the arccos function.

@details    The polynomial approximation is done using the square root function of 
            the input parameter. The essential assumption of this approach is 
            a fast H/W based calculation of the square root operation. The approximation
            polynomial coefficients assume an input argument in the
            \f$\left[-\pi,\pi\right]\f$ interval.

            \par
            By calling the function alias #GFLIB_Acos, default values of the
            coefficients are used. Polynomial coefficients can be modified by
            the user and in such a case the full function call shall be used, i.e.
            #GFLIB_AcosANSIC
@endcond
*//*-------------------------------------------------------------------------*/

typedef struct
{
    tFloat  s32a[5]; /*!< Array of appoximation coefficients */
} GFLIB_ACOS_TAYLOR_T;



/******************************************************************************
* Exported Variables
******************************************************************************/

extern const GFLIB_ACOS_TAYLOR_T gflibAcosCoef;

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GFLIB_GROUP 
*/ 
extern tMclib GFLIB_AcosANSIC(tMclib s32In, const GFLIB_ACOS_TAYLOR_T *const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/ 

#endif /*GFLIB_ACOS_H_*/
