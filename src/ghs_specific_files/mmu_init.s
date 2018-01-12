;
;######################################################################
;                                RAppID
;           Rapid Application Initialization and Documentation Tool
;                         Freescale Semiconductor Inc.
;
;######################################################################
;
; Project Name           : lsm_ghs_flash_vle
;
; Project File           : lsm_ghs_flash_vle.rsp
;
; Revision Number        : 1.0
;
; Tool Version           : Engineering Release
;
; file                   : mmu_init_p0.s
;
; Target Compiler        : GreenHills
;
; Target Part            : MPC5643L
;
; Part Errata Fixes      : none
;
; Project Last Save Date : 29-Apr-2011 18:38:42
;
; Created on Date        : 29-Apr-2011 18:38:43
;
; Brief Description      : This file contains TLB entry configuration for MMU 
;
;******************************************************************************* 
;
; Detail Description     : This file contains setup for Memory Management Unit
;                         Setup Registers such as MAS0,MAS1,MAS2 and MAS3
;                         corresponding to each MMU TLB entry
;
;******************************************************************************* 
;
;######################################################################
;

 
 


#ifdef __vle
.section ".vletext", "vax"
.align 1
.vle
;# /* ----------------------------------------------------------- */

;# /*   Memory Management Unit Setup Registers                     */

;# /* ----------------------------------------------------------- */

;# /* ----------------------------------------------------------- */
;# /*   MMU TLB entry 1 Entry Name : Internal Flash Memory                    */
;# /* ----------------------------------------------------------- */
    e_lis   r10, 0x1001
    e_or2i   r10, 0x0000
    mtspr 624, r10        
;#             /* ----------------------------------------------- */
;#             /*   MAS0 Register (Set to value 0x10010000)        */
;#             /* ----------------------------------------------- */
;#             /* NV: TLB Entry No: 1         */
    e_lis   r11, 0xC000
    e_or2i   r11, 0x0700
    mtspr 625, r11        
;#             /* ----------------------------------------------- */
;#             /*   MAS1 Register (Set to value 0xC0000700)        */
;#             /* ----------------------------------------------- */
;#             /* VALID: TLB Valid Entry: Enabled     */
;#             /* IPROT: Invalidation Enabled: Enabled     */
;#             /* TID: Process ID: 0                */
;#             /* TS: Translation Address Space: Disabled   */
;#             /* TSIZE: Page Size: 16 MB              */
    e_lis   r12, 0x0000
    e_or2i   r12, 0x0020
    mtspr 626, r12        
;#             /* ----------------------------------------------- */
;#             /*   MAS2 Register (Set to value 0x00000020)        */
;#             /* ----------------------------------------------- */
;#             /* EPN: Effective Page Number: 00000000 */
;#             /* VLE: PowerPC VLE: Enabled    */
;#             /* W: Write Through Required: Disabled      */
;#             /* CI: Cache Inhibited: Disabled            */
;#             /* E: Endianess:     Big-endian            */
    e_lis   r9, 0x0000
    e_or2i   r9, 0x003F
    mtspr 627, r9        
;#             /* ----------------------------------------------- */
;#             /*   MAS3 Register (Set to value 0x0000003F)        */
;#             /* ----------------------------------------------- */
;#             /* RPN: Real Page Number: 00000000    */
;#             /* UX: User Execute Permission: Enabled    */
;#             /* SX: Supervisor Execution Permission: Enabled                 */
;#             /* UW: User Write Permission: Enabled    */
;#             /* SW: Supervisor Write Permission: Enabled               */
;#             /* UR: User Read Permission: Enabled     */
;#             /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;#     /* Use special buffer entry write to add entry to TLB*/
    se_isync        

;# /* ----------------------------------------------------------- */
;# /*   MMU TLB entry 2 Entry Name : SRAM_0                    */
;# /* ----------------------------------------------------------- */
    e_lis   r10, 0x1002
    e_or2i   r10, 0x0000
    mtspr 624, r10        
;#             /* ----------------------------------------------- */
;#             /*   MAS0 Register (Set to value 0x10020000)        */
;#             /* ----------------------------------------------- */
;#             /* NV: TLB Entry No: 2         */
    e_lis   r11, 0xC000
    e_or2i   r11, 0x0380
    mtspr 625, r11        
;#             /* ----------------------------------------------- */
;#             /*   MAS1 Register (Set to value 0xC0000380)        */
;#             /* ----------------------------------------------- */
;#             /* VALID: TLB Valid Entry: Enabled     */
;#             /* IPROT: Invalidation Enabled: Enabled     */
;#             /* TID: Process ID: 0                */
;#             /* TS: Translation Address Space: Disabled   */
;#             /* TSIZE: Page Size: 128 KB              */
    e_lis   r12, 0x4000
    e_or2i   r12, 0x0028
    mtspr 626, r12        
;#             /* ----------------------------------------------- */
;#             /*   MAS2 Register (Set to value 0x40000028)        */
;#             /* ----------------------------------------------- */
;#             /* EPN: Effective Page Number: 010000000000000 */
;#             /* VLE: PowerPC VLE: Enabled    */
;#             /* W: Write Through Required: Disabled      */
;#             /* CI: Cache Inhibited: Enabled             */
;#             /* E: Endianess:     Big-endian            */
    e_lis   r9, 0x4000
    e_or2i   r9, 0x003F
    mtspr 627, r9        
;#             /* ----------------------------------------------- */
;#             /*   MAS3 Register (Set to value 0x4000003F)        */
;#             /* ----------------------------------------------- */
;#             /* RPN: Real Page Number: 010000000000000    */
;#             /* UX: User Execute Permission: Enabled    */
;#             /* SX: Supervisor Execution Permission: Enabled                 */
;#             /* UW: User Write Permission: Enabled    */
;#             /* SW: Supervisor Write Permission: Enabled               */
;#             /* UR: User Read Permission: Enabled     */
;#             /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;#     /* Use special buffer entry write to add entry to TLB*/
    se_isync        

;# /* ----------------------------------------------------------- */
;# /*   MMU TLB entry 3 Entry Name : Peripherals_A                    */
;# /* ----------------------------------------------------------- */
    e_lis   r10, 0x1003
    e_or2i   r10, 0x0000
    mtspr 624, r10        
;#             /* ----------------------------------------------- */
;#             /*   MAS0 Register (Set to value 0x10030000)        */
;#             /* ----------------------------------------------- */
;#             /* NV: TLB Entry No: 3         */
    e_lis   r11, 0xC000
    e_or2i   r11, 0x0500
    mtspr 625, r11        
;#             /* ----------------------------------------------- */
;#             /*   MAS1 Register (Set to value 0xC0000500)        */
;#             /* ----------------------------------------------- */
;#             /* VALID: TLB Valid Entry: Enabled     */
;#             /* IPROT: Invalidation Enabled: Enabled     */
;#             /* TID: Process ID: 0                */
;#             /* TS: Translation Address Space: Disabled   */
;#             /* TSIZE: Page Size: 1 MB              */
    e_lis   r12, 0xC3F0
    e_or2i   r12, 0x0028
    mtspr 626, r12        
;#             /* ----------------------------------------------- */
;#             /*   MAS2 Register (Set to value 0xC3F00028)        */
;#             /* ----------------------------------------------- */
;#             /* EPN: Effective Page Number: 110000111111 */
;#             /* VLE: PowerPC VLE: Enabled    */
;#             /* W: Write Through Required: Disabled      */
;#             /* CI: Cache Inhibited: Enabled             */
;#             /* E: Endianess:     Big-endian            */
    e_lis   r9, 0xC3F0
    e_or2i   r9, 0x003F
    mtspr 627, r9        
;#             /* ----------------------------------------------- */
;#             /*   MAS3 Register (Set to value 0xC3F0003F)        */
;#             /* ----------------------------------------------- */
;#             /* RPN: Real Page Number: 110000111111    */
;#             /* UX: User Execute Permission: Enabled    */
;#             /* SX: Supervisor Execution Permission: Enabled                 */
;#             /* UW: User Write Permission: Enabled    */
;#             /* SW: Supervisor Write Permission: Enabled               */
;#             /* UR: User Read Permission: Enabled     */
;#             /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;#     /* Use special buffer entry write to add entry to TLB*/
    se_isync        

;# /* ----------------------------------------------------------- */
;# /*   MMU TLB entry 4 Entry Name : Peripherals_B                    */
;# /* ----------------------------------------------------------- */
    e_lis   r10, 0x1004
    e_or2i   r10, 0x0000
    mtspr 624, r10        
;#             /* ----------------------------------------------- */
;#             /*   MAS0 Register (Set to value 0x10040000)        */
;#             /* ----------------------------------------------- */
;#             /* NV: TLB Entry No: 4         */
    e_lis   r11, 0xC000
    e_or2i   r11, 0x0580
    mtspr 625, r11        
;#             /* ----------------------------------------------- */
;#             /*   MAS1 Register (Set to value 0xC0000580)        */
;#             /* ----------------------------------------------- */
;#             /* VALID: TLB Valid Entry: Enabled     */
;#             /* IPROT: Invalidation Enabled: Enabled     */
;#             /* TID: Process ID: 0                */
;#             /* TS: Translation Address Space: Disabled   */
;#             /* TSIZE: Page Size: 2 MB              */
    e_lis   r12, 0xFFE0
    e_or2i   r12, 0x0028
    mtspr 626, r12        
;#             /* ----------------------------------------------- */
;#             /*   MAS2 Register (Set to value 0xFFE00028)        */
;#             /* ----------------------------------------------- */
;#             /* EPN: Effective Page Number: 11111111111 */
;#             /* VLE: PowerPC VLE: Enabled    */
;#             /* W: Write Through Required: Disabled      */
;#             /* CI: Cache Inhibited: Enabled             */
;#             /* E: Endianess:     Big-endian            */
    e_lis   r9, 0xFFE0
    e_or2i   r9, 0x003F
    mtspr 627, r9        
;#             /* ----------------------------------------------- */
;#             /*   MAS3 Register (Set to value 0xFFE0003F)        */
;#             /* ----------------------------------------------- */
;#             /* RPN: Real Page Number: 11111111111    */
;#             /* UX: User Execute Permission: Enabled    */
;#             /* SX: Supervisor Execution Permission: Enabled                 */
;#             /* UW: User Write Permission: Enabled    */
;#             /* SW: Supervisor Write Permission: Enabled               */
;#             /* UR: User Read Permission: Enabled     */
;#             /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;#     /* Use special buffer entry write to add entry to TLB*/
    se_isync        

#else
.align 2
.novle
;# /* ----------------------------------------------------------- */
;# /*   MMU TLB entry 1 Entry Name : Internal Flash Memory                    */
;# /* ----------------------------------------------------------- */
    lis   r10, 0x1001
    ori   r10, r10, 0x0000
    mtspr 624, r10        
;#             /* ----------------------------------------------- */
;#             /*   MAS0 Register (Set to value 0x10010000)        */
;#             /* ----------------------------------------------- */
;#             /* NV: TLB Entry No: 1         */
    lis   r11, 0xC000
    ori   r11, r11, 0x0700
    mtspr 625, r11        
;#             /* ----------------------------------------------- */
;#             /*   MAS1 Register (Set to value 0xC0000700)        */
;#             /* ----------------------------------------------- */
;#             /* VALID: TLB Valid Entry: Enabled     */
;#             /* IPROT: Invalidation Enabled: Enabled     */
;#             /* TID: Process ID: 0                */
;#             /* TS: Translation Address Space: Disabled   */
;#             /* TSIZE: Page Size: 16 MB              */
    lis   r12, 0x0000
    ori   r12, r12, 0x0020
    mtspr 626, r12        
;#             /* ----------------------------------------------- */
;#             /*   MAS2 Register (Set to value 0x00000020)        */
;#             /* ----------------------------------------------- */
;#             /* EPN: Effective Page Number: 00000000 */
;#             /* VLE: PowerPC VLE: Enabled    */
;#             /* W: Write Through Required: Disabled      */
;#             /* CI: Cache Inhibited: Disabled            */
;#             /* E: Endianess:     Big-endian            */
    lis   r9, 0x0000
    ori   r9, r9, 0x003F
    mtspr 627, r9        
;#             /* ----------------------------------------------- */
;#             /*   MAS3 Register (Set to value 0x0000003F)        */
;#             /* ----------------------------------------------- */
;#             /* RPN: Real Page Number: 00000000    */
;#             /* UX: User Execute Permission: Enabled    */
;#             /* SX: Supervisor Execution Permission: Enabled                 */
;#             /* UW: User Write Permission: Enabled    */
;#             /* SW: Supervisor Write Permission: Enabled               */
;#             /* UR: User Read Permission: Enabled     */
;#             /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;#     /* Use special buffer entry write to add entry to TLB*/
    isync        

;# /* ----------------------------------------------------------- */
;# /*   MMU TLB entry 2 Entry Name : SRAM_0                    */
;# /* ----------------------------------------------------------- */
    lis   r10, 0x1002
    ori   r10, r10, 0x0000
    mtspr 624, r10        
;#             /* ----------------------------------------------- */
;#             /*   MAS0 Register (Set to value 0x10020000)        */
;#             /* ----------------------------------------------- */
;#             /* NV: TLB Entry No: 2         */
    lis   r11, 0xC000
    ori   r11, r11, 0x0380
    mtspr 625, r11        
;#             /* ----------------------------------------------- */
;#             /*   MAS1 Register (Set to value 0xC0000380)        */
;#             /* ----------------------------------------------- */
;#             /* VALID: TLB Valid Entry: Enabled     */
;#             /* IPROT: Invalidation Enabled: Enabled     */
;#             /* TID: Process ID: 0                */
;#             /* TS: Translation Address Space: Disabled   */
;#             /* TSIZE: Page Size: 128 KB              */
    lis   r12, 0x4000
    ori   r12, r12, 0x0028
    mtspr 626, r12        
;#             /* ----------------------------------------------- */
;#             /*   MAS2 Register (Set to value 0x40000028)        */
;#             /* ----------------------------------------------- */
;#             /* EPN: Effective Page Number: 010000000000000 */
;#             /* VLE: PowerPC VLE: Enabled    */
;#             /* W: Write Through Required: Disabled      */
;#             /* CI: Cache Inhibited: Enabled             */
;#             /* E: Endianess:     Big-endian            */
    lis   r9, 0x4000
    ori   r9, r9, 0x003F
    mtspr 627, r9        
;#             /* ----------------------------------------------- */
;#             /*   MAS3 Register (Set to value 0x4000003F)        */
;#             /* ----------------------------------------------- */
;#             /* RPN: Real Page Number: 010000000000000    */
;#             /* UX: User Execute Permission: Enabled    */
;#             /* SX: Supervisor Execution Permission: Enabled                 */
;#             /* UW: User Write Permission: Enabled    */
;#             /* SW: Supervisor Write Permission: Enabled               */
;#             /* UR: User Read Permission: Enabled     */
;#             /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;#     /* Use special buffer entry write to add entry to TLB*/
    isync        

;# /* ----------------------------------------------------------- */
;# /*   MMU TLB entry 3 Entry Name : Peripherals_A                    */
;# /* ----------------------------------------------------------- */
    lis   r10, 0x1003
    ori   r10, r10, 0x0000
    mtspr 624, r10        
;#             /* ----------------------------------------------- */
;#             /*   MAS0 Register (Set to value 0x10030000)        */
;#             /* ----------------------------------------------- */
;#             /* NV: TLB Entry No: 3         */
    lis   r11, 0xC000
    ori   r11, r11, 0x0500
    mtspr 625, r11        
;#             /* ----------------------------------------------- */
;#             /*   MAS1 Register (Set to value 0xC0000500)        */
;#             /* ----------------------------------------------- */
;#             /* VALID: TLB Valid Entry: Enabled     */
;#             /* IPROT: Invalidation Enabled: Enabled     */
;#             /* TID: Process ID: 0                */
;#             /* TS: Translation Address Space: Disabled   */
;#             /* TSIZE: Page Size: 1 MB              */
    lis   r12, 0xC3F0
    ori   r12, r12, 0x0028
    mtspr 626, r12        
;#             /* ----------------------------------------------- */
;#             /*   MAS2 Register (Set to value 0xC3F00028)        */
;#             /* ----------------------------------------------- */
;#             /* EPN: Effective Page Number: 110000111111 */
;#             /* VLE: PowerPC VLE: Enabled    */
;#             /* W: Write Through Required: Disabled      */
;#             /* CI: Cache Inhibited: Enabled             */
;#             /* E: Endianess:     Big-endian            */
    lis   r9, 0xC3F0
    ori   r9, r9, 0x003F
    mtspr 627, r9        
;#             /* ----------------------------------------------- */
;#             /*   MAS3 Register (Set to value 0xC3F0003F)        */
;#             /* ----------------------------------------------- */
;#             /* RPN: Real Page Number: 110000111111    */
;#             /* UX: User Execute Permission: Enabled    */
;#             /* SX: Supervisor Execution Permission: Enabled                 */
;#             /* UW: User Write Permission: Enabled    */
;#             /* SW: Supervisor Write Permission: Enabled               */
;#             /* UR: User Read Permission: Enabled     */
;#             /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;#     /* Use special buffer entry write to add entry to TLB*/
    isync        

;# /* ----------------------------------------------------------- */
;# /*   MMU TLB entry 4 Entry Name : Peripherals_B                    */
;# /* ----------------------------------------------------------- */
    lis   r10, 0x1004
    ori   r10, r10, 0x0000
    mtspr 624, r10        
;#             /* ----------------------------------------------- */
;#             /*   MAS0 Register (Set to value 0x10040000)        */
;#             /* ----------------------------------------------- */
;#             /* NV: TLB Entry No: 4         */
    lis   r11, 0xC000
    ori   r11, r11, 0x0580
    mtspr 625, r11        
;#             /* ----------------------------------------------- */
;#             /*   MAS1 Register (Set to value 0xC0000580)        */
;#             /* ----------------------------------------------- */
;#             /* VALID: TLB Valid Entry: Enabled     */
;#             /* IPROT: Invalidation Enabled: Enabled     */
;#             /* TID: Process ID: 0                */
;#             /* TS: Translation Address Space: Disabled   */
;#             /* TSIZE: Page Size: 2 MB              */
    lis   r12, 0xFFE0
    ori   r12, r12, 0x0028
    mtspr 626, r12        
;#             /* ----------------------------------------------- */
;#             /*   MAS2 Register (Set to value 0xFFE00028)        */
;#             /* ----------------------------------------------- */
;#             /* EPN: Effective Page Number: 11111111111 */
;#             /* VLE: PowerPC VLE: Enabled    */
;#             /* W: Write Through Required: Disabled      */
;#             /* CI: Cache Inhibited: Enabled             */
;#             /* E: Endianess:     Big-endian            */
    lis   r9, 0xFFE0
    ori   r9, r9, 0x003F
    mtspr 627, r9        
;#             /* ----------------------------------------------- */
;#             /*   MAS3 Register (Set to value 0xFFE0003F)        */
;#             /* ----------------------------------------------- */
;#             /* RPN: Real Page Number: 11111111111    */
;#             /* UX: User Execute Permission: Enabled    */
;#             /* SX: Supervisor Execution Permission: Enabled                 */
;#             /* UW: User Write Permission: Enabled    */
;#             /* SW: Supervisor Write Permission: Enabled               */
;#             /* UR: User Read Permission: Enabled     */
;#             /* SR: Supervisor Read Permission: Enabled     */
    msync 
    tlbwe
        ;#     /* Use special buffer entry write to add entry to TLB*/
    isync        

#endif

 
;
;######################################################################
;                           End of File
;######################################################################
;

