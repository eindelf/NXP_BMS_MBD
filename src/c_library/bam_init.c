/*
 *######################################################################
 *                                RAppIDJDP
 *           Rapid Application Initialization and Documentation Tool
 *                         Freescale Semiconductor Inc.
 *
 *######################################################################
 *
 * Project Name           : RAppIDToolbox8Mhz
 *
 * Project File           : RAppIDToolbox8Mhz.rsp
 *
 * Revision Number        : 1.0
 *
 * Tool Version           : 1.2.0.2
 *
 * file                   : bam_init.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : MPC5604P
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 18-Mar-2010 16:07:26
 *
 * Created on Date        : 18-Mar-2010 16:07:34
 *
 * Brief Description      : File contains RCHW initialization
 *
 ******************************************************************************** 
 *
 * Detail Description     : This file contains the Bootup Reset Config Half Word(RCHW)initialization.
 *                          This file pushed control on reset to crt0.s start function.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
#pragma section code_type ".init"

extern __asm void __start();

typedef void (*resetfuncptr)(void);

#pragma push /* Save the current state */
#pragma section sconst_type ".__bam_bootarea"
extern const long int bam_rchw;
extern const resetfuncptr bam_resetvector;

const long int bam_rchw =  0x005A0000;             

const resetfuncptr bam_resetvector = __start;

#pragma pop

 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

