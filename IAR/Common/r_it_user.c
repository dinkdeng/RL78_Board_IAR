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
* Filename: CG_it_user.c
* Abstract: This file implements device driver for IT module.
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
#include "r_cg_it.h"
#include "r_cg_serial.h"
#include "r_cg_port.h"
#include "r_cg_userdefine.h"
/* Start user code for include. Do not edit comment generated here */
volatile int G_msTimer = 0;   // Timer Counter
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/* uart0 receive buffer address */
extern volatile uint8_t  *gpUart0RxAddress;

/* Declare and initialise a variable used for counting from 0-9 */
volatile uint8_t _count = 0;

/* Null terminated buffer containing serial data to be transmitted */
extern uint8_t _SerialDataOut[];
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
**  This function is INTIT interrupt service routine.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
#pragma vector = INTIT_vect
__interrupt void R_MD_INTIT(void)
{
    /* Start user code. Do not edit comment generated here */
    /* Check the received character */
    if(RXD0 == 'z')
    {
        /* Turn off LED 0 to indicate halt to serial data output */
        LED_OFF(0);

        /* Turn on LED1 */
        LED_ON(1);
    }
    else
    {
        /* Transmit the data */
        R_UART0_SendData(&_SerialDataOut[_count++], 1);

        /* Reset the count after transmitting all data in the buffer */
        if(_count == 12)
        {
            _count = 0;
        }

        /* Turn on LED 0 to indicate serial data output */
        LED_ON(0);

        /* Turn off LED1 */
        LED_OFF(1);
    }

    /* Clear IT interrupt flag */
    ITIF = 0;

    G_msTimer++;
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */

/*---------------------------------------------------------------------------*
 * delay_ms
 *---------------------------------------------------------------------------
 * Description:
 *      Uses the interval timer to delay so many milliseconds
 * Inputs:
 *      aTimeMS - milliseconds to delay
 *---------------------------------------------------------------------------*/
void delay_ms(int aTimeMS)
{
    G_msTimer = 0;
    R_IT_Start();
    while(G_msTimer < aTimeMS);
    R_IT_Stop();
}

/* End user code. Do not edit comment generated here */
