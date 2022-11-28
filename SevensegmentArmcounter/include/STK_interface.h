#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit (void);
void MSTK_voidSetBusyWait (u32 Copy_u32Ticks); // polling (Synchronous function)
void MSTK_voidSetIntervalSingle (u32 Copy_u32Ticks, void (*ptr)(void) );
void MSTK_voidSetIntervalPeriodic (u32 Copy_u32Ticks, void (*ptr)(void) );
void MSTK_voidStopInterval (void);
u32  Mstk_u32GetElapsedTime (void);
u32  MSTK_u32GetRemainingTime (void);

#endif