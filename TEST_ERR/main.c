/*
 * interrupt_ass1.c
 *
 *  Created on: Aug 20, 2021
 *      Author: hp
 */

#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO_int.h"
#include<avr/interrupt.h>


int main(void)
{
   //setting two pins as output for the leds
  DIO_vidSetPinDirection(u8PORTA,DIO_u8PIN_0,DIO_u8OUTPUT);
  DIO_vidSetPinDirection(u8PORTA,DIO_u8PIN_1,DIO_u8OUTPUT);


  //setting the twu pins for interrupt 0  and interrupt 1

   DIO_vidSetPinDirection(u8PORTD,DIO_u8PIN_2,DIO_u8INPUT);  //INT 0
   DIO_vidSetPinDirection(u8PORTD,DIO_u8PIN_3,DIO_u8INPUT);  //INT 1

   //interrupt trigger mpde IOC
   /*INT 0*/

   MCUCR_REG.Bits.BIT_0=1;
   MCUCR_REG.Bits.BIT_1=0;

   /*INT 1*/
   MCUCR_REG.Bits.BIT_2=1;
   MCUCR_REG.Bits.BIT_3=0;

   //Enabling PIE
   GICR_REG.Bits.BIT_6=1; //INT 0
   GICR_REG.Bits.BIT_7=1; //INT 1

   //Enabling GIE
    SREG_REG.Bits.BIT_7=1;

    while(1);


  return 0;
}

ISR(INT0_vect)
{
   DIO_vidTogglePinVal(u8PORTA,DIO_u8PIN_0);
}

ISR(INT1_vect)
{
	 DIO_vidTogglePinVal(u8PORTA,DIO_u8PIN_1);
}
