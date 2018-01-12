/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: linflex_init.c
 *
 * Code generated for Simulink model 'dspi_block_bu1130'.
 *
 * Model version                  : 1.96
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Nov 30 16:38:03 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/********************  Dependent Include files here **********************/
#include "linflex_init.h"

/**********************  Initialization Function(s) *************************/
void linflex_init_fnc (void)
{
  LINFLEX_0.LINCR1.B.INIT = 1;

  /*Initialization Request: Set */
  LINFLEX_0.LINCR1.B.SLEEP = 0;

  /*Sleep Request: Clear */
  LINFLEX_0.UARTCR.B.UART= 1;

  /* UART Mode: Enabled */

  /*----------------------------------------------------------- */

  /*        LIN control register 2   (LINFLEX_X_LINCR2)        */

  /*----------------------------------------------------------- */
  LINFLEX_0.LINCR2.R = 0x0000;

  /* Idle on Bit Error: Disabled*/

  /* Idle on Identifier Parity Error: Disabled*/

  /*----------------------------------------------------------- */

  /*        LIN integer baudrate register  (LINFLEX_X_LINIBRR)   */

  /*----------------------------------------------------------- */
  LINFLEX_0.LINIBRR.R = 0x0082;

  /* Integer Baud Rate Factor: 130*/

  /*----------------------------------------------------------- */

  /*        LIN fractional baudrate register  (LINFLEX_X_LINFBRR)*/

  /*----------------------------------------------------------- */
  LINFLEX_0.LINFBRR.R = 0x0003;

  /* Fractional Baud Rate Factor: 3*/

  /*----------------------------------------------------------- */

  /*        Identifier filter mode register  (LINFLEX_X_IFMR)         */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFMR.R = 0x0000;

  /* Filters 0:identifier list mode    */

  /* Filters 1:identifier list mode    */

  /* Filters 2:identifier list mode    */

  /* Filters 3:identifier list mode    */

  /* Filters 4:identifier list mode    */

  /* Filters 5:identifier list mode    */

  /* Filters 6:identifier list mode    */

  /* Filters 7:identifier list mode    */

  /*----------------------------------------------------------- */

  /*        Identifier filter enable register  (LINFLEX_X_IFER)         */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFER.R = 0x0000;

  /* Activate Filter 0:Disabled    */

  /* Activate Filter 1:Disabled    */

  /* Activate Filter 2:Disabled    */

  /* Activate Filter 3:Disabled    */

  /* Activate Filter 4:Disabled    */

  /* Activate Filter 5:Disabled    */

  /* Activate Filter 6:Disabled    */

  /* Activate Filter 7:Disabled    */

  /*----------------------------------------------------------- */

  /*    Identifier filter control register  (LINFLEX_0_IFCR0)    */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFCR0.R = 0x0000;

  /* Data Field Length (Bytes): 1    */

  /* Direction: Receive    */

  /* Checksum: Enhanced    */

  /* Identifier: 0b0    */

  /*----------------------------------------------------------- */

  /*    Identifier filter control register  (LINFLEX_0_IFCR1)    */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFCR1.R = 0x0000;

  /* Data Field Length (Bytes): 1    */

  /* Direction: Receive    */

  /* Checksum: Enhanced    */

  /* Identifier: 0b0    */

  /*----------------------------------------------------------- */

  /*    Identifier filter control register  (LINFLEX_0_IFCR2)    */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFCR2.R = 0x0000;

  /* Data Field Length (Bytes): 1    */

  /* Direction: Receive    */

  /* Checksum: Enhanced    */

  /* Identifier: 0b0    */

  /*----------------------------------------------------------- */

  /*    Identifier filter control register  (LINFLEX_0_IFCR3)    */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFCR3.R = 0x0000;

  /* Data Field Length (Bytes): 1    */

  /* Direction: Receive    */

  /* Checksum: Enhanced    */

  /* Identifier: 0b0    */

  /*----------------------------------------------------------- */

  /*    Identifier filter control register  (LINFLEX_0_IFCR4)    */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFCR4.R = 0x0000;

  /* Data Field Length (Bytes): 1    */

  /* Direction: Receive    */

  /* Checksum: Enhanced    */

  /* Identifier: 0b0    */

  /*----------------------------------------------------------- */

  /*    Identifier filter control register  (LINFLEX_0_IFCR5)    */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFCR5.R = 0x0000;

  /* Data Field Length (Bytes): 1    */

  /* Direction: Receive    */

  /* Checksum: Enhanced    */

  /* Identifier: 0b0    */

  /*----------------------------------------------------------- */

  /*    Identifier filter control register  (LINFLEX_0_IFCR6)    */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFCR6.R = 0x0000;

  /* Data Field Length (Bytes): 1    */

  /* Direction: Receive    */

  /* Checksum: Enhanced    */

  /* Identifier: 0b0    */

  /*----------------------------------------------------------- */

  /*    Identifier filter control register  (LINFLEX_0_IFCR7)    */

  /*----------------------------------------------------------- */
  LINFLEX_0.IFCR7.R = 0x0000;

  /* Data Field Length (Bytes): 1    */

  /* Direction: Receive    */

  /* Checksum: Enhanced    */

  /* Identifier: 0b0    */

  /*----------------------------------------------------------- */

  /*        UART mode control register  (LINFLEX_X_UARTCR)        */

  /*----------------------------------------------------------- */
  LINFLEX_0.UARTCR.R = 0x0033;

  /* UART Mode: Enable*/

  /* Parity transmit/check: Disable*/

  /* Sent parity: Even*/

  /* Word Length in UART mode: 8 bit data (9 bit if PCE is set)*/

  /* Transmitter Data Field Length (Bytes): 1*/

  /* Receiver Data Field Length (Bytes): 1*/

  /* Transmitter : Enable*/

  /* Receiver : Enable*/

  /*----------------------------------------------------------- */

  /*        LIN timeout control status register  (LINFLEX_X_LINTCSR)        */

  /*----------------------------------------------------------- */
  LINFLEX_0.LINTCSR.R = 0x0000;

  /* LIN timeout mode: Disabled*/

  /* Idle on Timeout: Disabled*/

  /* Timeout Counter: Disabled*/

  /*----------------------------------------------------------- */

  /*        LIN output compare register  (LINFLEX_X_LINOCR)        */

  /*----------------------------------------------------------- */
  LINFLEX_0.LINOCR.R = 0xFFFF;

  /* Output compare Value 1: 255*/

  /* Output compare Value 2: 255*/

  /*----------------------------------------------------------- */

  /*        LIN timeout control register  (LINFLEX_X_LINTOCR)        */

  /*----------------------------------------------------------- */
  LINFLEX_0.LINTOCR.R = 0x0E2C;

  /* Header Timeout (Bit Time): 44*/

  /* Response Timeout Timeout: 14*/

  /*----------------------------------------------------------- */

  /*        LIN interrupt enable register  (LINFLEX_X_LINIER)        */

  /*----------------------------------------------------------- */
  LINFLEX_0.LINIER.R = 0x0000;

  /* Header Received Interrupt: Disabled    */

  /* Data Transmitted Interrupt: Disabled    */

  /* Data Reception Complete Interrupt: Disabled    */

  /* Data Buffer Empty Interrupt: Disabled    */

  /* Data Buffer Full Interrupt: Disabled    */

  /* Wakeup Interrupt: Disabled    */

  /* LIN State Interrupt: Disabled    */

  /* Buffer Overrun Error Interrupt: Disabled    */

  /* Frame Error Interrupt:Disabled    */

  /* Header Error Interrupt:Disabled    */

  /* Checksum Error Interrupt:Disabled    */

  /* Bit Error Interrupt:Disabled    */

  /* Output Compare Interrupt:Disabled    */

  /* Stuck at Zero Interrupt:Disabled    */

  /*----------------------------------------------------------- */

  /*        LIN control register 1   (LINFLEX_X_LINCR1)        */

  /*----------------------------------------------------------- */
  LINFLEX_0.LINCR1.R = 0x0081;

  /* Initialization Request: Set  */

  /* Master Mode Enable: Slave*/

  /* Receiver Buffer: Not Locked*/

  /* Loopback Mode: Disabled*/

  /* Self Test Mode: Disabled*/

  /* LIN Master Break Length: 10 bits*/

  /* Slave Mode Break Detection Threshold: 11 bits*/

  /* Bypass Filter: Enabled*/

  /* Automatic Wake-Up Mode: Disabled*/

  /* Checksum field: Enabled*/

  /* Checksum Calculation: Disabled*/

  /* LIN Slave Automatic Resynchronization: Disabled*/
  LINFLEX_0.LINCR1.B.INIT = 0;

  /*Initialization Request: Clear */
}

/*

 *######################################################################

 *                           End of File

 *######################################################################

 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
