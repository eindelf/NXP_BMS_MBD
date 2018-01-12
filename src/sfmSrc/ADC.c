/***************************************************************************************************
* SF Motors Confidential – Copyright [2017], all rights reserved.
* Author: shawn.yuan@sfmotors.com
* Date: 2017-06-29
* Description: ADC configurations.
***************************************************************************************************/

#ifdef __cplusplus

extern "C"{

#endif

/******************************************************************************
*                  Includes
******************************************************************************/
#include "ADC.h"
#include "adc_564xl_library.h"


/*********************  Trigger Initialization Function(s) ************************/
/******************************************************************************
*   Function:  adc_trigger_setup_fnc
     @brief    ADC Trigger Initialization Function .
     @details       ADC Trigger Initialization Function

     @return none
*/
static  void adc_trigger_setup_fnc()
{
    /*-----------------------------------------------------------*/
    /*                    ADC 0 Trigger Configuration            */
    /*-----------------------------------------------------------*/
    ADC_0.MCR.R = 0xa0000000;

    /* Injection Trigger : Disabled     */
    /* Injection trigger edge : Falling*/

    /*-----------------------------------------------------------*/
    /*                    ADC 1 Trigger Configuration            */
    /*-----------------------------------------------------------*/
    ADC_1.MCR.R = 0xa0000000;

    /* Injection Trigger : Disabled     */
    /* Injection trigger edge :  Falling */
}

/*********************  Interrupt Initialization Function(s) ************************/
/******************************************************************************
*   Function:  adc_interrupt_setup_fnc
     @brief    ADC Interrupt Initialization Function .
     @details       ADC Interrupt Initialization Function

     @return none
*/
static  void adc_interrupt_setup_fnc()
{
    /*-----------------------------------------------------------*/
    /*                    Interrupt Mask Register(ADC0_IMR)        */
    /*-----------------------------------------------------------*/
    ADC_0.IMR.R = 0x00000000;

    /* End of Chain Conversion Interrupt : Disabled */
    /* End of Injected Chain Interrupt : Disabled */
    /* End of Channel Conversion Interrupt : Disabled */
    /* End of Injected Channel Interrupt : Disabled */
    /* Error in Offset Refresh Interrupt : Disabled */
    /* Offset Cancellation Over Interrupt : Disabled */
    /* End of CTU conversion Interrupt : Disabled */

    /*-----------------------------------------------------------*/
    /*                    Interrupt Mask Register(ADC1_IMR)        */
    /*-----------------------------------------------------------*/
    ADC_1.IMR.R = 0x00000000;

    /* End of Chain Conversion Interrupt : Disabled */
    /* End of Injected Chain Interrupt : Disabled */
    /* End of Channel Conversion Interrupt : Disabled */
    /* End of Injected Channel Interrupt : Disabled */
    /* Error in Offset Refresh Interrupt : Disabled */
    /* Offset Cancellation Over Interrupt : Disabled */
    /* End of CTU conversion Interrupt : Disabled */
}

/*********************  Sampling Initialization Function(s) ************************/
/******************************************************************************
*   Function:  adc_sampling_setup_fnc
     @brief    ADC Sampling Initialization Function .
     @details       ADC Sampling Initialization Function

     @return none
*/
static void adc_sampling_setup_fnc()
{
    /*-----------------------------------------------------------*/
    /*                ADC_0 Sampling Control            */
    /*-----------------------------------------------------------*/

    /*-----------------------------------------------------------*/
    /*                Conversion Timing Register 0(ADC_0_CTR0)    */
    /*-----------------------------------------------------------*/
    ADC_0.CTR[0].R = 0x00008203;

    /*Phase duration Latch : Enabled */
    /*Input Sampling Duration : 3 clock Cycles     */
    /*Input Comparison Duration : 1 clock Cycles     */

    /*-----------------------------------------------------------*/
    /*                Offset  Word Register (ADC_OFFWR)    */
    /*-----------------------------------------------------------*/
    //        ADC_0.OFFWR.B.OFFSETWORD = 0x00000000;
    /* Offset Loading : Disabled     */
    /* External Offset Word : 0    */

    /*-----------------------------------------------------------*/
    /*             Main Configuration Register (ADC_0_MCR)    */
    /*-----------------------------------------------------------*/
    ADC_0.MCR.R = 0x00000000;

    /* Offset Cancellation Phase : Disabled */
    /* Offset Refresh during Idle mode :Disabled     */
    ADC_0.MCR.B.PWDN = 0x0;

    /* Exit from power down state*/
    while (ADC_0.MCR.B.OFFCANC) {
      /*No Operation*/
    }

    /* Note that offset cancellation is performed only after coming
       out of powerdown state. As a consequence, OFFCANC bit must be
       set before PWDN bit resetting after the offset cancellation
       phase is over the 8-bit offset coefficient is stored in the
       Offset word register OFFREG and as a consequence, the OFFCANC bit is cleared */

    /*-----------------------------------------------------------*/
    /*                ADC_1 Sampling Control            */
    /*-----------------------------------------------------------*/

    /*-----------------------------------------------------------*/
    /*                Conversion Timing Register 0(ADC_1_CTR0)    */
    /*-----------------------------------------------------------*/
    ADC_1.CTR[0].R = 0x00008203;

    /*Phase duration Latch : Enabled */
    /*Input Sampling Duration : 3 clock Cycles     */
    /*Input Comparison Duration : 1 clock Cycles     */

    /*-----------------------------------------------------------*/
    /*                Offset  Word Register (ADC_OFFWR)    */
    /*-----------------------------------------------------------*/
    //        ADC_1.OFFWR.B.OFFSETWORD = 0x00000000;
    /* Offset Loading : Disabled     */
    /* External Offset Word : 0    */

    /*-----------------------------------------------------------*/
    /*             Main Configuration Register (ADC_1_MCR)    */
    /*-----------------------------------------------------------*/
    ADC_1.MCR.R = 0x00000000;

    /* Offset Cancellation Phase : Disabled */
    /* Offset Refresh during Idle mode :Disabled     */
    ADC_1.MCR.B.PWDN = 0x0;

    /* Exit from power down state*/
    while (ADC_1.MCR.B.OFFCANC) {
      /*No Operation*/
    }

    /* Note that offset cancellation is performed only after coming
       out of powerdown state. As a consequence, OFFCANC bit must be
       set before PWDN bit resetting after the offset cancellation
       phase is over the 8-bit offset coefficient is stored in the
       Offset word register OFFREG and as a consequence, the OFFCANC bit is cleared */
}

/*********************  General Initialization Function(s) ************************/
/******************************************************************************
*   Function:  adc_general_setup_fnc
     @brief    ADC General Initialization Function .
     @details       ADC General Initialization Function

     @return none
*/
static void adc_general_setup_fnc(void)
{
    /*-----------------------------------------------------------*/
    /*                ADC 0 Device Setup             */
    /*-----------------------------------------------------------*/
    ADC_0.MCR.R = 0xA0000000;

    /* Auto Clock Off feature : Disabled */
    /* Conversion data Overwrite: Enabled */
    /* Conversion Data Aligned: Right Aligned */
    /* Conversion Mode Selected :  Scan */
    /* ADC Conversion clock selected as :  System Clock/2 */
    /* ADC PowerDown Mode is :  Disabled */
    //ADC_0.DSDR.R = 0x00000000;

    /* The Decode Signal Delay : 0 clock Cycle      */
    ADC_0.PDEDR.R = 0x00000000;

    /* The Power Down Delay : 0 clock Cycle      */

    /*-----------------------------------------------------------*/
    /*                ADC 1 Device Setup             */
    /*-----------------------------------------------------------*/
    ADC_1.MCR.R = 0xA0000000;

    /* Auto Clock Off feature : Disabled */
    /* Conversion data Overwrite: Enabled */
    /* Conversion Data Aligned: Right Aligned */
    /* Conversion Mode Selected :  Scan */
    /* ADC Conversion clock selected as :  System Clock/2 */
    //ADC_1.DSDR.R = 0x00000000;

    /* The Decode Signal Delay : 0 clock Cycle      */
    ADC_1.PDEDR.R = 0x00000000;

    /* The Power Down Delay : 0 clock Cycle      */
}

/*********************  Channel Initialization Function(s) ************************/
/******************************************************************************
*   Function:  adc_channel_setup_fnc
     @brief    ADC Channel Initialization Function .
     @details       ADC Channel Initialization Function

     @return none
*/
static  void adc_channel_setup_fnc(void)
{
    /*-----------------------------------------------------------*/
    /*                ADC 0 Channel Setup            */
    /*-----------------------------------------------------------*/

    /*-----------------------------------------------------------*/
    /*    Normal Channel Conversion Mask Register 0(ADC_0_NCMR0)*/
    /*-----------------------------------------------------------*/
    ADC_0.NCMR[0].R = 0x0000FFFF;

    /* ADC Channel 0 in Normal Mode : Enabled */
    /* ADC Channel 1 in Normal Mode : Enabled  */
    /* ADC Channel 2 in Normal Mode : Enabled  */
    /* ADC Channel 3 in Normal Mode : Enabled  */
    /* ADC Channel 4 in Normal Mode : Enabled  */
    /* ADC Channel 5 in Normal Mode : Enabled  */
    /* ADC Channel 6 in Normal Mode : Enabled  */
    /* ADC Channel 7 in Normal Mode : Enabled  */
    /* ADC Channel 8 in Normal Mode : Enabled  */
    /* ADC Channel 9 in Normal Mode : Enabled  */
    /* ADC Channel 10 in Normal Mode : Enabled  */
    /* ADC Channel 11 in Normal Mode : Enabled  */
    /* ADC Channel 12 in Normal Mode : Enabled  */
    /* ADC Channel 13 in Normal Mode : Enabled  */
    /* ADC Channel 14 in Normal Mode : Enabled  */
    /* ADC Channel 15 in Normal Mode : Enabled  */

    /*-----------------------------------------------------------*/
    /*        Injected Channel Conversion Mask Register 0(ADC_0_JCMR0)*/
    /*-----------------------------------------------------------*/
    ADC_0.JCMR[0].R = 0x00000000;

    /* ADC Channel 0 in Injected Mode : Disabled */
    /* ADC Channel 1 in Injected Mode : Disabled */
    /* ADC Channel 2 in Injected Mode : Disabled */
    /* ADC Channel 3 in Injected Mode : Disabled */
    /* ADC Channel 4 in Injected Mode : Disabled */
    /* ADC Channel 5 in Injected Mode : Disabled */
    /* ADC Channel 6 in Injected Mode : Disabled */
    /* ADC Channel 7 in Injected Mode : Disabled */
    /* ADC Channel 8 in Injected Mode : Disabled */
    /* ADC Channel 9 in Injected Mode : Disabled */
    /* ADC Channel 10 in Injected Mode : Disabled */
    /* ADC Channel 11 in Injected Mode : Disabled */
    /* ADC Channel 12 in Injected Mode : Disabled */
    /* ADC Channel 13 in Injected Mode : Disabled */
    /* ADC Channel 14 in Injected Mode : Disabled */
    /* ADC Channel 15 in Injected Mode : Disabled */

    /*-----------------------------------------------------------*/
    /*         Threshold Control Register 0 (ADC_0_TRC0)            */
    /*-----------------------------------------------------------*/
    //ADC_0.TRC[0].R = 0x00000000;

    /* Threshold detection for WatchDog 0 : Disabled */
    /* Threshold Inversion for WatchDog 0:DIsabled */
    /* Threshold Channel Select for WatchDog 0 : 0    */

    /*-----------------------------------------------------------*/
    /*         Threshold Control Register 1 (ADC_0_TRC1)            */
    /*-----------------------------------------------------------*/
    //ADC_0.TRC[1].R = 0x00000000;

    /* Threshold detection for WatchDog 1 : Disabled */
    /* Threshold Inversion for WatchDog 1:DIsabled */
    /* Threshold Channel Select for WatchDog 1 : 0    */

    /*-----------------------------------------------------------*/
    /*         Threshold Control Register 2 (ADC_0_TRC2)            */
    /*-----------------------------------------------------------*/
    //ADC_0.TRC[2].R = 0x00000000;

    /* Threshold detection for WatchDog 2 : Disabled */
    /* Threshold Inversion for WatchDog 2:DIsabled */
    /* Threshold Channel Select for WatchDog 2 : 0    */

    /*-----------------------------------------------------------*/
    /*         Threshold Control Register 3 (ADC_0_TRC3)            */
    /*-----------------------------------------------------------*/
    //ADC_0.TRC[3].R = 0x00000000;

    /* Threshold detection for WatchDog 3 : Disabled */
    /* Threshold Inversion for WatchDog 3:DIsabled */
    /* Threshold Channel Select for WatchDog 3 : 0    */

    /*-----------------------------------------------------------*/
    /*            Threshold Register 0 (ADC_0_THRHLR0)          */
    /*-----------------------------------------------------------*/
    ADC_0.THRHLR[0].R = 0x03840000;

    /* Lower Threshold value : 0    */
    /* Higher Threshold value : 900    */

    /*-----------------------------------------------------------*/
    /*            Threshold Register 1 (ADC_0_THRHLR1)          */
    /*-----------------------------------------------------------*/
    ADC_0.THRHLR[1].R = 0x03FF0000;

    /* Lower Threshold value : 0    */
    /* Higher Threshold value : 1023    */

    /*-----------------------------------------------------------*/
    /*            Threshold Register 2 (ADC_0_THRHLR2)          */
    /*-----------------------------------------------------------*/
    ADC_0.THRHLR[2].R = 0x03FF0000;

    /* Lower Threshold value : 0    */
    /* Higher Threshold value : 1023    */

    /*-----------------------------------------------------------*/
    /*            Threshold Register 3 (ADC_0_THRHLR3)          */
    /*-----------------------------------------------------------*/
    ADC_0.THRHLR[3].R = 0x03FF0000;

    /* Lower Threshold value : 0    */
    /* Higher Threshold value : 1023    */

    /*-----------------------------------------------------------*/
    /*Watchdog Threshold Interrupt Mask Register (ADC_0_WTIMR) */
    /*-----------------------------------------------------------*/
    ADC_0.WTIMR.R = 0x00000000;

    /* Low Threshold Interrupt for Watchdog 0 : Disabled */
    /* Low Threshold Interrupt for Watchdog 1 : Disabled */
    /* Low Threshold Interrupt for Watchdog 2 : Disabled */
    /* Low Threshold Interrupt for Watchdog 3 : Disabled */
    /* High Threshold Interrupt for Watchdog 0 : Disabled */
    /* High Threshold Interrupt for Watchdog 1 : Disabled */
    /* High Threshold Interrupt for Watchdog 2 : Disabled */
    /* High Threshold Interrupt for Watchdog 3 : Disabled */

    /*-----------------------------------------------------------*/
    /*                ADC 1 Channel Setup            */
    /*-----------------------------------------------------------*/

    /*-----------------------------------------------------------*/
    /*    Normal Channel Conversion Mask Register 0(ADC_1_NCMR0)*/
    /*-----------------------------------------------------------*/
    ADC_1.NCMR[0].R = 0x0000FFFF;

    /* ADC Channel 0 in Normal Mode : Enabled  */
    /* ADC Channel 1 in Normal Mode : Enabled  */
    /* ADC Channel 2 in Normal Mode : Enabled  */
    /* ADC Channel 3 in Normal Mode : Enabled  */
    /* ADC Channel 4 in Normal Mode : Enabled  */
    /* ADC Channel 5 in Normal Mode : Enabled  */
    /* ADC Channel 6 in Normal Mode : Enabled  */
    /* ADC Channel 7 in Normal Mode : Enabled  */
    /* ADC Channel 8 in Normal Mode : Enabled  */
    /* ADC Channel 9 in Normal Mode : Enabled  */
    /* ADC Channel 10 in Normal Mode : Enabled  */
    /* ADC Channel 11 in Normal Mode : Enabled  */
    /* ADC Channel 12 in Normal Mode : Enabled  */
    /* ADC Channel 13 in Normal Mode : Enabled  */
    /* ADC Channel 14 in Normal Mode : Enabled  */
    /* ADC Channel 15 in Normal Mode : Enabled  */

    /*-----------------------------------------------------------*/
    /*        Injected Channel Conversion Mask Register 0(ADC_1_JCMR0)*/
    /*-----------------------------------------------------------*/
    ADC_1.JCMR[0].R = 0x00000000;

    /* ADC Channel 0 in Injected Mode : Disabled */
    /* ADC Channel 1 in Injected Mode : Disabled */
    /* ADC Channel 2 in Injected Mode : Disabled */
    /* ADC Channel 3 in Injected Mode : Disabled */
    /* ADC Channel 4 in Injected Mode : Disabled */
    /* ADC Channel 5 in Injected Mode : Disabled */
    /* ADC Channel 6 in Injected Mode : Disabled */
    /* ADC Channel 7 in Injected Mode : Disabled */
    /* ADC Channel 8 in Injected Mode : Disabled */
    /* ADC Channel 9 in Injected Mode : Disabled */
    /* ADC Channel 10 in Injected Mode : Disabled */
    /* ADC Channel 11 in Injected Mode : Disabled */
    /* ADC Channel 12 in Injected Mode : Disabled */
    /* ADC Channel 13 in Injected Mode : Disabled */
    /* ADC Channel 14 in Injected Mode : Disabled */
    /* ADC Channel 15 in Injected Mode : Disabled */

    /*-----------------------------------------------------------*/
    /*         Threshold Control Register 0 (ADC_1_TRC0)            */
    /*-----------------------------------------------------------*/
    //ADC_1.TRC[0].R = 0x00000000;

    /* Threshold detection for WatchDog 0 : Disabled */
    /* Threshold Inversion for WatchDog 0:DIsabled */
    /* Threshold Channel Select for WatchDog 0 : 0*/

    /*-----------------------------------------------------------*/
    /*         Threshold Control Register 1 (ADC_1_TRC1)            */
    /*-----------------------------------------------------------*/
    //ADC_1.TRC[1].R = 0x00000000;

    /* Threshold detection for WatchDog 1 : Disabled */
    /* Threshold Inversion for WatchDog 1:DIsabled */
    /* Threshold Channel Select for WatchDog 1 : 0*/

    /*-----------------------------------------------------------*/
    /*         Threshold Control Register 2 (ADC_1_TRC2)            */
    /*-----------------------------------------------------------*/
    //ADC_1.TRC[2].R = 0x00000000;

    /* Threshold detection for WatchDog 2 : Disabled */
    /* Threshold Inversion for WatchDog 2:DIsabled */
    /* Threshold Channel Select for WatchDog 2 : 0*/

    /*-----------------------------------------------------------*/
    /*         Threshold Control Register 3 (ADC_1_TRC3)            */
    /*-----------------------------------------------------------*/
    //ADC_1.TRC[3].R = 0x00000000;

    /* Threshold detection for WatchDog 3 : Disabled */
    /* Threshold Inversion for WatchDog 3:DIsabled */
    /* Threshold Channel Select for WatchDog 3 : 0*/

    /*-----------------------------------------------------------*/
    /*            Threshold Register 0 (ADC_1_THRHLR0)          */
    /*-----------------------------------------------------------*/
    ADC_1.THRHLR[0].R = 0x03FF0000;

    /* Lower Threshold value : 0    */
    /* Higher Threshold value : 1023    */

    /*-----------------------------------------------------------*/
    /*            Threshold Register 1 (ADC_1_THRHLR1)          */
    /*-----------------------------------------------------------*/
    ADC_1.THRHLR[1].R = 0x03FF0000;

    /* Lower Threshold value : 0    */
    /* Higher Threshold value : 1023    */

    /*-----------------------------------------------------------*/
    /*            Threshold Register 2 (ADC_1_THRHLR2)          */
    /*-----------------------------------------------------------*/
    ADC_1.THRHLR[2].R = 0x03FF0000;

    /* Lower Threshold value : 0    */
    /* Higher Threshold value : 1023    */

    /*-----------------------------------------------------------*/
    /*            Threshold Register 3 (ADC_1_THRHLR3)          */
    /*-----------------------------------------------------------*/
    ADC_1.THRHLR[3].R = 0x03FF0000;

    /* Lower Threshold value : 0    */
    /* Higher Threshold value : 1023    */

    /*-----------------------------------------------------------*/
    /*Watchdog Threshold Interrupt Mask Register (ADC_1_WTIMR) */
    /*-----------------------------------------------------------*/
    ADC_1.WTIMR.R = 0x00000000;

    /* Low Threshold Interrupt for Watchdog 0 : Disabled */
    /* Low Threshold Interrupt for Watchdog 1 : Disabled */
    /* Low Threshold Interrupt for Watchdog 2 : Disabled */
    /* Low Threshold Interrupt for Watchdog 3 : Disabled */
    /* High Threshold Interrupt for Watchdog 0 : Disabled */
    /* High Threshold Interrupt for Watchdog 1 : Disabled */
    /* High Threshold Interrupt for Watchdog 2 : Disabled */
    /* High Threshold Interrupt for Watchdog 3 : Disabled */
}

/*********************  DMA Setup Function(s)************************/
/******************************************************************************
*   Function:  adc_dma_setup_fnc
     @brief    ADC DMA Setup Function .
     @details       ADC DMA Setup Function

     @return none
*/
static  void adc_dma_setup_fnc()
{
    /*-----------------------------------------------------------*/
    /*            ADC 0  DMA Enable Register (DMAE)            */
    /*-----------------------------------------------------------*/
    ADC_0.DMAE.R = 0x00000000;

    /*DMA Global : Disabled */
    /*DMA clear sequence : ACK from DMA */
    /*-----------------------------------------------------------*/
    /*            ADC 0  DMA Channel Select Registers DMAR_0        */
    /*-----------------------------------------------------------*/
    ADC_0.DMAR[0].R = 0x00000000;

    /* DMA 0 Disable */
    /* DMA 1 Disable */
    /* DMA 2 Disable */
    /* DMA 3 Disable */
    /* DMA 4 Disable */
    /* DMA 5 Disable */
    /* DMA 6 Disable */
    /* DMA 7 Disable */
    /* DMA 8 Disable */
    /* DMA 9 Disable */
    /* DMA 10 Disable */
    /* DMA 11 Disable */
    /* DMA 12 Disable */
    /* DMA 13 Disable */
    /* DMA 14 Disable */
    /* DMA 15 Disable */

    /*-----------------------------------------------------------*/
    /*             ADC 1 DMA Enable Register (DMAE)        */
    /*-----------------------------------------------------------*/
    ADC_1.DMAE.R = 0x00000000;

    /*DMA Global : Disabled */
    /*DMA clear sequence : ACK from DMA */
    /*-----------------------------------------------------------*/
    /*            ADC 1  DMA Channel Select Registers DMAR_0        */
    /*-----------------------------------------------------------*/
    ADC_1.DMAR[0].R = 0x00000000;

    /* DMA 0 Disable */
    /* DMA 1 Disable */
    /* DMA 2 Disable */
    /* DMA 3 Disable */
    /* DMA 4 Disable */
    /* DMA 5 Disable */
    /* DMA 6 Disable */
    /* DMA 7 Disable */
    /* DMA 8 Disable */
    /* DMA 9 Disable */
    /* DMA 10 Disable */
    /* DMA 11 Disable */
    /* DMA 12 Disable */
    /* DMA 13 Disable */
    /* DMA 14 Disable */
    /* DMA 15 Disable */
  }

  /*********************  CTU Initialization Function(s)  ************************/
  /******************************************************************************
   *   Function:  adc_ctu_fnc
     @brief    ADC CTU Initialization Function .
     @details       ADC CTU Initialization Function

     @return none
   */
 static void adc_ctu_fnc()
  {
    /*-----------------------------------------------------------*/
    /*             ADC 0 CTU Control         */
    /*-----------------------------------------------------------*/
    ADC_0.MCR.B.CTUEN = 0;

    /* Cross Triggering Unit :  Disabled */

    /*-----------------------------------------------------------*/
    /*             ADC 1 CTU Control             */
    /*-----------------------------------------------------------*/
    ADC_1.MCR.B.CTUEN = 0;

    /* Cross Triggering Unit :  Disabled */
}

static void adc0_config(void)
{
    ADC_0.MCR.B.OWREN = 1;
    ADC_0.MCR.B.WLSIDE = 0;
    ADC_0.MCR.B.ADCLKSEL = 1;
    ADC_0.MCR.B.ACKO = 1;
    ADC_0.CTR0.B.INPLATCH = 0;
    ADC_0.CTR0.B.OFFSHIFT = 2;
    ADC_0.CTR0.B.INPCMP = 1;
    ADC_0.CTR0.B.INSAMP = 10;
    ADC_0.MCR.B.CTUEN = 1;
    ADC_0.CTR1.B.INPLATCH = 0;
    ADC_0.CTR1.B.INPCMP = 1;
    ADC_0.CTR1.B.INSAMP = 1;
    ADC_0.CTR1.B.TSENSOR_SEL = 0;
    ADC_0.PSCR.B.PREVAL0 = 0;
    ADC_0.PSCR.B.PRECONV = 0;
    return;
}

/*********************  Normal Software Trigger Function ************************/
/******************************************************************************
*   Function:  adc_normal_start_fnc
     @brief    Normal Software Trigger Function .
     @details   Normal Software Trigger Function

     @return none
*/
static void adc_normal_start_fnc(void)
{
    /*ADC 0*/
    ADC_0.MCR.B.NSTART = 1;

    /* Starts The Normal ADC Conversion */

    /*ADC 1*/
    ADC_1.MCR.B.NSTART = 1;

    /* Starts The Normal ADC Conversion */
}

#if 0
/*********************  Injected Software Trigger Function ************************/
/******************************************************************************
*   Function:  adc_injected_start_fnc
     @brief    Injected Software Trigger Function .
     @details   Injected Software Trigger Function

     @return none
*/
static void adc_injected_start_fnc(void)
{
    /*ADC 0*/
    ADC_0.MCR.B.JSTART = 1;

    /* Starts The Injected ADC Conversion */
    /*ADC 1*/
    ADC_1.MCR.B.JSTART = 1;

    /* Starts The Injected ADC Conversion */
}

/*********************  Normal Software Conversion  Stop Function ************************/
/******************************************************************************
*   Function:  adc_normal_stop_fnc
     @brief    Normal Software Conversion  Stop Function.
     @details   Normal Software Conversion  Stop Function

     @return none
*/
static void adc_normal_stop_fnc(void)
{
    /*ADC 0*/
    ADC_0.MCR.B.ABORT = 1;

    /*  Stops The Normal ADC Conversion */
    /*ADC 1*/
    ADC_1.MCR.B.ABORT = 1;

    /*  Stops The Normal ADC Conversion */
}

/*********************  Enter Powedown Mode Function ************************/
/******************************************************************************
*   Function:  adc_enter_powerdownmode_fnc
     @brief    Enter Powedown Mode Function.
     @details   Enter Powedown Mode Function

     @return none
*/
static void adc_enter_powerdownmode_fnc(void)
{
    /*ADC 0*/
    ADC_0.MCR.B.NSTART = 1;

    /*  Enter Power down state */
    /*ADC 1*/
    ADC_1.MCR.B.NSTART = 1;

    /*  Enter Power down state */
}

/*********************  Exit from Powedown Mode Function ************************/
/******************************************************************************
*   Function:  adc_exit_powerdownmode_fnc
     @brief    Exit from Powedown Mode Function.
     @details   Exit from Powedown Mode Function

     @return none
*/
static void adc_exit_powerdownmode_fnc(void)
{
    /*ADC 0*/
    ADC_0.MCR.B.PWDN = 0;

    /*  Exit Power down state */
    /*ADC 1*/
    ADC_1.MCR.B.PWDN = 0;

    /*  Exit Power down state */
  }
#endif

/*********************  Initialization Function(s) ************************/
/******************************************************************************
 *   Function:  adc_init_fnc
   @brief    ADC Initialization Function .
   @details       ADC Initialization Function

   @return none
 */
void ADC_init(void)
{
    /*-----------------------------------------------------------*/
    /*            Abort all conversion in process                */
    /*-----------------------------------------------------------*/
    ADC_0.MCR.B.ABORT = 1;
    ADC_1.MCR.B.ABORT = 1;

    /*-----------------------------------------------------------*/
    /*            ADC Sampling and ThresHold Configuration                    */
    /*-----------------------------------------------------------*/
    adc_sampling_setup_fnc();

    /*-----------------------------------------------------------*/
    /*            ADC General Setup                    */
    /*-----------------------------------------------------------*/
    adc_general_setup_fnc();

    /*-----------------------------------------------------------*/
    /*            ADC CTU Configuration        */
    /*-----------------------------------------------------------*/
    adc_ctu_fnc();

    /*-----------------------------------------------------------*/
    /*            ADC Interrupt Configuration                            */
    /*-----------------------------------------------------------*/
    adc_interrupt_setup_fnc();

    /*-----------------------------------------------------------*/
    /*            ADC Channel Configuration                    */
    /*-----------------------------------------------------------*/
    adc_channel_setup_fnc();

    /*-----------------------------------------------------------*/
    /*            ADC Trigger Configuration                    */
    /*-----------------------------------------------------------*/
    adc_trigger_setup_fnc();

    /*-----------------------------------------------------------*/
    /*            DMA Setup Function(s)                    */
    /*-----------------------------------------------------------*/
    adc_dma_setup_fnc();

    /*-----------------------------------------------------------*/
    /*            Exit the ABORT state                    */
    /*-----------------------------------------------------------*/
    ADC_0.MCR.B.ABORT = 0;
    ADC_1.MCR.B.ABORT = 0;

    adc0_config();
    adc_normal_start_fnc();

    /* Start for S-Function (adc_564xl_input): '<S1>/ADC Channel' */
    adc_pin_init( 0, 0);
    adc_channelmode_setup( 0, 0, 1);
    adc_presample( 0, 0, 0);
    adc_interrupt_set_channel( 0, 0);

    /* Start for S-Function (adc_564xl_input): '<S1>/ADC Channel2' */
    adc_pin_init( 0, 1);
    adc_channelmode_setup( 0, 1, 1);
    adc_presample( 0, 1, 0);
}

#ifdef __cplusplus

}
#endif

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
