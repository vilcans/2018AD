	GLOBAL print_message_init
	GLOBAL print_message
	GLOBAL print_cursor_init
	GLOBAL print_cursor_init_custom
	GLOBAL print_cursor

	INCLUDE vz.inc

; hl = ptr to message
; de = screen start position
print_message_init:
	ld (message_ptr),hl
	ld (screen_ptr),de
	xor a
	ld ($6800),a
	ret

; prints a message one letter at a time
; message is terminated at 0
print_message:
screen_ptr=$+1
	ld de,$7000
message_ptr=$+1
	ld hl,0
.loop:
	ld a,(hl)
	or a
	ret z
	or %01000000
	ld (de),a
	inc hl
	inc de
	cp ' '+%01000000
	jp z,.loop

	ld (message_ptr),hl
	ld (screen_ptr),de
	ld a,$ff
	; z flag is not set if we get here
	ret

; bc = pointer to custom cursor
print_cursor_init_custom:
	ld (cursor_ptr),bc
	ld (cursor_reset_ptr),bc
	ret

print_cursor_init:
	ld bc,cursor
	ld (cursor_ptr),bc
	ld (cursor_reset_ptr),bc
	ret

print_cursor:
	; put a * at the next char pos
	ld hl,(message_ptr)
	ld de,(screen_ptr)

	exx

	ld b,4
.char_loop:
	exx

cursor_ptr=$+1
	ld bc,cursor
.loop_cursor:
	ld a,(hl)
	or a
	jp z,.done
	cp ' '
	jp z,.skip_space
	ld a,(bc)
	or a
	jp z,.reset_cursor
	or %01000000
	ld (de),a
	inc bc
	ld (cursor_ptr),bc
	inc hl
	inc de
	jp .done

.skip_space:
	inc hl
	inc de
	jp .loop_cursor

.reset_cursor:
cursor_reset_ptr=$+1
	ld bc,0
	ld (cursor_ptr),bc

.done:
	exx
	djnz .char_loop

	ld a,$ff
	or a ; clear z flag
	ret

cursor:
	defb '#*-.' ; this can be any length
	defb 0

;message:
	;     12345678901234567890123456789012
;	defb '                                '
;	defb 'YOUR PRIVACY IS IMPORTANT TO US '
;	defb '    AND WE ARE COMMITTED TO     ' 
;	defb '         PROTECTING YOUR        '
;	defb '       PERSONAL INFORMATION     '
;	defb '                                '
;	defb ' DUE TO THE GDPR WE ARE UPDATING'
;	defb '       OUR PRIVACY POLICY       '
;	defb '                                '
;	defb '   BY WATCHING THIS DEMO YOU    '
;	defb '  CONSENT TO THE TERMS OF THIS  '
;	defb '         PRIVACY POLICY         '
;	defb '                                '
;	defb ' IF YOU WISH TO OPT OUT YOU CAN '
;	defb '     PRESS STOP ON TAPE NOW     '
;	defb '                                '

;	defb 0

