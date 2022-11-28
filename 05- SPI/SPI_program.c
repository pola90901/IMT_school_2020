#include "STD_TYPES.h"
#include "SPI_interface.h"
#include "SPI_private.h"

void MSPI_voidMasterInit (void)
{
    DDRB = (1 << MOSI) | (1 << SCK) | (1 << SS);
    PORTB &= ~(1 << SS);
    
    SPCR = (1 << SPE) | (1 << MSTR);
}
void MSPI_voidSlaveInit (void)
{
    DDRB = (1 << MISO);
    SPCR = (1 << SPE);
}
void MSPI_voidTransmit (u8 data)
{
    SPDR = data;
    while(SPSR & (1 << SPIF) == 0);
}
u8 MSPI_u8Receive (void)
{
    while(SPSR & (1 << SPIF) == 0);
    return SPDR;
}