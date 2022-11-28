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
{
	//H_BRIDGE CIRCUIT
	//done :)
	Dio_SetPinDirection(PH_PORTA,PIN_0,OUTPUT_DIRECTION);
	Dio_SetPinDirection(PH_PORTA,PIN_1,OUTPUT_DIRECTION);
while(1)
{


	Dio_WritePin(PH_PORTA,PIN_0,HIGH_LEVEL);
	_delay_ms(1000);
	Dio_WritePin(PH_PORTA,PIN_0,LOW_LEVEL);
	Dio_WritePin(PH_PORTA,PIN_1,HIGH_LEVEL);
	_delay_ms(1000);
	Dio_WritePin(PH_PORTA,PIN_1,LOW_LEVEL);


}




}

