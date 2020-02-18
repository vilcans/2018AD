	GLOBAL shadebobs_start

	INCLUDE vz.inc

USE_IRQ=0
SCREEN_HEIGHT=64
SCREEN_WIDTH=128

NUM_PIXELS=50

shadebobs_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	ld a,%01000
	ld ($6800),a ; hires

	call clear_screen

	ld hl,sine_table
	ld b,63
	ld c,63
	call generate_sine_with_offset

.move_loop:
	call waitvbl

	ld a,%11000
	ld ($6800),a ; bgcolor

	call set_pixel

	ld a,%01000
	ld ($6800),a ; bgcolor


	jp .move_loop


.wait_forever:
	jp .wait_forever
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

clear_screen:
	ld hl,$7000
	ld de,$7001
	ld a,0
	ld (hl),a

	; TODO this can be done faster
	ld bc,$800
	ldir
	ret

set_pixel:

.current_x_sine=$+1
	ld a,0
	add 1
	ld (.current_x_sine),a
	ld d,a

.current_y_sine=$+1
	ld a,31
	add 3
	ld (.current_y_sine),a
	ld e,a

	ld b,NUM_PIXELS
.loop:
	push de
	exx
	pop de

	ld h,>sine_table
	ld l,d
	ld a,(hl)
	ex af,af'

	ld l,e
	ld a,(hl)
	rra
	and 64-1

	ld c,0
	rra
	rr c
	rra
	rr c
	rra
	rr c
	add $70
	ld h,a

	ex af,af'

	or a
	ld e,0
	rra
	rl e
	rra
	rl e
	add c
	ld l,a

	ld d,>mask_table
	ld a,(de)
	ld b,a ; mask	ex: %11 00 00 00
	ld e,(hl)	; value  ex: %01 11 10 00
	and e	; mask and value  ex: %01 00 00 00
	add %01010101	; add ex: %01 00 00 00 + %01 01 01 01 = %10 01 01 01  
	and b	; mask and new value ex: %10 00 00 00
	ld d,a	; save new value
	ld a,b	
	cpl	; inverted mask ex: %00 11 11 11
	and e	; mask and value ex: %00 11 10 00
	or d	; or new value ex: %10 11 10 00
	ld (hl),a

	exx

	ld a,d
	add 1
	ld d,a

	ld a,e
	add 1
	ld e,a

	djnz .loop

	ret

	align 8
mask_table:
	defb %11000000
	defb %00001100
	defb %00110000
	defb %00000011

	SECTION .bss,"uR"

workmem_start:
	align 8
sine_table:
	dsb 256,0

workmem_len=$-workmem_start

