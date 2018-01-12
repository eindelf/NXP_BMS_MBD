/***************************************************************************************************
* SF Motors Confidential – Copyright [2017], all rights reserved.
* Author: shawn.yuan@sfmotors.com
* Date: 2017-06-29
* Description: CTU configuration and interrupts.
***************************************************************************************************/

#include "CTU_564xL_library.h"
#include "gpio_564xl_library.h"
#include "CTU.h"

void CTU_init(void)
{
    // Enable trigger 0
    CTU.CTUIR.B.T0_I = 1;

    // Enable FIFO 0 with threshold 4
    CTU.TH1.B.THRESHOLD0 = 4;                   //FIFO0 threshold value
    CTU.FCR.B.FIFO_OVERFLOW_EN0 = 1;            //FIFO0 threshold overflow interrupt enable

    //    INTC.PSR[206].R = 0x0C;               // CTU ADC command INT enable
    INTC.PSR[194].R = 0x0C;                     // CTU trigger 0 INT enable
    INTC.PSR[202].R = 0x0C;                     // CTU FIFO0 INT enable

    // Config pin 49 as CTU external trigger pin
    ctu_init_pcr_out_564xL(49, 255);

    {
        // No delay on the triggers.
        uint16_t triggerDelay[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

        uint32_t TriggerOutput[2] = { 97, 0 };

        uint16_t ADCcommands[24] =
        {
            49152, 33793, 16384, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0
        };

        uint32_t ADC_CmdIndex[2] = { 0, 0 };

        ctu_init_564xL (0, 256, TriggerOutput, 0, 20, triggerDelay, ADC_CmdIndex, ADCcommands);
    }
}

void CTU_adc_ISR(void)
{
    static tBool ledState = FALSE;

    /* Pin Data Output Signal Update PCR[95]. */
    gpo_pin_update_564xl_fnc(95, ledState);/* GPO Pin Data Output Register Update */

    ledState = !ledState;

    CTU.CTUIFR.B.ADC_I = 1;              //clear flags
}

void CTU_trigger0_ISR(void)
{
    static tBool ledState = FALSE;

    /* Pin Data Output Signal Update PCR[95]. */
    gpo_pin_update_564xl_fnc(95, ledState);/* GPO Pin Data Output Register Update */

    ledState = !ledState;

    CTU.CTUIFR.B.T0_I = 1;               //clear flags
}

void CTU_fifo0_ISR(void)
{
    static tBool ledState = FALSE;
    static tBool phaseShift = TRUE;
    uint32_t result[4];

    /* Pin Data Output Signal Update PCR[83]. */
    gpo_pin_update_564xl_fnc(83, ledState);/* GPO Pin Data Output Register Update */

    ledState = !ledState;

    if (phaseShift)
    {
        // Read FIFO once for the first time to adjust the interrupt phase to the 10kHz PWM.
        result[0] = CTU.FR0.B.DATA;
        phaseShift = FALSE;
    }
    else
    {
        // Read the data from CTU FIFO
        result[0] = CTU.FR0.B.DATA;
        result[1] = CTU.FR0.B.DATA;
        result[2] = CTU.FR0.B.DATA;
        result[3] = CTU.FR0.B.DATA;
    }
    (void) result;
}
