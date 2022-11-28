#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interaface.h"

u8 ARRAY[8] = {0, 124, 18, 18, 18, 124, 0, 0};


/* 
u8 ARRAY[][8] ={ {40, 56, 32, 40, 40, 56, 0, 124},
                 {56, 40, 56, 32, 40, 40, 56, 0},
                 {32, 56, 40, 56, 32, 40, 40, 56},
                 {56, 32, 56, 40, 56, 32, 40, 40},
                 {32, 56, 32, 56, 40, 56, 32, 40},
                 {32, 32, 56, 32, 56, 40, 56, 32},       
               };

u8 i, j;
while(1)
{
    for(i=0; i<6; i++)
    {
        for(j=0; j<10; j++)
        {
            HLEDMRX_voidDisplay(ARRAY[i]);
        }
    }
}
*/
int main (void)
{
	// RCC
	MRCC_voidInitSystemClock();
	MRCC_voidEnablePeripheralClock(RCC_APB2, 2);
	MRCC_voidEnablePeripheralClock(RCC_APB2, 3);

	//SYSTICK
	MSTK_voidInit();

	//LEDMRX
	HLEDMRX_voidInit();

	HLEDMRX_voidDisplay(ARRAY);
	return 0;
}
