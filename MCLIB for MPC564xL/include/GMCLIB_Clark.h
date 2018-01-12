/******************************************************************************
*
* (c) Copyright 2010, Freescale Semiconductor
*
***************************************************************************//*!
*
* @file      GMCLIB_Clark.h
*
* @version   1.0.5.0
*
* @date      Nov-16-2010
*
* @brief     Header file for #GMCLIB_Clark transformation algorithm.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90.
*
******************************************************************************/
#ifndef _GMCLIB_CLARK_H_
#define _GMCLIB_CLARK_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/

/*!
 * \def GMCLIB_Clark
 * Function alias for the #GMCLIB_ClarkANSIC function.
 */
#define GMCLIB_Clark(pOut,pIn) GMCLIB_ClarkANSIC(pOut,pIn)

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
* @ingroup GMCLIB_GROUP
*/
extern void GMCLIB_ClarkANSIC (SWLIBS_2Syst *pOut,
                               const SWLIBS_3Syst *const pIn);

#ifdef __cplusplus
}
#endif
#endif /* _GMCLIB_CLARK_H_ */

/* End of file */
