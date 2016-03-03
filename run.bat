avr-gcc -mmcu=attiny861a vilkutus.c salama.c -I. -Os -DF_CPU=8000000UL -o jee
avr-objcopy -O ihex -R .eeprom jee jeetest.hex
avrdude -c  avrisp -p t861 -B3 -P COM3 -b 19200 -U flash:w:jeetest.hex