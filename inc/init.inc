.include "header.inc"
.include "constants.inc"
.include "zeropage.inc"

.segment "VECTORS"
    .word VBLANK, RESET, $0000

.include "macros.inc"

; Include reset/clear memory routines
.include "startup.inc"
