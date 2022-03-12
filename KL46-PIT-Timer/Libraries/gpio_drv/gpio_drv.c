/*
 * gpio_drv.c
 *
 *  Created on: Dec 8, 2021
 *      Author: quocl
 */


#include "gpio_drv.h"

void LedInit()
{
	/* Enable clock */
	SIM->SCGC5 |= 1<<12;
	/* Config port cho pin PTD5 */
	PORTD->PCR[5] |= 1<<8;// as GPIO
	GPIOD->PDDR |= 1<<5; // as output
}

void delay(unsigned int time)
{
	while(time--);
}


void BlinkLed()
{
	GPIOD->PDOR |= 1<<5;
	delay(0xFFFF);
	GPIOD->PDOR &= ~(1<<5);
	delay(0xFFFF);
}
