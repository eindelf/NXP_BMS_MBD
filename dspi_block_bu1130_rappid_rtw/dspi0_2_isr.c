#include "dspi_block_bu1130.h"
#include "dspi_block_bu1130_private.h"

void dspi0_2_isr(void)
{
  dspi_block_bu1130_Subsystem2();

  {
    uint32_t flag = 0U;
    flag |= DSPI_ISR_EOQF_RE;
    DSPI_0.SR.R = flag;                //clear flag
  }
}
