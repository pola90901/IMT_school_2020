/*
 * PWM.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */


/*
 * app.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */

#include"types.h"
#include"util.h"
#include"Dio.h"
#include"regiester.h"
#include<avr/delay.h>

void main(void)
{
	Dio_SetPinDirection(PH_PORTB,PIN_3,OUTPUT_DIRECTION);




	reg_OCR0=3;
	reg_TCCR0=0b01101001;
	while(1)
	{
		for(int i=0;i<255;i++)
		{
			//Dio_TogglePin(PH_PORTA,PIN_0);


			reg_OCR0=i;
			_delay_ms(10);

		}
		for(int j=255;j>0;j--)
		{
			//Dio_TogglePin(PH_PORTA,PIN_0);


			reg_OCR0=j;
			_delay_ms(10);

		}

	}

}
