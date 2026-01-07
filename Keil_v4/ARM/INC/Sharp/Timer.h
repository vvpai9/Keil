/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  TIMER.H:  Header file for Timers                                          */
/*            Sharp LH754xx                                                   */
/*                                                                            */
/******************************************************************************/

#ifndef __TIMER_H
#define __TIMER_H


#define TIMER_BASE         0xFFFC4000                /* Timer Base Address */

#define TM0_CNTRL          REG16(TIMER_BASE + 0x00)  /* Timer0 Control */
#define TM0_CMP_CAP_CNTRL  REG16(TIMER_BASE + 0x04)  /* Timer0 Cmp/Cap Ctrl */
#define TM0_INT_CNTRL      REG16(TIMER_BASE + 0x08)  /* Timer0 Interrupt Ctrl */
#define TM0_STATUS         REG16(TIMER_BASE + 0x0C)  /* Timer0 Status */
#define TM0_CNT            REG16(TIMER_BASE + 0x10)  /* Timer0 Counter */
#define TM0_CMP0           REG16(TIMER_BASE + 0x14)  /* Timer0 Compare Reg. 0 */
#define TM0_CMP1           REG16(TIMER_BASE + 0x18)  /* Timer0 Compare Reg. 1 */
#define TM0_CAP0           REG16(TIMER_BASE + 0x1C)  /* Timer0 Capture Reg. 0 */
#define TM0_CAP1           REG16(TIMER_BASE + 0x20)  /* Timer0 Capture Reg. 1 */
#define TM0_CAP2           REG16(TIMER_BASE + 0x24)  /* Timer0 Capture Reg. 2 */
#define TM0_CAP3           REG16(TIMER_BASE + 0x28)  /* Timer0 Capture Reg. 3 */
#define TM0_CAP4           REG16(TIMER_BASE + 0x2C)  /* Timer0 Capture Reg. 4 */

#define TM1_CNTRL          REG16(TIMER_BASE + 0x30)  /* Timer1 Control */
#define TM1_INT_CNTRL      REG16(TIMER_BASE + 0x34)  /* Timer1 Interrupt Ctrl */
#define TM1_STATUS         REG16(TIMER_BASE + 0x38)  /* Timer1 Status */
#define TM1_CNT            REG16(TIMER_BASE + 0x3C)  /* Timer1 Counter */
#define TM1_CMP0           REG16(TIMER_BASE + 0x40)  /* Timer1 Compare Reg. 0 */
#define TM1_CMP1           REG16(TIMER_BASE + 0x44)  /* Timer1 Compare Reg. 1 */
#define TM1_CAP0           REG16(TIMER_BASE + 0x48)  /* Timer1 Capture Reg. 0 */
#define TM1_CAP1           REG16(TIMER_BASE + 0x4C)  /* Timer1 Capture Reg. 1 */

#define TM2_CNTRL          REG16(TIMER_BASE + 0x50)  /* Timer2 Control */
#define TM2_INT_CNTRL      REG16(TIMER_BASE + 0x54)  /* Timer2 Interrupt Ctrl */
#define TM2_STATUS         REG16(TIMER_BASE + 0x58)  /* Timer2 Status */
#define TM2_CNT            REG16(TIMER_BASE + 0x5C)  /* Timer2 Counter */
#define TM2_CMP0           REG16(TIMER_BASE + 0x60)  /* Timer2 Compare Reg. 0 */
#define TM2_CMP1           REG16(TIMER_BASE + 0x64)  /* Timer2 Compare Reg. 1 */
#define TM2_CAP0           REG16(TIMER_BASE + 0x68)  /* Timer2 Capture Reg. 0 */
#define TM2_CAP1           REG16(TIMER_BASE + 0x6C)  /* Timer2 Capture Reg. 1 */


#endif /* __TIMER_H */
