#!/bin/bash
set -xue

# QEMU file path
QEMU=qemu-system-riscv32

# compiler and flags
CC=clang
CFLAGS="-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib"

# build kernel:
# -std=c11	            Use C11
# -O2	                Enable optimizations to generate efficient machine code.
# -g3               	Generate the maximum amount of debug information.
# -Wall	                Enable major warnings.
# -Wextra	            Enable additional warnings.
# --target=riscv32	    Compile for 32-bit RISC-V.
# -ffreestanding        Do not use the standard library of the host environment (your development environment).
# -nostdlib             Do not link the standard library.
# -Wl,-Tkernel.ld	    Specify the linker script.
# -Wl,-Map=kernel.map	Output a map file (linker allocation result).

# clang command does C compilation and executes the linker internally.

$CC $CFLAGS -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf kernel.c

# Start QEMU
$QEMU -machine virt \
    -bios default \
    -nographic \
    -serial mon:stdio \
    --no-reboot \
    -kernel kernel.elf
