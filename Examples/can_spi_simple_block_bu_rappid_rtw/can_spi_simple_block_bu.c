/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: can_spi_simple_block_bu.c
 *
 * Code generated for Simulink model 'can_spi_simple_block_bu'.
 *
 * Model version                  : 1.94
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Wed Nov 29 13:29:53 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "can_spi_simple_block_bu.h"
#include "can_spi_simple_block_bu_private.h"

/* Block signals (auto storage) */
BlockIO_can_spi_simple_block_bu can_spi_simple_block_bu_B;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_can_spi_simple_ can_spi_simple_block_bu_Y;

/* Output and update for function-call system: '<Root>/Subsystem' */
void can_spi_simple_block__Subsystem(void)
{
  int32_T i;

  /* Inport: '<S1>/In3' */
  for (i = 0; i < 8; i++) {
    can_spi_simple_block_bu_B.In3[i] =
      can_spi_simple_block_bu_B.CANReceiveDataTrigger1_o4[i];
  }

  /* End of Inport: '<S1>/In3' */
}

/* Model step function */
void can_spi_simple_block_bu_step(void)
{
  /* S-Function (dspi_564xl_transmit): '<Root>/DSPI Transmit' */
  {
    DSPI_PUSHR_32B_tag pushr;
    pushr.R = 0U;
    pushr.B.TXDATA = can_spi_simple_block_bu_ConstB.DataTypeConversion4;
    pushr.R |= (uint32_t)32769<<16;
    dspi_564xl_send(1,pushr);
  }

  /* S-Function (can_564xl_receive_data): '<Root>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 7)) {
      can_spi_simple_block_bu_Y.Out3 = flexcan_564xl_get_id(0, 7);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 7);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&can_spi_simple_block_bu_Y.Out1[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      can_spi_simple_block_bu_Y.Out2 = flexcan_564xl_get_idtype(0, 7);
      can_spi_simple_block_bu_Y.Out4 = flexcan_564xl_get_ts(0, 7);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 7);
    }
  }

  /* Outport: '<Root>/Out5' */
  can_spi_simple_block_bu_Y.Out5 = can_spi_simple_block_bu_B.In3[0];

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
  can_spi_simple_block_bu_B.TmpSignalConversionAtCANTransmi[0] = 1U;
  can_spi_simple_block_bu_B.TmpSignalConversionAtCANTransmi[1] = 2U;
  can_spi_simple_block_bu_B.TmpSignalConversionAtCANTransmi[2] = 3U;
  can_spi_simple_block_bu_B.TmpSignalConversionAtCANTransmi[3] = 4U;
  can_spi_simple_block_bu_B.TmpSignalConversionAtCANTransmi[4] = 5U;
  can_spi_simple_block_bu_B.TmpSignalConversionAtCANTransmi[5] = 6U;
  can_spi_simple_block_bu_B.TmpSignalConversionAtCANTransmi[6] = 7U;
  can_spi_simple_block_bu_B.TmpSignalConversionAtCANTransmi[7] = 8U;

  /* S-Function (can_564xl_transmit): '<Root>/CAN Transmit1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    uint8_t* data = &can_spi_simple_block_bu_B.TmpSignalConversionAtCANTransmi[0];
    uint8_t datalen = ((uint8_T)8U);
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    ptr_FLEXCAN_MsgBufferStructure->length = datalen;
    if (522&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 522;
    ptr_FLEXCAN_MsgBufferStructure->id = 1002;
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
void can_spi_simple_block_bu_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &can_spi_simple_block_bu_B), 0,
                sizeof(BlockIO_can_spi_simple_block_bu));

  /* external outputs */
  (void) memset((void *)&can_spi_simple_block_bu_Y, 0,
                sizeof(ExternalOutputs_can_spi_simple_));

  /* Start for S-Function (can_564xl_config): '<Root>/CAN Config' */
  flexcan_564xl_init( 0, 1342177343, 81461382);
  flexcan_564xl_pin_init( 0);

  /* Start for S-Function (dspi_564xl_config): '<Root>/DSPI Config' */
  dspi_564xl_config( 1, -2130759679, 2013951783);

  /* Start for S-Function (dspi_564xl_transmit): '<Root>/DSPI Transmit' */
  dspi_564xl_pin_init(5, 1, 1);
  dspi_564xl_pin_init(8, 0, 1);
  dspi_564xl_pin_init(7, 1, 1);
  dspi_564xl_pin_init(6, 1, 1);

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
void can_spi_simple_block_bu_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
