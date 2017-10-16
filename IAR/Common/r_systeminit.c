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
* Filename:	        r_systeminit.c
* Abstract:	        This file implements system initializing function.
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
#include "r_cg_port.h"
#include "r_cg_intc.h"
#include "r_cg_serial.h"
#include "r_cg_it.h"
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
**	This function initializes every macro.
**
**  Parameters:
**	None
**
**  Returns:
**	None
**
**-----------------------------------------------------------------------------
*/
void R_Systeminit(void)
{
	PIOR = 0x00U;
	R_CGC_Get_ResetSource();
	R_PORT_Create();
	R_CGC_Create();
	R_SAU0_Create();
	R_IT_Create();
	R_INTC_Create();
	CRC0CTL = 0x00U;
	IAWCTL = 0x00U;
}

/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**	This function initializes hardware setting.
**
**  Parameters:
**	None
**
**  Returns:
**	None
**
**-----------------------------------------------------------------------------
*/
int __low_level_init(void)
{
	__disable_interrupt();
	R_Systeminit();
	__enable_interrupt();
        
       return (1U); 
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
