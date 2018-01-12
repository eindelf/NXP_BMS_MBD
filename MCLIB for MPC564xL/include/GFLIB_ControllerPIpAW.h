/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_ControllerPIpAW.h
*
* @version  1.0.16.0
*
* @date     Aug-15-2011
*
* @brief    Header file for #GFLIB_ControllerPIpAW function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GFLIB_CONTROLLER_PIPAW_H
#define _GFLIB_CONTROLLER_PIPAW_H

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
    /*! Function alias for the #GFLIB_ControllerPIpAWANSIC function.*/
#define GFLIB_ControllerPIpAW(s32InErr,pParam)\
                    GFLIB_ControllerPIpAWANSIC(s32InErr, pParam)

/*! Macro containing default values for the structure of parameters of
 *  the parallel PI controller with anti-windup.*/
#define GFLIB_CONTROLLER_PIAW_P_DEFAULT   {0,0,FLOAT_MIN,FLOAT_MAX,0,0,0} 


/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_CONTROLLER_PIAW_P_T "\GFLIB_ControllerPIpAW.h"

@brief  Structure containing parameters and states of the parallel form PI controller
        with anti-windup.
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGFLIB00075 */
typedef struct{
/** @remarks Implements DGFLIB00225 */
/*! Proportional Gain, single precision floating point format */
  tFloat    s32PropGain;        
/** @remarks Implements DGFLIB00226 */
/*! Integral Gain, single precision floating point format */
  tFloat    s32IntegGain;       
/** @remarks Implements DGFLIB00227 */
/*! Lower Limit of the controller, single precision floating point format */
  tFloat    s32LowerLimit;      
/** @remarks Implements DGFLIB00228 */
/*! Upper Limit of the controller, single precision floating point format */
  tFloat    s32UpperLimit;      
/** @remarks Implements DGFLIB00229 */
/*! State variable integral part at step k-1, single precision floating point format*/
  tFloat    s32IntegPartK_1;    
/** @remarks Implements DGFLIB00076 */
/*! State variable input error at step k-1, single precision floating point format*/
  tFloat    s32InK_1;
/*! Limitation flag, if set to 1, the controller output has reached either the UpperLimit or LowerLimit*/           
  tU16      u16LimitFlag;       
}GFLIB_CONTROLLER_PIAW_P_T; 
 

/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/

/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/
/*!
* @ingroup GFLIB_GROUP
*/
extern tMclib GFLIB_ControllerPIpAWANSIC(tMclib s32InErr,
                                          GFLIB_CONTROLLER_PIAW_P_T *pParam);

/******************************************************************************
| Inline functions
-----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* _GFLIB_CONTROLLER_PIPAW_H */

/* End of file */
