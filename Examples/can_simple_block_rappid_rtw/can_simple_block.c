/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: can_simple_block.c
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

/* Block signals (auto storage) */
BlockIO_can_simple_block can_simple_block_B;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_can_simple_bloc can_simple_block_Y;

/* Output and update for function-call system: '<Root>/Subsystem' */
void can_simple_block_Subsystem(void)
{
  int32_T i;

  /* Inport: '<S1>/In3' */
  for (i = 0; i < 8; i++) {
    can_simple_block_B.In3[i] = can_simple_block_B.CANReceiveDataTrigger1_o4[i];
  }

  /* End of Inport: '<S1>/In3' */
}

/* Model step function */
void can_simple_block_step(void)
{
  /* S-Function (can_564xl_receive_data): '<Root>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 7)) {
      can_simple_block_Y.Out3 = flexcan_564xl_get_id(0, 7);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 7);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&can_simple_block_Y.Out1[0])[i] = ptr_FLEXCAN_MsgBufferStructure->
          data[i];
      }

      can_simple_block_Y.Out2 = flexcan_564xl_get_idtype(0, 7);
      can_simple_block_Y.Out4 = flexcan_564xl_get_ts(0, 7);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 7);
    }
  }

  /* Outport: '<Root>/Out5' */
  can_simple_block_Y.Out5 = can_simple_block_B.In3[0];

  /* SignalConversion: '<Root>/TmpSignal ConversionAtCAN Transmit1Inport1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  Constant: '<Root>/Constant8'
   */
  can_simple_block_B.TmpSignalConversionAtCANTransmi[0] = 1U;
  can_simple_block_B.TmpSignalConversionAtCANTransmi[1] = 2U;
  can_simple_block_B.TmpSignalConversionAtCANTransmi[2] = 3U;
  can_simple_block_B.TmpSignalConversionAtCANTransmi[3] = 4U;
  can_simple_block_B.TmpSignalConversionAtCANTransmi[4] = 5U;
  can_simple_block_B.TmpSignalConversionAtCANTransmi[5] = 6U;
  can_simple_block_B.TmpSignalConversionAtCANTransmi[6] = 7U;
  can_simple_block_B.TmpSignalConversionAtCANTransmi[7] = 8U;

  /* S-Function (can_564xl_transmit): '<Root>/CAN Transmit1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    uint8_t* data = &can_simple_block_B.TmpSignalConversionAtCANTransmi[0];
    uint8_t datalen = ((uint8_T)8U);
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    ptr_FLEXCAN_MsgBufferStructure->length = datalen;
    if (522&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 522;
    for (i=0;i<datalen;i++) {
      ptr_FLEXCAN_MsgBufferStructure->data[i] = *(data++);
    }

    ptr_FLEXCAN_MsgBufferStructure->code = CAN_TX_MSG;
    flexcan_564xl_buffer_transmit(ptr_FLEXCAN_MsgBufferStructure,14,0);
    flexcan_564xl_release_mb_lock(0);
    flexcan_564xl_clear_mask(0, 14);
  }
}

/* Model initialize function */
void can_simple_block_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &can_simple_block_B), 0,
                sizeof(BlockIO_can_simple_block));

  /* external outputs */
  (void) memset((void *)&can_simple_block_Y, 0,
                sizeof(ExternalOutputs_can_simple_bloc));

  /* Start for S-Function (can_564xl_config): '<Root>/CAN Config' */
  flexcan_564xl_init( 0, 1342177343, 81461382);
  flexcan_564xl_pin_init( 0);

  /* Start for S-Function (can_564xl_receive_data): '<Root>/CAN_Receive_data1' */
  {
    if ((1010U & 0x1FFFF800) != 0x0) { //extended tag
      flexcan_564xl_set_filter_id(0, 7, 1010U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 7, 1010U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data_trigger): '<Root>/CAN Receive Data Trigger1' */
  flexcan_564xl_set_filter_id(0, 5, 1021, 0);
  CAN_0.IMASK1.R |= 1<<5;
}

/* Model terminate function */
void can_simple_block_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
