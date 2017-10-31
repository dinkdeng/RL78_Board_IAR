#include "RL78G13_Buzzer.h"

uint8_t RL78G13_BuzzerReadAll(RL78G13_BUZZER_CHANNEL channel)
{
    uint8_t regValue = 0;
    if (channel == RL78G13_BUZZER_CHANNEL_0)
    {
        regValue = CKS0;
    }
    else
    {
        regValue = CKS1;
    }
    return regValue;
}
uint8_t RL78G13_BuzzerReadOne(RL78G13_BUZZER_CHANNEL channel, uint8_t mask)
{
    uint8_t regValue = 0;
    if (channel == RL78G13_BUZZER_CHANNEL_0)
    {
        regValue = CKS0;
    }
    else
    {
        regValue = CKS1;
    }
    regValue &= mask;
    return regValue;
}

void RL78G13_BuzzerWriteAll(RL78G13_BUZZER_CHANNEL channel, uint8_t enable, uint8_t div)
{
    uint8_t regValue = 0;
    enable &= RL78G13_BUZZER_ENABLE_MASK;
    div &= RL78G13_BUZZER_CLOCK_DIV_MASK;
    regValue = (enable | div);
    if (channel == RL78G13_BUZZER_CHANNEL_0)
    {
        CKS0 = regValue;
    }
    else
    {
        CKS1 = regValue;
    }
}
void RL78G13_BuzzerWriteOne(RL78G13_BUZZER_CHANNEL channel, uint8_t mask, uint8_t value)
{
    uint8_t regValue = 0;
    regValue = RL78G13_BuzzerReadAll(channel);
    regValue &= (~mask);
    regValue |= value;
    if (channel == RL78G13_BUZZER_CHANNEL_0)
    {
        CKS0 = regValue;
    }
    else
    {
        CKS1 = regValue;
    }
}



