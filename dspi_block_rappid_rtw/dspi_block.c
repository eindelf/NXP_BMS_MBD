/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: dspi_block.c
 *
 * Code generated for Simulink model 'dspi_block'.
 *
 * Model version                  : 1.100
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Dec 07 16:06:36 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dspi_block.h"
#include "dspi_block_private.h"

/* Named constants for Chart: '<S2>/Chart' */
#define dspi_block_IN_A                ((uint8_T)1U)
#define dspi_block_IN_A1               ((uint8_T)2U)
#define dspi_block_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)

/* Block signals (auto storage) */
BlockIO_dspi_block dspi_block_B;

/* Block states (auto storage) */
D_Work_dspi_block dspi_block_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_dspi_block dspi_block_Y;

/*
 * System initialize for atomic system:
 *    '<S2>/Chart'
 *    '<S3>/Chart'
 *    '<S1>/Chart'
 */
void dspi_block_Chart_Init(rtB_Chart_dspi_block *localB, rtDW_Chart_dspi_block
  *localDW)
{
  localDW->is_active_c5_dspi_block = 0U;
  localDW->is_c5_dspi_block = dspi_block_IN_NO_ACTIVE_CHILD;
  localB->count = 0.0;
  localB->A = false;
}

/*
 * System reset for atomic system:
 *    '<S2>/Chart'
 *    '<S3>/Chart'
 *    '<S1>/Chart'
 */
void dspi_block_Chart_Reset(rtB_Chart_dspi_block *localB, rtDW_Chart_dspi_block *
  localDW)
{
  localDW->is_active_c5_dspi_block = 0U;
  localDW->is_c5_dspi_block = dspi_block_IN_NO_ACTIVE_CHILD;
  localB->count = 0.0;
  localB->A = false;
}

/*
 * Output and update for atomic system:
 *    '<S2>/Chart'
 *    '<S3>/Chart'
 *    '<S1>/Chart'
 */
void dspi_block_Chart(rtB_Chart_dspi_block *localB, rtDW_Chart_dspi_block
                      *localDW)
{
  /* Gateway: Subsystem1/Chart */
  /* During: Subsystem1/Chart */
  if (localDW->is_active_c5_dspi_block == 0U) {
    /* Entry: Subsystem1/Chart */
    localDW->is_active_c5_dspi_block = 1U;

    /* Entry Internal: Subsystem1/Chart */
    /* Transition: '<S5>:1' */
    localB->count = 0.0;
    localDW->is_c5_dspi_block = dspi_block_IN_A;
    localB->A = true;
  } else if (localDW->is_c5_dspi_block == dspi_block_IN_A) {
    /* During 'A': '<S5>:3' */
    /* Transition: '<S5>:7' */
    localB->A = false;
    localDW->is_c5_dspi_block = dspi_block_IN_A1;
  } else {
    /* During 'A1': '<S5>:6' */
    /* Transition: '<S5>:8' */
    localB->count++;
    localDW->is_c5_dspi_block = dspi_block_IN_A;
    localB->A = true;
  }
}

/* System initialize for function-call system: '<Root>/Subsystem1' */
void dspi_block_Subsystem1_Init(void)
{
  /* SystemInitialize for Chart: '<S2>/Chart' */
  dspi_block_Chart_Init(&dspi_block_B.sf_Chart, &dspi_block_DWork.sf_Chart);
}

/* System reset for function-call system: '<Root>/Subsystem1' */
void dspi_block_Subsystem1_Reset(void)
{
  /* SystemReset for Chart: '<S2>/Chart' */
  dspi_block_Chart_Reset(&dspi_block_B.sf_Chart, &dspi_block_DWork.sf_Chart);
}

/* Start for function-call system: '<Root>/Subsystem1' */
void dspi_block_Subsystem1_Start(void)
{
  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 1' */

  /* Initialize Pad Configuration Register 53 as Output */
  gpo_init_pcr_out_564xl_fnc( 53 );
}

/* Output and update for function-call system: '<Root>/Subsystem1' */
void dspi_block_Subsystem1(void)
{
  /* Chart: '<S2>/Chart' */
  dspi_block_Chart(&dspi_block_B.sf_Chart, &dspi_block_DWork.sf_Chart);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 1' */

  /* Pin Data Output Signal Update PCR[53]. */
  gpo_pin_update_564xl_fnc(53, dspi_block_B.sf_Chart.A);/* GPO Pin Data Output Register Update */
}

/* System initialize for function-call system: '<Root>/Subsystem2' */
void dspi_block_Subsystem2_Init(void)
{
  /* SystemInitialize for Chart: '<S3>/Chart' */
  dspi_block_Chart_Init(&dspi_block_B.sf_Chart_c, &dspi_block_DWork.sf_Chart_c);
}

/* System reset for function-call system: '<Root>/Subsystem2' */
void dspi_block_Subsystem2_Reset(void)
{
  /* SystemReset for Chart: '<S3>/Chart' */
  dspi_block_Chart_Reset(&dspi_block_B.sf_Chart_c, &dspi_block_DWork.sf_Chart_c);
}

/* Start for function-call system: '<Root>/Subsystem2' */
void dspi_block_Subsystem2_Start(void)
{
  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 1' */

  /* Initialize Pad Configuration Register 54 as Output */
  gpo_init_pcr_out_564xl_fnc( 54 );
}

/* Output and update for function-call system: '<Root>/Subsystem2' */
void dspi_block_Subsystem2(void)
{
  /* Chart: '<S3>/Chart' */
  dspi_block_Chart(&dspi_block_B.sf_Chart_c, &dspi_block_DWork.sf_Chart_c);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 1' */

  /* Pin Data Output Signal Update PCR[54]. */
  gpo_pin_update_564xl_fnc(54, dspi_block_B.sf_Chart_c.A);/* GPO Pin Data Output Register Update */
}

/* System initialize for function-call system: '<Root>/Subsystem' */
void dspi_block_Subsystem_Init(void)
{
  /* SystemInitialize for Chart: '<S1>/Chart' */
  dspi_block_Chart_Init(&dspi_block_B.sf_Chart_h, &dspi_block_DWork.sf_Chart_h);
}

/* System reset for function-call system: '<Root>/Subsystem' */
void dspi_block_Subsystem_Reset(void)
{
  /* SystemReset for Chart: '<S1>/Chart' */
  dspi_block_Chart_Reset(&dspi_block_B.sf_Chart_h, &dspi_block_DWork.sf_Chart_h);
}

/* Start for function-call system: '<Root>/Subsystem' */
void dspi_block_Subsystem_Start(void)
{
  /* Start for S-Function (dspi_564xl_transmit): '<S1>/DSPI Transmit' */
  dspi_564xl_pin_init(36, 0, 0);
  dspi_564xl_pin_init(39, 0, 0);
  dspi_564xl_pin_init(38, 1, 0);
  dspi_564xl_pin_init(37, 0, 0);

  /* Start for S-Function (gpio_564xl_output): '<S1>/Digital Output 1' */

  /* Initialize Pad Configuration Register 55 as Output */
  gpo_init_pcr_out_564xl_fnc( 55 );
}

/* Output and update for function-call system: '<Root>/Subsystem' */
void dspi_block_Subsystem(void)
{
  /* S-Function (dspi_564xl_transmit): '<S1>/DSPI Transmit' */
  {
    DSPI_PUSHR_32B_tag pushr;
    pushr.R = 0U;
    pushr.B.TXDATA = dspi_block_Y.Out1;
    pushr.R |= (uint32_t)1<<16;
    dspi_564xl_send(0,pushr);
  }

  /* Chart: '<S1>/Chart' */
  dspi_block_Chart(&dspi_block_B.sf_Chart_h, &dspi_block_DWork.sf_Chart_h);

  /* S-Function (gpio_564xl_output): '<S1>/Digital Output 1' */

  /* Pin Data Output Signal Update PCR[55]. */
  gpo_pin_update_564xl_fnc(55, dspi_block_B.sf_Chart_h.A);/* GPO Pin Data Output Register Update */
}

/* Model step function */
void dspi_block_step(void)
{
  int32_T rtb_PulseGenerator1;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator1 = (dspi_block_DWork.clockTickCounter < 1) &&
    (dspi_block_DWork.clockTickCounter >= 0) ? 169 : 0;
  if (dspi_block_DWork.clockTickCounter >= 1) {
    dspi_block_DWork.clockTickCounter = 0;
  } else {
    dspi_block_DWork.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  dspi_block_B.DataTypeConversion = (uint16_T)(int32_T)fmod(rtb_PulseGenerator1,
    65536.0);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_PulseGenerator1 = ((dspi_block_DWork.clockTickCounter_l < 3) &&
    (dspi_block_DWork.clockTickCounter_l >= 0));
  if (dspi_block_DWork.clockTickCounter_l >= 4) {
    dspi_block_DWork.clockTickCounter_l = 0;
  } else {
    dspi_block_DWork.clockTickCounter_l++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  dspi_block_B.DataTypeConversion1 = (rtb_PulseGenerator1 != 0);

  /* S-Function (dspi_564xl_transmit): '<Root>/DSPI Transmit' */
  {
    DSPI_PUSHR_32B_tag pushr;
    pushr.R = 0U;
    pushr.B.EOQ = (uint32_t)dspi_block_B.DataTypeConversion1;
    pushr.B.TXDATA = dspi_block_B.DataTypeConversion;
    pushr.R |= (uint32_t)1<<16;
    dspi_564xl_send(1,pushr);
  }

  /* S-Function (dspi_564xl_receive): '<Root>/DSPI Receive' */

  /* DSPI Data read DSPI: 2 Mode: slave  */
  dspi_block_Y.Out2 = dspi_564xl_read_slave( 1);
}

/* Model initialize function */
void dspi_block_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &dspi_block_B), 0,
                sizeof(BlockIO_dspi_block));

  /* states (dwork) */
  (void) memset((void *)&dspi_block_DWork, 0,
                sizeof(D_Work_dspi_block));

  /* external outputs */
  (void) memset((void *)&dspi_block_Y, 0,
                sizeof(ExternalOutputs_dspi_block));

  /* Start for S-Function (dspi_564xl_config): '<Root>/DSPI Config' */
  dspi_564xl_config( 1, -2130759679, 2013951783);

  /* Start for S-Function (dspi_564xl_config): '<Root>/DSPI Config1' */
  dspi_564xl_config( 0, 16723969, 2013951783);

  /* Start for S-Function (dspi_564xl_transmit): '<Root>/DSPI Transmit' */
  dspi_564xl_pin_init(5, 1, 1);
  dspi_564xl_pin_init(8, 0, 1);
  dspi_564xl_pin_init(7, 1, 1);
  dspi_564xl_pin_init(6, 1, 1);

  /* Start for S-Function (dspi_564xl_receive_trg): '<Root>/DSPI Receive Trigger' incorporates:
   *  Start for SubSystem: '<Root>/Subsystem'
   */
  dspi_block_Subsystem_Start();

  /* End of Start for S-Function (dspi_564xl_receive_trg): '<Root>/DSPI Receive Trigger' */

  /* Start for S-Function (dspi_564xl_receive_trg): '<Root>/DSPI Receive Trigger' */
  dspi_564xl_interrupt_set(0, DSPI_ISR_RFDF_RE);

  /* Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR2' incorporates:
   *  Start for SubSystem: '<Root>/Subsystem1'
   */
  dspi_block_Subsystem1_Start();

  /* End of Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR2' */

  /* Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR2' */
  {
    uint32_t flag = 0U;
    flag |= DSPI_ISR_TCF_RE;
    dspi_564xl_interrupt_set(1, flag);
  }

  /* Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' incorporates:
   *  Start for SubSystem: '<Root>/Subsystem2'
   */
  dspi_block_Subsystem2_Start();

  /* End of Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' */

  /* Start for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' */
  {
    uint32_t flag = 0U;
    flag |= DSPI_ISR_EOQF_RE;
    dspi_564xl_interrupt_set(1, flag);
  }

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  dspi_block_DWork.clockTickCounter = 0;

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  dspi_block_DWork.clockTickCounter_l = 0;

  /* SystemInitialize for S-Function (dspi_564xl_receive_trg): '<Root>/DSPI Receive Trigger' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Subsystem'
   */
  dspi_block_Subsystem_Init();

  /* End of SystemInitialize for S-Function (dspi_564xl_receive_trg): '<Root>/DSPI Receive Trigger' */

  /* SystemInitialize for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR2' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Subsystem1'
   */
  dspi_block_Subsystem1_Init();

  /* End of SystemInitialize for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR2' */

  /* SystemInitialize for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' incorporates:
   *  SystemInitialize for SubSystem: '<Root>/Subsystem2'
   */
  dspi_block_Subsystem2_Init();

  /* End of SystemInitialize for S-Function (dspi_564xl_isr): '<Root>/DSPI ISR3' */
}

/* Model terminate function */
void dspi_block_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
