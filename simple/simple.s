	GLOBAL simple_start

	INCLUDE vz.inc

simple_start:
	di
.lp:
	ld hl,$7000
	inc (hl)
	jr .lp

	;SECTION .bss,"uR"
