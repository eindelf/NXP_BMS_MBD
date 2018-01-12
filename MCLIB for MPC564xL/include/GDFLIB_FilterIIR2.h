/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GDFLIB_FilterIIR2.h
*
* @version  1.0.6.0
*
* @date     May-6-2011
*
* @brief    Header file for #GDFLIB_FilterIIR2 function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GDFLIB_FILTER_IIR2_H
#define _GDFLIB_FILTER_IIR2_H

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
/*! Function alias for the #GDFLIB_FilterIIR2InitANSIC function.*/
#define GDFLIB_FilterIIR2Init(pParam) \
        GDFLIB_FilterIIR2InitANSIC(pParam)

/*! Function alias for the #GDFLIB_FilterIIR2ANSIC function.*/
#define GDFLIB_FilterIIR2(s32In,pParam)\
        GDFLIB_FilterIIR2ANSIC(s32In,pParam)

/*! Macro containing default values of the second order IIR filter structure.*/
#define GDFLIB_FILTER_IIR2_DEFAULT   {{0,0,0,0,0},{0,0},{0,0}}

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!
@struct FILTER_IIR2_COEFF_T "\GDFLIB_FilterIIR2.h"

@brief  Sub-structure containing filter coefficients.
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGDFLIB00025 */
typedef struct {
  /** @remarks Implements DGDFLIB00073 */
  /*! @cond MPC564xL B0 coefficient of an IIR2 filter. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32B0;
  /** @remarks Implements DGDFLIB00074 */
  /*! @cond MPC564xL B1 coefficient of an IIR2 filter. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32B1;
  /** @remarks Implements DGDFLIB00075 */
  /*! @cond MPC564xL B2 coefficient of an IIR2 filter. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32B2;
  /** @remarks Implements DGDFLIB00076 */
  /*! @cond MPC564xL A1 coefficient of an IIR2 filter. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32A1;
  /** @remarks Implements DGDFLIB00077 */
  /*! @cond MPC564xL A2 coefficient of an IIR2 filter. The parameter is in full range single precision floating point format. @endcond */
  tMclib s32A2;
}FILTER_IIR2_COEFF_T;

/*------------------------------------------------------------------------*//*!
@struct GDFLIB_FILTER_IIR2_T "\GDFLIB_FilterIIR2.h"

@brief  Structure containing filter buffer and coefficients.
*//*-------------------------------------------------------------------------*/
typedef struct {
  /** @remarks Implements DGDFLIB00026 */
  /*! @cond MPC564xL Filter coefficients substructure. @endcond */
  FILTER_IIR2_COEFF_T trFiltCoeff;
  /** @remarks Implements DGDFLIB00078 */
  /*! @cond MPC564xL Input buffer of an IIR2 filter. The input values are in full range single precision floating point format. @endcond */
  tMclib s32FiltBufferX[3];
  /** @remarks Implements DGDFLIB00079 */
  /*! @cond MPC564xL Internal accumulator buffer. The values are in full range single precision floating point format. @endcond */
  tMclib s32FiltBufferY[3];
}GDFLIB_FILTER_IIR2_T;

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GDFLIB_GROUP 
*/

/* Prototype of function for clearing buffers of IIR2 filter.*/
extern void GDFLIB_FilterIIR2InitANSIC(GDFLIB_FILTER_IIR2_T *pParam);

/* Prototype of direct form II second order IIR filter.*/
extern tMclib GDFLIB_FilterIIR2ANSIC(tMclib s32InErr, \
                                      GDFLIB_FILTER_IIR2_T *pParam);

/******************************************************************************
* Inline functions
******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _GDFLIB_FILTER_IIR2_H */

/* End of file */

