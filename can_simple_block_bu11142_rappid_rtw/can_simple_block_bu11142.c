/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: can_simple_block_bu11142.c
 *
 * Code generated for Simulink model 'can_simple_block_bu11142'.
 *
 * Model version                  : 1.1257
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Jan 02 13:58:39 2018
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "can_simple_block_bu11142.h"
#include "can_simple_block_bu11142_private.h"

/* Named constants for Chart: '<S18>/Chart1' */
#define IN_A                           ((uint8_T)1U)
#define IN_A1                          ((uint8_T)2U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)

/* Named constants for Chart: '<S7>/Chart' */
#define IN_A1_a                        ((uint8_T)2U)
#define IN_A_n                         ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD_d           ((uint8_T)0U)

/* Named constants for Chart: '<S2>/Chart' */
#define IN_A1_c                        ((uint8_T)2U)
#define IN_A_j                         ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD_j           ((uint8_T)0U)

/* Named constants for Chart: '<S2>/Data collection chart' */
#define IN_GPIO123                     ((uint8_T)1U)
#define IN_GPIO45_Vref                 ((uint8_T)2U)
#define IN_Vol_C123                    ((uint8_T)3U)
#define IN_Vol_C456                    ((uint8_T)4U)
#define IN_Vol_C789                    ((uint8_T)5U)

/* Block signals and states (auto storage) */
D_Work rtDWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void can_simple_block_bu11142_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(rtM, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [1.0s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Output and update for function-call system: '<Root>/Subsystem' */
void Subsystem(void)
{
  int32_T i;

  /* Inport: '<S5>/In3' */
  for (i = 0; i < 8; i++) {
    rtDWork.In3[i] = rtDWork.CANReceiveDataTrigger1_o4[i];
  }

  /* End of Inport: '<S5>/In3' */
}

/* System initialize for function-call system: '<Root>/Subsystem2' */
void Subsystem2_Init(void)
{
  /* SystemInitialize for Chart: '<S7>/Chart' */
  rtDWork.A_m = false;
}

/* System reset for function-call system: '<Root>/Subsystem2' */
void Subsystem2_Reset(void)
{
  /* SystemReset for Chart: '<S7>/Chart' */
  rtDWork.is_active_c1_can_simple_block_b = 0U;
  rtDWork.is_c1_can_simple_block_bu11142 = IN_NO_ACTIVE_CHILD_d;
  rtDWork.count_k = 0U;
  rtDWork.A_m = false;
}

/* Start for function-call system: '<Root>/Subsystem2' */
void Subsystem2_Start(void)
{
  /* Start for S-Function (gpio_564xl_output): '<S7>/Digital Output 4' */

  /* Initialize Pad Configuration Register 12 as Output */
  gpo_init_pcr_out_564xl_fnc( 12 );
}

/* Output and update for function-call system: '<Root>/Subsystem2' */
void Subsystem2(void)
{
  /* S-Function (SPIRead): '<S7>/S-Function Builder1' */
  SPIRead_Outputs_wrapper( &rtDWork.SFunctionBuilder1_o1,
    &rtDWork.SFunctionBuilder1_o2, &rtDWork.SFunctionBuilder1_o3,
    &rtDWork.SFunctionBuilder1_o4 );

  /* Chart: '<S7>/Chart' */
  /* Gateway: Subsystem2/Chart */
  /* During: Subsystem2/Chart */
  if (rtDWork.is_active_c1_can_simple_block_b == 0U) {
    /* Entry: Subsystem2/Chart */
    rtDWork.is_active_c1_can_simple_block_b = 1U;

    /* Entry Internal: Subsystem2/Chart */
    /* Transition: '<S28>:1' */
    rtDWork.count_k = 0U;
    rtDWork.is_c1_can_simple_block_bu11142 = IN_A_n;
    rtDWork.A_m = true;
  } else if (rtDWork.is_c1_can_simple_block_bu11142 == IN_A_n) {
    /* During 'A': '<S28>:3' */
    /* Transition: '<S28>:7' */
    rtDWork.A_m = false;
    rtDWork.is_c1_can_simple_block_bu11142 = IN_A1_a;
  } else {
    /* During 'A1': '<S28>:6' */
    /* Transition: '<S28>:8' */
    rtDWork.count_k++;
    rtDWork.is_c1_can_simple_block_bu11142 = IN_A_n;
    rtDWork.A_m = true;
  }

  /* End of Chart: '<S7>/Chart' */

  /* S-Function (gpio_564xl_output): '<S7>/Digital Output 4' */

  /* Pin Data Output Signal Update PCR[12]. */
  gpo_pin_update_564xl_fnc(12, rtDWork.A_m);/* GPO Pin Data Output Register Update */
}

real_T rt_roundd(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* System reset for function-call system: '<S2>/Subsystem' */
void Subsystem_Reset(rtDW_Subsystem *localDW)
{
  /* SystemReset for Chart: '<S18>/Chart1' */
  localDW->is_active_c19_can_simple_block_ = 0U;
  localDW->is_c19_can_simple_block_bu11142 = IN_NO_ACTIVE_CHILD;
  localDW->count = 0.0;
}

/* Output and update for function-call system: '<S2>/Subsystem' */
void Subsystem_i(rtDW_Subsystem *localDW, uint16_T rtd_CellV_1_104[104])
{
  int32_T i;
  uint16_T tmp;

  /* Chart: '<S18>/Chart1' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  /* Gateway: Function-Call
     Subsystem/Subsystem/Chart1 */
  /* During: Function-Call
     Subsystem/Subsystem/Chart1 */
  if (localDW->is_active_c19_can_simple_block_ == 0U) {
    /* Entry: Function-Call
       Subsystem/Subsystem/Chart1 */
    localDW->is_active_c19_can_simple_block_ = 1U;

    /* Entry Internal: Function-Call
       Subsystem/Subsystem/Chart1 */
    /* Transition: '<S20>:1' */
    localDW->count = 0.0;
    localDW->is_c19_can_simple_block_bu11142 = IN_A;

    /* Entry 'A': '<S20>:3' */
    localDW->count++;
  } else if (localDW->is_c19_can_simple_block_bu11142 == IN_A) {
    /* During 'A': '<S20>:3' */
    if (localDW->count >= 7.0) {
      /* Transition: '<S20>:7' */
      localDW->is_c19_can_simple_block_bu11142 = IN_A1;

      /* Entry 'A1': '<S20>:6' */
      localDW->count = 1.0;
    } else {
      localDW->count++;
    }
  } else {
    /* During 'A1': '<S20>:6' */
    /* Transition: '<S20>:8' */
    localDW->is_c19_can_simple_block_bu11142 = IN_A;

    /* Entry 'A': '<S20>:3' */
    localDW->count++;
  }

  /* End of Chart: '<S18>/Chart1' */

  /* MATLAB Function: '<S18>/RawData to StoreData' */
  /* MATLAB Function 'Function-Call Subsystem/Subsystem/RawData to StoreData': '<S21>:1' */
  /* '<S21>:1:4' VTDataCAN_8b =  uint8(zeros(1,8)); */
  for (i = 0; i < 8; i++) {
    localDW->VTDataCAN_8b[i] = 0U;
  }

  /* '<S21>:1:6' VTDataCAN_8b(1) =         CellV_1_104(StrCell*4-3)/256; */
  i = (int32_T)rt_roundd((real_T)rtd_CellV_1_104[(int32_T)(localDW->count * 4.0
    - 3.0) - 1] / 256.0);
  tmp = (uint16_T)i;
  if ((uint16_T)i > 255) {
    tmp = 255U;
  }

  localDW->VTDataCAN_8b[0] = (uint8_T)tmp;

  /* '<S21>:1:7' VTDataCAN_8b(2) = mod(CellV_1_104(StrCell*4-3),256); */
  tmp = (uint16_T)((uint32_T)rtd_CellV_1_104[(int32_T)(localDW->count * 4.0 -
    3.0) - 1] - ((int32_T)((uint32_T)rtd_CellV_1_104[(int32_T)(localDW->count *
    4.0 - 3.0) - 1] >> 8) << 8));
  if (tmp > 255) {
    tmp = 255U;
  }

  localDW->VTDataCAN_8b[1] = (uint8_T)tmp;

  /* '<S21>:1:8' VTDataCAN_8b(3) =         CellV_1_104(StrCell*4-2)/256; */
  i = (int32_T)rt_roundd((real_T)rtd_CellV_1_104[(int32_T)(localDW->count * 4.0
    - 2.0) - 1] / 256.0);
  tmp = (uint16_T)i;
  if ((uint16_T)i > 255) {
    tmp = 255U;
  }

  localDW->VTDataCAN_8b[2] = (uint8_T)tmp;

  /* '<S21>:1:9' VTDataCAN_8b(4) = mod(CellV_1_104(StrCell*4-2),256); */
  tmp = (uint16_T)((uint32_T)rtd_CellV_1_104[(int32_T)(localDW->count * 4.0 -
    2.0) - 1] - ((int32_T)((uint32_T)rtd_CellV_1_104[(int32_T)(localDW->count *
    4.0 - 2.0) - 1] >> 8) << 8));
  if (tmp > 255) {
    tmp = 255U;
  }

  localDW->VTDataCAN_8b[3] = (uint8_T)tmp;

  /* '<S21>:1:10' VTDataCAN_8b(5) =         CellV_1_104(StrCell*4-1)/256; */
  i = (int32_T)rt_roundd((real_T)rtd_CellV_1_104[(int32_T)(localDW->count * 4.0
    - 1.0) - 1] / 256.0);
  tmp = (uint16_T)i;
  if ((uint16_T)i > 255) {
    tmp = 255U;
  }

  localDW->VTDataCAN_8b[4] = (uint8_T)tmp;

  /* '<S21>:1:11' VTDataCAN_8b(6) = mod(CellV_1_104(StrCell*4-1),256); */
  tmp = (uint16_T)((uint32_T)rtd_CellV_1_104[(int32_T)(localDW->count * 4.0 -
    1.0) - 1] - ((int32_T)((uint32_T)rtd_CellV_1_104[(int32_T)(localDW->count *
    4.0 - 1.0) - 1] >> 8) << 8));
  if (tmp > 255) {
    tmp = 255U;
  }

  localDW->VTDataCAN_8b[5] = (uint8_T)tmp;

  /* '<S21>:1:12' VTDataCAN_8b(7) =         CellV_1_104(StrCell*4   )/256; */
  i = (int32_T)rt_roundd((real_T)rtd_CellV_1_104[(int32_T)(localDW->count * 4.0)
    - 1] / 256.0);
  tmp = (uint16_T)i;
  if ((uint16_T)i > 255) {
    tmp = 255U;
  }

  localDW->VTDataCAN_8b[6] = (uint8_T)tmp;

  /* '<S21>:1:13' VTDataCAN_8b(8) = mod(CellV_1_104(StrCell*4   ),256); */
  tmp = (uint16_T)((uint32_T)rtd_CellV_1_104[(int32_T)(localDW->count * 4.0) - 1]
                   - ((int32_T)((uint32_T)rtd_CellV_1_104[(int32_T)
    (localDW->count * 4.0) - 1] >> 8) << 8));
  if (tmp > 255) {
    tmp = 255U;
  }

  localDW->VTDataCAN_8b[7] = (uint8_T)tmp;

  /* End of MATLAB Function: '<S18>/RawData to StoreData' */
  /*  VTDataCAN_8b(1) =         CellV_1_104(1)/256; */
  /*  VTDataCAN_8b(2) = mod(CellV_1_104(1),256); */
  /*  VTDataCAN_8b(3) =         CellV_1_104(2)/256; */
  /*  VTDataCAN_8b(4) = mod(CellV_1_104(2),256); */
  /*  VTDataCAN_8b(5) =         CellV_1_104(9)/256; */
  /*  VTDataCAN_8b(6) = mod(CellV_1_104(9),256); */
  /*  VTDataCAN_8b(7) =         CellV_1_104(10)/256; */
  /*  VTDataCAN_8b(8) = mod(CellV_1_104(10),256); */
  /*  VTDataCAN_8b(1) =         uint16(30000)/256; */
  /*  VTDataCAN_8b(2) = mod(uint16(30000),256); */
  /*  VTDataCAN_8b(3) =         uint16(35000)/256; */
  /*  VTDataCAN_8b(4) = mod(uint16(35000),256); */
  /*  VTDataCAN_8b(5) =         uint16(33000)/256; */
  /*  VTDataCAN_8b(6) = mod(uint16(33000),256); */
  /*  VTDataCAN_8b(7) =         uint16(20000)/256; */
  /*  VTDataCAN_8b(8) = mod(uint16(20000),256); */
  /*  CellV_1_104(1) = uint16(1); */
  /*  SPIDataStore = uint16(zeros(1,21)); */
  /*  DataFault =  zeros(1,7); */
  /*  */
  /*  for i=1:7 */
  /*    SPIDataStore(i*3-2) = SPIData(i*8-7)+SPIData(i*8-6)*256; */
  /*    SPIDataStore(i*3-1) = SPIData(i*8-5)+SPIData(i*8-4)*256; */
  /*    SPIDataStore(i*3   ) = SPIData(i*8-3)+SPIData(i*8-2)*256; */
  /*    if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
  /*      DataFault(i) = 1; */
  /*    else */
  /*      DataFault(i) = 0; */
  /*    end */
  /*  end */
  /*  onemask8 = uint16(hex2dec('00FF')); */
  /*  onemask8_8sft = uint16(hex2dec('FF00')); */
  /*  onemask88 = uint8(hex2dec('FF')); */
  /*  onemask16 = uint16(hex2dec('FFFF')); */
  /*  */
  /*  % data_test = zeros(1,2); */
  /*  remainder = uint16(16); */
  /*  */
  /*  for i=1:len */
  /*      ii = uint16(i); */
  /*  %     data_test(1,i) = data(ii); */
  /*  %     address = 2; */
  /*      address = bitand( ... */
  /*          bitxor( ... */
  /*          uint8(bitsra(remainder,7)),data(ii) ), ... */
  /*          onemask88); */
  /*      remainder = bitxor(bitshift(remainder,8,'uint16'),pec15Table(address+1)); */
  /*  end */
  /*  pec15 = uint16(bitand(bitshift(remainder,1,'uint16'),onemask16)); */
  /*  pec0 = uint8(bitand(pec15,onemask8)); */
  /*  pec1 = uint8(bitsra(bitand(pec15,onemask8_8sft),8)); */

  /* S-Function (can_564xl_transmit): '<S18>/CAN Transmit1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    uint8_t* data = &localDW->VTDataCAN_8b[0];
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

/* Output and update for function-call system: '<S2>/Subsystem1' */
void Subsystem1(uint16_T rtd_CellSOC_1_104[104])
{
  /* DataStoreWrite: '<S19>/Data Store Write SOC_1c_8c' */
  memset(&rtd_CellSOC_1_104[0], 0, 104U * sizeof(uint16_T));

  /* S-Function (SOCEstimationInit): '<S19>/S-Function Builder1' */
  SOCEstimationInit_Outputs_wrapper( );
}

/* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
void FunctionCallSubsystem_Init(void)
{
  /* SystemInitialize for Chart: '<S2>/Chart' */
  rtDWork.A = false;
}

/* System reset for function-call system: '<Root>/Function-Call Subsystem' */
void FunctionCallSubsystem_Reset(void)
{
  /* SystemReset for Chart: '<S2>/Chart' */
  rtDWork.is_active_c7_can_simple_block_b = 0U;
  rtDWork.is_c7_can_simple_block_bu11142 = IN_NO_ACTIVE_CHILD_j;
  rtDWork.count_a = 0.0;
  rtDWork.A = false;
  rtDWork.is_active_c17_can_simple_block_ = 0U;
  rtDWork.is_c17_can_simple_block_bu11142 = IN_NO_ACTIVE_CHILD_j;
  rtDWork.count_o = 0.0;

  /* SystemReset for Chart: '<S2>/Chart1' incorporates:
   *  SystemReset for SubSystem: '<S2>/Subsystem'
   */
  Subsystem_Reset(&rtDWork.Subsystem_i5);

  /* SystemReset for Chart: '<S2>/Chart2' */
  rtDWork.is_active_c9_can_simple_block_b = 0U;
  rtDWork.is_c9_can_simple_block_bu11142 = IN_NO_ACTIVE_CHILD_j;
  rtDWork.count_m = 0.0;

  /* SystemReset for Chart: '<S2>/Data collection chart' */
  rtDWork.is_active_c15_can_simple_block_ = 0U;
  rtDWork.is_c15_can_simple_block_bu11142 = IN_NO_ACTIVE_CHILD_j;
  rtDWork.count = 0.0;
  rtDWork.CMD32[0] = 0U;
  rtDWork.CMD32[1] = 0U;
  rtDWork.CMD32[2] = 0U;
  rtDWork.CMD32[3] = 0U;
}

/* Start for function-call system: '<Root>/Function-Call Subsystem' */
void FunctionCallSubsystem_Start(void)
{
  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 1' */

  /* Initialize Pad Configuration Register 78 as Output */
  gpo_init_pcr_out_564xl_fnc( 78 );
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
void FunctionCallSubsystem(void)
{
  int32_T rtb_STATE;

  /* Chart: '<S2>/Chart' */
  /* Gateway: Function-Call
     Subsystem/Chart */
  /* During: Function-Call
     Subsystem/Chart */
  if (rtDWork.is_active_c7_can_simple_block_b == 0U) {
    /* Entry: Function-Call
       Subsystem/Chart */
    rtDWork.is_active_c7_can_simple_block_b = 1U;

    /* Entry Internal: Function-Call
       Subsystem/Chart */
    /* Transition: '<S10>:1' */
    rtDWork.count_a = 0.0;
    rtDWork.is_c7_can_simple_block_bu11142 = IN_A_j;
    rtDWork.A = true;
  } else if (rtDWork.is_c7_can_simple_block_bu11142 == IN_A_j) {
    /* During 'A': '<S10>:3' */
    /* Transition: '<S10>:7' */
    rtDWork.A = false;
    rtDWork.is_c7_can_simple_block_bu11142 = IN_A1_c;
  } else {
    /* During 'A1': '<S10>:6' */
    /* Transition: '<S10>:8' */
    rtDWork.count_a++;
    rtDWork.is_c7_can_simple_block_bu11142 = IN_A_j;
    rtDWork.A = true;
  }

  /* End of Chart: '<S2>/Chart' */

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 1' */

  /* Pin Data Output Signal Update PCR[78]. */
  gpo_pin_update_564xl_fnc(78, rtDWork.A);/* GPO Pin Data Output Register Update */

  /* Chart: '<S2>/Chart1' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  /* Gateway: Function-Call
     Subsystem/Chart1 */
  /* During: Function-Call
     Subsystem/Chart1 */
  if (rtDWork.is_active_c17_can_simple_block_ == 0U) {
    /* Entry: Function-Call
       Subsystem/Chart1 */
    rtDWork.is_active_c17_can_simple_block_ = 1U;

    /* Entry Internal: Function-Call
       Subsystem/Chart1 */
    /* Transition: '<S11>:1' */
    rtDWork.is_c17_can_simple_block_bu11142 = IN_A_j;

    /* Entry 'A': '<S11>:3' */
    rtDWork.count_o = 0.0;
  } else if (rtDWork.is_c17_can_simple_block_bu11142 == IN_A_j) {
    /* During 'A': '<S11>:3' */
    if (rtDWork.count_o > 10.0) {
      /* Outputs for Function Call SubSystem: '<S2>/Subsystem' */

      /* Transition: '<S11>:7' */
      /* Event: '<S11>:12' */
      Subsystem_i(&rtDWork.Subsystem_i5, rtDWork.CellV_1_104);

      /* End of Outputs for SubSystem: '<S2>/Subsystem' */
      rtDWork.is_c17_can_simple_block_bu11142 = IN_A1_c;

      /* Entry 'A1': '<S11>:6' */
      rtDWork.count_o = 0.0;
    } else {
      rtDWork.count_o++;
    }
  } else {
    /* During 'A1': '<S11>:6' */
    /* Transition: '<S11>:8' */
    rtDWork.is_c17_can_simple_block_bu11142 = IN_A_j;

    /* Entry 'A': '<S11>:3' */
    rtDWork.count_o = 0.0;
  }

  /* End of Chart: '<S2>/Chart1' */

  /* Chart: '<S2>/Chart2' incorporates:
   *  Constant: '<S2>/Constant10'
   */
  /* Gateway: Function-Call
     Subsystem/Chart2 */
  /* During: Function-Call
     Subsystem/Chart2 */
  if (rtDWork.is_active_c9_can_simple_block_b == 0U) {
    /* Entry: Function-Call
       Subsystem/Chart2 */
    rtDWork.is_active_c9_can_simple_block_b = 1U;

    /* Entry Internal: Function-Call
       Subsystem/Chart2 */
    /* Transition: '<S12>:1' */
    rtDWork.is_c9_can_simple_block_bu11142 = IN_A_j;

    /* Entry 'A': '<S12>:3' */
    rtDWork.count_m = 0.0;
  } else if (rtDWork.is_c9_can_simple_block_bu11142 == IN_A_j) {
    /* During 'A': '<S12>:3' */
    if (rtDWork.count_m > 5.0) {
      /* Outputs for Function Call SubSystem: '<S2>/Subsystem1' */

      /* Transition: '<S12>:7' */
      /* Event: '<S12>:12' */
      Subsystem1(rtDWork.CellSOC_1_104);

      /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
      rtDWork.is_c9_can_simple_block_bu11142 = IN_A1_c;

      /* Entry 'A1': '<S12>:6' */
      rtDWork.count_m = 0.0;
    } else {
      rtDWork.count_m++;
    }
  } else {
    /* During 'A1': '<S12>:6' */
    /* Transition: '<S12>:8' */
    rtDWork.is_c9_can_simple_block_bu11142 = IN_A_j;

    /* Entry 'A': '<S12>:3' */
    rtDWork.count_m = 0.0;
  }

  /* End of Chart: '<S2>/Chart2' */

  /* Chart: '<S2>/Data collection chart' */
  /* Gateway: Function-Call
     Subsystem/Data collection chart */
  /* During: Function-Call
     Subsystem/Data collection chart */
  if (rtDWork.is_active_c15_can_simple_block_ == 0U) {
    /* Entry: Function-Call
       Subsystem/Data collection chart */
    rtDWork.is_active_c15_can_simple_block_ = 1U;

    /* Entry Internal: Function-Call
       Subsystem/Data collection chart */
    /* Transition: '<S13>:1' */
    rtDWork.count = 0.0;
    rtDWork.is_c15_can_simple_block_bu11142 = IN_Vol_C123;

    /* Entry 'Vol_C123': '<S13>:3' */
    rtDWork.CMD32[0] = (uint8_T)0x03;
    rtDWork.CMD32[1] = (uint8_T)0x70;
    rtDWork.CMD32[2] = (uint8_T)0x00;
    rtDWork.CMD32[3] = (uint8_T)0x04;
    rtb_STATE = 0;
  } else {
    switch (rtDWork.is_c15_can_simple_block_bu11142) {
     case IN_GPIO123:
      /* During 'GPIO123': '<S13>:12' */
      /* Transition: '<S13>:15' */
      /* Exit 'GPIO123': '<S13>:12' */
      /* Event: '<S13>:26' */
      rtDWork.is_c15_can_simple_block_bu11142 = IN_GPIO45_Vref;

      /* Entry 'GPIO45_Vref': '<S13>:13' */
      rtDWork.CMD32[0] = (uint8_T)0x04;
      rtDWork.CMD32[1] = (uint8_T)0x60;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x0E;
      rtb_STATE = 4;
      break;

     case IN_GPIO45_Vref:
      /* During 'GPIO45_Vref': '<S13>:13' */
      /* Transition: '<S13>:16' */
      rtDWork.count++;

      /* Exit 'GPIO45_Vref': '<S13>:13' */
      /* Event: '<S13>:27' */
      rtDWork.is_c15_can_simple_block_bu11142 = IN_Vol_C123;

      /* Entry 'Vol_C123': '<S13>:3' */
      rtDWork.CMD32[0] = (uint8_T)0x03;
      rtDWork.CMD32[1] = (uint8_T)0x70;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x04;
      rtb_STATE = 0;
      break;

     case IN_Vol_C123:
      /* During 'Vol_C123': '<S13>:3' */
      /* Transition: '<S13>:7' */
      /* Exit 'Vol_C123': '<S13>:3' */
      /* Event: '<S13>:25' */
      rtDWork.is_c15_can_simple_block_bu11142 = IN_Vol_C456;

      /* Entry 'Vol_C456': '<S13>:6' */
      rtDWork.CMD32[0] = (uint8_T)0x03;
      rtDWork.CMD32[1] = (uint8_T)0x70;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x06;
      rtb_STATE = 1;
      break;

     case IN_Vol_C456:
      /* During 'Vol_C456': '<S13>:6' */
      /* Transition: '<S13>:8' */
      /* Exit 'Vol_C456': '<S13>:6' */
      /* Event: '<S13>:28' */
      rtDWork.is_c15_can_simple_block_bu11142 = IN_Vol_C789;

      /* Entry 'Vol_C789': '<S13>:11' */
      rtDWork.CMD32[0] = (uint8_T)0x03;
      rtDWork.CMD32[1] = (uint8_T)0x70;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x08;
      rtb_STATE = 2;
      break;

     default:
      /* During 'Vol_C789': '<S13>:11' */
      /* Transition: '<S13>:14' */
      /* Exit 'Vol_C789': '<S13>:11' */
      /* Event: '<S13>:29' */
      rtDWork.is_c15_can_simple_block_bu11142 = IN_GPIO123;

      /* Entry 'GPIO123': '<S13>:12' */
      rtDWork.CMD32[0] = (uint8_T)0x04;
      rtDWork.CMD32[1] = (uint8_T)0x60;
      rtDWork.CMD32[2] = (uint8_T)0x00;
      rtDWork.CMD32[3] = (uint8_T)0x0C;
      rtb_STATE = 3;
      break;
    }
  }

  /* End of Chart: '<S2>/Data collection chart' */

  /* S-Function (SPITask): '<S2>/S-Function Builder' */
  SPITask_Outputs_wrapper(&rtDWork.CMD32[0], &rtDWork.SFunctionBuilder_o1[0],
    &rtDWork.SFunctionBuilder_o2[0] );

  /* MATLAB Function: '<S2>/RawData to StoreData' */
  /* MATLAB Function 'Function-Call Subsystem/RawData to StoreData': '<S17>:1' */
  /* '<S17>:1:4' DataFault =  zeros(1,7); */
  /* '<S17>:1:6' switch STATE */
  switch (rtb_STATE) {
   case 0:
    /* '<S17>:1:7' case 0 % VC123 */
    /*  VC123 */
    /* '<S17>:1:8' for i=1:7 */
    for (rtb_STATE = 0; rtb_STATE < 7; rtb_STATE++) {
      /* '<S17>:1:9' CellV_1_104(i*8-7) = uint16(SPIData(i*8-7))*256+uint16(SPIData(i*8-6)); */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 8] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 8] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 7]);

      /* '<S17>:1:10' CellV_1_104(i*8-6) = uint16(SPIData(i*8-5))*256+uint16(SPIData(i*8-4)); */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 7] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 6] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 5]);

      /* '<S17>:1:11' CellV_1_104(i*8-5) = uint16(SPIData(i*8-3))*256+uint16(SPIData(i*8-2)); */
      rtDWork.CellV_1_104[((1 + rtb_STATE) << 3) - 6] = (uint16_T)
        ((rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 4] << 8) +
         rtDWork.SFunctionBuilder_o1[((1 + rtb_STATE) << 3) - 3]);

      /* '<S17>:1:12' if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
    }
    break;

   case 1:
    /* '<S17>:1:18' case 1 % VC456 */
    /*  VC456 */
    break;

   case 2:
    /* '<S17>:1:20' case 2 % VC78 */
    /*  VC78 */
    break;

   case 3:
    /* '<S17>:1:22' case 3 % GP123 */
    /*  GP123 */
    break;

   case 4:
    /* '<S17>:1:24' case 4 % GP45 */
    /*  GP45 */
    break;

   default:
    /* '<S17>:1:26' otherwise */
    /*  ERROR */
    break;
  }

  /* End of MATLAB Function: '<S2>/RawData to StoreData' */
  /*  CellV_1_104(1) = uint16(1); */
  /*  SPIDataStore = uint16(zeros(1,21)); */
  /*  DataFault =  zeros(1,7); */
  /*   */
  /*  for i=1:7 */
  /*    SPIDataStore(i*3-2) = SPIData(i*8-7)+SPIData(i*8-6)*256; */
  /*    SPIDataStore(i*3-1) = SPIData(i*8-5)+SPIData(i*8-4)*256; */
  /*    SPIDataStore(i*3   ) = SPIData(i*8-3)+SPIData(i*8-2)*256; */
  /*    if (PecChk(i*2-1) == SPIData(i*8-1)) && (PecChk(i*2) == SPIData(i*8)) */
  /*      DataFault(i) = 1; */
  /*    else */
  /*      DataFault(i) = 0; */
  /*    end */
  /*  end */
  /*  onemask8 = uint16(hex2dec('00FF')); */
  /*  onemask8_8sft = uint16(hex2dec('FF00')); */
  /*  onemask88 = uint8(hex2dec('FF')); */
  /*  onemask16 = uint16(hex2dec('FFFF')); */
  /*   */
  /*  % data_test = zeros(1,2); */
  /*  remainder = uint16(16); */
  /*   */
  /*  for i=1:len */
  /*      ii = uint16(i); */
  /*  %     data_test(1,i) = data(ii); */
  /*  %     address = 2; */
  /*      address = bitand( ... */
  /*          bitxor( ... */
  /*          uint8(bitsra(remainder,7)),data(ii) ), ... */
  /*          onemask88); */
  /*      remainder = bitxor(bitshift(remainder,8,'uint16'),pec15Table(address+1)); */
  /*  end */
  /*  pec15 = uint16(bitand(bitshift(remainder,1,'uint16'),onemask16)); */
  /*  pec0 = uint8(bitand(pec15,onemask8)); */
  /*  pec1 = uint8(bitsra(bitand(pec15,onemask8_8sft),8)); */
}

/* Model step function for TID0 */
void can_simple_block_bu11142_step0(void) /* Sample time: [0.2s, 0.0s] */
{
  {                                    /* Sample time: [0.2s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void can_simple_block_bu11142_step1(void) /* Sample time: [1.0s, 0.0s] */
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator7' */
  if (rtDWork.clockTickCounter >= 99) {
    rtDWork.clockTickCounter = 0;
  } else {
    rtDWork.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator7' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtDWork.DataTypeConversion = 0U;

  /* S-Function (dspi_564xl_transmit): '<Root>/DSPI Transmit' */
  {
    DSPI_PUSHR_32B_tag pushr;
    pushr.R = 0U;
    pushr.B.TXDATA = rtDWork.DataTypeConversion;
    pushr.R |= (uint32_t)1<<16;
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
      rtY.Out3 = flexcan_564xl_get_id(0, 7);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 7);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&rtY.Out1[0])[i] = ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      rtY.Out2 = flexcan_564xl_get_idtype(0, 7);
      rtY.Out4 = flexcan_564xl_get_ts(0, 7);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 7);
    }
  }

  /* Outport: '<Root>/Out5' */
  rtY.Out5 = rtDWork.In3[0];

  /* S-Function (DMA_init): '<Root>/S-Function Builder' */
  DMA_init_Outputs_wrapper( );
}

/* Model step wrapper function for compatibility with a static main program */
void can_simple_block_bu11142_step(int_T tid)
{
  switch (tid) {
   case 0 :
    can_simple_block_bu11142_step0();
    break;

   case 1 :
    can_simple_block_bu11142_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void can_simple_block_bu11142_initialize(void)
{
  /* Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' incorporates:
   *  Start for SubSystem: '<Root>/Subsystem2'
   */
  Subsystem2_Start();

  /* End of Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' */

  /* Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' */
  {
    uint32_t flag = 0U;
    flag |= DSPI_ISR_EOQF_RE;
    dspi_564xl_interrupt_set(1, flag);
  }

  /* Start for S-Function (can_564xl_config): '<Root>/CAN Config' */
  flexcan_564xl_init( 0, 1342177343, 81461382);
  flexcan_564xl_pin_init( 0);

  /* Start for S-Function (dspi_564xl_config): '<Root>/DSPI Config' */
  dspi_564xl_config( 1, -2130759679, 1053390631);

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

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' incorporates:
   *  Start for SubSystem: '<Root>/Function-Call Subsystem'
   */
  FunctionCallSubsystem_Start();

  /* End of Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' */

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' */
  pit_timer_init_564xl(1,5999999);

  /* S-Function Block: <Root>/S-Function Builder */

  /* ConstCode for Outport: '<Root>/Out7' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtY.Out7 = 8U;

  /* SystemInitialize for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Subsystem2'
   */
  Subsystem2_Init();

  /* End of SystemInitialize for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' */

  /* SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Function-Call Subsystem'
   */
  FunctionCallSubsystem_Init();

  /* End of SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer' */
}

/* Model terminate function */
void can_simple_block_bu11142_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
