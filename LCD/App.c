/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include "Dio.h"
#include"util.h"
#include"types.h"
#include "regiester.h"
#include<avr/delay.h>
#include "Lcd.h"
void main(void)
{

	Lcd_Init();
	Lcd_SendCommand(0x00);// clear display command
	u8 arr [20]="We Need 2";
u8 ar[100]="weeks off pls :D";
Lcd_SendString(&arr[0]);

Lcd_SendCommand(0x14); ///// shift cursor right by 1

/*
Lcd_SendCommand(0x40);         //set AC at CG ram 1st position
 	 	 _delay_ms(2);
		Lcd_SendChar(0x00);        //drawing the desired character (right mark)
		_delay_ms(2);
		Lcd_SendChar(0x01);
		_delay_ms(2);
		Lcd_SendChar(0x02);
		_delay_ms(2);
		Lcd_SendChar(0x14);
		_delay_ms(2);
		Lcd_SendChar(0x18);
		_delay_ms(2);
		Lcd_SendChar(0x10);
		_delay_ms(2);
		Lcd_SendChar(0x00);
		_delay_ms(2);

		Lcd_SendCommand(0x8B);   // storing the drawn char in DD RAM

		Lcd_SendChar(0x00); // call to display the drawn character

		Lcd_SendCommand(0x14);///// shift cursor right by 1
*/

	/*	Lcd_SendCommand(0x48);   //set AC at CG ram 2nd position
		 	 	 _delay_ms(2);
				Lcd_SendChar(0x11);
				_delay_ms(2);          // drawing (X)
				Lcd_SendChar(0x0A);
				_delay_ms(2);
				Lcd_SendChar(0x04);
				_delay_ms(2);
				Lcd_SendChar(0x0A);
				_delay_ms(2);
				Lcd_SendChar(0x11);
				_delay_ms(2);
				Lcd_SendChar(0x00);
				_delay_ms(2);
				Lcd_SendChar(0x00);
				_delay_ms(2);

				Lcd_SendCommand(0x8C);

				Lcd_SendChar(0x01);

*/
				Lcd_SetXY(1,2);

				Lcd_SendString(&ar[0]);

/*				Lcd_SendCommand(0x40);         //set AC at CG ram 1st position
				 	 	 _delay_ms(2);
						Lcd_SendChar(0x0E);        //drawing the desired character (right mark)
						_delay_ms(2);
						Lcd_SendChar(0x05);
						_delay_ms(2);
						Lcd_SendChar(0x0D);
						_delay_ms(2);
						Lcd_SendChar(0x05);
						_delay_ms(2);
						Lcd_SendChar(0x0D);
						_delay_ms(2);
						Lcd_SendChar(0x05);
						_delay_ms(2);
						Lcd_SendChar(0x0E);
						_delay_ms(2);

						Lcd_SendCommand(0x8B);   // storing the drawn char in DD RAM

						Lcd_SendChar(0x00); // call to display the drawn character
*/
}



