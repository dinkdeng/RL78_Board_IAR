#ifndef __LED_H_
#define __LED_H_
#include "DDIL_Led_Config.h"
#include "RL78G13_Port.h"


/*LED初始化*/
DDIL_ERROR_CODE Led0Init(DDIL_LED_STATUS initStatus);
                   
/*LED设置状态*/    
DDIL_ERROR_CODE Led0Set(DDIL_LED_STATUS status);
                   
/*LED读取状态*/    
DDIL_ERROR_CODE Led0Get(DDIL_LED_STATUS* status);

/*LED初始化*/
DDIL_ERROR_CODE Led1Init(DDIL_LED_STATUS initStatus);
                   
/*LED设置状态*/    
DDIL_ERROR_CODE Led1Set(DDIL_LED_STATUS status);
                   
/*LED读取状态*/    
DDIL_ERROR_CODE Led1Get(DDIL_LED_STATUS* status);

/*LED初始化*/
DDIL_ERROR_CODE Led2Init(DDIL_LED_STATUS initStatus);

/*LED设置状态*/
DDIL_ERROR_CODE Led2Set(DDIL_LED_STATUS status);

/*LED读取状态*/
DDIL_ERROR_CODE Led2Get(DDIL_LED_STATUS* status);


#endif




