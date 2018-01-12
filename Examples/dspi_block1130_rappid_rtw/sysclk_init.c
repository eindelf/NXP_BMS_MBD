/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    sysclk_init.c
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   Mode Entry, System Clock, CMU initialization file - 8Mhz XTAL 60Mhz Clk.
 *    @details This file contains definitions for initialization
 *                         functions of Mode Entry, System Clock and CMU module.
 *                         Mode Entry function will configure the system SoC for
 *                         different operating modes. In System Clock function the
 *                         Clock Generation Module parameters are initialized for
 *                         DRUN mode. CMU function is initialized to monitor the
 *                         system clock parameters and report the failures.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		23-May-2011
 *   Author:                         B14423
 *
 */

#ifdef __cplusplus

extern "C"{

#endif

  /******************************************************************************
   *                  Includes
   ******************************************************************************/
#include "sysclk_init.h"

  /******************************************************************************
   *                   Global functions
   ******************************************************************************/

  /*********************  Initialization Function(s) ************************/

  /******************************************************************************
   *   Function:  sysclk_module_init_fnc
     @brief    Sets the Channel Watchdog Selection Register .
     @details   Sets the Channel Watchdog Selection Register

     @return none
   */
  void sysclk_module_init_fnc(void)
  {
    while (RGM.FES.R != 0) {
      RGM.FES.R = 0xFFFF;
    }                                  /* Errata for cut1 */

    Mode_Entry_init_fnc();

    /* Mode Entry Initialization Function */
    sysclk_init_fnc();

    /* System Clock Initialization Function */
    cmu_init_fnc();

    /* CMU Initialization Function */
  }

  /******************************************************************************
   *   Function:  Mode_Entry_init_fnc
     @brief    Mode Entry Initialization Function .
     @details   Mode Entry Initialization Function

     @return none
   */
  void Mode_Entry_init_fnc(void)
  {
    /* ----------------------------------------------------------- */
    /*              Operating Modes Initialization - Start            */
    /* ----------------------------------------------------------- */

    /* ----------------------------------------------------------- */
    /*              Mode Entry Setup            */
    /* ----------------------------------------------------------- */
    ME.MEN.R = 0x0000801D;

    /* STOP0 Mode : Disabled    */
    /* HALT0 Mode : Disabled    */
    /* RUN3 Mode : Disabled    */
    /* RUN2 Mode : Disabled    */
    /* RUN1 Mode : Disabled    */
    /* RUN0 Mode : Enabled    */
    /* DRUN Mode : Enabled    */
    /* SAFE Mode : Enabled    */
    /* TEST Mode : Disabled    */
    /* RESET Mode : Enabled    */
    /*---------------------------TEST Mode--------------------------------*/
    ME.TEST_MC.R = 0x001F0010;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: ON    */
    /* Code Flash Power Down Control: Normal    */
    /* Secondary PLL (PLL1): OFF    */
    /* System PLL0: OFF    */
    /* Crystal Oscillator: OFF    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: 16MHz internal RC oscillator     */
    /*---------------------------SAFE Mode--------------------------------*/
    ME.SAFE_MC.R = 0x009F0010;

    /* I/O Power Down Control: Enabled    */
    /* Main Voltage Regulator Control: ON    */
    /* Code Flash Power Down Control: Normal    */
    /* Secondary PLL (PLL1): OFF    */
    /* System PLL0: OFF    */
    /* Crystal Oscillator: OFF    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: 16MHz internal RC oscillator     */
    /*---------------------------RUN0 Mode--------------------------------*/
    ME.RUN_MC[0].R = 0x001F00F4;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: ON    */
    /* Code Flash Power Down Control: Normal    */
    /* Secondary PLL (PLL1): ON    */
    /* System PLL0: ON    */
    /* Crystal Oscillator: ON    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: System PLL 0    */
    /*---------------------------RUN1 Mode--------------------------------*/
    ME.RUN_MC[1].R = 0x001F0010;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: ON    */
    /* Code Flash Power Down Control: Normal    */
    /* Secondary PLL (PLL1): OFF    */
    /* System PLL0: OFF    */
    /* Crystal Oscillator: OFF    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: 16MHz internal RC oscillator     */
    /*---------------------------RUN2 Mode--------------------------------*/
    ME.RUN_MC[2].R = 0x001F0010;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: ON    */
    /* Code Flash Power Down Control: Normal    */
    /* Secondary PLL (PLL1): OFF    */
    /* System PLL0: OFF    */
    /* Crystal Oscillator: OFF    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: 16MHz internal RC oscillator     */
    /*---------------------------RUN3 Mode--------------------------------*/
    ME.RUN_MC[3].R = 0x001F0010;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: ON    */
    /* Code Flash Power Down Control: Normal    */
    /* Secondary PLL (PLL1): OFF    */
    /* System PLL0: OFF    */
    /* Crystal Oscillator: OFF    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: 16MHz internal RC oscillator     */
    /*---------------------------HALT0 Mode--------------------------------*/
    ME.HALT0_MC.R = 0x001F0010;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: ON    */
    /* Code Flash Power Down Control: Normal    */
    /* Secondary PLL (PLL1): OFF    */
    /* System PLL0: OFF    */
    /* Crystal Oscillator: OFF    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: 16MHz internal RC oscillator     */
    /*---------------------------STOP0 Mode--------------------------------*/
    ME.STOP0_MC.R = 0x00150010;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: ON    */
    /* Code Flash Power Down Control: Power Down    */
    /* Secondary PLL (PLL1): OFF    */
    /* System PLL0: OFF    */
    /* Crystal Oscillator: OFF    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: 16MHz internal RC oscillator     */

    /* ----------------------------------------------------------- */
    /*              Peripheral RUN Mode Configuration            */
    /* ----------------------------------------------------------- */
    ME.RUNPC[0].R = 0x000000FE;

    /* Peripheral Operation in RUN3  mode: Enabled    */
    /* Peripheral Operation in RUN2  mode: Enabled    */
    /* Peripheral Operation in RUN1  mode: Enabled    */
    /* Peripheral Operation in RUN0  mode: Enabled    */
    /* Peripheral Operation in DRUN  mode: Enabled    */
    /* Peripheral Operation in SAFE  mode: Enabled    */
    /* Peripheral Operation in TEST  mode: Enabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[1].R = 0x00000008;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Enabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[2].R = 0x00000008;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Enabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[3].R = 0x00000008;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Enabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[4].R = 0x00000008;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Enabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[5].R = 0x00000008;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Enabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[6].R = 0x00000008;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Enabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[7].R = 0x00000008;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Enabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */

    /* ----------------------------------------------------------- */
    /*              Peripheral Low-Power Mode Configuration            */
    /* ----------------------------------------------------------- */
    ME.LPPC[0].R = 0x00000500;

    /* Peripheral Operation in STOP0 mode: Enabled    */
    /* Peripheral Operation in HALT0 mode: Enabled    */
    ME.LPPC[1].R = 0x00000000;

    /* Peripheral Operation in STOP0 mode: Disabled    */
    /* Peripheral Operation in HALT0 mode: Disabled    */
    ME.LPPC[2].R = 0x00000000;

    /* Peripheral Operation in STOP0 mode: Disabled    */
    /* Peripheral Operation in HALT0 mode: Disabled    */
    ME.LPPC[3].R = 0x00000000;

    /* Peripheral Operation in STOP0 mode: Disabled    */
    /* Peripheral Operation in HALT0 mode: Disabled    */
    ME.LPPC[4].R = 0x00000000;

    /* Peripheral Operation in STOP0 mode: Disabled    */
    /* Peripheral Operation in HALT0 mode: Disabled    */
    ME.LPPC[5].R = 0x00000000;

    /* Peripheral Operation in STOP0 mode: Disabled    */
    /* Peripheral Operation in HALT0 mode: Disabled    */
    ME.LPPC[6].R = 0x00000000;

    /* Peripheral Operation in STOP0 mode: Disabled    */
    /* Peripheral Operation in HALT0 mode: Disabled    */
    ME.LPPC[7].R = 0x00000000;

    /* Peripheral Operation in STOP0 mode: Disabled    */
    /* Peripheral Operation in HALT0 mode: Disabled    */

    /* ----------------------------------------------------------- */
    /*              Peripheral Mode Control Setup            */
    /* ----------------------------------------------------------- */

    /* DSPI_0 Control */
    ME.PCTL[4].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* DSPI_1 Control */
    ME.PCTL[5].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* DSPI_2 Control */
    ME.PCTL[6].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexCAN_0 Control */
    ME.PCTL[16].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexCAN_1 Control */
    ME.PCTL[17].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexRay Control */
    ME.PCTL[24].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* ADC_0 Control */
    ME.PCTL[32].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* ADC_1 Control */
    ME.PCTL[33].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* eTimer0 Control */
    ME.PCTL[38].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* eTimer1 Control */
    ME.PCTL[39].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* eTimer2 Control */
    ME.PCTL[40].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexPWM0 Control */
    ME.PCTL[41].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* FlexPWM1 Control */
    ME.PCTL[42].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_0 Control */
    ME.PCTL[48].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* LINFlex_1 Control */
    ME.PCTL[49].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* CRC Control*/
    ME.PCTL[58].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* SWG Control*/
    ME.PCTL[62].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */
    /* RUN Mode Peripheral Configuration: RUN Mode Configuration 0    */

    /* PIT Control */
    ME.PCTL[92].R = 0x00;

    /* Peripheral Operation in Debug mode: Disabled    */
    /* Low-Power Mode Peripheral Configuration: Low-Power Mode Configuration 0    */

    /* ----------------------------------------------------------- */
    /*              Interrupt Setup            */
    /* ----------------------------------------------------------- */
    ME.IM.R = 0x00000000;

    /* Invalid Mode Configuration Interrupt: Disabled    */
    /* Invalid Mode Interrupt: Disabled    */
    /* SAFE Mode Interrupt: Disabled    */
    /* Mode Transition Complete Interrupt: Disabled    */

    /* ----------------------------------------------------------- */
    /*              Operating Modes Initialization - End                */
    /* ----------------------------------------------------------- */
  }

  /******************************************************************************
   *   Function:  sysclk_init_fnc
     @brief    System Clock Initialization Function .
     @details   System Clock Initialization Function

     @return none
   */
  void sysclk_init_fnc(void)
  {
    /* ----------------------------------------------------------- */
    /*              Enable Peripheral Clocks            */
    /* ----------------------------------------------------------- */
    CGM.SC_DC.R = 0x80;

    /* Peripheral Set 0 Clock Divider Status: Enabled */

    /* ----------------------------------------------------------- */
    /*              Enable All Auxiliary Clocks            */
    /* ----------------------------------------------------------- */
    CGM.AC0_DC0_3.B.DE0 = 0x1;

    /* Motor Control Clock Divider:  Enabled */
    CGM.AC0_DC0_3.B.DE1 = 0x1;

    /* Sinewave Generator Clock Divider:  Enabled */
    CGM.AC1_DC0_3.B.DE0 = 0x1;

    /* FlexRay Clock Divider:  Enabled */
    CGM.AC1_DC0_3.B.DE0 = 0x1;

    /* FlexCAN Clock Divider:  Enabled */

    /* --------------- Set Maximum CMU0 RC Divider  --------------- */
    CMU0.CSR.R = 0x00000006;

    /* RC Clock Division factor: 8  */

    /* ----------------------------------------------------------- */
    /*              Clock Source Configuration            */
    /* ----------------------------------------------------------- */
    CGM.RC_CTL.R = 0x00000000;

    /* IRC Oscillator Trimming: 0    */
    CGM.OSC_CTL.R = 0x00800000;

    /* Oscillator Output is Disabled as rootclock    */
    /* The End of Count Value for XOSC = 0x80    */
    /* The XOSC Clock Interrupt: Disabled    */
    CGM.AC3_SC.B.SELCTL = 1;

    /* PLL0 reference clock source : XTAL */
    CGM.AC4_SC.B.SELCTL = 1;

    /* PLL1 reference clock source : XTAL */
    CGM.FMPLL[0].CR.R = PLL_VALUE_0;
    CGM.FMPLL[0].MR.R = 0x00000000;

    /* The selected Spread Type: Down Spread    */
    /* The Modulation Period for FMPLL0: 0    */
    /* Frequency modulation for PLL: Disabled    */
    /* The Increment Step for FMPLL0: 0    */
    CGM.FMPLL[1].CR.R = PLL_VALUE_1;
    CGM.FMPLL[1].MR.R = 0x00000000;

    /* The selected Spread Type: Down Spread    */
    /* The Modulation Period for FMPLL1: 0    */
    /* Frequency modulation for PLL: Disabled    */
    /* The Increment Step for FMPLL1: 0    */

    /* ----------------------------------------------------------- */
    /*                    System Clock Setup  (PLL)                 */
    /* ----------------------------------------------------------- */

    /* ----------------   PLL Configuration  ------------------- */
    ME.DRUN_MC.R = 0x001F00F0;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: Enabled    */
    /* Code Flash Power Down Control: Enabled    */
    /* Secondary PLL (PLL1): ON    */
    /* System PLL: ON    */
    /* Crystal Oscillator: ON    */
    /* 16MHz IRC: ON    */
    /* System Clock Source: 16MHz IRC    */
    ME.MCTL.R = 0x30005AF0;

    /* Mode & Key */
    ME.MCTL.R = 0x3000A50F;

    /* Mode & Key  Inverted  */
    while (0x1 == ME.GS.B.S_MTRANS) {
    }

    ;

    /* Wait for mode entry to complete  */
    while (0x3 != ME.GS.B.S_CURRENT_MODE) {
    }

    ;

    /* Check DRUN mode has been entered  */

    /* Wait for PLL to lock - will not lock before DRUN Re-entry  */
    while (0x0 == CGM.FMPLL[0].CR.B.S_LOCK) {
    }

    ;
    ME.DRUN_MC.R = 0x001F00F4;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: Enabled    */
    /* Code Flash Power Down Control: Enabled    */
    /* Secondary PLL (PLL1): ON    */
    /* System PLL0: ON    */
    /* Crystal Oscillator: ON    */
    /* 16MHz IRC: ON    */
    /* System Clock Source: System PLL 0    */
    ME.MCTL.R = 0x30005AF0;

    /* Mode & Key */
    ME.MCTL.R = 0x3000A50F;

    /* Mode & Key  Inverted  */
    while (0x1 == ME.GS.B.S_MTRANS) {
    }

    ;

    /* Wait for mode entry to complete  */
    while (0x3 != ME.GS.B.S_CURRENT_MODE) {
    }

    ;

    /* Check DRUN mode has been entered  */

    /* Poll Global Status Register to get current System Clock  */
    while (0x4 != ME.GS.B.S_SYSCLK) {
    }

    ;

    /* Fail is stuck here  */

    /* System Clock to System PLL */
    CGM.SC_SS.B.SELSTAT = 0x0100;

    /* ----------------------------------------------------------- */
    /*          Activate the clock Configuration              */
    /* -----------------------------------------------------------  */
    ME.MCTL.R = ((ME.GS.B.S_CURRENT_MODE << 28) | 0x00005AF0);
    ME.MCTL.R = ((ME.GS.B.S_CURRENT_MODE << 28) | 0x0000A50F);

    /* ----------------------------------------------------------- */
    /*                    System Output Clock Setup                 */
    /* ----------------------------------------------------------- */
    CGM.OCDS_SC.R = 0x02000000;

    /* Clock Divider: 1 */
    /* Output Clock Source: System PLL (PLL0) */
    CGM.OC_EN.B.EN = 0x1;

    /* Output Clock: Enabled */
    CGM.SC_DC.R = 0x80;

    /* Peripheral Set 0 Clock Divider: 1 */
    CGM.AC0_SC.B.SELCTL = 4;

    /* Auxiliary Clock 0 Source: System PLL */
    CGM.AC0_DC0_3.B.DIV0 = MC_DIV;

    /* Motor Control Clock Divider */
    CGM.AC0_DC0_3.B.DIV1 = SW_DIV;

    /* Sinewave Generator Clock Divider */
    CGM.AC1_SC.R = 0x04000000;

    /* Auxiliary Clock 1 Source: System PLL (PLL0) */
    CGM.AC1_DC0_3.B.DIV0 = 1;

    /* FlexRay Clock Divider Value: 1    */
    CGM.AC2_SC.R = 0x04000000;

    /* Auxiliary Clock 2 Source: System PLL (PLL0) */
    CGM.AC2_DC0_3.B.DIV0 = 1;

    /* FlexCAN Clock Divider Value: 1    */
  }

  /******************************************************************************
   *   Function:  cmu_init_fnc
     @brief     CMU Initialization Function .
     @details    CMU Initialization Function

     @return none
   */
  void cmu_init_fnc(void)
  {
    /*-----------------------CMU0 Setup------------------------*/
    CMU0.MDR.R = 0x00000000;

    /* IRC Measurement Duration in IRC Clock Cycles: 0 */
    CMU0.HFREFR_A.R = 0x00000FFF;

    /* High Frequency Reference Value for System Clock: 1023.75MHz */
    CMU0.LFREFR_A.R = 0x00000000;

    /* Low Frequency Reference Value for System Clock: 0.0MHz */
    CMU0.CSR.R = 0x00000006;

    /* RC Oscillator to be calibrated by Frequency Meter: 16MHz IRC*/
    /* RC Clock Division factor: 8 */
    /* Clock Monitoring Unit 0: Disable */

    /*-----------------------CMU1 Setup------------------------*/
    CMU1.HFREFR_A.R = 0x00000FFF;

    /* High Frequency Reference Value for Motor Control Clock: 1023.75MHz */
    CMU1.LFREFR_A.R = 0x00000000;

    /* Low Frequency Reference Value for Motor Control Clock: 0.0MHz */
    CMU1.CSR.R = 0x00000006;

    /* Clock Monitoring Unit 0: Disable */

    /*-----------------------CMU2 Setup------------------------*/
    CMU2.HFREFR_A.R = 0x00000FFF;

    /* High Frequency Reference Value for FlexRay Clock: 1023.75MHz */
    CMU2.LFREFR_A.R = 0x00000000;

    /* Low Frequency Reference Value for FMPLL0: 0.0MHz */
    CMU2.CSR.R = 0x00000006;

    /* Clock Monitoring Unit 0: Disable */
  }

  /******************************************************************************
   *   Function:  mode_entry_post_config_fnc
     @brief     Mode entry configuration .
     @details    Mode entry configuration

     @return none
   */
  void mode_entry_post_config_fnc(void)
  {
    /* ----------------------------------------------------------- */
    /*              Peripheral RUN Mode Configuration            */
    /* ----------------------------------------------------------- */
    ME.RUNPC[0].R = 0x000000FE;

    /* Peripheral Operation in RUN3  mode: Enabled    */
    /* Peripheral Operation in RUN2  mode: Enabled    */
    /* Peripheral Operation in RUN1  mode: Enabled    */
    /* Peripheral Operation in RUN0  mode: Enabled    */
    /* Peripheral Operation in DRUN  mode: Enabled    */
    /* Peripheral Operation in SAFE  mode: Enabled    */
    /* Peripheral Operation in TEST  mode: Enabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[1].R = 0x00000000;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Disabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[2].R = 0x00000000;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Disabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[3].R = 0x00000000;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Disabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[4].R = 0x00000000;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Disabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[5].R = 0x00000000;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Disabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[6].R = 0x00000000;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Disabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */
    ME.RUNPC[7].R = 0x00000000;

    /* Peripheral Operation in RUN3  mode: Disabled    */
    /* Peripheral Operation in RUN2  mode: Disabled    */
    /* Peripheral Operation in RUN1  mode: Disabled    */
    /* Peripheral Operation in RUN0  mode: Disabled    */
    /* Peripheral Operation in DRUN  mode: Disabled    */
    /* Peripheral Operation in SAFE  mode: Disabled    */
    /* Peripheral Operation in TEST  mode: Disabled    */
    /* Peripheral Operation in RESET  mode: Disabled    */

    /* ----------------------------------------------------------- */
    /*      DRUN Clock settings & Peripheral Clock and Auxiliary Divider Settings    	   */
    /* ----------------------------------------------------------- */
    ME.DRUN_MC.R = 0x001F00F4;

    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: Enabled    */
    /* Code Flash Power Down Control: Normal    */
    /* System PLL0: ON    */
    /* Secondary PLL (PLL1): ON    */
    /* Crystal Oscillator: ON    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: System PLL 0    */
    CGM.SC_DC.R = 0x80;

    /* Peripheral Set 0 Clock Divider Status: Enabled */
    /* Peripheral Set 1 Clock Divider: 1 */
    CGM.AC0_DC0_3.B.DE0 = 0x1;

    /* Motor Control Clock Divider : Enabled    */
    CGM.AC0_DC0_3.B.DE1 = 0x1;

    /* Sinewave Generator Clock Divider: Enabled    */
    CGM.AC1_DC0_3.B.DE0 = 0x1;

    /* FlexRay Clock (Aux Clock 1 Divider): Enabled    */
    CGM.AC2_DC0_3.B.DE0 = 0x1;

    /* FlexCAN Clock Divider: Enabled    */

    /* ----------------------------------------------------------- */
    /*                     DRUN Re-Entry                    */
    /* ----------------------------------------------------------- */

    /* Re-enter in DRUN mode to update the configuration*/
    ME.MCTL.R = 0x30005AF0;

    /* Mode & Key */
    ME.MCTL.R = 0x3000A50F;

    /* Mode & Key  Inverted */
    while (0x1 == ME.GS.B.S_MTRANS) {
    }

    ;

    /* Wait for mode entry to complete */
    while (0x3 != ME.GS.B.S_CURRENT_MODE) {
    }

    ;

    /* Check DRUN mode has been entered  */
  }

#ifdef __cplusplus

}
#endif

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
