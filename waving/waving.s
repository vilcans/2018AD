	GLOBAL waving_start

	INCLUDE vz.inc

draw_width = $20   ; number of char columns to draw

color_offset = 6

;frames_per_run_0 = 42  = two beats
;frames_per_run_1 = 22  = one beat
frames_per_run_0 = 42*4-1
frames_per_run_1 = 24*4-1


waving_start:
	call initialize

	ld de,%1111111111000000
	ld a,-3
	ld c,10
	ld hl,(-2<<8)|(-3&$ff)
	call waving_run

	ld de,%1111110000000000
	ld c,19
	ld a,-4
	ld hl,(-2<<8)|(-7&$ff)
	call waving_run

	ld de,%1110001110000000
	ld a,2
	ld c,11
	ld hl,(-2<<8)|(-7&$ff)
	call waving_run

	ld de,%1111110000000000
	ld a,3
	ld c,29
	ld hl,(-2<<8)|(3&$ff)
	call waving_run

	ld de,%1110001110000000
	ld a,-2
	ld c,18
	ld hl,(-2<<8)|(7&$ff)
	call waving_run

	ld de,%1110001110000000
	ld a,-2
	ld c,18
	ld hl,(-2<<8)|(7&$ff)
	call waving_run

	ld de,%1110000000000000
	ld a,0
	ld c,14
	ld hl,(3<<8)|(5&$ff)
	call waving_run

out:
; Transition out

	ld a,$60
	ld de,$7000
	ld c,16
.each_row:
	call wait_vbl_end
	call wait_vbl
	ld (hl),$00
	ld b,32
.fill:
	ld (de),a
	inc de
	djnz .fill
	dec c
	jr nz,.each_row

	call wait_vbl_end
	call wait_vbl
	ld (hl),$08

	xor a   ; background color
	ld de,$7000
	ld b,2
.fill_vram:
	ld (de),a
	inc e
	jr nz,.fill_vram
	inc d
	djnz .fill_vram

	ret

waving_run:
; DE = bit pattern
; C = sine amplitude
; A = sine step
; H = sine 1 speed
; L = sine 2 speed

	ld (sine_step_1),a
	ld (sine_step_2),a

	ld a,h
	ld (sine1_speed),a
	ld a,l
	ld (sine2_speed),a

	push bc

	; Generate shifts
	ld hl,shifts
	;ld de,%1111111111000000
	ld b,16
.each_shift:
	ld (hl),d
	inc hl
	ld (hl),e
	inc hl
	ld a,d
	rla
	rl e
	rl d
	djnz .each_shift

	pop bc

	; Generate sine table
	ld hl,sine_table
	;ld c,sine_amplitude
	call generate_sine

	call wait_vbl_end

.frames_per_run = $+1
	ld a,frames_per_run_1
	xor frames_per_run_0^frames_per_run_1
	ld (.frames_per_run),a

	ld b,a
main_loop:
	push bc

	IF !RELEASE
	ld a,($68fd)  ; Ctrl key
	and 4
	jp z,0  ; reset
	ENDIF

	call wait_vbl

	ld hl,screen_buffer
	ld de,$7000
	ld bc,$200
.copy_loop:
	call ldi_32
	jp pe,.copy_loop

	xor a
	ld ($6800),a

	exx
sine_position = $+1
	ld de,sine_table      ; DE' = sine 1 pointer
sine_position2 = $+1
	ld hl,sine_table      ; HL' = sine 2 pointer
	exx

	ld d,>shifts
	ld ix,screen_buffer+draw_width-1
	ld h,>colors
.each_col:
	; Get sine for left part of char
	exx
	inc e     ; 4t
	ld a,l    ; 4t
sine_step_1 = $+1
	add 0     ; 7t
	ld l,a    ; 4t
	ld a,(de)
	add (hl)
	exx

	ld l,a
	res 0,l   ; Divide by two, but color table is two bytes per entry

	; Get bitmask for left part of char
	and 15
	add a
	ld e,a
	ld a,(de)  ; 7t
	ld c,a

	inc e        ; 4t
	ld a,(de)    ; 7t
	ld iyl,a     ; 8t  Store second byte of bitmap

	; Get sine for right part of char
	exx
	inc e     ; 4t
	ld a,l    ; 4t
sine_step_2 = $+1
	add 0     ; 7t
	ld l,a    ; 4t
	ld a,(de)
	add (hl)
	exx
	
	; Get bitmask for right part of char
	and 15
	add a
	ld e,a
	ld a,(de)
	ld b,a

	call draw_four_char_rows
	ld c,iyl    ; 8t  Get second byte of left bitmap
	inc e       ; 4t
	ld a,(de)   ; 7t  Get second byte of right bitmap
	ld b,a      ; 4t
	call draw_four_char_rows

	dec ixl
	jp p,.each_col

	ld a,(sine_position)
sine1_speed = $+1
	add -2
	ld (sine_position),a

	ld a,(sine_position2)
sine2_speed = $+1
	add -7
	ld (sine_position2),a

	ld a,$10
	ld ($6800),a

	pop bc
	djnz main_loop
	ret

wait_vbl_end:
	ld h,$68
.wait_vbl_end:
	bit 7,(hl)
	jr z,.wait_vbl_end
	ret

wait_vbl:
	ld h,$68
.wait_vbl:
	bit 7,(hl)
	jr nz,.wait_vbl
	ret

draw_template:
; Template for function that draws four character rows,
; i.e. 8 pixel rows

	;REPT 4

	xor a
	rlc b    ; 8t
	adc a    ; 4t Upper left
	rlc c    ; 8t
	adc a    ; 4t Upper right
	rlc b    ; 8t
	adc a    ; 4t Lower left
	rlc c    ; 8t
	adc a    ; 4t Lower right

	or (hl)  ; add color
	inc l
.offs1 = $+2-draw_template
	ld (ix+0),a ;ld (ix+.rep*draw_width),a

	inc ixh

	and $f
	or (hl)  ; add color
	inc l
.offs2 = $+2-draw_template
	ld (ix+0),a ;ld (ix+.rep*draw_width),a

	dec ixh

.rept_end:
.rept_len = $-draw_template
	;ENDR

	ld a,ixl   ; 8t
	add $80    ; 7t
	ld ixl,a   ; 8t

	ret
.end_len = $-.rept_end

draw_function_len = .rept_len*4+.end_len

original_colors:
.green	= (8+0)<<4
.yellow	= (8+1)<<4
.blue	= (8+2)<<4
.red	= (8+3)<<4
.buff	= (8+4)<<4
.cyan	= (8+5)<<4
.magenta	= (8+6)<<4
.orange	= (8+7)<<4

	db .red,.orange,.yellow,.buff,.buff,.cyan,.blue,.magenta
number_of_colors = $-original_colors

	SECTION reusebss
initialize:
	IF !RELEASE
	ld hl,screen_buffer
	ld de,screen_buffer+1
	ld (hl),'X'
	ld bc,$1ff
	ldir
	ENDIF

	; Generate draw function
	ld de,draw_four_char_rows

	ld b,4  ; rept
	xor a   ; .rep*draw_width
.each_rep:
	push bc

	ld hl,draw_template
	push de
	pop ix
	ld bc,draw_template.rept_len
	ldir
	ld (ix+draw_template.offs1),a
	ld (ix+draw_template.offs2),a

	add draw_width

	pop bc
	djnz .each_rep

	ld bc,draw_template.end_len
	ldir

	IF 0
	ld a,d
	cp >draw_four_char_rows_end
	jr nz,.wrong_function_length
	ld a,e
	cp <draw_four_char_rows_end
	jr z,.correct_function_length

.wrong_function_length:
	ld ($7000),a
	jr .wrong_function_length
.correct_function_length:
	ENDIF

	; Generate repeating colors
	ld hl,colors+color_offset*2
	ld d,h
	ld e,(color_offset-8)*2+1
.each_color_repetition:
	ld ix,original_colors
	ld c,number_of_colors
.each_original:
	ld a,(ix)
	inc ix
	ld b,8
.each_color:
	ld (hl),a
	inc l
	inc l
	ld (de),a
	inc e
	inc e
	djnz .each_color
	dec c
	jr nz,.each_original
	ld a,l
	cp color_offset*2
	jr nz,.each_color_repetition

	; Generate LDI
	ld hl,ldi_32
	ld b,32
.set_ldi:
	ld (hl),$ed
	inc hl
	ld (hl),$a0
	inc hl
	djnz .set_ldi
	ld (hl),$c9
	ret

	SECTION .bss,"uR"

	ALIGN 8
sine_table:
	ds $100

	ALIGN 8
colors:
	ds $100

	ALIGN 8
shifts:
	ds $20   ; 2 bytes per shift

ldi_32:
	ds 65  ; ldi=2 bytes + ret

draw_four_char_rows:
	ds draw_function_len
draw_four_char_rows_end:

	ALIGN 8
screen_buffer:
	; Screen back buffer
	ds $10*draw_width
