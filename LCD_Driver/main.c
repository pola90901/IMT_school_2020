/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: youss
 */
#include "util.h"
#include "types.h"
#include "regiester.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include<avr/delay.h>

int main (void)
{
	LCD_vidInit();

	u8 i=0;
	u8 y=0;
	while(1)
	{
		for(i=0;i<2;i++)
		{
			for(y=1;y<=10;y++)
			{
				LCD_vidSendCommand(0x01);    /* to clear the panel*/
				LCD_vidGoTo(i,y);			/* set cursor to the desired destination*/
				LCD_vidWriteString("pola");		/*printing my name*/
				_delay_ms(500);
			}
		}
	}
	return 0;

}
