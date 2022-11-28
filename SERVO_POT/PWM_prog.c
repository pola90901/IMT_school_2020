/*
 * PWM_prog.c
 *
 *  Created on: Aug 25, 2021
 *      Author: User
 */


#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO_int.h"
#include <avr/interrupt.h>
#include "EXTI.h"
#include "ADC.h"
#include "PWM_int.h"



void PWM_vidPWMInit (u8 Copy_TimerNo)
{

	switch(Copy_TimerNo)
	{

	case TIMER0:                      //until it reaches the overflow  //fast pwm
		TCCR0_REG.Bits.u8BIT_3 =1;
		TCCR0_REG.Bits.u8BIT_6 =1;
		break;
	case TIMER1:                       //until it reaches the ICR1
		TCCR1A_REG.Bits.u8BIT_7=1;   //clear OC1A on compare match
		TCCR1A_REG.Bits.u8BIT_6=0;
		TCCR1A_REG.Bits.u8BIT_5=0;  //OC1B disconnected
		TCCR1A_REG.Bits.u8BIT_4=0;

		TCCR1A_REG.Bits.u8BIT_0=0;  //OCR1 at top //WGM
		TCCR1A_REG.Bits.u8BIT_1=1;
		TCCR1B_REG.Bits.u8BIT_3=1;
		TCCR1B_REG.Bits.u8BIT_4=1;
		ICR1_REG = PWM_ICR1_VALUE;  //ICR1 value after calculations
		break;

	case TIMER2:
		break;

	}

}

void PWM_vidSetPWMDutyCycle( u8 Copy_TimerNo, f32 Copy_DC) // OCR= (Duty cycle*ICR1)/100
{
	switch(Copy_TimerNo)
	{

	case TIMER0:  //TOP is the OVF which is 256

		OCR0_REG.u8Whole_Register= (u8)(((f32)Copy_DC*((f32)256))/100);

			break;
	case TIMER1:  //Top is the value of ICR1
		OCR1A_REG= (u16)(((f32)Copy_DC*((f32)PWM_ICR1_VALUE))/100);

		break;
	case TIMER2:
		break;
	}

}

void PWM_StartTimer(u8 Copy_TimerNo)
{
	 switch(Copy_TimerNo)
		  {
		  case TIMER0:
			  TCCR0_REG.u8Whole_Register &= PWM_CS_CLEAR_MASK;  //clear mask
			  TCCR0_REG.u8Whole_Register |= PWM_CS0_MODE;  //oring with the value of CS0
			  break;
		  case TIMER1:
			  TCCR1B_REG.u8Whole_Register &= PWM_CS_CLEAR_MASK; //clear mask
			  TCCR1B_REG.u8Whole_Register |= PWM_CS1_MODE;    //oring with the value of CS1
			  break;
		  }
}
void PWM_StopTimer(u8 Copy_TimerNo)
{
	 switch(Copy_TimerNo)
	  {
	  case TIMER0:
		  TCCR0_REG.u8Whole_Register &= 0xF8;  //clock select for bits 1,2,3 =0 (1111 1000) to stop timer0
		  break;
	  case TIMER1:
		  TCCR1B_REG.u8Whole_Register &= 0xF8;   //clock select for bits 1,2,3 =0 (1111 1000) to stop timer1
		  break;
	  }




}
