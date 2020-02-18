	GLOBAL masked_start

; Usage:
;
;start_y = 63
;end_y = 4
;image_width = 72/4
;image_height = (masked_image_end-masked_image)/image_width
;mask_left = 0  ; or 1
;
;	jp masked_start
;
;	INCLUDE ../masked/masked.s
;
;masked_image:
;	INCBIN image.bin
;masked_image_end:
;mask_data:
;	INCLUDE maskdat.s

masked_start:
	call create_copy_code

	call wait_vbl
	ld (hl),$08

	IF 0
	ld hl,$7000
	ld b,8
	xor a
.clear:
	ld (hl),a
	inc l
	jr nz,.clear
	inc h
	djnz .clear
	ENDIF

main_loop:
	ld hl,mask_data
	ld a,(y_pos)
	add a  ; 2 bytes per entry
	add <mask_data
	ld l,a
	jr nc,.noc_mask
	inc h
.noc_mask:

	push hl
	pop ix


y_pos = $+1
	ld b,start_y

	xor a
	ld e,b
	REPT 5  ; times screen width
	rl e
	rla
	ENDR
	add $70
	ld d,a

	; draw_height = min(image_height, 64-y_pos)
	ld a,64   ; screen height
	sub b
	jr c,.no_draw
	jr z,.no_draw
	cp image_height
	jr c,.draw_min
	ld a,image_height
.draw_min:
	ld iyh,a    ; row counter

	;ld hl,$7000
	;ld (hl),a

	call wait_vbl

	ld hl,masked_image

.each_row:
; HL = source image
; DE = target image
; IX = mask data
; IYH = loop counter
; IYL = save width
; B = temp
; C = temp

	ld c,(ix)   ; c=left edge
	inc ix

	ld a,c
	ld iyl,a    ; save width for later

	IF mask_left

	; Mask on left - copy first bytes
	ld a,31
	sub c
	add a
	ld (copy_offset_left),a
	push bc
copy_offset_left = $+1
	call copy
	pop bc

	; Skip rest
	ld a,image_width
	sub c
	add l
	ld l,a
	jr nc,.left_mask_noc
	inc h
.left_mask_noc:
	ELSE

	; Mask is at right. Skip to left edge
	add e
	ld e,a

	ld a,c
	sub 32-image_width
	add l
	ld l,a
	jr nc,.noc_source
	inc h
.noc_source:

	ENDIF

	ld a,(de)   ; target byte

	ld c,(ix)   ; C = mask
	inc ix
	and c       ; A = masked target byte
	ld b,a      ; B = masked target byte

	ld a,c
	cpl
	and (hl)    ; A = masked source byte
	or b
	ld (de),a

	inc hl
	inc e

	IF mask_left
	ld a,e
	add 31
	jr nc,.left_screen_noc
	inc d
.left_screen_noc
	and $e0
	ld e,a

	ELSE

	ld a,iyl
	add a
	ld (copy_offset),a
copy_offset = $+1
	call copy

	ENDIF

.no_copy:

	dec iyh
	jp nz,.each_row

.no_draw:
	ld a,(y_pos)
	dec a
	cp end_y
	ld (y_pos),a
	jp nz,main_loop

	ret

wait_vbl:
	ld h,$68
.wait_exit:
	ld a,(hl)
	add a
	jr nc,.wait_exit

	;ld (hl),$18

.wait_enter:
	ld a,(hl)
	add a
	jr c,.wait_enter

	;ld (hl),$08
	ret

create_copy_code:
	ld hl,copy
	ld b,31     ; minus one because mask is one byte
.create_ldi:
	ld (hl),$ed
	inc hl
	ld (hl),$a0
	inc hl
	djnz .create_ldi
	ld (hl),$c9
	ret

	SECTION .bss,"uR"
	ALIGN 8
copy:
	ds 32*2   ; LDI
	ds 1  ; ret
