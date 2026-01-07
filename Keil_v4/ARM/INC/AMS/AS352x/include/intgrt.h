/******************************************************************************
**                                                                           **
**  Copyright (c) 2000 ARM Limited                                           **
**  All rights reserved                                                      **
**                                                                           **
******************************************************************************/

#ifndef __INTGRTDEF
#define __INTGRTDEF

/*****************************************************************************/
/*  Base addresses for standard memory-mapped peripherals                    */
/*****************************************************************************/
#define IntBase         0x14000000  /* Interrupt Controller Base             */
#define FIQBase         0x14000020  /* FIQ Controller Base                   */
#define CoreBase        0x10000000  /* Core Module Registers                 */

/*****************************************************************************/
/*  Definitions of IRQ and FIQ ids                                           */
/*****************************************************************************/
#define SOFTINT         0x000001
#define UARTINT0        0x000002
#define UARTINT1        0x000004
#define KBDINT          0x000008
#define MOUSEINT        0x000010
#define TIMERINT0       0x000020
#define TIMERINT1       0x000040
#define TIMERINT2       0x000080
#define RTCINT          0x000100
#define EXPINT0         0x000200
#define EXPINT1         0x000400
#define EXPINT2         0x000800
#define EXPINT3         0x001000
#define PCIINT0         0x002000
#define PCIINT1         0x004000
#define PCIINT2         0x008000
#define PCIINT3         0x010000
#define LINT            0x020000
#define DEGINT          0x040000
#define ENUMINT         0x080000
#define PCIINT          0x100000
#define APCIINT         0x200000

/*****************************************************************************/
/*  Retain previous definitions from PID7T board for code compatibility      */
/*****************************************************************************/
#define IRQSerialA      UARTINT0
#define IRQSerialB      UARTINT1
#define IRQTimer0       TIMERINT0
#define IRQTimer1       TIMERINT1
#define IRQTimer2       TIMERINT2

/*****************************************************************************/
/* RPS interrupt Controller IRQ register                                     */
/*****************************************************************************/
#define IRQStatus      ((volatile unsigned *)IntBase)
#define IRQRawStatus   ((volatile unsigned *)(IntBase + 0x04))
#define IRQEnable      ((volatile unsigned *)(IntBase + 0x08))
#define IRQEnableSet   ((volatile unsigned *)(IntBase + 0x08))
#define IRQEnableClear ((volatile unsigned *)(IntBase + 0x0c))
#define IRQSoft        ((volatile unsigned *)(IntBase + 0x10))

/*****************************************************************************/
/* RPS interrupt Controller FIQ register                                     */
/*****************************************************************************/
#define FIQStatus      ((volatile unsigned *)FIQBase)
#define FIQRawStatus   ((volatile unsigned *)(FIQBase + 0x04))
#define FIQEnable      ((volatile unsigned *)(FIQBase + 0x08))
#define FIQEnableSet   ((volatile unsigned *)(FIQBase + 0x08))
#define FIQEnableClear ((volatile unsigned *)(FIQBase + 0x0c))

/*****************************************************************************/
/*  Core Module Registers                                                    */
/*****************************************************************************/
#define CM_ID              ((volatile unsigned *)CoreBase)
#define CM_PROC            ((volatile unsigned *)(CoreBase + 0x004))
#define CM_OSC             ((volatile unsigned *)(CoreBase + 0x008))
#define CM_CTRL            ((volatile unsigned *)(CoreBase + 0x00C))
#define CM_STAT            ((volatile unsigned *)(CoreBase + 0x010))
#define CM_LOCK            ((volatile unsigned *)(CoreBase + 0x014))
#define CM_SDRAM           ((volatile unsigned *)(CoreBase + 0x020))
#define CM_IRQ_STAT        ((volatile unsigned *)(CoreBase + 0x040))
#define CM_IRQ_RSTAT       ((volatile unsigned *)(CoreBase + 0x044))
#define CM_IRQ_ENSET       ((volatile unsigned *)(CoreBase + 0x048))
#define CM_IRQ_ENCLR       ((volatile unsigned *)(CoreBase + 0x04C))
#define CM_SOFT_INTSET     ((volatile unsigned *)(CoreBase + 0x050))
#define CM_SOFT_INTCLR     ((volatile unsigned *)(CoreBase + 0x054))
#define CM_FIQ_STAT        ((volatile unsigned *)(CoreBase + 0x060))
#define CM_FIQ_RSTAT       ((volatile unsigned *)(CoreBase + 0x064))
#define CM_FIQ_ENSET       ((volatile unsigned *)(CoreBase + 0x068))
#define CM_FIQ_ENCLR       ((volatile unsigned *)(CoreBase + 0x06C))
#define CM_SPD_BASE        ((volatile unsigned *)(CoreBase + 0x100))

/*****************************************************************************/
/*  LED Control Registers & Idle Bit                                         */
/*****************************************************************************/
#define LED_ALPHA          (volatile unsigned *)0x1A000000
#define LED_LIGHTS         (volatile unsigned *)0x1A000004
#define LED_SWITCHES       (volatile unsigned *)0x1A000008
#define LED_IDLE           0x01



/* UART 0 */
#define __UART0_DR   *(volatile OS_U32*)0x16000000
#define __UART0_RSR  *(volatile OS_U32*)0x16000004
#define __UART0_ECR  *(volatile OS_U32*)0x16000004
#define __UART0_LCRH *(volatile OS_U32*)0x16000008
#define __UART0_LCRM *(volatile OS_U32*)0x1600000c
#define __UART0_LCRL *(volatile OS_U32*)0x16000010
#define __UART0_CR   *(volatile OS_U32*)0x16000014
#define __UART0_FR   *(volatile OS_U32*)0x16000018
#define __UART0_IIR  *(volatile OS_U32*)0x1600001c
#define __UART0_ICR  *(volatile OS_U32*)0x1600001c

/* UART 1 */
#define __UART1_DR   *(volatile OS_U32*)0x17000000
#define __UART1_RSR  *(volatile OS_U32*)0x17000004
#define __UART1_ECR  *(volatile OS_U32*)0x17000004
#define __UART1_LCRH *(volatile OS_U32*)0x17000008
#define __UART1_LCRM *(volatile OS_U32*)0x1700000c
#define __UART1_LCRL *(volatile OS_U32*)0x17000010
#define __UART1_CR   *(volatile OS_U32*)0x17000014
#define __UART1_FR   *(volatile OS_U32*)0x17000018
#define __UART1_IIR  *(volatile OS_U32*)0x1700001c
#define __UART1_ICR  *(volatile OS_U32*)0x1700001c

#define UART_WLEN_8BITS     (3<<5) /* word length */
#define UART_FIFO_ENABLE    (1<<4) /* fifo enable */
#define UART_TX_INTR_ENABLE (1<<5) /* tx intr enable */
#define UART_RX_INTR_ENABLE (1<<4) /* rx intr enable */
#define UART_ENABLE         1      /* enable uart */
#define UART_TX_FIFO_EMPTY  (1<<7) /* tx fifo empty */
#define UART_RX_FIFO_FULL   (1<<6) /* rx fifo full */
#define UART_TX_FIFO_FULL   (1<<5) /* tx fifo full */
#define UART_RX_FIFO_EMPTY  (1<<4) /* rx fifo empty */
#define UART_BUSY           (1<<3) /* uart busy */
#define UART_RX_INTR_STAT   (1<<1) /* receive interrupt status */
#define UART_TX_INTR_STAT   (1<<2) /* transmit interrupt status */



#define INTEGRATOR_SC_BASE              0x11000000
#define INTEGRATOR_SC_OSC_OFFSET        0x04
#define INTEGRATOR_SC_LOCK_OFFSET       0x1C
#define INTEGRATOR_SC_OSC               (INTEGRATOR_SC_BASE + INTEGRATOR_SC_OSC_OFFSET)
#define INTEGRATOR_SC_LOCK              (INTEGRATOR_SC_BASE + INTEGRATOR_SC_LOCK_OFFSET)

#define LM0_LEDS            0xC812000C
#define LM0_INT             0xC8120010
#define LM0_SW              0xC8120014
#define LM0_LEDSMUX         0xC8120018
#define LM0_NAFSEL          0xC812001C
#define LM0_TIMENA          0xC8120020
#define LM0_MISC            0xC8120024
#define LM0_LASEL           0xC8120028





#endif



