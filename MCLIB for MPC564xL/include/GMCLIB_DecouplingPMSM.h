/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GMCLIB_DecouplingPMSM.h
*
* @version  1.0.8.0
*
* @date     May-5-2011
*
* @brief    Header file for #GMCLIB_DecouplingPMSM function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GMCLIB_DECOUPLINGPMSM_H
#define _GMCLIB_DECOUPLINGPMSM_H

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
/*! Function alias for the #GMCLIB_DecouplingPMSMANSIC function.*/
#define GMCLIB_DecouplingPMSM(pUdqDec,pUdq,pIdq,s32AngularVel,pParam)\
        GMCLIB_DecouplingPMSMANSIC(pUdqDec,pUdq,pIdq,s32AngularVel,pParam)

/*! Macro containing reset values of the parameters for the decoupling algorithm implemented
 * in the #GMCLIB_DecouplingPMSM function.*/
#define GMCLIB_DECOUPLINGPMSM_DEFAULT   {0,0,0,0}

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!
@struct GMCLIB_DECOUPLINGPMSM_T "\GMCLIB_DecouplingPMSM.h"

@brief  Structure containing coefficients for calculation of the decoupling algorithm
        implemented in the #GMCLIB_DecouplingPMSM function.
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGMCLIB00059 */
typedef struct {
  /** @remarks Implements DGMCLIB00062 */
  /*! \f$L_{D}\f$ inductance [H]. The parameter is in full range single precision floating point format. */
  tFloat s32LD;
  /** @remarks Implements DGMCLIB00063 */
  /*! \f$L_{Q}\f$ inductance [H]. The parameter is in full range single precision floating point format. */
  tFloat s32LQ;
}GMCLIB_DECOUPLINGPMSM_T;
 

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GMCLIB_GROUP 
*/ 
extern void GMCLIB_DecouplingPMSMANSIC(SWLIBS_2Syst *pUdqDec,
                                       const SWLIBS_2Syst *const pUdq,
                                       const SWLIBS_2Syst *const pIdq,
                                       tMclib s32AngularVel,
                                       const GMCLIB_DECOUPLINGPMSM_T *const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/ 

#ifdef __cplusplus
}
#endif

#endif /* _GMCLIB_DECOUPLINGPMSM_H */

/* End of file */
