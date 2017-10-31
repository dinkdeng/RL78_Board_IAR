#ifndef __EXTKEY_H_
#define __EXTKEY_H_
#include "RL78G13_Port.h"
#include "RL78G13_KRM.h"
#include "RL78G13_Int.h"
#include "DDIL_ExtKey_Config.h"

/*按键初始化*/
DDIL_ERROR_CODE ExtKey_BoardInit(void);
/*获取按键状态*/
DDIL_ERROR_CODE ExtKey_BoardGetStatus(DDIL_EXTKEY_STATUS* status);
/*等待按键触发设定状态*/
DDIL_ERROR_CODE ExtKey_BoardWaitStatus(DDIL_EXTKEY_STATUS status);



#endif






