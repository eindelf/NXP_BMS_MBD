/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file      GMCLIB_ClarkInv.h
*
* @version   1.0.4.0
*
* @date      Nov-16-2010
*
* @brief     Header file for #GMCLIB_ClarkInv transformation algorithm.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GMCLIB_CLARK_INV_H_
#define _GMCLIB_CLARK_INV_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef  _MATLAB_BAM_CREATE
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Inlines.h"
#include "SWLIBS_Defines.h"
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/

/*!
 * \def GMCLIB_ClarkInv
 * Function alias for the #GMCLIB_ClarkInvANSIC function.
 */
#define GMCLIB_ClarkInv(pOut, pIn)    GMCLIB_ClarkInvANSIC(pOut, pIn)

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/

/*!
* @ingroup GMCLIB_GROUP
*/
extern void GMCLIB_ClarkInvANSIC (SWLIBS_3Syst *pOut,
                                  const SWLIBS_2Syst *const pIn);

#ifdef __cplusplus
}
#endif
#endif /* _GMCLIB_CLARK_INV_H_ */

/* End of file */
