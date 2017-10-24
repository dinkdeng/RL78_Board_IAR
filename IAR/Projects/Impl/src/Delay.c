#include "Delay.h"

/*基于时钟指令周期计算的13.3倍*/

const uint16_t facUs = 1;
const uint16_t facMs = 1203;

DDIL_ERROR_CODE Delay_Init(void)
{
    return DDIL_ERROR_NONE;
}

DDIL_ERROR_CODE Delay_Ms(uint16_t ms)
{
    uint16_t i = 0;
    uint16_t j = 0;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < facMs; j++)
        {
            asm("nop");
        }
    }
    return DDIL_ERROR_NONE;
}

DDIL_ERROR_CODE Delay_Us(uint16_t us)
{
    uint16_t i = 0;
    uint16_t j = 0;
    for (i = 0; i < us; i++)
    {
        for (j = 0; j < facUs; j++)
        {
            asm("nop");
        }
    }
    return DDIL_ERROR_NONE;
}



