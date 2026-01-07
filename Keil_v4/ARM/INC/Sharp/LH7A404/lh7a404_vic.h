/***********************************************************************
 * $Id:: lh7a404_vic.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 vectored interrupt controller definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         Vectored Interrupt Controller
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

#ifndef LH7A404_VIC_H
#define LH7A404_VIC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * VIC Module Register Structure
 **********************************************************************/

/* Vectored Interrupt Controller Module Register Structure */ 
typedef struct 
{
    volatile UNS_32 irqstatus;    /* VIC IRQ pending register */
    volatile UNS_32 fiqstatus;    /* VIC FIQ pending register */
    volatile UNS_32 rawstatus;    /* VIC raw interrupt register */
    volatile UNS_32 intsel;       /* VIC interrupt select register */
    volatile UNS_32 inten;        /* VIC interrupt enable register */
    volatile UNS_32 intenclr;     /* VIC interrupt disable register */
    volatile UNS_32 swint;        /* VIC software interrupt register */
    volatile UNS_32 swint_clr;    /* VIC software clear register */
    volatile UNS_32 prot_en;      /* VIC protection register */
    volatile UNS_32 reserved1[3];
    volatile PFV    vecaddr;      /* VIC vector address register */
    volatile PFV    nv_vecaddr;   /* VIC non-vectored address reg */
    volatile UNS_32 reserved2[50];
    volatile PFV    vecaddrs[16]; /* VIC vector address registers */
    volatile UNS_32 reserved3[48];
    volatile UNS_32 vec_cntl[16]; /* VIC vector control registers */
    volatile UNS_32 reserved4[48];
    volatile UNS_32 reserved5[4];
    volatile UNS_32 vecaddrout;   /* Vector address written to VIC1 */
} VIC_REGS_T;

/***********************************************************************
 * VIC Register Bit Fields
 **********************************************************************/

/* All VIC Interrupt Sources */
typedef enum {
    VIC_BROWNOUT = 0,
    VIC_FIRST_VIC1_INTERRUPT = VIC_BROWNOUT,
    VIC_WDTINTR,
    VIC_ARM_COMMRX,
    VIC_ARM_COMMTX,
    VIC_TC1UINTR,
    VIC_TC2UINTR,
    VIC_AACINTR,
    VIC_DMA_M2PCH0,
    VIC_DMA_M2PCH1,
    VIC_DMA_M2PCH2,
    VIC_DMA_M2PCH3,
    VIC_DMA_M2PCH4,
    VIC_DMA_M2PCH5,
    VIC_DMA_M2PCH6,
    VIC_DMA_M2PCH7,
    VIC_DMA_M2PCH8,
    VIC_DMA_M2PCH9,
    VIC_DMA_M2MCH0,
    VIC_DMA_M2MCH1,
    VIC_GPIO0INTR,
    VIC_GPIO1INTR,
    VIC_GPIO2INTR,
    VIC_GPIO3INTR,
    VIC_UNUSED_23,
    VIC_UNUSED_24,
    VIC_UNUSED_25,
    VIC_UNUSED_26,
    VIC_UNUSED_27,
    VIC_UNUSED_28,
    VIC_UNUSED_29,
    VIC_UNUSED_30,
    VIC_UNUSED_31,
    VIC_LAST_VIC1_INTERRUPT = VIC_UNUSED_31,
    VIC_BLINTR,
    VIC_FIRST_VIC2_INTERRUPT = VIC_BLINTR,
    VIC_BMIINTR,
    VIC_MCINTR,
    VIC_TICKINTR,
    VIC_WEINTR,
    VIC_RTCMINTR,
    VIC_UART1INTR,
    VIC_UART1ERRINTR,
    VIC_UART2INTR,
    VIC_UART2ERRINTR,
    VIC_UART3INTR,
    VIC_UART3ERRINTR,
    VIC_SCIINTR,
    VIC_ADCINTR,
    VIC_KMIINTR,
    VIC_GPIO4INTR,
    VIC_GPIO5INTR,
    VIC_GPIO6INTR,
    VIC_GPIO7INTR,
    VIC_TC3UINTR,
    VIC_LCDINTR,
    VIC_SSEOTINTR,
    VIC_SDMMCINTR,
    VIC_USBCINTR,
    VIC_USBHINTR,
    VIC_RESERVED57,
    VIC_UNUSED_58,
    VIC_UNUSED_59,
    VIC_UNUSED_60,
    VIC_UNUSED_61,
    VIC_UNUSED_62,
    VIC_UNUSED_63,
    VIC_LAST_VIC2_INTERRUPT = VIC_UNUSED_63,
    VIC_END_OF_INTERRUPTS
} VIC_INT_SOURCE_T;

/***********************************************************************
 * VIC1 register definitions for the IRQ status 1, FIQ status 1, raw
 * interrupt status 1, interrupt select 1, interrupt enable 1, interrupt
 * disable 1, interrupt clear 1, soft interrupt 1, and soft interrupt
 * clear 1 registers
 **********************************************************************/

#define VIC1_BROWNOUT        0x00000001 /* VIC1 brownout bit */
#define VIC1_WDTINTR         0x00000002 /* VIC1 wtahcdof timer bit */
#define VIC1_ARM_COMMRX      0x00000004 /* VIC1 ARM RX COMM bit */
#define VIC1_ARM_COMMTX      0x00000008 /* VIC1 ARM TX COMM bit */
#define VIC1_TC1OINTR        0x00000010 /* VIC1 Timer 1 underflow bit */
#define VIC1_TC2OINTR        0x00000020 /* VIC1 Timer 2 underflow bit */
#define VIC1_AACINTR         0x00000040 /* VIC1 Audio CODEC bit */
#define VIC1_DMA_M2PCH0      0x00000080 /* VIC1 DMA M2P channel 0 bit */
#define VIC1_DMA_M2PCH1      0x00000100 /* VIC1 DMA M2P channel 1 bit */
#define VIC1_DMA_M2PCH2      0x00000200 /* VIC1 DMA M2P channel 2 bit */
#define VIC1_DMA_M2PCH3      0x00000400 /* VIC1 DMA M2P channel 3 bit */
#define VIC1_DMA_M2PCH4      0x00000800 /* VIC1 DMA M2P channel 4 bit */
#define VIC1_DMA_M2PCH5      0x00001000 /* VIC1 DMA M2P channel 5 bit */
#define VIC1_DMA_M2PCH6      0x00002000 /* VIC1 DMA M2P channel 6 bit */
#define VIC1_DMA_M2PCH7      0x00004000 /* VIC1 DMA M2P channel 7 bit */
#define VIC1_DMA_M2PCH8      0x00008000 /* VIC1 DMA M2P channel 8 bit */
#define VIC1_DMA_M2PCH9      0x00010000 /* VIC1 DMA M2P channel 9 bit */
#define VIC1_DMA_M2MCH0      0x00020000 /* VIC1 DMA M2M channel 0 bit */
#define VIC1_DMA_M2MCH1      0x00040000 /* VIC1 DMA M2M channel 1 bit */
#define VIC1_GPIO0INTR       0x00080000 /* VIC1 GPIO port F0 bit */
#define VIC1_GPIO1INTR       0x00100000 /* VIC1 GPIO port F1 bit */
#define VIC1_GPIO2INTR       0x00200000 /* VIC1 GPIO port F2 bit */
#define VIC1_GPIO3INTR       0x00400000 /* VIC1 GPIO port F3 bit */
#define VIC1_UNUSED_23       0x00800000 /* VIC1 unused bit */
#define VIC1_UNUSED_24       0x01000000 /* VIC1 unused bit */
#define VIC1_UNUSED_25       0x02000000 /* VIC1 unused bit */
#define VIC1_UNUSED_26       0x04000000 /* VIC1 unused bit */
#define VIC1_UNUSED_27       0x08000000 /* VIC1 unused bit */
#define VIC1_UNUSED_28       0x10000000 /* VIC1 unused bit */
#define VIC1_UNUSED_29       0x20000000 /* VIC1 unused bit */
#define VIC1_UNUSED_30       0x40000000 /* VIC1 unused bit */
#define VIC1_UNUSED_31       0x80000000 /* VIC1 unused bit */
#define VIC1_ALL_MASK        0xFFFFFFFF /* VIC1 all interrupt bits */

/***********************************************************************
 * VIC2 register definitions for the IRQ status 2, FIQ status 2, raw
 * interrupt status 2, interrupt select 2, interrupt enable 2, interrupt
 * disable 2, interrupt clear 2, soft interrupt 2, and soft interrupt
 * clear 2 registers
 **********************************************************************/

#define VIC2_BLINTR          0x00000001 /* VIC2 battery low bit */
#define VIC2_BMIINTR         0x00000002 /* VIC2 battery monitor bit */
#define VIC2_MCINTR          0x00000004 /* VIC2 media change bit */
#define VIC2_TICKINTR        0x00000008 /* VIC2 64Hz tick bit */
#define VIC2_WEINTR          0x00000010 /* VIC2 Wtahcdog expired bit */
#define VIC2_RTCMINTR        0x00000020 /* VIC2 RTC match bit */
#define VIC2_UART1INTR       0x00000040 /* VIC2 UART 1 bit */
#define VIC2_UART1ERRINTR    0x00000080 /* VIC2 UART 1 error bit */
#define VIC2_UART2INTR       0x00000100 /* VIC2 UART 2 bit */
#define VIC2_UART2ERRINTR    0x00000200 /* VIC2 UART 2 error bit bit */
#define VIC2_UART3INTR       0x00000400 /* VIC2 UART 3 bit */
#define VIC2_UART3ERRINTR    0x00000800 /* VIC2 UART 3 error bit bit */
#define VIC2_SCIINTR         0x00001000 /* VIC2 Smartcard bit */
#define VIC2_ADCINTR         0x00002000 /* VIC2 ADC bit */
#define VIC2_KMIINTR         0x00004000 /* VIC2 Keyboard monitor bit */
#define VIC2_GPIO4INTR       0x00008000 /* VIC2 GPIO port F4 bit */
#define VIC2_GPIO5INTR       0x00010000 /* VIC2 GPIO port F5 bit */
#define VIC2_GPIO6INTR       0x00020000 /* VIC2 GPIO port F6 bit */
#define VIC2_GPIO7INTR       0x00040000 /* VIC2 GPIO port F7 bit */
#define VIC2_TC3OINTR        0x00080000 /* VIC2 Timer 3 underflow bit */
#define VIC2_LCDINTR         0x00100000 /* VIC2 LCD interrupt bit */
#define VIC2_SSEOTINTR       0x00200000 /* VIC2 SSP bit */
#define VIC2_SDMMCINTR       0x00400000 /* VIC2 SD/MMC bit */
#define VIC2_USBCINTR        0x00800000 /* VIC2 USB client bit */
#define VIC2_USBHINTR        0x01000000 /* VIC2 USB host bit */
#define VIC2_RESERVED57      0x02000000 /* VIC2 reserved bit */
#define VIC2_UNUSED_58       0x04000000 /* VIC2 unused bit */
#define VIC2_UNUSED_59       0x08000000 /* VIC2 unused bit */
#define VIC2_UNUSED_60       0x10000000 /* VIC2 unused bit */
#define VIC2_UNUSED_61       0x20000000 /* VIC2 unused bit */
#define VIC2_UNUSED_62       0x40000000 /* VIC2 unused bit */
#define VIC2_UNUSED_63       0x80000000 /* VIC2 unused bit */

/* Macro for selecting an interrupt bit */
#define VIC_INT_SELECT(n)    _BIT(n)

/***********************************************************************
 * VIC1 and VIC2 protection register definitions
 **********************************************************************/

/* VIC Protection enable bit */
#define VIC_PROT_EN          0x00000001

/***********************************************************************
 * VIC1 and VIC2 vector control register definitions
 **********************************************************************/

/* Vector interrupt source load macro */
#define VIC_VEC_SELECT(n)    ((n) & 0x0000001F)
/* Vector interrupt source mask */
#define VIC_VEC_SEL_MSK      0x0000001F
/* Vector interrupt enable bit */
#define VIC_VEC_EN           0x00000020

/* Macro pointing to vectored interrupt controller 1 registers */
#define VIC1 ((VIC_REGS_T *)(VIC1_BASE))
/* Macro pointing to vectored interrupt controller 2 registers */
#define VIC2 ((VIC_REGS_T *)(VIC2_BASE))

#endif /* LH7A404_VIC_H */ 
