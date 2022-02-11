.macro COPY mem, val
    LDA val
    STA mem
.endmacro

.macro COPY16 src, dst
    LDA #<src
    STA dst

    LDA #>src
    STA dst+1
.endmacro

.macro INC8 val
    LDA val
    ADC #$08
    STA val
.endmacro

.macro NEA
    EOR #$FF
    SEC
    ADC #0
.endmacro
