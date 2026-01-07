/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  IC.H:  Header file for Interrupt Controller                               */
/*         Samsung S3C44B0X                                                   */
/*                                                                            */
/******************************************************************************/

#ifndef __IC_H
#define __IC_H


#define IC_BASE     0x01E00000  // Interrupt Controller Base Address


// Interrupt Controller Registers
typedef struct {
  reg32 INTCON;     // Interrupt Control
  reg32 INTPND;     // Interrupt Request Status
  reg32 INTMOD;     // Interrupt Mode Control
  reg32 INTMSK;     // Interrupt Mask Control
  reg32 I_PSLV;     // IRQ Interrupt Previous Slave
  reg32 I_PMST;     // IRQ Interrupt Priority Master
  reg32 I_CSLV;     // IRQ Interrupt Current Slave
  reg32 I_CMST;     // IRQ Interrupt Current Master
  reg32 I_ISPR;     // IRQ Interrupt Pending Status
  reg32 I_ISPC;     // IRQ Interrupt Pending Clear
  reg32 rsrvd[4];
  reg32 F_ISPR;     // FIQ Interrupt Pending
  reg32 F_ISPC;     // FIQ Interrupt Pending Clear
} regIC;

#define pIC ((regIC *)IC_BASE)


// INTCON: Interrupt Control Register
#define FIQ_ENABLE      0x00
#define FIQ_DISABLE     0x01
#define IRQ_ENABLE      0x00
#define IRQ_DISABLE     0x02
#define VECT_IRQ        0x00
#define NONVECT_IRQ     0x04

// Interrupt Bit Masks
#define INT_ADC         0x00000001
#define INT_RTC         0x00000002
#define INT_UTXD1       0x00000004
#define INT_UTXD0       0x00000008
#define INT_SIO         0x00000010
#define INT_IIC         0x00000020
#define INT_URXD1       0x00000040
#define INT_URXD0       0x00000080
#define INT_TIMER5      0x00000100
#define INT_TIMER4      0x00000200
#define INT_TIMER3      0x00000400
#define INT_TIMER2      0x00000800
#define INT_TIMER1      0x00001000
#define INT_TIMER0      0x00002000
#define INT_UERR01      0x00004000
#define INT_WDT         0x00008000
#define INT_BDMA1       0x00010000
#define INT_BDMA0       0x00020000
#define INT_ZDMA1       0x00040000
#define INT_ZDMA0       0x00080000
#define INT_TICK        0x00100000
#define INT_EINT4567    0x00200000
#define INT_EINT3       0x00400000
#define INT_EINT2       0x00800000
#define INT_EINT1       0x01000000
#define INT_EINT0       0x02000000
#define INT_GLOBAL      0x04000000


#endif /* __IC_H */
