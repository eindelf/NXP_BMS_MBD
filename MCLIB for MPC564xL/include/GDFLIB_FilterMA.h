/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GDFLIB_FilterMA.h
*
* @version  1.0.8.0
*
* @date     May-2-2011
*
* @brief    Header file for #GDFLIB_FilterMA function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GDFLIB_FILTER_MA_H
#define _GDFLIB_FILTER_MA_H

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
/*! Function alias for the #GDFLIB_FilterMAInitANSIC function.*/
#define GDFLIB_FilterMAInit(pParam)\
        GDFLIB_FilterMAInitANSIC(pParam)

/*! Function alias for the #GDFLIB_FilterMAANSIC function.*/
#define GDFLIB_FilterMA(s32In, pParam)\
        GDFLIB_FilterMAANSIC(s32In, pParam)

/*! Macro containing default values of the first order MA filter structure.*/
#define GDFLIB_FILTER_MA_DEFAULT   {0,0}

/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//*!
@struct GDFLIB_FILTER_MA_T "\GDFLIB_FilterMA.h"

@brief  Structure containing filter buffer and coefficients.
*//*-------------------------------------------------------------------------*/
/** @remarks Implements DGDFLIB00060 */
typedef struct{
/** @remarks Implements DGDFLIB00059 */
/*! filter accumulator */
    tMclib  s32Acc;
/*! number of samples for averaging, filter sample window [0,31]*/                 
    tU16    u16NSamples;        
}GDFLIB_FILTER_MA_T;

/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/

/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/
// Prototype of function for clearing buffers of MA filter.
extern void GDFLIB_FilterMAInitANSIC(GDFLIB_FILTER_MA_T *pParam);

// Prototype of MA filter.
extern tMclib GDFLIB_FilterMAANSIC(tMclib s32In, \
                                   GDFLIB_FILTER_MA_T *pParam);

/******************************************************************************
| Inline functions
-----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* _GDFLIB_FILTER_MA_H */
