/***************************************************************************************************
* SF Motors Confidential – Copyright [2017], all rights reserved.
* Author: shawn.yuan@sfmotors.com
* Date: 2017-06-29
* Description: CTU header.
***************************************************************************************************/

#ifndef CTU_H_
#define CTU_H_

extern void CTU_init(void);
extern void CTU_adc_ISR(void);
extern void CTU_trigger0_ISR(void);
extern void CTU_fifo0_ISR(void);

#endif /* CTU_H_ */
