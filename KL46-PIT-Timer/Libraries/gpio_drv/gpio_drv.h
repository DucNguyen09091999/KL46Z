/*
 * gpio_drv.h
 *
 *  Created on: Dec 8, 2021
 *      Author: quocl
 */

#ifndef _GPIO_DRV_H_
#define _GPIO_DRV_H_

#include "MKL46Z4.h"

void LedInit();
void BlinkLed();
void delay(unsigned int time);

#endif /* _GPIO_DRV_H_ */
