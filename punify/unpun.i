

; Added this here so you don't have to include msx.i
	ifndef VDP_DATAR
VDP_DATAR       EQU	$84	; for some reason SVI separates read and write ports
	endif
	ifndef VDP_DATAW
VDP_DATAW       EQU	$80
	endif

; for punify -B
; Can run from ROM
;  in: hl = data start
; 
	MACRO UNPUN_TO_VDP
unpun_to_vdp_\@
	; assume we have only ROM so we can't use the stack.. but we can use the stackpointer :)
	ld ix, 0
	add ix, sp	; save stack pointer
	; sp is data start
	ld sp, hl
	ld c, VDP_DATAW

.loop_\@
	ld b, (hl)
	inc hl
	ld a, b
	rlca
	jr c, .block_\@
	and a
	jr z, .end_\@
	rlca
	jr nc, .simple_\@   ; < 64 byte block
	ld e, (hl)
	inc hl
	ld a, 63
	and b
	jr z, .fullbyte_\@    ; could be something like 135
.multi_\@
	ld b, 0
	otir
	dec a
	jr nz, .multi_\@
.fullbyte_\@
	ld b, e
.simple_\@
	otir
	jr .loop_\@

.block_\@
	res 7, b
	ld d, (hl)
	inc hl
	ld e, (hl)
	inc hl
	ex de, hl
	add hl, sp
	otir
	ex de, hl
	jr .loop_\@
.end_\@
	ld sp, ix
	ENDM


; for punify -b faster and better but unpacks to RAM and needs run in ram and a stack
; in: hl = src, de = dst
	MACRO UNPUN_MEM
unpun_mem_\@
	ex de, hl
	ld (unpun_mem_dst_\@), hl
	ex de, hl

.unpun_loop
	ld a, (hl)
	inc hl
	and a
	jp m,.unpun_block
	ret z
	bit 6, a
	jr z, .unpun_simple   ; < 64 byte block
	and 63
	ld b, a
	ld c, (hl)
	inc hl
.unpun_multi
	ldir
	jp .unpun_loop
.unpun_simple
	ld b, 0
	ld c, a
	ldir
	jp .unpun_loop

.unpun_block
	ld b, (hl)
	inc hl
	ld c, (hl)
	inc hl
	push hl
unpun_mem_dst_\@ EQU $+1
	ld hl, 0
	add hl, bc
	ld b, 0
	and 127
	ld c, a
	ldir
	pop hl
	jp .unpun_loop
	ENDM

;
; for punify -b faster and better but unpacks to RAM and needs run in ram and a stack
; NOTE: VDP read address must be set before calling!!
; in: hl = destination address in ram
	MACRO UNPUN_FROM_VDP
unpun_from_vdp_\@
	ld (unpun_from_vdp_dst_\@), hl
	ld c, VDP_DATAR
.unpun_loop_\@
	in a, (VDP_DATAR)
	and a
	jp m, .unpun_block_\@
	ret z
	bit 6, a
	jr z, .unpun_simple_\@   ; < 64 byte block
	and 63
	in b, (c)
	inir
	and a
	jr z, .unpun_loop_\@
.copy_block_\@
	inir
	dec a
	jr nz, .copy_block_\@
	jp .unpun_loop_\@

.unpun_simple_\@
	ld b, a
	inir
	jp .unpun_loop_\@

.unpun_block_\@
	ex de, hl
	in b, (c)
unpun_from_vdp_dst_\@ EQU $+1
	ld hl, 0
	in c, (c)
	add hl, bc
	ld b, 0
	and 127
	ld c, a
	ldir
	ex de, hl
	ld c, VDP_DATAR
	jp .unpun_loop_\@
	ENDM
