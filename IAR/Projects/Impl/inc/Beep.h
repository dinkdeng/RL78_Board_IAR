#ifndef __BEEP_H_
#define __BEEP_H_
#include "DDIL_Beep_Config.h"

/*蜂鸣器初始化*/
DDIL_ERROR_CODE Beep_Init(DDIL_BEEP_STATUS initStatus);

/*设置蜂鸣器状态*/
DDIL_ERROR_CODE Beep_Set(DDIL_BEEP_STATUS status);


#endif