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
* Filename:	        r_main.c
* Abstract:	        This file implements main function.
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
/* Following header file provides useful macros and function prototypes for
   controlling the LCD interface. */
#include "lcd.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/*
*******************************************************************************
**  Global define
*******************************************************************************
*/
/* Start user code for global. Do not edit comment generated here */
/* Set option bytes */
#pragma location = "OPTBYTE"
__root const UCHAR opbyte0 = 0xEFU;
#pragma location = "OPTBYTE"
__root const UCHAR opbyte1 = 0x35U;
#pragma location = "OPTBYTE"
__root const UCHAR opbyte2 = 0xE8U;   
#pragma location = "OPTBYTE"
__root const UCHAR opbyte3 = 0x84U;

/* Set security ID */
#pragma location = "SECUID"
__root const UCHAR secuid[10] = 
	{0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU};

/* Declare serial data output buffer */
uint8_t _SerialDataOut[] = "0123456789\r\n";		

/* End user code. Do not edit comment generated here */

/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**	This function implements main function.
**
**  Parameters:
**	None
**
**  Returns:
**	None
**
**-----------------------------------------------------------------------------
*/
void main(void)
{
	/* Start user code. Do not edit comment generated here */

	/* Initialise the LCD module. */
	InitialiseDisplay();

	/* Display Renesas Splash Screen. */
	LCDStringLinePos("SAU in async mode", 0, 4);
	LCDStringLinePos("1)Connect serial", 0, 5);
	LCDStringLinePos("2)Open a terminal", 0, 6);
	LCDStringLinePos("3)Baud=19,200", 0, 7);
	LCDStringLinePos("4)Type z/Z to pause", 0, 8);/* Edited O.G. 11/15/11 */

	/* Enable UART0 operations */
	R_UART0_Start();	

	/* Start the Interval Timer */
	R_IT_Start();

	/* Halt program in an infinite while loop */
	while (1U)
	{
        NOP();
        //delay_ms(50); /* Leave some room for the system to respond */
	}
	/* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
