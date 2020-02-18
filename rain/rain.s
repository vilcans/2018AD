	GLOBAL rain_start

	INCLUDE vz.inc

USE_IRQ=0
SCREEN_HEIGHT=64
SCREEN_WIDTH=128

NUM_CIRCLES=10
MAX_RADIUS=16

rain_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	call generate_color_tables
	call init_raindrops

	call clear_screen

	call lfsr_8

.move_loop:
	call waitvbl

	call clear_pixels
	call draw_pixels

	call copy_draw_to_clear

	call poke_buffer
	call fix_offsets


	ld a,(.framecounter)
	and %1111
	jp nz,.all_running

	ld a,(current_num_circles)
	cp NUM_CIRCLES
	jp z,.all_running
	inc a
	ld (current_num_circles),a
.all_running:

.framecounter=$+1
	ld hl,50*8
	dec hl
	ld (.framecounter),hl
	ld a,l
	or h
	jp nz,.move_loop

.out_loop:
	call waitvbl

	call clear_pixels
	call draw_pixels

	call copy_draw_to_clear

	call poke_buffer
	call fix_offsets

	ld a,(.framecounter)
	and %111
	jp nz,.not_now

	ld a,(current_num_circles)
	or a
	jp z,.no_running
	dec a
	ld (current_num_circles),a

.not_now:
	ld hl,(.framecounter)
	dec hl
	ld (.framecounter),hl
	jp .out_loop

.no_running:

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

	call waitvbl

	ld a,%11000
	ld ($6800),a ; hires

	ld bc,$680
	ldir

	call waitvbl
	ld bc,$180
	ldir

	ret

clear_pixels:
	ld (.stack_save),sp
	ld sp,buffer_clear
; format of buffer_clear
; two bytes per row, byte to clear
; y low byte included
; SCREEN_HEIGHT*2 bytes
; must not cross page boundary

	ld h,$70
	xor a
	ld c,64/8
.loop:
	ld b,8*2/2
.eight_loop:
	pop de
	ld l,e 
	ld (hl),a
	ld l,d
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
	ld sp,buffer_draw

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
	ld (hl),d
	djnz .eight_loop
	inc h
	dec c
	jp nz,.loop

.stack_save=$+1
	ld sp,$0
	ret

copy_draw_to_clear:
	ld hl,buffer_draw
	ld de,buffer_clear
	ld c,-1
	ld b,SCREEN_HEIGHT*2
.loop:
	ld a,(hl)
	ld (hl),c
	inc l
	inc l
	ld (de),a
	inc e
	djnz .loop
	ret

fix_offsets:
	ld c,$0
	ld d,>pixel_to_bits_color
	ld hl,buffer_draw
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
	jp p,.value
	xor a
	ld (hl),a
	inc l
	ld (hl),a
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

	ld hl,raindrops

current_num_circles=$+1
	ld a,0
	or a
	ret z
	ld b,a
.loop:
	push bc
	; check radius
	ld a,(hl)
	add $70
	ld (hl),a
	inc hl
	ld a,(hl)
	adc 0
	ld (hl),a
	cp MAX_RADIUS
	jp nz,.no_reset

	push hl
	dec hl
	call restart_raindrop
	pop hl

	ld a,(hl)
.no_reset:
	ld b,a
	inc hl
	; x
	ld d,(hl)
	inc hl
	; y 
	ld e,(hl)
	inc hl

	push hl
;	ld d,SCREEN_WIDTH/2 ; xc
;	ld e,SCREEN_HEIGHT/2 ; yc
;	ld b,a ; radius
	call bresenham_circle
	pop hl
	
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
	ret m
	jp nz,.not_zero
	inc a
.not_zero:
	ld bc,buffer_draw
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

init_raindrops:
	ld hl,raindrops
	ld b,NUM_CIRCLES
.loop:
	call restart_raindrop

	djnz .loop
	ret

restart_raindrop:
	; initial size
	xor a
	ld (hl),a
	inc hl

	call lfsr_8
	and 32-1
	neg
	ld (hl),a
	inc hl
	; x
	call lfsr_8
	and 64-1
	add 32
	ld (hl),a
	inc hl
	; y
	call lfsr_8
	and 32-1
	add 16
	ld (hl),a
	inc hl
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

	SECTION .bss,"uR"

workmem_start:
	align 8
; bytes to draw, 4 bytes per row
buffer_draw:
	dsb SCREEN_HEIGHT*4,0

; bytes to clear, 2 bytes per row
buffer_clear:
	dsb SCREEN_HEIGHT*2,0

	align 8
pixel_to_bits_color:
	dsb 4,0

raindrops:
	; radius lo byte, radius hi byte, cx, cy
	dsb 4*NUM_CIRCLES,0

workmem_len=$-workmem_start

