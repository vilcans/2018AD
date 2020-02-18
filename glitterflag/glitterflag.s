	GLOBAL glitterflag_start

	INCLUDE vz.inc

USE_IRQ=0

SCREEEN_WIDTH = 32
SCREEN_HEIGHT = 16

X_PER_COL_ADD = 35
Y_PER_COL_ADD = 13
X_PER_ROW_ADD = 33
Y_PER_ROW_ADD = 13

X_PER_FRAME_ADD = 5
Y_PER_FRAME_ADD = 3

NUM_PER_ROW = 8
NUM_ROWS = 6

glitterflag_start:
	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	ld hl,$7000
	ld a,' '|%01000000
	ld (hl),a
	ld de,$7001
	ld bc,32*16-1
	ldir

	ld hl,sine_table
	ld b,10
	ld c,10
	call generate_sine_with_offset

.move_loop:
	call waitvbl

	ld a,%10000
	ld ($6800),a ; bgcolor

	call copy_to_screen
	call display

	ld a,(.framecounter)
	and %1111
	jp nz,.not_now

	ld a,(current_num_rows)
	cp NUM_ROWS
	jp z,.all_go
	inc a
	ld (current_num_rows),a


.all_go:
.not_now:

	ld a,%00000
	ld ($6800),a ; bgcolor


.framecounter=$+1
	ld hl,50*10
	dec hl
	ld (.framecounter),hl
	ld a,l
	or h
	jp nz,.move_loop

out_loop:
	call waitvbl

	ld a,%10000
	ld ($6800),a ; bgcolor

	call copy_to_screen
	call display

	ld a,(.framecounter)
	and %1111
	jp nz,.not_now

	ld a,(current_num_rows)
	or a
	jp z,.done
	dec a
	ld (current_num_rows),a

.not_now:

.framecounter=$+1
	ld hl,50*10
	dec hl
	ld (.framecounter),hl

	jp out_loop

.done:
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
	ld de,$7000
	ld hl,buffer

	ld c,%10010000

	ld ixl,SCREEN_HEIGHT
.y_loop:
	ld b,SCREEEN_WIDTH
.x_loop:
	ld a,(hl)
	ld (hl),c
	ld (de),a

	inc l
	inc e

	djnz .x_loop

	ld a,e
	or a
	jp nz,.no_page
	inc h
	inc d
.no_page:
	dec ixl
	jp nz,.y_loop

	ret


display:

	ld h,>sine_table

.y=$+1
	ld a,$40
	ld (.current_y),a
.x=$+1
	ld a,0
	ld (.current_x),a


	xor a
	ld (.offset_y),a


	exx

current_num_rows=$+1
	ld a,0
	or a
	ret z
	ld c,a
.y_loop:

	xor a
	ld (.offset_x),a

current_num_per_row=$+1
	ld a,8
	or a
	ret z
	ld b,a
.x_loop:
	exx

	; h points to sine table hi byte
	ld d,>buffer ; screen hi byte

.current_y=$+1
	ld l,0
	ld a,(hl)
	or a
	rra
.offset_y=$+1
	add 0
	ld c,a
.current_x=$+1
	ld l,0
	ld a,(hl)
	or a
	rra
.offset_x=$+1
	add 0
	ld b,a

	ld a,c
	cp 16
	jp c,.upper_half

.lower_half:
	sub 16
	inc d

.upper_half
	; a = y
	or a
	rra
	jp c,.y_set_odd

.y_set_even:
	; todo use a table
	or a
	rla 
	rla 
	rla 
	rla 
	rla 

	ld c,a

	ld a,b
	or a
	rra
	jp nc,.x_set_left_even
.x_set_right_even:
	add c
	ld e,a
	ld a,(de)
	or %11110100
	jp .draw_even

.x_set_left_even:
	add c
	ld e,a
	ld a,(de)
	or %11011000

.draw_even:
;	xor ixl
	ld (de),a

	jp .prepare_next

.y_set_odd:
	; todo use a table
	or a
	rla 
	rla 
	rla 
	rla 
	rla 

	ld c,a

	ld a,b
	or a
	rra
	jp nc,.x_set_left_odd
.x_set_right_odd:
	add c
	ld e,a
	ld a,(de)
	or %10110001
	jp .draw_even

.x_set_left_odd:
	add c
	ld e,a
	ld a,(de)
	or %10010010

.draw_odd:
	ld (de),a

	jp .prepare_next

	nop

.prepare_next:

	exx

	ld a,(.offset_x)
	add 7
	ld (.offset_x),a

	ld a,(.current_x)
	add X_PER_COL_ADD
	ld (.current_x),a

	ld a,(.current_y)
	add Y_PER_COL_ADD
	ld (.current_y),a

	djnz .x_loop

	ld a,(.offset_y)
	add 4
	ld (.offset_y),a


	ld a,(.current_x)
	add (X_PER_ROW_ADD+(-X_PER_COL_ADD*NUM_PER_ROW))&$ff
	ld (.current_x),a

	ld a,(.current_y)
	add (Y_PER_ROW_ADD+(-Y_PER_COL_ADD*NUM_PER_ROW))&$ff
	ld (.current_y),a

	dec c
	jp nz,.y_loop


	ld a,(.x)
	add X_PER_FRAME_ADD
	ld (.x),a

	jp z,.no
	ld a,(.y)
	add Y_PER_FRAME_ADD
	ld (.y),a
.no:

	ret


	SECTION .bss,"uR"

	align 8
sine_table:
	dsb 256,0

	align 8
buffer:
	dsb SCREEEN_WIDTH*SCREEN_HEIGHT,0
