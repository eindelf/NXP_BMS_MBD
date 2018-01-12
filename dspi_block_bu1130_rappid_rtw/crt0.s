#**************************************************************************/
#* FILE NAME: ctr0_VLE_Flash.s             COPYRIGHT (c) Freescale 2008   */
#*                                                All Rights Reserved     */
#* DESCRIPTION:                                                           */
#* This is a generic base template for init of a VLE Flash Project        */
#=========================================================================*/
#*                                                                        */
#*========================================================================*/
#* REV      AUTHOR        DATE        DESCRIPTION OF CHANGE               */
#* ---   -----------    ----------    ---------------------               */
#* 0.3    S. OBrien      02/26/2010    Updated for BookE
#* 0.2    M.Ruthenbeck   12/03/2009    Updated for Leopard Lock Step Mode */
#* 0.1    R. Moran       10/12/2008    Initial Version                    */
#**************************************************************************/

##------- BEFORE USING ------------------------------------------------------   
# Ensure in the linker file that the correct SRAM size is selected
##---------------------------------------------------------------------------

##------- Reset Configuration Half Word -------------------------------------   
    .section .init
    
    #.LONG 0x005A005A        # MPC5643 - Leopard - VLE OFF, Valid Bood Identifier 0x5A    
   .LONG 0x015A015A       # MPC5643 - Leopard - VLE ON, Valid Bood Identifier 0x5A

    .globl  _start
      
    .extern main
    .extern __SP_INIT
    .extern _SDA_BASE_
    .extern _SDA2_BASE_
	
	.extern __BSS_START
	.extern __BSS_SIZE
    
    .equ _BIUCR_RAM_ADDR, 0x40000000  
##---------------------------------------------------------------------------       

    .align 4


##---------------------------------------------------------------------------
## Initialise GPR's for LockStep Mode 
## This REALLY IS A MUST!
##---------------------------------------------------------------------------

# Set the MSR[SPE] bit so code can use "evmergelo" instruction.
 .equ     MSR_Mask, 0x02000000     
 
      .ifdef VLE_IS_ON
   
 .section .text_vle,text_vle   		; The "text" generates symbols for debug
  
     _start:     
	e_li    r5, 0                           
	mfmsr    r5                     
	e_lis    r6, MSR_Mask@h
	e_or2i   r6, MSR_Mask@l                                                                
	se_or    r5,r6 
	mtmsr    r5                                                                                              
	se_isync 

;# 1.  32 64-bit GPR0-31
	e_lis       r1, 0      ;# Initialize the lower 32-bits of GPR1 to 0 
 
 .else  
 
 .section .text,text
 
  _start:   
	lis     r5, 0                           
	mfmsr   r5                     
	lis     r6, MSR_Mask@h
	ori     r6, r6, MSR_Mask@l                                                                
	or      r5, r5,r6 
	mtmsr   r5                                                                                              
	isync

;# 1.  32 64-bit GPR0-31
	lis       r1, 0      ;# Initialize the lower 32-bits of GPR1 to 0 
  
.endif

 evmergelo r0,r1,r1   # Initialize the 64-bits of GPR0 to 0
 evmergelo r1,r0,r0   # Continue initializing the other 64-bit GPRs
 evmergelo r2,r0,r0   # ...
 evmergelo r3,r0,r0   #
 evmergelo r4,r0,r0   #
 evmergelo r5,r0,r0   #
 evmergelo r6,r0,r0   #
 evmergelo r7,r0,r0   #
 evmergelo r8,r0,r0   #
 evmergelo r9,r0,r0   #
 evmergelo r10,r0,r0  #
 evmergelo r11,r0,r0  #
 evmergelo r12,r0,r0  # 
 evmergelo r13,r0,r0  #
 evmergelo r14,r0,r0  #
 evmergelo r15,r0,r0  # 
 evmergelo r16,r0,r0  #
 evmergelo r17,r0,r0  #
 evmergelo r18,r0,r0  # 
 evmergelo r19,r0,r0  #
 evmergelo r20,r0,r0  #
 evmergelo r21,r0,r0  # 
 evmergelo r22,r0,r0  #
 evmergelo r23,r0,r0  #
 evmergelo r24,r0,r0  #
 evmergelo r25,r0,r0  #
 evmergelo r26,r0,r0  #
 evmergelo r27,r0,r0  #
 evmergelo r28,r0,r0  #
 evmergelo r29,r0,r0  #
 evmergelo r30,r0,r0  #
 evmergelo r31,r0,r0  # Initialize the 64-bit GPR31 to 0 

# 2.  32-bit DEAR (spr 61)

# mtspr 61,r31         #DEAR

# 3.  32-bit SPRG0-9 (spr 272-279, 604 & 605)

 mtspr 272,r31        #SPRG0-7
 mtspr 273,r31
 mtspr 274,r31
 mtspr 275,r31
 mtspr 276,r31
 mtspr 277,r31
 mtspr 278,r31
 mtspr 279,r31
    
 mtspr 604,r31         #SPRG8-9
 mtspr 605,r31

# 4.  32-bit USPRG0 (spr 256)

 mtspr 256,r31         #USPRG0

# 5.  32-bit SRR0 (spr 26), SRR1 (spr 27), CSRR0 (spr58), CSRR1 (spr59),
#    DSRR0 (spr 574), DSRR1 (spr 575), MCSRR0 (spr570), MCSRR1 (spr571)

 mtspr 26,r31          #SRR0-1
 mtspr 27,r31
 mtspr 58,r31          #CSRR0-1
 mtspr 59,r31
 mtspr 570,r31         #MCSRR0-1
 mtspr 571,r31 
 mtspr 574,r31         #DSSRR0-1 
 mtspr 575,r31      
    
# 6.  32-bit IVPR (spr 63)

 mtspr 63,r31          #IVPR
 mtspr 62,r31          #ESR
 mtspr 340,r31         #TCR
 mtspr 512,r31         #SPEFSCR
 mtspr 1,r31           #XER
 mtspr 256,r31         #USPRG0 
 
# 7.  32-bit IVOR0-15 (spr 400 - 415), IVOR 32-35 (spr 528 - 531)

 mtspr 400,r31         #IVOR0-15
 mtspr 401,r31
 mtspr 402,r31
 mtspr 403,r31   
 mtspr 404,r31
 mtspr 405,r31
 mtspr 406,r31
 mtspr 407,r31
 mtspr 408,r31
 mtspr 409,r31
 mtspr 410,r31
 mtspr 411,r31
 mtspr 412,r31
 mtspr 413,r31
 mtspr 414,r31
 mtspr 415,r31

 mtspr 528,r31         #IVOR32-35
 mtspr 529,r31
 mtspr 530,r31
 
# Executing this instruction crashes the part. August 11, 2010
# mtspr 531,r31         # does IVOR 35 exist? Not in e200z4 RM ?

# 8.  32-bit MCAR (spr 573)

 mtspr 573,r31         #MCAR
 
# 9. 32-bit TBL, TBU (spr 284, 285)

 mtspr 284,r31         #TBL
 mtspr 285,r31         #TBU
 
# 10. 32-bit DEC, DECAR (spr 22, 54)

 mtspr 22,r31          #DEC
 mtspr 54,r31          #DECAR

# 11. 64-bit DVC1, DVC2 (spr 318, 319)
# Note most debug registers are reset by POR so initialization is not required.

 mtspr 318,r31         #DVC1
 mtspr 319,r31         #DVC2

# 12. 32-bit DBCNT (spr 562)

 mtspr 562,r31         #DBCNT

# 16. SPE ACC register. 
 
 evmra r1,r31           # Initialize the 64-bit SPE ACC to 0
 evmra r1,r31           # It was required to use the "evmra" command twice in
                        # simulation. Verify on silicon ??????                
# 17. Condition Registers  
   
 mtcrf 0xFF,r31
                
# 18. Counter/Decrementer/Link Register

 mtspr 9,r31            #CTR
 mtspr 8,r31            #LR


##------- Disable Watchdog  -----------------------------------------------
# Included for reference
# Not needed because Watchdog is off in the shadow block.
.ifdef VLE_IS_ON
        e_lis     r6,0xfff3
	e_or2i  r6, 0x8010
	e_li      r7,0xC520
	e_stw     r7,0x0(r6)
	e_li      r7,0xD928
	e_stw     r7,0x0(r6) # Disengage soft-lock

	e_lis     r6,0xfff3
	e_or2i    r6, 0x8000
	e_lis     r7,0xff00
	e_or2i    r7, 0x10A
	e_stw     r7,0x0(r6) # WEN = 0	

.else
	lis     r6,0xfff3
	ori     r6,r6, 0x8010
	li      r7,0xC520
	stw     r7,0x0(r6)
	li      r7,0xD928
	stw     r7,0x0(r6) # Disengage soft-lock

	lis     r6,0xfff3
	ori     r6,r6, 0x8000
	lis     r7,0xff00
	ori     r7,r7, 0x10A
	stw     r7,0x0(r6) # WEN = 0	
.endif
##------- End of Disable Watchdog  -----------------------------------------

##---------------------------------------------------------------------------       
## Linker variables
##---------------------------------------------------------------------------       
.ifdef VLE_IS_ON
    e_lis       r1, __SP_INIT@h                    # Initialize stack pointer r1 to
    e_or2i       r1,  __SP_INIT@l                # value in linker command file. 
     
    e_lis       r13, _SDA_BASE_@h                  # Initialize r13 to sdata base
    e_or2i       r13,  _SDA_BASE_@l             # (provided by linker).    
    
    e_lis       r2, _SDA2_BASE_@h                  # Initialize r2 to sdata2 base
    e_or2i       r2,  _SDA2_BASE_@l              # (provided by linker).
    
    e_addi      r0, r0, 0
    e_stwu      r0,-128(r1)                        # Terminate stack.  This seems to be required for main()
.else
    addis       r11,r0,__SP_INIT@ha     # Initialize stack pointer r1 to
    addi        r1,r11,__SP_INIT@l      # value in linker command file.

    addis       r13,r0,_SDA_BASE_@ha    # Initialize r13 to sdata base
    addi        r13,r13,_SDA_BASE_@l    # (provided by linker).

    addis       r2,r0,_SDA2_BASE_@ha    # Initialize r2 to sdata2 base
    addi        r2,r2,_SDA2_BASE_@l     # (provided by linker).

    stwu        r0,-64(r1)              # Terminate stack.

.endif

##---------------------------------------------------------------------------       
## MMU Stuff
##---------------------------------------------------------------------------       
.ifdef VLE_IS_ON
##---------------------------------------------------------------------------   

#    //# Second MMU Entry First 128K SRAM in LSM - No Translation
#    //# MAS0 : ESEL=1
#    //# MAS1 : TSIZ=256Kbytes
#    //# MAS2 : EPN=0x400000000, W=0, I=1, M=0, G=0, E=big 
#    //# MAS3 : RPN=0x400000000, PERMIS=all 

    e_lis     r3, 0x1001
    mtMAS0    r3

    e_lis     r4, 0xC000
    e_or2i    r4, 0x0380
    mtMAS1    r4


    e_lis     r5, 0x4000
    e_or2i    r5, 0x0028
    mtMAS2    r5

    e_lis     r6, 0x4000
    e_or2i    r6, 0x003f
    mtMAS3    r6

    msync	             
    tlbwe
    se_isync

#    // Set up MMU
#    // Flash area - setup direct No translation
#    // MAS0 : ESEL=0 
#    // MAS1 : TSIZ=16Mbytes
#    // MAS2 : EPN=0x000000000, VLE=0, W=0, I=0, M=0, G=0, E=big 
#    // MAS3 : RPN=0x000000000, PERMIS=all 

    e_lis    r3, 0x1000
    mtMAS0   r3

    e_lis    r4, 0xC000
    e_or2i   r4, 0x0500
    mtMAS1   r4

    e_lis    r5, 0x0000
    e_or2i   r5, 0x0000
    mtMAS2   r5

    e_lis    r6, 0x0000
    e_or2i   r6, 0x003f
    mtMAS3   r6
	   
#    // common to both LSM and DPM
#    //# Fourth MMU Entry Peripheral A 
#    //# MAS0 : ESEL=2
#    //# MAS1 : TSIZ=1Mbytes
#    //# MAS2 : EPN=0xC3F000000, W=0, I=1, M=0, G=1, E=big 
#    //# MAS3 : RPN=0xC3F000000, PERMIS=all 

    e_lis     r3, 0x1002
    mtMAS0    r3

    e_lis     r4, 0xC000
    e_or2i    r4, 0x0500
    mtMAS1    r4

    e_lis     r5, 0xC3F0
    e_or2i    r5, 0x000A   
    mtMAS2    r5

    e_lis     r6, 0xC3F0
    e_or2i    r6, 0x003F
    mtMAS3    r6

    msync	             
    tlbwe
    se_isync

#    //# Fifth MMU Entry Peripheral B 
#    //# MAS0 : ESEL=3
#    //# MAS1 : TSIZ=2Mbytes
#    //# MAS2 : EPN=0xFFE000000, W=0, I=1, M=0, G=0, E=big 
#    //# MAS3 : RPN=0xFFE000000, PERMIS=all 

    e_lis     r3, 0x1003
    mtMAS0    r3
 
    e_lis     r4, 0xC000
    e_or2i    r4, 0x0580
    mtMAS1    r4
 
    e_lis     r5, 0xFFE0
    e_or2i    r5, 0x0008   
    mtMAS2    r5
 
    e_lis     r6, 0xFFE0
    e_or2i    r6, 0x003F
    mtMAS3    r6
 
    msync	             
    tlbwe
    se_isync 
	
#// MMU Entry Shadow Flash
#// MAS0 : ESEL=4
#// MAS1 : TSIZE=16KB
#// MAS2 : EPN=0x00F00000, I=1
#// MAS3 : RPN=0x00F00000, readonly
    e_lis     r3, 0x1004
    mtMAS0    r3
 
    e_lis     r4, 0xC000
    e_or2i    r4, 0x0200
    mtMAS1    r4
 
    e_lis     r5, 0x00F0
    e_or2i    r5, 0x0008   
    mtMAS2    r5
 
    e_lis     r6, 0x00F0
    e_or2i    r6, 0x0003
    mtMAS3    r6
 
    msync	             
    tlbwe
    se_isync    
    
##--------- Initialize BSS section ------------------------------------------

bss_Init:
    e_lis        r9, __BSS_SIZE@h            # Load upper BSS load size (# of bytes) into R9
    e_or2i       r9, __BSS_SIZE@l            # Load lower BSS load size into R9 and compare to zero
    e_cmp16i     r9,0   
    e_beq        bss_Init_end                # Exit if size is zero (no data to initialise)

    mtctr        r9                          # Store no. of bytes to be moved in counter

    e_lis        r5, __BSS_START@h           # Load upper BSS address into R5 (from linker file)
    e_or2i       r5,  __BSS_START@l          # Load lower BSS address into R5 (from linker file)
    e_subi       r5, r5, 1                   # Decrement address to prepare for bss_Init_loop

    e_lis        r4, 0x0 

bss_Init_loop:
    e_stbu        r4, 1(r5)                  # Store zero byte into BSS at R5 and update BSS address
    e_bdnz        bss_Init_loop              # Branch if more bytes to load
	
bss_Init_end:

##--------- Start of Main Code-----------------------------------------------

    e_bl        main

##---------------------------------------------------------------------------    

.else
#    //# Second MMU Entry First 128K SRAM in LSM - No Translation
#    //# MAS0 : ESEL=1
#    //# MAS1 : TSIZ=256Kbytes
#    //# MAS2 : EPN=0x400000000, W=0, I=1, M=0, G=0, E=big 
#    //# MAS3 : RPN=0x400000000, PERMIS=all 

    lis     r3, 0x1001
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0380
    mtMAS1  r4


    lis     r5, 0x4000
    ori     r5, r5, 0x0028

    mtMAS2  r5

    lis     r6, 0x4000
    ori     r6, r6, 0x003f
    mtMAS3  r6

    msync	             
    tlbwe
    isync

#    // Set up MMU
#    // Flash area - setup direct No translation
#    // MAS0 : ESEL=0 
#    // MAS1 : TSIZ=16Mbytes
#    // MAS2 : EPN=0x000000000, VLE=0, W=0, I=0, M=0, G=0, E=big 
#    // MAS3 : RPN=0x000000000, PERMIS=all 

    lis    r3, 0x1000
    mtMAS0 r3

    lis    r4, 0xC000
    ori    r4, r4, 0x0500
    mtMAS1 r4

    lis    r5, 0x0000
    ori    r5, r5, 0x0000
    mtMAS2 r5

    lis    r6, 0x0000
    ori    r6, r6, 0x003f
    mtMAS3 r6
	   

#    // common to both LSM and DPM
#    //# Fourth MMU Entry Peripheral A 
#    //# MAS0 : ESEL=2
#    //# MAS1 : TSIZ=1Mbytes
#    //# MAS2 : EPN=0xC3F000000, W=0, I=1, M=0, G=1, E=big 
#    //# MAS3 : RPN=0xC3F000000, PERMIS=all 

    lis     r3, 0x1002
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0500
    mtMAS1  r4

    lis     r5, 0xC3F0
    ori     r5, r5, 0x000A   
    mtMAS2  r5

    lis     r6, 0xC3F0
    ori     r6, r6, 0x003F
    mtMAS3  r6

    msync	             
    tlbwe
    isync

#    //# Fifth MMU Entry Peripheral B 
#    //# MAS0 : ESEL=3
#    //# MAS1 : TSIZ=2Mbytes
#    //# MAS2 : EPN=0xFFE000000, W=0, I=1, M=0, G=0, E=big 
#    //# MAS3 : RPN=0xFFE000000, PERMIS=all 

    lis     r3, 0x1003
    mtMAS0  r3
 
    lis     r4, 0xC000
    ori     r4, r4, 0x0580
    mtMAS1  r4
 
    lis     r5, 0xFFE0
    ori     r5, r5, 0x0008   
    mtMAS2  r5
 
    lis     r6, 0xFFE0
    ori     r6, r6, 0x003F
    mtMAS3  r6
 
    msync	             
    tlbwe
    isync 
	
#// MMU Entry Shadow Flash
#// MAS0 : ESEL=4
#// MAS1 : TSIZE=16KB
#// MAS2 : EPN=0x00F00000, I=1
#// MAS3 : RPN=0x00F00000, readonly
	lis     r3, 0x1004
    mtMAS0  r3
 
    lis     r4, 0xC000
    ori     r4, r4, 0x0200
    mtMAS1  r4
 
    lis     r5, 0x00F0
    ori     r5, r5, 0x0008   
    mtMAS2  r5
 
    lis     r6, 0x00F0
    ori     r6, r6, 0x0003
    mtMAS3  r6
 
    msync	             
    tlbwe
    isync    
    

##--------- Start of Main Code-----------------------------------------------

    bl        main


  .endif
