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
	UBRR0H = (BAUDRATE>>8);
	UBRR0L = BAUDRATE;

	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C |= (1<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );

		/* Put data into buffer, sends the data */
		UDR0 = data;

}

unsigned char USART_Receive(void)
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );

		/* Get and return received data from buffer */
		return UDR0;

}
