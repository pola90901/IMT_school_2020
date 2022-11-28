#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void (*callBack) (void); // global ptr : function to be used in ISR
u8 periodic;

void MSTK_voidInit (void)
{
	STK_CTRL = 0;
	#if CLOCK_SOURCE == AHB
	SET_BIT(STK_CTRL, 2);
	#elif CLOCK_SOURCE == AHB_DIV_8
	CLR_BIT(STK_CTRL, 2);
	#else
		#error "invalid option"
	#endif
}
void MSTK_voidSetBusyWait (u32 Copy_u32Ticks)
{
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, 0); // eneble systick
	while(GET_BIT(STK_CTRL, 16) == 0);
    CLR_BIT(STK_CTRL, 0);
}
void MSTK_voidSetIntervalSingle (u32 Copy_u32Ticks, void (*ptr)(void) )
{
	periodic = 0;
	callBack = ptr;
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, 1);
	SET_BIT(STK_CTRL, 0);
}

void MSTK_voidSetIntervalPeriodic (u32 Copy_u32Ticks, void (*ptr)(void) )
{
	periodic = 1;
	callBack = ptr;
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, 1);  // enable interrupt
	SET_BIT(STK_CTRL, 0);  // enable systick
}
void MSTK_voidStopInterval (void)
{
	CLR_BIT(STK_CTRL, 0);
}
u32  Mstk_u32GetElapsedTime (void)
{
	return (STK_LOAD - STK_VALUE);
}
u32  MSTK_u32GetRemainingTime (void)
{
	return (STK_VALUE);
}

void SysTick_Handler(void)
{
	callBack(); /* --> ptr() --> user function */
	if(periodic == 0)
	{
		STK_LOAD  = 0;
	    STK_VALUE = 0;
	}
	
}
