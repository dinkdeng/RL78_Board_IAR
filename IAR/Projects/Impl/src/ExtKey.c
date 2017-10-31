#include "ExtKey.h"
#include "Delay.h"

/*按键初始化*/
DDIL_ERROR_CODE ExtKey_BoardInit(void)
{
    /*IO初始化,P7.0-P7.3输出,默认输出高*/
    RL78G13_Port_Init(PORT_INDEX7, PORT_BIT0, RL78G13_PORT_PMn0_MODE_OUTPUT,
        RL78G13_PORT_Pn0_OUTPUT_1, RL78G13_PORT_PULLUP0_ON, RL78G13_PORT_PIM0_TTL_OFF,
        RL78G13_PORT_POM0_NCH_OFF, RL78G13_PORT_PMC0_DI_ON);

    RL78G13_Port_Init(PORT_INDEX7, PORT_BIT1, RL78G13_PORT_PMn1_MODE_OUTPUT,
        RL78G13_PORT_Pn1_OUTPUT_1, RL78G13_PORT_PULLUP1_ON, RL78G13_PORT_PIM1_TTL_OFF,
        RL78G13_PORT_POM1_NCH_OFF, RL78G13_PORT_PMC1_DI_ON);

    RL78G13_Port_Init(PORT_INDEX7, PORT_BIT2, RL78G13_PORT_PMn2_MODE_OUTPUT,
        RL78G13_PORT_Pn2_OUTPUT_1, RL78G13_PORT_PULLUP2_ON, RL78G13_PORT_PIM2_TTL_OFF,
        RL78G13_PORT_POM2_NCH_OFF, RL78G13_PORT_PMC2_DI_ON);

    RL78G13_Port_Init(PORT_INDEX7, PORT_BIT3, RL78G13_PORT_PMn3_MODE_OUTPUT,
        RL78G13_PORT_Pn3_OUTPUT_1, RL78G13_PORT_PULLUP3_ON, RL78G13_PORT_PIM3_TTL_OFF,
        RL78G13_PORT_POM3_NCH_OFF, RL78G13_PORT_PMC3_DI_ON);
    /*P7.4-P7.7 ,输入,上拉*/
    RL78G13_Port_Init(PORT_INDEX7, PORT_BIT4, RL78G13_PORT_PMn4_MODE_INPUT,
        RL78G13_PORT_Pn4_OUTPUT_0, RL78G13_PORT_PULLUP4_ON, RL78G13_PORT_PIM4_TTL_OFF,
        RL78G13_PORT_POM4_NCH_OFF, RL78G13_PORT_PMC4_DI_ON);

    RL78G13_Port_Init(PORT_INDEX7, PORT_BIT5, RL78G13_PORT_PMn5_MODE_INPUT,
        RL78G13_PORT_Pn5_OUTPUT_0, RL78G13_PORT_PULLUP5_ON, RL78G13_PORT_PIM5_TTL_OFF,
        RL78G13_PORT_POM5_NCH_OFF, RL78G13_PORT_PMC5_DI_ON);

    RL78G13_Port_Init(PORT_INDEX7, PORT_BIT6, RL78G13_PORT_PMn6_MODE_INPUT,
        RL78G13_PORT_Pn6_OUTPUT_0, RL78G13_PORT_PULLUP6_ON, RL78G13_PORT_PIM6_TTL_OFF,
        RL78G13_PORT_POM6_NCH_OFF, RL78G13_PORT_PMC6_DI_ON);

    RL78G13_Port_Init(PORT_INDEX7, PORT_BIT7, RL78G13_PORT_PMn7_MODE_INPUT,
        RL78G13_PORT_Pn7_OUTPUT_0, RL78G13_PORT_PULLUP7_ON, RL78G13_PORT_PIM7_TTL_OFF,
        RL78G13_PORT_POM7_NCH_OFF, RL78G13_PORT_PMC7_DI_ON);

    /*禁用P3.1的中断,INTP4中断*/
    RL78G13_Int_Ext_Set(RL78G13_INT_EXT_SRC_4, RL78G13_INT_EXT_TYPE_DISABLE);
    return DDIL_ERROR_NONE;
}

#define KEY_PORT    	    P7

#define KEY_PORT_IN0   	    P7_bit.no7
#define KEY_PORT_IN1   	    P7_bit.no6
#define KEY_PORT_IN2   	    P7_bit.no5
#define KEY_PORT_IN3   	    P7_bit.no4

#define KEY_PORT_OUT0   	P7_bit.no3
#define KEY_PORT_OUT1   	P7_bit.no2
#define KEY_PORT_OUT2   	P7_bit.no1
#define KEY_PORT_OUT3   	P7_bit.no0

DDIL_EXTKEY_STATUS KeyBoard_Scan()
{
    uint8_t readValue = 0;
    KEY_PORT = 0xff;
    Delay_Ms(10);
    /*输出1*/
    KEY_PORT_OUT0 = 0;
    readValue = KEY_PORT;
    readValue &= 0xf0;
    if (readValue != 0xf0)
    {
        Delay_Ms(10);
        readValue = KEY_PORT;
        readValue &= 0xf0;
        if (readValue != 0xf0)
        {
            readValue = KEY_PORT;
            readValue &= 0xf0;
            switch (readValue)
            {
            case 0xe0:
                return DDIL_EXTKEY_STATUS_1;
                break;
            case 0xd0:
                return DDIL_EXTKEY_STATUS_5;
                break;
            case 0xb0:
                return DDIL_EXTKEY_STATUS_9;
                break;
            case 0x70:
                return DDIL_EXTKEY_STATUS_13;
                break;
            }
        }
    }
    /*输出2*/
    KEY_PORT = 0xff;
    Delay_Ms(10);
    KEY_PORT_OUT1 = 0;
    readValue = KEY_PORT;
    readValue &= 0xf0;
    if (readValue != 0xf0)
    {
        Delay_Ms(10);
        readValue = KEY_PORT;
        readValue &= 0xf0;
        if (readValue != 0xf0)
        {
            readValue = KEY_PORT;
            readValue &= 0xf0;
            switch (readValue)
            {
            case 0xe0:
                return DDIL_EXTKEY_STATUS_2;
                break;
            case 0xd0:
                return DDIL_EXTKEY_STATUS_6;
                break;
            case 0xb0:
                return DDIL_EXTKEY_STATUS_10;
                break;
            case 0x70:
                return DDIL_EXTKEY_STATUS_14;
                break;
            }
        }
    }
    /*输出3*/
    KEY_PORT = 0xff;
    Delay_Ms(10);
    KEY_PORT_OUT2 = 0;
    readValue = KEY_PORT;
    readValue &= 0xf0;
    if (readValue != 0xf0)
    {
        Delay_Ms(10);
        readValue = KEY_PORT;
        readValue &= 0xf0;
        if (readValue != 0xf0)
        {
            readValue = KEY_PORT;
            readValue &= 0xf0;
            switch (readValue)
            {
            case 0xe0:
                return DDIL_EXTKEY_STATUS_3;
                break;
            case 0xd0:
                return DDIL_EXTKEY_STATUS_7;
                break;
            case 0xb0:
                return DDIL_EXTKEY_STATUS_11;
                break;
            case 0x70:
                return DDIL_EXTKEY_STATUS_15;
                break;
            }
        }
    }
    /*输出4*/
    KEY_PORT = 0xff;
    Delay_Ms(10);
    KEY_PORT_OUT3 = 0;
    readValue = KEY_PORT;
    readValue &= 0xf0;
    if (readValue != 0xf0)
    {
        Delay_Ms(10);
        readValue = KEY_PORT;
        readValue &= 0xf0;
        if (readValue != 0xf0)
        {
            readValue = KEY_PORT;
            readValue &= 0xf0;
            switch (readValue)
            {
            case 0xe0:
                return DDIL_EXTKEY_STATUS_4;
                break;
            case 0xd0:
                return DDIL_EXTKEY_STATUS_8;
                break;
            case 0xb0:
                return DDIL_EXTKEY_STATUS_12;
                break;
            case 0x70:
                return DDIL_EXTKEY_STATUS_16;
                break;
            }
        }
    }
    return DDIL_EXTKEY_STATUS_NONE;
}


/*获取按键状态*/
DDIL_ERROR_CODE ExtKey_BoardGetStatus(DDIL_EXTKEY_STATUS* status)
{
    DDIL_EXTKEY_STATUS readStatus = KeyBoard_Scan();
    *status = readStatus;
    return DDIL_ERROR_NONE;
}


/*等待按键触发设定状态*/
DDIL_ERROR_CODE ExtKey_BoardWaitStatus(DDIL_EXTKEY_STATUS status)
{
    DDIL_EXTKEY_STATUS statusTemp;
    do
    {
        ExtKey_BoardGetStatus(&statusTemp);
        Delay_Ms(5);
    } while (statusTemp != status);
    return DDIL_ERROR_NONE;
}


