FROM debian:12.9-slim


RUN apt update && apt install -y \
    clang \
    llvm \
    lld \
    qemu-system-riscv32 \
    curl \
    tar \
    llvm \
    make

WORKDIR /app

RUN curl -LO https://github.com/qemu/qemu/raw/v8.0.4/pc-bios/opensbi-riscv32-generic-fw_dynamic.bin

CMD [ "make" ]
