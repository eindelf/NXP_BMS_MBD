/******************************************************************************
*
* (c) Copyright 2010, Freescale
*
***************************************************************************//*!
*
* @file     SWLIBS_Config.h
*
* @version  1.0.7.0
*
* @date     May-3-2011
*
* @brief    MCLIB configuration header file.
*
*******************************************************************************
*
******************************************************************************/
#ifndef _SWLIBS_CONFIG_H
#define _SWLIBS_CONFIG_H

/* Arithmetics selection type */
#define MATH_FIX32          1     /*!< 32-bit fix point arithmetic selection switch. */
#define MATH_FIX16          2     /*!< 16-bit fix point arithmetic selection switch. */
#define MATH_FLOAT          3     /*!< Single precision floating point arithmetic selection switch. */
#define MATH_DOUBLE         4     /*!< Double precision floating point arithmetic selection switch. */

/*! Arithmetics selector */
#define USE_ARITHMETIC      MATH_FLOAT

#endif /* _SWLIBS_CONFIG_H */
