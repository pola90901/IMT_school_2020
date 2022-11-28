/*
 * GPT.h
 *
 *  Created on: Aug 24, 2021
 *      Author: User
 */

#ifndef GPT_H_
#define GPT_H_

//clock sources
#define CS_STOPPED                  0X00
#define CS_INT_0                    0X01
#define CS_INT_8                    0X02
#define CS_INT_64                   0X03
#define CS_INT_256                  0X04
#define CS_INT_1024                 0X05
#define CS_EXT_FALLING_EDGE         0X06
#define CS_EXT_RISING_EDGE          0X07
#define CS_CLEAR_MASK             ~(0X07)

#define CTC                           0
#define NORMAL                        1          //overflow mood
#define GPT_MODE                    NORMAL

//OC0 MODES
#define OC0_DISCONNECTED                   0
#define OC0_TOGGLE                      0X10
#define OC0_CLEAR                       0X20
#define OC0_SET                         0X30

#define OC0_MODE                   OC0_TOGGLE
#define OC0_MODE_CLEAR_MASK         ~(0X30)

#define OCR0_VALUE                    200
//Interrupt IDs
#define OVF_INTERRUPT    0
#define CTC_INTERRUPT    0

#define CS_MODE                   CS_INT_8
void GPT_vidInit( );
void GPT_vidStartTimer();
 void GPT_vidStopTimer();
void GPT_vidLoadTimer(u16 Copy_u8preload);
void GPT_vidEnableNotification(void);
void GPT_vidDisableNotification(void);
void GPT_vidSetCallBackFunction (pFunc CBF,u8 InterruptID);

#endif /* GPT_H_ */
