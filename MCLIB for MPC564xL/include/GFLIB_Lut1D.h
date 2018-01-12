/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Lut1D.h
*
* @version  1.0.11.0
*
* @date     Aug-15-2011
* 
* @brief    Header file for the #GFLIB_Lut1D function. 
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GFLIB_LUT1D_H
#define _GFLIB_LUT1D_H

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/

/*! Function alias for the #GFLIB_Lut1DANSIC function.*/
#define GFLIB_Lut1D(x, pParam) GFLIB_Lut1DANSIC((x), (pParam))

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_LUT1D_T "\GFLIB_Lut1D.h"

@brief  Structure containing look-up table parameters.
*//*-------------------------------------------------------------------------*/
typedef struct {
  /** @remarks Implements DGFLIB00238 */
  /*! Shift amount for extracting the fractional offset within an interpolated interval. The value is a 32-bit signed integer number. */
  tS32 s32ShamOffset;
  /** @remarks Implements DGFLIB00132 */
  /*! Table holding ordinate values of interpolating intervals. The ordinate values are in full range single precision floating point format. */
  const tFloat *ps32Table;
} GFLIB_LUT1D_T;


/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/

/*! 
* @ingroup GFLIB_GROUP 
*/ 

extern tMclib GFLIB_Lut1DANSIC(tMclib s32In,
                        const GFLIB_LUT1D_T *const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/

#endif /* _GFLIB_LUT1D_H */

/* End of file */

