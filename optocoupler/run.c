/*
 * run.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */

#include"types.h"
#include"Dio.h"
#include"util.h"
#include<avr/delay.h>
void main(void)
{// opto not working
	u8 x;
	Dio_SetPinDirection(PH_PORTA,PIN_0,INPUT_DIRECTION);
	Dio_SetPinDirection(PH_PORTA,PIN_1,OUTPUT_DIRECTION);
	Dio_ActivatePinPullupResistor(PH_PORTA,PIN_0);
	while(1)
	{
		x=Dio_ReadPin(PH_PORTA,PIN_0);

		if (x==0)
		{
			Dio_WritePin(PH_PORTA,PIN_1,LOW_LEVEL);


		}
		else
		{
			Dio_WritePin(PH_PORTA,PIN_1,HIGH_LEVEL);

		}

	}
}

