#ifndef __MAIN_INC_H_
#define __MAIN_INC_H_

extern void mainCallBackLed();

extern void mainCallBackBeep();

extern void mainCallBackUart0();

extern void mainCallBackExtKey();

extern void mainCallBackTimerCount();

extern void mainCallBackADC();

#define MAIN_CALL_FUNC()    mainCallBackADC();

#endif




