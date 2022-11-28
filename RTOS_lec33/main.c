//#include "LIB/types.h"
//#include "LIB/bit.h"
#define F_CPU 8000000UL			/* Define frequency here its 8MHz */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "_TYPES_H_.h"
#include <avr/interrupt.h>
#define NO_OF_TASKS 3
volatile u8 x,y,z;

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

typedef struct
{
	u8 periodicity;
	u8 first_delay;
	void (*ptr) (void);
}task_t;

task_t task1={1,0,led1};
task_t task2={2,0,led2};
task_t task3={3,0,led3};

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
	sei(); // Enable global interrupt
	TIMSK = (1 << TOIE0 );
	TCCR0 = (1 << CS00)|(1 << CS02);
	while(1);
}

ISR(TIMER0_OVF_vect)
{

	x++;
	if(x == 30)
	{
		scheduler();
		x=0;
	}


}
