/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GMCLIB_ElimDcBusRip.h
*
* @version  1.0.8.0
*
* @date     May-5-2011
*
* @brief    Header file for #GMCLIB_ElimDcBusRip function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GMCLIB_ELIMDCBUSRIP_H
#define _GMCLIB_ELIMDCBUSRIP_H

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
 * \def GMCLIB_ElimDcBusRip
 * Function alias for the #GMCLIB_ElimDcBusRipANSIC function.
 */
#define GMCLIB_ElimDcBusRip(pOut, pIn, pParams) GMCLIB_ElimDcBusRipANSIC(pOut, pIn, pParams)

/*! Macro containing default values for the parameter structure of the #GMCLIB_ElimDcBusRip
 * function.*/
#define GMCLIB_ELIMDCBUSRIP_DEFAULT   {0,0}

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/*------------------------------------------------------------------------*//*!
@struct GMCLIB_ELIMDCBUSRIP_T "\GMCLIB_ElimDcBusRip.h"

@brief  Structure containing the PWM modulation index and the measured value of
        the DC bus voltage for calculation of the DC bus ripple elimination.

*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGMCLIB00049 */
typedef struct {
  /** @remarks Implements DGMCLIB00064 */
  /*! @cond MPC564xL Inverse Modulation Index. The parameter is in full range single precision floating point format. The modulation index must be equal to or greater than 0. @endcond */
  tMclib s32ModIndex;
  /** @remarks Implements DGMCLIB00065 */
  /*! @cond MPC564xL Measured DC bus voltage. The parameter is in full range single precision floating point format. The measured voltage must be positive and equal to or greater than 0. @endcond */
  tMclib s32ArgDcBusMsr;
} GMCLIB_ELIMDCBUSRIP_T;

/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/

/******************************************************************************
* Exported Variables
******************************************************************************/
/*!
* @ingroup GMCLIB_GROUP
*/
extern void GMCLIB_ElimDcBusRipANSIC(SWLIBS_2Syst *pOut,
                                     const SWLIBS_2Syst *const pIn,
                                     const GMCLIB_ELIMDCBUSRIP_T *const pParam);

/******************************************************************************
* Exported function prototypes
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _GMCLIB_ELIMDCBUSRIP_H */

