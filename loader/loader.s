	INCLUDE vz.inc

	GLOBAL loader_start

loader_start:

loop:
	call speedload_block
	ld de,loop  ; return to loop
	push de
	jp (hl)
