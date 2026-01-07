/***********************************************************************
 * $Id:: lh7a404_uart.h 14 2007-08-28 16:08:18Z kevinw                 $
 *
 * Project: LH7A404 UART definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         UART
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

#ifndef LH7A404_UART_H
#define LH7A404_UART_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * UART Module Register Structure
 **********************************************************************/

/* UART Module Register Structure (for all UARTs) */ 
typedef struct 
{
    volatile UNS_32 data;       /* UART data register */
    volatile UNS_32 lcr;        /* UART Line Control register */
    volatile UNS_32 bcr;        /* UART Baud Rate Control register */
    volatile UNS_32 control;    /* UART Control register */
    volatile UNS_32 status;     /* UART Status Flag register */
    volatile UNS_32 intraw;     /* UART Raw Interrupt register */
    volatile UNS_32 inte;       /* UART Interrupt Enable register */
    volatile UNS_32 intr;       /* UART Resultant Interrupt register */
    volatile UNS_32 dataerr;    /* UART data error register */
    volatile UNS_32 intclr;     /* UART Interrupt clear register */
    volatile UNS_32 dmacr;      /* UART DMA control register */
} UART_REGS_T;

/***********************************************************************
 * UART Data register defines
 **********************************************************************/

#define UART_DATA_BE      0x00000800    /* UART Break Error bit */
#define UART_DATA_OE      0x00000400    /* UART Overrun Error bit */
#define UART_DATA_PE      0x00000200    /* UART Parity Error bit */
#define UART_DATA_FE      0x00000100    /* UART Framing Error bit */
#define UART_DATA_MASK    0xFF          /* UART Data mask (8 bits) */

/***********************************************************************
 * UART Line Control register defines
 **********************************************************************/

/* UART data word length macro */
#define UART_LCR_WLEN(n)   ((_SBF(5, ((n) - 5))) & 0x00000060)
#define UART_LCR_WLEN5     0x00000000   /* UART 5 bit data mode */
#define UART_LCR_WLEN6     0x00000020   /* UART 6 bit data mode */
#define UART_LCR_WLEN7     0x00000040   /* UART 7 bit data mode */
#define UART_LCR_WLEN8     0x00000060   /* UART 8 bit data mode */
#define UART_LCR_FEN       0x00000010   /* UART FIFO Enable */
#define UART_LCR_STP1      0x00000000   /* UART One Stop Bits Select */
#define UART_LCR_STP2      0x00000008   /* UART Two Stop Bits Select */
#define UART_LCR_PEVEN     0x00000004   /* UART Even Parity Select */
#define UART_LCR_PODD      0x00000000   /* UART Odd Parity Select */
#define UART_LCR_PEN       0x00000002   /* UART Parity Enable */
#define UART_LCR_PNONE     0x00000000   /* UART Parity None */
#define UART_LCR_SENDBRK   0x00000001   /* UART Assert Break */

/***********************************************************************
 * UART Baud Rate Control register defines
 **********************************************************************/

#define UART_BCR_2400      0x000000BF   /* UART 2400 bps, 7MHz clk */
#define UART_BCR_4800      0x0000005F   /* UART 4800 bps, 7MHz clk */
#define UART_BCR_9600      0x0000002F   /* UART 9600 bps, 7MHz clk */
#define UART_BCR_19200     0x00000017   /* UART 19.2Kbps, 7MHz clk */
#define UART_BCR_28800     0x0000000F   /* UART 28.8Kbps, 7MHz clk */
#define UART_BCR_38400     0x0000000B   /* UART 38.4Kbps, 7MHz clk */
#define UART_BCR_57600     0x00000007   /* UART 57.6Kbps, 7MHz clk */
#define UART_BCR_115200    0x00000003   /* UART 115.2Kbps, 7MHz clk */
#define UART_BCR_153600    0x00000002   /* UART 153.6Kbps, 7MHz clk */
#define UART_BCR_230400    0x00000001   /* UART 230.4Kbps, 7MHz clk */
#define UART_BCR_460800    0x00000000   /* UART 460.8Kbps, 7MHz clk */
#define UART_BCR_921600    0x00000000   /* UART 921.6Kbps, 14MHz clk */

/***********************************************************************
 * UART Control register defines
 **********************************************************************/

#define UART_CNTL_SIRBD    0x00000080   /* UART SIR Blanking Disable */
#define UART_CNTL_LBE      0x00000040   /* UART Loop Back Enable */
#define UART_CNTL_MXP      0x00000020   /* UART Modem Polarity sel */
#define UART_CNTL_TXP      0x00000010   /* UART Tx Pin Polarity sel */
#define UART_CNTL_RXP      0x00000008   /* UART Rx Pin Polarity sel */
#define UART_CNTL_SIRLP    0x00000004   /* UART IrDA SIR Low Power */
#define UART_CNTL_SIR_EN   0x00000000   /* UART SIR Enable */
#define UART_CNTL_SIR_DIS  0x00000002   /* UART SIR disable bit */
#define UART_CNTL_EN       0x00000001   /* UART Enable */
#define UART_CNTL_DIS      0x00000000   /* UART Disable */

/***********************************************************************
 * UART Status register defines
 **********************************************************************/

#define UART_STATUS_TXFE   0x00000080   /* UART Transmit FIFO Empty */
#define UART_STATUS_RXFF   0x00000040   /* UART Receive FIFO Full */
#define UART_STATUS_TXFF   0x00000020   /* UART Transmit FIFO Full */
#define UART_STATUS_RXFE   0x00000010   /* UART Receive FIFO Empty */
#define UART_STATUS_BUSY   0x00000008   /* UART Transmitter Busy */
#define UART_STATUS_DCD    0x00000004   /* UART Data Carrier Detect */
#define UART_STATUS_DSR    0x00000002   /* UART Data Set Ready */
#define UART_STATUS_CTS    0x00000001   /* UART Clear To Send */

/***********************************************************************
 * UART Interrupt register defines (intraw, inte, intr)
 **********************************************************************/

#define UART_INTR_OVI      0x00000080   /* UART overrun err Interrupt */
#define UART_INTR_BEI      0x00000040   /* UART break error Interrupt */
#define UART_INTR_PEI      0x00000020   /* UART parity err Interrupt */
#define UART_INTR_FEI      0x00000010   /* UART frame error Interrupt */
#define UART_INTR_RTI      0x00000008   /* UART Rx Timeout Interrupt */
#define UART_INTR_MI       0x00000004   /* UART Modem Interrupt */
#define UART_INTR_TI       0x00000002   /* UART Tx Interrupt */
#define UART_INTR_RI       0x00000001   /* UART Rx Interrupt */

/***********************************************************************
 * UART Interrupt clear register defines
 **********************************************************************/

#define UART_INT_CL_OV     0x00000008   /* UART overrun err int clear */
#define UART_INT_CL_BE     0x00000004   /* UART break error int clear */
#define UART_INT_CL_PE     0x00000002   /* UART parity err int clear */
#define UART_INT_CL_FE     0x00000001   /* UART frame error int clear */

/***********************************************************************
 * UART DMA control register defines
 **********************************************************************/

#define UART_DMA_RX_EN     0x00000001   /* UART DMA RX enable */
#define UART_DMA_TX_EN     0x00000002   /* UART DMA TX enable */
#define UART_DMA_ERRDIS    0x00000004   /* UART DMA error disable bit */

/* Macro pointing to UART registers at UART 1 base address */
#define UART1  ((UART_REGS_T *)(UART1_BASE))
/* Macro pointing to UART registers at UART 2 base address */
#define UART2  ((UART_REGS_T *)(UART2_BASE))
/* Macro pointing to UART registers at UART 3 base address */
#define UART3  ((UART_REGS_T *)(UART3_BASE))

#endif /* LH7A404_UART_H */
