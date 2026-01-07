/*********************************************************************** 
 * $Id:: lh79524_uart.h 27 2007-08-31 19:35:06Z kevinw                 $
 * 
 * Project: LH79524
 * 
 * Description: 
 *     This file contains the structure definitions and manifest
 *     constants for the LH79524 component: UART0, UART1 & UART2
 * 
 *********************************************************************** 
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 **********************************************************************/
#ifndef LH79524_UART_H
#define LH79524_UART_H

#include "lh79524_chip.h"

/*********************************************************************** 
 * UART0/1/2 (16C550) Module Register Structure
 **********************************************************************/

typedef struct UART_REGS_S
{
/* Data register */
  volatile UNS_32 dr;         
/* Receive Status (read) and Error Clear (write) */
  volatile UNS_32 rsr_ecr;    
/* reserved */
  UNS_32   reserved1[4];      
/* Flag register */                          
  volatile UNS_32 fr;         
/* reserved */
  UNS_32   reserved2;   
/* IrDA Low Power Counter Register */ 
  volatile UNS_32 ilpr;
/* Integer Baud Rate Divisor */ 
  volatile UNS_32 ibrd;
/* Fractional Baud Rate Divisor */
  volatile UNS_32 fbrd;
/* Line Control HIGH Byte */
  volatile UNS_32 lcr_h;
/* Control register */
  volatile UNS_32 cr;
/* Interrupt FIFO Level Select */
  volatile UNS_32 ifls;
/* Interrupt Mask Set/Clear */
  volatile UNS_32 imsc;
/* Raw Interrupt Status */
  volatile UNS_32 ris;
/* Masked Interrupt Status */ 
  volatile UNS_32 mis;
/* Interrupt Clear */
  volatile UNS_32 icr;
/* DMA Control */
  volatile UNS_32 dmacr;
} UART_REGS_T, *PUART_REGS_T;

/***********************************************************************
 * UART 16C550 Register Bit Fields
 **********************************************************************/

/* UART Data Register Bit Field */

/* Framing Error */
#define UART_DR_FE            (0x00000100)
/* Parity Error */     
#define UART_DR_PE            (0x00000200) 
/* Break Error */           
#define UART_DR_BE            (0x00000400)
/* Overrun Error */
#define UART_DR_OE            (0x00000800)

/* UART Receive Status/Error Clear Register Bit Field */

/* Error Clear */
#define UART_ECR_CLEAR        (0x00000000)
/* Framing Error */         
#define UART_RSR_FE           (0x00000001)
/* Parity Error */
#define UART_RSR_PE           (0x00000002)
/* Break Error */
#define UART_RSR_BE           (0x00000004)
/* Overrun Error */ 
#define UART_RSR_OE           (0x00000008)

/* UART Flag Register Bit Field */

/* Busy */
#define UART_FR_BUSY          (0x00000008)      
/* Receive FIFO Empty */
#define UART_FR_RXFE          (0x00000010)
/* Transmit FIFO Full */
#define UART_FR_TXFF          (0x00000020)
/* Receive FIFO Full */ 
#define UART_FR_RXFF          (0x00000040)
/* Transmit FIFO Empty */
#define UART_FR_TXFE          (0x00000080)

/* UART Integer Baud Rate Register Bit Field */
#define UART_BRINT(uclk,baud)  (UNS_32)(uclk/(16*baud))
#define UART_BRFRAC(uclk,baud) (UNS_32)((((uclk%(16*baud))*4)/baud)+0.5)

/* UART Line Control Register Bit Field */

#define UART_LCR_PARITY_NONE  (0x00000000)
/* Send Break */ 
#define UART_LCR_BRK          (0x00000001)
/* Parity Enable */ 
#define UART_LCR_PEN          (0x00000002)
/* Even Parity Select */  
#define UART_LCR_EPS          (0x00000004)
/* One Stop Bit Select */ 
#define UART_LCR_STP1         (0x00000000)
/* Two Stop Bits Select */          
#define UART_LCR_STP2         (0x00000008)
/* Enable FIFOs */ 
#define UART_LCR_FEN          (0x00000010)
/* Word Length 5 bits */  
#define UART_LCR_WLEN5        (0x00000000)
/* Word Length 6 bits */ 
#define UART_LCR_WLEN6        (0x00000020)
/* Word Length 7 bits */ 
#define UART_LCR_WLEN7        (0x00000040)
/* Word Length 8 bits */ 
#define UART_LCR_WLEN8        (0x00000060)
 /* Stick Parity Select */  
#define UART_LCR_SPS          (0x00000080)


/* UART Control Register Bit Field */

/* UART Enable */ 
#define UART_CR_ENABLE        (0x00000001)
/* SIR Enable */ 
#define UART_CR_SIREN         (0x00000002)
/* SIR Low Power Mode */ 
#define UART_CR_SIRLP         (0x00000004)
/* Loopback Enable */ 
#define UART_CR_LBE           (0x00000080)
/* Transmit Enable */ 
#define UART_CR_TXE           (0x00000100)
/* Receive Enable */ 
#define UART_CR_RXE           (0x00000200)

/* Interrupt Bits for all Interrupt Registers */ 

/* Receive */ 
#define UART_INT_RX           (0x00000010)
/* Transmit */ 
#define UART_INT_TX           (0x00000020)
/* Receive Timeout */ 
#define UART_INT_RT           (0x00000040)
/* Framing Error */ 
#define UART_INT_FE           (0x00000080)
/* Parity Error */ 
#define UART_INT_PE           (0x00000100)
/* Break Error */ 
#define UART_INT_BE           (0x00000200)
/* Overrun Error */ 
#define UART_INT_OE           (0x00000400)

/* UART DMA Control Register Bit Field */

/* Receive DMA enable */
#define UART_DMACR_RXDMAE    (0x00000001) 
/* Transmit DMA enable */
#define UART_DMACR_TXDMAE    (0x00000002)
/* DMA on Error */
#define UART_DMACR_DMAONERR  (0x00000004)

/* Driver config macros */

/* Max number of 16C550 uarts on the chip */
#define N_UARTS           (3) 
/* Max tx/rx fifo depth */
#define MAX_FIFO_DEPTH    (16)
/* Clear all interrupts */
#define UART_CLR_ALL      (0xFFFF)
/* Mask all uart generated interrupts */
#define UART_IMASK_ALL    (0)
/* Mask for setting the tx fifo level */
#define UART_TX_FIFO_MASK (0xF8)
/* Mask for setting the rx fifo level */
#define UART_RX_FIFO_MASK (0xC7)

/* UART 16550 fifo levels */
typedef enum
{
  UART_FIFO_DEPTH_1_8 = 0,
  UART_FIFO_DEPTH_1_4,
  UART_FIFO_DEPTH_1_2,
  UART_FIFO_DEPTH_3_4,
  UART_FIFO_DEPTH_7_8
} UART_FIFO_DEPTH;

/* Macro pointing to UART registers at UART 0 base address */
#define UART0 ((UART_REGS_T *)(UART0_BASE))
/* Macro pointing to UART registers at UART 1 base address */
#define UART1 ((UART_REGS_T *)(UART1_BASE))
/* Macro pointing to UART registers at UART 2 base address */
#define UART2 ((UART_REGS_T *)(UART2_BASE))

#endif /* LH79524_UART_H */
