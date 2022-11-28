
/*    4 options for clock source :    
                  RCC_HSE_CRYSTAL  
                  RCC_HSE_RC
                  RCC_HSI  
                  RCC_PLL             */
#define RCC_CLOCK_SYSTEM  RCC_HSE_RC



/*    PLL options    */
//PLL input  --> 3 options (HSI_DIV_2, HSE_DIV_2, HSE)
#define RCC_CLOCK_INPUT  HSI_DIV_2

//PLL mult factor --> 2:16
#define RCC_CLOCK_MULT_FACTOR  9



