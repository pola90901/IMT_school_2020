//#include "LIB/types.h"
//#include "LIB/bit.h"
#define F_CPU 8000000UL			/* Define frequency here its 8MHz */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "_TYPES_H_.h"
#include <avr/interrupt.h>

volatile u8 x,y,z;
void main(void)
{
	DDRA = 0xFF;
	sei(); // Enable global interrupt ( SREG = 0b10000000 )
	TIMSK = (1 << TOIE0 );
	TCCR0 = (1 << CS00)|(1 << CS02);
	while(1); // to make the leds blinking all the time and if we remove (while) the leds blink one time only
}

ISR(TIMER0_OVF_vect)
{

	if(x == 30) // timer overflows 30 times to make 1 sec
	{
		PORTA ^= 0x01;  // we put (^) to make the led blinking (toggle)
		x=0;           // to make it counting again
	}
	else
	{
		x++;
	}



	if(y == 60)   // timer overflows 60 times to make 2 sec
	{
		PORTA ^= 0x02;
		y=0;
	}
	else
	{
		y++;
	}


	if(z == 90)  // timer overflows 90 times to make 3 sec
	{
		PORTA ^= 0x04;
		z=0;
	}
	else
	{
		z++;
	}


}
