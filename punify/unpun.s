
; a0 = src
; a1 = dst
; destroys a0,a1,a2,a3,d0
unpun_mem:
    ; save destination
    move.l a1,a2

.unpun_loop:
    move.b (a0)+,d0
    ; bit 7 set, copy from already unpacked data
    bmi.s .unpun_block
    ; 0 end of data marker
    beq.s .done
    ; bit 6 set
    btst #6,d0
    beq.s .unpun_simple ; < 64 byte block
    and.b #63,d0 ; hi byte
    lsl.w #8,d0
    move.b (a0)+,d0 ; lo byte
    subq.w #1,d0
.unpun_multi:
    move.b (a0)+,(a1)+
    dbf d0,.unpun_multi
    bra.s .unpun_loop
.unpun_simple:
    and.w #63,d0
    subq.w #1,d0
.unpun_simple_loop:
    move.b (a0)+,(a1)+
    dbf d0,.unpun_simple_loop
    bra.s .unpun_loop

; bit 7 is set
; copy from already unpacked data
.unpun_block
    move.l #0,d1
    move.b (a0)+,d1
    lsl.w #8,d1
    move.b (a0)+,d1
    move.l a2,a3
    add.l d1,a3
    and.w #127,d0
    subq.w #1,d0
.unpun_block_loop:
    move.b (a3)+,(a1)+
    dbf d0,.unpun_block_loop
    bra.s .unpun_loop
    
.done:
    rts