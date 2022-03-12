/*
 * File:		adc_demo.c
 * Purpose:		Main process
 *
 */

#include "derivative.h"
#include "adc16.h"
#include "uart.h"
#include "tower.h"
#include "io.h"
/*****************************************************************************************************
* Definition of module wide VARIABLEs - NOT for use in other modules
****************************************************************************************************/
// ADC configuration variable  keeps configuration parameters, can be used for reconfiguration or use in with different ADCs)
tADC_Config  Master_Adc_Config;
uint16_t adc_isrv_result;

#ifdef FREEDOM
#define BOARD_SENSOR_ADC   3  //ADC0_SE3   light sensor
#endif
#ifdef TOWER
#define BOARD_SENSOR_ADC   4  //PTE29/ADC0_SE4B  Potentiometer
#endif
/*
  This function calibrate and prepare adc for reading, none adc reading is started
*/
void init_ADC16(void)
{

	// Turn on the ADC0 clock
	SIM_SCGC6 |= (SIM_SCGC6_ADC0_MASK );
	 //data that will be stored at ADCx_CFG1
	Master_Adc_Config.CONFIG1  = (  ADLPC_LOW
								  | ADC_CFG1_ADIV(ADIV_1)
								  | ADLSMP_LONG
								  | ADC_CFG1_MODE(MODE_16)
								  | ADC_CFG1_ADICLK(ADICLK_BUS));



	//ADCx_CFG2
	#ifdef FREEDOM
	Master_Adc_Config.CONFIG2  = MUXSEL_ADCA   //A for FREEDOM
								  | ADACKEN_DISABLED
								  | ADHSC_HISPEED
								  | ADC_CFG2_ADLSTS(ADLSTS_20) ;
	#endif

	#ifdef TOWER
	Master_Adc_Config.CONFIG2  = MUXSEL_ADCB   //A for FREEDOM
	  | ADACKEN_DISABLED
	  | ADHSC_HISPEED
	  | ADC_CFG2_ADLSTS(ADLSTS_20) ;
	#endif
	Master_Adc_Config.COMPARE1 = 0x1234u ;                 // can be anything
	Master_Adc_Config.COMPARE2 = 0x5678u ;                 // can be anything
	// since not using
	// compare feature
	Master_Adc_Config.STATUS2  = ADTRG_SW
								  | ACFE_DISABLED
								  | ACFGT_GREATER
								  | ACREN_DISABLED
								  | DMAEN_DISABLED
								  | ADC_SC2_REFSEL(REFSEL_EXT);

	Master_Adc_Config.STATUS3  = CAL_OFF
								  | ADCO_SINGLE
								  | !AVGE_ENABLED
								  | ADC_SC3_AVGS(AVGS_4);

	Master_Adc_Config.STATUS1A = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(31);

	// Configure ADC as it will be used, but becuase ADC_SC1_ADCH is 31,
	// the ADC will be inactive.  Channel 31 is just disable function.
	// There really is no channel 31.

	ADC_Config_Alt(ADC0_BASE_PTR, &Master_Adc_Config);  // config ADC


	// Calibrate the ADC in the configuration in which it will be used:
	ADC_Cal(ADC0_BASE_PTR);                    // do the calibration

	// The structure still has the desired configuration.  So restore it.
	// Why restore it?  The calibration makes some adjustments to the
	// configuration of the ADC.  They are now undone:

	// config the ADC again to desired conditions
	ADC_Config_Alt(ADC0_BASE_PTR, &Master_Adc_Config);
}

/*
    adc simple read   read a single channel as a configured in
    Sigle mode, no interruptions
    Note: before run this function make sure init_ADC16 has been executed
*/
uint16_t adc16_simple_read(uint8_t adc_channel)
{
	ADC0_SC1A = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(adc_channel);  // start conversion
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)){};                        // wait for conversion complete
	return ADC0_RA;

}

/**/

void adc16_start_conversion(uint8_t adc_channel)
{
	ADC0_SC1A = !AIEN_ON | DIFF_SINGLE | ADC_SC1_ADCH(adc_channel);  // start conversion
}


void ADC0_isrv(void)
{
	if (ADC0_SC1A & ADC_SC1_COCO_MASK)
	{
		adc_isrv_result = ADC0_RA;
	}

}


/********************************************************************/
int main (void)
{

    uint16_t adc_result;
  	uart_putstr(TERM_PORT, "\n\rRunning the adc_demo project.\n\r");
    init_ADC16();
	while(1)
	{

#ifdef FREEDOM
        adc_result=adc16_simple_read(BOARD_SENSOR_ADC);
        printf("\r  light sensor   =  %i", adc_result);
#else
        adc_result=adc16_simple_read(BOARD_SENSOR_ADC);
        printf("\r  potentiometer = %i", adc_result);
#endif
	}
}
/********************************************************************/
