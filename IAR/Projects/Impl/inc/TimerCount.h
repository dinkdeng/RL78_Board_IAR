#ifndef __TIMER_COUNT_H_
#define __TIMER_COUNT_H_
#include "DDIL_TimerCount_Config.h"

extern DDIL_TimerCount_CallBack_FuncPtr timerCountCallBackFunc;

/*初始化*/
DDIL_ERROR_CODE TimerCount_Init(DDIL_TimerCount_CallBack_FuncPtr callBackFunc);

/*启动计数*/
DDIL_ERROR_CODE TimerCount_Start(void);

/*停止计数*/
DDIL_ERROR_CODE TimerCount_Stop(void);


/*中断回调函数*/
void TimerCountCallBack(void);

#endif




