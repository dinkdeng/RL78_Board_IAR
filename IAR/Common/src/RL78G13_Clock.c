#include "RL78G13_Clock.h"

uint8_t RL78G13_Clock_CMC_Read()
{
    uint8_t flag = CMC;
    return flag;
}

void RL78G13_Clock_CMC_Set(uint8_t mainPinMode, uint8_t vicePinMode, uint8_t viceVibrationMode,
    uint8_t mainFreq)
{
    uint8_t value = 0;
    value = mainPinMode | vicePinMode | viceVibrationMode | mainFreq;
    CMC = value;
}

uint8_t RL78G13_Clock_CKC_Read(void)
{
    uint8_t flag = CKC;
    return flag;
}

void RL78G13_Clock_CKC_Set(uint8_t fclkSet,uint8_t fmainSet)
{
    uint8_t value = fclkSet | fmainSet;
    CKC = value;
}


uint8_t RL78G13_Clock_CSC_Read(void)
{
    uint8_t flag = CSC;
    return flag;
}

void RL78G13_Clock_CSC_Set(uint8_t hseFlag,uint8_t xtFlag,uint8_t hsiStop)
{
    uint8_t value = hseFlag | xtFlag | hsiStop;
    CSC = value;
}

uint8_t RL78G13_Clock_OSTC_Read(void)
{
    uint8_t value = OSTC;
    return value;
}

uint8_t RL78G13_Clock_OSTS_Read(void)
{
    uint8_t flag = OSTS;
    return flag;
}

void RL78G13_Clock_OSTS_Set(uint8_t setWaitTime)
{
    OSTS = setWaitTime;
}

uint8_t RL78G13_Clock_PER0_Read(void)
{
    uint8_t flag = PER0;
    return flag;
}

void RL78G13_Clock_PER0_Enable(uint8_t enableBits)
{
    uint8_t value = RL78G13_Clock_PER0_Read();
    value |= enableBits;
    PER0 = value;
}

void RL78G13_Clock_PER0_Disable(uint8_t disableBits)
{
    uint8_t value = RL78G13_Clock_PER0_Read();
    value &= (~disableBits);
    PER0 = value;
}

uint8_t RL78G13_Clock_OSMC_Read(void)
{
    uint8_t flag = OSMC;
    return flag;
}

void RL78G13_Clock_OSMC_Set(uint8_t rtcLpcSet,uint8_t rtcTimerSelect)
{
    uint8_t value = rtcLpcSet | rtcTimerSelect;
    OSMC = value;
}

uint8_t RL78G13_Clock_HOCODIV_Read(void)
{
    uint8_t flag = HOCODIV;
    return flag;
}

void RL78G13_Clock_HOCODIV_Set(uint8_t hsiSelect)
{
    uint8_t value = hsiSelect;
    HOCODIV = value;
}

uint8_t RL78G13_Clock_HIOTRM_Read(void)
{
    uint8_t flag = HIOTRM;
    return flag;
}

void RL78G13_Clock_HIOTRM_Set(uint8_t hiotrmValue)
{
    HIOTRM = hiotrmValue;
}

uint8_t RL78G13_Clock_GetResetSource(void)
{
    uint8_t reset_flag = RESF;
    return reset_flag;
}



/*系统时钟初始化,使用外部16M时钟*/
void RL78G13_Clock_Init(void)
{
    /*记录OSTC稳定时间*/
    uint8_t hseWaitStableSet = RL78G13_CLOCK_OSTC_2_18_MIN;
    uint8_t hseWaitStableRead = 0;
    /*设定CMC时钟,X1用作时钟输入,XT1用作时钟输入,XT1正常运行模式,外部时钟主频20M*/
    RL78G13_Clock_CMC_Set(RL78G13_CLOCK_CMC_MAIN_PIN_MODE_X1, RL78G13_CLOCK_CMC_VICE_PIN_MODE_XT1,
        RL78G13_CLOCK_CMC_VICE_VIBRATION_MODE_NORMAL, RL78G13_CLOCK_CMC_MAIN_FREQ_10_20M);
    /*设置X1的稳定时间*/
    RL78G13_Clock_OSTS_Set(RL78G13_CLOCK_OSTS_2_18);
    /*X1 XT1 内部高速振荡电路工作*/
    RL78G13_Clock_CSC_Set(0,0,0);
    /*等待稳定*/
    do
    {
        hseWaitStableRead = RL78G13_Clock_OSTC_Read();
    }
    while (hseWaitStableRead != hseWaitStableSet);
    /*选择FMAIN时钟和FCLK时钟,fmx作为fmain,fclk选择fmain*/
    RL78G13_Clock_CKC_Set(RL78G13_CLOCK_CKC_FCLK_SET_FMAIN, RL78G13_CLOCK_CKC_FMAIN_SET_FMX);
    /*设置FSUB,停止向外围功能供应FSUB,使用副系统时钟作为RTC时钟*/
    RL78G13_Clock_OSMC_Set(RL78G13_CLOCK_OSMC_STOP_CLOCK,0);
}



