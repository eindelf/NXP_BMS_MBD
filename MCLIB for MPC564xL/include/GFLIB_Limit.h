/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file      GFLIB_Limit.h
*
* @version   1.0.6.0
* 
* @date      May-5-2011
* 
* @brief     Header file for two side limit function.
*
*******************************************************************************
*
* Function impemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_LIMIT_H_
#define _GFLIB_LIMIT_H_

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
 * \def GFLIB_Limit(s32In, pParam)
 * Function alias for the #GFLIB_LimitANSIC function.
 */

#define GFLIB_Limit(s32In, pParam) GFLIB_LimitANSIC((s32In), (pParam))

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/*------------------------------------------------------------------------*//*!
@struct     GFLIB_LIMIT_T "\GFLIB_Limit.h"

@brief      Structure containing the limits.

*//*-------------------------------------------------------------------------*/

typedef struct {
  /** @remarks Implements DGFLIB00235 */
  /*! @cond MPC564xL Value determining the lower limit threshold. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32LowerLimit;
  /** @remarks Implements DGFLIB00236 */
  /*! @cond MPC564xL Value determining the upper limit threshold. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32UpperLimit;
} GFLIB_LIMIT_T;

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/

/*! 
* @ingroup GFLIB_GROUP 
*/ 
extern tMclib GFLIB_LimitANSIC (tMclib s32In,
                                const GFLIB_LIMIT_T *const pParam);

#ifdef __cplusplus
}
#endif

#endif /* _GFLIB_LIMIT_H_ */

/* End of file */
