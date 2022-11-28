/*
 * DIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ENG. Ezzat EL-Shafey
 */
#include "DIO.h"
#include "util.h"
#include "register.h"
#include "_TYPES_H_.h"

void DIO_SET_PIN_DIRECTION(u8 PH_PORT_ID, u8 PH_PIN_ID, u8 DIRECTION)
{
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
		if(DIRECTION == INPUT_DIRECTION)  // direction is input
		{
			CLEAR_BIT(REG_DDRA,PH_PIN_ID);
		}
		else if(DIRECTION == OUTPUT_DIRECTION)  //direction is output
		{
			SET_BIT(REG_DDRA,PH_PIN_ID);
		}
		break;
	case PH_PORTB:// physical PORTB
		if(DIRECTION == INPUT_DIRECTION)  // direction is input
		{
			CLEAR_BIT(REG_DDRB,PH_PIN_ID);
		}
		else if(DIRECTION == OUTPUT_DIRECTION)  //direction is output
		{
			SET_BIT(REG_DDRB,PH_PIN_ID);
		}
		break;
	case PH_PORTC:// physical PORTC
		if(DIRECTION == INPUT_DIRECTION)  // direction is input
		{
			CLEAR_BIT(REG_DDRC,PH_PIN_ID);
		}
		else if(DIRECTION == OUTPUT_DIRECTION)  //direction is output
		{
			SET_BIT(REG_DDRC,PH_PIN_ID);
		}
		break;
	case PH_PORTD:   // physical PORTD
		if(DIRECTION == INPUT_DIRECTION)  // direction is input
		{
			CLEAR_BIT(REG_DDRD,PH_PIN_ID);
		}
		else if(DIRECTION == OUTPUT_DIRECTION)  //direction is output
		{
			SET_BIT(REG_DDRD,PH_PIN_ID);
		}
		break;
	}
}


void DIO_WRITE_PIN(u8 PH_PORT_ID, u8 PH_PIN_ID, u8 LEVEL)
{
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
		if(LEVEL == LOW_LEVEL)  //  LOW
		{
			CLEAR_BIT(REG_PORTA,PH_PIN_ID);
		}
		else if(LEVEL == HIGH_LEVEL)  // high
		{
			SET_BIT(REG_PORTA,PH_PIN_ID);
		}
		break;
	case PH_PORTB:// physical PORTB
		if(LEVEL == LOW_LEVEL)  //  LOW
		{
			CLEAR_BIT(REG_PORTB,PH_PIN_ID);
		}
		else if(LEVEL == HIGH_LEVEL)  // high
		{
			SET_BIT(REG_PORTB,PH_PIN_ID);
		}
		break;
	case PH_PORTC:// physical PORTC
		if(LEVEL == LOW_LEVEL)  //  LOW
		{
			CLEAR_BIT(REG_PORTC,PH_PIN_ID);
		}
		else if(LEVEL == HIGH_LEVEL)  // high
		{
			SET_BIT(REG_PORTC,PH_PIN_ID);
		}
		break;
	case PH_PORTD:   // physical PORTD
		if(LEVEL == LOW_LEVEL)  // LOW
		{
			CLEAR_BIT(REG_PORTD,PH_PIN_ID);
		}
		else if(LEVEL == HIGH_LEVEL)  // high
		{
			SET_BIT(REG_PORTD,PH_PIN_ID);
		}
		break;
	}
}

u8 DIO_READ_PIN(u8 PH_PORT_ID, u8 PH_PIN_ID)
{
	u8 pin_level;
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
		pin_level = GET_BIT(REG_PINA,PH_PIN_ID);

		break;
	case PH_PORTB:// physical PORTB
		pin_level = GET_BIT(REG_PINB,PH_PIN_ID);
		break;
	case PH_PORTC:// physical PORTC
		pin_level = GET_BIT(REG_PINC,PH_PIN_ID);
		break;
	case PH_PORTD:   // physical PORTD
		pin_level = GET_BIT(REG_PIND,PH_PIN_ID);
		break;
	}
	return pin_level;
}

void DIO_SET_PORT_DIRECTION(u8 PH_PORT_ID, u8 DIRECTION)
{
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
		if(DIRECTION == INPUT_DIRECTION)  // direction is input
		{
			WRITE_BYTE(REG_DDRA,INPUT_PORT_DIRECTION);
		}
		else if(DIRECTION == OUTPUT_DIRECTION)  //direction is output
		{
			WRITE_BYTE(REG_DDRA,OUTPUT_PORT_DIRECTION);
		}
		break;
	case PH_PORTB:// physical PORTB
		if(DIRECTION == INPUT_DIRECTION)  // direction is input
		{
			WRITE_BYTE(REG_DDRB,INPUT_PORT_DIRECTION);
		}
		else if(DIRECTION == OUTPUT_DIRECTION)  //direction is output
		{
			WRITE_BYTE(REG_DDRB,OUTPUT_PORT_DIRECTION);
		}
		break;
	case PH_PORTC:// physical PORTC
		if(DIRECTION == INPUT_DIRECTION)  // direction is input
		{
			WRITE_BYTE(REG_DDRC,INPUT_PORT_DIRECTION);
		}
		else if(DIRECTION == OUTPUT_DIRECTION)  //direction is output
		{
			WRITE_BYTE(REG_DDRC,OUTPUT_PORT_DIRECTION);
		}
		break;
	case PH_PORTD:   // physical PORTD
		if(DIRECTION == INPUT_DIRECTION)  // direction is input
		{
			WRITE_BYTE(REG_DDRD,INPUT_PORT_DIRECTION);
		}
		else if(DIRECTION == OUTPUT_DIRECTION)  //direction is output
		{
			WRITE_BYTE(REG_DDRD,OUTPUT_PORT_DIRECTION);
		}
		break;
	}
}

void DIO_WRITE_PORT(u8 PH_PORT_ID, u8 data)
{
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
			WRITE_BYTE(REG_PORTA,data);
		break;
	case PH_PORTB:// physical PORTB
			WRITE_BYTE(REG_PORTB,data);
		break;
	case PH_PORTC:// physical PORTC
			WRITE_BYTE(REG_PORTC,data);
		break;
	case PH_PORTD:   // physical PORTD
			WRITE_BYTE(REG_PORTD,data);
		break;
	}
}

u8 DIO_READ_PORT(u8 PH_PORT_ID)
{
	u8 port_level;
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
		port_level = READ_BYTE(REG_PINA);

		break;
	case PH_PORTB:// physical PORTB
		port_level = READ_BYTE(REG_PINB);
		break;
	case PH_PORTC:// physical PORTC
		port_level = READ_BYTE(REG_PINC);
		break;
	case PH_PORTD:   // physical PORTD
		port_level = READ_BYTE(REG_PIND);
		break;
	}
	return port_level;
}

void DIO_ACTIVATE_PIN_PULL_UP_RESISTOR(u8 PH_PORT_ID, u8 PH_PIN_ID)
{
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
		CLEAR_BIT(REG_DDRA,PH_PIN_ID);
		CLEAR_BIT(REG_SFIOR,2);
		SET_BIT(REG_PORTA,PH_PIN_ID);
		break;
	case PH_PORTB:// physical PORTB
		CLEAR_BIT(REG_DDRB,PH_PIN_ID);
		CLEAR_BIT(REG_SFIOR,2);
		SET_BIT(REG_PORTB,PH_PIN_ID);
		break;
	case PH_PORTC:// physical PORTC
		CLEAR_BIT(REG_DDRC,PH_PIN_ID);
		CLEAR_BIT(REG_SFIOR,2);
		SET_BIT(REG_PORTC,PH_PIN_ID);
		break;
	case PH_PORTD:   // physical PORTD
		CLEAR_BIT(REG_DDRD,PH_PIN_ID);
		CLEAR_BIT(REG_SFIOR,2);
		SET_BIT(REG_PORTD,PH_PIN_ID);
		break;
	}
}

void DIO_ACTIVATE_PORT_PULL_UP_RESISTOR(u8 PH_PORT_ID)
{
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
		WRITE_BYTE(REG_DDRA,INPUT_PORT_DIRECTION);
		CLEAR_BIT(REG_SFIOR,2);
		WRITE_BYTE(REG_PORTA,HIGH_PORT_LEVEL);
		break;
	case PH_PORTB:// physical PORTB
		WRITE_BYTE(REG_DDRB,INPUT_PORT_DIRECTION);
		CLEAR_BIT(REG_SFIOR,2);
		WRITE_BYTE(REG_PORTB,HIGH_PORT_LEVEL);
		break;
	case PH_PORTC:// physical PORTC
		WRITE_BYTE(REG_DDRC,INPUT_PORT_DIRECTION);
		CLEAR_BIT(REG_SFIOR,2);
		WRITE_BYTE(REG_PORTC,HIGH_PORT_LEVEL);
		break;
	case PH_PORTD:   // physical PORTD
		WRITE_BYTE(REG_DDRD,INPUT_PORT_DIRECTION);
		CLEAR_BIT(REG_SFIOR,2);
		WRITE_BYTE(REG_PORTD,HIGH_PORT_LEVEL);
		break;
	}
}

void DIO_TOGGLE_PIN(u8 PH_PORT_ID, u8 PH_PIN_ID)
{
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
		TOGGLE_BIT(REG_PORTA,PH_PIN_ID);
		break;
	case PH_PORTB:// physical PORTB
		TOGGLE_BIT(REG_PORTB,PH_PIN_ID);
		break;
	case PH_PORTC:// physical PORTC
		TOGGLE_BIT(REG_PORTC,PH_PIN_ID);
		break;
	case PH_PORTD:   // physical PORTD
		TOGGLE_BIT(REG_PORTD,PH_PIN_ID);
		break;
	}
}

void DIO_TOGGLE_PORT(u8 PH_PORT_ID)
{
	switch(PH_PORT_ID)
	{
	case PH_PORTA:// physical PORTA
		TOGGLE_BYTE(REG_PORTA);
		break;
	case PH_PORTB:// physical PORTB
		TOGGLE_BYTE(REG_PORTB);
		break;
	case PH_PORTC:// physical PORTC
		TOGGLE_BYTE(REG_PORTC);
		break;
	case PH_PORTD:   // physical PORTD
		TOGGLE_BYTE(REG_PORTD);
		break;
	}
}

