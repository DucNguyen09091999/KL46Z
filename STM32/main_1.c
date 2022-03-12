#include "uart.h"
/*****************************************************/
#define USE_MY_BOARD
#define msg "Hello World!\n\r"
int count = 0;
/*****************************************************/
void SystemClockInit(void)
{
	RCC->CR |= 1<<0; /* enable HSI clock */
	while((RCC->CR & (uint32_t)(1<<1)) == 0);
	RCC->APB2ENR |= (uint32_t)(1<<0); /* Alternate Function I/O clock enabled */
	RCC->APB2ENR |= (uint32_t)(1<<2); /* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<14);/* USART1 clock enabled */
}

/*****************************************************/
void GPIO_Init(void)
{
#if defined (USE_MY_BOARD)
	/* Init LED */
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk; /* enable clock for GPIOA */
	GPIOA->CRL &= ~(0xF << 4);
	GPIOA->CRL |= (0b0110 << 4);
	/* Init Button (PA8) */
	//RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk; /* enable clock for GPIOA */
	GPIOA->CRH &= ~(0xF << 0);
	GPIOA->CRH |= (0b1000 << 0); /* Input pull up/down mode */
	GPIOA->ODR |= (1<<8);
#else
	/* Init LED (PC13) */
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN_Msk; /* enable clock for GPIOC */
	GPIOC->CRH &= ~(0xF << 20);
	GPIOC->CRH |= (0b0110 << 20);
	/* Init Button (PA0) */
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk; /* enable clock for GPIOA */
	GPIOA->CRL &= ~(0xF << 0);
	GPIOA->CRL |= (0b1000 << 0); /* Input pull up/down mode */
	GPIOA->ODR |= (1<<0);
#endif

}

void EXTI_Init(void)
{
	EXTI->IMR |= 1<<0;
	EXTI->EMR  |= 1<<0;
	EXTI->FTSR |= 1<<0;
	EXTI->SWIER |= 1<<0;
	AFIO->EXTICR[1] &= ~(0xF<<0);
}

void EXTI0_IRQHandler()
{
#if defined (USE_MY_BOARD)

#else
	GPIOC->ODR ^= 1<<13;
	EXTI->PR |= 1<<0;
#endif
}

/*****************************************************/
void delay(uint32_t time)
{
	while(time--);
}
/*****************************************************/

int main(void)
{
	SystemClockInit();
	//UART_Init();
	GPIO_Init();
	EXTI_Init();
	//uint8_t rxData[5] = "";
	NVIC_EnableIRQ(EXTI0_IRQn);/* cho phep ngat EXTI0 hoat dong */
	__enable_irq(); /* CHo phep ngat tren CPU (global interrupt) */
	while(1)
	{
		//UartRxMsg(rxData, 5);
		//count = 1;
#if defined (USE_MY_BOARD)
//		GPIOA->ODR |= 1<<1;
//		delay(0x1FFFF);
//		GPIOA->ODR &= ~(1<<1);
//		delay(0x1FFFF);
		if((GPIOA->IDR & 1<<8) == 0) /* Press button */
		{
			GPIOA->ODR ^= (1<<1);
			while((GPIOA->IDR & 1<<8) == 0); /* while if bt is pressing */
		}
#else
//		GPIOC->ODR |= 1<<13;
//		delay(0xFFFF);
//		GPIOC->ODR &= ~(1<<13);
//		delay(0xFFFF);
//		if((GPIOA->IDR && (1<<0)) == 0) /* Press button */
//		{
//			GPIOC->ODR &= ~(1<<13);
//		}
//		else
//		{
//			GPIOC->ODR |= 1<<13;
//		}
#endif
	}
}
/*****************************************************/
