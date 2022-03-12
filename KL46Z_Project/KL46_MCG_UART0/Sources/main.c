#include "MKL46Z4.h"
#include "stdlib.h"

void MCG_FEI(void);
void MCG_FEE(void);
void MCG_FBI(void);
void UART_Init(uint32_t sysclk, uint32_t baud_rate);
void UartTxMsg(uint8_t *data, uint8_t size);
void UartRxMsg(uint8_t *data, uint8_t size);
uint8_t UartRxByte(void);


uint8_t UartRxBuff[5];

void ClockInit(void)
{
	// set a safe value for divider
	SIM->CLKDIV1 |= SIM_CLKDIV1_OUTDIV4_MASK | SIM_CLKDIV1_OUTDIV1_MASK;
	MCG->C1 |= MCG_C1_IREFS_MASK; // Internal clock (32.768kHz) for FLL
	MCG->C4 |= MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(1);// 32.768 * 1464 = 47972.352kHz ~ 48MHz
	MCG->C1 &= ~MCG_C1_CLKS_MASK; // Output of FLL is selected for MCGOUTCLK
	while((MCG->S & MCG_S_IREFST_MASK) == 0); // wait for Internal clock is selected
	while((MCG->S & MCG_S_CLKST_MASK) != 0); // wait for FLL is selected
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1); /* MCGFLLCLK is selected for UART0 clock source */
}


int main(void)
{
    //set a safe value for divider
    SIM->CLKDIV1 |= SIM_CLKDIV1_OUTDIV4_MASK | SIM_CLKDIV1_OUTDIV1_MASK;
    MCG_FEI();
    MCG_FEE();
    SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1(1 - 1) |  // core/system clock = MCGOUTCLK / 1
                   SIM_CLKDIV1_OUTDIV4(2 - 1);   // flash/bus clock = core/system / 2
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
    SIM->SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; // MCGFLLCLK is selected for UART0 clock source
    SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);
    UART_Init(40000, 115200);
    while(1)
    {
        switch(UartRxByte())
        {
            case '0':
                MCG_FEI();
                UART_Init(48000, 115200);// UART0 clock Up to 48 MHz
                break;
            case '1':
                MCG_FEE();
                UART_Init(40000, 115200);// UART0 clock Up to 48 MHz
                break;
            case '2':
                MCG_FBI();
                SIM->SOPT2 |= SIM_SOPT2_UART0SRC(3); // UART0 clock source select MCGIRCLK clock
                UART_Init(4000, 115200);// UART0 clock Up to 48 MHz
                break;
        }
        UartTxMsg(UartRxBuff, 1);
    }
}

// switch to FEI 48MHz
void MCG_FEI(void)
{
    MCG->C1 |= MCG_C1_IREFS_MASK; // Internal clock (32.768kHz) for FLL
    MCG->C4 &= ~MCG_C4_DRST_DRS_MASK;
    MCG->C4 |= MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(1);// 32.768 * 1464 = 47972.352kHz ~ 48MHz
    MCG->C1 &= ~MCG_C1_CLKS_MASK; // Output of FLL is selected for MCGOUTCLK
    while((MCG->S & MCG_S_IREFST_MASK) == 0); // wait for Internal clock is selected
    while((MCG->S & MCG_S_CLKST_MASK) != 0); // wait for FLL is selected
}

// switch to FEE 40MHz
void MCG_FEE(void)
{
    MCG->C2 &= ~MCG_C2_RANGE0_MASK;
    MCG->C2 |= MCG_C2_RANGE0(3) |// Very high frequency range selected for the crystal oscillator
               MCG_C2_EREFS0_MASK |
               MCG_C2_HGO0_MASK ;

    MCG->C1 &= ~MCG_C1_FRDIV_MASK;
    MCG->C1 |= MCG_C1_FRDIV(3); // Divide Factor is 256. 8000 / 256 = 31.25kHz

    MCG->C1 &= ~MCG_C1_IREFS_MASK; // External clock (8MHz) for FLL

    MCG->C4 &= ~MCG_C4_DRST_DRS_MASK;
    MCG->C4 &= ~MCG_C4_DMX32_MASK;
    MCG->C4 |= MCG_C4_DRST_DRS(1);// 31.25 * 1280 = 40000kHz

    MCG->C6 &= ~MCG_C6_PLLS_MASK;// select FLL

    MCG->C1 &= ~MCG_C1_CLKS_MASK; // Output of FLL is selected for MCGOUTCLK

    while((MCG->S & MCG_S_OSCINIT0_MASK) == 0); // wait for osc init
    while((MCG->S & MCG_S_PLLST_MASK) != 0); // wait for FLL
    while((MCG->S & MCG_S_IREFST_MASK) != 0); // wait for External clock is selected
    while((MCG->S & MCG_S_CLKST_MASK) != 0); // wait for FLL is selected
}

// switch to FBI 4MHz
void MCG_FBI(void)
{
    MCG->SC &= ~MCG_SC_FCRDIV_MASK; // Divide Factor is 1

    MCG->C1 &= ~MCG_C1_CLKS_MASK;
    MCG->C1 |= MCG_C1_CLKS(1) |   // Internal reference clock is selected
               MCG_C1_IREFS_MASK |// Enable MCGIRCLK for uart0
               MCG_C1_IRCLKEN_MASK;

    MCG->C2 &= ~MCG_C2_LP_MASK;  // FLL or PLL is not disabled in bypass modes
    MCG->C2 |= MCG_C2_IRCS_MASK; // Fast internal reference clock selected

    MCG->C6 &= ~MCG_C6_PLLS_MASK;

    while((MCG->S & MCG_S_IRCST_MASK) == 0);
    while((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(1));
}

void UART_Init(uint32_t sysclk, uint32_t baud_rate)
{
    uint8_t i;
    uint32_t calculated_baud = 0;
    uint32_t baud_diff = 0;
    uint32_t osr_val = 0;
    uint32_t sbr_val, uart0clk;
    uint32_t reg_temp = 0;
    uint32_t temp = 0;

    /* Set Mux UART */
	PORTA->PCR[1]= 2<<8;
	PORTA->PCR[2]= 2<<8;

    SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
    UART0->C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
    // Change units to Hz
    uart0clk = sysclk * 1000;
    // Calculate the first baud rate using the lowest OSR value possible.
    i = 4;
    sbr_val = (uint32_t)(uart0clk/(baud_rate * i));
    calculated_baud = (uart0clk / (i * sbr_val));
    baud_diff = abs(calculated_baud - baud_rate);
    osr_val = i;
    // Select the bester OSR value
    for (i = 5; i <= 32; i++)
    {
        sbr_val = (uint32_t)(uart0clk/(baud_rate * i));
        calculated_baud = (uart0clk / (i * sbr_val));
        temp = abs(calculated_baud - baud_rate);
        if (temp <= baud_diff)
        {
            baud_diff = temp;
            osr_val = i;
        }
    }

    if (baud_diff < ((baud_rate / 100) * 3))
    {
        if ((osr_val >3) && (osr_val < 9))UART0->C5 |= UART0_C5_BOTHEDGE_MASK;
        // Setup OSR value
        reg_temp = UART0->C4;
        reg_temp &= ~UART0_C4_OSR_MASK;
        reg_temp |= UART0_C4_OSR(osr_val-1);
        // Write reg_temp to C4 register
        UART0->C4 = reg_temp;
        reg_temp = (reg_temp & UART0_C4_OSR_MASK) + 1;
        sbr_val = (uint32_t)((uart0clk)/(baud_rate * (reg_temp)));
         /* Save off the current value of the uartx_BDH except for the SBR field */
        reg_temp = UART0->BDH & ~(UART0_BDH_SBR(0x1F));
        UART0->BDH = reg_temp |  UART0_BDH_SBR(((sbr_val & 0x1F00) >> 8));
        UART0->BDL = (uint8_t)(sbr_val & UART0_BDL_SBR_MASK);
        /* Enable receiver and transmitter */
        UART0->C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK );
    }
    else
    {
    	while(1);
    }
}
void UartTxMsg(uint8_t *data, uint8_t size)
{
	uint8_t *pTX = (uint8_t*)&UART0->D;
	while(size--)
	{
		while((UART0->S1 & (1<<6)) == 0);
		*pTX = *data++;
	}

}

void UartRxMsg(uint8_t *data, uint8_t size)
{
	while(size--)
	{
		/* Wait until character has been received */
		while (!(UART0->S1 & UART0_S1_RDRF_MASK));
		/* Return the 8-bit data from the receiver */
		*data++ = UART0->D;
	}
}

uint8_t UartRxByte(void)
{
	/* Wait until character has been received */
	while ((UART0->S1 & (1<<5)) == 0);
	/* Return the 8-bit data from the receiver */
	return UART0->D;
}
