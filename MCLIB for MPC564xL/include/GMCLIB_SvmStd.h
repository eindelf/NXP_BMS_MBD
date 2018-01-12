/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GMCLIB_SvmStd.h
*
* @version  1.0.4.0
*
* @date     Feb-18-2011
*
* @brief    Header file for #GMCLIB_SvmStd function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GMCLIB_SVMSTD_H
#define _GMCLIB_SVMSTD_H

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
| Defines and macros            (scope: module-local)
-----------------------------------------------------------------------------*/
/*! Function alias for the #GMCLIB_SvmStdANSIC function.*/
#define GMCLIB_SvmStd(pOutput,pInput)     GMCLIB_SvmStdANSIC(pOutput,pInput)


/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/

/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/
/*! 
* @ingroup GMCLIB_GROUP 
*/ 
extern tU32 GMCLIB_SvmStdANSIC(SWLIBS_3Syst *pOut,const SWLIBS_2Syst *const pIn);

/******************************************************************************
| Inline functions
-----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* _GMCLIB_SVMSTD_H */
