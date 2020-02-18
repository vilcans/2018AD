	GLOBAL raster_start

	INCLUDE vz.inc
	INCLUDE timing.inc
	INCLUDE sleep.inc

top_value = $10
bottom_value = $18

raster_start:
	halt   ; emulator gives phantom keypresses if we don't wait one frame

	ld hl,$7000
	ld de,$7001
	ld (hl),$ff  ;$aa
	ld bc,$7ff
	ldir

	ld hl,$7000
	ld b,64
	xor a
.draw:
	push af
	print_byte
	pop af

	inc hl
	inc hl
	ld (hl),'X'

	ld de,28
	add hl,de
	inc a
	djnz .draw

	ld hl,routine
	ld (interrupt_routine),hl
.w:
	jr .w

routine:
	;ld hl,$6800
;.wait:
	;bit 7,(hl)
	;jr z,.wait

	ld a,top_value
	ld ($6800),a

cycles_left = $1a89*4
sleep_time = $+1
	ld bc,cycles_left/4
	wait_nops

	ld a,bottom_value
	ld ($6800),a

	;sleep_209   ; 229-7-13
	;sleep_211
	;sleep_11

	ld a,top_value
	ld ($6800),a

	tweak_timing sleep_time,$701c

	ret

	;SECTION .bss,"uR"
