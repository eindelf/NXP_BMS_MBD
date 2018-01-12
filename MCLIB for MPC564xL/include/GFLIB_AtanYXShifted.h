/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_AtanYXShifted.h
* 
* @version  1.0.6.0
* 
* @date     Aug-15-2011
* 
* @brief    Header file for #GFLIB_AtanYXShifted function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef _GFLIB_ATANYXSHIFTED_H_
#define _GFLIB_ATANYXSHIFTED_H_

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif
/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
/*!
  \def GFLIB_AtanYXShifted
  Function alias for the #GFLIB_AtanYXShiftedANSIC function.
*/
#define GFLIB_AtanYXShifted(y, x, p) GFLIB_AtanYXShiftedANSIC((y), (x), (p))

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/*------------------------------------------------------------------------*//*!
@struct		GFLIB_ATANYXSHIFTED_T "\GFLIB_AtanYXShiftedANSIC.h"

@brief		Structure containing the parameter for the AtanYXShifted
            function.

*//*-------------------------------------------------------------------------*/
typedef struct
{    
    tFloat      s32Ky;  /*!<Multiplication coefficient for the y-signal. */
    tFloat      s32Kx;  /*!<Multiplication coefficient for the x-signal. */
    tFloat      s32ThetaAdj; /*!<Adjusting angle. */
    
} GFLIB_ATANYXSHIFTED_T;


/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GFLIB_GROUP 
*/ 
extern tMclib GFLIB_AtanYXShiftedANSIC(tMclib s32InY, tMclib s32InX,
                const GFLIB_ATANYXSHIFTED_T * const pParam);

/******************************************************************************
* Inline functions
******************************************************************************/ 

#endif /* _GFLIB_ATANYXSHIFTED_H_*/
