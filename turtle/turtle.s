	GLOBAL turtle_start

	INCLUDE vz.inc

USE_IRQ=0
SCREEN_HEIGHT=64
SCREEN_WIDTH=128

NUM_CIRCLES=10
MAX_RADIUS=16

EXTRA_Y_OFFSET=1

turtle_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	; when we get here in the demo, we are in textmode
	call clear_screen

	ld hl,sine_table
	ld c,127
	call generate_sine

	call generate_color_tables
	call init_pen

	ld hl,pattern
	ld (pattern_position),hl

.move_loop:
	call waitvbl

	ld hl,(framecounter)
	inc hl
	ld (framecounter),hl

	ld b,5
.turtle_loop:
	push bc
	call do_turtle
	pop bc

	ld ix,(pattern_position)
	ld a,(ix+0)
	cp PEN_DONE
	ret z

	djnz .turtle_loop
	
	jp .move_loop

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

do_turtle:

.next_command_counter=$+1
	ld a,1
	dec a
	jp z,.get_next_command
; keep doing this
	ld (.next_command_counter),a

	ld ix,pen
	xor a ; reset carry
	ld e,a
	ld a,(ix+2) ; x pos
	rra
	rl e
	rra ; a = x byte to set
	rl e ; c = bits to set -> but in wrong order
	ld c,a

	xor a ; reset carry
	ld l,a
	ld a,(ix+5) ; y pos
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
	ld c, a ; current bits

	ld a,(ix+1) ; pen color
	and c
	ld b,a ; pen color masked

	ld a,(hl) ; current bit value
	or c
	xor c ; clear current bits
	or b ; add new color bits 
	ld (hl),a

	ld h,(ix+2) ; xpos hi byte
	ld l,(ix+3) ; xpos lo byte
	ld e,(ix+4) ; x velocity

	ld a,e
	rlca
	sbc a,a
	ld d,a ; sign extended e into de

	add hl,de
	ld a,h
	and 128-1
	ld (ix+2),a
	ld (ix+3),l

	ld h,(ix+5) ; ypos hi byte
	ld l,(ix+6) ; ypos lo byte
	ld e,(ix+7) ; y velocity

	ld a,e
	rlca
	sbc a,a
	ld d,a ; sign extended e into de

	add hl,de
	ld a,h
	and 64-1
	ld (ix+5),a
	ld (ix+6),l

	ret

.get_next_command:
	ld ix,(pattern_position)
	ld a,(ix+0)
	; TODO jump table
	cp PEN_DONE
	ret z
	cp PEN_UP
	jp z,.pen_up
	cp PEN_DOWN
	jp z,.pen_down
	cp PEN_MOVE
	jp z,.pen_move
	cp PEN_ROTATE
	jp z,.pen_rotate
.unknown_command:
	jp .unknown_command

.pen_up:
	ld iy,pen
	xor a
	ld (iy+0),a
	inc ix
	ld (pattern_position),ix
	ret	

.pen_down:
	ld iy,pen
	ld a,-1
	ld (iy+0),a ; pen down
	ld a,(ix+1)
	ld (iy+1),a ; color	
	inc ix
	inc ix
	ld (pattern_position),ix
	ret	

.pen_move:
	ld a,(ix+1)
	ld (.next_command_counter),a
	inc ix
	inc ix
	ld (pattern_position),ix
	ret	

.pen_rotate:
	ld a,(ix+1)
	ld iy,pen
	ld l,a
	ld a,(iy+8)
	add l
	ld (iy+8),a
	ld l,a
	ld h,>sine_table
	ld a,(hl)
	ld (iy+7),a ; x add cos
	ld a,l
	add 256/4
	ld l,a
	ld a,(hl)
	ld (iy+4),a ; y add sin
	
	inc ix
	inc ix
	ld (pattern_position),ix
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

init_pen:
	ld hl,pen
	ld (hl),PEN_UP
	inc hl
	ld (hl),0 ; color
	inc hl
	ld (hl),START_X-4 ; x pos 8.8
	inc hl
	ld (hl),0
	inc hl
	ld (hl),0 ; x velocity 0.8
	inc hl
	ld (hl),START_Y-4+EXTRA_Y_OFFSET; y pos 8.8 ; hack to move hand one pixel down
	inc hl
	ld (hl),0
	inc hl
	ld (hl),0 ; y velocity 0.8
	inc hl
	ld (hl),0 ; current rotation

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

PEN_DONE = -1
PEN_UP = 0 ; data = no data
PEN_DOWN = 1 ; data = color 1 byte
PEN_MOVE = 2 ; data = distance 1 byte
PEN_ROTATE = 3 ; data = angle 1 byte (index into sine table)

PEN_COLOR_00 = %00000000
PEN_COLOR_01 = %01010101
PEN_COLOR_10 = %10101010
PEN_COLOR_11 = %11111111

pattern:
	; command, data

	include 'hand.inc'

	if 0	

	defb PEN_ROTATE,0 ; always start with direction
	defb PEN_DOWN,PEN_COLOR_11
	defb PEN_ROTATE,-109
	defb PEN_MOVE,8
	defb PEN_ROTATE,-7
	defb PEN_MOVE,8
	defb PEN_ROTATE,-2
	defb PEN_MOVE,8
	defb PEN_ROTATE,5
	defb PEN_MOVE,7
	defb PEN_DONE

	defb PEN_ROTATE,64
	defb PEN_DOWN,PEN_COLOR_10
	defb PEN_MOVE,50
	defb PEN_ROTATE,64
	defb PEN_DOWN,PEN_COLOR_11
	defb PEN_MOVE,50
	defb PEN_ROTATE,64
	defb PEN_DOWN,PEN_COLOR_01
	defb PEN_MOVE,50
	defb PEN_ROTATE,64
	defb PEN_DONE

	endif

framecounter:
	defw 0

	SECTION .bss,"uR"

workmem_start:
	align 8

sine_table:
	dsb 256,0

	align 8
pixel_to_bits_color:
	dsb 4,0

pen:
	dsb 1,0 ; 0 pen up/down
	dsb 1,0 ; 1 pen color 00 01 10 11
	dsb 2,0 ; 2,3 position x 8.8
	dsb 1,0 ; 4 add x 0.8
	dsb 2,0 ; 5,6 position y 8.8
	dsb 1,0 ; 7 add y 0.8
	dsb 1,0 ; 8 current rotation

pattern_position:
	dsw 1,0

workmem_len=$-workmem_start

