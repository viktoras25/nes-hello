.INCLUDE "colors.inc"

; ================== PPU

; Bits - VPHB SINN
; V - NMI enable/disable
; P - PPU master/slave select
; H - Sprite size (0 - 8x8 pixels, 1 - 8x16 pixels)
; B - Background table address (0: $0000; 1: $1000)
; S - Sprite table address for 8x8 sprites (0: $0000; 1: $1000)
; I - VRAM address increment per CPU read/write of PPU_DATA (0 - add 1, 1 - add 32)
; NN - Base nametable address (0 - $2000, 1 - $2400, 2 - $2800, 3 - #2C00)
PPU_CTRL = $2000

; Bits - BGRs bMmG
; BGR - Color emphasis
; s - Sprite enable
; b - Background enable
; M - Sprite left column enable
; m - Background left column enable
; G - Greyscale
PPU_MASK = $2001

; Bits - VSO
; V - VBLANK
; S - Sprite 0 hit
; O - Sprite overflow
; Read resets write pair for $2005/$2006
PPU_STATUS = $2002

OAM_ADDR = $2003
OAM_DATA = $2004

PPU_SCROLL = $2005
PPU_ADDR = $2006
PPU_DATA = $2007

; ================== APU / Joysticks

OAM_DMA = $4014

; APU - Audo
; Delta modulation channel
APU_DMC_FREQ = $4010

; Bits - MI
; M - Mode. 0 = 4-step, 1 = 5-step
; I = IRQ inhibit flag
APU_FRAME_COUNTER = $4017

; ================== Misc

SPRITE_MEM = $0200

SCREEN_HEIGHT = $F0
SCREEN_WIDTH = $FF