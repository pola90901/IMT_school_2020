/*
 * GPT_prog.c
 *
 *  Created on: Aug 24, 2021
 *      Author: User
 */

#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO_int.h"
#include "ADC.h"
#include "GPT.h"
#include "avr/interrupt.h"
pFunc Internal_CBF[2];
void GPT_vidInit( )  //initialization of timer //general purpose timer
{

#if GPT_MODE == NORMAL  // normal=interval timer

	TCCR0_REG.Bits.u8BIT_3=0;    //set bit 3 to 0
	TCCR0_REG.Bits.u8BIT_6=0;  //set bit 6 to 0
#elif GPT_MODE == CTC   //ctc= clear timer on comparison match
	TCCR0_REG.Bits.u8BIT_3=1;       //set bit 3 to 1
		TCCR0_REG.Bits.u8BIT_6=0;      //set bit 6 to 0
		TCCR0_REG.u8WholeRegister &=OC0_MODE_CLEAR_MASK ;  //clear mask for OC0 mode
		TCCR0_REG.u8WholeRegister |=OC0_MODE;//Oring with the mode to get its real value
		if(OCR0_VALUE<= 255)
OCR0_REG.u8WholeRegister = OCR0_VALUE;
#endif

}

void GPT_vidStopTimer()  //function to stop the timer
{

  TCCR0_REG.u8Whole_Register &= 0xF8;  //0x11111000



}
void GPT_vidStartTimer()   //function to start the timer
{

	TCCR0_REG.u8Whole_Register &= CS_CLEAR_MASK;
	TCCR0_REG.u8Whole_Register |= CS_MODE;

}

void GPT_vidLoadTimer(u16 Copy_u8preload)       //preload value
{
	TCNT0_REG.u8Whole_Register= Copy_u8preload;

}
void GPT_vidEnableNotification(void) //enable interrupt
{
#if GPT_MODE ==NORMAL                   //TOV0: Timer/Counter0 Overflow Flag =1
	TIMSK_REG.Bits.u8BIT_0=1;
#elif GPT_MODE == CTC                   //OCF0: Output Compare Flag 0 =0
	TIMSK_REG.Bits.u8BIT_1=1;
#endif
}


void GPT_vidDisableNotification(void)  //disable interrupt
{

#if GPT_MODE ==NORMAL                                //TOV0: Timer/Counter0 Overflow Flag =1
	TIMSK_REG.Bits.u8BIT_0=0;
#elif GPT_MODE == CTC                              //OCF0: Output Compare Flag 0 =0
	TIMSK_REG.Bits.u8BIT_1=0;
#endif
}

void GPT_vidSetCallBackFunction (pFunc CBF, u8 InterruptID)
{
if(CBF)
{
	Internal_CBF[InterruptID]= CBF;
}


}

ISR(TIMER0_OVF_vect)
{
	if(Internal_CBF[0])
	{
		Internal_CBF[0]();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(Internal_CBF[1])
	{
		Internal_CBF[1]();
	}
}

