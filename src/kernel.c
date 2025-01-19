typedef unsigned char byte_t;
typedef unsigned int size_t;

//add [] so that we get an address not a byte
extern char __bss[], __bss_end[], __stack_top[];

void *memset(void *buf, char c, size_t n) {
    byte_t *p = (byte_t *) buf;
    while (n--)
        *p++ = c;
    return buf;
}

void kernel_main(void) {
    //init bss to zero (some bootloaders do that)
    memset(__bss, 0, (size_t) __bss_end - (size_t) __bss);
 
    //infinite loop
    for (;;);
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
