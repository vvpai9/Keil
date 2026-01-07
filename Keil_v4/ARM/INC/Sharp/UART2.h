/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  UART2.H:  Header file for UART2                                           */
/*            Sharp LH754xx                                                   */
/*                                                                            */
/******************************************************************************/

#ifndef __UART2_H
#define __UART2_H


#define UART2_BASE  0xFFFC2000               /* UART2 Base Address */

/* Register Bank 0 */
#define UART2_TXD   REG8(UART2_BASE + 0x00)  /* Tx Data (Write) */
#define UART2_RXD   REG8(UART2_BASE + 0x00)  /* Rx Data (Read) */
#define UART2_BAL   REG8(UART2_BASE + 0x00)  /* BRGA Divisor LSB */
#define UART2_BAH   REG8(UART2_BASE + 0x04)  /* BRGA Divisor MSB */
#define UART2_GER   REG8(UART2_BASE + 0x04)  /* General Enable Register */
#define UART2_GIR   REG8(UART2_BASE + 0x08)  /* General Interrupt Register */
#define UART2_LCR   REG8(UART2_BASE + 0x0C)  /* Line Control Register */
#define UART2_MCR   REG8(UART2_BASE + 0x10)  /* Loopback Control Register */
#define UART2_LSR   REG8(UART2_BASE + 0x14)  /* Line Status Register */
#define UART2_ACR0  REG8(UART2_BASE + 0x1C)  /* Rx Char Recognition Reg. 0 */

/* Register Bank 1 */
#define UART2_TXD   REG8(UART2_BASE + 0x00)  /* Tx Data (Write) */
#define UART2_RXD   REG8(UART2_BASE + 0x00)  /* Rx Data (Read) */
#define UART2_TXF   REG8(UART2_BASE + 0x04)  /* Tx Character Flag (Write) */
#define UART2_RXF   REG8(UART2_BASE + 0x04)  /* Rx Character Flag (Read) */
#define UART2_GIR   REG8(UART2_BASE + 0x08)  /* General Interrupt Register */
#define UART2_TMCR  REG8(UART2_BASE + 0x0C)  /* Timer Control Reg. (Write) */
#define UART2_TMST  REG8(UART2_BASE + 0x0C)  /* Timer Status Reg. (Read) */
#define UART2_MCR   REG8(UART2_BASE + 0x10)  /* Loopback Control Reg. (Write) */
#define UART2_FLR   REG8(UART2_BASE + 0x10)  /* FIFO Level Reg. (Read) */
#define UART2_RCM   REG8(UART2_BASE + 0x14)  /* Rx Command Reg. (Write) */
#define UART2_RST   REG8(UART2_BASE + 0x14)  /* Rx Status Reg. (Read) */
#define UART2_TCM   REG8(UART2_BASE + 0x18)  /* Tx Command Reg. (Write) */
#define UART2_ICM   REG8(UART2_BASE + 0x1C)  /* Internal Command Reg. (Write) */
#define UART2_GSR   REG8(UART2_BASE + 0x1C)  /* General Status Reg. (Read) */

/* Register Bank 2 */
#define UART2_FMD   REG8(UART2_BASE + 0x04)  /* FIFO Mode Register */
#define UART2_GIR   REG8(UART2_BASE + 0x08)  /* General Interrupt Register */
#define UART2_TMD   REG8(UART2_BASE + 0x0C)  /* Tx Mode Register */
#define UART2_IMD   REG8(UART2_BASE + 0x10)  /* Internal Mode Register */
#define UART2_ACR1  REG8(UART2_BASE + 0x14)  /* Rx Char Recognition Reg. 1 */
#define UART2_RIE   REG8(UART2_BASE + 0x18)  /* Rx Interrupt Enable */
#define UART2_RMD   REG8(UART2_BASE + 0x1C)  /* Rx Mode Register */

/* Register Bank 3 */
#define UART2_CLCF  REG8(UART2_BASE + 0x00)  /* Clock Configure Register */
#define UART2_BACF  REG8(UART2_BASE + 0x04)  /* BRGA Configuration Register */
#define UART2_BBL   REG8(UART2_BASE + 0x00)  /* BRGB Divisor LSB */
#define UART2_BBH   REG8(UART2_BASE + 0x04)  /* BRGB Divisor MSB */
#define UART2_GIR   REG8(UART2_BASE + 0x08)  /* General Interrupt Register */
#define UART2_BBCF  REG8(UART2_BASE + 0x0C)  /* BRGB Configuration Register */
#define UART2_TMIE  REG8(UART2_BASE + 0x18)  /* Timer Interrupt Enable */


#endif /* __UART2_H */
