/*
 * ADC_Prog.c
 *
 *  Created on: Aug 23, 2021
 *      Author: User
 */
#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "ADC.h"


void ADC_vidInit (void)   //ADC initialization and enable
{
	//ADC enable
    ADCSRA_REG.Bits.u8BIT_7=1;  //ADEN

   //pre-scalar configuration as 128
    ADCSRA_REG.Bits.u8BIT_0=1;  //ADPS0
    ADCSRA_REG.Bits.u8BIT_1=1;  //ADPS1
    ADCSRA_REG.Bits.u8BIT_2=1;  //ADPS2

    //Reference voltage as AVCC with external capacitor
    ADMUX_REG.Bits.u8BIT_7=0;
    ADMUX_REG.Bits.u8BIT_6=1;

    //ADC data right adjustment
    ADMUX_REG.Bits.u8BIT_5=0;


}
u16 ADC_u16Read (u8 channel)  //Read from the ADC channel
{
   u16 Local_Result;
   //ADC channel selection
   ADMUX_REG.u8Whole_Register &= ADC_ADMUX_CHANNEL_CLEAR_MASK; //clear the MUX bits
   ADMUX_REG.u8Whole_Register |= channel;

   //start single conversion
   ADCSRA_REG.Bits.u8BIT_6=1;   //ADSC

   //wait for the conversion
   while(!(ADCSRA_REG.Bits.u8BIT_4));  //while(ADIF ==0)

	   Local_Result = ADCL_REG.u8Whole_Register;
	   Local_Result |= (((u16)ADCH_REG.u8Whole_Register)<<8);

   return Local_Result;

}

