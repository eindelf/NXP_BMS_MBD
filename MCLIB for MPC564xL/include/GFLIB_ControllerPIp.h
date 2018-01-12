/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_ControllerPIp.h
*
* @version  1.0.9.0
*
* @date     Aug-15-2011
*
* @brief    Header file for #GFLIB_ControllerPIp function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_CONTROLLER_PIP_H
#define _GFLIB_CONTROLLER_PIP_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef  _MATLAB_BAM_CREATE
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Inlines.h"
#include "SWLIBS_Defines.h"
#endif

/******************************************************************************
| Defines and macros            (scope: module-local)
-----------------------------------------------------------------------------*/
/*! Function alias for the #GFLIB_ControllerPIpANSIC function.*/
#define GFLIB_ControllerPIp(s32InErr,pParam) GFLIB_ControllerPIpANSIC(s32InErr, pParam)

/*! Macro containing default values of the parallel PI controller structure.*/
#define GFLIB_CONTROLLER_PI_P_DEFAULT   {0,0,0,0}
 

/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_CONTROLLER_PI_P_T "\GFLIB_ControllerPIp.h"

@brief  Structure containing parameters and states of the the parallel form PI controller.
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGFLIB00065 */
typedef struct {
/** @remarks Implements DGFLIB00218 */
/*! Proportional Gain, single precision floating point format */
  tFloat    s32PropGain;        
/** @remarks Implements DGFLIB00219 */
/*! Integral Gain, single precision floating point format */
  tFloat    s32IntegGain;       
/** @remarks Implements DGFLIB00220 */
/*! State variable integral part at step k-1, single precision floating point format */
  tFloat    s32IntegPartK_1;    
/** @remarks Implements DGFLIB00066 */
/*! State variable input error at step k-1, single precision floating point format */
  tFloat    s32InK_1;           
} GFLIB_CONTROLLER_PI_P_T;
 

/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/

/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/
/*!
* @ingroup GFLIB_GROUP
*/

extern tMclib GFLIB_ControllerPIpANSIC(tMclib s32InErr,
                                        GFLIB_CONTROLLER_PI_P_T *pParam);

/******************************************************************************
| Inline functions
-----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* _GFLIB_CONTROLLER_PIP_H */

/* End of file */
