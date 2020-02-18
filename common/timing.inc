; For waiting and tweaking timing

	INCLUDE printing.inc

wait_nops MACRO
; Delay some time
; BC = Number of cycles to wait divided by 4
; Additionally, delays the overhead given in wait_nops_overhead_cycles
;
; Delay 100 cycles:
;
;     wait_nops (100-wait_nops_overhead_cycles)/4

	ld a,c             ; 4t
	and 7              ; 7t
	xor 7              ; 7t
	ld (.reljump\@),a  ; 13t
.reljump\@ = $+1
	db $18,$00   ; jr xx   ; 12t
	db 0,0,0,0,0,0,0  ; 7 nops

	; Div by 4 (not 8 as we do dec bc twice in wait)
	srl b    ; 8t
	rr c     ; 8t
	srl b    ; 8t
	rr c     ; 8t

	res 0,c  ; 8t

	; Loop takes 32t (8 nops) per iteration:
.wait\@:
	dec bc   ; 6t
	dec bc   ; 6t
	ld a,b   ; 4t
	or c     ; 4t
	jr nz,.wait\@  ; 12/7t

	inc bc   ; 6t  just to make the overhead divisable by 4
	ENDM


; The time in nops that wait_nops has as overhead
wait_nops_overhead_cycles = (4+7+7+13+12+ 8+8+8+8 +8 -5 +6)

tweak_timing MACRO
; Tweak a delay value with the keyboard.
; Parameters:
;   \1 = pointer to word that contains the value
;   \2 = screen address where to print the value

.keybase = $6880

	ld ix,.keybase
	xor a  ; diff to add to HL

	bit 2,(ix+$68bf-.keybase)   ; Return
	jr nz,.after_freeze

	xor a
	ld ($6800),a
	ld bc,0
.wait:
	dec bc
	ld a,b
	or c
	jr nz,.wait
.after_freeze:

	bit 4,(ix+$68fe-.keybase)   ; Q
	jr nz,.after_coarse_up
	ld a,16
.after_coarse_up:
	bit 4,(ix+$68fd-.keybase)   ; A
	jr nz,.after_coarse_down
	ld a,-16
.after_coarse_down:

	bit 1,(ix+$68fe-.keybase)   ; W
	jr nz,.after_fine_up
	ld a,1
.after_fine_up:
	bit 1,(ix+$68fd-.keybase)   ; S
	jr nz,.after_fine_down
	ld a,-1
.after_fine_down:

	bit 3,(ix+$68fe-.keybase)   ; E
	jr nz,.after_scanline_up
	ld a,228/4
.after_scanline_up:

	bit 3,(ix+$68fd-.keybase)   ; D
	jr nz,.after_scanline_down
	ld a,-228/4
.after_scanline_down:

	ld hl,(\1)
.last_diff = $+1
	cp 0
	ld (.last_diff),a
	jr z,.no_repeat

	ld e,a
	add a
	sbc a   ; sign extend
	ld d,a
	add hl,de
	ld (\1),hl
.no_repeat:
	push hl
	ld a,h
	ld hl,\2
	print_byte
	pop hl
	ld a,l
	ld hl,\2+2
	print_byte

	ENDM

; vim: set filetype=asm ts=16 sw=16 tw=0 noet :
