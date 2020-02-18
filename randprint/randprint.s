	GLOBAL randprint_message
	GLOBAL randprint_init

	INCLUDE vz.inc

USE_IRQ=0

SCREEEN_WIDTH = 32
SCREEN_HEIGHT = 16


randprint_message:

	; increase this if we do any work
	ld ixl,0

	ld hl,x_table
	ld b,SCREEEN_WIDTH
.loop:
	ld a,(hl)
	or a
	jp m,.next_column
	jp nz,.new_char

.new_row:
	inc ixl

	inc l
	ld a,(hl)
	ld e,a
	add 32
	ld (hl),a
	inc l
	ld a,(hl)
	ld d,a
	adc 0
	ld (hl),a
	push de
	ex af,af' ; save a
	inc l
	ld e,(hl)
	inc l
	ld d,(hl)
	ld a,(de)
	ld c,a
	dec l
	ld a,e
	add 32
	ld (hl),a
	inc l
	ld a,d
	adc 0
	ld (hl),a
	pop de
	ld a,c
	or %01000000
	ld (de),a
	ex af,af' ; save a
	cp $72
	jp nz,.not_done
	; this one is below screen
	dec l
	dec l
	dec l
	dec l
	ld a,-1
	ld (hl),a
	jp .next_column

.not_done:
	dec l
	dec l
	dec l
	dec l
	call lfsr_8
	and %111111
	inc a

.new_char:
	inc ixl

	dec a
	ld (hl),a
	inc l
	call lfsr_8
	and %1111
	ld de,letters
	add e
	ld e,a
	ld a,(de)
	ld e,(hl)
	inc l
	ld d,(hl)
	inc l
	xor %01000000
	ld (de),a
	inc l
	inc l
	djnz .loop
	ld a,ixl
	ret

.next_column:
	inc l
	inc l
	inc l
	inc l
	inc l
	djnz .loop
	ld a,ixl
	ret


; de = message ptr
randprint_init:
	ld hl,x_table
;	ld de,message
	ld a,-1
	ld c,0
	ld b,SCREEEN_WIDTH
.loop:
	call lfsr_8
	and %1111111
	ld (hl),a
	inc l
	ld (hl),c
	inc c
	inc l
	ld a,$70
	ld (hl),a
	inc l
	ld (hl),e
	inc e
	inc l
	ld (hl),d
	inc l
	djnz .loop
	ret

; Linear Feedback Shift Register
; destroys a
lfsr_8:
.seed = $+1
	ld a,0 ; SMC
	cp 0
	jp z,.do_xor
	; a can never be zero here
	sla a
	jp nc,.no_xor
	jp z,.no_xor ; only way this can be true is if a was $80
.do_xor:
	xor $c3
.no_xor:
	ld (.seed),a
	ret

letters:
	;     0123456789012345
	defb 'JANMZTHIQSGRBKSP'

	SECTION .bss,"uR"

	align 8
x_table:
	; counter, ypos addr, message addr
	dsb SCREEEN_WIDTH*5,0
