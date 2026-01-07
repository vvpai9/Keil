/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  PWM.H:  Header file for PWM Timer                                         */
/*          Samsung S3C44B0X                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __PWM_H
#define __PWM_H


#define PWM_BASE    0x01D50000  // PWM Timer Base Address


// PWM Timer Registers
typedef struct {
  reg32 TCFG0;      // Timer Configuration 0
  reg32 TCFG1;      // Timer Configuration 1
  reg32 TCON;       // Timer Control
  reg32 TCNTB0;     // Timer Count Buffer 0
  reg32 TCMPB0;     // Timer Compare Buffer 0
  reg32 TCNTO0;     // Timer Count Observation 0
  reg32 TCNTB1;     // Timer Count Buffer 1
  reg32 TCMPB1;     // Timer Compare Buffer 1
  reg32 TCNTO1;     // Timer Count Observation 1
  reg32 TCNTB2;     // Timer Count Buffer 2
  reg32 TCMPB2;     // Timer Compare Buffer 2
  reg32 TCNTO2;     // Timer Count Observation 2
  reg32 TCNTB3;     // Timer Count Buffer 3
  reg32 TCMPB3;     // Timer Compare Buffer 3
  reg32 TCNTO3;     // Timer Count Observation 3
  reg32 TCNTB4;     // Timer Count Buffer 4
  reg32 TCMPB4;     // Timer Compare Buffer 4
  reg32 TCNTO4;     // Timer Count Observation 4
  reg32 TCNTB5;     // Timer Count Buffer 5
  reg32 TCNTO5;     // Timer Count Observation 5
} regPWM;

#define pPWM ((regPWM *)PWM_BASE)


// TCFG0: Timer Configuration 0 Register
// TCFG1: Timer Configuration 1 Register
#define MUX0_1_2        0x00000000
#define MUX0_1_4        0x00000001
#define MUX0_1_8        0x00000002
#define MUX0_1_16       0x00000003
#define MUX0_1_32       0x00000004
#define MUX1_1_2        0x00000000
#define MUX1_1_4        0x00000010
#define MUX1_1_8        0x00000020
#define MUX1_1_16       0x00000030
#define MUX1_1_32       0x00000040
#define MUX2_1_2        0x00000000
#define MUX2_1_4        0x00000100
#define MUX2_1_8        0x00000200
#define MUX2_1_16       0x00000300
#define MUX2_1_32       0x00000400
#define MUX3_1_2        0x00000000
#define MUX3_1_4        0x00001000
#define MUX3_1_8        0x00002000
#define MUX3_1_16       0x00003000
#define MUX3_1_32       0x00004000
#define MUX4_1_2        0x00000000
#define MUX4_1_4        0x00010000
#define MUX4_1_8        0x00020000
#define MUX4_1_16       0x00030000
#define MUX4_1_TCLK     0x00040000
#define MUX5_1_2        0x00000000
#define MUX5_1_4        0x00100000
#define MUX5_1_8        0x00200000
#define MUX5_1_16       0x00300000
#define MUX5_1_EXTCLK   0x00400000
#define DMA_NO          0x00000000
#define DMA_TIMER0      0x01000000
#define DMA_TIMER1      0x02000000
#define DMA_TIMER2      0x03000000
#define DMA_TIMER3      0x04000000
#define DMA_TIMER4      0x05000000
#define DMA_TIMER5      0x06000000

// TCON: Timer Control Register
#define T0_START        0x00000001
#define T0_UPDATE       0x00000002
#define T0_INVERT       0x00000004
#define T0_AUTOREL      0x00000008
#define DEAD_ZONE       0x00000010
#define T1_START        0x00000100
#define T1_UPDATE       0x00000200
#define T1_INVERT       0x00000400
#define T1_AUTOREL      0x00000800
#define T2_START        0x00001000
#define T2_UPDATE       0x00002000
#define T2_INVERT       0x00004000
#define T2_AUTOREL      0x00008000
#define T3_START        0x00010000
#define T3_UPDATE       0x00020000
#define T3_INVERT       0x00040000
#define T3_AUTOREL      0x00080000
#define T4_START        0x00100000
#define T4_UPDATE       0x00200000
#define T4_INVERT       0x00400000
#define T4_AUTOREL      0x00800000
#define T5_START        0x01000000
#define T5_UPDATE       0x02000000
#define T5_AUTOREL      0x04000000


#endif /* __PWM_H */
