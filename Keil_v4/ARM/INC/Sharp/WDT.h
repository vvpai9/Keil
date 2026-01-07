/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  WDT.H:  Header file for Watchdog Timer (WDT)                              */
/*          Sharp LH754xx                                                     */
/*                                                                            */
/******************************************************************************/

#ifndef __WDT_H
#define __WDT_H


#define WDT_BASE    0xFFFE3000              /* WDT Base Address */

#define WDCTRL      REG32(WDT_BASE + 0x00)  /* Watchdog Control */
#define WDCNTR      REG16(WDT_BASE + 0x04)  /* Watchdog Counter Reset */
#define WDTSTR      REG32(WDT_BASE + 0x08)  /* Watchdog Register */
#define WDCNT0      REG8 (WDT_BASE + 0x0C)  /* Watchdog Counter Section 0 */
#define WDCNT1      REG8 (WDT_BASE + 0x10)  /* Watchdog Counter Section 1 */
#define WDCNT2      REG8 (WDT_BASE + 0x14)  /* Watchdog Counter Section 2 */
#define WDCNT3      REG8 (WDT_BASE + 0x18)  /* Watchdog Counter Section 3 */


#endif /* __WDT_H */
