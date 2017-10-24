#ifndef __RL78G13_CLOCK_H_
#define __RL78G13_CLOCK_H_
#include "MacroDriver.h"

/*CMC寄存器,时钟操作模式控制*/
/* 在复位结束后(fCLK 切换为 fMX 之前) fIH 被选择作为 fCLK 时，
 * 指定 AMPH、AMPHS1 和AMPHS0 位的设置
 * 尽管最大系统时钟频率是 32 MHz，但 X1 振荡器的最大频率是 20 MHz
 * 解除复位后，通过时钟操作状态控制寄存器(CSC)的设置，在 X1 或
 * XT1 振荡前，设置 CMC
 * 当X1 时钟振荡频率超过10MHz 时，必须将AMPH 位设置为1寄存器
 */
/*高速系统时钟引脚输入模式掩码*/
#define RL78G13_CLOCK_CMC_MAIN_PIN_MODE_MASK                            0xC0U
/*高速系统时钟引脚输入端口模式*/
#define RL78G13_CLOCK_CMC_MAIN_PIN_MODE_INPUT_1                         0x00U
/*高速系统时钟X1振荡模式*/
#define RL78G13_CLOCK_CMC_MAIN_PIN_MODE_X1                              0x40U
/*高速系统时钟输入端口模式*/
#define RL78G13_CLOCK_CMC_MAIN_PIN_MODE_INPUT_2                         0x80U
/*高速系统时钟外部时钟输入模式*/
#define RL78G13_CLOCK_CMC_MAIN_PIN_MODE_EXT                             0xC0U

/*副系统时钟引脚*/
#define RL78G13_CLOCK_CMC_VICE_PIN_MODE_MASK                            0x30U
#define RL78G13_CLOCK_CMC_VICE_PIN_MODE_INPUT_1                         0x00U
#define RL78G13_CLOCK_CMC_VICE_PIN_MODE_XT1                             0x10U
#define RL78G13_CLOCK_CMC_VICE_PIN_MODE_INPUT_2                         0x20U
#define RL78G13_CLOCK_CMC_VICE_PIN_MODE_EXT                             0x30U

/*XT1振荡电路的振荡模式*/
#define RL78G13_CLOCK_CMC_VICE_VIBRATION_MODE_MASK                      0X06U
#define RL78G13_CLOCK_CMC_VICE_VIBRATION_MODE_LOW_POWER                 0x00U
#define RL78G13_CLOCK_CMC_VICE_VIBRATION_MODE_NORMAL                    0x02U
#define RL78G13_CLOCK_CMC_VICE_VIBRATION_MODE_SUPER_LOW_POWER           0x04U

/*X1时钟振荡频率的控制*/
#define RL78G13_CLOCK_CMC_MAIN_FREQ_MASK                                0X01U
#define RL78G13_CLOCK_CMC_MAIN_FREQ_1_10M                               0x00U
#define RL78G13_CLOCK_CMC_MAIN_FREQ_10_20M                              0x01U

/*CKC寄存器,系统时钟控制寄存器*/
/* 位7 和 5 为只读位
* CSS 位设置为 1 时，禁止改变MCM0 位的值
* 选用副系统时钟作为外围硬件时钟时，无法保证 A/D 转换器和 IICA 的操作
*/
/*CPU/外围硬件时钟的选择*/
#define RL78G13_CLOCK_CKC_FCLK_SET_MASK                                 0X40U
#define RL78G13_CLOCK_CKC_FCLK_SET_FMAIN                                0x00U
#define RL78G13_CLOCK_CKC_FCLK_SET_FSUB                                 0x40U

/*CPU/外围硬件时钟的状态*/
#define RL78G13_CLOCK_CKC_FCLK_STATUS_MASK                              0X80U
#define RL78G13_CLOCK_CKC_FCLK_STATUS_FMAIN                             0x00U
#define RL78G13_CLOCK_CKC_FCLK_STATUS_FSUB                              0x80U

/*主系统时钟操作控制*/
#define RL78G13_CLOCK_CKC_FMAIN_SET_MASK                                0X10U
#define RL78G13_CLOCK_CKC_FMAIN_SET_FMX                                 0x10U
#define RL78G13_CLOCK_CKC_FMAIN_SET_FIH                                 0x00U

/*主系统时钟状态*/
#define RL78G13_CLOCK_CKC_FMAIN_STATUS_MASK                             0X20U
#define RL78G13_CLOCK_CKC_FMAIN_STATUS_FMX                              0x20U
#define RL78G13_CLOCK_CKC_FMAIN_STATUS_FIH                              0x00U

/*CSC寄存器,时钟操作状态控制寄存器*/
/*外部高速时钟停止*/
#define RL78G13_CLOCK_CSC_HSE_MASK                                      0X80U
#define RL78G13_CLOCK_CSC_HSE_STOP                                      0x80U

/*外部低速时钟停止振荡*/
#define RL78G13_CLOCK_CSC_XT_MASK                                       0X40U
#define RL78G13_CLOCK_CSC_XT_STOP                                       0x40U

/*高速片上振荡器工作*/
#define RL78G13_CLOCK_CSC_HSI_MASK                                      0X01U
#define RL78G13_CLOCK_CSC_HSI_STOP                                      0x01U

/*OSTC寄存器,振荡稳定时间计数器状态寄存器*/
/*该寄存器用于表示X1 时钟振荡稳定时间计数器的计数状态。
 *在以下情况下可以确认X1 时钟振荡稳定时间*/
#define RL78G13_CLOCK_OSTC_MASK                                         0XFFU
#define RL78G13_CLOCK_OSTC_2_8_MAX                                      0x00U
#define RL78G13_CLOCK_OSTC_2_8_MIN                                      0x80U
#define RL78G13_CLOCK_OSTC_2_9_MIN                                      0xC0U
#define RL78G13_CLOCK_OSTC_2_10_MIN                                     0xE0U
#define RL78G13_CLOCK_OSTC_2_11_MIN                                     0xF0U
#define RL78G13_CLOCK_OSTC_2_13_MIN                                     0xF8U
#define RL78G13_CLOCK_OSTC_2_15_MIN                                     0xFCU
#define RL78G13_CLOCK_OSTC_2_17_MIN                                     0xFEU
#define RL78G13_CLOCK_OSTC_2_18_MIN                                     0xFFU

/*OSTS寄存器,振荡稳定时间选择寄存器*/
/*该寄存器用于选择解除STOP 模式时的X1 时钟振荡稳定等待时间*/
#define RL78G13_CLOCK_OSTS_MASK                                         0X07U
#define RL78G13_CLOCK_OSTS_2_8                                          0x00U
#define RL78G13_CLOCK_OSTS_2_9                                          0x01U
#define RL78G13_CLOCK_OSTS_2_10                                         0x02U
#define RL78G13_CLOCK_OSTS_2_11                                         0x03U
#define RL78G13_CLOCK_OSTS_2_13                                         0x04U
#define RL78G13_CLOCK_OSTS_2_15                                         0x05U
#define RL78G13_CLOCK_OSTS_2_17                                         0x06U
#define RL78G13_CLOCK_OSTS_2_18                                         0x07U

/*PER0寄存器,外围允许寄存器*/
/*该寄存器用于允许或禁止向外围硬件供应时钟。
* 通过停止向未使用的硬件供应时钟，可以降低功耗和噪声*/
#define RL78G13_CLOCK_PER0_RTCEN                                        0x80U
#define RL78G13_CLOCK_PER0_IICA1EN                                      0x40U
#define RL78G13_CLOCK_PER0_ADCEN                                        0x20U
#define RL78G13_CLOCK_PER0_IICA0EN                                      0x10U
#define RL78G13_CLOCK_PER0_SAU1EN                                       0x08U
#define RL78G13_CLOCK_PER0_SAU0EN                                       0x04U
#define RL78G13_CLOCK_PER0_TAU1EN                                       0x02U
#define RL78G13_CLOCK_PER0_TAU0EN                                       0x01U

/*OSMC寄存器,操作速度模式控制寄存器*/
/*该寄存器是通过停止不必要的时钟功能来实现降低功耗的目的的
 *可用于选择实时时钟和12 位间隔定时器的工作时钟
 */
#define RL78G13_CLOCK_OSMC_STOP_CLOCK                                   0x80U
#define RL78G13_CLOCK_OSMC_RTC_TIM_SEL_FIL                              0x10U

/*HOCODIV寄存器,高速片上振荡器频率选择寄存器*/
/*通过高速片上振荡器频率选择寄存器(HOCODIV)，可以改变由选项字节(000C2H)
* 设置的高速片上振荡器的频率。然而，可以选择的频率因选项字节(000C2H)的
* FRQSEL3 位的值而异*/
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_24M_FRQSEL3_0                    0x00U
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_12M_FRQSEL3_0                    0x01U
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_6M_FRQSEL3_0                     0x02U
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_3M_FRQSEL3_0                     0x03U
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_32M_FRQSEL3_1                    0x00U
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_16M_FRQSEL3_1                    0x01U
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_8M_FRQSEL3_1                     0x02U
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_4M_FRQSEL3_1                     0x03U
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_2M_FRQSEL3_1                     0x04U
#define RL78G13_CLOCK_HOCODIV_HSI_FREQ_1M_FRQSEL3_1                     0x05U

/*HIOTRM寄存器,高速片上振荡器调节寄存器*/
/*通过采用高精度外部时钟输入的定时器（定时器阵列单元）等来对高速片上
振荡器的频率进行自我测量，从而调节精度*/
#define RL78G13_CLOCK_HIOTRM_MAX_SPEED                                  0x3FU
#define RL78G13_CLOCK_HIOTRM_MIN_SPEED                                  0x00U


uint8_t RL78G13_Clock_CMC_Read();
void RL78G13_Clock_CMC_Set(uint8_t mainPinMode, uint8_t vicePinMode, uint8_t viceVibrationMode,
    uint8_t mainFreq);

uint8_t RL78G13_Clock_CKC_Read(void);
void RL78G13_Clock_CKC_Set(uint8_t fclkSet, uint8_t fmainSet);

uint8_t RL78G13_Clock_CSC_Read(void);
void RL78G13_Clock_CSC_Set(uint8_t hseFlag, uint8_t xtFlag, uint8_t hsiStop);

uint8_t RL78G13_Clock_OSTC_Read(void);

uint8_t RL78G13_Clock_OSTS_Read(void);
void RL78G13_Clock_OSTS_Set(uint8_t setWaitTime);

uint8_t RL78G13_Clock_PER0_Read(void);
void RL78G13_Clock_PER0_Enable(uint8_t enableBits);

void RL78G13_Clock_PER0_Disable(uint8_t disableBits);
uint8_t RL78G13_Clock_OSMC_Read(void);

void RL78G13_Clock_OSMC_Set(uint8_t rtcLpcSet, uint8_t rtcTimerSelect);

uint8_t RL78G13_Clock_HOCODIV_Read(void);
void RL78G13_Clock_HOCODIV_Set(uint8_t hsiSelect);

uint8_t RL78G13_Clock_HIOTRM_Read(void);
void RL78G13_Clock_HIOTRM_Set(uint8_t hiotrmValue);

uint8_t RL78G13_Clock_GetResetSource(void);


void RL78G13_Clock_Init(void);

#endif




