#include "main_inc.h"
#include "stdint.h"
//选项字节设定
#pragma location = "OPTBYTE"
__root const uint8_t opbyte0 = 0x60U;
#pragma location = "OPTBYTE"
__root const uint8_t opbyte1 = 0x83U;
#pragma location = "OPTBYTE"
__root const uint8_t opbyte2 = 0xE8U;
#pragma location = "OPTBYTE"
__root const uint8_t opbyte3 = 0x85U;

#pragma location = "SECUID"
__root const uint8_t secuid[10] =
	{0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU};


int main(void)
{
    MAIN_CALL_FUNC();
}





