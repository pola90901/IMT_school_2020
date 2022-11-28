#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInitSystemClock (void)
{
#if RCC_SYSTEM_CLOCK == RCC_HSE_CRYSTAL
	RCC_CR   = 0x00010000;
	RCC_CFGR = 0x00000001;

#elif RCC_SYSTEM_CLOCK == RCC_HSE_RC
	RCC_CR   = 0x00050000;
	RCC_CFGR = 0x00000001;

#elif RCC_SYSTEM_CLOCK == RCC_HSI
	RCC_CR   = 0x00000081;
	RCC_CFGR = 0x00000000;

#elif RCC_SYSTEM_CLOCK == RCC_PLL
#if PLL_INPUT == HSE
#if MULT_FACTOR == 2

#elif MULT_FACTOR == 3

#elif MULT_FACTOR == 4


#else
#endif

#else
	// error

#endif
#endif
}
void MRCC_voidEnablePeripheralClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case AHB  : SET_BIT(RCC_AHBENR, Copy_u8PerId);
		break;
		case APB1 : SET_BIT(RCC_APB1ENR, Copy_u8PerId);
		break;
		case APB2 : SET_BIT(RCC_APB2ENR, Copy_u8PerId);
		break;
		default: // invalid bus id
		break;
		}
	}
	else
	{
		//return error
	}
}
void MRCC_voidDisablePeripheralClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31 )
	{
		switch(Copy_u8BusId)
		{
		case AHB  : CLR_BIT(RCC_AHBENR, Copy_u8PerId);
		break;
		case APB1 : CLR_BIT(RCC_APB1ENR, Copy_u8PerId);
		break;
		case APB2 : CLR_BIT(RCC_APB2ENR, Copy_u8PerId);
		break;
		default: // invalid bus id
		break;
		}
	}
	else
	{
		//return error
	}
}
