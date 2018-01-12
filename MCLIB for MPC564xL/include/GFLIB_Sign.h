/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file     GFLIB_Sign.h
*
* @version  1.0.4.0
* 
* @date     Nov-16-2010
* 
* @brief    Header file for #GFLIB_Sign function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef GFLIB_SIGN_H_
#define GFLIB_SIGN_H_

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
 * \def GFLIB_Sign
 * Function alias for the #GFLIB_SignANSIC function.
 */
#define GFLIB_Sign(x) GFLIB_SignANSIC(x)

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
extern tMclib GFLIB_SignANSIC(tMclib s32In);

/******************************************************************************
* Inline functions
******************************************************************************/ 

#ifdef __cplusplus
}
#endif

#endif /* GFLIB_SIGN_H_*/

/* End of file */
