#ifndef _CG_LCD_
#define _CG_LCD_
#include <stdint.h>
#include "r_cg_port.h"

#define LCD_LINE1_POS 60

#define LCD_LINE1 (char*)gLineBuffer1

#define LCD_LINE_WIDTH 14

/* LCD Line buffer*/
extern volatile char gLineBuffer1[LCD_LINE_WIDTH];

void DisplayString(char *lineBuffer, const char* text);
void RepaintLCD();
void InitialiseDisplay();

/* LEDs */
extern uint8_t LEDPort[];
extern uint8_t LEDPin[];

#define LED_ON(X) R_GPIO_SetLow(LEDPort[X], LEDPin[X])
#define LED_OFF(X) R_GPIO_SetHigh(LEDPort[X], LEDPin[X])
#define LED_TOGGLE(X) R_GPIO_Toggle(LEDPort[X], LEDPin[X])

#endif
