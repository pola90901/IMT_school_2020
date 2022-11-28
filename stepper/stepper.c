/*
 * stepper.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
/*
#include <avr/delay.h>
#include "Dio.h"
#include"util.h"
#include"types.h"
#include "regiester.h"
void main(void)
{
	Dio_SetPortDirection(PH_PORTA,OUTPUT_DIRECTION);
   while(1)
   {
	   for(int i=0;i<520;i++)
	   {
	   Dio_WritePin(PH_PORTA,PIN_0,HIGH_LEVEL);
	   _delay_ms(2);
	   Dio_WritePin(PH_PORTA,PIN_0,LOW_LEVEL);

	   Dio_WritePin(PH_PORTA,PIN_1,HIGH_LEVEL);
	   _delay_ms(2);
	   Dio_WritePin(PH_PORTA,PIN_1,LOW_LEVEL);

	   Dio_WritePin(PH_PORTA,PIN_2,HIGH_LEVEL);
	   _delay_ms(2);
	   Dio_WritePin(PH_PORTA,PIN_2,LOW_LEVEL);

	   Dio_WritePin(PH_PORTA,PIN_3,HIGH_LEVEL);
	   _delay_ms(2);
	   Dio_WritePin(PH_PORTA,PIN_3,LOW_LEVEL);
	   }
	   _delay_ms(5000);

	   for(int y=0;y<520;y++)
	 	   {

	 	   Dio_WritePin(PH_PORTA,PIN_3,HIGH_LEVEL);
	 	   _delay_ms(2);
	 	   Dio_WritePin(PH_PORTA,PIN_3,LOW_LEVEL);

	 	   Dio_WritePin(PH_PORTA,PIN_2,HIGH_LEVEL);
	 	   _delay_ms(2);
	 	   Dio_WritePin(PH_PORTA,PIN_2,LOW_LEVEL);

	 	   Dio_WritePin(PH_PORTA,PIN_1,HIGH_LEVEL);
	 	   _delay_ms(2);
	 	   Dio_WritePin(PH_PORTA,PIN_1,LOW_LEVEL);

	 	   Dio_WritePin(PH_PORTA,PIN_0,HIGH_LEVEL);
	 	   _delay_ms(2);
	 	   Dio_WritePin(PH_PORTA,PIN_0,LOW_LEVEL);
	 	   }
	   _delay_ms(5000);






   }



}*/
/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#include "types.h"
#include "util.h"
#include "avr/io.h"

#include "avr/delay.h"

#define Coil_Blue     0
#define Coil_Pink     1
#define Coil_Yellow   2
#define Coil_Orange   3

void Stepper_RotateACW(void);
void Stepper_RotateCW(void);

void main(void)
{
	/* PORT D as output */
	DDRD = 0xff;
	u8 i;

	while (1)
	{
		/* Rotate clock wise for 5 seconds */
		for (i=0;i<250;i++)
		{
			Stepper_RotateCW();
		}

		/* Rotate anti clock wise for 5 seconds */



	}

	return;
}


void Stepper_RotateCW(void)
{
	set_bit(PORTD,Coil_Blue);
	clear_bit(PORTD,Coil_Pink);
	clear_bit(PORTD,Coil_Yellow);
	clear_bit(PORTD,Coil_Orange);
	_delay_ms(5);

	clear_bit(PORTD,Coil_Blue);
	set_bit(PORTD,Coil_Pink);
	clear_bit(PORTD,Coil_Yellow);
	clear_bit(PORTD,Coil_Orange);
	_delay_ms(5);

	clear_bit(PORTD,Coil_Blue);
	clear_bit(PORTD,Coil_Pink);
	set_bit(PORTD,Coil_Yellow);
	clear_bit(PORTD,Coil_Orange);
	_delay_ms(5);

	clear_bit(PORTD,Coil_Blue);
	clear_bit(PORTD,Coil_Pink);
	clear_bit(PORTD,Coil_Yellow);
	set_bit(PORTD,Coil_Orange);
	_delay_ms(5);
}

void Stepper_RotateACW(void)
{

	clear_bit(PORTD,Coil_Blue);
	clear_bit(PORTD,Coil_Pink);
	clear_bit(PORTD,Coil_Yellow);
	set_bit(PORTD,Coil_Orange);
	_delay_ms(5);

	clear_bit(PORTD,Coil_Blue);
	clear_bit(PORTD,Coil_Pink);
	set_bit(PORTD,Coil_Yellow);
	clear_bit(PORTD,Coil_Orange);
	_delay_ms(5);

	clear_bit(PORTD,Coil_Blue);
	set_bit(PORTD,Coil_Pink);
	clear_bit(PORTD,Coil_Yellow);
	clear_bit(PORTD,Coil_Orange);
	_delay_ms(5);

	set_bit(PORTD,Coil_Blue);
	clear_bit(PORTD,Coil_Pink);
	clear_bit(PORTD,Coil_Yellow);
	clear_bit(PORTD,Coil_Orange);
	_delay_ms(5);
}
