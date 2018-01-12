/******************************************************************************
*
* (c) Copyright 2011, Freescale
*
***************************************************************************//*!
*
* @file     SWLIBS_MacroDisp.h
*
* @version  1.0.2.0
*
* @date     Jun-23-2011
*
* @brief    MCLIB dispatcher header file.
*
******************************************************************************/
#ifndef SWLIBS_MACRODISP_H_
#define SWLIBS_MACRODISP_H_

#define _ARG2(_0, _1, _2, _3,...) _3
#define VA_NUM_ARGS(...) _ARG2(__VA_ARGS__, 3, 2, 1, 0)

#define macro_dispatcher(func, ...) macro_dispatcher_(func, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(func, nargs) macro_dispatcher__(func, nargs)
#define macro_dispatcher__(func, nargs) func##_Dsptchr_## nargs


#endif /* SWLIBS_MACRODISP_H_ */
