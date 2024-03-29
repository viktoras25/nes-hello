PALETTE_BACKGROUND = $3F00

; Addresses $3F04/$3F08/$3F0C can contain unique data,
; though these values are not used by the PPU when normally rendering
; (since the pattern values that would otherwise select those cells
; select the backdrop color instead).

PALETTE_BG_0 = $3F01
PALETTE_BG_0_0 = $3F01
PALETTE_BG_0_1 = $3F01
PALETTE_BG_0_2 = $3F02
PALETTE_BG_0_3 = $3F03

PALETTE_BG_1 = $3F04
PALETTE_BG_1_0 = $3F04
PALETTE_BG_1_1 = $3F05
PALETTE_BG_1_2 = $3F06
PALETTE_BG_1_3 = $3F07

PALETTE_BG_2 = $3F08
PALETTE_BG_2_0 = $3F08
PALETTE_BG_2_1 = $3F09
PALETTE_BG_2_2 = $3F0A
PALETTE_BG_2_3 = $3F0B

PALETTE_BG_3 = $3F0C
PALETTE_BG_3_0 = $3F0C
PALETTE_BG_3_1 = $3F0D
PALETTE_BG_3_2 = $3F0E
PALETTE_BG_3_3 = $3F0F

PALETTE_SP_0 = $3F11
PALETTE_SP_0_0 = $3F11
PALETTE_SP_0_1 = $3F11
PALETTE_SP_0_2 = $3F12
PALETTE_SP_0_3 = $3F13

PALETTE_SP_1 = $3F14
PALETTE_SP_1_0 = $3F14
PALETTE_SP_1_1 = $3F15
PALETTE_SP_1_2 = $3F16
PALETTE_SP_1_3 = $3F17

PALETTE_SP_2 = $3F18
PALETTE_SP_2_0 = $3F18
PALETTE_SP_2_1 = $3F19
PALETTE_SP_2_2 = $3F1A
PALETTE_SP_2_3 = $3F1B

PALETTE_SP_3 = $3F1C
PALETTE_SP_3_0 = $3F1C
PALETTE_SP_3_1 = $3F1D
PALETTE_SP_3_2 = $3F1E
PALETTE_SP_3_3 = $3F1F

COLOR_DIM_GRAY              = $00   ; #656565
COLOR_PRUSSIAN_BLUE         = $01   ; #002D69
COLOR_MIDNIGHT_BLUE         = $02   ; #131F7F
COLOR_PERSIAN_INDIGO        = $03   ; #3C147C
COLOR_PALATINATE_PURPLE     = $04   ; #600B62
COLOR_TYRIAN_PURPLE         = $05   ; #730A37
COLOR_MAROON                = $06   ; #710E07
COLOR_BAKERS_CHOCOLATE      = $07   ; #5A1A00
COLOR_MAIRE                 = $08   ; #342800
COLOR_MYRTLE                = $09   ; #0B3400
COLOR_MYRTLE_LIGHER         = $0A   ; #0B3400
COLOR_BRITISH_RACING_GREEN  = $0B   ; #003D11
COLOR_SHERPA_BLUE           = $0C   ; #003840
COLOR_BLACK_0D              = $0D   ; #000000
COLOR_BLACK_0E              = $0E   ; #000000
COLOR_BLACK_0F              = $0F   ; #000000

COLOR_DARK_GRAY             = $10   ; #ADADAD
COLOR_DENIM                 = $11   ; #0F63B3
COLOR_FREE_SPEECH_BLUE      = $12   ; #4051D0
COLOR_PURPLE_HEART          = $13   ; #7841CC
COLOR_VIOLET_BLUE           = $14   ; #A736A9

COLOR_WHITE_20              = $20   ; #FFFFFF
COLOR_MAYA_BLUE             = $21   ; #5DB3FF
COLOR_PORTAGE               = $22   ; #8FA1FF
COLOR_MAUVE                 = $23   ; #C890FF
COLOR_VIOLET                = $24   ; #F785FA
COLOR_TEA_ROSE              = $25   ; #FF83BF

COLOR_WHITE_30              = $30   ; #FFFFFF
COLOR_PALE_CORNFLOWER_BLUE  = $31   ; #BCDEFF
COLOR_LAVENDER_BLUE         = $32   ; #D1D8FF
COLOR_BLUE_CHALK            = $33   ; #E8D1FF