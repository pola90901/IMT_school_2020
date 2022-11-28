#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"


void main(void)
{



	MRCC_voidInitSystemClock();
	MRCC_voidEnablePeripheralClock(RCC_APB2,2);

	MGPIO_voidSetPinMode(GPIOA,PIN0,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN1,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(GPIOA,PIN2,OUTPUT_2MHZ_PP);

	u8 i;
	while(1)
	{
		for(i=0; i<8; i++)
		{
			HSTP_voidTransmit(1<<i);
			MSTK_voidSetBusyWait(200000);
		}
	}



}
