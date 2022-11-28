/*
 * toggle.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include"avr/delay.h"
#include"util.h"
#include"types.h"
#include"regiester.h"
int i=0,x;
void main(void)
{



	while(1)
	{

	clear_bit(reg_DDRA,0);
	set_bit(reg_PORTA,0);
	clear_bit(reg_SFIOR,2);

x=Get_bit(reg_PINA,0);

		if (x==0)
		{
		    _delay_ms(100);
			toggle_bit(reg_PORTA,1);
		    _delay_ms(100);

		}




}}

