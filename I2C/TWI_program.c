#include "types.h"
#include "util.h"
#include<util/delay.h>
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

void MTWI_voidMasterInit (void)
{
    TWBR = 0x47;
    TWCR = (1 << TWEN);
}
void MTWI_voidMasterStart (void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while(!(TWCR & (1 << TWINT)));
    //while(GET_BIT(TWCR,TWINT) == 0);
}
void MTWI_voidMasterTransmit (u8 data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while(!(TWCR & (1 << TWINT)));
}
u8   MTWI_u8MasterReceive (void)
{
    while(!(TWCR & (1 << TWINT)));
    return TWDR;
}
void MTWI_voidMasterStop (void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void MTWI_voidSlaveInit (u8 address)
{
    TWCR = (1 << TWEN);
    TWAR = address;
}

void MTWI_voidListen(void)
{

    while(!(TWCR & (1 << TWINT)));
}
void MTWI_voidSlaveTransmit(u8 data)
{
    TWDR = data;
    TWCR = (1 << TWEN);
    while(!(TWCR & (1 << TWINT)));
}
u8   MTWI_u8SlaveReceive (void)
{
	TWCR =TWCR &~(1<<TWINT);
	//TWCR &=~(1<<6);
	//TWCR|= (1<<TWINT);

   //while(!(TWCR & (1 << TWINT)));
    return TWDR;
}
