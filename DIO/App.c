/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include "Dio.h"
#include"util.h"
#include"types.h"
#include "regiester.h"
#include<avr/delay.h>
void main(void)
{

Dio_SetPortDirection(PH_PORTA,OUTPUT_DIRECTION);


	while(1)
	{
		 Dio_WritePort(PH_PORTA,0xff);
		 _delay_ms(1000);
		 Dio_TogglePort(PH_PORTA);
		 _delay_ms(1000);

	}
	/*test for toggle bytes (Succeed)*/

}
