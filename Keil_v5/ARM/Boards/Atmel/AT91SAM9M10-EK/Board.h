/******************************************************************************/
/* Board.H: AT91SAM9M10 Evaluation Board Features Definitions                 */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2013 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/


#ifndef __BOARD_H
#define __BOARD_H

#pragma diag_suppress 61,68

/* Clock Definitions */
#define EXT_OSC         12000000        /* External Oscillator MAINCK */
#define MCK             64500000        /* Master Clock               */
#define PCK             258000000       /* Processor Clock            */
#define PLLA            516000000       /* PLL A Clock                */

#define BAUD(br)        ((MCK + 8*br)/(16*br))

/* LED's Definitions */
#define LED1            AT91C_PIO_PD0
#define LED2            AT91C_PIO_PD31

#define LED_CNT         2
#define LED_MASK        (LED1 | LED2)

/* Push Button Definitions */
#define PB4             AT91C_PIO_PB7
#define PB5             AT91C_PIO_PB6
#define PB_MASK         (PB4 | PB5)

/* Absolute IO access macros */
#define pPIOA           AT91C_BASE_PIOA
#define pPIOB           AT91C_BASE_PIOB
#define pDBGU           AT91C_BASE_DBGU
#define pPITC           AT91C_BASE_PITC
#define pPMC            AT91C_BASE_PMC
#define pADC            AT91C_BASE_ADC

#endif /* __BOARD_H */
