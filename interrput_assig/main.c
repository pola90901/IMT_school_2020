/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */

#include "util.h"
#include "types.h"
#include "regiester.h"
#include "DIO_int.h"
#include<avr/delay.h>
#include<avr/interrupt.h>


/********************************	LAP 1			****************************************/

int main(void)
{
	// output and low  initial value
	DIO_vidSetPinDirection(1,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(1,DIO_u8PIN_1,DIO_u8OUTPUT);

	DIO_vidSetPinVal(1,DIO_u8PIN_0,DIO_u8LOW);
	DIO_vidSetPinVal(1,DIO_u8PIN_1,DIO_u8LOW);
	//input
	DIO_vidSetPinDirection(4,DIO_u8PIN_2,DIO_u8INPUT);
	DIO_vidSetPinDirection(4,DIO_u8PIN_3,DIO_u8INPUT);
	// PULL UP
	DIO_vidSetPinVal(4,DIO_u8PIN_2,DIO_u8HIGH);
	DIO_vidSetPinVal(4,DIO_u8PIN_3,DIO_u8HIGH);

	SREG_REG.Bits.BIT_7 = 1;         //Enabling the Global Interrupt

	MCUCR_REG.Bits.BIT_0 = 1;
	MCUCR_REG.Bits.BIT_1 = 0;        // Make the Trigger mode of INT0 "logical"

	MCUCR_REG.Bits.BIT_2 = 1;        // Make the Trigger mode of INT1 "logical  "
	MCUCR_REG.Bits.BIT_3 = 0;

	GICR_REG.Bits.BIT_6 = 1 ;        // Set The PIE of INT0 to 1
	GICR_REG.Bits.BIT_7 = 1 ;			// SET the PIE INT1 to 1

	while(1)
	{

	}
	return 0;
}

ISR(INT0_vect)
{
	DIO_vidTogglePinVal(1,DIO_u8PIN_0);
}

ISR(INT1_vect)
{
	DIO_vidTogglePinVal(1,DIO_u8PIN_1);
}


/***********************************	LAP 2	******************************************************/

/*
u8 FLAG=1;
int main(void)
{

	DIO_vidSetPortDirection(1,0xFF);

	//input pin
	DIO_vidSetPinDirection(4,DIO_u8PIN_2,DIO_u8INPUT);
	// PULL UP
	DIO_vidSetPinVal(4,DIO_u8PIN_2,DIO_u8HIGH);




	SREG_REG.Bits.BIT_7 = 1;         //Enabling the Global Interrupt

	MCUCR_REG.Bits.BIT_0 = 0;
	MCUCR_REG.Bits.BIT_1 = 1;        // Make the Trigger mode of INT0 "Falling Edge"

	GICR_REG.Bits.BIT_6 = 1 ;        // Set The PIE of INT0 to 1

	u8 iterator;

	while(1)
	{
		if(FLAG==0)
		{
			for(iterator=0;iterator<8;iterator++)
			{
				DIO_vidSetPortVal(1,1<<iterator);
				_delay_ms(2000);
			}
		}
		else
		{
			DIO_vidSetPortVal(1,0xFF);
			_delay_ms(3000);
			DIO_vidSetPortVal(1,0x00);
			_delay_ms(3000);
		}
	}
	return 0;
}
ISR(INT0_vect)
{
	if(FLAG==1)
	{
		FLAG=0;
	}
	else
	{
		FLAG=1;
	}
}

*/
