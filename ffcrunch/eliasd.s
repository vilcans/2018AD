; Decompresses data encoded in Elias Delta encoding.

eliasd_decompress:
; Decompress directly to RAM.
;
; Input:
;   HL = eliasd compressed data
;   DE = target buffer
;   BC = decompressed size

	; Prepare for loop, based on the technique in
	; http://wikiti.brandonw.net/index.php?title=Z80_Optimization#Looping_with_16_bit_counter
	dec bc
	inc b
	inc c
	ld a,b
	ld b,c
	ld c,a

	push hl
	exx
	pop hl
	call eliasd_init
	exx
.loop:
	exx
	call eliasd_get_next_byte
	exx
	ld (de),a
	inc de
	djnz .loop
	;call maybe_next_frame here if needed
	dec c
	jp nz,.loop

	ret

eliasd_init:
; Initialize decompression, if you want to decompress one byte at a time.
; After this, follow up with calls to eliasd_get_next_value.
;
; Input:
;   HL = eliasd compressed data
; Output:
;   HL, C = save these to calls to eliasd_get_next_value
;   A = destroyed

	ld c,(hl)    ; number of unique values
	inc hl

	ld a,h
	ld (eliasd_value_table_highbyte),a
	ld a,l
	ld (eliasd_value_table_lowbyte),a

	add c
	ld l,a
	ld c,$80
	ret nc
	inc h
	ret

eliasd_get_next_byte:
; Input:
;   HL, C = from eliasd_init or previous call to eliasd_get_next_byte
; Output:
;   A = value
;   B, DE = destroyed

.get_next_bit MACRO
	sla c
	call z,.next_byte

	;push af
	;push af
	;call console_print
	;ASCIIZ 'bit='
	;pop af
	;ld a,0
	;adc '0'
	;call console_putc
	;call console_print
	;ASCIIZ 10
	;pop af
	ENDM

	ld a,-1   ; length_of_length
.count_zeroes:
	.get_next_bit
	inc a  ; preserves carry but modifies zero
	jp nc,.count_zeroes

	;push af
	;call console_print
	;ASCIIZ 'got length of length='
	;call console_print_byte
	;call console_newline
	;pop af

	jr z,.got_value   ; length was 0 => value is 1, offset to 0

	ld b,1    ; length
.read_length:
	.get_next_bit
	rl b
	dec a
	jp nz,.read_length

	dec b    ; is now length

	;ld a,b
	;call console_print
	;ASCIIZ 'got length='
	;call console_print_byte
	;call console_newline

	ld a,1   ; value
.read_rest:
	.get_next_bit
	rla
	djnz .read_rest

	;call console_print
	;ASCIIZ 'got value='
	;call console_print_byte
	;call console_newline

	dec a           ; as Elias doesn't encode 0, we offset
.got_value:
eliasd_value_table_lowbyte = $+1
	add 0
	ld e,a
eliasd_value_table_highbyte = $+1
	adc 0
	sub e

	ld d,a
	ld a,(de)
	ret

.next_byte:
	;call console_print
	;ASCIIZ 'next_byte = '

	ld c,(hl)

	;push af
	;ld a,c
	;call console_print_byte
	;call console_newline
	;pop af

	inc hl
	sll c    ; get first bit and insert a 1
	ret
