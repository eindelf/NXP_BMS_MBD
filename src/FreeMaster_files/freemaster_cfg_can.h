/***************************************************************************//*!
*
* @file   freemaster_cfg.h.example
*
* @brief  FreeMASTER Serial Communication Driver configuration file
*
*******************************************************************************/

#ifndef __FREEMASTER_CFG_H
#define __FREEMASTER_CFG_H


/******************************************************************************
* Select interrupt or poll-driven serial communication
******************************************************************************/

#define FMSTR_LONG_INTR    0        /* complete message processing in interrupt */
#define FMSTR_SHORT_INTR   0        /* SCI FIFO-queuing done in interrupt */
#define FMSTR_POLL_DRIVEN  1        /* no interrupt needed, polling only */

/*****************************************************************************
* Select communication interface (SCI base address)
******************************************************************************/

#include "freemaster_device.h"

#ifndef FMSTR_SCI_SECOND
#define FMSTR_SCI_BASE 0xFFE40000UL   /* LINFlex0 base on MPC5643L */
#else
#define FMSTR_SCI_BASE 0xFFE44000UL   /* LINFlex1 base on MPC5643L */
#endif
#ifndef FMSTR_CAN_SECOND
#define FMSTR_CAN_BASE 0xFFFC0000UL   /* FlexCAN0 base on MPC5643L */
#else
#define FMSTR_CAN_BASE 0xFFFC4000UL   /* FlexCAN1 base on MPC5643L */
#endif

#define FMSTR_USE_SCI      0
#define FMSTR_USE_FLEXCAN  1
#define FMSTR_USE_CAN	   1

/* select RX and TX FlexCAN Message buffers */
#define FMSTR_FLEXCAN_TXMB 0
#define FMSTR_FLEXCAN_RXMB 1

/******************************************************************************
* Input/output communication buffer size
******************************************************************************/

#define FMSTR_COMM_BUFFER_SIZE 0    /* set to 0 for "automatic" */

/******************************************************************************
* Receive FIFO queue size (use with FMSTR_SHORT_INTR only)
******************************************************************************/

#define FMSTR_COMM_RQUEUE_SIZE 32   /* set to 0 for "default" */

/*****************************************************************************
* Support for Application Commands 
******************************************************************************/

#define FMSTR_USE_APPCMD       1    /* enable/disable App.Commands support */
#define FMSTR_APPCMD_BUFF_SIZE 32   /* App.Command data buffer size */
#define FMSTR_MAX_APPCMD_CALLS 4    /* how many app.cmd callbacks? (0=disable) */

/*****************************************************************************
* Oscilloscope support
******************************************************************************/

#define FMSTR_USE_SCOPE       1     /* enable/disable scope support */
#define FMSTR_MAX_SCOPE_VARS  8     /* max. number of scope variables (2..8) */

/*****************************************************************************
* Recorder support
******************************************************************************/

#define FMSTR_USE_RECORDER    1     /* enable/disable recorder support */
#define FMSTR_MAX_REC_VARS    8     /* max. number of recorder variables (2..8) */
#define FMSTR_REC_OWNBUFF     0     /* use user-allocated rec. buffer (1=yes) */

/* built-in recorder buffer (use when FMSTR_REC_OWNBUFF is 0) */
#define FMSTR_REC_BUFF_SIZE   1024  /* built-in buffer size */

/* recorder time base, specifies how often the recorder is called in the user app. */
#define FMSTR_REC_TIMEBASE    FMSTR_REC_BASE_MILLISEC(0) /* 0 = "unknown" */

#define FMSTR_REC_FLOAT_TRIG  0     /* enable/disable floating point triggering */

/*****************************************************************************
* Target-side address translation (TSA)
******************************************************************************/

#define FMSTR_USE_TSA         0     /* enable TSA functionality */
#define FMSTR_USE_TSA_SAFETY  0     /* enable access to TSA variables only */
#define FMSTR_USE_TSA_INROM   0     /* TSA tables declared as const (put to ROM) */

/*****************************************************************************
* Enable/Disable read/write memory commands
******************************************************************************/

#define FMSTR_USE_READMEM      1    /* enable read memory commands */
#define FMSTR_USE_WRITEMEM     1    /* enable write memory commands */
#define FMSTR_USE_WRITEMEMMASK 1    /* enable write memory bits commands */

/*****************************************************************************
* Enable/Disable read/write variable commands (a bit faster than Read Mem)
******************************************************************************/

#define FMSTR_USE_READVAR      0    /* enable read variable fast commands */
#define FMSTR_USE_WRITEVAR     0    /* enable write variable fast commands */
#define FMSTR_USE_WRITEVARMASK 0    /* enable write variable bits fast commands */

/*****************************************************************************
* CAN-related constants 
******************************************************************************/
    
#ifdef FMSTR_CAN_EXTID 
	#if FMSTR_CAN_EXTID != 0x80000000U
		#error FMSTR_CAN_EXTID must be defined as 0x80000000
		#undef FMSTR_CAN_EXTID 
	#endif
#endif

#ifndef FMSTR_CAN_EXTID
	#define FMSTR_CAN_EXTID 0x80000000U
#endif

/* flexcan needs to know the transmit and receive MB number */
#if FMSTR_USE_FLEXCAN
	/* Flexcan TX message buffer must be defined */
	#ifndef FMSTR_FLEXCAN_TXMB
	//#error FlexCAN transmit buffer needs to be specified (use FMSTR_FLEXCAN_TXMB)
	#warning "FlexCAN Message Buffer 0 is used for transmitting messages"
	#define FMSTR_FLEXCAN_TXMB 0
#endif
/* Flexcan RX message buffer must be defined */
#ifndef FMSTR_FLEXCAN_RXMB
	//#error FlexCAN receive buffer needs to be specified (use FMSTR_FLEXCAN_RXMB)
	#warning "FlexCAN Message Buffer 1 is used for receiving messages"
	#define FMSTR_FLEXCAN_RXMB 1
	#endif
#endif
  
/* incoming (command) CAN message ID */
#ifndef FMSTR_CAN_CMDID
    #define FMSTR_CAN_CMDID 0x7aa
#endif

/* command ID can be changed in runtime (before FMSTR_Init) */
#ifndef FMSTR_CAN_CMDID_DYNAMIC
    #define FMSTR_CAN_CMDID_DYNAMIC 0  /* disabled by default */
#endif
    
/* response CAN message ID, may be the same as command ID */
#ifndef FMSTR_CAN_RESPID
    #define FMSTR_CAN_RESPID 0x7aa
#endif
    
/* response ID can be changed in runtime (before FMSTR_Init) */
#ifndef FMSTR_CAN_RESPID_DYNAMIC
    #define FMSTR_CAN_RESPID_DYNAMIC 0  /* disabled by default */
#endif


#endif /* __FREEMASTER_CFG_H */
