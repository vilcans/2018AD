	GLOBAL ykaros_start

	INCLUDE vz.inc
	INCLUDE timing.inc
	INCLUDE sleep.inc

USE_IRQ=0
SCREEN_HEIGHT=64
SCREEN_WIDTH=128

STATE_INTRO = 0
STATE_DEMO = 1
STATE_OUTRO = 2

ykaros_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif


	; when we get here in the demo 
	; we are in textmode
	call clear_screen
	; and now we are in gfxmode

	ld hl,sine_table
	ld b,26
	ld c,26
	call generate_sine_with_offset

	call poke_buffer
.move_loop:
	call prepare_fill_screen

	call waitvbl
	ld a,%11000
	ld ($6800),a ; bgcolor

	call fill_screen
	call draw_pixels
	call poke_buffer

timing = $+1
	ld bc,390+(57*84)   ; = 390+57*(scanline to wait for)
	wait_nops

	ld a,%01000
	ld ($6800),a ; bgcolor

	IF !RELEASE
	tweak_timing timing,$701c
	ENDIF

.raster_bar_sine=$+1
	ld hl,sine_table+$40 ; (hl) == 0
	ld c,(hl)
	inc l
	ld (.raster_bar_sine),hl
	ld a,(hl)
	; only three possible cases
	; 0, -1 or +1
	sub c
	jp z,.no_rb_change
	jp m,.rb_negative

	ld hl,(timing)
	ld de,57
	add hl,de
	ld (timing),hl
	jp .rb_done

.rb_negative:
	ld hl,(timing)
	ld de,-57
	add hl,de
	ld (timing),hl
;	jp .rb_done

.no_rb_change:
.rb_done:

	ld a,(state)
	cp STATE_INTRO
	jp z,.state_intro
	cp STATE_DEMO
	jp z,.state_demo

.prepare_next_frame:

.framecounter=$+1
	ld hl,50*15
	dec hl
	ld (.framecounter),hl
	ld a,l
	or h
	jp nz,.move_loop

	jp .do_outtro

.state_intro:
	ld a,(current_screen_height)
	cp SCREEN_HEIGHT
	jp z,.all_on
	inc a
	ld (current_screen_height),a
.all_on:

	ld a,(fill_screen_height)
	cp SCREEN_HEIGHT+1
	jp z,.all_filled
	inc a
	ld (fill_screen_height),a
	jp .prepare_next_frame

.all_filled:
	ld a,STATE_DEMO
	ld (state),a
	jp .prepare_next_frame

.state_demo:
	jp .prepare_next_frame


.do_outtro:

	ld de,$7000
	ld hl,$7800-1
	ld c,64/2
.out_loop:
	push hl
	call waitvbl
	pop hl

	ld a,%11000
	ld ($6800),a ; bgcolor

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

	ld h,$68
.loop_clear:
	ld a,(hl)
	add a
	jp nc,.loop_clear

.loop_set:
	ld a,(hl)
	add a
	jp c,.loop_set

	ret

prepare_fill_screen:
fill_screen_height=$+1
	ld a,1
	cp SCREEN_HEIGHT+1
	ret nz

	ld hl,0
	ld (fill_screen.old_de),hl
	ld hl,buffer
	ld (fill_screen.old_stack_ptr),hl
	ret

fill_screen:
	ld (.stack_save),sp
.old_stack_ptr=$+1
	ld sp,buffer

.old_de=$+1
	ld de,$7000

	ld ixl,1
.loop:
	pop bc
	pop hl

.first_bytes:
	ld a,l
	cp e
	jp z,.left_column

	; bytes to the left
	ld a,(bc)
	ld (de),a
	inc e
	jp .first_bytes

.left_column:
	; left column
	ld a,(bc)
	ld (de),a
	inc e
	inc c
	ld a,(bc)
	ld (de),a
	inc e
	inc c
	ld a,(bc)
	ld (de),a
	inc e

	; bytes in the middle
	pop bc
	pop hl
.middle_bytes:
	ld a,l
	cp e
	jp z,.right_column

	ld a,(bc)
	ld (de),a
	inc e
	jp .middle_bytes

.right_column:
	; right column
	ld a,(bc)
	ld (de),a
	inc e
	inc c
	ld a,(bc)
	ld (de),a
	inc e
	inc c

; save a few bytes
;	ld a,(bc)
;	ld (de),a
;	inc de

	; bytes to the right
.last_bytes:
	ld a,e
	and %00011111
	jp z,.next

	ld a,(bc)
	ld (de),a
	inc de
	jp .last_bytes

.next:
;	dec ixl
;	jp nz,.loop

	ld (.old_de),de

	ld (.old_stack_ptr),sp
.stack_save=$+1
	ld sp,$0

	ret

draw_pixels:
current_screen_height=$+1
	ld a,1 ; SCREEN_HEIGHT

	push af

	ld (.stack_save),sp
	ld sp,buffer

.loop:
	pop hl  ; 10t
	pop de  ; 10t
	ldi     ; 16t
	ldi
	ldi
	pop hl
	pop de
	ldi
	ldi
	ldi
	dec a   ; 4t
	jp nz,.loop  ; 10t
.time_per_iteration = (10+10+16*3)*2+4+10

.stack_save=$+1
	ld sp,$0

	ld a,SCREEN_HEIGHT+1
	pop bc
	sub b
.delay:
	sleep_136  ; .time_per_iteration-4-10
	dec a         ; 4t
	jp nz,.delay  ; 10t
	ret

poke_buffer:
	ld hl,buffer
	ld de,$7000

	exx

.current_sine_1=$+1
	ld hl,sine_table
.current_sine_2=$+1
	ld de,sine_table

	ld b,SCREEN_HEIGHT
.loop:

	ld c,0
	ld a,(hl)

	srl a
	rl c

	srl a
	rl c

	ld (.dst_1),a

	; c will now be bits within byte, but in wrong order
	; 00 is left pixel left_bar_0
	; 10 is left_bar_1
	; 01 is left_bar_2
	; 11 is left_bar_3
	ld a,c
	rla
	rla ; multiply by 4
	add <left_bar_0
	ld (.src_1),a

	ld a,l
	add 2
	ld l,a

	exx

.src_1=$+1
	ld bc,left_bar_0
	; src
	ld (hl),c
	inc l
	ld (hl),b
	inc l
	; dst
.dst_1=$+1
	ld a,0
	add e
	ld (hl),a
	inc l
	ld (hl),d ; TODO this will be the same every frame
	inc l

	ld a,e
	add 128/4/2
	ld e,a
	ld a,d
	adc 0
	ld d,a

	exx

	ld c,0
	ld a,(de)

	srl a
	rl c

	srl a
	rl c

	ld (.dst_2),a

	; c will now be bits within byte, but in wrong order
	ld a,c
	rla
	rla ; multiply by 4
	add <right_bar_0
	ld (.src_2),a

	ld a,e
	add 1
	ld e,a

	exx

.src_2=$+1
	ld bc,right_bar_0
	; src
	ld (hl),c
	inc l
	ld (hl),b
	inc l
	; dst
.dst_2=$+1
	ld a,0
	add e
	ld (hl),a
	inc l
	ld (hl),d ; TODO this will be the same every frame
	inc hl

	ld a,e
	add 128/4/2
	ld e,a
	ld a,d
	adc 0
	ld d,a

	exx
	djnz .loop

	ld a,(.current_sine_1)
	sub 3
	ld (.current_sine_1),a

	ld a,(.current_sine_2)
	add 1
	ld (.current_sine_2),a

	ret

clear_screen:
	; we are in text mode, fill upper part first
	; invisible in textmode
	call waitvbl
	ld hl,$7400
	ld de,$7401
	ld a,0
	ld (hl),a
	ld bc,$400-1
	ldir

	; now fill upper part
	call waitvbl
	ld hl,$7000
	ld de,$7001
	ld a,0
	ld (hl),a
	ld bc,$400-1
	ldir

	; and go hires
	ld a,%11000
	ld ($6800),a ; hires

	ret

state:
	defb STATE_INTRO

	align 8
	; order of these are important
left_bar_0:
	defb %10101010
	defb %10111111
	defb %11111111
	defb 2 ; dummy so we get 4 byte alignment

left_bar_2:
	defb %10101010
	defb %10101011
	defb %11111111
	defb 2 ; dummy so we get 4 byte alignment

left_bar_1:
	defb %10101010
	defb %10101111
	defb %11111111
	defb 2 ; dummy so we get 4 byte alignment

left_bar_3:
	defb %10101010
	defb %10101010
	defb %11111111
	defb 2 ; dummy so we get 4 byte alignment

right_bar_0:
	defb %11111111
	defb %11010101
	defb %01010101
	defb 2 ; dummy so we get 4 byte alignment

right_bar_2:
	defb %11111111
	defb %11111101
	defb %01010101
	defb 2 ; dummy so we get 4 byte alignment

right_bar_1:
	defb %11111111
	defb %11110101
	defb %01010101
	defb 2 ; dummy so we get 4 byte alignment

right_bar_3:
	defb %11111111
	defb %11111111
	defb %01010101
	defb 2 ; dummy so we get 4 byte alignment


	SECTION .bss,"uR"

workmem_start:
	align 8
sine_table:
	dsb 256

	align 8
; what to draw, src addr, dst addr, src addr, dst addr
buffer:
	dsb SCREEN_HEIGHT*2*4,0




workmem_len=$-workmem_start

