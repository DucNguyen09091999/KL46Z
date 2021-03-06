
#include "derivative.h"
#include "LCDConfig.h"   // indicates how LCD module is configured and what type of LCD is going to be used 7seg, 14-seg, 16 seg, DotMatrix etc


#define LCD_ALTERNATE_MODE    4   // Write message to Alternate Backplanes
#define LCD_NORMAL_MODE       0   // Write message to Original BackPlanes 


/* variables */
extern uint32_t __VECTOR_RAM[]; //Get vector table that was copied to RAM

extern const uint32_t MASK_BIT[];  
extern const uint32_t *LCD_TO_PORT[];


#if _LCDINTENABLE == 1
  extern void LcdInterruptCallBack(void);
#endif
  
/*||||||||||||||||||||||       vfnLCD_Init            ||||||||||||||||||||||
brief:  Initialize all the registers on the mcu module 
param:  void                            return:  void    
*/  
void vfnLCD_Init  (void);


void vfnLCD_Home (void);
 /*||||||||||||||||||||||       vfnLCD_Write_Char   ||||||||||||||||||||||
 brief:  Writes on char after the last character was write
 param:  uint8_t --- Ascii to write                            return:  void    
*/
void vfnLCD_Write_Char (uint8_t lbValue);

/*
   Send a message until a end of char or max number of characters
   if the message size is greater than LCD character the message is cut ad the size of LCD Characters
   If the message lenght is minor than Display character is filled with Blanks
 */
void  vfnLCD_Write_Msg (uint8_t *lbpMessage);


 /*||||||||||||||||||||||       vfnLCD_Scroll    ||||||||||||||||||||||
brief:  Moves the message on the LCD 
param:  uint8_t pointer --- the first character  on the array to write
param: uint8_t --- the size of the character  
return:  void    
*/


 /*||||||||||||||||||||||       vfnLCD_Write_Msg    ||||||||||||||||||||||
brief:  Writes on message on the LCD   if the message is longer than the number of character  is send to the Scroll function
param:  uint8_t pointer --- the first character  on the array to write
param: uint8_t --- the numbers of characterts to write      
return:  void    
*/
void  vfnLCD_Write_MsgPLace (uint8_t *lbpMessage, uint8_t lbSize );



void vfnLCD_Scroll (uint8_t *lbpMessage,uint8_t lbSize);
 /*||||||||||||||||||||||       vfnLCD_All_Segments_ON   ||||||||||||||||||||||
brief: Turns on all the segments on the LCD
param:  uint8_t pointer --- the first character  on the array to write
param: uint8_t --- the size of the character  
return:  void    
*/



void vfnLCD_All_Segments_ON (void);
                                                                                                      
/*Same as clear dispay */
void vfnLCD_All_Segments_OFF (void);
  


/* functions for DOT matrix LCD panel only*/
void vfnLCD_All_Segments_Char (uint8_t val);
void PutPoint(uint8_t x, uint8_t y);
void ClrPoint(uint8_t x, uint8_t y);
void SetX(uint8_t x, uint8_t value);


extern char  lcdBuffer[];


extern uint8_t lcd_alternate_mode;


void LCD_vector_interrupt_init(void);
extern void lcd_pinmux(uint8_t  mux_val);  //only 0 or 7 is allowed

extern void vfnBP_VScroll(int8_t scroll_count);

 // LCD call samples
 //  vfnLCD_Home();
 //  vfnLCD_Write_Char ('0');
 //  vfnLCD_All_Segments_ON();
 //  vfnLCD_All_Segments_OFF();
 //  vfnLCD_Write_Msg("@@@@@@@@@");  // TURN ON all characters
 //  vfnLCD_All_Segments_OFF();



/*{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{        Macros            }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}*/
/*{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{   ----------------------------  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}*/

#define LCD_ENABLE()        (LCD_GCR |=  LCD_GCR_LCDEN_MASK)
#define LCD_DISABLE()       (LCD_GCR &= ~LCD_GCR_LCDEN_MASK) 
#define LCD_VTRIM(x)        (LCD_GCR &= ~LCD_GCR_RVTRIM_MASK; LCD_GCR |= LCD_GCR_RVTRIM(x));







/*{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{        Functions        }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}*/
/*{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{   ----------------------------  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}*/



/*||||||||||||||||||||||       vfnLCD_EnablePins   ||||||||||||||||||||
brief: Enable all the pins of the mcu directly connected to the  LCD on use
param:  void                            return:  void    
*/  
void vfnEnablePins (void);

 /*||||||||||||||||||||||       vfnLCD_SetBackplanes ||||||||||||||
brief:  Set as a backplane and give the number of COM that corresponds  
param:  void                            return:  void    
*/
void vfnSetBackplanes (void);

/*||||||||||||||||||||||       vfnLCD_Home            ||||||||||||||||||||||
brief:  Reset the counter to the first position
param:  void
return:  void    
*/  



void vfnLCD_interrupt_init(void);
