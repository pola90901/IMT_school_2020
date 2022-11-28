/*
 * PWM_int.h
 *
 *  Created on: Aug 25, 2021
 *      Author: User
 */

#ifndef PWM_INT_H_
#define PWM_INT_H_

#define TIMER0    0
#define TIMER1    1
#define TIMER2    2

#define PWM_CS0_STOPPED                  0X00
#define PWM_CS0_INT_0                    0X01
#define PWM_CS0_INT_8                    0X02
#define PWM_CS0_INT_64                   0X03
#define PWM_CS0_INT_256                  0X04
#define PWM_CS0_INT_1024                 0X05

#define PWM_CS1_STOPPED                  0X00
#define PWM_CS1_INT_0                    0X01
#define PWM_CS1_INT_8                    0X02
#define PWM_CS1_INT_64                   0X03
#define PWM_CS1_INT_256                  0X04
#define PWM_CS1_INT_1024                 0X05

#define PWM_CS_CLEAR_MASK          ~(0x07)

#define PWM_CS0_MODE     PWM_CS0_INT_256
#define PWM_ICR1_VALUE    ( u16) 2500
#define PWM_CS1_MODE      PWM_CS1_INT_64



void PWM_vidPWMInit (u8 Copy_TimerNo);
void PWM_vidSetPWMDutyCycle( u8 Copy_TimerNo, f32 Copy_DC);
void PWM_StartTimer(u8 Copy_TimerNo);
void PWM_StopTimer(u8 Copy_TimerNo);

#endif /* PWM_INT_H_ */
