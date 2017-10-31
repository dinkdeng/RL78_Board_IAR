#include "DDIL_Beep.h"

/**
* Brief:
*      The ddil beep object[ ddil beep num].
*/

static DDIL_BEEP_STRUCT DDIL_beepObject[DDIL_BEEP_NUM] = { 0 };

/*驱动注册*/

/**
* Function:
*  DDIL_ERROR_CODE DDIL_Beep_Register(DDIL_BEEP_INDEX index, DDIL_BeepInit_FuncPtr init,
*  DDIL_BeepSet_FuncPtr set)
*
* Brief:
*      Ddil beep register.
*
* Author:
*      Dink
*
* Date:
*      2017/10/16
*
* Param:
*  index -     Zero-based index of the.
*  init -      The init.
*  set -       The set.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_Beep_Register(DDIL_BEEP_INDEX index, DDIL_BeepInit_FuncPtr init,
    DDIL_BeepSet_FuncPtr set)
{
    if (index >= DDIL_BEEP_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    DDIL_beepObject[index].init = init;
    DDIL_beepObject[index].set = set;
    return DDIL_ERROR_NONE;
}

/*蜂鸣器初始化*/

/**
* Function:        DDIL_ERROR_CODE DDIL_Beep_Init(DDIL_BEEP_INDEX index, DDIL_BEEP_STATUS initStatus)
*
* Brief:
*      Ddil beep init.
*
* Author:
*      Dink
*
* Date:
*      2017/10/16
*
* Param:
*  index -         Zero-based index of the.
*  initStatus -    The init status.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_Beep_Init(DDIL_BEEP_INDEX index, DDIL_BEEP_STATUS initStatus)
{
    if (index >= DDIL_BEEP_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_beepObject[index].init == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_beepObject[index].init(initStatus);
}

/*蜂鸣器设置指定状态*/

/**
* Function:        DDIL_ERROR_CODE DDIL_Beep_Set(DDIL_BEEP_INDEX index, DDIL_BEEP_STATUS setStatus)
*
* Brief:
*      Ddil beep set.
*
* Author:
*      Dink
*
* Date:
*      2017/10/16
*
* Param:
*  index -         Zero-based index of the.
*  setStatus -     The set status.
*
* Returns:
*      A DDIL_ERROR_CODE.
*/

DDIL_ERROR_CODE DDIL_Beep_Set(DDIL_BEEP_INDEX index, DDIL_BEEP_STATUS setStatus)
{
    if (index >= DDIL_BEEP_NUM)
        return DDIL_ERROR_NUM_LIMIT;
    if (DDIL_beepObject[index].set == NULL)
        return DDIL_ERROR_FUNC_NULL;
    return DDIL_beepObject[index].set(setStatus);
}


