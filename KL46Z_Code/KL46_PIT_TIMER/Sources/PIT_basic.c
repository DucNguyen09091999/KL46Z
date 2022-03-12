/*
 * File:		PIT_basic.c
 * Purpose:		Initialized PIT to create a 1msec periodic interrupt
 *                      
 */

#include "MKL46Z4.h"
#include "freedom_gpio.h" //define LED and SW on freedom board as LED1, LED2, SW1, etc
#include "io.h" // printf declaration without all the baggage 
#include "sysinit.h" // declaration of enable irq

#define PIT_INTERRUPT_PERIOD  24000000/1000  //busclock Fr Hz /target Freq Hz


uint32_t base_time;


/**   PIT_init
 * \brief    Initialize PIT to create a periodic interrupt timer, PIT is clocked by busclock 24MHZ
 * \brief    
 * \brief   Timer start count when enabled in descending
 * \param    none
 * \return   none
 */  
void Pit_init(void)
{
    SIM_SCGC6 |= SIM_SCGC6_PIT_MASK; // enable PIT module
    
    /* Enable PIT Interrupt in NVIC*/   
    enable_irq(38 - 16);
       
    PIT_MCR  =  !PIT_MCR_MDIS_MASK | !PIT_MCR_FRZ_MASK;   // MDIS = 0  enables timer;  FRZ=1 Timer stops in debug mode
    PIT_TCTRL1 =  !PIT_TCTRL_TEN_MASK | !PIT_TCTRL_TIE_MASK | !PIT_TCTRL_CHN_MASK; //Disable timer
    PIT_LDVAL1 = PIT_INTERRUPT_PERIOD; // 1msec = BusClock 
    PIT_TFLG1  =   PIT_TFLG_TIF_MASK; // (w1c) clear flag in case there is a pending flag
    PIT_TCTRL1 |= PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK; 
   
}

/**   PIT_isrv
 * \brief    Periodic interrupt Timer 1.  Interrupt service
 * \brief    PIT1 is used for tone/buzzer time control
 * \param    none
 * \return   none
 */  

void PIT_IRQHandler(void)
{  
    static uint8_t  base_count_125m=125;
    PIT_TFLG1 = PIT_TFLG_TIF_MASK; // clear PIT flag by writing one
    //Put your code here
    
    if (base_count_125m)base_count_125m--;
    else
    {
      base_count_125m=125; //restart base time counter       
      base_time++;   // created a base time  .125 .250  0.5 1 2 seconds
    }
}

/********************************************************************/
int main (void)
{
	char ch;
	gpio_init();
	Pit_init();
	LED1_ON;
	LED2_ON;
	LED1_OFF;
	LED2_OFF;
	printf("\n\rRunning the PIT_basic project.\n\r");
	while(1)
	{
		if (base_time & 0x02) LED1_ON;
		else LED1_OFF;
	} 
}
/********************************************************************/
