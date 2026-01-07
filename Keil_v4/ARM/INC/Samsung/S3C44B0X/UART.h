/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  UART.H:  Header file for UART                                             */
/*           Samsung S3C44B0X                                                 */
/*                                                                            */
/******************************************************************************/

#ifndef __UART_H
#define __UART_H


#define UART0_BASE  0x01D00000  // UART0 Base Address
#define UART1_BASE  0x01D04000  // UART1 Base Address


// UART Registers
typedef struct {
  reg32 ULCON;      // UART Line Control
  reg32 UCON;       // UART Control
  reg32 UFCON;      // UART FIFO Control
  reg32 UMCON;      // UART MODEM Control
  reg32 UTRSTAT;    // UART Tx/Rx Status
  reg32 UERSTAT;    // UART Error Status
  reg32 UFSTAT;     // UART FIFO Status
  reg32 UMSTAT;     // UART MODEM Status
  reg8  UTXH;       // UART Tx Hold
  reg8  pad0[3];
  reg8  URXH;       // UART RX Buffer
  reg8  pad1[3];
  reg32 UBRDIV;     // UART Baud Rate Divisor
} regUART;

#define pUART0 ((regUART *)UART0_BASE)
#define pUART1 ((regUART *)UART1_BASE)


// ULCON: UART Line Control Register
#define DATA_5          0x00
#define DATA_6          0x01
#define DATA_7          0x02
#define DATA_8          0x03
#define STOP_ONE        0x00
#define STOP_TWO        0x04
#define PARITY_NONE     0x00
#define PARITY_ODD      0x20
#define PARITY_EVEN     0x28
#define PARITY_FC1      0x30
#define PARITY_FC0      0x38
#define NORMAL_MODE     0x00
#define IRDA_MODE       0x40

// UCON: UART Control Register
#define RXM_INTPOL      0x0001
#define RXM_BDMA0       0x0002  // UART0 Only
#define RXM_BDMA1       0x0003  // UART1 Only
#define TXM_INTPOL      0x0004
#define TXM_BDMA0       0x0008  // UART0 Only
#define TXM_BDMA1       0x000C  // UART1 Only
#define SEND_BREAK_SIG  0x0010
#define LOOPBACK_MODE   0x0020
#define RXINT_ERRSTAT   0x0040
#define RX_TIMEOUT      0x0080
#define RXINTTYP_LEVEL  0x0100
#define TXINTTYP_LEVEL  0x0200

// UFCON: UART FIFO Control Register
#define FIFO_EN         0x01
#define RXF_RST         0x02
#define TXF_RST         0x04
#define RXF_TRIG4B      0x00
#define RXF_TRIG8B      0x10
#define RXF_TRIG12B     0x20
#define RXF_TRIG16B     0x30
#define TXF_TRIG4B      0x40
#define TXF_TRIG8B      0x80
#define TXF_TRIG12B     0xC0

// UMCON: UART MODEM Control Register
#define RTS_ACTIVE      0x01
#define AFC_EN          0x10

// UTRSTAT: UART Tx/Rx Status Register
#define RX_BUF_READY    0x01
#define TX_BUF_EMPTY    0x02
#define TX_EMPTY        0x04

// UERSTAT: UART Error Status Register
#define OVERRUN_ERR     0x01
#define PARITY_ERR      0x02
#define FRAME_ERR       0x04
#define BREAK           0x08

// UFSTAT: UART FIFO Status Register
#define RXF_SHIFT       0
#define TXF_SHIFT       4
#define RXF_CMASK       0x000F
#define TXF_CMASK       0x00F0
#define RXF_FULL        0x0100
#define TXF_FULL        0x0200

// UMSTAT: UART MODEM Status Register
#define CTS_ACTIVE      0x01    // CTS Pin is Low
#define CTS_CHANGED     0x10


#endif /* __UART_H */
