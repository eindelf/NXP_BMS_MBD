/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    adc_564xl_library.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   ADC module support.
*    @details Implementation of ADC module functions.
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
 
#include "adc_564xl_library.h"
#include "adc_init.h"

static volatile ADC_tag* ADC[]={ &ADC_0, &ADC_1};

/**/
/******************************************************************************
*                   Local functions
******************************************************************************/

void adc_wdg_set_selector(uint8_t adc_num, uint8_t adc_chan);


/******************************************************************************
*   Function:  adc_wdg_set_selector
@brief    Sets the Channel Watchdog Selection Register . 
@details   Sets the Channel Watchdog Selection Register
    
@param[in]     adc_num     ADC Convertor number
@param[in]     adc_chan     ADC  channel 
   
@return none
*/
void adc_wdg_set_selector(uint8_t adc_num, uint8_t adc_chan)
{
	if (adc_chan < 8){
		ADC[adc_num]->CWSELR0.R |= (uint32_t)adc_chan << (adc_chan*4);
	}else{
		ADC[adc_num]->CWSELR1.R |= (uint32_t)adc_chan << ((adc_chan-8)*4);
	}
}

/******************************************************************************
*                   Global functions
******************************************************************************/

/******************************************************************************
*   Function:  adc_wdg_init
@brief    ADC WDG init function
@details   ADC WDG init function
    
@param[in]     adc_num     ADC Convertor number
@param[in]     adc_chan     ADC  channel 
@param[in]     mode           defines upper or lower threshold
@param[in]     value       threshold value for channel
   
@return none
*/
void adc_wdg_init(uint8_t adc_num, uint8_t adc_chan, uint16_t upValue, uint16_t lowValue)
{
	uint32_t mask = 0x0U;
	
	mask = 3U << (adc_chan*2);

	ADC[adc_num]->WTIMR.R |= mask;
	
	adc_wdg_set_selector( adc_num, adc_chan);
	
	ADC[adc_num]->CWENR0.R |= 0x1U << adc_chan;
	
	if (adc_chan == 0){
		ADC[adc_num]->THRHLR0.B.THRH = upValue;
		ADC[adc_num]->THRHLR0.B.THRL = lowValue;
	}else if (adc_chan == 1){
		ADC[adc_num]->THRHLR1.B.THRH = upValue;
		ADC[adc_num]->THRHLR1.B.THRL = lowValue;
	}else if (adc_chan == 2){
		ADC[adc_num]->THRHLR2.B.THRH = upValue;
		ADC[adc_num]->THRHLR2.B.THRL = lowValue;
	}else if (adc_chan == 3){
		ADC[adc_num]->THRHLR3.B.THRH = upValue;
		ADC[adc_num]->THRHLR3.B.THRL = lowValue;
	}else if (adc_chan == 4){
		ADC[adc_num]->THRHLR4.B.THRH = upValue;
		ADC[adc_num]->THRHLR4.B.THRL = lowValue;
	}else if (adc_chan == 5){
		ADC[adc_num]->THRHLR5.B.THRH = upValue;
		ADC[adc_num]->THRHLR5.B.THRL = lowValue;
	}else if (adc_chan == 6){
		ADC[adc_num]->THRHLR6.B.THRH = upValue;
		ADC[adc_num]->THRHLR6.B.THRL = lowValue;
	}else if (adc_chan == 7){
		ADC[adc_num]->THRHLR7.B.THRH = upValue;
		ADC[adc_num]->THRHLR7.B.THRL = lowValue;
	}else if (adc_chan == 8){
		ADC[adc_num]->THRHLR8.B.THRH = upValue;
		ADC[adc_num]->THRHLR8.B.THRL = lowValue;
	}else if (adc_chan == 9){
		ADC[adc_num]->THRHLR9.B.THRH = upValue;
		ADC[adc_num]->THRHLR9.B.THRL = lowValue;
	}else if (adc_chan == 10){
		ADC[adc_num]->THRHLR10.B.THRH = upValue;
		ADC[adc_num]->THRHLR10.B.THRL = lowValue;
	}else if (adc_chan == 11){
		ADC[adc_num]->THRHLR11.B.THRH = upValue;
		ADC[adc_num]->THRHLR11.B.THRL = lowValue;
	}else if (adc_chan == 12){
		ADC[adc_num]->THRHLR12.B.THRH = upValue;
		ADC[adc_num]->THRHLR12.B.THRL = lowValue;
	}else if (adc_chan == 13){
		ADC[adc_num]->THRHLR13.B.THRH = upValue;
		ADC[adc_num]->THRHLR13.B.THRL = lowValue;
	}else if (adc_chan == 14){
		ADC[adc_num]->THRHLR14.B.THRH = upValue;
		ADC[adc_num]->THRHLR14.B.THRL = lowValue;
	}else if (adc_chan == 15){
		ADC[adc_num]->THRHLR15.B.THRH = upValue;
		ADC[adc_num]->THRHLR15.B.THRL = lowValue;
	}

}

/******************************************************************************
*   Function:  adc_read_chan
@brief    ADC Read Data function . 
@details Detailed description of the function
    
@param[in]     adc_num      Specifies which ADC module is used
@param[in]     adc_chan_in      Specifies which ADC channel is used
   
@return The ADC convertion result
*/
uint16_t adc_read_chan(uint8_t adc_num, uint8_t adc_chan_in)
{
  uint16_t ret = 0U;
  
  while ( ADC[adc_num]->CDR[adc_chan_in].B.VALID == 0) {}
  ret = ADC[adc_num]->CDR[adc_chan_in].B.CDATA;
  
  return(ret);
}

/******************************************************************************
*   Function:  adc_pin_init
@brief    ADC Channel Pin Configuration Setup . 
@details ADC Init Channel PCR as Input function
    
@param[in]     adc_num      Specifies which ADC module is used
@param[in]     adc_chan_in      Specifies which ADC channel is used
   
@return none
*/
void adc_pin_init( uint8_t adc_num, uint8_t adc_chan_in )
{
   
  static uint8_t adc_ch2num[2][16] = {
/*  0   1   2   3   4   5   6   7   8  9 10  11  12  13  14 15  -- adc channel*/
  {23, 24, 33, 34, 70, 66, 71, 68, 69, 0, 0, 25, 26, 27, 28, 0},
  {29, 30, 31, 32, 75, 64, 76, 73, 74, 0, 0, 25, 26, 27, 28, 0}
  };
  
  uint8_t pcr_num = adc_ch2num[adc_num][adc_chan_in];
  
  if ( 0 != pcr_num){
	SIU.PCR[pcr_num].R = 0x2000;
  }

  return;
}

/******************************************************************************
*   Function:  adc_presample
@brief    ADC Channel presampling setup . 
@details ADC Conversion setup setup
    
@param[in]     adc_num     ADC Convertor number
@param[in]     adc_chan      Specifies which ADC channel is used
@param[in]      adc_presample       ,   2 - Injected
   
@return none
*/
void adc_presample( uint8_t adc_num, uint8_t adc_chan, uint8_t adc_presample){

	ADC[adc_num]->PSR0.R |= (uint32_t)adc_presample<<adc_chan;
}

/******************************************************************************
*   Function:  adc_channelmode_setup
@brief    ADC Conversion setup setup . 
@details ADC Conversion setup setup
    
@param[in]     adc_num     ADC Convertor number
@param[in]     adc_chan_in      Specifies which ADC channel is used
@param[in]      adc_mode       mode - 1 - Normal,   2 - Injected
   
@return none
*/
void adc_channelmode_setup(uint8_t adc_num, uint8_t adc_chan, uint8_t adc_mode)
{
	uint8_t chan = adc_chan;
	
	if (adc_mode == 1){
		ADC[adc_num]->NCMR0.R |= 1U << chan;;
		ADC[adc_num]->JCMR0.R &= ~(1U << chan);		
	} else if (adc_mode == 2){
		ADC[adc_num]->NCMR0.R &= ~(1U << chan);
		ADC[adc_num]->JCMR0.R |= 1U << chan;
	}
	
	return;
}

/******************************************************************************
*   Function:  adc_singleshot_set
@brief    Set single shot mode . 
@details Set single shot mode - Configures the normal conversion of one chain
    
@param[in]     adc_num     ADC Convertor number
   
@return none
*/
void adc_singleshot_set(uint8_t adc_num)
{
	ADC[adc_num]->MCR.B.MODE = 0;

	return;
}

/******************************************************************************
*   Function:  adc_scanmode_set
@brief    Set scan mode . 
@details    Scan Mode—Configures continuous chain conversion mode; when the programmed
                   chain conversion is finished it restarts immediately
    
@param[in]     adc_num     ADC Convertor number
   
@return none
*/
void adc_scanmode_set(uint8_t adc_num)
{
	ADC[adc_num]->MCR.B.MODE = 1;
	
	return;	
}

/******************************************************************************
*   Function:  adc_normal_stop
@brief    Stop Normal mode . 
@details Stop Normal mode
    
@param[in]     adc_num     ADC Convertor number
   
@return none
*/
void adc_normal_stop(uint8_t adc_num)
{
	
	ADC[adc_num]->MCR.B.NSTART = 0;
	ADC[adc_num]->MCR.B.ABORTCHAIN = 1;
	ADC[adc_num]->MCR.B.ABORT = 1;
	
	while(ADC[adc_num]->MSR.B.NSTART == 1){}
	
	return;
}

/******************************************************************************
*   Function:  adc_injected_start
@brief    Start injected mode . 
@details Start injected mode
    
@param[in]     adc_num     ADC Convertor number
   
@return none
*/
void adc_injected_start(uint8_t adc_num)
{
	
	ADC[adc_num]->MCR.B.JSTART = 1;
	
	while(ADC[adc_num]->MSR.B.JSTART == 0){}
	
	return;
}


/******************************************************************************
*   Function:  adc_normal_start
@brief    Start normal mode . 
@details Start normal mode
    
@param[in]     adc_num     ADC Convertor number
   
@return none
*/
void adc_normal_start( uint8_t adc_num )
{

	ADC[adc_num]->MCR.B.NSTART = 1;
	
	while(ADC[adc_num]->MSR.B.NSTART == 0){}

	return;
}

/******************************************************************************
*   Function:  adc_interrupt_set_imr
@brief    Set ISR mode . 
@details  Set ISR mode
    
@param[in]     adc_num     ADC Convertor number
@param[in]     adc_isr_mode     ADC  ISR mode 
   
@return none
*/
void adc_interrupt_set_imr( uint8_t adc_num, uint8_t adc_isr_mode)
{

	ADC[adc_num]->IMR.R = adc_isr_mode;

	return;
}

/******************************************************************************
*   Function:  adc_interrupt_set_channel
@brief    Enable the insterrupt for the channel . 
@details  Enable the insterrupt for the channel
    
@param[in]     adc_num     ADC Convertor number
@param[in]     adc_chan     ADC  channel 
   
@return none
*/
void adc_interrupt_set_channel( uint8_t adc_num, uint8_t adc_chan)
{

	uint8_t chan = adc_chan;
	
	ADC[adc_num]->CIMR0.R |= 1U << chan;

	return;
}

/******************************************************************************
*   Function:  adc_interrupt_clear_channel
@brief    Disable the insterrupt for the channel . 
@details  Disable the insterrupt for the channel
    
@param[in]     adc_num     ADC Convertor number
@param[in]     adc_chan     ADC  channel 
   
@return none
*/
void adc_interrupt_clear_channel( uint8_t adc_num, uint8_t adc_chan)
{

	uint8_t chan = adc_chan;
	
	ADC[adc_num]->CIMR0.R &= ~(1U << chan);

	return;

}

#ifdef __cplusplus
}
#endif

/*
*######################################################################
*                           End of File
*######################################################################
*/
