/*
 * ATMEGA32_REGISTERS.h
 *
 *  Created on: Aug 15, 2021
 *      Author: User
 */


#include "STD_TYPES.h"
#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_


typedef union
{
	struct{
		u8 BIT_0 : 1;
		u8 BIT_1 : 1;
		u8 BIT_2 : 1;
		u8 BIT_3 : 1;
		u8 BIT_4 : 1;
		u8 BIT_5 : 1;
		u8 BIT_6 : 1;
		u8 BIT_7 : 1;

	}Bits;
	u8 Whole_Regester;
}tuniReg;

#define SREG_REG        (*(( volatile tuniReg*) (0X5F)))
//DIOA
#define PORTA_REG        (*((volatile u8*)(0x3B)))
#define DDRA_REG         (*((volatile u8*)(0x3A)))
#define PINA_REG         (*((volatile u8*)(0x39)))
//DIOB
#define PORTB_REG       ( *((volatile u8*)(0x38)))
#define DDRB_REG        ( *((volatile u8*)(0x37)))
#define PINB_REG         (*((volatile u8*)(0x36)))
//DIOC
#define PORTC_REG        (*((volatile u8*)(0x35)))
#define DDRC_REG         (*((volatile u8*)(0x34)))
#define PINC_REG         (*((volatile u8*)(0x33)))
//DIOD
#define PORTD_REG       ( *((volatile u8*)(0x32)))
#define DDRD_REG        ( *((volatile u8*)(0x31)))
#define PIND_REG        ( *((volatile u8*)(0x30)))

//External interrupts registers

#define MCUCR_REG  (*(( volatile tuniReg*) (0X55)))
#define GICR_REG   (*(( volatile tuniReg*) (0X5B)))
#define GIFR_REG   (*(( volatile tuniReg*) (0X5A)))


#define ADMUX_REG	(*((volatile tuniReg* )0x27))
#define ADCSRA_REG 	(*((volatile tuniReg* )0x26))
#define ADCH_REG 	(*((volatile tuniReg* )0x25))
#define ADCL_REG	(*((volatile tuniReg* )0x24))






#endif
