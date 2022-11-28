/*
 * ADC_prog.c
 *
 *  Created on: Aug 22, 2021
 *      Author: youss
 */


#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "ADC.h"


void ADC_Init (void)    // ADC Initialization And Enable
{
	// ADC Enable
	ADCSRA_REG.Bits.BIT_7 = 1;

	// Pre-scaler Configuration as 128
	ADCSRA_REG.Bits.BIT_0=1;
	ADCSRA_REG.Bits.BIT_1=1;
	ADCSRA_REG.Bits.BIT_2=1;

	// Reference Voltage as AVCC with external capacitor
	ADMUX_REG.Bits.BIT_7=0;
	ADMUX_REG.Bits.BIT_6=0;

	// ADC Data Right Adjustment
	ADMUX_REG.Bits.BIT_5=0;

}
u16 ADC_Read (u8 channel)     // Read From The ADC Channel
{
	u16 Local_Result;
	// ADC Channel Selection
	ADMUX_REG.Whole_Regester &= ADC_ADMUX_CHANNEL_CLEAR_MASK;
	ADMUX_REG.Whole_Regester |= channel;

	// Start Single Conversion
	ADCSRA_REG.Bits.BIT_6=1;

	//wait for the conversion
	while((ADCSRA_REG.Bits.BIT_6));

	Local_Result = ADCL_REG.Whole_Regester;
	Local_Result |=(((u16)ADCH_REG.Whole_Regester)<<8);

	return Local_Result;
}
