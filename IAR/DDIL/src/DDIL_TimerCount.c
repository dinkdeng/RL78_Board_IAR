#include "DDIL_TimerCount.h"

DDIL_TIMER_COUNT_STRUCT DDIL_TimerCountObject[DDIL_TIMER_COUNT_NUM] = { 0 };

/*驱动注册*/
DDIL_ERROR_CODE DDIL_TimerCount_Register(DDIL_TIMER_COUNT_INDEX index, DDIL_TimerCount_Init_FuncPtr init,
    DDIL_TimerCount_Start_FuncPtr start, DDIL_TimerCount_Stop_FuncPtr stop)
{
    if (index >= DDIL_TIMER_COUNT_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    DDIL_TimerCountObject[index].init = init;
    DDIL_TimerCountObject[index].start = start;
    DDIL_TimerCountObject[index].stop = stop;
    return DDIL_ERROR_NONE;
}

/*初始化*/
DDIL_ERROR_CODE DDIL_TimerCount_Init(DDIL_TIMER_COUNT_INDEX index, DDIL_TimerCount_CallBack_FuncPtr callBackPtr)
{
    if (index >= DDIL_TIMER_COUNT_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_TimerCountObject[index].init == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_TimerCountObject[index].init(callBackPtr);
}

/*启动定时器*/
DDIL_ERROR_CODE DDIL_TimerCount_Start(DDIL_TIMER_COUNT_INDEX index)
{
    if (index >= DDIL_TIMER_COUNT_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_TimerCountObject[index].start == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_TimerCountObject[index].start();
}

/*停止定时器*/
DDIL_ERROR_CODE DDIL_TimerCount_Stop(DDIL_TIMER_COUNT_INDEX index)
{
    if (index >= DDIL_TIMER_COUNT_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_TimerCountObject[index].stop == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_TimerCountObject[index].stop();
}




