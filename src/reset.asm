.include "constants.inc"

.segment "CODE"

.import main
.export reset_handler

.proc reset_handler
  SEI ; ignore interrupts
  CLD ; turn off decimal mode
  LDX #$00
  STX PPUCTRL
  STX PPUMASK ; By storing $00 to both PPUCTRL and PPUMASK, we turn off NMIs and disable rendering to the screen during startup.
vblankwait:
  BIT PPUSTATUS
  BPL vblankwait
vblankwait2:
  BIT PPUSTATUS
  BPL vblankwait2
  JMP main
.endproc