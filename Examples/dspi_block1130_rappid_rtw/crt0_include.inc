
##---------------------------------------------------------------------------
## Initialise GPR's for LockStep Mode 
## This REALLY IS A MUST!
## This is the version given to me by Gene Fortunately in Austin
##---------------------------------------------------------------------------

# Set the MSR[SPE] bit so code can use "evmergelo" instruction.
 .equ     MSR_Mask, 0x02000000  
 lis     r5, 0                           
 mfmsr   r5                     
 lis     r6, MSR_Mask@h
 ori     r6, r6, MSR_Mask@l                                                                
 or      r5, r5,r6 
 mtmsr   r5                                                                                              
 isync 

# 1.  32 64-bit GPR0-31
 
 lis       r1, 0      # Initialize the lower 32-bits of GPR1 to 0 
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

 mtspr 61,r31         #DEAR

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
 
 
 	// initialize MAS0 - MAS6; actual TLB configuration done later
	mtmas0 r0
	mtmas1 r0
	mtmas2 r0
	mtmas3 r0
	mtmas4 r0
	// no MAS5
	mtmas6 r0
	
	// init ACC
	evmra r0, r4
	evmra r0, r4
	
	mtcrf 0xFF,r0 // CFR
	mtspr 9,r0 // COUNT

;######################################################################
;#                           End of File                        
;######################################################################
