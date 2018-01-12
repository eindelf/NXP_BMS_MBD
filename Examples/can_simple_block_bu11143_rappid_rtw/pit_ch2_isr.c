#include "can_simple_block_bu11143.h"
#include "can_simple_block_bu11143_private.h"

void PIT_Ch2_ISR(void)
{
  DataDumpFast();
  PIT.CH[2].TFLG.B.TIF = 1 ;           /* Clear PIT Timer Interrupt Acknoledgement Flag */
}
