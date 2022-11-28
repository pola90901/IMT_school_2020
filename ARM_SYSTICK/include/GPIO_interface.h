#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

void MGPIO_voidSetPinMode (u8 copy_u8PortID, u8 copy_u8PinId, u8 copy_u8Mode );
void MGPIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinId, u8 copy_u8Value);
u8   MGPIO_u8GetPinValue  (u8 copy_u8PortID, u8 copy_u8PinId);


/* states */
#define GPIO_HIGH  1
#define GPIO_LOW   0

/* PORTS */
#define GPIOA 0
#define GPIOB 1
#define GPIOC 2

/* PINS */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define PIN8   8
#define PIN9   9
#define PIN10  10
#define PIN11  11
#define PIN12  12
#define PIN13  13
#define PIN14  14
#define PIN15  15


/*  modes */
#define INPUT_ANALOG         0b0000
#define INPUT_FLOATING       0b0100
#define INPUT_PULL_UP_DOWN   0b1000

#define OUTPUT_PP_2MHZ       0b0010
#define OUTPUT_OD_2MHZ       0b0110
#define OUTPUT_AF_PP_2MHZ    0b1010
#define OUTPUT_AF_OD_2MHZ    0b1110

/*  do it alone

#define OUTPUT_PP_10MHZ       
#define OUTPUT_OD_10MHZ       
#define OUTPUT_AF_PP_10MHZ    
#define OUTPUT_AF_OD_10MHZ    

#define OUTPUT_PP_50MHZ       
#define OUTPUT_OD_50MHZ       
#define OUTPUT_AF_PP_50MHZ    
#define OUTPUT_AF_OD_50MHZ  */
    


#endif