; Includes all compression routines.
; To avoid this, you can also just include the one you need.

	GLOBAL unary_decompress
	GLOBAL unary_init
	GLOBAL unary_get_next_byte

	INCLUDE unary.s

	GLOBAL eliasd_decompress
	GLOBAL eliasd_init
	GLOBAL eliasd_get_next_byte

	INCLUDE eliasd.s
