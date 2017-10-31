#include "DDIL_ExtKey.h"

/**
* Brief:
*      The ddil extent ket object[ ddil extkey num].
*/

DDIL_EXTKEY_STRUCT DDIL_extKetObject[DDIL_EXTKEY_NUM] = { 0 };


/*外部按键驱动注册*/

/**
* Function:
*  DDIL_ERROR_CODE DDIL_ExtKey_Register(DDIL_EXTKEY_INDEX index, DDIL_ExtKey_Init_FuncPtr init,
*  DDIL_ExtKey_GetStatus_FuncPtr getStatus, DDIL_ExtKey_WaitStatus_FuncPtr waitStatus)
*
* Brief:
*      Ddil extent key register.
*
* Author:
*      Dink
*
* Date:
*      2017/10/15
*
* Param:
*  index -         Zero-based index of the.
*  init -          The init.
*  getStatus -     The get status.
*  waitStatus -    The wait status.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_ExtKey_Register(DDIL_EXTKEY_INDEX index, DDIL_ExtKey_Init_FuncPtr init,
    DDIL_ExtKey_GetStatus_FuncPtr getStatus, DDIL_ExtKey_WaitStatus_FuncPtr waitStatus)
{
    if (index >= DDIL_EXTKEY_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    DDIL_extKetObject[index].init = init;
    DDIL_extKetObject[index].getStatus = getStatus;
    DDIL_extKetObject[index].waitStatus = waitStatus;
    return DDIL_ERROR_NONE;
}

/*初始化*/

/**
* Function:        DDIL_ERROR_CODE DDIL_ExtKey_Init(DDIL_EXTKEY_INDEX index)
*
* Brief:
*      Ddil extent key init.
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

DDIL_ERROR_CODE DDIL_ExtKey_Init(DDIL_EXTKEY_INDEX index)
{
    if (index >= DDIL_EXTKEY_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_extKetObject[index].init == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_extKetObject[index].init();
}

/*获取状态,立即返回*/

/**
* Function:
*  DDIL_ERROR_CODE DDIL_ExtKey_GetStatus(DDIL_EXTKEY_INDEX index, DDIL_EXTKEY_STATUS* status)
*
* Brief:
*      Ddil extent key get status.
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

DDIL_ERROR_CODE DDIL_ExtKey_GetStatus(DDIL_EXTKEY_INDEX index, DDIL_EXTKEY_STATUS* status)
{
    if (index >= DDIL_EXTKEY_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_extKetObject[index].getStatus == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_extKetObject[index].getStatus(status);
}

/*等待状态,直到等待到指定的状态才返回*/

/**
* Function:
*  DDIL_ERROR_CODE DDIL_ExtKey_WaitStatus(DDIL_EXTKEY_INDEX index, DDIL_EXTKEY_STATUS status)
*
* Brief:
*      Ddil extent key wait status.
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

DDIL_ERROR_CODE DDIL_ExtKey_WaitStatus(DDIL_EXTKEY_INDEX index, DDIL_EXTKEY_STATUS status)
{
    if (index >= DDIL_EXTKEY_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_extKetObject[index].waitStatus == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_extKetObject[index].waitStatus(status);
}