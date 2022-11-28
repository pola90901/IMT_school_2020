#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interaface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void HLEDMRX_voidInit (void)
{
	/* set rows pins as output  */
	MGPIO_voidSetPinMode(LEDMRX_ROW0_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_ROW1_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_ROW2_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_ROW3_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_ROW4_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_ROW5_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_ROW6_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_ROW7_PIN, OUTPUT_2MHZ_PP);
	
	/* set columns pins as output  */
	MGPIO_voidSetPinMode(LEDMRX_COL0_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_COL1_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_COL2_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_COL3_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_COL4_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_COL5_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_COL6_PIN, OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinMode(LEDMRX_COL7_PIN, OUTPUT_2MHZ_PP);
}


void HLEDMRX_voidDisplay (u8 *Ptr_u8Data)
{	    
	    disableAllColumns();
		setRowValues(Ptr_u8Data[0]);
	    MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_LOW);
	    MSTK_voidSetBusyWait(2500); //2.5ms
		
		disableAllColumns();
		setRowValues(Ptr_u8Data[1]);
	    MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_LOW);	    
	    MSTK_voidSetBusyWait(2500); //2.5ms
		
		disableAllColumns();
		setRowValues(Ptr_u8Data[2]);
	    MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_LOW);	    
	    MSTK_voidSetBusyWait(2500); //2.5ms
		
		disableAllColumns();
	    setRowValues(Ptr_u8Data[3]);
	    MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_LOW);
	    MSTK_voidSetBusyWait(2500); //2.5ms
		
		disableAllColumns();
		setRowValues(Ptr_u8Data[4]);
	    MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_LOW);	    
	    MSTK_voidSetBusyWait(2500); //2.5ms
		
		disableAllColumns();
	    setRowValues(Ptr_u8Data[5]);
	    MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_LOW);	  
	    MSTK_voidSetBusyWait(2500); //2.5ms
		
		disableAllColumns();
		setRowValues(Ptr_u8Data[6]);
	    MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_LOW);	   
	    MSTK_voidSetBusyWait(2500); //2.5ms
		
		disableAllColumns();
		setRowValues(Ptr_u8Data[7]);
	    MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_LOW);	    
	    MSTK_voidSetBusyWait(2500); //2.5ms
	
	
}

static void disableAllColumns (void)
{
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_HIGH); 
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_HIGH);
}

static void setRowValues(u8 Copy_u8Value)
{
	u8 Local_u8Bit;
	
	 Local_u8Bit = GET_BIT(Copy_u8Value, 0);
	 MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN, Local_u8Bit);
	 
	 Local_u8Bit = GET_BIT(Copy_u8Value, 1);
	 MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN, Local_u8Bit);
	 
	 Local_u8Bit = GET_BIT(Copy_u8Value, 2);
	 MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN, Local_u8Bit);
	 
	 Local_u8Bit = GET_BIT(Copy_u8Value, 3);
	 MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN, Local_u8Bit);
	 
	 Local_u8Bit = GET_BIT(Copy_u8Value, 4);
	 MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN, Local_u8Bit);
	 
	 Local_u8Bit = GET_BIT(Copy_u8Value, 5);
	 MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN, Local_u8Bit);
	 
	 Local_u8Bit = GET_BIT(Copy_u8Value, 6);
	 MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN, Local_u8Bit);
	 
	 Local_u8Bit = GET_BIT(Copy_u8Value, 7);
	 MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN, Local_u8Bit);
	
}
