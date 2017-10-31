#include "RL78G13_Serial.h"

/*SPS*/

/**
 * Function:        static void RL78G13_SerialSPSWriteSingle
 * (RL78G13_SERIAL_UNIT unit,uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial sps write single.
 *      串行时钟选择寄存器
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  value -     The value.
 */

static void RL78G13_SerialSPSWriteSingle(RL78G13_SERIAL_UNIT unit,uint16_t value)
{
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        SPS0 = value;
    }
    else
    {
        SPS1 = value;
    }
}

/**
 * Function:        static uint16_t RL78G13_SerialSPSReadSingle(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial sps read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSPSReadSingle(RL78G13_SERIAL_UNIT unit)
{
    uint16_t value = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        value = SPS0;
    }
    else
    {
        value = SPS1;
    }
    return value;
}

/**
 * Function:
 *  void RL78G13_SerialSPSWriteAll(RL78G13_SERIAL_UNIT unit,uint16_t fclk0Div, uint16_t fclk1Div)
 *
 * Brief:
 *      Rl 78 g 13 serial sps write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.串行单元号码
 *  fclk0Div -  The fclk 0 div.时钟0的分频系数
 *  fclk1Div -  The fclk 1 div.时钟1的分频系数
 */

void RL78G13_SerialSPSWriteAll(RL78G13_SERIAL_UNIT unit,uint16_t fclk0Div, uint16_t fclk1Div)
{
    fclk0Div &= RL78G13_SERIAL_SPS_FLCK0_MASK;
    fclk1Div &= RL78G13_SERIAL_SPS_FLCK1_MASK;
    uint16_t value = (fclk0Div | fclk1Div);
    RL78G13_SerialSPSWriteSingle(unit,value);
}

/**
 * Function:
 *  void RL78G13_SerialSPSWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask,uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial sps write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSPSWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask,uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSPSReadSingle(unit);
    regValue &= (~mask);
    value &= mask;
    regValue |= value;
    RL78G13_SerialSPSWriteSingle(unit, regValue);
}

/**
 * Function:        uint16_t RL78G13_SerialSPSReadAll(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial sps read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSPSReadAll(RL78G13_SERIAL_UNIT unit)
{
    return RL78G13_SerialSPSReadSingle(unit);
}

/**
 * Function:        uint16_t RL78G13_SerialSPSReadOne(RL78G13_SERIAL_UNIT unit,uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial sps read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSPSReadOne(RL78G13_SERIAL_UNIT unit,uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSPSReadSingle(unit);
    regValue &= mask;
    return regValue;
}


/*SMR*/

/**
 * Function:
 *  void RL78G13_SerialSMRWriteSingle(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial smr write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.单元号
 *  channel -   The channel.通道号
 *  value -     The value.值
 */

static void RL78G13_SerialSMRWriteSingle(RL78G13_SERIAL_UNIT unit,
    RK78G13_SERIAL_UNIT_CHANNEL channel, uint16_t value)
{
    /*0020是初始化值,必须要设置*/
    value |= 0x0020U;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            SMR00 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            SMR01 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            SMR02 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            SMR03 = value;
            break;
        }
    }
    else
    {
        switch (channel)
        {
            case RK78G13_SERIAL_UNIT_CHANNEL_0:
                SMR10 = value;
                break;
            case RK78G13_SERIAL_UNIT_CHANNEL_1:
                SMR11 = value;
                break;
            case RK78G13_SERIAL_UNIT_CHANNEL_2:
                //SMR12 = value;
                break;
            case RK78G13_SERIAL_UNIT_CHANNEL_3:
                //SMR13 = value;
                break;
        }
    }
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSMRReadSingle(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial smr read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSMRReadSingle(RL78G13_SERIAL_UNIT unit,
    RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    uint16_t value = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            value = SMR00;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            value = SMR01;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            value = SMR02;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            value = SMR03;
            break;
        }
    }
    else
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            value = SMR10;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            value = SMR11;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            //value = SMR12;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            //value = SMR13;
            break;
        }
    }
    return value;
}

/**
 * Function:
 *  void RL78G13_SerialSMRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
 *  uint16_t FMCKSelect,uint16_t FTCLKSelect,uint16_t startTrigSourceSelect,
 *  uint16_t uartRecvStartLevel, uint16_t channelMode,uint16_t intSrcSelect)
 *
 * Brief:
 *      Rl 78 g 13 serial smr write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -                      The unit.单元号
 *  channel -                   The channel.通道号
 *  FMCKSelect -                The fmck select.FMCK的来源选择
 *  FTCLKSelect -               The ftclk select.FTCLK的来源选择
 *  startTrigSourceSelect -     The start trig source select.触发开始信号选择
 *  uartRecvStartLevel -        The uart receive start level.接收开始电平选择
 *  channelMode -               The channel mode.通道模式
 *  intSrcSelect -              The int source select.中断源选择
 */

void RL78G13_SerialSMRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t FMCKSelect,uint16_t FTCLKSelect,uint16_t startTrigSourceSelect,uint16_t uartRecvStartLevel,
    uint16_t channelMode,uint16_t intSrcSelect)
{
    FMCKSelect &= RL78G13_SERIAL_SMR_FMCK_SELECT_MASK;
    FTCLKSelect &= RL78G13_SERIAL_SMR_FTCLK_SELECT_MASK;
    startTrigSourceSelect &= RL78G13_SERIAL_SMR_START_TRIG_SOURCE_MASK;
    uartRecvStartLevel &= RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_MASK;
    channelMode &= RL78G13_SERIAL_SMR_CHANNEL_MODE_MASK;
    intSrcSelect &= RL78G13_SERIAL_SMR_INT_SRC_MASK;
    uint16_t value = (FMCKSelect | FTCLKSelect | startTrigSourceSelect |
        uartRecvStartLevel | channelMode | intSrcSelect);
    RL78G13_SerialSMRWriteSingle(unit,channel,value);
}

/**
 * Function:
 *  void RL78G13_SerialSMRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
 *  uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial smr write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSMRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSMRReadSingle(unit, channel);
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSMRWriteSingle(unit, channel,regValue);
}

/**
 * Function:
 *  uint16_t RL78G13_SerialReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    return RL78G13_SerialSMRReadSingle(unit,channel);
}

/**
 * Function:
 *  uint16_t RL78G13_SerialReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
 *  uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  mask -      The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSMRReadSingle(unit, channel);
    regValue &= mask;
    return regValue;
}


/*SCR*/

/**
 * Function:
 *  void RL78G13_SerialSCRWriteSingle(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial screen write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  value -     The value.
 */

static void RL78G13_SerialSCRWriteSingle(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t value)
{
    value |= 0x0004U;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            SCR00 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            SCR01 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            SCR02 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            SCR03 = value;
            break;
        }
    }
    else
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            SCR10 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            SCR11 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            //SCR12 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            //SCR13 = value;
            break;
        }
    }
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSCRReadSingle(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial screen read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSCRReadSingle(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            regValue = SCR00;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            regValue = SCR01;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            regValue = SCR02;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            regValue = SCR03;
            break;
        }
    }
    else
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            regValue = SCR10;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            regValue = SCR11;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            //regValue = SCR12;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            //regValue = SCR13;
            break;
        }
    }
    return regValue;
}

/**
 * Function:
 *  void RL78G13_SerialSCRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
 *  uint16_t txrxMode,uint16_t csiSingalType,uint16_t errorShield,uint16_t txrxCheckMode,
 *  uint16_t firstBitSet,uint16_t stopBitsSet,uint16_t dataLengthSet)
 *
 * Brief:
 *      Rl 78 g 13 serial screen write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -              The unit.单元号
 *  channel -           The channel.通道号
 *  txrxMode -          The txrx mode.发送接收模式选择
 *  csiSingalType -     Type of the csi singal.信号类型选择
 *  errorShield -       The error shield.错误屏蔽
 *  txrxCheckMode -     The txrx check mode.奇偶校验模式设定
 *  firstBitSet -       Set the first bit belongs to.优先传送BIT设定
 *  stopBitsSet -       Set the stop bits belongs to.停止位设定
 *  dataLengthSet -     Set the data length belongs to.数据长度设定
 */

void RL78G13_SerialSCRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t txrxMode,uint16_t csiSingalType,uint16_t errorShield,uint16_t txrxCheckMode,
    uint16_t firstBitSet,uint16_t stopBitsSet,uint16_t dataLengthSet)
{
    txrxMode &= RL78G13_SERIAL_SCR_MODE_MASK;
    csiSingalType &= RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_MASK;
    errorShield &= RL78G13_SERIAL_SCR_INT_DISABLE_MASK;
    txrxCheckMode &= RL78G13_SERIAL_SCR_UART_CHECK_MASK;
    firstBitSet &= RL78G13_SERIAL_SCR_UART_CSI_SEQ_MASK;
    stopBitsSet &= RL78G13_SERIAL_SCR_UART_STOP_BITS_MASK;
    dataLengthSet &= RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_MASK;
    uint16_t regValue = (txrxMode | csiSingalType | errorShield | txrxCheckMode
        |firstBitSet | stopBitsSet | dataLengthSet);
    RL78G13_SerialSCRWriteSingle(unit, channel, regValue);
}

/**
 * Function:
 *  void RL78G13_SerialSCRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
 *  uint16_t mask,uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial screen write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSCRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask,uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSCRReadSingle(unit, channel);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSCRWriteSingle(unit, channel,regValue);
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSCRReadAll(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial screen read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSCRReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    return RL78G13_SerialSCRReadSingle(unit,channel);
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSCRReadOne(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial screen read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  mask -      The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSCRReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSCRReadSingle(unit, channel);
    regValue &= mask;
    return regValue;
}


/*SDR*/

/**
 * Function:
 *  void RL78G13_SerialSDRWriteSingle(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial sdr write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  value -     The value.
 */

static void RL78G13_SerialSDRWriteSingle(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t value)
{
    value &= (~0X0100U);
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            SDR00 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            SDR01 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            SDR02 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            SDR03 = value;
            break;
        }
    }
    else
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            SDR10 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            SDR11 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            //SDR12 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            //SDR13 = value;
            break;
        }
    }
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSDRReadSingle(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial sdr read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSDRReadSingle(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            regValue = SDR00;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            regValue = SDR01;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            regValue = SDR02;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            regValue = SDR03;
            break;
        }
    }
    else
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            regValue = SDR10;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            regValue = SDR11;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            //regValue = SDR12;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            //regValue = SDR13;
            break;
        }
    }
    return regValue;
}

/**
 * Function:
 *  void RL78G13_SerialSDRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
 *  uint16_t fmclkDiv,uint16_t sendData)
 *
 * Brief:
 *      Rl 78 g 13 serial sdr write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.单元号
 *  channel -   The channel.通道号
 *  fmclkDiv -  The fmclk div.从FMCLK分频系数
 *  sendData -  Information describing the send.发送数据
 */

void RL78G13_SerialSDRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t fmclkDiv,uint16_t sendData)
{
    fmclkDiv &= RL78G13_SERIAL_SDR_FMCK_DIV_MASK;
    sendData &= RL78G13_SERIAL_SDR_DATA_MASK;
    uint16_t regValue = (fmclkDiv | sendData);
    RL78G13_SerialSDRWriteSingle(unit, channel, regValue);
}

/**
 * Function:
 *  void RL78G13_SerialSDRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
 *  uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial sdr write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSDRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSDRReadSingle(unit, channel);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSDRWriteSingle(unit, channel, regValue);
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSDRReadAll(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial sdr read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSDRReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    return RL78G13_SerialSDRReadSingle(unit, channel);
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSDRReadOne(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial sdr read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  mask -      The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSDRReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSDRReadSingle(unit, channel);
    regValue &= mask;
    return regValue;
}



/*SIR*/

/**
 * Function:
 *  void RL78G13_SerialSIRWriteSingle(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial sir write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  value -     The value.
 */

static void RL78G13_SerialSIRWriteSingle(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t value)
{
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            SIR00 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            SIR01 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            SIR02 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            SIR03 = value;
            break;
        }
    }
    else
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            SIR10 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            SIR11 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            //SIR12 = value;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            //SIR13 = value;
            break;
        }
    }
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSIRReadSingle(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial sir read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSIRReadSingle(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            regValue = SIR00;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            regValue = SIR01;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            regValue = SIR02;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            regValue = SIR03;
            break;
        }
    }
    else
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            regValue = SIR10;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            regValue = SIR11;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            //regValue = SIR12;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            //regValue = SIR13;
            break;
        }
    }
    return regValue;
}

/**
 * Function:
 *  void RL78G13_SerialSIRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
 *  uint16_t frameErrClear,uint16_t checkErrClear,uint16_t overFlowErrClear)
 *
 * Brief:
 *      Rl 78 g 13 serial sir write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -              The unit.单元号
 *  channel -           The channel.通道号码
 *  frameErrClear -     The frame error clear.清除帧错误
 *  checkErrClear -     The check error clear.清除就校验错误或者ACK错误
 *  overFlowErrClear -  The over flow error clear.缓存溢出错误
 */

void RL78G13_SerialSIRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t frameErrClear,uint16_t checkErrClear,uint16_t overFlowErrClear)
{
    frameErrClear &= RL78G13_SERIAL_SIR_FECT_MASK;
    checkErrClear &= RL78G13_SERIAL_SIR_PECT_MASK;
    overFlowErrClear &= RL78G13_SERIAL_SIR_OVCT_MASK;
    uint16_t regValue = (frameErrClear| checkErrClear| overFlowErrClear);
    RL78G13_SerialSIRWriteSingle(unit, channel, regValue);
}

/**
 * Function:
 *  void RL78G13_SerialSIRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
 *  uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial sir write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSIRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSIRReadSingle(unit, channel);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSIRWriteSingle(unit, channel, regValue);
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSIRReadAll(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial sir read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSIRReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    return RL78G13_SerialSIRReadSingle(unit, channel);
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSIRReadOne(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial sir read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  mask -      The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSIRReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSIRReadSingle(unit, channel);
    regValue &= mask;
    return regValue;
}


/*SSR*/

/**
 * Function:
 *  uint16_t RL78G13_SerialSSRReadSingle(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial ssr read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSSRReadSingle(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            regValue = SSR00;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            regValue = SSR01;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            regValue = SSR02;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            regValue = SSR03;
            break;
        }
    }
    else
    {
        switch (channel)
        {
        case RK78G13_SERIAL_UNIT_CHANNEL_0:
            regValue = SSR10;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_1:
            regValue = SSR11;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_2:
            //regValue = SSR12;
            break;
        case RK78G13_SERIAL_UNIT_CHANNEL_3:
            //regValue = SSR13;
            break;
        }
    }
    return regValue;
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSSRReadAll(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel)
 *
 * Brief:
 *      Rl 78 g 13 serial ssr read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSSRReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel)
{
    return RL78G13_SerialSSRReadSingle(unit, channel);
}

/**
 * Function:
 *  uint16_t RL78G13_SerialSSRReadOne(RL78G13_SERIAL_UNIT unit,
 *  RK78G13_SERIAL_UNIT_CHANNEL channel, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial ssr read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  channel -   The channel.
 *  mask -      The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSSRReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSSRReadSingle(unit, channel);
    regValue &= mask;
    return regValue;
}


/*SS*/

/**
 * Function:        void RL78G13_SerialSSWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial ss write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  value -     The value.
 */

static void RL78G13_SerialSSWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
{
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        SS0 = value;
    }
    else
    {
        SS1 = value;
    }
}

/**
 * Function:        uint16_t RL78G13_SerialSSReadSingle(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial ss read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSSReadSingle(RL78G13_SERIAL_UNIT unit)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        regValue = SS0;
    }
    else
    {
        regValue = SS1;
    }
    return regValue;
}

/**
 * Function:
 *  void RL78G13_SerialSSWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t com0Wait, uint16_t com1Wait,
 *  uint16_t com2Wait, uint16_t com3Wait)
 *
 * Brief:
 *      Rl 78 g 13 serial ss write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  com0Wait -  The com 0 wait.设定通讯口0开始操作,等待操作
 *  com1Wait -  The com 1 wait.设定通讯口1开始操作,等待操作
 *  com2Wait -  The com 2 wait.设定通讯口2开始操作,等待操作
 *  com3Wait -  The com 3 wait.设定通讯口3开始操作,等待操作
 */

void RL78G13_SerialSSWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t com0Wait, uint16_t com1Wait,
    uint16_t com2Wait, uint16_t com3Wait)
{
    com0Wait &= RL78G13_SERIAL_SS_COM0_WAIT_FLAG_MASK;
    com1Wait &= RL78G13_SERIAL_SS_COM1_WAIT_FLAG_MASK;
    com2Wait &= RL78G13_SERIAL_SS_COM2_WAIT_FLAG_MASK;
    com3Wait &= RL78G13_SERIAL_SS_COM3_WAIT_FLAG_MASK;
    uint16_t regValue = (com0Wait|com1Wait|com1Wait|com2Wait);
    RL78G13_SerialSSWriteSingle(unit, regValue);
}

/**
 * Function:
 *  void RL78G13_SerialSSWriteOne(RL78G13_SERIAL_UNIT unit,uint16_t mask,uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial ss write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSSWriteOne(RL78G13_SERIAL_UNIT unit,uint16_t mask,uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSSReadSingle(unit);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSSWriteSingle(unit, regValue);
}

/**
 * Function:        uint16_t RL78G13_SerialSSReadAll(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial ss read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSSReadAll(RL78G13_SERIAL_UNIT unit)
{
    return RL78G13_SerialSSReadSingle(unit);
}

/**
 * Function:        uint16_t RL78G13_SerialSSReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial ss read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSSReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSSReadSingle(unit);
    regValue &= mask;
    return regValue;
}


/*ST*/

/**
 * Function:        void RL78G13_SerialSTWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial st write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  value -     The value.
 */

static void RL78G13_SerialSTWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
{
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        ST0 = value;
    }
    else
    {
        ST1 = value;
    }
}

/**
 * Function:        uint16_t RL78G13_SerialSTReadSingle(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial st read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSTReadSingle(RL78G13_SERIAL_UNIT unit)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        regValue = ST0;
    }
    else
    {
        regValue = ST1;
    }
    return regValue;
}

/**
 * Function:
 *  void RL78G13_SerialSTWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t com0Stop, uint16_t com1Stop,
 *  uint16_t com2Stop, uint16_t com3Stop)
 *
 * Brief:
 *      Rl 78 g 13 serial st write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.单元号
 *  com0Stop -  The com 0 stop.设定通讯口0停止操作,不在传输
 *  com1Stop -  The com 1 stop.设定通讯口1停止操作,不在传输
 *  com2Stop -  The com 2 stop.设定通讯口2停止操作,不在传输
 *  com3Stop -  The com 3 stop.设定通讯口3停止操作,不在传输
 */

void RL78G13_SerialSTWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t com0Stop, uint16_t com1Stop,
    uint16_t com2Stop, uint16_t com3Stop)
{
    com0Stop &= RL78G13_SERIAL_ST_COM0_STOP_FLAG_MASK;
    com1Stop &= RL78G13_SERIAL_ST_COM1_STOP_FLAG_MASK;
    com2Stop &= RL78G13_SERIAL_ST_COM2_STOP_FLAG_MASK;
    com3Stop &= RL78G13_SERIAL_ST_COM3_STOP_FLAG_MASK;
    uint16_t regValue = (com0Stop|com1Stop|com2Stop|com3Stop);
    RL78G13_SerialSTWriteSingle(unit, regValue);
}

/**
 * Function:
 *  void RL78G13_SerialSTWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial st write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSTWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSTReadSingle(unit);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSTWriteSingle(unit, regValue);
}

/**
 * Function:        uint16_t RL78G13_SerialSTReadAll(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial st read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSTReadAll(RL78G13_SERIAL_UNIT unit)
{
    return RL78G13_SerialSTReadSingle(unit);
}

/**
 * Function:        uint16_t RL78G13_SerialSTReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial st read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSTReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSTReadSingle(unit);
    regValue &= mask;
    return regValue;
}


/*SE*/

/**
 * Function:        uint16_t RL78G13_SerialSEReadSingle(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial se read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSEReadSingle(RL78G13_SERIAL_UNIT unit)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        regValue = SE0;
    }
    else
    {
        regValue = SE1;
    }
    return regValue;
}

/**
 * Function:        uint16_t RL78G13_SerialSEReadAll(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial se read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSEReadAll(RL78G13_SERIAL_UNIT unit)
{
    return RL78G13_SerialSEReadSingle(unit);
}

/**
 * Function:        uint16_t RL78G13_SerialSEReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial se read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSEReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSEReadSingle(unit);
    regValue &= mask;
    return regValue;
}


/*SOE*/

/**
 * Function:        void RL78G13_SerialSOEWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial soe write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  value -     The value.
 */

static void RL78G13_SerialSOEWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
{
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        SOE0 = value;
    }
    else
    {
        SOE1 = value;
    }
}

/**
 * Function:        uint16_t RL78G13_SerialSOEReadSingle(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial soe read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSOEReadSingle(RL78G13_SERIAL_UNIT unit)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        regValue = SOE0;
    }
    else
    {
        regValue = SOE1;
    }
    return regValue;
}

/**
 * Function:
 *  void RL78G13_SerialSOEWriteAll(RL78G13_SERIAL_UNIT unit,uint16_t com0AllowOP,
 *  uint16_t com1AllowOP, uint16_t com2AllowOP, uint16_t com3AllowOP)
 *
 * Brief:
 *      Rl 78 g 13 serial soe write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -          The unit.
 *  com0AllowOP -   The com 0 allow operation.通讯口0允许操作
 *  com1AllowOP -   The com 1 allow operation.通讯口1允许操作
 *  com2AllowOP -   The com 2 allow operation.通讯口2允许操作
 *  com3AllowOP -   The com 3 allow operation.通讯口3允许操作
 */

void RL78G13_SerialSOEWriteAll(RL78G13_SERIAL_UNIT unit,uint16_t com0AllowOP,
    uint16_t com1AllowOP, uint16_t com2AllowOP, uint16_t com3AllowOP)
{
    com0AllowOP &= RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_MASK;
    com1AllowOP &= RL78G13_SERIAL_SOE_COM1_OUTPUT_ENABLE_FLAG_MASK;
    com2AllowOP &= RL78G13_SERIAL_SOE_COM2_OUTPUT_ENABLE_FLAG_MASK;
    com3AllowOP &= RL78G13_SERIAL_SOE_COM3_OUTPUT_ENABLE_FLAG_MASK;
    uint16_t regValue = (com0AllowOP| com1AllowOP| com2AllowOP| com3AllowOP);
    RL78G13_SerialSOEWriteSingle(unit, regValue);
}

/**
 * Function:
 *  void RL78G13_SerialSOEWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial soe write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSOEWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSOEReadSingle(unit);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSOEWriteSingle(unit, regValue);
}

/**
 * Function:        uint16_t RL78G13_SerialSOEReadAll(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial soe read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSOEReadAll(RL78G13_SERIAL_UNIT unit)
{
    return RL78G13_SerialSOEReadSingle(unit);
}

/**
 * Function:        uint16_t RL78G13_SerialSOEReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial soe read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSOEReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSOEReadSingle(unit);
    regValue &= mask;
    return regValue;
}


/*SO*/

/**
 * Function:        void RL78G13_SerialSOWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial so write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  value -     The value.
 */

static void RL78G13_SerialSOWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
{
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        SO0 = value;
    }
    else
    {
        SO1 = value;
    }
}

/**
 * Function:        uint16_t RL78G13_SerialSOReadSingle(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial so read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSOReadSingle(RL78G13_SERIAL_UNIT unit)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        regValue = SO0;
    }
    else
    {
        regValue = SO1;
    }
    return regValue;
}

/**
 * Function:
 *  void RL78G13_SerialSOWriteAll(RL78G13_SERIAL_UNIT unit,uint16_t clock0OutValue,
 *  uint16_t clock1OutValue, uint16_t clock2OutValue, uint16_t clock3OutValue,
 *  uint16_t data0OutValue, uint16_t data1OutValue, uint16_t data2OutValue,
 *  uint16_t data3OutValue)
 *
 * Brief:
 *      Rl 78 g 13 serial so write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -              The unit.
 *  clock0OutValue -    The clock 0 out value.端口0时钟引脚输出电平
 *  clock1OutValue -    The clock 1 out value.端口1时钟引脚输出电平
 *  clock2OutValue -    The clock 2 out value.端口2时钟引脚输出电平
 *  clock3OutValue -    The clock 3 out value.端口3时钟引脚输出电平
 *  data0OutValue -     The data 0 out value.端口0数据引脚输出电平
 *  data1OutValue -     The data 1 out value.端口1数据引脚输出电平
 *  data2OutValue -     The data 2 out value.端口2数据引脚输出电平
 *  data3OutValue -     The data 3 out value.端口3数据引脚输出电平
 */

void RL78G13_SerialSOWriteAll(RL78G13_SERIAL_UNIT unit,uint16_t clock0OutValue,
    uint16_t clock1OutValue, uint16_t clock2OutValue, uint16_t clock3OutValue,
    uint16_t data0OutValue, uint16_t data1OutValue, uint16_t data2OutValue,
    uint16_t data3OutValue)
{
    clock0OutValue &= RL78G13_SERIAL_SO_COM0_CLOCK_OUTPUT_MASK;
    clock1OutValue &= RL78G13_SERIAL_SO_COM1_CLOCK_OUTPUT_MASK;
    clock2OutValue &= RL78G13_SERIAL_SO_COM2_CLOCK_OUTPUT_MASK;
    clock3OutValue &= RL78G13_SERIAL_SO_COM3_CLOCK_OUTPUT_MASK;

    data0OutValue &= RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_MASK;
    data1OutValue &= RL78G13_SERIAL_SO_COM1_DATA_OUTPUT_MASK;
    data2OutValue &= RL78G13_SERIAL_SO_COM2_DATA_OUTPUT_MASK;
    data3OutValue &= RL78G13_SERIAL_SO_COM3_DATA_OUTPUT_MASK;

    uint16_t regValue = (clock0OutValue| clock1OutValue| clock2OutValue| clock3OutValue
        | data0OutValue| data1OutValue| data2OutValue| data3OutValue);
    RL78G13_SerialSOWriteSingle(unit, regValue);
}

/**
 * Function:
 *  void RL78G13_SerialSOWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial so write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSOWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSOReadSingle(unit);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSOWriteSingle(unit, regValue);
}

/**
 * Function:        uint16_t RL78G13_SerialSOReadAll(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial so read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSOReadAll(RL78G13_SERIAL_UNIT unit)
{
    return RL78G13_SerialSOReadSingle(unit);
}

/**
 * Function:        uint16_t RL78G13_SerialSOReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial so read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSOReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSOReadSingle(unit);
    regValue &= mask;
    return regValue;
}


/*SOL*/

/**
 * Function:        void RL78G13_SerialSOLWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial sol write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  value -     The value.
 */

static void RL78G13_SerialSOLWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
{
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        SOL0 = value;
    }
    else
    {
        SOL1 = value;
    }
}

/**
 * Function:        uint16_t RL78G13_SerialSOLReadSingle(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial sol read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSOLReadSingle(RL78G13_SERIAL_UNIT unit)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        regValue = SOL0;
    }
    else
    {
        regValue = SOL1;
    }
    return regValue;
}

/**
 * Function:
 *  void RL78G13_SerialSOLWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t tx0LevelReserve,
 *  uint16_t tx2LevelReserve)
 *
 * Brief:
 *      Rl 78 g 13 serial sol write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -              The unit.
 *  tx0LevelReserve -   The transmit 0 level reserve.发送口0传输信号反向
 *  tx2LevelReserve -   The transmit 2 level reserve.传输口1传输信号反向
 */

void RL78G13_SerialSOLWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t tx0LevelReserve,
    uint16_t tx2LevelReserve)
{
    tx0LevelReserve &= RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_MASK;
    tx2LevelReserve &= RL78G13_SERIAL_SOL_COM2_OUTPUT_REVERSE_FLAG_MASK;
    uint16_t regValue = (tx0LevelReserve | tx2LevelReserve);
    RL78G13_SerialSOLWriteSingle(unit, regValue);
}

/**
 * Function:
 *  void RL78G13_SerialSOLWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial sol write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSOLWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSOLReadSingle(unit);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSOLWriteSingle(unit, regValue);
}

/**
 * Function:        uint16_t RL78G13_SerialSOLReadAll(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial sol read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSOLReadAll(RL78G13_SERIAL_UNIT unit)
{
    return RL78G13_SerialSOLReadSingle(unit);
}

/**
 * Function:        uint16_t RL78G13_SerialSOLReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial sol read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSOLReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSOLReadSingle(unit);
    regValue &= mask;
    return regValue;
}


/*SSC*/

/**
 * Function:        void RL78G13_SerialSSCWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial ssc write single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  value -     The value.
 */

static void RL78G13_SerialSSCWriteSingle(RL78G13_SERIAL_UNIT unit, uint16_t value)
{
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        SSC0 = value;
    }
    else
    {
        //SSC1 = value;
    }
}

/**
 * Function:        uint16_t RL78G13_SerialSSCReadSingle(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial ssc read single.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

static uint16_t RL78G13_SerialSSCReadSingle(RL78G13_SERIAL_UNIT unit)
{
    uint16_t regValue = 0;
    if (unit == RL78G13_SERIAL_UNIT_0)
    {
        regValue = SSC0;
    }
    else
    {
        //regValue = SSC1;
    }
    return regValue;
}

/**
 * Function:
 *  void RL78G13_SerialSSCWriteAll(RL78G13_SERIAL_UNIT unit,uint16_t errIntEnable,
 *  uint16_t snoozeEnable)
 *
 * Brief:
 *      Rl 78 g 13 serial ssc write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -          The unit.
 *  errIntEnable -  The error int enable.错误唤醒使能
 *  snoozeEnable -  The snooze enable.SNOOZE模式使能
 */

void RL78G13_SerialSSCWriteAll(RL78G13_SERIAL_UNIT unit,uint16_t errIntEnable,
    uint16_t snoozeEnable)
{
    errIntEnable &= RL78G13_SERIAL_SSC_INT_ERR_ENABLE_MASK;
    snoozeEnable &= RL78G13_SERIAL_SSC_SNOOZE_ENABLE_MASK;
    uint16_t regValue = (errIntEnable| snoozeEnable);
    RL78G13_SerialSSCWriteSingle(unit, regValue);
}

/**
 * Function:
 *  void RL78G13_SerialSSCWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial ssc write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -      The unit.
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialSSCWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value)
{
    uint16_t regValue = RL78G13_SerialSSCReadSingle(unit);
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    RL78G13_SerialSSCWriteSingle(unit, regValue);
}

/**
 * Function:        uint16_t RL78G13_SerialSSCReadAll(RL78G13_SERIAL_UNIT unit)
 *
 * Brief:
 *      Rl 78 g 13 serial ssc read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSSCReadAll(RL78G13_SERIAL_UNIT unit)
{
    return RL78G13_SerialSSCReadSingle(unit);
}

/**
 * Function:        uint16_t RL78G13_SerialSSCReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial ssc read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  unit -  The unit.
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialSSCReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask)
{
    uint16_t regValue = RL78G13_SerialSSCReadSingle(unit);
    regValue &= mask;
    return regValue;
}


/*ISC*/

/**
 * Function:        void RL78G13_SerialISCWriteAll(uint8_t timer7Switch,uint8_t intp0Switch)
 *
 * Brief:
 *      Rl 78 g 13 serial isc write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  timer7Switch -  The timer 7 switch.TIMER7引脚切换
 *  intp0Switch -   The intp 0 switch.intp0引脚切换
 */

void RL78G13_SerialISCWriteAll(uint8_t timer7Switch,uint8_t intp0Switch)
{
    timer7Switch &= RL78G13_SERIAL_ISC_TIMER7_INPUT_MASK;
    intp0Switch &= RL78G13_SERIAL_ISC_INTP0_INPUT_MASK;
    uint8_t regValue = (timer7Switch| intp0Switch);
    ISC = regValue;
}

/**
 * Function:        void RL78G13_SerialISCWriteOne(uint16_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial isc write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialISCWriteOne(uint16_t mask, uint8_t value)
{
    uint8_t regValue = ISC;
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    ISC = regValue;
}

/**
 * Function:        uint8_t RL78G13_SerialISCReadAll(void)
 *
 * Brief:
 *      Rl 78 g 13 serial isc read all.
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

uint8_t RL78G13_SerialISCReadAll(void)
{
    uint8_t regValue = ISC;
    return regValue;
}

/**
 * Function:        uint8_t RL78G13_SerialISCReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial isc read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint8_t.
 */

uint8_t RL78G13_SerialISCReadOne(uint16_t mask)
{
    uint8_t regValue = ISC;
    regValue &= mask;
    return regValue;
}


/*NFEN*/

/**
 * Function:
 *  void RL78G13_SerialNFENWriteAll(uint8_t rxd0FilterEnable, uint8_t rxd1FilterEnable,
 *  uint8_t rxd2FilterEnable, uint8_t rxd3FilterEnable)
 *
 * Brief:
 *      Rl 78 g 13 serial nfen write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  rxd0FilterEnable -  The receive data 0 filter enable.输入0的引脚滤波器开关
 *  rxd1FilterEnable -  The receive data 1 filter enable.输入1的引脚滤波器开关
 *  rxd2FilterEnable -  The receive data 2 filter enable.输入2的引脚滤波器开关
 *  rxd3FilterEnable -  The receive data 3 filter enable.输入3的引脚滤波器开关
 */

void RL78G13_SerialNFENWriteAll(uint8_t rxd0FilterEnable, uint8_t rxd1FilterEnable,
    uint8_t rxd2FilterEnable, uint8_t rxd3FilterEnable)
{
    rxd0FilterEnable &= RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_MASK;
    rxd1FilterEnable &= RL78G13_SERIAL_NFEN_RXD1_NOIZE_FILTER_MASK;
    rxd2FilterEnable &= RL78G13_SERIAL_NFEN_RXD2_NOIZE_FILTER_MASK;
    rxd3FilterEnable &= RL78G13_SERIAL_NFEN_RXD3_NOIZE_FILTER_MASK;
    uint8_t regValue = (rxd0FilterEnable| rxd1FilterEnable| rxd2FilterEnable| rxd3FilterEnable);
    NFEN0 = regValue;
}

/**
 * Function:        void RL78G13_SerialNFENWriteOne(uint16_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 serial nfen write one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  mask -      The mask.
 *  value -     The value.
 */

void RL78G13_SerialNFENWriteOne(uint16_t mask, uint8_t value)
{
    uint8_t regValue = NFEN0;
    value &= mask;
    regValue &= (~mask);
    regValue |= value;
    NFEN0 = regValue;
}

/**
 * Function:        uint16_t RL78G13_SerialNFENReadAll()
 *
 * Brief:
 *      Rl 78 g 13 serial nfen read all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialNFENReadAll()
{
    uint8_t regValue = NFEN0;
    return regValue;
}

/**
 * Function:        uint16_t RL78G13_SerialNFENReadOne(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 serial nfen read one.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  mask -  The mask.
 *
 * Returns:
 *      An uint16_t.
 */

uint16_t RL78G13_SerialNFENReadOne(uint16_t mask)
{
    uint8_t regValue = NFEN0;
    regValue &= mask;
    return regValue;
}


