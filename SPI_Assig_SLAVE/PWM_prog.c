/*
 * PWM_prog.c
 *
 *  Created on: Aug 25, 2021
 *      Author: youss
 */



#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "PWM_int.h"



void PWM_vidPwmInit(u8 Copy_TimerNo)
{
	switch(Copy_TimerNo)
	{
	case TIMER_0:
		TCCR0_REG.Bits.BIT_3=1;
		TCCR0_REG.Bits.BIT_6=1;
		break;
	case TIMER_1:
		TCCR1A_REG.Bits.BIT_7 = 1;
		TCCR1A_REG.Bits.BIT_6 = 0;
		TCCR1A_REG.Bits.BIT_5 = 0;
		TCCR1A_REG.Bits.BIT_4 = 0;
		/****************************/

		TCCR1A_REG.Bits.BIT_0 = 0;
		TCCR1A_REG.Bits.BIT_1 = 1;

		TCCR1B_REG.Bits.BIT_3 = 1;
		TCCR1B_REG.Bits.BIT_4 = 1;

		/***************************/

		ICR1_REG = PWM_ICR1_VALUE;
		break;
	case TIMER_2:

		break;
	}
}

void PWM_vidSetPWMDutyCycle(u8 Copy_TimerNo, f32 Copy_DC)
{
	switch(Copy_TimerNo)
	{
	case TIMER_0:
		OCR0_REG.Whole_Regester = (u8)(((f32)Copy_DC *((f32)256))/100);
		break;
	case TIMER_1:
		OCR1A_REG = (u16)(((f32)Copy_DC *((f32)PWM_ICR1_VALUE))/(100));
		break;
	case TIMER_2:

		break;
	}
}

void PWM_StartTimer(u8 Copy_TimerNo)
{
	switch(Copy_TimerNo)
	{
	case TIMER_0:
		TCCR0_REG.Whole_Regester &= PWM_CS_CLEAR_MASK;
		TCCR0_REG.Whole_Regester |= PWM_CS0_MODE;
		break;
	case TIMER_1:
		TCCR1B_REG.Whole_Regester &= PWM_CS_CLEAR_MASK;
		TCCR1B_REG.Whole_Regester |= PWM_CS1_MODE;
		break;
	}
}

void PWM_StopTimer(u8 Copy_TimerNo)
{
	switch(Copy_TimerNo)
	{
	case TIMER_0:
		TCCR0_REG.Whole_Regester  &= 0xF8;
		break;
	case TIMER_1:
		TCCR1B_REG.Whole_Regester &= 0xF8;
		break;
	}
}

