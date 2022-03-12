
#include "mcg.h"

uint32_t getMCGMode()
{
	int IREFS = (MCG->S & MCG_S_IREFST_MASK) >> MCG_S_IREFST_SHIFT;
	int CLKS = (MCG->S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT;
	int PLLS = (MCG->S & MCG_S_PLLST_MASK) >> MCG_S_PLLST_SHIFT;
	int LP = (MCG->C2 & MCG_C2_LP_MASK) >> MCG_C2_LP_SHIFT;
	
	if(CLKS == 0) return emcgmFEE;
	
	if(CLKS == 3) return emcgmPEE;
	
	if(CLKS == 1)
	{
		if(LP == 1) return emcgmBLPI;
		return emcgmFBI;
	}
	
	if(LP == 1) return emcgmBLPE;
	
	if(PLLS == 1) return emcgmPBE;
	
	return emcgmFBE;
}

uint32_t initMCG(uint32_t crystal_val, uint8_t drst_drs, uint8_t dmx32, uint8_t frdiv_val, uint8_t lp_mode, uint8_t clks)
{
	int i=0;
	int mcgMode = getMCGMode();
	unsigned int return_value=0;
	
	MCG->C2 |= MCG_C2_RANGE0(1);
	MCG->C2 |= MCG_C2_HGO0_MASK;
	MCG->C2 |= MCG_C2_EREFS0_MASK;
	
	MCG->C1 |= MCG_C1_CLKS(2);
	MCG->C1 |= MCG_C1_FRDIV(3);
	MCG->C1 &= (~MCG_C1_IREFS_MASK);
	
	for(i=0; (MCG->S & (~MCG_S_OSCINIT0_MASK) >> MCG_S_OSCINIT0_SHIFT != 1); i++)
	{
		if(i >= 2000)
		{
			return -1;
		}
	}
	for(i=0; (MCG->S & (~MCG_S_IREFST_MASK) >> MCG_S_IREFST_SHIFT != 0); i++)
	{
		if(i >= 2000)
		{
			return -1;
		}
	}
	
	for(i=0; (MCG->S & MCG_S_CLKST_MASK >> MCG_S_CLKST_SHIFT != 2); i++)
	{
		if(i >= 2000)
		{
			return -1;
		}
	}

	MCG->C5 |= MCG_C5_PRDIV0(3);
        /* If a transition through BLPE mode is desired, first set C2[LP] to 1.
	 */
	MCG->C2 |= MCG_C2_LP_MASK;

	MCG->C6 |= MCG_C6_PLLS_MASK;
	MCG->C6 |= MCG_C6_VDIV0(0);
	MCG->C2 &= ~MCG_C2_LP_MASK;

	for(i=0; (MCG->S & MCG_S_PLLST_MASK >> MCG_S_PLLST_SHIFT != 1); i++)
	{
		if(i >= 2000)
		{
			return -1;
		}
	}
	for(i=0; (MCG->S & MCG_S_LOCK0_MASK >> MCG_S_LOCK0_SHIFT != 1); i++)
	{
		if(i >= 2000)
		{
			return -1;
		}
	}
	MCG->C1 &= ~MCG_C1_CLKS_MASK;

	for(i=0; (MCG->S & MCG_S_CLKST_MASK >> MCG_S_CLKST_SHIFT != 3); i++)
	{
		if(i >= 2000)
		{
			return -1;
		}
	}
	return return_value;
}
