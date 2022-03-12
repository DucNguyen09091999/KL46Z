#include "mcg.h"
#include "uart.h"
#include <MKL46Z4.h>

int main(void)
{
	uint8_t ch;
	SIM->SCGC5 |= (SIM_SCGC5_PORTA_MASK
		  | SIM_SCGC5_PORTB_MASK
		  | SIM_SCGC5_PORTC_MASK
		  | SIM_SCGC5_PORTD_MASK
		  | SIM_SCGC5_PORTE_MASK );
	initMCG(0, 1, 1, 1, 1, 1);
    PORTA->PCR[1]= PORT_PCR_MUX(0x2);// Chuyen chan PAT1 sang che do uart
	PORTA->PCR[2]= PORT_PCR_MUX(0x2);// Chuyen chan PAT2 sang che do uart
	SIM->SOPT2 = (SIM->SOPT2 & ~SIM_SOPT2_UART0SRC_MASK) | SIM_SOPT2_UART0SRC(1);
	SIM->SOPT2 = (SIM->SOPT2 & ~SIM_SOPT2_PLLFLLSEL_MASK) | SIM_SOPT2_PLLFLLSEL_MASK;
	uart0_init(24000, 115200);
    while(1)
    {
		USART0_putstr("Hello members of the EP0920E class \n");
		ch= uart0_getchar();
		uart0_putchar(ch);
    }
}
