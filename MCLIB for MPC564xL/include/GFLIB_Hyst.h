/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Hyst.h
*
* @version  1.0.10.0
*
* @date     May-5-2011
*
* @brief    Header file for #GFLIB_Hyst function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_HYST_H
#define _GFLIB_HYST_H

#ifndef  _MATLAB_BAM_CREATE
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
/*! Function alias for the #GFLIB_HystANSIC function.*/
#define GFLIB_Hyst(s32In, pParam) GFLIB_HystANSIC(s32In, pParam)

/*! Macro containing default values of the hysteresis function structure.*/
#define GFLIB_HYST_DEFAULT   {0,0,0,0,0}

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_HYST_T "\GFLIB_Hyst.h"

@brief      Structure containing parameters and states for the hysteresis function
            implemented in #GFLIB_Hyst.

@details
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGFLIB00175 */
typedef struct {
  /** @remarks Implements DGFLIB00230 */ 
  /*! @cond MPC564xL Value determining the upper threshold. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32HystOn;
  /** @remarks Implements DGFLIB00231 */
  /*! @cond MPC564xL Value determining the lower threshold. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32HystOff;
  /** @remarks Implements DGFLIB00232 */
  /*! @cond MPC564xL Value of the output when input is higher than the upper threshold. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32OutValOn;
  /** @remarks Implements DGFLIB00233 */
  /*! @cond MPC564xL Value of the output when input is the lower than the lower threshold. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32OutValOff;
  /** @remarks Implements DGFLIB00234 */  
  /*! @cond MPC564xL Actual state of the output. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32OutState;
}GFLIB_HYST_T;

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*!
* @ingroup GFLIB_GROUP
*/
extern tMclib GFLIB_HystANSIC(tMclib s32In, GFLIB_HYST_T *pParam);

/******************************************************************************
* Inline functions
******************************************************************************/

#endif /* _GFLIB_HYST_H */

/* End of file */

