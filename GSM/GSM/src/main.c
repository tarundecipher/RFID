/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include"USART.h"
#include <asf.h>

#include <util/delay.h>
void Send_String(char ar[]){
	int i;
	i=0;
	while(ar[i]!='\0'){
		USART_Transmit(ar[i]);
		i++;
	}
}


int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
	USART_Init();
	while(1){
	Send_String("AT\r\n");
	_delay_ms(1000);
	}
	/* Insert application code here, after the board has been initialized. */
}
