/********************  Dependent Include files here **********************/
#include "rappid_utils.h"
#include "mcu_specific.h"

/****************** Enable/Disable Interrupt Interrupts *******************/

void EnableExternalInterrupts (void)
{
    asm(" wrteei 1");
}


void DisableExternalInterrupts (void)
{
    asm(" wrteei 0");
}



/*  ###################### Function for clearing BUFFERs ######################  */

void fs_clearmem(vuint8_t* address , uint16_t size, uint8_t fillbyte)
{
    while(size > 0)
    {
        *address = fillbyte;
        size-- ;
        address++ ;
    }
}

/******************************************************************************
*   Function: MC_Cleanup (Magic Carpet Cleanup)
*
*   Description: Uses entry into SAFE mode to disable peripherals so that any
*                dependencies on the PLL0 are removed so that PLL0 can be 
*                turned off.  Then will re-enter DRUN mode to verify MCU
*                can exit SAFE mode.
*   Caveats:
*
******************************************************************************/

void MC_Cleanup (void)
{
        /* Re-enter in SAFE mode to update the configuration and disable peripherals */
    ME.MCTL.R = 0x20005AF0;    
        /* Mode & Key */
    ME.MCTL.R = 0x2000A50F;    
        /* Mode & Key  Inverted */
    while(0x1 == ME.GS.B.S_MTRANS){};    
        /* Wait for mode entry to complete */
    while(0x2 != ME.GS.B.S_CURRENT_MODE){};    
    /* Check SAFE mode has been entered  */
        
        /* Disable PLL0 clock */
    ME.DRUN_MC.R = 0x001F0030;
    /* I/O Power Down Control: Disabled    */
    /* Main Voltage Regulator Control: Enabled    */
    /* Code Flash Power Down Control: Normal    */
    /* Secondary PLL (PLL1): OFF    */
    /* System PLL0: OFF    */
    /* Crystal Oscillator: ON    */
    /* 16MHz IRC:  ON    */
    /* System Clock Source: 16MHz internal RC oscillator     */

    /* ----------------------------------------------------------- */
    /*                     DRUN Re-Entry                    */
    /* ----------------------------------------------------------- */
        /* Re-enter in DRUN mode to update the configuration*/
    ME.MCTL.R = 0x30005AF0;    
        /* Mode & Key */
    ME.MCTL.R = 0x3000A50F;    
        /* Mode & Key  Inverted */
    while(0x1 == ME.GS.B.S_MTRANS){};    
        /* Wait for mode entry to complete */
    while(0x3 != ME.GS.B.S_CURRENT_MODE){};    
        /* Check DRUN mode has been entered  */
}
