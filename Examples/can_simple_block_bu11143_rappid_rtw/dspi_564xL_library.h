/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    dspi_564xL_library.h
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   DSPI module support.
 *    @details Declarations for dspi_564xL_library.c file.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:		2-Aug-2011
 *   Author:                         b13508
 *
 */

#ifndef _DSPI_564xL_LIBRARY_H
#define _DSPI_564xL_LIBRARY_H
#ifdef __cplusplus

extern "C"{

#endif

  /******************************************************************************
   *                  Includes
   ******************************************************************************/
#include "target.h"

  /******************************************************************************
   *                   Defines and Macros
   ******************************************************************************/
#define DSPI0                          0
#define DSPI1                          1
#define DSPI2                          2
#define DSPI_ISR_TCF_RE                0x80000000
#define DSPI_ISR_EOQF_RE               0x10000000
#define DSPI_ISR_TFUF_RE               0x08000000
#define DSPI_ISR_TFFF_RE               0x02000000
#define DSPI_ISR_TFFF_DIRS             0x01000000
#define DSPI_ISR_SPEF_RE               0x00200000
#define DSPI_ISR_RFOF_RE               0x00080000
#define DSPI_ISR_RFDF_RE               0x00020000
#define DSPI_ISR_RFDF_DIRS             0x00010000

  /*==================================================================================================
   *   Configurable parameters
   *	User shall change configuration in this section regarding needs of the application.
     ==================================================================================================*/
#define DSPI_0_CS0_EN                                            ///enables Chip-Select number 0 for DSPI0

  //	#define	DSPI_0_CS1_EN	///enables Chip-Select number 1 for DSPI0
  //	#define	DSPI_0_CS2_EN	///enables Chip-Select number 2 for DSPI0
  //	#define	DSPI_0_CS3_EN	///enables Chip-Select number 3 for DSPI0
#define DSPI_1_CS0_EN                                            ///enables Chip-Select number 0 for DSPI1

  //	#define	DSPI_1_CS1_EN	///enables Chip-Select number 1 for DSPI1
  //	#define	DSPI_1_CS2_EN	///enables Chip-Select number 2 for DSPI1
  //	#define	DSPI_1_CS3_EN	///enables Chip-Select number 3 for DSPI1
#define DSPI_2_CS0_EN                                            ///enables Chip-Select number 0 for DSPI2

  //	#define	DSPI_2_CS1_EN	///enables Chip-Select number 1 for DSPI2
  //	#define	DSPI_2_CS2_EN	///enables Chip-Select number 2 for DSPI2
  //	#define	DSPI_2_CS3_EN	///enables Chip-Select number 3 for DSPI2

  /*==================================================================================================
   *   NON - configurable parameters
   *	User should not modify configuration in this section.
     ==================================================================================================*/
  ///DSPI basic defines
#define MASTER                         1
#define SLAVE                          0
#define PBR_VALUE1                     2.
#define PBR_VALUE2                     3.
#define PBR_VALUE3                     5.
#define PBR_VALUE4                     7.
#define PBR1                           0b00
#define PBR2                           0b01
#define PBR3                           0b10
#define PBR4                           0b11
#define BR_VALUE1                      2
#define BR_VALUE2                      4
#define BR_VALUE3                      6
#define BR_VALUE4                      8
#define BR_VALUE5                      16
#define BR_VALUE6                      32
#define BR_VALUE7                      64
#define BR_VALUE8                      128
#define BR_VALUE9                      256
#define BR_VALUE10                     512
#define BR_VALUE11                     1024
#define BR_VALUE12                     2048
#define BR_VALUE13                     4096
#define BR_VALUE14                     8192
#define BR_VALUE15                     16384
#define BR_VALUE16                     32768
#define BR1                            0b0000
#define BR2                            0b0001
#define BR3                            0b0010
#define BR4                            0b0011
#define BR5                            0b0100
#define BR6                            0b0101
#define BR7                            0b0110
#define BR8                            0b0111
#define BR9                            0b1000
#define BR10                           0b1001
#define BR11                           0b1010
#define BR12                           0b1011
#define BR13                           0b1100
#define BR14                           0b1101
#define BR15                           0b1110
#define BR16                           0b1111

  ///Minimal values of the ratio (fsys/SCKbr) with different PBR setting
#define RATIO_MIN1                     4                         //PBR = 00
#define RATIO_MIN2                     6                         //PBR = 01
#define RATIO_MIN3                     10                        //PBR = 10
#define RATIO_MIN4                     14                        //PBR = 11

  ///Maximal values of the ratio (fsys/SCKbr) with different PBR setting
#define RATIO_MAX1                     65536                     //PBR = 00
#define RATIO_MAX2                     98304                     //PBR = 01
#define RATIO_MAX3                     163840                    //PBR = 10
#define RATIO_MAX4                     229376                    //PBR = 11

  ///CTAR defines
#define LOW_SCK                        0                         //CPOL
#define HIGH_SCK                       1
#define CAPTURE_RISING                 0                         //CPHA
#define CAPTURE_FALLING                1
#define NORMAL_BR                      0                         //DBR
#define DOUBLED_BR                     1

  ///CTAR Prescalers
#define PRESC_VAL1                     0b00
#define PRESC_VAL3                     0b01
#define PRESC_VAL5                     0b10
#define PRESC_VAL7                     0b11

  ///CTAR Scalers
#define SCALER1                        0b0000
#define SCALER2                        0b0001
#define SCALER3                        0b0010
#define SCALER4                        0b0011
#define SCALER5                        0b0100
#define SCALER6                        0b0101
#define SCALER7                        0b0110
#define SCALER8                        0b0111
#define SCALER9                        0b1000
#define SCALER10                       0b1001
#define SCALER11                       0b1010
#define SCALER12                       0b1011
#define SCALER13                       0b1100
#define SCALER14                       0b1101
#define SCALER15                       0b1110
#define SCALER16                       0b1111

  ///Interrupts
#define TCFRE                          0x80000000
#define EOQFRE                         0x10000000
#define TFUFRE                         0x08000000
#define TFFFRE                         0x02000000                //Transmit FIFO Fill Request Enable (FIFO Fill will be requested by TFFF flag in the DSPI->SR)
#define TFFFDIRS                       0x01000000                //DMA request will be generated when Transmit FIFO Fill requested by TFFF flag in the DSPI->SR
#define RFOFRE                         0x00080000
#define RFDFRE                         0x00020000                //Receive FIFO Drain Request Enable (FIFO Drain will be requested by RFDF flag in the DSPI->SR)
#define RFDFDIRS                       0x00010000                //DMA request will be generated when Receive FIFO Drain requested by RFDF flag in the DSPI->SR

  ///Offset definitions
#define CTAR0_OFF                      0x000C                    //till CTAR5 by 4 Bytes each
#define TXFR0_OFF                      0x003C                    //till TXFR3 by 4 Bytes each
#define RXFR0_OFF                      0x007C                    //till RXFR3 by 4 Bytes each

  /*******************************************************************************
   * Freescale Semiconductor Inc.
   * (c) Copyright 2004-2005 Freescale Semiconductor, Inc.
   * ALL RIGHTS RESERVED.
   ********************************************************************************
     Services performed by FREESCALE in this matter are performed AS IS and without
     any warranty. CUSTOMER retains the final decision relative to the total design
     and functionality of the end product. FREESCALE neither guarantees nor will be
     held liable by CUSTOMER for the success of this project.
     FREESCALE DISCLAIMS ALL WARRANTIES, EXPRESSED, IMPLIED OR STATUTORY INCLUDING,
     BUT NOT LIMITED TO, IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS FOR
     A PARTICULAR PURPOSE ON ANY HARDWARE, SOFTWARE ORE ADVISE SUPPLIED TO THE PROJECT
     BY FREESCALE, AND OR NAY PRODUCT RESULTING FROM FREESCALE SERVICES. IN NO EVENT
     SHALL FREESCALE BE LIABLE FOR INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF
     THIS AGREEMENT.

     CUSTOMER agrees to hold FREESCALE harmless against any and all claims demands or
     actions by anyone on account of any damage, or injury, whether commercial,
     contractual, or tortuous, rising directly or indirectly as a result of the advise
     or assistance supplied CUSTOMER in connection with product, services or goods
     supplied under this Agreement.
   ********************************************************************************
   * File              template.h
   * Owner             b05111
   * Version           0.0
   * Date              mmm-dd-yyyy
   * Classification    General Business Information
   * Brief             Brief description of the file
   ********************************************************************************
   * Detailed Description:
   ********************************************************************************
     Revision History:
     Version  Date         Author        Description of Changes
     0.0      MMM-DD-YYYY  D.Tosenovjan  Initial version
   *******************************************************************************/
#ifndef _DSPI_H
#define _DSPI_H

  /*******************************************************************************
   * Bit masks for DSPI module
   *******************************************************************************/

  /* taken from COLDFIRE - should be revised !!!!!!!!!!! */

  /* Bit definitions and macros for DSPI_MCR */
#define DSPI_MCR_HALT                  (0x1)
#define DSPI_MCR_SMPL_PT(x)            (((x)&0x3)<<0x8)
#define DSPI_MCR_SMPL_PT_0CLK          (0)
#define DSPI_MCR_SMPL_PT_1CLK          (0x100)
#define DSPI_MCR_SMPL_PT_2CLK          (0x200)
#define DSPI_MCR_CLR_RXF               (0x400)
#define DSPI_MCR_CLR_TXF               (0x800)
#define DSPI_MCR_DIS_RXF               (0x1000)
#define DSPI_MCR_DIS_TXF               (0x2000)
#define DSPI_MCR_MDIS                  (0x4000)
#define DSPI_MCR_PCSIS0                (0x10000)
#define DSPI_MCR_PCSIS1                (0x20000)
#define DSPI_MCR_PCSIS2                (0x40000)
#define DSPI_MCR_PCSIS3                (0x80000)
#define DSPI_MCR_PCSIS5                (0x200000)
#define DSPI_MCR_ROOE                  (0x1000000)
#define DSPI_MCR_PCSSE                 (0x2000000)
#define DSPI_MCR_MTFE                  (0x4000000)
#define DSPI_MCR_FRZ                   (0x8000000)
#define DSPI_MCR_DCONF(x)              (((x)&0x3)<<0x1C)
#define DSPI_MCR_CONT_SCKE             (0x40000000)
#define DSPI_MCR_MSTR                  (0x80000000)

  /* Bit definitions and macros for DSPI_TCR */
#define DSPI_TCR_SPI_TCNT(x)           (((x)&0xFFFF)<<0x10)

  /* Bit definitions and macros for DSPI_CTAR */
#define DSPI_CTAR_BR(x)                (((x)&0xF)<<0)
#define DSPI_CTAR_DT(x)                (((x)&0xF)<<0x4)
#define DSPI_CTAR_ASC(x)               (((x)&0xF)<<0x8)
#define DSPI_CTAR_CSSCK(x)             (((x)&0xF)<<0xC)
#define DSPI_CTAR_PBR(x)               (((x)&0x3)<<0x10)
#define DSPI_CTAR_PBR_1CLK             (0)
#define DSPI_CTAR_PBR_3CLK             (0x10000)
#define DSPI_CTAR_PBR_5CLK             (0x20000)
#define DSPI_CTAR_PBR_7CLK             (0x30000)
#define DSPI_CTAR_PDT(x)               (((x)&0x3)<<0x12)
#define DSPI_CTAR_PDT_1CLK             (0)
#define DSPI_CTAR_PDT_3CLK             (0x40000)
#define DSPI_CTAR_PDT_5CLK             (0x80000)
#define DSPI_CTAR_PDT_7CLK             (0xC0000)
#define DSPI_CTAR_PASC(x)              (((x)&0x3)<<0x14)
#define DSPI_CTAR_PASC_1CLK            (0)
#define DSPI_CTAR_PASC_3CLK            (0x100000)
#define DSPI_CTAR_PASC_5CLK            (0x200000)
#define DSPI_CTAR_PASC_7CLK            (0x300000)
#define DSPI_CTAR_PCSSCK(x)            (((x)&0x3)<<0x16)
#define DSPI_CTAR_LSBFE                (0x1000000)
#define DSPI_CTAR_CPHA                 (0x2000000)
#define DSPI_CTAR_CPOL                 (0x4000000)
#define DSPI_CTAR_FMSZ(x)              (((x)&0xF)<<0x1B)
#define DSPI_CTAR_DBR                  (0x80000000)

  /* Bit definitions and macros for DSPI_SR */
#define DSPI_SR_POPNXTPTR(x)           (((x)&0xF)<<0)
#define DSPI_SR_RXCTR(x)               (((x)&0xF)<<0x4)
#define DSPI_SR_TXNXTPTR(x)            (((x)&0xF)<<0x8)
#define DSPI_SR_TXCTR(x)               (((x)&0xF)<<0xC)
#define DSPI_SR_RFDF                   (0x20000)
#define DSPI_SR_RFOF                   (0x80000)
#define DSPI_SR_TFFF                   (0x2000000)
#define DSPI_SR_TFUF                   (0x8000000)
#define DSPI_SR_EOQF                   (0x10000000)
#define DSPI_SR_TXRXS                  (0x40000000)
#define DSPI_SR_TCF                    (0x80000000)

  /* Bit definitions and macros for DSPI_RSER */
#define DSPI_RSER_RFDF_DIRS            (0x10000)
#define DSPI_RSER_RFDF_RE              (0x20000)
#define DSPI_RSER_RFOF_RE              (0x80000)
#define DSPI_RSER_TFFF_DIRS            (0x1000000)
#define DSPI_RSER_TFFF_RE              (0x2000000)
#define DSPI_RSER_TFUF_RE              (0x8000000)
#define DSPI_RSER_EOQF_RE              (0x10000000)
#define DSPI_RSER_TCF_RE               (0x80000000)

  /* Bit definitions and macros for DSPI_PUSHR */
#define DSPI_PUSHR_TXDATA(x)           (((x)&0xFFFF)<<0)
#define DSPI_PUSHR_PCS0                (0x10000)
#define DSPI_PUSHR_PCS1                (0x20000)
#define DSPI_PUSHR_PCS2                (0x40000)
#define DSPI_PUSHR_PCS3                (0x80000)
#define DSPI_PUSHR_PCS5                (0x200000)
#define DSPI_PUSHR_CTCNT               (0x4000000)
#define DSPI_PUSHR_EOQ                 (0x8000000)
#define DSPI_PUSHR_CTAS(x)             (((x)&0x7)<<0x1C)
#define DSPI_PUSHR_CONT                (0x80000000)

  /* Bit definitions and macros for DSPI_POPR */
#define DSPI_POPR_RXDATA(x)            (((x)&0xFFFF)<<0)

  /* Bit definitions and macros for DSPI_TXFR */
#define DSPI_TXFR_TXDATA(x)            (((x)&0xFFFF)<<0)
#define DSPI_TXFR_TXCMD(x)             (((x)&0xFFFF)<<0x10)

  /* Bit definitions and macros for DSPI_RXFR */
#define DSPI_RXFR_RXDATA(x)            (((x)&0xFFFF)<<0)
#endif                                 /* _DSPI_H */

  /*==================================================================================================
   *   Function prototypes
     ==================================================================================================*/
  void DSPI_Init(uint8_t,uint8_t, uint32_t, uint32_t, uint32_t);
  void DSPI_Send(uint8_t,uint8_t,uint16_t);
  uint32_t DSPI_Read(uint8_t);
  uint32_t DSPI_RoundBaudRate(uint32_t);
  void DSPI_SetPhase(uint8_t, uint8_t);
  void DSPI_SetPolarity(uint8_t, uint8_t);
  void DSPI_Enable(uint8_t);
  void DSPI_Disable(uint8_t);
  void changeBaudRateType(uint8_t DspiNumber, uint8_t typeBR);
  void changeFrameSizeDSPIx(uint8_t DspiNumber, uint8_t frameSize);
  void DSPI_EnableTxFIFO(uint8_t);
  void DSPI_DisableTxFIFO(uint8_t);
  void DSPI_EnableRxFIFO(uint8_t);
  void DSPI_DisableRxFIFO(uint8_t);
  void DSPI_SendWithInt(uint8_t,uint8_t,uint16_t);
  uint32_t DSPI_ReadWithInt(uint8_t);
  void DSPI_ClearRFDF(uint8_t);

  /******************************************************************************
   *                   Global function prototypes
   ******************************************************************************/
  uint16_t dspi_564xl_read_master(uint8_t dspi_num);
  uint16_t dspi_564xl_read_slave(uint8_t dspi_num);
  uint32_t dspi_564xl_get_status(uint8_t dspiNum);
  void dspi_564xl_send(uint8_t dspi_num, DSPI_PUSHR_32B_tag pushr_data);
  void dspi_564xl_config(uint8_t, uint32_t, uint32_t);
  void dspi_564xl_pin_init(uint8_t pcr_num, uint8_t in_out, uint8_t dspi_num);
  void dspi_564xl_interrupt_set(uint8_t dspiNum, uint32_t flag);
  void dspi_564xl_interrupt_clr(uint8_t dspiNum, uint32_t flag);

#ifdef __cplusplus

}
#endif
#endif                                 /* _DSPI_564xL_LIBRARY_H */

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
