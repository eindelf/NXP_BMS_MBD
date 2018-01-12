;#**********************************************************************************************
;#* FILE NAME:                                                    COPYRIGHT (c) Freescale 2011 *
;#* sw_handlers.s                                                          All Rights Reserved *
;#* DESCRIPTION:                                                                               *
;#* This file creates prolog, epilog for C ISR and enables nested interrupts. This file starts *
;#* in memory designated by the label "IVOR4Handler".                                          *
;#=============================================================================================*

;# STACK FRAME DESIGN: Depth: 34 words (0x88 or 136 bytes)
;#            ************* ______________
;#   0x80     *  ACC      *    ^
;#   0x78     *  GPR12    *    |
;#   0x70     *  GPR11    *    |
;#   0x68     *  GPR10    *    |
;#   0x60     *  GPR9     *    |
;#   0x58     *  GPR8     *    |
;#   0x50     *  GPR7     *  GPRs (64 bit)
;#   0x48     *  GPR6     *    |
;#   0x40     *  GPR5     *    |
;#   0x38     *  GPR4     *    |
;#   0x30     *  GPR3     *    |
;#   0x28     *  GPR0     * ___v__________
;#   0x24     *  padding  *
;#   0x20     *  CR       * __CR__________
;#   0x1C     *  XER      *    ^
;#   0x18     *  CTR      *    |
;#   0x14     *  LR       * locals & padding for 16 B alignment
;#   0x10     *  SRR1     *    |
;#   0x0C     *  SRR0     *    |
;#   0x08     *  padding  * ___v__________
;#   0x04     * resvd- LR * Reserved for calling function 
;#   0x00     *  SP       * Backchain (same as gpr1 in GPRs)
;#            ************* 

.ifdef __vle
  .section .text_vle
  .align 4
.else
  .section .text
  .align 4
.endif 

  .globl IVOR4Handler
  .equ INTC_IACKR_PRC0, 0xfff48010 ;#Interrupt Acknowledge Register address
  .equ INTC_EOIR_PRC0,  0xfff48018 ;#End Of Interrupt Register address
  .equ MSR_Mask, 0x02000000        ;#MSR[SPE] enable  


IVOR4Handler:
.ifdef __vle

prolog:
                      ;# PROLOGUE
 e_stw     r3,  -0x58 (r1)     ;# Temporary store a working 32-register
 e_subi    r3, r1, 0x88        ;# Create stack frame and store back chain
 e_stw     r1, 0x0 (r3)
 e_subi    r1, r1, 0x88
 
 mfsrr0    r3                  ;# Store SRR0:1 (must be done before enabling EE)
 e_stw     r3,  0x0C (r1)
 mfsrr1    r3                  
 se_stw    r3,  0x10 (r1)
 e_lis     r3, INTC_IACKR_PRC0@h      ;# Read pointer into ISR Vector Table & store in r3
 e_or2i    r3, INTC_IACKR_PRC0@l
 e_lwz     r3,  0x0  (r3)      ;# Read ISR address from ISR Vector Table using pointer
 e_lwz     r3,  0x0  (r3)
 wrteei    1                   ;# Set MSR[EE]=1 (must wait a couple clocks after reading IACKR)
 se_stw    r4,  0x38 (r1)      ;# Temporary store a second working 32-register
 se_mflr   r4                  ;# Store LR (LR will be used for ISR Vector)
 se_stw    r4,  0x14 (r1)
 se_mtlr   r3                  ;# Store ISR address to LR to use for branching later

 e_li      r3, 0               ;# Set MSR[SPE]
 mfmsr     r3                     
 e_lis     r4, MSR_Mask@h
 e_or2i    r4, MSR_Mask@l                                                                
 se_or     r3, r4 
 mtmsr     r3                    
 
 se_lwz    r4,  0x38 (r1)      ;# Restore working 32-registers
 se_lwz    r3,  0x30 (r1)      

 evstdd    r12, 0x78 (r1)      ;# Store 64-gprs
 evstdd    r11, 0x70 (r1)
 evstdd    r10, 0x68 (r1)
 evstdd    r9,  0x60 (r1)
 evstdd    r8,  0x58 (r1)
 evstdd    r7,  0x50 (r1)
 evstdd    r6,  0x48 (r1)
 evstdd    r5,  0x40 (r1)
 evstdd    r4,  0x38 (r1) 
 evstdd    r3,  0x30 (r1) 
 evstdd    r0,  0x28 (r1)    
 
 mfcr      r3                  ;# Store CR
 se_stw    r3,  0x20 (r1)
 mfxer     r3                  ;# Store XER
 se_stw    r3,  0x1C (r1)
 se_mfctr  r3                  ;# Store CTR
 se_stw    r3,  0x18 (r1)                                   
 
 evxor     r3, r3, r3          ;# store SPE accumulator
 evmwumiaa r3, r3, r3
 e_stw     r3, 0x80 (r1)      

 se_blrl                       ;# Branch to ISR, but return here

epilog:  
                      ;# EPILOGUE
 se_lwz    r3,  0x14 (r1)      ;# Restore LR
 se_mtlr   r3
 se_lwz    r3,  0x18 (r1)      ;# Restore CTR
 se_mtctr  r3
 se_lwz    r3,  0x1C (r1)      ;# Restore XER
 mtxer     r3
 se_lwz    r3,  0x20 (r1)      ;# Restore CR
 mtcrf     0xFF, r3

 e_lwz     r3,  0x80 (r1)      ;# Restore SPE accumulator
 evmra     r4, r3              
 
 evldd     r0,  0x28 (r1)      ;# Restore 64-gprs except working registers
 evldd     r5,  0x40 (r1)
 evldd     r6,  0x48 (r1)
 evldd     r7,  0x50 (r1)
 evldd     r8,  0x58 (r1)
 evldd     r9,  0x60 (r1)
 evldd     r10, 0x68 (r1)
 evldd     r11, 0x70 (r1)
 evldd     r12, 0x78 (r1)
 
 mbar      0                   ;# Ensure store to clear interrupt's flag bit has completed
 e_lis     r3, INTC_EOIR_PRC0@h       ;# Load upper half of EIOR address to r3
 e_li      r4, 0       
 wrteei    0                   ;# Disable interrupts for rest of handler
 e_or2i    r3, INTC_EOIR_PRC0@l
 e_stw     r4,  0x0 (r3)       ;# Write 0 to INTC_EOIR_PRC0 
 e_lwz     r3, 0x0C (r1)       ;# Restore SRR0
 mtsrr0    r3
 e_lwz     r3, 0x10 (r1)       ;# Restore SRR1
 mtsrr1    r3
 
 evldd     r4,  0x38 (r1)      ;# Restore 64-working registers
 evldd     r3,  0x30 (r1)      
 e_add16i  r1, r1, 0x88        ;# Delete stack frame
 se_rfi                        ;# End of Interrupt

.else

prolog:
                      ;# PROLOGUE
 stw       r3, -0x58 (r1)      ;# Temporary store a working 32-register
 subi      r3, r1, 0x88        ;# Create stack frame and store back chain
 stw       r1, 0x0 (r3)
 subi      r1, r1, 0x88
 
 mfsrr0    r3                  ;# Store SRR0:1 (must be done before enabling EE)
 stw       r3,  0x0C (r1)
 mfsrr1    r3                  
 stw       r3,  0x10 (r1)
 lis       r3, INTC_IACKR_PRC0@ha     ;# Read pointer into ISR Vector Table
 lwz       r3, INTC_IACKR_PRC0@l(r3)  ;# Store pointer into r3
 lwz       r3, 0x0(r3)         ;# Read ISR address from ISR Vector Table using pointer
 wrteei    1                   ;# Set MSR[EE]=1 (must wait a couple clocks after reading IACKR)
 stw       r4,  0x38 (r1)      ;# Temporary store a second working 32-register
 mflr      r4                  ;# Store LR (LR will be used for ISR Vector)
 stw       r4,  0x14 (r1)
 mtlr      r3                  ;# Store ISR address to LR to use for branching later

 li        r3, 0               ;# Set MSR[SPE]
 mfmsr     r3                     
 lis       r4, MSR_Mask@h
 ori       r4, MSR_Mask@l                                                                
 or        r3, r4 
 mtmsr     r3                    
 
 lwz       r4,  0x38 (r1)      ;# Restore working 32-registers
 lwz       r3,  0x30 (r1)      

 evstdd    r12, 0x78 (r1)      ;# Store 64-gprs
 evstdd    r11, 0x70 (r1)
 evstdd    r10, 0x68 (r1)
 evstdd    r9,  0x60 (r1)
 evstdd    r8,  0x58 (r1)
 evstdd    r7,  0x50 (r1)
 evstdd    r6,  0x48 (r1)
 evstdd    r5,  0x40 (r1)
 evstdd    r4,  0x38 (r1) 
 evstdd    r3,  0x30 (r1) 
 evstdd    r0,  0x28 (r1)    

 mfcr      r3                  ;# Store CR
 stw       r3,  0x20 (r1)
 mfxer     r3                  ;# Store XER
 stw       r3,  0x1C (r1)
 mfctr     r3                  ;# Store CTR
 stw       r3,  0x18 (r1)
 
 evxor     r3, r3, r3          ;# store SPE accumulator
 evmwumiaa r3, r3, r3
 stw       r3, 0x80 (r1)      

 blrl                          ;# Branch to ISR, but return here

epilog:
                      ;# EPILOGUE
 lwz       r3,  0x14 (r1)      ;# Restore LR
 mtlr      r3
 lwz       r3,  0x18 (r1)      ;# Restore CTR
 mtctr     r3
 lwz       r3,  0x1C (r1)      ;# Restore XER
 mtxer     r3
 lwz       r3,  0x20 (r1)      ;# Restore CR
 mtcrf     0xff, r3
 
 e_lwz     r3,  0x80 (r1)      ;# Restore SPE accumulator
 evmra     r4, r3              
 
 evldd     r0,  0x28 (r1)      ;# Restore 64-gprs except working registers
 evldd     r5,  0x40 (r1)
 evldd     r6,  0x48 (r1)
 evldd     r7,  0x50 (r1)
 evldd     r8,  0x58 (r1)
 evldd     r9,  0x60 (r1)
 evldd     r10, 0x68 (r1)
 evldd     r11, 0x70 (r1)
 evldd     r12, 0x78 (r1)
 
 mbar      0                          ;# Ensure store to clear interrupt's flag bit completed
 lis       r3, INTC_EOIR_PRC0@ha      ;# Load upper half of EOIR address to r3
 li        r4, 0      
 wrteei    0                   ;# Disable interrupts for rest of handler
 stw       r4, INTC_EOIR_PRC0@l(r3)   ;# Write 0 to INTC_EOIR_PRC0
 lwz       r3,  0x0C (r1)      ;# Restore SRR0
 mtsrr0    r3
 lwz       r3,  0x10 (r1)      ;# Restore SRR1
 mtsrr1    r3
 
 evldd     r4,  0x38 (r1)      ;# Restore 64-working registers
 evldd     r3,  0x30 (r1)      
 addi      r1, r1, 0x88        ;# Delete stack frame
 rfi                           ;# End of Interrupt

.endif


