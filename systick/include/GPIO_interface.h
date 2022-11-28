#ifndef GPIO_INTERAFCE_H
#define GPIO_INTERAFCE_H

/*  Pin values  */
#define GPIO_HIGH  1
#define GPIO_LOW   0

/*   PORTS    */
#define GPIOA 0
#define GPIOB 1
#define GPIOC 2

/* PINS  */
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7
#define PIN8  8
#define PIN9  9
#define PIN10  10
#define PIN11  11
#define PIN12  12
#define PIN13  13
#define PIN14  14
#define PIN15  15

/* PIN MODES */
#define INPUT_ANALOG         0b0000
#define INPUT_FLOATING       0b0100
#define INPUT_PULL_UP_DOWN   0b1000

#define OUTPUT_2MHZ_PP       0b0010
#define OUTPUT_2MHZ_OD       0b0110
#define OUTPUT_2MHZ_AF_PP    0b1010
#define OUTPUT_2MHZ_AF_OD    0b1110

 /* continue alone  */
 /*
#define OUTPUT_10MHZ_PP       
#define OUTPUT_10MHZ_OD       
#define OUTPUT_10MHZ_AF_PP    
#define OUTPUT_10MHZ_AF_OD    

#define OUTPUT_50MHZ_PP       
#define OUTPUT_50MHZ_OD       
#define OUTPUT_50MHZ_AF_PP    
#define OUTPUT_50MHZ_AF_OD    
*/


void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);



#endif