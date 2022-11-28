/*
 * DIO_Prog.c
 *
 *  Created on: Aug 15, 2021
 *      Author: youss
 */

#include "util.h"
#include "types.h"
#include "regiester.h"
#include "DIO_int.h"

u8 DIO_u8GetPin(u8 Copy_PortX, u8 Copy_PinX)
{
	return 0;
}

void DIO_vidSetPinVal(u8 Copy_PortX,u8 Copy_PinX, u8 Copy_Value)
{

	switch(Copy_PortX)
	{
	case PORTA://physical port A
		if(Copy_Value == DIO_u8LOW) // input
		{
			CLR_BIT(PORTA_REG,Copy_PinX);

		}
		else if (Copy_Value == DIO_u8HIGH)// output
		{
			SET_BIT(PORTA_REG,Copy_PinX);

		}
		break;





	case PORTB://physical port b
		if(Copy_Value == DIO_u8LOW) // input
		{
			CLR_BIT(PORTB_REG,Copy_PinX);

		}
		else if (Copy_Value == DIO_u8HIGH)// output
		{
			SET_BIT(PORTB_REG,Copy_PinX);

		}
		break;


	case PORTC://physical port C
		if(Copy_Value == DIO_u8LOW) // input
		{
			CLR_BIT(PORTC_REG,Copy_PinX);

		}
		else if (Copy_Value == DIO_u8HIGH)// output
		{
			SET_BIT(PORTC_REG,Copy_PinX);

		}
		break;



	case PORTD://physical port A
		if(Copy_Value == DIO_u8LOW) // input
		{
			CLR_BIT(PORTD_REG,Copy_PinX);

		}
		else if (Copy_Value == DIO_u8HIGH)// output
		{
			SET_BIT(PORTD_REG,Copy_PinX);

		}
		break;



		/* default:error code to return
		   break;*/
	}


}

void DIO_vidSetPinDirection(u8 Copy_PortX,u8 Copy_PinX, u8 Copy_Direction)
{
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

void DIO_vidTogglePinVal(u8 Copy_PortX, u8 Copy_PinX)
{

}

void DIO_vidSetPortDirection(u8 Copy_PortX, u8 Copy_Direction)
{
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)))
	{
		switch(Copy_PortX)
		{
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
	else
	{
		/* DO Nothing */
	}
}
void DIO_vidSetPortVal(u8 Copy_PortX, u8 Copy_Value)
{
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)))
	{
		switch(Copy_PortX)
		{
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
	else
	{
		/* DO Nothing */
	}
}
