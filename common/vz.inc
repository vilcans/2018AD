
; Called by the ROM code for rst $38 interrupt handler
user_interrupt = $787d

; The memory-mapped latch register. Any address between $6800 and $6fff
;
; Write:
;   Bit 0 ($01): Speaker A
;   Bit 1 ($02): Cassette out (LSB), unused according to VZAsm
;   Bit 2 ($04): Cassette out (MSB)
;   Bit 3 ($08): VDC display mode:
;                    0 = text/lowres (Alphanumeric internal)
;                    1 = graphics/hires (Semigraphics 4)
;   Bit 4 ($10): VDC background color:
;                    0 = green,
;                    1 = buff (orange in text mode)
;   Bit 5 ($20): Speaker B
;
; Read:
;   Bit 6 ($40): Cassette data
;   Bit 7 ($80): Vblank

; Summary of VDC display mode and background color bits (bit 3 and 4):
;
; Value  Mode   Border   Background   Foreground
; --------------------------------------------------
;  $00   Text   Black    Dark green   Bright green
;  $10   Text   Black    Dark green   Orange
;  $08   Gfx    Green    Bright green Yellow, blue, red
;  $18   Gfx    White    White        Cyan, orange, magenta

u1 = $6800
screen_start = $7000

u1_copy_addr = $783B               ; System keeps a copy of U1 here

; From schema
;  
; Read: $6800-§6FFF 
;   D6 = CAS DATA IN
;   D0 - D5 = Keyboard data
;   Address lines A0 - A7 = keyboard scan lines
;   (i.e read from $6810 -> data from keyboard scanline 5 (D0-D5))

u1_addr = $6800        ; $6800-6FFF

U1_SPEAKER_1 = %00000001
U1_SPEAKER_2 = %00100000

U1_CAS_GAIN = %00000010            ; Not used
U1_CAS_DATA = %00000100

U1_VDG_MODE = %00001000            ; VDG A'/G
U1_VDG_BACKGROUND = %00010000      ; VDG CSS

vdg_ram_begin = $7000
vdg_ram_end = $77ff

rom0_addr = $0000                  ; ROM0 $0000-$1FFF
rom1_addr = $2000                  ; ROM0 $2000-$3FFF

ram0_begin = $7800
ram0_end = $8000
ram1_begin = $A000                 ; $8000+$800*4 - $B000
ram1_end = $B000

