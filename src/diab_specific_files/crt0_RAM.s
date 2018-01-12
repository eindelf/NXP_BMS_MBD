    ;*************************************************************************/              
    ; FILE NAME: ctr0.s                    COPYRIGHT (c) Freescale 2011   */              
    ;                                                All Rights Reserved     */             
    ; This initializes stack pointer, SDA_BASE and SDA2_BASE register        */             
    ;                                                             			 */
    ;*************************************************************************/             
 
    .globl    _start  
    .extern   __SP_INIT
    .extern   _SDA_BASE_
    .extern   _SDA2_BASE_  
	.extern   __BSS_START
	.extern   __BSS_END
	.extern   __BSS_SIZE
    .extern   main

 .ifdef __vle
    e_add2i.   r0,0         # Debuggers may object to starting at 0.             
    .section .text_vle
    .align   2             

       
	_start:
        .include "initialize_gpr.s"
        .include "crt0_include.inc"
		
;--------------ICACHE configuration -----------------------------

.cfg_ICACHE_nVLE:

    ;--------------------------------------------;
    ; Invalidate Instruction Cache - Set ICINV   ;
    ; bit in L1CSR1 Register
    ;--------------------------------------------;
    lis   r5, 0x0000
    ori   r5,r5, 0x0002
    mtspr l1csr1,r5

    ;--------------------------------------------;
    ; Mask out ICINV and ICABT to see if         ;
    ; invalidation is complete (i.e. ICINV=0,    ;
    ; ICABT=0)                                   ;
    ;--------------------------------------------;
.label_ICINV_check_nVLE:
    ;--------------------------------------------;
    ; Load Registers with Masks:                 ;
    ; Load ICINV mask into R4                    ;
    ; Load ICABT mask into R6                    ;
    ; Load ICABT clear mask into R7              ;
    ;--------------------------------------------;
    lis   r4, 0x0000
    ori   r4,r4, 0x0002
    lis   r6, 0x0000
    ori   r6,r6, 0x0004
    lis   r7, 0xFFFF
    ori   r7,r7, 0xFFFB
    ;--------------------------------------------;

.CHECK_ICINV_nVLE:

    ;--------------------------------------------;
    ; Read L1CSR1 register, store in r3          ;
    ;--------------------------------------------;
    mfspr r3, l1csr1
    ;--------------------------------------------;
    ; check for an ABORT of the cache invalidate ;
    ; operation
    ;--------------------------------------------;
    and. r6,r6, r3
    beq   .NO_IABORT_nVLE
    ;--------------------------------------------;
    ; If abort detected, clear ICABT bit and     ;
    ; re-run invalidation
    ;--------------------------------------------;
    and. r7,r7, r3
    mtspr   l1csr1, r10
    b    .cfg_ICACHE_nVLE

.NO_IABORT_nVLE:

    ;--------------------------------------------;
    ; Check that invalidation has completed -    ;
    ; (ICINV=0). Branch if invalidation not      ;
    ; complete.
    ;--------------------------------------------;
    and. r4,r4, r3
    bne   .CHECK_ICINV_nVLE

    ;--------------------------------------------;
    ; Enable cache the ICache by performing a    ;
    ; read/modify/write of the ICE bit in the    ;
    ; L1CSR1 register
    ;--------------------------------------------;
    mfspr r5, l1csr1
    oris  r5,r5,0x0000
    ori   r5,r5,0x0001      ; Store L1CSR1 value to R5 (ICE=1)
    isync
    msync
    mtspr l1csr1, r5    ; Write R5 to L1CSR1 register
;-----------------------------------------------------------------

		
		e_lis      r1, __SP_INIT@h	; Initialize stack pointer r1 to             
		e_or2i     r1, __SP_INIT@l  	; value in linker command file.              
		e_lis      r13, _SDA_BASE_@h	; Initialize r13 to sdata base             
		e_or2i     r13, _SDA_BASE_@l	;              

		e_lis      r2, _SDA2_BASE_@h	; Initialize r2 to sdata2 base              
		e_or2i     r2, _SDA2_BASE_@l	; (provided by linker).             
		e_addi     r0,r0,0              ; Clear r0.             
		e_stwu     r1,-64(r1)           ; Terminate stack.             
    
;#--------- Initialize BSS section ------------------------------------------

bss_Init:
    e_lis        r9, __BSS_SIZE@h       ; Load upper BSS load size (# of bytes) into R9
    e_or2i       r9, __BSS_SIZE@l       ; Load lower BSS load size into R9 and compare to zero
    e_cmp16i     r9,0   
    e_beq        bss_Init_end           ; Exit if size is zero (no data to initialise)     

    mtctr        r9                     ; Store no. of bytes to be moved in counter

    e_lis        r5, __BSS_START@h      ; Load upper BSS address into R5 (from linker file) 
    e_or2i       r5,  __BSS_START@l     ; Load lower BSS address into R5 (from linker file)
    e_subi       r5, r5, 1              ; Decrement address to prepare for bss_Init_loop

    e_lis        r4, 0x0 

bss_Init_loop:
    e_stbu       r4, 1(r5)              ; Store zero byte into BSS at R5 and update BSS address 
    e_bdnz       bss_Init_loop          ; Branch if more bytes to load
	
bss_Init_end:

;----------------------------------------------------------------------------	
	
 .else
    addi           r0,r0,0      ; Debuggers may object to starting at 0.             
    .section .text
    .align 2

	_start:           
        .include "initialize_gpr.s"
        .include "crt0_include.inc"
	 
		lis      r1, __SP_INIT_z4_0@h		; Initialize stack pointer r1 to             
		ori      r1, r1, __SP_INIT_z4_0@l	; value in linker command file.              
		lis      r13, _SDA_BASE_@h		; Initialize r13 to sdata base             
		ori      r13, r13, _SDA_BASE_@l	;                

		lis      r2, _SDA2_BASE_@h     	; Initialize r2 to sdata2 base              
		ori      r2, r2, _SDA2_BASE_@l 	; (provided by linker).             
		addi     r0,r0,0               	; Clear r0.             
		stwu     r1,-64(r1)            	; Terminate stack.             

 .endif              

;------------------------------------------------------------------------------            
; Start of code              

    .ifdef __vle            


		e_bl	main				; Finish initialization; call main().             
        ;e_b    exit					; Never returns.             
   .else              


        bl		main				; Finish initialization; call main().             
        ;b      exit					; Never returns.             
   .endif              
;------------------------------------------------------------------------------
;                           	End of File                        
;------------------------------------------------------------------------------
