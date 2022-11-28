/*
 * DIO_prog.c
 *
 *  Created on: Aug 15, 2021
 *      Author: hp
 */

#include "ATMEGA32_REGISTERS.h"
#include "types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"



u8 DIO_U8GetPin(u8 Copy_PortX, u8 Copy_PinX)
{
	u8 PinLevel;
	if(((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7))){
		switch(Copy_PortX){
		case u8PORTA:
			PinLevel = GET_BIT(PINA_REG,Copy_PinX);
			break;
		case u8PORTB:
			PinLevel = GET_BIT(PINB_REG,Copy_PinX);
			break;
		case u8PORTC:
			PinLevel = GET_BIT(PINC_REG,Copy_PinX);
			break;
		case u8PORTD:
			PinLevel = GET_BIT(PIND_REG,Copy_PinX);
			break;
		}

	}
	return PinLevel;
}



void DIO_vidSetPinVal(u8 Copy_PortX,u8 Copy_PinX,u8 Copy_Value)
{
	if((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)))
	{
		if(Copy_Value == DIO_u8LOW)
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
		else if(Copy_Value== DIO_u8HIGH)
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
		else
		{

		}
	}
}
	void DIO_vidTogglePinVal(u8 Copy_PortX,u8 Copy_PinX)
	{
		if((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)))
			{
		  	switch(Copy_PortX)
					{
					case u8PORTA:
						TGL_BIT(PORTA_REG,Copy_PinX);
						break;
					case u8PORTB:
						TGL_BIT(PORTB_REG,Copy_PinX);
						break;
					case u8PORTC:
						TGL_BIT(PORTC_REG,Copy_PinX);
						break;
					case u8PORTD:
						TGL_BIT(PORTD_REG,Copy_PinX);
						break;
					}
				}
		else
		{

		}

	}

	void DIO_vidSetPinDirection(u8 Copy_PortX,u8 Copy_PinX,u8 Copy_Direction)
	{
		if(((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)) \
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
		else
		{
			/*  DO NOTHING  */
		}
	}

	void DIO_vidSetPortDirection(u8 Copy_PortX,u8 Copy_Direction)
	{
		if((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD))
		{
			switch(Copy_PortX)
			{
			case u8PORTA:
				DDRA_REG =Copy_Direction;
				break;
			case u8PORTB:
				DDRB_REG =Copy_Direction;
				break;
			case u8PORTC:
				DDRC_REG =Copy_Direction;
				break;
			case u8PORTD:
				DDRD_REG =Copy_Direction;
				break;
			}
		}
		else
		{

		}
	}

	void DIO_vidSetPortVal(u8 Copy_PortX,u8 Copy_Value)
	{
		if((Copy_PortX >= u8PORTA) && (Copy_PortX <= u8PORTD))
		{
			switch(Copy_PortX)
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
		else
		{

		}
	}
