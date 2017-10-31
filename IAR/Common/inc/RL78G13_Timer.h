#ifndef __RL78G13_TIMER_H_
#define __RL78G13_TIMER_H_
#include "MacroDriver.h"

typedef enum RL78G13_TIMER_CHANNEL
{
    RL78G13_TIMER_CHANNEL_0 = 0,
    RL78G13_TIMER_CHANNEL_1 = 1,
    RL78G13_TIMER_CHANNEL_2 = 2,
    RL78G13_TIMER_CHANNEL_3 = 3,
    RL78G13_TIMER_CHANNEL_4 = 4,
    RL78G13_TIMER_CHANNEL_5 = 5,
    RL78G13_TIMER_CHANNEL_6 = 6,
    RL78G13_TIMER_CHANNEL_7 = 7,
}RL78G13_TIMER_CHANNEL;

/*宏定义*/

/*TPS 选择定时器两个单元的时钟分频系数,一个单元拥有四个时钟*/
#define RL78G13_TIMER_TPS_CLK00_DIV_MASK                                            0X000FU
#define RL78G13_TIMER_TPS_CLK00_DIV_1                                               0X0000U
#define RL78G13_TIMER_TPS_CLK00_DIV_2                                               0X0001U
#define RL78G13_TIMER_TPS_CLK00_DIV_4                                               0X0002U
#define RL78G13_TIMER_TPS_CLK00_DIV_8                                               0X0003U
#define RL78G13_TIMER_TPS_CLK00_DIV_16                                              0X0004U
#define RL78G13_TIMER_TPS_CLK00_DIV_32                                              0X0005U
#define RL78G13_TIMER_TPS_CLK00_DIV_64                                              0X0006U
#define RL78G13_TIMER_TPS_CLK00_DIV_128                                             0X0007U
#define RL78G13_TIMER_TPS_CLK00_DIV_256                                             0X0008U
#define RL78G13_TIMER_TPS_CLK00_DIV_512                                             0X0009U
#define RL78G13_TIMER_TPS_CLK00_DIV_1024                                            0X000AU
#define RL78G13_TIMER_TPS_CLK00_DIV_2048                                            0X000BU
#define RL78G13_TIMER_TPS_CLK00_DIV_4096                                            0X000CU
#define RL78G13_TIMER_TPS_CLK00_DIV_8192                                            0X000DU
#define RL78G13_TIMER_TPS_CLK00_DIV_16384                                           0X000EU
#define RL78G13_TIMER_TPS_CLK00_DIV_32768                                           0X000FU
                                                                                    
#define RL78G13_TIMER_TPS_CLK01_DIV_MASK                                            0X00F0U
#define RL78G13_TIMER_TPS_CLK01_DIV_1                                               0X0000U
#define RL78G13_TIMER_TPS_CLK01_DIV_2                                               0X0010U
#define RL78G13_TIMER_TPS_CLK01_DIV_4                                               0X0020U
#define RL78G13_TIMER_TPS_CLK01_DIV_8                                               0X0030U
#define RL78G13_TIMER_TPS_CLK01_DIV_16                                              0X0040U
#define RL78G13_TIMER_TPS_CLK01_DIV_32                                              0X0050U
#define RL78G13_TIMER_TPS_CLK01_DIV_64                                              0X0060U
#define RL78G13_TIMER_TPS_CLK01_DIV_128                                             0X0070U
#define RL78G13_TIMER_TPS_CLK01_DIV_256                                             0X0080U
#define RL78G13_TIMER_TPS_CLK01_DIV_512                                             0X0090U
#define RL78G13_TIMER_TPS_CLK01_DIV_1024                                            0X00A0U
#define RL78G13_TIMER_TPS_CLK01_DIV_2048                                            0X00B0U
#define RL78G13_TIMER_TPS_CLK01_DIV_4096                                            0X00C0U
#define RL78G13_TIMER_TPS_CLK01_DIV_8192                                            0X00D0U
#define RL78G13_TIMER_TPS_CLK01_DIV_16384                                           0X00E0U
#define RL78G13_TIMER_TPS_CLK01_DIV_32768                                           0X00F0U
                                                                                    
                                                                                    
#define RL78G13_TIMER_TPS_CLK02_DIV_MASK                                            0X0300U
#define RL78G13_TIMER_TPS_CLK02_DIV_2                                               0X0000U
#define RL78G13_TIMER_TPS_CLK02_DIV_4                                               0X0100U
#define RL78G13_TIMER_TPS_CLK02_DIV_16                                              0X0200U
#define RL78G13_TIMER_TPS_CLK02_DIV_64                                              0X0300U
                                                                                    
                                                                                    
#define RL78G13_TIMER_TPS_CLK03_DIV_MASK                                            0X3000U
#define RL78G13_TIMER_TPS_CLK03_DIV_2                                               0X0000U
#define RL78G13_TIMER_TPS_CLK03_DIV_4                                               0X1000U
#define RL78G13_TIMER_TPS_CLK03_DIV_16                                              0X2000U
#define RL78G13_TIMER_TPS_CLK03_DIV_64                                              0X3000U
                                                                                    
                                                                                    
/*TMR 选择定时器指定通道的时钟,运行模式,触发条件*/                                                                             
#define RL78G13_TIMER_TMR_CLOCK_SELECT_MASK                                         0XC000U
#define RL78G13_TIMER_TMR_CLOCK_SELECT_CLK0                                         0X0000U
#define RL78G13_TIMER_TMR_CLOCK_SELECT_CLK2                                         0X4000U
#define RL78G13_TIMER_TMR_CLOCK_SELECT_CLK1                                         0X8000U
#define RL78G13_TIMER_TMR_CLOCK_SELECT_CLK3                                         0XC000U
                                                                                    
#define RL78G13_TIMER_TMR_CCS_FTCLK_SELECT_MASK                                     0X1000U
#define RL78G13_TIMER_TMR_CCS_FTCLK_SELECT_MCK                                      0X0000U
#define RL78G13_TIMER_TMR_CCS_FTCLK_SELECT_INPUT                                    0X1000U
                                                                                    
#define RL78G13_TIMER_TMR_STS_TRIG_SRC_SELECT_MASK                                  0X0700U
#define RL78G13_TIMER_TMR_STS_TRIG_SRC_SELECT_SOFT                                  0X0000U
#define RL78G13_TIMER_TMR_STS_TRIG_SRC_SELECT_ALL_EDGE                              0X0100U
#define RL78G13_TIMER_TMR_STS_TRIG_SRC_SELECT_2EDGE                                 0X0200U
#define RL78G13_TIMER_TMR_STS_TRIG_SRC_SELECT_INT_MAIN                              0X0400U
                                                                                    
#define RL78G13_TIMER_TMR_CIS_TRIG_EDGE_SELECT_MASK                                 0X00C0U
#define RL78G13_TIMER_TMR_CIS_TRIG_EDGE_SELECT_FALLING                              0X0000U
#define RL78G13_TIMER_TMR_CIS_TRIG_EDGE_SELECT_RISEING                              0X0040U
#define RL78G13_TIMER_TMR_CIS_TRIG_EDGE_SELECT_ALL_BY_LOW                           0X0080U
#define RL78G13_TIMER_TMR_CIS_TRIG_EDGE_SELECT_ALL_BY_HIGH                          0X00C0U
                                                                                    
#define RL78G13_TIMER_TMR_CHANNEL_MODE_SELECT_MASK                                  0X000EU
#define RL78G13_TIMER_TMR_CHANNEL_MODE_SELECT_COUNT                                 0X0000U
#define RL78G13_TIMER_TMR_CHANNEL_MODE_SELECT_CAPTURE                               0X0004U
#define RL78G13_TIMER_TMR_CHANNEL_MODE_SELECT_EVENT_COUNT                           0X0006U
#define RL78G13_TIMER_TMR_CHANNEL_MODE_SELECT_ONLY_COUNT                            0X0008U
#define RL78G13_TIMER_TMR_CHANNEL_MODE_SELECT_CAPTURE_ONLY_COUNT                    0X000CU
                                                                                    
#define RL78G13_TIMER_TMR_START_INT_ENABLE_MASK                                     0X0001U
#define RL78G13_TIMER_TMR_START_INT_ENABLE                                          0X0001U
#define RL78G13_TIMER_TMR_START_INT_DISABLE                                         0X0000U
                                                                                    
#define RL78G13_TIMER_TMR_MASTER_SELECT_MASK                                        0X0800U
#define RL78G13_TIMER_TMR_MASTER_SELECT_SINGLE                                      0X0000U
#define RL78G13_TIMER_TMR_MASTER_SELECT_LINK                                        0X0800U
                                                                                    
#define RL78G13_TIMER_TMR_SPLIT_SELECT_MASK                                         0X0800U
#define RL78G13_TIMER_TMR_SPLIT_SELECT_16BIT                                        0X0000U
#define RL78G13_TIMER_TMR_SPLIT_SELECT_8BIT                                         0X0800U
                                                                                    
/*TSR 指定通道是否发出溢出事件*/                                                                             
#define RL78G13_TIMER_TSR_OVERFLOW_MASK                                             0X0001U
#define RL78G13_TIMER_TSR_OVERFLOW_ON                                               0X0001U
#define RL78G13_TIMER_TSR_OVERFLOW_OFF                                              0X0000U
                                                                                    
/*TE 当前通道处于运行状态还是停滞状态*/                                                                              
#define RL78G13_TIMER_TE_CHANNEL0_STATUS_MASK                                       0X0001U
#define RL78G13_TIMER_TE_CHANNEL0_STATUS_ENABLE                                     0X0001U
#define RL78G13_TIMER_TE_CHANNEL0_STATUS_DISABLE                                    0X0000U
                                                                                    
#define RL78G13_TIMER_TE_CHANNEL1_STATUS_MASK                                       0X0002U
#define RL78G13_TIMER_TE_CHANNEL1_STATUS_ENABLE                                     0X0002U
#define RL78G13_TIMER_TE_CHANNEL1_STATUS_DISABLE                                    0X0000U
                                                                                    
#define RL78G13_TIMER_TE_CHANNEL2_STATUS_MASK                                       0X0004U
#define RL78G13_TIMER_TE_CHANNEL2_STATUS_ENABLE                                     0X0004U
#define RL78G13_TIMER_TE_CHANNEL2_STATUS_DISABLE                                    0X0000U
                                                                                    
#define RL78G13_TIMER_TE_CHANNEL3_STATUS_MASK                                       0X0008U
#define RL78G13_TIMER_TE_CHANNEL3_STATUS_ENABLE                                     0X0008U
#define RL78G13_TIMER_TE_CHANNEL3_STATUS_DISABLE                                    0X0000U
                                                                                    
#define RL78G13_TIMER_TE_CHANNEL4_STATUS_MASK                                       0X0010U
#define RL78G13_TIMER_TE_CHANNEL4_STATUS_ENABLE                                     0X0010U
#define RL78G13_TIMER_TE_CHANNEL4_STATUS_DISABLE                                    0X0000U
                                                                                    
#define RL78G13_TIMER_TE_CHANNEL5_STATUS_MASK                                       0X0020U
#define RL78G13_TIMER_TE_CHANNEL5_STATUS_ENABLE                                     0X0020U
#define RL78G13_TIMER_TE_CHANNEL5_STATUS_DISABLE                                    0X0000U
                                                                                    
#define RL78G13_TIMER_TE_CHANNEL6_STATUS_MASK                                       0X0040U
#define RL78G13_TIMER_TE_CHANNEL6_STATUS_ENABLE                                     0X0040U
#define RL78G13_TIMER_TE_CHANNEL6_STATUS_DISABLE                                    0X0000U
                                                                                    
#define RL78G13_TIMER_TE_CHANNEL7_STATUS_MASK                                       0X0080U
#define RL78G13_TIMER_TE_CHANNEL7_STATUS_ENABLE                                     0X0080U
#define RL78G13_TIMER_TE_CHANNEL7_STATUS_DISABLE                                    0X0000U
                                                                                    
#define RL78G13_TIMER_TE_CHANNEL_H1_STATUS_MASK                                     0X0200U
#define RL78G13_TIMER_TE_CHANNEL_H1_STATUS_ENABLE                                   0X0200U
#define RL78G13_TIMER_TE_CHANNEL_H1_STATUS_DISABLE                                  0X0000U
                                                                                    
#define RL78G13_TIMER_TE_CHANNEL_H3_STATUS_MASK                                     0X0800U
#define RL78G13_TIMER_TE_CHANNEL_H3_STATUS_ENABLE                                   0X0800U
#define RL78G13_TIMER_TE_CHANNEL_H3_STATUS_DISABLE                                  0X0000U
                                                                                    
                                                                                    
/*TS 指定通道启动运行*/                                                                              
#define RL78G13_TIMER_TS_CHANNEL0_START_ON_MASK                                     0X0001U
#define RL78G13_TIMER_TS_CHANNEL0_START_ON                                          0X0001U
#define RL78G13_TIMER_TS_CHANNEL0_START_OFF                                         0X0000U

#define RL78G13_TIMER_TS_CHANNEL1_START_ON_MASK                                     0X0002U
#define RL78G13_TIMER_TS_CHANNEL1_START_ON                                          0X0002U
#define RL78G13_TIMER_TS_CHANNEL1_START_OFF                                         0X0000U

#define RL78G13_TIMER_TS_CHANNEL2_START_ON_MASK                                     0X0004U
#define RL78G13_TIMER_TS_CHANNEL2_START_ON                                          0X0004U
#define RL78G13_TIMER_TS_CHANNEL2_START_OFF                                         0X0000U

#define RL78G13_TIMER_TS_CHANNEL3_START_ON_MASK                                     0X0008U
#define RL78G13_TIMER_TS_CHANNEL3_START_ON                                          0X0008U
#define RL78G13_TIMER_TS_CHANNEL3_START_OFF                                         0X0000U

#define RL78G13_TIMER_TS_CHANNEL4_START_ON_MASK                                     0X0010U
#define RL78G13_TIMER_TS_CHANNEL4_START_ON                                          0X0010U
#define RL78G13_TIMER_TS_CHANNEL4_START_OFF                                         0X0000U

#define RL78G13_TIMER_TS_CHANNEL5_START_ON_MASK                                     0X0020U
#define RL78G13_TIMER_TS_CHANNEL5_START_ON                                          0X0020U
#define RL78G13_TIMER_TS_CHANNEL5_START_OFF                                         0X0000U

#define RL78G13_TIMER_TS_CHANNEL6_START_ON_MASK                                     0X0040U
#define RL78G13_TIMER_TS_CHANNEL6_START_ON                                          0X0040U
#define RL78G13_TIMER_TS_CHANNEL6_START_OFF                                         0X0000U

#define RL78G13_TIMER_TS_CHANNEL7_START_ON_MASK                                     0X0080U
#define RL78G13_TIMER_TS_CHANNEL7_START_ON                                          0X0080U
#define RL78G13_TIMER_TS_CHANNEL7_START_OFF                                         0X0000U

#define RL78G13_TIMER_TS_CHANNEL_H1_START_ON_MASK                                   0X0200U
#define RL78G13_TIMER_TS_CHANNEL_H1_START_ON                                        0X0200U
#define RL78G13_TIMER_TS_CHANNEL_H1_START_OFF                                       0X0000U

#define RL78G13_TIMER_TS_CHANNEL_H3_START_ON_MASK                                   0X0800U
#define RL78G13_TIMER_TS_CHANNEL_H3_START_ON                                        0X0800U
#define RL78G13_TIMER_TS_CHANNEL_H3_START_OFF                                       0X0000U
                                                                                    
                                                                                    
                                                                                    
/*TT 指定通道运行停止*/                                                                              
#define RL78G13_TIMER_TT_CHANNEL0_STOP_ON_MASK                                      0X0001U
#define RL78G13_TIMER_TT_CHANNEL0_STOP_ON                                           0X0001U
#define RL78G13_TIMER_TT_CHANNEL0_STOP_OFF                                          0X0000U

#define RL78G13_TIMER_TT_CHANNEL1_STOP_ON_MASK                                      0X0002U
#define RL78G13_TIMER_TT_CHANNEL1_STOP_ON                                           0X0002U
#define RL78G13_TIMER_TT_CHANNEL1_STOP_OFF                                          0X0000U

#define RL78G13_TIMER_TT_CHANNEL2_STOP_ON_MASK                                      0X0004U
#define RL78G13_TIMER_TT_CHANNEL2_STOP_ON                                           0X0004U
#define RL78G13_TIMER_TT_CHANNEL2_STOP_OFF                                          0X0000U

#define RL78G13_TIMER_TT_CHANNEL3_STOP_ON_MASK                                      0X0008U
#define RL78G13_TIMER_TT_CHANNEL3_STOP_ON                                           0X0008U
#define RL78G13_TIMER_TT_CHANNEL3_STOP_OFF                                          0X0000U

#define RL78G13_TIMER_TT_CHANNEL4_STOP_ON_MASK                                      0X0010U
#define RL78G13_TIMER_TT_CHANNEL4_STOP_ON                                           0X0010U
#define RL78G13_TIMER_TT_CHANNEL4_STOP_OFF                                          0X0000U

#define RL78G13_TIMER_TT_CHANNEL5_STOP_ON_MASK                                      0X0020U
#define RL78G13_TIMER_TT_CHANNEL5_STOP_ON                                           0X0020U
#define RL78G13_TIMER_TT_CHANNEL5_STOP_OFF                                          0X0000U

#define RL78G13_TIMER_TT_CHANNEL6_STOP_ON_MASK                                      0X0040U
#define RL78G13_TIMER_TT_CHANNEL6_STOP_ON                                           0X0040U
#define RL78G13_TIMER_TT_CHANNEL6_STOP_OFF                                          0X0000U

#define RL78G13_TIMER_TT_CHANNEL7_STOP_ON_MASK                                      0X0080U
#define RL78G13_TIMER_TT_CHANNEL7_STOP_ON                                           0X0080U
#define RL78G13_TIMER_TT_CHANNEL7_STOP_OFF                                          0X0000U

#define RL78G13_TIMER_TT_CHANNEL_H1_STOP_ON_MASK                                    0X0200U
#define RL78G13_TIMER_TT_CHANNEL_H1_STOP_ON                                         0X0200U
#define RL78G13_TIMER_TT_CHANNEL_H1_STOP_OFF                                        0X0000U

#define RL78G13_TIMER_TT_CHANNEL_H3_STOP_ON_MASK                                    0X0800U
#define RL78G13_TIMER_TT_CHANNEL_H3_STOP_ON                                         0X0800U
#define RL78G13_TIMER_TT_CHANNEL_H3_STOP_OFF                                        0X0000U
                                                                                    
/*TIS 通道5的定时器输入信号*/                                                                             
#define RL78G13_TIMER_TIS_CHANNEL5_INPUT_PIN_SELECT_MASK                            0X07U
#define RL78G13_TIMER_TIS_CHANNEL5_INPUT_PIN_SELECT_TIO5                            0X00U
#define RL78G13_TIMER_TIS_CHANNEL5_INPUT_PIN_SELECT_FIL                             0X04U
#define RL78G13_TIMER_TIS_CHANNEL5_INPUT_PIN_SELECT_FSUB                            0X05U
                                                                                    
/*TOE 禁止或者使能定时器的输出*/                                                                             
#define RL78G13_TIMER_TOE_CHANNEL_0_OUTPUT_SET_MASK                                 0X0001U
#define RL78G13_TIMER_TOE_CHANNEL_0_OUTPUT_SET_DISABLE                              0X0000U
#define RL78G13_TIMER_TOE_CHANNEL_0_OUTPUT_SET_ENABLE                               0X0001U
                                                                                    
#define RL78G13_TIMER_TOE_CHANNEL_1_OUTPUT_SET_MASK                                 0X0002U
#define RL78G13_TIMER_TOE_CHANNEL_1_OUTPUT_SET_DISABLE                              0X0000U
#define RL78G13_TIMER_TOE_CHANNEL_1_OUTPUT_SET_ENABLE                               0X0002U
                                                                                    
#define RL78G13_TIMER_TOE_CHANNEL_2_OUTPUT_SET_MASK                                 0X0004U
#define RL78G13_TIMER_TOE_CHANNEL_2_OUTPUT_SET_DISABLE                              0X0000U
#define RL78G13_TIMER_TOE_CHANNEL_2_OUTPUT_SET_ENABLE                               0X0004U
                                                                                    
#define RL78G13_TIMER_TOE_CHANNEL_3_OUTPUT_SET_MASK                                 0X0008U
#define RL78G13_TIMER_TOE_CHANNEL_3_OUTPUT_SET_DISABLE                              0X0000U
#define RL78G13_TIMER_TOE_CHANNEL_3_OUTPUT_SET_ENABLE                               0X0008U
                                                                                    
#define RL78G13_TIMER_TOE_CHANNEL_4_OUTPUT_SET_MASK                                 0X0010U
#define RL78G13_TIMER_TOE_CHANNEL_4_OUTPUT_SET_DISABLE                              0X0000U
#define RL78G13_TIMER_TOE_CHANNEL_4_OUTPUT_SET_ENABLE                               0X0010U
                                                                                    
#define RL78G13_TIMER_TOE_CHANNEL_5_OUTPUT_SET_MASK                                 0X0020U
#define RL78G13_TIMER_TOE_CHANNEL_5_OUTPUT_SET_DISABLE                              0X0000U
#define RL78G13_TIMER_TOE_CHANNEL_5_OUTPUT_SET_ENABLE                               0X0020U
                                                                                    
#define RL78G13_TIMER_TOE_CHANNEL_6_OUTPUT_SET_MASK                                 0X0040U
#define RL78G13_TIMER_TOE_CHANNEL_6_OUTPUT_SET_DISABLE                              0X0000U
#define RL78G13_TIMER_TOE_CHANNEL_6_OUTPUT_SET_ENABLE                               0X0040U
                                                                                    
#define RL78G13_TIMER_TOE_CHANNEL_7_OUTPUT_SET_MASK                                 0X0080U
#define RL78G13_TIMER_TOE_CHANNEL_7_OUTPUT_SET_DISABLE                              0X0000U
#define RL78G13_TIMER_TOE_CHANNEL_7_OUTPUT_SET_ENABLE                               0X0080U
                                                                                    
                                                                                    
/*TO 定时器输出寄存器*/                                                                              
#define RL78G13_TIMER_TO_CHANNEL_0_OUTPUT_VALUE_MASK                                0X0001U
#define RL78G13_TIMER_TO_CHANNEL_0_OUTPUT_VALUE_1                                   0X0001U
#define RL78G13_TIMER_TO_CHANNEL_0_OUTPUT_VALUE_0                                   0X0000U
                                                                                    
#define RL78G13_TIMER_TO_CHANNEL_1_OUTPUT_VALUE_MASK                                0X0002U
#define RL78G13_TIMER_TO_CHANNEL_1_OUTPUT_VALUE_1                                   0X0002U
#define RL78G13_TIMER_TO_CHANNEL_1_OUTPUT_VALUE_0                                   0X0000U
                                                                                    
#define RL78G13_TIMER_TO_CHANNEL_2_OUTPUT_VALUE_MASK                                0X0004U
#define RL78G13_TIMER_TO_CHANNEL_2_OUTPUT_VALUE_1                                   0X0004U
#define RL78G13_TIMER_TO_CHANNEL_2_OUTPUT_VALUE_0                                   0X0000U
                                                                                    
#define RL78G13_TIMER_TO_CHANNEL_3_OUTPUT_VALUE_MASK                                0X0008U
#define RL78G13_TIMER_TO_CHANNEL_3_OUTPUT_VALUE_1                                   0X0008U
#define RL78G13_TIMER_TO_CHANNEL_3_OUTPUT_VALUE_0                                   0X0000U
                                                                                    
#define RL78G13_TIMER_TO_CHANNEL_4_OUTPUT_VALUE_MASK                                0X0010U
#define RL78G13_TIMER_TO_CHANNEL_4_OUTPUT_VALUE_1                                   0X0010U
#define RL78G13_TIMER_TO_CHANNEL_4_OUTPUT_VALUE_0                                   0X0000U
                                                                                    
#define RL78G13_TIMER_TO_CHANNEL_5_OUTPUT_VALUE_MASK                                0X0020U
#define RL78G13_TIMER_TO_CHANNEL_5_OUTPUT_VALUE_1                                   0X0020U
#define RL78G13_TIMER_TO_CHANNEL_5_OUTPUT_VALUE_0                                   0X0000U
                                                                                    
#define RL78G13_TIMER_TO_CHANNEL_6_OUTPUT_VALUE_MASK                                0X0040U
#define RL78G13_TIMER_TO_CHANNEL_6_OUTPUT_VALUE_1                                   0X0040U
#define RL78G13_TIMER_TO_CHANNEL_6_OUTPUT_VALUE_0                                   0X0000U
                                                                                    
#define RL78G13_TIMER_TO_CHANNEL_7_OUTPUT_VALUE_MASK                                0X0080U
#define RL78G13_TIMER_TO_CHANNEL_7_OUTPUT_VALUE_1                                   0X0080U
#define RL78G13_TIMER_TO_CHANNEL_7_OUTPUT_VALUE_0                                   0X0000U
                                                                                    
/*TOL 输出电平逻辑寄存器,正向为0 反向为1*/                                                                             
#define RL78G13_TIMER_TOL_CHANNEL_1_OUTPUT_REVESER_MASK                             0X0002U
#define RL78G13_TIMER_TOL_CHANNEL_1_OUTPUT_REVESER_ON                               0X0002U
#define RL78G13_TIMER_TOL_CHANNEL_1_OUTPUT_REVESER_OFF                              0X0000U

#define RL78G13_TIMER_TOL_CHANNEL_2_OUTPUT_REVESER_MASK                             0X0004U
#define RL78G13_TIMER_TOL_CHANNEL_2_OUTPUT_REVESER_ON                               0X0004U
#define RL78G13_TIMER_TOL_CHANNEL_2_OUTPUT_REVESER_OFF                              0X0000U

#define RL78G13_TIMER_TOL_CHANNEL_3_OUTPUT_REVESER_MASK                             0X0008U
#define RL78G13_TIMER_TOL_CHANNEL_3_OUTPUT_REVESER_ON                               0X0008U
#define RL78G13_TIMER_TOL_CHANNEL_3_OUTPUT_REVESER_OFF                              0X0000U

#define RL78G13_TIMER_TOL_CHANNEL_4_OUTPUT_REVESER_MASK                             0X0010U
#define RL78G13_TIMER_TOL_CHANNEL_4_OUTPUT_REVESER_ON                               0X0010U
#define RL78G13_TIMER_TOL_CHANNEL_4_OUTPUT_REVESER_OFF                              0X0000U

#define RL78G13_TIMER_TOL_CHANNEL_5_OUTPUT_REVESER_MASK                             0X0020U
#define RL78G13_TIMER_TOL_CHANNEL_5_OUTPUT_REVESER_ON                               0X0020U
#define RL78G13_TIMER_TOL_CHANNEL_5_OUTPUT_REVESER_OFF                              0X0000U

#define RL78G13_TIMER_TOL_CHANNEL_6_OUTPUT_REVESER_MASK                             0X0040U
#define RL78G13_TIMER_TOL_CHANNEL_6_OUTPUT_REVESER_ON                               0X0040U
#define RL78G13_TIMER_TOL_CHANNEL_6_OUTPUT_REVESER_OFF                              0X0000U

#define RL78G13_TIMER_TOL_CHANNEL_7_OUTPUT_REVESER_MASK                             0X0080U
#define RL78G13_TIMER_TOL_CHANNEL_7_OUTPUT_REVESER_ON                               0X0080U
#define RL78G13_TIMER_TOL_CHANNEL_7_OUTPUT_REVESER_OFF                              0X0000U
                                                                                   
                                                                                    
/*TOM 通道输出模式寄存器,中断输出还是从属输出*/                                                                             
#define RL78G13_TIMER_TOM_CHANNEL_1_OUTPUT_MODE_MASK                                0X0002U
#define RL78G13_TIMER_TOM_CHANNEL_1_OUTPUT_MODE_MAIN                                0X0000U
#define RL78G13_TIMER_TOM_CHANNEL_1_OUTPUT_MODE_SUB                                 0X0002U
                                             

#define RL78G13_TIMER_TOM_CHANNEL_2_OUTPUT_MODE_MASK                                0X0004U
#define RL78G13_TIMER_TOM_CHANNEL_2_OUTPUT_MODE_MAIN                                0X0000U
#define RL78G13_TIMER_TOM_CHANNEL_2_OUTPUT_MODE_SUB                                 0X0004U
                                                

#define RL78G13_TIMER_TOM_CHANNEL_3_OUTPUT_MODE_MASK                                0X0008U
#define RL78G13_TIMER_TOM_CHANNEL_3_OUTPUT_MODE_MAIN                                0X0000U
#define RL78G13_TIMER_TOM_CHANNEL_3_OUTPUT_MODE_SUB                                 0X0008U
                                              

#define RL78G13_TIMER_TOM_CHANNEL_4_OUTPUT_MODE_MASK                                0X0010U
#define RL78G13_TIMER_TOM_CHANNEL_4_OUTPUT_MODE_MAIN                                0X0000U
#define RL78G13_TIMER_TOM_CHANNEL_4_OUTPUT_MODE_SUB                                 0X0010U
                                                

#define RL78G13_TIMER_TOM_CHANNEL_5_OUTPUT_MODE_MASK                                0X0020U
#define RL78G13_TIMER_TOM_CHANNEL_5_OUTPUT_MODE_MAIN                                0X0000U
#define RL78G13_TIMER_TOM_CHANNEL_5_OUTPUT_MODE_SUB                                 0X0020U
                                                     

#define RL78G13_TIMER_TOM_CHANNEL_6_OUTPUT_MODE_MASK                                0X0040U
#define RL78G13_TIMER_TOM_CHANNEL_6_OUTPUT_MODE_MAIN                                0X0000U
#define RL78G13_TIMER_TOM_CHANNEL_6_OUTPUT_MODE_SUB                                 0X0040U
                                                 

#define RL78G13_TIMER_TOM_CHANNEL_7_OUTPUT_MODE_MASK                                0X0080U
#define RL78G13_TIMER_TOM_CHANNEL_7_OUTPUT_MODE_MAIN                                0X0000U
#define RL78G13_TIMER_TOM_CHANNEL_7_OUTPUT_MODE_SUB                                 0X0080U
                                                   
/*NFEN滤波*/
#define RL78G13_TIMER_NFEN2_CHANNEL_0_NOISE_FILTER_MODE_MASK                        0X01U
#define RL78G13_TIMER_NFEN2_CHANNEL_0_NOISE_FILTER_MODE_ENABLE                      0X01U
#define RL78G13_TIMER_NFEN2_CHANNEL_0_NOISE_FILTER_MODE_DISABLE                     0X00U
                                                                                   
#define RL78G13_TIMER_NFEN2_CHANNEL_1_NOISE_FILTER_MODE_MASK                        0X02U
#define RL78G13_TIMER_NFEN2_CHANNEL_1_NOISE_FILTER_MODE_ENABLE                      0X02U
#define RL78G13_TIMER_NFEN2_CHANNEL_1_NOISE_FILTER_MODE_DISABLE                     0X00U
                                                                   
#define RL78G13_TIMER_NFEN2_CHANNEL_2_NOISE_FILTER_MODE_MASK                        0X04U
#define RL78G13_TIMER_NFEN2_CHANNEL_2_NOISE_FILTER_MODE_ENABLE                      0X04U
#define RL78G13_TIMER_NFEN2_CHANNEL_2_NOISE_FILTER_MODE_DISABLE                     0X00U
                                                                    
#define RL78G13_TIMER_NFEN2_CHANNEL_3_NOISE_FILTER_MODE_MASK                        0X08U
#define RL78G13_TIMER_NFEN2_CHANNEL_3_NOISE_FILTER_MODE_ENABLE                      0X08U
#define RL78G13_TIMER_NFEN2_CHANNEL_3_NOISE_FILTER_MODE_DISABLE                     0X00U
                                                                                    
#define RL78G13_TIMER_NFEN2_CHANNEL_4_NOISE_FILTER_MODE_MASK                        0X10U
#define RL78G13_TIMER_NFEN2_CHANNEL_4_NOISE_FILTER_MODE_ENABLE                      0X10U
#define RL78G13_TIMER_NFEN2_CHANNEL_4_NOISE_FILTER_MODE_DISABLE                     0X00U
                                                                                    
#define RL78G13_TIMER_NFEN2_CHANNEL_5_NOISE_FILTER_MODE_MASK                        0X20U
#define RL78G13_TIMER_NFEN2_CHANNEL_5_NOISE_FILTER_MODE_ENABLE                      0X20U
#define RL78G13_TIMER_NFEN2_CHANNEL_5_NOISE_FILTER_MODE_DISABLE                     0X00U
                                                                                    
#define RL78G13_TIMER_NFEN2_CHANNEL_6_NOISE_FILTER_MODE_MASK                        0X40U
#define RL78G13_TIMER_NFEN2_CHANNEL_6_NOISE_FILTER_MODE_ENABLE                      0X40U
#define RL78G13_TIMER_NFEN2_CHANNEL_6_NOISE_FILTER_MODE_DISABLE                     0X00U
                                                                                    
#define RL78G13_TIMER_NFEN2_CHANNEL_7_NOISE_FILTER_MODE_MASK                        0X80U
#define RL78G13_TIMER_NFEN2_CHANNEL_7_NOISE_FILTER_MODE_ENABLE                      0X80U
#define RL78G13_TIMER_NFEN2_CHANNEL_7_NOISE_FILTER_MODE_DISABLE                     0X00U



/*函数API接口定义*/

void RL78G13_Timer_TPS_Write_All(uint16_t flck0, uint16_t flck1,
    uint16_t flck2, uint16_t flck3);
void RL78G13_Timer_TPS_Write_One(uint16_t mask, uint16_t value);
uint16_t RL78G13_Timer_TPS_ReadAll(void);
uint16_t RL78G13_Timer_TPS_ReadOne(uint16_t mask);

void RL78G13_Timer_TMR_Write_All(RL78G13_TIMER_CHANNEL ch, uint16_t clkSelect,
    uint16_t tclkSelect, uint16_t masterSplitSelect, uint16_t trigStartMode,
    uint16_t edgeSelect, uint16_t channelModeSelect, uint16_t startIntSet);
void RL78G13_Timer_TMR_Write_One(RL78G13_TIMER_CHANNEL ch,
    uint16_t mask, uint16_t value);
uint16_t RL78G13_Timer_TMR_ReadAll(RL78G13_TIMER_CHANNEL ch);
uint16_t RL78G13_Timer_TMR_ReadOne(RL78G13_TIMER_CHANNEL ch,
    uint16_t mask);


uint16_t RL78G13_Timer_TSR_ReadAll(RL78G13_TIMER_CHANNEL ch);
uint16_t RL78G13_Timer_TSR_ReadOne(RL78G13_TIMER_CHANNEL ch,
    uint16_t mask);

uint16_t RL78G13_Timer_TE_ReadAll(void);
uint16_t RL78G13_Timer_TE_ReadOne(uint16_t mask);


void RL78G13_Timer_TS_Write_All(uint16_t channel0Start, uint16_t channel1Start,
    uint16_t channel2Start, uint16_t channel3Start, uint16_t channel4Start,
    uint16_t channel5Start, uint16_t channel6Start, uint16_t channel7Start,
    uint16_t channelh1Start, uint16_t channelh3Start);
void RL78G13_Timer_TS_Write_One(uint16_t mask, uint16_t value);
uint16_t RL78G13_Timer_TS_ReadAll(void);
uint16_t RL78G13_Timer_TS_ReadOne(uint16_t mask);

void RL78G13_Timer_TT_Write_All(uint16_t channel0Stop, uint16_t channel1Stop,
    uint16_t channel2Stop, uint16_t channel3Stop, uint16_t channel4Stop,
    uint16_t channel5Stop, uint16_t channel6Stop, uint16_t channel7Stop,
    uint16_t channelh1Stop, uint16_t channelh3Stop);
void RL78G13_Timer_TT_Write_One(uint16_t mask, uint16_t value);
uint16_t RL78G13_Timer_TT_ReadAll(void);
uint16_t RL78G13_Timer_TT_ReadOne(uint16_t mask);

void RL78G13_Timer_TIS_Write_All(uint8_t ch5InputSelect);
void RL78G13_Timer_TIS_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_Timer_TIS_ReadAll(void);
uint8_t RL78G13_Timer_TIS_ReadOne(uint8_t mask);

void RL78G13_Timer_TOE_Write_All(uint16_t channel0OutputEnable, uint16_t channel1OutputEnable,
    uint16_t channel2OutputEnable, uint16_t channel3OutputEnable, uint16_t channel4OutputEnable,
    uint16_t channel5OutputEnable, uint16_t channel6OutputEnable, uint16_t channel7OutputEnable);
void RL78G13_Timer_TOE_Write_One(uint16_t mask, uint16_t value);
uint16_t RL78G13_Timer_TOE_ReadAll(void);
uint16_t RL78G13_Timer_TOE_ReadOne(uint16_t mask);


void RL78G13_Timer_TO_Write_All(uint16_t channel0OutputValue, uint16_t channel1OutputValue,
    uint16_t channel2OutputValue, uint16_t channel3OutputValue, uint16_t channel4OutputValue,
    uint16_t channel5OutputValue, uint16_t channel6OutputValue, uint16_t channel7OutputValue);
void RL78G13_Timer_TO_Write_One(uint16_t mask, uint16_t value);
uint16_t RL78G13_Timer_TO_ReadAll(void);
uint16_t RL78G13_Timer_TO_ReadOne(uint16_t mask);

void RL78G13_Timer_TOL_Write_All(uint16_t channel1Resever, uint16_t channel2Resever,
    uint16_t channel3Resever, uint16_t channel4Resever, uint16_t channel5Resever,
    uint16_t channel6Resever, uint16_t channel7Resever);
void RL78G13_Timer_TOL_Write_One(uint16_t mask, uint16_t value);
uint16_t RL78G13_Timer_TOL_ReadAll(void);
uint16_t RL78G13_Timer_TOL_ReadOne(uint16_t mask);

void RL78G13_Timer_TOM_Write_All(uint16_t channel1OutPutMode, uint16_t channel2OutPutMode,
    uint16_t channel3OutPutMode, uint16_t channel4OutPutMode, uint16_t channel5OutPutMode,
    uint16_t channel6OutPutMode, uint16_t channel7OutPutMode);
void RL78G13_Timer_TOM_Write_One(uint16_t mask, uint16_t value);
uint16_t RL78G13_Timer_TOM_ReadAll(void);
uint16_t RL78G13_Timer_TOM_ReadOne(uint16_t mask);

void RL78G13_Timer_NFEN1_Write_All(uint8_t channel0NoiseFilterEnable,
    uint8_t channel1NoiseFilterEnable, uint8_t channel2NoiseFilterEnable,
    uint8_t channel3NoiseFilterEnable, uint8_t channel4NoiseFilterEnable,
    uint8_t channel5NoiseFilterEnable, uint8_t channel6NoiseFilterEnable,
    uint8_t channel7NoiseFilterEnable);
void RL78G13_Timer_NFEN1_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_Timer_NFEN1_ReadAll(void);
uint8_t RL78G13_Timer_NFEN1_ReadOne(uint8_t mask);



#endif




