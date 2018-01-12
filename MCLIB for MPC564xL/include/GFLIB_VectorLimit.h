/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file      GFLIB_VectorLimit.h
* 
* @version   1.0.6.0
* 
* @date      May-5-2011
* 
* @brief     Header file for the Vector-Limit function.
*
*******************************************************************************
*
* Function impemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_VECTORLIMIT_H_
#define _GFLIB_VECTORLIMIT_H_

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
 * \def GFLIB_VectorLimit(s32In, s32Out, pParam)
 * Function alias for the #GFLIB_VectorLimitANSIC function.
 */

#define GFLIB_VectorLimit(s32Out, s32In, pParam) \
            GFLIB_VectorLimitANSIC((s32Out), (s32In), (pParam))
                            

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/*------------------------------------------------------------------------*//*!
@struct     GFLIB_VECTORLIMIT_T "\GFLIB_VectorLimit.h"

@brief      Structure containing the limits.

*//*-------------------------------------------------------------------------*/

typedef struct {
  /** @remarks Implements DGFLIB00245 */
  /*! @cond MPC564xL The maximum magnitude of the input vector. The parameter is in full range single precision floating point format. The defined magnitude must be positive and equal to or greater than 0. @endcond */
  tMclib s32Lim;
} GFLIB_VECTORLIMIT_T;

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GFLIB_GROUP 
*/

extern tBool GFLIB_VectorLimitANSIC(SWLIBS_2Syst *const pOut,
                                    const SWLIBS_2Syst *const pIn,
                                    const GFLIB_VECTORLIMIT_T *const pParam);

#ifdef __cplusplus
}
#endif

#endif /* _GFLIB_VECTORLIMIT_H_ */

/* End of file */
