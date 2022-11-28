/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include "types.h"
#include "util.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"
#include<avr/io.h>
void main(void)
{
DDRD=0xFF;
MTWI_voidSlaveInit(0b10101010);



while (1)
{
	//MTWI_voidListen();

PORTD=MTWI_u8SlaveReceive();
}

}
