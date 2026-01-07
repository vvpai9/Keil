/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  SSP.H:  Header file for Synchronous Serial Port (SSP)                     */
/*          Sharp LH754xx                                                     */
/*                                                                            */
/******************************************************************************/

#ifndef __SSP_H
#define __SSP_H


#define SSP_BASE    0xFFFC6000              /* SSP Base Address */

#define SSPCR0      REG16(SSP_BASE + 0x00)  /* Control Register 0 */
#define SSPCR1      REG16(SSP_BASE + 0x04)  /* Control Register 1 */
#define SSPDR       REG16(SSP_BASE + 0x08)  /* Rx/Tx Data Register */
#define SSPSR       REG16(SSP_BASE + 0x0C)  /* Status Register */
#define SSPCPSR     REG16(SSP_BASE + 0x10)  /* Clock Prescale Register*/
#define SSPIIR      REG16(SSP_BASE + 0x14)  /* Interrupt ID Register */
#define SSPICR      REG16(SSP_BASE + 0x14)  /* Interrupt Clear Register */
#define SSPRXTO     REG16(SSP_BASE + 0x18)  /* Receive Timeout Register */


#endif /* __SSP_H */
