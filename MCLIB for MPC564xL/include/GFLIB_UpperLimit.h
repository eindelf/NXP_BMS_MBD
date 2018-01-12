/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file      GFLIB_UpperLimit.h
* 
* @version   1.0.6.0
* 
* @date      May-5-2011
* 
* @brief     Header file for the Upper-Limit function
*
*******************************************************************************
*
* Function impemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_UPPERLIMIT_H_
#define _GFLIB_UPPERLIMIT_H_

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

/*! Function alias for the #GFLIB_UpperLimitANSIC function.*/
#define GFLIB_UpperLimit(s32In, pParam) GFLIB_UpperLimitANSIC((s32In),(pParam))

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/*------------------------------------------------------------------------*//*!
@struct		GFLIB_UPPERLIMIT_T "\GFLIB_UpperLimit.h"

@brief		Structure containing the upper limit.

@details
*//*-------------------------------------------------------------------------*/

typedef struct {    
  /** @remarks Implements DGFLIB00244 */
  /*! @cond MPC564xL Value determining the upper limit threshold. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32UpperLimit;
} GFLIB_UPPERLIMIT_T;

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GFLIB_GROUP 
*/
extern tMclib GFLIB_UpperLimitANSIC (tMclib s32In,
                                     const GFLIB_UPPERLIMIT_T *const pParam);
#ifdef __cplusplus
}
#endif
#endif /* _GFLIB_UPPERLIMIT_H_ */

/* End of file */
