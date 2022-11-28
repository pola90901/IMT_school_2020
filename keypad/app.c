/*
 * app.c


 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */



#include "KeyPad.h"
#include "Dio.h"
#include "avr/delay.h"
#include "util.h"
#include "types.h"
#include "Lcd.h"
void main(void)
{
	u8 x;

	Lcd_Init();
	KeyPad_Init();
	while(1)
	{
		x=KeyPad_GetPressedKey();

		if(x!=0)
		{

			if(x=='C')
			{
				Lcd_SendCommand(0x01);
			}
			else
			{
				Lcd_SendChar(x);
			}
		}

	}

}
