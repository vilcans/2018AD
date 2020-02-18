	GLOBAL technobabble_start

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

	ld de,message
	call randprint_init

.move_loop:
	call waitvbl

;	ld a,%10000
;	ld ($6800),a ; bgcolor

	call randprint_message
	or a
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
	defb 'LASER 200 A.K.A.                ' 
	defb 'DICK SMITH VZ200                '
	defb '                                '
	defb '- CPU ZILOG Z80 3.58 MHZ        ' 
	defb '- RAM 2 KB                      ' 
	defb '- VRAM 2 KB                     '
	defb '  CAN ONLY BE ACCESSED DURING   '
	defb '  BLANKING                      '
	defb '- MC6847 VDG                    '
	defb '- TEXT MODE 32X16               '
    defb '  NO CUSTOM CHARACTER SET       '
	defb '- GRAPHICS MODE 128X64          '
	defb '  4 COLOURS                     '
	defb '- 1 BIT AUDIO                   '
	defb '- ONE OF THE COLORS IS "BUFF"   '
	defb '  I.E. STOCKHOLMSVIT            '

	defb 0
