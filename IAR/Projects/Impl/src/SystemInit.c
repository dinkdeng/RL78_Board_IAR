#include "SystemInit.h"

void SystemInit()
{
    PIOR = 0x00U;
    RL78G13_Clock_GetResetSource();
    RL78G13_Clock_Init();
}

/*底层初始化,由IAR汇编底层自动调用*/
int __low_level_init()
{
    DI();
    SystemInit();
    return 0;
}