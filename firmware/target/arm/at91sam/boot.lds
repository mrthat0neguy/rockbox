OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(reset_handler)
STARTUP(target/arm/at91sam/lyre_proto1/crt0.o)

#define DRAMSIZE    (MEMORYSIZE * 0x100000)
#define DRAMORIG    0x20000000
#define IRAM0ORIG   0x200000
#define IRAM0SIZE   4K
#define IRAM1ORIG   0x300000
#define IRAM1SIZE   4K
#define STACKSIZE   2k

MEMORY
{
    DRAM : ORIGIN = DRAMORIG, LENGTH = DRAMSIZE
    IRAM0 : ORIGIN = IRAM0ORIG, LENGTH = IRAM0SIZE
}

SECTIONS
{
    /* We will put Rockbox bootloader at the last 1MByte of the  SDRAM. */

    /* Example of a section:
    * .section VMA(Virtual Memory Address) : LMA(Load Memory Address).
    * VMA and LMA addresses can be verified by doing:
    * "arm-elf-objdump -h bootloader.elf". */

    .vectors 0 : AT (DRAMORIG + DRAMSIZE - 1M)
    {
        _start_vectors_section = .;
        KEEP(*(.vectors))
        *(.glue_7)
        *(.glue_7t)
        . = ALIGN(4);
        _end_vectors_section = .;
    }

    .text (DRAMORIG + DRAMSIZE -1M + SIZEOF(.vectors)) : \
    AT (DRAMORIG + DRAMSIZE -1M + SIZEOF(.vectors))
    {
        *(.text)
        *(.text*)
        *(.icode)
        *(.icode*)
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    }

    /* Initialized variables are placed on SDRAM, right after .vectors section. */
    /* Data section: VMA is the same as the LMA, right after the end of .vector */
    .data . :
    {
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _end_data_section = .;
    }

    /* Uninitialized variables are placed at SDRAM, right after .text section. */
    .bss (NOLOAD) :
    
    { 
        _start_bss_section = .;
        *(.bss) /* Bss section contains all uninitialized data generated by the compiler. */
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _end_bss_section = .;
    }

    /* Stack is placed at SDRAM, right after .bss section. */
    .stack . :
    {
       *(.stack)
       stackbegin = .;
       . += STACKSIZE;
       stackend = .;
    }
}
