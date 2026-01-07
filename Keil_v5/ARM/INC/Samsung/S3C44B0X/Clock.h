/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  CLOCK.H:  Header file for Clock & Power Management                        */
/*            Samsung S3C44B0X                                                */
/*                                                                            */
/******************************************************************************/

#ifndef __CLOCK_H
#define __CLOCK_H


#define CLK_BASE    0x01D80000  // Clock & Power Management Base Address


// Clock & Power Management Registers
typedef struct {
  reg32 PLLCON;     // PLL Control
  reg32 CLKCON;     // Clock Control
  reg32 CLKSLOW;    // Slow Clock Control
  reg32 LOCKTIME;   // PLL Lock Time Counter
} regCLK;

#define pCLK ((regCLK *)CLK_BASE)


#endif /* __CLOCK_H */
