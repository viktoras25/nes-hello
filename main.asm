.include "inc/init.inc"

.PROC INIT
    LDA #$00
    STA bg_color
    STA frame_count

    LDA #$44
    STA pos_x

    LDA #$6C
    STA pos_y

    LDA #$01
    STA mov_x
    STA mov_y

    JSR LOAD_PALETTES

    RTS
.ENDPROC

.PROC MAIN
    JMP FOREVER
.ENDPROC

FOREVER:
    JMP FOREVER

.PROC LOAD_PALETTES
    ; Write $3F00 into PPU_ADDR
    LDA #$3F
    STA PPU_ADDR
    LDA #$00
    STA PPU_ADDR

    LDX #$00
    _LOOP:
        ; Write palette data
        LDA PALETTE_DATA, X
        STA PPU_DATA
        INX
        CPX #$20
        BNE _LOOP

    RTS
.ENDPROC

.PROC PRINT_HELLO
    COPY16 _TEXT, text_buf
    JSR PUT_TEXT
    RTS

    _TEXT: .byte CHR_H, CHR_E, CHR_L, CHR_L, CHR_O, CHR_EXCL, CHR_END
.ENDPROC

.PROC PUT_TEXT
    LDY #$00
    LDX #$00

    LDA pos_x
    STA current_letter_x

    _LOOP:
        ; Y coord
        LDA pos_y
        STA SPRITE_MEM, X
        INX

        ; Sprite #
        LDA (text_buf), Y
        STA SPRITE_MEM, X
        INX

        LDA #$00
        STA SPRITE_MEM, X
        INX

        ; X coord
        LDA current_letter_x
        STA SPRITE_MEM, X
        INX

        ; Move current letter position to the right
        INC8 current_letter_x

        INY

        LDA (text_buf), Y
        CMP #$FF
        BNE _LOOP
    RTS
.ENDPROC

.PROC UPDATE_BG_COLOR
    ; Choose on of 48 ($31) colors
    INC bg_color
    LDA bg_color
    CMP #$31
    BNE _SET_COLOR

    ; Reset back to first color
    LDA #$00
    STA bg_color

    _SET_COLOR:
    LDA #$3F
    STA PPU_ADDR
    LDA #$00
    STA PPU_ADDR

    LDX bg_color

    LDA COLORS, X
    STA PPU_DATA

    RTS
.ENDPROC

.PROC UPDATE_TEXT_POS
    LDA pos_y
    ADC mov_y
    CMP #$E8
    BCC _CONTINUE_Y

    ; Reverse Y
    LDA mov_y
    NEA
    STA mov_y

    JSR UPDATE_BG_COLOR

    LDA pos_y
    _CONTINUE_Y:
    STA pos_y

    LDA pos_x
    ADC mov_x
    CMP #$D4
    BCC _CONTINUE_X

    ; Reverse X
    LDA mov_x
    NEA
    STA mov_x

    JSR UPDATE_BG_COLOR

    LDA pos_x
    _CONTINUE_X:
    STA pos_x

    _RETURN:
    RTS
.ENDPROC

.PROC TICK_FRAME_COUNT
    INC frame_count

    INC frame30_count
    CMP #$1E
    BNE _SKIP_RESET_8COUNTER
    LDA #$00
    STA frame30_count
    INC seconds
    _SKIP_RESET_8COUNTER:

    RTS
.ENDPROC

.PROC VBLANK
    JSR TICK_FRAME_COUNT
    JSR UPDATE_TEXT_POS
    JSR PRINT_HELLO

    ; Copy sprite mem to PPU
    LDA #$02
    STA OAM_DMA

    RTI
.ENDPROC

PALETTE_DATA:
    ; Background palettes
    .byte   COLOR_PORTAGE, COLOR_DENIM, COLOR_MAROON, COLOR_PERSIAN_INDIGO ; BG 0
    .byte   COLOR_PORTAGE, COLOR_DENIM, COLOR_MAROON, COLOR_LAVENDER_BLUE ; BG 1
    .byte   COLOR_PORTAGE, COLOR_DENIM, COLOR_MAROON, COLOR_WHITE_20 ; BG 2
    .byte   COLOR_PORTAGE, COLOR_DENIM, COLOR_MAROON, COLOR_BLUE_CHALK ; BG 3

    ; Sprite palettes
    .byte   COLOR_PORTAGE, COLOR_DENIM, COLOR_PERSIAN_INDIGO, COLOR_BLACK_0D ; SP 0
    .byte   COLOR_PORTAGE, COLOR_BRITISH_RACING_GREEN, COLOR_MAROON, COLOR_BLACK_0E ; SP 1
    .byte   COLOR_PORTAGE, COLOR_LAVENDER_BLUE, COLOR_MAROON, COLOR_BLACK_0F ; SP 2
    .byte   COLOR_PORTAGE, COLOR_MIDNIGHT_BLUE, COLOR_MAROON, COLOR_WHITE_20 ; SP 3

FONT_LETTERS:
    CHR_A = $00
    CHR_B = $01
    CHR_C = $02
    CHR_D = $03
    CHR_E = $04
    CHR_F = $05
    CHR_G = $06
    CHR_H = $07
    CHR_I = $08
    CHR_J = $09
    CHR_K = $0A
    CHR_L = $0B
    CHR_M = $0C
    CHR_N = $0D
    CHR_O = $0E
    CHR_P = $0F
    CHR_Q = $10
    CHR_R = $11
    CHR_S = $12
    CHR_T = $13
    CHR_U = $14
    CHR_V = $15
    CHR_W = $16
    CHR_X = $17
    CHR_Y = $18
    CHR_Z = $19

    CHR_SPACE = $1A

    CHR_0 = $20
    CHR_1 = $21
    CHR_2 = $22
    CHR_3 = $23
    CHR_4 = $24
    CHR_5 = $25
    CHR_6 = $26
    CHR_7 = $27
    CHR_8 = $28
    CHR_9 = $29
    CHR_EXCL = $2A
    CHR_QUOT = $2B
    CHR_DOLL = $2C
    CHR_PLUS = $2D
    CHR_MINS = $2E
    CHR_DOT = $2F

    CHR_END = $FF

COLORS:
    .byte $31, $21, $11, $01, $02, $12, $22, $32
    .byte $33, $23, $13, $03, $04, $14, $24, $34
    .byte $35, $25, $15, $05, $06, $16, $26, $36
    .byte $37, $27, $17, $07, $08, $18, $28, $38
    .byte $39, $29, $19, $09, $0A, $1A, $2A, $3A
    .byte $3B, $2B, $1B, $0B, $0C, $1C, $2C, $3C

.segment "CHARS"
    .incbin "chr/sprites.chr"
