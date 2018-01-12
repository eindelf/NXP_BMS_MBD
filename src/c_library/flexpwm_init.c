/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    flexpwm_init.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   FlexPWM initialization.
*    @details function for configuration of FlexPWM sub modules and  General configuration.
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
#include "flexpwm_init.h"


/******************************************************************************
*                   Global functions
******************************************************************************/

static volatile mcPWM_tag* FlexPWM_module[2] = { &FLEXPWM_0, &FLEXPWM_1 };

/**********************  Initialization Function(s) *************************/

/******************************************************************************
*   Function:  flexpwm_init_fnc
@brief    initialization for Flex PWM module 0 . 
@details   initialization for Flex PWM module 0
  
@return none
*/
void flexpwm_init_fnc (void) 
{
    flexpwm_sub0_init_fnc(0); 
    flexpwm_sub1_init_fnc(0); 
    flexpwm_sub2_init_fnc(0); 
    flexpwm_sub3_init_fnc(0); 
    flexpwm_GenConfig_fnc(0); 
	
    flexpwm_sub0_init_fnc(1); 
    flexpwm_sub1_init_fnc(1); 
    flexpwm_sub2_init_fnc(1); 
    flexpwm_sub3_init_fnc(1); 
    flexpwm_GenConfig_fnc(1); 
}

/******************************************************************************
*   Function:  flexpwm_GenConfig_fnc
@brief    General Configuration for Flex PWM module 0 . 
@details   FlexPWM General Configuration Initialization code for FLEXPWM_0 Device
  
@return none
*/
void flexpwm_GenConfig_fnc (uint8_t pwmMod)
{

/*----------------------------------------------------------- */
/*    FlexPWM General Configuration Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->OUTEN.R = 0x0FFF;
            /* PWM A O/P : Enabled    */
            /* PWM B O/P : Enabled    */
            /* PWM X O/P : Enabled    */

    FlexPWM_module[pwmMod]->MASK.R = 0x0000;
            /* PWM A Mask : Disabled    */
            /* PWM B Mask : Disabled    */
            /* PWM X Mask : Disabled    */

    FlexPWM_module[pwmMod]->SWCOUT.R = 0x0000;
            /* S/W Controlled O/P OUTA_3 : A logic 0 is supplied to the deadtime generator of submodule 3    */
            /* S/W Controlled O/P OUTB_3 : A logic 0 is supplied to the deadtime generator of submodule 3    */
            /* S/W Controlled O/P OUTA_2 : A logic 0 is supplied to the deadtime generator of submodule 2    */
            /* S/W Controlled O/P OUTB_2 : A logic 0 is supplied to the deadtime generator of submodule 2    */
            /* S/W Controlled O/P OUTA_1 : A logic 0 is supplied to the deadtime generator of submodule 1    */
            /* S/W Controlled O/P OUTB_1 : A logic 0 is supplied to the deadtime generator of submodule 1    */
            /* S/W Controlled O/P OUTA_0 : A logic 0 is supplied to the deadtime generator of submodule 0    */
            /* S/W Controlled O/P OUTB_0 : A logic 0 is supplied to the deadtime generator of submodule 0    */

    FlexPWM_module[pwmMod]->DTSRCSEL.R = 0x0000;
            /* Deadtime source SELA_3 : Generated PWM signal is used by the deadtime logic.    */
            /* Deadtime source SELB_3 : Generated PWM signal is used by the deadtime logic.    */
            /* Deadtime source SELA_2 : Generated PWM signal is used by the deadtime logic.    */
            /* Deadtime source SELB_2 : Generated PWM signal is used by the deadtime logic.    */
            /* Deadtime source SELA_1 : Generated PWM signal is used by the deadtime logic.    */
            /* Deadtime source SELB_1 : Generated PWM signal is used by the deadtime logic.    */
            /* Deadtime source SELA_0 : Generated PWM signal is used by the deadtime logic.    */
            /* Deadtime source SELB_0 : Generated PWM signal is used by the deadtime logic.    */

    FlexPWM_module[pwmMod]->FSTS.B.FFLAG = 0xF;
            /* Clear Fault FFLAGx     */

    FlexPWM_module[pwmMod]->FCTRL.R = 0x0000;
            /* Fault Level : logic 0    */
            /* Automatic Fault Clearing : Disabled    */
            /*Fault Safe Mode         : Disabled    */
            /*Fault Interrupt         : Disabled    */

    FlexPWM_module[pwmMod]->FFILT.R = 0x0000;
            /* Filter Count : 3 samples    */
            /* Filter Period : 0    */

    FlexPWM_module[pwmMod]->MCTRL.B.IPOL= 0x0;
            /* Current Polarity (PWM) Submodule 0 : PWMA    */
            /* Current Polarity (PWM) Submodule 1 : PWMA    */
            /* Current Polarity (PWM) Submodule 2 : PWMA    */
            /* Current Polarity (PWM) Submodule 3 : PWMA    */
}

/******************************************************************************
*   Function:  flexpwm_sub0_init_fnc
@brief    Sub module config 0  for Flex PWM module 0 . 
@details   FlexPWM Configuration  Initialization code for FLEXPWM_0 Device
  
@return none
*/
/* Sub module config 0 */
void flexpwm_sub0_init_fnc (uint8_t pwmMod) 
{

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 1 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[0].INIT.R = 0xFF00;
            /* Initial count value for the PWM : 0xFF00    */

    FlexPWM_module[pwmMod]->SUB[0].CTRL2.R = 0x9000;
            /* Debug Enable : Enabled    */
            /* Wait Enable : Disabled    */
            /* Pair Operation : Complementary PWM    */
            /* Initial value for PWMA : 1    */
            /* Initial value for PWMB : 0    */
            /* Initial value for PWMX : 0    */
            /* Initialization Control: Local sync    */
            /* Initialization from a Force Out event : Disabled    */
            /* Force Source : Local force    */
            /* Reload Source : Local reload    */
            /* Clock source for the local prescaler and counter : IPBus clock    */

    FlexPWM_module[pwmMod]->SUB[0].CTRL.R = 0x0470;
            /* PWM load frequency  : Every PWM    */
            /* Half Cycle Reload : Disabled    */
            /* Full Cycle Reload : Enabled    */
            /* Prescalar : fclk/128    */
            /* Double Switching : Disabled    */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 2 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[0].VAL[0].R = 0x0000;
            /* Mid-cycle reload point for the PWM in PWM clock periods : 0000    */

    FlexPWM_module[pwmMod]->SUB[0].VAL[1].R = 0x0100;
            /* Modulo count value (maximum count) for the submodule counter : 0x0100    */

    FlexPWM_module[pwmMod]->SUB[0].VAL[2].R = 0xFF74;
            /* Count value to set PWMA high : 0xFF74    */

    FlexPWM_module[pwmMod]->SUB[0].VAL[3].R = 0x008C;
            /* Count value to set PWMA low : 0x008C    */

    FlexPWM_module[pwmMod]->SUB[0].VAL[4].R = 0xFF7E;
            /* Count value to set PWMB high : 0xFF7E    */

    FlexPWM_module[pwmMod]->SUB[0].VAL[5].R = 0x0082;
            /* Count value to set PWMB low : 0x0082    */

    FlexPWM_module[pwmMod]->SUB[0].OCTRL.R = 0x0000;
            /* PWM A O/P Polarity : PWM A output Not Inverted    */
            /* PWM B O/P Polarity : PWM B output Not Inverted    */
            /* PWM X O/P Polarity : PWM X output Not Inverted    */
            /* PWM A O/P Fault State : Output is forced to Logic 0    */
            /* PWM B O/P Fault State : Output is forced to Logic 0    */
            /* PWM X O/P Fault State : Output is forced to Logic 0    */

    FlexPWM_module[pwmMod]->SUB[0].TCTRL.R = 0x0000;
            /* Output Trigger Control : OUT_TRIGx not set when the counter value matches the VALx value     */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 3 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[0].INTEN.R = 0x0000;
            /* REF CPU interrupt requests (Reload Error Interrupt) : Disabled    */
            /* RF CPU interrupt requests ( Reload Error ) : Disabled    */
            /* Interrupt request for CFX1 (Capture X1 Interrupt) : Disabled    */
            /* Interrupt request for CFX0 (Capture X0 Interrupt) : Disabled    */
            /* Compare 0 Interrupt : Disabled    */
            /* Compare 1 Interrupt : Disabled    */
            /* Compare 2 Interrupt : Disabled    */
            /* Compare 3 Interrupt : Disabled    */
            /* Compare 4 Interrupt : Disabled    */
            /* Compare 5 Interrupt : Disabled    */

    FlexPWM_module[pwmMod]->SUB[0].DMAEN.R = 0x0000;
            /* DMA write requests : Disabled    */
            /* Selected FIFO watermarks : OR' ed together.    */
            /* Read DMA requests : Read DMA Disabled.    */
            /* DMA read requests for the Capture A1 FIFO data : Disabled    */
            /* DMA read requests for the Capture A0 FIFO data : Disabled    */
            /* DMA read requests for the Capture B1 FIFO data : Disabled    */
            /* DMA read requests for the Capture B0 FIFO data : Disabled    */
            /* DMA read requests for the Capture X1 FIFO data : Disabled    */
            /* DMA read requests for the Capture X0 FIFO data : Disabled    */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 4 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[0].DISMAP.R = 0xF000;
            /* PWM X Fault Mask : 0000    */
            /* PWM B Fault Mask : 0000    */
            /* PWM A Fault Mask : 0000    */

    FlexPWM_module[pwmMod]->SUB[0].DTCNT0.R = 0x07FF;
            /* PWM A Dead Count : 0x7ff    */

    FlexPWM_module[pwmMod]->SUB[0].DTCNT1.R = 0x07FF;
            /* PWM B Dead Count : 0x7ff    */

    FlexPWM_module[pwmMod]->SUB[0].CAPTCTRLX.R = 0x0000;
            /* Capture X0 FIFOs Water Mark : Disabled    */
            /* Capture X1 FIFOs Water Mark : Disabled    */
            /* Edge Counter X : Disabled    */
            /* Input signal selected as source for the input capture circuit ( Input Select X ) : Raw PWMX    */
            /* Input Edge X1 Select : Disabled    */
            /* Input Edge X0 Select : Disabled    */
            /* Capture Mode : Free Running    */
            /* Input Capture Mode : Disabled    */

    FlexPWM_module[pwmMod]->SUB[0].CAPTCOMPX.R = 0x0000;
            /* Compare value associated with the edge counter for the PWMX input capture circuitry : 0x0000    */
}

/******************************************************************************
*   Function:  flexpwm_sub1_init_fnc
@brief    Sub module config 1  for Flex PWM module 0 . 
@details   FlexPWM Configuration  Initialization code for FLEXPWM_0 Device
  
@return none
*/
/* Sub module config 1 */
void flexpwm_sub1_init_fnc (uint8_t pwmMod) 
{

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 1 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[1].INIT.R = 0xFF00;
            /* Initial count value for the PWM : 0xFF00    */

    FlexPWM_module[pwmMod]->SUB[1].CTRL2.R = 0x9000;
            /* Debug Enable : Enabled    */
            /* Wait Enable : Disabled    */
            /* Pair Operation : Complementary PWM    */
            /* Initial value for PWMA : 1    */
            /* Initial value for PWMB : 0    */
            /* Initial value for PWMX : 0    */
            /* Initialization Control: Local sync    */
            /* Initialization from a Force Out event : Disabled    */
            /* Force Source : Local force    */
            /* Reload Source : Local reload    */
            /* Clock source for the local prescaler and counter : IPBus clock    */

    FlexPWM_module[pwmMod]->SUB[1].CTRL.R = 0x0470;
            /* PWM load frequency  : Every PWM    */
            /* Half Cycle Reload : Disabled    */
            /* Full Cycle Reload : Enabled    */
            /* Prescalar : fclk/128    */
            /* Double Switching : Disabled    */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 2 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[1].VAL[0].R = 0x0000;
            /* Mid-cycle reload point for the PWM in PWM clock periods : 0000    */

    FlexPWM_module[pwmMod]->SUB[1].VAL[1].R = 0x0100;
            /* Modulo count value (maximum count) for the submodule counter : 0x0100    */

    FlexPWM_module[pwmMod]->SUB[1].VAL[2].R = 0xFF74;
            /* Count value to set PWMA high : 0xFF74    */

    FlexPWM_module[pwmMod]->SUB[1].VAL[3].R = 0x008C;
            /* Count value to set PWMA low : 0x008C    */

    FlexPWM_module[pwmMod]->SUB[1].VAL[4].R = 0xFF7E;
            /* Count value to set PWMB high : 0xFF7E    */

    FlexPWM_module[pwmMod]->SUB[1].VAL[5].R = 0x0082;
            /* Count value to set PWMB low : 0x0082    */

    FlexPWM_module[pwmMod]->SUB[1].OCTRL.R = 0x0000;
            /* PWM A O/P Polarity : PWM A output Not Inverted    */
            /* PWM B O/P Polarity : PWM B output Not Inverted    */
            /* PWM X O/P Polarity : PWM X output Not Inverted    */
            /* PWM A O/P Fault State : Output is forced to Logic 0    */
            /* PWM B O/P Fault State : Output is forced to Logic 0    */
            /* PWM X O/P Fault State : Output is forced to Logic 0    */

    FlexPWM_module[pwmMod]->SUB[1].TCTRL.R = 0x0000;
            /* Output Trigger Control : OUT_TRIGx not set when the counter value matches the VALx value     */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 3 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[1].INTEN.R = 0x0000;
            /* REF CPU interrupt requests (Reload Error Interrupt) : Disabled    */
            /* RF CPU interrupt requests ( Reload Error ) : Disabled    */
            /* Interrupt request for CFX1 (Capture X1 Interrupt) : Disabled    */
            /* Interrupt request for CFX0 (Capture X0 Interrupt) : Disabled    */
            /* Compare 0 Interrupt : Disabled    */
            /* Compare 1 Interrupt : Disabled    */
            /* Compare 2 Interrupt : Disabled    */
            /* Compare 3 Interrupt : Disabled    */
            /* Compare 4 Interrupt : Disabled    */
            /* Compare 5 Interrupt : Disabled    */

    FlexPWM_module[pwmMod]->SUB[1].DMAEN.R = 0x0000;
            /* DMA write requests : Disabled    */
            /* Selected FIFO watermarks : OR' ed together.    */
            /* Read DMA requests : Read DMA Disabled.    */
            /* DMA read requests for the Capture A1 FIFO data : Disabled    */
            /* DMA read requests for the Capture A0 FIFO data : Disabled    */
            /* DMA read requests for the Capture B1 FIFO data : Disabled    */
            /* DMA read requests for the Capture B0 FIFO data : Disabled    */
            /* DMA read requests for the Capture X1 FIFO data : Disabled    */
            /* DMA read requests for the Capture X0 FIFO data : Disabled    */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 4 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[1].DISMAP.R = 0xF000;
            /* PWM X Fault Mask : 0000    */
            /* PWM B Fault Mask : 0000    */
            /* PWM A Fault Mask : 0000    */

    FlexPWM_module[pwmMod]->SUB[1].DTCNT0.R = 0x07FF;
            /* PWM A Dead Count : 0x7ff    */

    FlexPWM_module[pwmMod]->SUB[1].DTCNT1.R = 0x07FF;
            /* PWM B Dead Count : 0x7ff    */

    FlexPWM_module[pwmMod]->SUB[1].CAPTCTRLX.R = 0x0000;
            /* Capture X0 FIFOs Water Mark : Disabled    */
            /* Capture X1 FIFOs Water Mark : Disabled    */
            /* Edge Counter X : Disabled    */
            /* Input signal selected as source for the input capture circuit ( Input Select X ) : Raw PWMX    */
            /* Input Edge X1 Select : Disabled    */
            /* Input Edge X0 Select : Disabled    */
            /* Capture Mode : Free Running    */
            /* Input Capture Mode : Disabled    */

    FlexPWM_module[pwmMod]->SUB[1].CAPTCOMPX.R = 0x0000;
            /* Compare value associated with the edge counter for the PWMX input capture circuitry : 0x0000    */
}

/******************************************************************************
*   Function:  flexpwm_sub2_init_fnc
@brief    Sub module config 2  for Flex PWM module 0 . 
@details   FlexPWM Configuration  Initialization code for FLEXPWM_0 Device
  
@return none
*/
void flexpwm_sub2_init_fnc (uint8_t pwmMod) 
{

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 1 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[2].INIT.R = 0xFF00;
            /* Initial count value for the PWM : 0xFF00    */

    FlexPWM_module[pwmMod]->SUB[2].CTRL2.R = 0x9000;
            /* Debug Enable : Enabled    */
            /* Wait Enable : Disabled    */
            /* Pair Operation : Complementary PWM    */
            /* Initial value for PWMA : 1    */
            /* Initial value for PWMB : 0    */
            /* Initial value for PWMX : 0    */
            /* Initialization Control: Local sync    */
            /* Initialization from a Force Out event : Disabled    */
            /* Force Source : Local force    */
            /* Reload Source : Local reload    */
            /* Clock source for the local prescaler and counter : IPBus clock    */

    FlexPWM_module[pwmMod]->SUB[2].CTRL.R = 0x0470;
            /* PWM load frequency  : Every PWM    */
            /* Half Cycle Reload : Disabled    */
            /* Full Cycle Reload : Enabled    */
            /* Prescalar : fclk/128    */
            /* Double Switching : Disabled    */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 2 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[2].VAL[0].R = 0x0000;
            /* Mid-cycle reload point for the PWM in PWM clock periods : 0000    */

    FlexPWM_module[pwmMod]->SUB[2].VAL[1].R = 0x0100;
            /* Modulo count value (maximum count) for the submodule counter : 0x0100    */

    FlexPWM_module[pwmMod]->SUB[2].VAL[2].R = 0xFF74;
            /* Count value to set PWMA high : 0xFF74    */

    FlexPWM_module[pwmMod]->SUB[2].VAL[3].R = 0x008C;
            /* Count value to set PWMA low : 0x008C    */

    FlexPWM_module[pwmMod]->SUB[2].VAL[4].R = 0xFF7E;
            /* Count value to set PWMB high : 0xFF7E    */

    FlexPWM_module[pwmMod]->SUB[2].VAL[5].R = 0x0082;
            /* Count value to set PWMB low : 0x0082    */

    FlexPWM_module[pwmMod]->SUB[2].OCTRL.R = 0x0000;
            /* PWM A O/P Polarity : PWM A output Not Inverted    */
            /* PWM B O/P Polarity : PWM B output Not Inverted    */
            /* PWM X O/P Polarity : PWM X output Not Inverted    */
            /* PWM A O/P Fault State : Output is forced to Logic 0    */
            /* PWM B O/P Fault State : Output is forced to Logic 0    */
            /* PWM X O/P Fault State : Output is forced to Logic 0    */

    FlexPWM_module[pwmMod]->SUB[2].TCTRL.R = 0x0000;
            /* Output Trigger Control : OUT_TRIGx not set when the counter value matches the VALx value     */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 3 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[2].INTEN.R = 0x0000;
            /* REF CPU interrupt requests (Reload Error Interrupt) : Disabled    */
            /* RF CPU interrupt requests ( Reload Error ) : Disabled    */
            /* Interrupt request for CFX1 (Capture X1 Interrupt) : Disabled    */
            /* Interrupt request for CFX0 (Capture X0 Interrupt) : Disabled    */
            /* Compare 0 Interrupt : Disabled    */
            /* Compare 1 Interrupt : Disabled    */
            /* Compare 2 Interrupt : Disabled    */
            /* Compare 3 Interrupt : Disabled    */
            /* Compare 4 Interrupt : Disabled    */
            /* Compare 5 Interrupt : Disabled    */

    FlexPWM_module[pwmMod]->SUB[2].DMAEN.R = 0x0000;
            /* DMA write requests : Disabled    */
            /* Selected FIFO watermarks : OR' ed together.    */
            /* Read DMA requests : Read DMA Disabled.    */
            /* DMA read requests for the Capture A1 FIFO data : Disabled    */
            /* DMA read requests for the Capture A0 FIFO data : Disabled    */
            /* DMA read requests for the Capture B1 FIFO data : Disabled    */
            /* DMA read requests for the Capture B0 FIFO data : Disabled    */
            /* DMA read requests for the Capture X1 FIFO data : Disabled    */
            /* DMA read requests for the Capture X0 FIFO data : Disabled    */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 4 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[2].DISMAP.R = 0xF000;
            /* PWM X Fault Mask : 0000    */
            /* PWM B Fault Mask : 0000    */
            /* PWM A Fault Mask : 0000    */

    FlexPWM_module[pwmMod]->SUB[2].DTCNT0.R = 0x07FF;
            /* PWM A Dead Count : 0x7ff    */

    FlexPWM_module[pwmMod]->SUB[2].DTCNT1.R = 0x07FF;
            /* PWM B Dead Count : 0x7ff    */

    FlexPWM_module[pwmMod]->SUB[2].CAPTCTRLX.R = 0x0000;
            /* Capture X0 FIFOs Water Mark : Disabled    */
            /* Capture X1 FIFOs Water Mark : Disabled    */
            /* Edge Counter X : Disabled    */
            /* Input signal selected as source for the input capture circuit ( Input Select X ) : Raw PWMX    */
            /* Input Edge X1 Select : Disabled    */
            /* Input Edge X0 Select : Disabled    */
            /* Capture Mode : Free Running    */
            /* Input Capture Mode : Disabled    */

    FlexPWM_module[pwmMod]->SUB[2].CAPTCOMPX.R = 0x0000;
            /* Compare value associated with the edge counter for the PWMX input capture circuitry : 0x0000    */
}

/******************************************************************************
*   Function:  flexpwm_sub3_init_fnc
@brief    Sub module config 3  for Flex PWM module 0 . 
@details   FlexPWM Configuration  Initialization code for FLEXPWM_0 Device
  
@return none
*/
void flexpwm_sub3_init_fnc (uint8_t pwmMod) 
{

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 1 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[3].INIT.R = 0x0000;
            /* Initial count value for the PWM : 0x0    */

    FlexPWM_module[pwmMod]->SUB[3].CTRL2.R = 0x0000;
            /* Debug Enable : Disabled    */
            /* Wait Enable : Disabled    */
            /* Pair Operation : Complementary PWM    */
            /* Initial value for PWMA : 0    */
            /* Initial value for PWMB : 0    */
            /* Initial value for PWMX : 0    */
            /* Initialization Control: Local sync    */
            /* Initialization from a Force Out event : Disabled    */
            /* Force Source : Local force    */
            /* Reload Source : Local reload    */
            /* Clock source for the local prescaler and counter : IPBus clock    */

    FlexPWM_module[pwmMod]->SUB[3].CTRL.R = 0x0420;
            /* PWM load frequency  : Every PWM    */
            /* Half Cycle Reload : Disabled    */
            /* Full Cycle Reload : Enabled    */
            /* Prescalar : fclk/4    */
            /* Double Switching : Disabled    */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 2 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[3].VAL[0].R = 0x0000;
            /* Mid-cycle reload point for the PWM in PWM clock periods : 0000    */

    FlexPWM_module[pwmMod]->SUB[3].VAL[1].R = 0x0000;
            /* Modulo count value (maximum count) for the submodule counter : 0x0000    */

    FlexPWM_module[pwmMod]->SUB[3].VAL[2].R = 0x0000;
            /* Count value to set PWMA high : 0x0000    */

    FlexPWM_module[pwmMod]->SUB[3].VAL[3].R = 0x0000;
            /* Count value to set PWMA low : 0x0000    */

    FlexPWM_module[pwmMod]->SUB[3].VAL[4].R = 0x0000;
            /* Count value to set PWMB high : 0x0000    */

    FlexPWM_module[pwmMod]->SUB[3].VAL[5].R = 0x0000;
            /* Count value to set PWMB low : 0x0000    */

    FlexPWM_module[pwmMod]->SUB[3].OCTRL.R = 0x0000;
            /* PWM A O/P Polarity : PWM A output Not Inverted    */
            /* PWM B O/P Polarity : PWM B output Not Inverted    */
            /* PWM X O/P Polarity : PWM X output Not Inverted    */
            /* PWM A O/P Fault State : Output is forced to Logic 0    */
            /* PWM B O/P Fault State : Output is forced to Logic 0    */
            /* PWM X O/P Fault State : Output is forced to Logic 0    */

    FlexPWM_module[pwmMod]->SUB[3].TCTRL.R = 0x0000;
            /* Output Trigger Control : OUT_TRIGx not set when the counter value matches the VALx value     */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 3 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[3].INTEN.R = 0x0000;
            /* REF CPU interrupt requests (Reload Error Interrupt) : Disabled    */
            /* RF CPU interrupt requests ( Reload Error ) : Disabled    */
            /* Interrupt request for CFX1 (Capture X1 Interrupt) : Disabled    */
            /* Interrupt request for CFX0 (Capture X0 Interrupt) : Disabled    */
            /* Compare 0 Interrupt : Disabled    */
            /* Compare 1 Interrupt : Disabled    */
            /* Compare 2 Interrupt : Disabled    */
            /* Compare 3 Interrupt : Disabled    */
            /* Compare 4 Interrupt : Disabled    */
            /* Compare 5 Interrupt : Disabled    */

    FlexPWM_module[pwmMod]->SUB[3].DMAEN.R = 0x0000;
            /* DMA write requests : Disabled    */
            /* Selected FIFO watermarks : OR' ed together.    */
            /* Read DMA requests : Read DMA Disabled.    */
            /* DMA read requests for the Capture A1 FIFO data : Disabled    */
            /* DMA read requests for the Capture A0 FIFO data : Disabled    */
            /* DMA read requests for the Capture B1 FIFO data : Disabled    */
            /* DMA read requests for the Capture B0 FIFO data : Disabled    */
            /* DMA read requests for the Capture X1 FIFO data : Disabled    */
            /* DMA read requests for the Capture X0 FIFO data : Disabled    */

/*----------------------------------------------------------- */
/*    FlexPWM Configuration 4 Initialization code for FLEXPWM_0 Device    */
/*----------------------------------------------------------- */

    FlexPWM_module[pwmMod]->SUB[3].DISMAP.R = 0xF000;
            /* PWM X Fault Mask : 0000    */
            /* PWM B Fault Mask : 0000    */
            /* PWM A Fault Mask : 0000    */

    FlexPWM_module[pwmMod]->SUB[3].DTCNT0.R = 0x07FF;
            /* PWM A Dead Count : 0x7ff    */

    FlexPWM_module[pwmMod]->SUB[3].DTCNT1.R = 0x07FF;
            /* PWM B Dead Count : 0x7ff    */

    FlexPWM_module[pwmMod]->SUB[3].CAPTCTRLX.R = 0x0000;
            /* Capture X0 FIFOs Water Mark : Disabled    */
            /* Capture X1 FIFOs Water Mark : Disabled    */
            /* Edge Counter X : Disabled    */
            /* Input signal selected as source for the input capture circuit ( Input Select X ) : Raw PWMX    */
            /* Input Edge X1 Select : Disabled    */
            /* Input Edge X0 Select : Disabled    */
            /* Capture Mode : Free Running    */
            /* Input Capture Mode : Disabled    */

    FlexPWM_module[pwmMod]->SUB[3].CAPTCOMPX.R = 0x0000;
            /* Compare value associated with the edge counter for the PWMX input capture circuitry : 0x0000    */
}

#ifdef __cplusplus
}
#endif

/*
*######################################################################
*                           End of File
*######################################################################
*/

