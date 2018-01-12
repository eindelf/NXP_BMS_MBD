#include "dspi_block.h"
#include "dspi_block_private.h"

void dspi1_4_isr(void)
{
  dspi_block_Subsystem1();

  {
    uint32_t flag = 0U;
    flag |= DSPI_ISR_TCF_RE;
    DSPI_1.SR.R = flag;                //clear flag
  }
}
