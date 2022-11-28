//#include "LIB/types.h"
//#include "LIB/bit.h"
#define F_CPU 8000000UL			/* Define frequency here its 8MHz */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include <avr/interrupt.h>
#include "types.h"
#include "util.h"
#include "avr/io.h"

#include "avr/delay.h"

#define Coil_Blue     0
#define Coil_Pink     1
#define Coil_Yellow   2
#define Coil_Orange   3
#define NO_OF_TASKS 3
volatile u8 x;

void led1(void)
{
	PORTA ^= 0x01;
}

void led2(void)
{
	PORTA ^= 0x02;
}

void led3(void)
{
	PORTA ^= 0x04;
}



void Stepper_RotateCW(void)
{
	{
	set_bit(PORTD,Coil_Blue);
	clear_bit(PORTD,Coil_Pink);
	clear_bit(PORTD,Coil_Yellow);
	clear_bit(PORTD,Coil_Orange);
	_delay_ms(5);

	clear_bit(PORTD,Coil_Blue);
	set_bit(PORTD,Coil_Pink);
	clear_bit(PORTD,Coil_Yellow);
	clear_bit(PORTD,Coil_Orange);
	_delay_ms(5);

	clear_bit(PORTD,Coil_Blue);
	clear_bit(PORTD,Coil_Pink);
	set_bit(PORTD,Coil_Yellow);
	clear_bit(PORTD,Coil_Orange);
	_delay_ms(5);

	clear_bit(PORTD,Coil_Blue);
	clear_bit(PORTD,Coil_Pink);
	clear_bit(PORTD,Coil_Yellow);
	set_bit(PORTD,Coil_Orange);
	_delay_ms(5);
}}


typedef struct
{
	u8 periodicity;
	u8 first_delay;
	void (*ptr) (void);
}task_t;

task_t task1={1,0,led1};
task_t task2={2,0,led2};
task_t task3={5,0,led3};


task_t*arr[NO_OF_TASKS] = {&task1,&task2,&task3};

void scheduler (void)
{
	for(u8 i=0; i<NO_OF_TASKS; i++)
	{
		if(arr[i] -> first_delay == 0)
		{
			arr[i] -> ptr();
			arr[i] -> first_delay = arr[i] -> periodicity-1;
		}
		else
		{
			arr[i] -> first_delay--;
		}
	}
}

void main(void)
{
	DDRA = 0xFF;
	DDRD=0xFF;
	sei(); // Enable global interrupt
	TIMSK = (1 << TOIE0 );
	TCCR0 = (1 << CS00)|(1 << CS02);
	while(1)
	{
		Stepper_RotateCW();
	}
}

ISR(TIMER0_OVF_vect)
{


	if(x == 30)
	{
		scheduler();
		x=0;
	}
	x++;


}
