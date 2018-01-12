/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    gpio_564xl_library.c
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   Functions to Read and Write GPIO data.
 *    @details Functions to Read and Write GPIO data.
 *
 *    Project M4_SRC_PROJECT_NAME
 *    Platform M4_SRC_MCU_FAMILY
 *
 *   Creation date:
 *   Author:               b14714
 *
 */

#ifdef __cplusplus

extern "C"{

#endif

  /******************************************************************************
   *                  Includes
   ******************************************************************************/
#include "gpio_564xl_library.h"

  /******************************************************************************
   *   Function:  gpi_pin_read_564xl_fnc
     @brief    Read data from GPI Pin Data Input Registers .
     @details  Read data from GPI Pin Data Input Registers

     @param[in]     pcr_num   - GPIO Pin Data Input Register number

     @return The read data
   */
  uint8_t gpi_pin_read_564xl_fnc(uint8_t pcr_num)
  {
    uint8_t inputdata = 0;

    /* Read data from GPI Pin Data Input Registers  */
    inputdata = SIU.GPDI[pcr_num].R;
    return(inputdata);
  }

  /******************************************************************************
   *   Function:  gpo_pin_update_564xl_fnc
     @brief    GPO Write Data function.
     @details  Write data to GPIO Pin Data output Registers

     @param[in]     pcr_num   - GPIO Pin Data Input Register number
     @param[in]     data   -  data to be written

     @return none
   */
  void gpo_pin_update_564xl_fnc(uint8_t pcr_num, uint8_t data)
  {
    /* Write data to GPIO Pin Data output Registers  */
    SIU.GPDO[pcr_num].R = data;
  }

  /******************************************************************************
   *   Function:  gpi_init_pcr_in_564xl_fnc
     @brief    GPI Init Pcr as Input function.
     @details  Init PCR to Digital Input Configuration

     @param[in]     pcr_num   - GPI Pin Data Input Register number

     @return none
   */
  void gpi_init_pcr_in_564xl_fnc( uint8_t pcr_num )
  {
    /* Init PCR to Digital Input Configuration */
    SIU.PCR[pcr_num].R = PCR_INPUT_ENABLE;
  }

  /******************************************************************************
   *   Function:  gpo_init_pcr_out_564xl_fnc
     @brief    GPO Init Pcr as Output function.
     @details  Init PCR to Digital Output Configuration

     @param[in]     pcr_num   - GPI Pin Data Input Register number

     @return none
   */
  /* GPO Init Pcr as Output function */
  void gpo_init_pcr_out_564xl_fnc( uint8_t pcr_num )
  {
    /* Init PCR to Digital Output Configuration */
    SIU.PCR[pcr_num].R = PCR_OUTPUT_ENABLE;
  }

#ifdef __cplusplus

}
#endif

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
