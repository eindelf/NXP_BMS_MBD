/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file      GFLIB_LowerLimit.h
* 
* @version   1.0.6.0
* 
* @date      May-5-2011
* 
* @brief     Header file for the lower limit function.
*
*******************************************************************************
*
* Function impemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_LOWERLIMIT_H_
#define _GFLIB_LOWERLIMIT_H_

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/

/*! 
 * \def GFLIB_LowerLimit(s32In, pParam)
 * Function alias for the #GFLIB_LowerLimitANSIC function.
 */
#define GFLIB_LowerLimit(s32In, pParam) GFLIB_LowerLimitANSIC((s32In), (pParam))

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/*------------------------------------------------------------------------*//*!
@struct		GFLIB_LOWERLIMIT_T "\GFLIB_LowerLimitANSIC.h"

@brief		Structure containing the lower limit.

*//*-------------------------------------------------------------------------*/

typedef struct {    
  /** @remarks Implements DGFLIB00237 */
  /*! @cond MPC564xL Value determining the lower limit threshold. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32LowerLimit;
} GFLIB_LOWERLIMIT_T;

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/

/*! 
* @ingroup GFLIB_GROUP 
*/
extern tMclib GFLIB_LowerLimitANSIC(tMclib s32In,
                                     const GFLIB_LOWERLIMIT_T *const pParam);

#ifdef __cplusplus
}
#endif
#endif /* _GFLIB_LOWERLIMIT_H_ */

/* End of file */
