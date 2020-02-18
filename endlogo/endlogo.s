	GLOBAL endlogo_start

	INCLUDE vz.inc

USE_IRQ=0

endlogo_start:

	di
	if USE_IRQ
	ld hl,flag_irq
	ld (user_interrupt+1),hl
	ei
	endif

	; textmode
	ld a,%00000
	ld ($6800),a ; bgcolor

.move_loop:
	call waitvbl

.logo_ptr=$+1
	ld hl,logo
.screen_ptr=$+1
	ld de,$7000
	ld bc,32
	ldir

	ld (.logo_ptr),hl
	ld (.screen_ptr),de
	ld a,d
	cp $72
	jp nz,.move_loop

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

logo:
	incbin 'vz-textmode_mm_looking_glass.bin'
