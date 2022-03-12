/*
 * uart.c
 *
 *  Created on: Dec 27, 2021
 *      Author: quocl
 */

#include "uart.h"

/*****************************************************/
void UART_Init(void)
{
	USART1->CR1 |= (uint32_t)(1<<2); /* Receiver is enabled and begins searching for a start bit */
	USART1->CR1 |= (uint32_t)(1<<3); /* Transmitter is enabled */
	USART1->CR1 |= (uint32_t)(1<<13); /* USART enabled */
	/* 1200 b/s */
	USART1->BRR |= (uint32_t)(416<<4); /* Mantissa */
	USART1->BRR |= (uint32_t)(10<<0); /* Fraction */

	GPIOA->CRH = 0x888444b4;
	GPIOA->IDR = 0x9f04;
	GPIOA->ODR = 0xa000;

}
/*****************************************************/
void UartTxMsg(uint8_t *data, uint8_t size)
{
	for(uint8_t i=0; i<size; i++)
	{
		USART1->DR = *(data+i);
		while((USART1->SR & (uint32_t)(1<<6))==0); /* Wait TC ==1 */
	}
}
/*****************************************************/

void UartRxMsg(uint8_t *data, uint8_t size)
{
	for(int i=0; i<size; i++)
	{
		while((USART1->SR & (1UL<<5U)) == 0); /* Wait if data not ready with timeout */
		*(data+i) = (uint8_t)USART1->DR;
	}
}
