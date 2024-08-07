; make the start label globally accessible. This means that the linker
; (or bootloader) can find this label when linking the kernel or loading it.
; It essentially marks the entry point of your code
global start

; .text is typically used for executable code
section .text
; the code is for a 32-bit architecture
bits 32

; entry point of the kernel
start:
	; stop processor
	hlt