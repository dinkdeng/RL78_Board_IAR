#include "DDIL_Uart.h"

DDIL_USART1_STRUCT DDIL_uartObject = { 0 };

/*函数体定义区域*/
/*驱动函数注册*/

DDIL_ERROR_CODE DDIL_Uart_Register(DDIL_Uart_Init_FuncPtr init, DDIL_Uart_SendChar_FuncPtr sendChar,
    DDIL_Uart_SendBuffer_FuncPtr sendBuffer, DDIL_Uart_SendString_FuncPtr sendString,
    DDIL_Uart_ReadRecv_FuncPtr readRecv, DDIL_Uart_ClearRecv_FuncPtr clearRecv)
{
    DDIL_uartObject.init = init;
    DDIL_uartObject.sendChar = sendChar;
    DDIL_uartObject.sendBuffer = sendBuffer;
    DDIL_uartObject.sendString = sendString;
    DDIL_uartObject.readRecv = readRecv;
    DDIL_uartObject.clearRecv = clearRecv;
    return DDIL_ERROR_NONE;
}

/*设备初始化*/

DDIL_ERROR_CODE DDIL_Uart_Init(uint32_t bps)
{
    if (DDIL_uartObject.init == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_uartObject.init(bps);
}

/*设备发送一个字节*/

DDIL_ERROR_CODE DDIL_Uart_SendChar(uint8_t chDat)
{
    if (DDIL_uartObject.sendChar == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_uartObject.sendChar(chDat);
}

/*设备发送一个数组*/

DDIL_ERROR_CODE DDIL_Uart_SendBuffer(uint8_t* bufferPtr, uint16_t length)
{
    if (DDIL_uartObject.sendBuffer == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_uartObject.sendBuffer(bufferPtr, length);
}

/*设备发送字符串*/

DDIL_ERROR_CODE DDIL_Uart_SendString(const uint8_t* strPtr)
{
    if (DDIL_uartObject.sendString == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_uartObject.sendString(strPtr);
}

/*设备读取接收到的数据*/

DDIL_ERROR_CODE DDIL_Uart_ReadRecv(uint8_t** recvPtr, uint16_t* recvLength)
{
    if (DDIL_uartObject.readRecv == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_uartObject.readRecv(recvPtr, recvLength);
}

/*清除接收缓冲区*/

DDIL_ERROR_CODE DDIL_Uart_ClearRecv(void)
{
    if (DDIL_uartObject.clearRecv == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_uartObject.clearRecv();
}

#if (DDIL_USART0_FOR_PRINTF == 1)
/*重定向系统printf库.*/
int putchar(int ch)
{
    DDIL_Uart_SendChar(ch);
    return ch;
}
#endif