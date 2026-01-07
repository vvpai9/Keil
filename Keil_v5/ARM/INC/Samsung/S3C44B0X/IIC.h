/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  IIC.H:  Header file for IIC-Bus Interface                                 */
/*          Samsung S3C44B0X                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __IIC_H
#define __IIC_H


#define IIC_BASE    0x01D60000  // IIC Base Address


// IIC Registers
typedef struct {
  reg32 IICCON;     // IIC Control
  reg32 IICSTAT;    // IIC Status
  reg32 IICADD;     // IIC Address
  reg32 IICDS;      // IIC Data Shift
} regIIC;

#define pIIC ((regIIC *)IIC_BASE)


// IICCON: IIC Control Register
#define IIC_ACK_EN        0x00000080
#define IIC_CLK_DIV16     0x00000000
#define IIC_CLK_DIV512    0x00000040
#define IIC_TXRXINT_EN    0x00000020
#define IIC_TXRXINT_NPEND 0x00000000
#define IIC_TXRXINT_PEND  0x00000010
#define IIC_TXCLK_MASK    0x0000000F

// IICSTAT: IIC Status Register
#define IIC_MODE_M_TX     0x000000C0
#define IIC_MODE_M_RX     0x00000080
#define IIC_MODE_S_TX     0x00000040
#define IIC_MODE_S_RX     0x00000000
#define IIC_BUSY          0x00000020
#define IIC_OUT_EN        0x00000010
#define IIC_ARBIT         0x00000008
#define IIC_SADDR_STAT    0x00000004
#define IIC_ZADDR_STAT    0x00000002
#define IIC_RXACK         0x00000001


#endif /* __IIC_H */
