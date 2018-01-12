/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: DigitalIO_block_demo.c
 *
 * Code generated for Simulink model 'DigitalIO_block_demo'.
 *
 * Model version                  : 1.173
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Jul 27 15:22:07 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DigitalIO_block_demo.h"
#include "DigitalIO_block_demo_private.h"

/* Named constants for Chart: '<S3>/Chart' */
#define DigitalIO_bl_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define DigitalIO_block_demo_IN_A      ((uint8_T)1U)
#define DigitalIO_block_demo_IN_A1     ((uint8_T)2U)

/* Named constants for Chart: '<S4>/Chart' */
#define DigitalIO__IN_NO_ACTIVE_CHILD_m ((uint8_T)0U)
#define DigitalIO_block_demo_IN_A1_k   ((uint8_T)2U)
#define DigitalIO_block_demo_IN_A_i    ((uint8_T)1U)

/* Named constants for Chart: '<S2>/Chart' */
#define DigitalIO__IN_NO_ACTIVE_CHILD_f ((uint8_T)0U)
#define DigitalIO_block_demo_IN_A1_o   ((uint8_T)2U)
#define DigitalIO_block_demo_IN_A_o    ((uint8_T)1U)

/* Named constants for Chart: '<Root>/Chart' */
#define DigitalIO__IN_NO_ACTIVE_CHILD_k ((uint8_T)0U)
#define DigitalIO_block_demo_IN_A1_n   ((uint8_T)2U)
#define DigitalIO_block_demo_IN_A_k    ((uint8_T)1U)

/* Exported block signals */
real_T In;                             /* '<Root>/In1' */
real_T Out;                            /* '<Root>/Gain' */
real_T count;                          /* '<Root>/Chart' */
real32_T countX;                       /* '<S2>/Chart' */
boolean_T StateA;                      /* '<S2>/Chart' */

/* Block signals (auto storage) */
BlockIO_DigitalIO_block_demo DigitalIO_block_demo_B;

/* Block states (auto storage) */
D_Work_DigitalIO_block_demo DigitalIO_block_demo_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_DigitalIO_block_ DigitalIO_block_demo_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_DigitalIO_block DigitalIO_block_demo_Y;

/* System initialize for function-call system: '<Root>/Function-Call Subsystem1' */
void Dig_FunctionCallSubsystem1_Init(void)
{
  /* SystemInitialize for Chart: '<S3>/Chart' */
  DigitalIO_block_demo_DWork.is_active_c3_DigitalIO_block_de = 0U;
  DigitalIO_block_demo_DWork.is_c3_DigitalIO_block_demo =
    DigitalIO_bl_IN_NO_ACTIVE_CHILD;
  DigitalIO_block_demo_B.count_k = 0.0;
}

/* System reset for function-call system: '<Root>/Function-Call Subsystem1' */
void Di_FunctionCallSubsystem1_Reset(void)
{
  /* SystemReset for Chart: '<S3>/Chart' */
  DigitalIO_block_demo_DWork.is_active_c3_DigitalIO_block_de = 0U;
  DigitalIO_block_demo_DWork.is_c3_DigitalIO_block_demo =
    DigitalIO_bl_IN_NO_ACTIVE_CHILD;
  DigitalIO_block_demo_B.count_k = 0.0;
}

/* Start for function-call system: '<Root>/Function-Call Subsystem1' */
void Di_FunctionCallSubsystem1_Start(void)
{
  /* Start for S-Function (gpio_564xl_input): '<S3>/Digital Input1' */

  /* Initialize Pad Configuration Register 49 as Input */
  gpi_init_pcr_in_564xl_fnc( 49 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 1' */

  /* Initialize Pad Configuration Register 53 as Output */
  gpo_init_pcr_out_564xl_fnc( 53 );
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem1' */
void DigitalI_FunctionCallSubsystem1(void)
{
  boolean_T rtb_A;

  /* user code (Output function Body) */
  {
    /* Start of Profile Code */
    vuint32_t tmp1;
    vuint32_t tmp2;
    tmp1 = gt_pf();

    /* Start Profiling This Function.*/

    /* Outport: '<Root>/Out4' incorporates:
     *  Gain: '<S3>/Gain'
     *  Inport: '<Root>/In3'
     */
    DigitalIO_block_demo_Y.Out4 = 2.0 * DigitalIO_block_demo_U.In3;

    /* Chart: '<S3>/Chart' */
    /* Gateway: Function-Call
       Subsystem1/Chart */
    /* During: Function-Call
       Subsystem1/Chart */
    if (DigitalIO_block_demo_DWork.is_active_c3_DigitalIO_block_de == 0U) {
      /* Entry: Function-Call
         Subsystem1/Chart */
      DigitalIO_block_demo_DWork.is_active_c3_DigitalIO_block_de = 1U;

      /* Entry Internal: Function-Call
         Subsystem1/Chart */
      /* Transition: '<S6>:1' */
      DigitalIO_block_demo_B.count_k = 0.0;
      DigitalIO_block_demo_DWork.is_c3_DigitalIO_block_demo =
        DigitalIO_block_demo_IN_A;
      rtb_A = true;
    } else if (DigitalIO_block_demo_DWork.is_c3_DigitalIO_block_demo ==
               DigitalIO_block_demo_IN_A) {
      /* During 'A': '<S6>:3' */
      /* Transition: '<S6>:7' */
      rtb_A = false;
      DigitalIO_block_demo_DWork.is_c3_DigitalIO_block_demo =
        DigitalIO_block_demo_IN_A1;
    } else {
      /* During 'A1': '<S6>:6' */
      /* Transition: '<S6>:8' */
      DigitalIO_block_demo_B.count_k++;
      DigitalIO_block_demo_DWork.is_c3_DigitalIO_block_demo =
        DigitalIO_block_demo_IN_A;
      rtb_A = true;
    }

    /* End of Chart: '<S3>/Chart' */

    /* S-Function (gpio_564xl_input): '<S3>/Digital Input1' */
    DigitalIO_block_demo_B.DigitalInput1_h = gpi_pin_read_564xl_fnc(49);/* GPI Pin Data Input Registers  */

    /* Logic: '<S3>/Logical Operator' */
    DigitalIO_block_demo_B.LogicalOperator_n = (rtb_A &&
      DigitalIO_block_demo_B.DigitalInput1_h);

    /* S-Function (gpio_564xl_output): '<S3>/Digital Output 1' */

    /* Pin Data Output Signal Update PCR[53]. */
    gpo_pin_update_564xl_fnc(53, DigitalIO_block_demo_B.LogicalOperator_n);/* GPO Pin Data Output Register Update */

    /* user code (Output function Trailer) */

    /* Profile Code : Compute execution cycles of function. */
    tmp2 = gt_pf();
    if (tmp1 < tmp2 ) {
      profile_buffer[2] = tmp2-tmp1;
    } else {
      profile_buffer[2] = 0xFFFFFFFF -(tmp1-tmp2);
    }

    /* End of Profile Code */
  }
}

/* System initialize for function-call system: '<Root>/Function-Call Subsystem2' */
void Dig_FunctionCallSubsystem2_Init(void)
{
  /* SystemInitialize for Chart: '<S4>/Chart' */
  DigitalIO_block_demo_DWork.is_active_c4_DigitalIO_block_de = 0U;
  DigitalIO_block_demo_DWork.is_c4_DigitalIO_block_demo =
    DigitalIO__IN_NO_ACTIVE_CHILD_m;
  DigitalIO_block_demo_B.count_d = 0.0;
}

/* System reset for function-call system: '<Root>/Function-Call Subsystem2' */
void Di_FunctionCallSubsystem2_Reset(void)
{
  /* SystemReset for Chart: '<S4>/Chart' */
  DigitalIO_block_demo_DWork.is_active_c4_DigitalIO_block_de = 0U;
  DigitalIO_block_demo_DWork.is_c4_DigitalIO_block_demo =
    DigitalIO__IN_NO_ACTIVE_CHILD_m;
  DigitalIO_block_demo_B.count_d = 0.0;
}

/* Start for function-call system: '<Root>/Function-Call Subsystem2' */
void Di_FunctionCallSubsystem2_Start(void)
{
  /* Start for S-Function (gpio_564xl_input): '<S4>/Digital Input1' */

  /* Initialize Pad Configuration Register 50 as Input */
  gpi_init_pcr_in_564xl_fnc( 50 );

  /* Start for S-Function (gpio_564xl_output): '<S4>/Digital Output 1' */

  /* Initialize Pad Configuration Register 54 as Output */
  gpo_init_pcr_out_564xl_fnc( 54 );
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem2' */
void DigitalI_FunctionCallSubsystem2(void)
{
  boolean_T rtb_A;

  /* user code (Output function Body) */
  {
    /* Start of Profile Code */
    vuint32_t tmp1;
    vuint32_t tmp2;
    tmp1 = gt_pf();

    /* Start Profiling This Function.*/

    /* Outport: '<Root>/Out5' incorporates:
     *  Gain: '<S4>/Gain'
     *  Inport: '<Root>/In4'
     */
    DigitalIO_block_demo_Y.Out5 = 2.0 * DigitalIO_block_demo_U.In4;

    /* Chart: '<S4>/Chart' */
    /* Gateway: Function-Call
       Subsystem2/Chart */
    /* During: Function-Call
       Subsystem2/Chart */
    if (DigitalIO_block_demo_DWork.is_active_c4_DigitalIO_block_de == 0U) {
      /* Entry: Function-Call
         Subsystem2/Chart */
      DigitalIO_block_demo_DWork.is_active_c4_DigitalIO_block_de = 1U;

      /* Entry Internal: Function-Call
         Subsystem2/Chart */
      /* Transition: '<S7>:1' */
      DigitalIO_block_demo_DWork.is_c4_DigitalIO_block_demo =
        DigitalIO_block_demo_IN_A_i;
      rtb_A = true;
    } else if (DigitalIO_block_demo_DWork.is_c4_DigitalIO_block_demo ==
               DigitalIO_block_demo_IN_A_i) {
      /* During 'A': '<S7>:3' */
      /* Transition: '<S7>:7' */
      rtb_A = false;
      DigitalIO_block_demo_DWork.is_c4_DigitalIO_block_demo =
        DigitalIO_block_demo_IN_A1_k;
    } else {
      /* During 'A1': '<S7>:6' */
      /* Transition: '<S7>:8' */
      DigitalIO_block_demo_B.count_d += 0.01;
      DigitalIO_block_demo_DWork.is_c4_DigitalIO_block_demo =
        DigitalIO_block_demo_IN_A_i;
      rtb_A = true;
    }

    /* End of Chart: '<S4>/Chart' */

    /* S-Function (gpio_564xl_input): '<S4>/Digital Input1' */
    DigitalIO_block_demo_B.DigitalInput1_n = gpi_pin_read_564xl_fnc(50);/* GPI Pin Data Input Registers  */

    /* Logic: '<S4>/Logical Operator' */
    DigitalIO_block_demo_B.LogicalOperator_df = (rtb_A &&
      DigitalIO_block_demo_B.DigitalInput1_n);

    /* S-Function (gpio_564xl_output): '<S4>/Digital Output 1' */

    /* Pin Data Output Signal Update PCR[54]. */
    gpo_pin_update_564xl_fnc(54, DigitalIO_block_demo_B.LogicalOperator_df);/* GPO Pin Data Output Register Update */

    /* user code (Output function Trailer) */

    /* Profile Code : Compute execution cycles of function. */
    tmp2 = gt_pf();
    if (tmp1 < tmp2 ) {
      profile_buffer[3] = tmp2-tmp1;
    } else {
      profile_buffer[3] = 0xFFFFFFFF -(tmp1-tmp2);
    }

    /* End of Profile Code */
  }
}

/* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
void Digi_FunctionCallSubsystem_Init(void)
{
  /* SystemInitialize for Chart: '<S2>/Chart' */
  DigitalIO_block_demo_DWork.is_active_c2_DigitalIO_block_de = 0U;
  DigitalIO_block_demo_DWork.is_c2_DigitalIO_block_demo =
    DigitalIO__IN_NO_ACTIVE_CHILD_f;
  countX = 0.0F;
  StateA = false;
}

/* System reset for function-call system: '<Root>/Function-Call Subsystem' */
void Dig_FunctionCallSubsystem_Reset(void)
{
  /* SystemReset for Chart: '<S2>/Chart' */
  DigitalIO_block_demo_DWork.is_active_c2_DigitalIO_block_de = 0U;
  DigitalIO_block_demo_DWork.is_c2_DigitalIO_block_demo =
    DigitalIO__IN_NO_ACTIVE_CHILD_f;
  countX = 0.0F;
  StateA = false;
}

/* Start for function-call system: '<Root>/Function-Call Subsystem' */
void Dig_FunctionCallSubsystem_Start(void)
{
  /* Start for S-Function (gpio_564xl_input): '<S2>/Digital Input1' */

  /* Initialize Pad Configuration Register 48 as Input */
  gpi_init_pcr_in_564xl_fnc( 48 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 1' */

  /* Initialize Pad Configuration Register 52 as Output */
  gpo_init_pcr_out_564xl_fnc( 52 );
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
void DigitalIO_FunctionCallSubsystem(void)
{
  /* user code (Output function Body) */
  {
    /* Start of Profile Code */
    vuint32_t tmp1;
    vuint32_t tmp2;
    tmp1 = gt_pf();

    /* Start Profiling This Function.*/

    /* Outport: '<Root>/Out3' incorporates:
     *  Gain: '<S2>/Gain'
     *  Inport: '<Root>/In2'
     */
    DigitalIO_block_demo_Y.Out3 = 2.0 * DigitalIO_block_demo_U.In2;

    /* Chart: '<S2>/Chart' */
    /* Gateway: Function-Call
       Subsystem/Chart */
    /* During: Function-Call
       Subsystem/Chart */
    if (DigitalIO_block_demo_DWork.is_active_c2_DigitalIO_block_de == 0U) {
      /* Entry: Function-Call
         Subsystem/Chart */
      DigitalIO_block_demo_DWork.is_active_c2_DigitalIO_block_de = 1U;

      /* Entry Internal: Function-Call
         Subsystem/Chart */
      /* Transition: '<S5>:1' */
      DigitalIO_block_demo_DWork.is_c2_DigitalIO_block_demo =
        DigitalIO_block_demo_IN_A_o;
      StateA = true;
    } else if (DigitalIO_block_demo_DWork.is_c2_DigitalIO_block_demo ==
               DigitalIO_block_demo_IN_A_o) {
      /* During 'A': '<S5>:3' */
      /* Transition: '<S5>:7' */
      StateA = false;
      DigitalIO_block_demo_DWork.is_c2_DigitalIO_block_demo =
        DigitalIO_block_demo_IN_A1_o;
    } else {
      /* During 'A1': '<S5>:6' */
      /* Transition: '<S5>:8' */
      countX = (real32_T)(countX + 0.01);
      DigitalIO_block_demo_DWork.is_c2_DigitalIO_block_demo =
        DigitalIO_block_demo_IN_A_o;
      StateA = true;
    }

    /* End of Chart: '<S2>/Chart' */

    /* S-Function (gpio_564xl_input): '<S2>/Digital Input1' */
    DigitalIO_block_demo_B.DigitalInput1 = gpi_pin_read_564xl_fnc(48);/* GPI Pin Data Input Registers  */

    /* Logic: '<S2>/Logical Operator' */
    DigitalIO_block_demo_B.LogicalOperator_d = (StateA &&
      DigitalIO_block_demo_B.DigitalInput1);

    /* S-Function (gpio_564xl_output): '<S2>/Digital Output 1' */

    /* Pin Data Output Signal Update PCR[52]. */
    gpo_pin_update_564xl_fnc(52, DigitalIO_block_demo_B.LogicalOperator_d);/* GPO Pin Data Output Register Update */

    /* user code (Output function Trailer) */

    /* Profile Code : Compute execution cycles of function. */
    tmp2 = gt_pf();
    if (tmp1 < tmp2 ) {
      profile_buffer[0] = tmp2-tmp1;
    } else {
      profile_buffer[0] = 0xFFFFFFFF -(tmp1-tmp2);
    }

    /* End of Profile Code */
  }
}

/* Model step function */
void DigitalIO_block_demo_step(void)
{
  boolean_T rtb_A;

  /* user code (Output function Body) */
  {
    /* Start of Profile Code */
    vuint32_t tmp1;
    vuint32_t tmp2;
    tmp1 = gt_pf();

    /* Start Profiling This Function.*/

    /* Gain: '<Root>/Gain' incorporates:
     *  Inport: '<Root>/In1'
     */
    Out = 2.0 * In;

    /* Chart: '<Root>/Chart' */
    /* Gateway: Chart */
    /* During: Chart */
    if (DigitalIO_block_demo_DWork.is_active_c1_DigitalIO_block_de == 0U) {
      /* Entry: Chart */
      DigitalIO_block_demo_DWork.is_active_c1_DigitalIO_block_de = 1U;

      /* Entry Internal: Chart */
      DigitalIO_block_demo_DWork.is_active_A = 1U;

      /* Entry Internal 'A': '<S1>:11' */
      /* Transition: '<S1>:1' */
      DigitalIO_block_demo_DWork.is_A = DigitalIO_block_demo_IN_A_k;
      rtb_A = true;
      DigitalIO_block_demo_DWork.is_active_A1 = 1U;
    } else {
      /* During 'A': '<S1>:11' */
      if (DigitalIO_block_demo_DWork.is_A == DigitalIO_block_demo_IN_A_k) {
        /* During 'A': '<S1>:3' */
        /* Transition: '<S1>:7' */
        rtb_A = false;
        DigitalIO_block_demo_DWork.is_A = DigitalIO_block_demo_IN_A1_n;
      } else {
        /* During 'A1': '<S1>:6' */
        /* Transition: '<S1>:8' */
        count += 0.01;
        DigitalIO_block_demo_DWork.is_A = DigitalIO_block_demo_IN_A_k;
        rtb_A = true;
      }

      /* During 'A1': '<S1>:12' */
      /* Transition: '<S1>:13' */
    }

    /* End of Chart: '<Root>/Chart' */

    /* Outport: '<Root>/Out7' */
    DigitalIO_block_demo_Y.Out7 = rtb_A;

    /* S-Function (gpio_564xl_input): '<Root>/Digital Input' */
    DigitalIO_block_demo_B.DigitalInput = gpi_pin_read_564xl_fnc(51);/* GPI Pin Data Input Registers  */

    /* Logic: '<Root>/Logical Operator' */
    DigitalIO_block_demo_B.LogicalOperator = (rtb_A &&
      DigitalIO_block_demo_B.DigitalInput);

    /* S-Function (gpio_564xl_output): '<Root>/Digital Output 1' */

    /* Pin Data Output Signal Update PCR[55]. */
    gpo_pin_update_564xl_fnc(55, DigitalIO_block_demo_B.LogicalOperator);/* GPO Pin Data Output Register Update */

    /* user code (Output function Trailer) */

    /* Profile Code : Compute execution cycles of function. */
    tmp2 = gt_pf();
    if (tmp1 < tmp2 ) {
      profile_buffer[1] = tmp2-tmp1;
    } else {
      profile_buffer[1] = 0xFFFFFFFF -(tmp1-tmp2);
    }

    /* End of Profile Code */
  }
}

/* Model initialize function */
void DigitalIO_block_demo_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &DigitalIO_block_demo_B), 0,
                sizeof(BlockIO_DigitalIO_block_demo));

  {
    DigitalIO_block_demo_B.count_d = 0.0;
    DigitalIO_block_demo_B.count_k = 0.0;
  }

  /* exported global signals */
  Out = 0.0;
  count = 0.0;
  countX = 0.0F;
  StateA = false;

  /* states (dwork) */
  (void) memset((void *)&DigitalIO_block_demo_DWork, 0,
                sizeof(D_Work_DigitalIO_block_demo));

  /* external inputs */
  In = 0.0;
  DigitalIO_block_demo_U.In2 = 0.0;
  DigitalIO_block_demo_U.In3 = 0.0;
  DigitalIO_block_demo_U.In4 = 0.0;

  /* external outputs */
  (void) memset((void *)&DigitalIO_block_demo_Y, 0,
                sizeof(ExternalOutputs_DigitalIO_block));
  DigitalIO_block_demo_Y.Out3 = 0.0;
  DigitalIO_block_demo_Y.Out4 = 0.0;
  DigitalIO_block_demo_Y.Out5 = 0.0;

  /* Start for S-Function (gpio_564xl_input): '<Root>/Digital Input' */

  /* Initialize Pad Configuration Register 51 as Input */
  gpi_init_pcr_in_564xl_fnc( 51 );

  /* Start for S-Function (gpio_564xl_output): '<Root>/Digital Output 1' */

  /* Initialize Pad Configuration Register 55 as Output */
  gpo_init_pcr_out_564xl_fnc( 55 );

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer3' incorporates:
   *  Start for SubSystem: '<Root>/Function-Call Subsystem'
   */
  Dig_FunctionCallSubsystem_Start();

  /* End of Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer3' */

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer3' */
  pit_timer_init_564xl(1,23999999);

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer1' incorporates:
   *  Start for SubSystem: '<Root>/Function-Call Subsystem1'
   */
  Di_FunctionCallSubsystem1_Start();

  /* End of Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer1' */

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer1' */
  pit_timer_init_564xl(2,11999999);

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer2' incorporates:
   *  Start for SubSystem: '<Root>/Function-Call Subsystem2'
   */
  Di_FunctionCallSubsystem2_Start();

  /* End of Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer2' */

  /* Start for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer2' */
  pit_timer_init_564xl(3,29999999);

  /* SystemInitialize for Chart: '<Root>/Chart' */
  DigitalIO_block_demo_DWork.is_active_A = 0U;
  DigitalIO_block_demo_DWork.is_A = DigitalIO__IN_NO_ACTIVE_CHILD_k;
  DigitalIO_block_demo_DWork.is_active_A1 = 0U;
  DigitalIO_block_demo_DWork.is_active_c1_DigitalIO_block_de = 0U;
  count = 0.0;

  /* SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer3' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Function-Call Subsystem'
   */
  Digi_FunctionCallSubsystem_Init();

  /* End of SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer3' */

  /* SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer1' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Function-Call Subsystem1'
   */
  Dig_FunctionCallSubsystem1_Init();

  /* End of SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer1' */

  /* SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer2' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Function-Call Subsystem2'
   */
  Dig_FunctionCallSubsystem2_Init();

  /* End of SystemInitialize for S-Function (timer_564xl_pit_block): '<Root>/Periodic Interrupt Timer2' */
}

/* Model terminate function */
void DigitalIO_block_demo_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
