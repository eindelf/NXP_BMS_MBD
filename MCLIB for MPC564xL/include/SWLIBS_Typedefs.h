/******************************************************************************
*
* (c) Copyright 2010, Freescale
*
***************************************************************************//*!
*
* @file     SWLIBS_Typedefs.h
* 
* @version  1.0.8.0
* 
* @date     May-6-2011
* 
* @brief    Basic types definition file.
*
*******************************************************************************
*
******************************************************************************/
#ifndef _SWLIBS_TYPEDEFS_H
#define _SWLIBS_TYPEDEFS_H

#include "SWLIBS_Config.h"

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#define NULL ((void*)0)
#endif
#endif

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

typedef unsigned char       tBool;          /*!< basic boolean type */

#ifndef FALSE
#define FALSE ((tBool)0)                    /*!< Boolean type FALSE constant. */
#endif

#ifndef TRUE
#define TRUE ((tBool)1)                     /*!< Boolean type TRUE constant. */
#endif

typedef unsigned char       tU8;            /*!< unsigned 8-bit integer type */
typedef signed char         tS8;            /*!< signed 8-bit integer type */
typedef unsigned short      tU16;           /*!< unsigned 16-bit integer type */
typedef signed short        tS16;           /*!< signed 16-bit integer type */
typedef unsigned int        tU32;           /*!< unsigned 32-bit integer type */
typedef signed int          tS32;           /*!< signed 32-bit integer type */
typedef unsigned long long  tU64;           /*!< unsigned 64-bit integer type */
typedef signed long long    tS64;           /*!< signed 64-bit integer type */
typedef tS16                tFrac16;        /*!< signed 16-bit fractional Q1.15 type */
typedef tS32                tFrac32;        /*!< signed 32-bit fractional Q1.31 type */                                            
typedef float               tFloat;         /*!< single precision float type */
typedef double              tDouble;        /*!< double precision float type */

  typedef float             tMclib;         /*!< 32-bit float type */



/*------------------------------------------------------------------------*//*!
@struct SWLIBS_3Syst "\SWLIBS_Typedefs.h"

@brief  Structure data type for three axis input/output variables.
*//*-------------------------------------------------------------------------*/
typedef struct
{
  tMclib s32Arg1;   /*!< First argument */
  tMclib s32Arg2;   /*!< Second argument */
  tMclib s32Arg3;   /*!< Third argument */
} SWLIBS_3Syst;

/*------------------------------------------------------------------------*//*!
@struct SWLIBS_2Syst "\SWLIBS_Typedefs.h"

@brief  Structure data type for two axis input/output variables.
*//*-------------------------------------------------------------------------*/

typedef struct
{
  tMclib s32Arg1;   /*!< First argument */
  tMclib s32Arg2;   /*!< Second argument */
} SWLIBS_2Syst;

/******************************************************************************
* Exported variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/

/******************************************************************************
* Inline functions
******************************************************************************/

#endif /* _SWLIBS_TYPEDEFS_H */
