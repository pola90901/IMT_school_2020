/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */

#include"types.h"
#include "util.h"
#include"regiester.h"
#include <avr/io.h>

#include <util/delay.h>






void TWI_Read_Nack (char* ptr) // The function argument is a pointer to a memory place in the MCU to store the received data in

{

       reg_TWCR=(1<<7)|(1<<2);

       while ((Get_bit(reg_TWCR,7))==0)

       {       }

       *ptr=reg_TWDR;

}

void TWI_Start (void)

{       reg_TWCR= (1<<7)|(1<<5)|(1<<2);

       while((Get_bit(reg_TWCR,7))==0)
       {       }

}

void TWI_Write (char data)

{

       reg_TWDR=data;

       reg_TWCR= (1<<7)|(1<<2);

       while ((Get_bit(reg_TWCR,7))==0)

       {       }

}

void TWI_Init (void)

{       reg_TWSR=0;

reg_TWBR=0x07;

reg_TWCR|=(1<<2);
}
void TWI_Stop (void)

{

       reg_TWCR=(1<<4)|(1<<2)|(1<<7);

}

void EEPROM_Read (char address, char* ptr) // the function arguments are an address in the EEPROM to read from and a pointer to a memory place in the MCU to store the read data in

{

       TWI_Start();

       TWI_Write(0xA8);

       TWI_Write(address);

       TWI_Start();

       TWI_Write(0xA9);

       TWI_Read_Nack(ptr);

       TWI_Stop();

}
void EEPROM_Write (char data, char address)

{

       TWI_Start();

       TWI_Write(0xA8); //slave address is 1010.100 and a 0 in the 8th bit to indicate Writting.

       TWI_Write(address);

       TWI_Write(data);

       TWI_Stop();

}

int main()
{

	char R;

	       reg_DDRD=0b11111111;

	       TWI_Init();

	       while(1)

	       {

	              EEPROM_Write(0xE0,0x00);

	              _delay_ms(1000); // You must allow suffcent delay for the EEPROM to complete the its internal write cycle

	              EEPROM_Read(0x00,&R);

	              if (R==0xE0)

	              {

	                     reg_PORTD=0b01000000;

	              }

	       }


	return 0;
	}
