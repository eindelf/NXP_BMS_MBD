#include "dspi_block_bu1130.h"
#include "dspi_block_bu1130_private.h"

void dspi0_4_isr(void)
{
  dspi_block_bu1130_Subsystem1();

  {
    uint32_t flag = 0U;
    flag |= DSPI_ISR_TCF_RE;
    DSPI_0.SR.R = flag;                //clear flag
  }
}
