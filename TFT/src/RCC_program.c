#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void MRCC_voidInitSystemClock (void)
{
    #if  RCC_CLOCK_SYSTEM == RCC_HSE_CRYSTAL
    RCC_CR   = 0x00010000;   /* Enable HSE "Crystal"   */
    RCC_CFGR = 0x00000001;
    
    #elif RCC_CLOCK_SYSTEM == RCC_HSE_RC
    RCC_CR   = 0x00050000;    /* Enable HSE "RC"    */
    RCC_CFGR = 0x00000001;
    
    #elif RCC_CLOCK_SYSTEM == RCC_HSI
    RCC_CR   = 0x00000081;    /* HSI + TRIM= 0 */
    RCC_CFGR = 0;
    
    #elif RCC_CLOCK_SYSTEM == RCC_PLL
        #if  RCC_CLOCK_INPUT == HSI_DIV_2
            #if RCC_CLOCK_MULT_FACTOR == 2
            RCC_CR   = 0x01000000;
            RCC_CFGR = 0;
            
            #elif RCC_CLOCK_MULT_FACTOR ==3
            RCC_CR   = 0x01000000;
            RCC_CFGR = 0x00040000;
            /* do it alone  */
            
            
            #endif
            
        
        #elif RCC_CLOCK_INPUT == HSE_DIV_2
        
        #elif RCC_CLOCK_INPUT == HSE
        
        #else
            #error("error")
            
        #endif
    
    #else
        #error("error")
    #endif
     
}

void MRCC_voidEnablePeripheralClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if(Copy_u8PerId <= 31)
    {
        switch(Copy_u8BusId)
        {
            case RCC_AHB  : SET_BIT(RCC_AHBENR , Copy_u8PerId); break;
            case RCC_APB1 : SET_BIT(RCC_APB1ENR, Copy_u8PerId); break;
            case RCC_APB2 : SET_BIT(RCC_APB2ENR, Copy_u8PerId); break;
            default: /* invalid input, return error */
            	break;
        }
    }
    else 
    {
        
    }
}

void MRCC_voidDisablePeripheralClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if(Copy_u8PerId <= 31)
    {
        switch(Copy_u8BusId)
        {
            case RCC_AHB  : CLR_BIT(RCC_AHBENR , Copy_u8PerId); break;
            case RCC_APB1 : CLR_BIT(RCC_APB1ENR, Copy_u8PerId); break;
            case RCC_APB2 : CLR_BIT(RCC_APB2ENR, Copy_u8PerId); break;
            default: /* invalid input, return error */
            	break;
        }
    }
    else 
    {
        
    }
}
