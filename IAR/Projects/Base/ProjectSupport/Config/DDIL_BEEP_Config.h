#ifndef __DDIL_BEEP_CONFIG_H_
#define __DDIL_BEEP_CONFIG_H_
#include "DDIL_ErrorCode.h"

/*设备数量*/
#define DDIL_BEEP_NUM      1

/*设备ID号枚举*/
typedef enum DDIL_BEEP_INDEX
{
    DDIL_BEEP_INDEX_0 = 0,
}DDIL_BEEP_INDEX;

/*BEEP状态枚举*/
typedef enum DDIL_BEEP_STATUS
{
    DDIL_BEEP_STATUS_OFF = 0,
    DDIL_BEEP_STATUS_ON = 1,
}DDIL_BEEP_STATUS;

#include "Beep.h"
#include "DDIL_Beep.h"



#endif




