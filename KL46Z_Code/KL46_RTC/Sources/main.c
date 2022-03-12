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
#include "rtc.h"

static int i = 0;


void RTC_Init(rtc_datetime_t *date)
{
	SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;
	RTC->SR &= ~RTC_SR_TCE_MASK;
	SIM->SOPT1 &= ~SIM_SOPT1_OSC32KSEL_MASK; // RTC clock in is LPO
	SIM->SOPT1 |= SIM_SOPT1_OSC32KSEL(3);
	RTC_SetDatetime(date);
	RTC->SR |= RTC_SR_TCE_MASK;
}

int main(void)
{
	uint32_t sec;
	uint32_t currSeconds;
	rtc_datetime_t date;
	// Set a start date time and start RT.
	date.year   = 2020U;
	date.month  = 12U;
	date.day    = 01U;
	date.hour   = 22U;
	date.minute = 0;
	date.second = 0;
	RTC_Init(&date);
    for (;;)
    {
    	RTC_GetDatetime(&date);
    }
    return 0;
}
