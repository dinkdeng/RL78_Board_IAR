#ifndef __RL78G13_BUZZER_H__
#define __RL78G13_BUZZER_H__
#include "MacroDriver.h"

#define RL78G13_BUZZER_ENABLE_MASK                  0X80U
#define RL78G13_BUZZER_ENABLE                       0X80U
#define RL78G13_BUZZER_DISABLE                      0X00U

#define RL78G13_BUZZER_CLOCK_DIV_MASK               0X0FU
#define RL78G13_BUZZER_CLOCK_FMAIN_DIV_1            0X00U
#define RL78G13_BUZZER_CLOCK_FMAIN_DIV_2            0X01U
#define RL78G13_BUZZER_CLOCK_FMAIN_DIV_4            0X02U
#define RL78G13_BUZZER_CLOCK_FMAIN_DIV_8            0X03U
#define RL78G13_BUZZER_CLOCK_FMAIN_DIV_16           0X04U
#define RL78G13_BUZZER_CLOCK_FMAIN_DIV_2048         0X05U
#define RL78G13_BUZZER_CLOCK_FMAIN_DIV_4096         0X06U
#define RL78G13_BUZZER_CLOCK_FMAIN_DIV_8192         0X07U
#define RL78G13_BUZZER_CLOCK_FSUB_DIV_1             0X08U
#define RL78G13_BUZZER_CLOCK_FSUB_DIV_2             0X09U
#define RL78G13_BUZZER_CLOCK_FSUB_DIV_4             0X0AU
#define RL78G13_BUZZER_CLOCK_FSUB_DIV_8             0X0BU
#define RL78G13_BUZZER_CLOCK_FSUB_DIV_16            0X0CU
#define RL78G13_BUZZER_CLOCK_FSUB_DIV_32            0X0DU
#define RL78G13_BUZZER_CLOCK_FSUB_DIV_64            0X0EU
#define RL78G13_BUZZER_CLOCK_FSUB_DIV_128           0X0FU


typedef enum RL78G13_BUZZER_CHANNEL
{
    RL78G13_BUZZER_CHANNEL_0 = 0x00U,
    RL78G13_BUZZER_CHANNEL_1 = 0x01U,
}RL78G13_BUZZER_CHANNEL;


uint8_t RL78G13_BuzzerReadAll(RL78G13_BUZZER_CHANNEL channel);
uint8_t RL78G13_BuzzerReadOne(RL78G13_BUZZER_CHANNEL channel,uint8_t mask);

void RL78G13_BuzzerWriteAll(RL78G13_BUZZER_CHANNEL channel,uint8_t enable,uint8_t div);
void RL78G13_BuzzerWriteOne(RL78G13_BUZZER_CHANNEL channel,uint8_t mask,uint8_t value);


#endif




