#ifndef __DDIL_UART_H_
#define __DDIL_UART_H_
#include "DDIL_ErrorCode.h"
#include "DDIL_Uart_Config.h"

#if (DDIL_USART0_FOR_PRINTF == 1)
/*包含printf需要的文件*/
#include <stdio.h>
#endif

/*函数指针定义区域*/
/*串口初始化函数指针类型*/
typedef DDIL_ERROR_CODE(*DDIL_Uart_Init_FuncPtr)(uint32_t bps);
/*串口发送字节*/
typedef DDIL_ERROR_CODE(*DDIL_Uart_SendChar_FuncPtr)(uint8_t chDat);
/*串口发送数组*/
typedef DDIL_ERROR_CODE(*DDIL_Uart_SendBuffer_FuncPtr)(uint8_t* bufferPtr, uint16_t length);
/*串口发送字符串*/
typedef DDIL_ERROR_CODE(*DDIL_Uart_SendString_FuncPtr)(const uint8_t* strPtr);
/*串口读取缓冲区数据*/
typedef DDIL_ERROR_CODE(*DDIL_Uart_ReadRecv_FuncPtr)(uint8_t** recvPtr, uint16_t* recvLength);
/*串口清除缓冲区状态*/
typedef DDIL_ERROR_CODE(*DDIL_Uart_ClearRecv_FuncPtr)(void);

/*方法对象定义区域*/
typedef struct DDIL_USART1_STRUCT
{
    DDIL_Uart_Init_FuncPtr init;
    DDIL_Uart_SendChar_FuncPtr sendChar;
    DDIL_Uart_SendBuffer_FuncPtr sendBuffer;
    DDIL_Uart_SendString_FuncPtr sendString;
    DDIL_Uart_ReadRecv_FuncPtr readRecv;
    DDIL_Uart_ClearRecv_FuncPtr clearRecv;
}DDIL_USART1_STRUCT;

/*函数体定义区域*/
/*驱动函数注册*/
DDIL_ERROR_CODE DDIL_Uart_Register(DDIL_Uart_Init_FuncPtr init, DDIL_Uart_SendChar_FuncPtr sendChar,
    DDIL_Uart_SendBuffer_FuncPtr sendBuffer, DDIL_Uart_SendString_FuncPtr sendString,
    DDIL_Uart_ReadRecv_FuncPtr readRecv, DDIL_Uart_ClearRecv_FuncPtr clearRecv);

/*设备初始化*/
DDIL_ERROR_CODE DDIL_Uart_Init(uint32_t bps);

/*设备发送一个字节*/
DDIL_ERROR_CODE DDIL_Uart_SendChar(uint8_t chDat);

/*设备发送一个数组*/
DDIL_ERROR_CODE DDIL_Uart_SendBuffer(uint8_t* bufferPtr, uint16_t length);

/*设备发送字符串*/
DDIL_ERROR_CODE DDIL_Uart_SendString(const uint8_t* strPtr);

/*设备读取接收到的数据*/
DDIL_ERROR_CODE DDIL_Uart_ReadRecv(uint8_t** recvPtr, uint16_t* recvLength);

/*清除接收缓冲区*/
DDIL_ERROR_CODE DDIL_Uart_ClearRecv(void);


#endif



