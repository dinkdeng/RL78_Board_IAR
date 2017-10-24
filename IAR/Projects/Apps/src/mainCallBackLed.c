#include "SystemInit.h"
#include "DDIL_Delay.h"
#include "DDIL_LED.h"


void mainCallBackLed()
{
    EI();
    /*延时函数注册*/
    DDIL_Delay_Register(DDIL_DELAY_INDEX_0, Delay_Init, Delay_Ms, Delay_Us);
    /*LED驱动注册*/
    DDIL_Led_Register(DDIL_LED_INDEX_0, Led0Init, Led0Set, Led0Get);
    DDIL_Led_Register(DDIL_LED_INDEX_1, Led1Init, Led1Set, Led1Get);
    DDIL_Led_Register(DDIL_LED_INDEX_2, Led2Init, Led2Set, Led2Get);

    /*Delay延时函数初始化*/
    DDIL_Delay_Init(DDIL_DELAY_INDEX_0);
    /*LED初始化*/
    DDIL_Led_Init(DDIL_LED_INDEX_0, DDIL_LED_STATUS_OFF);
    DDIL_Led_Init(DDIL_LED_INDEX_1, DDIL_LED_STATUS_OFF);
    DDIL_Led_Init(DDIL_LED_INDEX_2, DDIL_LED_STATUS_OFF);

    /* Start user code. Do not edit comment generated here */
    P4_bit.no1 = 1;
    P4_bit.no2 = 1;
    P4_bit.no3 = 1;
    while (1)
    {
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 100);
        DDIL_Led_Set(DDIL_LED_INDEX_0, DDIL_LED_STATUS_ON);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 100);
        DDIL_Led_Set(DDIL_LED_INDEX_0, DDIL_LED_STATUS_OFF);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 100);
        DDIL_Led_Set(DDIL_LED_INDEX_1, DDIL_LED_STATUS_ON);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 100);
        DDIL_Led_Set(DDIL_LED_INDEX_1, DDIL_LED_STATUS_OFF);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 100);
        DDIL_Led_Set(DDIL_LED_INDEX_2, DDIL_LED_STATUS_ON);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 100);
        DDIL_Led_Set(DDIL_LED_INDEX_2, DDIL_LED_STATUS_OFF);
    }
}