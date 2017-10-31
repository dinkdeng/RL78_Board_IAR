#include "RL78G13_Port.h"

/**
 * Function:    
 *  void RL78G13_Port0_Init(PORT_BITS bit,uint8_t PMnSet,uint8_t PnSet,uint8_t PULLUPSet,
 *  uint8_t PIMSet, uint8_t POMSet,uint8_t PMCSet)
 *
 * Brief:
 *      Rl 78 g 13 port 0 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/23
 *
 * Param:
 *  bit -           The bit.先设置的端口位
 *  PMnSet -        Set the mn belongs to. 端口输入输出,1为输入,0为输出,使用头文件宏定义
 *  PnSet -         Set the pn belongs to. 端口高低电平,1为高电平,0为低电平,使用头文件宏定义
 *  PULLUPSet -     Set the pullup belongs to.端口上拉电阻,1为上拉,0为不上拉,使用头文件宏定义
 *  PIMSet -        Set the pim belongs to.端口输入TTL缓冲,1为缓冲,0为不缓冲,使用头文件宏定义
 *  POMSet -        Set the pom belongs to.端口输出TTL缓冲,1位缓冲,0为不缓冲,针对总线通讯的N极开路,使用头文件宏定义
 *  PMCSet -        Set the pmc belongs to.端口模式,模拟输入还是数字输入输出,1为模拟输入,0为数字,使用头文件宏定义
 */

void RL78G13_Port0_Init(PORT_BITS bit,uint8_t PMnSet,uint8_t PnSet,uint8_t PULLUPSet,uint8_t PIMSet,
    uint8_t POMSet,uint8_t PMCSet)
{
    uint8_t regValue = 0;
    regValue = PM0;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM0 = regValue;

    regValue = P0;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P0 = regValue;

    regValue = PU0;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PULLUPSet;
    /*写回寄存器*/
    PU0 = regValue;
    
    regValue = PIM0;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PIMSet;
    /*写回寄存器*/
    PIM0 = regValue;

    regValue = POM0;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= POMSet;
    /*写回寄存器*/
    POM0 = regValue;

    regValue = PMC0;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMCSet;
    /*写回寄存器*/
    PMC0 = regValue;
}

/**
 * Function:    
 *  void RL78G13_Port1_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet,
 *  uint8_t PIMSet, uint8_t POMSet)
 *
 * Brief:
 *      Rl 78 g 13 port 1 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -           The bit.端口号
 *  PMnSet -        Set the mn belongs to.输入输出
 *  PnSet -         Set the pn belongs to.输出电平
 *  PULLUPSet -     Set the pullup belongs to.是否上拉
 *  PIMSet -        Set the pim belongs to.输入缓冲设置
 *  POMSet -        Set the pom belongs to.输出缓冲设置
 */

void RL78G13_Port1_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet, uint8_t PIMSet,
    uint8_t POMSet)
{
    uint8_t regValue = 0;
    regValue = PM1;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM1 = regValue;

    regValue = P1;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P1 = regValue;

    regValue = PU1;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PULLUPSet;
    /*写回寄存器*/
    PU1 = regValue;

    regValue = PIM1;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PIMSet;
    /*写回寄存器*/
    PIM1 = regValue;

    regValue = POM1;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= POMSet;
    /*写回寄存器*/
    POM1 = regValue;
}

/**
 * Function:        void RL78G13_Port2_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet)
 *
 * Brief:
 *      Rl 78 g 13 port 2 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -       The bit.端口号
 *  PMnSet -    Set the mn belongs to.输入输出
 *  PnSet -     Set the pn belongs to.输出值
 */

void RL78G13_Port2_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet)
{
    uint8_t regValue = 0;
    regValue = PM2;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM2 = regValue;

    regValue = P2;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P2 = regValue;
}

/**
 * Function:    
 *  void RL78G13_Port3_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet)
 *
 * Brief:
 *      Rl 78 g 13 port 3 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -           The bit.端口号
 *  PMnSet -        Set the mn belongs to.输入输出
 *  PnSet -         Set the pn belongs to.输出电平
 *  PULLUPSet -     Set the pullup belongs to.上拉电阻
 */

void RL78G13_Port3_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet)
{
    uint8_t regValue = 0;
    regValue = PM3;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM3 = regValue;

    regValue = P3;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P3 = regValue;

    regValue = PU3;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PULLUPSet;
    /*写回寄存器*/
    PU3 = regValue;
}

/**
 * Function:    
 *  void RL78G13_Port4_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet)
 *
 * Brief:
 *      Rl 78 g 13 port 4 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -           The bit.端口号
 *  PMnSet -        Set the mn belongs to.输入输出
 *  PnSet -         Set the pn belongs to.输出值
 *  PULLUPSet -     Set the pullup belongs to.上拉值
 */

void RL78G13_Port4_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet)
{
    uint8_t regValue = 0;
    regValue = PM4;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM4 = regValue;

    regValue = P4;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P4 = regValue;

    regValue = PU4;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PULLUPSet;
    /*写回寄存器*/
    PU4 = regValue;
}

/**
 * Function:    
 *  void RL78G13_Port5_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet,
 *  uint8_t PIMSet, uint8_t POMSet)
 *
 * Brief:
 *      Rl 78 g 13 port 5 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -           The bit.端口号
 *  PMnSet -        Set the mn belongs to.输入输出设置
 *  PnSet -         Set the pn belongs to.输出值
 *  PULLUPSet -     Set the pullup belongs to.端口上哪
 *  PIMSet -        Set the pim belongs to.输入缓冲
 *  POMSet -        Set the pom belongs to.输出缓冲
 */

void RL78G13_Port5_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet, uint8_t PIMSet,
    uint8_t POMSet)
{
    uint8_t regValue = 0;
    regValue = PM5;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM5 = regValue;

    regValue = P5;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P5 = regValue;

    regValue = PU5;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PULLUPSet;
    /*写回寄存器*/
    PU5 = regValue;

    regValue = PIM5;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PIMSet;
    /*写回寄存器*/
    PIM5 = regValue;

    regValue = POM5;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= POMSet;
    /*写回寄存器*/
    POM5 = regValue;
}

/**
 * Function:        void RL78G13_Port6_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet)
 *
 * Brief:
 *      Rl 78 g 13 port 6 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -       The bit.端口号
 *  PMnSet -    Set the mn belongs to.输入输出
 *  PnSet -     Set the pn belongs to.输出值
 */

void RL78G13_Port6_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet)
{
    uint8_t regValue = 0;
    regValue = PM6;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM6 = regValue;

    regValue = P6;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P6 = regValue;
}

/**
 * Function:    
 *  void RL78G13_Port7_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet,
 *  uint8_t POMSet)
 *
 * Brief:
 *      Rl 78 g 13 port 7 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -           The bit.端口号
 *  PMnSet -        Set the mn belongs to.输入输出
 *  PnSet -         Set the pn belongs to.输出值
 *  PULLUPSet -     Set the pullup belongs to.上拉电阻
 *  POMSet -        Set the pom belongs to.输出缓冲
 */

void RL78G13_Port7_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet, uint8_t POMSet)
{
    uint8_t regValue = 0;
    regValue = PM7;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM7 = regValue;

    regValue = P7;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P7 = regValue;

    regValue = PU7;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PULLUPSet;
    /*写回寄存器*/
    PU7 = regValue;

    regValue = POM7;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= POMSet;
    /*写回寄存器*/
    POM7 = regValue;
}

/**
 * Function:    
 *  void RL78G13_Port12_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet,
 *  uint8_t PMCSet)
 *
 * Brief:
 *      Rl 78 g 13 port 12 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -           The bit.端口号
 *  PMnSet -        Set the mn belongs to.输入输出
 *  PnSet -         Set the pn belongs to.输出值
 *  PULLUPSet -     Set the pullup belongs to.上拉电阻
 *  PMCSet -        Set the pmc belongs to.输出模式
 */

void RL78G13_Port12_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet,uint8_t PMCSet)
{
    uint8_t regValue = 0;
    regValue = PM12;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM12 = regValue;

    regValue = P12;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P12 = regValue;

    regValue = PU12;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PULLUPSet;
    /*写回寄存器*/
    PU12 = regValue;

    regValue = PMC12;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMCSet;
    /*写回寄存器*/
    PMC12 = regValue;
}

/**
 * Function:        void RL78G13_Port13_Init(PORT_BITS bit, uint8_t PnSet)
 *
 * Brief:
 *      Rl 78 g 13 port 13 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -       The bit.端口号
 *  PnSet -     Set the pn belongs to.输出值
 */

void RL78G13_Port13_Init(PORT_BITS bit, uint8_t PnSet)
{
    uint8_t regValue = 0;

    regValue = P13;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P13 = regValue;
}

/**
 * Function:    
 *  void RL78G13_Port14_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet,
 *  uint8_t PMCSet)
 *
 * Brief:
 *      Rl 78 g 13 port 14 init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  bit -           The bit.端口号
 *  PMnSet -        Set the mn belongs to.输入输出
 *  PnSet -         Set the pn belongs to.输出值
 *  PULLUPSet -     Set the pullup belongs to.端口上拉电阻
 *  PMCSet -        Set the pmc belongs to.端口模式
 */

void RL78G13_Port14_Init(PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet,  uint8_t PMCSet)
{
    uint8_t regValue = 0;
    regValue = PM14;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMnSet;
    /*写回寄存器*/
    PM14 = regValue;

    regValue = P14;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PnSet;
    /*写回寄存器*/
    P14 = regValue;

    regValue = PU14;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PULLUPSet;
    /*写回寄存器*/
    PU14 = regValue;

    regValue = PMC14;
    /*清除指定位*/
    regValue &= (bit);
    /*与设定结合*/
    regValue |= PMCSet;
    /*写回寄存器*/
    PMC14 = regValue;
}

/**
 * Function:    
 *  void RL78G13_Port_Init(PORT_INDEX index, PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet,
 *  uint8_t PULLUPSet, uint8_t PIMSet, uint8_t POMSet, uint8_t PMCSet)
 *
 * Brief:
 *      Rl 78 g 13 port init.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 *
 * Param:
 *  index -         Zero-based index of the.端口序号
 *  bit -           The bit.端口号
 *  PMnSet -        Set the mn belongs to.输入输出
 *  PnSet -         Set the pn belongs to.输出值
 *  PULLUPSet -     Set the pullup belongs to.上拉电阻
 *  PIMSet -        Set the pim belongs to.输入缓冲
 *  POMSet -        Set the pom belongs to.输出缓冲
 *  PMCSet -        Set the pmc belongs to.输出模式
 */

void RL78G13_Port_Init(PORT_INDEX index, PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet, uint8_t PIMSet,
    uint8_t POMSet, uint8_t PMCSet)
{
    switch (index)
    {
    case PORT_INDEX0:
        RL78G13_Port0_Init(bit, PMnSet, PnSet, PULLUPSet, PIMSet, POMSet, PMCSet);
        break;
    case PORT_INDEX1:
        RL78G13_Port1_Init(bit, PMnSet, PnSet, PULLUPSet, PIMSet, POMSet);
        break;
    case PORT_INDEX2:
        RL78G13_Port2_Init(bit, PMnSet, PnSet);
        break;
    case PORT_INDEX3:
        RL78G13_Port3_Init(bit, PMnSet, PnSet, PULLUPSet);
        break;
    case PORT_INDEX4:
        RL78G13_Port4_Init(bit, PMnSet, PnSet, PULLUPSet);
        break;
    case PORT_INDEX5:
        RL78G13_Port5_Init(bit, PMnSet, PnSet, PULLUPSet, PIMSet, POMSet);
        break;
    case PORT_INDEX6:
        RL78G13_Port6_Init(bit, PMnSet, PnSet);
        break;
    case PORT_INDEX7:
        RL78G13_Port7_Init(bit, PMnSet, PnSet, PULLUPSet, POMSet );
        break;
    case PORT_INDEX12:
        RL78G13_Port12_Init(bit, PMnSet, PnSet, PULLUPSet, PMCSet);
        break;
    case PORT_INDEX13:
        RL78G13_Port13_Init(bit, PnSet);
        break;
    case PORT_INDEX14:
        RL78G13_Port14_Init(bit, PMnSet, PnSet, PULLUPSet, PMCSet);
        break;
    }
}

/**
 * Function:        void RL78G13_Port_Init_User()
 *
 * Brief:
 *      Rl 78 g 13 port init user.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/24
 */

void RL78G13_Port_Init_User()
{
    P4 = RL78G13_PORT_Pn1_OUTPUT_1 | RL78G13_PORT_Pn2_OUTPUT_1 | RL78G13_PORT_Pn3_OUTPUT_1;
    PM4 = RL78G13_PORT_PMn1_MODE_OUTPUT | RL78G13_PORT_PMn2_MODE_OUTPUT | RL78G13_PORT_PMn3_MODE_OUTPUT;
}



