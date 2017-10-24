#ifndef __DDIL_LED_H_
#define __DDIL_LED_H_
#include "DDIL_ErrorCode.h"
#include "DDIL_Led_Config.h"

/*函数指针类型定义*/
typedef DDIL_ERROR_CODE(*DDIL_LedInit_FuncPtr)(DDIL_LED_STATUS initStatus);

typedef DDIL_ERROR_CODE(*DDIL_LedSet_FuncPtr)(DDIL_LED_STATUS status);

typedef DDIL_ERROR_CODE(*DDIL_LedGet_FuncPtr)(DDIL_LED_STATUS* status);

/*驱动接口函数指针结构体*/
typedef struct DDIL_LED_STRUCT
{
    DDIL_LedInit_FuncPtr init;
    DDIL_LedSet_FuncPtr set;
    DDIL_LedGet_FuncPtr get;
}DDIL_LED_STRUCT;

/*驱动注册*/
DDIL_ERROR_CODE DDIL_Led_Register(DDIL_LED_INDEX index, DDIL_LedInit_FuncPtr init,
    DDIL_LedSet_FuncPtr set, DDIL_LedGet_FuncPtr get);

/*LED初始化*/
DDIL_ERROR_CODE DDIL_Led_Init(DDIL_LED_INDEX index, DDIL_LED_STATUS initStatus);

/*LED设置状态*/
DDIL_ERROR_CODE DDIL_Led_Set(DDIL_LED_INDEX index, DDIL_LED_STATUS status);

/*LED获取状态*/
DDIL_ERROR_CODE DDIL_Led_Get(DDIL_LED_INDEX index, DDIL_LED_STATUS* status);



#endif




