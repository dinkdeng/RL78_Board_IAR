#include "TimerCount.h"
#include "MacroDriver.h"
#include "RL78G13_Int.h"
#include "RL78G13_Port.h"
#include "RL78G13_Timer.h"
#include "RL78G13_Clock.h"

DDIL_TimerCount_CallBack_FuncPtr timerCountCallBackFunc = NULL;


void TimerCountCallBack(void)
{
    /*LED0循环翻转*/
    (P4_bit.no1) = !(P4_bit.no1);
}


DDIL_ERROR_CODE TimerCount_Init(DDIL_TimerCount_CallBack_FuncPtr callBackFunc)
{
    /*首先使能TAU0时钟*/
    RL78G13_Clock_PER0_Enable(RL78G13_CLOCK_PER0_TAU0EN);
    /*设置单元输出时钟 16M 64分频 250K*/
    RL78G13_Timer_TPS_Write_All(RL78G13_TIMER_TPS_CLK00_DIV_64,
        RL78G13_TIMER_TPS_CLK01_DIV_1, RL78G13_TIMER_TPS_CLK02_DIV_2, RL78G13_TIMER_TPS_CLK03_DIV_2);
    /*停止全部的通道*/
    RL78G13_Timer_TT_Write_All(RL78G13_TIMER_TT_CHANNEL0_STOP_ON, RL78G13_TIMER_TT_CHANNEL1_STOP_ON,
        RL78G13_TIMER_TT_CHANNEL2_STOP_ON, RL78G13_TIMER_TT_CHANNEL3_STOP_ON, RL78G13_TIMER_TT_CHANNEL4_STOP_ON,
        RL78G13_TIMER_TT_CHANNEL5_STOP_ON, RL78G13_TIMER_TT_CHANNEL6_STOP_ON, RL78G13_TIMER_TT_CHANNEL7_STOP_ON,
        RL78G13_TIMER_TT_CHANNEL_H1_STOP_ON, RL78G13_TIMER_TT_CHANNEL_H3_STOP_ON);
    /*禁止单元0通道0中断并清除单元0通道0触发标志*/
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM00, RL78G13_INT_STATUS_DISABLE);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM00);
    /*禁止单元0通道1中断并清除单元0通道0触发标志*/
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM01, RL78G13_INT_STATUS_DISABLE);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM01);
    /*禁止单元0通道2中断并清除单元0通道0触发标志*/
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM02, RL78G13_INT_STATUS_DISABLE);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM02);
    /*禁止单元0通道3中断并清除单元0通道0触发标志*/
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM03, RL78G13_INT_STATUS_DISABLE);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM03);
    /*禁止单元0通道4中断并清除单元0通道0触发标志*/
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM04, RL78G13_INT_STATUS_DISABLE);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM04);
    /*禁止单元0通道5中断并清除单元0通道0触发标志*/
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM05, RL78G13_INT_STATUS_DISABLE);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM05);
    /*禁止单元0通道6中断并清除单元0通道0触发标志*/
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM06, RL78G13_INT_STATUS_DISABLE);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM06);
    /*禁止单元0通道7中断并清除单元0通道0触发标志*/
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM07, RL78G13_INT_STATUS_DISABLE);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM07);
    /*设置通道00处于最低优先级*/
    RL78G13_Int_Pri_Write(RL78G13_INT_SRC_TM00, RL78G13_INT_PRI_3);
    /*设置单元0通道0模式*/
    RL78G13_Timer_TMR_Write_All(RL78G13_TIMER_CHANNEL_0, RL78G13_TIMER_TMR_CLOCK_SELECT_CLK0,
        RL78G13_TIMER_TMR_CCS_FTCLK_SELECT_MCK, RL78G13_TIMER_TMR_SPLIT_SELECT_16BIT,
        RL78G13_TIMER_TMR_STS_TRIG_SRC_SELECT_SOFT, RL78G13_TIMER_TMR_CIS_TRIG_EDGE_SELECT_FALLING,
        RL78G13_TIMER_TMR_CHANNEL_MODE_SELECT_COUNT, RL78G13_TIMER_TMR_START_INT_DISABLE);
    /*设置计数值 250K时钟下,计数25000,100毫秒*/
    TDR00 = 25000;
    /*设置端口0输出0*/
    RL78G13_Timer_TO_Write_One(RL78G13_TIMER_TO_CHANNEL_0_OUTPUT_VALUE_MASK,
        RL78G13_TIMER_TO_CHANNEL_0_OUTPUT_VALUE_0);
    /*设置端口0输出禁止*/
    RL78G13_Timer_TOE_Write_One(RL78G13_TIMER_TOE_CHANNEL_0_OUTPUT_SET_MASK,
        RL78G13_TIMER_TOE_CHANNEL_0_OUTPUT_SET_DISABLE);
    /*建立函数指针连接*/
    timerCountCallBackFunc = callBackFunc;

    return DDIL_ERROR_NONE;
}

/*启动计数*/
DDIL_ERROR_CODE TimerCount_Start(void)
{
    /*清除中断标志,使能中断*/
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM00);
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM00, RL78G13_INT_STATUS_ENABLE);
    /*启动定时器计数*/
    RL78G13_Timer_TS_Write_One(RL78G13_TIMER_TS_CHANNEL0_START_ON_MASK,
        RL78G13_TIMER_TS_CHANNEL0_START_ON);
    return DDIL_ERROR_NONE;
}

/*停止计数*/
DDIL_ERROR_CODE TimerCount_Stop(void)
{
    /*停止计数器计数,禁止中断,清除中断标志*/
    RL78G13_Timer_TT_Write_One(RL78G13_TIMER_TT_CHANNEL0_STOP_ON_MASK,
        RL78G13_TIMER_TT_CHANNEL0_STOP_ON);
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_TM00, RL78G13_INT_STATUS_DISABLE);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_TM00);
    return DDIL_ERROR_NONE;
}

/*定时器单元0中断处理函数*/
#pragma vector = INTTM00_vect
__interrupt void Timer_Unit0_Channel0_Process(void)
{
    /*LED0循环翻转*/
    if (timerCountCallBackFunc != NULL)
    {
        timerCountCallBackFunc();
    }
}

