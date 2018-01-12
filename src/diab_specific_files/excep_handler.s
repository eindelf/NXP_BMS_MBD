 
 
;#
;# Assumes IVPR contains address of teh section mwvects
;# STACK FRAME DESIGN: Depth: 20 words (0x50, or 80 bytes)

;#            ************* ______________
;#   0x4C     *  GPR12    *    ^
;#   0x48     *  GPR11    *    |
;#   0x44     *  GPR10    *  GPRs (32 bit)
;#   0x40     *  GPR9     *    |
;#   0x3C     *  GPR8     *    |
;#   0x38     *  GPR7     *    |
;#   0x34     *  GPR6     *    |
;#   0x30     *  GPR5     *    |
;#   0x2C     *  GPR4     *    |
;#   0x28     *  GPR3     *    |
;#   0x24     *  GPR0     * ___v__________
;#   0x20     *  CR       * __CR__________
;#   0x1C     *  XER      *    ^
;#   0x18     *  CTR      *    |
;#   0x14     *  LR       * locals & padding for 16 B alignment
;#   0x10     *  CSRR1    *    |
;#   0x0C     *  CSRR0    *    |
;#   0x08     *  padding  * ___v__________
;#   0x04     * resvd- LR * Reserved for calling function
;#   0x00     *  SP       * Backchain (same as gpr1 in GPRs)
;#            *************
;#
;#  To ensure the servicing is recognized the EISR.NMI (Z4) must be set to clear the request.
;#
    .global IVOR0Handler
    .global IVOR1Handler
    .global IVOR2Handler
    .global IVOR3Handler
    .global IVOR4Handler
    .global IVOR5Handler
    .global IVOR6Handler
    .global IVOR7Handler
    .global IVOR8Handler
    .global IVOR9Handler
    .global IVOR10Handler
    .global IVOR11Handler
    .global IVOR12Handler
    .global IVOR13Handler
    .global IVOR14Handler
    .global IVOR15Handler
    .global IVOR32Handler
    .global IVOR33Handler
    .global IVOR34Handler
    .global IVORxHandlers
;# Ensure access to the C Interrupt Service Routine for Handlers
    .global default_except_handler
    .globl  e200zX_Interrupt_Setup

.ifdef __vle

  .section .exec_vect_vle
  .align 4
IVORxHandlers: 

. = IVORxHandlers +0x1200
IVOR0_address:
     e_b               IVOR0Handler          ;#Critical Input 

. = IVORxHandlers +0x1210
IVOR1_address:
     e_b               IVOR1Handler          ;#Machine Check 

. = IVORxHandlers +0x1220
IVOR2_address:
     e_b               IVOR2Handler          ;#Data Storage

. = IVORxHandlers +0x1230
IVOR3_address:
     e_b               IVOR3Handler          ;#Instruction Storage 

. = IVORxHandlers +0x1240
IVOR4_address:
     e_b               IVOR4Handler          ;#External Input 

. = IVORxHandlers +0x1250
IVOR5_address:
     e_b               IVOR5Handler          ;#Alignment 

. = IVORxHandlers +0x1260
IVOR6_address:
     e_b               IVOR6Handler          ;#Program 

. = IVORxHandlers +0x1270
IVOR7_address:
     e_b               IVOR7Handler          ;#Floating point unavailable

. = IVORxHandlers +0x1280
IVOR8_address:
     e_b               IVOR8Handler          ;#System call 

. = IVORxHandlers +0x1290
IVOR9_address:
     e_b               IVOR9Handler          ;#AP unavailable 

. = IVORxHandlers +0x12a0
IVOR10_address:
     e_b               IVOR10Handler          ;#Decrementer 

. = IVORxHandlers +0x12b0
IVOR11_address:
     e_b               IVOR11Handler          ;#Fixed Interval Timer

. = IVORxHandlers +0x12c0
IVOR12_address:
     e_b               IVOR12Handler          ;#Watchdog Timer 

. = IVORxHandlers +0x12d0
IVOR13_address:
     e_b               IVOR13Handler          ;#Data TLB Error 

. = IVORxHandlers +0x12e0
IVOR14_address:
     e_b               IVOR14Handler          ;#Instruction TLB Error 

. = IVORxHandlers +0x12f0
IVOR15_address:
     e_b               IVOR15Handler          ;#Debug 

. = IVORxHandlers +0x1410
IVOR32_address:
     e_b               IVOR32Handler          ;#SPE_EFP Unavailable exception 

. = IVORxHandlers +0x1420
IVOR33_address:
     e_b               IVOR33Handler          ;#EFPU data exception 

. = IVORxHandlers +0x1430
IVOR34_address:
     e_b               IVOR34Handler          ;#EFPU round exception 

   .section .text_vle
   .align 4

IVOR0Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR1Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR2Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR3Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR5Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR6Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR7Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR8Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR9Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR10Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR11Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR12Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR13Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR14Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR15Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR32Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR33Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

IVOR34Handler:  

;# PROLOGUE
     e_stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     e_add16i r1,r1,0x50     ;# Delete stack frame
     se_rfi ;# Return 

.else


  .section .exec_vect
IVORxHandlersZ4_0: 

. = IVORxHandlersZ4_0 +0x1200
IVOR0_address:
     b               IVOR0HandlerZ4_0          ;#Critical Input 

. = IVORxHandlersZ4_0 +0x1210
IVOR1_address:
     b               IVOR1HandlerZ4_0          ;#Machine Check 

. = IVORxHandlersZ4_0 +0x1220
IVOR2_address:
     b               IVOR2HandlerZ4_0          ;#Data Storage

. = IVORxHandlersZ4_0 +0x1230
IVOR3_address:
     b               IVOR3HandlerZ4_0          ;#Instruction Storage 

. = IVORxHandlersZ4_0 +0x1240
IVOR4_address:
     b               IVOR4HandlerZ4_0          ;#External Input 

. = IVORxHandlersZ4_0 +0x1250
IVOR5_address:
     b               IVOR5HandlerZ4_0          ;#Alignment 

. = IVORxHandlersZ4_0 +0x1260
IVOR6_address:
     b               IVOR6HandlerZ4_0          ;#Program 

. = IVORxHandlersZ4_0 +0x1270
IVOR7_address:
     b               IVOR7HandlerZ4_0          ;#Floating point unavailable

. = IVORxHandlersZ4_0 +0x1280
IVOR8_address:
     b               IVOR8HandlerZ4_0          ;#System call 

. = IVORxHandlersZ4_0 +0x1290
IVOR9_address:
     b               IVOR9HandlerZ4_0          ;#AP unavailable 

. = IVORxHandlersZ4_0 +0x12a0
IVOR10_address:
     b               IVOR10HandlerZ4_0          ;#Decrementer 

. = IVORxHandlersZ4_0 +0x12b0
IVOR11_address:
     b               IVOR11HandlerZ4_0          ;#Fixed Interval Timer

. = IVORxHandlersZ4_0 +0x12c0
IVOR12_address:
     b               IVOR12HandlerZ4_0          ;#Watchdog Timer 

. = IVORxHandlersZ4_0 +0x12d0
IVOR13_address:
     b               IVOR13HandlerZ4_0          ;#Data TLB Error 

. = IVORxHandlersZ4_0 +0x12e0
IVOR14_address:
     b               IVOR14HandlerZ4_0          ;#Instruction TLB Error 

. = IVORxHandlersZ4_0 +0x12f0
IVOR15_address:
     b               IVOR15HandlerZ4_0          ;#Debug 

. = IVORxHandlersZ4_0 +0x1410
IVOR32_address:
     b               IVOR32HandlerZ4_0          ;#SPE_EFP Unavailable exception 

. = IVORxHandlersZ4_0 +0x1420
IVOR33_address:
     b               IVOR33HandlerZ4_0          ;#EFPU data exception 

. = IVORxHandlersZ4_0 +0x1430
IVOR34_address:
     b               IVOR34HandlerZ4_0          ;#EFPU round exception 

  .section .text
  .align 4
IVOR0HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR1HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR2HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR3HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR5HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR6HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR7HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR8HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR9HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR10HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR11HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR12HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR13HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR14HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR15HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR32HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR33HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

IVOR34HandlerZ4_0:  

;# PROLOGUE
     stwu   r1,  -0x50(r1)     ;# Create stack frame and store back chain (4 * 20) = 0x50

     addi r1,r1,0x50     ;# Delete stack frame
     rfi ;# Return 

.endif



default_except_handler:     

;#=================================================
;#  Function to Setup the Core Interrupt Registers
;#=================================================              
e200zX_Interrupt_Setup:
      e_lis       r3,  IVORxHandlers@h
      e_or2i   r3,  IVORxHandlers@l
      mtivpr   r3        ;# move to Interrupt vector table address to IVPR register
      
      e_lis       r3,  IVOR0_address@h
      e_or2i   r3,  IVOR0_address@l
      mtspr 400,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR1_address@h
      e_or2i   r3,  IVOR1_address@l
      mtspr 401,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR2_address@h
      e_or2i   r3,  IVOR2_address@l
      mtspr 402,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR3_address@h
      e_or2i   r3,  IVOR3_address@l
      mtspr 403,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR4_address@h
      e_or2i   r3,  IVOR4_address@l
      mtspr 404,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR5_address@h
      e_or2i   r3,  IVOR5_address@l
      mtspr 405,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR6_address@h
      e_or2i   r3,  IVOR6_address@l
      mtspr 406,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR7_address@h
      e_or2i   r3,  IVOR7_address@l
      mtspr 407,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR8_address@h
      e_or2i   r3,  IVOR8_address@l
      mtspr 408,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR9_address@h
      e_or2i   r3,  IVOR9_address@l
      mtspr 409,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR10_address@h
      e_or2i   r3,  IVOR10_address@l
      mtspr 410,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR11_address@h
      e_or2i   r3,  IVOR11_address@l
      mtspr 411,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR12_address@h
      e_or2i   r3,  IVOR12_address@l
      mtspr 412,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR13_address@h
      e_or2i   r3,  IVOR13_address@l
      mtspr 413,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR14_address@h
      e_or2i   r3,  IVOR14_address@l
      mtspr 414,r3        ;# move IVOR offset to SPRs

      e_lis       r3,  IVOR15_address@h
      e_or2i   r3,  IVOR15_address@l
      mtspr 415,r3        ;# move IVOR offset to SPRs
	  
	   e_lis       r3,  IVOR32_address@h
      e_or2i   r3,  IVOR32_address@l
      mtspr 528,r3        ;# move IVOR offset to SPRs
	  
	   e_lis       r3,  IVOR33_address@h
      e_or2i   r3,  IVOR33_address@l
      mtspr 529,r3        ;# move IVOR offset to SPRs
	  
	   e_lis       r3,  IVOR34_address@h
      e_or2i   r3,  IVOR34_address@l
      mtspr 530,r3        ;# move IVOR offset to SPRs
      
      se_blr
