/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MKL46Z4.h"
#include "stdlib.h"
#include "stdio.h"

#define msg "Hello World\r\n"

void GPIO_Init(void)
{
	/* Enable clock PORT A, B, C , D, E */
	SIM->SCGC5 |= 0x1F<<9;
	/* PTD5 is GPIO output */
	PORTD->PCR[5] = 1<<8;
	GPIOD->PDDR |= 1<<5;
	/* PTE29 is GPIO output */
	PORTE->PCR[29] = 1<<8;
	GPIOE->PDDR |= 1<<29;
}

void UartTxMsg(uint8_t *data, uint8_t size)
{
	uint8_t *pTX = (uint8_t*)&UART0->D;
	while(size--)
	{
		while((UART0->S1 & (1<<6)) == 0);
		*pTX = *data++;
	}

}

char UartRxMsg()
{
	/* Wait until character has been received */
	while (!(UART0->S1 & UART0_S1_RDRF_MASK));
	/* Return the 8-bit data from the receiver */
	return UART0->D;
}
/*
 * system clock = 48MHz
 * flash/bus clock = core/system / 2 = 24MHz
 * */

void ClockInit(void)
{
	// set a safe value for divider
	SIM->CLKDIV1 |= SIM_CLKDIV1_OUTDIV4_MASK | SIM_CLKDIV1_OUTDIV1_MASK;
	MCG->C1 |= MCG_C1_IREFS_MASK; // Internal clock (32.768kHz) for FLL
	MCG->C4 |= MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(1);// 32.768 * 1464 = 47972.352kHz ~ 48MHz
	MCG->C1 &= ~MCG_C1_CLKS_MASK; // Output of FLL is selected for MCGOUTCLK
	while((MCG->S & MCG_S_IREFST_MASK) == 0); // wait for Internal clock is selected
	while((MCG->S & MCG_S_CLKST_MASK) != 0); // wait for FLL is selected
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1); /* MCGFLLCLK is selected for UART0 clock source */
}


void UART_Init(uint32_t sysclk, uint32_t baud_rate)
{
    uint8_t i;
    uint32_t calculated_baud = 0;
    uint32_t baud_diff = 0;
    uint32_t osr_val = 0;
    uint32_t sbr_val, uart0clk;
    uint32_t reg_temp = 0;
    uint32_t temp = 0;

    /* Set Mux UART */
	PORTA->PCR[1]= 2<<8;
	PORTA->PCR[2]= 2<<8;

    SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
    UART0->C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
    // Change units to Hz
    uart0clk = sysclk * 1000;
    // Calculate the first baud rate using the lowest OSR value possible.
    i = 4;
    sbr_val = (uint32_t)(uart0clk/(baud_rate * i));
    calculated_baud = (uart0clk / (i * sbr_val));
    baud_diff = abs(calculated_baud - baud_rate);
    osr_val = i;
    // Select the bester OSR value
    for (i = 5; i <= 32; i++)
    {
        sbr_val = (uint32_t)(uart0clk/(baud_rate * i));
        calculated_baud = (uart0clk / (i * sbr_val));
        temp = abs(calculated_baud - baud_rate);
        if (temp <= baud_diff)
        {
            baud_diff = temp;
            osr_val = i;
        }
    }

    if (baud_diff < ((baud_rate / 100) * 3))
    {
        if ((osr_val >3) && (osr_val < 9))UART0->C5 |= UART0_C5_BOTHEDGE_MASK;
        // Setup OSR value
        reg_temp = UART0->C4;
        reg_temp &= ~UART0_C4_OSR_MASK;
        reg_temp |= UART0_C4_OSR(osr_val-1);
        // Write reg_temp to C4 register
        UART0->C4 = reg_temp;
        reg_temp = (reg_temp & UART0_C4_OSR_MASK) + 1;
        sbr_val = (uint32_t)((uart0clk)/(baud_rate * (reg_temp)));
         /* Save off the current value of the uartx_BDH except for the SBR field */
        reg_temp = UART0->BDH & ~(UART0_BDH_SBR(0x1F));
        UART0->BDH = reg_temp |  UART0_BDH_SBR(((sbr_val & 0x1F00) >> 8));
        UART0->BDL = (uint8_t)(sbr_val & UART0_BDL_SBR_MASK);
        /* Enable receiver and transmitter */
        UART0->C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK );
    }
    else
    {
    	while(1);
    }
}

uint8_t UartRxByte(void)
{
	/* Wait until character has been received */
	while ((UART0->S1 & (1<<5)) == 0);
	/* Return the 8-bit data from the receiver */
	return UART0->D;
}

int main(void)
{
	ClockInit();
	GPIO_Init();
	UART_Init(48000, 115200);
	char RxByte;
    for (;;)
    {
    	UartTxMsg((uint8_t*)msg, sizeof(msg));
    	RxByte = UartRxByte();
    }
    return 0;
}
