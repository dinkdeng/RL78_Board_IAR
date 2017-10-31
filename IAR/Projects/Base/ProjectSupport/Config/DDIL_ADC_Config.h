#ifndef __DDIL_ADC_CONFIG_H_
#define __DDIL_ADC_CONFIG_H_
#include "DDIL_ErrorCode.h"

/*主板ADC模块数量*/
#define DDIL_ADC_NUM    1

/*主板ADC模块序号*/
typedef enum DDIL_ADC_INDEX
{
    DDIL_ADC_0 = 0,
}DDIL_ADC_INDEX;


#include "adc.h"
#include "DDIL_ADC.h"

#endif




