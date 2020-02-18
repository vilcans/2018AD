; Utilities for setting up interrupts
;
; Typical usage:
;
; Start interrupts:
;	save_interrupt interrupt,save_interrupt
;	ei
;
; Restore memory at user_interrupt ($787d) before returning to loader:
;
;	di
;	restore_interrupt save_interrupt
;
; Define interrupt routine:
; interrupt:
;	...
;	end_interrupt
;	; no ret needed
;
; In BSS:
; save_interrupt:
;	ds 3


set_interrupt MACRO
; \1 = interrupt routine
; \2 = Address of 3 bytes to save the old interrupt at

	ld hl,user_interrupt
	push hl
	ld de,\2
	ld bc,3
	ldir
	pop hl
	ld (hl),$c3   ; JP
	inc hl
	ld (hl),<(\1)
	inc hl
	ld (hl),>(\1)

	ENDM

restore_interrupt MACRO
; Restore interrupt saved in \1 (3 bytes)

	ld hl,\1
	ld de,user_interrupt
	ld bc,3
	ldir
	ENDM

; Return from an interrupt.
; The interrupt code needs to be at user_interrupt and end with this macro.
end_interrupt MACRO
	; Remove return address from call in ROM so we can
	; return directly to non-interrupt code
	pop af

	; These were pushed by the ROM code
	pop hl
	pop de
	pop bc
	pop af

	ei
	reti
	ENDM
