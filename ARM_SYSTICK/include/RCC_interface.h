#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void MRCC_voidInitSystemClock (void);
void MRCC_voidEnablePeripheralClock (u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisablePeripheralClock (u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif