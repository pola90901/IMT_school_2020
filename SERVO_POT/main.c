/*
 * day20_assig.c
 *
 *  Created on: Aug 27, 2021
 *      Author: User
 */

#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO_int.h"
#include "ADC.h"
#include "GPT.h"
#include "PWM_int.h"
#include "avr/interrupt.h"
#include "LCD_int.h"

int main (void)
{
     f32 angle=0.0; //declaring a variable to store the value of angle for the motor to rotate
     f32 dutycycle=0.0;  //declaring a variable for dutycycle
     f32 adc=0.0;  //declaring a variable to store the value of potentiometer
   DIO_vidSetPinDirection(u8PORTD,DIO_u8_PIN_5,DIO_u8OUTPUT);  //set motor as output
   DIO_vidSetPinDirection(u8PORTA,DIO_u8_PIN_0,DIO_u8INPUT); //set potentiometer as input
   DIO_vidSetPinVal(u8PORTA,DIO_u8_PIN_0,DIO_u8HIGH); //pull up resistor
   LCD_vidInit();  //initialize lcd
   ADC_vidInit(); //initialize adc
   PWM_vidPWMInit(TIMER1);   //initialization for PWM TIMER1
   PWM_StartTimer(TIMER1); //start timer 1



   while(1)
   {
	 adc= ADC_u16Read(ADC_ADMUX_CHANNEL_ADC0);  //read the value of the potentiometer
	  angle= (adc*180)/1024;   //translate the value of the potentiometer to degrees for the lcd (equivalent value of potentiometer in degrees)
	  dutycycle=((5*adc)/1024.0)+5;  //equivalent value of potentiometer for dutycycle for the servo motor
	  PWM_vidSetPWMDutyCycle(TIMER1, dutycycle); //servo's dutycycle
	   LCD_vidGoTo(0,0); //cursor movement
	  LCD_vidWriteData((((u32)angle/100)%10)+'0'); //ascii relevant value of the number to be printed on the lcd screen
	  LCD_vidGoTo(0,1); //cursor movement one step
	  LCD_vidWriteData((((u32)angle/10)%10)+'0'); //ascii relevant value of the number to be printed on the lcd screen
	  LCD_vidGoTo(0,2); //cursor movement one step
	  LCD_vidWriteData(((u32)angle%10)+'0'); //ascii relevant value of the number to be printed on the screen





     //LCD_vidGoTo(0,10);
   }


  return 0;

}
