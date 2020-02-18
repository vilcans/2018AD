	GLOBAL covfefe_start

	INCLUDE vz.inc

USE_IRQ=0
SCREEN_HEIGHT=64
SCREEN_WIDTH=128

NUM_CIRCLES=10
MAX_RADIUS=16

covfefe_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	ld a,%01000
	ld ($6800),a ; hires

;	call clear_screen

	ld hl,sine_table
	ld b,8
	ld c,8
	call generate_sine_with_offset


loop:
	call waitvbl

	ld a,%11000
	ld ($6800),a ; bgcolor

	ld hl,(framecounter)
	inc hl
	ld (framecounter),hl

	call do_cube

;	ld a,%01000
;	ld ($6800),a ; bgcolor
	


	jp loop


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

; CP, and if the zero flag is set, A and the argument were equal
; else if the carry is set the argument was greater,
; and finally, if neither is set, then A must be greater

do_cube:

.angle=$+1
	ld a,-1
	inc a
	cp 256/4
	jp nz,.no_reset
	xor a
	; TODO next face color
.no_reset:
	ld (.angle),a

	ld h,>sine_table

	; 160.0 224.0 32.0 => increase by 64
	add 160
	ld l,a
	ld a,(hl)
	rlca
	ld (y1),a

	ld a,l
	add 64
	ld l,a
	ld a,(hl)
	rlca
	ld (y2),a

	ld a,l
	add 64
	ld l,a
	ld a,(hl)
	rlca
	ld (y3),a

	; 96.0 160.0 224.0 => increase by 64
	xor a ; clear carry
	ld a,(.angle)
	add 96
	ld l,a
	ld a,(hl)
	rra
	ld (x1),a

	xor a ; clear carry
	ld a,l
	add 64
	ld l,a
	ld a,(hl)
	rra
	ld (x2),a

	xor a ; clear carry
	ld a,l
	add 64
	ld l,a
	ld a,(hl)
	rra
	ld (x3),a



	if 0
	ld hl,coords
face_one:
	ld a,(y1)
	ld c,a
	ld a,(y2)
	sub c ; dy = y2 - y1
	ld c,a ; dy

	ld a,(x2)
	ld b,a
	ld a,(x1)
	sub b ; dx = x1 - x2
	ld b,a
	cp c ; if dy > dx
	jp c,.dy_gt_dx
.dy_lte_dx:
	ld a,c
	add a
	ld c,a ; 2*dy
	sub b
	ld e,a ; e = 2*dy - dx
	ld a,b
	add a
	ld b,a ; 2*dx
	
	ld a,(y1)
	ld d,a ; y

	ld a,e
	ld ixl,a
	ld a,(x2)
	ld e,a
	ld a,(x1)
	ld ixh,a
.x_loop:
	cp e
	jp z,.face_one_done

	ld (hl),d ; y
	inc hl
	ld (hl),a ; x
	inc hl
	push de
	exx
	pop de
	ld e,a
	ld a,d

	ld c,0
	rra
	rr c
	rra
	rr c
	rra
	rr c
	add $70 ; screen
	ld h,a

	ld a,%11111111
;	ld (hl),a

	exx
	ld a,ixl
	cp 0
	jp c,.no_inc_y
	inc d ; y = y + 1
	sub b ; e = e - 2*dx
.no_inc_y:
	add c ; e = e + 2*dy
	ld ixl,a
	ld a,ixh
	dec a ; x = x - 1
	jp .x_loop
                
.dy_gt_dx:
	ld a,b
	add a
	ld b,a ; 2*dx
	sub c
	ld e,a ; e = 2*dx - dy
	ld a,c
	add a
	ld c,a ; 2*dy

	ld a,(x1)
	ld d,a ; x

	ld a,e
	ld ixl,a
	ld a,(y2)
	ld e,a
	ld a,(y1)
	ld ixh,a
.y_loop:
	cp e
	jp z,.face_one_done

	ld (hl),a ; y
	inc hl
	ld (hl),d ; x
	inc hl
	ld a,ixl
	cp 0
	jp c,.no_inc_x
	dec d ; x = x - 1
	sub c ; e = e - 2*dy
.no_inc_x:
	add b ; e = e + 2*dx
	ld ixl,a
	ld a,ixh
	inc a ; y = y + 1
	jp .y_loop

.face_one_done:
face_two:

	endif
	ret

framecounter:
	defw 0

	SECTION .bss,"uR"

workmem_start:
	align 8

sine_table:
	dsb 256,0

	align 8
coords:
	dsb 64*2 ; should never be more than screen, usually much less

x1:
	dsb 1,0
y1:
	dsb 1,0
x2:
	dsb 1,0
y2:
	dsb 1,0
x3:
	dsb 1,0
y3:
	dsb 1,0

workmem_len=$-workmem_start

