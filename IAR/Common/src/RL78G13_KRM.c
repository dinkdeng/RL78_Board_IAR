#include "RL78G13_KRM.h"

RL78G13_KRM_STATUS RL78G13_KRM_Read(RL78G13_KRM_BIT bit)
{
    uint8_t regValue = KRM;
    regValue >>= bit;
    if (bit == 0)
        return RL78G13_KRM_STATUS_DISABLE;
    else
        return RL78G13_KRM_STATUS_ENABLE;
}

void RL78G13_KRM_Write(RL78G13_KRM_BIT bit, RL78G13_KRM_STATUS status)
{
    uint8_t regValue = KRM;
    uint8_t regStatus = status;
    uint8_t mask = (0x01U << bit);
    regValue &= (~mask);
    regStatus <<= bit;
    regStatus &= mask;
    regValue |= regStatus;
    KRM = regValue;
}


