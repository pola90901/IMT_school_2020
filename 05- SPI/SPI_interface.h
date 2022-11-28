#ifndef SPI_INTERAFCE_H
#define SPI_INTERAFCE_H

void MSPI_voidMasterInit (void);
void MSPI_voidSlaveInit (void);
void MSPI_voidTransmit (u8 data);
u8 MSPI_u8Receive (void);

/***        SPSR BITS        ***/
#define SPIF  7

/***        SPCR BITS        ***/
#define SPE  6
#define MSTR 4

/***        SPI PINS         ***/
#define MOSI 5
#define MISO 6
#define SCK  7
#define SS   4

#endif