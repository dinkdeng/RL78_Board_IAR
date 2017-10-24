#ifndef __DELAY_H_
#define __DELAY_H_
#include "DDIL_Delay_Config.h"

DDIL_ERROR_CODE Delay_Init(void);

DDIL_ERROR_CODE Delay_Ms(uint16_t ms);

DDIL_ERROR_CODE Delay_Us(uint16_t us);



#endif




