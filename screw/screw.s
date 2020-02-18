	GLOBAL screw_start

	INCLUDE vz.inc


USE_IRQ=0

BAR_WIDTH=5 ; bytes

screw_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	ld hl,x_sine_table1
	ld b,28
	ld c,23
	call generate_sine_with_offset

	ld hl,x_sine_table2
	ld b,28
	ld c,12
	call generate_sine_with_offset

	; textmode
	ld a,%00000
	ld ($6800),a ; bgcolor

.move_loop:
	call waitvbl

;	ld a,%10000
;	ld ($6800),a ; bgcolor

	call copy_and_clear
	call do_screw


	ld a,(num_to_set)
	cp 32
	jp z,.all_set
	inc a
	ld (num_to_set),a
	ld a,(num_to_clear)
	dec a
	ld (num_to_clear),a
.all_set:
;	ld a,%00000
;	ld ($6800),a ; bgcolor

.framecounter=$+1
	ld hl,50*7
	dec hl
	ld (.framecounter),hl
	ld a,l
	or h
	jp nz,.move_loop


.out_loop:
	ld a,$80   ; black
	ld (clear_value),a
	call waitvbl

	call copy_and_clear
	call do_screw

	ld a,(num_to_set)
	or a
	jp z,.all_clear
	dec a
	ld (num_to_set),a
	ld a,(num_to_clear)
	inc a
	ld (num_to_clear),a
	jp .out_loop

.all_clear:
prepare_for_next_part:
	; Fill screen with green in graphics
	; (Leftover from before but keeping just in case)
	ld hl,$7200
	ld b,6
.each_frame:
	call waitvbl
.clear_vram:
	ld (hl),0
	inc l
	jr nz,.clear_vram

	inc h
	djnz .each_frame

	ret


do_screw:
.x_offset=$+1
	ld a,0
	ld (.x_offset_current),a

	ld d,>backbuffer

	ld b,0; row

	ld ixl,16
.row_loop:
	ld c,-1 

; bar 1
	ld h,>x_sine_table1
.x_offset_current=$+1
	ld a,0
	add $40
	ld l,a

	xor a
	ld a,(hl)
	rra
	jp nc,.bar1_x_set_left_even
.bar1_x_set_right_even:
	ld hl,bar1_right_even

	jp .bar1_draw

.bar1_x_set_left_even:
	ld hl,bar1_left_even

.bar1_draw:
	add b
	ld e,a
	REPT BAR_WIDTH
	ldi
	ENDR

; bar2
	ld h,>x_sine_table2
	ld a,(.x_offset_current)
	add $40
	ld l,a

	xor a
	ld a,(hl)
	rra
	jp nc,.bar2_x_set_left_even
.bar2_x_set_right_even:
	ld hl,bar2_right_even

	jp .bar2_draw

.bar2_x_set_left_even:
	ld hl,bar2_left_even

.bar2_draw:
	add b
	ld e,a
	REPT BAR_WIDTH
	ldi
	ENDR


; middle bar
	ld hl,bar_middle
	ld a,(32-BAR_WIDTH)/2+1
	add b
	ld e,a
	REPT BAR_WIDTH
	ldi
	ENDR

; bar3
	ld h,>x_sine_table2
	ld a,(.x_offset_current)
	add $40+$80 ; opposite bar 2
	ld l,a

	xor a
	ld a,(hl)
	rra
	jp nc,.bar3_x_set_left_even
.bar3_x_set_right_even:
	ld hl,bar2_right_even

	jp .bar3_draw

.bar3_x_set_left_even:
	ld hl,bar2_left_even

.bar3_draw:
	add b
	ld e,a
	REPT BAR_WIDTH
	ldi
	ENDR

; bar 4
	ld h,>x_sine_table1
	ld a,(.x_offset_current)
	add $40+$80 ; opposite bar 1
	ld l,a

	xor a
	ld a,(hl)
	rra
	jp nc,.bar4_x_set_left_even
.bar4_x_set_right_even:
	ld hl,bar1_right_even

	jp .bar4_draw

.bar4_x_set_left_even:
	ld hl,bar1_left_even

.bar4_draw:
	add b
	ld e,a
	REPT BAR_WIDTH
	ldi
	ENDR

	ld a,b
	add 32
	ld b,a
	ld a,d
	adc 0
	ld d,a

	ld a,(.x_offset_current)
	add 5
	and $7f
	ld (.x_offset_current),a


	dec ixl
	jp nz,.row_loop

	; next frame
	ld a,(.x_offset)
	sub 1
	and $7f
	ld (.x_offset),a

	ret



bar1_left_even:
	defb %10011100
	defb %10011100
	defb %10011100
	defb %10011100
	defb %10000000

bar1_right_even:
	defb %10010100
	defb %10011100
	defb %10011100
	defb %10011100
	defb %10011000

bar2_left_even:
	defb %10101100
	defb %10101100
	defb %10101100
	defb %10101100
	defb %10000000

bar2_right_even:
	defb %10100100
	defb %10101100
	defb %10101100
	defb %10101100
	defb %10101000

bar_middle:
	defb %10110100
	defb %10111100
	defb %10111100
	defb %10111100
	defb %10111000

	if USE_IRQ
flag_irq:
	ld a,$ff
	ld (irq),a
	ret
	endif

waitvbl:
	if USE_IRQ
	xor a
	ld (irq),a
.wait:

irq=$+1
	ld a,(irq)
	or a
	jp z,.wait
	ret
	endif

.loop_clear:
	ld a,($6800)
	and %10000000
	jp z,.loop_clear

.loop_set:
	ld a,($6800)
	and %10000000
	jp nz,.loop_set
	ret

copy_and_clear:
	ld hl,backbuffer
	ld de,$7000

	ld c,$80 ; ' '
	ld ixl,16
.loop:

num_to_set=$+1
	ld a,0
	or a
	jp z,.no_set
	ld b,a
.row_loop_set:
	ld a,(hl)
	ld (hl),c
	ld (de),a
	inc hl
	inc de
	djnz .row_loop_set

.no_set:

num_to_clear=$+1
	ld a,32
	or a
	jp z,.no_clear
	ld b,a
clear_value = $+1
	ld a,$80
.row_loop_clear:
	ld (hl),c
	ld (de),a
	inc hl
	inc de
	djnz .row_loop_clear
.no_clear:


	dec ixl
	jp nz,.loop
	ret

	SECTION .bss,"uR"

workmem_start:
	align 8

	align 8
x_sine_table1:
	dsb 256

	align 8
x_sine_table2:
	dsb 256

	align 8
backbuffer:
	dsb 32*16

workmem_len=$-workmem_start
