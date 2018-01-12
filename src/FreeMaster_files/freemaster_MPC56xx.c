/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2011 Freescale Semiconductor
* ALL RIGHTS RESERVED.
*
****************************************************************************//*!
*
* @file   freemaster_MPC56xx.c
*
* @brief  FreeMASTER Driver MPC56xx-hardware dependent stuff
*
* @version 1.0.3.0
*
* @date Aug-4-2011
*
*******************************************************************************/

#include "freemaster.h"
#include "freemaster_private.h"
#include "freemaster_MPC56xx.h"

#if (!FMSTR_DISABLE)
/*******************************************************************************
*
* @brief    API: Main SCI Interrupt handler call
*
* This Interrupt Service Routine handles the SCI interrupts for the FreeMASTER
* driver. In case you want to handle the interrupt in the application yourselves,
* call the FMSTR_ProcessSCI function which does the same job but is not compiled
* as an Interrupt Service Routine.
*
* In poll-driven mode (FMSTR_POLL_DRIVEN) this function does nothing.
*
*******************************************************************************/

void FMSTR_Isr(void)
{
#if FMSTR_LONG_INTR || FMSTR_SHORT_INTR

    /* process serial interface */
#if FMSTR_USE_SCI
    FMSTR_ProcessSCI();

    /* process CAN interface */
#elif FMSTR_USE_CAN
    FMSTR_ProcessCanRx();
    FMSTR_ProcessCanTx(); 
#endif

#endif
}

/**************************************************************************//*!
*
* @brief    The "memcpy" used internally in FreeMASTER driver
*
* @param    nDestAddr - destination memory address
* @param    nSrcAddr  - source memory address
* @param    nSize     - memory size (always in bytes)
*
******************************************************************************/

void FMSTR_CopyMemory(FMSTR_ADDR nDestAddr, FMSTR_ADDR nSrcAddr, FMSTR_SIZE8 nSize)
{
    FMSTR_U8* ps = (FMSTR_U8*) nSrcAddr;
    FMSTR_U8* pd = (FMSTR_U8*) nDestAddr;

    while(nSize--)
        *pd++ = *ps++;
}

/**************************************************************************//*!
*
* @brief  Write-into the communication buffer memory
*
* @param  pDestBuff - pointer to destination memory in communication buffer
* @param  nSrcAddr  - source memory address
* @param  nSize     - buffer size (always in bytes)
*
* @return This function returns a pointer to next byte in comm. buffer
*
******************************************************************************/

FMSTR_BPTR FMSTR_CopyToBuffer(FMSTR_BPTR pDestBuff, FMSTR_ADDR nSrcAddr, FMSTR_SIZE8 nSize)
{
    FMSTR_U8* ps = (FMSTR_U8*) nSrcAddr;
    FMSTR_U8* pd = (FMSTR_U8*) pDestBuff;

    while(nSize--)
        *pd++ = *ps++;

    return (FMSTR_BPTR) pd;
}

/**************************************************************************//*!
*
* @brief  Read-out memory from communication buffer
*
* @param  nDestAddr - destination memory address
* @param  pSrcBuff  - pointer to source memory in communication buffer
* @param  nSize     - buffer size (always in bytes)
*
* @return This function returns a pointer to next byte in comm. buffer
*
******************************************************************************/

FMSTR_BPTR FMSTR_CopyFromBuffer(FMSTR_ADDR nDestAddr, FMSTR_BPTR pSrcBuff, FMSTR_SIZE8 nSize)
{
    FMSTR_U8* ps = (FMSTR_U8*) pSrcBuff;
    FMSTR_U8* pd = (FMSTR_U8*) nDestAddr;

    while(nSize--)
        *pd++ = *ps++;

    return (FMSTR_BPTR) ps;
}


/**************************************************************************//*!
*
* @brief  Read-out memory from communication buffer, perform AND-masking
*
* @param  nDestAddr - destination memory address
* @param  pSrcBuff  - source memory in communication buffer, mask follows data
* @param  nSize     - buffer size (always in bytes)
*
******************************************************************************/

void FMSTR_CopyFromBufferWithMask(FMSTR_ADDR nDestAddr, FMSTR_BPTR pSrcBuff, FMSTR_SIZE8 nSize)
{
    FMSTR_U8* ps = (FMSTR_U8*) pSrcBuff;
    FMSTR_U8* pd = (FMSTR_U8*) nDestAddr;
    FMSTR_U8* pm = ps + nSize;
    FMSTR_U8 mask, stmp, dtmp;

    while(nSize--)
    {
        mask = *pm++;
        stmp = *ps++;
        dtmp = *pd;

        /* perform AND-masking */
        stmp = (FMSTR_U8) ((stmp & mask) | (dtmp & ~mask));

        /* put the result back       */
        *pd++ = stmp;
    }
}

/******************************************************************************/

/* mixed EX and no-EX commands? */
#if FMSTR_USE_EX_CMDS && FMSTR_USE_NOEX_CMDS

/**************************************************************************//*!
*
* @brief  When mixed EX and no-EX command may occur, this variable is
*         here to remember what command is just being handled.
*
******************************************************************************/

static FMSTR_BOOL pcm_bNextAddrIsEx;

void FMSTR_SetExAddr(FMSTR_BOOL bNextAddrIsEx)
{
    pcm_bNextAddrIsEx = bNextAddrIsEx;
}

/**************************************************************************//*!
*
* @brief  Store address to communication buffer. The address may be
*         32 or 16 bit wide (based on previous call to FMSTR_SetExAddr)
*
******************************************************************************/

FMSTR_BPTR FMSTR_AddressToBuffer(FMSTR_BPTR pDest, FMSTR_ADDR nAddr)
{
    if(pcm_bNextAddrIsEx)
    {
        /* fill in the 32bit address */
        *(FMSTR_U32*) pDest = ((FMSTR_U32)nAddr);
        pDest += 4;
    }
    else
    {
        /* fill in the 16bit address (never used) */
        *(FMSTR_U16*) pDest = ((FMSTR_U16)nAddr);
        pDest += 2;
    }

    return pDest;
}

/**************************************************************************//*!
*
* @brief  Fetch address from communication buffer
*
******************************************************************************/

FMSTR_BPTR FMSTR_AddressFromBuffer(FMSTR_ADDR* pAddr, FMSTR_BPTR pSrc)
{
    if(pcm_bNextAddrIsEx)
    {
        *pAddr = (FMSTR_ADDR) *((FMSTR_U32*) pSrc);
        pSrc += 4;
    }
    else
    {
        *pAddr = (FMSTR_ADDR) *((FMSTR_U16*) pSrc);
        pSrc += 2;
    }

    return pSrc;
}

#endif /* mixed EX and no-EX commands */

#endif /* (!FMSTR_DISABLE) */
