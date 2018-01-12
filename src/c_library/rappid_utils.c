/**
 *######################################################################
*                (c) Copyright 2011 Freescale Semiconductor, Inc.
*                         ALL RIGHTS RESERVED. 
 *######################################################################
*
*    @file    rappid_utils.c
*    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*    @brief   utility functions.
*    @details utility functions.
*    
*    Project M4_SRC_PROJECT_NAME
*    Platform M4_SRC_MCU_FAMILY
*
*   Creation date:		23-May-2011
*   Author:                         B14423
* 
*/

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
*                  Includes
******************************************************************************/
 #include "rappid_utils.h"
/******************************************************************************
*                   Global functions
******************************************************************************/
/****************** Enable/Disable Interrupt Interrupts *******************/
/******************************************************************************
*   Function:  EnableExternalInterrupts
@brief    Enable External Interrupts . 
@details   Sets Enable External Interrupts  flag
   
@return none
*/
void EnableExternalInterrupts (void)
{
    asm(" wrteei 1");
}

/******************************************************************************
*   Function:  DisableExternalInterrupts
@brief    Disable External Interrupts . 
@details   Clear Enable External Interrupts  flag
   
@return none
*/
void DisableExternalInterrupts (void)
{
    asm(" wrteei 0");
}



/*  ###################### Function for clearing BUFFERs ######################  */
/******************************************************************************
*   Function:  fs_clearmem
@brief    Function for clearing BUFFERs . 
@details   Function for clearing BUFFERs
    
@param[in]     address     address
@param[in]     size     size 
@param[in]     fillbyte     fillbyte 
 
@return none
*/
void fs_clearmem(vuint8_t* address , uint8_t size, uint8_t fillbyte)
{
    while(size > 0)
    {
        *address = fillbyte;
        size-- ;
        address++ ;
    }
}

#ifdef __cplusplus
}
#endif

/*
*######################################################################
*                           End of File
*######################################################################
*/
