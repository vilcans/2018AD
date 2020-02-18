	GLOBAL kefrens_start

	INCLUDE vz.inc
	INCLUDE timing.inc
	INCLUDE sleep.inc
	INCLUDE printing.inc
	INCLUDE interrupts.inc

total_time = 16*50

trigger_value = $00
main_value = $08

background_color = %10101010
clear_color = %00000000  ; color that will scroll in from below

;x_max = (sine1_offset + sine1_amplitude + sine2_offset + sine2_amplitude) * .5 = 120
;     => (sine1_offset * 2 + sine2_offset * 2) = 240
;     => (sine1_offset + sine2_offset) = 120
;x_min = (sine1_offset - sine1_amplitude + sine2_offset - sine2_amplitude) = 0

sine1_amplitude = 80
sine1_offset = 80

sine2_amplitude = 40
sine2_offset = 40

sine1_speed = -2
sine2_speed = 1

time	MACRO
cycles_left SET cycles_left-(\1)
	IF cycles_left<0
	FAIL Out of cycles
	ENDIF
	ENDM

kefrens_start:
	ld hl,sine1_table
	ld bc,(sine1_offset<<8)|sine1_amplitude
	call generate_sine_with_offset
	ld hl,sine2_table
	ld bc,(sine2_offset<<8)|sine2_amplitude
	call generate_sine_with_offset

	ld hl,shifted_graphics_original
	ld de,shifted_graphics
	ld bc,shifted_graphics_original_end-shifted_graphics_original
	ldir

	call wait_vbl
	ld (hl),main_value

	; Set up interrupt
	set_interrupt interrupt,save_interrupt
	ei

	ld a,3
	ld hl,$7800
	ld de,number_of_scanlines
.transition_in:
	ld (de),a
	halt
	inc a
	ld (de),a
	halt
	inc a
	ld (de),a
	halt
	inc a

	ld bc,-$20
	add hl,bc
	ld (clear_address),hl

	cp 189
	jr c,.transition_in

	halt
	ld hl,$7020   ; second line that will be visible unless cleared
	ld (clear_address),hl

	ld bc,total_time-189*2
.wait:
	halt
	dec bc
	ld a,b
	or c
	jr nz,.wait

	ld a,188
.transition_out:
	ld (number_of_scanlines),a
	halt
	dec a
	jr nz,.transition_out

	; Clear the final row
	ld hl,$7000
	ld (hl),clear_color
	ld de,$7001
	ld bc,$1f
	ldir

	; Restore interrupt
	di
	restore_interrupt save_interrupt
	ret

interrupt:
	ld h,$68

	ld a,main_value
	ld (hl),main_value

cycles_left SET $1985*4+10+7+7+(7+4+13)*$20-5

	ld hl,$7000   ; 10t
	ld a,background_color
	ld b,$20
	time 10+7+7
.fill:
	ld (hl),a
	inc l
	djnz .fill
	time (7+4+13)*$20-5

	ld bc,($20<<8)|clear_color
	time 10
clear_address = $+1
	ld hl,0
	time 10
.clear:
	ld (hl),c
	inc l
	djnz .clear
	time (7+4+13)*$20-5

sleep_time = $+1
	ld bc,cycles_left/4
	wait_nops

	ld h,$70
	exx

sine1_pos = $+1
	ld de,sine1_table
sine2_pos = $+1
	ld hl,sine2_table
	ld ix,(main_value<<8)(trigger_value)

	ld (.save_sp),sp
number_of_scanlines = $+1
	ld b,3
.loop:

cycles_left SET 228

	ld a,(de)    ; sine1 value
	inc e
	inc e
	time 7+4+4
	add (hl)     ; sine2 value
	inc l
	time 7+4

	exx
	time 4

	rra      ; Divide sine value
	time 4

	ld l,a
	time 4

	srl l  ; 8t
	srl l  ; 8t
	time 8+8

	and 3    ; shift within byte
	add a   ; shift within byte * 2
	add a   ; shift within byte * 4
	add a   ; shift within byte * 8
	time 7+4+4+4

	ld (.set_sp),a
	time 13

.set_sp = $+1
	ld sp,shifted_graphics
	time 10

	; Byte 0 - with mask
	pop bc      ; 10t  C=mask, B=bitmap
	ld a,c      ; 4t
	and (hl)    ; 7t
	or b        ; 4t
	ld (hl),a   ; 7t
	inc l       ; 4t
	time 10+4+7+4+7+4

	; Byte 1 - without mask
	pop bc      ; 10t  C=----, B=bitmap
	ld (hl),b   ; 7t
	inc l       ; 4t
	time 10+7+4

	ld ($6800),ix   ; writes IXL, then IXH
	time 20

	; Byte 2 - with mask
	pop bc      ; 10t  C=mask, B=bitmap
	ld a,c      ; 4t
	and (hl)    ; 7t
	or b        ; 4t
	ld (hl),a   ; 7t
	time 10+4+7+4+7

	exx
	time 4

	; Finish up
	time 13    ; djnz

	IF cycles_left=6
	;sleep_6
	ld sp,hl  ; 6t
	ELSE
	FAIL Wrong number of cycles
	ENDIF

	djnz .loop   ; 13t

.save_sp = $+1
	ld sp,0

	ld a,(sine1_pos)
	add sine1_speed
	ld (sine1_pos),a

	ld a,(sine2_pos)
	add sine2_speed
	ld (sine2_pos),a

	IF !RELEASE
	tweak_timing sleep_time,$71fc
	ENDIF

	end_interrupt

wait_vbl:
	ld h,$68
.wait_for_vbl_end:
	bit 7,(hl)
	jr nz,.wait_for_vbl_end
.wait_for_vbl_start:
	bit 7,(hl)
	ret nz
	jr .wait_for_vbl_start

shifted_graphics_original:
;         R B R Y Y R B R --------
pixels = %111011010111101100000000
mask =   %111111111111111100000000

.to_c = 0   ; will be put into C by POP BC

	db (mask>>16)^$ff,pixels>>16,.to_c,(pixels>> 8)&$ff,((mask>>0)&$ff)^$ff,(pixels>>0)&$ff,0,0
	db (mask>>18)^$ff,pixels>>18,.to_c,(pixels>>10)&$ff,((mask>>2)&$ff)^$ff,(pixels>>2)&$ff,0,0
	db (mask>>20)^$ff,pixels>>20,.to_c,(pixels>>12)&$ff,((mask>>4)&$ff)^$ff,(pixels>>4)&$ff,0,0
	db (mask>>22)^$ff,pixels>>22,.to_c,(pixels>>14)&$ff,((mask>>6)&$ff)^$ff,(pixels>>6)&$ff,0,0
shifted_graphics_original_end:

	SECTION .bss,"uR"
	ALIGN 8
sine1_table:
	ds $100
sine2_table:
	ds $100

shifted_graphics:
	ds 8*4

save_interrupt:
	ds 3
