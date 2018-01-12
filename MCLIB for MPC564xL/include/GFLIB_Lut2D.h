/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Lut2D.h
*
* @version  1.0.11.0
*
* @date     Aug-15-2011
* 
* @brief    Header file for the #GFLIB_Lut2D function. 
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GFLIB_LUT2D_H
#define _GFLIB_LUT2D_H

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/

/*! Function alias for #GFLIB_Lut2DANSIC function.*/
#define GFLIB_Lut2D(x, y, pParam_xy) GFLIB_Lut2DANSIC((x), (y), (pParam_xy))

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
/*------------------------------------------------------------------------*//*!
@struct GFLIB_LUT2D_T "\GFLIB_Lut2D.h"

@brief  Structure containing 2D look-up table parameters.
*//*-------------------------------------------------------------------------*/
typedef struct {
  /** @remarks Implements DGFLIB00239 */
  /*! X-axis shift amount for extracting fractional offset within an interpolated interval. The value is a 32-bit signed integer number. */
  tS32 s32ShamOffset1;
  /** @remarks Implements DGFLIB00240 */
  /*! Y-axis shift amount for extracting fractional offset within an interpolated interval. The value is a 32-bit signed integer number. */
  tS32 s32ShamOffset2;
  /** @remarks Implements DGFLIB00212 */
  /*! Table holding 2D ordinate values of interpolating intervals. The ordinate values are in full range single precision floating point format. */
  const tFloat *ps32Table;
} GFLIB_LUT2D_T;


/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/

/*! 
* @ingroup GFLIB_GROUP 
*/ 

extern tMclib GFLIB_Lut2DANSIC(tMclib s32In1,
                               tMclib s32In2,
                               const GFLIB_LUT2D_T *const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/

#endif /* _GFLIB_LUT2D_H */

/* End of file */

