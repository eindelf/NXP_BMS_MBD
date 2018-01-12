#include "DigitalIO_block_demo.h"
#include "DigitalIO_block_demo_private.h"

void PIT_Ch2_ISR(void)
{
  DigitalI_FunctionCallSubsystem1();
  PIT.CH[2].TFLG.B.TIF = 1 ;           /* Clear PIT Timer Interrupt Acknoledgement Flag */
}
