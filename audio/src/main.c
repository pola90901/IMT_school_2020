#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "Song.h"


#define GPIOA_ODR   *((u32*)(0x4001080C))

volatile u16 i ;
void DAC(void)

{
	GPIOA_ODR=mytrack_raw[i++];
	if(i==39938)
	{
		i=0;
	}



}

void main(void)
{
	MRCC_voidInitSystemClock();
	MRCC_voidEnablePeripheralClock(RCC_APB2,2);

	MGPIO_voidSetPinMode(GPIOA,PIN0,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN1,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN2,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN3,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN4,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN5,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN6,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN7,OUTPUT_2MHZ_PP);

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125,DAC);



	while(1)
	{


	}


}
