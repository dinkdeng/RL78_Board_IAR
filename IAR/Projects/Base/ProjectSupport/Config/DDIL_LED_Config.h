#ifndef __DDIL_LED_CONFIG_H_
#define __DDIL_LED_CONFIG_H_
#include "DDIL_ErrorCode.h"

/*设备数量*/
#define DDIL_LED_NUM      3

/*设备ID号枚举*/
typedef enum DDIL_LED_INDEX
{
    DDIL_LED_INDEX_0 = 0,
    DDIL_LED_INDEX_1 = 1,
    DDIL_LED_INDEX_2 = 2,
}DDIL_LED_INDEX;

/*led状态枚举*/
typedef enum DDIL_LED_STATUS
{
    DDIL_LED_STATUS_OFF = 0,
    DDIL_LED_STATUS_ON = 1,
}DDIL_LED_STATUS;


#include "Led.h"
#include "DDIL_Led.h"

#endif