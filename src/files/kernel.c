#include "../include/kernel.h"

sbiret sbi_call(long arg0, long arg1, long arg2, long arg3, long arg4,
                       long arg5, long fid, long eid) {
    register long a0 __asm__("a0") = arg0;
    register long a1 __asm__("a1") = arg1;
    register long a2 __asm__("a2") = arg2;
    register long a3 __asm__("a3") = arg3;
    register long a4 __asm__("a4") = arg4;
    register long a5 __asm__("a5") = arg5;
    register long a6 __asm__("a6") = fid;
    register long a7 __asm__("a7") = eid;

    __asm__ __volatile__("ecall"
        : "=r"(a0), "=r"(a1)
        : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5),
        "r"(a6), "r"(a7)
        : "memory");

    sbiret ret;
    ret.error = a0;
    ret.value = a1;

    return (ret);
}


void kernel_main(void) {
    //init bss to zero (some bootloaders do that)
    memset(__bss, 0, (size_t) __bss_end - (size_t) __bss);
 
    printf("\n\nHello %s\n", "World!");
    printf("1 + 2 = %d, %x\n", 1 + 2, 0x1234abcd);
    for (;;)
    {
         __asm__ __volatile__("wfi");
    }
}

//this is at the top section of linker ".text.boot"
__attribute__((section(".text.boot")))

//naked tells the compiler to not add code after or before the body
__attribute__((naked))
void boot(void) {
    //inline assemblly:
    __asm__ __volatile__(
        "mv sp, %[stack_top]\n" // Set the stack pointer
        "j kernel_main\n"       // Jump to the kernel main function
        :
        : [stack_top] "r" (__stack_top) // Pass the stack top address as %[stack_top]
    );
}
