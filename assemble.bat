ca65 src/main.asm
ca65 src/reset.asm
ld65 src/reset.o src/main.o -C nes.cfg -o output.nes
timeout /t 20