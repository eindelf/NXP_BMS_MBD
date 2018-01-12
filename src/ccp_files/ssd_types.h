 /************************************************************************
 * (c) Copyright Freescale Semiconductor & STMicroelectronics,2011       *
 *                        All Rights Reserved                            *
 *************************************************************************

 *************************************************************************
 *                                                                       *
 *               Standard Software Driver for C90FL                      *
 *                                                                       *
 * FILE NAME     :  ssd_types.h                                          *
 * DATE          :  December 07, 2007                                    *
 * AUTHOR        :  Arvind Awasthi                                       *
 * E-mail        :  r56611@freescale.com                                 *
 *                                                                       *
 *************************************************************************/

/******************************* CHANGES *********************************
 0.0.0   2007.12.07               Arvind Awasthi          Initial Version
 *************************************************************************/

#ifndef _C90FL_TYPES_H_
#define _C90FL_TYPES_H_

/*************************************************************************/
/*  SSD general data types                                               */
/*************************************************************************/

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

#define VLE_ASM

typedef unsigned char BOOL;

typedef signed char INT8;
typedef unsigned char UINT8;
typedef volatile signed char VINT8;
typedef volatile unsigned char VUINT8;

typedef signed short INT16;
typedef unsigned short UINT16;
typedef volatile signed short VINT16;
typedef volatile unsigned short VUINT16;

typedef signed long INT32;
typedef unsigned long UINT32;
typedef volatile signed long VINT32;
typedef volatile unsigned long VUINT32;

typedef signed long long INT64;
typedef unsigned long long UINT64;
typedef volatile signed long long VINT64;
typedef volatile unsigned long long VUINT64;

#endif  /* _C90FL_TYPES_H_ */
