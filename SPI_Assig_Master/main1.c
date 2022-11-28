
#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "SPI_interface.h"
#include"DIO_int.h"
#include "ADC.h"
#include<avr/delay.h>
int  main(void)
{


	u8 DATA;
	u8 dutycycle;

	// POT
	DIO_vidSetPinDirection(u8PORTA,DIO_u8PIN_0,DIO_u8INPUT);
	DIO_vidSetPinVal(u8PORTA,DIO_u8PIN_0,DIO_u8HIGH);

	SPI_vidMasterInit();
	ADC_Init();


	while(1)
	{
		DATA=ADC_Read(ADC_ADMUX_CHANNEL_ADC0);
		dutycycle=((u8)(DATA)/51.0)+5;
		SPI_vidTransfer(dutycycle);
		_delay_ms(100);
	}
	return 0;

}




