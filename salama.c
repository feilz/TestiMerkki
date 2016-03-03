#include <avr/io.h>
#include <util/delay.h>

#include <kuviot.c>



void main (void)
{
//       76543210
DDRB |= 0b00000010;
DDRA = 0b11111111;
PORTA = 0b00001111;
PORTB &= 0b11111101;


while (1)
   {
	if (0b00000010 & PINB){
		musta(1,1);
	}
   //kaikki();
   //kirkkaustesti();
   himmennys(2,5); //(kerrat,nopeus)
   ympari(3,5);
   isoT(2,10);
   //randomi(5,5);
   }
} 
