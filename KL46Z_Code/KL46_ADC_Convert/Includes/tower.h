/*
 * File:        tower.h
 * Purpose:     Kinetis tower CPU card definitions
 *
 * Notes:
 */

#ifndef __TOWER_H__
#define __TOWER_H__

#include "mcg.h"
/********************************************************************/

/* Global defines to use for all Tower cards */
#define DEBUG_PRINT

// Define which CPU  you are using.  
#define CPU_MKL46Z256VMC4

/*
* Input Clock Info
*/
#define CLK0_FREQ_HZ        8000000
#define CLK0_TYPE           CRYSTAL

// Uncomment this next line if you desire the clock output
//#define ENABLE_CLKOUT


/*
   * PLL Configuration Info
   */
  //#define NO_PLL_INIT  // define this to skip PLL initilaization and stay in default FEI mode

/* The expected PLL output frequency is:
 * PLL out = (((CLKIN/PRDIV) x VDIV) / 2)
 * where the CLKIN is CLK0_FREQ_HZ.
 *
 * For more info on PLL initialization refer to the mcg driver files.
 */

  #define PLL0_PRDIV      4       // divide reference by 4 = 2 MHz
  #define PLL0_VDIV       24      // multiply reference by 24 = 48 MHz

  /* Serial Port Info */

  /**************************************************************************
   * Note:
   * 
   * Because of the changes to the UART modules, we can no longer define
   * the TERM_PORT as a base pointer.  The uart functions have been modified 
   * accommodate this change.  Now, TERM_PORT_NUM must be defined as the 
   * number of the UART port desired to use
   *
   * TERM_PORT_NUM = 0  -- This allows you to use UART0; default pins are
   *						PTA14 and PTA15
   *
   * TERM_PORT_NUM = 1  -- This allows you to use UART1; default pins are
   *						PTC3 and PTC4
   * 
   * TERM_PORT_NUM = 2  -- This allows you to use UART2; default pins are
   *						PTD2 and PTD3
   *
   *************************************************************************/
#ifdef  TWR_REVA
 #define TERM_PORT_NUM       0
#else
 #define TERM_PORT_NUM       2
#endif

#define TERM_OUT            0   //0 

#define FREEDOM
#define TERM_PORT		UART2_BASE_PTR
#define TERMINAL_BAUD       115200
#undef  HW_FLOW_CONTROL



#endif /* __TOWER_H__ */
