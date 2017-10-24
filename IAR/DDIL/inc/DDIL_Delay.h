#ifndef __DDIL_DELAY_H_
#define __DDIL_DELAY_H_
#include "DDIL_ErrorCode.h"
#include "DDIL_Delay_Config.h"

/*函数指针类型定义区域*/
typedef DDIL_ERROR_CODE(*DDIL_DelayInit_FuncPtr)(void);
typedef DDIL_ERROR_CODE(*DDIL_DelayMs_FuncPtr)(uint16_t nms);
typedef DDIL_ERROR_CODE(*DDIL_DelayUs_FuncPtr)(uint16_t nus);

/*驱动接口结构体定义(函数指针与数据集合)*/
typedef struct DDIL_DELAY_STRUCT
{
    DDIL_DelayInit_FuncPtr delayInit;
    DDIL_DelayMs_FuncPtr delayMs;
    DDIL_DelayUs_FuncPtr delayUs;
}DDIL_DELAY_STRUCT;

/*API定义*/
/*驱动注册API定义*/
DDIL_ERROR_CODE DDIL_Delay_Register(DDIL_DELAY_INDEX index, DDIL_DelayInit_FuncPtr init,
    DDIL_DelayMs_FuncPtr delayMs, DDIL_DelayUs_FuncPtr delayUs);

/*初始化*/
DDIL_ERROR_CODE DDIL_Delay_Init(DDIL_DELAY_INDEX index);

/*延时毫秒*/
DDIL_ERROR_CODE DDIL_Delay_DelayMs(DDIL_DELAY_INDEX index, uint16_t nms);

/*延时微秒*/
DDIL_ERROR_CODE DDIL_Delay_DelayUs(DDIL_DELAY_INDEX index, uint16_t nus);


#endif



