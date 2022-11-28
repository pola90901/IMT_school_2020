/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */


#include "FreeRTOS.h"
#include "task.h"
#include<avr/io.h>
#include"semphr.h"

void led1(void*ptr);
void led2(void*ptr);
void led3(void *ptr);
int main(void)
{
	DDRA=0xFF;


	xTaskCreate(&led1,NULL,200,NULL,1,NULL);
	xTaskCreate(&led2,NULL,200,NULL,1,NULL);
	xTaskCreate(&led3,NULL,200,NULL,1,NULL);
	vTaskStartScheduler();
	while(1);

}

void led1(void*ptr)
{
	while(1)
	{
		PORTA ^=0x01;
		vTaskDelay(1000);
	}
}

void led2(void*ptr)
{
	while(1)
	{
		PORTA ^=0x02;
		vTaskDelay(1000);
	}
}



void led3(void*ptr)
{
	while(1)
	{
		PORTA ^=0x04;
		vTaskDelay(1000);
	}
}




