/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */

#include"types.h"
#include"util.h"
#include <avr/io.h>
#include<avr/delay.h>
int main(void)
{
	u8 DIP_Value=PINC;




	/* PORT A as outPut*/
	DDRA=0xff;
	/*port C as pull up input*/
	DDRC=0x00;
	PORTC=0xff;
	/**************************************************************/


	while(1)
	{
		/*read value of input */
		DIP_Value=~PINC;

		switch(DIP_Value)
		{
		/* flashing LEDS*/
		case 1:
			PORTA=0xff;
			_delay_ms(500);
			PORTA=0x00;
			_delay_ms(500);
			break;
		case 2:				/*	shift left 			*/
			PORTA=0b00000111;
			_delay_ms(250);
			PORTA=0b00001110;
			_delay_ms(250);
			PORTA=0b00011100;
			_delay_ms(250);
			PORTA=0b00111000;
			_delay_ms(250);
			PORTA=0b01110000;
			_delay_ms(250);
			PORTA=0b11100000;
			_delay_ms(250);
			break;


		case 3:	/*	shift right		*/
			PORTA=0b11100000;
			_delay_ms(250);
			PORTA=0b01110000;
			_delay_ms(250);
			PORTA=0b00111000;
			_delay_ms(250);
			PORTA=0b00011100;
			_delay_ms(250);
			PORTA=0b00001110;
			_delay_ms(250);
			PORTA=0b00000111;
			_delay_ms(250);
			break;

		case 4:	/*	 Converging		*/
			PORTA=0b10000001;
			_delay_ms(250);
			PORTA=0b11000011;
			_delay_ms(250);
			PORTA=0b11100111;
			_delay_ms(250);
			PORTA=0b11101111;
			_delay_ms(250);
			PORTA=0b1111111;
			_delay_ms(250);
			break;
		case 5:	/*	  Diverging		*/
			PORTA=0b00010000;
			_delay_ms(250);
			PORTA=0b00011000;
			_delay_ms(250);
			PORTA=0b00111000;
			_delay_ms(250);
			PORTA=0b00111100;
			_delay_ms(250);
			PORTA=0b0111110;
			_delay_ms(250);
			PORTA=0b1111111;
			_delay_ms(250);
			break;


		default :
			PORTA=0x00;
			break;



		}


	}

	return 0;










}
