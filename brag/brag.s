	GLOBAL brag_start

	INCLUDE vz.inc

USE_IRQ=0

brag_start:

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

	ld hl,message
	ld de,$7000
	call print_message_init

.move_loop:
	call print_cursor_init
	ld b,2
.delay:
	push bc
	call waitvbl
	call print_cursor
	pop bc
	djnz .delay

;	ld a,%10000
;	ld ($6800),a ; bgcolor

	call print_message
	jp z,do_scroll_up

;	ld a,%00000
;	ld ($6800),a ; bgcolor

	jp .move_loop

do_scroll_up:

	ld b,50*2
.loop:
	call waitvbl
	djnz .loop

out_loop_1:
	call waitvbl

	ld a,(.framecounter)
	and %11
	jp nz,.not_now

	ld bc,15*32
	call scroll_up
.not_now:

.framecounter=$+1
	ld hl,32
	dec hl
	ld (.framecounter),hl
	ld a,l
	or h
	jp nz,out_loop_1

out_loop_2:
	call waitvbl

	ld a,(.framecounter)
	and %11
	jp nz,.not_now

	ld bc,6*32
	call scroll_up
.not_now:

.framecounter=$+1
	ld hl,32
	dec hl
	ld (.framecounter),hl
	ld a,l
	or h
	jp nz,out_loop_2

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

; bc = num rows * 32
scroll_up:
	ld hl,$7000+32
	ld de,$7000
	ldir

	ld a,' '
	ld b,32
.clear:
	ld (de),a
	inc de
	djnz .clear

	ret

message:
	;     12345678901234567890123456789012
	defb 'SOME FACTS ABOUT THIS DEMO:     '
	defb '- CUSTOM CABLE ALLOWS PLAYING   '
	defb '  MUSIC FROM CD WHILE LOADING.  '
	defb '- UNDOCUMENTED BINARY FORMAT    '
	defb '  USED WITH CRUN AND CLOAD.     '
	defb '- CUSTOM SPEEDLOADER USED FOR   '
	defb '  LOADING EACH PART FROM CD AT  '
	defb '  ABOUT 4000 BPS.               '
	defb '- UNDOCUMENTED HARDWARE FEATURE '
	defb '  ALLOWS C64 FLD-STYLE EFFECTS. '
	defb '- COUNTING CYCLES TO GET HIGHER '
	defb '  Y RESOLUTION.                 '
	defb '- COUNTING CYCLES TO ACCESS VRAM'
	defb '  DURING HORIZONTAL BLANKING.   ' 
	defb '- NOTE: NOT USING 1 BIT AUDIO   '
	defb '-*# MUSIC IS PLAYED FROM CD #*- '

	defb 0
