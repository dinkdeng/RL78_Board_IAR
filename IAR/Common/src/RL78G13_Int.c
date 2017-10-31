#include "RL78G13_Int.h"

/*读取中断标志位状态*/
RL78G13_INT_FLAG RL78G13_Int_Flag_Read(RL78G13_INT_SRC intSrc)
{
    uint8_t intGroup = intSrc / 8;
    uint8_t intBit = intSrc % 8;
    uint8_t regValue = 0;

    switch (intGroup)
    {
    case 0:
        regValue = IF0L;
        break;
    case 1:
        regValue = IF0H;
        break;
    case 2:
        regValue = IF1L;
        break;
    case 3:
        regValue = IF1H;
        break;
    case 4:
        regValue = IF2L;
        break;
    case 5:
        regValue = IF2H;
        break;
    case 6:
        //regValue = IF3L;
        break;
    }
    regValue >>= intBit;
    regValue &= 0x01;
    if (regValue == 0x01)return RL78G13_INT_FLAG_ON;
    else return RL78G13_INT_FLAG_OFF;
}

/*清除中断标志位状态*/
void RL78G13_Int_Flag_Clear(RL78G13_INT_SRC intSrc)
{
    uint8_t intGroup = intSrc / 8;
    uint8_t intBit = intSrc % 8;

    switch (intGroup)
    {
    case 0:
        switch (intBit)
        {
        case 0:
            IF0L_bit.no0 = 0;
            break;
        case 1:
            IF0L_bit.no1 = 0;
            break;
        case 2:
            IF0L_bit.no2 = 0;
            break;
        case 3:
            IF0L_bit.no3 = 0;
            break;
        case 4:
            IF0L_bit.no4 = 0;
            break;
        case 5:
            IF0L_bit.no5 = 0;
            break;
        case 6:
            IF0L_bit.no6 = 0;
            break;
        case 7:
            IF0L_bit.no7 = 0;
            break;
        }
        break;
    case 1:
        switch (intBit)
        {
        case 0:
            IF0H_bit.no0 = 0;
            break;
        case 1:
            IF0H_bit.no1 = 0;
            break;
        case 2:
            IF0H_bit.no2 = 0;
            break;
        case 3:
            IF0H_bit.no3 = 0;
            break;
        case 4:
            IF0H_bit.no4 = 0;
            break;
        case 5:
            IF0H_bit.no5 = 0;
            break;
        case 6:
            IF0H_bit.no6 = 0;
            break;
        case 7:
            IF0H_bit.no7 = 0;
            break;
        }
        break;
    case 2:
        switch (intBit)
        {
        case 0:
            IF1L_bit.no0 = 0;
            break;
        case 1:
            IF1L_bit.no1 = 0;
            break;
        case 2:
            IF1L_bit.no2 = 0;
            break;
        case 3:
            IF1L_bit.no3 = 0;
            break;
        case 4:
            IF1L_bit.no4 = 0;
            break;
        case 5:
            IF1L_bit.no5 = 0;
            break;
        case 6:
            IF1L_bit.no6 = 0;
            break;
        case 7:
            IF1L_bit.no7 = 0;
            break;
        }
        break;
    case 3:
        switch (intBit)
        {
        case 0:
            IF1H_bit.no0 = 0;
            break;
        case 1:
            IF1H_bit.no1 = 0;
            break;
        case 2:
            IF1H_bit.no2 = 0;
            break;
        case 3:
            IF1H_bit.no3 = 0;
            break;
        case 4:
            IF1H_bit.no4 = 0;
            break;
        case 5:
            IF1H_bit.no5 = 0;
            break;
        case 6:
            IF1H_bit.no6 = 0;
            break;
        case 7:
            IF1H_bit.no7 = 0;
            break;
        }
        break;
    case 4:
        switch (intBit)
        {
        case 0:
            IF2L_bit.no0 = 0;
            break;
        case 1:
            IF2L_bit.no1 = 0;
            break;
        case 2:
            IF2L_bit.no2 = 0;
            break;
        case 3:
            IF2L_bit.no3 = 0;
            break;
        case 4:
            IF2L_bit.no4 = 0;
            break;
        case 5:
            IF2L_bit.no5 = 0;
            break;
        case 6:
            IF2L_bit.no6 = 0;
            break;
        case 7:
            IF2L_bit.no7 = 0;
            break;
        }
        break;
    case 5:
        switch (intBit)
        {
        case 0:
            IF2H_bit.no0 = 0;
            break;
        case 1:
            IF2H_bit.no1 = 0;
            break;
        case 2:
            IF2H_bit.no2 = 0;
            break;
        case 3:
            IF2H_bit.no3 = 0;
            break;
        case 4:
            IF2H_bit.no4 = 0;
            break;
        case 5:
            IF2H_bit.no5 = 0;
            break;
        case 6:
            IF2H_bit.no6 = 0;
            break;
        case 7:
            IF2H_bit.no7 = 0;
            break;
        }
        break;
    case 6:
        /*switch (intBit)
        {
        case 0:
            IF3L_bit.no0 = 0;
            break;
        case 1:
            IF3L_bit.no1 = 0;
            break;
        case 2:
            IF3L_bit.no2 = 0;
            break;
        case 3:
            IF3L_bit.no3 = 0;
            break;
        case 4:
            IF3L_bit.no4 = 0;
            break;
        case 5:
            IF3L_bit.no5 = 0;
            break;
        case 6:
            IF3L_bit.no6 = 0;
            break;
        case 7:
            IF3L_bit.no7 = 0;
            break;
        }*/
        break;
    }
}

/*读取中断屏蔽状态*/
RL78G13_INT_STATUS RL78G13_Int_Status_Read(RL78G13_INT_SRC intSrc)
{
    uint8_t intGroup = intSrc / 8;
    uint8_t intBit = intSrc % 8;
    uint8_t regValue = 0;

    switch (intGroup)
    {
    case 0:
        regValue = MK0L;
        break;
    case 1:
        regValue = MK0H;
        break;
    case 2:
        regValue = MK1L;
        break;
    case 3:
        regValue = MK1H;
        break;
    case 4:
        regValue = MK2L;
        break;
    case 5:
        regValue = MK2H;
        break;
    case 6:
        //regValue = MK3L;
        break;
    }
    regValue >>= intBit;
    regValue &= 0x01;
    if (regValue == 0x01)return RL78G13_INT_STATUS_DISABLE;
    else return RL78G13_INT_STATUS_ENABLE;
}

/*写入中断使能或屏蔽状态*/
void RL78G13_Int_Status_Write(RL78G13_INT_SRC intSrc, RL78G13_INT_STATUS status)
{
    uint8_t intGroup = intSrc / 8;
    uint8_t intBit = intSrc % 8;
    uint8_t intMask = (1 << intBit);
    uint8_t statusValue = status;
    statusValue <<= intBit;
    uint8_t regValue = 0;
    switch (intGroup)
    {
    case 0:
        regValue = MK0L;
        break;
    case 1:
        regValue = MK0H;
        break;
    case 2:
        regValue = MK1L;
        break;
    case 3:
        regValue = MK1H;
        break;
    case 4:
        regValue = MK2L;
        break;
    case 5:
        regValue = MK2H;
        break;
    case 6:
        //regValue = MK3L;
        break;
    }
    regValue &= (~intMask);
    regValue |= statusValue;
    switch (intGroup)
    {
    case 0:
        MK0L = regValue;
        break;
    case 1:
        MK0H = regValue;
        break;
    case 2:
        MK1L = regValue;
        break;
    case 3:
        MK1H = regValue;
        break;
    case 4:
        MK2L = regValue;
        break;
    case 5:
        MK2H = regValue;
        break;
    case 6:
        //MK3L = regValue;
        break;
    }
}

/*读取中断优先级*/
RL78G13_INT_PRI RL78G13_Int_Pri_Read(RL78G13_INT_SRC intSrc)
{
    uint8_t intGroup = intSrc / 8;
    uint8_t intBit = intSrc % 8;
    uint8_t regValue1 = 0;
    uint8_t regValue2 = 0;
    uint8_t regValue = 0;

    switch (intGroup)
    {
    case 0:
        regValue1 = PR00L;
        regValue2 = PR10L;
        break;
    case 1:
        regValue1 = PR00H;
        regValue2 = PR10H;
        break;
    case 2:
        regValue1 = PR01L;
        regValue2 = PR11L;
        break;
    case 3:
        regValue1 = PR01H;
        regValue2 = PR11H;
        break;
    case 4:
        regValue1 = PR02L;
        regValue2 = PR12L;
        break;
    case 5:
        regValue1 = PR02H;
        regValue2 = PR12H;
        break;
    case 6:
        //regValue1 = PR03L;
        //regValue2 = PR13L;
        break;
    }
    regValue1 >>= intBit;
    regValue1 &= 0x01;
    regValue2 >>= intBit;
    regValue2 &= 0x01;
    regValue = regValue2 * 2 + regValue1;
    switch (regValue)
    {
    case 0:
        return RL78G13_INT_PRI_0;
        break;
    case 1:
        return RL78G13_INT_PRI_1;
        break;
    case 2:
        return RL78G13_INT_PRI_2;
        break;
    case 3:
        return RL78G13_INT_PRI_3;
        break;
    }
    return RL78G13_INT_PRI_0;
}

/*写入指定中断优先级*/
void RL78G13_Int_Pri_Write(RL78G13_INT_SRC intSrc, RL78G13_INT_PRI priSet)
{
    uint8_t intGroup = intSrc / 8;
    uint8_t intBit = intSrc % 8;
    uint8_t intMask = (1 << intBit);
    uint8_t priValue1 = ((priSet & 0x01) == 0) ? 0x00 : 0x01;
    uint8_t priValue2 = ((priSet & 0x02) == 0) ? 0x00 : 0x01;
    priValue1 <<= intBit;
    priValue2 <<= intBit;

    uint8_t regValue1 = 0;
    uint8_t regValue2 = 0;

    switch (intGroup)
    {
    case 0:
        regValue1 = PR00L;
        regValue2 = PR10L;
        break;
    case 1:
        regValue1 = PR00H;
        regValue2 = PR10H;
        break;
    case 2:
        regValue1 = PR01L;
        regValue2 = PR11L;
        break;
    case 3:
        regValue1 = PR01H;
        regValue2 = PR11H;
        break;
    case 4:
        regValue1 = PR02L;
        regValue2 = PR12L;
        break;
    case 5:
        regValue1 = PR02H;
        regValue2 = PR12H;
        break;
    case 6:
        //regValue1 = PR03L;
        //regValue2 = PR13L;
        break;
    }
    regValue1 &= (~intMask);
    regValue1 |= priValue1;

    regValue2 &= (~intMask);
    regValue2 |= priValue2;

    switch (intGroup)
    {
    case 0:
        PR00L = regValue1;
        PR10L = regValue2;
        break;
    case 1:
        PR00H = regValue1;
        PR10H = regValue2;
        break;
    case 2:
        PR01L = regValue1;
        PR11L = regValue2;
        break;
    case 3:
        PR01H = regValue1;
        PR11H = regValue2;
        break;
    case 4:
        PR02L = regValue1;
        PR12L = regValue2;
        break;
    case 5:
        PR02H = regValue1;
        PR12H = regValue2;
        break;
    case 6:
        //PR03L = regValue1;
        //PR13L = regValue2;
        break;
    }
}

/*读取外部中断设定状态*/
RL78G13_INT_EXT_TYPE RL78G13_Int_Ext_Read(RL78G13_INT_EXT_SRC extSrc)
{
    uint8_t extGroup = extSrc / 8;
    uint8_t extBit = extSrc % 8;

    uint8_t regValue1 = 0;
    uint8_t regValue2 = 0;
    uint8_t regValue = 0;

    switch (extGroup)
    {
    case 0:
        regValue1 = EGN0;
        regValue2 = EGP0;
        break;
    case 1:
        regValue1 = EGN1;
        regValue2 = EGP1;
        break;
    }
    regValue1 >>= extBit;
    regValue1 &= 0x01;
    regValue2 >>= extBit;
    regValue2 &= 0x01;
    regValue = regValue2 * 2 + regValue1;
    switch (regValue)
    {
    case 0:
        return RL78G13_INT_EXT_TYPE_DISABLE;
        break;
    case 1:
        return RL78G13_INT_EXT_TYPE_FALLING;
        break;
    case 2:
        return RL78G13_INT_EXT_TYPE_RISING;
        break;
    case 3:
        return RL78G13_INT_EXT_TYPE_ALL;
        break;
    }
    return RL78G13_INT_EXT_TYPE_DISABLE;
}

/*写入外部中断设定状态*/
void RL78G13_Int_Ext_Set(RL78G13_INT_EXT_SRC extSrc, RL78G13_INT_EXT_TYPE type)
{
    uint8_t extGroup = extSrc / 8;
    uint8_t extBit = extSrc % 8;
    uint8_t extMask = (1 << extBit);
    uint8_t extValue1 = ((type & 0x01) == 0) ? 0x00 : 0x01;
    uint8_t extValue2 = ((type & 0x02) == 0) ? 0x00 : 0x01;

    uint8_t regValue1 = 0;
    uint8_t regValue2 = 0;

    extValue1 <<= extBit;
    extValue2 <<= extBit;

    switch (extGroup)
    {
    case 0:
        regValue1 = EGN0;
        regValue2 = EGP0;
        break;
    case 1:
        regValue1 = EGN1;
        regValue2 = EGP1;
        break;
    }
    regValue1 &= (~extMask);
    regValue1 |= extValue1;

    regValue2 &= (~extMask);
    regValue2 |= extValue2;

    switch (extGroup)
    {
    case 0:
        EGN0 = regValue1;
        EGP0 = regValue2;
        break;
    case 1:
        EGN1 = regValue1;
        EGP1 = regValue2;
        break;
    }
}



