#include "stm32f1xx.h"

void SystemClockInit(void)
{
  RCC->CR |= RCC_CR_HSION_Msk;
    while((RCC->CR & RCC_CR_HSIRDY_Msk) != RCC_CR_HSIRDY_Msk);
    RCC->CFGR &= ~(RCC_CFGR_SW_0|RCC_CFGR_SW_1);


}


int main()
{
	SystemClockInit();
	while(1)
	{

	}
	return 0;
}
