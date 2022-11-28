/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include <avr/io.h>
#include"util.h"
#include"types.h"
#include<avr/delay.h>


int main(void)
{


DDRA=0xFF;
DDRC=0x00;
while(1)
{

	if((PINC &0x07)==0)
	{
		PORTA=0xff;
		_delay_ms(1000);
		PORTA=0x00;
		_delay_ms(1000);
	}

	if(    (PINC &0x07)==2)
	{

	}
	if(    (PINC &0x07)==3)
	{

	}
	if(    (PINC &0x07)==4)
	{

	}
	if(    (PINC &0x07)==5)
	{

	}
	if(    (PINC &0x07)==6)
	{

	}
	if(    (PINC &0x07)==7)
	{

	}
	if(    (PINC &0x07)==8)
	{

	}




















}
return 0;
}
