#include "RL78G13_ADC.h"

/**
 * Function:        static uint8_t RL78G13_ADC_ADM0_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 0 read.
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

static uint8_t RL78G13_ADC_ADM0_Read(void)
{
    uint8_t regValue = ADM0;
    return regValue;
}

/**
 * Function:        static void RL78G13_ADC_ADM0_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 0 write.
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

static void RL78G13_ADC_ADM0_Write(uint8_t value)
{
    ADM0 = value;
}

/**
 * Function:        static uint8_t RL78G13_ADC_ADM1_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 1 read.
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

static uint8_t RL78G13_ADC_ADM1_Read(void)
{
    uint8_t regValue = ADM1;
    return regValue;
}

/**
 * Function:        static void RL78G13_ADC_ADM1_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 1 write.
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

static void RL78G13_ADC_ADM1_Write(uint8_t value)
{
    ADM1 = value;
}

/**
 * Function:        uint8_t RL78G13_ADC_ADM2_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 2 read.
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

uint8_t RL78G13_ADC_ADM2_Read(void)
{
    uint8_t regValue = ADM2;
    return regValue;
}

/**
 * Function:        static void RL78G13_ADC_ADM2_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 2 write.
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

static void RL78G13_ADC_ADM2_Write(uint8_t value)
{
    ADM2 = value;
}

/**
 * Function:        static uint16_t RL78G13_ADC_ADCR_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adcr read.
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

static uint16_t RL78G13_ADC_ADCR_Read(void)
{
    uint16_t regValue = ADCR;
    return regValue;
}

/**
 * Function:        static uint8_t RL78G13_ADC_ADS_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC ads read.
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

static uint8_t RL78G13_ADC_ADS_Read(void)
{
    uint8_t regValue = ADS;
    return regValue;
}

/**
 * Function:        static void RL78G13_ADC_ADS_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC ads write.
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

static void RL78G13_ADC_ADS_Write(uint8_t value)
{
    ADS = value;
}

/**
 * Function:        static uint8_t RL78G13_ADC_ADUL_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adul read.
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

static uint8_t RL78G13_ADC_ADUL_Read(void)
{
    uint8_t regValue = ADUL;
    return regValue;
}

/**
 * Function:        static void RL78G13_ADC_ADUL_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adul write.
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

static void RL78G13_ADC_ADUL_Write(uint8_t value)
{
    ADUL = value;
}

/**
 * Function:        static uint8_t RL78G13_ADC_ADLL_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adll read.
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

static uint8_t RL78G13_ADC_ADLL_Read(void)
{
    uint8_t regValue = ADLL;
    return regValue;
}

/**
 * Function:        static void RL78G13_ADC_ADLL_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adll write.
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

static void RL78G13_ADC_ADLL_Write(uint8_t value)
{
    ADLL = value;
}

/**
 * Function:        static uint8_t RL78G13_ADC_ADTES_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adtes read.
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

static uint8_t RL78G13_ADC_ADTES_Read(void)
{
    uint8_t regValue = ADTES;
    return regValue;
}

/**
 * Function:        static void RL78G13_ADC_ADTES_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adtes write.
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

static void RL78G13_ADC_ADTES_Write(uint8_t value)
{
    ADTES = value;
}

/**
 * Function:        static uint8_t RL78G13_ADC_ADPC_Read(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adpc read.
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

static uint8_t RL78G13_ADC_ADPC_Read(void)
{
    uint8_t regValue = ADPC;
    return regValue;
}

/**
 * Function:        static void RL78G13_ADC_ADPC_Write(uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adpc write.
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

static void RL78G13_ADC_ADPC_Write(uint8_t value)
{
    ADPC = value;
}




/*外部导出函数*/

/**
 * Function:    
 *  void RL78G13_ADC_ADM0_Write_All(uint8_t readThenStopSet,uint8_t channelMode,
 *  uint8_t compareMode, uint8_t convertClockDiv,uint8_t convertLowPowerModeSet)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 0 write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  readThenStopSet -           Set the read then stop belongs to.
 *  channelMode -               The channel mode.
 *  compareMode -               The compare mode.
 *  convertClockDiv -           The convert clock div.
 *  convertLowPowerModeSet -    Set the convert low power mode belongs to.
 */

void RL78G13_ADC_ADM0_Write_All(uint8_t readThenStopSet,uint8_t channelMode,uint8_t compareMode,
    uint8_t convertClockDiv,uint8_t convertLowPowerModeSet)
{
    uint8_t regValue = 0;
    readThenStopSet &= RL78G13_ADC_ADM0_ADCS_READ_THEN_STOP_MASK;
    channelMode &= RL78G13_ADC_ADM0_ADMD_MODE_SELECT_MASK;
    compareMode &= RL78G13_ADC_ADM0_ADCE_COMPARE_SET_MASK;
    convertClockDiv &= RL78G13_ADC_ADM0_FR_CONVERT_CLK_DIV_MASK;
    convertLowPowerModeSet &= RL78G13_ADC_ADM0_LV_CONVERT_MODE_SET_MASK;
    regValue = (readThenStopSet| channelMode| compareMode| convertClockDiv| convertLowPowerModeSet);
    RL78G13_ADC_ADM0_Write(regValue);
}

/**
 * Function:        void RL78G13_ADC_ADM0_Write_One(uint8_t mask,uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 0 write one.
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

void RL78G13_ADC_ADM0_Write_One(uint8_t mask,uint8_t value)
{
    uint8_t regValue = RL78G13_ADC_ADM0_Read();
    regValue &= (~mask);
    regValue |= value;
    RL78G13_ADC_ADM0_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_ADC_ADM0_Read_All(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 0 read all.
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

uint8_t RL78G13_ADC_ADM0_Read_All(void)
{
    return RL78G13_ADC_ADM0_Read();
}

/**
 * Function:        uint8_t RL78G13_ADC_ADM0_Read_One(uint8_t mask)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 0 read one.
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

uint8_t RL78G13_ADC_ADM0_Read_One(uint8_t mask)
{
    uint8_t regValue = RL78G13_ADC_ADM0_Read();
    regValue &= mask;
    return regValue;
}

/**
 * Function:    
 *  void RL78G13_ADC_ADM1_Write_All(uint8_t trigMode,uint8_t convertMode,uint8_t hardTrigSelect)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 1 write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  trigMode -          The trig mode.
 *  convertMode -       The convert mode.
 *  hardTrigSelect -    The hard trig select.
 */

void RL78G13_ADC_ADM1_Write_All(uint8_t trigMode,uint8_t convertMode,uint8_t hardTrigSelect)
{
    uint8_t regValue = 0;
    trigMode &= RL78G13_ADC_ADM1_ADTMD_TRIG_MODE_SET_MASK;
    convertMode &= RL78G13_ADC_ADM1_ADSCM_CONVERT_MODE_MASK;
    hardTrigSelect &= RL78G13_ADC_ADM1_ADTRS_TRIG_SINGLE_SELECT_MASK;
    regValue = (trigMode| convertMode| hardTrigSelect);
    RL78G13_ADC_ADM1_Write(regValue);
}

/**
 * Function:        void RL78G13_ADC_ADM1_Write_One(uint8_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 1 write one.
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

void RL78G13_ADC_ADM1_Write_One(uint8_t mask, uint8_t value)
{
    uint8_t regValue = RL78G13_ADC_ADM1_Read();
    regValue &= (~mask);
    regValue |= value;
    RL78G13_ADC_ADM1_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_ADC_ADM1_Read_All(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 1 read all.
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

uint8_t RL78G13_ADC_ADM1_Read_All(void)
{
    return RL78G13_ADC_ADM1_Read();
}

/**
 * Function:        uint8_t RL78G13_ADC_ADM1_Read_One(uint8_t mask)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 1 read one.
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

uint8_t RL78G13_ADC_ADM1_Read_One(uint8_t mask)
{
    uint8_t regValue = RL78G13_ADC_ADM1_Read();
    regValue &= mask;
    return regValue;
}

/**
 * Function:    
 *  void RL78G13_ADC_ADM2_Write_All(uint8_t refpSet,uint8_t refmSet,uint8_t resultCheckMode,
 *  uint8_t snoozeSet,uint8_t resulotionSet)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 2 write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  refpSet -           Set the refp belongs to.
 *  refmSet -           Set the refm belongs to.
 *  resultCheckMode -   The result check mode.
 *  snoozeSet -         Set the snooze belongs to.
 *  resulotionSet -     Set the resulotion belongs to.
 */

void RL78G13_ADC_ADM2_Write_All(uint8_t refpSet,uint8_t refmSet,uint8_t resultCheckMode,
    uint8_t snoozeSet,uint8_t resulotionSet)
{
    uint8_t regValue = 0;
    refpSet &= RL78G13_ADC_ADM2_ADREFP_VREFP_SELECT_MASK;
    refmSet &= RL78G13_ADC_ADM2_ADREFM_VREFM_SELECT_MASK;
    resultCheckMode &= RL78G13_ADC_ADM2_ADRCK_LIMIT_MODE_MASK;
    snoozeSet &= RL78G13_ADC_ADM2_AWC_SNOOZE_MODE_MASK;
    resulotionSet &= RL78G13_ADC_ADM2_ADTYP_RESOLUTION_MASK;
    regValue = (refpSet| refmSet| resultCheckMode| snoozeSet| resulotionSet);
    RL78G13_ADC_ADM2_Write(regValue);
}

/**
 * Function:        void RL78G13_ADC_ADM2_Write_One(uint8_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 2 write one.
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

void RL78G13_ADC_ADM2_Write_One(uint8_t mask, uint8_t value)
{
    uint8_t regValue = RL78G13_ADC_ADM2_Read();
    regValue &= (~mask);
    regValue |= value;
    RL78G13_ADC_ADM2_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_ADC_ADM2_Read_All(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 2 read all.
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

uint8_t RL78G13_ADC_ADM2_Read_All(void)
{
    return RL78G13_ADC_ADM2_Read();
}

/**
 * Function:        uint8_t RL78G13_ADC_ADM2_Read_One(uint8_t mask)
 *
 * Brief:
 *      Rl 78 g 13 ADC adm 2 read one.
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

uint8_t RL78G13_ADC_ADM2_Read_One(uint8_t mask)
{
    uint8_t regValue = RL78G13_ADC_ADM2_Read();
    regValue &= mask;
    return regValue;
}

/**
 * Function:        uint16_t RL78G13_ADC_ADCR_Read_All(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adcr read all.
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

uint16_t RL78G13_ADC_ADCR_Read_All(void)
{
    return RL78G13_ADC_ADCR_Read();
}

/**
 * Function:        uint8_t RL78G13_ADC_ADCR_Read_One(uint16_t mask)
 *
 * Brief:
 *      Rl 78 g 13 ADC adcr read one.
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

uint16_t RL78G13_ADC_ADCR_Read_One(uint16_t mask)
{
    uint16_t regValue = RL78G13_ADC_ADCR_Read();
    if (mask == RL78G13_ADC_ADCR_RESULT_RESOLUTION_10_MASK)
    {
        regValue >>= 6;
    }
    else
    {
        regValue >>= 8;
    }
    return regValue;
}

/**
 * Function:        void RL78G13_ADC_ADS_Write_All(uint8_t sourceRange,uint8_t source)
 *
 * Brief:
 *      Rl 78 g 13 ADC ads write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  sourceRange -   Source range.
 *  source -        Source for the.
 */

void RL78G13_ADC_ADS_Write_All(uint8_t sourceRange,uint8_t source)
{
    uint8_t regValue = 0;
    sourceRange &= RL78G13_ADC_ADS_ADISS_SINGLE_SOURCE_MASK;
    source &= RL78G13_ADC_ADS_ADS_SIGNAL_SOURCE_MASK;
    regValue = (sourceRange| source);
    RL78G13_ADC_ADS_Write(regValue);
}

/**
 * Function:        void RL78G13_ADC_ADS_Write_One(uint8_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC ads write one.
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

void RL78G13_ADC_ADS_Write_One(uint8_t mask, uint8_t value)
{
    uint8_t regValue = RL78G13_ADC_ADS_Read();
    regValue &= (~mask);
    regValue |= value;
    RL78G13_ADC_ADS_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_ADC_ADS_Read_All(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC ads read all.
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

uint8_t RL78G13_ADC_ADS_Read_All(void)
{
    return RL78G13_ADC_ADS_Read();
}

/**
 * Function:        uint8_t RL78G13_ADC_ADS_Read_One(uint8_t mask)
 *
 * Brief:
 *      Rl 78 g 13 ADC ads read one.
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

uint8_t RL78G13_ADC_ADS_Read_One(uint8_t mask)
{
    uint8_t regValue = RL78G13_ADC_ADS_Read();
    regValue &= mask;
    return regValue;
}

/**
 * Function:        void RL78G13_ADC_ADUL_Write_All(uint8_t upperLimit)
 *
 * Brief:
 *      Rl 78 g 13 ADC adul write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  upperLimit -    The upper limit.
 */

void RL78G13_ADC_ADUL_Write_All(uint8_t upperLimit)
{
    upperLimit &= RL78G13_ADC_ADUL_UPPER_LIMIT_MASK;
    RL78G13_ADC_ADUL_Write(upperLimit);
}

/**
 * Function:        void RL78G13_ADC_ADUL_Write_One(uint8_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adul write one.
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

void RL78G13_ADC_ADUL_Write_One(uint8_t mask, uint8_t value)
{
    uint8_t regValue = RL78G13_ADC_ADUL_Read();
    regValue &= (~mask);
    regValue |= value;
    RL78G13_ADC_ADUL_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_ADC_ADUL_Read_All(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adul read all.
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

uint8_t RL78G13_ADC_ADUL_Read_All(void)
{
    return RL78G13_ADC_ADUL_Read();
}

/**
 * Function:        uint8_t RL78G13_ADC_ADUL_Read_One(uint8_t mask)
 *
 * Brief:
 *      Rl 78 g 13 ADC adul read one.
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

uint8_t RL78G13_ADC_ADUL_Read_One(uint8_t mask)
{
    uint8_t regValue = RL78G13_ADC_ADUL_Read();
    regValue &= mask;
    return regValue;
}

/**
 * Function:        void RL78G13_ADC_ADLL_Write_All(uint8_t lowLimit)
 *
 * Brief:
 *      Rl 78 g 13 ADC adll write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  lowLimit -  The low limit.
 */

void RL78G13_ADC_ADLL_Write_All(uint8_t lowLimit)
{
    lowLimit &= RL78G13_ADC_ADLL_LOWER_LIMIT_MASK;
    RL78G13_ADC_ADLL_Write(lowLimit);
}

/**
 * Function:        void RL78G13_ADC_ADLL_Write_One(uint8_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adll write one.
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

void RL78G13_ADC_ADLL_Write_One(uint8_t mask, uint8_t value)
{
    uint8_t regValue = RL78G13_ADC_ADLL_Read();
    regValue &= (~mask);
    regValue |= value;
    RL78G13_ADC_ADLL_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_ADC_ADLL_Read_All(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adll read all.
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

uint8_t RL78G13_ADC_ADLL_Read_All(void)
{
    return RL78G13_ADC_ADLL_Read();
}

/**
 * Function:        uint8_t RL78G13_ADC_ADLL_Read_One(uint8_t mask)
 *
 * Brief:
 *      Rl 78 g 13 ADC adll read one.
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

uint8_t RL78G13_ADC_ADLL_Read_One(uint8_t mask)
{
    uint8_t regValue = RL78G13_ADC_ADLL_Read();
    regValue &= mask;
    return regValue;
}

/**
 * Function:        void RL78G13_ADC_ADTES_Write_All(uint8_t testTarget)
 *
 * Brief:
 *      Rl 78 g 13 ADC adtes write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  testTarget -    The test target.
 */

void RL78G13_ADC_ADTES_Write_All(uint8_t testTarget)
{
    testTarget &= RL78G13_ADC_ADTES_TEST_TARGET_SELECT_MASK;
    RL78G13_ADC_ADTES_Write(testTarget);
}

/**
 * Function:        void RL78G13_ADC_ADTES_Write_One(uint8_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adtes write one.
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

void RL78G13_ADC_ADTES_Write_One(uint8_t mask, uint8_t value)
{
    uint8_t regValue = RL78G13_ADC_ADTES_Read();
    regValue &= (~mask);
    regValue |= value;
    RL78G13_ADC_ADTES_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_ADC_ADTES_Read_All(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adtes read all.
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

uint8_t RL78G13_ADC_ADTES_Read_All(void)
{
    return RL78G13_ADC_ADTES_Read();
}

/**
 * Function:        uint8_t RL78G13_ADC_ADTES_Read_One(uint8_t mask)
 *
 * Brief:
 *      Rl 78 g 13 ADC adtes read one.
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

uint8_t RL78G13_ADC_ADTES_Read_One(uint8_t mask)
{
    uint8_t regValue = RL78G13_ADC_ADTES_Read();
    regValue &= mask;
    return regValue;
}

/**
 * Function:        void RL78G13_ADC_ADPC_Write_All(uint8_t adpcSelect)
 *
 * Brief:
 *      Rl 78 g 13 ADC adpc write all.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/30
 *
 * Param:
 *  adpcSelect -    The adpc select.
 */

void RL78G13_ADC_ADPC_Write_All(uint8_t adpcSelect)
{
    adpcSelect &= RL78G13_ADC_ADPC_ANALOG_PIN_SELECT_MASK;
    RL78G13_ADC_ADPC_Write(adpcSelect);
}

/**
 * Function:        void RL78G13_ADC_ADPC_Write_One(uint8_t mask, uint8_t value)
 *
 * Brief:
 *      Rl 78 g 13 ADC adpc write one.
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

void RL78G13_ADC_ADPC_Write_One(uint8_t mask, uint8_t value)
{
    uint8_t regValue = RL78G13_ADC_ADPC_Read();
    regValue &= (~mask);
    regValue |= value;
    RL78G13_ADC_ADPC_Write(regValue);
}

/**
 * Function:        uint8_t RL78G13_ADC_ADPC_Read_All(void)
 *
 * Brief:
 *      Rl 78 g 13 ADC adpc read all.
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

uint8_t RL78G13_ADC_ADPC_Read_All(void)
{
    return RL78G13_ADC_ADPC_Read();
}

/**
 * Function:        uint8_t RL78G13_ADC_ADPC_Read_One(uint8_t mask)
 *
 * Brief:
 *      Rl 78 g 13 ADC adpc read one.
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

uint8_t RL78G13_ADC_ADPC_Read_One(uint8_t mask)
{
    uint8_t regValue = RL78G13_ADC_ADPC_Read();
    regValue &= mask;
    return regValue;
}








