#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	if(Copy_u8Pin <= 15)
	{
		switch(Copy_u8Port)
		{
		case GPIOA: if(Copy_u8Pin <= 7)
		{
			GPIOA_CRL &= ~( (0b1111) << (Copy_u8Pin * 4));
			GPIOA_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= 15 )
		{
			Copy_u8Pin -= 8;
			GPIOA_CRH &= ~( (0b1111) << (Copy_u8Pin * 4));
			GPIOA_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else{
		}
		break;
		case GPIOB: if(Copy_u8Pin <= 7)
		{
			GPIOB_CRL &= ~( (0b1111) << (Copy_u8Pin * 4));
			GPIOB_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= 15 )
		{
			Copy_u8Pin -= 8;
			GPIOB_CRH &= ~( (0b1111) << (Copy_u8Pin * 4));
			GPIOB_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else{
		}
		break;
		case GPIOC: if(Copy_u8Pin <= 7)
		{
			GPIOC_CRL &= ~( (0b1111) << (Copy_u8Pin * 4));
			GPIOC_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= 15 )
		{
			Copy_u8Pin -= 8;
			GPIOC_CRH &= ~( (0b1111) << (Copy_u8Pin * 4));
			GPIOC_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else{
		}
		break;
		default: //error
			break;
		}
	}
	else
	{
		// invalid pin number error
	}
}
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if(Copy_u8Pin <= 15)
	{
		switch(Copy_u8Port)
		{
		case GPIOA: if(Copy_u8Value == GPIO_HIGH)
		{
			SET_BIT(GPIOA_ODR, Copy_u8Pin);
		}
		else if(Copy_u8Value == GPIO_LOW)
		{
			CLR_BIT(GPIOA_ODR, Copy_u8Pin);
		}
		else{
		}
		break;
		case GPIOB: if(Copy_u8Value == GPIO_HIGH)
		{
			SET_BIT(GPIOB_ODR, Copy_u8Pin);
		}
		else if(Copy_u8Value == GPIO_LOW)
		{
			CLR_BIT(GPIOB_ODR, Copy_u8Pin);
		}
		else{
		}
		break;
		case GPIOC: if(Copy_u8Value == GPIO_HIGH)
		{
			SET_BIT(GPIOC_ODR, Copy_u8Pin);
		}
		else if(Copy_u8Value == GPIO_LOW)
		{
			CLR_BIT(GPIOC_ODR, Copy_u8Pin);
		}
		else{
		}
		break;
		default: //error
			break;
		}
	}
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 LOC_u8Value = 0;
	if(Copy_u8Pin <= 15)
	{
		switch(Copy_u8Port)
		{
		case GPIOA: LOC_u8Value = GET_BIT(GPIOA_IDR, Copy_u8Pin);
		break;
		case GPIOB: LOC_u8Value = GET_BIT(GPIOB_IDR, Copy_u8Pin);
		break;
		case GPIOC: LOC_u8Value = GET_BIT(GPIOC_IDR, Copy_u8Pin);
		break;
		default: //error
			break;
		}
	}
	else
	{
		//error
	}

	return LOC_u8Value;
}
