#ifndef __RL78G13_SERIAL_H_
#define __RL78G13_SERIAL_H_
#include "MacroDriver.h"

/*串行阵列单元*/
typedef enum RL78G13_SERIAL_UNIT
{
    RL78G13_SERIAL_UNIT_0 = 0,
    RL78G13_SERIAL_UNIT_1 = 1,
}RL78G13_SERIAL_UNIT;

/*串行阵列通道,单元0有四个通道,单元1有两个通道*/
typedef enum RK78G13_SERIAL_UNIT_CHANNEL
{
    RK78G13_SERIAL_UNIT_CHANNEL_0 = 0,
    RK78G13_SERIAL_UNIT_CHANNEL_1 = 1,
    RK78G13_SERIAL_UNIT_CHANNEL_2 = 2,
    RK78G13_SERIAL_UNIT_CHANNEL_3 = 3,
}RK78G13_SERIAL_UNIT_CHANNEL;

/*串行时钟选择寄存器SPS*/
/*单元时钟0,基于FCLK的分频*/
#define RL78G13_SERIAL_SPS_FLCK0_MASK                                       0X0FU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_1                                      0X00U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_2                                      0X01U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_4                                      0X02U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_8                                      0X03U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_16                                     0X04U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_32                                     0X05U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_64                                     0X06U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_128                                    0X07U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_256                                    0X08U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_512                                    0X09U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_1024                                   0X0AU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_2048                                   0X0BU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_4096                                   0X0CU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_8192                                   0X0DU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_16384                                  0X0EU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_32768                                  0X0FU

/*单元时钟1,基于FCLK的分频*/
#define RL78G13_SERIAL_SPS_FLCK1_MASK                                       0XF0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_1                                      0X00U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_2                                      0X10U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_4                                      0X20U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_8                                      0X30U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_16                                     0X40U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_32                                     0X50U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_64                                     0X60U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_128                                    0X70U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_256                                    0X80U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_512                                    0X90U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_1024                                   0XA0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_2048                                   0XB0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_4096                                   0XC0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_8192                                   0XD0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_16384                                  0XE0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_32768                                  0XF0U


/*串行模式寄存器SMR*/
/*通道N的操作时钟FMCK的选择,单元时钟0或者1*/
#define RL78G13_SERIAL_SMR_FMCK_SELECT_MASK                                 0X8000U
#define RL78G13_SERIAL_SMR_FMCK_SELECT_FCLK0                                0X0000U
#define RL78G13_SERIAL_SMR_FMCK_SELECT_FCLK1                                0X8000U

/*通道N的传送时钟FTCLK的选择,FMCK或者引脚输入时钟*/
#define RL78G13_SERIAL_SMR_FTCLK_SELECT_MASK                                0X4000U
#define RL78G13_SERIAL_SMR_FTCLK_SELECT_FMCK                                0X0000U
#define RL78G13_SERIAL_SMR_FTCLK_SELECT_FSCK                                0X4000U
       
/*开始触发源的选择,软件触发或者RXDQ有效沿触发*/
#define RL78G13_SERIAL_SMR_START_TRIG_SOURCE_MASK                           0X0100U
#define RL78G13_SERIAL_SMR_START_TRIG_SOURCE_SOFT                           0X0000U
#define RL78G13_SERIAL_SMR_START_TRIG_SOURCE_RXDQ_PIN                       0X0100U

/*串口模式下,接收电平的反向控制,下降沿起始位还是上升沿起始位*/
#define RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_MASK                       0X0040U
#define RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_FALLING                    0X0000U
#define RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_RISING                     0X0040U

/*通道的使用模式,CSI模式 UART模式 简易IIC模式*/
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_MASK                                0X0006U
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_CSI                                 0X0000U
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_UART                                0X0002U
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_IIC                                 0X0004U

/*通道N的中断源的选择,传送结束发生中断还是缓冲区空发生中断*/
#define RL78G13_SERIAL_SMR_INT_SRC_MASK                                     0X0001U
#define RL78G13_SERIAL_SMR_INT_SRC_END                                      0X0000U
#define RL78G13_SERIAL_SMR_INT_SRC_EMPTY                                    0X0001U


/*串行通讯操作设置寄存器SCR*/
/*通道N的操作模式设定,禁止通讯,仅接受,仅发送,同时发送接收*/
#define RL78G13_SERIAL_SCR_MODE_MASK                                        0XC000U
#define RL78G13_SERIAL_SCR_MODE_DISABLE                                     0X0000U
#define RL78G13_SERIAL_SCR_MODE_TX_ONLY                                     0X4000U
#define RL78G13_SERIAL_SCR_MODE_RX_ONLY                                     0X8000U
#define RL78G13_SERIAL_SCR_MODE_TX_RX                                       0XC000U

/*CSI模式下数据和时钟相位的选择,一共四种模式,具体看文档*/
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_MASK                             0X3000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_0                                0X0000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_1                                0X1000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_2                                0X2000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_3                                0X3000U
        
/*选择是否屏蔽错误中断信号*/
#define RL78G13_SERIAL_SCR_INT_DISABLE_MASK                                 0X0400U
#define RL78G13_SERIAL_SCR_INT_DISABLE_ON                                   0X0400U
#define RL78G13_SERIAL_SCR_INT_DISABLE_OFF                                  0X0000U

/*UART模式下的奇偶校验选择*/
#define RL78G13_SERIAL_SCR_UART_CHECK_MASK                                  0X0300U
/*发送模式下的奇偶校验,分为不输出,0校验,奇校验,偶校验*/
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_NONE                               0X0000U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_ZERO                               0X0100U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_ODD                                0X0200U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_EVEN                               0X0300U
/*接受模式下的奇偶校验,分为无校验,奇校验,偶校验*/
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_NO                                 0X0000U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_NO1                                0X0100U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_ODD                                0X0200U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_EVEN                               0X0300U

/*CSI和UART模式下的数据传送序列选择,分为MSB优先和LSB优先*/
#define RL78G13_SERIAL_SCR_UART_CSI_SEQ_MASK                                0X0080U
#define RL78G13_SERIAL_SCR_UART_CSI_SEQ_MSB_FIRST                           0X0000U
#define RL78G13_SERIAL_SCR_UART_CSI_SEQ_LSB_FIRST                           0X0080U

/*UART模式下的停止位长度选择,分为0长度 1长度 2长度*/
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_MASK                              0X0030U
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_NONE                              0X0000U
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_1                                 0X0010U
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_2                                 0X0020U

/*CSI和UART模式下的数据长度选择,分为9 8 7长度*/
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_MASK                         0X0003U
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_9                            0X0001U
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_7                            0X0002U
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_8                            0X0003U
                   

/*串行数据寄存器,高八位为二级分频,低八位为数据缓冲区SDR*/
/*分频公式为 FMCK/(SDR+1)*/
#define RL78G13_SERIAL_SDR_FMCK_DIV_MASK                                    0XFF00U
#define RL78G13_SERIAL_SDR_FMCK_DIV_2                                       0X0000U
#define RL78G13_SERIAL_SDR_FMCK_DIV_4                                       0X0100U
#define RL78G13_SERIAL_SDR_FMCK_DIV_6                                       0X0200U
#define RL78G13_SERIAL_SDR_FMCK_DIV_8                                       0X0300U
#define RL78G13_SERIAL_SDR_FMCK_DIV_10                                      0X0400U
#define RL78G13_SERIAL_SDR_FMCK_DIV_12                                      0X0500U
#define RL78G13_SERIAL_SDR_FMCK_DIV_14                                      0X0600U
#define RL78G13_SERIAL_SDR_FMCK_DIV_16                                      0X0700U
#define RL78G13_SERIAL_SDR_FMCK_DIV_18                                      0X0800U
#define RL78G13_SERIAL_SDR_FMCK_DIV_254                                     0XFE00U
#define RL78G13_SERIAL_SDR_FMCK_DIV_256                                     0XFF00U
                              
/*SDR中的数据掩码*/
#define RL78G13_SERIAL_SDR_DATA_MASK                                        0X00FFU
                                          

/*串行标志清除触发寄存器,清除通道N各个错误标志SIR*/
/*帧错误标志清除*/
#define RL78G13_SERIAL_SIR_FECT_MASK                                        0X0004U
#define RL78G13_SERIAL_SIR_FECT_CLECR                                       0X0004U
#define RL78G13_SERIAL_SIR_FECT_NONE                                        0X0000U
  
/*奇偶校验错误标志清除*/
#define RL78G13_SERIAL_SIR_PECT_MASK                                        0X0002U
#define RL78G13_SERIAL_SIR_PECT_CLECR                                       0X0002U
#define RL78G13_SERIAL_SIR_PECT_NONE                                        0X0000U

/*溢出错误标志清除*/
#define RL78G13_SERIAL_SIR_OVCT_MASK                                        0X0001U
#define RL78G13_SERIAL_SIR_OVCT_CLECR                                       0X0001U
#define RL78G13_SERIAL_SIR_OVCT_NONE                                        0X0000U


/*串行状态寄存器SSR,指示通讯状态和错误状态,只读*/
/*通讯正在进行或者已经停止或暂停*/
#define RL78G13_SERIAL_SSR_TSF_MASK                                         0X0040U
#define RL78G13_SERIAL_SSR_TSF_RUNNING                                      0X0040U
#define RL78G13_SERIAL_SSR_TSF_STOP_PAUSE                                   0X0000U

/*有效数据是否保存在SDR中*/
#define RL78G13_SERIAL_SSR_BUFFER_MASK                                      0X0020U
#define RL78G13_SERIAL_SSR_BUFFER_FULL                                      0X0020U
#define RL78G13_SERIAL_SSR_BUFFER_EMPTY                                     0X0000U

/*帧错误标志*/
#define RL78G13_SERIAL_SSR_RECV_ERR_FLAG_MASK                               0X0004U
#define RL78G13_SERIAL_SSR_RECV_ERR_FLAG_ON                                 0X0004U
#define RL78G13_SERIAL_SSR_RECV_ERR_FLAG_NONE                               0X0000U                                       

/*奇偶校验,ACK错误检测标志*/
#define RL78G13_SERIAL_SSR_CHECK_ERR_FLAG_MASK                              0X0002U
#define RL78G13_SERIAL_SSR_CHECK_ERR_FLAG_ON                                0X0002U
#define RL78G13_SERIAL_SSR_CHECK_ERR_FLAG_NONE                              0X0000U                           

/*溢出错误检测标志*/
#define RL78G13_SERIAL_SSR_OVER_ERR_FLAG_MASK                               0X0001U
#define RL78G13_SERIAL_SSR_OVER_ERR_FLAG_ON                                 0X0001U
#define RL78G13_SERIAL_SSR_OVER_ERR_FLAG_NONE                               0X0000U                


/*串行通道开始寄存器,SS,设置通道允许,开始通讯的触发寄存器*/
/*通道0进入通讯等待状态*/
#define RL78G13_SERIAL_SS_COM0_WAIT_FLAG_MASK                               0X0001U
#define RL78G13_SERIAL_SS_COM0_WAIT_FLAG_ON                                 0X0001U
#define RL78G13_SERIAL_SS_COM0_WAIT_FLAG_OFF                                0X0000U             

/*通道1进入通讯等待状态*/
#define RL78G13_SERIAL_SS_COM1_WAIT_FLAG_MASK                               0X0002U
#define RL78G13_SERIAL_SS_COM1_WAIT_FLAG_ON                                 0X0002U
#define RL78G13_SERIAL_SS_COM1_WAIT_FLAG_OFF                                0X0000U     

/*通道2进入通讯等待状态*/
#define RL78G13_SERIAL_SS_COM2_WAIT_FLAG_MASK                               0X0004U
#define RL78G13_SERIAL_SS_COM2_WAIT_FLAG_ON                                 0X0004U
#define RL78G13_SERIAL_SS_COM2_WAIT_FLAG_OFF                                0X0000U     

/*通道3进入通讯等待状态*/
#define RL78G13_SERIAL_SS_COM3_WAIT_FLAG_MASK                               0X0008U
#define RL78G13_SERIAL_SS_COM3_WAIT_FLAG_ON                                 0X0008U
#define RL78G13_SERIAL_SS_COM3_WAIT_FLAG_OFF                                0X0000U

/*串行通道停止寄存器ST,设置通道禁止,停止通讯的触发寄存器*/
/*通道0停止通讯操作*/
#define RL78G13_SERIAL_ST_COM0_STOP_FLAG_MASK                               0X0001U
#define RL78G13_SERIAL_ST_COM0_STOP_FLAG_ON                                 0X0001U
#define RL78G13_SERIAL_ST_COM0_STOP_FLAG_OFF                                0X0000U

/*通道1停止通讯操作*/
#define RL78G13_SERIAL_ST_COM1_STOP_FLAG_MASK                               0X0002U
#define RL78G13_SERIAL_ST_COM1_STOP_FLAG_ON                                 0X0002U
#define RL78G13_SERIAL_ST_COM1_STOP_FLAG_OFF                                0X0000U

/*通道2停止通讯操作*/
#define RL78G13_SERIAL_ST_COM2_STOP_FLAG_MASK                               0X0004U
#define RL78G13_SERIAL_ST_COM2_STOP_FLAG_ON                                 0X0004U
#define RL78G13_SERIAL_ST_COM2_STOP_FLAG_OFF                                0X0000U      

/*通道3停止通讯操作*/
#define RL78G13_SERIAL_ST_COM3_STOP_FLAG_MASK                               0X0008U
#define RL78G13_SERIAL_ST_COM3_STOP_FLAG_ON                                 0X0008U
#define RL78G13_SERIAL_ST_COM3_STOP_FLAG_OFF                                0X0000U    


/*串行通道允许状态寄存器,SE,显示的就是SS和ST的设置结果,只读*/
/*通道0允许操作或者停止操作*/
#define RL78G13_SERIAL_SE_COM0_ALLOW_OP_FLAG_MASK                           0X0001U
#define RL78G13_SERIAL_SE_COM0_ALLOW_OP_FLAG_ON                             0X0001U
#define RL78G13_SERIAL_SE_COM0_ALLOW_OP_FLAG_OFF                            0X0000U                                        

/*通道1允许操作或者停止操作*/
#define RL78G13_SERIAL_SE_COM1_ALLOW_OP_FLAG_MASK                           0X0002U
#define RL78G13_SERIAL_SE_COM1_ALLOW_OP_FLAG_ON                             0X0002U
#define RL78G13_SERIAL_SE_COM1_ALLOW_OP_FLAG_OFF                            0X0000U 

/*通道2允许操作或者停止操作*/
#define RL78G13_SERIAL_SE_COM2_ALLOW_OP_FLAG_MASK                           0X0004U
#define RL78G13_SERIAL_SE_COM2_ALLOW_OP_FLAG_ON                             0X0004U
#define RL78G13_SERIAL_SE_COM2_ALLOW_OP_FLAG_OFF                            0X0000U       

/*通道3允许操作或者停止操作*/
#define RL78G13_SERIAL_SE_COM3_ALLOW_OP_FLAG_MASK                           0X0008U
#define RL78G13_SERIAL_SE_COM3_ALLOW_OP_FLAG_ON                             0X0008U
#define RL78G13_SERIAL_SE_COM3_ALLOW_OP_FLAG_OFF                            0X0000U           


/*串行输出允许寄存器SOE,设置是否允许各个串行通道的输出*/
/*通道0允许或者停止串行通道的输出*/
#define RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_MASK                     0X0001U
#define RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_ON                       0X0001U
#define RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_OFF                      0X0000U                    

/*通道1允许或者停止串行通道的输出*/
#define RL78G13_SERIAL_SOE_COM1_OUTPUT_ENABLE_FLAG_MASK                     0X0002U
#define RL78G13_SERIAL_SOE_COM1_OUTPUT_ENABLE_FLAG_ON                       0X0002U
#define RL78G13_SERIAL_SOE_COM1_OUTPUT_ENABLE_FLAG_OFF                      0X0000U                        

/*通道2允许或者停止串行通道的输出*/
#define RL78G13_SERIAL_SOE_COM2_OUTPUT_ENABLE_FLAG_MASK                     0X0004U
#define RL78G13_SERIAL_SOE_COM2_OUTPUT_ENABLE_FLAG_ON                       0X0004U
#define RL78G13_SERIAL_SOE_COM2_OUTPUT_ENABLE_FLAG_OFF                      0X0000U                      

/*通道3允许或者停止串行通道的输出*/
#define RL78G13_SERIAL_SOE_COM3_OUTPUT_ENABLE_FLAG_MASK                     0X0008U
#define RL78G13_SERIAL_SOE_COM3_OUTPUT_ENABLE_FLAG_ON                       0X0008U
#define RL78G13_SERIAL_SOE_COM3_OUTPUT_ENABLE_FLAG_OFF                      0X0000U                     

/*串行输出寄存器SO,用于各个通道串行输出的缓冲,控制串行时钟的输出和数据的输出*/
/*SE启用时,软件改写将被忽略,手动单比特传送有用*/
/*通道0时钟输出0或1*/
#define RL78G13_SERIAL_SO_COM0_CLOCK_OUTPUT_MASK                            0X0100U
#define RL78G13_SERIAL_SO_COM0_CLOCK_OUTPUT_1                               0X0100U
#define RL78G13_SERIAL_SO_COM0_CLOCK_OUTPUT_0                               0X0000U                           

/*通道1时钟输出0或1*/
#define RL78G13_SERIAL_SO_COM1_CLOCK_OUTPUT_MASK                            0X0200U
#define RL78G13_SERIAL_SO_COM1_CLOCK_OUTPUT_1                               0X0200U
#define RL78G13_SERIAL_SO_COM1_CLOCK_OUTPUT_0                               0X0000U                     

/*通道2时钟输出0或1*/
#define RL78G13_SERIAL_SO_COM2_CLOCK_OUTPUT_MASK                            0X0400U
#define RL78G13_SERIAL_SO_COM2_CLOCK_OUTPUT_1                               0X0400U
#define RL78G13_SERIAL_SO_COM2_CLOCK_OUTPUT_0                               0X0000U                                                         

/*通道3时钟输出0或1*/
#define RL78G13_SERIAL_SO_COM3_CLOCK_OUTPUT_MASK                            0X0800U
#define RL78G13_SERIAL_SO_COM3_CLOCK_OUTPUT_1                               0X0800U
#define RL78G13_SERIAL_SO_COM3_CLOCK_OUTPUT_0                               0X0000U                                                         

/*通道0数据输出0或1*/
#define RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_MASK                             0X0001U
#define RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_1                                0X0001U
#define RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_0                                0X0000U                                                         

/*通道1数据输出0或1*/
#define RL78G13_SERIAL_SO_COM1_DATA_OUTPUT_MASK                             0X0002U
#define RL78G13_SERIAL_SO_COM1_DATA_OUTPUT_1                                0X0002U
#define RL78G13_SERIAL_SO_COM1_DATA_OUTPUT_0                                0X0000U                                                        

/*通道2数据输出0或1*/
#define RL78G13_SERIAL_SO_COM2_DATA_OUTPUT_MASK                             0X0004U
#define RL78G13_SERIAL_SO_COM2_DATA_OUTPUT_1                                0X0004U
#define RL78G13_SERIAL_SO_COM2_DATA_OUTPUT_0                                0X0000U                                                       

/*通道3数据输出0或1*/
#define RL78G13_SERIAL_SO_COM3_DATA_OUTPUT_MASK                             0X0008U
#define RL78G13_SERIAL_SO_COM3_DATA_OUTPUT_1                                0X0008U
#define RL78G13_SERIAL_SO_COM3_DATA_OUTPUT_0                                0X0000U                                                      


/*串行输出电平寄存器SOL.数据电平是否反向*/
/*通道0输出数据是否反向*/
#define RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_MASK                    0X0001U
#define RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_ON                      0X0001U
#define RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_OFF                     0X0000U                                                  

/*通道2输出数据是否反向*/
#define RL78G13_SERIAL_SOL_COM2_OUTPUT_REVERSE_FLAG_MASK                    0X0004U
#define RL78G13_SERIAL_SOL_COM2_OUTPUT_REVERSE_FLAG_ON                      0X0004U
#define RL78G13_SERIAL_SOL_COM2_OUTPUT_REVERSE_FLAG_OFF                     0X0000U                                      


/*串行待机控制寄存器SSC,设置通过接受UART0或者CSI0的串行数据,控制STOP模式下启动接收*/
/*使用或者不使用SNOOZE模式*/
#define RL78G13_SERIAL_SSC_SNOOZE_ENABLE_MASK                               0X0001U
#define RL78G13_SERIAL_SSC_SNOOZE_ENABLE_FLAG                               0X0001U
#define RL78G13_SERIAL_SSC_SNOOZE_DISABLE_FLAG                              0X0000U                                        

/*允许或者停止传送结束中断*/
#define RL78G13_SERIAL_SSC_INT_ERR_ENABLE_MASK                              0X0002U
#define RL78G13_SERIAL_SSC_INT_ERR_ENABLE_FLAG                              0X0002U
#define RL78G13_SERIAL_SSC_INT_ERR_DISABLE_FLAG                             0X0000U                                              


/*输入切换控制寄存器ISC,用于切换定时器阵列7和RXD2的交替模式,主要在LIN模式使用*/
/*TI07使用正常的YI07引脚还是使用RXD2引脚*/
#define RL78G13_SERIAL_ISC_TIMER7_INPUT_MASK                                0X01U
#define RL78G13_SERIAL_ISC_TIMER7_INPUT_RXD2                                0X01U
#define RL78G13_SERIAL_ISC_TIMER7_INPUT_NORMAL                              0X00U                                           

/*外部中断INTP0使用正常的INTP0引脚还是使用RXD2引脚*/
#define RL78G13_SERIAL_ISC_INTP0_INPUT_MASK                                 0X02U
#define RL78G13_SERIAL_ISC_INTP0_INPUT_RXD2                                 0X02U
#define RL78G13_SERIAL_ISC_INTP0_INPUT_NORMAL                               0X00U                                         
     

/*噪声滤波器允许寄存器NFEN,用于控制RX引脚的噪声滤波功能的开关*/
/*RXD0引脚噪声滤波器开启或者关闭*/
#define RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_MASK                          0X01U
#define RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_OPEN                          0X01U
#define RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_CLOSE                         0X00U                                               

/*RXD1引脚噪声滤波器开启或者关闭*/
#define RL78G13_SERIAL_NFEN_RXD1_NOIZE_FILTER_MASK                          0X04U
#define RL78G13_SERIAL_NFEN_RXD1_NOIZE_FILTER_OPEN                          0X04U
#define RL78G13_SERIAL_NFEN_RXD1_NOIZE_FILTER_CLOSE                         0X00U                                              

/*RXD2引脚噪声滤波器开启或者关闭*/
#define RL78G13_SERIAL_NFEN_RXD2_NOIZE_FILTER_MASK                          0X10U
#define RL78G13_SERIAL_NFEN_RXD2_NOIZE_FILTER_OPEN                          0X10U
#define RL78G13_SERIAL_NFEN_RXD2_NOIZE_FILTER_CLOSE                         0X00U                                               

/*RXD3引脚噪声滤波器开启或者关闭*/
#define RL78G13_SERIAL_NFEN_RXD3_NOIZE_FILTER_MASK                          0X40U
#define RL78G13_SERIAL_NFEN_RXD3_NOIZE_FILTER_OPEN                          0X40U
#define RL78G13_SERIAL_NFEN_RXD3_NOIZE_FILTER_CLOSE                         0X00U

#endif





