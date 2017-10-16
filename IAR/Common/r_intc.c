/*
*******************************************************************************
* Copyright(C) 2010, 2011 Renesas Electronics Corporation
* RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY
* This program must be used solely for the purpose for which
* it was furnished by Renesas Electronics Corporation. No part of this
* program may be reproduced or disclosed to others, in any
* form, without the prior written permission of Renesas Electronics
* Corporation.
*
* This device driver was created by CodeGenerator for RL78/G13
* 16-Bit Single-Chip Microcontrollers
* Filename:         r_intc.c
* Abstract:         This file implements device driver for INTC module.
* APIlib:           CodeGenerator for RL78/G13 V1.01.00 [31 May 2011]
* Device:           R5F100LLAFAB
* Compiler:         ICCRL78
* Creation date:    05/07/2011
*******************************************************************************
*/

/*
*******************************************************************************
** Pragma directive
*******************************************************************************
*/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
/*
*******************************************************************************
** Include files
*******************************************************************************
*/
#include "r_cg_macrodriver.h"
#include "r_cg_intc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/*
*******************************************************************************
**  Global define
*******************************************************************************
*/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function initializes INTP module.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_INTC_Create(void)
{
    PMK0 = 1U;  /* disable INTP0 operation */
    PIF0 = 0U;  /* clear INTP0 interrupt flag */
    PMK1 = 1U;  /* disable INTP1 operation */
    PIF1 = 0U;  /* clear INTP1 interrupt flag */
    PMK2 = 1U;  /* disable INTP2 operation */
    PIF2 = 0U;  /* clear INTP2 interrupt flag */
    PMK3 = 1U;  /* disable INTP3 operation */
    PIF3 = 0U;  /* clear INTP3 interrupt flag */
    PMK4 = 1U;  /* disable INTP4 operation */
    PIF4 = 0U;  /* clear INTP4 interrupt flag */
    PMK5 = 1U;  /* disable INTP5 operation */
    PIF5 = 0U;  /* clear INTP5 interrupt flag */
    PMK6 = 1U;  /* disable INTP6 operation */
    PIF6 = 0U;  /* clear INTP6 interrupt flag */
    PMK7 = 1U;  /* disable INTP7 operation */
    PIF7 = 0U;  /* clear INTP7 interrupt flag */
    PMK8 = 1U;  /* disable INTP8 operation */
    PIF8 = 0U;  /* clear INTP8 interrupt flag */
    PMK9 = 1U;  /* disable INTP9 operation */
    PIF9 = 0U;  /* clear INTP9 interrupt flag */
    PMK10 = 1U; /* disable INTP10 operation */
    PIF10 = 0U; /* clear INTP10 interrupt flag */
    PMK11 = 1U; /* disable INTP11 operation */
    PIF11 = 0U; /* clear INTP11 interrupt flag */
    /* Set INTP0 level 1 priority */
    PPR10 = 0U;
    PPR00 = 1U;
    /* Set INTP1 level 1 priority */
    PPR11 = 0U;
    PPR01 = 1U;
    /* Set INTP2 level 1 priority */
    PPR12 = 0U;
    PPR02 = 1U;
    EGN0 = _01_INTP0_EDGE_FALLING_SEL | _02_INTP1_EDGE_FALLING_SEL | _04_INTP2_EDGE_FALLING_SEL;
        /* Set INTP1 pin */
    PM5 |= 0x01U;
        /* Set INTP2 pin */
    PM5 |= 0x02U;
        /* Set INTP4 pin */
    PM3 |= 0x02U;
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function clears INTP1 interrupt flag and enables interrupt.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_INTC1_Start(void)
{
    PIF1 = 0U;  /* clear INTP1 interrupt flag */
    PMK1 = 0U;  /* enable INTP1 interrupt */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function disables INTP1 interrupt and clears interrupt flag.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_INTC1_Stop(void)
{
    PMK1 = 1U;  /* disable INTP1 interrupt */
    PIF1 = 0U;  /* clear INTP1 interrupt flag */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function clears INTP2 interrupt flag and enables interrupt.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_INTC2_Start(void)
{
    PIF2 = 0U;  /* clear INTP2 interrupt flag */
    PMK2 = 0U;  /* enable INTP2 interrupt */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function disables INTP2 interrupt and clears interrupt flag.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_INTC2_Stop(void)
{
    PMK2 = 1U;  /* disable INTP2 interrupt */
    PIF2 = 0U;  /* clear INTP2 interrupt flag */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function clears INTP0 interrupt flag and enables interrupt.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_INTC0_Start(void)
{
    PIF0 = 0U;  /* clear INTP0 interrupt flag */
    PMK0 = 0U;  /* enable INTP0 interrupt */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function disables INTP0 interrupt and clears interrupt flag.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_INTC0_Stop(void)
{
    PMK0 = 1U;  /* disable INTP0 interrupt */
    PIF0 = 0U;  /* clear INTP0 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
