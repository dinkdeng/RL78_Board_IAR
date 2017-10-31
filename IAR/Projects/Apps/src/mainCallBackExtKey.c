#include "DDIL_Delay_Config.h"
#include "DDIL_LED_Config.h"
#include "DDIL_Uart_Config.h"
#include "DDIL_ExtKey_Config.h"

void mainCallBackExtKey()
{
    EI();
    /*延时函数注册*/
    DDIL_Delay_Register(DDIL_DELAY_INDEX_0, Delay_Init, Delay_Ms, Delay_Us);
    /*LED驱动注册*/
    DDIL_Led_Register(DDIL_LED_INDEX_0, Led0Init, Led0Set, Led0Get);
    DDIL_Led_Register(DDIL_LED_INDEX_1, Led1Init, Led1Set, Led1Get);
    DDIL_Led_Register(DDIL_LED_INDEX_2, Led2Init, Led2Set, Led2Get);
    /*串口驱动注册*/
    DDIL_Uart_Register(Uart0_Init, Uart0_SendChar, Uart0_SendBuffer, Uart0_SendString,
        Uart0_ReadRecv, Uart0_ClearRecv);
    /*外部按键检测注册*/
    DDIL_ExtKey_Register(DDIL_EXTKEY_INDEX_0, ExtKey_BoardInit,ExtKey_BoardGetStatus,
        ExtKey_BoardWaitStatus);

    /*Delay延时函数初始化*/
    DDIL_Delay_Init(DDIL_DELAY_INDEX_0);
    /*LED初始化*/
    DDIL_Led_Init(DDIL_LED_INDEX_0, DDIL_LED_STATUS_OFF);
    DDIL_Led_Init(DDIL_LED_INDEX_1, DDIL_LED_STATUS_OFF);
    DDIL_Led_Init(DDIL_LED_INDEX_2, DDIL_LED_STATUS_OFF);
    /*串口初始化*/
    DDIL_Uart_Init(38400);
    /*外部按键初始化*/
    DDIL_ExtKey_Init(DDIL_EXTKEY_INDEX_0);
    DDIL_EXTKEY_STATUS extKeyStatus = DDIL_EXTKEY_STATUS_NONE;

    while (1)
    {
        //printf("RL78 Board Uart0 Test\r\n");
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 50);
        DDIL_Led_Set(DDIL_LED_INDEX_0, DDIL_LED_STATUS_ON);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 50);
        DDIL_Led_Set(DDIL_LED_INDEX_0, DDIL_LED_STATUS_OFF);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 50);
        DDIL_Led_Set(DDIL_LED_INDEX_1, DDIL_LED_STATUS_ON);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 50);
        DDIL_Led_Set(DDIL_LED_INDEX_1, DDIL_LED_STATUS_OFF);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 50);
        DDIL_Led_Set(DDIL_LED_INDEX_2, DDIL_LED_STATUS_ON);
        DDIL_Delay_DelayMs(DDIL_DELAY_INDEX_0, 50);
        DDIL_Led_Set(DDIL_LED_INDEX_2, DDIL_LED_STATUS_OFF);
        /*读取串口接收状态并原样发回去*/
        uint8_t* readBuffer;
        uint16_t readLength;
        DDIL_Uart_ReadRecv(&readBuffer, &readLength);
        if (readLength != 0)
        {
            DDIL_Uart_SendBuffer(readBuffer, readLength);
            DDIL_Uart_SendString("\r\n");
            DDIL_Uart_ClearRecv();
            printf("Receive Package\r\n");
        }
        DDIL_ExtKey_GetStatus(DDIL_EXTKEY_INDEX_0, &extKeyStatus);
        if (extKeyStatus != DDIL_EXTKEY_STATUS_NONE)
        {
            printf("Key Value : %x\r\n", extKeyStatus);
            extKeyStatus = DDIL_EXTKEY_STATUS_NONE;
        }
    }
}