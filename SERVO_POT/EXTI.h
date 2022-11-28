/*
 * EXTI.h
 *
 *  Created on: Aug 22, 2021
 *      Author: User
 */

#ifndef EXTI_H_
#define EXTI_H_

#define INT1_SC_LOW_LEVEL    0x00
#define INT1_SC_IOC         0b00000100
#define INT1_SC_FALLING_EDGE   0X08
#define INT1_SC_RISING_EDGE   0x0C

#define INT0_SC_LOW_LEVEL    0x00
#define INT0_SC_IOC         0x01
#define INT0_SC_FALLING_EDGE   0X02
#define INT0_SC_RISING_EDGE   0x03

#define INT1_SC_CLEAR_MASK 0b11110011
#define INT0_SC_CLEAR_MASK 0b11111100

#define INT1_SC_MODE INT1_SC_LOW_LEVEL
#define INT0_SC_MODE  INT0_SC_IOC


void EXTI_vidEnable_Interrupt ( u8 Copy_IntNumb);
void EXTI_vidDisable_Interrupt ( u8 Copy_IntNumb);
void EXTI_vidInit(void);
void EXTI_vidSetCallBackFunction( pFunc CBF,u8 Copy_IntNumb);

#endif /* EXTI_H_ */
