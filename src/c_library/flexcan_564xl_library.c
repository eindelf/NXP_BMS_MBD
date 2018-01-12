/**
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED.
 *######################################################################
 *
 *    @file    flexcan_564xl_library.c
 *    @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
 *
 *    @brief   FlexCAN module support.
 *    @details Implementation of FlexCAN module functions.
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
#include "flexcan_564xl_library.h"

/**/
/******************************************************************************
*                   Global functions
******************************************************************************/

/******************************************************************************
*   Function:  flexcan_564xl_init
	@brief    Initialize FlexCAN module .
	@details   Initialize FlexCAN module

	@param[in]     flex_can     FlexCAN module
	@param[in]     MCR     	MCR
	@param[in]     CR     	CR

	@return status
*/
uint8_t flexcan_564xl_init(uint8_t flex_can, uint32_t MCR, uint32_t CR)	{
	uint8_t x = 0U;
	uint8_t i = 0U;
	uint8_t status = 0U;
	switch (flex_can)	{
		case FLEXCAN_0:	{
			CAN_0.MCR.B.MDIS = 0;
			CAN_0.MCR.B.SOFT_RST = 1;
			while (CAN_0.MCR.B.SOFT_RST ==1) {}

			CAN_0.MCR.B.MDIS = 1;
			CAN_0.CR.B.CLK_SRC = 0;

			/*Enable the CAN module */
			CAN_0.MCR.B.MDIS = 0;

			/* Set FRZ bit */
			CAN_0.MCR.B.FRZ = 1;

			/* Set HALT bit */
			CAN_0.MCR.B.HALT = 1;
			CAN_0.MCR.R = MCR;
			CAN_0.CR.R = CR;

			/* Set the FlexCAN Maximum Buffer Number */
			CAN_0.MCR.B.MAXMB = 32;

			/* clear memory from message buffer 0 to 15 */
			for (x=0; x < 32; x++)	{
				CAN_0.BUF[x].CS.R = 0;
				CAN_0.BUF[x].ID.R = 0;
				for (i=0; i < 2; i++)	{
					CAN_0.BUF[x].DATA.W[i] = 0;
				}
			}

			for (x=0 ; x<32 ; x++)	{
				CAN_0.RXIMR[x].R = 0xFFFFFFFF;
			}

			CAN_0.IMRL.R = 0x00000000;
			CAN_0.MCR.B.HALT = 0;
			CAN_0.MCR.B.FRZ = 0;

			/* await synchronization (delay) */
			for (x=1; x < 255; x++)	{}

			if (CAN_0.MCR.B.NOT_RDY == 1)	{
				status = 1;
			} else	{
				status = 0;
			}
			break;
		}

		case FLEXCAN_1:	{
			CAN_1.MCR.B.MDIS = 0;
			CAN_1.MCR.B.SOFT_RST = 1;
			while (CAN_1.MCR.B.SOFT_RST ==1)	{}

			CAN_1.MCR.B.MDIS = 1;
			CAN_1.CR.B.CLK_SRC = 0;

			/*Enable the CAN module */
			CAN_1.MCR.B.MDIS = 0;

			/* Set FRZ bit */
			CAN_1.MCR.B.FRZ = 1;

			/* Set HALT bit */
			CAN_1.MCR.B.HALT = 1;
			CAN_1.MCR.R = MCR;
			CAN_1.CR.R = CR;

			/* Set the FlexCAN Maximum Buffer Number */
			CAN_1.MCR.B.MAXMB = 32;

			/* clear memory from message buffer 0 to 15 */
			for (x=0; x < 32; x++)	{
				CAN_1.BUF[x].CS.R = 0;
				CAN_1.BUF[x].ID.R = 0;
				for (i=0; i < 2; i++)	{
					CAN_1.BUF[x].DATA.W[i] = 0;
				}
			}

			for (x=0 ; x<32 ; x++)	{
				CAN_1.RXIMR[x].R = 0xFFFFFFFF;
			}

			CAN_1.IMRL.R = 0x00000000;
			CAN_1.MCR.B.HALT = 0;
			CAN_1.MCR.B.FRZ = 0;

			/* await synchronization (delay) */
			for (x=1; x < 255; x++)	{}

			if (CAN_1.MCR.B.NOT_RDY == 1)	{
				status = 1;
			} else	{
				status = 0;
			}
			break;
		}
		default:
			break;
	}

	return status;
}

/******************************************************************************
*	Function:  flexcan_564xl_init_CCP
	@brief    Initialize FlexCAN module .
	@details   Initialize FlexCAN module and don't update MB reserved by CCP module
	

	@param[in]     flex_can     FlexCAN module
	@param[in]     MCR     	MCR
	@param[in]     CR     	CR
	@param[in]	   mb0		MB0 for CCP
	@param[in]	   mb1		MB1 for CCP

	@return status
*/

uint8_t flexcan_564xl_init_CCP(uint8_t flex_can, uint32_t MCR, uint32_t CR, uint8_t mb0, uint8_t mb1){
	uint32_t mb0_data = 0;
	uint32_t mb1_data = 0;
	uint8_t out = 0;
	
	if (flex_can == FLEXCAN_0){
		mb0_data = CAN_0.RXIMR[mb0].R;
		mb1_data = CAN_0.RXIMR[mb1].R;
		
		out = flexcan_564xl_init(flex_can, MCR, CR);
		
		CAN_0.RXIMR[mb0].R = mb0_data;
		CAN_0.RXIMR[mb1].R = mb1_data;
		
	}else if (flex_can == FLEXCAN_1){
		
		mb0_data = CAN_1.RXIMR[mb0].R;
		mb1_data = CAN_1.RXIMR[mb1].R;
		
		out = flexcan_564xl_init(flex_can, MCR, CR);
		
		CAN_1.RXIMR[mb0].R = mb0_data;
		CAN_1.RXIMR[mb1].R = mb1_data;
	
	}
	
	return out;	
}

/******************************************************************************
*	Function:  flexcan_564xl_init_CCP_FM
	@brief    Initialize FlexCAN module .
	@details   Initialize FlexCAN module and don't update MB reserved by FreeMaster and CCP modules
	

	@param[in]     flex_can     FlexCAN module
	@param[in]     MCR     	MCR
	@param[in]     CR     	CR
	@param[in]	   mb0		MB0 for CCP
	@param[in]	   mb1		MB1 for CCP

	@return status
*/
uint8_t flexcan_564xl_init_CCP_FM(uint8_t flex_can, uint32_t MCR, uint32_t CR, uint8_t mb0, uint8_t mb1){
	uint32_t mb0_data = 0;
	uint32_t mb1_data = 0;
	uint8_t out = 0;
	
	if (flex_can == FLEXCAN_0){
		mb0_data = CAN_0.RXIMR[mb0].R;
		mb1_data = CAN_0.RXIMR[mb1].R;
		
		out = flexcan_564xl_init_FM(flex_can, MCR, CR);
		
		CAN_0.RXIMR[mb0].R = mb0_data;
		CAN_0.RXIMR[mb1].R = mb1_data;
		
	}else if (flex_can == FLEXCAN_1){
		
		mb0_data = CAN_1.RXIMR[mb0].R;
		mb1_data = CAN_1.RXIMR[mb1].R;
		
		out = flexcan_564xl_init_FM(flex_can, MCR, CR);
		
		CAN_1.RXIMR[mb0].R = mb0_data;
		CAN_1.RXIMR[mb1].R = mb1_data;
	
	}
	
	return out;	
}

/******************************************************************************
*	Function:  flexcan_564xl_init_FM
	@brief    Initialize FlexCAN module .
	@details   Initialize FlexCAN module
	this function doesn't initialize MB0, MB1 because it was done before by FreeMaster

	@param[in]     flex_can     FlexCAN module
	@param[in]     MCR     	MCR
	@param[in]     CR     	CR

	@return status
*/
uint8_t flexcan_564xl_init_FM(uint8_t flex_can, uint32_t MCR, uint32_t CR)	{
	uint8_t x = 0U;
	uint8_t i = 0U;
	uint8_t status = 0U;
	switch (flex_can)	{
		case FLEXCAN_0:		{
			CAN_0.MCR.B.MDIS = 0;
			CAN_0.MCR.B.SOFT_RST = 1;
			while (CAN_0.MCR.B.SOFT_RST ==1) {}

			CAN_0.MCR.B.MDIS = 1;
			CAN_0.CR.B.CLK_SRC = 0;

			/*Enable the CAN module */
			CAN_0.MCR.B.MDIS = 0;

			/* Set FRZ bit */
			CAN_0.MCR.B.FRZ = 1;

			/* Set HALT bit */
			CAN_0.MCR.B.HALT = 1;
			CAN_0.MCR.R = MCR;
			CAN_0.CR.R = CR;

			/* Set the FlexCAN Maximum Buffer Number */
			CAN_0.MCR.B.MAXMB = 32;

			/* clear memory from message buffer 0 to 15 */
			for (x=2; x < 32; x++)	{
				CAN_0.BUF[x].CS.R = 0;
				CAN_0.BUF[x].ID.R = 0;
				for (i=0; i < 2; i++)	{
					CAN_0.BUF[x].DATA.W[i] = 0;
				}
			}

			for (x=2 ; x<32 ; x++)	{
				CAN_0.RXIMR[x].R = 0xFFFFFFFF;
			}

			CAN_0.IMRL.R = 0x00000000;
			CAN_0.MCR.B.HALT = 0;
			CAN_0.MCR.B.FRZ = 0;

			/* await synchronization (delay) */
			for (x=1; x < 255; x++)	{}

			if (CAN_0.MCR.B.NOT_RDY == 1) {
				status = 1;
			} else {
				status = 0;
			}
			break;
		}

		case FLEXCAN_1:		{
			CAN_1.MCR.B.MDIS = 0;
			CAN_1.MCR.B.SOFT_RST = 1;
			while (CAN_1.MCR.B.SOFT_RST ==1)	{}

			CAN_1.MCR.B.MDIS = 1;
			CAN_1.CR.B.CLK_SRC = 0;

			/*Enable the CAN module */
			CAN_1.MCR.B.MDIS = 0;

			/* Set FRZ bit */
			CAN_1.MCR.B.FRZ = 1;

			/* Set HALT bit */
			CAN_1.MCR.B.HALT = 1;
			CAN_1.MCR.R = MCR;
			CAN_1.CR.R = CR;

			/* Set the FlexCAN Maximum Buffer Number */
			CAN_1.MCR.B.MAXMB = 32;

			/* clear memory from message buffer 0 to 15 */
			for (x=2; x < 32; x++)	{
				CAN_1.BUF[x].CS.R = 0;
				CAN_1.BUF[x].ID.R = 0;
				for (i=0; i < 2; i++)	{
					CAN_1.BUF[x].DATA.W[i] = 0;
				}
			}

			for (x=2 ; x<32 ; x++)	{
				CAN_1.RXIMR[x].R = 0xFFFFFFFF;
			}

			CAN_1.IMRL.R = 0x00000000;
			CAN_1.MCR.B.HALT = 0;
			CAN_1.MCR.B.FRZ = 0;

			/* await synchronization (delay) */
			for (x=1; x < 255; x++)	{}

			if (CAN_1.MCR.B.NOT_RDY == 1) {
				status = 1;
			} else {
				status = 0;
			}
			break;
		}
		default:
			break;
	}

	return status;
}

/******************************************************************************
*   Function:  flexcan_564xl_pin_init
	@brief    Initialize FlexCAN module pins.
	@details   Initialize FlexCAN module pins


	@param[in]     flex_can     FlexCAN module

	@return none
*/
void flexcan_564xl_pin_init(uint8_t flex_can)	{
	switch (flex_can)	{
		case FLEXCAN_0:		{
			SIU.PCR[16].R = 0x0624;
			SIU.PCR[17].R = 0x0100;
			SIU.PSMI[33].R = 0x01;
			break;
		}

		case FLEXCAN_1:		{
			SIU.PCR[14].R = 0x0624;
			SIU.PCR[15].R = 0x0100;
			SIU.PSMI[34].R = 0x00;
			break;
		}
		default:
			break;
	}
}

/******************************************************************************
*   Function:  flexcan_564xl_buffer_init
	@brief    Initialize FlexCAN module buffer.
	@details   Initialize FlexCAN module buffer

	@param[in]     ptr_FLEXCAN_MsgBufferStructure     pointer to structure
	@param[in]     BufferNo     buffer
	@param[in]     flex_can     FlexCAN module

	@return none
*/
void flexcan_564xl_buffer_init(const FLEXCAN_MsgBufferStructure
    *ptr_FLEXCAN_MsgBufferStructure,uint8_t BufferNo,uint8_t flex_can)	{

	if (flex_can == FLEXCAN_0)	{
		/* clear message buffer memory */
		CAN_0.BUF[BufferNo].CS.R = ptr_FLEXCAN_MsgBufferStructure->code;
		CAN_0.BUF[BufferNo].MSG_ID.R = ptr_FLEXCAN_MsgBufferStructure->id;
	} else if (flex_can == FLEXCAN_1) {
		/* clear message buffer memory */
		CAN_1.BUF[BufferNo].CS.R = ptr_FLEXCAN_MsgBufferStructure->code;
		CAN_1.BUF[BufferNo].MSG_ID.R = ptr_FLEXCAN_MsgBufferStructure->id;
	}
}

/******************************************************************************
*   Function:flexcan_564xl_buffer_transmit
	@brief    transmit  FlexCAN module buffer.
	@details   transmit FlexCAN module buffer

	@param[in]     ptr_FLEXCAN_MsgBufferStructure     pointer to structure
	@param[in]     BufferNo     buffer
	@param[in]     flex_can     FlexCAN module

	@return none
*/
void flexcan_564xl_buffer_transmit(const FLEXCAN_MsgBufferStructure
    *ptr_FLEXCAN_MsgBufferStructure,uint8_t BufferNo,uint8_t flex_can)  {

	uint8_t i;
	if (flex_can==FLEXCAN_0)	{
		if (ptr_FLEXCAN_MsgBufferStructure->ext)	{
			CAN_0.BUF[BufferNo].CS.B.IDE = 1;/* extended ID */
			CAN_0.BUF[BufferNo].ID.R = ptr_FLEXCAN_MsgBufferStructure->id;
		} else	{
			CAN_0.BUF[BufferNo].CS.B.IDE = 0;/* standart ID */
			CAN_0.BUF[BufferNo].ID.B.STD_ID = (uint16_t)
			ptr_FLEXCAN_MsgBufferStructure->id;
		}

		CAN_0.BUF[BufferNo].CS.B.RTR = 0;
		CAN_0.BUF[BufferNo].CS.B.LENGTH = ptr_FLEXCAN_MsgBufferStructure->length;
		for (i=0; i < ptr_FLEXCAN_MsgBufferStructure->length; i++)	{
			CAN_0.BUF[BufferNo].DATA.B[i] = 0;
			CAN_0.BUF[BufferNo].DATA.B[i] = ptr_FLEXCAN_MsgBufferStructure->data[i];
		}

		CAN_0.BUF[BufferNo].CS.B.SRR = 1;/* Tx frame */
		CAN_0.BUF[BufferNo].CS.B.CODE |= ptr_FLEXCAN_MsgBufferStructure->code;
	} else if (flex_can==FLEXCAN_1)	{
		if (ptr_FLEXCAN_MsgBufferStructure->ext)	{
			CAN_1.BUF[BufferNo].CS.B.IDE = 1;/* extended ID */
			CAN_1.BUF[BufferNo].ID.R = ptr_FLEXCAN_MsgBufferStructure->id;
		} else {
			CAN_1.BUF[BufferNo].CS.B.IDE = 0;/* standart ID */
			CAN_1.BUF[BufferNo].ID.B.STD_ID = (uint16_t)
			ptr_FLEXCAN_MsgBufferStructure->id;
		}

		CAN_1.BUF[BufferNo].CS.B.RTR = 0;
		CAN_1.BUF[BufferNo].CS.B.LENGTH = ptr_FLEXCAN_MsgBufferStructure->length;
		for (i=0; i < ptr_FLEXCAN_MsgBufferStructure->length; i++)	{
			CAN_1.BUF[BufferNo].DATA.B[i] = 0;
			CAN_1.BUF[BufferNo].DATA.B[i] = ptr_FLEXCAN_MsgBufferStructure->data[i];
		}

		CAN_1.BUF[BufferNo].CS.B.SRR = 1;/* Tx frame */
		CAN_1.BUF[BufferNo].CS.B.CODE |= ptr_FLEXCAN_MsgBufferStructure->code;
	}
}

/******************************************************************************
*	Function: flexcan_564xl_rxbuffull
	@brief      FlexCAN module buffer full.
	@details   FlexCAN module buffer full

	@param[in]     flex_can     FlexCAN module
	@param[in]     mb     mb

	@return none
*/
uint8_t flexcan_564xl_rxbuffull(uint8_t flex_can, uint8_t mb)	{
	uint8_t ret = 0U;
	switch (flex_can){
		case FLEXCAN_0:	{
			if (CAN_0.IFLAG1.R & (0x1U << mb))
				ret= 1;
			break;
		}

		case FLEXCAN_1:	{
			if (CAN_1.IFLAG1.R & (0x1U << mb))
				ret= 1;
			break;
		}
		default:
			break;
	}
	return ret;
}

/******************************************************************************
*	Function: flexcan_564xl_buffer_lock
	@brief      FlexCAN module buffer lock.
	@details   FlexCAN module buffer lock

	@param[in]     flex_can     FlexCAN module
	@param[in]     BufferNo     BufferNo

	@return none
*/
void flexcan_564xl_buffer_lock(uint8_t flex_can,uint8_t BufferNo)	{
	vuint32_t dummy;
	if (flex_can == FLEXCAN_0)	{
		dummy = CAN_0.BUF[BufferNo].CS.R;
	} else if (flex_can == FLEXCAN_1)	{
		dummy = CAN_1.BUF[BufferNo].CS.R;
	}
}

/******************************************************************************
*	Function: flexcan_564xl_buffer_rxbusy
	@brief      FlexCAN module buffer busy.
	@details   FlexCAN module buffer busy

	@param[in]     flex_can     FlexCAN module
	@param[in]     BufferNo     BufferNo

	@return  status
*/
uint8_t flexcan_564xl_buffer_rxbusy(uint8_t flex_can, uint8_t BufferNo)	{
	uint8_t ubReturn = 0;
	if (flex_can == FLEXCAN_0)	{
		if ((CAN_0.BUF[BufferNo].CS.B.CODE & 0x01) !=0)	{
			ubReturn = 1;
		}
	} else if (flex_can == FLEXCAN_1)	{
		if ((CAN_1.BUF[BufferNo].CS.B.CODE & 0x01) !=0)	{
			ubReturn = 1;
		}
	}
	return ubReturn;
}

/******************************************************************************
*	Function: flexcan_564xl_get_id
	@brief      returns message ID.
	@details   returns message ID

	@param[in]     flex_can     FlexCAN module
	@param[in]     BufferNo     BufferNo

	@return  id
*/
uint32_t flexcan_564xl_get_id(uint8_t flex_can, uint8_t BufferNo)	{
	uint32_t id = 0;
	if (flex_can == FLEXCAN_0)	{
		if ((CAN_0.BUF[BufferNo].CS.B.IDE & 0x01) ==0)	{
			/* Standard ID */
			id = CAN_0.BUF[BufferNo].MSG_ID.B.STD_ID;
		} else if ((CAN_0.BUF[BufferNo].CS.B.IDE & 0x01) !=0)	{
			/* Extended ID */
			id = CAN_0.BUF[BufferNo].MSG_ID.R;
		}
	} else if (flex_can == FLEXCAN_1) {
		if ((CAN_1.BUF[BufferNo].CS.B.IDE & 0x01) ==0)	{
			/* Standard ID */
			id = CAN_1.BUF[BufferNo].MSG_ID.B.STD_ID;
		} else if ((CAN_1.BUF[BufferNo].CS.B.IDE & 0x01) !=0)	{
			/* Extended ID */
			id = CAN_1.BUF[BufferNo].MSG_ID.R;
		}
	}
	return id;
}

/******************************************************************************
*	Function: flexcan_564xl_get_mb
	@brief      returns message ID.
	@details   returns message ID

	@param[in]     ptr_FLEXCAN_MsgBufferStructure     pointer to structure
	@param[in]     flex_can     FlexCAN module
	@param[in]     BufferNo     BufferNo

	@return  none
*/
void flexcan_564xl_get_mb(FLEXCAN_MsgBufferStructure
    *ptr_FLEXCAN_MsgBufferStructure, uint8_t flex_can, uint8_t BufferNo)	{
    uint8_t i= 0;
    if (flex_can == FLEXCAN_0)	{
    	ptr_FLEXCAN_MsgBufferStructure->length = CAN_0.BUF[BufferNo].CS.B.LENGTH;
    	for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++)	{
    		ptr_FLEXCAN_MsgBufferStructure->data[i] = CAN_0.BUF[BufferNo].DATA.B[i];
    	}
	} else if (flex_can == FLEXCAN_1)	{
		ptr_FLEXCAN_MsgBufferStructure->length = CAN_1.BUF[BufferNo].CS.B.LENGTH;
		for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++)	{
			ptr_FLEXCAN_MsgBufferStructure->data[i] = CAN_1.BUF[BufferNo].DATA.B[i];
		}
	}
}

/******************************************************************************
*	Function: flexcan_564xl_get_idtype
	@brief      returns message ID type.
	@details   returns message ID type

	@param[in]     flex_can     FlexCAN module
	@param[in]     BufferNo     BufferNo

	@return  id type
*/
uint8_t flexcan_564xl_get_idtype(uint8_t flex_can, uint8_t BufferNo)	{
	uint8_t idtype = 0;
	if (flex_can == FLEXCAN_0)	{
		idtype = (uint8_t) CAN_0.BUF[BufferNo].CS.B.IDE;
	} else if (flex_can == FLEXCAN_1)	{
		idtype = (uint8_t) CAN_1.BUF[BufferNo].CS.B.IDE;
	}
	return idtype;
}

/******************************************************************************
*	Function: flexcan_564xl_release_mb_lock
	@brief      release mb lock.
	@details   release mb lock

	@param[in]     flexcan     FlexCAN module

	@return  none
*/
void flexcan_564xl_release_mb_lock(uint8_t flexcan)	{
	vuint32_t dummy;
	if (flexcan == FLEXCAN_0)	{
		dummy = CAN_0.TIMER.R;
	} else if (flexcan == FLEXCAN_1)	{
		dummy = CAN_1.TIMER.R;
	}
}

/******************************************************************************
*	Function: flexcan_564xl_clear_isr_flag
	@brief      clear_isr_flag
	@details   clear_isr_flag

	@param[in]     flex_can     FlexCAN module
	@param[in]     BufferNo     buffer
	@param[in]     IFR_Mask     mask

	@return  none
*/
void flexcan_564xl_clear_isr_flag(uint8_t flex_can, uint8_t BufferNo, uint32_t IFR_Mask)  {
	if (flex_can == FLEXCAN_0)	{
		/* Write 1 to clear */
		CAN_0.IFLAG1.R &= IFR_Mask;
	} else if (flex_can == FLEXCAN_1){
		/* Write 1 to clear */
		CAN_1.IFLAG1.R &= IFR_Mask;
	}
}

/******************************************************************************
*	Function: flexcan_564xl_clear_mask
	@brief      clear mask
	@details   clear mask

	@param[in]     flex_can     FlexCAN module
	@param[in]     mb     mb

	@return  none
*/
void flexcan_564xl_clear_mask(uint8_t flex_can, uint8_t mb)	{
	switch (flex_can)	{
		case FLEXCAN_0:		{
			CAN_0.IFLAG1.R = (0x1U << mb);
			break;
		}

		case FLEXCAN_1:		{
			CAN_1.IFLAG1.R = (0x1U << mb);
			break;
		}
		default:
			break;
	}
}

/******************************************************************************
*	Function: flexcan_564xl_set_filter_id
	@brief      set_filter_id
	@details   set_filter_id

	@param[in]     flex_can     FlexCAN module
	@param[in]     mb			mb
	@param[in]	   id			id
	@param[in]     ext			ext

	@return  none
*/
void flexcan_564xl_set_filter_id(uint8_t flex_can, uint8_t mb, uint32_t id, uint8_t ext)	{
	switch (flex_can)	{
		case FLEXCAN_0:		{
			if (ext)	{
				CAN_0.BUF[mb].CS.B.IDE = 1;    /* MB for extended ID */
				CAN_0.BUF[mb].ID.R = id;       /* MB ID */
			} else {
				CAN_0.BUF[mb].CS.B.IDE = 0;    /* MB for standard ID */
				CAN_0.BUF[mb].ID.B.STD_ID = (uint16_t)id;/* MB ID */
			}

			CAN_0.BUF[mb].CS.B.CODE = CAN_RX_EMPTY;/* Set rx MB empty */
			break;
		}

		case FLEXCAN_1:		{
			if (ext) {
				CAN_1.BUF[mb].CS.B.IDE = 1;    /* MB for extended ID */
				CAN_1.BUF[mb].ID.R = id;       /* MB ID */
			} else {
				CAN_1.BUF[mb].CS.B.IDE = 0;    /* MB for standard ID */
				CAN_1.BUF[mb].ID.B.STD_ID = (uint16_t)id;/* MB ID */
			}

			CAN_1.BUF[mb].CS.B.CODE = CAN_RX_EMPTY;/* Set rx MB empty */
			break;
		default:
			break;
		}
	}
}

/******************************************************************************
*	Function: flexcan_564xl_readytoreceive
	@brief      ready to receive
	@details   ready to receive

	@param[in]     flex_can     FlexCAN module
	@param[in]     BufferNo     buffer

	@return  none
*/
void flexcan_564xl_readytoreceive(uint8_t flex_can, uint8_t BufferNo)	{
	if (flex_can == FLEXCAN_0)	{
		/* MB active and empty */
		CAN_0.BUF[BufferNo].CS.B.CODE = 0x04;
    } else if (flex_can == FLEXCAN_1)	{
    	/* MB active and empty */
    	CAN_1.BUF[BufferNo].CS.B.CODE = 0x04;
	}
}

/******************************************************************************
*	Function: flexcan_564xl_get_ts
	@brief      get  timestamp
	@details   get  timestamp

	@param[in]     flex_can     FlexCAN module
	@param[in]     BufferNo     buffer

	@return  none
*/
uint16_t flexcan_564xl_get_ts(uint8_t flex_can, uint8_t BufferNo)	{
	uint16_t ts = 0U;
	if (flex_can == FLEXCAN_0)	{
		ts = CAN_0.BUF[BufferNo].MSG_CS.B.TIMESTAMP;
	} else if (flex_can == FLEXCAN_1)	{
		ts = CAN_1.BUF[BufferNo].MSG_CS.B.TIMESTAMP;
	}

    return ts;
}

#ifdef __cplusplus

}
#endif

/*
 *######################################################################
 *                           End of File
 *######################################################################
 */
