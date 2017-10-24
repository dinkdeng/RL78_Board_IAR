#include "DDIL_Delay.h"

/**
* Brief:
*      The ddil delay object[ ddil delay num].
*/

DDIL_DELAY_STRUCT DDIL_delayObject[DDIL_DELAY_NUM] = { 0 };

/*驱动注册API定义*/
DDIL_ERROR_CODE DDIL_Delay_Register(DDIL_DELAY_INDEX index, DDIL_DelayInit_FuncPtr init,
    DDIL_DelayMs_FuncPtr delayMs, DDIL_DelayUs_FuncPtr delayUs)
{
    if (index >= DDIL_DELAY_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    DDIL_delayObject[index].delayInit = init;
    DDIL_delayObject[index].delayMs = delayMs;
    DDIL_delayObject[index].delayUs = delayUs;
    return DDIL_ERROR_NONE;
}

/**
* Function:        DDIL_ERROR_CODE DDIL_Delay_Init(DDIL_DELAY_INDEX index)
*
* Brief:
*      Ddil delay init.
*
* Author:
*      Dink
*
* Date:
*      2017/10/15
*
* Param:
*  index -     Zero-based index of the.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_Delay_Init(DDIL_DELAY_INDEX index)
{
    if (index >= DDIL_DELAY_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_delayObject[index].delayInit == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_delayObject[index].delayInit();
}

/**
 * Function:        DDIL_ERROR_CODE DDIL_Delay_DelayMs(DDIL_DELAY_INDEX index, uint16_t nms)
 *
 * Brief:
 *      Ddil delay milliseconds.
 *
 * Author:
 *      Dink
 *
 * Date:
 *      2017/10/23
 *
 * Param:
 *  index -     Zero-based index of the.
 *  nms -       The nms.
 *
 * Returns:
 *      A DDIL_ERROR_CODE.
 */

DDIL_ERROR_CODE DDIL_Delay_DelayMs(DDIL_DELAY_INDEX index, uint16_t nms)
{
    if (index >= DDIL_DELAY_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_delayObject[index].delayMs == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_delayObject[index].delayMs(nms);
}

/**
* Function:        DDIL_ERROR_CODE DDIL_Delay_DelayUs(DDIL_DELAY_INDEX index, uint16_t nus)
*
* Brief:
*      Ddil delay us.
*
* Author:
*      Dink
*
* Date:
*      2017/10/15
*
* Param:
*  index -     Zero-based index of the.
*  nus -       The nus.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_Delay_DelayUs(DDIL_DELAY_INDEX index, uint16_t nus)
{
    if (index >= DDIL_DELAY_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_delayObject[index].delayUs == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_delayObject[index].delayUs(nus);
}

