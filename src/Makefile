CC=clang
CFLAGS=-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib
QEMU=qemu-system-riscv32

HEADERS = ./include/kernel.h \
		  ./include/kernel.h

SRCS = ./files/kernel.c \
	   ./files/lib.c

init: build
	$(QEMU) -machine virt \
    -bios default \
    -nographic \
    -serial mon:stdio \
    --no-reboot \
    -kernel kernel.elf

build: $(HEADERS)
	$(CC) $(CFLAGS) -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf $(SRCS)
