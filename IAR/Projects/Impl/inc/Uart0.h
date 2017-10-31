#ifndef __UART0_H_
#define __UART0_H_
#include "DDIL_Uart_Config.h"
#include "MacroDriver.h"
#include "RL78G13_Serial.h"
#include "RL78G13_Port.h"
#include "RL78G13_Clock.h"
#include "RL78G13_Int.h"


/*设置中断模式下串口缓冲区的最大数据长度*/
#define UART0_INT_RX_NUMBER_LIMIT   64

/*设备初始化*/
DDIL_ERROR_CODE Uart0_Init(uint32_t bps);

/*设备发送一个字节*/
DDIL_ERROR_CODE Uart0_SendChar(uint8_t chDat);

/*设备发送一个数组*/
DDIL_ERROR_CODE Uart0_SendBuffer(uint8_t* bufferPtr, uint16_t length);

/*设备发送字符串*/
DDIL_ERROR_CODE Uart0_SendString(const uint8_t* strPtr);

/*设备读取接收到的数据*/
DDIL_ERROR_CODE Uart0_ReadRecv(uint8_t** recvPtr, uint16_t* recvLength);

/*清除接收缓冲区*/
DDIL_ERROR_CODE Uart0_ClearRecv(void);

/*中断处理函数*/
void Uart0_Int_Process(void);

#endif






