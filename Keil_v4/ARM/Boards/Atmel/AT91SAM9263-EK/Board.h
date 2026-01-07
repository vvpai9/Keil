/******************************************************************************/
/* Board.H: AT91SAM9263 Evaluation Board Features Definitions                 */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/


#ifndef __BOARD_H
#define __BOARD_H

#pragma diag_suppress 61

/* Clock Definitions */
#define EXT_OSC         16367660        /* External Oscillator MAINCK */
#define MCK             100024589       /* Master Clock               */
#define PCK             100024589       /* Processor Clock            */
#define PLLA            200049178       /* PLL A Clock                */

#define BAUD(br)        ((MCK + 8*br)/(16*br))

/* LED's Definitions */
#define LED1            AT91C_PIO_PB8
#define LED2            AT91C_PIO_PC29

/* Push Button Definitions */
#define PB1             AT91C_PIO_PC4
#define PB2             AT91C_PIO_PC5
#define PB_MASK         (PB1 | PB2)

/* Absolute IO access macros */
#define pPIOA           AT91C_BASE_PIOA
#define pPIOB           AT91C_BASE_PIOB
#define pPIOC           AT91C_BASE_PIOC
#define pDBGU           AT91C_BASE_DBGU
#define pPITC           AT91C_BASE_PITC
#define pPMC            AT91C_BASE_PMC

#endif /* __BOARD_H */
