/******************************************************************************
*
* (c) Copyright 2009, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file      GDFLIB_FilterFIR.h
* 
* @version   1.0.10.0
* 
* @date      Feb-18-2011
* 
* @brief     Header file for the filter FIR function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GDFLIB_FILTERFIR_H_
#define _GDFLIB_FILTERFIR_H_

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
| defines and macros (scope: module-local)
|-----------------------------------------------------------------------*/

/*! Function alias for the #GDFLIB_FilterFIRInitANSIC function.*/
#define GDFLIB_FilterFIRInit(pParam, pState, pInBuf) \
    GDFLIB_FilterFIRInitANSIC((pParam), (pState), (pInBuf))

/*! Function alias for the #GDFLIB_FilterFIRANSIC function.*/
#define GDFLIB_FilterFIR(s32In, pParam, pState) \
    GDFLIB_FilterFIRANSIC((s32In), (pParam), (pState))

/************************************************************************
| typedefs and structures (scope: module-local)
|-----------------------------------------------------------------------*/

/*------------------------------------------------------------------------*//*!
@struct     GDFLIB_FILTERFIR_PARAM_T "\GDFLIB_FilterFIR.h"

@brief      Structure containing parameters of the filter.
*
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGDFLIB00043 */
typedef struct  
{
/*! FIR filter order, must be 1 or more. */    
     tU32    u32Order;      
/** @remarks Implements DGDFLIB00042 */
/*! FIR filter coefficients buffer. */ 
     const tMclib *ps32CoefBuf;  
} GDFLIB_FILTERFIR_PARAM_T;

/*------------------------------------------------------------------------*//*!
@struct     GDFLIB_FILTERFIR_STATE_T "\GDFLIB_FilterFIR.h"

@brief      Structure containing the current state of the filter.
*
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGDFLIB00081 */
typedef struct
{    
/*! Input buffer index. */     
     tU32 u32Idx;          
/** @remarks Implements DGDFLIB00080 */
/*! Pointer to the input buffer. */     
     tMclib *ps32InBuf;    
} GDFLIB_FILTERFIR_STATE_T;

/************************************************************************
| exported variables
|-----------------------------------------------------------------------*/

/************************************************************************
| exported function prototypes
|-----------------------------------------------------------------------*/
/*! 
* @ingroup GDFLIB_GROUP 
*/

void GDFLIB_FilterFIRInitANSIC(const GDFLIB_FILTERFIR_PARAM_T *const pParam,
                               GDFLIB_FILTERFIR_STATE_T *const pState,
                               tMclib *ps32InBuf);

/*! 
* @ingroup GDFLIB_GROUP 
*/
tMclib GDFLIB_FilterFIRANSIC(tMclib s32In,
                             const GDFLIB_FILTERFIR_PARAM_T *const pParam,
                             GDFLIB_FILTERFIR_STATE_T *const pState);

#ifdef __cplusplus
}
#endif
#endif /* _GDFLIB_FILTERFIR_H_ */

/* End of file */
