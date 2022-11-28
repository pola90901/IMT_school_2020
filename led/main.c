/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include<avr/io.h>

#include"util.h"
#include"types.h"
#include"avr/delay.h"
//#include"regiester.h"

void main(void)
{
	while(1)
	{
	set_bit(DDRA,0);
    set_bit(PORTA,0);
    _delay_ms(100);
    clear_bit(DDRA,0);
    clear_bit(PORTA,0);
    _delay_ms(100);

        set_bit(DDRA,1);
        set_bit(PORTA,1);
        _delay_ms(100);
        clear_bit(DDRA,1);
        clear_bit(PORTA,1);
        _delay_ms(100);

        set_bit(DDRA,2);
        set_bit(PORTA,2);
        _delay_ms(100);
        clear_bit(DDRA,2);
        clear_bit(PORTA,2);
        _delay_ms(100);

        set_bit(DDRA,3);
        set_bit(PORTA,3);
        _delay_ms(100);
        clear_bit(DDRA,3);
        clear_bit(PORTA,3);
        _delay_ms(100);

        set_bit(DDRA,4);
        set_bit(PORTA,4);
        _delay_ms(100);
        clear_bit(DDRA,4);
        clear_bit(PORTA,4);
        _delay_ms(100);

        set_bit(DDRA,5);
        set_bit(PORTA,5);
        _delay_ms(100);
        clear_bit(DDRA,5);
        clear_bit(PORTA,5);
        _delay_ms(100);

        set_bit(DDRA,6);
        set_bit(PORTA,6);
        _delay_ms(100);
        clear_bit(DDRA,6);
        clear_bit(PORTA,6);
        _delay_ms(100);

        set_bit(DDRA,7);
        set_bit(PORTA,7);
        _delay_ms(100);
        clear_bit(DDRA,7);
        clear_bit(PORTA,7);
        _delay_ms(100);

        set_bit(DDRA,6);
        set_bit(PORTA,6);
        _delay_ms(100);
        clear_bit(DDRA,6);
        clear_bit(PORTA,6);
        _delay_ms(100);

        set_bit(DDRA,5);
        set_bit(PORTA,5);
        _delay_ms(100);
        clear_bit(DDRA,5);
        clear_bit(PORTA,5);
        _delay_ms(100);

        set_bit(DDRA,4);
        set_bit(PORTA,4);
        _delay_ms(100);
        clear_bit(DDRA,4);
        clear_bit(PORTA,4);
        _delay_ms(100);

        set_bit(DDRA,3);
        set_bit(PORTA,3);
        _delay_ms(100);
        clear_bit(DDRA,3);
        clear_bit(PORTA,3);
        _delay_ms(100);



        set_bit(DDRA,2);
        set_bit(PORTA,2);
        _delay_ms(100);
        clear_bit(DDRA,2);
        clear_bit(PORTA,2);
        _delay_ms(100);

        set_bit(DDRA,1);
        set_bit(PORTA,1);
        _delay_ms(100);
        clear_bit(DDRA,1);
        clear_bit(PORTA,1);
        _delay_ms(100);




    }





}
