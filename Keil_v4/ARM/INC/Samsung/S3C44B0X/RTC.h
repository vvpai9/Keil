/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  RTC.H:  Header file for Real Time Clock (RTC)                             */
/*          Samsung S3C44B0X                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __RTC_H
#define __RTC_H


#define RTC_BASE    0x01D70040  // Real Time Clock Base Address


// Real Time Clock Registers
typedef struct {
  reg8  RTCCON;     // RTC Control
  reg8  pad0[15];
  reg8  RTCALM;     // RTC Alarm
  reg8  pad1[3];
  reg8  ALMSEC;     // Alarm Second
  reg8  pad2[3];
  reg8  ALMMIN;     // Alarm Minute
  reg8  pad3[3];
  reg8  ALMHOUR;    // Alarm Hour
  reg8  pad4[3];
  reg8  ALMDAY;     // Alarm Day
  reg8  pad5[3];
  reg8  ALMMON;     // Alarm Month
  reg8  pad6[3];
  reg8  ALMYEAR;    // Alarm Year
  reg8  pad7[3];
  reg8  RTCRST;     // RTC Round Reset
  reg8  pad8[3];
  reg8  BCDSEC;     // BCD Second
  reg8  pad9[3];
  reg8  BCDMIN;     // BCD Minute
  reg8  padA[3];
  reg8  BCDHOUR;    // BCD Hour
  reg8  padB[3];
  reg8  BCDDAY;     // BCD Day
  reg8  padC[3];
  reg8  BCDDATE;    // BCD Date
  reg8  padD[3];
  reg8  BCDMON;     // BCD Month
  reg8  padE[3];
  reg8  MCDYEAR;    // BCD Year
  reg8  padF[3];
  reg8  TICINT;     // Tick Time Count
  reg8  padG[3];
} regRTC;

#define pRTC ((regRTC *)RTC_BASE)


// RTCCON: RTC Control Register
#define RTCEN       0x00000001
#define CLKSEL      0x00000002
#define CNTSEL      0x00000004
#define CLKRST      0x00000008

// RTCALM: RTC Alarm Register
#define SECEN       0x00000001
#define MINEN       0x00000002
#define HOUREN      0x00000004
#define DAYEN       0x00000008
#define MONREN      0x00000010
#define YEAREN      0x00000020
#define ALMEN       0x00000040

// RTCRST: RTC Round Reset Register
#define SECCR_NONE  0x00000000
#define SECCR_30    0x00000003
#define SECCR_40    0x00000004
#define SECCR_50    0x00000005
#define SRSTEN      0x00000008

// TICNT: Tick Time Count Register
#define TICKINT_EN  0x00000080


#endif /* __RTC_H */
