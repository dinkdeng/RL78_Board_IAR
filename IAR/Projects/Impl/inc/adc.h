#ifndef __ADC_H_
#define __ADC_H_
#include "DDIL_ADC_Config.h"
#include "RL78G13_Port.h"
#include "RL78G13_ADC.h"
#include "RL78G13_Clock.h"
#include "RL78G13_Int.h"

/*ADC初始化*/
DDIL_ERROR_CODE Adc_Init(void);

/*获取指定ADC值*/
DDIL_ERROR_CODE Adc_GetValueByChannel(uint32_t channel, uint16_t* adcValue);

#endif




