/*
 * File:		uart.h
 * Purpose:     Provide common ColdFire uart routines for polled serial IO
 *
 * Notes:
 */

#ifndef __uart_H__
#define __uart_H__
#include <MKL46Z4.h>
/********************************************************************/

#define TRUE					1
#define FALSE					0

#define UART_MODE_INTERRUPT		FALSE
extern void UART0_IRQHandler(void);

void uart0_init ( int sysclk, int baud);
char uart0_getchar ();
void uart0_putchar ( char ch);
void USART0_putstr(char *str);



/********************************************************************/

#endif /* __uart_H__ */
