/*
 * Kinetis Learning Modules
 *
 *
 * File:		io.c
 * Purpose:		Serial Input/Output routines
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "uart.h"
#include "freedom.h"

/********************************************************************/
char in_char (void)
{
	return uart_getchar(TERM_PORT);
}
/********************************************************************/
void
out_char (char ch)
{
	uart_putchar(TERM_PORT, ch);
}
/********************************************************************/
int
char_present (void)
{
	return uart_getchar_present(TERM_PORT);
}
/********************************************************************/
