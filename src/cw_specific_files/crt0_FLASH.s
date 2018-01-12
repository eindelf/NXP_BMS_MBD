#**************************************************************************/
#* FILE NAME: ctr0_VLE_Flash.s             COPYRIGHT (c) Freescale 2008   */
#*                                                All Rights Reserved     */
#* DESCRIPTION:                                                           */
#* This is a generic base template for init of a Flash Project            */
#=========================================================================*/
#*                                                                        */
#*========================================================================*/
#**************************************************************************/

##------- BEFORE USING ------------------------------------------------------   
# Ensure in the linker file that the correct SRAM size is selected
##---------------------------------------------------------------------------

    .extern main
    .extern romcopy

# CW requires that these be externel

    .extern __SP_INIT
    .extern _SDA_BASE_
    .extern __DATA_ROM_ADDR
    .extern __DATA_SRAM_ADDR
    .extern __DATA_SIZE
    .extern __SDATA_ROM_ADDR
    .extern __SDATA_SRAM_ADDR
    .extern __SDATA_SIZE
    .extern _SDA2_BASE_
    .extern _SRAM_BASE_ADDR
    .extern _SRAM_SIZE
	.extern __BSS_START
	.extern __BSS_SIZE
	
##---------------------------------------------------------------------------
## Reset Configuration Half Word
##---------------------------------------------------------------------------

    .section .rcw
    
    #.LONG 0x005A005A         # MPC5643 - Leopard - VLE OFF, Valid Bood Identifier 0x5A    
    .LONG 0x015A015A        # MPC5643 - Leopard - VLE ON, Valid Bood Identifier 0x5A
    #.LONG 0x015A015A        # MPC55xx - e200 Core Watchdog OFF, External Boot OFF, VLE ON
    #.LONG 0x055A0000        # MPC55xx - e200 Core Watchdog ON,  External Boot OFF, VLE ON
    #.LONG 0x095A0000        # Monaco/Mamba - Software Watchdog ON,       e200 Core Watchdog OFF, External Boot OFF, VLE ON
    #.LONG 0x015A0000        # Monaco/Mamba - Software Watchdog DISABLED, e200 Core Watchdog OFF, External Boot OFF, VLE ON
    #.LONG 0x055A0000        # Fado - Software Watchdog ON,  VLE ON
    #.LONG 0x015A0000        # Fado - Software Watchdog OFF, VLE ON
    #.LONG 0x005A0000        # Bolero/Pictus/Spectrum
        
    .LONG _start             # Code starts at _start
    .equ _BIUCR_RAM_ADDR, 0x40000000   
##---------------------------------------------------------------------------
## Program Entry
##---------------------------------------------------------------------------       

# CW Requires it this way, though it appears to work for GHS also
# This is what it was originally.section    ".text", "vax"        

    .globl       _start

# This needs to be here to work for both CW & GHS dues to the GHS Linker file (which could be changed...)

##---------------------------------------------------------------------------
## Initialise GPR's for LockStep Mode 
## This REALLY IS A MUST!
## This is the version given to me by Gene Fortunately in Austin
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


;##---------------------------------------------------------------------------
;## MMU Setup
;##---------------------------------------------------------------------------
.ifdef VLE_IS_ON

;/* ----------------------------------------------------------- */
;/*   MMU TLB entry 1 Entry Name : Internal Flash Memory                    */
;/* ----------------------------------------------------------- */
    e_lis   r10, 0x1000
    e_or2i   r10, 0x0000
    mtspr 624, r10        
;            /* ----------------------------------------------- */
;            /*   MAS0 Register (Set to value 0x10010000)        */
;            /* ----------------------------------------------- */
;            /* NV: TLB Entry No: 1         */
    e_lis   r11, 0xC000
    e_or2i   r11, 0x0500
    mtspr 625, r11        
;            /* ----------------------------------------------- */
;            /*   MAS1 Register (Set to value 0xC0000700)        */
;            /* ----------------------------------------------- */
;            /* VALID: TLB Valid Entry: Enabled     */
;            /* IPROT: Invalidation Enabled: Enabled     */
;            /* TID: Process ID: 0                */
;            /* TS: Translation Address Space: Disabled   */
;            /* TSIZE: Page Size: 16 MB              */
    e_lis   r12, 0x0000
    e_or2i   r12, 0x0020
    mtspr 626, r12        
;            /* ----------------------------------------------- */
;            /*   MAS2 Register (Set to value 0x00000020)        */
;            /* ----------------------------------------------- */
;            /* EPN: Effective Page Number: 00000000 */
;            /* VLE: PowerPC VLE: Enabled    */
;            /* W: Write Through Required: Disabled      */
;            /* CI: Cache Inhibited: Disabled            */
;            /* E: Endianess:     Big-endian            */
    e_lis   r9, 0x0000
    e_or2i   r9, 0x003F
    mtspr 627, r9        
;            /* ----------------------------------------------- */
;            /*   MAS3 Register (Set to value 0x0000003F)        */
;            /* ----------------------------------------------- */
;            /* RPN: Real Page Number: 00000000    */
;            /* UX: User Execute Permission: Enabled    */
;            /* SX: Supervisor Execution Permission: Enabled                 */
;            /* UW: User Write Permission: Enabled    */
;            /* SW: Supervisor Write Permission: Enabled               */
;            /* UR: User Read Permission: Enabled     */
;            /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;    /* Use special buffer entry write to add entry to TLB*/
    se_isync        
    
;/* ----------------------------------------------------------- */
;/*   MMU TLB entry 2 Entry Name : SRAM_0                    */
;/* ----------------------------------------------------------- */
    e_lis   r10, 0x1002
    e_or2i   r10, 0x0000
    mtspr 624, r10        
;            /* ----------------------------------------------- */
;            /*   MAS0 Register (Set to value 0x10020000)        */
;            /* ----------------------------------------------- */
;            /* NV: TLB Entry No: 2         */
    e_lis   r11, 0xC000
    e_or2i   r11, 0x0300
    mtspr 625, r11        
;            /* ----------------------------------------------- */
;            /*   MAS1 Register (Set to value 0xC0000300)        */
;            /* ----------------------------------------------- */
;            /* VALID: TLB Valid Entry: Enabled     */
;            /* IPROT: Invalidation Enabled: Enabled     */
;            /* TID: Process ID: 0                */
;            /* TS: Translation Address Space: Disabled   */
;            /* TSIZE: Page Size: 64 KB              */
    e_lis   r12, 0x4000
    e_or2i   r12, 0x0028
    mtspr 626, r12        
;            /* ----------------------------------------------- */
;            /*   MAS2 Register (Set to value 0x40000028)        */
;            /* ----------------------------------------------- */
;            /* EPN: Effective Page Number: 0100000000000000 */
;            /* VLE: PowerPC VLE: Enabled    */
;            /* W: Write Through Required: Disabled      */
;            /* CI: Cache Inhibited: Enabled             */
;            /* E: Endianess:     Big-endian            */
    e_lis   r9, 0x4000
    e_or2i   r9, 0x003F
    mtspr 627, r9        
;            /* ----------------------------------------------- */
;            /*   MAS3 Register (Set to value 0x4000003F)        */
;            /* ----------------------------------------------- */
;            /* RPN: Real Page Number: 0100000000000000    */
;            /* UX: User Execute Permission: Enabled    */
;            /* SX: Supervisor Execution Permission: Enabled                 */
;            /* UW: User Write Permission: Enabled    */
;            /* SW: Supervisor Write Permission: Enabled               */
;            /* UR: User Read Permission: Enabled     */
;            /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;    /* Use special buffer entry write to add entry to TLB*/
    se_isync        
    
;/* ----------------------------------------------------------- */
;/*   MMU TLB entry 3 Entry Name : On-platform 1 peripherals                    */
;/* ----------------------------------------------------------- */
    e_lis   r10, 0x1003
    e_or2i   r10, 0x0000
    mtspr 624, r10        
;            /* ----------------------------------------------- */
;            /*   MAS0 Register (Set to value 0x10040000)        */
;            /* ----------------------------------------------- */
;            /* NV: TLB Entry No: 4         */
    e_lis   r11, 0xC000
    e_or2i   r11, 0x0A00
    mtspr 625, r11        
;            /* ----------------------------------------------- */
;            /*   MAS1 Register (Set to value 0xC0000A00)        */
;            /* ----------------------------------------------- */
;            /* VALID: TLB Valid Entry: Enabled     */
;            /* IPROT: Invalidation Enabled: Enabled     */
;            /* TID: Process ID: 0                */
;            /* TS: Translation Address Space: Disabled   */
;            /* TSIZE: Page Size: 1GB              */
    e_lis   r12, 0x8000
    e_or2i   r12, 0x0008
    mtspr 626, r12        
;            /* ----------------------------------------------- */
;            /*   MAS2 Register (Set to value 0x80000028)        */
;            /* ----------------------------------------------- */
;            /* EPN: Effective Page Number: 10 */
;            /* VLE: PowerPC VLE: Enabled    */
;            /* W: Write Through Required: Disabled      */
;            /* CI: Cache Inhibited: Enabled             */
;            /* E: Endianess:     Big-endian            */
    e_lis   r9, 0x8000
    e_or2i   r9, 0x003F
    mtspr 627, r9        
;            /* ----------------------------------------------- */
;            /*   MAS3 Register (Set to value 0x8000003F)        */
;            /* ----------------------------------------------- */
;            /* RPN: Real Page Number: 10    */
;            /* UX: User Execute Permission: Enabled    */
;            /* SX: Supervisor Execution Permission: Enabled                 */
;            /* UW: User Write Permission: Enabled    */
;            /* SW: Supervisor Write Permission: Enabled               */
;            /* UR: User Read Permission: Enabled     */
;            /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;    /* Use special buffer entry write to add entry to TLB*/
    se_isync        

;/* ----------------------------------------------------------- */
;/*   MMU TLB entry 4 Entry Name : Peripherals_A                    */
;/* ----------------------------------------------------------- */
    e_lis   r10, 0x1004
    e_or2i   r10, 0x0000
    mtspr 624, r10        
;            /* ----------------------------------------------- */
;            /*   MAS0 Register (Set to value 0x10050000)        */
;            /* ----------------------------------------------- */
;            /* NV: TLB Entry No: 5         */
    e_lis   r11, 0xC000
    e_or2i   r11, 0x0500
    mtspr 625, r11        
;            /* ----------------------------------------------- */
;            /*   MAS1 Register (Set to value 0xC0000500)        */
;            /* ----------------------------------------------- */
;            /* VALID: TLB Valid Entry: Enabled     */
;            /* IPROT: Invalidation Enabled: Enabled     */
;            /* TID: Process ID: 0                */
;            /* TS: Translation Address Space: Disabled   */
;            /* TSIZE: Page Size: 1 MB              */
    e_lis   r12, 0xC3F0
    e_or2i   r12, 0x0008
    mtspr 626, r12        
;            /* ----------------------------------------------- */
;            /*   MAS2 Register (Set to value 0xC3F00028)        */
;            /* ----------------------------------------------- */
;            /* EPN: Effective Page Number: 110000111111 */
;            /* VLE: PowerPC VLE: Enabled    */
;            /* W: Write Through Required: Disabled      */
;            /* CI: Cache Inhibited: Enabled             */
;            /* E: Endianess:     Big-endian            */
    e_lis   r9, 0xC3F0
    e_or2i   r9, 0x003F
    mtspr 627, r9        
;            /* ----------------------------------------------- */
;            /*   MAS3 Register (Set to value 0xC3F0003F)        */
;            /* ----------------------------------------------- */
;            /* RPN: Real Page Number: 110000111111    */
;            /* UX: User Execute Permission: Enabled    */
;            /* SX: Supervisor Execution Permission: Enabled                 */
;            /* UW: User Write Permission: Enabled    */
;            /* SW: Supervisor Write Permission: Enabled               */
;            /* UR: User Read Permission: Enabled     */
;            /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;    /* Use special buffer entry write to add entry to TLB*/
    se_isync        

;/* ----------------------------------------------------------- */
;/*   MMU TLB entry 5 Entry Name : Peripherals_B                    */
;/* ----------------------------------------------------------- */
    e_lis   r10, 0x1005
    e_or2i   r10, 0x0000
    mtspr 624, r10        
;            /* ----------------------------------------------- */
;            /*   MAS0 Register (Set to value 0x10060000)        */
;            /* ----------------------------------------------- */
;            /* NV: TLB Entry No: 6         */
    e_lis   r11, 0xC000
    e_or2i   r11, 0x0580
    mtspr 625, r11        
;            /* ----------------------------------------------- */
;            /*   MAS1 Register (Set to value 0xC0000580)        */
;            /* ----------------------------------------------- */
;            /* VALID: TLB Valid Entry: Enabled     */
;            /* IPROT: Invalidation Enabled: Enabled     */
;            /* TID: Process ID: 0                */
;            /* TS: Translation Address Space: Disabled   */
;            /* TSIZE: Page Size: 2 MB              */
    e_lis   r12, 0xFFE0
    e_or2i   r12, 0x0028
    mtspr 626, r12        
;            /* ----------------------------------------------- */
;            /*   MAS2 Register (Set to value 0xFFE00028)        */
;            /* ----------------------------------------------- */
;            /* EPN: Effective Page Number: 11111111111 */
;            /* VLE: PowerPC VLE: Enabled    */
;            /* W: Write Through Required: Disabled      */
;            /* CI: Cache Inhibited: Enabled             */
;            /* E: Endianess:     Big-endian            */
    e_lis   r9, 0xFFE0
    e_or2i   r9, 0x003F
    mtspr 627, r9        
;            /* ----------------------------------------------- */
;            /*   MAS3 Register (Set to value 0xFFE0003F)        */
;            /* ----------------------------------------------- */
;            /* RPN: Real Page Number: 11111111111    */
;            /* UX: User Execute Permission: Enabled    */
;            /* SX: Supervisor Execution Permission: Enabled                 */
;            /* UW: User Write Permission: Enabled    */
;            /* SW: Supervisor Write Permission: Enabled               */
;            /* UR: User Read Permission: Enabled     */
;            /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;    /* Use special buffer entry write to add entry to TLB*/
    se_isync        
.else
    
    //# MMU Entry First 1MB FLASH    //# MAS0 : ESEL=1
    //# MAS1 : TSIZ=1MB
    //# MAS2 : EPN=0x000000000, W=0, I=0, M=0, G=0, E=big 
    //# MAS3 : RPN=0x000000000, PERMIS=all
    
 	lis     r3, 0x1000
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0500
    mtMAS1  r4

    lis     r5, 0x0000
    ori     r5, r5, 0x0000
    mtMAS2  r5

    lis     r6, 0x0000
    ori     r6, r6, 0x003f
    mtMAS3  r6

    msync
    tlbwe
    isync

    //# MMU Entry First 64K SRAM in DPM - No Translation
    //# MAS0 : ESEL=2
    //# MAS1 : TSIZ=64Kbytes
    //# MAS2 : EPN=0x400000000, W=0, I=1, M=0, G=0, E=big 
    //# MAS3 : RPN=0x400000000, PERMIS=all 

    lis     r3, 0x1002
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0300
    mtMAS1  r4
	lis     r5, 0x4000
    ori     r5, r5, 0x0008
    mtMAS2  r5

    lis     r6, 0x4000
    ori     r6, r6, 0x003f
    mtMAS3  r6

    tlbwe

    //# Peripheral Space in DPM mode things start at 0x8ff0_0000
    //# will start at 0x8ff0_0000 and extend 1M
    //# MAS0 : ESEL=4
    //# MAS1 : TSIZ=1MB
    //# MAS2 : EPN=0x8ff00000, W=0, I=1, M=0, G=1, E=big 
    //# MAS3 : RPN=0x8ff00000, PERMIS=all 

    lis     r3, 0x1004
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0500
    mtMAS1  r4

    lis     r5, 0x8ff0
    ori     r5, r5, 0x000A
    mtMAS2  r5

    lis     r6,0x8ff0
    ori     r6, r6, 0x003f
    mtMAS3  r6

    tlbwe


	//# common to both LSM and DPM
    //# MMU Entry Peripheral A 
    //# MAS0 : ESEL=5
    //# MAS1 : TSIZ=1Mbytes
    //# MAS2 : EPN=0xC3F00000, W=0, I=1, M=0, G=1, E=big 
    //# MAS3 : RPN=0xC3F00000, PERMIS=all 

    lis     r3, 0x1005
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

    tlbwe

    //# MMU Entry Peripheral B 
    //# MAS0 : ESEL=6
    //# MAS1 : TSIZ=1Mbytes
    //# MAS2 : EPN=0xFFE00000, W=0, I=1, M=0, G=0, E=big 
    //# MAS3 : RPN=0xFFE00000, PERMIS=all 

    lis     r3, 0x1006
    mtMAS0  r3
 
    lis     r4, 0xC000
    ori     r4, r4, 0x0500
    mtMAS1  r4
 
    lis     r5, 0xFFE0
    ori     r5, r5, 0x0008   
    mtMAS2  r5
 
    lis     r6, 0xFFE0
    ori     r6, r6, 0x003F
    mtMAS3  r6
 
    tlbwe

	//# MMU On-Platform 0 Peripherals 
    //# MAS0 : ESEL=7
    //# MAS1 : TSIZ=512 Kbytes
    //# MAS2 : EPN=0xFFF00000, W=0, I=1, M=0, G=0, E=big 
    //# MAS3 : RPN=0xFFF00000, PERMIS=all 

    lis     r3, 0x1007
    mtMAS0  r3
 
    lis     r4, 0xC000
    ori     r4, r4, 0x0480
    mtMAS1  r4
 
    lis     r5, 0xFFF0
    ori     r5, r5, 0x0008   
    mtMAS2  r5
 
    lis     r6, 0xFFF0
    ori     r6, r6, 0x003F
    mtMAS3  r6
 
    tlbwe

;-----------------------------------------------------------------
.endif   
    
.ifdef VLE_IS_ON
##---------------------------------------------------------------------------
## Initialise SRAM ECC
##---------------------------------------------------------------------------

RAMINIT:

    e_lis        r5, _SRAM_BASE_ADDR@h
    e_or2i        r5, _SRAM_BASE_ADDR@l
 
# Store number of 128Byte (32GPRs) segments in Counter

    e_lis        r6, _SRAM_SIZE@h                  # Initialize r6 to size of SRAM (Bytes)
    e_or2i        r6,  _SRAM_SIZE@l              # this is 64K in dual core mode
    
    e_srwi        r6, r6, 0x3                      # Divide SRAM size by 8 (half SRAM size in words)
    mtctr       r6                               # Move to counter for use with "bdnz"
    
# Fill SRAM with known values not registers 
# Never write content of uninitialised registers to SRAM 

sram_loop1:
    e_lis         r0,0x0
    e_stw         r0,0x0(r5)                       # Write all 32 registers to SRAM    
    e_addi        r5,r5,4                          # Increment the RAM pointer to next 128byte
    e_bdnz        sram_loop1                       # Loop for all of SRAM

# Finish initializing SRAM

    mtctr     r6                                 # r6 still contains half the SRAM size in words
    sram_loop2:
    e_lis           r0,0x0
    e_stwu       r0,0x0(r5)                         # Write all 32 registers to SRAM    
    e_addi      r5,r5,4                            # Increment the RAM pointer to next 128byte
    e_bdnz      sram_loop2                         # Loop for all of SRAM
	
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

##---------------------------------------------------------------------------       
## Initialised Data - ".data"
##---------------------------------------------------------------------------       

DATACOPY:

    e_lis        r9, __DATA_SIZE@h               # Load upper SRAM load size (# of bytes) into R9
    e_or2i       r9, __DATA_SIZE@l            # Load lower SRAM load size into R9 and compare to zero
    e_cmp16i     r9,0   
    e_beq        SDATACOPY                        # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr        r9                               # Store no. of bytes to be moved in counter

    e_lis         r10, __DATA_ROM_ADDR@h           # Load address of first SRAM load into R10
    e_or2i         r10,  __DATA_ROM_ADDR@l      # Load lower address of SRAM load into R10
    e_subi        r10,r10, 1                       # Decrement address to prepare for ROMCPYLOOP

    e_lis         r5, __DATA_SRAM_ADDR@h           # Load upper SRAM address into R5 (from linker file)
    e_or2i         r5,  __DATA_SRAM_ADDR@l       # Load lower SRAM address into R5 (from linker file)
    e_subi        r5, r5, 1                        # Decrement address to prepare for ROMCPYLOOP

DATACPYLOOP:

    e_lbzu        r4, 1(r10)                       # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu        r4, 1(r5)                        # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz        DATACPYLOOP                      # Branch if more bytes to load from ROM

##---------------------------------------------------------------------------       
## Small Initialised Data - ".sdata"
##---------------------------------------------------------------------------       

SDATACOPY:
 
    e_lis         r9, __SDATA_SIZE@h              # Load upper SRAM load size (# of bytes) into R9
    e_or2i        r9,  __SDATA_SIZE@l           # Load lower SRAM load size into R9 and compare to zero
     e_cmp16i     r9,0  
    e_beq         ROMCPYEND                        # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                               # Store no. of bytes to be moved in counter

    e_lis         r10, __SDATA_ROM_ADDR@h          # Load address of first SRAM load into R10
    e_or2i        r10,  __DATA_ROM_ADDR@l      # Load lower address of SRAM load into R10
    e_subi        r10,r10, 1                       # Decrement address to prepare for ROMCPYLOOP

    e_lis         r5, __SDATA_SRAM_ADDR@h          # Load upper SRAM address into R5 (from linker file)
    e_or2i        r5, __SDATA_SRAM_ADDR@l      # Load lower SRAM address into R5 (from linker file)
    e_subi        r5, r5, 1                        # Decrement address to prepare for ROMCPYLOOP

SDATACPYLOOP:

    e_lbzu        r4, 1(r10)                       # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu        r4, 1(r5)                        # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz        SDATACPYLOOP                     # Branch if more bytes to load from ROM

ROMCPYEND:

##---------------------------------------------------------------------------       
## Setup the Stack
##---------------------------------------------------------------------------       

SETUPSTACK:

    e_lis       r1, __SP_INIT@h                    # Initialize stack pointer r1 to
    e_or2i       r1,  __SP_INIT@l                # value in linker command file. 
 
    e_lis       r13, _SDA_BASE_@h                  # Initialize r13 to sdata base
    e_or2i       r13,  _SDA_BASE_@l             # (provided by linker).    

    e_lis       r2, _SDA2_BASE_@h                  # Initialize r2 to sdata2 base
    e_or2i       r2,  _SDA2_BASE_@l              # (provided by linker).

    e_addi      r0, r0, 0
    e_stwu      r0,-128(r1)                        # Terminate stack.  This seems to be required for main()

.else
# Doing this in halves for Leopard 128k SRAM to allow for WDOG service at the half-way point.
# Base Address of the internal SRAM

RAMINIT:

    lis        r5, _SRAM_BASE_ADDR@h
    ori        r5, r5, _SRAM_BASE_ADDR@l
 
# Store number of 128Byte (32GPRs) segments in Counter

    lis        r6, _SRAM_SIZE@h                  # Initialize r6 to size of SRAM (Bytes)
    ori        r6, r6, _SRAM_SIZE@l              # this is 64K in dual core mode
    
    srwi        r6, r6, 0x3                      # Divide SRAM size by 8 (half SRAM size in words)
    mtctr       r6                               # Move to counter for use with "bdnz"
    
# Fill SRAM with known values not registers 
# Never write content of uninitialised registers to SRAM 

sram_loop1:
    lis         r0,0x0
    stw         r0,0x0(r5)                       # Write all 32 registers to SRAM    
    addi        r5,r5,4                          # Increment the RAM pointer to next 128byte
    bdnz        sram_loop1                       # Loop for all of SRAM


# Finish initializing SRAM

    mtctr     r6                                 # r6 still contains half the SRAM size in words
    sram_loop2:
    lis           r0,0x0
    stw       r0,0x0(r5)                         # Write all 32 registers to SRAM    
    addi      r5,r5,4                            # Increment the RAM pointer to next 128byte
    bdnz      sram_loop2                         # Loop for all of SRAM

##---------------------------------------------------------------------------       
## Initialised Data - ".data"
##---------------------------------------------------------------------------       

DATACOPY:

    lis         r9, __DATA_SIZE@h               # Load upper SRAM load size (# of bytes) into R9
    addic.      r9, r9, __DATA_SIZE@l            # Load lower SRAM load size into R9 and compare to zero
    beq         SDATACOPY                        # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                               # Store no. of bytes to be moved in counter

    lis         r10, __DATA_ROM_ADDR@h           # Load address of first SRAM load into R10
    ori         r10, r10, __DATA_ROM_ADDR@l      # Load lower address of SRAM load into R10
    subi        r10,r10, 1                       # Decrement address to prepare for ROMCPYLOOP

    lis         r5, __DATA_SRAM_ADDR@h           # Load upper SRAM address into R5 (from linker file)
    ori         r5, r5, __DATA_SRAM_ADDR@l       # Load lower SRAM address into R5 (from linker file)
    subi        r5, r5, 1                        # Decrement address to prepare for ROMCPYLOOP

DATACPYLOOP:

    lbzu        r4, 1(r10)                       # Load data byte at R10 into R4,incrementing (update) ROM address
    stbu        r4, 1(r5)                        # Store R4 data byte into SRAM at R5 and update SRAM address
    bdnz        DATACPYLOOP                      # Branch if more bytes to load from ROM

##---------------------------------------------------------------------------       
## Small Initialised Data - ".sdata"
##---------------------------------------------------------------------------       

SDATACOPY:
 
    lis         r9, __SDATA_SIZE@ha              # Load upper SRAM load size (# of bytes) into R9
    addic.      r9, r9, __SDATA_SIZE@l           # Load lower SRAM load size into R9 and compare to zero
    beq         ROMCPYEND                        # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                               # Store no. of bytes to be moved in counter

    lis         r10, __SDATA_ROM_ADDR@h          # Load address of first SRAM load into R10
    ori         r10, r10, __DATA_ROM_ADDR@l      # Load lower address of SRAM load into R10
    subi        r10,r10, 1                       # Decrement address to prepare for ROMCPYLOOP

    lis         r5, __SDATA_SRAM_ADDR@h          # Load upper SRAM address into R5 (from linker file)
    ori         r5, r5, __SDATA_SRAM_ADDR@l      # Load lower SRAM address into R5 (from linker file)
    subi        r5, r5, 1                        # Decrement address to prepare for ROMCPYLOOP

SDATACPYLOOP:

    lbzu        r4, 1(r10)                       # Load data byte at R10 into R4,incrementing (update) ROM address
    stbu        r4, 1(r5)                        # Store R4 data byte into SRAM at R5 and update SRAM address
    bdnz        SDATACPYLOOP                     # Branch if more bytes to load from ROM

ROMCPYEND:

##---------------------------------------------------------------------------       
## Setup the Stack
##---------------------------------------------------------------------------       

SETUPSTACK:

    lis       r1, __SP_INIT@h                    # Initialize stack pointer r1 to
    ori       r1, r1, __SP_INIT@l                # value in linker command file. 
 
    lis       r13, _SDA_BASE_@h                  # Initialize r13 to sdata base
    ori       r13, r13, _SDA_BASE_@l             # (provided by linker).    

    lis       r2, _SDA2_BASE_@h                  # Initialize r2 to sdata2 base
    ori       r2, r2, _SDA2_BASE_@l              # (provided by linker).

    addi      r0, r0, 0
    stwu      r0,-128(r1)                        # Terminate stack.  This seems to be required for main()

;-----------------------------------------------------------------
.endif  

.ifdef VLE_IS_ON
##---------------------------------------------------------------------------       
## Main Code - May Need Optimizations Here (Flash, Cache, etc)
##---------------------------------------------------------------------------       
#--------------------------------------------#
# Load Flash BIUCR Setting into R7           #
##############################################
## CHANGE FOR DIFFERENT FSYS:               ##
##  Up to 147MHz : 0x00538CFD               ##
##  Up to 135MHz : 0x00534BFD               ##
##  Up to 102MHz : 0x00532AFD               ##
##  Up to 82MHz  : 0x005329FD               ##
##
##  Leopard PFCR0 & 1 are a differnt format ##
##  3 WS needed for 120MHZ                  ##
##  3 Read, 3 Write, 3 Pipeline             ##
##  All Prefetch and Buffers Enabled        ## 
##  PFCR0 = 0x18C7FDFD                      ##
##############################################
#--------------------------------------------#
     e_lis   r7, 0x18C7
     e_or2i   r7, 0xFDFD
#--------------------------------------------#
# Load Flash BIUCR Address into R6           #
#--------------------------------------------#
     e_lis   r6, 0xC3F8
     e_or2i   r6, 0x801C
 
 SRAMLOAD:
#--------------------------------------------#
# Load BIUCR write instruction into R8, R9 & #
#--------------------------------------------#
     e_lis   r8, 0x90E6
     e_or2i   r8,  0x0000    # R8 = "stw r7, 0x0(r6)"
     e_lis   r9, 0x4C00
     e_or2i   r9,  0x012C    # R9 = "isync" added 02 December 2009
     e_lis   r10, 0x4E80
     e_or2i   r10,  0x0020  # R10 = "blr"
 
#--------------------------------------------#
# Load RAM address into R11                  #
#--------------------------------------------#
     e_lis   r11, _BIUCR_RAM_ADDR@h
     e_addi  r11,r11, _BIUCR_RAM_ADDR@l
 
#--------------------------------------------#
# Store Instructions in RAM, then branch and #
# execute instructions to setup BIUCR        #
#--------------------------------------------#
     e_stw   r8, 0x0(r11);
     e_stw   r9, 0x4(r11);
     e_stw   r10, 0x8(r11);
#--------------------------------------------#
# Load SRAM Wait State Setting into R3       #
##############################################
## CHANGE FOR DIFFERENT FSYS:               ##
##  >=100MHz   : 0x40000000                 ##
##  <100MHz    : 0x00000000                 ##
##############################################
#--------------------------------------------#
        e_lis   r3, 0x4000
        e_or2i   r3, 0x0000
#--------------------------------------------#
# Load SRAM Wait State Register Address into #
# R4 and perform write                       #
#--------------------------------------------#
        e_lis   r4, 0xFFF4
        e_or2i   r4, 0x0024
        e_stw   r3, 0x0(r4)
cfg_ICACHE:

    #--------------------------------------------#
    # Invalidate Instruction Cache - Set ICINV   #
    # bit in L1CSR1 Register                     #
    #--------------------------------------------#
    e_lis   r5, 0x0000
    e_or2i   r5, 0x0002
    mtspr l1csr1,r5

    #--------------------------------------------#
    # Mask out ICINV and ICABT to see if         #
    # invalidation is complete (i.e. ICINV=0,    #
    # ICABT=0)                                   #
    #--------------------------------------------#
label_ICINV_check:
    #--------------------------------------------#
    # Load Registers with Masks:                 #
    # Load ICINV mask into R8                    #
    # Load ICABT mask into R7                    #
    # Load ICABT clear mask into R11             #
    #--------------------------------------------#
    e_lis   r8, 0x0000
    e_or2i   r8,  0x0002
    e_lis   r7, 0x0000
    e_or2i   r7,  0x0004
    e_lis   r11, 0xFFFF
    e_or2i   r11,  0xFFFB
CHECK_ICINV:

    #--------------------------------------------#
    # Read L1CSR1 register, store in r9          #
    #--------------------------------------------#
    mfspr r9, l1csr1
    #--------------------------------------------#
    # check for an ABORT of the cache invalidate #
    # operation                                  #
    #--------------------------------------------#
    and.  r10, r7, r9
    e_beq   NO_ABORT
    #--------------------------------------------#
    # If abort detected, clear ICABT bit and     #
    # re-run invalidation                        #
    #--------------------------------------------#
    and.  r10, r11, r9
    mtspr l1csr1, r10
    e_b     cfg_ICACHE

NO_ABORT:
    #--------------------------------------------#
    # Check that invalidation has completed -    #
    # (ICINV=0). Branch if invalidation not      #
    # complete.                                  #
    #--------------------------------------------#
    and.  r10, r8, r9
    e_bne CHECK_ICINV

    #--------------------------------------------#
    # Enable cache the ICache by performing a    #
    # read/modify/write of the ICE bit in the    #
    # L1CSR1 register                            #
    #--------------------------------------------#
    mfspr r5, l1csr1
    e_or2i   r5,  0x0000
    e_or2i   r5,  0x0001    # Store L1CSR1 value to R5 (ICE=1)
    se_isync
    msync
    mtspr l1csr1, r5        # Write R5 to L1CSR1 register
    
    #--------------------------------------------#
    # Flush BTB - Set BBFI bit in BUCSR          #
    #--------------------------------------------#
    e_lis   r3, 0x0
    e_or2i   r3,  0x0200
    mtspr 1013, r3
    #--------------------------------------------#
    # Enable BTB - Set BPEN bit in BUCSR         #
    #--------------------------------------------#
    e_lis   r3, 0x0
    e_or2i   r3,  0x0001
    mtspr 1013, r3
    #--------------------------------------------#
    # Configure FLASH Slave - XBAR_MPR0/SGPCR0   #
    #--------------------------------------------#
    #       Master         |   Priority          #
    #   M0 CPU Instruction :      1              #
    #   M1 CPU Data/Nexus  :      0              #
    #   M2 eDMA            :      2              #
    #   M3 GFX2D/GXG       :      5              #
    #   M4 VIU             :      6              #
    #   M5 DCULite         :      4              #
    #   M6 DCU             :      3              #
    #   M7 (Reserved)      :      7              #
    #--------------------------------------------#
    # Park CPU Instruction (M0) on Flash         #
    #--------------------------------------------#
    # r3 - XBAR_Base Address                     #
    # r4 - XBAR_MPR0 Value                       #
    # r5 - XBAR_SGPCR0 Value                     #
    #--------------------------------------------#
    e_lis   r3, 0xFFF0
    e_or2i   r3,  0x4000
    e_lis   r4, 0x7346
    e_or2i   r4,  0x5201
    e_stw   r4, 0x0(r3)           # Write to MPR0
    e_lis   r5, 0000
    e_or2i   r5,  0x0000
    e_stw   r5, 0x10(r3)          # Write to SGPCR0
    #--------------------------------------------#
    # Configure SRAM Slave - XBAR_MPR2/SGPCR2    #
    #--------------------------------------------#
    #       Master         |   Priority          #
    #   M0 CPU Instruction :      1              #
    #   M1 CPU Data/Nexus  :      0              #
    #   M2 eDMA            :      2              #
    #   M3 GFX2D/GXG       :      6              #
    #   M4 VIU             :      5              #
    #   M5 DCULite         :      4              #
    #   M6 DCU             :      3              #
    #   M7 (Reserved)      :      7              #
    #--------------------------------------------#
    # Park CPU Data (M1) on RAM                  #
    #--------------------------------------------#
    # r4 - XBAR_MPR1 Value                       #
    # r5 - XBAR_SGPCR1 Value                     #
    #--------------------------------------------#
    e_lis   r4, 0x7345
    e_or2i   r4,  0x6201
    e_stw   r4, 0x200(r3)         # Write to MPR2
    e_lis   r5, 0x0000
    e_or2i   r5,  0x0001
    e_stw   r5, 0x210(r3)         # Write to SGPCR2

    e_bl        romcopy

.else
 
##---------------------------------------------------------------------------       
## Main Code - May Need Optimizations Here (Flash, Cache, etc)
##---------------------------------------------------------------------------       
#--------------------------------------------#
# Load Flash BIUCR Setting into R7           #
##############################################
## CHANGE FOR DIFFERENT FSYS:               ##
##  Up to 147MHz : 0x00538CFD               ##
##  Up to 135MHz : 0x00534BFD               ##
##  Up to 102MHz : 0x00532AFD               ##
##  Up to 82MHz  : 0x005329FD               ##
##
##  Leopard PFCR0 & 1 are a differnt format ##
##  3 WS needed for 120MHZ                  ##
##  3 Read, 3 Write, 3 Pipeline             ##
##  All Prefetch and Buffers Enabled        ## 
##  PFCR0 = 0x18C7FDFD                      ##
##############################################
#--------------------------------------------#
     lis   r7, 0x18C7
     ori   r7, r7, 0xFDFD
#--------------------------------------------#
# Load Flash BIUCR Address into R6           #
#--------------------------------------------#
     lis   r6, 0xC3F8
     ori   r6, r6, 0x801C
 
 SRAMLOAD:
#--------------------------------------------#
# Load BIUCR write instruction into R8, R9 & #
#--------------------------------------------#
     lis   r8, 0x90E6
     ori   r8, r8, 0x0000    # R8 = "stw r7, 0x0(r6)"
     lis   r9, 0x4C00
     ori   r9, r9, 0x012C    # R9 = "isync" added 02 December 2009
     lis   r10, 0x4E80
     ori   r10, r10, 0x0020  # R10 = "blr"
 
#--------------------------------------------#
# Load RAM address into R11                  #
#--------------------------------------------#
     lis   r11, _BIUCR_RAM_ADDR@h
     addi  r11,r11, _BIUCR_RAM_ADDR@l
 
#--------------------------------------------#
# Store Instructions in RAM, then branch and #
# execute instructions to setup BIUCR        #
#--------------------------------------------#
     stw   r8, 0x0(r11);
     stw   r9, 0x4(r11);
     stw   r10, 0x8(r11);
#--------------------------------------------#
# Load SRAM Wait State Setting into R3       #
##############################################
## CHANGE FOR DIFFERENT FSYS:               ##
##  >=100MHz   : 0x40000000                 ##
##  <100MHz    : 0x00000000                 ##
##############################################
#--------------------------------------------#
        lis   r3, 0x4000
        ori   r3, r3, 0x0000
#--------------------------------------------#
# Load SRAM Wait State Register Address into #
# R4 and perform write                       #
#--------------------------------------------#
        lis   r4, 0xFFF4
        ori   r4, r4, 0x0024
        stw   r3, 0x0(r4)
cfg_ICACHE:

    #--------------------------------------------#
    # Invalidate Instruction Cache - Set ICINV   #
    # bit in L1CSR1 Register                     #
    #--------------------------------------------#
    lis   r5, 0x0000
    ori   r5, r5, 0x0002
    mtspr l1csr1,r5

    #--------------------------------------------#
    # Mask out ICINV and ICABT to see if         #
    # invalidation is complete (i.e. ICINV=0,    #
    # ICABT=0)                                   #
    #--------------------------------------------#
label_ICINV_check:
    #--------------------------------------------#
    # Load Registers with Masks:                 #
    # Load ICINV mask into R8                    #
    # Load ICABT mask into R7                    #
    # Load ICABT clear mask into R11             #
    #--------------------------------------------#
    lis   r8, 0x0000
    ori   r8, r8, 0x0002
    lis   r7, 0x0000
    ori   r7, r7, 0x0004
    lis   r11, 0xFFFF
    ori   r11, r11, 0xFFFB
CHECK_ICINV:

    #--------------------------------------------#
    # Read L1CSR1 register, store in r9          #
    #--------------------------------------------#
    mfspr r9, l1csr1
    #--------------------------------------------#
    # check for an ABORT of the cache invalidate #
    # operation                                  #
    #--------------------------------------------#
    and.  r10, r7, r9
    beq   NO_ABORT
    #--------------------------------------------#
    # If abort detected, clear ICABT bit and     #
    # re-run invalidation                        #
    #--------------------------------------------#
    and.  r10, r11, r9
    mtspr l1csr1, r10
    b     cfg_ICACHE

NO_ABORT:
    #--------------------------------------------#
    # Check that invalidation has completed -    #
    # (ICINV=0). Branch if invalidation not      #
    # complete.                                  #
    #--------------------------------------------#
    and.  r10, r8, r9
    bne CHECK_ICINV

    #--------------------------------------------#
    # Enable cache the ICache by performing a    #
    # read/modify/write of the ICE bit in the    #
    # L1CSR1 register                            #
    #--------------------------------------------#
    mfspr r5, l1csr1
    oris  r5, r5, 0x0000
    ori   r5, r5, 0x0001    # Store L1CSR1 value to R5 (ICE=1)
    isync
    msync
    mtspr l1csr1, r5        # Write R5 to L1CSR1 register
    
    #--------------------------------------------#
    # Flush BTB - Set BBFI bit in BUCSR          #
    #--------------------------------------------#
    lis   r3, 0x0
    ori   r3, r3, 0x0200
    mtspr 1013, r3
    #--------------------------------------------#
    # Enable BTB - Set BPEN bit in BUCSR         #
    #--------------------------------------------#
    lis   r3, 0x0
    ori   r3, r3, 0x0001
    mtspr 1013, r3
    #--------------------------------------------#
    # Configure FLASH Slave - XBAR_MPR0/SGPCR0   #
    #--------------------------------------------#
    #       Master         |   Priority          #
    #   M0 CPU Instruction :      1              #
    #   M1 CPU Data/Nexus  :      0              #
    #   M2 eDMA            :      2              #
    #   M3 GFX2D/GXG       :      5              #
    #   M4 VIU             :      6              #
    #   M5 DCULite         :      4              #
    #   M6 DCU             :      3              #
    #   M7 (Reserved)      :      7              #
    #--------------------------------------------#
    # Park CPU Instruction (M0) on Flash         #
    #--------------------------------------------#
    # r3 - XBAR_Base Address                     #
    # r4 - XBAR_MPR0 Value                       #
    # r5 - XBAR_SGPCR0 Value                     #
    #--------------------------------------------#
    lis   r3, 0xFFF0
    ori   r3, r3, 0x4000
    lis   r4, 0x7346
    ori   r4, r4, 0x5201
    stw   r4, 0x0(r3)           # Write to MPR0
    lis   r5, 0000
    ori   r5, r5, 0x0000
    stw   r5, 0x10(r3)          # Write to SGPCR0
    #--------------------------------------------#
    # Configure SRAM Slave - XBAR_MPR2/SGPCR2    #
    #--------------------------------------------#
    #       Master         |   Priority          #
    #   M0 CPU Instruction :      1              #
    #   M1 CPU Data/Nexus  :      0              #
    #   M2 eDMA            :      2              #
    #   M3 GFX2D/GXG       :      6              #
    #   M4 VIU             :      5              #
    #   M5 DCULite         :      4              #
    #   M6 DCU             :      3              #
    #   M7 (Reserved)      :      7              #
    #--------------------------------------------#
    # Park CPU Data (M1) on RAM                  #
    #--------------------------------------------#
    # r4 - XBAR_MPR1 Value                       #
    # r5 - XBAR_SGPCR1 Value                     #
    #--------------------------------------------#
    lis   r4, 0x7345
    ori   r4, r4, 0x6201
    stw   r4, 0x200(r3)         # Write to MPR2
    lis   r5, 0x0000
    ori   r5, r5, 0x0001
    stw   r5, 0x210(r3)         # Write to SGPCR2

    bl        main

.endif  

##---------------------------------------------------------------------------    

        
