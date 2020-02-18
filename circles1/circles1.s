	GLOBAL circles1_start

	INCLUDE vz.inc

USE_IRQ=0
SCREEN_HEIGHT=64
SCREEN_WIDTH=128

NUM_CIRCLES=9

circles1_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	; Clear buffers to avoid drawing garbage date the first frames
	ld hl,buffer_one
	ld de,buffer_one+1
	ld (hl),0
	ld bc,buffer_two_end-buffer_one-1
	ldir

	call generate_color_tables

	ld hl,sine_table
	ld b,32
	ld c,32
	call generate_sine_with_offset

	;call clear_screen

	ld hl,buffer_one
	ld (buffer_clear),hl
	ld hl,buffer_two
	ld (buffer_draw),hl

.move_loop:
	call waitvbl

	ld a,%11000
	ld ($6800),a ; bgcolor

	call clear_pixels
	call draw_pixels

	call copy_draw_to_clear

	call poke_buffer
	call fix_offsets

;	ld a,%01000
;	ld ($6800),a ; bgcolor

.framecounter=$+1
	ld hl,50*10
	dec hl
	ld (.framecounter),hl
	ld a,l
	or h
	jp nz,.move_loop

	ld de,$7000
	ld hl,$7800-1
	ld c,64/2
.out_loop:
	call waitvbl
	xor a
	ld b,32
.inner_out_loop:
	ld (de),a
	inc de
	ld (hl),a
	dec hl
	djnz .inner_out_loop

	dec c
	jp nz,.out_loop

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
	ld a,$ff
	ld (hl),a

	; TODO this can be done faster
	ld bc,$800
	ldir
	ret

clear_pixels:
	ld (.stack_save),sp
	ld sp,(buffer_clear)
; format of buffer_clear, same as buffer_draw

	ld h,$70
	xor a
	ld c,64/8
.loop:
	ld b,8*2/2
.eight_loop:
	pop de
	ld l,e 
	ld a,(hl)
	and %10101010
	ld (hl),a

	pop de
	ld l,e 
	ld a,(hl)
	and %10101010
	ld (hl),a

	djnz .eight_loop
	inc h
	dec c
	jp nz,.loop

.stack_save=$+1
	ld sp,$0
	ret

draw_pixels:
	ld (.stack_save),sp
	ld sp,(buffer_draw)

; format of buffer_draw
; four bytes per row, byte to set, value to set
; y low byte included
; SCREEN_HEIGHT*4 bytes
; must not cross page boundary
	
	ld h,$70
	ld c,64/8
.loop:
	ld b,8*2
.eight_loop:
	pop de
	ld l,e
	ld a,(hl)
	or d
	ld (hl),a
	djnz .eight_loop
	inc h
	dec c
	jp nz,.loop

.stack_save=$+1
	ld sp,$0
	ret

copy_draw_to_clear:
	; swap pointers
	ld hl,(buffer_clear)
	ld de,(buffer_draw)
	ld (buffer_draw),hl
	ld (buffer_clear),de

	; 4 bytes per row
	ld de,SCREEN_HEIGHT*4
	add hl,de

	ld (.stack_save),sp
	ld sp,hl

	ld hl,0
	ld b,SCREEN_HEIGHT
.loop:
	; 4 bytes per row
	push hl
	push hl
	djnz .loop

.stack_save=$+1
	ld sp,$0
	ret

fix_offsets:
	ld c,$0
	ld d,>pixel_to_bits_color
	ld hl,(buffer_draw)
	exx
	ld c,64/8
.outer_loop:

	ld b,8
.loop:
	exx

	ld b,2
.inner_loop:
	ld a,(hl)
	or a
	jp nz,.value
	inc l
	inc l
	djnz .inner_loop
	jp .next_row

.value:

	; carry is always clear when we get here, due to 'or a' above
	ld e,0
	rra
	rl e
	rra
	rl e
	add c
	ld (hl),a
	inc l
	ld a,(de)
	ld (hl),a
	inc l

	djnz .inner_loop

; TODO if possible use more bss and this implemenation
;	ld l,x
;    sll l
;    ld a,(hl)   ; offset
;    inc l
;    ld a,(hl)   ; color bits

.next_row:
	ld a,c
	add $20
	ld c,a
	exx
	djnz .loop

	dec c
	jp nz,.outer_loop

	ret

poke_buffer:
.current_xc_sine_1=$+1
	ld a,1
	add 3
	ld (.current_xc_sine_1),a
	ld (.xc_sine),a

.current_yc_sine=$+1
	ld a,123
	sub 3
	ld (.current_yc_sine),a
	ld (.yc_sine),a

.current_radius_sine=$+1
	ld a,243
	inc a
	ld (.current_radius_sine),a
	ld (.radius_sine),a

	ld b,NUM_CIRCLES
.loop:
	push bc

	ld h,>sine_table
.xc_sine=$+1
	ld a,0
	add $100/NUM_CIRCLES
	ld (.xc_sine),a
	ld l,a
	ld a,(hl)
	add 32-1
	ld d,a ; xc

	ld h,>sine_table
.yc_sine=$+1
	ld a,0
	add $100/NUM_CIRCLES
	ld (.yc_sine),a
	ld l,a
	ld a,(hl) ; yc
	rra
	and %00111111
	add 16
	ld e,a

	ld h,>sine_table
.radius_sine=$+1
	ld a,0
	add $100/NUM_CIRCLES
	ld (.radius_sine),a
	ld l,a
	ld a,(hl)
	rra
	rra
	and %00111111
	cp 15
	jp c,.not_too_large
	ld a,15
.not_too_large:
	ld b,a

;	ld d,SCREEN_WIDTH/2 ; xc
;	ld e,SCREEN_HEIGHT/2 ; yc
;	ld b,a ; radius
	call bresenham_circle
	pop bc

	djnz .loop

	ret


	MACRO SET_PIXEL 
	push hl
	exx 
	pop hl 

; xc PLUS n
	ld a,e ; yc
	add l 
	add a
	add a
	ld (.yc_plus_y),a
	add 2
	ld c,a ; yc+y
	ld a,d ; xc
	add h
	ld (bc),a ; xc+x
	ex af,af'

	ld a,e ; yc
	sub l
	add a
	add a
	ld (.yc_minus_y),a
	add 2
	ld c,a ; yc-y
	ex af,af'
	ld (bc),a ; xc+x

	ld a,e ; yc
	add h
	add a
	add a
	ld (.yc_plus_x),a
	add 2
	ld c,a ; yc+x
	ld a,d ; xc
	add l
	ld (bc),a ; xc+y
	ex af,af'

	ld a,e ; yc
	sub h
	add a
	add a
	ld (.yc_minus_x),a
	add 2
	ld c,a ; yc-x
	ex af,af'
	ld (bc),a ; xc+y

; xc MINUS n

.yc_plus_y=$+1
	ld c,0 ; yc+y
	ld a,d ; xc
	sub h
	ld (bc),a ; xc-x
	ex af,af'

.yc_minus_y=$+1
	ld c,0 ; yc-y
	ex af,af'
	ld (bc),a ; xc-x

.yc_plus_x=$+1
	ld c,0 ; yc+x
	ld a,d ; xc
	sub l
	ld (bc),a ; xc-y
	ex af,af'

.yc_minus_x=$+1
	ld c,0 ; yc-x
	ex af,af'
	ld (bc),a ;  xc-y

	exx
	ENDM

; d = xc
; e = yc
; b = radius
; radius in range 1 < radius < 63
bresenham_circle:
	ld a,b
	or a
	jp nz,.not_zero
	inc a
.not_zero:
	ld bc,(buffer_draw)
	exx

	ld h,0 ; x = 0
	ld l,a ; y = radius
	ld a,1
	sub l
	ld b,a ; d = 1 - radius
	ld d,1 ; dd_x = 1
	xor a
	sub l
	sub l
	ld e,a ; dd_y = -2 * radius

.loop:
	; set pixel
	SET_PIXEL

	; while x < y
	ld a,l
	cp h
	ret c

	; if d >= 0:
	ld a,b
	or a
	jp m,.d_is_negative

.d_is_positive:
	dec l ; y -= 1
	inc e
	inc e ; dd_y += 2
	ld a,b
	add e
	ld b,a

.d_is_negative:
	inc h ; x += 1
	inc d
	inc d ; dd_x += 2
	ld a,b
	add d
	ld b,a
	
	jp .loop

generate_color_tables:
	ld de,pixel_to_bits_color
	ld hl,.color_table
	ld bc,4
	ldir
	ret

.color_table:
	defb %01000000
	defb %00000100
	defb %00010000
	defb %00000001

	SECTION .bss,"uR"

workmem_start:
	align 8
sine_table:
	dsb 256

	align 8
; bytes to draw, 4 bytes per row
buffer_one:
	dsb SCREEN_HEIGHT*4,0

; bytes to clear, 2 bytes per row
buffer_two:
	dsb SCREEN_HEIGHT*4,0
buffer_two_end:

	align 8
pixel_to_bits_color:
	dsb 4,0

buffer_clear:
	dsw 1,0
buffer_draw:
	dsw 1,0


workmem_len=$-workmem_start

