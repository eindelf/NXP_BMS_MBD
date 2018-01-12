/*
 *                                RAppID
 *                         Freescale Semiconductor Inc.
 * Target Compiler        : GreenHills
 * Target Part            : MPC5643L
*/

 
 
MEMORY
{
    rcw:                            org=0x00000000, len=0x00000008
    init:                           org=0x00000020, len=0x00001FE0
    int_flash:                      org=0x00002000, len=0x000DE000
    exception_handlers:             org=0x000E0000, len=0x00002000
    vector_table:                   org=0x000E2000, len=0x00002000
    int_sram:                       org=0x40000000, len=0x0000F800
    stack_ram:                      org=0x4000F800, len=0x00000800
}


SECTIONS
{





        .__bam_bootarea  LOAD (0x0):        >rcw



        .init :        >init
        .init_vle  LOAD (0x20):        >init



        .__argv :        >int_flash
        .__env :        >int_flash
        .text :        >int_flash
        .text_vle :       >int_flash
        .vletext :        >int_flash
        .code :        >int_flash
        .rodata :        >int_flash
        .ctors  ALIGN (0x4): { *(.ctors) }       >int_flash
        .dtors  ALIGN (0x4): { *(.dtors) }       >int_flash
        .sdata2 :        >int_flash
        .sbss2 :        >int_flash

        .exec_vect  LOAD (0xE0000):        >exception_handlers
        .exec_vect_Vle  LOAD (0xE0000):        >exception_handlers



        .vects               LOAD (0xE2000):        >vector_table


        __DATA_ROM =ADDR(.sbss2) + SIZEOF(.sbss2);
        __DATA_ROM_ADDR = __DATA_ROM;

        __DATA_RAM =ADDR(int_sram);

        .data  LOAD (__DATA_ROM):        >int_sram
        .sdabase  LOAD (ADDR(.sdabase) - ADDR(.data) + __DATA_ROM):        >int_sram
        .sdata  LOAD (ADDR(.sdata) - ADDR(.sdabase) + __DATA_ROM):        >int_sram
        __DATA_END=.;

        __BSS_START = .;

        .sbss : { *(.sbss) }       >int_sram
        .bss : { *(.bss) }       >int_sram
        .tibss :        >int_sram
        __BSS_END = .;

        .tidata :        >int_sram
        ._HEAP_START  ALIGN (0x10):        >int_sram
        __SP_INIT =ADDR(stack_ram)+SIZEOF(stack_ram);

        __SP_END=ADDR(stack_ram);

        __HEAP_END=__SP_END;

        __DATA_SIZE = (__DATA_END)-(__DATA_RAM);

        __BSSDATA_SIZE = (__BSS_END)-(__BSS_START);

}
