/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"

#define GPIOA_CRL *( (u32*) 0x40010800   )
#define GPIOA_ODR *( (u32*) 0x4001080C   )

void main(void)
{
	MRCC_voidInitSystemClock();
	MRCC_voidEnablePeripheralClock(APB2,2);// from data sheet RCC register to choose port A

	GPIOA_CRL =0x000000020; // output 2 Mhz push pull
	GPIOA_ODR= 0x00000002;

}
