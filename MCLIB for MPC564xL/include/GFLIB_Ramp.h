/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Ramp.h
*
* @version  1.0.7.0
*
* @date     May-5-2011
*
* @brief    Header file for #GFLIB_Ramp function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GFLIB_RAMP_H
#define _GFLIB_RAMP_H

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
/*! Function alias for the #GFLIB_RampANSIC function.*/
#define GFLIB_Ramp(in, pParam)  GFLIB_RampANSIC(in, pParam)

/*! Macro containing default values of the Ramp structure.*/
#define GFLIB_RAMP_DEFAULT   {0,0,0}

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_RAMP_T "\GFLIB_Ramp.h"

@brief      Structure containing increment/decrement coefficients and state value 
            for the ramp function implemented in #GFLIB_Ramp.

@details
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGFLIB00193 */
typedef struct {
  /** @remarks Implements DGFLIB00241 */
  /*! @cond MPC564xL Ramp state value. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32State;
  /** @remarks Implements DGFLIB00242 */
  /*! @cond MPC564xL Ramp up increment coefficient. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32RampUp;
  /** @remarks Implements DGFLIB00243 */
  /*! @cond MPC564xL Ramp down increment (decrement) coefficient. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32RampDown;
}GFLIB_RAMP_T;

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GFLIB_GROUP 
*/

extern tMclib GFLIB_RampANSIC(tMclib s32In, GFLIB_RAMP_T *pParam);

/******************************************************************************
* Inline functions
******************************************************************************/ 

#ifdef __cplusplus
}
#endif

#endif /* _GFLIB_RAMP_H */

/* End of file */
