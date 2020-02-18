	GLOBAL electron_start

	INCLUDE vz.inc


USE_IRQ=0


electron_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	ld a,%01000
	ld ($6800),a ; hires

	call clear_screen

	call generate_color_tables

	ld hl,sine_table
	ld b,0
	ld c,127
	call generate_sine_with_offset

	call next_point

.move_loop:
	call waitvbl

	ld a,%11000
	ld ($6800),a ; bgcolor

	call set_point
	call clear_point
	call copy_draw_to_clear
	call next_point

;	ld a,%01000
;	ld ($6800),a ; bgcolor

	jp .move_loop



set_point:

.current_color=$+1
	ld b,%10101010

	ld hl,pixels_draw

	ld e,0
	ld a,(hl) ; x pos
	add 128/2
	or a ; reset carry
	rra
	rl e
	rra ; a = x byte to set
	rl e ; e = bits to set -> but in wrong order
	ld c,a

	inc l
	ld a,(hl) ; y pos
	add 64/2

	or a ; reset carry
	ld l,0
	rra
	rr l
	rra
	rr l
	rra
	rr l
	add $70
	ld h,a
	ld a,l
	add c
	ld l,a

	ld d,>pixel_to_bits_color
	ld a,(de)
	and b
	ld c, a ; current bits

	ld a,(hl) ; current bit value
	or c
	ld (hl),a

	ld a,(t)
	and %1111
	jp nz,.no_new_color

	ld a,b
	add %01010101
	jp nc,.no_carry
	ld a,%01010101
.no_carry:
	ld (.current_color),a

.no_new_color:
	ret

	
clear_point:
	ld hl,pixels_clear

	ld e,0
	ld a,(hl) ; x pos
	add 128/2
	or a ; reset carry
	rra
	rl e
	rra ; a = x byte to set
	rl e ; e = bits to set -> but in wrong order
	ld c,a

	inc l
	ld a,(hl) ; y pos
	add 64/2

	or a ; reset carry
	ld l,0
	rra
	rr l
	rra
	rr l
	rra
	rr l
	add $70
	ld h,a
	ld a,l
	add c
	ld l,a

	ld d,>pixel_to_bits_color
	ld a,(de)
	cpl
	ld c, a ; current bits

	ld a,(hl) ; current bit value
	and c
	ld (hl),a

	ret

copy_draw_to_clear:
	; TODO swap pointers
	ld hl,pixels_clear-1
	ld de,pixels_clear+1
	ld bc,pixels_end-pixels_draw
	lddr
	ret


next_point:
t=$+1
	ld a,0

	; x(t) = 2 * cos(t) + sin(2 * t) * cos(60 * t)
	; y(t) = sin(2 * t) + sin(60 * t)

	; 2t
	ld e,a
;	sra a ; this might not be needed
	add a
	ld (.2t),a

	; cos(t)
	ld a,e
	add $40
	ld l,a
	ld h,>sine_table
	ld a,(hl)
	; 2 cos(t)
	; but I want to keep it in a byte
	; TODO so should be the same as and $fe
	sra a
	add a
	ld (.2cost),a

	; 60t
.60_offset=$+1
	ld h,$0 ; 60   
	call mult_h_e
	ld a,l
	ld (.60t),a

	; sin(2t)
.2t=$+1
	ld e,0
	ld d,>sine_table
	ld a,(de)
	ld (.sin2t),a

	; cos(60t)
.60t=$+1
	ld a,0
	add $40
	ld e,a
	ld a,(de)
	ld (.cos60t),a

.sin2t=$+1
	ld e,0

.cos60t=$+1
	ld h,0

	call mult_h_e

.2cost=$+1
	ld a,0
	sra a ; shift down so we don't overlow
	sra h ; shift down so we don't overlow
	add h

	; a is now x
	sra a ; make sure that -64 < x < 63
	ld hl,pixels_draw
	ld (hl),a


	ld a,(.60t)
	ld d,>sine_table
	ld e,a
	ld a,(de)
	ld l,a ; sin60t

	ld a,(.sin2t)
	sra a ; shift down so we don't overlow
	sra l ; shift down so we don't overlow
	add l

	; a is now y
	sra a
	sra a ; make sure that -32 < y < 32
	ld hl,pixels_draw+1
	ld (hl),a


	ld a,(t)
	inc a
	ld (t),a
	jp nz,.not_now
	ld a,(.60_offset)
	add $40
	jp nc,.not_now_2
	inc a
.not_now_2:
	ld (.60_offset),a
.not_now:

	ret


generate_color_tables:
	ld de,pixel_to_bits_color
	ld hl,.color_table
	ld bc,4
	ldir
	ret

.color_table:
	defb %11000000
	defb %00001100
	defb %00110000
	defb %00000011

clear_screen:
	ld hl,$7000
	ld de,$7001
	ld a,0
	ld (hl),a

	; TODO this can be done faster
	ld bc,$800
	ldir
	ret

; h = x
; e = y
; hl = result
mult_h_e:
	xor a
	ld (.fix_x),a
	ld (.fix_y),a

	ld a,h
	or a
	jp p,.no_fix_x
	ld a,e
	ld (.fix_x),a
.no_fix_x:
	ld a,e
	or a
	jp p,.no_fix_y
	ld a,h
	ld (.fix_y),a
.no_fix_y:

   	ld l,0
   	ld d,l

   	sla	h		; optimised 1st iteration
   	jr nc,$+3
   	ld l,e
   
   	ld b, 7
.loop:
	add	hl,hl          
	jr nc,$+3
	add	hl,de
   
	djnz .loop
   
	ld a,h
.fix_x=$+1
	sub 0
.fix_y=$+1
	sub 0
	ld h,a
	ret

; z = unsignedmul(x, y);

; if (x < 0)
;     z -= (y << 8);
; if (y < 0)
;     z -= (x << 8);

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

	SECTION .bss,"uR"

workmem_start:
	align 8
sine_table:
	dsb 256,0

	align 8
pixel_to_bits_color:
	dsb 4,0

;	align 8
pixels_draw:
	dsb 2,0 ; x,y
pixels_buffer:
	dsb 60*2,0 ; x,y
pixels_clear:
	dsb 2,0 ; x,y
pixels_end:


workmem_len=$-workmem_start
