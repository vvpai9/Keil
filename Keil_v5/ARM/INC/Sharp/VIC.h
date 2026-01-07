/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  VIC.H:  Header file for Vectored Interrupt Controller (VIC)               */
/*          Sharp LH754xx                                                     */
/*                                                                            */
/******************************************************************************/

#ifndef __VIC_H
#define __VIC_H


#define VIC_BASE        0xFFFFF000                /* VIC Base Address */

#define VICIRQStatus    REG32(VIC_BASE + 0x0000)  /* IRQ Status */
#define VICFIQStatus    REG32(VIC_BASE + 0x0004)  /* FIQ Status */
#define VICRawIntr      REG32(VIC_BASE + 0x0008)  /* Raw Interrupt Status */
#define VICIntSelect    REG32(VIC_BASE + 0x000C)  /* Interrupt Select */
#define VICIntEnable    REG32(VIC_BASE + 0x0010)  /* Interrupt Enable */
#define VICIntEnClr     REG32(VIC_BASE + 0x0014)  /* Interrupt Enable Clear */
#define VICSoftInt      REG32(VIC_BASE + 0x0018)  /* Software Interrupt */
#define VICSoftIntClr   REG32(VIC_BASE + 0x001C)  /* Software Interrupt Clear */
#define VICVectAddr     REG32(VIC_BASE + 0x0030)  /* Vector Address */
#define VICDefVectAddr  REG32(VIC_BASE + 0x0034)  /* Default Vector Address */
#define VICVectAddr0    REG32(VIC_BASE + 0x0100)  /* Vector Address 0 */
#define VICVectAddr1    REG32(VIC_BASE + 0x0104)  /* Vector Address 1 */
#define VICVectAddr2    REG32(VIC_BASE + 0x0108)  /* Vector Address 2 */
#define VICVectAddr3    REG32(VIC_BASE + 0x010C)  /* Vector Address 3 */
#define VICVectAddr4    REG32(VIC_BASE + 0x0110)  /* Vector Address 4 */
#define VICVectAddr5    REG32(VIC_BASE + 0x0114)  /* Vector Address 5 */
#define VICVectAddr6    REG32(VIC_BASE + 0x0118)  /* Vector Address 6 */
#define VICVectAddr7    REG32(VIC_BASE + 0x011C)  /* Vector Address 7 */
#define VICVectAddr8    REG32(VIC_BASE + 0x0120)  /* Vector Address 8 */
#define VICVectAddr9    REG32(VIC_BASE + 0x0124)  /* Vector Address 9 */
#define VICVectAddr10   REG32(VIC_BASE + 0x0128)  /* Vector Address 10 */
#define VICVectAddr11   REG32(VIC_BASE + 0x012C)  /* Vector Address 11 */
#define VICVectAddr12   REG32(VIC_BASE + 0x0130)  /* Vector Address 12 */
#define VICVectAddr13   REG32(VIC_BASE + 0x0134)  /* Vector Address 13 */
#define VICVectAddr14   REG32(VIC_BASE + 0x0138)  /* Vector Address 14 */
#define VICVectAddr15   REG32(VIC_BASE + 0x013C)  /* Vector Address 15 */
#define VICVectCntl0    REG32(VIC_BASE + 0x0200)  /* Vector Control 0 */
#define VICVectCntl1    REG32(VIC_BASE + 0x0204)  /* Vector Control 1 */
#define VICVectCntl2    REG32(VIC_BASE + 0x0208)  /* Vector Control 2 */
#define VICVectCntl3    REG32(VIC_BASE + 0x020C)  /* Vector Control 3 */
#define VICVectCntl4    REG32(VIC_BASE + 0x0210)  /* Vector Control 4 */
#define VICVectCntl5    REG32(VIC_BASE + 0x0214)  /* Vector Control 5 */
#define VICVectCntl6    REG32(VIC_BASE + 0x0218)  /* Vector Control 6 */
#define VICVectCntl7    REG32(VIC_BASE + 0x021C)  /* Vector Control 7 */
#define VICVectCntl8    REG32(VIC_BASE + 0x0220)  /* Vector Control 8 */
#define VICVectCntl9    REG32(VIC_BASE + 0x0224)  /* Vector Control 9 */
#define VICVectCntl10   REG32(VIC_BASE + 0x0228)  /* Vector Control 10 */
#define VICVectCntl11   REG32(VIC_BASE + 0x022C)  /* Vector Control 11 */
#define VICVectCntl12   REG32(VIC_BASE + 0x0230)  /* Vector Control 12 */
#define VICVectCntl13   REG32(VIC_BASE + 0x0234)  /* Vector Control 13 */
#define VICVectCntl14   REG32(VIC_BASE + 0x0238)  /* Vector Control 14 */
#define VICVectCntl15   REG32(VIC_BASE + 0x023C)  /* Vector Control 15 */
#define VICITOP1        REG32(VIC_BASE + 0x030C)  /* Test Output 1 */

/* Interrupt Position Assignments */
#define WDT_INT         0   /* Watchdog */
#define DBGCOMMRX_INT   2   /* ARM7TDMI Debug Rx */
#define DBGCOMMTX_INT   3   /* ARM7TDMI Debug Tx */
#define TIMER0_INT      4   /* Timer 0 */
#define TIMER1_INT      5   /* Timer 1 */
#define TIMER2_INT      6   /* Timer 2 */
#define EXT0_INT        7   /* External Interrupt 0 */
#define EXT1_INT        8   /* External Interrupt 0 */
#define EXT2_INT        9   /* External Interrupt 0 */
#define EXT3_INT        10  /* External Interrupt 0 */
#define EXT4_INT        11  /* External Interrupt 0 */
#define EXT5_INT        12  /* External Interrupt 0 */
#define EXT6_INT        13  /* External Interrupt 0 */
#define RTC_INT         15  /* RTC */
#define TSC_INT         16  /* Touch Screen Controller */
#define BOUT_INT        17  /* Brown Out */
#define PEN_INT         18  /* Pen */
#define LCD_INT         19  /* LCD */
#define SSPTX_INT       20  /* SSP Tx */
#define SSPRX_INT       21  /* SSP Rx */
#define SSPROR_INT      22  /* SSP Rx Overrun */
#define SSPRXTO_INT     23  /* SSP Rx Timeout */
#define SSP_INT         24  /* SSP */
#define UART1RX_INT     25  /* UART1 Rx */
#define UART1TX_INT     26  /* UART1 Tx */
#define UART1_INT       27  /* UART1 */
#define UART0_INT       28  /* UART0 */
#define UART2_INT       29  /* UART2 */
#define DMA_INT         30  /* DMA */
#define CAN_INT         31  /* CAN */


#endif /* __VIC_H */
