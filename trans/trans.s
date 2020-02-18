	GLOBAL trans_start

	INCLUDE vz.inc

trans_start:
	ld a, $c0
	ld (peel_layer.fill_char), a
	call clear_graphics
	ld a, $cf
	call clear_text

	ld c, 0
.next_frame

	call peel_layer

	inc c
	ld a, 8
	cp c
	jr nz, .next_frame

	ret

waitvbl:
.loop_clear:
	ld a,($6800)
	and %10000000
	jp z,.loop_clear

.loop_set:
	ld a,($6800)
	and %10000000
	jp nz,.loop_set
	ret

	; c = offset
peel_layer:
	ld a, c
	rrca
	rrca
	rrca
	and $e0
	ld l, a   ; h=32*c
	neg
	sub 32
	add c
	ld d, $71
	ld e, a
	ld a, l
	add c
	ld l, a   ; l = 32*c + c
	ld h, $70


	ld a, c
	add a
	neg
	add 30
	ld b, a  ; b = 32 - 2*c

	call waitvbl

	push de
	push hl

	ld a, $c4
	ld (de), a
	ld (hl), $c1

	ld a, $cc
.horisontal
	inc l
	ld (hl), $c3
	inc e
	ld (de), a
	djnz .horisontal
	ld a, $c8
	inc l
	inc e
	ld (de), a
	ld (hl), $c2

	ld de, 32
	exx
	ld de, 32
	pop hl
	push hl
	exx

	ld a, c
	add a
	neg
	add 13
	jp m, .skip_vertical1
	inc a

	ld b, a  ; b = 16 - 2*c


;	call waitvbl


.vertical
	add hl, de
	ld (hl), $ca
	exx
	add hl, de	
	ld (hl), $c5
	exx
	djnz .vertical

.skip_vertical1
	; second layer
	;
	pop hl
	pop de

	ld a, c
	add a
	neg
	add 31
	ld b, a  ; b = 32 - 2*c

	push hl

	call waitvbl

.fill_char = $+1
	ld a, $c0

.horisontal2
	ld (hl), a
	inc l
	ld (de), a
	inc e
	djnz .horisontal2
	ex af, af'

	ld de, 32
	exx
;	ld de, 32
	pop hl
	exx

	ld a, c
	add a
	neg
	add 15
	ret m    ; skip vertical 2
	inc a
	ld b, a  ; b = 16 - 2*c

;	call waitvbl

	ex af, af'
.vertical2
	ld (hl), a
	add hl, de
	exx
	ld (hl), a
	add hl, de	
	exx
	djnz .vertical2
	
	ret

	

clear_graphics:
	ld hl,$7000
	ld de,$7001
	ld a,0
	ld (hl),a

	call waitvbl

;	ld a,%11000
	ld a, U1_VDG_MODE | U1_VDG_BACKGROUND
	ld ($6800), a ; hires + buff

	ld bc,$400
	ldir

	call waitvbl
	ld bc,$400
	ldir
	ret

	; a = char to set
clear_text:
	ld hl,$7000
	ld de,$7001
	ld (hl),a
	ld bc,$200
	call waitvbl
	ldir
	ld a, 0   
	ld ($6800), a  ; text + black border

	ret
