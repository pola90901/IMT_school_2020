#ifndef SPI_INTERAFCE_H
#define SPI_INTERAFCE_H

void SPI_vidMasterInit (void);
void SPI_vidSlaveInit (void);
void SPI_vidTransfer (u8 data);
u8 SPI_u8Recieve (void);

#endif
