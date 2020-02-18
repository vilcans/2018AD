	GLOBAL fldscroll_start

	INCLUDE vz.inc
	INCLUDE timing.inc
	INCLUDE sleep.inc

text_height = 8
text_width_chars = $20
text_width_bytes = text_width_chars/8

sine_amplitude = 7

time	MACRO
cycles_left SET cycles_left-(\1)
	IF cycles_left<0
	FAIL Out of cycles
	ENDIF
	ENDM

fldscroll_start:
	ld hl,bitmap
	ld b,text_width_bytes*text_height
	xor a
.clear_loop:
	ld (hl),a
	inc hl
	djnz .clear_loop

	ld a,193  ; wait until out of screen
	ld (positions_end),a

	ld c,sine_amplitude
	ld hl,sine_table
	call generate_sine

	call wait_vbl

	ld hl,$7000
	ld a,$80
	ld bc,$0002
.clear_screen:
	ld (hl),a
	inc hl
	djnz .clear_screen
	dec c
	jr nz,.clear_screen

main_loop:
	; Advance text
.char_pos = $+1
	ld a,1
	dec a
	jr nz,.after_text_advance

.text_addr = $+1
	ld hl,text
	ld a,(hl)
	inc hl
	ld (.text_addr),hl
	dec a
	ret m    ; text ends with $00

	ld h,0
	rla  ; *2
	rla  ; *4
	rla  ; *8
	rl h
	ld l,a
	ld bc,font
	add hl,bc

	ld a,9  ; width of char
	ld c,0  ; start char with empty bitmap
	jr .after_new_char

.after_text_advance:

font_addr = $+1
	ld hl,font
	ld c,(hl)
	inc hl
.after_new_char:
	ld (.char_pos),a
	ld (font_addr),hl
	ld a,c
	ld (current_char_bitmap),a

	; Generate positions
	ld b,text_height
	ld h,>sine_table

.sine_pos = $+1
	ld a,0
	add 2
	ld (.sine_pos),a
	ld l,a

	ld de,positions

	ld c,20    ; position
.each_pos:
	ld a,c
	add (hl)
	ld (de),a
	inc de

	ld a,l
	add 40
	ld l,a

	ld a,c
	add 21
	ld c,a

	djnz .each_pos

	ld h,$68
.wait_vbl:
	bit 7,(hl)
	jr nz,.wait_vbl

cycles_left SET $1a74*4

	; Draw 

	ld ix,text_chars
	ld de,$7000
	ld hl,bitmap
	ld b,text_height
.each_row:
	push bc
	ld a,(ix)
	inc ix
	ld (.char),a

	ld a,text_width_bytes
.each_column:
	ex af,af'

	ld c,(hl)
	inc hl

	scf     ; 4t  TODO: move before .each_byte; rl c will set carry
	rl c    ; insert 1 into bit 0
.each_bit:
	sbc a   ; 4t
.char = $+1
	and $ec ; 7t
	or $80  ; 7t

	ld (de),a  ; 7t
	inc e   ; 4t

	rl c    ; insert 0 into bit 0
	jr nz,.each_bit

	ex af,af'
	dec a
	jp nz,.each_column

	pop bc
	djnz .each_row

	; Scroll
current_char_bitmap = $+1
	ld c,0

	ld de,bitmap_end-1
	ld b,text_height
.each_scroll_row:
	rl c
	REPT text_width_bytes
	ld a,(de)
	rla
	ld (de),a
	dec de   ; If bitmap and bitmap_end are same page: dec e
	ENDR

	djnz .each_scroll_row

	ld a,$10
	ld ($6800),a

.wait_vbl_end:  ; TODO: try removing this, we already did wait_vbl
	ld a,($6800)
	rla
	jr nc,.wait_vbl_end

sleep_time = $+1
	ld bc,$b52  ;cycles_left/4
	wait_nops

	ld hl,positions
	ld b,0       ; current line
.each_scanline:
cycles_left SET 228
	ld a,(hl)
	time 7
	sub b
	time 4
	jr z,.new_line  ; 12/7t
	time 7

	sub 12
	time 7
	jr c,.no_fld     ; 12/7t
	time 7

	; do FLD
	ld a,8   ; 7t
	ld ($6800),a  ; 13t
	time 20

	ld a,0   ; 7t
	ld ($6800),a  ; 13t
	time 20

.next:
	; next line
	inc b    ; increase current line
	time 4

	time 4   ; ld a,b
	time 7   ; cp 128

	time 10  ; jp nz

	IF cycles_left=131
	sleep_131
	ELSE
FAIL_cycles = cycles_left
	FAIL Wrong number of cycles
	ENDIF

	ld a,b
	cp 180
	jp nz,.each_scanline

	jp .end

.new_line:
	inc hl  ; 6t
	inc b   ; 4t
	sleep_183    ; 228-7-4-12-6-4-12
	jr .each_scanline  ; 12t

.no_fld:
	sleep_23   ; 20+20-5-12
	jr .next   ; 12t

.end:
	IF 1
	ld h,$68
	ld b,5
	xor a         ; 4t
.each_end_bar:
	ld (hl),a     ; 7t
	xor $10       ; 7t

	sleep_201     ; 228-14-13
	djnz .each_end_bar   ; 13t

	ENDIF

	IF !RELEASE
	tweak_timing sleep_time,$71fc
	ENDIF

	jp main_loop

wait_vbl:
	ld h,$68
.wait_vbl_end:
	ld a,(hl)
	add a
	jr nc,.wait_vbl_end

.wait_vbl:
	ld a,(hl)
	add a
	jr c,.wait_vbl

	ret

font:
	INCBIN font.bin

text:
	INCLUDE text.s
	db 0

text_chars:
	; 0 ($8x) = Green
	; 1 ($9x) = Yellow
	; 2 ($ax) = Blue
	; 3 ($bx) = Red
	; 4 ($cx) = Buff
	; 5 ($dx) = Cyan
	; 6 ($ex) = Magenta
	; 7 ($fx) = Orange
	db $bf
	db $ff
	db $9f
	db $cf
	db $cf
	db $9f
	db $ff
	db $bf

	SECTION .bss,"uR"

	ALIGN 8
sine_table:
	ds $100

bitmap:
	ds text_width_bytes*text_height
bitmap_end:

positions:
	ds text_height
positions_end:
	ds 1   ; end marker (out of screen position)
