/*
 * pit_drv.c
 *
 *  Created on: Dec 8, 2021
 *      Author: quocl
 */

#include "pit_drv.h"

void PIT_Init(uint32_t ms) /* Bus clock default = 20971520/2 = 10485760 */
{
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK; /* PIT clock enable */
	PIT->MCR &= ~(PIT_MCR_MDIS_MASK|PIT_MCR_FRZ_MASK); /* clear all */
	PIT->MCR |= PIT_MCR_FRZ_MASK; /* stop in debug mode */
	PIT->CHANNEL[1].LDVAL |= 400;/* 100us */
	PIT->CHANNEL[1].TCTRL |= PIT_TCTRL_TEN_MASK;/* enable channel 0 */


	PIT->CHANNEL[1].TCTRL |= 1<<1; /* Enable interrupt timer */

}
