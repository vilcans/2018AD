	GLOBAL helix_start

	INCLUDE vz.inc


num_bars=5
bar_x_increment=21
USE_IRQ=0

helix_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	ld hl,x_sine_table
	ld b,31
	ld c,31
	call generate_sine_with_offset

	ld hl,sine_table
	ld b,63
	ld c,63
	call generate_sine_with_offset

	call clear_backbuffer

.move_loop:
	call waitvbl

	ld a,%10000
	ld ($6800),a ; bgcolor

	call copy_to_screen
	call clear_backbuffer
	call do_helix

	ld a,(num_helix_rows)
	cp 16
	jp z,.all_showing
	inc a
	ld (num_helix_rows),a
.all_showing:

;	ld a,%00000
;	ld ($6800),a ; bgcolor

.framecounter=$+1
	ld hl,340
	dec hl
	ld (.framecounter),hl
	ld a,l
	or h
	jp nz,.move_loop

.out_loop:
	call waitvbl

	call copy_to_screen
	call clear_backbuffer
	call do_helix

	ld a,(num_helix_rows)
	or a
	jp z,.finally_done
	dec a
	ld (num_helix_rows),a
	jp .out_loop

.finally_done:
	call waitvbl
	call copy_to_screen

	ret


do_helix:
	; add 2 sine values 
x_offset1=$+1
	ld hl,sine_table
	ld a,(hl)
x_offset2=$+1
	ld l,0
	add (hl)
;	rra
	ld (x_pos),a

x_pos=$+1
	ld hl,x_sine_table

	ld d,>backbuffer
	ld c,0

	exx

num_helix_rows=$+1
	ld a,0
	or a
	ret z
	ld c,a
.render_loop:
	exx

current_color=$+1
	ld a,0

	ld a,(current_color)
	ld ixl,a

	ld b,num_bars
.even_loop:
; even rows

	xor a
	ld a,(hl)
	rra
	jp nc,.x_set_left_even
.x_set_right_even:
	add c
	ld e,a
	ld a,(de)
	or %10000100
	jp .draw_even

.x_set_left_even:
	add c
	ld e,a
	ld a,(de)
	or %10001000

.draw_even:
	xor ixl
	ld (de),a

	ld a,l
	add bar_x_increment
	ld l,a

	ld a,ixl
	add %00010000
	and %01110000
	ld ixl,a

	djnz .even_loop

	ld a,l
	add $3-bar_x_increment*num_bars
	ld l,a

	ld a,(current_color)
	ld ixl,a

	ld b,num_bars
.odd_loop:
; odd rows

	or a
	ld a,(hl)
	rra
	jp nc,.x_set_left_odd
.x_set_right_odd:
	add c
	ld e,a
	ld a,(de)
	or %10000001
	jp .draw_odd

.x_set_left_odd:
	add c
	ld e,a
	ld a,(de)
	or %10000010

.draw_odd:
	or ixl
	ld (de),a

	ld a,l
	add bar_x_increment
	ld l,a

	ld a,ixl
	add %00010000
	and %01110000
	ld ixl,a

	djnz .odd_loop

	ld a,l
	add $3-bar_x_increment*num_bars
	ld l,a

	ld a,c
	add 32
	ld c,a
	jp nc,.no_carry
	inc d
.no_carry:


	ld a,(current_color)
	add %00010000
	and %01110000
	ld (current_color),a

	exx
	dec c
	jp nz, .render_loop

	ld a,(x_offset1)
	add 1
	ld (x_offset1),a

	ld a,(x_offset2)
	add 2
	ld (x_offset2),a

	ret

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


copy_to_screen:
	ld hl,backbuffer
	ld de,$7000

	ld bc,16*256+32*16
.copy_loop:

	REPT 32
	ldi
	ENDR

	djnz .copy_loop
	ret

clear_backbuffer:
	ld hl,backbuffer
	ld a,$80

	ld b,16
.clear_loop:

	REPT 32
	ld (hl),a
	inc l
	ENDR

	jp nz,.no_reset
	inc h
.no_reset:

	djnz .clear_loop
	ret

	SECTION .bss,"uR"

	align 8
x_sine_table:
	dsb 256

	align 8
sine_table:
	dsb 256

	align 8
backbuffer:
	dsb 32*16

