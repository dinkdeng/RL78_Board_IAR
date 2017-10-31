#include "RL78G13_Clock.h"

/**
 * Function:        uint8_t RL78G13_Clock_CMC_Read()
 *
 * Brief:
 *      Rl 78 g 13 clock cmc read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Clock_CMC_Read()
{
    uint8_t flag = CMC;
    return flag;
}

/**
 * Function:    
 *  void RL78G13_Clock_CMC_Set(uint8_t mainPinMode, uint8_t vicePinMode,
 *  uint8_t viceVibrationMode, uint8_t mainFreq)
 *
 * Brief:
 *      Rl 78 g 13 clock cmc set.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  mainPinMode -           The main pin mode.X1输入引脚振荡模式
 *  vicePinMode -           The vice pin mode.XT1输入引脚振荡模式
 *  viceVibrationMode -     The vice vibration mode.XT1时钟运行模式
 *  mainFreq -              The main frequency.外部晶振主频
 */

void RL78G13_Clock_CMC_Set(uint8_t mainPinMode, uint8_t vicePinMode, uint8_t viceVibrationMode,
    uint8_t mainFreq)
{
    uint8_t value = 0;
    value = mainPinMode | vicePinMode | viceVibrationMode | mainFreq;
    CMC = value;
}

/**
 * Function:        uint8_t RL78G13_Clock_CKC_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 clock ckc read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Clock_CKC_Read(void)
{
    uint8_t flag = CKC;
    return flag;
}

/**
 * Function:        void RL78G13_Clock_CKC_Set(uint8_t fclkSet,uint8_t fmainSet)
 *
 * Brief:
 *      Rl 78 g 13 clock ckc set.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  fclkSet -   Set the fclk belongs to.选择FCLK来源
 *  fmainSet -  Set the fmain belongs to.选择FMAIN来源
 */

void RL78G13_Clock_CKC_Set(uint8_t fclkSet,uint8_t fmainSet)
{
    uint8_t value = fclkSet | fmainSet;
    CKC = value;
}

/**
 * Function:        uint8_t RL78G13_Clock_CSC_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 clock csc read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Clock_CSC_Read(void)
{
    uint8_t flag = CSC;
    return flag;
}

/**
 * Function:        void RL78G13_Clock_CSC_Set(uint8_t hseFlag,uint8_t xtFlag,uint8_t hsiStop)
 *
 * Brief:
 *      Rl 78 g 13 clock csc set.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  hseFlag -   The hse flag.设置外部高速晶振停止
 *  xtFlag -    The xt flag.设置XT1停止
 *  hsiStop -   The hsi stop.设置内部振荡器停止
 */

void RL78G13_Clock_CSC_Set(uint8_t hseFlag,uint8_t xtFlag,uint8_t hsiStop)
{
    uint8_t value = hseFlag | xtFlag | hsiStop;
    CSC = value;
}

/**
 * Function:        uint8_t RL78G13_Clock_OSTC_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 clock ostc read.
 *      获取振荡时间
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Clock_OSTC_Read(void)
{
    uint8_t value = OSTC;
    return value;
}

/**
 * Function:        uint8_t RL78G13_Clock_OSTS_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 clock osts read.
 *      读取晶振振荡稳定时间
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Clock_OSTS_Read(void)
{
    uint8_t flag = OSTS;
    return flag;
}

/**
 * Function:        void RL78G13_Clock_OSTS_Set(uint8_t setWaitTime)
 *
 * Brief:
 *      Rl 78 g 13 clock osts set.
 *      设置晶振震荡时间
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  setWaitTime -   The set wait time.
 */

void RL78G13_Clock_OSTS_Set(uint8_t setWaitTime)
{
    OSTS = setWaitTime;
}

/**
 * Function:        uint8_t RL78G13_Clock_PER0_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 clock per 0 read.
 *      读取外围模块使能情况
 *      
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Clock_PER0_Read(void)
{
    uint8_t flag = PER0;
    return flag;
}

/**
 * Function:        void RL78G13_Clock_PER0_Enable(uint8_t enableBits)
 *
 * Brief:
 *      Rl 78 g 13 clock per 0 enable.
 *      使能指定外围模块
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  enableBits -    The enable bits.
 */

void RL78G13_Clock_PER0_Enable(uint8_t enableBits)
{
    uint8_t value = RL78G13_Clock_PER0_Read();
    value |= enableBits;
    PER0 = value;
}

/**
 * Function:        void RL78G13_Clock_PER0_Disable(uint8_t disableBits)
 *
 * Brief:
 *      Rl 78 g 13 clock per 0 disable.
 *      禁止指定外围模块
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  disableBits -   The disable bits.
 */

void RL78G13_Clock_PER0_Disable(uint8_t disableBits)
{
    uint8_t value = RL78G13_Clock_PER0_Read();
    value &= (~disableBits);
    PER0 = value;
}

/**
 * Function:        uint8_t RL78G13_Clock_OSMC_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 clock osmc read.
 *      读取rtc的一些设置
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Clock_OSMC_Read(void)
{
    uint8_t flag = OSMC;
    return flag;
}

/**
 * Function:        void RL78G13_Clock_OSMC_Set(uint8_t rtcLpcSet,uint8_t rtcTimerSelect)
 *
 * Brief:
 *      Rl 78 g 13 clock osmc set.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  rtcLpcSet -         Set the RTC lpc belongs to.设置RTC低功耗
 *  rtcTimerSelect -    The RTC timer select.设置RTC定时器来源
 */

void RL78G13_Clock_OSMC_Set(uint8_t rtcLpcSet,uint8_t rtcTimerSelect)
{
    uint8_t value = rtcLpcSet | rtcTimerSelect;
    OSMC = value;
}

/**
 * Function:        uint8_t RL78G13_Clock_HOCODIV_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 clock hocodiv read.
 *      获取更改的内部高速振荡器震荡周期
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Clock_HOCODIV_Read(void)
{
    uint8_t flag = HOCODIV;
    return flag;
}

/**
 * Function:        void RL78G13_Clock_HOCODIV_Set(uint8_t hsiSelect)
 *
 * Brief:
 *      Rl 78 g 13 clock hocodiv set.
 *      设置内部高速振荡器震荡周期
 *  
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  hsiSelect -     The hsi select.
 */

void RL78G13_Clock_HOCODIV_Set(uint8_t hsiSelect)
{
    uint8_t value = hsiSelect;
    HOCODIV = value;
}

/**
 * Function:        uint8_t RL78G13_Clock_HIOTRM_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 clock hiotrm read.
 *      获取晶振修正系数
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Clock_HIOTRM_Read(void)
{
    uint8_t flag = HIOTRM;
    return flag;
}

/**
 * Function:        void RL78G13_Clock_HIOTRM_Set(uint8_t hiotrmValue)
 *
 * Brief:
 *      Rl 78 g 13 clock hiotrm set.
 *      设置内部振荡器修正系数
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  hiotrmValue -   The hiotrm value.
 */

void RL78G13_Clock_HIOTRM_Set(uint8_t hiotrmValue)
{
    HIOTRM = hiotrmValue;
}

/**
 * Function:        uint8_t RL78G13_Clock_GetResetSource(void)
 *
 * Brief:
 *      Rl 78 g 13 clock get reset source.
 *      获取系统复位源
 *  
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint8_t.
 */

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



