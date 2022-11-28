/*
 * EXTI_Prog.c
 *
 *  Created on: Aug 22, 2021
 *      Author: User
 */
#include "types.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO_int.h"
#include <avr/interrupt.h>
#include "EXTI.h"


pFunc InternalCBF[3];

void EXTI_vidEnable_Interrupt ( u8 Copy_IntNumb)
{
   switch (Copy_IntNumb)
   {
     case 0:
	   GICR_REG.Bits.u8BIT_6=1;     //set the PIE of INT0 to 1
	   break;
   case 1:
	   GICR_REG.Bits.u8BIT_7=1;     //set the PIE of INT1 to 1
	   break;
   case 2:
	   GICR_REG.Bits.u8BIT_5=1;     //set the PIE of INT2 to 1
	   break;
   default:
	   break;

   }

}
void EXTI_vidDisable_Interrupt ( u8 Copy_IntNumb)
{
	 switch (Copy_IntNumb)
	   {
	    case 0:
		   GICR_REG.Bits.u8BIT_6=0;     //set the PIE of INT0 to 0
		   break;
	   case 1:
		   GICR_REG.Bits.u8BIT_7=0;     //set the PIE of INT1 to 0
		   break;
	   case 2:
		   GICR_REG.Bits.u8BIT_5=0;     //set the PIE of INT2 to 0
		   break;
	   default:
		   break;

	   }

}
void EXTI_vidInit(void)
{
	MCUCR_REG.u8Whole_Register &= INT0_SC_CLEAR_MASK;
	MCUCR_REG.u8Whole_Register &= INT1_SC_CLEAR_MASK;

	MCUCR_REG.u8Whole_Register |= INT1_SC_MODE;
	MCUCR_REG.u8Whole_Register |= INT0_SC_MODE;

}
void EXTI_vidSetCallBackFunction(pFunc CBF, u8 Copy_IntNumb )
{
  if( CBF )
	  InternalCBF[Copy_IntNumb ]= CBF;

}

ISR (INT0_vect)
{

	if(InternalCBF[0])
	{

      InternalCBF[0]( );
	}

}

ISR (INT1_vect)
{

	if(InternalCBF[1])
	{

      InternalCBF[1]( );
	}

}

ISR (INT2_vect)
{

	if(InternalCBF[2])
	{

      InternalCBF[2]( );
	}

}
