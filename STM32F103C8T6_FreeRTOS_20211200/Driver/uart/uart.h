/*
 * uart.h
 *
 *  Created on: Dec 27, 2021
 *      Author: quocl
 */

#ifndef _UART_H_
#define _UART_H_

#include "stm32f1xx.h"

void UART_Init(void);
void UartTxMsg(uint8_t *data, uint8_t size);
void UartRxMsg(uint8_t *data, uint8_t size);

#endif /* UART_UART_H_ */
