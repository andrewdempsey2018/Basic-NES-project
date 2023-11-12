PPUCTRL = $2000

; PPUMASK allows your code to give the PPU instructions about what to draw, as well as set some tweaks to how colors are displayed. The byte that we store to PPUMASK is a set of eight bit flags, where each bit in the byte acts as an on/off switch for a particular property.
; Bit 0: Greyscale mode enable (0: normal color, 1: greyscale)
; Bit 1: Left edge (8px) background enable (0: hide, 1: show)
; Bit 2: Left edge (8px) foreground enable (0: hide, 1: show)
; Bit 3: Background enable
; Bit 4: Foreground enable
; Bit 5: Emphasize red
; Bit 6: Emphasize green
; Bit 7: Emphasize blue
PPUMASK = $2001

; This is a read only address, it tells us what the PPU is currently doing. A read from PPUSTATUS also resets the address latch for PPUADDR
PPUSTATUS = $2002

; PPUADDR store the high byte first, followed by the low byte to set the address. We then write to PPUDATA - the address auto increments from that point on for us.
PPUADDR = $2006

; Store a bytw with PPUDATA to the address we first selected with PPUADDR but remember, each time we store a byte to PPUDATA, the memory address for the next store is incremented by one.
PPUDATA = $2007