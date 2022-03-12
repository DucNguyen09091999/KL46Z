/*
 * File:		sLCD_freedom.c
 * Purpose:		Main process
 *
 */

#include "MKL46Z4.h"
#include "lcd.h"
#include "io.h"

char chBufDisp[10];

/********************************************************************/
int main (void)
{
	int  delay;
	int  count;
	printf("\n\rRunning the sLCD_freedom project.\n\r");
	vfnLCD_Init();
	vfnLCD_Write_Msg("1234");
        
	while(1)
	{
		count++;
		if (count>9999) count=0;
		for (delay=0; delay<500000; delay++);
		sprintf(chBufDisp,"%04i",count);
		vfnLCD_Write_Msg((uint8_t *)chBufDisp);
	} 
}
/********************************************************************/
