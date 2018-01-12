#include "dspi_block1130.h"
#include "dspi_block1130_private.h"

void dspi1_isr(void)
{
  dspi_block1130_Y.Out1 = dspi_564xl_read_slave( 1);
  dspi_block1130_Subsystem();
  DSPI_1.SR.B.RFDF = 1;                //clear flag
}
