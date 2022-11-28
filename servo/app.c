/*
 * app.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */


#include<avr/io.h>


#include"types.h"
#include"util.h"
#include"Dio.h"

#include<avr/delay.h>


#define F_CPU 8000000UL
void main(void)
{
	Dio_SetPinDirection(PH_PORTD,PIN_5,OUTPUT_DIRECTION);

	//Dio_ActivatePinPullupResistor(PH_PORTB,PIN_0);

	//reg_OCR1AH=700>>8;
	//reg_OCR1AL=700;

	ICR1=2499;

	TCCR1A=0b10000010;
	TCCR1B=0b00011011;
	while(1)
	{


		OCR1A=65;
		_delay_ms(1000);
		OCR1A=175;
		_delay_ms(1000);
		OCR1A=300;
		_delay_ms(1000);

	}

}

