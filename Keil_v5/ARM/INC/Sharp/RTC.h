/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  RTC.H:  Header file for Real-Timer Clock (RTC)                            */
/*          Sharp LH754xx                                                     */
/*                                                                            */
/******************************************************************************/

#ifndef __RTC_H
#define __RTC_H


#define RTC_BASE    0xFFFE0000              /* RTC Base Address */

#define RTCDR0      REG16(RTC_BASE + 0x00)  /* Lower 16-bit Data Register */
#define RTCDR1      REG16(RTC_BASE + 0x04)  /* Upper 16-bit Data Register */
#define RTCMR0      REG16(RTC_BASE + 0x08)  /* Lower 16-bit Match Register */
#define RTCMR1      REG16(RTC_BASE + 0x0C)  /* Upper 16-bit Match Register */
#define RTCSTAT     REG16(RTC_BASE + 0x10)  /* Interrupt Status Register*/
#define RTCEOI      REG16(RTC_BASE + 0x10)  /* Interrupt Clear Register */
#define RTCLR0      REG16(RTC_BASE + 0x14)  /* Lower 16-bit Load Register */
#define RTCLR1      REG16(RTC_BASE + 0x18)  /* Upper 16-bit Load Register */
#define RTCCR       REG16(RTC_BASE + 0x1C)  /* Control Register */


#endif /* __RTC_H */
