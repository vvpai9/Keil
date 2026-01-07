/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  91M42800.H:  Header file for AT91M42800A                           */
/*                                                                     */
/***********************************************************************/

#ifndef __91M42800_H
#define __91M42800_H


#define AT91M42800


/*-------------------------------------*/
/* Peripheral and Interrupt Identifier */
/*-------------------------------------*/

#define FIQ_ID     0       /* Fast Interrupt */

#define SW_ID      1       /* Software Interrupt */

#define US0_ID     2       /* USART Channel 0 */
#define US1_ID     3       /* USART Channel 1 */

#define SPIA_ID    4       /* SPI Channel A */
#define SPIB_ID    5       /* SPI Channel B */

#define TC0_ID     6       /* Timer Channel 0 */
#define TC1_ID     7       /* Timer Channel 1 */
#define TC2_ID     8       /* Timer Channel 2 */
#define TC3_ID     9       /* Timer Channel 3 */
#define TC4_ID     10      /* Timer Channel 4 */
#define TC5_ID     11      /* Timer Channel 5 */

#define ST_ID      12      /* System Timer */

#define PIOA_ID    13      /* Parallel I/O Controller A */
#define PIOB_ID    14      /* Parallel I/O Controller B */

#define PMC_ID     15      /* Power Management Controller */

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

#define SPIA_BASE    0xFFFC8000    /* SPI A */
#define SPIB_BASE    0xFFFCC000    /* SPI B */

#define ST_BASE      0xFFFF8000    /* System Timer */

#define SF_BASE      0xFFF00000    /* Special Functions */


/*-------------------------*/
/* Internal RAM Definition */
/*-------------------------*/

#define RAM_SIZE       (8*1024)
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
#include "ST.h"    /* System Timer */
#include "SF.h"    /* Special Functions */


/*------------------*/
/* Pin Multiplexing */
/*------------------*/

/* PIO Controller A */
#define PIOIRQ0    0       /* External Interrupt 0 */
#define PIOIRQ1    1       /* External Interrupt 1 */
#define PIOIRQ2    2       /* External Interrupt 2 */
#define PIOIRQ3    3       /* External Interrupt 3 */
#define PIOFIQ     4       /* Fast Interrupt */

#define PIOSCK0    5       /* USART 0 Clock Signal */
#define PIOTXD0    6       /* USART 0 Transmit Data */
#define PIORXD0    7       /* USART 0 Receive Data  */
#define PIOSCK1    8       /* USART 1 Clock Signal  */
#define PIOTXD1    9       /* USART 1 Transmit Data */
#define PIORXD1    10      /* USART 1 Receive Data  */

#define PIOSPCKA   11      /* SPI A Clock Signal */
#define PIOMISOA   12      /* SPI A Master In Slave */
#define PIOMOSIA   13      /* SPI A Master Out Slave */
#define PIONSSA    14
#define PIONPCSA0  14      /* SPI A Peripheral Chip Select 0 */
#define PIONPCSA1  15      /* SPI A Peripheral Chip Select 1 */
#define PIONPCSA2  16      /* SPI A Peripheral Chip Select 2 */
#define PIONPCSA3  17      /* SPI A Peripheral Chip Select 3 */

#define PIOSPCKB   18      /* SPI B Clock Signal */
#define PIOMISOB   19      /* SPI B Master In Slave */
#define PIOMOSIB   20      /* SPI B Master Out Slave */
#define PIONSSB    21
#define PIONPCSB0  21      /* SPI B Peripheral Chip Select 0 */
#define PIONPCSB1  22      /* SPI B Peripheral Chip Select 1 */
#define PIONPCSB2  23      /* SPI B Peripheral Chip Select 2 */
#define PIONPCSB3  24      /* SPI B Peripheral Chip Select 3 */

#define PIOMCKO    25      /* Master Clock Output */

#define PIOBMS     27      /* Boot Mode Select */

#define PIOPME     29      /* Protect Mode Enable */

/* PIO Controller B */
#define PIONCS2    0       /* Chip Select 2 */
#define PIONCS3    1       /* Chip Select 3 */
#define PIOCS7     2       /* Address 20/Chip Select 7 */
#define PIOCS6     3       /* Address 21/Chip Select 6 */
#define PIOCS5     4       /* Address 22/Chip Select 5 */
#define PIOCS4     5       /* Address 23/Chip Select 4 */

#define PIOTCLK0   6       /* Timer 0 Clock Signal */
#define PIOTIOA0   7       /* Timer 0 Signal A   */
#define PIOTIOB0   8       /* Timer 0 Signal B   */
#define PIOTCLK1   9       /* Timer 1 Clock Signal */
#define PIOTIOA1   10      /* Timer 1 Signal A */
#define PIOTIOB1   11      /* Timer 1 Signal B */
#define PIOTCLK2   12      /* Timer 2 Clock Signal */
#define PIOTIOA2   13      /* Timer 2 Signal A */
#define PIOTIOB2   14      /* Timer 2 Signal B */
#define PIOTCLK3   15      /* Timer 3 Clock Signal */
#define PIOTIOA3   16      /* Timer 3 Signal A */
#define PIOTIOB3   17      /* Timer 3 Signal B */
#define PIOTCLK4   18      /* Timer 4 Clock Signal */
#define PIOTIOA4   19      /* Timer 4 Signal A */
#define PIOTIOB4   20      /* Timer 4 Signal B */
#define PIOTCLK5   21      /* Timer 5 Clock Signal */
#define PIOTIOA5   22      /* Timer 5 Signal A */
#define PIOTIOB5   23      /* Timer 5 Signal B */


#endif /* __91M42800_H */
