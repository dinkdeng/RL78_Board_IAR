#ifndef __DDIL_ADC_H_
#define __DDIL_ADC_H_
#include "DDIL_ADC_Config.h"

/*函数指针定义区域*/
typedef DDIL_ERROR_CODE(*DDIL_ADC_Init_FuncPtr)(void);

typedef DDIL_ERROR_CODE(*DDIL_ADC_GetValueByChannel_FuncPtr)(uint32_t channel,
    uint16_t* adcValue);

/*驱动结构体定义*/
typedef struct DDIL_ADC_STRUCT
{
    DDIL_ADC_Init_FuncPtr init;
    DDIL_ADC_GetValueByChannel_FuncPtr getValueByChannel;
}DDIL_ADC_STRUCT;

/*函数API定义*/

DDIL_ERROR_CODE DDIL_ADC_Register(DDIL_ADC_INDEX index, DDIL_ADC_Init_FuncPtr init,
    DDIL_ADC_GetValueByChannel_FuncPtr getValueByChannel);

DDIL_ERROR_CODE DDIL_ADC_Init(DDIL_ADC_INDEX index);

DDIL_ERROR_CODE DDIL_ADC_GetValueByChannel(DDIL_ADC_INDEX index, uint32_t channel,
    uint16_t* adcValue);


#endif





