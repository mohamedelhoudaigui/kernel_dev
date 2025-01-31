ENTRY(boot) /* boot is the entry function (like main() in c) */

SECTIONS {
    . = 0x80200000; /* bootloader loads from this address */

    .text :{ /* this where our code lives, include all .text entrys */
        KEEP(*(.text.boot));
        *(.text .text.*);
    }

    .rodata : ALIGN(4) { /* read only data */
        *(.rodata .rodata.*);
    }

    .data : ALIGN(4) { /* initialised data */
        *(.data .data.*);
    }

    .bss : ALIGN(4) { /* uninitialised data, save the start and end of the bss */
        __bss = .;
        *(.bss .bss.* .sbss .sbss.*);
        __bss_end = .;
    }
    /* the "." means current memory location */
    . = ALIGN(4);
    . += 128 * 1024; /* 128KB reserved for stack */
    __stack_top = .; /* start stack at the lowest address */

    . = ALIGN(4096);
    __free_ram = .;
    . += 128 * 1024 * 1024; /* 64 mb */
    __free_ram_end = .;
}

