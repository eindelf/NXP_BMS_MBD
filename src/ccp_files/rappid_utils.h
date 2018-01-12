/********************  Dependent Include files here **********************/
#ifndef _RAPPID_UTIL_H
#define _RAPPID_UTIL_H

#include "typedefs.h"

#define SIZE_32BITS 4
#define SIZE_16BITS 2
#define SIZE_8BITS 1


extern void IVOR4Handler(void);

/**********************  Function Prototype here *************************/
extern void EnableExternalInterrupts (void);
extern void DisableExternalInterrupts (void);
extern void fs_clearmem(vuint8_t* address , uint16_t size, uint8_t fillbyte);
extern void MC_Cleanup (void);

#endif /* _RAPPID_UTIL_H */
