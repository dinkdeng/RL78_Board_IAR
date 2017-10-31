#ifndef __DDIL_TIMERCOUNT_H_
#define __DDIL_TIMERCOUNT_H_
#include "DDIL_ErrorCode.h"
#include "DDIL_TimerCount_Config.h"

/*函数指针定义区域*/

/*定时器初始化*/
typedef DDIL_ERROR_CODE(*DDIL_TimerCount_Init_FuncPtr)(DDIL_TimerCount_CallBack_FuncPtr callBackPtr);
/*启动计数*/
typedef DDIL_ERROR_CODE(*DDIL_TimerCount_Start_FuncPtr)(void);
/*停止计数*/
typedef DDIL_ERROR_CODE(*DDIL_TimerCount_Stop_FuncPtr)(void);

/*函数指针结构体定义*/
typedef struct DDIL_TIMER_COUNT_STRUCT
{
    DDIL_TimerCount_Init_FuncPtr init;
    DDIL_TimerCount_Start_FuncPtr start;
    DDIL_TimerCount_Stop_FuncPtr stop;
}DDIL_TIMER_COUNT_STRUCT;

/*函数定义*/

/*驱动注册*/
DDIL_ERROR_CODE DDIL_TimerCount_Register(DDIL_TIMER_COUNT_INDEX index, DDIL_TimerCount_Init_FuncPtr init,
    DDIL_TimerCount_Start_FuncPtr start, DDIL_TimerCount_Stop_FuncPtr stop);

/*初始化*/
DDIL_ERROR_CODE DDIL_TimerCount_Init(DDIL_TIMER_COUNT_INDEX index, DDIL_TimerCount_CallBack_FuncPtr callBackPtr);

/*启动定时器*/
DDIL_ERROR_CODE DDIL_TimerCount_Start(DDIL_TIMER_COUNT_INDEX index);

/*停止定时器*/
DDIL_ERROR_CODE DDIL_TimerCount_Stop(DDIL_TIMER_COUNT_INDEX index);


#endif




