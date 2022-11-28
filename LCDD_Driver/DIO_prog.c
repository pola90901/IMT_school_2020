/*
 * DIO_prog.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Mina Mossa
 */


#include "../LIB/types.h"
#include"../LIB/typedefs.h"
#include"DIO_int.h"
#include"../LIB/ATMEGA32_REGISTERS.h"

u8 DIO_u8GetPin(u8 Copy_PortX, u8 Copy_PinX){
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)) \
			&& ((Copy_PinX == DIO_u8HIGH) || (Copy_PinX == DIO_u8LOW))){
		switch(Copy_PortX)
		{
		case PORTA:
			return GET_BIT(PINA_REG,Copy_PinX);
			break;
		case PORTB:
			return GET_BIT(PINB_REG,Copy_PinX);
			break;
		case PORTC:
			return GET_BIT(PINC_REG,Copy_PinX);
			break;
		case PORTD:
			return GET_BIT(PIND_REG,Copy_PinX);
			break;
		}
	}
	return 0;
};
void DIO_vidSetPinVal(u8 Copy_PortX, u8 Copy_PinX, u8 Copy_Value){
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)) \
			&& ((Copy_Value == DIO_u8HIGH) || (Copy_Value == DIO_u8LOW)))
	{
		if(Copy_Value == DIO_u8LOW)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				CLR_BIT(DDRA_REG,Copy_PinX);
				break;
			case PORTB:
				CLR_BIT(DDRB_REG,Copy_PinX);
				break;
			case PORTC:
				CLR_BIT(DDRC_REG,Copy_PinX);
				break;
			case PORTD:
				CLR_BIT(DDRD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_Value == DIO_u8HIGH)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				SET_BIT(DDRA_REG,Copy_PinX);
				break;
			case PORTB:
				SET_BIT(DDRB_REG,Copy_PinX);
				break;
			case PORTC:
				SET_BIT(DDRC_REG,Copy_PinX);
				break;
			case PORTD:
				SET_BIT(DDRD_REG,Copy_PinX);
				break;
			}
		}
	}
	else
	{
		/*  DO NOTHING  */
	}
};

void DIO_vidSetPinDirection(u8 Copy_PortX, u8 Copy_PinX, u8 Copy_Direction){
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)) \
			&& ((Copy_Direction == DIO_u8INPUT) || (Copy_Direction == DIO_u8OUTPUT)))
	{
		if(Copy_Direction == DIO_u8INPUT)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				CLR_BIT(DDRA_REG,Copy_PinX);
				break;
			case PORTB:
				CLR_BIT(DDRB_REG,Copy_PinX);
				break;
			case PORTC:
				CLR_BIT(DDRC_REG,Copy_PinX);
				break;
			case PORTD:
				CLR_BIT(DDRD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_Direction == DIO_u8OUTPUT)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				SET_BIT(DDRA_REG,Copy_PinX);
				break;
			case PORTB:
				SET_BIT(DDRB_REG,Copy_PinX);
				break;
			case PORTC:
				SET_BIT(DDRC_REG,Copy_PinX);
				break;
			case PORTD:
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
void DIO_vidTogglePinVal(u8 Copy_PortX, u8 Copy_PinX){
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7))){
		switch(Copy_PortX)
		{
		case PORTA:
			TGL_BIT(DDRA_REG,Copy_PinX);
			break;
		case PORTB:
			TGL_BIT(DDRB_REG,Copy_PinX);
			break;
		case PORTC:
			TGL_BIT(DDRC_REG,Copy_PinX);
			break;
		case PORTD:
			TGL_BIT(DDRD_REG,Copy_PinX);
			break;
		}

	}
};
void DIO_vidSetPortDirection(u8 Copy_PortX, u8 Copy_Direction){
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD))){
		switch(Copy_PortX){
		case PORTA:
			DDRA_REG = Copy_Direction;
			break;
		case PORTB:
			DDRB_REG = Copy_Direction;
			break;
		case PORTC:
			DDRC_REG = Copy_Direction;
			break;
		case PORTD:
			DDRD_REG = Copy_Direction;
			break;
		}
	}
};
void DIO_vidSetPortVal(u8 Copy_PortX, u8 Copy_Value){
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD))){
		switch(Copy_PortX){
		case PORTA:
			PORTA_REG = Copy_Value;
			break;
		case PORTB:
			PORTB_REG = Copy_Value;
			break;
		case PORTC:
			PORTC_REG = Copy_Value;
			break;
		case PORTD:
			PORTD_REG = Copy_Value;
			break;
		}
	}
};

