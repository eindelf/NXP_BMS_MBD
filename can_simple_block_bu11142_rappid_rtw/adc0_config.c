#include "can_simple_block_bu11142.h"
#include "can_simple_block_bu11142_private.h"

void adc0_config(void)
{
  ADC_0.MCR.B.OWREN = 1;
  ADC_0.MCR.B.WLSIDE = 0;
  ADC_0.MCR.B.ADCLKSEL = 1;
  ADC_0.MCR.B.ACKO = 1;
  ADC_0.CTR0.B.INPLATCH = 0;
  ADC_0.CTR0.B.OFFSHIFT = 2;
  ADC_0.CTR0.B.INPCMP = 1;
  ADC_0.CTR0.B.INSAMP = 3;
  ADC_0.MCR.B.CTUEN = 0;
  ADC_0.CTR1.B.INPLATCH = 0;
  ADC_0.CTR1.B.INPCMP = 1;
  ADC_0.CTR1.B.INSAMP = 1;
  ADC_0.CTR1.B.TSENS = 0;
  ADC_0.PSCR.B.PREVAL0 = 0;
  ADC_0.PSCR.B.PRECONV = 0;
  return;
}
