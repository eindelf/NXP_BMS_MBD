#include "DigitalIO_block_demo.h"
#include "DigitalIO_block_demo_private.h"

void PIT_Ch1_ISR(void)
{
  DigitalIO_FunctionCallSubsystem();
  PIT.CH[1].TFLG.B.TIF = 1 ;           /* Clear PIT Timer Interrupt Acknoledgement Flag */
}
