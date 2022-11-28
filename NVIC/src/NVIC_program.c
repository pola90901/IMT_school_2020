#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/* note
 *
 * all NVIC registers are ATOMIC --> 0 has no effect
 *
 */
void MNVIC_voidEnableInterrupt(u8 Copy_u8PerNumber)
{
	if(Copy_u8PerNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8PerNumber);
	}
	else if(Copy_u8PerNumber <= 59)
	{
		Copy_u8PerNumber -= 32;
		NVIC_ISER0 = (1 << Copy_u8PerNumber);
	}
	else
	{
		
	}
}


void MNVIC_voidDisableInterrupt(u8 Copy_u8PerNumber)
{
	if(Copy_u8PerNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8PerNumber);
	}
	else if(Copy_u8PerNumber <= 59)
	{
		Copy_u8PerNumber -= 32;
		NVIC_ICER0 = (1 << Copy_u8PerNumber);
	}
	else
	{
		
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8PerNumber)
{
	if(Copy_u8PerNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8PerNumber);
	}
	else if(Copy_u8PerNumber <= 59)
	{
		Copy_u8PerNumber -= 32;
		NVIC_ISPR0 = (1 << Copy_u8PerNumber);
	}
	else
	{
		
	}
}