
#include "types.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include"ADC.h"
#include<avr/io.h>
int  main(void)
{
	u8 DATA;
		SPI_vidMasterInit();
		ADC_Init();
		PORTA=0x01;

		//DIO_vidSetPinVal(u8PORTA,DIO_u8PIN_0,DIO_u8HIGH);
		while(1)
		{
			DATA=ADC_Read(ADC_ADMUX_CHANNEL_ADC0);

			SPI_vidTransfer(DATA);
		}
return 0;

}

