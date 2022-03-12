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
/******************************************************************************/
#include "MKL46Z4.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "queue.h"
#include "event_groups.h"
#include "stream_buffer.h"
/******************************************************************************/
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);
void GPIO_Init(void);
/******************************************************************************/
int main(void)
{
	GPIO_Init();
	xTaskCreate(vTask1, "Task_1", 256, NULL, 1, NULL);
	xTaskCreate(vTask2, "Task_2", 256, NULL, 2, NULL);
	vTaskStartScheduler();
    for (;;)
    {

    }
}
/******************************************************************************/
void vTask1 (void *pvParameters)
{
	while(1)
	{
		GPIOD->PTOR |= 1<<5; /* Toggle LED */
		vTaskDelay(300);
	}
}

/******************************************************************************/
void vTask2 (void *pvParameters)
{
	while(1)
	{
		GPIOE->PTOR |= 1<<29; /* Toggle LED */
		vTaskDelay(150);
	}
}

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
/******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
