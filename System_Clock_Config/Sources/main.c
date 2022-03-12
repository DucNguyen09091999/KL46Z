

#include "MKL46Z4.h"

void FEI_Mode(void) //FLL Engaged Internal
{
	MCG->C1 &= ~(MCG_C1_CLKS_MASK);
	MCG->C1 |= (MCG_C1_IREFS_MASK);
	MCG->C6 &= ~(MCG_C6_PLLS_MASK);
	MCG->C4 |= (MCG_C4_DMX32_MASK);
	MCG->C4 &= ~(MCG_C4_DRST_DRS_MASK);
	MCG->C4 |=  1 << MCG_C4_DRST_DRS_MASK;

}

void FEE_Mode(void) // FLL Engaged External
{
	MCG->C1 &= ~(MCG_C1_CLKS_MASK);
	MCG->C1 &= ~(MCG_C1_IREFS_MASK);
	MCG->C4 &= ~(MCG_C4_DMX32_MASK);
	MCG->C4 &= ~(MCG_C4_DRST_DRS_MASK);
	MCG->C4 |=  (0x1UL << (5));
}

void

void FBE_Mode(void) // PLL Bypassed External
{
	MCG->C1 &= ~(MCG_C1_CLKS_MASK);
	MCG->C1 |= (0x2UL << (6U));
	MCG->C1 &= ~(MCG_C1_IREFS_MASK);
	MCG->C1 &= ~(MCG_C1_FRDIV_MASK);
	MCG->C4 &= ~(MCG_C4_DRST_DRS_MASK);
	MCG->C4 |= (0x1UL <<(5U));

}
void System_Clock_Init(void)
{
	FEI_Mode();
	SIM->SCGC5 |= (0x1UL << (12U));

}

void GPIO_Init(void)
{
	PORTD->PCR[5] |= (0x1UL << (8U));
	GPIOD->PDDR |= (0x1UL << (5U));

}

void Blink_Led()
{
	GPIO->PDOR ^= (0x1UL << (5U));
}

int main(void)
{
	SystemCoreClockUpdate();
	System_Clock_Init();
	GPIO_Init();

	while(1)
	{

	}
    return 0;
}

