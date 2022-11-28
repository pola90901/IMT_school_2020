/*
 * PWM_int.h
 *
 *  Created on: Aug 25, 2021
 *      Author: youss
 */

#ifndef PWM_INT_H_
#define PWM_INT_H_


#define TIMER_0          0
#define TIMER_1          1
#define TIMER_2          2


/* Clock Sources */

#define PWM_CS0_STOPED                  0X00
#define PWM_CS0_INT_0                   0x01
#define PWM_CS0_INT_8                   0x02
#define PWM_CS0_INT_64                  0x03
#define PWM_CS0_INT_256                 0x04
#define PWM_CS0_INT_1024                0x05


#define PWM_CS1_STOPED                  0X00
#define PWM_CS1_INT_0                   0x01
#define PWM_CS1_INT_8                   0x02
#define PWM_CS1_INT_64                  0x03
#define PWM_CS1_INT_256                 0x04
#define PWM_CS1_INT_1024                0x05


#define PWM_CS_CLEAR_MASK              ~(0x07)

#define PWM_CS0_MODE                    PWM_CS0_INT_256
#define PWM_CS1_MODE                    PWM_CS1_INT_8
#define PWM_ICR1_VALUE                  (u16)20000


void PWM_vidPwmInit(u8 Copy_TimerNo);

void PWM_vidSetPWMDutyCycle(u8 Copy_TimerNo, f32 Copy_DC);

void PWM_StartTimer(u8 Copy_TimerNo);

void PWM_StopTimer(u8 Copy_TimerNo);


#endif /* PWM_INT_H_ */
