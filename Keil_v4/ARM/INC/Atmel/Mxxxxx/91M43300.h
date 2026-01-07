/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  91M43300.H:  Header file for AT91M43300                            */
/*                                                                     */
/***********************************************************************/

#ifndef __91M43300_H
#define __91M43300_H


#define AT91M43300


/*-------------------------------------*/
/* Peripheral and Interrupt Identifier */
/*-------------------------------------*/

#define FIQ_ID     0       /* Fast Interrupt */

#define SW_ID      1       /* Software Interrupt */

#define US0_ID     2       /* USART Channel 0 */
#define US1_ID     3       /* USART Channel 1 */
#define US2_ID     4       /* USART Channel 2 */

#define SPI_ID     5       /* SPI Channel */

#define TC0_ID     6       /* Timer Channel 0 */
#define TC1_ID     7       /* Timer Channel 1 */
#define TC2_ID     8       /* Timer Channel 2 */
#define TC3_ID     9       /* Timer Channel 3 */
#define TC4_ID     10      /* Timer Channel 4 */
#define TC5_ID     11      /* Timer Channel 5 */

#define WD_ID      12      /* Watchdog */

#define PIOA_ID    13      /* Parallel I/O Controller A */
#define PIOB_ID    14      /* Parallel I/O Controller B */

#define IRQ3_ID    28      /* External Interrupt 3 */
#define IRQ2_ID    29      /* External Interrupt 2 */
#define IRQ1_ID    30      /* External Interrupt 1 */
#define IRQ0_ID    31      /* External Interrupt 0 */


/*-----------------------*/
/* Peripheral Memory Map */
/*-----------------------*/

#define EBI_BASE     0xFFE00000    /* External Bus Interface */

#define PMC_BASE     0xFFFF4000    /* Power Management controller */

#define AIC_BASE     0xFFFFF000    /* Advanced Interrupt Controller */

#define PIOA_BASE    0xFFFEC000    /* Parallel I/O Controller A */
#define PIOB_BASE    0xFFFF0000    /* Parallel I/O Controller B */

#define TCB0_BASE    0xFFFD0000    /* Timer Counter Block 0 */
#define TCB1_BASE    0xFFFD4000    /* Timer Counter Block 1 */

#define USART0_BASE  0xFFFC0000    /* USART 0 */
#define USART1_BASE  0xFFFC4000    /* USART 1 */
#define USART2_BASE  0xFFFC8000    /* USART 2 */

#define SPI_BASE     0xFFFBC000    /* SPI */

#define WD_BASE      0xFFFF8000    /* Watchdog Timer */

#define SF_BASE      0xFFF00000    /* Special Functions */


/*-------------------------*/
/* Internal RAM Definition */
/*-------------------------*/

#define RAM_SIZE       (3*1024)
#define RAM_BASE       0x00000000
#define RAM_LIMIT      (RAM_BASE + RAM_SIZE)

/* The internal RAM is mapped at address 0x00300000 after reset
   until Remap command is performed on the EBI. */
#define RAM_BASE_BOOT  0x00300000


#include "ARM.h"   /* ARM Core */
#include "EBI.h"   /* External Bus Interface */
#include "PMC.h"   /* Power Management Controller */
#include "AIC.h"   /* Advanced Interrupt Controller */
#include "PIO.h"   /* Parallel I/O Controller */
#include "TC.h"    /* Timer Counter */
#include "USART.h" /* USART */
#include "SPI.h"   /* SPI */
#include "WD.h"    /* Watchdog Timer */
#include "SF.h"    /* Special Functions */


/*------------------*/
/* Pin Multiplexing */
/*------------------*/

/* PIO Controller A */
#define PIOTCLK3   0       /* Timer 3 Clock Signal */
#define PIOTIOA3   1       /* Timer 3 Signal A */
#define PIOTIOB3   2       /* Timer 3 Signal B */
#define PIOTCLK4   3       /* Timer 4 Clock Signal */
#define PIOTIOA4   4       /* Timer 4 Signal A */
#define PIOTIOB4   5       /* Timer 4 Signal B */
#define PIOTCLK5   6       /* Timer 5 Clock Signal */
#define PIOTIOA5   7       /* Timer 5 Signal A */
#define PIOTIOB5   8       /* Timer 5 Signal B */

#define PIOIRQ0    9       /* External Interrupt 0 */
#define PIOIRQ1    10      /* External Interrupt 1 */
#define PIOIRQ2    11      /* External Interrupt 2 */
#define PIOIRQ3    12      /* External Interrupt 3 */
#define PIOFIQ     13      /* Fast Interrupt */

#define PIOSCK0    14      /* USART 0 Clock Signal */
#define PIOTXD0    15      /* USART 0 Transmit Data */
#define PIORXD0    16      /* USART 0 Receive Data  */
#define PIOSCK1    17      /* USART 1 Clock Signal  */
#define PIOTXD1    18      /* USART 1 Transmit Data */
#define PIORXD1    19      /* USART 1 receive Data  */
#define PIOSCK2    20      /* USART 2 Clock Signal */
#define PIOTXD2    21      /* USART 2 Transmit Data */
#define PIORXD2    22      /* USART 2 Receive Data  */

#define PIOSPCK    23      /* SPI Clock Signal */
#define PIOMISO    24      /* SPI Master In Slave */
#define PIOMOSI    25      /* SPI Master Out Slave */
#define PIONSS     26
#define PIONPCS0   26      /* SPI Peripheral Chip Select 0 */
#define PIONPCS1   27      /* SPI Peripheral Chip Select 1 */
#define PIONPCS2   28      /* SPI Peripheral Chip Select 2 */
#define PIONPCS3   29      /* SPI Peripheral Chip Select 3 */

/* PIO Controller B */
#define PIOBMS     18      /* Boot Mode Select */

#define PIOTCLK0   19      /* Timer 0 Clock Signal */
#define PIOTIOA0   20      /* Timer 0 Signal A   */
#define PIOTIOB0   21      /* Timer 0 Signal B   */
#define PIOTCLK1   22      /* Timer 1 Clock Signal */
#define PIOTIOA1   23      /* Timer 1 Signal A */
#define PIOTIOB1   24      /* Timer 1 Signal B */
#define PIOTCLK2   25      /* Timer 2 Clock Signal */
#define PIOTIOA2   26      /* Timer 2 Signal A */
#define PIOTIOB2   27      /* Timer 2 Signal B */


#endif /* __91M43300_H */
