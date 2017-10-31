#include "Uart0.h"

/*接收辅助单元*/
uint8_t sendOver = 0;


/** Summary: 用于缓存串口数据的数组 */
uint8_t uart0RxIntBuffer[UART0_INT_RX_NUMBER_LIMIT] = { 0 };

/** Summary: 保存当前串口接收数据状态,16位 0-7位表示数据长度,最长数据由DEVICE_SOC_UART1_INT1_RX_NUMBER_LIMIT限制
* 一般不超过200
* 14位 是否已经接收到回车
* 15位 是否已经接收到换行. */
uint16_t uart0RxIntStatus = 0;

/*获取当前接收到的有效数据长度*/
#define UART0_GET_PACKAGE_LENGTH()   ((uart0RxIntStatus&0x8000) ? uart0RxIntStatus&0x00FF : 0)

/*清除当前串口接受状态*/
#define UART0_CLEAR_STATUS()         (uart0RxIntStatus = 0)

/*检查当前串口有没有接收到回车*/
#define UART0_CHECK_RX_STATUS_CR()   (uart0RxIntStatus&0x4000)

/*设置当前串口接收到回车*/
#define UART0_SET_RX_STATUS_CR()     (uart0RxIntStatus |= 0x4000)

/*检查当前串口有没有接收到换行*/
#define UART0_CHECK_RX_STATUS_LF()   (uart0RxIntStatus&0x8000)

/*设置当前串口接收到换行*/
#define UART0_SET_RX_STATUS_LF()     (uart0RxIntStatus |= 0x8000)

/*设备初始化*/
DDIL_ERROR_CODE Uart0_Init(uint32_t bps)
{
    uint16_t divValue = 0;
    divValue = (4000000UL / bps);
    divValue = ((divValue / 2) - 1);
    divValue <<= 9;
    /*打开SAU0时钟*/
    RL78G13_Clock_PER0_Enable(RL78G13_CLOCK_PER0_SAU0EN);
    /*等待十个时钟*/
    for (uint8_t i = 0; i < 100; i++)
    {
        __no_operation();
    }
    /*选择SAU0时钟分频,选择四分频*/
    RL78G13_SerialSPSWriteAll(RL78G13_SERIAL_UNIT_0, RL78G13_SERIAL_SPS_FLCK0_DIV_4,
        RL78G13_SERIAL_SPS_FLCK1_DIV_4);
    /*停止发送接收*/
    RL78G13_SerialSTWriteOne(RL78G13_SERIAL_UNIT_0, RL78G13_SERIAL_ST_COM0_STOP_FLAG_MASK,
        RL78G13_SERIAL_ST_COM0_STOP_FLAG_ON);
    RL78G13_SerialSTWriteOne(RL78G13_SERIAL_UNIT_0, RL78G13_SERIAL_ST_COM1_STOP_FLAG_MASK,
        RL78G13_SERIAL_ST_COM1_STOP_FLAG_ON);
    /*禁止INTST0 发送0中断*/
    STMK0 = 1U;
    /*清除INTST0 发送0 中断标志位*/
    STIF0 = 0U;
    /*禁止INTSR0,接收中断*/
    SRMK0 = 1U;
    /*清除INTSR0,接收中断*/
    SRIF0 = 0U;
    /*禁止INTSRE0,接收错误中断*/
    SREMK0 = 1U;
    /*清除INTSRE0,接收错误中断*/
    SREIF0 = 0U;
    /*设置发送的低优先级*/
    STPR10 = 1U;
    STPR00 = 1U;
    /*设置接收的低优先级*/
    SRPR10 = 1U;
    SRPR00 = 1U;
    /*设置串行模式寄存器00,发送端口,设置为FCLK0,FMCK,软件触发*/
    /*下降沿启动,uart模式,传送结束中断*/
    RL78G13_SerialSMRWriteAll(RL78G13_SERIAL_UNIT_0, RK78G13_SERIAL_UNIT_CHANNEL_0,
        RL78G13_SERIAL_SMR_FMCK_SELECT_FCLK0, RL78G13_SERIAL_SMR_FTCLK_SELECT_FMCK,
        RL78G13_SERIAL_SMR_START_TRIG_SOURCE_SOFT, RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_FALLING,
        RL78G13_SERIAL_SMR_CHANNEL_MODE_UART, RL78G13_SERIAL_SMR_INT_SRC_END);
    /*设置串行操作设置寄存器,发送端口,仅发送,信号模式0,屏蔽错误中断,发送无校验*/
    /*LSB,停止位1,数据长度8*/
    RL78G13_SerialSCRWriteAll(RL78G13_SERIAL_UNIT_0, RK78G13_SERIAL_UNIT_CHANNEL_0,
        RL78G13_SERIAL_SCR_MODE_TX_ONLY, RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_0,
        RL78G13_SERIAL_SCR_INT_DISABLE_ON, RL78G13_SERIAL_SCR_UART_CHECK_TX_NONE,
        RL78G13_SERIAL_SCR_UART_CSI_SEQ_LSB_FIRST, RL78G13_SERIAL_SCR_UART_STOP_BITS_1,
        RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_8);
    /*设置输出波特率*/
    RL78G13_SerialSDRWriteAll(RL78G13_SERIAL_UNIT_0, RK78G13_SERIAL_UNIT_CHANNEL_0,
        divValue,0);
    /*打开接收滤波器*/
    RL78G13_SerialNFENWriteOne(RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_MASK,
        RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_OPEN);
    /*清除RXD通道1的错误标志*/
    RL78G13_SerialSIRWriteAll(RL78G13_SERIAL_UNIT_0, RK78G13_SERIAL_UNIT_CHANNEL_1,
        RL78G13_SERIAL_SIR_FECT_CLECR, RL78G13_SERIAL_SIR_PECT_CLECR,
        RL78G13_SERIAL_SIR_OVCT_CLECR);
    /*设置RXD通道模式,FCLK0,FMCK,RX引脚触发,下降沿启动,UART模式*/
    /*传送结束中断*/
    RL78G13_SerialSMRWriteAll(RL78G13_SERIAL_UNIT_0, RK78G13_SERIAL_UNIT_CHANNEL_1,
        RL78G13_SERIAL_SMR_FMCK_SELECT_FCLK0, RL78G13_SERIAL_SMR_FTCLK_SELECT_FMCK,
        RL78G13_SERIAL_SMR_START_TRIG_SOURCE_RXDQ_PIN, RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_FALLING,
        RL78G13_SERIAL_SMR_CHANNEL_MODE_UART, RL78G13_SERIAL_SMR_INT_SRC_END);
    /*设置接收格式,只接收,信号模式0,禁用错误中断,无校验,LSB,停止位1,数据长度8*/
    RL78G13_SerialSCRWriteAll(RL78G13_SERIAL_UNIT_0, RK78G13_SERIAL_UNIT_CHANNEL_1,
        RL78G13_SERIAL_SCR_MODE_RX_ONLY, RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_0,
        RL78G13_SERIAL_SCR_INT_DISABLE_ON, RL78G13_SERIAL_SCR_UART_CHECK_RX_NO,
        RL78G13_SERIAL_SCR_UART_CSI_SEQ_LSB_FIRST, RL78G13_SERIAL_SCR_UART_STOP_BITS_1,
        RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_8);
    /*设置接收时钟*/
    RL78G13_SerialSDRWriteAll(RL78G13_SERIAL_UNIT_0, RK78G13_SERIAL_UNIT_CHANNEL_1,
        divValue, 0);
    /*设置输出电平,数据1*/
    RL78G13_SerialSOWriteOne(RL78G13_SERIAL_UNIT_0,
        RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_MASK,RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_1);
    /*设置输出电平是否翻转,TX0输出电平不翻转*/
    RL78G13_SerialSOLWriteOne(RL78G13_SERIAL_UNIT_0,
        RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_MASK, RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_OFF);
    /*使能输出,使能输出端口*/
    RL78G13_SerialSOEWriteOne(RL78G13_SERIAL_UNIT_0,
        RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_MASK, RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_ON);
    /*引脚映射定义,使用P1.6为RXD,P1.7位TXD*/
    PIOR = 0x02U;
    /*P1.6设定*/
    RL78G13_Port_Init(PORT_INDEX1, PORT_BIT6, RL78G13_PORT_PMn6_MODE_INPUT, RL78G13_PORT_Pn6_OUTPUT_0,
        RL78G13_PORT_PULLUP6_OFF, RL78G13_PORT_PIM6_TTL_OFF, RL78G13_PORT_POM6_NCH_OFF,
        RL78G13_PORT_PMC6_DI_ON);
    /*P1.7设定*/
    RL78G13_Port_Init(PORT_INDEX1, PORT_BIT7, RL78G13_PORT_PMn7_MODE_OUTPUT, RL78G13_PORT_Pn7_OUTPUT_1,
        RL78G13_PORT_PULLUP7_OFF, RL78G13_PORT_PIM7_TTL_OFF, RL78G13_PORT_POM7_NCH_OFF,
        RL78G13_PORT_PMC7_DI_ON);
    /*启动输入输出,启动TX RX*/
    RL78G13_SerialSSWriteOne(RL78G13_SERIAL_UNIT_0, RL78G13_SERIAL_SS_COM0_WAIT_FLAG_MASK,
        RL78G13_SERIAL_SS_COM0_WAIT_FLAG_ON);
    RL78G13_SerialSSWriteOne(RL78G13_SERIAL_UNIT_0, RL78G13_SERIAL_SS_COM1_WAIT_FLAG_MASK,
        RL78G13_SERIAL_SS_COM1_WAIT_FLAG_ON);
    /*清除请求中断标志*/
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_CSI00_IIC00_ST0);
    RL78G13_Int_Flag_Clear(RL78G13_INT_SRC_CSI01_IIC01_SR0);
    /*中断优先级设定*/
    RL78G13_Int_Pri_Write(RL78G13_INT_SRC_CSI00_IIC00_ST0, RL78G13_INT_PRI_3);
    RL78G13_Int_Pri_Write(RL78G13_INT_SRC_CSI01_IIC01_SR0, RL78G13_INT_PRI_0);
    /*使能中断*/
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_CSI00_IIC00_ST0, RL78G13_INT_STATUS_ENABLE);
    RL78G13_Int_Status_Write(RL78G13_INT_SRC_CSI01_IIC01_SR0, RL78G13_INT_STATUS_ENABLE);

    /*设置内部需要数据*/
    sendOver = 0;
    uart0RxIntStatus = 0;

    return DDIL_ERROR_NONE;
}



/*设备发送一个字节*/
DDIL_ERROR_CODE Uart0_SendChar(uint8_t chDat)
{
    /*设置中断为传输完成*/
    sendOver = 0;
    TXD0 = chDat;
    while (sendOver == 0)
    {
        __no_operation();
    }
    return DDIL_ERROR_NONE;
}

/*设备发送一个数组*/
DDIL_ERROR_CODE Uart0_SendBuffer(uint8_t* bufferPtr, uint16_t length)
{
   for(uint16_t i = 0; i < length; i++)
   {
       Uart0_SendChar(bufferPtr[i]);
   }
   return DDIL_ERROR_NONE;
}

/*设备发送字符串*/
DDIL_ERROR_CODE Uart0_SendString(const uint8_t* strPtr)
{
    while (*strPtr != '\0')
    {
        Uart0_SendChar(*strPtr);
        strPtr++;
    }
    return DDIL_ERROR_NONE;
}


/*串口接收中断处理函数*/
#pragma vector = INTSR0_vect
__interrupt void Uart0_RecvInt_Process(void)
{
    uint8_t Res;
    //接收中断(接收到的数据必须是0x0d 0x0a \r\n回车换行结尾)
    //(USART1->DR);	//读取接收到的数据
    Res = (uint8_t)(RL78G13_SerialSDRReadOne(RL78G13_SERIAL_UNIT_0, RK78G13_SERIAL_UNIT_CHANNEL_1, RL78G13_SERIAL_SDR_DATA_MASK));
    if (UART0_CHECK_RX_STATUS_LF())
    {
        /*接收到换行,等待主程序处理,此时接收到任何数据都不处理*/
        return;
    }
    /*已经接收到回车,等待接收换行*/
    else if (UART0_CHECK_RX_STATUS_CR())
    {
        /*接收到换行,设置接收到换行标识符*/
        if (Res == '\n')
        {
            UART0_SET_RX_STATUS_LF();
        }
        else
        {
            /*清除当前串口接收状态,从0开始接收,相当于重新初始化*/
            UART0_CLEAR_STATUS();
        }
    }
    /*既没接收到回车也没接收到换行,而且此刻数据总量已经超过了最大接收量*/
    else if (UART0_INT_RX_NUMBER_LIMIT == (uart0RxIntStatus & 0x00FF))
    {
        /*清除接受状态,重新开始接收,至于回车丢了这种特殊情况,我们可以依靠协议来解决,而不需要在中断层做过于复杂的处理,降低
        中断延迟*/
        UART0_CLEAR_STATUS();
    }
    else
    {
        /*既没接收到回车也没接收到换行,此时正常接收到回车,表示回车标志*/
        if (Res == '\r')
        {
            UART0_SET_RX_STATUS_CR();
        }
        else
        {
            /*不是回车,那么正常接收*/
            uart0RxIntBuffer[(uart0RxIntStatus & 0x00FF)] = Res;
            /*接收之后将接收到的字符串的总数量+1*/
            uart0RxIntStatus++;
        }
    }
}

/*串口0发送完成中断处理函数*/
#pragma vector = INTST0_vect
__interrupt void Uart0_SendInt_Process(void)
{
    sendOver = 1;
    /*清除发送中断标志*/
    STIF0 = 0U;
}

/*串口0错误中断处理函数*/
#pragma vector = INTSRE0_vect
__interrupt void Uart0_ErrorInt_Process(void)
{

}



/*设备读取接收到的数据*/
DDIL_ERROR_CODE Uart0_ReadRecv(uint8_t** recvPtr, uint16_t* recvLength)
{
    *recvPtr = uart0RxIntBuffer;
    *recvLength = UART0_GET_PACKAGE_LENGTH();
    return DDIL_ERROR_NONE;
}

/*清除接收缓冲区*/
DDIL_ERROR_CODE Uart0_ClearRecv(void)
{
    UART0_CLEAR_STATUS();
    return DDIL_ERROR_NONE;
}





