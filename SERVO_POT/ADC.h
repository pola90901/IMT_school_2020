/*
 * ADC.h
 *
 *  Created on: Aug 23, 2021
 *      Author: User
 */

#ifndef ADC_H_
#define ADC_H_


#define ADC_ADMUX_CHANNEL_CLEAR_MASK  ~(0x1F)
#define ADC_ADMUX_CHANNEL_ADC0  0x00
#define ADC_ADMUX_CHANNEL_ADC1  0x01
#define ADC_ADMUX_CHANNEL_ADC2  0x02
#define ADC_ADMUX_CHANNEL_ADC3  0x03
#define ADC_ADMUX_CHANNEL_ADC4  0x04
#define ADC_ADMUX_CHANNEL_ADC5  0x05
#define ADC_ADMUX_CHANNEL_ADC6  0x06
#define ADC_ADMUX_CHANNEL_ADC7  0x07




void ADC_vidInit (void);
u16 ADC_u16Read (u8 channel);


#endif /* ADC_H_ */
