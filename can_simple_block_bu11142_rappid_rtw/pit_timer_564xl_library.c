/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    pit_timer_564xl_library.c
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   PIR module support.
 *    @details Implementation ofPIT module functions.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		28-Oct-2010
 *   Author:                         r61406
 *
 */

#ifdef __cplusplus

extern "C"{

#endif

  /******************************************************************************
   *                  Includes
   ******************************************************************************/
#include "pit_timer_564xl_library.h"

  /******************************************************************************
   *   Function:  pit_timer_init_564xl
     @brief    configure PIT timer.
     @details  configure PIT timer

     @param[in]     chan          PIT channel
     @param[in]     timeout     sample time is %<period> seconds.

     @return none
   */
  void pit_timer_init_564xl( uint8_t chan, uint32_t timeout)
  {
    PIT.PITMCR.B.MDIS = 1 ;

    /*Disable PIT for initialization         */
    /* ----------------------------------------------------------- */
    /*                     Configure Load Value Registers                */
    /* ----------------------------------------------------------- */
    PIT.CH[chan].LDVAL.R = timeout;    /* The model's base sample time is %<period> seconds. */

    /* ----------------------------------------------------------- */
    /*                     Enable Interrupts                  */
    /* ----------------------------------------------------------- */
    PIT.CH[chan].TCTRL.B.TIE = 0x1 ;

    /* ----------------------------------------------------------- */
    /*                   Start Timers                 */
    /* ----------------------------------------------------------- */
    PIT.CH[chan].TCTRL.B.TEN = 0x1 ;

    /*Start Timer 0 is : Enabled    */
    PIT.PITMCR.B.MDIS = 0 ;
  }

#ifdef __cplusplus

}
#endif

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
