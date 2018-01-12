#include "dspi_block.h"
#include "dspi_block_private.h"

void dspi1_2_isr(void)
{
  dspi_block_Subsystem2();

  {
    uint32_t flag = 0U;
    flag |= DSPI_ISR_EOQF_RE;
    DSPI_1.SR.R = flag;                //clear flag
  }
}
