	GLOBAL rot8_start

	INCLUDE vz.inc

slowdown = 0

draw_width = $20

scale_min = 6
scale_max = $28
scale_sine_amplitude = (scale_max-scale_min)

; "Beat" is 2 bars in the music
beat_length = 172-2    ; -2 because new_beat takes two frames
beats_per_frame = 382   ; 16 bicimals

number_of_ldis = 64

rot8_start:
	call initialize

	; Rotation sine table
	ld hl,sine_table
	ld c,$7f
	call generate_sine

	call new_beat

.main_loop:

.beat_count = $+1
	ld hl,0
	ld bc,beats_per_frame
	add hl,bc
	ld (.beat_count),hl
	call c,new_beat

	; Update scale
scale_pos = $+1
	ld a,0
	ld l,a
	inc a
	ld (scale_pos),a
	ld h,>scale_table
	ld l,a
	ld a,(hl)
	ld (scale),a

	; Move
	ld a,(shift_u)
	add -4
	ld (shift_u),a
	ld a,(shift_v)
	add 1
	ld (shift_v),a


rotation_angle = $+1
	ld a,-64
	add 3
	ld (rotation_angle),a

	; Calculate

	; add_v_x = -add_u_y = sin
	; add_u_x =  add_v_y = cos
	; top_left_u = -16cos + 8sin = B
	; top_left_v = -16sin - 8cos = C
	; mid_left_u = -16cos
	; mid_left_v = -16sin

	ld d,>sine_table

	ld e,a
	ld a,(de)   ; sin
	call multiply_by_scale
	ld (add_v_x),a
	neg         ; -sin
	ld (add_u_y),a

	add a
	add a
	add a   ; -8sin
	ld b,a  ; B = -8sin
	add a   ; -16sin
	ld (mid_left_v),a
	ld c,a  ; C = -16sin

	ld a,e
	add $40
	ld e,a
	ld a,(de)   ; cos
	call multiply_by_scale
	ld (add_u_x),a
	ld (add_v_y),a

	add a
	add a
	add a  ; 8cos
	neg    ; -8cos
	add c  ; -8cos - 16sin = top_left_v
	;ld c,a
	ld (top_left_v),a

	sub c  ; -8cos
	add a  ; -16cos
	ld (mid_left_u),a
	sub b  ; -16cos + 8sin
	;ld b,a
	ld (top_left_u),a

	; Render

	; 1. Render bottom part to offscreen buffer

	ld hl,offscreen  ; render bottom part to offscreen
	ld d,>texture
	exx                ; Prim set
	ld d,$f0   ; mask

mid_left_v = $+1
mid_left_u = $+2
	ld bc,0   ; texture uv in 4.4 format

add_v_x = $+1   ; L
add_u_x = $+2   ; H
	ld hl,0

	call render_half
	exx                 ; Sec set

	; 2. Wait for vblank

	call wait_vbl
	ld (hl),0

	; 3. Render top part directly to screen

	ld h,$70   ; screen address
	exx                 ; Prim set
top_left_v = $+1
top_left_u = $+2
	ld bc,0   ; texture uv in 4.4 format
	call render_half

	; 4. Copy to screen
	ld hl,offscreen
	ld de,$7100
	ld bc,draw_width*8
	call fast_ldir

	;xor a
	;ld ($71ff),a
	;ld ($71ff-$20),a
	;ld ($71ff-$20*2),a
	;ld ($71ff-$20*3),a
	;ld ($71ff-$20*4),a
	;ld ($71ff-$20*5),a
	;ld ($71ff-$20*6),a

	jp .main_loop

render_half:
; HL' = screen
; DE' = texture
; BC = uv coords
; HL = du, dv
; D = $f0 (mask)
; E = temp texture offset

	ld a,b
shift_u = $+1
	add 8<<4
	ld b,a
	ld a,c
shift_v = $+1
	add 8<<4
	ld c,a

repeats = 4
.each_row:
	push bc      ; Save uv coords at start of row
	exx          ; Sec set
	ld b,draw_width/repeats
.each_column:
	REPT repeats

	exx          ; Prim set

	ld a,b
	add h
	ld b,a
	and d
	rra
	rra
	rra
	rra
	ld e,a

	ld a,c
	add l
	ld c,a

	and d
	or e

	exx           ; Sec set
	ld e,a
	ld a,(de)     ; 7t  texel
	ld (hl),a     ; 7t
	inc l
	ENDR

	djnz .each_column

	exx           ; Prim set

	pop bc   ; Restore uv coords at start of row

	ld a,b
add_u_y = $+1
	add 0<<5
	ld b,a

	ld a,c
add_v_y = $+1
	add 1<<5
	ld c,a

	exx

	REPT $20-draw_width
	inc l
	ENDR

	ld a,l
	or a
	exx
	jp nz,.each_row

	ret

multiply_by_scale:
; Multiply A by scale
	push bc
	push de

	or a
	jr z,.ret

scale = $+1
	ld c,$40

	jp p,.positive

	neg
	call A_Times_C
	ld a,c
	neg
.ret:
	pop de
	pop bc
	ret
.positive:
	call A_Times_C
	ld a,c
	jp .ret

; Based on D_Times_C from http://z80-heaven.wikidot.com/math#toc6
;Returns a 16-bit result
;
;===============================================================
A_Times_C:
;Inputs:
;     D and C are factors
;Outputs:
;     A is the product (lower 8 bits)
;     B is 0
;     C is the overflow (upper 8 bits)
;     DE, HL are not changed

     ld d,a
     xor a         ;This is an optimised way to set A to zero. 4 cycles, 1 byte.
     ld b,8        ;Number of bits in E, so number of times we will cycle through
Loop:
     add a,a       ;We double A, so we shift it left. Overflow goes into the c flag.
     rl c          ;Rotate overflow in and get the next bit of C in the c flag
     jr nc,$+6     ;If it is 0, we don't need to add anything to A
       add a,d     ;Since it was 1, we do A+1*D
       jr nc,$+3   ;Check if there was overflow
         inc c     ;If there was overflow, we need to increment E
     djnz Loop     ;Decrements B, if it isn't zero yet, jump back to Loop:
     ret

wait_vbl:
	ld h,$68
	;ld (hl),0

	IF slowdown>1
	ld b,slowdown+1
.multivbl:
	ENDIF
.wait_vbl_end:
	bit 7,(hl)
	jr z,.wait_vbl_end
.wait_vbl:
	bit 7,(hl)
	jr nz,.wait_vbl
	IF slowdown>1
	djnz .multivbl
	ENDIF

	;ld (hl),$10
	ret

new_beat:
	call wait_vbl

.script_pos = $+1
	ld hl,script

	; Compressed texture
	ld a,(hl)
	inc hl
	or a
	jr z,.finished
	ld e,a
	ld d,(hl)
	inc hl
	push hl

	ex de,hl
	ld de,texture
	ld bc,16*16
	call unary_decompress

	pop hl
	ld (.script_pos),hl

	xor a
	ld (rotation_angle),a
	ld (scale_pos),a

	jp wait_vbl

.finished:
	pop af  ; remove return address
	ret     ; back to loader

script:
	; Textures
	dw texture0_copy
	dw texture1_copy
	dw texture2_copy
	dw texture3_copy
	dw texture4_copy
	dw texture5_copy
	dw texture6_copy
	dw texture7_copy
	dw texture8_copy
	dw 0

ldi_suffix:
	jp pe,fast_ldir
	ret
ldi_suffix_length = $-ldi_suffix

	INCLUDE ../ffcrunch/unary.s

	SECTION reusebss

initialize:
	ld hl,texture_originals
	ld de,texture_copies
	ld bc,texture_originals_end-texture_originals
	ldir

	ld hl,fast_ldir
	ld b,number_of_ldis
.set_ldi:
	; Set up a bunch of LDI
	ld (hl),$ed
	inc hl
	ld (hl),$a0
	inc hl
	djnz .set_ldi
	ex de,hl
	ld hl,ldi_suffix
	ld c,ldi_suffix_length
	ldir

	; Make scale table:
	; first a quarter of a sine,
	; then constant, then ending quarter of a sine

	ld hl,scale_table
	ld bc,(scale_min<<8)|(scale_sine_amplitude)
	call generate_sine_with_offset

	ld hl,scale_table+$40
	ld a,scale_max
	ld b,beat_length-$40-$40
.fill:
	ld (hl),a
	inc l
	djnz .fill

	ld de,scale_table+$40
	ld b,$40
.ending:
	dec e
	ld a,(de)
	ld (hl),a
	inc l
	djnz .ending
	ld a,scale_min
.zero:
	ld (hl),a
	inc l
	jr nz,.zero
	ret

texture_originals:
texture0_original: INCBIN texture_0.unary
texture1_original: INCBIN texture_1.unary
texture2_original: INCBIN texture_2.unary
texture3_original: INCBIN texture_3.unary
texture4_original: INCBIN texture_4.unary
texture5_original: INCBIN texture_F.unary
texture6_original: INCBIN texture_I.unary
texture7_original: INCBIN texture_V.unary
texture8_original: INCBIN texture_E.unary
texture_originals_end:

	SECTION .bss,"uR"

	ALIGN 8
texture:	ds 16*16

	ALIGN 8
sine_table:
	ds $100

	ALIGN 8
offscreen:
; Backbuffer for the bottom part of the screen.
; We render the top part directly to the screen in vblank.
	ds $100
offscreen_end:

	SECTION vram,"uR"

	ALIGN 8
scale_table:
	ds $100
fast_ldir:
	; ldi, ldi, ldi + ldi_suffix
	ds number_of_ldis*2+ldi_suffix_length

texture_copies:
texture0_copy: ds texture1_original-texture0_original
texture1_copy: ds texture2_original-texture1_original
texture2_copy: ds texture3_original-texture2_original
texture3_copy: ds texture4_original-texture3_original
texture4_copy: ds texture5_original-texture4_original
texture5_copy: ds texture6_original-texture5_original
texture6_copy: ds texture7_original-texture6_original
texture7_copy: ds texture8_original-texture7_original
texture8_copy: ds texture_originals_end-texture8_original

	IF $-texture_copies!=texture_originals_end-texture_originals
	FAIL Texture copies seem to be inconsistant with originals
	ENDIF
