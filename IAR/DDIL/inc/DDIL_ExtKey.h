#ifndef __DDIL_EXTKEY_H_
#define __DDIL_EXTKEY_H_
#include "DDIL_ExtKey_Config.h"

/*函数指针定义区域*/
typedef DDIL_ERROR_CODE(*DDIL_ExtKey_Init_FuncPtr)(void);

typedef DDIL_ERROR_CODE(*DDIL_ExtKey_GetStatus_FuncPtr)(DDIL_EXTKEY_STATUS* status);

typedef DDIL_ERROR_CODE(*DDIL_ExtKey_WaitStatus_FuncPtr)(DDIL_EXTKEY_STATUS status);

/*设备方法封装的结构体*/
typedef struct DDIL_EXTKEY_STRUCT
{
    DDIL_ExtKey_Init_FuncPtr init;
    DDIL_ExtKey_GetStatus_FuncPtr getStatus;
    DDIL_ExtKey_WaitStatus_FuncPtr waitStatus;
}DDIL_EXTKEY_STRUCT;

/*外部按键驱动注册*/
DDIL_ERROR_CODE DDIL_ExtKey_Register(DDIL_EXTKEY_INDEX index, DDIL_ExtKey_Init_FuncPtr init,
    DDIL_ExtKey_GetStatus_FuncPtr getStatus, DDIL_ExtKey_WaitStatus_FuncPtr waitStatus);

/*初始化*/
DDIL_ERROR_CODE DDIL_ExtKey_Init(DDIL_EXTKEY_INDEX index);

/*获取状态,立即返回*/
DDIL_ERROR_CODE DDIL_ExtKey_GetStatus(DDIL_EXTKEY_INDEX index, DDIL_EXTKEY_STATUS* status);

/*等待状态,直到等待到指定的状态才返回*/
DDIL_ERROR_CODE DDIL_ExtKey_WaitStatus(DDIL_EXTKEY_INDEX index, DDIL_EXTKEY_STATUS status);


#endif




