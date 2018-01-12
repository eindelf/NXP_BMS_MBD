#**************************************************************************/
#* FILE NAME: Optimise_BookE_MPC5643L.s    COPYRIGHT (c) Freescale 2009   */
#*                                                All Rights Reserved     */
#* DESCRIPTION:                                                           */
#* This software will configure the MPC5643L hardware features to achieve */
#* optimal performance.                                                   */
#*                                                                        */
#* Please be aware that further performance improvements may be made by   */
#* optimising compiler settings, and tweaking MPC5643L hardware features  */
#* for a specific application.                                            */
#=========================================================================*/
#*                                                                        */
#*========================================================================*/
#* REV      AUTHOR        DATE        DESCRIPTION OF CHANGE               */
#* ---   -----------    ----------    ---------------------               */
#* 0.1    R. Moran       13/08/2009    Initial Version                    */
#* 0.2    R. Dees        02/DEC/2009   Added isync in SRAMLOAD for flash  */
#* 0.3    D. Mckenna     01/02/2010    Altered for MPC5645S               */
#* 0.4    S. OBrien      03/19/2010    Modified for Leopard (MPC564xL)    */
#*        Most of this could/should be done after main() due to FSYS      */
#**************************************************************************/


#--------------------------------------------#

   .global     optimise_MCU

#--------------------------------------------------------------------------#
# Specify 8bytes of available memory in RAM for configuring Flash BIUCR    #
# Register - wait states, prefetch, etc...                                 #
#--------------------------------------------------------------------------#
# Use ABSOLUTE Address or Label from Linker File section.                  #
# Example of linker section below (place in linker file:                   #
# Section {                                                                #
#     .BIUCR_RAM PAD(8) : {} > int_sram                                    #
#     __BIUCR_RAM_START = ADDR(.BIUCR_RAM); }                              #
#--------------------------------------------------------------------------#
# .equ _BIUCR_RAM_ADDR, __BIUCR_RAM_START                                  #
#--------------------------------------------------------------------------#
   .equ _BIUCR_RAM_ADDR, 0x40000000

#**************************************************************************/
# FUNCTION     : cfg_FLASH                                                */
# PURPOSE      : This function configures the Flash wait states, prefetch */
#                and other BIU settings.                                  */
#                SEQUENCE:                                                */
#                - Load Flash settings and BIUCR Address into R6 & R7     */
#                - Copy "stw" and "blr" instructions into RAM             */
#                - Branch to RAM, and execute above instructions to write */
#                  flash settings to BIUCR                                */
#**************************************************************************/
cfg_FLASH:

    #--------------------------------------------#
    # Save Link Register as this will be modified#
    #--------------------------------------------#
    mflr  r3
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
    ##  PFCR0 = 0x18C7FDFD                                              ##
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
    # R1                                         #
    #--------------------------------------------#
    lis   r8, 0xD076
    ori   r8, r8, 0x0001    # R8 = "stw r7, 0x0(r6), isync"
    lis   r9, 0x0004
    ori   r9, r9, 0x0000    # R9 = "blr"


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
    mtlr  r11
    blrl

#**************************************************************************/
# FUNCTION     : cfg_SRAM                                                 */
# PURPOSE      : This function configure the SRAM Wait State              */
#                SEQUENCE:                                                */
#                - Configure SRAM Wait States                             */
#**************************************************************************/
cfg_SRAM:

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

#**************************************************************************/
# END OF cfg_SRAM                                                         */
#**************************************************************************/

#**************************************************************************/
# FUNCTION     : cfg_ICACHE                                               */
# PURPOSE      : This function initializes the ICACHE, using L1CSR1       */
#                register.                                                */
#                SEQUENCE:                                                */
#                - Start ICache Invalidate                                */
#                - Wait for invalidation to complete, check for Abort     */
#                  operation and restart invalidation if detected         */
#                - Enable ICache by setting ICE bit                       */
#**************************************************************************/
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

#**************************************************************************/
# END OF cfg_ICACHE                                                       */
#**************************************************************************/

#**************************************************************************/
# FUNCTION     : cfg_BTB                                                  */
# PURPOSE      : This function enables the Branch Target Buffer           */
#                SEQUENCE:                                                */
#                - Flush Branch Target Buffer (BUCSR Register)            */
#                - Enable Branch Target Buffer (BUCSR Register)           */
#**************************************************************************/
cfg_BTB:
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

#**************************************************************************/
# END OF cfg_BTB                                                          */
#**************************************************************************/

#**************************************************************************/
# FUNCTION     : cfg_XBAR                                                 */
# PURPOSE      : This function optimises the XBAR                         */
#                SEQUENCE:                                                */
#                - Write Master Priority Registers for RAM and Flash      */
#                  with optimised settings                                */
#**************************************************************************/
cfg_XBAR:
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

#**************************************************************************/
# END OF cfg_XBAR                                                         */
#**************************************************************************/

