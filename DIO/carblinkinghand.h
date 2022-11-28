/*
 * carblinkinghand.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */


#include "Dio.h"
#include"util.h"
#include"types.h"
#include "regiester.h"
#include<avr/delay.h>
void main(void)
{
	Dio_SetPinDirection(PH_PORTA,OUTPUT_DIRECTION,PIN_7);//led right
	Dio_SetPinDirection(PH_PORTA,OUTPUT_DIRECTION,PIN_6);//led left
	Dio_SetPinDirection(PH_PORTA,INPUT_DIRECTION,PIN_1);//up cursor
	Dio_SetPinDirection(PH_PORTA,INPUT_DIRECTION,PIN_2);//down cursor
	Dio_SetPinDirection(PH_PORTA,INPUT_DIRECTION,PIN_0);// hazard
	Dio_ActivatePinPullupResistor(PH_PORTA,PIN_0);
	Dio_ActivatePinPullupResistor(PH_PORTA,PIN_1);
	Dio_ActivatePinPullupResistor(PH_PORTA,PIN_2);



	u8 x,y,z,i=0,w=0;
	while(1)
	{
		z=Dio_ReadPin(PH_PORTA,PIN_0);
		if (z==0)
		{
			Dio_WritePin(PH_PORTA,PIN_7,HIGH_LEVEL);
			Dio_WritePin(PH_PORTA,PIN_6,HIGH_LEVEL);

			_delay_ms(1000);

			Dio_WritePin(PH_PORTA,PIN_7,LOW_LEVEL);
			Dio_WritePin(PH_PORTA,PIN_6,LOW_LEVEL);


			_delay_ms(1000);

		}
		else
		{
			x=Dio_ReadPin(PH_PORTA,PIN_1);
			y=Dio_ReadPin(PH_PORTA,PIN_2);
			if (x==0)
			{
				i=1;
			}
			if (y==0)
			{
				w=1;
			}

			if(i>w)
			{
				Dio_TogglePin(PH_PORTA,PIN_7);
				_delay_ms(500);

			}
			if(w>i)
			{
				Dio_TogglePin(PH_PORTA,PIN_6);
				_delay_ms(500);

			}
			if(i==w)
			{
				i=0;
				w=0;
				Dio_WritePin(PH_PORTA,PIN_7,LOW_LEVEL);
				Dio_WritePin(PH_PORTA,PIN_6,LOW_LEVEL);
				_delay_ms(500);





			}




		}}}










































