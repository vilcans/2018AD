	org 0

	INCLUDE vz.inc

	di
	im 1
	xor a
	ld (u1),a

	ld hl,boot_text
	ld de,screen_start
	ld bc,boot_text_len
	ldir

	ld sp,$8000
	ld hl,data
	ld de,load_address
	push de
	ld bc,data_length
	ldir
	ret

	org $0038
	; IM 1 interrupt (vblank)
	jp interrupt_handler

interrupt_handler:    ; Original code in ROM at $2eb8
	push af			;2eb8	f5 	. 
	push bc			;2eb9	c5 	. 
	push de			;2eba	d5 	. 
	push hl			;2ebb	e5 	. 
	; Call the user-defined interrupt routine
	call user_interrupt		;2ebc	cd 7d 78 	. } x 
	; We hijack the stack so the following code is never run
	;call sub_3f7bh		;2ebf	cd 7b 3f 	. { ? 
	;call sub_2edch		;2ec2	cd dc 2e 	. . . 
	;call l2efdh		;2ec5	cd fd 2e 	. . . 
	;push af			;2ec8	f5 	. 
	;ld hl,07839h		;2ec9	21 39 78 	! 9 x 
	;bit 0,(hl)		;2ecc	cb 46 	. F 
	;call z,sub_301bh		;2ece	cc 1b 30 	. . 0 
	;pop af			;2ed1	f1 	. 
	;call sub_3430h		;2ed2	cd 30 34 	. 0 4 
	;pop hl			;2ed5	e1 	. 
	;pop de			;2ed6	d1 	. 
	;pop bc			;2ed7	c1 	. 
	;pop af			;2ed8	f1 	. 
	;ei			;2ed9	fb 	. 
	;reti		;2eda	ed 4d 	. M 

	; We should never end up here
	di
	ld hl,error_text
	ld de,screen_start
	ld bc,error_text_len
	ldir
.freeze:
	jr .freeze

boot_text:
	db '   FIVE FINGER PUNCH BOOT ROM   '
	db '   (C) 2018 FIVE FINGER PUNCH   '
boot_text_len = $-boot_text

error_text:
	db 'INTERRUPT RETURNED'
error_text_len = $-error_text


data:
	incbin unpack.bin
data_length = $-data

	org $3fff
	db 0
rom_end:
