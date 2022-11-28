/*
 * trafficlight.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */

/*
#include "Dio.h"
#include"util.h"
#include"types.h"
#include "regiester.h"
#include<avr/delay.h>
void main(void)
{
	 Dio_SetPortDirection(PH_PORTA,OUTPUT_DIRECTION);
	 Dio_SetPortDirection(PH_PORTD,OUTPUT_DIRECTION);
	 Dio_SetPortDirection(PH_PORTC,OUTPUT_DIRECTION);
	 u8 numbers[10]={0b00111111,0b01101111,0b01111111,0b00000111,0b01111101,0b01101101,0b01100110,0b01001111,0b01011011,0b00000110};
	 Dio_WritePin(PH_PORTC,PIN_0,LOW_LEVEL);
	 Dio_WritePin(PH_PORTC,PIN_1,LOW_LEVEL);
	 Dio_WritePin(PH_PORTC,PIN_2,LOW_LEVEL);

 while(1)

 {
	 for(u8 i=0;i<10;i++)
	 {
		 Dio_WritePin(PH_PORTC,PIN_1,LOW_LEVEL);
		 Dio_WritePin(PH_PORTC,PIN_2,LOW_LEVEL);
		 Dio_WritePin(PH_PORTC,PIN_0,HIGH_LEVEL);// red led high
		if(i!=0)
			{write_byte(reg_PORTA,0b00111111);}
		 write_byte(reg_PORTD,numbers[i]); /// first 7 segment counting

		     if (i==0)
		     {
				 write_byte(reg_PORTA,0b00000110);

		     }
		     _delay_ms(1000);
	 }
	 for(u8 y=0;y<10;y++)
	 {
		 Dio_WritePin(PH_PORTC,PIN_1,LOW_LEVEL);
		 Dio_WritePin(PH_PORTC,PIN_0,LOW_LEVEL);// red led off
		 Dio_WritePin(PH_PORTC,PIN_2,HIGH_LEVEL); // green led on
		 if(y!=0)
		 			{write_byte(reg_PORTA,0b00111111);}
		 write_byte(reg_PORTD,numbers[y]); /// first 7 segment counting

		     if (y==0)
		     {
				 write_byte(reg_PORTA,0b00000110);

		     }
		     _delay_ms(1000);
	 }
	 for(u8 w=7;w<10;w++)
	 {
		 Dio_WritePin(PH_PORTC,PIN_0,LOW_LEVEL);// red led off
		 Dio_WritePin(PH_PORTC,PIN_2,LOW_LEVEL); // green led off
		 Dio_WritePin(PH_PORTC,PIN_1,HIGH_LEVEL);// yellow led on
		 write_byte(reg_PORTA,0b00111111);
		 write_byte(reg_PORTD,numbers[w]); /// first 7 segment counting
		     _delay_ms(1000);
	 }







 }
}*/
