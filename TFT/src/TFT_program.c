#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit (void)
{
	/* pulse train on the RESET pin */
	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(100);

	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(1);

	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(100);

	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(100);

	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);

	/* sleep out */
	sendCommand(0x11);

	/* wait 150 msec */
	MSTK_voidSetBusyWait(150000);

	/* set color standard */
	sendCommand(0x3A);
	sendData(0x05);

	/* display on */
	sendCommand(0x29);
}

void HTFT_voidDisplayImage(const u16 *Ptr_u16ImageArray)
{
	/* set x address */
	sendCommand(0x2A);
	sendData(0);
	sendData(0);
	sendData(0);
	sendData(127);

	/* set y address */
	sendCommand(0x2B);
	sendData(0);
	sendData(0);
	sendData(0);
	sendData(159);

	/* RAM write */
	sendCommand(0x2C);

	/* write on pixels */
	u8  Local_u8Data;
	u16 Local_u16Counter;
	for(Local_u16Counter=0; Local_u16Counter<20480; Local_u16Counter++)
	{
		/* for high part */
		Local_u8Data = Ptr_u16ImageArray[Local_u16Counter]>>8;
		sendData(Local_u8Data);

		/* for low part */
		Local_u8Data = Ptr_u16ImageArray[Local_u16Counter] & 0x00FF;
		sendData(Local_u8Data);
	}

}

void HTFT_voidFillColor(u16 Copy_u16color)
{
	/* set x address */
	sendCommand(0x2A);
	sendData(0);
	sendData(0);
	sendData(0);
	sendData(127);

	/* set y address */
	sendCommand(0x2B);
	sendData(0);
	sendData(0);
	sendData(0);
	sendData(159);

	/* RAM write */
	sendCommand(0x2C);

	/* write on pixels */
	u8  Local_u8Data;
	u16 Local_u16Counter;
	for(Local_u16Counter=0; Local_u16Counter<20480; Local_u16Counter++)
	{
		/* for high part */
		Local_u8Data = Copy_u16color>>8;
		sendData(Local_u8Data);

		/* for low part */
		Local_u8Data = Copy_u16color & 0x00FF;
		sendData(Local_u8Data);
	}

}

void HTFT_voidDrawRect(u8 x1, u8 x2,u8 y1,u8 y2, u16 color)
{
	u16 size = ((y2-y1) * (x2-x1));
	/* set x address */
	sendCommand(0x2A);
	sendData(0);
	sendData(x1);
	sendData(0);
	sendData(x2);

	/* set y address */
	sendCommand(0x2B);
	sendData(0);
	sendData(y1);
	sendData(0);
	sendData(y2);

	/* RAM write */
	sendCommand(0x2C);

	/* write on pixels */
	u8  Local_u8Data;
	u16 Local_u16Counter;
	for(Local_u16Counter=0; Local_u16Counter<size; Local_u16Counter++)
	{
		/* for high part */
		Local_u8Data = color>>8;
		sendData(Local_u8Data);

		/* for low part */
		Local_u8Data = color & 0x00FF;
		sendData(Local_u8Data);
	}
}

static void sendCommand (u8 command)
{
	u8 temp;
	MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_LOW);
	MSPI_voidSendData(command, &temp);
}

static void sendData (u8 data)
{
	u8 temp;
	MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_HIGH);
	MSPI_voidSendData(data, &temp);
}
