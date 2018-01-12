/***************************************************************************************************
* SF Motors Confidential – Copyright [2017], all rights reserved.
* Author: shawn.yuan@sfmotors.com
* Date: 2017-06-29
* Description: GPIO configurations
***************************************************************************************************/

#include "gpio_564xl_library.h"
#include "GPIO.h"

void GPIO_init(void)
{
    /* Initialize Pad Configuration Register 95,83 as Output */
    gpo_init_pcr_out_564xl_fnc( 95 );   // LED0
    gpo_init_pcr_out_564xl_fnc( 83 );   // LED3
}
