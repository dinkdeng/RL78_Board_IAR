#ifndef __RL78G13_PORT_H_
#define __RL78G13_PORT_H_
#include "MacroDriver.h"

typedef enum PORT_BITS
{
    PORT_BIT0 = 0X01,
    PORT_BIT1 = 0X02,
    PORT_BIT2 = 0X04,
    PORT_BIT3 = 0X08,
    PORT_BIT4 = 0X10,
    PORT_BIT5 = 0X20,
    PORT_BIT6 = 0X40,
    PORT_BIT7 = 0X80,
}PORT_BITS;

typedef enum PORT_INDEX
{
    PORT_INDEX0 = 0,
    PORT_INDEX1 = 1,
    PORT_INDEX2 = 2,
    PORT_INDEX3 = 3,
    PORT_INDEX4 = 4,
    PORT_INDEX5 = 5,
    PORT_INDEX6 = 6,
    PORT_INDEX7 = 7,
    PORT_INDEX8 = 8,
    PORT_INDEX9 = 9,
    PORT_INDEX10 = 10,
    PORT_INDEX11 = 11,
    PORT_INDEX12 = 12,
    PORT_INDEX13 = 13,
    PORT_INDEX14 = 14,
    PORT_INDEX15 = 15,
}PORT_INDEX;

/*端口模式寄存器*/
/*设置端口模式为输入或者输出*/
#define RL78G13_PORT_PMn0_MODE_INPUT     (0x01U) 
#define RL78G13_PORT_PMn0_MODE_OUTPUT    (0x00U) 

#define RL78G13_PORT_PMn1_MODE_INPUT     (0x02U) 
#define RL78G13_PORT_PMn1_MODE_OUTPUT    (0x00U) 

#define RL78G13_PORT_PMn2_MODE_INPUT     (0x04U) 
#define RL78G13_PORT_PMn2_MODE_OUTPUT    (0x00U) 

#define RL78G13_PORT_PMn3_MODE_INPUT     (0x08U) 
#define RL78G13_PORT_PMn3_MODE_OUTPUT    (0x00U) 

#define RL78G13_PORT_PMn4_MODE_INPUT     (0x10U) 
#define RL78G13_PORT_PMn4_MODE_OUTPUT    (0x00U) 

#define RL78G13_PORT_PMn5_MODE_INPUT     (0x20U) 
#define RL78G13_PORT_PMn5_MODE_OUTPUT    (0x00U) 

#define RL78G13_PORT_PMn6_MODE_INPUT     (0x40U) 
#define RL78G13_PORT_PMn6_MODE_OUTPUT    (0x00U) 

#define RL78G13_PORT_PMn7_MODE_INPUT     (0x80U) 
#define RL78G13_PORT_PMn7_MODE_OUTPUT    (0x00U) 

/*端口寄存器*/
/*设置端口输出低电平或者高电平*/
#define RL78G13_PORT_Pn0_OUTPUT_0       (0x00U)
#define RL78G13_PORT_Pn0_OUTPUT_1       (0x01U)

#define RL78G13_PORT_Pn1_OUTPUT_0       (0x00U)
#define RL78G13_PORT_Pn1_OUTPUT_1       (0x02U)

#define RL78G13_PORT_Pn2_OUTPUT_0       (0x00U)
#define RL78G13_PORT_Pn2_OUTPUT_1       (0x04U)

#define RL78G13_PORT_Pn3_OUTPUT_0       (0x00U)
#define RL78G13_PORT_Pn3_OUTPUT_1       (0x08U)

#define RL78G13_PORT_Pn4_OUTPUT_0       (0x00U)
#define RL78G13_PORT_Pn4_OUTPUT_1       (0x10U)

#define RL78G13_PORT_Pn5_OUTPUT_0       (0x00U)
#define RL78G13_PORT_Pn5_OUTPUT_1       (0x20U)

#define RL78G13_PORT_Pn6_OUTPUT_0       (0x00U)
#define RL78G13_PORT_Pn6_OUTPUT_1       (0x40U)

#define RL78G13_PORT_Pn7_OUTPUT_0       (0x00U)
#define RL78G13_PORT_Pn7_OUTPUT_1       (0x80U)

/*上拉电阻选择寄存器*/
/*设置端口上拉或不上拉*/
#define RL78G13_PORT_PULLUP0_OFF         (0x00U)
#define RL78G13_PORT_PULLUP0_ON          (0x01U)

#define RL78G13_PORT_PULLUP1_OFF         (0x00U)
#define RL78G13_PORT_PULLUP1_ON          (0x02U)

#define RL78G13_PORT_PULLUP2_OFF         (0x00U)
#define RL78G13_PORT_PULLUP2_ON          (0x04U)

#define RL78G13_PORT_PULLUP3_OFF         (0x00U)
#define RL78G13_PORT_PULLUP3_ON          (0x08U)

#define RL78G13_PORT_PULLUP4_OFF         (0x00U)
#define RL78G13_PORT_PULLUP4_ON          (0x10U)

#define RL78G13_PORT_PULLUP5_OFF         (0x00U)
#define RL78G13_PORT_PULLUP5_ON          (0x20U)

#define RL78G13_PORT_PULLUP6_OFF         (0x00U)
#define RL78G13_PORT_PULLUP6_ON          (0x40U)

#define RL78G13_PORT_PULLUP7_OFF         (0x00U)
#define RL78G13_PORT_PULLUP7_ON          (0x80U)


/*端口输入模式寄存器*/
/*设置端口输入TTL或者正常*/
#define RL78G13_PORT_PIM0_TTL_OFF        (0x00U)
#define RL78G13_PORT_PIM0_TTL_ON         (0x01U)

#define RL78G13_PORT_PIM1_TTL_OFF        (0x00U)
#define RL78G13_PORT_PIM1_TTL_ON         (0x02U)

#define RL78G13_PORT_PIM2_TTL_OFF        (0x00U)
#define RL78G13_PORT_PIM2_TTL_ON         (0x04U)

#define RL78G13_PORT_PIM3_TTL_OFF        (0x00U)
#define RL78G13_PORT_PIM3_TTL_ON         (0x08U)

#define RL78G13_PORT_PIM4_TTL_OFF        (0x00U)
#define RL78G13_PORT_PIM4_TTL_ON         (0x10U)

#define RL78G13_PORT_PIM5_TTL_OFF        (0x00U)
#define RL78G13_PORT_PIM5_TTL_ON         (0x20U)

#define RL78G13_PORT_PIM6_TTL_OFF        (0x00U)
#define RL78G13_PORT_PIM6_TTL_ON         (0x40U)

#define RL78G13_PORT_PIM7_TTL_OFF        (0x00U)
#define RL78G13_PORT_PIM7_TTL_ON         (0x80U)


/*端口输出模式寄存器*/
/*设置端口输出模式开漏输出还是正常*/
#define RL78G13_PORT_POM0_NCH_OFF       (0x00U)
#define RL78G13_PORT_POM0_NCH_ON        (0x01U)

#define RL78G13_PORT_POM1_NCH_OFF       (0x00U)
#define RL78G13_PORT_POM1_NCH_ON        (0x02U)

#define RL78G13_PORT_POM2_NCH_OFF       (0x00U)
#define RL78G13_PORT_POM2_NCH_ON        (0x04U)

#define RL78G13_PORT_POM3_NCH_OFF       (0x00U)
#define RL78G13_PORT_POM3_NCH_ON        (0x08U)

#define RL78G13_PORT_POM4_NCH_OFF       (0x00U)
#define RL78G13_PORT_POM4_NCH_ON        (0x10U)

#define RL78G13_PORT_POM5_NCH_OFF       (0x00U)
#define RL78G13_PORT_POM5_NCH_ON        (0x20U)

#define RL78G13_PORT_POM6_NCH_OFF       (0x00U)
#define RL78G13_PORT_POM6_NCH_ON        (0x40U)

#define RL78G13_PORT_POM7_NCH_OFF       (0x00U)
#define RL78G13_PORT_POM7_NCH_ON        (0x80U)


/*端口模式控制寄存器*/
/*设置端口为模拟还是数字,1位模拟输入*/
#define RL78G13_PORT_PMC0_NOT_USE       (0x01U)
#define RL78G13_PORT_PMC0_DI_ON         (0x00U)

#define RL78G13_PORT_PMC1_NOT_USE       (0x02U)
#define RL78G13_PORT_PMC1_DI_ON         (0x00U)

#define RL78G13_PORT_PMC2_NOT_USE       (0x04U)
#define RL78G13_PORT_PMC2_DI_ON         (0x00U)

#define RL78G13_PORT_PMC3_NOT_USE       (0x08U)
#define RL78G13_PORT_PMC3_DI_ON         (0x00U)

#define RL78G13_PORT_PMC4_NOT_USE       (0x10U)
#define RL78G13_PORT_PMC4_DI_ON         (0x00U)

#define RL78G13_PORT_PMC5_NOT_USE       (0x20U)
#define RL78G13_PORT_PMC5_DI_ON         (0x00U)

#define RL78G13_PORT_PMC6_NOT_USE       (0x40U)
#define RL78G13_PORT_PMC6_DI_ON         (0x00U)

#define RL78G13_PORT_PMC7_NOT_USE       (0x80U)
#define RL78G13_PORT_PMC7_DI_ON         (0x00U)


/*AD端口配置寄存器*/
/*P20 - P27 设置指定端口是否配置为ADC端口*/
#define RL78G13_PORT_ADPC_DI_OFF         (0x00U)
#define RL78G13_PORT_ADPC_DI_7           (0x08U)
#define RL78G13_PORT_ADPC_DI_6_7         (0x07U)
#define RL78G13_PORT_ADPC_DI_5_7         (0x06U)
#define RL78G13_PORT_ADPC_DI_4_7         (0x05U)
#define RL78G13_PORT_ADPC_DI_3_7         (0x04U)
#define RL78G13_PORT_ADPC_DI_2_7         (0x03U)
#define RL78G13_PORT_ADPC_DI_1_7         (0x02U)
#define RL78G13_PORT_ADPC_DI_0_7         (0x01U)


/*外围输入输出重定向寄存器*/
/*具体查看重定向表*/
#define RL78G13_PORT_PIOR_BIT_0_SET      (0x01U)
#define RL78G13_PORT_PIOR_BIT_1_SET      (0x02U)
#define RL78G13_PORT_PIOR_BIT_2_SET      (0x04U)
#define RL78G13_PORT_PIOR_BIT_3_SET      (0x08U)
#define RL78G13_PORT_PIOR_BIT_4_SET      (0x10U)
#define RL78G13_PORT_PIOR_BIT_5_SET      (0x20U)
#define RL78G13_PORT_PIOR_BIT_6_SET      (0x40U)
#define RL78G13_PORT_PIOR_BIT_7_SET      (0x80U)

/*设置端口输入输出缓冲器是否打开*/
#define RL78G13_PORT_GDIDIS_DISABLE      (0x01U)

void RL78G13_Port_Init(PORT_INDEX index, PORT_BITS bit, uint8_t PMnSet, uint8_t PnSet, uint8_t PULLUPSet, uint8_t PIMSet,
    uint8_t POMSet, uint8_t PMCSet);

void RL78G13_Port_Init_User();

#endif




