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
 * file                   : siu_init.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : MPC5643L
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 05-Apr-2011 09:50:39
 *
 * Created on Date        : 05-Apr-2011 09:50:41
 *
 * Brief Description      : This File Contains Pads, external Interrupts and
 *                          Wakeups configuration
 *
 ******************************************************************************** 
 *
 * Detail Description     : This File contains function for peripheral assignment
 *                         for each pads, External Interrupt configuration,
 *                         Wakeup configuration and Trigger configuration.
 *                         It also handles Port parallel masking.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "rappid_ref.h"
#include "siu_init.h"




/* ----------------------------------------------------------- */
/*	                SIU Initialization                         */
/* ----------------------------------------------------------- */
void siu_init_fnc(void)
{
    siu_portA_init_fnc();
    siu_portB_init_fnc();
    siu_portC_init_fnc();
    siu_portD_init_fnc();
    siu_portE_init_fnc();
    siu_portF_init_fnc();
    siu_portG_init_fnc();
    siu_portH_init_fnc();
    siu_portI_init_fnc();
    siu_general_init_fnc();
    siu_parallel_port_init_fnc();
    siu_unused_pins_init_fnc();
    siu_psmi_init_fnc();
}


/* ----------------------------------------------------------- */
/*                 SIU PORT A PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_portA_init_fnc(void)
{
    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[0]  eTIMER_0_CH0_SCK_2_PA0 (T14) */
    /* ----------------------------------------------------------- */
       SIU.PCR[0].R = 0x0000;
             /*	Selected Function : PA0          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[1]  eTIMER_0_CH1_SOUT_2_PA1 (R14) */
    /* ----------------------------------------------------------- */
       SIU.PCR[1].R = 0x0000;
             /*	Selected Function : PA1          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[2]  eTIMER_0_CH2_FlexPWM0_A_3_SIN_2_PA2 (N16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[2].R = 0x0102;
             /*	Selected Function : PA2 I          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Enabled           */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Enabled       */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[3]  eTIMER_0_CH3_PCS_2.0_FlexPWM0_B_3_PA3 (K17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[3].R = 0x0102;
             /*	Selected Function : PA3 I          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Enabled           */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Enabled       */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[4]  eTIMER_1_CH0_PCS_2.1_eTIMER_0_CH4_PA4 (C16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[4].R = 0x0102;
             /*	Selected Function : PA4 I          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Enabled           */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Enabled       */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[5]  PCS_1.0_eTIMER_1_CH5_PCS_0.7_PA5 (H4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[5].R = 0x0000;
             /*	Selected Function : PA5          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[6]  SCK_1_PA6 (G4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[6].R = 0x0000;
             /*	Selected Function : PA6          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[7]  SOUT_1_PA7 (F3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[7].R = 0x0000;
             /*	Selected Function : PA7          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[8]  SIN_1_PA8 (F4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[8].R = 0x0000;
             /*	Selected Function : PA8          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[9]  PCS_2.1_FlexPWM0_B_3_FlexPWM0_Fault_0_PA9 (B6) */
    /* ----------------------------------------------------------- */
       SIU.PCR[9].R = 0x0000;
             /*	Selected Function : PA9          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[10]  PCS_2.0_FlexPWM0_B_0_FlexPWM0_X_2_PA10 (A13) */
    /* ----------------------------------------------------------- */
       SIU.PCR[10].R = 0x0000;
             /*	Selected Function : PA10          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[11]  SCK_2_FlexPWM0_A_0_FlexPWM0_A_2_PA11 (D11) */
    /* ----------------------------------------------------------- */
       SIU.PCR[11].R = 0x0000;
             /*	Selected Function : PA11          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[12]  SOUT_2_FlexPWM0_A_2_FlexPWM0_B_2_PA12 (A10) */
    /* ----------------------------------------------------------- */
       SIU.PCR[12].R = 0x0000;
             /*	Selected Function : PA12          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[13]  FlexPWM0_B_2_SIN_2_FlexPWM0_Fault_0_PA13 (C6) */
    /* ----------------------------------------------------------- */
       SIU.PCR[13].R = 0x0000;
             /*	Selected Function : PA13          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[14]  CAN_1_Tx_eTIMER_1_CH4_PA14 (B4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[14].R = 0x0000;
             /*	Selected Function : PA14          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[15]  eTIMER_1_CH5_CAN_1_Rx_CAN_0_Rx_PA15 (D3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[15].R = 0x0000;
             /*	Selected Function : PA15          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

}


/* ----------------------------------------------------------- */
/*                 SIU PORT B PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_portB_init_fnc(void)
{
    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[16]  CAN_0_Tx_eTIMER_1_CH2_SSCM_Debug_0_PB0 (B15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[16].R = 0x0000;
             /*	Selected Function : PB0          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[17]  eTIMER_1_CH3_SSCM_Debug_1_CAN_0_Rx_CAN_1_Rx_PB1 (C14) */
    /* ----------------------------------------------------------- */
       SIU.PCR[17].R = 0x0000;
             /*	Selected Function : PB1          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[18]  LINFlex_0_Tx_SSCM_Debug_2_PB2 (A14) */
    /* ----------------------------------------------------------- */
       SIU.PCR[18].R = 0x0000;
             /*	Selected Function : PB2          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[19]  SSCM_Debug_3_LINFlex_0_Rx_PB3 (B13) */
    /* ----------------------------------------------------------- */
       SIU.PCR[19].R = 0x0000;
             /*	Selected Function : PB3          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[20]  JTAG_TDO_PB4 (L17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[20].R = 0x0604;
             /*	Selected Function : JTAG_TDO          */
             /*	Output Buffers : Enabled          */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Medium        */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[21]  JTAG_TDI_PB5 (M15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[21].R = 0x4103;
             /*	Selected Function : PB5 I          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Enabled           */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Enabled       */
             /*	Weak Pull Up/Down Select : Up     */
             /*	Safe Mode Control: Enabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[22]  CLKOUT_PCS_2.2_PB6 (B3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[22].R = 0x0604;
             /*	Selected Function : CLKOUT          */
             /*	Output Buffers : Enabled          */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Medium        */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[23]  LINFlex_0_Rx_ADC_0_AN0_PB7 (R5) */
    /* ----------------------------------------------------------- */
       SIU.PCR[23].R = 0x0000;
             /*	Selected Function : PB7          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[24]  eTIMER_0_CH5_ADC_0_AN1_PB8 (P7) */
    /* ----------------------------------------------------------- */
       SIU.PCR[24].R = 0x0000;
             /*	Selected Function : PB8          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[25]  ADC_0_ADC_1_AN11_PB9 (U7) */
    /* ----------------------------------------------------------- */
       SIU.PCR[25].R = 0x0000;
             /*	Selected Function : PB9          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[26]  ADC_0_ADC_1_AN12_PB10 (R8) */
    /* ----------------------------------------------------------- */
       SIU.PCR[26].R = 0x0000;
             /*	Selected Function : PB10          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[27]  ADC_0_ADC_1_AN13_PB11 (T8) */
    /* ----------------------------------------------------------- */
       SIU.PCR[27].R = 0x0000;
             /*	Selected Function : PB11          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[28]  ADC_0_ADC_1_AN14_PB12 (U8) */
    /* ----------------------------------------------------------- */
       SIU.PCR[28].R = 0x0000;
             /*	Selected Function : PB12          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[29]  LINFlex_1_Rx_ADC_1_AN0_PB13 (R10) */
    /* ----------------------------------------------------------- */
       SIU.PCR[29].R = 0x0000;
             /*	Selected Function : PB13          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[30]  eTIMER_0_CH4_ADC_1_AN1_PB14 (P11) */
    /* ----------------------------------------------------------- */
       SIU.PCR[30].R = 0x0000;
             /*	Selected Function : PB14          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[31]  ADC_1_AN2_PB15 (R11) */
    /* ----------------------------------------------------------- */
       SIU.PCR[31].R = 0x0000;
             /*	Selected Function : PB15          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

}


/* ----------------------------------------------------------- */
/*                 SIU PORT C PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_portC_init_fnc(void)
{
    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[32]  ADC_1_AN3_PC0 (R12) */
    /* ----------------------------------------------------------- */
       SIU.PCR[32].R = 0x0000;
             /*	Selected Function : PC0          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[33]  ADC_0_AN2_PC1 (T4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[33].R = 0x0000;
             /*	Selected Function : PC1          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[34]  ADC_0_AN3_PC2 (U5) */
    /* ----------------------------------------------------------- */
       SIU.PCR[34].R = 0x0000;
             /*	Selected Function : PC2          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[36]  PCS_0.0_FlexPWM0_X_1_SSCM_Debug_4_PC4 (H3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[36].R = 0x0000;
             /*	Selected Function : PC4          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[37]  SCK_0_SSCM_Debug_5_FlexPWM0_Fault_3_PC5 (G3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[37].R = 0x0000;
             /*	Selected Function : PC5          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[38]  SOUT_0_FlexPWM0_B_1_SSCM_Debug_6_PC6 (D4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[38].R = 0x0000;
             /*	Selected Function : PC6          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[39]  FlexPWM0_A_1_SSCM_Debug_7_SIN_0_PC7 (K4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[39].R = 0x0000;
             /*	Selected Function : PC7          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[42]  PCS_2.2_FlexPWM0_A_3_FlexPWM0_Fault_1_PC10 (A15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[42].R = 0x0000;
             /*	Selected Function : PC10          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[43]  eTIMER_0_CH4_PCS_2.2_PC11 (M14) */
    /* ----------------------------------------------------------- */
       SIU.PCR[43].R = 0x0000;
             /*	Selected Function : PC11          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[44]  eTIMER_0_CH5_PCS_2.3_PC12 (N15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[44].R = 0x0000;
             /*	Selected Function : PC12          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[45]  eTIMER_1_CH1_CTU_EXT_IN_FlexPWM0_Ext_Sync_PC13 (F15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[45].R = 0x0000;
             /*	Selected Function : PC13          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[46]  eTIMER_1_CH2_CTU_EXT_TGR_PC14 (E15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[46].R = 0x0000;
             /*	Selected Function : PC14          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[47]  FlexRay_A_TX_EN_eTIMER_1_CH0_FlexPWM0_A_1_CTU_EXT_IN_FlexPWM0_Ext_Sync_PC15 (A8) */
    /* ----------------------------------------------------------- */
       SIU.PCR[47].R = 0x0000;
             /*	Selected Function : PC15          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

}


/* ----------------------------------------------------------- */
/*                 SIU PORT D PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_portD_init_fnc(void)
{
    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[48]  FlexRay_A_TX_eTIMER_1_CH1_FlexPWM0_B_1_PD0 (B8) */
    /* ----------------------------------------------------------- */
       SIU.PCR[48].R = 0x0000;
             /*	Selected Function : PD0          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[49]  eTIMER_1_CH2_CTU_EXT_TGR_FlexRay_A_RX_PD1 (E3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[49].R = 0x0000;
             /*	Selected Function : PD1          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[50]  eTIMER_1_CH3_FlexPWM0_X_3_FlexRay_B_RX_PD2 (C5) */
    /* ----------------------------------------------------------- */
       SIU.PCR[50].R = 0x0000;
             /*	Selected Function : PD2          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[51]  FlexRay_B_TX_eTIMER_1_CH4_FlexPWM0_A_3_PD3 (A7) */
    /* ----------------------------------------------------------- */
       SIU.PCR[51].R = 0x0000;
             /*	Selected Function : PD3          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[52]  FlexRay_B_TX_EN_eTIMER_1_CH5_FlexPWM0_B_3_PD4 (B7) */
    /* ----------------------------------------------------------- */
       SIU.PCR[52].R = 0x0000;
             /*	Selected Function : PD4          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[53]  PCS_0.3_FlexPWM0_Fault_2_PD5 (N3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[53].R = 0x0000;
             /*	Selected Function : PD5          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[54]  PCS_0.2_FlexPWM0_X_3_FlexPWM0_Fault_1_PD6 (P3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[54].R = 0x0000;
             /*	Selected Function : PD6          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[55]  PCS_1.3_PCS_0.4_SWG AN_OP_PD7 (R4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[55].R = 0x0000;
             /*	Selected Function : PD7          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[56]  PCS_1.2_eTIMER_1_CH4_PCS_0.5_FlexPWM0_Fault_3_PD8 (M3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[56].R = 0x0000;
             /*	Selected Function : PD8          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[57]  FlexPWM0_X_0_LINFlex_1_Tx_PD9 (L3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[57].R = 0x0000;
             /*	Selected Function : PD9          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[58]  FlexPWM0_A_0_eTIMER_0_CH0_PD10 (T15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[58].R = 0x0000;
             /*	Selected Function : PD10          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[59]  FlexPWM0_B_0_eTIMER_0_CH1_PD11 (R16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[59].R = 0x0000;
             /*	Selected Function : PD11          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[60]  FlexPWM0_X_1_LINFlex_1_Rx_PD12 (G14) */
    /* ----------------------------------------------------------- */
       SIU.PCR[60].R = 0x0000;
             /*	Selected Function : PD12          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[62]  FlexPWM0_B_1_eTIMER_0_CH3_PD14 (D16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[62].R = 0x0000;
             /*	Selected Function : PD14          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

}


/* ----------------------------------------------------------- */
/*                 SIU PORT E PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_portE_init_fnc(void)
{
    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[64]  ADC_1_AN5_PE0 (T13) */
    /* ----------------------------------------------------------- */
       SIU.PCR[64].R = 0x0000;
             /*	Selected Function : PE0          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[66]  ADC_0_AN5_PE2 (U6) */
    /* ----------------------------------------------------------- */
       SIU.PCR[66].R = 0x0000;
             /*	Selected Function : PE2          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[68]  ADC_0_AN7_PE4 (U4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[68].R = 0x0000;
             /*	Selected Function : PE4          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[69]  ADC_0_AN8_PE5 (T5) */
    /* ----------------------------------------------------------- */
       SIU.PCR[69].R = 0x0000;
             /*	Selected Function : PE5          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[70]  ADC_0_AN4_PE6 (R6) */
    /* ----------------------------------------------------------- */
       SIU.PCR[70].R = 0x0000;
             /*	Selected Function : PE6          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[71]  ADC_0_AN6_PE7 (T6) */
    /* ----------------------------------------------------------- */
       SIU.PCR[71].R = 0x0000;
             /*	Selected Function : PE7          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[73]  ADC_1_AN7_PE9 (T10) */
    /* ----------------------------------------------------------- */
       SIU.PCR[73].R = 0x0000;
             /*	Selected Function : PE9          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[74]  ADC_1_AN8_PE10 (T11) */
    /* ----------------------------------------------------------- */
       SIU.PCR[74].R = 0x0000;
             /*	Selected Function : PE10          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[75]  ADC_1_AN4_PE11 (U11) */
    /* ----------------------------------------------------------- */
       SIU.PCR[75].R = 0x0000;
             /*	Selected Function : PE11          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[76]  ADC_1_AN6_PE12 (T12) */
    /* ----------------------------------------------------------- */
       SIU.PCR[76].R = 0x0000;
             /*	Selected Function : PE12          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[77]  eTIMER_0_CH5_PCS_2.3_PE13 (D12) */
    /* ----------------------------------------------------------- */
       SIU.PCR[77].R = 0x0000;
             /*	Selected Function : PE13          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[78]  eTIMER_1_CH5_PE14 (B12) */
    /* ----------------------------------------------------------- */
       SIU.PCR[78].R = 0x0000;
             /*	Selected Function : PE14          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[79]  PCS_0.1_PE15 (B11) */
    /* ----------------------------------------------------------- */
       SIU.PCR[79].R = 0x0000;
             /*	Selected Function : PE15          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

}


/* ----------------------------------------------------------- */
/*                 SIU PORT F PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_portF_init_fnc(void)
{
    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[80]  FlexPWM0_A_1_eTIMER_0_CH2_PF0 (D7) */
    /* ----------------------------------------------------------- */
       SIU.PCR[80].R = 0x0000;
             /*	Selected Function : PF0          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[83]  PCS_0.6_PF3 (B5) */
    /* ----------------------------------------------------------- */
       SIU.PCR[83].R = 0x0000;
             /*	Selected Function : PF3          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[84]  Nexus_MDO_3_PF4 (D2) */
    /* ----------------------------------------------------------- */
       SIU.PCR[84].R = 0x0000;
             /*	Selected Function : PF4          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[85]  Nexus_MDO_2_PF5 (D1) */
    /* ----------------------------------------------------------- */
       SIU.PCR[85].R = 0x0000;
             /*	Selected Function : PF5          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[86]  Nexus_MDO_1_PF6 (E2) */
    /* ----------------------------------------------------------- */
       SIU.PCR[86].R = 0x0000;
             /*	Selected Function : PF6          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[87]  Nexus_MCKO_PF7 (J1) */
    /* ----------------------------------------------------------- */
       SIU.PCR[87].R = 0x0000;
             /*	Selected Function : PF7          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[88]  Nexus_MSEO1_PF8 (K2) */
    /* ----------------------------------------------------------- */
       SIU.PCR[88].R = 0x0000;
             /*	Selected Function : PF8          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[89]  Nexus_MSEO0_PF9 (K1) */
    /* ----------------------------------------------------------- */
       SIU.PCR[89].R = 0x0000;
             /*	Selected Function : PF9          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[90]  Nexus_EVTO_PF10 (L1) */
    /* ----------------------------------------------------------- */
       SIU.PCR[90].R = 0x0000;
             /*	Selected Function : PF10          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[91]  Nexus_EVTI_PF11 (L2) */
    /* ----------------------------------------------------------- */
       SIU.PCR[91].R = 0x0000;
             /*	Selected Function : PF11          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[92]  eTIMER_1_CH3_PF12 (C17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[92].R = 0x0000;
             /*	Selected Function : PF12          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[93]  eTIMER_1_CH4_PF13 (B14) */
    /* ----------------------------------------------------------- */
       SIU.PCR[93].R = 0x0000;
             /*	Selected Function : PF13          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[94]  LINFlex_1_Tx_PF14 (C13) */
    /* ----------------------------------------------------------- */
       SIU.PCR[94].R = 0x0000;
             /*	Selected Function : PF14          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[95]  LINFlex_1_Rx_PF15 (D13) */
    /* ----------------------------------------------------------- */
       SIU.PCR[95].R = 0x0000;
             /*	Selected Function : PF15          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

}


/* ----------------------------------------------------------- */
/*                 SIU PORT G PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_portG_init_fnc(void)
{
    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[98]  FlexPWM0_X_2_PCS_1.1_PG2 (E16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[98].R = 0x0000;
             /*	Selected Function : PG2          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[99]  FlexPWM0_A_2_eTIMER_0_CH4_PG3 (D17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[99].R = 0x0000;
             /*	Selected Function : PG3          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[100]  FlexPWM0_B_2_eTIMER_0_CH5_PG4 (F17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[100].R = 0x0000;
             /*	Selected Function : PG4          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[101]  FlexPWM0_X_3_PCS_2.3_PG5 (N17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[101].R = 0x0000;
             /*	Selected Function : PG5          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[102]  FlexPWM0_A_3_PG6 (G17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[102].R = 0x0000;
             /*	Selected Function : PG6          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[103]  FlexPWM0_B_3_PG7 (P17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[103].R = 0x0000;
             /*	Selected Function : PG7          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[104]  FlexRay_DEBUG_0_PCS_0.1_FlexPWM0_Fault_0_PG8 (P16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[104].R = 0x0000;
             /*	Selected Function : PG8          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[105]  FlexRay_DEBUG_1_PCS_1.1_FlexPWM0_Fault_1_PG9 (R17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[105].R = 0x0000;
             /*	Selected Function : PG9          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[106]  FlexRay_DEBUG_2_PCS_2.3_FlexPWM0_Fault_2_PG10 (P15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[106].R = 0x0000;
             /*	Selected Function : PG10          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[107]  FlexRay_DEBUG_3_FlexPWM0_Fault_3_PG11 (U15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[107].R = 0x0000;
             /*	Selected Function : PG11          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[108]  Nexus_MDO_11_PG12 (F2) */
    /* ----------------------------------------------------------- */
       SIU.PCR[108].R = 0x0000;
             /*	Selected Function : PG12          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[109]  Nexus_MDO_10_PG13 (H1) */
    /* ----------------------------------------------------------- */
       SIU.PCR[109].R = 0x0000;
             /*	Selected Function : PG13          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[110]  Nexus_MDO_9_PG14 (A6) */
    /* ----------------------------------------------------------- */
       SIU.PCR[110].R = 0x0000;
             /*	Selected Function : PG14          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[111]  Nexus_MDO_8_PG15 (J2) */
    /* ----------------------------------------------------------- */
       SIU.PCR[111].R = 0x0000;
             /*	Selected Function : PG15          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

}


/* ----------------------------------------------------------- */
/*                 SIU PORT H PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_portH_init_fnc(void)
{
    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[112]  Nexus_MDO_7_PH0 (A5) */
    /* ----------------------------------------------------------- */
       SIU.PCR[112].R = 0x0000;
             /*	Selected Function : PH0          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[113]  Nexus_MDO_6_PH1 (F1) */
    /* ----------------------------------------------------------- */
       SIU.PCR[113].R = 0x0000;
             /*	Selected Function : PH1          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[114]  Nexus_MDO_5_PH2 (A4) */
    /* ----------------------------------------------------------- */
       SIU.PCR[114].R = 0x0000;
             /*	Selected Function : PH2          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[115]  Nexus_MDO_4_PH3 (G1) */
    /* ----------------------------------------------------------- */
       SIU.PCR[115].R = 0x0000;
             /*	Selected Function : PH3          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[116]  FlexPWM1_X_0_eTIMER_2_CH0_PH4 (L16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[116].R = 0x0000;
             /*	Selected Function : PH4          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[117]  FlexPWM1_A_0_PCS_0.4_PH5 (M17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[117].R = 0x0000;
             /*	Selected Function : PH5          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[118]  FlexPWM1_B_0_PCS_0.5_PH6 (H17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[118].R = 0x0000;
             /*	Selected Function : PH6          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[119]  FlexPWM1_X_1_eTIMER_2_CH1_PH7 (K16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[119].R = 0x0000;
             /*	Selected Function : PH7          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[120]  FlexPWM1_A_1_PCS_0.6_PH8 (K15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[120].R = 0x0000;
             /*	Selected Function : PH8          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[121]  FlexPWM1_B_1_PCS_0.7_PH9 (G16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[121].R = 0x0000;
             /*	Selected Function : PH9          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[122]  FlexPWM1_X_2_eTIMER_2_CH2_PH10 (A11) */
    /* ----------------------------------------------------------- */
       SIU.PCR[122].R = 0x0000;
             /*	Selected Function : PH10          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[123]  FlexPWM1_A_2_PH11 (C11) */
    /* ----------------------------------------------------------- */
       SIU.PCR[123].R = 0x0000;
             /*	Selected Function : PH11          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[124]  FlexPWM1_B_2_PH12 (B10) */
    /* ----------------------------------------------------------- */
       SIU.PCR[124].R = 0x0000;
             /*	Selected Function : PH12          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[125]  FlexPWM1_X_3_eTIMER_2_CH3_PH13 (G15) */
    /* ----------------------------------------------------------- */
       SIU.PCR[125].R = 0x0000;
             /*	Selected Function : PH13          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[126]  FlexPWM1_A_3_eTIMER_2_CH4_PH14 (A12) */
    /* ----------------------------------------------------------- */
       SIU.PCR[126].R = 0x0000;
             /*	Selected Function : PH14          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[127]  FlexPWM1_B_3_eTIMER_2_CH5_PH15 (J17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[127].R = 0x0000;
             /*	Selected Function : PH15          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

}


/* ----------------------------------------------------------- */
/*                 SIU PORT I PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_portI_init_fnc(void)
{
    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[128]  eTIMER_2_CH0_PCS_0.4_FlexPWM1_Fault_0_PI0 (C9) */
    /* ----------------------------------------------------------- */
       SIU.PCR[128].R = 0x0000;
             /*	Selected Function : PI0          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[129]  eTIMER_2_CH1_PCS_0.5_FlexPWM1_Fault_1_PI1 (C12) */
    /* ----------------------------------------------------------- */
       SIU.PCR[129].R = 0x0000;
             /*	Selected Function : PI1          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[130]  eTIMER_2_CH2_PCS_0.6_FlexPWM1_Fault_2_PI2 (F16) */
    /* ----------------------------------------------------------- */
       SIU.PCR[130].R = 0x0000;
             /*	Selected Function : PI2          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[131]  eTIMER_2_CH3_PCS_0.7_CTU_EXT_TGR_FlexPWM1_Fault_3_PI3 (E17) */
    /* ----------------------------------------------------------- */
       SIU.PCR[131].R = 0x0000;
             /*	Selected Function : PI3          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

    /* ----------------------------------------------------------- */
    /*      Pad Configuration Register PCR[132]  Nexus_RDY_PI4 (K3) */
    /* ----------------------------------------------------------- */
       SIU.PCR[132].R = 0x0000;
             /*	Selected Function : PI4          */
             /*	Output Buffers : Disabled         */
             /*	Input Buffers : Disabled          */
             /*	Output Drain : Disabled           */
             /*	Slew Rate Control : Minimum       */
             /*	Weak Pull Up/Down : Disabled      */
             /*	Weak Pull Up/Down Select : Down   */
             /*	Safe Mode Control: Disabled       */

}


/* ----------------------------------------------------------- */
/*               SIU General PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_general_init_fnc(void)
{

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Clock Prescaler Register- IFCPR    */
    /* ----------------------------------------------------------- */
        SIU.IFCPR.R = 0x00000000;
 		    /* Filter Clock Prescalar:- 1     */

    /* ----------------------------------------------------------- */
    /*   Interrupt Request Enable Register- IRER    */
    /* ----------------------------------------------------------- */
        SIU.IRER.R = 0x00000000;
             /* Edge Trigger External Interrupt 0 Enable :-Disabled */
             /* Edge Trigger External Interrupt 1 Enable :-Disabled */
             /* Edge Trigger External Interrupt 2 Enable :-Disabled */
             /* Edge Trigger External Interrupt 3 Enable :-Disabled */
             /* Edge Trigger External Interrupt 4 Enable :-Disabled */
             /* Edge Trigger External Interrupt 5 Enable :-Disabled */
             /* Edge Trigger External Interrupt 6 Enable :-Disabled */
             /* Edge Trigger External Interrupt 7 Enable :-Disabled */
             /* Edge Trigger External Interrupt 8 Enable :-Disabled */
             /* Edge Trigger External Interrupt 9 Enable :-Disabled */
             /* Edge Trigger External Interrupt 10 Enable :-Disabled */
             /* Edge Trigger External Interrupt 11 Enable :-Disabled */
             /* Edge Trigger External Interrupt 12 Enable :-Disabled */
             /* Edge Trigger External Interrupt 13 Enable :-Disabled */
             /* Edge Trigger External Interrupt 14 Enable :-Disabled */
             /* Edge Trigger External Interrupt 15 Enable :-Disabled */
             /* Edge Trigger External Interrupt 16 Enable :-Disabled */
             /* Edge Trigger External Interrupt 17 Enable :-Disabled */
             /* Edge Trigger External Interrupt 18 Enable :-Disabled */
             /* Edge Trigger External Interrupt 19 Enable :-Disabled */
             /* Edge Trigger External Interrupt 20 Enable :-Disabled */
             /* Edge Trigger External Interrupt 21 Enable :-Disabled */
             /* Edge Trigger External Interrupt 22 Enable :-Disabled */
             /* Edge Trigger External Interrupt 23 Enable :-Disabled */
             /* Edge Trigger External Interrupt 24 Enable :-Disabled */
             /* Edge Trigger External Interrupt 25 Enable :-Disabled */
             /* Edge Trigger External Interrupt 26 Enable :-Disabled */
             /* Edge Trigger External Interrupt 27 Enable :-Disabled */
             /* Edge Trigger External Interrupt 28 Enable :-Disabled */
             /* Edge Trigger External Interrupt 29 Enable :-Disabled */
             /* Edge Trigger External Interrupt 30 Enable :-Disabled */
             /* Edge Trigger External Interrupt 31 Enable :-Disabled */

    /* ----------------------------------------------------------- */
    /*   External IRQ Rising-Edge Event Enable Register - IREER    */
    /* ----------------------------------------------------------- */
        SIU.IREER.R = 0x00000000;

             /* NMI 0 Rising-Edge Event : Disabled */

             /* IRQ 0 Rising-Edge Event : Disabled */
             /* IRQ 1 Rising-Edge Event : Disabled */
             /* IRQ 2 Rising-Edge Event : Disabled */
             /* IRQ 3 Rising-Edge Event : Disabled */
             /* IRQ 4 Rising-Edge Event : Disabled */
             /* IRQ 5 Rising-Edge Event : Disabled */
             /* IRQ 6 Rising-Edge Event : Disabled */
             /* IRQ 7 Rising-Edge Event : Disabled */
             /* IRQ 8 Rising-Edge Event : Disabled */
             /* IRQ 9 Rising-Edge Event : Disabled */
             /* IRQ 10 Rising-Edge Event : Disabled */
             /* IRQ 11 Rising-Edge Event : Disabled */
             /* IRQ 12 Rising-Edge Event : Disabled */
             /* IRQ 13 Rising-Edge Event : Disabled */
             /* IRQ 14 Rising-Edge Event : Disabled */
             /* IRQ 15 Rising-Edge Event : Disabled */
             /* IRQ 16 Rising-Edge Event : Disabled */
             /* IRQ 17 Rising-Edge Event : Disabled */
             /* IRQ 18 Rising-Edge Event : Disabled */
             /* IRQ 19 Rising-Edge Event : Disabled */
             /* IRQ 20 Rising-Edge Event : Disabled */
             /* IRQ 21 Rising-Edge Event : Disabled */
             /* IRQ 22 Rising-Edge Event : Disabled */
             /* IRQ 23 Rising-Edge Event : Disabled */
             /* IRQ 24 Rising-Edge Event : Disabled */
             /* IRQ 25 Rising-Edge Event : Disabled */
             /* IRQ 26 Rising-Edge Event : Disabled */
             /* IRQ 27 Rising-Edge Event : Disabled */
             /* IRQ 28 Rising-Edge Event : Disabled */
             /* IRQ 29 Rising-Edge Event : Disabled */
             /* IRQ 30 Rising-Edge Event : Disabled */
             /* IRQ 31 Rising-Edge Event : Disabled */

    /* ----------------------------------------------------------- */
    /*   External IRQ Falling-Edge Event Enable Register - IFEER   */
    /* ----------------------------------------------------------- */
        SIU.IFEER.R = 0x00000000;

             /* IRQ 0 Falling-Edge Event : Disabled */
             /* IRQ 1 Falling-Edge Event : Disabled */
             /* IRQ 2 Falling-Edge Event : Disabled */
             /* IRQ 3 Falling-Edge Event : Disabled */
             /* IRQ 4 Falling-Edge Event : Disabled */
             /* IRQ 5 Falling-Edge Event : Disabled */
             /* IRQ 6 Falling-Edge Event : Disabled */
             /* IRQ 7 Falling-Edge Event : Disabled */
             /* IRQ 8 Falling-Edge Event : Disabled */
             /* IRQ 9 Falling-Edge Event : Disabled */
             /* IRQ 10 Falling-Edge Event : Disabled */
             /* IRQ 11 Falling-Edge Event : Disabled */
             /* IRQ 12 Falling-Edge Event : Disabled */
             /* IRQ 13 Falling-Edge Event : Disabled */
             /* IRQ 14 Falling-Edge Event : Disabled */
             /* IRQ 15 Falling-Edge Event : Disabled */
             /* IRQ 16 Falling-Edge Event : Disabled */
             /* IRQ 17 Falling-Edge Event : Disabled */
             /* IRQ 18 Falling-Edge Event : Disabled */
             /* IRQ 19 Falling-Edge Event : Disabled */
             /* IRQ 20 Falling-Edge Event : Disabled */
             /* IRQ 21 Falling-Edge Event : Disabled */
             /* IRQ 22 Falling-Edge Event : Disabled */
             /* IRQ 23 Falling-Edge Event : Disabled */
             /* IRQ 24 Falling-Edge Event : Disabled */
             /* IRQ 25 Falling-Edge Event : Disabled */
             /* IRQ 26 Falling-Edge Event : Disabled */
             /* IRQ 27 Falling-Edge Event : Disabled */
             /* IRQ 28 Falling-Edge Event : Disabled */
             /* IRQ 29 Falling-Edge Event : Disabled */
             /* IRQ 30 Falling-Edge Event : Disabled */
             /* IRQ 31 Falling-Edge Event : Disabled */

    /* ----------------------------------------------------------- */
    /*    Interrupt Filter Enable Register - IFER    */
    /* ----------------------------------------------------------- */
        SIU.IFER.R = 0x00000000;
             /* Analog glitch filter on External Input 0 Pad:- Disabled */
             /* Analog glitch filter on External Input 1 Pad:- Disabled */
             /* Analog glitch filter on External Input 2 Pad:- Disabled */
             /* Analog glitch filter on External Input 3 Pad:- Disabled */
             /* Analog glitch filter on External Input 4 Pad:- Disabled */
             /* Analog glitch filter on External Input 5 Pad:- Disabled */
             /* Analog glitch filter on External Input 6 Pad:- Disabled */
             /* Analog glitch filter on External Input 7 Pad:- Disabled */
             /* Analog glitch filter on External Input 8 Pad:- Disabled */
             /* Analog glitch filter on External Input 9 Pad:- Disabled */
             /* Analog glitch filter on External Input 10 Pad:- Disabled */
             /* Analog glitch filter on External Input 11 Pad:- Disabled */
             /* Analog glitch filter on External Input 12 Pad:- Disabled */
             /* Analog glitch filter on External Input 13 Pad:- Disabled */
             /* Analog glitch filter on External Input 14 Pad:- Disabled */
             /* Analog glitch filter on External Input 15 Pad:- Disabled */
             /* Analog glitch filter on External Input 16 Pad:- Disabled */
             /* Analog glitch filter on External Input 17 Pad:- Disabled */
             /* Analog glitch filter on External Input 18 Pad:- Disabled */
             /* Analog glitch filter on External Input 19 Pad:- Disabled */
             /* Analog glitch filter on External Input 20 Pad:- Disabled */
             /* Analog glitch filter on External Input 21 Pad:- Disabled */
             /* Analog glitch filter on External Input 22 Pad:- Disabled */
             /* Analog glitch filter on External Input 23 Pad:- Disabled */
             /* Analog glitch filter on External Input 24 Pad:- Disabled */
             /* Analog glitch filter on External Input 25 Pad:- Disabled */
             /* Analog glitch filter on External Input 26 Pad:- Disabled */
             /* Analog glitch filter on External Input 27 Pad:- Disabled */
             /* Analog glitch filter on External Input 28 Pad:- Disabled */
             /* Analog glitch filter on External Input 29 Pad:- Disabled */
             /* Analog glitch filter on External Input 30 Pad:- Disabled */
             /* Analog glitch filter on External Input 31 Pad:- Disabled */

    /* ----------------------------------------------------------- */
    /*          NMI Configuration Register - NCR       */
    /* ----------------------------------------------------------- */
        WKUP.NCR.R = 0x00000000;
             /* NMI 0 Destination Source Select:- Non-maskable interrupt */
             /* NMI 0 Rising Edge Trigger Event:- Disabled  */
             /* NMI 0 Falling Edge Trigger Event:- Disabled  */
             /* Analog glitch filter on NMI 0 Input pad:- Disabled    */
    

        WKUP.NCR.B.NLOCK0 = 0;
             /* NMI Configuration Lock:- Disabled */

    
    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register0- IFMC0    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[0].R = 0x00000000;
        /* External Interrupt 0 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register1- IFMC1    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[1].R = 0x00000000;
        /* External Interrupt 1 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register2- IFMC2    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[2].R = 0x00000000;
        /* External Interrupt 2 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register3- IFMC3    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[3].R = 0x00000000;
        /* External Interrupt 3 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register4- IFMC4    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[4].R = 0x00000000;
        /* External Interrupt 4 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register5- IFMC5    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[5].R = 0x00000000;
        /* External Interrupt 5 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register6- IFMC6    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[6].R = 0x00000000;
        /* External Interrupt 6 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register7- IFMC7    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[7].R = 0x00000000;
        /* External Interrupt 7 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register8- IFMC8    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[8].R = 0x00000000;
        /* External Interrupt 8 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register9- IFMC9    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[9].R = 0x00000000;
        /* External Interrupt 9 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register10- IFMC10    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[10].R = 0x00000000;
        /* External Interrupt 10 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register11- IFMC11    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[11].R = 0x00000000;
        /* External Interrupt 11 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register12- IFMC12    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[12].R = 0x00000000;
        /* External Interrupt 12 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register13- IFMC13    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[13].R = 0x00000000;
        /* External Interrupt 13 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register14- IFMC14    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[14].R = 0x00000000;
        /* External Interrupt 14 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register15- IFMC15    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[15].R = 0x00000000;
        /* External Interrupt 15 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register16- IFMC16    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[16].R = 0x00000000;
        /* External Interrupt 16 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register17- IFMC17    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[17].R = 0x00000000;
        /* External Interrupt 17 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register18- IFMC18    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[18].R = 0x00000000;
        /* External Interrupt 18 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register19- IFMC19    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[19].R = 0x00000000;
        /* External Interrupt 19 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register20- IFMC20    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[20].R = 0x00000000;
        /* External Interrupt 20 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register21- IFMC21    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[21].R = 0x00000000;
        /* External Interrupt 21 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register22- IFMC22    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[22].R = 0x00000000;
        /* External Interrupt 22 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register23- IFMC23    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[23].R = 0x00000000;
        /* External Interrupt 23 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register24- IFMC24    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[24].R = 0x00000000;
        /* External Interrupt 24 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register25- IFMC25    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[25].R = 0x00000000;
        /* External Interrupt 25 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register26- IFMC26    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[26].R = 0x00000000;
        /* External Interrupt 26 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register27- IFMC27    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[27].R = 0x00000000;
        /* External Interrupt 27 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register28- IFMC28    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[28].R = 0x00000000;
        /* External Interrupt 28 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register29- IFMC29    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[29].R = 0x00000000;
        /* External Interrupt 29 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register30- IFMC30    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[30].R = 0x00000000;
        /* External Interrupt 30 maximum Filter Counter:- 0 */

    /* ----------------------------------------------------------- */
    /*   Interrupt Filter Maximum Counter Register31- IFMC31    */
    /* ----------------------------------------------------------- */
        SIU.IFMC[31].R = 0x00000000;
        /* External Interrupt 31 maximum Filter Counter:- 0 */

}


/* ----------------------------------------------------------- */
/*                 SIU Parallel PORT PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_parallel_port_init_fnc(void)
{
  /* ----------------------------------------------------------- */
  /*       Masked Parallel GPIO Pin Data Output Register 0        */
  /* ----------------------------------------------------------- */
        SIU.MPGPDO[0].R = 0x00000000;
           /*   Port A Mask: 0x0000       */
           /*   Port A Data: 0x0000       */

  /* ----------------------------------------------------------- */
  /*       Masked Parallel GPIO Pin Data Output Register 1        */
  /* ----------------------------------------------------------- */
        SIU.MPGPDO[1].R = 0x00000000;
           /*   Port B Mask: 0x0000       */
           /*   Port B Data: 0x0000       */

  /* ----------------------------------------------------------- */
  /*       Masked Parallel GPIO Pin Data Output Register 2        */
  /* ----------------------------------------------------------- */
        SIU.MPGPDO[2].R = 0x00000000;
           /*   Port C Mask: 0x0000       */
           /*   Port C Data: 0x0000       */

  /* ----------------------------------------------------------- */
  /*       Masked Parallel GPIO Pin Data Output Register 3        */
  /* ----------------------------------------------------------- */
        SIU.MPGPDO[3].R = 0x00000000;
           /*   Port D Mask: 0x0000       */
           /*   Port D Data: 0x0000       */

  /* ----------------------------------------------------------- */
  /*       Masked Parallel GPIO Pin Data Output Register 4        */
  /* ----------------------------------------------------------- */
        SIU.MPGPDO[4].R = 0x00000000;
           /*   Port E Mask: 0x0000       */
           /*   Port E Data: 0x0000       */

  /* ----------------------------------------------------------- */
  /*       Masked Parallel GPIO Pin Data Output Register 5        */
  /* ----------------------------------------------------------- */
        SIU.MPGPDO[5].R = 0x00000000;
           /*   Port F Mask: 0x0000       */
           /*   Port F Data: 0x0000       */

  /* ----------------------------------------------------------- */
  /*       Masked Parallel GPIO Pin Data Output Register 6        */
  /* ----------------------------------------------------------- */
        SIU.MPGPDO[6].R = 0x00000000;
           /*   Port G Mask: 0x0000       */
           /*   Port G Data: 0x0000       */

  /* ----------------------------------------------------------- */
  /*       Masked Parallel GPIO Pin Data Output Register 7        */
  /* ----------------------------------------------------------- */
        SIU.MPGPDO[7].R = 0x00000000;
           /*   Port H Mask: 0x0000       */
           /*   Port H Data: 0x0000       */


}


/* ----------------------------------------------------------- */
/*               SIU Unused Pins Configuration                 */
/* ----------------------------------------------------------- */
void siu_unused_pins_init_fnc(void)
{
}


/* ----------------------------------------------------------- */
/*               SIU PSMI PAD Configuration                 */
/* ----------------------------------------------------------- */
void siu_psmi_init_fnc(void)
{
/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[0]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[0].R = 0x00;
                /*Function Pad Selected CTU EXT_IN :- PCR45*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[1]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[1].R = 0x00;
                /*Function Pad Selected DSPI2_SCK :- PCR0*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[2]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[2].R = 0x00;
                /*Function Pad Selected DSPI2_SIN :- PCR2*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[3]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[3].R = 0x00;
                /*Function Pad Selected DSPI2_CS0 :- PCR3*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[7]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[7].R = 0x00;
                /*Function Pad Selected eTimer0_CH4 :- PCR4*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[8]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[8].R = 0x00;
                /*Function Pad Selected eTimer0_CH5 :- PCR44*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[9]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[9].R = 0x00;
                /*Function Pad Selected eTimer1_CH0 :- PCR4*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[10]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[10].R = 0x00;
                /*Function Pad Selected eTimer1_CH1 :- PCR45*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[11]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[11].R = 0x00;
                /*Function Pad Selected eTimer1_CH2 :- PCR16*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[12]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[12].R = 0x00;
                /*Function Pad Selected eTimer1_CH3 :- PCR17*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[13]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[13].R = 0x00;
                /*Function Pad Selected eTimer1_CH4 :- PCR14*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[14]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[14].R = 0x00;
                /*Function Pad Selected eTimer1_CH5 :- PCR5*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[15]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[15].R = 0x00;
                /*Function Pad Selected FlexPWM0 EXT_SYNC :- PCR45*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[16]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[16].R = 0x00;
                /*Function Pad Selected FlexPWM0 FAULT_0 :- PCR9*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[17]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[17].R = 0x00;
                /*Function Pad Selected FlexPWM0 FAULT_1 :- PCR42*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[18]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[18].R = 0x00;
                /*Function Pad Selected FlexPWM0 FAULT_2 :- PCR53*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[19]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[19].R = 0x00;
                /*Function Pad Selected FlexPWM0 FAULT_3 :- PCR37*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[20]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[20].R = 0x00;
                /*Function Pad Selected FlexPWM0 A_0 :- PCR11*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[21]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[21].R = 0x00;
                /*Function Pad Selected FlexPWM0 A_1 :- PCR39*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[22]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[22].R = 0x00;
                /*Function Pad Selected FlexPWM0 A_2 :- PCR11*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[23]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[23].R = 0x00;
                /*Function Pad Selected FlexPWM0 A_3 :- PCR2*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[24]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[24].R = 0x00;
                /*Function Pad Selected FlexPWM0 B_0 :- PCR10*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[25]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[25].R = 0x00;
                /*Function Pad Selected FlexPWM0 B_1 :- PCR38*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[26]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[26].R = 0x00;
                /*Function Pad Selected FlexPWM0 B_2 :- PCR12*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[27]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[27].R = 0x00;
                /*Function Pad Selected FlexPWM0 B_3 :- PCR3*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[28]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[28].R = 0x00;
                /*Function Pad Selected FlexPWM0 X_1 :- PCR36*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[29]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[29].R = 0x00;
                /*Function Pad Selected FlexPWM0 X_2 :- PCR10*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[30]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[30].R = 0x00;
                /*Function Pad Selected FlexPWM0 X_3 :- PCR50*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[31]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[31].R = 0x00;
                /*Function Pad Selected LIN0_RX :- PCR19*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[32]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[32].R = 0x00;
                /*Function Pad Selected LIN1_RX :- PCR29*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[33]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[33].R = 0x00;
                /*Function Pad Selected CAN0_RXD :- PCR15*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[34]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[34].R = 0x00;
                /*Function Pad Selected CAN1_RXD :- PCR15*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[35]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[35].R = 0x00;
                /*Function Pad Selected eTimer0_CH0 :- PCR0*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[36]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[36].R = 0x00;
                /*Function Pad Selected eTimer0_CH1 :- PCR1*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[37]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[37].R = 0x00;
                /*Function Pad Selected eTimer0_CH2 :- PCR2*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[38]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[38].R = 0x00;
                /*Function Pad Selected eTimer0_CH3 :- PCR3*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[39]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[39].R = 0x00;
                /*Function Pad Selected eTimer2_CH0 :- PCR116*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[40]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[40].R = 0x00;
                /*Function Pad Selected eTimer2_CH1 :- PCR119*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[41]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[41].R = 0x00;
                /*Function Pad Selected eTimer2_CH2 :- PCR0*/

/*-----------------------------------------------------------*/
/* Pad Selection for Multiplex Input Register PSMI[42]      */
/*-----------------------------------------------------------*/
               SIU.PSMI[42].R = 0x00;
                /*Function Pad Selected eTimer2_CH3 :- PCR125*/

}



 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

