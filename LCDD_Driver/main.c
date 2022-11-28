/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Mina Mossa
 */


#include "../LIB/types.h"
#include"../LIB/typedefs.h"
#include"../LIB/ATMEGA32_REGISTERS.h"
#include"DIO_int.h"
#include"LCD_int.h"
int main(void){

	LCD_vidInit();
	LCD_vidWriteString("Mina");
	while(1){

	}

	return 0;
}
