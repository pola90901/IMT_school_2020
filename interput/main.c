/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */

#include"util.h"
#include"types.h"
#include "regiester.h"
#include "Dio.h"

void __vector_1(void)__attribute__((signal, __INTR_ATTRS));
// speaking to the complier to go to the vector that carry the address of ISR code to execute

void main(void)
{
	Dio_SetPinDirection(PH_PORTA,0,OUTPUT_DIRECTION);
	Dio_SetPinDirection(PH_PORTD,2,INPUT_DIRECTION);
	Dio_ActivatePinPullupResistor(PH_PORTD,2);

	write_byte(reg_MCUCR,2);// falling edge -rising edge -level)for INT0 and INT1 pins of micro controller at bit 2 -
	write_byte(reg_SREG,128);//global Interput enable
	write_byte(reg_GICR,64);//PIE -masked enable




	while(1)
	{

	}


}
void __vector_1(void)
{

	Dio_TogglePin(PH_PORTA,0);



	}
