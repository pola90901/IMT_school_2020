#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI_voidInit(void)
{
    SPI -> CR1 = 0x0347;
}

void MSPI_voidSendData(u8 data, u8 *dataReceived)
{
    MGPIO_voidSetPinValue(SPI_SLAVE_PIN, GPIO_LOW);
    SPI -> DR = data;
    while(GET_BIT(SPI -> SR, 7) == 1);
    *dataReceived = SPI -> DR;
    MGPIO_voidSetPinValue(SPI_SLAVE_PIN, GPIO_HIGH);
}