	GLOBAL transout_start

transout_start:
	ld a, $c0
	call clear_text

	ld a, $cf
	ld (peel_layer.fill_char), a

	ld c, 7
.next_frame

	call peel_layer

	dec c
	jp p, .next_frame
	call clear_graphics

	ret

	INCLUDE ../trans/trans.s
