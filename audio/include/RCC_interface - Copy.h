#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void MRCC_voidInitSystemClock (void);
void MRCC_voidEnablePeripheralClock (u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisablePeripheralClock (u8 Copy_u8BusId, u8 Copy_u8PerId);


/**     System buses    **/
#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2

/**      CLOCK source      **/
#define RCC_HSE_CRYSTAL  0
#define RCC_HSE_RC       1
#define RCC_HSI          2
#define RCC_PLL          3

/**        PLL input       **/
#define HSI_DIV_2     0
#define HSE_DIV_2     1
#define HSE           2




      #endif
