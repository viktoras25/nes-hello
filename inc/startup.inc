.segment "STARTUP"

.PROC RESET
    SEI         ; Disable IRQs
    CLD         ; Disable decimal mode

    ; Disable APU frame IRQ
    LDX #%01000000
    STX APU_FRAME_COUNTER

    ; Disable DMC IRQs
    LDX #$00
    STX APU_DMC_FREQ

    ; Set up stack register
    LDX #$FF
    TXS

    ; Disable video
    LDX #$00
    STX PPU_CTRL    ; Disable NMI/VBLANK
    STX PPU_MASK    ; Disable rendering

    JSR WAIT_VBLANK
    
    ; Manual JSR / RTS
    ; When we clear the memory, we also clear the stack
    JMP CLEAR_MEM
    MEM_CLEARED:

    JSR INIT

    ; Enable interrupts
    CLI

    ; Enable video again
    LDX #%10010000
    STX PPU_CTRL
    LDX #%00011110
    STX PPU_MASK

    JMP MAIN
.ENDPROC

.PROC WAIT_VBLANK
    BIT PPU_STATUS
    BPL WAIT_VBLANK
    RTS
.ENDPROC

.PROC CLEAR_MEM
    ; Reset RAM
    LDX #$00

    LOOP:
        LDA #$00
        STA $0000, X
        STA $0100, X
        STA $0300, X
        STA $0400, X
        STA $0500, X
        STA $0600, X
        STA $0700, X
        ; Reset sprite memory
        LDA #$FF
        STA SPRITE_MEM, X

        INX
        BNE LOOP

    :
        BIT PPU_STATUS
        BPL :-

    ; Set sprite memory location ($0200) by setting most significat byte
    LDA #$02
    STA OAM_DMA
    NOP ; Let PPU do it's job

    JMP RESET::MEM_CLEARED
.ENDPROC
