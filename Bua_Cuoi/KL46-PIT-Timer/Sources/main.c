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

#include "pit_drv.h"
#include "gpio_drv.h"
uint8_t second = 0, minute = 0, hour = 0;

void Clock4MHzInternal()
{
	SIM->CLKDIV1 = (uint32_t)0;
	MCG->SC &= ~(7<<1);
	MCG->C1 |= 1<<6; /* select internal clock */
	MCG->C2 |= 1<<0;
	while((MCG->S & MCG_S_IRCST_MASK) != MCG_S_IRCST_MASK);
	SystemCoreClockUpdate();
}

void SystemClockInit()
{
	Clock4MHzInternal();
}


void PIT_IRQHandler()
{
	GPIOD->PTOR |= 1<<5;/* my task */
	PIT->CHANNEL[1].TFLG |= PIT_TFLG_TIF_MASK; /* clear flag */
}


int main(void)
{
	SystemClockInit();/* 48MHz */
	LedInit();
	PIT_Init(100);/* ms */
	NVIC_EnableIRQ(PIT_IRQn);
	__enable_irq(); /* global */
	while(1)
	{
//		if((PIT->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK) == PIT_TFLG_TIF_MASK) /* ting ting */
//		{
//			GPIOD->PTOR |= 1<<5;/* my task */
//			PIT->CHANNEL[1].TFLG |= PIT_TFLG_TIF_MASK; /* clear flag */
//		}
	}
    return 0;
}
