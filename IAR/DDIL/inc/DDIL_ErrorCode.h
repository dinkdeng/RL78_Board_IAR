#ifndef __DDIL_ERROR_CODE_H_
#define __DDIL_ERROR_CODE_H_

#include "MacroDriver.h"

#ifndef NULL
#define NULL 0
#endif

typedef enum DDIL_ERROR_CODE
{
    /*无错误*/
    DDIL_ERROR_NONE = 0X0000,
    /*注册驱动超过了系统设备数量限制*/
    DDIL_ERROR_NUM_LIMIT = 0X0001,
    /*注册方法为空*/
    DDIL_ERROR_FUNC_NULL = 0X0002,
    /*参数错误*/
    DDIL_ERROR_PARAM_LIMIT = 0x0003,
    /*超时*/
    DDIL_ERROR_TIMEOUT = 0x0004,
}DDIL_ERROR_CODE;

#endif
