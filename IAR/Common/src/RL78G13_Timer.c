#include "RL78G13_Timer.h"

/*定时器时钟选择单元寄存器*/

/**
 * Function:        static void RL78G13_Timer_TPS_Write(uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tps write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  value -     The value.
 */

static void RL78G13_Timer_TPS_Write(uint16_t value)
{
    TPS0 = value;
}

/**
 * Function:        static uint16_t RL78G13_Timer_TPS_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tps read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TPS_Read(void)
{
    uint16_t regValue = TPS0;
    return regValue;
}

/*定时器模式寄存器*/

/**
 * Function:        static void RL78G13_Timer_TMR_Write(RL78G13_TIMER_CHANNEL channel, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer timer write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel -   The channel.
 *  value -     The value.
 */

static void RL78G13_Timer_TMR_Write(RL78G13_TIMER_CHANNEL channel, uint16_t value)
{
    switch (channel)
    {
    case RL78G13_TIMER_CHANNEL_0:
        TMR00 = value;
        break;
    case RL78G13_TIMER_CHANNEL_1:
        TMR01 = value;
        break;
    case RL78G13_TIMER_CHANNEL_2:
        TMR02 = value;
        break;
    case RL78G13_TIMER_CHANNEL_3:
        TMR03 = value;
        break;
    case RL78G13_TIMER_CHANNEL_4:
        TMR04 = value;
        break;
    case RL78G13_TIMER_CHANNEL_5:
        TMR05 = value;
        break;
    case RL78G13_TIMER_CHANNEL_6:
        TMR06 = value;
        break;
    case RL78G13_TIMER_CHANNEL_7:
        TMR07 = value;
        break;
    }
}

/**
 * Function:        static uint16_t RL78G13_Timer_TMR_Read(RL78G13_TIMER_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 timer timer read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TMR_Read(RL78G13_TIMER_CHANNEL channel)
{
    uint16_t regValue = 0;
    switch (channel)
    {
    case RL78G13_TIMER_CHANNEL_0:
        regValue = TMR00;
        break;
    case RL78G13_TIMER_CHANNEL_1:
        regValue = TMR01;
        break;
    case RL78G13_TIMER_CHANNEL_2:
        regValue = TMR02;
        break;
    case RL78G13_TIMER_CHANNEL_3:
        regValue = TMR03;
        break;
    case RL78G13_TIMER_CHANNEL_4:
        regValue = TMR04;
        break;
    case RL78G13_TIMER_CHANNEL_5:
        regValue = TMR05;
        break;
    case RL78G13_TIMER_CHANNEL_6:
        regValue = TMR06;
        break;
    case RL78G13_TIMER_CHANNEL_7:
        regValue = TMR07;
        break;
    }
    return regValue;
}

/**
 * Function:        static uint16_t RL78G13_Timer_TSR_Read(RL78G13_TIMER_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 timer tsr read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TSR_Read(RL78G13_TIMER_CHANNEL channel)
{
    uint16_t regValue = 0;
    switch (channel)
    {
    case RL78G13_TIMER_CHANNEL_0:
        regValue = TSR00;
        break;
    case RL78G13_TIMER_CHANNEL_1:
        regValue = TSR01;
        break;
    case RL78G13_TIMER_CHANNEL_2:
        regValue = TSR02;
        break;
    case RL78G13_TIMER_CHANNEL_3:
        regValue = TSR03;
        break;
    case RL78G13_TIMER_CHANNEL_4:
        regValue = TSR04;
        break;
    case RL78G13_TIMER_CHANNEL_5:
        regValue = TSR05;
        break;
    case RL78G13_TIMER_CHANNEL_6:
        regValue = TSR06;
        break;
    case RL78G13_TIMER_CHANNEL_7:
        regValue = TSR07;
        break;
    }
    return regValue;
}

/*定时器通道允许状态寄存器,只读*/

/**
 * Function:        static uint16_t RL78G13_Timer_TE_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer te read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TE_Read(void)
{
    uint16_t regValue = 0;
    regValue = TE0;
    return regValue;
}

/*定时器通道开始寄存器*/

/**
 * Function:        static void RL78G13_Timer_TS_Write(uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer ts write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  value -     The value.
 */

static void RL78G13_Timer_TS_Write(uint16_t value)
{
    TS0 = value;
}

/**
 * Function:        static uint16_t RL78G13_Timer_TS_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer ts read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TS_Read(void)
{
    uint16_t regValue = TS0;
    return regValue;
}

/*定时器通道停止寄存器*/

/**
 * Function:        static void RL78G13_Timer_TT_Write(uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tt write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  value -     The value.
 */

static void RL78G13_Timer_TT_Write(uint16_t value)
{
    TT0 = value;
}

/**
 * Function:        static uint16_t RL78G13_Timer_TT_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tt read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TT_Read(void)
{
    uint16_t regValue = TT0;
    return regValue;
}

/*定时器输入选择寄存器,八位*/

/**
 * Function:        static void RL78G13_Timer_TIS_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tis write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  value -     The value.
 */

static void RL78G13_Timer_TIS_Write(uint8_t value)
{
    TIS0 = value;
}

/**
 * Function:        static uint8_t RL78G13_Timer_TIS_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tis read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint8_t.
 */

static uint8_t RL78G13_Timer_TIS_Read(void)
{
    uint8_t regValue = TIS0;
    return regValue;
}

/*定时器输出允许寄存器*/

/**
 * Function:        static void RL78G13_Timer_TOE_Write(uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer toe write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  value -     The value.
 */

static void RL78G13_Timer_TOE_Write(uint16_t value)
{
    TOE0 = value;
}

/**
 * Function:        static uint16_t RL78G13_Timer_TOE_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer toe read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TOE_Read(void)
{
    uint16_t regValue = TOE0;
    return regValue;
}

/*定时器输出寄存器*/

/**
 * Function:        static void RL78G13_Timer_TO_Write(uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer to write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  value -     The value.
 */

static void RL78G13_Timer_TO_Write(uint16_t value)
{
    TO0 = value;
}

/**
 * Function:        static uint16_t RL78G13_Timer_TO_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer to read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TO_Read(void)
{
    uint16_t regValue = TO0;
    return regValue;
}

/*定时器输出电平寄存器*/

/**
 * Function:        static void RL78G13_Timer_TOL_Write(uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tolerance write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  value -     The value.
 */

static void RL78G13_Timer_TOL_Write(uint16_t value)
{
    TOL0 = value;
}

/**
 * Function:        static uint16_t RL78G13_Timer_TOL_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tolerance read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TOL_Read(void)
{
    uint16_t regValue = TOL0;
    return regValue;
}

/*定时器输出模式寄存器*/

/**
 * Function:        static void RL78G13_Timer_TOM_Write(uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tom write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  value -     The value.
 */

static void RL78G13_Timer_TOM_Write(uint16_t value)
{
    TOM0 = value;
}

/**
 * Function:        static uint16_t RL78G13_Timer_TOM_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tom read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_Timer_TOM_Read(void)
{
    uint16_t regValue = TOM0;
    return regValue;
}

/*噪声滤波器允许寄存器*/

/**
 * Function:        static void RL78G13_Timer_NFEN1_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer nfen 1 write.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  value -     The value.
 */

static void RL78G13_Timer_NFEN1_Write(uint8_t value)
{
    NFEN1 = value;
}

/**
 * Function:        static uint8_t RL78G13_Timer_NFEN1_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 timer nfen 1 read.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint8_t.
 */

static uint8_t RL78G13_Timer_NFEN1_Read(void)
{
    uint8_t regValue = NFEN1;
    return regValue;
}



/*定时器时钟选择单元寄存器*/

/**
 * Function:    
 *  void RL78G13_Timer_TPS_Write_All(uint16_t flck0, uint16_t flck1, uint16_t flck2,
 *  uint16_t flck3)
 *
 * Brief:
 *      Rl 78 g 13 timer tps write all.
 *      选择定时器每个单元输出的时钟的分频系数
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  flck0 -     The flck 0.
 *  flck1 -     The first flck.
 *  flck2 -     The second flck.
 *  flck3 -     The third flck.
 */

void RL78G13_Timer_TPS_Write_All(uint16_t flck0, uint16_t flck1, 
    uint16_t flck2, uint16_t flck3)
{
    uint16_t regValue = 0;
    flck0 &= RL78G13_TIMER_TPS_CLK00_DIV_MASK;
    flck1 &= RL78G13_TIMER_TPS_CLK01_DIV_MASK;
    flck2 &= RL78G13_TIMER_TPS_CLK02_DIV_MASK;
    flck3 &= RL78G13_TIMER_TPS_CLK03_DIV_MASK;
    regValue = (flck0| flck1| flck2| flck3);
    RL78G13_Timer_TPS_Write(regValue);
}

/**
 * Function:        void RL78G13_Timer_TPS_Write_One(uint16_t mask,uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tps write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_Timer_TPS_Write_One(uint16_t mask,uint16_t value)
{
    uint16_t regValue = RL78G13_Timer_TPS_Read();
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_TPS_Write(regValue);
}

/**
 * Function:        uint16_t RL78G13_Timer_TPS_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tps read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TPS_ReadAll(void)
{
    return RL78G13_Timer_TPS_Read();
}

/**
 * Function:        uint16_t RL78G13_Timer_TPS_ReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer tps read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TPS_ReadOne(uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TPS_Read();
    regValue &= mask;
    return regValue;
}


/*TMR*/

/**
 * Function:    
 *  void RL78G13_Timer_TMR_Write_All(RL78G13_TIMER_CHANNEL ch,uint16_t clkSelect,
 *  uint16_t tclkSelect,uint16_t masterSplitSelect,uint16_t trigStartMode, uint16_t edgeSelect,
 *  uint16_t channelModeSelect,uint16_t startIntSet)
 *
 * Brief:
 *      Rl 78 g 13 timer timer write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  ch -                    The ch.
 *  clkSelect -             The clock select.
 *  tclkSelect -            The tclk select.
 *  masterSplitSelect -     The master split select.
 *  trigStartMode -         The trig start mode.
 *  edgeSelect -            The edge select.
 *  channelModeSelect -     The channel mode select.
 *  startIntSet -           The start int set.
 */

void RL78G13_Timer_TMR_Write_All(RL78G13_TIMER_CHANNEL ch,uint16_t clkSelect,
     uint16_t tclkSelect,uint16_t masterSplitSelect,uint16_t trigStartMode,
     uint16_t edgeSelect,uint16_t channelModeSelect,uint16_t startIntSet)
{
     uint16_t regValue = 0;
     clkSelect &= RL78G13_TIMER_TMR_CLOCK_SELECT_MASK;
     tclkSelect &= RL78G13_TIMER_TMR_CCS_FTCLK_SELECT_MASK;
     masterSplitSelect &= RL78G13_TIMER_TMR_MASTER_SELECT_MASK;
     trigStartMode &= RL78G13_TIMER_TMR_STS_TRIG_SRC_SELECT_MASK;
     edgeSelect &= RL78G13_TIMER_TMR_CIS_TRIG_EDGE_SELECT_MASK;
     channelModeSelect &= RL78G13_TIMER_TMR_CHANNEL_MODE_SELECT_MASK;
     startIntSet &= RL78G13_TIMER_TMR_START_INT_ENABLE_MASK;
     regValue = (clkSelect| tclkSelect| masterSplitSelect| trigStartMode|
         edgeSelect| channelModeSelect| startIntSet);
     RL78G13_Timer_TMR_Write(ch, regValue);
}

/**
 * Function:    
 *  void RL78G13_Timer_TMR_Write_One(RL78G13_TIMER_CHANNEL ch, uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer timer write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  ch -        The ch.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_Timer_TMR_Write_One(RL78G13_TIMER_CHANNEL ch,
    uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_Timer_TMR_Read(ch);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_TMR_Write(ch,regValue);
}

/**
 * Function:        uint16_t RL78G13_Timer_TMR_ReadAll(RL78G13_TIMER_CHANNEL ch)
 *
 * Brief:
 *      Rl 78 g 13 timer timer read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  ch -    The ch.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TMR_ReadAll(RL78G13_TIMER_CHANNEL ch)
{
    return RL78G13_Timer_TMR_Read(ch);
}

/**
 * Function:        uint16_t RL78G13_Timer_TMR_ReadOne(RL78G13_TIMER_CHANNEL ch, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer timer read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  ch -    The ch.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TMR_ReadOne(RL78G13_TIMER_CHANNEL ch,
     uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TMR_Read(ch);
    regValue &= mask;
    return regValue;
}

/*TSR*/

/**
 * Function:        uint16_t RL78G13_Timer_TSR_ReadAll(RL78G13_TIMER_CHANNEL ch)
 *
 * Brief:
 *      Rl 78 g 13 timer tsr read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  ch -    The ch.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TSR_ReadAll(RL78G13_TIMER_CHANNEL ch)
{
    return RL78G13_Timer_TSR_Read(ch);
}

/**
 * Function:        uint16_t RL78G13_Timer_TSR_ReadOne(RL78G13_TIMER_CHANNEL ch, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer tsr read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  ch -    The ch.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TSR_ReadOne(RL78G13_TIMER_CHANNEL ch,
     uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TSR_Read(ch);
    regValue &= mask;
    return regValue;
}

/*TE*/

/**
 * Function:        uint16_t RL78G13_Timer_TE_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer te read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TE_ReadAll(void)
{
    return RL78G13_Timer_TE_Read();
}

/**
 * Function:        uint16_t RL78G13_Timer_TE_ReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer te read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TE_ReadOne(uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TE_Read();
    regValue &= mask;
    return regValue;
}


/*TS*/

/**
 * Function:    
 *  void RL78G13_Timer_TS_Write_All(uint16_t channel0Start, uint16_t channel1Start,
 *  uint16_t channel2Start, uint16_t channel3Start, uint16_t channel4Start,
 *  uint16_t channel5Start, uint16_t channel6Start, uint16_t channel7Start,
 *  uint16_t channelh1Start, uint16_t channelh3Start)
 *
 * Brief:
 *      Rl 78 g 13 timer ts write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel0Start -     The channel 0 start.
 *  channel1Start -     The channel 1 start.
 *  channel2Start -     The channel 2 start.
 *  channel3Start -     The channel 3 start.
 *  channel4Start -     The channel 4 start.
 *  channel5Start -     The channel 5 start.
 *  channel6Start -     The channel 6 start.
 *  channel7Start -     The channel 7 start.
 *  channelh1Start -    The channelh 1 start.
 *  channelh3Start -    The channelh 3 start.
 */

void RL78G13_Timer_TS_Write_All(uint16_t channel0Start, uint16_t channel1Start, 
     uint16_t channel2Start, uint16_t channel3Start, uint16_t channel4Start, 
     uint16_t channel5Start, uint16_t channel6Start, uint16_t channel7Start, 
     uint16_t channelh1Start, uint16_t channelh3Start)
{
     uint16_t regValue = 0;
     channel0Start &= RL78G13_TIMER_TS_CHANNEL0_START_ON_MASK;
     channel1Start &= RL78G13_TIMER_TS_CHANNEL1_START_ON_MASK;
     channel2Start &= RL78G13_TIMER_TS_CHANNEL2_START_ON_MASK;
     channel3Start &= RL78G13_TIMER_TS_CHANNEL3_START_ON_MASK;
     channel4Start &= RL78G13_TIMER_TS_CHANNEL4_START_ON_MASK;
     channel5Start &= RL78G13_TIMER_TS_CHANNEL5_START_ON_MASK;
     channel6Start &= RL78G13_TIMER_TS_CHANNEL6_START_ON_MASK;
     channel7Start &= RL78G13_TIMER_TS_CHANNEL7_START_ON_MASK;
     channelh1Start &= RL78G13_TIMER_TS_CHANNEL_H1_START_ON_MASK;
     channelh3Start &= RL78G13_TIMER_TS_CHANNEL_H3_START_ON_MASK;
     regValue = (channel0Start | channel1Start | channel2Start |
         channel3Start | channel4Start | channel5Start | channel6Start |
         channel7Start | channelh1Start | channelh3Start);
     RL78G13_Timer_TS_Write(regValue);
}

/**
 * Function:        void RL78G13_Timer_TS_Write_One(uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer ts write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_Timer_TS_Write_One(uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_Timer_TS_Read();
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_TS_Write(regValue);
}

/**
 * Function:        uint16_t RL78G13_Timer_TS_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer ts read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TS_ReadAll(void)
{
    return RL78G13_Timer_TS_Read();
}

/**
 * Function:        uint16_t RL78G13_Timer_TS_ReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer ts read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TS_ReadOne(uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TS_Read();
    regValue &= mask;
    return regValue;
}


/*TT*/

/**
 * Function:    
 *  void RL78G13_Timer_TT_Write_All(uint16_t channel0Stop, uint16_t channel1Stop,
 *  uint16_t channel2Stop, uint16_t channel3Stop, uint16_t channel4Stop, uint16_t channel5Stop,
 *  uint16_t channel6Stop, uint16_t channel7Stop, uint16_t channelh1Stop, uint16_t channelh3Stop)
 *
 * Brief:
 *      Rl 78 g 13 timer tt write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel0Stop -      The channel 0 stop.
 *  channel1Stop -      The channel 1 stop.
 *  channel2Stop -      The channel 2 stop.
 *  channel3Stop -      The channel 3 stop.
 *  channel4Stop -      The channel 4 stop.
 *  channel5Stop -      The channel 5 stop.
 *  channel6Stop -      The channel 6 stop.
 *  channel7Stop -      The channel 7 stop.
 *  channelh1Stop -     The channelh 1 stop.
 *  channelh3Stop -     The channelh 3 stop.
 */

void RL78G13_Timer_TT_Write_All(uint16_t channel0Stop, uint16_t channel1Stop, 
     uint16_t channel2Stop, uint16_t channel3Stop, uint16_t channel4Stop, 
     uint16_t channel5Stop, uint16_t channel6Stop, uint16_t channel7Stop, 
     uint16_t channelh1Stop, uint16_t channelh3Stop)
{
     uint16_t regValue = 0;
     channel0Stop &= RL78G13_TIMER_TT_CHANNEL0_STOP_ON_MASK;
     channel1Stop &= RL78G13_TIMER_TT_CHANNEL1_STOP_ON_MASK;
     channel2Stop &= RL78G13_TIMER_TT_CHANNEL2_STOP_ON_MASK;
     channel3Stop &= RL78G13_TIMER_TT_CHANNEL3_STOP_ON_MASK;
     channel4Stop &= RL78G13_TIMER_TT_CHANNEL4_STOP_ON_MASK;
     channel5Stop &= RL78G13_TIMER_TT_CHANNEL5_STOP_ON_MASK;
     channel6Stop &= RL78G13_TIMER_TT_CHANNEL6_STOP_ON_MASK;
     channel7Stop &= RL78G13_TIMER_TT_CHANNEL7_STOP_ON_MASK;
     channelh1Stop &= RL78G13_TIMER_TT_CHANNEL_H1_STOP_ON_MASK;
     channelh3Stop &= RL78G13_TIMER_TT_CHANNEL_H3_STOP_ON_MASK;
     regValue = (channel0Stop| channel1Stop| channel2Stop | channel3Stop |
         channel4Stop | channel5Stop | channel6Stop | channel7Stop |
         channelh1Stop | channelh3Stop);
     RL78G13_Timer_TT_Write(regValue);
}

/**
 * Function:        void RL78G13_Timer_TT_Write_One(uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tt write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_Timer_TT_Write_One(uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_Timer_TT_Read();
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_TT_Write(regValue);
}

/**
 * Function:        uint16_t RL78G13_Timer_TT_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tt read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TT_ReadAll(void)
{
    return RL78G13_Timer_TT_Read();
}

/**
 * Function:        uint16_t RL78G13_Timer_TT_ReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer tt read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TT_ReadOne(uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TT_Read();
    regValue &= mask;
    return regValue;
}

/*TIS*/

/**
 * Function:        void RL78G13_Timer_TIS_Write_All(uint8_t ch5InputSelect)
 *
 * Brief:
 *      Rl 78 g 13 timer tis write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  ch5InputSelect -    The 5 input select.
 */

void RL78G13_Timer_TIS_Write_All(uint8_t ch5InputSelect)
{
     uint8_t regValue = 0;
     ch5InputSelect &= RL78G13_TIMER_TIS_CHANNEL5_INPUT_PIN_SELECT_MASK;
     regValue = ch5InputSelect;
     RL78G13_Timer_TIS_Write(regValue);
}

/**
 * Function:        void RL78G13_Timer_TIS_Write_One(uint8_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tis write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_Timer_TIS_Write_One(uint8_t mask, uint8_t value)
{
    uint8_t regValue = RL78G13_Timer_TIS_Read();
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_TIS_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_Timer_TIS_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tis read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Timer_TIS_ReadAll(void)
{
    return RL78G13_Timer_TIS_Read();
}

 /**
  * Function:       uint8_t RL78G13_Timer_TIS_ReadOne(uint8_t mask)
  *
  * Brief:
  *         Rl 78 g 13 timer tis read one.
  *
  * Author:
  *         Dink
  *
  * Date:
  *         2017/10/30
  *
  * Param:
  *     mask -  The mask.
  *
  * Returns:
  *         An uint8_t.
  */

 uint8_t RL78G13_Timer_TIS_ReadOne(uint8_t mask)
{
    uint8_t regValue = RL78G13_Timer_TIS_Read();
    regValue &= mask;
    return regValue;
}

/*TOE*/

/**
 * Function:    
 *  void RL78G13_Timer_TOE_Write_All(uint16_t channel0OutputEnable, uint16_t channel1OutputEnable,
 *  uint16_t channel2OutputEnable, uint16_t channel3OutputEnable, uint16_t channel4OutputEnable,
 *  uint16_t channel5OutputEnable, uint16_t channel6OutputEnable, uint16_t channel7OutputEnable)
 *
 * Brief:
 *      Rl 78 g 13 timer toe write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel0OutputEnable -  The channel 0 output enable.
 *  channel1OutputEnable -  The channel 1 output enable.
 *  channel2OutputEnable -  The channel 2 output enable.
 *  channel3OutputEnable -  The channel 3 output enable.
 *  channel4OutputEnable -  The channel 4 output enable.
 *  channel5OutputEnable -  The channel 5 output enable.
 *  channel6OutputEnable -  The channel 6 output enable.
 *  channel7OutputEnable -  The channel 7 output enable.
 */

void RL78G13_Timer_TOE_Write_All(uint16_t channel0OutputEnable, uint16_t channel1OutputEnable, 
     uint16_t channel2OutputEnable, uint16_t channel3OutputEnable, uint16_t channel4OutputEnable, 
     uint16_t channel5OutputEnable, uint16_t channel6OutputEnable, uint16_t channel7OutputEnable)
{
     uint16_t regValue = 0;
     channel0OutputEnable &= RL78G13_TIMER_TOE_CHANNEL_0_OUTPUT_SET_MASK;
     channel1OutputEnable &= RL78G13_TIMER_TOE_CHANNEL_1_OUTPUT_SET_MASK;
     channel2OutputEnable &= RL78G13_TIMER_TOE_CHANNEL_2_OUTPUT_SET_MASK;
     channel3OutputEnable &= RL78G13_TIMER_TOE_CHANNEL_3_OUTPUT_SET_MASK;
     channel4OutputEnable &= RL78G13_TIMER_TOE_CHANNEL_4_OUTPUT_SET_MASK;
     channel5OutputEnable &= RL78G13_TIMER_TOE_CHANNEL_5_OUTPUT_SET_MASK;
     channel6OutputEnable &= RL78G13_TIMER_TOE_CHANNEL_6_OUTPUT_SET_MASK;
     channel7OutputEnable &= RL78G13_TIMER_TOE_CHANNEL_7_OUTPUT_SET_MASK;
     regValue = (channel0OutputEnable| channel1OutputEnable| channel2OutputEnable|
         channel3OutputEnable| channel4OutputEnable| channel5OutputEnable| channel6OutputEnable|
         channel7OutputEnable);
     RL78G13_Timer_TOE_Write(regValue);
}

 /**
  * Function:       void RL78G13_Timer_TOE_Write_One(uint16_t mask, uint16_t value)
  *
  * Brief:
  *         Rl 78 g 13 timer toe write one.
  *
  * Author:
  *         Dink
  *
  * Date:
  *         2017/10/30
  *
  * Param:
  *     mask -      The mask.
  *     value -     The value.
  */

 void RL78G13_Timer_TOE_Write_One(uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_Timer_TOE_Read();
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_TOE_Write(regValue);
}

/**
 * Function:        uint16_t RL78G13_Timer_TOE_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer toe read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TOE_ReadAll(void)
{
    return RL78G13_Timer_TOE_Read();
}

/**
 * Function:        uint16_t RL78G13_Timer_TOE_ReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer toe read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TOE_ReadOne(uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TOE_Read();
    regValue &= mask;
    return regValue;
}

/*TO*/

/**
 * Function:    
 *  void RL78G13_Timer_TO_Write_All(uint16_t channel0OutputValue, uint16_t channel1OutputValue,
 *  uint16_t channel2OutputValue, uint16_t channel3OutputValue, uint16_t channel4OutputValue,
 *  uint16_t channel5OutputValue, uint16_t channel6OutputValue, uint16_t channel7OutputValue)
 *
 * Brief:
 *      Rl 78 g 13 timer to write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel0OutputValue -   The channel 0 output value.
 *  channel1OutputValue -   The channel 1 output value.
 *  channel2OutputValue -   The channel 2 output value.
 *  channel3OutputValue -   The channel 3 output value.
 *  channel4OutputValue -   The channel 4 output value.
 *  channel5OutputValue -   The channel 5 output value.
 *  channel6OutputValue -   The channel 6 output value.
 *  channel7OutputValue -   The channel 7 output value.
 */

void RL78G13_Timer_TO_Write_All(uint16_t channel0OutputValue, uint16_t channel1OutputValue, 
     uint16_t channel2OutputValue, uint16_t channel3OutputValue, uint16_t channel4OutputValue, 
     uint16_t channel5OutputValue, uint16_t channel6OutputValue, uint16_t channel7OutputValue)
{
     uint16_t regValue = 0;
     channel0OutputValue &= RL78G13_TIMER_TO_CHANNEL_0_OUTPUT_VALUE_MASK;
     channel1OutputValue &= RL78G13_TIMER_TO_CHANNEL_1_OUTPUT_VALUE_MASK;
     channel2OutputValue &= RL78G13_TIMER_TO_CHANNEL_2_OUTPUT_VALUE_MASK;
     channel3OutputValue &= RL78G13_TIMER_TO_CHANNEL_3_OUTPUT_VALUE_MASK;
     channel4OutputValue &= RL78G13_TIMER_TO_CHANNEL_4_OUTPUT_VALUE_MASK;
     channel5OutputValue &= RL78G13_TIMER_TO_CHANNEL_5_OUTPUT_VALUE_MASK;
     channel6OutputValue &= RL78G13_TIMER_TO_CHANNEL_6_OUTPUT_VALUE_MASK;
     channel7OutputValue &= RL78G13_TIMER_TO_CHANNEL_7_OUTPUT_VALUE_MASK;
     regValue = (channel0OutputValue| channel1OutputValue| channel2OutputValue|
         channel3OutputValue| channel4OutputValue| channel5OutputValue|
         channel6OutputValue| channel7OutputValue);
     RL78G13_Timer_TO_Write(regValue);
}

/**
 * Function:        void RL78G13_Timer_TO_Write_One(uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer to write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_Timer_TO_Write_One(uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_Timer_TO_Read();
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_TO_Write(regValue);
}

/**
 * Function:        uint16_t RL78G13_Timer_TO_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer to read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TO_ReadAll(void)
{
    return RL78G13_Timer_TO_Read();
}

/**
 * Function:        uint16_t RL78G13_Timer_TO_ReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer to read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TO_ReadOne(uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TO_Read();
    regValue &= mask;
    return regValue;
}

/*TOL*/

/**
 * Function:    
 *  void RL78G13_Timer_TOL_Write_All(uint16_t channel1Resever, uint16_t channel2Resever,
 *  uint16_t channel3Resever, uint16_t channel4Resever, uint16_t channel5Resever,
 *  uint16_t channel6Resever, uint16_t channel7Resever)
 *
 * Brief:
 *      Rl 78 g 13 timer tolerance write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel1Resever -   The channel 1 resever.
 *  channel2Resever -   The channel 2 resever.
 *  channel3Resever -   The channel 3 resever.
 *  channel4Resever -   The channel 4 resever.
 *  channel5Resever -   The channel 5 resever.
 *  channel6Resever -   The channel 6 resever.
 *  channel7Resever -   The channel 7 resever.
 */

void RL78G13_Timer_TOL_Write_All(uint16_t channel1Resever, uint16_t channel2Resever, 
     uint16_t channel3Resever, uint16_t channel4Resever, uint16_t channel5Resever, 
     uint16_t channel6Resever, uint16_t channel7Resever)
{
     uint16_t regValue = 0;
     channel1Resever &= RL78G13_TIMER_TOL_CHANNEL_1_OUTPUT_REVESER_MASK;
     channel2Resever &= RL78G13_TIMER_TOL_CHANNEL_2_OUTPUT_REVESER_MASK;
     channel3Resever &= RL78G13_TIMER_TOL_CHANNEL_3_OUTPUT_REVESER_MASK;
     channel4Resever &= RL78G13_TIMER_TOL_CHANNEL_4_OUTPUT_REVESER_MASK;
     channel5Resever &= RL78G13_TIMER_TOL_CHANNEL_5_OUTPUT_REVESER_MASK;
     channel6Resever &= RL78G13_TIMER_TOL_CHANNEL_6_OUTPUT_REVESER_MASK;
     channel7Resever &= RL78G13_TIMER_TOL_CHANNEL_7_OUTPUT_REVESER_MASK;
     regValue = (channel1Resever| channel2Resever| channel3Resever
         | channel4Resever| channel5Resever| channel6Resever| channel7Resever);
     RL78G13_Timer_TOL_Write(regValue);
}

/**
 * Function:        void RL78G13_Timer_TOL_Write_One(uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tolerance write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_Timer_TOL_Write_One(uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_Timer_TOL_Read();
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_TOL_Write(regValue);
}

/**
 * Function:        uint16_t RL78G13_Timer_TOL_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tolerance read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TOL_ReadAll(void)
{
    return RL78G13_Timer_TOL_Read();
}

/**
 * Function:        uint16_t RL78G13_Timer_TOL_ReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer tolerance read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TOL_ReadOne(uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TOL_Read();
    regValue &= mask;
    return regValue;
}

/*TOM*/

/**
 * Function:    
 *  void RL78G13_Timer_TOM_Write_All(uint16_t channel1OutPutMode, uint16_t channel2OutPutMode,
 *  uint16_t channel3OutPutMode, uint16_t channel4OutPutMode, uint16_t channel5OutPutMode,
 *  uint16_t channel6OutPutMode, uint16_t channel7OutPutMode)
 *
 * Brief:
 *      Rl 78 g 13 timer tom write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel1OutPutMode -    The channel 1 out put mode.
 *  channel2OutPutMode -    The channel 2 out put mode.
 *  channel3OutPutMode -    The channel 3 out put mode.
 *  channel4OutPutMode -    The channel 4 out put mode.
 *  channel5OutPutMode -    The channel 5 out put mode.
 *  channel6OutPutMode -    The channel 6 out put mode.
 *  channel7OutPutMode -    The channel 7 out put mode.
 */

void RL78G13_Timer_TOM_Write_All(uint16_t channel1OutPutMode, uint16_t channel2OutPutMode, 
     uint16_t channel3OutPutMode, uint16_t channel4OutPutMode, uint16_t channel5OutPutMode, 
     uint16_t channel6OutPutMode, uint16_t channel7OutPutMode)
{
     uint16_t regValue = 0;
     channel1OutPutMode &= RL78G13_TIMER_TOM_CHANNEL_1_OUTPUT_MODE_MASK;
     channel2OutPutMode &= RL78G13_TIMER_TOM_CHANNEL_2_OUTPUT_MODE_MASK;
     channel3OutPutMode &= RL78G13_TIMER_TOM_CHANNEL_3_OUTPUT_MODE_MASK;
     channel4OutPutMode &= RL78G13_TIMER_TOM_CHANNEL_4_OUTPUT_MODE_MASK;
     channel5OutPutMode &= RL78G13_TIMER_TOM_CHANNEL_5_OUTPUT_MODE_MASK;
     channel6OutPutMode &= RL78G13_TIMER_TOM_CHANNEL_6_OUTPUT_MODE_MASK;
     channel7OutPutMode &= RL78G13_TIMER_TOM_CHANNEL_7_OUTPUT_MODE_MASK;
     regValue = (channel1OutPutMode| channel2OutPutMode| channel3OutPutMode|
         channel4OutPutMode| channel5OutPutMode| channel6OutPutMode|
         channel7OutPutMode);
     RL78G13_Timer_TOM_Write(regValue);
}

/**
 * Function:        void RL78G13_Timer_TOM_Write_One(uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer tom write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_Timer_TOM_Write_One(uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_Timer_TOM_Read();
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_TOM_Write(regValue);
}

/**
 * Function:        uint16_t RL78G13_Timer_TOM_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer tom read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TOM_ReadAll(void)
{
    return RL78G13_Timer_TOM_Read();
}

/**
 * Function:        uint16_t RL78G13_Timer_TOM_ReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer tom read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_Timer_TOM_ReadOne(uint16_t mask)
{
    uint16_t regValue = RL78G13_Timer_TOM_Read();
    regValue &= mask;
    return regValue;
}

/*NFEN1*/

/**
 * Function:    
 *  void RL78G13_Timer_NFEN1_Write_All(uint8_t channel0NoiseFilterEnable,
 *  uint8_t channel1NoiseFilterEnable, uint8_t channel2NoiseFilterEnable,
 *  uint8_t channel3NoiseFilterEnable, uint8_t channel4NoiseFilterEnable,
 *  uint8_t channel5NoiseFilterEnable, uint8_t channel6NoiseFilterEnable,
 *  uint8_t channel7NoiseFilterEnable)
 *
 * Brief:
 *      Rl 78 g 13 timer nfen 1 write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  channel0NoiseFilterEnable -     The channel 0 noise filter enable.
 *  channel1NoiseFilterEnable -     The channel 1 noise filter enable.
 *  channel2NoiseFilterEnable -     The channel 2 noise filter enable.
 *  channel3NoiseFilterEnable -     The channel 3 noise filter enable.
 *  channel4NoiseFilterEnable -     The channel 4 noise filter enable.
 *  channel5NoiseFilterEnable -     The channel 5 noise filter enable.
 *  channel6NoiseFilterEnable -     The channel 6 noise filter enable.
 *  channel7NoiseFilterEnable -     The channel 7 noise filter enable.
 */

void RL78G13_Timer_NFEN1_Write_All(uint8_t channel0NoiseFilterEnable,
     uint8_t channel1NoiseFilterEnable, uint8_t channel2NoiseFilterEnable, 
     uint8_t channel3NoiseFilterEnable, uint8_t channel4NoiseFilterEnable, 
     uint8_t channel5NoiseFilterEnable, uint8_t channel6NoiseFilterEnable, 
     uint8_t channel7NoiseFilterEnable)
{
     uint8_t regValue = 0;
     channel0NoiseFilterEnable &= RL78G13_TIMER_NFEN2_CHANNEL_0_NOISE_FILTER_MODE_MASK;
     channel1NoiseFilterEnable &= RL78G13_TIMER_NFEN2_CHANNEL_1_NOISE_FILTER_MODE_MASK;
     channel2NoiseFilterEnable &= RL78G13_TIMER_NFEN2_CHANNEL_2_NOISE_FILTER_MODE_MASK;
     channel3NoiseFilterEnable &= RL78G13_TIMER_NFEN2_CHANNEL_3_NOISE_FILTER_MODE_MASK;
     channel4NoiseFilterEnable &= RL78G13_TIMER_NFEN2_CHANNEL_4_NOISE_FILTER_MODE_MASK;
     channel5NoiseFilterEnable &= RL78G13_TIMER_NFEN2_CHANNEL_5_NOISE_FILTER_MODE_MASK;
     channel6NoiseFilterEnable &= RL78G13_TIMER_NFEN2_CHANNEL_6_NOISE_FILTER_MODE_MASK;
     channel7NoiseFilterEnable &= RL78G13_TIMER_NFEN2_CHANNEL_7_NOISE_FILTER_MODE_MASK;
     regValue = (channel0NoiseFilterEnable| channel1NoiseFilterEnable| channel2NoiseFilterEnable|
         channel3NoiseFilterEnable| channel4NoiseFilterEnable| channel5NoiseFilterEnable|
         channel6NoiseFilterEnable| channel7NoiseFilterEnable);
     RL78G13_Timer_NFEN1_Write(regValue);
}

/**
 * Function:        void RL78G13_Timer_NFEN1_Write_One(uint8_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 timer nfen 1 write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_Timer_NFEN1_Write_One(uint8_t mask, uint8_t value)
{
    uint8_t regValue = RL78G13_Timer_NFEN1_Read();
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_Timer_NFEN1_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_Timer_NFEN1_ReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 timer nfen 1 read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Timer_NFEN1_ReadAll(void)
{
    return RL78G13_Timer_NFEN1_Read();
}

/**
 * Function:        uint8_t RL78G13_Timer_NFEN1_ReadOne(uint8_t mask)
 *
 * Brief:
 *      Rl 78 g 13 timer nfen 1 read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_Timer_NFEN1_ReadOne(uint8_t mask)
{
    uint8_t regValue = RL78G13_Timer_NFEN1_Read();
    regValue &= mask;
    return regValue;
}