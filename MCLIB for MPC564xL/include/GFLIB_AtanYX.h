/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_AtanYX.h
*
* @version  1.0.5.0
* 
* @date     Feb-18-2011
* 
* @brief    Header file for #GFLIB_AtanYX function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef GFLIB_ATANYX_H_
#define GFLIB_ATANYX_H_

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif
/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
/*!
  \def GFLIB_AtanYX
  Function alias for the #GFLIB_AtanYXANSIC function.
*/
#define GFLIB_AtanYX(y,x) GFLIB_AtanYXANSIC((y), (x))

/*!
  \def GFLIB_AtanXY
  Function alias for the #GFLIB_AtanYXANSIC function.
*/
#define GFLIB_AtanXY(x, y) GFLIB_AtanYXANSIC((y), (x))

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GFLIB_GROUP 
*/ 
extern tMclib GFLIB_AtanYXANSIC(tMclib s32InY, tMclib s32InX);

/******************************************************************************
* Inline functions
******************************************************************************/ 

#endif /*GFLIB_ATANYX_H_*/
