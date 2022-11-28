/*
 * ATMEGA32_REGISTERS.h
 *
 *  Created on: Aug 15, 2021
 *      Author: User
 */



#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

typedef union{

	struct{
	u8 u8BIT_0 : 1;
	u8 u8BIT_1 : 1;
	u8 u8BIT_2 : 1;
	u8 u8BIT_3 : 1;
	u8 u8BIT_4 : 1;
	u8 u8BIT_5 : 1;
	u8 u8BIT_6 : 1;
	u8 u8BIT_7 : 1;

}Bits;
u8 u8Whole_Register;
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

//ADC Registers

#define ADMUX_REG (*((volatile tuniReg* )0x27))  //ADC Multiplexer register
#define ADCSRA_REG   (*((volatile tuniReg* )0x26))  //ADC Control and status register
#define ADCH_REG     (*((volatile tuniReg* )0x25))   //ADC High register
#define ADCL_REG	(*((volatile tuniReg* )0x24))   //ADC LOW register

//Timer registers

#define OCR0_REG  (*((volatile tuniReg* )0x5C))
#define TIMSK_REG   (*((volatile tuniReg* )0x59))
#define TCCR0_REG   (*((volatile tuniReg* )0x53))
#define TCNT0_REG   (*((volatile tuniReg* )0x52))

#define TCCR1A_REG (*((volatile tuniReg* )0x4F))
#define TCCR1B_REG (*((volatile tuniReg* )0x4E))
#define TCNT1_REG (*((volatile u16* )0x4C))
#define OCR1A_REG (*((volatile u16* )0x4A))
#define OCR1B_REG (*((volatile u16* )0x48))
#define ICR1_REG (*((volatile u16* )0x46))


#endif
