#ifndef __DDIL_TIMERCOUNT_CONFIG_H_
#define __DDIL_TIMERCOUNT_CONFIG_H_
#include "DDIL_ErrorCode.h"

/*中断回调指针*/
typedef void(*DDIL_TimerCount_CallBack_FuncPtr)(void);

/*系统定时器用作普通定时的数量*/
#define DDIL_TIMER_COUNT_NUM      1

/*定时器序号*/
typedef enum DDIL_TIMER_COUNT_INDEX
{
    DDIL_TIMER_COUNT_INDEX_0 = 0,
}DDIL_TIMER_COUNT_INDEX;

#include "TimerCount.h"
#include "DDIL_TimerCount.h"


#endif





