	INCLUDE vz.inc

number_of_columns = 32
number_of_rows = 16

	GLOBAL console_print
console_print:
; Print the null terminated string following the CALL
; E.g.
;   call console_print
;   asciiz "Hello, world!"

	ld (.save_hl),hl
	pop hl   ; text string
	push af
.loop:
	ld a,(hl)
	inc hl
	or a
	jr z,.end

	call console_putc
	jr .loop

.end:
	pop af

	; Jump to the instruction after the null terminator
	push hl
.save_hl = $+1
	ld hl,0
	ret
	
	GLOBAL console_putc
console_putc:
; Output the character in A.
	push af

	cp 10
	jr z,.newline

	push de
	push hl
	push af

	ld d,$70>>2  ; screen address
	ld a,(cursor_row)
	or a
	rla  ; Multiply by number_of_columns
	rla
	rla
	rla
	rl d
	rla
	rl d
	ld e,a
	ld a,(cursor_col)
	add e
	ld e,a

	pop af
	and $3f  ; ASCII $40 maps to char $00
	ld (de),a

	call advance_cursor

	pop hl
	pop de
	pop af
	ret
.newline:
	pop af
	jr console_newline

	GLOBAL console_print_byte
console_print_byte:
; Print A as two hex characters
	push af
	push af
	rra
	rra
	rra
	rra
	call print_nibble
	pop af
	call print_nibble
	pop af
	ret

	GLOBAL console_print_word
; Print HL as two hex characters
console_print_word:
	push af
	ld a,h
	call console_print_byte
	ld a,l
	call console_print_byte
	pop af
	ret

print_nibble:
	and $f
	cp 10
	jr c,.low
	add 'A'-'0'-10
.low:
	add '0'
	jp console_putc

	GLOBAL console_hexdump
console_hexdump:
; Dump from HL
; Number of bytes in BC

	push af
	push bc
	push de
	push hl
.each_row:
	call console_print_word
	call console_print
	asciiz ': '

	ld e,8  ; bytes per row
.each_byte:
	ld a,(hl)
	inc hl
	call console_print_byte
	ld a,' '
	call console_putc

	dec bc
	ld a,b
	or c
	jr z,.end

	dec e
	jr nz,.each_byte
	call console_newline
	jr .each_row
.end:
	call console_newline
	pop hl
	pop de
	pop bc
	pop af
	ret

advance_cursor:
; Destroys AF
	ld a,(cursor_col)
	inc a
	ld (cursor_col),a
	cp number_of_columns
	ret nz
	; fallthrough!
	GLOBAL console_newline
console_newline:
	push af
	xor a
	ld (cursor_col),a

	ld a,(cursor_row)
	inc a
	ld (cursor_row),a
	cp number_of_rows
	jr nz,.end
	dec a
	ld (cursor_row),a
	call scroll_up
.end:
	pop af
	ret

scroll_up:
; Destroys AF
	push de
	push bc
	push hl

	ld de,screen_start
	ld hl,screen_start+number_of_columns
	ld bc,number_of_rows*number_of_columns-number_of_columns
	ldir

	ld b,number_of_columns
	ld a,' '
.empty_bottom_row:
	ld (de),a
	inc e
	djnz .empty_bottom_row

	pop hl
	pop bc
	pop de
	ret

cursor_row:	db 0
cursor_col:	db 0
