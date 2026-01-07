/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  91M40400.H:  Header file for AT91M40400                            */
/*                                                                     */
/***********************************************************************/

#ifndef __91M40400_H
#define __91M40400_H


#define AT91M40400


/*-------------------------------------*/
/* Peripheral Identifier and Interrupt */
/*-------------------------------------*/

#define FIQ_ID     0       /* Fast Interrupt */

#define SW_ID      1       /* Software Interrupt */

#define US0_ID     2       /* USART Channel 0 */
#define US1_ID     3       /* USART Channel 1 */

#define TC0_ID     4       /* Timer Channel 0 */
#define TC1_ID     5       /* Timer Channel 1 */
#define TC2_ID     6       /* Timer Channel 2 */

#define WD_ID      7       /* Watchdog */

#define PIO_ID     8       /* Parallel I/O Controller */

#define IRQ0_ID    16      /* External Interrupt 0 */
#define IRQ1_ID    17      /* External Interrupt 1 */
#define IRQ2_ID    18      /* External Interrupt 2 */


/*-----------------------*/
/* Peripheral Memory Map */
/*-----------------------*/

#define EBI_BASE     0xFFE00000    /* External Bus Interface */

#define PS_BASE      0xFFFF4000    /* Power Saving */

#define AIC_BASE     0xFFFFF000    /* Advanced Interrupt Controller */

#define PIO_BASE     0xFFFF0000    /* Parallel I/O Controller */

#define TCB0_BASE    0xFFFE0000    /* Timer Counter Block */

#define USART0_BASE  0xFFFD0000    /* USART 0 */
#define USART1_BASE  0xFFFCC000    /* USART 1 */

#define WD_BASE      0xFFFF8000    /* Watchdog Timer */

#define SF_BASE      0xFFF00000    /* Special Functions */


/*-------------------------*/
/* Internal RAM Definition */
/*-------------------------*/

#define RAM_SIZE       (4*1024)
#define RAM_BASE       0x00000000
#define RAM_LIMIT      (RAM_BASE + RAM_SIZE)

/* The internal RAM is mapped at address 0x00300000 after reset
   until Remap command is performed on the EBI. */
#define RAM_BASE_BOOT  0x00300000


#include "ARM.h"   /* ARM Core */
#include "EBI.h"   /* External Bus Interface */
#include "PS.h"    /* Power Saving */
#include "AIC.h"   /* Advanced Interrupt Controller */
#include "PIO.h"   /* Parallel I/O Controller */
#include "TC.h"    /* Timer Counter */
#include "USART.h" /* USART */
#include "WD.h"    /* Watchdog Timer */
#include "SF.h"    /* Special Functions */


/*------------------*/
/* Pin Multiplexing */
/*------------------*/

/* PIO Controller  */
#define PIOTCLK0   0       /* Timer 0 Clock Signal */
#define PIOTIOA0   1       /* Timer 0 Signal A */
#define PIOTIOB0   2       /* Timer 0 Signal B */
#define PIOTCLK1   3       /* Timer 1 Clock Signal */
#define PIOTIOA1   4       /* Timer 1 Signal A */
#define PIOTIOB1   5       /* Timer 1 Signal B */
#define PIOTCLK2   6       /* Timer 2 Clock Signal */
#define PIOTIOA2   7       /* Timer 2 Signal A */
#define PIOTIOB2   8       /* Timer 2 Signal B */

#define PIOIRQ0    9       /* External Interrupt 0 */
#define PIOIRQ1    10      /* External Interrupt 1 */
#define PIOIRQ2    11      /* External Interrupt 2 */
#define PIOFIQ     12      /* Fast Interrupt */

#define PIOSCK0    13      /* USART 0 Clock Signal */
#define PIOTXD0    14      /* USART 0 Transmit Data */
#define PIORXD0    15      /* USART 0 Receive Data */
#define PIOSCK1    20      /* USART 1 Clock Signal */
#define PIOTXD1    21      /* USART 1 Transmit Data */
#define PIORXD1    22      /* USART 1 Receive Data */

#define PIOMCK0    25      /* Master Clock Output */
#define PIONCS2    26      /* Chip Select 2 */
#define PIONCS3    27      /* Chip Select 3 */
#define PIOCS7     28      /* Address 20/Chip Select 7 */
#define PIOCS6     29      /* Address 21/Chip Select 6 */
#define PIOCS5     30      /* Address 22/Chip Select 5 */
#define PIOCS4     31      /* Address 23/Chip Select 4 */


#endif /* __91M40400_H */
