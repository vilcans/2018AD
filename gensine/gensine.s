
	GLOBAL generate_sine_with_offset

generate_sine_with_offset:
; Input:
;   HL = will receive 256 bytes of sine values
;   B = offset to add to the sine values, make B=C to make values go from 0 to 2*C.
;   C = amplitude
; Output:
;   HL = unchanged

	push bc
	call generate_sine
	pop bc
	ld c,0
.add_loop:
	dec hl
	ld a,(hl)
	add b
	ld (hl),a
	dec c
	jp nz,.add_loop
	ret

	GLOBAL generate_sine
generate_sine:
; Generate a sine table
; Input:
;   HL = will receive 256 bytes of sine values
;   C = amplitude

	; Point to significand, exponent pairs
	; The data skips the first value as it's always zero
	; and the multiplication hangs if factor is 0
	ld (hl),0
	inc hl

	ld de,sine_values

	ld b,$40-1   ; a quarter of the sine
.first_quadrant:
	push hl

	ld a,(de)  ; significand
	inc de

	; Multiply significand with amplitude
	; HL = C * A
	; Note: Multiplication hangs if A has no set bits

	push bc
	ld hl,0
	ld b,h  ;0
.mul_loop:
	srl a
	jr nc,.no_add
	add hl,bc   ; doesn't affect Z flag
	jr z,.after_mul
.no_add:
	sla c
	rl b
	jr .mul_loop
.after_mul:
	; HL = multiplication result

	pop bc

	ld a,b
	cp number_of_values_without_exponent+1
	jr c,.zero_exponent

	ld a,(de)  ; exponent
	inc de
.shift_loop:
	srl h
	dec a
	jr nz,.shift_loop
	ld a,h
	adc 0   ; round
	jr .after_shift
.zero_exponent:
	ld a,h
	rl l
	adc 0
.after_shift:
	pop hl
	ld (hl),a
	inc hl
	djnz .first_quadrant

	ld d,h
	ld e,l
	;dec de   ; DE = already calculated values, looping backwards

	; Hard-insert the amplitude value at 90 degrees
	ld a,c

	; Create the second quadrant by mirroring the first quadrant
	ld b,$40
.second_quadrant:
	ld (hl),a
	inc hl
	dec de
	ld a,(de)
	djnz .second_quadrant

	; Mirror the firsts half of the sine table
	;ld de,result   ; DE already points to result
	ld b,$80
.second_half:
	ld a,(de)
	inc de
	neg
	ld (hl),a
	inc hl
	djnz .second_half

	;ret  ; Fallthrough as first byte in values.s happens to be $c9

sine_values:
	; significand, exponent
	INCLUDE values.s
