#include "DDIL_ADC.h"

/**
* Brief:
*      The ddil ADC object[ ddil ADC num].
*/

DDIL_ADC_STRUCT DDIL_ADCObject[DDIL_ADC_NUM] = { 0 };


/**
* Function:
*  DDIL_ERROR_CODE DDIL_ADC_Register(DDIL_ADC_INDEX index, DDIL_ADC_Init_FuncPtr init,
*  DDIL_ADC_GetValueByChannel_FuncPtr getValueByChannel)
*
* Brief:
*      Ddil ADC register.
*
* Author:
*      Dink
*
* Date:
*      2017/10/16
*
* Param:
*  index -                 Zero-based index of the.
*  init -                  The init.
*  getValueByChannel -     The get value by channel.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_ADC_Register(DDIL_ADC_INDEX index, DDIL_ADC_Init_FuncPtr init,
    DDIL_ADC_GetValueByChannel_FuncPtr getValueByChannel)
{
    if (index >= DDIL_ADC_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    DDIL_ADCObject[index].init = init;
    DDIL_ADCObject[index].getValueByChannel = getValueByChannel;
    return DDIL_ERROR_NONE;
}

/**
* Function:        DDIL_ERROR_CODE DDIL_ADC_Init(DDIL_ADC_INDEX index)
*
* Brief:
*      Ddil ADC init.
*
* Author:
*      Dink
*
* Date:
*      2017/10/16
*
* Param:
*  index -     Zero-based index of the.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_ADC_Init(DDIL_ADC_INDEX index)
{
    if (index >= DDIL_ADC_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_ADCObject[index].init == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_ADCObject[index].init();
}

/**
* Function:
*  DDIL_ERROR_CODE DDIL_ADC_GetValueByChannel(DDIL_ADC_INDEX index, uint32_t channel,
*  uint32_t* adcValue)
*
* Brief:
*      Ddil ADC get value by channel.
*
* Author:
*      Dink
*
* Date:
*      2017/10/16
*
* Param:
*  index -     Zero-based index of the.
*  channel -   The channel.
*  adcValue -  [in,out] If non-null, the ADC value.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_ADC_GetValueByChannel(DDIL_ADC_INDEX index, uint32_t channel,
    uint16_t* adcValue)
{
    if (index >= DDIL_ADC_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_ADCObject[index].getValueByChannel == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_ADCObject[index].getValueByChannel(channel, adcValue);
}