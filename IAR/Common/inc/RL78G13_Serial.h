#ifndef __RL78G13_SERIAL_H_
#define __RL78G13_SERIAL_H_
#include "MacroDriver.h"

#define _0000_SAU_CK00_FCLK_0            (0x0000U)    /* ck00 - fCLK */
#define _0001_SAU_CK00_FCLK_1            (0x0001U)    /* ck00 - fCLK/2^1 */
#define _0002_SAU_CK00_FCLK_2            (0x0002U)    /* ck00 - fCLK/2^2 */
#define _0003_SAU_CK00_FCLK_3            (0x0003U)    /* ck00 - fCLK/2^3 */
#define _0004_SAU_CK00_FCLK_4            (0x0004U)    /* ck00 - fCLK/2^4 */
#define _0005_SAU_CK00_FCLK_5            (0x0005U)    /* ck00 - fCLK/2^5 */
#define _0006_SAU_CK00_FCLK_6            (0x0006U)    /* ck00 - fCLK/2^6 */
#define _0007_SAU_CK00_FCLK_7            (0x0007U)    /* ck00 - fCLK/2^7 */
#define _0008_SAU_CK00_FCLK_8            (0x0008U)    /* ck00 - fCLK/2^8 */
#define _0009_SAU_CK00_FCLK_9            (0x0009U)    /* ck00 - fCLK/2^9 */
#define _000A_SAU_CK00_FCLK_10           (0x000AU)    /* ck00 - fCLK/2^10 */
#define _000B_SAU_CK00_FCLK_11           (0x000BU)    /* ck00 - fCLK/2^11 */
#define _000C_SAU_CK00_FCLK_12           (0x000CU)    /* ck00 - fCLK/2^12 */
#define _000D_SAU_CK00_FCLK_13           (0x000DU)    /* ck00 - fCLK/2^13 */
#define _000E_SAU_CK00_FCLK_14           (0x000EU)    /* ck00 - fCLK/2^14 */
#define _000F_SAU_CK00_FCLK_15           (0x000FU)    /* ck00 - fCLK/2^15 */
/* Operating mode and clear mode selection (PRS013 - PRS010) */
#define _0000_SAU_CK01_FCLK_0            (0x0000U)    /* ck01 - fCLK */
#define _0010_SAU_CK01_FCLK_1            (0x0010U)    /* ck01 - fCLK/2^1 */
#define _0020_SAU_CK01_FCLK_2            (0x0020U)    /* ck01 - fCLK/2^2 */
#define _0030_SAU_CK01_FCLK_3            (0x0030U)    /* ck01 - fCLK/2^3 */
#define _0040_SAU_CK01_FCLK_4            (0x0040U)    /* ck01 - fCLK/2^4 */
#define _0050_SAU_CK01_FCLK_5            (0x0050U)    /* ck01 - fCLK/2^5 */
#define _0060_SAU_CK01_FCLK_6            (0x0060U)    /* ck01 - fCLK/2^6 */
#define _0070_SAU_CK01_FCLK_7            (0x0070U)    /* ck01 - fCLK/2^7 */
#define _0080_SAU_CK01_FCLK_8            (0x0080U)    /* ck01 - fCLK/2^8 */
#define _0090_SAU_CK01_FCLK_9            (0x0090U)    /* ck01 - fCLK/2^9 */
#define _00A0_SAU_CK01_FCLK_10           (0x00A0U)    /* ck01 - fCLK/2^10 */
#define _00B0_SAU_CK01_FCLK_11           (0x00B0U)    /* ck01 - fCLK/2^11 */
#define _00C0_SAU_CK01_FCLK_12           (0x00C0U)    /* ck01 - fCLK/2^12 */
#define _00D0_SAU_CK01_FCLK_13           (0x00D0U)    /* ck01 - fCLK/2^13 */
#define _00E0_SAU_CK01_FCLK_14           (0x00E0U)    /* ck01 - fCLK/2^14 */
#define _00F0_SAU_CK01_FCLK_15           (0x00F0U)    /* ck01 - fCLK/2^15 */

/*
    Serial Mode Register mn (SMRmn)
*/
#define _0020_SAU_SMRMN_INITIALVALUE     (0x0020U)
/* Selection of macro clock (MCK) of channel n (CKSmn) */
#define _0000_SAU_CLOCK_SELECT_CK00      (0x0000U)    /* operation clock CK0 set by PRS register */
#define _8000_SAU_CLOCK_SELECT_CK01      (0x8000U)    /* operation clock CK1 set by PRS register */
/* Selection of transfer clock (TCLK) of channel n (CCSmn) */
#define _0000_SAU_CLOCK_MODE_CKS         (0x0000U)    /* divided operation clock MCK specified by CKSmn bit */
#define _4000_SAU_CLOCK_MODE_TI0N        (0x4000U)    /* clock input from SCK pin (slave transfer in CSI mode) */
/* Selection of start trigger source (STSmn) */
#define _0000_SAU_TRIGGER_SOFTWARE       (0x0000U)    /* only software trigger is valid */
#define _0100_SAU_TRIGGER_RXD            (0x0100U)    /* valid edge of RXD pin */
/* Controls inversion of level of receive data of channel n in UART mode (SISmn0) */
#define _0000_SAU_EDGE_FALL              (0x0000U)    /* falling edge is detected as the start bit */
#define _0040_SAU_EDGE_RISING            (0x0040U)    /* rising edge is detected as the start bit */
/* Setting of operation mode of channel n (MDmn2, MDmn1) */
#define _0000_SAU_MODE_CSI               (0x0000U)    /* CSI mode */
#define _0002_SAU_MODE_UART              (0x0002U)    /* UART mode */
#define _0004_SAU_MODE_IIC               (0x0004U)    /* simplified IIC mode */
/* Selection of interrupt source of channel n (MDmn0) */
#define _0000_SAU_TRANSFER_END           (0x0000U)    /* transfer end interrupt */
#define _0001_SAU_BUFFER_EMPTY           (0x0001U)    /* buffer empty interrupt */

/*
    Serial Communication Operation Setting Register mn (SCRmn)
*/
/* Setting of operation mode of channel n (TXEmn, RXEmn) */
#define _0000_SAU_NOT_COMMUNICATION      (0x0000U)    /* does not start communication */
#define _4000_SAU_RECEPTION              (0x4000U)    /* reception only */
#define _8000_SAU_TRANSMISSION           (0x8000U)    /* transmission only */
#define _C000_SAU_RECEPTION_TRANSMISSION (0xC000U)    /* reception and transmission */
/* Selection of data and clock phase in CSI mode (DAPmn, CKPmn) */
#define _0000_SAU_TIMING_1               (0x0000U)    /* type 1 */
#define _1000_SAU_TIMING_2               (0x1000U)    /* type 2 */
#define _2000_SAU_TIMING_3               (0x2000U)    /* type 3 */
#define _3000_SAU_TIMING_4               (0x3000U)    /* type 4 */
/* Selection of masking of error interrupt signal (EOCmn) */
#define _0000_SAU_INTSRE_MASK            (0x0000U)    /* masks error interrupt INTSREx */
#define _0400_SAU_INTSRE_ENABLE          (0x0400U)    /* enables generation of error interrupt INTSREx */
/* Setting of parity bit in UART mode (PTCmn1 - PTCmn0) */
#define _0000_SAU_PARITY_NONE            (0x0000U)    /* none parity */
#define _0100_SAU_PARITY_ZERO            (0x0100U)    /* zero parity */
#define _0200_SAU_PARITY_EVEN            (0x0200U)    /* even parity */
#define _0300_SAU_PARITY_ODD             (0x0300U)    /* odd parity */
/* Selection of data transfer sequence in CSI and UART modes (DIRmn) */
#define _0000_SAU_MSB                    (0x0000U)    /* MSB */
#define _0080_SAU_LSB                    (0x0080U)    /* LSB */
/* Setting of stop bit in UART mode (SLCmn1, SLCmn0) */
#define _0000_SAU_STOP_NONE              (0x0000U)    /* none stop bit */
#define _0010_SAU_STOP_1                 (0x0010U)    /* 1 stop bit */
#define _0020_SAU_STOP_2                 (0x0020U)    /* 2 stop bits */
/* Setting of data length in CSI and UART modes (DLSmn2 - DLSmn0) */
#define _0005_SAU_LENGTH_9               (0x0005U)    /* 9-bit data length */
#define _0006_SAU_LENGTH_7               (0x0006U)    /* 7-bit data length */
#define _0007_SAU_LENGTH_8               (0x0007U)    /* 8-bit data length */

/*
    Serial Output Level Register m (SOLm)
*/
/* Selects inversion of the level of the transmit data of channel n in UART mode */
#define _0000_SAU_CHANNEL0_NORMAL        (0x0000U)    /* normal bit level */
#define _0001_SAU_CHANNEL0_INVERTED      (0x0001U)    /* inverted bit level */
#define _0000_SAU_CHANNEL1_NORMAL        (0x0000U)    /* normal bit level */
#define _0002_SAU_CHANNEL1_INVERTED      (0x0002U)    /* inverted bit level */
#define _0000_SAU_CHANNEL2_NORMAL        (0x0000U)    /* normal bit level */
#define _0004_SAU_CHANNEL2_INVERTED      (0x0004U)    /* inverted bit level */
#define _0000_SAU_CHANNEL3_NORMAL        (0x0000U)    /* normal bit level */
#define _0008_SAU_CHANNEL3_INVERTED      (0x0008U)    /* inverted bit level */

/*
    Noise Filter Enable Register 0 (NFEN0)
*/
/* Use of noise filter */
#define _00_SAU_RXD3_FILTER_OFF          (0x00U)      /* noise filter off */
#define _40_SAU_RXD3_FILTER_ON           (0x40U)      /* noise filter on */
#define _00_SAU_RXD2_FILTER_OFF          (0x00U)      /* noise filter off */
#define _10_SAU_RXD2_FILTER_ON           (0x10U)      /* noise filter on */
#define _00_SAU_RXD1_FILTER_OFF          (0x00U)      /* noise filter off */
#define _04_SAU_RXD1_FILTER_ON           (0x04U)      /* noise filter on */
#define _00_SAU_RXD0_FILTER_OFF          (0x00U)      /* noise filter off */
#define _01_SAU_RXD0_FILTER_ON           (0x01U)      /* noise filter on */

/*
    Format of Serial Status Register mn (SSRmn)
*/
/* Communication status indication flag of channel n (TSFmn) */
#define _0040_SAU_UNDER_EXECUTE          (0x0040U)    /* communication is under execution */
/* Buffer register status indication flag of channel n (BFFmn) */
#define _0020_SAU_VALID_STORED           (0x0020U)    /* valid data is stored in the SDRmn register */
/* Framing error detection flag of channel n (FEFmn) */
#define _0004_SAU_FRAM_ERROR             (0x0004U)    /* a framing error occurs during UART reception */
/* Parity error detection flag of channel n (PEFmn) */
#define _0002_SAU_PARITY_ERROR           (0x0002U)    /* a parity error occurs or ACK is not detected */
/* Overrun error detection flag of channel n (OVFmn) */
#define _0001_SAU_OVERRUN_ERROR          (0x0001U)    /* an overrun error occurs */

/*
    Serial Channel Start Register m (SSm)
*/
/* Operation start trigger of channel 0 (SSm0) */
#define _0000_SAU_CH0_START_TRG_OFF      (0x0000U)    /* no trigger operation */
#define _0001_SAU_CH0_START_TRG_ON       (0x0001U)    /* sets SEm0 to 1 and enters the communication wait status */
/* Operation start trigger of channel 1 (SSm1) */
#define _0000_SAU_CH1_START_TRG_OFF      (0x0000U)    /* no trigger operation */
#define _0002_SAU_CH1_START_TRG_ON       (0x0002U)    /* sets SEm1 to 1 and enters the communication wait status */
/* Operation start trigger of channel 2 (SSm2) */
#define _0000_SAU_CH2_START_TRG_OFF      (0x0000U)    /* no trigger operation */
#define _0004_SAU_CH2_START_TRG_ON       (0x0004U)    /* sets SEm2 to 1 and enters the communication wait status */
/* Operation start trigger of channel 3 (SSm3) */
#define _0000_SAU_CH3_START_TRG_OFF      (0x0000U)    /* no trigger operation */
#define _0008_SAU_CH3_START_TRG_ON       (0x0008U)    /* sets SEm3 to 1 and enters the communication wait status */

/*
    Serial Channel Stop Register m (STm)
*/
/* Operation stop trigger of channel 0 (STm0) */
#define _0000_SAU_CH0_STOP_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0001_SAU_CH0_STOP_TRG_ON        (0x0001U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 (STm1) */
#define _0000_SAU_CH1_STOP_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0002_SAU_CH1_STOP_TRG_ON        (0x0002U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 2 (STm2) */
#define _0000_SAU_CH2_STOP_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0004_SAU_CH2_STOP_TRG_ON        (0x0004U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 3 (STm3) */
#define _0000_SAU_CH3_STOP_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0008_SAU_CH3_STOP_TRG_ON        (0x0008U)    /* operation is stopped (stop trigger is generated) */

/*
    Format of Serial Flag Clear Trigger Register mn (SIRmn)
*/
/* Clear trigger of overrun error flag of channel n (OVCTmn) */
#define _0001_SAU_SIRMN_OVCTMN           (0x0001U)
/* Clear trigger of parity error flag of channel n (PECTmn) */
#define _0002_SAU_SIRMN_PECTMN           (0x0002U)
/* Clear trigger of framing error of channel n (FECTMN) */
#define _0004_SAU_SIRMN_FECTMN           (0x0004U)

/*
    Serial Output Enable Register m (SOEm)
*/
/* Serial output enable/disable of channel 0 (SOEm0) */
#define _0001_SAU_CH0_OUTPUT_ENABLE      (0x0001U)    /* stops output by serial communication operation */
#define _0000_SAU_CH0_OUTPUT_DISABLE     (0x0000U)    /* enables output by serial communication operation */
/* Serial output enable/disable of channel 1 (SOEm1) */
#define _0002_SAU_CH1_OUTPUT_ENABLE      (0x0002U)    /* stops output by serial communication operation */
#define _0000_SAU_CH1_OUTPUT_DISABLE     (0x0000U)    /* enables output by serial communication operation */
/* Serial output enable/disable of channel 2 (SOEm2) */
#define _0004_SAU_CH2_OUTPUT_ENABLE      (0x0004U)    /* stops output by serial communication operation */
#define _0000_SAU_CH2_OUTPUT_DISABLE     (0x0000U)    /* enables output by serial communication operation */
/* Serial output enable/disable of channel 3 (SOEm3) */
#define _0008_SAU_CH3_OUTPUT_ENABLE      (0x0008U)    /* stops output by serial communication operation */
#define _0000_SAU_CH3_OUTPUT_DISABLE     (0x0000U)    /* enables output by serial communication operation */

/*
    Serial Output Register m (SOm)
*/
/* Serial data output of channel 0 (SOm0) */
#define _0000_SAU_CH0_DATA_OUTPUT_0      (0x0000U)    /* Serial data output value is "0" */
#define _0001_SAU_CH0_DATA_OUTPUT_1      (0x0001U)    /* Serial data output value is "1" */
/* Serial data output of channel 1 (SOm1) */
#define _0000_SAU_CH1_DATA_OUTPUT_0      (0x0000U)    /* Serial data output value is "0" */
#define _0002_SAU_CH1_DATA_OUTPUT_1      (0x0002U)    /* Serial data output value is "1" */
/* Serial data output of channel 2 (SOm2) */
#define _0000_SAU_CH2_DATA_OUTPUT_0      (0x0000U)    /* Serial data output value is "0" */
#define _0004_SAU_CH2_DATA_OUTPUT_1      (0x0004U)    /* Serial data output value is "1" */
/* Serial data output of channel 3 (SOm3) */
#define _0000_SAU_CH3_DATA_OUTPUT_0      (0x0000U)    /* Serial data output value is "0" */
#define _0008_SAU_CH3_DATA_OUTPUT_1      (0x0008U)    /* Serial data output value is "1" */
/* Serial clock output of channel 0 (CKOm0) */
#define _0000_SAU_CH0_CLOCK_OUTPUT_0     (0x0000U)    /* Serial clock output value is "0" */
#define _0100_SAU_CH0_CLOCK_OUTPUT_1     (0x0100U)    /* Serial clock output value is "1" */
/* Serial clock output of channel 1 (CKOm1) */
#define _0000_SAU_CH1_CLOCK_OUTPUT_0     (0x0000U)    /* Serial clock output value is "0" */
#define _0200_SAU_CH1_CLOCK_OUTPUT_1     (0x0200U)    /* Serial clock output value is "1" */
/* Serial clock output of channel 2 (CKOm2) */
#define _0000_SAU_CH2_CLOCK_OUTPUT_0     (0x0000U)    /* Serial clock output value is "0" */
#define _0400_SAU_CH2_CLOCK_OUTPUT_1     (0x0400U)    /* Serial clock output value is "1" */
/* Serial clock output of channel 3 (CKOm3) */
#define _0000_SAU_CH3_CLOCK_OUTPUT_0     (0x0000U)    /* Serial clock output value is "0" */
#define _0800_SAU_CH3_CLOCK_OUTPUT_1     (0x0800U)    /* Serial clock output value is "1" */

/*
    SAU Standby Control Register m (SSCm)
*/
/* SAU Standby Wakeup Control Bit (SWC) */
#define _0000_SAU_CH0_SNOOZE_OFF         (0x0000U)    /* disable start function from STOP state of chip */
#define _0001_SAU_CH0_SNOOZE_ON          (0x0001U)    /* enable start function from STOP state of chip */

/* SAU used flag */
#define _00_SAU_IIC_MASTER_FLAG_CLEAR    (0x00U)
#define _01_SAU_IIC_SEND_FLAG            (0x01U)
#define _02_SAU_IIC_RECEIVE_FLAG         (0x02U)
#define _04_SAU_IIC_SENDED_ADDRESS_FLAG  (0x04U)

/*
    Input switch control register (ISC)
*/
/* Channel 0 SSI00 input setting in CSI communication and slave mode (SSIE00) */
#define _00_SAU_SSI00_UNUSED             (0x00U)      /* disables SSI00 pin input */
#define _80_SAU_SSI00_USED               (0x80U)      /* enables SSI00 pin input */

/*
    IICA Control Register (IICCTLn0)
*/
/* IIC operation enable (IICEn) */
#define _00_IICA_OPERATION_DISABLE       (0x00U)    /* stop operation */
#define _80_IICA_OPERATION_ENABLE        (0x80U)    /* enable operation */
/* Exit from communications (LRELn) */
#define _00_IICA_COMMUNICATION_NORMAL    (0x00U)    /* normal operation */
#define _40_IICA_COMMUNICATION_EXIT      (0x40U)    /* exit from current communication */
/* Wait cancellation (WRELn) */
#define _00_IICA_WAIT_NOTCANCEL          (0x00U)    /* do not cancel wait */
#define _20_IICA_WAIT_CANCEL             (0x20U)    /* cancel wait */
/* Generation of interrupt when stop condition (SPIEn) */
#define _00_IICA_STOPINT_DISABLE         (0x00U)    /* disable */
#define _10_IICA_STOPINT_ENABLE          (0x10U)    /* enable */
/* Wait and interrupt generation (WTIMn) */
#define _00_IICA_WAITINT_CLK8FALLING     (0x00U)    /* generated at the eighth clock's falling edge */
#define _08_IICA_WAITINT_CLK9FALLING     (0x08U)    /* generated at the ninth clock's falling edge */
/* Acknowledgement control (ACKEn) */
#define _00_IICA_ACK_DISABLE             (0x00U)    /* disable acknowledgement */
#define _04_IICA_ACK_ENABLE              (0x04U)    /* enable acknowledgement */
/* Start condition trigger (STTn) */
#define _00_IICA_START_NOTGENERATE       (0x00U)    /* do not generate start condition */
#define _02_IICA_START_GENERATE          (0x02U)    /* generate start condition */
/* Stop condition trigger (SPTn) */
#define _00_IICA_STOP_NOTGENERATE        (0x00U)    /* do not generate stop condition */
#define _01_IICA_STOP_GENERATE           (0x01U)    /* generate stop condition */

/*
    IICA Status Register (IICSn)
*/
/* Master device status (MSTSn) */
#define _00_IICA_STATUS_NOTMASTER        (0x00U)    /* slave device status or communication standby status */
#define _80_IICA_STATUS_MASTER           (0x80U)    /* master device communication status */
/* Detection of arbitration loss (ALDn) */
#define _00_IICA_ARBITRATION_NO          (0x00U)    /* arbitration win or no arbitration */
#define _40_IICA_ARBITRATION_LOSS        (0x40U)    /* arbitration loss */
/* Detection of extension code reception (EXCn) */
#define _00_IICA_EXTCODE_NOT             (0x00U)    /* extension code not received */
#define _20_IICA_EXTCODE_RECEIVED        (0x20U)    /* extension code received */
/* Detection of matching addresses (COIn) */
#define _00_IICA_ADDRESS_NOTMATCH        (0x00U)    /* addresses do not match */
#define _10_IICA_ADDRESS_MATCH           (0x10U)    /* addresses match */
/* Detection of transmit/receive status (TRCn) */
#define _00_IICA_STATUS_RECEIVE          (0x00U)    /* receive status */
#define _08_IICA_STATUS_TRANSMIT         (0x08U)    /* transmit status */
/* Detection of acknowledge signal (ACKDn) */
#define _00_IICA_ACK_NOTDETECTED         (0x00U)    /* ACK signal was not detected */
#define _04_IICA_ACK_DETECTED            (0x04U)    /* ACK signal was detected */
/* Detection of start condition (STDn) */
#define _00_IICA_START_NOTDETECTED       (0x00U)    /* start condition not detected */
#define _02_IICA_START_DETECTED          (0x02U)    /* start condition detected */
/* Detection of stop condition (SPDn) */
#define _00_IICA_STOP_NOTDETECTED        (0x00U)    /* stop condition not detected */
#define _01_IICA_STOP_DETECTED           (0x01U)    /* stop condition detected */

/*
    IICA Flag Register (IICFn)
*/
/* STT clear flag (STCFn) */
#define _00_IICA_STARTFLAG_GENERATE      (0x00U)    /* generate start condition */
#define _80_IICA_STARTFLAG_UNSUCCESSFUL  (0x80U)    /* start condition generation unsuccessful */
/* IIC bus status flag (IICBSYn) */
#define _00_IICA_BUS_RELEASE             (0x00U)    /* bus release status */
#define _40_IICA_BUS_COMMUNICATION       (0x40U)    /* bus communication status */
/* Initial start enable trigger (STCENn) */
#define _00_IICA_START_WITHSTOP          (0x00U)    /* generate start condition upon detecting a stop condition */
#define _02_IICA_START_WITHOUTSTOP       (0x02U)    /* generate start condition without detection of a stop condition */
/* Communication reservation function disable bit (IICRSVn) */
#define _00_IICA_RESERVATION_ENABLE      (0x00U)    /* enable communication reservation */
#define _01_IICA_RESERVATION_DISABLE     (0x01U)    /* disable communication reservation */

/*
    IICA Control Register 1 (IICCTLn1)
*/
/* Control of address match wakeup (WUPn) */
#define _00_IICA_WAKEUP_STOP             (0x00U)    /* stop address match wakeup function in STOP mode */
#define _80_IICA_WAKEUP_ENABLE           (0x80U)    /* enable address match wakeup function in STOP mode */
/* Detection of SCL0 pin level (CLDn) */
#define _00_IICA_SCL_LOW                 (0x00U)    /* detect clock line at low level */
#define _20_IICA_SCL_HIGH                (0x20U)    /* detect clock line at high level */
/* Detection of SDA0 pin level (DADn) */
#define _00_IICA_SDA_LOW                 (0x00U)    /* detect data line at low level */
#define _10_IICA_SDA_HIGH                (0x10U)    /* detect data line at high level */
/* Operation mode switching (SMCn) */
#define _00_IICA_MODE_STANDARD           (0x00U)    /* operates in standard mode */
#define _08_IICA_MODE_HIGHSPEED          (0x08U)    /* operates in high-speed mode */
/* Digital filter operation control (DFCn) */
#define _00_IICA_FILTER_OFF              (0x00U)    /* digital filter off */
#define _04_IICA_FILTER_ON               (0x04U)    /* digital filter on */
/* Operation of clock dividing frequency permission (PRSn) */
#define _00_IICA_fCLK                    (0x00U)    /* clock of dividing frequency operation (fCLK) */
#define _01_IICA_fCLK_HALF               (0x01U)    /* 2 clock of dividing frequency operation (fCLK/2) */
/* IICA used flag */
#define _80_IICA_ADDRESS_COMPLETE        (0x80U)
#define _00_IICA_MASTER_FLAG_CLEAR       (0x00U)

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _CE00_UART0_RECEIVE_DIVISOR      (0xCE00U)
#define _CE00_UART0_TRANSMIT_DIVISOR     (0xCE00U)

/*串行阵列单元*/
typedef enum RL78G13_SERIAL_UNIT
{
    RL78G13_SERIAL_UNIT_0 = 0,
    RL78G13_SERIAL_UNIT_1 = 1,
}RL78G13_SERIAL_UNIT;

/*串行阵列通道,单元0有四个通道,单元1有两个通道*/
typedef enum RK78G13_SERIAL_UNIT_CHANNEL
{
    RK78G13_SERIAL_UNIT_CHANNEL_0 = 0,
    RK78G13_SERIAL_UNIT_CHANNEL_1 = 1,
    RK78G13_SERIAL_UNIT_CHANNEL_2 = 2,
    RK78G13_SERIAL_UNIT_CHANNEL_3 = 3,
}RK78G13_SERIAL_UNIT_CHANNEL;

/*串行时钟选择寄存器SPS*/
/*单元时钟0,基于FCLK的分频*/
#define RL78G13_SERIAL_SPS_FLCK0_MASK                                       0X000FU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_1                                      0X0000U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_2                                      0X0001U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_4                                      0X0002U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_8                                      0X0003U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_16                                     0X0004U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_32                                     0X0005U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_64                                     0X0006U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_128                                    0X0007U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_256                                    0X0008U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_512                                    0X0009U
#define RL78G13_SERIAL_SPS_FLCK0_DIV_1024                                   0X000AU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_2048                                   0X000BU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_4096                                   0X000CU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_8192                                   0X000DU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_16384                                  0X000EU
#define RL78G13_SERIAL_SPS_FLCK0_DIV_32768                                  0X000FU

/*单元时钟1,基于FCLK的分频*/
#define RL78G13_SERIAL_SPS_FLCK1_MASK                                       0X00F0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_1                                      0X0000U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_2                                      0X0010U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_4                                      0X0020U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_8                                      0X0030U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_16                                     0X0040U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_32                                     0X0050U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_64                                     0X0060U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_128                                    0X0070U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_256                                    0X0080U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_512                                    0X0090U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_1024                                   0X00A0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_2048                                   0X00B0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_4096                                   0X00C0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_8192                                   0X00D0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_16384                                  0X00E0U
#define RL78G13_SERIAL_SPS_FLCK1_DIV_32768                                  0X00F0U


/*串行模式寄存器SMR*/
/*通道N的操作时钟FMCK的选择,单元时钟0或者1*/
#define RL78G13_SERIAL_SMR_FMCK_SELECT_MASK                                 0X8000U
#define RL78G13_SERIAL_SMR_FMCK_SELECT_FCLK0                                0X0000U
#define RL78G13_SERIAL_SMR_FMCK_SELECT_FCLK1                                0X8000U

/*通道N的传送时钟FTCLK的选择,FMCK或者引脚输入时钟*/
#define RL78G13_SERIAL_SMR_FTCLK_SELECT_MASK                                0X4000U
#define RL78G13_SERIAL_SMR_FTCLK_SELECT_FMCK                                0X0000U
#define RL78G13_SERIAL_SMR_FTCLK_SELECT_FSCK                                0X4000U

/*开始触发源的选择,软件触发或者RXDQ有效沿触发*/
#define RL78G13_SERIAL_SMR_START_TRIG_SOURCE_MASK                           0X0100U
#define RL78G13_SERIAL_SMR_START_TRIG_SOURCE_SOFT                           0X0000U
#define RL78G13_SERIAL_SMR_START_TRIG_SOURCE_RXDQ_PIN                       0X0100U

/*串口模式下,接收电平的反向控制,下降沿起始位还是上升沿起始位*/
#define RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_MASK                       0X0040U
#define RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_FALLING                    0X0000U
#define RL78G13_SERIAL_SMR_UART_RECV_START_LEVEL_RISING                     0X0040U

/*通道的使用模式,CSI模式 UART模式 简易IIC模式*/
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_MASK                                0X0006U
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_CSI                                 0X0000U
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_UART                                0X0002U
#define RL78G13_SERIAL_SMR_CHANNEL_MODE_IIC                                 0X0004U

/*通道N的中断源的选择,传送结束发生中断还是缓冲区空发生中断*/
#define RL78G13_SERIAL_SMR_INT_SRC_MASK                                     0X0001U
#define RL78G13_SERIAL_SMR_INT_SRC_END                                      0X0000U
#define RL78G13_SERIAL_SMR_INT_SRC_EMPTY                                    0X0001U


/*串行通讯操作设置寄存器SCR*/
/*通道N的操作模式设定,禁止通讯,仅接受,仅发送,同时发送接收*/
#define RL78G13_SERIAL_SCR_MODE_MASK                                        0XC000U
#define RL78G13_SERIAL_SCR_MODE_DISABLE                                     0X0000U
#define RL78G13_SERIAL_SCR_MODE_RX_ONLY                                     0X4000U
#define RL78G13_SERIAL_SCR_MODE_TX_ONLY                                     0X8000U
#define RL78G13_SERIAL_SCR_MODE_TX_RX                                       0XC000U

/*CSI模式下数据和时钟相位的选择,一共四种模式,具体看文档*/
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_MASK                             0X3000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_0                                0X0000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_1                                0X1000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_2                                0X2000U
#define RL78G13_SERIAL_SCR_CSI_SINGLE_TYPE_3                                0X3000U

/*选择是否屏蔽错误中断信号*/
#define RL78G13_SERIAL_SCR_INT_DISABLE_MASK                                 0X0400U
#define RL78G13_SERIAL_SCR_INT_DISABLE_ON                                   0X0000U
#define RL78G13_SERIAL_SCR_INT_DISABLE_OFF                                  0X0400U

/*UART模式下的奇偶校验选择*/
#define RL78G13_SERIAL_SCR_UART_CHECK_MASK                                  0X0300U
/*发送模式下的奇偶校验,分为不输出,0校验,奇校验,偶校验*/
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_NONE                               0X0000U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_ZERO                               0X0100U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_ODD                                0X0200U
#define RL78G13_SERIAL_SCR_UART_CHECK_TX_EVEN                               0X0300U
/*接受模式下的奇偶校验,分为无校验,奇校验,偶校验*/
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_NO                                 0X0000U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_NO1                                0X0100U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_ODD                                0X0200U
#define RL78G13_SERIAL_SCR_UART_CHECK_RX_EVEN                               0X0300U

/*CSI和UART模式下的数据传送序列选择,分为MSB优先和LSB优先*/
#define RL78G13_SERIAL_SCR_UART_CSI_SEQ_MASK                                0X0080U
#define RL78G13_SERIAL_SCR_UART_CSI_SEQ_MSB_FIRST                           0X0000U
#define RL78G13_SERIAL_SCR_UART_CSI_SEQ_LSB_FIRST                           0X0080U

/*UART模式下的停止位长度选择,分为0长度 1长度 2长度*/
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_MASK                              0X0030U
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_NONE                              0X0000U
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_1                                 0X0010U
#define RL78G13_SERIAL_SCR_UART_STOP_BITS_2                                 0X0020U

/*CSI和UART模式下的数据长度选择,分为9 8 7长度*/
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_MASK                         0X0003U
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_9                            0X0001U
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_7                            0X0002U
#define RL78G13_SERIAL_SCR_UART_CSI_DATALENGTH_8                            0X0003U


/*串行数据寄存器,高八位为二级分频,低八位为数据缓冲区SDR*/
/*分频公式为 FMCK/(SDR+1)*/
#define RL78G13_SERIAL_SDR_FMCK_DIV_MASK                                    0XFE00U
#define RL78G13_SERIAL_SDR_FMCK_DIV_2                                       0X0000U
#define RL78G13_SERIAL_SDR_FMCK_DIV_4                                       0X0200U
#define RL78G13_SERIAL_SDR_FMCK_DIV_6                                       0X0400U
#define RL78G13_SERIAL_SDR_FMCK_DIV_8                                       0X0600U
#define RL78G13_SERIAL_SDR_FMCK_DIV_254                                     0XFD00U
#define RL78G13_SERIAL_SDR_FMCK_DIV_256                                     0XFE00U

/*SDR中的数据掩码*/
#define RL78G13_SERIAL_SDR_DATA_MASK                                        0X00FFU


/*串行标志清除触发寄存器,清除通道N各个错误标志SIR*/
/*帧错误标志清除*/
#define RL78G13_SERIAL_SIR_FECT_MASK                                        0X0004U
#define RL78G13_SERIAL_SIR_FECT_CLECR                                       0X0004U
#define RL78G13_SERIAL_SIR_FECT_NONE                                        0X0000U

/*奇偶校验错误标志清除*/
#define RL78G13_SERIAL_SIR_PECT_MASK                                        0X0002U
#define RL78G13_SERIAL_SIR_PECT_CLECR                                       0X0002U
#define RL78G13_SERIAL_SIR_PECT_NONE                                        0X0000U

/*溢出错误标志清除*/
#define RL78G13_SERIAL_SIR_OVCT_MASK                                        0X0001U
#define RL78G13_SERIAL_SIR_OVCT_CLECR                                       0X0001U
#define RL78G13_SERIAL_SIR_OVCT_NONE                                        0X0000U


/*串行状态寄存器SSR,指示通讯状态和错误状态,只读*/
/*通讯正在进行或者已经停止或暂停*/
#define RL78G13_SERIAL_SSR_TSF_MASK                                         0X0040U
#define RL78G13_SERIAL_SSR_TSF_RUNNING                                      0X0040U
#define RL78G13_SERIAL_SSR_TSF_STOP_PAUSE                                   0X0000U

/*有效数据是否保存在SDR中*/
#define RL78G13_SERIAL_SSR_BUFFER_MASK                                      0X0020U
#define RL78G13_SERIAL_SSR_BUFFER_FULL                                      0X0020U
#define RL78G13_SERIAL_SSR_BUFFER_EMPTY                                     0X0000U

/*帧错误标志*/
#define RL78G13_SERIAL_SSR_RECV_ERR_FLAG_MASK                               0X0004U
#define RL78G13_SERIAL_SSR_RECV_ERR_FLAG_ON                                 0X0004U
#define RL78G13_SERIAL_SSR_RECV_ERR_FLAG_NONE                               0X0000U

/*奇偶校验,ACK错误检测标志*/
#define RL78G13_SERIAL_SSR_CHECK_ERR_FLAG_MASK                              0X0002U
#define RL78G13_SERIAL_SSR_CHECK_ERR_FLAG_ON                                0X0002U
#define RL78G13_SERIAL_SSR_CHECK_ERR_FLAG_NONE                              0X0000U

/*溢出错误检测标志*/
#define RL78G13_SERIAL_SSR_OVER_ERR_FLAG_MASK                               0X0001U
#define RL78G13_SERIAL_SSR_OVER_ERR_FLAG_ON                                 0X0001U
#define RL78G13_SERIAL_SSR_OVER_ERR_FLAG_NONE                               0X0000U


/*串行通道开始寄存器,SS,设置通道允许,开始通讯的触发寄存器*/
/*通道0进入通讯等待状态*/
#define RL78G13_SERIAL_SS_COM0_WAIT_FLAG_MASK                               0X0001U
#define RL78G13_SERIAL_SS_COM0_WAIT_FLAG_ON                                 0X0001U
#define RL78G13_SERIAL_SS_COM0_WAIT_FLAG_OFF                                0X0000U

/*通道1进入通讯等待状态*/
#define RL78G13_SERIAL_SS_COM1_WAIT_FLAG_MASK                               0X0002U
#define RL78G13_SERIAL_SS_COM1_WAIT_FLAG_ON                                 0X0002U
#define RL78G13_SERIAL_SS_COM1_WAIT_FLAG_OFF                                0X0000U

/*通道2进入通讯等待状态*/
#define RL78G13_SERIAL_SS_COM2_WAIT_FLAG_MASK                               0X0004U
#define RL78G13_SERIAL_SS_COM2_WAIT_FLAG_ON                                 0X0004U
#define RL78G13_SERIAL_SS_COM2_WAIT_FLAG_OFF                                0X0000U

/*通道3进入通讯等待状态*/
#define RL78G13_SERIAL_SS_COM3_WAIT_FLAG_MASK                               0X0008U
#define RL78G13_SERIAL_SS_COM3_WAIT_FLAG_ON                                 0X0008U
#define RL78G13_SERIAL_SS_COM3_WAIT_FLAG_OFF                                0X0000U

/*串行通道停止寄存器ST,设置通道禁止,停止通讯的触发寄存器*/
/*通道0停止通讯操作*/
#define RL78G13_SERIAL_ST_COM0_STOP_FLAG_MASK                               0X0001U
#define RL78G13_SERIAL_ST_COM0_STOP_FLAG_ON                                 0X0001U
#define RL78G13_SERIAL_ST_COM0_STOP_FLAG_OFF                                0X0000U

/*通道1停止通讯操作*/
#define RL78G13_SERIAL_ST_COM1_STOP_FLAG_MASK                               0X0002U
#define RL78G13_SERIAL_ST_COM1_STOP_FLAG_ON                                 0X0002U
#define RL78G13_SERIAL_ST_COM1_STOP_FLAG_OFF                                0X0000U

/*通道2停止通讯操作*/
#define RL78G13_SERIAL_ST_COM2_STOP_FLAG_MASK                               0X0004U
#define RL78G13_SERIAL_ST_COM2_STOP_FLAG_ON                                 0X0004U
#define RL78G13_SERIAL_ST_COM2_STOP_FLAG_OFF                                0X0000U

/*通道3停止通讯操作*/
#define RL78G13_SERIAL_ST_COM3_STOP_FLAG_MASK                               0X0008U
#define RL78G13_SERIAL_ST_COM3_STOP_FLAG_ON                                 0X0008U
#define RL78G13_SERIAL_ST_COM3_STOP_FLAG_OFF                                0X0000U


/*串行通道允许状态寄存器,SE,显示的就是SS和ST的设置结果,只读*/
/*通道0允许操作或者停止操作*/
#define RL78G13_SERIAL_SE_COM0_ALLOW_OP_FLAG_MASK                           0X0001U
#define RL78G13_SERIAL_SE_COM0_ALLOW_OP_FLAG_ON                             0X0001U
#define RL78G13_SERIAL_SE_COM0_ALLOW_OP_FLAG_OFF                            0X0000U

/*通道1允许操作或者停止操作*/
#define RL78G13_SERIAL_SE_COM1_ALLOW_OP_FLAG_MASK                           0X0002U
#define RL78G13_SERIAL_SE_COM1_ALLOW_OP_FLAG_ON                             0X0002U
#define RL78G13_SERIAL_SE_COM1_ALLOW_OP_FLAG_OFF                            0X0000U

/*通道2允许操作或者停止操作*/
#define RL78G13_SERIAL_SE_COM2_ALLOW_OP_FLAG_MASK                           0X0004U
#define RL78G13_SERIAL_SE_COM2_ALLOW_OP_FLAG_ON                             0X0004U
#define RL78G13_SERIAL_SE_COM2_ALLOW_OP_FLAG_OFF                            0X0000U

/*通道3允许操作或者停止操作*/
#define RL78G13_SERIAL_SE_COM3_ALLOW_OP_FLAG_MASK                           0X0008U
#define RL78G13_SERIAL_SE_COM3_ALLOW_OP_FLAG_ON                             0X0008U
#define RL78G13_SERIAL_SE_COM3_ALLOW_OP_FLAG_OFF                            0X0000U


/*串行输出允许寄存器SOE,设置是否允许各个串行通道的输出*/
/*通道0允许或者停止串行通道的输出*/
#define RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_MASK                     0X0001U
#define RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_ON                       0X0001U
#define RL78G13_SERIAL_SOE_COM0_OUTPUT_ENABLE_FLAG_OFF                      0X0000U

/*通道1允许或者停止串行通道的输出*/
#define RL78G13_SERIAL_SOE_COM1_OUTPUT_ENABLE_FLAG_MASK                     0X0002U
#define RL78G13_SERIAL_SOE_COM1_OUTPUT_ENABLE_FLAG_ON                       0X0002U
#define RL78G13_SERIAL_SOE_COM1_OUTPUT_ENABLE_FLAG_OFF                      0X0000U

/*通道2允许或者停止串行通道的输出*/
#define RL78G13_SERIAL_SOE_COM2_OUTPUT_ENABLE_FLAG_MASK                     0X0004U
#define RL78G13_SERIAL_SOE_COM2_OUTPUT_ENABLE_FLAG_ON                       0X0004U
#define RL78G13_SERIAL_SOE_COM2_OUTPUT_ENABLE_FLAG_OFF                      0X0000U

/*通道3允许或者停止串行通道的输出*/
#define RL78G13_SERIAL_SOE_COM3_OUTPUT_ENABLE_FLAG_MASK                     0X0008U
#define RL78G13_SERIAL_SOE_COM3_OUTPUT_ENABLE_FLAG_ON                       0X0008U
#define RL78G13_SERIAL_SOE_COM3_OUTPUT_ENABLE_FLAG_OFF                      0X0000U

/*串行输出寄存器SO,用于各个通道串行输出的缓冲,控制串行时钟的输出和数据的输出*/
/*SE启用时,软件改写将被忽略,手动单比特传送有用*/
/*通道0时钟输出0或1*/
#define RL78G13_SERIAL_SO_COM0_CLOCK_OUTPUT_MASK                            0X0100U
#define RL78G13_SERIAL_SO_COM0_CLOCK_OUTPUT_1                               0X0100U
#define RL78G13_SERIAL_SO_COM0_CLOCK_OUTPUT_0                               0X0000U

/*通道1时钟输出0或1*/
#define RL78G13_SERIAL_SO_COM1_CLOCK_OUTPUT_MASK                            0X0200U
#define RL78G13_SERIAL_SO_COM1_CLOCK_OUTPUT_1                               0X0200U
#define RL78G13_SERIAL_SO_COM1_CLOCK_OUTPUT_0                               0X0000U

/*通道2时钟输出0或1*/
#define RL78G13_SERIAL_SO_COM2_CLOCK_OUTPUT_MASK                            0X0400U
#define RL78G13_SERIAL_SO_COM2_CLOCK_OUTPUT_1                               0X0400U
#define RL78G13_SERIAL_SO_COM2_CLOCK_OUTPUT_0                               0X0000U

/*通道3时钟输出0或1*/
#define RL78G13_SERIAL_SO_COM3_CLOCK_OUTPUT_MASK                            0X0800U
#define RL78G13_SERIAL_SO_COM3_CLOCK_OUTPUT_1                               0X0800U
#define RL78G13_SERIAL_SO_COM3_CLOCK_OUTPUT_0                               0X0000U

/*通道0数据输出0或1*/
#define RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_MASK                             0X0001U
#define RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_1                                0X0001U
#define RL78G13_SERIAL_SO_COM0_DATA_OUTPUT_0                                0X0000U

/*通道1数据输出0或1*/
#define RL78G13_SERIAL_SO_COM1_DATA_OUTPUT_MASK                             0X0002U
#define RL78G13_SERIAL_SO_COM1_DATA_OUTPUT_1                                0X0002U
#define RL78G13_SERIAL_SO_COM1_DATA_OUTPUT_0                                0X0000U

/*通道2数据输出0或1*/
#define RL78G13_SERIAL_SO_COM2_DATA_OUTPUT_MASK                             0X0004U
#define RL78G13_SERIAL_SO_COM2_DATA_OUTPUT_1                                0X0004U
#define RL78G13_SERIAL_SO_COM2_DATA_OUTPUT_0                                0X0000U

/*通道3数据输出0或1*/
#define RL78G13_SERIAL_SO_COM3_DATA_OUTPUT_MASK                             0X0008U
#define RL78G13_SERIAL_SO_COM3_DATA_OUTPUT_1                                0X0008U
#define RL78G13_SERIAL_SO_COM3_DATA_OUTPUT_0                                0X0000U


/*串行输出电平寄存器SOL.数据电平是否反向*/
/*通道0输出数据是否反向*/
#define RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_MASK                    0X0001U
#define RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_ON                      0X0001U
#define RL78G13_SERIAL_SOL_COM0_OUTPUT_REVERSE_FLAG_OFF                     0X0000U

/*通道2输出数据是否反向*/
#define RL78G13_SERIAL_SOL_COM2_OUTPUT_REVERSE_FLAG_MASK                    0X0004U
#define RL78G13_SERIAL_SOL_COM2_OUTPUT_REVERSE_FLAG_ON                      0X0004U
#define RL78G13_SERIAL_SOL_COM2_OUTPUT_REVERSE_FLAG_OFF                     0X0000U


/*串行待机控制寄存器SSC,设置通过接受UART0或者CSI0的串行数据,控制STOP模式下启动接收*/
/*使用或者不使用SNOOZE模式*/
#define RL78G13_SERIAL_SSC_SNOOZE_ENABLE_MASK                               0X0001U
#define RL78G13_SERIAL_SSC_SNOOZE_ENABLE_FLAG                               0X0001U
#define RL78G13_SERIAL_SSC_SNOOZE_DISABLE_FLAG                              0X0000U

/*允许或者停止传送结束中断*/
#define RL78G13_SERIAL_SSC_INT_ERR_ENABLE_MASK                              0X0002U
#define RL78G13_SERIAL_SSC_INT_ERR_ENABLE_FLAG                              0X0002U
#define RL78G13_SERIAL_SSC_INT_ERR_DISABLE_FLAG                             0X0000U


/*输入切换控制寄存器ISC,用于切换定时器阵列7和RXD2的交替模式,主要在LIN模式使用*/
/*TI07使用正常的YI07引脚还是使用RXD2引脚*/
#define RL78G13_SERIAL_ISC_TIMER7_INPUT_MASK                                0X01U
#define RL78G13_SERIAL_ISC_TIMER7_INPUT_RXD2                                0X01U
#define RL78G13_SERIAL_ISC_TIMER7_INPUT_NORMAL                              0X00U

/*外部中断INTP0使用正常的INTP0引脚还是使用RXD2引脚*/
#define RL78G13_SERIAL_ISC_INTP0_INPUT_MASK                                 0X02U
#define RL78G13_SERIAL_ISC_INTP0_INPUT_RXD2                                 0X02U
#define RL78G13_SERIAL_ISC_INTP0_INPUT_NORMAL                               0X00U


/*噪声滤波器允许寄存器NFEN,用于控制RX引脚的噪声滤波功能的开关*/
/*RXD0引脚噪声滤波器开启或者关闭*/
#define RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_MASK                          0X01U
#define RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_OPEN                          0X01U
#define RL78G13_SERIAL_NFEN_RXD0_NOIZE_FILTER_CLOSE                         0X00U

/*RXD1引脚噪声滤波器开启或者关闭*/
#define RL78G13_SERIAL_NFEN_RXD1_NOIZE_FILTER_MASK                          0X04U
#define RL78G13_SERIAL_NFEN_RXD1_NOIZE_FILTER_OPEN                          0X04U
#define RL78G13_SERIAL_NFEN_RXD1_NOIZE_FILTER_CLOSE                         0X00U

/*RXD2引脚噪声滤波器开启或者关闭*/
#define RL78G13_SERIAL_NFEN_RXD2_NOIZE_FILTER_MASK                          0X10U
#define RL78G13_SERIAL_NFEN_RXD2_NOIZE_FILTER_OPEN                          0X10U
#define RL78G13_SERIAL_NFEN_RXD2_NOIZE_FILTER_CLOSE                         0X00U

/*RXD3引脚噪声滤波器开启或者关闭*/
#define RL78G13_SERIAL_NFEN_RXD3_NOIZE_FILTER_MASK                          0X40U
#define RL78G13_SERIAL_NFEN_RXD3_NOIZE_FILTER_OPEN                          0X40U
#define RL78G13_SERIAL_NFEN_RXD3_NOIZE_FILTER_CLOSE                         0X00U



/*源文件API设定*/

/*SPS*/
void RL78G13_SerialSPSWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t fclk0Div, uint16_t fclk1Div);
void RL78G13_SerialSPSWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSPSReadAll(RL78G13_SERIAL_UNIT unit);
uint16_t RL78G13_SerialSPSReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask);


/*SMR*/
void RL78G13_SerialSMRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t FMCKSelect, uint16_t FTCLKSelect, uint16_t startTrigSourceSelect, uint16_t uartRecvStartLevel,
    uint16_t channelMode, uint16_t intSrcSelect);
void RL78G13_SerialSMRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel);
uint16_t RL78G13_SerialReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask);


/*SCR*/
void RL78G13_SerialSCRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t txrxMode, uint16_t csiSingalType, uint16_t errorShield, uint16_t txrxCheckMode,
    uint16_t firstBitSet, uint16_t stopBitsSet, uint16_t dataLengthSet);
void RL78G13_SerialSCRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSCRReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel);
uint16_t RL78G13_SerialSCRReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask);


/*SDR*/
void RL78G13_SerialSDRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t fmclkDiv, uint16_t sendData);
void RL78G13_SerialSDRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSDRReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel);
uint16_t RL78G13_SerialSDRReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask);


/*SIR*/
void RL78G13_SerialSIRWriteAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t frameErrClear, uint16_t checkErrClear, uint16_t overFlowErrClear);
void RL78G13_SerialSIRWriteOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSIRReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel);
uint16_t RL78G13_SerialSIRReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask);


/*SSR*/
uint16_t RL78G13_SerialSSRReadAll(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel);
uint16_t RL78G13_SerialSSRReadOne(RL78G13_SERIAL_UNIT unit, RK78G13_SERIAL_UNIT_CHANNEL channel,
    uint16_t mask);


/*SS*/
void RL78G13_SerialSSWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t com0Wait, uint16_t com1Wait,
    uint16_t com2Wait, uint16_t com3Wait);
void RL78G13_SerialSSWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSSReadAll(RL78G13_SERIAL_UNIT unit);
uint16_t RL78G13_SerialSSReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask);


/*ST*/
void RL78G13_SerialSTWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t com0Stop, uint16_t com1Stop,
    uint16_t com2Stop, uint16_t com3Stop);
void RL78G13_SerialSTWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSTReadAll(RL78G13_SERIAL_UNIT unit);
uint16_t RL78G13_SerialSTReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask);


/*SE*/
uint16_t RL78G13_SerialSEReadAll(RL78G13_SERIAL_UNIT unit);
uint16_t RL78G13_SerialSEReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask);



/*SOE*/
void RL78G13_SerialSOEWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t com0AllowOP,
    uint16_t com1AllowOP, uint16_t com2AllowOP, uint16_t com3AllowOP);
void RL78G13_SerialSOEWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSOEReadAll(RL78G13_SERIAL_UNIT unit);
uint16_t RL78G13_SerialSOEReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask);


/*SO*/
void RL78G13_SerialSOWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t clock0OutValue,
    uint16_t clock1OutValue, uint16_t clock2OutValue, uint16_t clock3OutValue,
    uint16_t data0OutValue, uint16_t data1OutValue, uint16_t data2OutValue,
    uint16_t data3OutValue);
void RL78G13_SerialSOWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSOReadAll(RL78G13_SERIAL_UNIT unit);
uint16_t RL78G13_SerialSOReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask);


/*SOL*/
void RL78G13_SerialSOLWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t tx0LevelReserve,
    uint16_t tx2LevelReserve);
void RL78G13_SerialSOLWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSOLReadAll(RL78G13_SERIAL_UNIT unit);
uint16_t RL78G13_SerialSOLReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask);


/*SSC*/
void RL78G13_SerialSSCWriteAll(RL78G13_SERIAL_UNIT unit, uint16_t errIntEnable,
    uint16_t snoozeEnable);
void RL78G13_SerialSSCWriteOne(RL78G13_SERIAL_UNIT unit, uint16_t mask, uint16_t value);
uint16_t RL78G13_SerialSSCReadAll(RL78G13_SERIAL_UNIT unit);
uint16_t RL78G13_SerialSSCReadOne(RL78G13_SERIAL_UNIT unit, uint16_t mask);


/*ISC*/
void RL78G13_SerialISCWriteAll(uint8_t timer7Switch, uint8_t intp0Switch);
void RL78G13_SerialISCWriteOne(uint16_t mask, uint8_t value);
uint8_t RL78G13_SerialISCReadAll(void);
uint8_t RL78G13_SerialISCReadOne(uint16_t mask);


/*NFEN*/
void RL78G13_SerialNFENWriteAll(uint8_t rxd0FilterEnable, uint8_t rxd1FilterEnable,
    uint8_t rxd2FilterEnable, uint8_t rxd3FilterEnable);
void RL78G13_SerialNFENWriteOne(uint16_t mask, uint8_t value);
uint16_t RL78G13_SerialNFENReadAll();
uint16_t RL78G13_SerialNFENReadOne(uint16_t mask);



#endif





