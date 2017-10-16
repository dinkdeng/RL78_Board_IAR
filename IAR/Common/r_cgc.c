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
* Filename:	        r_cgc.c
* Abstract:	        This file implements device driver for CGC module.
* APIlib:               CodeGenerator for RL78/G13 V1.01.00 [31 May 2011]
* Device:               R5F100LE
* Compiler:             ICCRL78
* Creation date:	05/07/2011
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
#include "r_cg_cgc.h"
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
**	This function initializes the clock generator.
**
**  Parameters:
**	None
**
**  Returns:
**	None
**
**-----------------------------------------------------------------------------
*/
void R_CGC_Create(void)
{
	/* Set fMX */
	CMC = _00_CG_HISYS_PORT | _00_CG_SUB_PORT | _00_CG_SYSOSC_DEFAULT | _00_CG_SUBMODE_DEFAULT;
	MSTOP = 1U;
	/* Set fMAIN */
	MCM0 = 0U;
	/* Set fSUB */
	XTSTOP = 1U;
	OSMC = _10_CG_RTC_CLK_FIL;
	/* Set fCLK */
	CSS = 0U;
	/* Set fIH */
	HIOSTOP = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
