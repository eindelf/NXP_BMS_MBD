/**************************************************************************
 * FILE NAME: $RCSfile: typedefs.h,v $       COPYRIGHT (c) Freescale 2005 *
 * DESCRIPTION:                                     All Rights Reserved   *
 * This file defines all of the data types for the Motorola header file.  *
 *========================================================================*
 * ORIGINAL AUTHOR: r12110                                                *
 * $Log: typedefs.h,v $
 * Revision 1.5 2016/04/18 11:20:19   b47769
 * Diab compiler compatibility
 *
 * Revision 1.4  2008/02/19 11:10:09  b04629
 * Fixed previous comment.
 *
 * Revision 1.3  2008/02/19 11:01:43  b04629
 * Replaced // comments for MISRA.
 *
 * Revision 1.2  2007/11/22 13:18:55  b04629
 * Removed original author name and replaced with author ID.
 *
 * Revision 1.1  2007/03/22 08:55:15  b04629
 * Imported and updated from MPC55xx Headers Rev 1.9
 *                                                                        *
 *                                                                        *
 **************************************************************************/

#ifndef _LOCAL_TYPEDEFS_H_
#define _LOCAL_TYPEDEFS_H_

#if defined (__MWERKS__)    /* Metrowerk CodeWarrior */
    #include <stdint.h>

    /*  Standard typedefs used by header files, based on ISO C standard */
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;

#elif defined (__ghs__)    /* GreenHills */
    #include <stdint.h>

    /* Standard typedefs used by header files, based on ISO C standard */
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;
#else
/* This is needed for compilers that don't have a stdint.h file */

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef volatile signed char vint8_t;
typedef volatile unsigned char vuint8_t;

typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef volatile signed short vint16_t;
typedef volatile unsigned short vuint16_t;

typedef signed long int32_t;
typedef unsigned long uint32_t;
typedef volatile signed long vint32_t;
typedef volatile unsigned long vuint32_t;
    
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/
#ifndef NULL
  #ifdef __cplusplus
    #define NULL ((void*)0)
  #else
    /*
    * @violates @ref SWLIBS_Typedefs_h_REF_1 MISRA 2004 Required Rule 20.2, Re-use of C90
    * identifier.
    */
    #define NULL 0
  #endif
#endif /* NULL */


/******************************************************************************
* Defines and macros            (scope: module-global)
******************************************************************************/


/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/
#ifndef tBool
typedef unsigned char       tBool;          /*!< basic boolean type */

#ifndef FALSE
#define FALSE ((tBool)0)                    /*!< Boolean type FALSE constant */
#endif

#ifndef TRUE
#define TRUE ((tBool)1)                     /*!< Boolean type TRUE constant */
#endif

typedef unsigned char       tU8;            /*!< unsigned 8-bit integer type */
typedef signed char         tS8;            /*!< signed 8-bit integer type */
typedef unsigned short      tU16;           /*!< unsigned 16-bit integer type */
typedef signed short        tS16;           /*!< signed 16-bit integer type */
typedef unsigned long       tU32;           /*!< unsigned 32-bit integer type */
typedef signed long         tS32;           /*!< signed 32-bit integer type */
typedef signed long long    tS64;           /*!< signed 64-bit integer type */
typedef unsigned long long  tU64;           /*!< unsigned 64-bit integer type */
typedef tS16                tFrac16;        /*!< 16-bit signed fractional Q1.15 type */
typedef tS32                tFrac32;        /*!< 32-bit Q1.31 type */
typedef float               tFloat;         /*!< single precision float type */
typedef double              tDouble;        /*!< double precision float type */

#endif
/*********************************************************************
 *
 * Copyright:
 *	Freescale Semiconductor, INC. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Freescale
 *  Semiconductor, Inc. This software is provided on an "AS IS"
 *  basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, Freescale
 *  Semiconductor DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED,
 *  INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A
 *  PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH
 *  REGARD TO THE SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF)
 *  AND ANY ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL Freescale Semiconductor BE LIABLE FOR ANY DAMAGES WHATSOEVER
 *  (INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS,
 *  BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER
 *  PECUNIARY LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Freescale Semiconductor assumes no responsibility for the
 *  maintenance and support of this software
 *
 ********************************************************************/


#endif // _LOCAL_TYPEDEFS_H_
