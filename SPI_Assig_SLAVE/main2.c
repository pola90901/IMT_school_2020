
#include "types.h"
#include "SPI_interface.h"
#include "LCD_int.h"
#include"DIO_int.h"
#include "PWM_int.h"
#include<avr/delay.h>
#include "ATMEGA32_REGISTERS.h"
int  main(void)
{
	u8 DATA;
	/*set motor as output*/
	DIO_vidSetPinDirection(u8PORTD,DIO_u8PIN_5,DIO_u8OUTPUT);
	SPI_vidSlaveInit();
	LCD_vidInit();
	PWM_vidPwmInit(TIMER_1);
	PWM_StartTimer(TIMER_1);
	while(1)
	{
		DATA=SPI_u8Recieve();
		PWM_vidSetPWMDutyCycle(TIMER_1, DATA);

		LCD_vidGoTo(0,0);
		LCD_vidWriteData((((u16)DATA/100)%10)+'0');
		LCD_vidGoTo(0,1);
		LCD_vidWriteData((((u16)DATA/10)%10)+'0');
		LCD_vidGoTo(0,2);
		LCD_vidWriteData(((u16)DATA%10)+'0');


	}
	return 0;

}

