; The very first code that is called by BASIC.
; This code is stored in a REM statement which means it must
; be relocatable and contain no null bytes.

; The data will be decoded and put at this address, then jumped to.
target_address = $7201  ; in VRAM

base_address:
	di
	ld sp,$7fff

	; Find which address this code is running at
	ld hl,(30862)   ; USR address from Basic, points to base_address

	ld bc,decode-base_address
	add hl,bc
	jp (hl)

data:
	INCBIN unzeroed.bin
data_end:
data_size = data_end-data

	IF <data_size==0
	; Add dummy byte to avoid a zero in ld bc,-(decode-data)
	db $ff
	ENDIF

; Decode the escaped data to target_address.
; This is located after end of data as target data may overwrite data
; and we don't want this code to be overwritten.

decode:
	ld bc,-(decode-data)
	add hl,bc               ; HL = data

	ld de,target_address
	push de         ; for jumping to target_address with a ret

	ld c,(hl)
	inc hl
	ld a,(hl)     ; escape
	ld ixh,a
	inc hl

; Use the trick at http://map.grauw.nl/articles/fast_loops.php#varlength
.lsb = <data_size
.msb = (>(data_size-1))+1

	ld ixl,.msb

	IF .lsb==0
	; ld b,.lsb would contain a null byte, so do this instead
	xor a
	ld b,a
	ELSE
	ld b,.lsb
	ENDIF

.decode_loop:
	ld a,(hl)
	inc hl
	xor c
	cp ixh
	jr nz,.after_escape
	ld a,(hl)
	inc hl
.after_escape:
	ld (de),a
	inc de
	djnz .decode_loop
	dec ixl
	jr nz,.decode_loop

	ret   ; jump to target_address
