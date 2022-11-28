#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include"GPIO_private.h"

int main (void)
{
	u8 numbers[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};

	MRCC_voidInitSystemClock();
	MRCC_voidEnablePeripheralClock(RCC_APB2,2);

	MSTK_voidInit();


	MGPIO_voidSetPinMode(GPIOA,PIN0,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN1,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN2,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN3,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN4,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN5,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN6,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN7,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN8,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinValue(GPIOA,PIN8,GPIO_HIGH);
	while(1)
	{
		for(u8 i=0;i<10;i++)
	{
			GPIOA_ODR=numbers[i];
			MSTK_voidSetBusyWait(1000000);
	}


	}


	return 0;
}
