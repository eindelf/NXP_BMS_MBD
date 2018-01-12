#include "can_simple_block_bu1114.h"
#include "can_simple_block_bu1114_private.h"

void PIT_Ch1_ISR(void)
{
  FunctionCallSubsystem();
  PIT.CH[1].TFLG.B.TIF = 1 ;           /* Clear PIT Timer Interrupt Acknoledgement Flag */
}
