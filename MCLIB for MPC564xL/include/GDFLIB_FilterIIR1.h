/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GDFLIB_FilterIIR1.h
*
* @version  1.0.6.0
*
* @date     May-6-2011
*
* @brief    Header file for #GDFLIB_FilterIIR1 function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GDFLIB_FILTER_IIR1_H
#define _GDFLIB_FILTER_IIR1_H

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
/*! Function alias for the #GDFLIB_FilterIIR1InitANSIC function.*/
#define GDFLIB_FilterIIR1Init(pParam) \
        GDFLIB_FilterIIR1InitANSIC(pParam)

/*! Function alias for the #GDFLIB_FilterIIR1ANSIC function.*/
#define GDFLIB_FilterIIR1(s32In,pParam)\
        GDFLIB_FilterIIR1ANSIC(s32In,pParam)

/*! Macro containing default values of the first order IIR filter structure.*/
#define GDFLIB_FILTER_IIR1_DEFAULT   {{0,0,0},{0},{0}}

/******************************************************************************
| Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!
@struct FILTER_IIR1_COEFF_T "\GDFLIB_FilterIIR1.h"

@brief  Sub-structure containing filter coefficients.
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGDFLIB00008 */
typedef struct {
  /** @remarks Implements DGDFLIB00068 */
  /*! @cond MPC564xL B0 coefficient of an IIR1 filter. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32B0;
  /** @remarks Implements DGDFLIB00069 */
  /*! @cond MPC564xL B1 coefficient of an IIR1 filter. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32B1;
  /** @remarks Implements DGDFLIB00070 */
  /*! @cond MPC564xL A1 coefficient of an IIR1 filter. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32A1;
}FILTER_IIR1_COEFF_T;

/*------------------------------------------------------------------------*//*!
@struct GDFLIB_FILTER_IIR1_T "\GDFLIB_FilterIIR1.h"

@brief  Structure containing filter buffer and coefficients.
*//*-------------------------------------------------------------------------*/
typedef struct {
  /** @remarks Implements DGDFLIB00009 */
  /*! @cond MPC564xL Filter coefficients substructure. @endcond */
  FILTER_IIR1_COEFF_T trFiltCoeff;
  /** @remarks Implements DGDFLIB00071 */
  /*! @cond MPC564xL Input buffer of an IIR1 filter. The input values are in full range single precision floating point format. @endcond */
  tMclib s32FiltBufferX[2];
  /** @remarks Implements DGDFLIB00072 */
  /*! @cond MPC564xL Internal accumulator buffer. The values are in full range single precision floating point format. @endcond */
  tMclib s32FiltBufferY[2];
}GDFLIB_FILTER_IIR1_T;

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GDFLIB_GROUP 
*/

/* Prototype of function for clearing buffers of IIR1 filter */
extern void GDFLIB_FilterIIR1InitANSIC(GDFLIB_FILTER_IIR1_T *pParam);

/* Prototype of direct form II first order IIR filter */
extern tMclib GDFLIB_FilterIIR1ANSIC(tMclib s32InErr, \
                                      GDFLIB_FILTER_IIR1_T *pParam);

/******************************************************************************
* Inline functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _GDFLIB_FILTER_IIR1_H */

/* End of file */

