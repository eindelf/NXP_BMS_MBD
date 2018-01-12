/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file      GMCLIB_ParkInv.h
*
* @version   1.0.4.0
*
* @date      Feb-18-2011
*
* @brief     Header file for Inverse Park Transformation algorithm.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GMCLIB_PARK_INV_H_
#define _GMCLIB_PARK_INV_H_

#ifdef __cplusplus
extern "C" {
#endif


#ifndef  _MATLAB_BAM_CREATE
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Inlines.h"
#include "SWLIBS_Defines.h"
#endif

/************************************************************************
| defines and macros (scope: module-local)
|-----------------------------------------------------------------------*/
/*! Function alias for the #GMCLIB_ParkInvANSIC function.*/
#define GMCLIB_ParkInv(pOut, pInAngle, pIn) GMCLIB_ParkInvANSIC(pOut, pInAngle, pIn)

/************************************************************************
| typedefs and structures (scope: module-local)
|-----------------------------------------------------------------------*/

/************************************************************************
| exported function prototypes
|-----------------------------------------------------------------------*/
/*!
* @ingroup GMCLIB_GROUP
*/
extern void GMCLIB_ParkInvANSIC (SWLIBS_2Syst *pOut,
                                 const SWLIBS_2Syst *const pInAngle,
                                 const SWLIBS_2Syst *const pIn);

#ifdef __cplusplus
}
#endif
#endif /* _GMCLIB_PARK_INV_H_ */

/* End of file */
