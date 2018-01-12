/******************************************************************************
*
* (c) Copyright 2010, Freescale
*
***************************************************************************//*!
*
* @file     SWLIBS_Defines.h
*
* @version  1.0.26.0
*
* @date     May-6-2011
*
* @brief    Defines and common Macros definition file.
*
*******************************************************************************
*
******************************************************************************/
#ifndef _SWLIBS_DEFINES_H
#define _SWLIBS_DEFINES_H

#if defined( __MWERKS__) || defined(__ghs__)
#include <stdint.h>
#endif

#include "SWLIBS_Typedefs.h"

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/

/*! Constant representing the maximal negative value of a signed 16-bit fixed point fractional
 *  number eq -1.0 */
#define SFRACT_MIN          (-1.0)

/*! Constant representing the maximal positive value of a signed 16-bit fixed point fractional
 *  number eq 0.999969482421875 */
#define SFRACT_MAX          (0.999969482421875)

/*! Constant representing the maximal negative value of signed 32-bit fixed point fractional
 *  number eq -1.0 */
#define FRACT_MIN           (-1.0)

/*! Constant representing the maximal positive value of a signed 32-bit fixed point fractional
 *  number eq 0.9999999995343387126922607421875 */
#define FRACT_MAX           (0.9999999995343387126922607421875)

/*! Constant representing the maximal positive value of a signed 16-bit fixed point integer
 *  number eq \f$ 2^{16-1}-1 = \f$ 0x7fff. */
#ifndef INT16_MAX
#define INT16_MAX           ((tS16) 0x7fff)
#endif

/*! Constant representing the maximal negative value of a signed 16-bit fixed point integer
 *  number eq \f$ -2^{16-1} = \f$ 0x8000. */
#ifndef INT16_MIN
#define INT16_MIN           ((tS16) 0x8000)
#endif

/*! Constant representing the maximal positive value of a signed 32-bit fixed point integer
 *  number eq \f$ 2^{32-1}-1 = \f$ 0x7fff ffff. */
#ifndef INT32_MAX
#define INT32_MAX           ((tS32) 0x7fffffff)
#endif

/*! Constant representing the maximal negative value of a signed 32-bit fixed point integer
 *  number eq \f$ -2^{32-1} = \f$ 0x8000 0000. */
#ifndef INT32_MIN
#define INT32_MIN           ((tS32) 0x80000000)
#endif

/*! Type casting - signed 16-bit fractional value cast to a signed integer 16-bit integer. */
#define F16TOINT16(x)       ((tS16) (x))

/*! Type casting - lower 16 bits of a signed 32-bit fractional value cast
 * to a signed 16-bit integer. */
#define F32TOINT16(x)       ((tS16) (x))

/*! Type casting - lower 16 bits of a signed 64-bit fractional value cast
 * to a signed 16-bit integer. */
#define F64TOINT16(x)       ((tS16) (x))

/*! Type casting - a signed 16-bit fractional value cast to a signed
 * 32-bit integer, the value placed at the lower 16 bits of the 32-bit result. */
#define F16TOINT32(x)       ((tS32) (x))

/*! Type casting - signed 32-bit fractional value cast to a signed
 * 32-bit integer. */
#define F32TOINT32(x)       ((tS32) (x))

/*! Type casting - lower 32 bits of a signed 64-bit fractional value cast
 * to a signed 32-bit integer. */
#define F64TOINT32(x)       ((tS32) (x))

/*! Type casting - signed 16-bit fractional value cast to a signed
 * 64-bit integer, the value placed at the lower 16 bits of the 64-bit result. */
#define F16TOINT64(x)       ((tS64) (x))

/*! Type casting - signed 32-bit fractional value cast to a signed
 * 64-bit integer, the value placed at the lower 32 bits of the 64-bit result. */
#define F32TOINT64(x)       ((tS64) (x))

/*! Type casting - signed 64-bit fractional value cast to a signed
 * 64-bit integer. */
#define F64TOINT64(x)       ((tS64) (x))

/*! Type casting - signed 16-bit integer value cast to a signed 
 * 16-bit fractional. */
#define INT16TOF16(x)       ((tFrac16) (x))

/*! Type casting - signed 16-bit integer value cast to a signed
 * 32-bit fractional, the value placed at the lower 16 bits of the 32-bit result. */
#define INT16TOF32(x)       ((tFrac32) (x))

/*! Type casting - lower 16 bits of a signed 32-bit integer value cast
 * to a signed 16-bit fractional. */
#define INT32TOF16(x)       ((tFrac16) (x))

/*! Type casting - signed 32-bit integer value cast to a signed
 * 32-bit fractional. */
#define INT32TOF32(x)       ((tFrac32) (x))

/*! Type casting - lower 16 bits of a signed 64-bit integer value cast
 * to a signed 16-bit fractional. */
#define INT64TOF16(x)       ((tFrac16) (x))

/*! Type casting - lower 32 bits of a signed 64-bit integer value cast
 * to a signed 32-bit fractional. */
#define INT64TOF32(x)       ((tFrac32) (x))

/*! One over sqrt(3) with a 16-bit result, the result rounded for a better
 * precision,i.e. \f$ round(1/sqrt(3)*2^{15}) \f$ */
#define F16_1_DIVBY_SQRT3   ((tFrac16) 0x49E7)

/*! One over sqrt(3) with a 32-bit result, the result rounded for a better
 *  precision, i.e. \f$ round(1/sqrt(3)*2^{31}) \f$ */
#define F32_1_DIVBY_SQRT3   ((tFrac32) 0x49E69D16)

/*! Sqrt(3) divided by two with a 16-bit result, the result rounded for a better
 * precision, i.e. \f$ round(sqrt(3)/2*2^{15}) \f$ */
#define F16_SQRT3_DIVBY_2   ((tFrac16) 0x6EDA)

/*! Sqrt(3) divided by two with a 32-bit result, the result rounded for a better
 * precision, i.e. \f$ round(sqrt(3)/2*2^{31}) \f$ */
#define F32_SQRT3_DIVBY_2   ((tFrac32) 0x6ED9EBA1)

/*! Macro converting a signed fractional [-1,1) number into a 16-bit fixed point 
 * number in format Q1.15.*/
#define FRAC16(x)           ((tFrac16) ((x) < (SFRACT_MAX) ? ((x) >= SFRACT_MIN ? (x)*0x8000 : 0x8000) : 0x7fff))

/*! Macro converting a signed fractional [-1,1) number into a 32-bit fixed point
 * number in format Q1.31.*/
#define FRAC32(x)           ((tFrac32) ((x) < (FRACT_MAX) ? ((x) >= FRACT_MIN ? (x)*0x80000000 : 0x80000000) : 0x7fffffff))

/*! Constant representing the maximal negative value of the 32-bit float type. */
#ifndef FLOAT_MIN
#define FLOAT_MIN           ((tFloat) -3.4E+38)
#endif

/*! Constant representing the maximal positive value of the 32-bit float type. */
#ifndef FLOAT_MAX
#define FLOAT_MAX           ((tFloat) 3.4E+38)
#endif

/*! One over sqrt(3) in single precision floating point format. */
#define FLOAT_DIVBY_SQRT3   ((tFloat) 0.5773502691896258)

/*! Sqrt(3) divided by two in single precision floating point format. */
#define FLOAT_SQRT3_DIVBY_2 ((tFloat) 0.866025403784439)

/*! Sqrt(3) divided by four in single precision floating point format. */
#define FLOAT_SQRT3_DIVBY_4 ((tFloat) 0.4330127018922190)

/*! Sqrt(3) divided by four correction constant. */
//#define FLOAT_SQRT3_DIVBY_4_CORRECTION ((tFloat)7.7718125e-09)
#define FLOAT_SQRT3_DIVBY_4_CORRECTION ((tFloat)0)

/*! 2*Pi in single precision floating point format. */
#define FLOAT_2_PI          ((tFloat) 6.28318530717958)

/*! Pi in single precision floating point format. */
#define FLOAT_PI            ((tFloat) 3.14159265358979)

/*! Pi/2 in single precision floating point format. */
#define FLOAT_PI_DIVBY_2    ((tFloat) 1.57079632679490)

/*! Double to single precision correction constant for Pi, equal to 
(PI(Double) - PI(Single)) */
#define FLOAT_PI_SINGLE_CORRECTION ((tFloat)4.37102068E-8)

/*! Double to single precision correction constant for Pi, equal to 
(2*(PI(Double) - PI(Single)) */
#define FLOAT_PI_CORRECTION ((tFloat)8.74204136E-8)

/*! Pi/4 in single precision floating point format. */
#define FLOAT_PI_DIVBY_4    ((tFloat) 0.7853981633974480)

/*! Number four divided by PI in single precision floating point format. */
#define FLOAT_4_DIVBY_PI    ((tFloat) 1.2732395447351600) 

/*! Value 0.5 in single precision floating point format. */
#define FLOAT_0_5           ((tFloat) 0.5)

/*! Value 1 in single precision floating point format. */
#define FLOAT_PLUS_1        ((tFloat) 1)

/*! Value -1 in single precision floating point format. */
#define FLOAT_MINUS_1       ((tFloat) -1)

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/******************************************************************************
* Exported variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/

/******************************************************************************
* Inline functions
******************************************************************************/

#endif /* _SWLIBS_DEFINES_H */
