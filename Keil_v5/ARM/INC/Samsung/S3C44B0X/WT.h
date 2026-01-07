/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  WT.H:  Header file for Watchdog Timer                                     */
/*         Samsung S3C44B0X                                                   */
/*                                                                            */
/******************************************************************************/

#ifndef __WT_H
#define __WT_H


#define WT_BASE     0x01D30000  // Watchdog Timer Base Address


// Watchdog Timer Registers
typedef struct {
  reg32 WTCON;      // Watchdog Timer Mode
  reg32 WTDAT;      // Watchdog Timer Data
  reg32 WTCNT;      // Watchdog Timer Count
} regWT;

#define pWT ((regWT *)WT_BASE)


#endif /* __WT_H */
