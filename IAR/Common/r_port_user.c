/*
*******************************************************************************
* Copyright(C) 2011 Renesas Electronics Corporation
* RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY
* This program must be used solely for the purpose for which
* it was furnished by Renesas Electronics Corporation. No part of this
* program may be reproduced or disclosed to others, in any
* form, without the prior written permission of Renesas Electronics
* Corporation.
*
* This device driver was created by Applilet3 for RL78/G13
* 16-Bit Single-Chip Microcontrollers
* Filename: CG_port_user.c
* Abstract: This file implements device driver for PORT module.
* APIlib:   Applilet3 for RL78/G13 E1.00b [14 Jan 2011]
* Device:   R5F100LLAFAB
* Compiler: IAR Systems iccrl78
* Creation date:    8/16/2011
*******************************************************************************
*/

/*
*******************************************************************************
** Include files
*******************************************************************************
*/
#include "r_cg_macrodriver.h"
#include "r_cg_port.h"
/* Start user code for include. Do not edit comment generated here */
#include <stdint.h>
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/*
*******************************************************************************
**  Global define
*******************************************************************************
*/
/* Start user code for global. Do not edit comment generated here */


const T_GPIOPort PORT0 = {
    (unsigned char *)&P0,
    (unsigned char *)&PM0,
};

const T_GPIOPort PORT1 = {
    (unsigned char *)&P1,
    (unsigned char *)&PM1,
};

const T_GPIOPort PORT2 = {
    (unsigned char *)&P2,
    (unsigned char *)&PM2,
};

const T_GPIOPort PORT3 = {
    (unsigned char *)&P3,
    (unsigned char *)&PM3,
};

const T_GPIOPort PORT4 = {
    (unsigned char *)&P4,
    (unsigned char *)&PM4,
};

const T_GPIOPort PORT5 = {
    (unsigned char *)&P5,
    (unsigned char *)&PM5,
};

const T_GPIOPort PORT6 = {
    (unsigned char *)&P6,
    (unsigned char *)&PM6,
};

const T_GPIOPort PORT7 = {
    (unsigned char *)&P7,
    (unsigned char *)&PM7,
};

const T_GPIOPort PORT12 = {
    (unsigned char *)&P12,
    (unsigned char *)&PM12,
};

const T_GPIOPort PORT13 = {
    (unsigned char *)&P13,
    0
};

const T_GPIOPort PORT14 = {
    (unsigned char *)&P14,
    (unsigned char *)&PM14,
};

const T_GPIOPort *GPIOTable[] = {
    &PORT0,
    &PORT1,
    &PORT2,
    &PORT3,
    &PORT4,
    &PORT5,
    &PORT6,
    &PORT7,
    0,
    0,
    0,
    0,
    &PORT12,
    &PORT13,
    &PORT14
};


void R_GPIO_OuputMode(unsigned char aPort, unsigned char aPin)
{
    *GPIOTable[aPort]->iPMn &= ~(1<<aPin);
}

void R_GPIO_SetHigh(unsigned char aPort, unsigned char aPin)
{
    *GPIOTable[aPort]->iPn |= (1<<aPin);
}

void R_GPIO_SetLow(unsigned char aPort, unsigned char aPin)
{
    *GPIOTable[aPort]->iPn &= ~(1<<aPin);
}

void R_GPIO_Toggle(unsigned char aPort, unsigned char aPin)
{
    *GPIOTable[aPort]->iPn ^= (1<<aPin);
}

void R_GPIO_InputMode(unsigned char aPort, unsigned char aPin)
{
    *GPIOTable[aPort]->iPMn |= (1<<aPin);
}

uint8_t R_GPIO_Read(unsigned char aPort, unsigned char aPin)
{
    return (*GPIOTable[aPort]->iPn & (1<<aPin)) >> aPin;
}

/* End user code. Do not edit comment generated here */


/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
