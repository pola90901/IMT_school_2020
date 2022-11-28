#include "types.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "ATMEGA32_REGISTERS.h"
#include"DIO_int.h"
void SPI_vidMasterInit (void)
{
	/* Set MOSI and SCK and SS output*/
	SET_BIT(DDRB_REG,5);
	SET_BIT(DDRB_REG,7);
	SET_BIT(DDRB_REG,4);
	/*slave select */
	CLR_BIT(PORTB_REG,4);
	/* Enable SPI,select  Master mode*/
	SET_BIT(SPCR_REG,4);
	SET_BIT(SPCR_REG,6);
}
void SPI_vidSlaveInit (void)
{
	/* Set MISO output */
	SET_BIT(DDRB_REG,6);
	/* Enable SPI */
	SET_BIT(SPCR_REG,6);
}
void SPI_vidTransfer (u8 data)
{
	/*Loading the data */
	SPDR_REG=data;
	/* waiting the flag*/
	while(((SPSR_REG) & (1 << 7)) == 0);
}
u8 SPI_u8Recieve (void)
{
	/* waiting the flag*/
	while(((SPSR_REG) & (1 << 7)) == 0);
	/* return data read*/
	return SPDR_REG;
}
