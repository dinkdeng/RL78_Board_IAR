/*
*******************************************************************************
** Pragma directive
*******************************************************************************
*/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/*
*******************************************************************************
** Include files
*******************************************************************************
*/
#include "r_cg_macrodriver.h"
#include "r_cg_port.h"
#include "lcd.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/* LEDs */
uint8_t LEDPort[] = {
  5, // RLED1
  6, // RLED2
  6, // RLED3
  5, // GLED1
  5, // GLED2
  5, // GLED3
};

uint8_t LEDPin[] = {
  5, // RLED1
  2, // RLED2
  3, // RLED3
  2, // GLED1
  3, // GLED2
  4, // GLED3
};

/* LCD Line buffers */
volatile char gLineBuffer1[LCD_LINE_WIDTH] = "             ";

void DisplayString(char *lineBuffer, const char* text)
{
  int i = 0;
  while(text[i] != '\0' && i < LCD_LINE_WIDTH - 1)
  {
    lineBuffer[i] = text[i];
    i++;
  }
  lineBuffer[i] = '\0';
}

void RepaintLCD()
{
  LCDString((char const*)gLineBuffer1, 10, LCD_LINE1_POS);
}

void InitialiseDisplay()
{
  /* Start user code. Do not edit comment generated here */
  LCDInit();
  LCDFont(FONT_LOGOS);
  LCDChar(0, (LCD_W-80)-10, 0);
  LCDFont(FONT_SMALL);
  LCDString("RL78 RDK", LCDRight(8)-10, 20);
}