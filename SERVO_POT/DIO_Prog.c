/*
 * DIO_Prog.c
 *
 *  Created on: Aug 15, 2021
 *      Author: User
 */


#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO_int.h"

u8 DIO_u8GetPin(u8 Copy_PortX , u8  Copy_PinX )
{
	u8 var=0;
	if(((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD)) && ((Copy_PinX >= DIO_u8_PIN_0) && (Copy_PinX <= DIO_u8_PIN_7)))
		 {
		         switch(Copy_PortX)
					{
					case u8PORTA:
						var=GET_BIT(PINA_REG ,Copy_PinX);
						break;
					case u8PORTB:
						var=GET_BIT(PINB_REG ,Copy_PinX);
						break;
					case u8PORTC:
						var=GET_BIT(PINC_REG ,Copy_PinX);
						break;
					case u8PORTD:
						var=GET_BIT(PIND_REG ,Copy_PinX);
						break;
					}
		 }

	return var;

}
void DIO_vidSetPinVal( u8 Copy_PortX , u8 Copy_PinX , u8 copy_value)

{

	if(((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD)) && ((Copy_PinX >= DIO_u8_PIN_0 ) && (Copy_PinX <= DIO_u8_PIN_7 )) \
			&& ((copy_value == DIO_u8HIGH) || (copy_value == DIO_u8LOW)))
	{
		if (copy_value==DIO_u8HIGH)
		{
			switch(Copy_PortX)
			{
			case u8PORTA:
				SET_BIT(PORTA_REG,Copy_PinX);
				break;
			case u8PORTB:
				SET_BIT(PORTB_REG,Copy_PinX);
				break;
			case u8PORTC:
				SET_BIT(PORTC_REG,Copy_PinX);
				break;
			case u8PORTD:
				SET_BIT(PORTD_REG,Copy_PinX);
				break;

			}
		}
			else if(copy_value == DIO_u8LOW)
			{

				switch(Copy_PortX)
				{
				case u8PORTA:
					CLR_BIT(PORTA_REG,Copy_PinX);
					break;
				case u8PORTB:
					CLR_BIT(PORTB_REG,Copy_PinX);
					break;
				case u8PORTC:
					CLR_BIT(PORTC_REG,Copy_PinX);
					break;
				case u8PORTD:
					CLR_BIT(PORTD_REG,Copy_PinX);
					break;

				}


			}

		}

}
void DIO_vidSetPinDirection(u8 Copy_PortX,u8 Copy_PinX, u8 Copy_Direction)
{
	if(((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD)) && ((Copy_PinX >= DIO_u8_PIN_0) && (Copy_PinX <= DIO_u8_PIN_7)) \
			&& ((Copy_Direction == DIO_u8INPUT) || (Copy_Direction == DIO_u8OUTPUT)))
	{
		if(Copy_Direction == DIO_u8INPUT)
		{
			switch(Copy_PortX)
			{
			case u8PORTA:
				CLR_BIT(DDRA_REG,Copy_PinX);
				break;

			case u8PORTB:
				CLR_BIT(DDRB_REG,Copy_PinX);
				break;

			case u8PORTC:
				CLR_BIT(DDRC_REG,Copy_PinX);
				break;

			case u8PORTD:
				CLR_BIT(DDRD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_Direction == DIO_u8OUTPUT)
		{
			switch(Copy_PortX)
			{
			case u8PORTA:
				SET_BIT(DDRA_REG,Copy_PinX);
				break;
			case u8PORTB:
				SET_BIT(DDRB_REG,Copy_PinX);
				break;
			case u8PORTC:
				SET_BIT(DDRC_REG,Copy_PinX);
				break;
			case u8PORTD:
				SET_BIT(DDRD_REG,Copy_PinX);
				break;
			}
		}

	}

}
void DIO_vidSetPortDirection(u8 Copy_Portx, u8 Copy_Direction)
 {
	 if(((Copy_Portx >= u8PORTA) && (Copy_Portx <= u8PORTD)))
	 {
		  switch(Copy_Portx)
		  {
		  case u8PORTA:
			  DDRA_REG = Copy_Direction;
			  break;
		  case u8PORTB:
			  DDRB_REG = Copy_Direction;
			  break;
		  case u8PORTC:
			  DDRC_REG = Copy_Direction;
			  break;
		  case u8PORTD:
			  DDRD_REG = Copy_Direction;
			  break;
		  }
	 }
 }
void DIO_vidSetPortVal( u8 Copy_Portx, u8 Copy_Value)
{
	 if((Copy_Portx>= u8PORTA) && (Copy_Portx <= u8PORTD))
	 {

		 switch(Copy_Portx)
				  {
				  case u8PORTA:
					  PORTA_REG = Copy_Value;
					  break;

				  case u8PORTB:
					  PORTB_REG = Copy_Value;
					  break;

				  case u8PORTC:
					  PORTC_REG = Copy_Value;
					  break;

				  case u8PORTD:
					  PORTD_REG = Copy_Value;
					  break;
				  }

	 }


}
void DIO_vidTogglePinVal( u8 Copy_PortX, u8 Copy_PinX)
{


	if(((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD)) && ((Copy_PinX >= DIO_u8_PIN_0) && (Copy_PinX <= DIO_u8_PIN_7)))
			 {
			         switch(Copy_PortX)
						{
						case u8PORTA:
							TGL_BIT( PORTA_REG ,Copy_PinX);
							break;
						case u8PORTB:
							TGL_BIT( PORTB_REG ,Copy_PinX);
							break;
						case u8PORTC:
							TGL_BIT( PORTC_REG ,Copy_PinX);
							break;
						case u8PORTD:
							TGL_BIT( PORTD_REG ,Copy_PinX);
							break;
						}
			 }



}


