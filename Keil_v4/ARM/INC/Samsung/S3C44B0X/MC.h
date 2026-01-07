/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  MC.H:  Header file for Memory Controller                                  */
/*         Samsung S3C44B0X                                                   */
/*                                                                            */
/******************************************************************************/

#ifndef __MC_H
#define __MC_H


#define MC_BASE     0x01C80000  // Memory Controller Base Address


// Memory Controller Registers
typedef struct {
  reg32 BWSCON;     // Bus Width & Wait Status Control
  reg32 BANKCON0;   // Bank0 (Boot ROM) Control
  reg32 BANKCON1;   // Bank1 Control
  reg32 BANKCON2;   // Bank2 Control
  reg32 BANKCON3;   // Bank3 Control
  reg32 BANKCON4;   // Bank4 Control
  reg32 BANKCON5;   // Bank5 Control
  reg32 BANKCON6;   // Bank6 Control
  reg32 BANKCON7;   // Bank7 Control
  reg32 REFRESH;    // DRAM/SDRAM REfresh Control
  reg32 BANKSIZE;   // Flexible Bank Size
  reg32 MRSRB6;     // SDRAM Mode register set Bank6
  reg32 MRSRB7;     // SDRAM Mode register set Bank7
} regMC;

#define pMC ((regMC *)MC_BASE)


#endif /* __MC_H */
