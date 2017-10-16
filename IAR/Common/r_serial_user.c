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
* Filename: CG_serial_user.c
* Abstract: This file implements device driver for Serial module.
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
#include "r_cg_serial.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/*
*******************************************************************************
**  Global define
*******************************************************************************
*/
extern volatile UCHAR   *gpUart0TxAddress;  /* uart0 transmit buffer address */
extern volatile USHORT  gUart0TxCnt;        /* uart0 transmit data number */
extern volatile UCHAR   *gpUart0RxAddress;  /* uart0 receive buffer address */
extern volatile USHORT  gUart0RxCnt;        /* uart0 receive data number */
extern volatile USHORT  gUart0RxLen;        /* uart0 receive data length */
extern volatile UCHAR   *gpCsi10RxAddress;  /* csi10 receive buffer address */
extern volatile USHORT  gCsi10RxLen;        /* csi10 receive data length */
extern volatile USHORT  gCsi10RxCnt;        /* csi10 receive data count */
extern volatile UCHAR   *gpCsi10TxAddress;  /* csi10 send buffer address */
extern volatile USHORT  gCsi10TxLen;        /* csi10 send data length */
extern volatile USHORT  gCsi10TxCnt;        /* csi10 send data count */
extern volatile UCHAR   gIica0MasterStatusFlag; /* iica0 master flag */
extern volatile UCHAR   gIica0SlaveStatusFlag;  /* iica0 slave flag */
extern volatile UCHAR   *gpIica0RxAddress;  /* iica0 receive buffer address */
extern volatile USHORT  gIica0RxCnt;        /* iica0 receive data length */
extern volatile USHORT  gIica0RxLen;        /* iica0 receive data count */
extern volatile UCHAR   *gpIica0TxAddress;  /* iica0 send buffer address */
extern volatile USHORT  gIica0TxCnt;        /* iica0 send data count */
/* Start user code for global. Do not edit comment generated here */
volatile UCHAR G_UART_SendingData = 0;
volatile UCHAR G_UART_ReceivingData = 0;
volatile UCHAR G_SPI_SendingData = 0;
volatile UCHAR G_SPI_ReceivingData = 0;
volatile UCHAR G_IIC_SendingData = 0;
volatile UCHAR G_IIC_ReceivingData = 0;
/* End user code. Do not edit comment generated here */

/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is INTSR0 interrupt service routine.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
#pragma vector = INTSR0_vect
__interrupt void R_MD_INTSR0(void)
{
    UCHAR rx_data;

    rx_data = RXD0;
    if (gUart0RxLen > gUart0RxCnt)
    {
        *gpUart0RxAddress = rx_data;
        gpUart0RxAddress++;
        gUart0RxCnt++;
        if (gUart0RxLen == gUart0RxCnt)
        {
            R_UART0_ReceiveEndCallback();
        }
    }
    else
    {
        R_UART0_SoftOverRunCallback(rx_data);
    }
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is INTSRE0 interrupt service routine.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
#pragma vector = INTSRE0_vect
__interrupt void R_MD_INTSRE0(void)
{
    UCHAR err_type;

    *gpUart0RxAddress = RXD0;
    err_type = (UCHAR)(SSR01 & 0x0007U);
    SIR01 = (USHORT)err_type;
    R_UART0_ErrorCallback(err_type);
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is INTST0 interrupt service routine.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
#pragma vector = INTST0_vect
__interrupt void R_MD_INTST0(void)
{
    if (gUart0TxCnt > 0U)
    {
        TXD0 = *gpUart0TxAddress;
        gpUart0TxAddress++;
        gUart0TxCnt--;
    }
    else
    {
        R_UART0_SendEndCallback();
    }
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when UART0 finishes reception.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_UART0_ReceiveEndCallback(void)
{
    /* Start user code. Do not edit comment generated here */
    G_UART_ReceivingData = 0;
    /* End user code. Do not edit comment generated here */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when UART0 receives an overflow data.
**
**  Parameters:
**  rx_data: receive data
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_UART0_SoftOverRunCallback(UCHAR rx_data)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when UART0 finishes transmission.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_UART0_SendEndCallback(void)
{
    /* Start user code. Do not edit comment generated here */
    G_UART_SendingData = 0;
    /* End user code. Do not edit comment generated here */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when UART0 reception error occurs.
**
**  Parameters:
**  err_type: error type value
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_UART0_ErrorCallback(UCHAR err_type)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is INTCSI10 interrupt service routine.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
#pragma vector = INTCSI10_vect
__interrupt void R_MD_INTCSI10(void)
{
    UCHAR err_type;

    err_type = (UCHAR)(SSR02 & _0001_SAU_OVERRUN_ERROR);
    SIR02 = (USHORT)err_type;
    if (err_type == 1U)
    {
        R_CSI10_ErrorCallback(err_type);    /* overrun error occurs */
    }
    else
    {
        if (gCsi10TxCnt > 0U)
        {
            *gpCsi10RxAddress = SIO10;
            gpCsi10RxAddress++;
            SIO10 = *gpCsi10TxAddress;
            gpCsi10TxAddress++;
            gCsi10TxCnt--;
        }
        else
        {
            if (gCsi10TxCnt == 0U)
            {
                *gpCsi10RxAddress = SIO10;
            }
            R_CSI10_SendEndCallback();  /* complete send */
            R_CSI10_ReceiveEndCallback();   /* complete receive */
        }
    }
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when CSI10 finishes reception.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_CSI10_ReceiveEndCallback(void)
{
    /* Start user code. Do not edit comment generated here */
    G_SPI_ReceivingData = 0;
    /* End user code. Do not edit comment generated here */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when CSI10 reception error occurs.
**
**  Parameters:
**  err_type: error type value
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_CSI10_ErrorCallback(UCHAR err_type)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when CSI10 finishes transmission.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_CSI10_SendEndCallback(void)
{
    /* Start user code. Do not edit comment generated here */
    G_SPI_SendingData = 0;
    /* End user code. Do not edit comment generated here */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is INTIICA0 interrupt service routine.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
#pragma vector = INTIICA0_vect
__interrupt void R_MD_INTIICA0(void)
{
    if ((IICS0 & _80_IICA_STATUS_MASTER) == 0x80U)
    {
        R_IICA0_MasterHandler();
    }
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is IICA0 master handler.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_IICA0_MasterHandler(void)
{
    /* Control for communication */
    if ((IICBSY0 == 0U) && (gIica0TxCnt != 0U))
    {
        R_IICA0_MasterErrorCallback(MD_SPT);
    }
    /* Control for sended address */
    else
    {
        if ((gIica0MasterStatusFlag & _80_IICA_ADDRESS_COMPLETE) == 0U)
        {
            if (ACKD0 == 1U)
            {
                gIica0MasterStatusFlag |= _80_IICA_ADDRESS_COMPLETE;
                if (TRC0 == 1U)
                {
                    WTIM0 = 1U;
                    if (gIica0TxCnt > 0U)
                    {
                        IICA0 = *gpIica0TxAddress;
                        gpIica0TxAddress++;
                        gIica0TxCnt--;
                    }
                    else
                    {
                        R_IICA0_MasterSendEndCallback();
                    }
                }
                else
                {
                    ACKE0 = 1U;
                    WTIM0 = 0U;
                    WREL0 = 1U;
                }
            }
            else
            {
                R_IICA0_MasterErrorCallback(MD_NACK);
            }
        }
        else
        {
            /* Master send control */
            if (TRC0 == 1U)
            {
                if ((ACKD0 == 0U) && (gIica0TxCnt != 0U))
                {
                    R_IICA0_MasterErrorCallback(MD_NACK);
                }
                else
                {
                    if (gIica0TxCnt > 0U)
                    {
                        IICA0 = *gpIica0TxAddress;
                        gpIica0TxAddress++;
                        gIica0TxCnt--;
                    }
                    else
                    {
                        R_IICA0_MasterSendEndCallback();
                    }
                }
            }
            /* Master receive control */
            else
            {
                if (gIica0RxCnt < gIica0RxLen)
                {
                    *gpIica0RxAddress = IICA0;
                    gpIica0RxAddress++;
                    gIica0RxCnt++;
                    if (gIica0RxCnt == gIica0RxLen)
                    {
                        ACKE0 = 0U;
                        WREL0 = 1U;
                        WTIM0 = 1U;
                    }
                    else
                    {
                        WREL0 = 1U;
                    }
                }
                else
                {
                    R_IICA0_MasterReceiveEndCallback();
                }
            }
        }
    }
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when IICA0 master error occurs.
**
**  Parameters:
**  flag: status flag
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_IICA0_MasterErrorCallback(MD_STATUS flag)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when IICA0 finishes master reception.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_IICA0_MasterReceiveEndCallback(void)
{
    SPT0 = 1U;
    /* Start user code. Do not edit comment generated here */
    G_IIC_ReceivingData = 0;
    /* End user code. Do not edit comment generated here */
}
/*
**-----------------------------------------------------------------------------
**
**  Abstract:
**  This function is a callback function when IICA0 finishes master transmission.
**
**  Parameters:
**  None
**
**  Returns:
**  None
**
**-----------------------------------------------------------------------------
*/
void R_IICA0_MasterSendEndCallback(void)
{
    SPT0 = 1U;
    /* Start user code. Do not edit comment generated here */
    G_IIC_SendingData = 0;
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
