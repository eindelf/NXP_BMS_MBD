/*
 *######################################################################
 *                                RAppID
 *           Rapid Application Initialization and Documentation Tool
 *                         Freescale Semiconductor Inc.
 *
 *######################################################################
 *
 * Project Name           : ClockTest1
 *
 * Project File           : ClockTest1.rsp
 *
 * Revision Number        : 1.0
 *
 * Tool Version           : 1.0.0.6
 *
 * file                   : z4_0sys_init_p0.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : MPC5643L
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 01-Apr-2011 17:52:31
 *
 * Created on Date        : 01-Apr-2011 17:52:33
 *
 * Brief Description      : This file contains system initialization code
 *
 ********************************************************************************
 *
 * Detail Description     : This file contains function which calls respective
 *                         peripheral initialization functions
 *
 ********************************************************************************
 *
 *######################################################################
 */

/********************  Dependent Include files here **********************/
#include "rappid_ref.h"
#include "sys_init.h"
#include "siu_init.h"

/*********************  Initialization Function(s) ************************/
void sys_init_fnc(void)
{
  {
    uint32_t i,a[4];
    for (i=0;i<4;i++) {
      FCCU.CFK.R = FCCU_CFK_Key;
      FCCU.CF_S[i].R = 0xFFFFFFFF;
      while (FCCU.CTRL.B.OPS != 0x03) ;/* wait for the completion of the operation */
      a[i]= FCCU.CF_S[i].R;
    }
  }

  {
    uint32_t i,b[4];
    for (i=0;i<4;i++) {
      FCCU.NCFK.R = FCCU_NCFK_Key;
      FCCU.NCF_S[i].R = 0xFFFFFFFF;
      while (FCCU.CTRL.B.OPS != 0x03) ;/* wait for the completion of the operation */
      b[i]= FCCU.NCF_S[i].R;
    }
  }

  /* ----------------------------------------------------------- */
  /*	               System Initialization Functions              */
  /* ----------------------------------------------------------- */

  /* ----------------------------------------------------------- */
  /*                  Reset Determination Goes Here             */
  /* ----------------------------------------------------------- */

  /* ----------------------------------------------------------- */
  /*	        Initialize the System Clock, Mode Entry (ME) & CMU             */
  /* ----------------------------------------------------------- */
  sysclk_module_init_fnc();

  /* ----------------------------------------------------------- */
  /*	        Initialize the Mode Entry Post Configuration             */
  /* ----------------------------------------------------------- */
  mode_entry_post_config_fnc();
  siu_init_fnc();
}

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
