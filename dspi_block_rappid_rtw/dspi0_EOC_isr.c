#include "dspi_block.h"
#include "dspi_block_private.h"

void dspi0_isr(void)
{
  dspi_block_Y.Out1 = dspi_564xl_read_master( 0);
  dspi_block_Subsystem();
  DSPI_0.SR.B.RFDF = 1;                //clear flag
}
