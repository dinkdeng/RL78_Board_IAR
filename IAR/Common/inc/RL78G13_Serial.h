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



#define RL78G13_SERIAL_SPS_FLCK1_MASK                                       0XF0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_1                                      0X10U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_2                                      0X20U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_4                                      0X30U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_8                                      0X40U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_16                                     0X50U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_32                                     0X60U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_64                                     0X70U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_128                                    0X80U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_256                                    0X90U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_512                                    0XA0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_1024                                   0XB0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_2048                                   0XC0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_4096                                   0XD0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_8192                                   0XE0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_16384                                  0XF0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_32768

#define RL78G13_SERIAL_SMR_FMCK_SELECT_MASK                                 0X8000U
#define RL78G13_SERIAL_SMR_FMCK_SELECT_FCLK0                                0X0000U
#define RL78G13_SERIAL_SMR_FMCK_SELECT_FCLK1                                0X8000U



#define RL78G13_SERIAL_SMR_FTCLK_SELECT_MASK                                0X4000U
#define RL78G13_SERIAL_SMR_FTCLK_SELECT_FMCK                                0X0000U
#define RL78G13_SERIAL_SMR_FTCLK_SELECT_FSCK                                0X4000U
                                                                            
#define RL78G13_SERIAL_SMR_START_TRIG_SOURCE_MASK                           0X0100U
#define RL78G13_SERIAL_SMR_START_TRIG_SOURCE_SOFT                           0X0000U
#define RL78G13_SERIAL_SMR_START_TRIG_SOURCE_RXDQ_PIN                       0X0100U


#define RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_MASK                       0X0040U
#define RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_FALLING                    0X0000U
#define RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_RISING                     0X0040U


#define RL78G13_SERIAL_SMR_CHANNEL_MODE_MASK                                0X0006U
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_CSI                                 0X0000U
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_UART                                0X0002U
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_IIC                                 0X0004U

#define RL78G13_SERIAL_SMR_INT_SRC_MASK                                     0X0001U
#define RL78G13_SERIAL_SMR_INT_SRC_END                                      0X0000U
#define RL78G13_SERIAL_SMR_INT_SRC_EMPTY                                    0X0001U


#define RL78G13_SERIAL_SCR_MODE_MASK                                        0XC000U
#define RL78G13_SERIAL_SCR_MODE_DISABLE                                     0X0000U
#define RL78G13_SERIAL_SCR_MODE_TX_ONLY                                     0X4000U
#define RL78G13_SERIAL_SCR_MODE_RX_ONLY                                     0X8000U
#define RL78G13_SERIAL_SCR_MODE_TX_RX                                       0XC000U

#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_MASK                             0X3000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_0                                0X0000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_1                                0X1000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_2                                0X2000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_3                                0X3000U
                                                                            
#define RL78G13_SERIAL_SCR_INT_DISABLE_MASK                                 0X0400U
#define RL78G13_SERIAL_SCR_INT_DISABLE_ON                                   0X0400U
#define RL78G13_SERIAL_SCR_INT_DISABLE_OFF                                  0X0000U


#define RL78G13_SERIAL_SCR_UART_CHECK_MASK                                  0X0300U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_NONE                               0X0000U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_ZERO                               0X0100U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_ODD                                0X0200U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_EVEN                               0X0300U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_NO                                 0X0000U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_NO1                                0X0100U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_ODD                                0X0200U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_EVEN                               0X0300U


#define RL78G13_SERIAL_SCR_UART_CSI_SEQ_MASK                                0X0080U
#define RL78G13_SERIAL_SCR_UART_CSI_SEQ_MSB_FIRST                           0X0000U
#define RL78G13_SERIAL_SCR_UART_CSI_SEQ_LSB_FIRST                           0X0080U

#define RL78G13_SERIAL_SCR_UART_STOP_BITS_MASK                              0X0030U
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_NONE                              0X0000U
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_1                                 0X0010U
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_2                                 0X0020U

#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_MASK                         0X0003U
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_9                            0X0001U
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_7                            0X0002U
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_8                            0X0003U
                                          
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
                                                         
#define RL78G13_SERIAL_SDR_DATA_MASK                                        0X00FFU
                                          

#define RL78G13_SERIAL_SIR_FECT_MASK                                        0X0004U
#define RL78G13_SERIAL_SIR_FECT_CLECR                                       0X0004U
  

#define RL78G13_SERIAL_SIR_PECT_MASK                                        0X0002U
#define RL78G13_SERIAL_SIR_PECT_CLECR                                       0X0002U
                               

#define RL78G13_SERIAL_SIR_OVCT_MASK                                        0X0001U
#define RL78G13_SERIAL_SIR_OVCT_CLECR                                       0X0001U
                          

#define RL78G13_SERIAL_SSR_TSF_MASK                                         0X0040U
#define RL78G13_SERIAL_SSR_TSF_RUNNING                                      0X0040U
                            

#define RL78G13_SERIAL_SSR_BUFFER_MASK                                      0X0020U
#define RL78G13_SERIAL_SSR_BUFFER_FULL                                      0X0020U
                              

#define RL78G13_SERIAL_SSR_RECV_ERR_FLAG_MASK                               0X0004U
#define RL78G13_SERIAL_SSR_RECV_ERR_FLAG_ON                                 0X0004U
                                                                            

#define RL78G13_SERIAL_SSR_CHECK_ERR_FLAG_MASK                              0X0002U
#define RL78G13_SERIAL_SSR_CHECK_ERR_FLAG_ON                                0X0002U
                                                         

#define RL78G13_SERIAL_SSR_OVER_ERR_FLAG_MASK                               0X0001U
#define RL78G13_SERIAL_SSR_OVER_ERR_FLAG_ON                                 0X0001U
                                              

#define RL78G13_SERIAL_SS_COM0_WAIT_FLAG_MASK                               0X0001U
#define RL78G13_SERIAL_SS_COM0_WAIT_FLAG_ON                                 0X0001U
                                       

#define RL78G13_SERIAL_SS_COM1_WAIT_FLAG_MASK                               0X0002U
#define RL78G13_SERIAL_SS_COM1_WAIT_FLAG_ON                                 0X0002U
                                        

#define RL78G13_SERIAL_SS_COM2_WAIT_FLAG_MASK                               0X0004U
#define RL78G13_SERIAL_SS_COM2_WAIT_FLAG_ON                                 0X0004U
                                       

#define RL78G13_SERIAL_SS_COM3_WAIT_FLAG_MASK                               0X0008U
#define RL78G13_SERIAL_SS_COM3_WAIT_FLAG_ON                                 0X0008U
                                  

#define RL78G13_SERIAL_ST_COM0_STOP_FLAG_MASK                               0X0001U
#define RL78G13_SERIAL_ST_COM0_STOP_FLAG_ON                                 0X0001U
                                       

#define RL78G13_SERIAL_ST_COM1_STOP_FLAG_MASK                               0X0002U
#define RL78G13_SERIAL_ST_COM1_STOP_FLAG_ON                                 0X0002U
                                  

#define RL78G13_SERIAL_ST_COM2_STOP_FLAG_MASK                               0X0004U
#define RL78G13_SERIAL_ST_COM2_STOP_FLAG_ON                                 0X0004U
                                         

#define RL78G13_SERIAL_ST_COM3_STOP_FLAG_MASK                               0X0008U
#define RL78G13_SERIAL_ST_COM3_STOP_FLAG_ON                                 0X0008U
                                     

#define RL78G13_SERIAL_SE_COM0_ALLOW_OP_FLAG_MASK                           0X0001U
#define RL78G13_SERIAL_SE_COM0_ALLOW_OP_FLAG_ON                             0X0001U
                                                                    

#define RL78G13_SERIAL_SE_COM1_ALLOW_OP_FLAG_MASK                           0X0002U
#define RL78G13_SERIAL_SE_COM1_ALLOW_OP_FLAG_ON                             0X0002U
                                     

#define RL78G13_SERIAL_SE_COM2_ALLOW_OP_FLAG_MASK                           0X0004U
#define RL78G13_SERIAL_SE_COM2_ALLOW_OP_FLAG_ON                             0X0004U
                                      

#define RL78G13_SERIAL_SE_COM3_ALLOW_OP_FLAG_MASK                           0X0008U
#define RL78G13_SERIAL_SE_COM3_ALLOW_OP_FLAG_ON                             0X0008U
                                        

#define RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_MASK                     0X0001U
#define RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_ON                       0X0001U
                                            

#define RL78G13_SERIAL_SOE_COM1_OUTPUT_ENABLE_FLAG_MASK                     0X0002U
#define RL78G13_SERIAL_SOE_COM1_OUTPUT_ENABLE_FLAG_ON                       0X0002U
                                               

#define RL78G13_SERIAL_SOE_COM2_OUTPUT_ENABLE_FLAG_MASK                     0X0004U
#define RL78G13_SERIAL_SOE_COM2_OUTPUT_ENABLE_FLAG_ON                       0X0004U
                                             

#define RL78G13_SERIAL_SOE_COM3_OUTPUT_ENABLE_FLAG_MASK                     0X0008U
#define RL78G13_SERIAL_SOE_COM3_OUTPUT_ENABLE_FLAG_ON                       0X0008U
                                            

#define RL78G13_SERIAL_SO_COM0_CLOCK_OUTPUT_ENABLE_FLAG_MASK                0X0100U
#define RL78G13_SERIAL_SO_COM0_CLOCK_OUTPUT_ENABLE_FLAG_ON                  0X0100U
                                            

#define RL78G13_SERIAL_SO_COM1_CLOCK_OUTPUT_ENABLE_FLAG_MASK                0X0200U
#define RL78G13_SERIAL_SO_COM1_CLOCK_OUTPUT_ENABLE_FLAG_ON                  0X0200U
                                        

#define RL78G13_SERIAL_SO_COM2_CLOCK_OUTPUT_ENABLE_FLAG_MASK                0X0400U
#define RL78G13_SERIAL_SO_COM2_CLOCK_OUTPUT_ENABLE_FLAG_ON                  0X0400U
                                                                           

#define RL78G13_SERIAL_SO_COM3_CLOCK_OUTPUT_ENABLE_FLAG_MASK                0X0800U
#define RL78G13_SERIAL_SO_COM3_CLOCK_OUTPUT_ENABLE_FLAG_ON                  0X0800U
                                                                           

#define RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_ENABLE_FLAG_MASK                 0X0001U
#define RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_ENABLE_FLAG_ON                   0X0001U
                                                                           

#define RL78G13_SERIAL_SO_COM1_DATA_OUTPUT_ENABLE_FLAG_MASK                 0X0002U
#define RL78G13_SERIAL_SO_COM1_DATA_OUTPUT_ENABLE_FLAG_ON                   0X0002U
                                                                           

#define RL78G13_SERIAL_SO_COM2_DATA_OUTPUT_ENABLE_FLAG_MASK                 0X0004U
#define RL78G13_SERIAL_SO_COM2_DATA_OUTPUT_ENABLE_FLAG_ON                   0X0004U
                                                                           

#define RL78G13_SERIAL_SO_COM3_DATA_OUTPUT_ENABLE_FLAG_MASK                 0X0008U
#define RL78G13_SERIAL_SO_COM3_DATA_OUTPUT_ENABLE_FLAG_ON                   0X0008U
                                                                           

#define RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_MASK                    0X0001U
#define RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_ON                      0X0001U
                                                                        

#define RL78G13_SERIAL_SOL_COM2_OUTPUT_REVERSE_FLAG_MASK                    0X0004U
#define RL78G13_SERIAL_SOL_COM2_OUTPUT_REVERSE_FLAG_ON                      0X0004U
                                                                

#define RL78G13_SERIAL_SSC_SNOOZE_ENABLE_MASK                               0X0001U
#define RL78G13_SERIAL_SSC_SNOOZE_ENABLE_FLAG                               0X0001U
                                                                       

#define RL78G13_SERIAL_SSC_INT_ERR_ENABLE_MASK                              0X0002U
#define RL78G13_SERIAL_SSC_INT_ERR_ENABLE_FLAG                              0X0002U
                                                                            

#define RL78G13_SERIAL_ISC_TIMER7_INPUT_MASK                                0X01U
#define RL78G13_SERIAL_ISC_TIMER7_INPUT_RXD2                                0X01U
                                                                            

#define RL78G13_SERIAL_ISC_INTP0_INPUT_MASK                                 0X02U
#define RL78G13_SERIAL_ISC_INTP0_INPUT_RXD2                                 0X02U
                                                                           
                                                                           
#define RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_MASK                          0X01U
#define RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_OPEN                          0X01U
                                                                           

#define RL78G13_SERIAL_NFEN_RXD1_NOIZE_FILTER_MASK                          0X04U
#define RL78G13_SERIAL_NFEN_RXD1_NOIZE_FILTER_OPEN                          0X04U
                                                                           

#define RL78G13_SERIAL_NFEN_RXD2_NOIZE_FILTER_MASK                          0X10U
#define RL78G13_SERIAL_NFEN_RXD2_NOIZE_FILTER_OPEN                          0X10U
                                                                           

#define RL78G13_SERIAL_NFEN_RXD3_NOIZE_FILTER_MASK                          0X40U
#define RL78G13_SERIAL_NFEN_RXD3_NOIZE_FILTER_OPEN                          0X40U


#endif





