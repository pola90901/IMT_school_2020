#include "types.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include<avr/io.h>
void SPI_vidMasterInit (void)
{
    DDRB = (1 << MOSI) | (1 << SCK) | (1 << SS);
    PORTB &= ~(1 << SS);
    SPCR = (1 << SPE) | (1 << MSTR);
}
void SPI_vidSlaveInit (void)
{
    DDRB = (1 << MISO);
    SPCR = (1 << SPE);
}

void SPI_vidTransfer (u8 data)
{
    SPDR = data;
    while(SPSR & (1 << SPIF) == 0);
}
u8 SPI_u8Recieve (void)
{
    while(SPSR & (1 << SPIF) == 0);
    return SPDR;
}
