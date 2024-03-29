.segment "HEADER"

    ; See: https://wiki.nesdev.org/w/index.php?title=INES
    ; The format of the header is as follows: 
    ; 0-3: Constant $4E $45 $53 $1A ("NES" followed by MS-DOS end-of-file)
    .byte "NES", $1A
    
    ; Size of PRG ROM in 16 KB units
    .byte $02

    ; Size of CHR ROM in 8 KB units (Value 0 means the board uses CHR RAM)
    .byte $01
    
    ; 6: Flags 6 - Mapper, mirroring, battery, trainer
    ; 7: Flags 7 - Mapper, VS/Playchoice, NES 2.0
    ; 8: Flags 8 - PRG-RAM size (rarely used extension)
    ; 9: Flags 9 - TV system (rarely used extension)
    ; 10: Flags 10 - TV system, PRG-RAM presence (unofficial, rarely used extension)
    .byte $00, $00, $00, $00, $00

    ; 11-15: Unused padding (should be filled with zero, but some rippers put their name across bytes 7-15)
    .byte $00, $00, $00, $00, $00
