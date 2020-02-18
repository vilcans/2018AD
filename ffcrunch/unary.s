; Decompression of data compressed with unary encoding.

unary_decompress:
; Decompress directly to RAM.
;
; Input:
;   HL = unary compressed data
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
	call unary_init
	exx
.loop:
	exx
	call unary_get_next_byte
	exx
	ld (de),a
	inc de
	djnz .loop

	dec c
	jp nz,.loop

	ret


unary_init:
; Initialize decompression, if you want to decompress one byte at a time.
; After this, follow up with calls to unary_get_next_value.
;
; Input:
;   HL = unary compressed data
; Output:
;   HL, C = save these to calls to unary_get_next_value
;   A = destroyed

	ld c,(hl)    ; number of unique values
	inc hl

	ld a,h
	ld (unary_value_table_highbyte),a
	ld a,l
	ld (unary_value_table_lowbyte),a

	add c
	ld l,a
	ld c,$80
	ret nc
	inc h
	ret

unary_get_next_byte:
; Input:
;   HL, C = from unary_init or previous call to unary_get_next_byte
; Output:
;   A = value
;   B, DE = destroyed

.get_next_bit MACRO
	sla c
	call z,.next_byte
	ENDM

	ld a,-1   ; count
.count_zeroes:
	.get_next_bit
	inc a
	jp nc,.count_zeroes

unary_value_table_lowbyte = $+1
	add 0
	ld e,a
unary_value_table_highbyte = $+1
	adc 0
	sub e

	ld d,a
	ld a,(de)
	ret

.next_byte:
	ld c,(hl)

	inc hl
	sll c    ; get first bit and insert a 1
	ret
