#include "stm32f1xx.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "queue.h"
#include "event_groups.h"
#include "stream_buffer.h"
/*****************************************************/
#define msg "Hello World!\n\r"
int count = 0;
/*****************************************************/
void SystemClockInit(void)
{
	RCC->CR |= 1<<0; /* enable HSI clock */
	while((RCC->CR & (uint32_t)(1<<1)) == 0);
	RCC->APB2ENR |= (uint32_t)(1<<0); /* Alternate Function I/O clock enabled */
	RCC->APB2ENR |= (uint32_t)(1<<2);/* I/O port A clock enable */
	RCC->APB2ENR |= (uint32_t)(1<<14);/* USART1 clock enabled */
}
/*****************************************************/
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);
/*****************************************************/
void GPIO_Init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRH &=~ (0xF << 20);	/*PC13:Clear all default options */
	GPIOC->CRH |= (0b0110<<20); /*PC13: General purpose output Open-drain and Output mode, max speed 2 MHz*/
}

int main(void)
{
	SystemClockInit();
	GPIO_Init();
	xTaskCreate(vTask1, "Task_1", 256, NULL, 1, NULL);
	xTaskCreate(vTask2, "Task_2", 256, NULL, 2, NULL);
	vTaskStartScheduler();
	while(1)
	{

	}
}
/*****************************************************/
/******************************************************************************/
void vTask1 (void *pvParameters)
{
	while(1)
	{
		GPIOC->ODR |= 1<<13;
		vTaskDelay(300);
	}
}

/******************************************************************************/
void vTask2 (void *pvParameters)
{
	while(1)
	{
		GPIOC->ODR |= 1<<13;
		vTaskDelay(150);
	}
}
