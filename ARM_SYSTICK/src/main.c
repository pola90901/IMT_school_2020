/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include "RCC_interface.h"
#include"RCC_private.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include"STK_interface.h"
#include"STK_private.h"


void main(void)
{
	MRCC_voidInitSystemClock();
	MRCC_voidEnablePeripheralClock(APB2,2);
	MSTK_voidInit();
	MGPIO_voidSetPinMode(GPIOA,PIN0,OUTPUT_PP_2MHZ);
	while(1)
	{
	MSTK_voidSetBusyWait(1000000);
	MGPIO_voidSetPinValue(GPIOA,PIN0,GPIO_HIGH);
	MSTK_voidSetBusyWait(1000000);
	MGPIO_voidSetPinValue(GPIOA,PIN0,GPIO_LOW);


	}


}

