/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */

#include "util.h"
#include "types.h"
#include "regiester.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include<avr/delay.h>
int main(void)
{
	LCD_vidInit();
	/*   set OUTPUT PINS  for motor 1      */
	DIO_vidSetPinDirection(PORTA,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTA,DIO_u8PIN_1,DIO_u8OUTPUT);
		/*SET output pins for motor 2 */
	DIO_vidSetPinDirection(PORTB,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(PORTB,DIO_u8PIN_1,DIO_u8OUTPUT);
	/* input PULL UP PINS for switches*/
	DIO_vidSetPinDirection(PORTA,DIO_u8PIN_3,DIO_u8INPUT);
	DIO_vidSetPinDirection(PORTA,DIO_u8PIN_4,DIO_u8INPUT);
	DIO_vidSetPinVal(PORTA,DIO_u8PIN_3,DIO_u8HIGH);
	DIO_vidSetPinVal(PORTA,DIO_u8PIN_4,DIO_u8HIGH);

	while(1)
	{
		/*				checking switches	statutes								*/
		if((DIO_u8GetPin(PORTA,DIO_u8PIN_4)==0)&&(DIO_u8GetPin(PORTA,DIO_u8PIN_3)==0))
		{
			/*breaking motor 1*/
			DIO_vidSetPinVal(PORTA,DIO_u8PIN_0,DIO_u8LOW);
			DIO_vidSetPinVal(PORTA,DIO_u8PIN_1,DIO_u8LOW);
			/*	breaking motor 2 */
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8LOW);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_1,DIO_u8LOW);
			/*	clear LCD and write Breaking */
			LCD_vidSendCommand(0x01);
			LCD_vidWriteString("BREAKING");
			_delay_ms(1000);
		}
		/*				checking switches	statutes								*/
		else  if((DIO_u8GetPin(PORTA,DIO_u8PIN_4)==1)&&(DIO_u8GetPin(PORTA,DIO_u8PIN_3)==1))
		{
			/*breaking motor 1*/
			DIO_vidSetPinVal(PORTA,DIO_u8PIN_0,DIO_u8LOW);
			DIO_vidSetPinVal(PORTA,DIO_u8PIN_1,DIO_u8LOW);
			/*breaking motor 2*/
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8LOW);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_1,DIO_u8LOW);
			/*	clear LCD and write Breaking */
			LCD_vidSendCommand(0x01);
			LCD_vidWriteString("BREAKING");
			_delay_ms(1000);
		}
		/*				checking switches	statutes								*/
		else if(DIO_u8GetPin(PORTA,DIO_u8PIN_3)==0)
		{
			/*MOTOR 1 rotate clock wise */
			DIO_vidSetPinVal(PORTA,DIO_u8PIN_0,DIO_u8HIGH);
			DIO_vidSetPinVal(PORTA,DIO_u8PIN_1,DIO_u8LOW);
			/*MOTOR 2 rotate clock wise */
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8HIGH);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_1,DIO_u8LOW);

			/*	clear LCD and write clockwise  */
			LCD_vidSendCommand(0x01);
			LCD_vidWriteString("Clock wise");
			_delay_ms(1000);
		}
		else if(DIO_u8GetPin(PORTA,DIO_u8PIN_4)==0)
		{
			/*MOTOR 1 rotate anti clock wise */
			DIO_vidSetPinVal(PORTA,DIO_u8PIN_0,DIO_u8LOW);
			DIO_vidSetPinVal(PORTA,DIO_u8PIN_1,DIO_u8HIGH);
			/*MOTOR 2 rotate anti clock wise */
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_0,DIO_u8LOW);
			DIO_vidSetPinVal(PORTB,DIO_u8PIN_1,DIO_u8HIGH);
			/*	clear LCD and write anti clockwise  */
			LCD_vidSendCommand(0x01);
			LCD_vidWriteString("antiClock wise");
			_delay_ms(1000);
		}
	}

	return 0;





}
