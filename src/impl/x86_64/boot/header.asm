header_start:

; magic number to identify a valid multi boot header
; (bootloader checks this)
dd 0xe85250d6

; protected mode i386
dd 0

; header length (This tells the bootloader how long the header is)
dd header_end - header_start

; check_sum
; The checksum field is used to verify the integrity of the header
dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

; end tag (mark the end of a header section)
dw 0
dw 0
dd 8

header_end:

; dd: Define Double Word (32-bit value).

; dw: Define Word (16-bit value).

; Magic Number: Identifies the Multiboot header.

; Protected Mode Flag: Specifies the mode (protected mode in this case).

; Header Length: The length of the header.

; Checksum: Verifies the integrity of the header.

; End Tag: Marks the end of the header.

