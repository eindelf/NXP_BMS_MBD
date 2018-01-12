#include "can_simple_block_bu11143.h"
#include "can_simple_block_bu11143_private.h"

void dspi1_2_isr(void)
{
  Subsystem2();

  {
    uint32_t flag = 0U;
    flag |= DSPI_ISR_EOQF_RE;
    DSPI_1.SR.R = flag;                //clear flag
  }
}
