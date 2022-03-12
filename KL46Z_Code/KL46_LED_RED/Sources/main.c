/*
 * File:		led.c
 * Purpose:		Main process
 *
 */

#include "derivative.h"
#include "gpio.h"
#include "uart.h"
#include "freedom.h" // TERM_PORT and BAUD ratio declarations

/********************************************************************/
int main (void)
{
	int delay;
	gpio_init();
	LED1_ON;   // Green LED
	LED1_OFF;

	LED2_ON;   // Red LED
	LED2_OFF;
	uart_putstr(TERM_PORT, "\n\rRunning the freedom_red_led project.\n\r");

	while(1)
	{
		LED2_TOGGLE;
		for (delay=0; delay<1000000; delay++);
	}
}
/********************************************************************/
