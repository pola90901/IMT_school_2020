#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

void MTWI_voidMasterInit (void);
void MTWI_voidMasterStart (void);
void MTWI_voidMasterTransmit (u8 data);
u8   MTWI_u8MasterReceive (void);
void MTWI_voidMasterStop (void);

void MTWI_voidSlaveInit (u8 address);
void MTWI_voidListen(void);
void MTWI_voidSlaveTransmit(u8 data);
u8   MTWI_u8SlaveReceive (void);

/***      TWCR BITS        ***/
#define TWINT 7
#define TWSTA 5
#define TWEN  2
#define TWSTO 4

#endif
