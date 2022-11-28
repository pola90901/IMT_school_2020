/*
 * LCD_prog.c
 *
 *  Created on: Aug 16, 2021
 *      Author: User
 */
#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include <avr/delay.h>
//#include "DIO_Prog.c"



void LCD_vidSendCommand(u8 Copy_Command)
{
	DIO_vidSetPinVal(u8PORTA, DIO_u8_PIN_2, DIO_u8LOW); //rs
	DIO_vidSetPinVal(u8PORTA, DIO_u8_PIN_3, DIO_u8LOW);//rw
	DIO_vidSetPortVal(u8PORTB, Copy_Command);
	DIO_vidSetPinVal(u8PORTA, DIO_u8_PIN_4, DIO_u8HIGH);//enable
	_delay_ms(1.53);
	DIO_vidSetPinVal(u8PORTA, DIO_u8_PIN_4, DIO_u8LOW);
}
void LCD_vidWriteString(u8 * Copy_String)
{
	u8 iterator=0;
	for( iterator=0; Copy_String[iterator] != '\0';iterator++)
	{
		LCD_vidWriteData(Copy_String[iterator]);
	}

}

void LCD_vidWriteData(u8 Copy_Data)
{
	DIO_vidSetPinVal(u8PORTA,DIO_u8_PIN_2,DIO_u8HIGH);  //RS=1 data
	DIO_vidSetPinVal(u8PORTA,DIO_u8_PIN_3,DIO_u8LOW);   //RW=0  write
	DIO_vidSetPortVal(u8PORTB,Copy_Data);
	DIO_vidSetPinVal(u8PORTA,DIO_u8_PIN_4,DIO_u8HIGH);      //enable is set to high (1)
	_delay_ms(2);
	DIO_vidSetPinVal(u8PORTA,DIO_u8_PIN_4,DIO_u8LOW);         //enable is set to low (0)
}
void LCD_vidInit()
{
	DIO_vidSetPinDirection(u8PORTA,DIO_u8_PIN_2,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(u8PORTA,DIO_u8_PIN_3,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(u8PORTA,DIO_u8_PIN_4,DIO_u8OUTPUT);
	DIO_vidSetPortDirection(u8PORTB,0xFF);

	_delay_ms(40); /* Step_1 */
	LCD_vidSendCommand(0b00111000); /* Step_2 */
	_delay_ms(1); /* Step_3 */
	LCD_vidSendCommand(0b00001111); /* Step_4 */
	_delay_ms(1); /* Step_5 */
	LCD_vidSendCommand(LCD_u8CLEAR_DISPLAY); /* Step_6 */
	_delay_ms(2); /* Step_7 */
	LCD_vidSendCommand(0b00000110); /* Step_8 */
}

void LCD_vidGoTo(u8 Copy_Row, u8 Copy_Column)
{
    if((Copy_Column >= 0) && (Copy_Column <=15))
    {
    	switch(Copy_Row)
    	{
    	case 0:
    		LCD_vidSendCommand((0b10000000) + (Copy_Column));
    		break;
    	case 1:
    		LCD_vidSendCommand((0b11000000) + (Copy_Column));
    		break;

    	default:

    		break;
    	}
    }
}


