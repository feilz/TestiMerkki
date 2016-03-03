#include <avr/io.h>
#include <util/delay.h>

#include <kuviot.c>



void main (void)
{
//       76543210
DDRB = 0b00111100;
DDRA = 0b11111111;
PORTA = 0b00001111;
PORTB = 0b00000000;

while (1)
   {
   //kaikki();
   //kirkkaustesti();
   //himmennys(2,4); //(kerrat,nopeus)
   //ympari(6,5);
   //isoT(5,10);
   randomi(5,5);
   }
} 
