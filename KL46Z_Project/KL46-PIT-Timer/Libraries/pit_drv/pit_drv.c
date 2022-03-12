/*
 * pit_drv.c
 *
 *  Created on: Dec 8, 2021
 *      Author: quocl
 */

#include <MKL46Z4.h>
#include "pit_drv.h"

void PIT_Init()
{
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK; //Enable clock for PIT
	PIT->MCR &= ~(PIT_MCR_MDIS_MASK); // Clear MDIS fields --> Module Control Register
	PIT->MCR |= 1;
	PIT->CHANNEL[0].LDVAL = 0x1400000;
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK; // Enable Timer Enable fields
	/*
	 * 1s 		--> 0x1400000 (20971520)
	 * 100ms 	--> 0x200000  (2097152)
	 *
	 */
}
