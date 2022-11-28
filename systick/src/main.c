/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "RCC_interface.h"
#include"RCC_private.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include"STK_interface.h"
#include"STK_private.h"


int main(void)
{
	MRCC_voidInitSystemClock();
	MRCC_voidEnablePeripheralClock(RCC_APB2,2);
	MSTK_voidInit();

	MGPIO_voidSetPinMode(GPIOA,PIN2,OUTPUT_2MHZ_PP);

	while(1)
	{
		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_HIGH);


	MSTK_voidSetBusyWait(1000000);
	MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_LOW);


	}

return 0;
}

