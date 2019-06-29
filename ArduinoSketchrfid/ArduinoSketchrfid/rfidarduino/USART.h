#define FOSC 8000000 // Clock Speed
#define BAUD 9600

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/setbaud.h>
#include <util/delay.h>

#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

void USART_Init(void)
{
	/*Set baud rate */
	UBRR1H = (BAUDRATE>>8);
	UBRR1L = BAUDRATE;

	UCSR1B |= (1<<RXEN1)|(1<<TXEN1);
	/* Set frame format: 8data, 2stop bit */
	UCSR1C |= (1<<USBS1)|(3<<UCSZ10);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1<<UDRE1)) );

		/* Put data into buffer, sends the data */
		UDR1 = data;

}

unsigned char USART_Receive(void)
{
	/* Wait for data to be received */
	while ( !(UCSR1A & (1<<RXC1)) );

		/* Get and return received data from buffer */
		return UDR1;

}
