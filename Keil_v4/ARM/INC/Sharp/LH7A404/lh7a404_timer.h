/***********************************************************************
 * $Id:: lh7a404_timer.h 14 2007-08-28 16:08:18Z kevinw                $
 *
 * Project: LH7A404 timer definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for LH7A404 component:
 *         Timers
 *
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 **********************************************************************/

#ifndef LH7A404_TIMER_H
#define LH7A404_TIMER_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * Timers Module Register Structure
 **********************************************************************/

/* Timer Module Register Structure (for all timers) */ 
typedef struct
{
    volatile UNS_32  load;     /* Timer load value */
    volatile UNS_32  value;    /* Timer current count value */
    volatile UNS_32  control;  /* Timer control word */
    volatile UNS_32  clear;    /* Timer interrupt clear register */
} TIMER_REGS_T;

/***********************************************************************
 * Timer Load register defines
 **********************************************************************/

/* Timer maximum count value */
#define TIMER_MAXCOUNT       0xFFFF
/* Timer load value macro */
#define	TIMER_LOAD(n)        ((n) & TIMER_MAXCOUNT)

/**********************************************************************
 * Timer Control register defines
 *********************************************************************/

#define TIMER_CTRL_ENABLE    0x80 /* Timer enable macro */
#define TIMER_CTRL_DISABLE   0x00 /* Timer disable macro */
#define TIMER_CTRL_PERIODIC  0x40 /* Timer periodic mode macro */
#define TIMER_CTRL_FREERUN   0x00 /* Timer freerun mode macro */
#define TIMER_CTRL_508K      0x08 /* Timer 508KHz clock source macro */
#define TIMER_CTRL_2K        0x00 /* Timer 2KHz clock source macro */

/**********************************************************************
 * Buzzer Control (timers) register defines
 *********************************************************************/ 

#define	BZCONT_BZMOD         0x2  /* Timer 1 buzzer signal enable */
#define	BZCONT_BZTOG         0x1  /* Set state of buzzer (BZTOG) */

/* Macro pointing to timer registers at timer 1 base address */
#define TIMER1 ((TIMER_REGS_T *)(TIMER1_BASE))
/* Macro pointing to timer registers registers at timer 3 base address */
#define TIMER2 ((TIMER_REGS_T *)(TIMER2_BASE))
/* Macro pointing to timer registers at timer 3 base address */
#define TIMER3 ((TIMER_REGS_T *)(TIMER3_BASE))
/* Macro pointing to buzzer control register */
#define BZCONT * ((UNS_32 *)(BZCONT_BASE))

#endif /* LH7A404_TIMER_H */ 
