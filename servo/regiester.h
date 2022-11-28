/*
 * regiester.h
 *
 *  Created on: ??�/??�/????
 *      Author: pola
 */
//#include"types.h"
#ifndef REGIESTER_H_
#define REGIESTER_H_

#define reg_DDRA *((volatile u8* )0x3A)
#define reg_PORTA *((volatile u8* )0x3B)
#define reg_PINA *((volatile u8* )0x39)

#define reg_DDRB *((volatile u8* )0x37)
#define reg_PORTB *((volatile u8* )0x38)
#define reg_PINB *((volatile u8* )0x36)

#define reg_DDRC *((volatile u8* )0x34)
#define reg_PORTC *((volatile u8* )0x35)
#define reg_PINC *((volatile u8* )0x33)

#define reg_DDRD *((volatile u8* )0x31)
#define reg_PORTD *((volatile u8* )0x32)
#define reg_PIND *((volatile u8* )0x30)

#define reg_SREG *((volatile u8* )0x5F)
#define reg_SPH *((volatile u8* )0x5E)
#define reg_SPL *((volatile u8* )0x5D)
#define reg_OCR0 *((volatile u8* )0x5C)
#define reg_GICR *((volatile u8* )0x5B)
#define reg_GIFR *((volatile u8* )0x5A)
#define reg_TIMSK *((volatile u8* )0x59)
#define reg_TIFR *((volatile u8* )0x58)
#define reg_SPMCR *((volatile u8* )0x57)
#define reg_TWCR *((volatile u8* )0x56)
#define reg_MCUCR *((volatile u8* )0x55)
#define reg_MCUCSR *((volatile u8* )0x54)
#define reg_TCCR0 *((volatile u8* )0x53)
#define reg_TCNT0 *((volatile u8* )0x52)
#define reg_OSCCAL *((volatile u8* )0x51)
#define reg_OSDR *((volatile u8* )0x51)
#define reg_SFIOR *((volatile u8* )0x50)
#define reg_TCCR1A *((volatile u8* )0x4F)
#define reg_TCCR1B *((volatile u8* )0x4E)
#define reg_TCNT1H *((volatile u8* )0x4D)
#define reg_TCNT1L *((volatile u8* )0x4C)
#define reg_OCR1AH *((volatile u8* )0x4B)
#define reg_OCR1AL *((volatile u16* )0x4A)// same larg

#define reg_OCR1BH *((volatile u8* )0x49)
#define reg_OCR1BL *((volatile u8* )0x48)
#define reg_ICR1H *((volatile u8* )0x47)
#define reg_ICR1L *((volatile u16* )0x46)/// to write larg value so it takes the next address as we mke it u16
#define reg_TCCR2 *((volatile u8* )0x45)
#define reg_TCNT2 *((volatile u8* )0x44)
#define reg_OCR2 *((volatile u8* )0x43)
#define reg_ASSR *((volatile u8* )0x42)
#define reg_WDTCR *((volatile u8* )0x41)
#define reg_UBRRH *((volatile u8* )0x40)
#define reg_EEARH *((volatile u8* )0x3F)
#define reg_EEARL *((volatile u8* )0x3E)
#define reg_EEDR *((volatile u8* )0x3D)
#define reg_EECR *((volatile u8* )0x3C)
#define reg_SPDR *((volatile u8* )0x2F)
#define reg_SPSR *((volatile u8* )0x2E)
#define reg_SPCR *((volatile u8* )0x2D)
#define reg_UDR *((volatile u8* )0x2C)
#define reg_UCSRA *((volatile u8* )0x2B)
#define reg_UCSRB *((volatile u8* )0x2A)
#define reg_UBRRL *((volatile u8* )0x29)
#define reg_ACSR *((volatile u8* )0x28)
#define reg_ADMUX *((volatile u8* )0x27)
#define reg_ADCSRA *((volatile u8* )0x26)
#define reg_ADCH *((volatile u8* )0x25)
#define reg_ADCL *((volatile u8* )0x24)
#define reg_TWDR *((volatile u8* )0x23)
#define reg_TWAR *((volatile u8* )0x22)
#define reg_TWSR *((volatile u8* )0x21)
#define reg_TWBR *((volatile u8* )0x20)
#endif /* REGIESTER_H_ */
