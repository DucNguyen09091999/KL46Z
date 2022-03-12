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
#include <stdio.h>

void Clock_config(void);
int main(void)
{
	while(1)
	{
		if(GPIOC->PDIR & GPIOC->PDIR |= 0x1UL << (4U))
		{
			GPIOD->PSOR |= (0x1UL << (5U));
			while(GPIOC->PDIR & GPIOC->PDIR |= 0x1UL << (4U));
		}
		else
		{
			GPIOD->PCOR |=  (0x1UL << (5U));
			while(GPIOC->PDIR & GPIOC->PDIR |= 0x1UL << (4U));
		}
	}

    return 0;
}


void Clock_config(void)
{
	//SW1 --> PTC3 LED1 --> PD5
	//Enable clock for PORTC
	SIM->SCGC5 |= SIM_SCGC5_PORTC(1);
	//Enable clock for PORTD
	SIM->SCGC5 |= SIM_SCGC5_PORTD(1);
	//PCR as GPIO
	PORTC->PCR[3] &= ~(PORT_PCR_MUX(7));
	PORTC->PCR[3] |= PORT_PCR_MUX(1);
	PORTD->PCR[5] &= ~(PORT_PCR_MUX(7));
	PORTD->PCR[5] |= PORT_PCR_MUX(1);
	//Enable Pull Up/Down
	PORTC->PCR[3] |= PORT_PCR_PE(1);
	//Select Pull Up Mode
	PORTC->PCR[3] |= PORT_PCR_PS(1);
	//Set PCR[3] as input mode
	GPIOD->PDDR &= ~(0x1UL << (4U));


}
