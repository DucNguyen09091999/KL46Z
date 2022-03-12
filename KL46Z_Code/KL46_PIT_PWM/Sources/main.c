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

#define DELAY_VALUE 10
#define TIME 100000

uint32_t max, min;
uint8_t invert = 0;

/**************************************************************/
void PIT_IRQHandler()
{
	if(PIT->CHANNEL[0].TFLG == 1) /* If interrupt request on channel 0 */
	{
		if((GPIOE->PDOR & (1<<29)) !=0 )
		{
			PIT->CHANNEL[0].LDVAL = min;
		}
		else
		{
			PIT->CHANNEL[0].LDVAL = max;
		}
		GPIOE->PTOR |= 1<<29; /* Toggle LED */
		GPIOD->PTOR |= 1<<5; /* Toggle LED */
		PIT->CHANNEL[0].TFLG = 1; /* w1c to clear interrupt flag */
	}
}
/**************************************************************/

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

	GPIOD->PDOR |= 1<<5;
}
/**************************************************************/

void PIT_Init(void)
{
	/* Enable clock for PIT Timer */
	SIM->SCGC6 |= 1<<23;
	/* Enable PIT timer */
	PIT_MCR = 0x00;
	/* Setup channel 0 */
	PIT->CHANNEL[0].LDVAL = 0x0003E7FF; /* setup timer 0 for 256000 cycles */
	PIT->CHANNEL[0].TCTRL = 3;
	/* Setup channel 1 */
	//PIT->CHANNEL[1].LDVAL = 0x0016E35F; /* setup timer 0 for 1500000 cycles */
	//PIT->CHANNEL[1].TCTRL = 3;
	/* Enable PIT interrupt PIT timer */
	NVIC_EnableIRQ(PIT_IRQn);
}
/**************************************************************/
void delay(uint32_t time)
{
	while(time--);
}
int main(void)
{
	GPIO_Init();
	PIT_Init();
    for (;;)
    {

    	if(invert == 0)
		{
    		max++;
    		if(max>TIME)
    		{
    			invert = 1;
    		}
		}
    	else
    	{
    		max--;
			if(max<1)
			{
				invert = 0;
			}
    	}
    	min = TIME-max;
    	delay(DELAY_VALUE);

    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
