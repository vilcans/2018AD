	GLOBAL initialize

	INCLUDE vz.inc

initialize:
	di

	; Overwrite initialize code with stack
	ld sp,.stack_end

	blk $0f,0   ; Make room for some stack
	call PART_START   ; Set by linker script
.stack_end:

	; A single part ends with a ret, so we need to do something.
	xor a
	ld (u1),a
	ld hl,$71ff
.freeze:
	inc (hl)
	jr .freeze
