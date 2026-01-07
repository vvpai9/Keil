/*
 *****************************************************************************
 * Copyright @ 2007 by austriamicrosystems AG                                *
 * All rights are reserved.                                                  *
 *                                                                           *
 * Reproduction in whole or in part is prohibited without the written consent*
 * of the copyright owner. Austriamicrosystems reserves the right to make    *
 * changes without notice at any time. The software is provided as is and    *
 * Austriamicrosystems makes no warranty, expressed, implied or statutory,   *
 * including but not limited to any implied warranty of merchantability or   *
 * fitness for any particular purpose, or that the use will not infringe any *
 * third party patent, copyright or trademark. Austriamicrosystems should    *
 * not be liable for any loss or damage arising from its use.                *
 *****************************************************************************
 */

/*
 *      PROJECT:   AS353x
 *      $Revision: 759 $
 *      LANGUAGE:  ANSI C
*/

/*! \file
 *
 *  \author Harsha Kumar
 *
 *  \brief I2C registers
 *
 *  Definition of AS353x I2C unit registers
 *
 */

#ifndef _I2C_REGISTERS_H_
#define _I2C_REGISTERS_H_

/*
******************************************************************************
* DEFINES
******************************************************************************
*/

/* I2c Register offsets */
#define I2C_DATA     (0x00) /*!< Transmit FIFO (write) and
                             *   receive FIFO (read) data register          */
#define I2C_SLAD0    (0x04) /*!< Slave ID in case of 7-bit addressing mode
                             *   and LSB 7-bits of Slave ID in case of
                             *   10-bit addressing mode                     */
#define I2C_SLAD1    (0x08) /*!< MSB 3-bits of Slave ID in 10-bit
                             *   addressing mode                            */
#define I2C_CNTRL    (0x0C) /*!< Control register                           */
#define I2C_DACNT    (0x10) /*!< Master data count                          */
#define I2C_SEAD0    (0x14) /*!< The self ID of the Slave. In case of 10-bit
                             *   addressing this register contains LSB 7 bits
                             *   of address                                 */
#define I2C_SEAD1    (0x18) /*!< The MSB 3-bits of the self ID of the Slave
                             *   in the 10bit addressing mode               */
#define I2C_CPSR0    (0x1C) /*!< Prescaler (LSB 8-bits)                     */
#define I2C_CPSR1    (0x20) /*!< Prescaler (MSB 2-bits)                     */
#define I2C_IMR      (0x24) /*!< Interrupt mask bits                        */
#define I2C_RIS      (0x28) /*!< Raw interrupt status register              */
#define I2C_MIS      (0x2C) /*!< Masked interrupt status register           */
#define I2C_SR       (0x30) /*!< I2C status register                        */
#define I2C_TXCNT    (0x34) /*!< Transmit FIFO data count (gives number of
                             *   valid data present in Tx FIFO)             */
#define I2C_RXCNT    (0x38) /*!< Receive FIFO data count (gives number of
                             *   valid data present in Rx FIFO)             */
#define I2C_TX_FLUSH (0x3C) /*!< A write to this register flushes the Tx FIFO
                             *   (resets the FIFO pointers)                 */
#define I2C_INT_CLR  (0x40) /*!< This register is used to clear the interrupts.
                             *   A write of ‘1’ to any bit of this register
                             *   will clear the corresponding interrupt.
                             *   Rx FIFO overrun interrupt, break interrupt,
                             *   slave transmit request interrupt are the
                             *   interrupts which can be cleared by writing
                             *   into this register                         */
#define I2C_TESTIN   (0x50) /*!< The input signals SclIn and SdaIn status are
                             *   available in this register                 */
#define I2C_TESTOUT1 (0x54) /*!< In test mode the output interrupts will be
                             *   driven by this register. This is to test the
                             *   system connectivity                        */
#define I2C_TESTOUT2 (0x58) /*!< In test mode the output I2C signals, SclOut,
                             *   SclOE, SdaOut, and SdaOE are driven by this
                             *   register                                   */

#define I2C_SADDR    (0x44) /*!< Register thats meant only for Audio Master */

#endif /* _I2C_REGISTERS_H_ */


