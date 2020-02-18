	GLOBAL roller_start

	INCLUDE vz.inc

clear_screen = 0

u1_value = $08

width_bytes = 32
source_lines = 8

roller_height = (source_addresses_end-source_addresses)/2

roller_start:
	call roller_init
	ldir

main_loop:
	IF RELEASE
	call wait_vbl
	ELSE
	;ld h,$68
	;ld (hl),$18
	;ld b,1
;.wait:
	call wait_vbl
	;djnz .wait
	;ld (hl),u1_value
	ENDIF


target_addr = $+1
	ld de,$7000-(roller_height-1)*32

	ex af,af'

	; Calculate how many rows to draw
	ld c,roller_height
rows_left = $+1
	ld a,64+roller_height
	cp roller_height
	jr c,.got_height
	ld a,roller_height
.got_height:

	ld (.save_sp),sp
	ld sp,source_addresses
.each_row:
	ex af,af'
	pop hl
offset = $+1
	ld a,0
	add l
	ld l,a

	ld bc,width_bytes
	ld a,d
	cp $70
	jr c,.outside_screen
	cp $78
	jr nc,.outside_screen
	ldir
	jp .not_before
.outside_screen:
	ex de,hl
	add hl,bc
	ex de,hl
.not_before:

	ex af,af'
	dec a
	jp nz,.each_row

.save_sp = $+1
	ld sp,0

	; Move down
	ld a,(rows_left)
	dec a
	ret z
	ld (rows_left),a

	ld hl,(target_addr)
	ld bc,$20
	add hl,bc
	ld (target_addr),hl

	; Update source image
	ld h,>image
	ld a,(offset)
	ld l,a            ; unpack new image row to HL
	add width_bytes
	ld (offset),a

	ld a,(rows_left)
	cp roller_height

	; Unpack new image row
	ld b,width_bytes
	jr c,.fill_with_empty_data
.unpack:
	exx
	call eliasd_get_next_byte
	exx
	ld (hl),a
	inc l
	djnz .unpack

	jp main_loop

.fill_with_empty_data:
	; Source image has ended, add some empty data
	ld a,$55
.fill_empty:
	ld (hl),a
	inc l
	djnz .fill_empty
	jp main_loop

wait_vbl:
	ld h,$68
.wait_for_vbl_end:
	bit 7,(hl)
	jr nz,.wait_for_vbl_end
.wait_for_vbl_start:
	bit 7,(hl)
	ret nz
	jr .wait_for_vbl_start

source_addresses:
	dw image+width_bytes*0
	INCLUDE offsets.s
source_addresses_end:

	INCLUDE ../ffcrunch/eliasd.s

	SECTION reusebss
roller_init:
	; Clear screen
	IF clear_screen
	ld de,$7700
	xor a
	ld b,$800/$100
.clear_outer:
	call wait_vbl
.clear:
	ld (de),a
	inc e
	jr nz,.clear
	dec d
	djnz .clear_outer
	ELSE
	call wait_vbl
	ENDIF

	;ld h,$68  ; still set after wait_vbl
	ld (hl),u1_value

	ld hl,roller_image_eliasd
	call eliasd_init
	exx

	ld hl,image
	ld de,image+1
	ld bc,width_bytes*source_lines-1
	ld (hl),0
	;ldir   This would overwrite this code! Let caller do it!

	ret

	SECTION .bss,"uR"
	ALIGN 8
image:
	ds width_bytes*source_lines
