
#include "types.h"
#include "util.h"
#define F_CPU 8000000UL			/* Define frequency here its 8MHz */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

//#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void UART_init(long USART_BAUDRATE)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);/* Turn on transmission and reception */
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit character sizes */
	UBRRL = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	UBRRH = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
}

void UART_SndChr(u8 data)
{
	while ((UCSRA & (1 << UDRE)) == 0);/* Wait till data is received */
	UDR = data;			/* Return the byte*/
}

u8 UART_GetChr(void)
{
	while (! (UCSRA & (1<<RXC)));	/* Wait for empty transmit buffer*/
	return(UDR) ;
}

void UART_SendString(char *str)
{
	unsigned char j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		UART_SndChr(str[j]);
		j++;
	}
}

int main()
{
	DDRA = 0xFF;     //for LEDs

	UART_init(9600);


while (1)
{
	u8 x=UART_SndChr();
if(x==1)
{
	PORTA=0x01;
	}

}
/*while(1)
{
	u8 x = UART_GetChr();
    if(x == '1')
	{
    	PORTA= 0;
    	_delay_ms(50);
    	PORTA = 0x01;
	}
	else if (x =='2')
	{
		PORTA = 0;
		_delay_ms(50);
		PORTA = 0x02;
	}
	else if (x =='3')
	{
		PORTA = 0;
		_delay_ms(50);
		PORTA = 0x04;
	}
	else if (x=='4')
	{
		PORTA = 0;
		_delay_ms(50);
		PORTA = 0x08;
	}
	else if (x =='5')
	{
		PORTA = 0;
		_delay_ms(50);
		PORTA = 0x10;
	}
	else if (x =='6')
	{
		PORTA = 0;
		_delay_ms(50);
		PORTA = 0x20;
	}
	else if (x =='7')
	{
		PORTA = 0;
		_delay_ms(50);
		PORTA = 0x40;
	}
	else if (x =='8')
	{
		PORTA = 0;
		_delay_ms(50);
		PORTA = 0x80;
	}
	else if(x =='9')
	{
		PORTA = 0;
	}


	}*/
}

