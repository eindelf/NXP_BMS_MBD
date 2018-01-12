/*
 *                                RAppID
 *                         Freescale Semiconductor Inc.
 * Target Compiler        : GreenHills
 * Target Part            : MPC5643L
*/
 
MEMORY
{
    exception_handlers:             org=0x40000000, len=0x00002000
    vector_table:                   org=0x40002000, len=0x00001000
    int_sram:                       org=0x40003000, len=0x0000C800
    stack_ram:                      org=0x4000F800, len=0x00000800
}

SECTIONS
{
        .exec_vect  LOAD (0x40000000):        >exception_handlers
        .exec_vect_Vle  LOAD (0x40000000):        >exception_handlers

        .vects  LOAD (0x40002000):        >vector_table

        .__argv :        >int_sram
        .__env :        >int_sram
        .init :        >int_sram
        .init_vle :        >int_sram
        .text :        >int_sram
        .text_vle :        >int_sram
        .vletext :        >int_sram
        .rdata :        >int_sram
        .rodata :        >int_sram
        .sdata2 :        >int_sram
        .sbss2 :        >int_sram
        .data : { *(.data) }       >int_sram
        .sdabase  ALIGN (0x10):        >int_sram
        .sdata : { *(.sdata) }       >int_sram
        __BSS_START=.;
        .sbss : { *(.sbss) }       >int_sram
        .bss : { *(.bss) }       >int_sram
        .tibss :        >int_sram
        __BSS_END=.;
        .tidata :        >int_sram
        .ctors  ALIGN (0x4): { *(.ctors) }       >int_sram
        .dtors  ALIGN (0x4): { *(.dtors) }       >int_sram
        .__HEAP_START :        >int_sram

        __SP_INIT =ADDR(stack_ram)+SIZEOF(stack_ram);

        __SP_END=ADDR(stack_ram);

        __HEAP_END=__SP_END;

        __BSS_SIZE       = __BSS_END - __BSS_START;
}





