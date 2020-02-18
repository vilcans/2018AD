	GLOBAL gdpr_start

	INCLUDE vz.inc

USE_IRQ=0

gdpr_start:

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
	ret z

;	ld a,%00000
;	ld ($6800),a ; bgcolor

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

message:
	;     12345678901234567890123456789012
	defb '                                '
	defb ' DUE TO THE GDPR WE ARE UPDATING'
	defb '       OUR PRIVACY POLICY       '
	defb '                                '
	defb 'YOUR PRIVACY IS IMPORTANT TO US '
	defb '    AND WE ARE COMMITTED TO     ' 
	defb '         PROTECTING YOUR        '
	defb '       PERSONAL INFORMATION     '
	defb '                                '
	defb '   BY WATCHING THIS DEMO YOU    '
	defb '  CONSENT TO THE TERMS OF THIS  '
	defb '         PRIVACY POLICY         '
	defb '                                '
	defb ' IF YOU WISH TO OPT OUT YOU CAN '
	defb '      PRESS STOP ON CD NOW      '
	defb '                                '

	defb 0
