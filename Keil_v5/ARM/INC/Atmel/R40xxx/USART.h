/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  USART.H:  Header file for USART                                    */
/*                                                                     */
/***********************************************************************/

#ifndef __USART_H
#define __USART_H


/*------------------*/
/* USART0 Registers */
/*------------------*/
#define US0_CR     REG(USART0_BASE + 0x00) /* Control Register */
#define US0_MR     REG(USART0_BASE + 0x04) /* Mode Register */
#define US0_IER    REG(USART0_BASE + 0x08) /* Interrupt Enable Register */
#define US0_IDR    REG(USART0_BASE + 0x0C) /* Interrupt Disable Register */
#define US0_IMR    REG(USART0_BASE + 0x10) /* Interrupt Mask Register */
#define US0_CSR    REG(USART0_BASE + 0x14) /* Channel Status Register */
#define US0_RHR    REG(USART0_BASE + 0x18) /* Receiver Holding Register */
#define US0_THR    REG(USART0_BASE + 0x1C) /* Transmitter Holding Register */
#define US0_BRGR   REG(USART0_BASE + 0x20) /* Baud Rate Generator Register */
#define US0_RTOR   REG(USART0_BASE + 0x24) /* Receiver Time-out Register */
#define US0_TTGR   REG(USART0_BASE + 0x28) /* Transmitter Time-guard Register */
#define US0_RPR    REG(USART0_BASE + 0x30) /* Receiver Pointer Register */
#define US0_RCR    REG(USART0_BASE + 0x34) /* Receiver Counter Register */
#define US0_TPR    REG(USART0_BASE + 0x38) /* Transmitter Pointer Register */
#define US0_TCR    REG(USART0_BASE + 0x3C) /* Transmitter Counter Register */

/*------------------*/
/* USART1 Registers */
/*------------------*/
#define US1_CR     REG(USART1_BASE + 0x00) /* Control Register */
#define US1_MR     REG(USART1_BASE + 0x04) /* Mode Register */
#define US1_IER    REG(USART1_BASE + 0x08) /* Interrupt Enable Register */
#define US1_IDR    REG(USART1_BASE + 0x0C) /* Interrupt Disable Register */
#define US1_IMR    REG(USART1_BASE + 0x10) /* Interrupt Mask Register */
#define US1_CSR    REG(USART1_BASE + 0x14) /* Channel Status Register */
#define US1_RHR    REG(USART1_BASE + 0x18) /* Receiver Holding Register */
#define US1_THR    REG(USART1_BASE + 0x1C) /* Transmitter Holding Register */
#define US1_BRGR   REG(USART1_BASE + 0x20) /* Baud Rate Generator Register */
#define US1_RTOR   REG(USART1_BASE + 0x24) /* Receiver Time-out Register */
#define US1_TTGR   REG(USART1_BASE + 0x28) /* Transmitter Time-guard Register */
#define US1_RPR    REG(USART1_BASE + 0x30) /* Receiver Pointer Register */
#define US1_RCR    REG(USART1_BASE + 0x34) /* Receiver Counter Register */
#define US1_TPR    REG(USART1_BASE + 0x38) /* Transmitter Pointer Register */
#define US1_TCR    REG(USART1_BASE + 0x3C) /* Transmitter Counter Register */

/*------------------*/
/* USART2 Registers */
/*------------------*/
#define US2_CR     REG(USART2_BASE + 0x00) /* Control Register */
#define US2_MR     REG(USART2_BASE + 0x04) /* Mode Register */
#define US2_IER    REG(USART2_BASE + 0x08) /* Interrupt Enable Register */
#define US2_IDR    REG(USART2_BASE + 0x0C) /* Interrupt Disable Register */
#define US2_IMR    REG(USART2_BASE + 0x10) /* Interrupt Mask Register */
#define US2_CSR    REG(USART2_BASE + 0x14) /* Channel Status Register */
#define US2_RHR    REG(USART2_BASE + 0x18) /* Receiver Holding Register */
#define US2_THR    REG(USART2_BASE + 0x1C) /* Transmitter Holding Register */
#define US2_BRGR   REG(USART2_BASE + 0x20) /* Baud Rate Generator Register */
#define US2_RTOR   REG(USART2_BASE + 0x24) /* Receiver Time-out Register */
#define US2_TTGR   REG(USART2_BASE + 0x28) /* Transmitter Time-guard Register */
#define US2_RPR    REG(USART2_BASE + 0x30) /* Receiver Pointer Register */
#define US2_RCR    REG(USART2_BASE + 0x34) /* Receiver Counter Register */
#define US2_TPR    REG(USART2_BASE + 0x38) /* Transmitter Pointer Register */
#define US2_TCR    REG(USART2_BASE + 0x3C) /* Transmitter Counter Register */


/*-------------------------*/
/* US_CR: Control Register */
/*-------------------------*/
#define US_RSTRX           (1<<2)      /* Reset Receiver */
#define US_RSTTX           (1<<3)      /* Reset Transmitter */
#define US_RXEN            (1<<4)      /* Receiver Enable */
#define US_RXDIS           (1<<5)      /* Receiver Disable */
#define US_TXEN            (1<<6)      /* Transmitter Enable */
#define US_TXDIS           (1<<7)      /* Transmitter Disable */
#define US_RSTSTA          (1<<8)      /* Reset Status Bits */
#define US_STTBRK          (1<<9)      /* Start Break */
#define US_STPBRK          (1<<10)     /* Stop Break */
#define US_STTTO           (1<<11)     /* Start Time-out */
#define US_SENDA           (1<<12)     /* Send Address */

/*----------------------*/
/* US_MR: Mode Register */
/*----------------------*/

#define US_CLKS            (3<<4)      /* Clock Selection */
#define US_CLKS_MCK        (0<<4)      /* Master Clock */
#define US_CLKS_MCK8       (1<<4)      /* Master Clock divided by 8 */
#define US_CLKS_SCK        (2<<4)      /* External Clock */
#define US_CLKS_SLCK       (3<<4)      /* Slow Clock */

#define US_CHRL            (3<<6)      /* Character Length */
#define US_CHRL_5          (0<<6)      /* 5 bits */
#define US_CHRL_6          (1<<6)      /* 6 bits */
#define US_CHRL_7          (2<<6)      /* 7 bits */
#define US_CHRL_8          (3<<6)      /* 8 bits */

#define US_SYNC            (1<<8)      /* Synchronous Mode Enable */

#define US_PAR             (7<<9)      /* Parity Mode */
#define US_PAR_EVEN        (0<<9)      /* Even Parity */
#define US_PAR_ODD         (1<<9)      /* Odd Parity */
#define US_PAR_SPACE       (2<<9)      /* Space Parity to 0 */
#define US_PAR_MARK        (3<<9)      /* Marked Parity to 1 */
#define US_PAR_NO          (4<<9)      /* No Parity */
#define US_PAR_MULTIDROP   (6<<9)      /* Multi-drop Mode */

#define US_NBSTOP          (3<<12)     /* Stop Bit Number */
#define US_NBSTOP_1        (0<<12)     /* 1 Stop Bit */
#define US_NBSTOP_1_5      (1<<12)     /* 1.5 Stop Bits */
#define US_NBSTOP_2        (2<<12)     /* 2 Stop Bits */

#define US_CHMODE                  (3<<14)     /* Channel Mode */
#define US_CHMODE_NORMAL           (0<<14)     /* Normal Mode */
#define US_CHMODE_AUTOMATIC_ECHO   (1<<14)     /* Automatic Echo */
#define US_CHMODE_LOCAL_LOOPBACK   (2<<14)     /* Local Loopback */
#define US_CHMODE_REMOTE_LOOPBACK  (3<<14)     /* Remote Loopback */

#define US_MODE9           (1<<17)     /* 9 Bit Mode */

#define US_CLKO            (1<<18)     /* Baud Rate Output Enable */

/*------------------------------------*/
/* US_IER: Interrupt Enable  Register */
/* US_IDR: Interrupt Disable Register */
/* US_IMR: Interrupt Mask    Register */
/* US_CSR: Channel   Status  Register */
/*------------------------------------*/
#define US_RXRDY           (1<<0)      /* Receiver Ready */
#define US_TXRDY           (1<<1)      /* Transmitter Ready */
#define US_RXBRK           (1<<2)      /* Receiver Break */
#define US_ENDRX           (1<<3)      /* End of Receiver PDC Transfer */
#define US_ENDTX           (1<<4)      /* End of Transmitter PDC Transfer */
#define US_OVRE            (1<<5)      /* Overrun Error */
#define US_FRAME           (1<<6)      /* Framing Error */
#define US_PARE            (1<<7)      /* Parity Error */
#define US_TIMEOUT         (1<<8)      /* Receiver Timeout */
#define US_TXEMPTY         (1<<9)      /* Transmitter Empty */

#define US_MASK_IRQ_TX     (US_TXRDY | US_ENDTX | US_TXEMPTY)
#define US_MASK_IRQ_RX     (US_RXRDY | US_ENDRX | US_TIMEOUT)
#define US_MASK_IRQ_ERROR  (US_PARE  | US_FRAME | US_OVRE  | US_RXBRK)


#endif /* __USART_H */
