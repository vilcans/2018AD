	INCLUDE vz.inc

boot_start:
	; Remove the green bar added when ROM scrolled everything up one line
	ld hl,$7200-33
	ld a,$80
.fill:
	ld (hl),a
	inc l
	jr nz,.fill

	; Load the first part
	jp loader_start

	;SECTION .bss,"uR"
