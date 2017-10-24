#include "Led.h"

/*LED初始化*/
/*P4.1初始化*/
DDIL_ERROR_CODE Led0Init(DDIL_LED_STATUS initStatus)
{
    if (initStatus == DDIL_LED_STATUS_OFF)
    {
        RL78G13_Port_Init(PORT_INDEX4, PORT_BIT1, RL78G13_PORT_PMn1_MODE_OUTPUT, RL78G13_PORT_Pn1_OUTPUT_1,
            RL78G13_PORT_PULLUP1_ON, RL78G13_PORT_PIM1_TTL_OFF, RL78G13_PORT_POM1_NCH_OFF, 
            RL78G13_PORT_PMC1_NOT_USE);
    }
    else
    {
        RL78G13_Port_Init(PORT_INDEX4, PORT_BIT1, RL78G13_PORT_PMn1_MODE_OUTPUT, RL78G13_PORT_Pn1_OUTPUT_0,
            RL78G13_PORT_PULLUP1_ON, RL78G13_PORT_PIM1_TTL_OFF, RL78G13_PORT_POM1_NCH_OFF,
            RL78G13_PORT_PMC1_NOT_USE);
    }
    
    return DDIL_ERROR_NONE;
}

/*LED设置状态*/
DDIL_ERROR_CODE Led0Set(DDIL_LED_STATUS status)
{
    if (status == DDIL_LED_STATUS_OFF)
    {
        P4_bit.no1 = 1;
    }
    else
    {
        P4_bit.no1 = 0;
    }
    return DDIL_ERROR_NONE;
}

/*LED读取状态*/
DDIL_ERROR_CODE Led0Get(DDIL_LED_STATUS* status)
{
    if (P4_bit.no1 == 0)
        *status = DDIL_LED_STATUS_ON;
    else
        *status = DDIL_LED_STATUS_OFF;
    return DDIL_ERROR_NONE;
}

/*LED初始化*/
/*P4.2*/
DDIL_ERROR_CODE Led1Init(DDIL_LED_STATUS initStatus)
{
    if (initStatus == DDIL_LED_STATUS_OFF)
    {
        RL78G13_Port_Init(PORT_INDEX4, PORT_BIT2, RL78G13_PORT_PMn2_MODE_OUTPUT, RL78G13_PORT_Pn2_OUTPUT_1,
            RL78G13_PORT_PULLUP2_ON, RL78G13_PORT_PIM2_TTL_OFF, RL78G13_PORT_POM2_NCH_OFF,
            RL78G13_PORT_PMC2_NOT_USE);
    }
    else
    {
        RL78G13_Port_Init(PORT_INDEX4, PORT_BIT2, RL78G13_PORT_PMn2_MODE_OUTPUT, RL78G13_PORT_Pn2_OUTPUT_0,
            RL78G13_PORT_PULLUP2_ON, RL78G13_PORT_PIM2_TTL_OFF, RL78G13_PORT_POM2_NCH_OFF,
            RL78G13_PORT_PMC2_NOT_USE);
    }
    return DDIL_ERROR_NONE;
}

/*LED设置状态*/
DDIL_ERROR_CODE Led1Set(DDIL_LED_STATUS status)
{
    if (status == DDIL_LED_STATUS_OFF)
    {
        P4_bit.no2 = 1;
    }
    else
    {
        P4_bit.no2 = 0;
    }
    return DDIL_ERROR_NONE;
}

/*LED读取状态*/
DDIL_ERROR_CODE Led1Get(DDIL_LED_STATUS* status)
{
    if (P4_bit.no2 == 0)
        *status = DDIL_LED_STATUS_ON;
    else
        *status = DDIL_LED_STATUS_OFF;
    return DDIL_ERROR_NONE;
}

/*LED初始化*/
/*P4.3*/
DDIL_ERROR_CODE Led2Init(DDIL_LED_STATUS initStatus)
{
    if (initStatus == DDIL_LED_STATUS_OFF)
    {
        RL78G13_Port_Init(PORT_INDEX4, PORT_BIT3, RL78G13_PORT_PMn3_MODE_OUTPUT, RL78G13_PORT_Pn3_OUTPUT_1,
            RL78G13_PORT_PULLUP3_ON, RL78G13_PORT_PIM3_TTL_OFF, RL78G13_PORT_POM3_NCH_OFF,
            RL78G13_PORT_PMC3_NOT_USE);
    }
    else
    {
        RL78G13_Port_Init(PORT_INDEX4, PORT_BIT3, RL78G13_PORT_PMn3_MODE_OUTPUT, RL78G13_PORT_Pn3_OUTPUT_0,
            RL78G13_PORT_PULLUP3_ON, RL78G13_PORT_PIM3_TTL_OFF, RL78G13_PORT_POM3_NCH_OFF,
            RL78G13_PORT_PMC3_NOT_USE);
    }
    return DDIL_ERROR_NONE;
}

/*LED设置状态*/
DDIL_ERROR_CODE Led2Set(DDIL_LED_STATUS status)
{
    if (status == DDIL_LED_STATUS_OFF)
    {
        P4_bit.no3 = 1;
    }
    else
    {
        P4_bit.no3 = 0;
    }
    return DDIL_ERROR_NONE;
}

/*LED读取状态*/
DDIL_ERROR_CODE Led2Get(DDIL_LED_STATUS* status)
{
    if (P4_bit.no3 == 0)
        *status = DDIL_LED_STATUS_ON;
    else
        *status = DDIL_LED_STATUS_OFF;
    return DDIL_ERROR_NONE;
}



