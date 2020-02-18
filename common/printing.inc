; Macros for printing, in case console is too heavy

print_nibble	MACRO
; Print the low nibble in A to the screen at (HL)
; Increses HL to point to the next character
	and $f
	cp 10
	ccf
	adc '0'
	daa
	and $3f
	ld (hl),a
	inc l
	ENDM

print_byte	MACRO
; Print A as two hex characters to the screen at (HL)
	push af
	rra
	rra
	rra
	rra
	print_nibble
	pop af
	print_nibble
	ENDM


print_word	MACRO
; Print DE as four hex characters to the screen at (HL)
	ld a,d
	print_byte
	ld a,e
	print_byte
	ENDM
