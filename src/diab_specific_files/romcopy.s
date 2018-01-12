;##--------- Load Initialised Data Values from Flash into RAM ----------------
;##--------- Initialised Data - ".data" & Small Initialised Data - ".sdata"---------

.ifdef __vle
;;.section .text_vle
;;.align 2

romcopy:
    e_lis       r6, __DATA_ROM@h  	;# Load address of __DATA_ROM into R6(from linker file)
    e_or2i      r6, __DATA_ROM@l  	;# Load lower address of __DATA_ROM into R6(from linker file)
    e_subi      r6,r6, 1          	;# Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __DATA_RAM@h  	;# Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __DATA_RAM@l  	;# Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1         	;# Decrement address to prepare for ROMCPYLOOP

	se_cmpl		r6, r5				;# compare data_rom address with data_ram address
    e_beq       BSSDATACOPY         ;# Exit cfg_ROMCPY if __DATA_ROM address equal to 
    								;# __DATA_RAM (no data to initialise)	

    e_lis       r9, __DATA_SIZE@h    ;# Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __DATA_SIZE@l    ;# Load lower SRAM load sizeSRAM load size into R9
    e_cmp16i    r9,0                 ;# Compare to see if equal to 0
    e_beq       BSSDATACOPY          ;# Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                   ;# Store no. of bytes to be moved in counter

DATACPYLOOP:
    e_lbzu      r4, 1(r6)            ;# Load data byte at R6 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)            ;# Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      DATACPYLOOP          ;# Branch if more bytes to load from ROM


;##--------- Uninitialised Data to zero - ".bss" --------------------------------------

BSSDATACOPY:
    e_lis       r6, __BSS_START@h 	;# Load address of first __BSS_START load into R10
    e_or2i      r6, __BSS_START@l 	;# Load lower address of __BSS_START load into R10
    e_subi      r6,r6, 1            ;# Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __BSS_END@h 	;# Load upper __BSS_END address into R5 (from linker file)
    e_or2i      r5, __BSS_END@l 	;# Load lower __BSS_END address into R5 (from linker file)
    e_subi      r5, r5, 1           ;# Decrement address to prepare for ROMCPYLOOP

    se_cmp      r6,r5                ;# Compare to see if both address are equal
    e_beq       ROMCPYEND            ;# Exit cfg_ROMCPY if size is zero (no data to initialise)

    e_lis       r9, __BSSDATA_SIZE@h  ;# Load upper BSS load size (# of bytes) into R9
    e_or2i      r9, __BSSDATA_SIZE@l  ;# Load lower BSS load size into R9
    e_cmp16i    r9,0                  ;# Compare to see if equal to 0
    e_beq       ROMCPYEND             ;# Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                    ;# Store no. of bytes to be moved in counter

BSSDATACPYLOOP:
    se_li	r4, 0
    e_stbu   r4, 1 (r6)
    e_bdnz      BSSDATACPYLOOP         ;# Branch if more bytes to load from ROM


ROMCPYEND:


.else                 
;;    .section .text
;;    .align 2

romcopy:
    lis       r6, __DATA_ROM@h  	;# Load address of __DATA_ROM into R6(from linker file)
    ori       r6,r6, __DATA_ROM@l  	;# Load lower address of __DATA_ROM into R6(from linker file)
    subi      r6,r6, 1              ;# Decrement address to prepare for ROMCPYLOOP

    lis       r5, __DATA_RAM@h  	;# Load upper SRAM address into R5 (from linker file)
    ori       r5,r5, __DATA_RAM@l  	;# Load lower SRAM address into R5 (from linker file)
    subi      r5, r5, 1             ;# Decrement address to prepare for ROMCPYLOOP

	cmpl		r6, r5				;# compare data_rom address with data_ram address
    beq       BSSDATACOPY           ;# Exit cfg_ROMCPY if __DATA_ROM address equal to 
    								;# __DATA_RAM (no data to initialise)	

    lis       r9, __DATA_SIZE@h     ;# Load upper SRAM load size (# of bytes) into R9
    ori       r9,r9, __DATA_SIZE@l  ;# Load lower SRAM load sizeSRAM load size into R9
    cmpi      r9,0                  ;# Compare to see if equal to 0
    beq       BSSDATACOPY           ;# Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                  ;# Store no. of bytes to be moved in counter

DATACPYLOOP:
    lbzu      r4, 1(r6)             ;# Load data byte at R6 into R4,incrementing (update) ROM address
    stbu      r4, 1(r5)             ;# Store R4 data byte into SRAM at R5 and update SRAM address
    bdnz      DATACPYLOOP           ;# Branch if more bytes to load from ROM


;##--------- Uninitialised Data to zero - ".bss" --------------------------------------

BSSDATACOPY:
    lis       r6, __BSS_START@h 	;# Load address of first __BSS_START load into R10
    ori       r6,r6, __BSS_START@l 	;# Load lower address of __BSS_START load into R10
    subi      r6,r6, 1              ;# Decrement address to prepare for ROMCPYLOOP

    lis       r5, __BSS_END@h 		;# Load upper __BSS_END address into R5 (from linker file)
    ori       r5,r5, __BSS_END@l 	;# Load lower __BSS_END address into R5 (from linker file)
    subi      r5, r5, 1             ;# Decrement address to prepare for ROMCPYLOOP

    cmp       r6,r5                 ;# Compare to see if both address are equal
    beq       ROMCPYEND             ;# Exit cfg_ROMCPY if size is zero (no data to initialise)

    lis      r9, __BSSDATA_SIZE@h  	;# Load upper BSS load size (# of bytes) into R9
    ori      r9,r9, __BSSDATA_SIZE@l	;# Load lower BSS load size into R9
    cmpi     r9,0                    ;# Compare to see if equal to 0
    beq       ROMCPYEND              ;# Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                   ;# Store no. of bytes to be moved in counter

BSSDATACPYLOOP:
    li	   r4, 0
    stbu   r4, 1 (r6)
    bdnz      BSSDATACPYLOOP         ;# Branch if more bytes to load from ROM

ROMCPYEND:


.endif   
  		
;##---------------------------------------------------------------------------
