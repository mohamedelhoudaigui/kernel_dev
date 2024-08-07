x86_64_asm_src := $(shell find src/impl/x86_64 -name *.asm)

x86_64_asm_obj := $(patsubst src/impl/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_src))

$(x86_64_asm_obj) : build/x86_64/%.o : src/impl/x86_64/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst nuild/x86_64/%.o, src/impl/x86_64/%.asm, $@) -o $@


.PHONY: build-x86_64
build-86_64: $(x86_64_asm_obj)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(x86_64_asm_obj) && \
	cp 	dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc dist/x86_64/kernel.iso targets/x86_64/iso
	
