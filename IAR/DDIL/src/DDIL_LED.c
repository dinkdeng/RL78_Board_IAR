#include "DDIL_Led.h"

/**
* Brief:
*      The ddil LED object[ ddil LED num].
*/

DDIL_LED_STRUCT DDIL_ledObject[DDIL_LED_NUM] = { 0 };

/*驱动注册*/

/**
* Function:
*  DDIL_ERROR_CODE DDIL_Led_Register(DDIL_LED_INDEX index, DDIL_LedInit_FuncPtr init,
*  DDIL_LedSet_FuncPtr set, DDIL_LedGet_FuncPtr get)
*
* Brief:
*      Ddil LED register.
*
* Author:
*      Dink
*
* Date:
*      2017/10/15
*
* Param:
*  index -     Zero-based index of the.
*  init -      The init.
*  set -       The set.
*  get -       The get.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_Led_Register(DDIL_LED_INDEX index, DDIL_LedInit_FuncPtr init,
    DDIL_LedSet_FuncPtr set, DDIL_LedGet_FuncPtr get)
{
    if (index >= DDIL_LED_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    DDIL_ledObject[index].init = init;
    DDIL_ledObject[index].get = get;
    DDIL_ledObject[index].set = set;
    return DDIL_ERROR_NONE;
}

/*LED初始化*/

/**
* Function:        DDIL_ERROR_CODE DDIL_Led_Init(DDIL_LED_INDEX index, DDIL_LED_STATUS initStatus)
*
* Brief:
*      Ddil LED init.
*
* Author:
*      Dink
*
* Date:
*      2017/10/15
*
* Param:
*  index -         Zero-based index of the.
*  initStatus -    The init status.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_Led_Init(DDIL_LED_INDEX index, DDIL_LED_STATUS initStatus)
{
    if (index >= DDIL_LED_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_ledObject[index].init == NULL)
        return DDIL_ERROR_FUNC_NULL;
    DDIL_ledObject[index].init(initStatus);
    return DDIL_ERROR_NONE;
}

/*LED设置状态*/

/**
* Function:        DDIL_ERROR_CODE DDIL_Led_Set(DDIL_LED_INDEX index, DDIL_LED_STATUS status)
*
* Brief:
*      Ddil LED set.
*
* Author:
*      Dink
*
* Date:
*      2017/10/15
*
* Param:
*  index -     Zero-based index of the.
*  status -    The status.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_Led_Set(DDIL_LED_INDEX index, DDIL_LED_STATUS status)
{
    if (index >= DDIL_LED_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_ledObject[index].set == NULL)
        return DDIL_ERROR_FUNC_NULL;
    DDIL_ledObject[index].set(status);
    return DDIL_ERROR_NONE;
}

/*LED获取状态*/

/**
* Function:        DDIL_ERROR_CODE DDIL_Led_Get(DDIL_LED_INDEX index, DDIL_LED_STATUS* status)
*
* Brief:
*      Ddil LED get.
*
* Author:
*      Dink
*
* Date:
*      2017/10/15
*
* Param:
*  index -     Zero-based index of the.
*  status -    [in,out] If non-null, the status.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_Led_Get(DDIL_LED_INDEX index, DDIL_LED_STATUS* status)
{
    if (index >= DDIL_LED_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_ledObject[index].get == NULL)
        return DDIL_ERROR_FUNC_NULL;
    DDIL_ledObject[index].get(status);
    return DDIL_ERROR_NONE;
}
