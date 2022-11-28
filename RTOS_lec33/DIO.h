/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ENG. Ezzat EL-Shafey
 */

#ifndef DIO_H_
#define DIO_H_

#include "_TYPES_H_.h"

#define PH_PORTA 1
#define PH_PORTB 2
#define PH_PORTC 3
#define PH_PORTD 4

#define INPUT_DIRECTION 0
#define OUTPUT_DIRECTION 1
#define LOW_LEVEL 0
#define HIGH_LEVEL 1
#define INPUT_PORT_DIRECTION 0
#define OUTPUT_PORT_DIRECTION 255
#define LOW_PORT_LEVEL 0
#define HIGH_PORT_LEVEL 255

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7


void DIO_SET_PIN_DIRECTION(u8 PH_PORT_ID, u8 PH_PIN_ID, u8 DIRECTION);
void DIO_WRITE_PIN(u8 PH_PORT_ID, u8 PH_PIN_ID, u8 LEVEL);
u8 DIO_READ_PIN(u8 PH_PORT_ID, u8 PH_PIN_ID);
void DIO_SET_PORT_DIRECTION(u8 PH_PORT_ID,u8 DIRECTION);
void DIO_WRITE_PORT(u8 PH_PORT_ID, u8 LEVEL);
u8 DIO_READ_PORT(u8 PH_PORT_ID);
void DIO_ACTIVATE_PIN_PULL_UP_RESISTOR(u8 PH_PORT_ID, u8 PH_PIN_ID);
void DIO_ACTIVATE_PORT_PULL_UP_RESISTOR(u8 PH_PORT_ID);
void DIO_TOGGLE_PIN(u8 PH_PORT_ID, u8 PH_PIN_ID);
void DIO_TOGGLE_PORT(u8 PH_PORT_ID);

#endif /* DIO_H_ */



