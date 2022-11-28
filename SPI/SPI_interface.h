#ifndef SPI_INTERAFCE_H
#define SPI_INTERAFCE_H

void SPI_vidMasterInit (void);
void SPI_vidSlaveInit (void);
void SPI_vidTransfer (u8 data);
u8 SPI_u8Recieve (void);

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
