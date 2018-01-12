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
    .extern   main

    .extern __DATA_ROM                 
    .extern __DATA_RAM                 
    .extern __DATA_END                 
    .extern __BSS_START                 
    .extern __BSS_END                 
    .extern __DATA_SIZE                 
    .extern __BSSDATA_SIZE 
	
	.section .rcw
	.LONG 0x015A015A
	.LONG _start

 .ifdef __vle
    .section .text_vle
    .align   2             

    e_add2i.   r0,0         # Debuggers may object to starting at 0.             
       
	_start:
        .include "initialize_gpr.s"
        .include "crt0_include.s"
		.include "optimise.s"
		
		e_lis      r1, __SP_INIT@h	; Initialize stack pointer r1 to             
		e_or2i     r1, __SP_INIT@l  	; value in linker command file.              
		e_lis      r13, _SDA_BASE_@h	; Initialize r13 to sdata base             
		e_or2i     r13, _SDA_BASE_@l	;              

		e_lis      r2, _SDA2_BASE_@h	; Initialize r2 to sdata2 base              
		e_or2i     r2, _SDA2_BASE_@l	; (provided by linker).             
		e_addi     r0,r0,0              ; Clear r0.             
		e_stwu     r1,-64(r1)           ; Terminate stack.             
	
 .else
    addi           r0,r0,0      ; Debuggers may object to starting at 0.             
    .section .text
    .align 2

	_start:           
        .include "initialize_gpr.s"              
        .include "crt0_include.s"              
	 
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
		.include "romcopy.s"

		e_bl	main				; Finish initialization; call main().             
        ;e_b    exit					; Never returns.             
   .else              
        .include "romcopy.s"

        bl		main				; Finish initialization; call main().             
        ;b      exit					; Never returns.             
   .endif              
;------------------------------------------------------------------------------
;                           	End of File                        
;------------------------------------------------------------------------------
