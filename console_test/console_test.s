	INCLUDE vz.inc

	ld a,' '
	ld b,120
.each_char:
	call console_putc
	inc a
	cp 128
	jr nz,.each_char

	call console_print
	asciiz 'HELLO, WORLD!'

	ld a,10
	call console_putc

	call console_print
	asciiz 'STRING',10,'WITH',10,'NEWLINES'

	xor a
.each_hexbyte:
	call console_print_byte
	inc a
	jr nz,.each_hexbyte

	; Test console_print_word
	call console_newline
	ld hl,$cafe
	call console_print_word
	call console_newline
	ld hl,$babe
	call console_print_word

	ld b,50
	call wait

	; Test hexdump
	ld hl,$0000
	ld bc,$3e
	call console_hexdump

	ld b,50
	call wait

	; Print a lot of text to test scrolling
	ld c,50
.line:
	call console_print
	asciiz 'MARTIN IS BEST! '

	ld b,3
	call wait

	dec c
	jr nz,.line

	ld hl,screen_start+15*$20
.f:	
	inc (hl)
	jr .f

	ret
wait:
	ld bc,0
.loop:
	dec bc
	ld a,b
	or c
	jr nz,.loop
	ret
