#include "DigitalIO_block_demo.h"
#include "DigitalIO_block_demo_private.h"

void PIT_Ch3_ISR(void)
{
  DigitalI_FunctionCallSubsystem2();
  PIT.CH[3].TFLG.B.TIF = 1 ;           /* Clear PIT Timer Interrupt Acknoledgement Flag */
}
