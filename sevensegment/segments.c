/*
 * segments.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */


#include"util.h"
#include"types.h"
#include "regiester.h"
#include"avr/delay.h"

void main(void)
{
	int i=0;
u8 numbers[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};


write_byte(reg_DDRA,255);




while(1)
{

    for(i=0;i<10;i++)
    {
    	write_byte(reg_PORTA,numbers[i]);
    _delay_ms(1000);
    }


}




}
