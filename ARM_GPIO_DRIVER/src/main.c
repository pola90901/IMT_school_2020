/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"

#include "GPIO_interface.h"




int main (void)
{
	MRCC_voidInitSystemClock();
	MRCC_voidEnablePeripheralClock(APB2,2);


	MGPIO_voidSetPinMode(GPIOA,PIN0,INPUT_PULL_UP_DOWN);
	MGPIO_voidSetPinValue(GPIOA,PIN0,GPIO_HIGH);

	MGPIO_voidSetPinMode(GPIOA,PIN1,OUTPUT_PP_2MHZ);


while(1)
{


	if (MGPIO_u8GetPinValue(GPIOA,PIN0)==1)
	{
		MGPIO_voidSetPinValue(GPIOA,PIN1,GPIO_LOW);

	}
	else
	{
		MGPIO_voidSetPinValue(GPIOA,PIN1,GPIO_HIGH);

	}
}
	return 0;
}
