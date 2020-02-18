
    GLOBAL video_start

	INCLUDE vz.inc

DEBUG=1

min_sync_count=20
max_sync_count=30
min_sync_len=30

video_chartable_len = video_chartable_end - video_chartable
video_screen_buffer = video_bss + video_chartable_len

	MACRO VIDEO_BIT_TIME
	ld l, 0
.bit_time_loop
	inc l
	ld a, (iy)
    cp c
	jr nz, .bit_time_loop
    ld c, a
	ENDM

video_start:
    ; text mode
    xor a
	ld (u1), a

    di

    ld hl, $7000
.loop
    ld (hl), a
    inc hl
    inc a
    jr nz, .loop
    ; wait for start of frame
    ; load frame
    ; 22050 / 4 -> 5ktecken 

    ld hl, video_chartable
    ld de, video_bss
    ld bc, video_chartable_len
    ldir

.next_frame
    call video_vsync
    ld h, >video_bss
    ld b, 0
    ld de, video_screen_buffer
    REPT 2
.next_byte
    VIDEO_BIT_TIME
    ld a, (hl)
    ld (de), a
    inc de
    djnz .next_byte
    ENDR


.waitnovbl
    ld a, (u1)
    and %10000000
    jp nz, .waitnovbl
.waitvbl
    ld a, (u1)
    and %10000000
    jp z, .waitvbl

    ld hl, video_screen_buffer
    ld de, $7000
    ld bc, 512
    ldir
    
    jr .next_frame


video_vsync:
	ld iy, u1
	ld de, min_sync_count*256+max_sync_count

    IF DEBUG   
    ld h, $70
	ld l, d
	ld (hl), 33
    ENDIF

.reset_count
	ld bc, min_sync_len*256
video_vsync_wait_start
.count
	VIDEO_BIT_TIME

    IF DEBUG
	ld (hl), 42
    ENDIF

    ld a, l
	cp d
	jr nc, video_vsync.reset_count
    cp e
	jr c, video_vsync.reset_count
    
	djnz .count
video_vsync_wait_end
.wait_sync_end
	VIDEO_BIT_TIME
    ld a, l
	cp e
	jr nc, .wait_sync_end
	ret


video_chartable:
    db "    ..,.,,----++;+xxxx==*=****%%M%$$&$&&B&BB#B##@#@@@@"
    db 143,143,143,143
video_chartable_end

	SECTION .bss,"uR"
	align 8
video_bss:
