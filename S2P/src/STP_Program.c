#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_INTERFACE.h"

#include "STP_CONFIG.h"






void HSTP_voidTransmit(u8 copyu8DataToSerial)
{

s8 i,x;



	for(i=7;i>=0;i--)
	{
		x= GET_BIT(copyu8DataToSerial,i);
		MGPIO_voidSetPinValue(SERIAL_DATA_PIN,x);

	MGPIO_voidSetPinValue(SHIFT_CLOCK_PIN,GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(SHIFT_CLOCK_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(1);



	}


	MGPIO_voidSetPinValue(STORGARE_CLOCK_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(STORGARE_CLOCK_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(1);

}
