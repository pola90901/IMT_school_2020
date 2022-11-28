/*
 * LCD_int.h
 *
 *  Created on: Aug 16, 2021
 *      Author: User
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_u8CLEAR_DISPLAY  0x01
#define LCD_u8RETURN_HOME   0x02

void LCD_vidWriteData(u8 Copy_Data);



void LCD_vidSendCommand(u8 Command);               // to do further functions
void LCD_vidWriteString(u8 * Copy_String);
void LCD_vidInit();                             //to start the LCD
void LCD_vidGoTo( u8 Copy_Row, u8 Copy_Column); //where to go on the LCD

//void LCD_vidWriteData(u8 Copy_Data);



#endif /* LCD_INT_H_ */
