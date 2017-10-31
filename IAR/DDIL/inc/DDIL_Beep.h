#ifndef __DDIL_BEEP_H_
#define __DDIL_BEEP_H_
#include "DDIL_Beep_Config.h"

/*函数指针定义区域*/
typedef DDIL_ERROR_CODE(*DDIL_BeepInit_FuncPtr)(DDIL_BEEP_STATUS initStatus);
typedef DDIL_ERROR_CODE(*DDIL_BeepSet_FuncPtr)(DDIL_BEEP_STATUS setStatus);

/*函数指针结构体定义区域*/
typedef struct DDIL_BEEP_STRUCT
{
    DDIL_BeepInit_FuncPtr init;
    DDIL_BeepSet_FuncPtr set;
}DDIL_BEEP_STRUCT;

/*函数定义区域*/

/*驱动注册*/
DDIL_ERROR_CODE DDIL_Beep_Register(DDIL_BEEP_INDEX index, DDIL_BeepInit_FuncPtr init,
    DDIL_BeepSet_FuncPtr set);

/*蜂鸣器初始化*/
DDIL_ERROR_CODE DDIL_Beep_Init(DDIL_BEEP_INDEX index, DDIL_BEEP_STATUS initStatus);

/*蜂鸣器设置指定状态*/
DDIL_ERROR_CODE DDIL_Beep_Set(DDIL_BEEP_INDEX index, DDIL_BEEP_STATUS setStatus);


#endif





