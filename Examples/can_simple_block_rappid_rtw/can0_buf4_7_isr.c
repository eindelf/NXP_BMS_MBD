/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: can0_buf4_7_isr.c
 *
 * Code generated for Simulink model 'can_simple_block'.
 *
 * Model version                  : 1.83
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Wed Oct 11 15:09:29 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "can_simple_block.h"
#include "can_simple_block_private.h"

void can0_buf4_7_isr(void)
{
  FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
  FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
  uint32_t isr_mask = CAN_0.IFLAG1.R;
  if (isr_mask & 1<<5) {
    if (flexcan_564xl_rxbuffull( 0, 5)) {
      uint8_t i = 0U;
      ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
      memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
             (*ptr_FLEXCAN_MsgBufferStructure));
      can_simple_block_B.CANReceiveDataTrigger1_o2 = flexcan_564xl_get_id(0, 5);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 5);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&can_simple_block_B.CANReceiveDataTrigger1_o4[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      can_simple_block_B.CANReceiveDataTrigger1_o3 = flexcan_564xl_get_idtype(0,
        5);
      can_simple_block_B.CANReceiveDataTrigger1_o5 = flexcan_564xl_get_ts(0, 5);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 5);
      CAN_0.IFLAG1.R = 1<<5;
      can_simple_block_Subsystem();
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
