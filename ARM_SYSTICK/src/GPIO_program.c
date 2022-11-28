#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void MGPIO_voidSetPinMode (u8 copy_u8PortID, u8 copy_u8PinId, u8 copy_u8Mode )
{
    if(copy_u8PinId <= 15)
    {
        switch(copy_u8PortID)
        {
            case GPIOA: if(copy_u8PinId <= 7)
                        {
                            GPIOA_CRL &= ~ ((0b1111) << (copy_u8PinId * 4));
                            GPIOA_CRL |= ((copy_u8Mode) << (copy_u8PinId * 4) );
                             
                        }
                        else if(copy_u8PinId <= 15)
                        {
                            copy_u8PinId -= 8;
                            GPIOA_CRH &= ~ ((0b1111) << (copy_u8PinId * 4));
                            GPIOA_CRH |= ((copy_u8Mode) << (copy_u8PinId * 4) );
                        }
                        else
                        {
                            // do nothing 
                        }
                        break;
                        
            case GPIOB: if(copy_u8PinId <= 7)
                        {
                            GPIOB_CRL &= ~ ((0b1111) << (copy_u8PinId * 4));
                            GPIOB_CRL |= ((copy_u8Mode) << (copy_u8PinId * 4) );
                             
                        }
                        else if(copy_u8PinId <= 15)
                        {
                            copy_u8PinId -= 8;
                            GPIOB_CRH &= ~ ((0b1111) << (copy_u8PinId * 4));
                            GPIOB_CRH |= ((copy_u8Mode) << (copy_u8PinId * 4) );
                        }
                        else
                        {
                            // do nothing 
                        }
                        break;
                        
            case GPIOC: if(copy_u8PinId <= 7)
                        {
                            GPIOC_CRL &= ~ ((0b1111) << (copy_u8PinId * 4));
                            GPIOC_CRL |= ((copy_u8Mode) << (copy_u8PinId * 4) );
                             
                        }
                        else if(copy_u8PinId <= 15)
                        {
                            copy_u8PinId -= 8;
                            GPIOC_CRH &= ~ ((0b1111) << (copy_u8PinId * 4));
                            GPIOC_CRH |= ((copy_u8Mode) << (copy_u8PinId * 4) );
                        }
                        else
                        {
                            // do nothing 
                        }
                        break;
            default: break;
        }
    }
    else{
        // do nothing 
    }
}
void MGPIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinId, u8 copy_u8Value)
{
    if(copy_u8PinId <= 15)
    {
         switch(copy_u8PortID)
         {
             case GPIOA: if(copy_u8Value == GPIO_HIGH)
                         {
                             SET_BIT(GPIOA_ODR, copy_u8PinId);
                         }
                         else if(copy_u8Value == GPIO_LOW)
                         {
                             CLR_BIT(GPIOA_ODR, copy_u8PinId);
                         }
                         else
                         {
                             // error
                         }
                         break;
                         
             case GPIOB: if(copy_u8Value == GPIO_HIGH)
                         {
                             SET_BIT(GPIOB_ODR, copy_u8PinId);
                         }
                         else if(copy_u8Value == GPIO_LOW)
                         {
                             CLR_BIT(GPIOB_ODR, copy_u8PinId);
                         }
                         else
                         {
                             // error
                         }
                         break;
                         
             case GPIOC: if(copy_u8Value == GPIO_HIGH)
                         {
                             SET_BIT(GPIOC_ODR, copy_u8PinId);
                         }
                         else if(copy_u8Value == GPIO_LOW)
                         {
                             CLR_BIT(GPIOC_ODR, copy_u8PinId);
                         }
                         else
                         {
                             // error
                         }
                         break;
             default: break;
         }         
    }
    else
    {
        //error
    }
}
u8   MGPIO_u8GetPinValue  (u8 copy_u8PortID, u8 copy_u8PinId)
{
    u8 Local_u8PinValue;
    if(copy_u8PinId <= 15)
    {
         switch(copy_u8PortID)
         {
             case GPIOA:Local_u8PinValue = GET_BIT(GPIOA_IDR, copy_u8PinId); break;
             case GPIOB:Local_u8PinValue = GET_BIT(GPIOB_IDR, copy_u8PinId); break;
             case GPIOC:Local_u8PinValue = GET_BIT(GPIOC_IDR, copy_u8PinId); break;
             default: break;
         }
    }
    else
    {
        //error
    }
    
    return Local_u8PinValue;
}