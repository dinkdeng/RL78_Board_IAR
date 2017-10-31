#ifndef __RL78G13_ADC_H_
#define __RL78G13_ADC_H_
#include "MacroDriver.h"
#include "RL78G13_Port.h"

/*ADM0 AD转换器模式寄存器0*/
#define RL78G13_ADC_ADM0_ADCS_READ_THEN_STOP_MASK                           0X80U
#define RL78G13_ADC_ADM0_ADCS_READ_THEN_STOP_ON                             0X00U
#define RL78G13_ADC_ADM0_ADCS_READ_THEN_STOP_OFF                            0X80U
                                                                            
#define RL78G13_ADC_ADM0_ADMD_MODE_SELECT_MASK                              0X40U
#define RL78G13_ADC_ADM0_ADMD_MODE_SELECT                                   0X00U
#define RL78G13_ADC_ADM0_ADMD_MODE_SCAN                                     0X40U
                                                                            
#define RL78G13_ADC_ADM0_ADCE_COMPARE_SET_MASK                              0X01U
#define RL78G13_ADC_ADM0_ADCE_COMPARE_SET_ENABLE                            0X01U
#define RL78G13_ADC_ADM0_ADCE_COMPARE_SET_DISABLE                           0X00U
                                                                            
#define RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_MASK                            0X38U
#define RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_2                               0X38U
#define RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_4                               0X30U
#define RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_5                               0X28U
#define RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_6                               0X20U
#define RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_8                               0X18U
#define RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_16                              0X10U
#define RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_32                              0X08U
#define RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_64                              0X00U
                                                                            
#define RL78G13_ADC_ADM0_LV_CONVERT_MODE_SET_MASK                           0X06U
#define RL78G13_ADC_ADM0_LV_CONVERT_MODE_SET_NORMAL_19                      0X00U
#define RL78G13_ADC_ADM0_LV_CONVERT_MODE_SET_NORMAL_17                      0X02U
#define RL78G13_ADC_ADM0_LV_CONVERT_MODE_SET_LOW_POWER_19                   0X04U
#define RL78G13_ADC_ADM0_LV_CONVERT_MODE_SET_LOW_POWER_17                   0X06U
                                                                            
                                                                            
/*ADM1 AD转换器模式寄存器1*/                                                                    
#define RL78G13_ADC_ADM1_ADTMD_TRIG_MODE_SET_MASK                           0XC0U
#define RL78G13_ADC_ADM1_ADTMD_TRIG_MODE_SET_SOFT                           0X00U
#define RL78G13_ADC_ADM1_ADTMD_TRIG_MODE_SET_HARDWARE_NOWAIT                0X80U
#define RL78G13_ADC_ADM1_ADTMD_TRIG_MODE_SET_HARDWARE_WAIT                  0XC0U
                                                                            
#define RL78G13_ADC_ADM1_ADSCM_CONVERT_MODE_MASK                            0X20U
#define RL78G13_ADC_ADM1_ADSCM_CONVERT_MODE_CONTINUOUS                      0X00U
#define RL78G13_ADC_ADM1_ADSCM_CONVERT_MODE_SINGLE                          0X20U
                                                                            
#define RL78G13_ADC_ADM1_ADTRS_TRIG_SINGLE_SELECT_MASK                      0X03U
#define RL78G13_ADC_ADM1_ADTRS_TRIG_SINGLE_SELECT_INTT_TM01                 0X00U
#define RL78G13_ADC_ADM1_ADTRS_TRIG_SINGLE_SELECT_INTRTC                    0X02U
#define RL78G13_ADC_ADM1_ADTRS_TRIG_SINGLE_SELECT_INTIT                     0X03U
                                                                            
/*ADM2 AD转换器模式寄存器2*/                                                                                                                                                
#define RL78G13_ADC_ADM2_ADREFP_VREFP_SELECT_MASK                           0XC0U
#define RL78G13_ADC_ADM2_ADREFP_VREFP_SELECT_VDD                            0X00U
#define RL78G13_ADC_ADM2_ADREFP_VREFP_SELECT_AIN0_P20                       0X40U
#define RL78G13_ADC_ADM2_ADREFP_VREFP_SELECT_INNER_1_45V                    0X80U
                                                                            
#define RL78G13_ADC_ADM2_ADREFM_VREFM_SELECT_MASK                           0X20U
#define RL78G13_ADC_ADM2_ADREFM_VREFM_SELECT_VSS                            0X00U
#define RL78G13_ADC_ADM2_ADREFM_VREFM_SELECT_P21_AIN1                       0X20U
                                                                            
#define RL78G13_ADC_ADM2_ADRCK_LIMIT_MODE_MASK                              0X08U
#define RL78G13_ADC_ADM2_ADRCK_LIMIT_MODE_MIDDLE_INT                        0X00U
#define RL78G13_ADC_ADM2_ADRCK_LIMIT_MODE_OVER_RANGE                        0X08U
                                                                            
#define RL78G13_ADC_ADM2_AWC_SNOOZE_MODE_MASK                               0X04U
#define RL78G13_ADC_ADM2_AWC_SNOOZE_MODE_ENABLE                             0X04U
#define RL78G13_ADC_ADM2_AWC_SNOOZE_MODE_DISABLE                            0X00U
                                                                            
#define RL78G13_ADC_ADM2_ADTYP_RESOLUTION_MASK                              0X01U
#define RL78G13_ADC_ADM2_ADTYP_RESOLUTION_10                                0X00U
#define RL78G13_ADC_ADM2_ADTYP_RESOLUTION_8                                 0X01U
                                                                            
                                                                            
/*ADCR AD转换器结果寄存器*/                                                                    
#define RL78G13_ADC_ADCR_RESULT_RESOLUTION_10_MASK                          0XFFC0U
#define RL78G13_ADC_ADCR_RESULT_RESOLUTION_8_MASK                           0XFF00U
                                                                            
/*ADS 模拟输入通道选择寄存器*/                                                                                                                                             
#define RL78G13_ADC_ADS_ADISS_SINGLE_SOURCE_MASK                            0X80U
#define RL78G13_ADC_ADS_ADISS_SINGLE_SOURCE_INNER                           0X80U
#define RL78G13_ADC_ADS_ADISS_SINGLE_SOURCE_EXTERN                          0X00U
                                                                            
                                                                            
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_MASK                              0X1FU
/*单次转换模式*/
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN0                       0X00U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN1                       0X01U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN2                       0X02U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN3                       0X03U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN4                       0X04U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN5                       0X05U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN6                       0X06U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN7                       0X07U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN8                       0X08U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN9                       0X09U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN10                      0X0AU
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN11                      0X0BU
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN12                      0X0CU
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN13                      0X0DU
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN14                      0X0EU
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN16                      0X10U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN17                      0X11U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN18                      0X12U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN19                      0X13U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN20                      0X14U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN21                      0X15U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN22                      0X16U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN23                      0X17U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN24                      0X18U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN25                      0X19U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_AIN26                      0X1AU
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_INNER_TEMP                 0X00U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SELECT_INNER_1_45V                0X01U
/*连续转换模式*/                                                                            
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN0_3                       0X00U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN1_4                       0X01U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN2_5                       0X02U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN3_6                       0X03U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN4_7                       0X04U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN5_8                       0X05U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN6_9                       0X06U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN7_10                      0X07U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN8_11                      0X08U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN9_12                      0X09U
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN10_13                     0X0AU
#define RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_SCAN_AIN11_14                     0X0BU
                                                                            
                                                                            
/*ADUL 转换结果比较上限值寄存器*/                                                                    
#define RL78G13_ADC_ADUL_UPPER_LIMIT_MASK                                   0XFFU
                                                                            
/*ADLL 转换结果比较下限值寄存器*/                                                                    
#define RL78G13_ADC_ADLL_LOWER_LIMIT_MASK                                   0XFFU
                                                                            
/*ADTES AD测试寄存器*/                                                                   
#define RL78G13_ADC_ADTES_TEST_TARGET_SELECT_MASK                           0X03U
#define RL78G13_ADC_ADTES_TEST_TARGET_SELECT_AINX                           0X00U
#define RL78G13_ADC_ADTES_TEST_TARGET_SELECT_AIN_VREFM                      0X02U
#define RL78G13_ADC_ADTES_TEST_TARGET_SELECT_AIN_VREFP                      0X03U
                                                                         
                                                                            
/*ADPC AD端口配置寄存器*/                                                                    
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_MASK                             0X0FU
                                                                            
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_ZERO                             0X01U
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0                             0X02U
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_1                           0X03U
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_2                           0X04U
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_3                           0X05U
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_4                           0X06U
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_5                           0X07U
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_6                           0X08U
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_7                           0X09U
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_8                           0X0AU
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_9                           0X0BU
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_10                          0X0CU
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_11                          0X0DU
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_12                          0X0EU
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_13                          0X0FU
#define RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_AIN0_14                          0X00U




/*API定义区域*/
void RL78G13_ADC_ADM0_Write_All(uint8_t readThenStopSet, uint8_t channelMode, uint8_t compareMode,
    uint8_t convertClockDiv, uint8_t convertLowPowerModeSet);
void RL78G13_ADC_ADM0_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_ADC_ADM0_Read_All(void);
uint8_t RL78G13_ADC_ADM0_Read_One(uint8_t mask);

void RL78G13_ADC_ADM1_Write_All(uint8_t trigMode, uint8_t convertMode, uint8_t hardTrigSelect);
void RL78G13_ADC_ADM1_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_ADC_ADM1_Read_All(void);
uint8_t RL78G13_ADC_ADM1_Read_One(uint8_t mask);

void RL78G13_ADC_ADM2_Write_All(uint8_t refpSet, uint8_t refmSet, uint8_t resultCheckMode,
    uint8_t snoozeSet, uint8_t resulotionSet);
void RL78G13_ADC_ADM2_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_ADC_ADM2_Read_All(void);
uint8_t RL78G13_ADC_ADM2_Read_One(uint8_t mask);

uint16_t RL78G13_ADC_ADCR_Read_All(void);
uint16_t RL78G13_ADC_ADCR_Read_One(uint16_t mask);

void RL78G13_ADC_ADS_Write_All(uint8_t sourceRange, uint8_t source);
void RL78G13_ADC_ADS_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_ADC_ADS_Read_All(void);
uint8_t RL78G13_ADC_ADS_Read_One(uint8_t mask);

void RL78G13_ADC_ADUL_Write_All(uint8_t upperLimit);
void RL78G13_ADC_ADUL_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_ADC_ADUL_Read_All(void);
uint8_t RL78G13_ADC_ADUL_Read_One(uint8_t mask);

void RL78G13_ADC_ADLL_Write_All(uint8_t lowLimit);
void RL78G13_ADC_ADLL_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_ADC_ADLL_Read_All(void);
uint8_t RL78G13_ADC_ADLL_Read_One(uint8_t mask);

void RL78G13_ADC_ADTES_Write_All(uint8_t testTarget);
void RL78G13_ADC_ADTES_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_ADC_ADTES_Read_All(void);
uint8_t RL78G13_ADC_ADTES_Read_One(uint8_t mask);

void RL78G13_ADC_ADPC_Write_All(uint8_t adpcSelect);
void RL78G13_ADC_ADPC_Write_One(uint8_t mask, uint8_t value);
uint8_t RL78G13_ADC_ADPC_Read_All(void);
uint8_t RL78G13_ADC_ADPC_Read_One(uint8_t mask);






#endif



