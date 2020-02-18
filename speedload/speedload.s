
	GLOBAL speedload_block
	GLOBAL speedload_sync
	GLOBAL speedload_byte

	INCLUDE vz.inc

DEBUG=0

min_sync_len = 60
avg_bit_time = 26

;	INCLUDE vz.inc

	; bit overhead 4t
	; iteration 4+12+20  = 36t
	; short 9, long 20
	;
	; 11 bytes
	MACRO SPEEDLOAD_BIT_TIME
	xor a
.bit_time_0_loop
	inc a
	bit 6, (iy)
	jr nz, .bit_time_0_loop
.bit_time_1_loop
	inc a
	bit 6, (iy)
	jr z, .bit_time_1_loop
	ENDM

speedload_sync:
	ld iy, u1
	ld d, avg_bit_time

    IF DEBUG   
	ld bc, $7000
	ld c, d
	; !
	ld a, 33
	ld (bc), a
	ENDIF

;.wait_low
;	bit 6, (hl)
;	jr nz, .wait_low


.reset_count
	ld e, min_sync_len
speedload_sync_wait_start
.count
	SPEEDLOAD_BIT_TIME
	cp d

    IF DEBUG   
	ld c, a
	ld a, 42
	ld (bc), a
	ENDIF

	jr nc, speedload_sync.reset_count
	dec e
	jr nz, .count
speedload_sync_wait_end
.wait_sync_end
	SPEEDLOAD_BIT_TIME
	cp d
	jr c, .wait_sync_end
	ret

	; byte overhead (including call) = 17 + 8+8 + 10 = 43t
	; bit overhead = 8+17+8+12 = 45t
	; total bit time 67t + 37t / count
speedload_byte:
	; shift until carry
	ld e, %00000001
	; start looking for high bit
.next_bit
	SPEEDLOAD_BIT_TIME
	cp d
	ccf
	rl e
	jr nc, .next_bit
	ret

	; worst case is 85t oh for one byte
speedload_block:
	call speedload_sync
	call speedload_byte
	ld l, e
;	ld a, e
;	call console_print_byte
;	ld d, avg_bit_time
	
	call speedload_byte
	ld h, e
;	ld a, e
;	call console_print_byte
;	ld d, avg_bit_time

;	ld hl, $7800
	push hl

	call speedload_byte
	ld c, e
	call speedload_byte
	ld b, e
.next_byte_in_block
	call speedload_byte
	ld (hl), e
	inc hl
	dec bc
	ld a,b
	or c
	jr nz,.next_byte_in_block

	pop hl
	ret
