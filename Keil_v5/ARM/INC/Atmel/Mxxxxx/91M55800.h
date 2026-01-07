/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  91M55800.H:  Header file for AT91M55800A                           */
/*                                                                     */
/***********************************************************************/

#ifndef __91M55800_H
#define __91M55800_H


#define AT91M55800


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

#define ADC0_ID    15      /* Analog to Digital Converter Channel 0 */
#define ADC1_ID    16      /* Analog to Digital Converter Channel 1 */

#define DAC0_ID    17      /* Digital to Analog Converter Channel 0 */
#define DAC1_ID    18      /* Digital to Analog Converter Channel 1 */

#define RTC_ID     19      /* Real Time Clock */

#define APMC_ID    20      /* Advanced Power Management Controller */

#define SLCKIRQ_ID 23      /* Slow Clock Interrupt */
#define IRQ5_ID    24      /* External Interrupt 5 */
#define IRQ4_ID    25      /* External Interrupt 4 */
#define IRQ3_ID    26      /* External Interrupt 3 */
#define IRQ2_ID    27      /* External Interrupt 2 */
#define IRQ1_ID    28      /* External Interrupt 1 */
#define IRQ0_ID    29      /* External Interrupt 0 */

#define COMMRX_ID  30      /* RX Debug Communication Channel Interrupt */
#define COMMTX_ID  31      /* TX Debug Communication Channel Interrupt */


/*-----------------------*/
/* Peripheral Memory Map */
/*-----------------------*/

#define EBI_BASE     0xFFE00000    /* External Bus Interface */

#define APMC_BASE    0xFFFF4000    /* Advanced Power Management controller */

#define AIC_BASE     0xFFFFF000    /* Advanced Interrupt Controller */

#define PIOA_BASE    0xFFFEC000    /* Parallel I/O Controller A */
#define PIOB_BASE    0xFFFF0000    /* Parallel I/O Controller B */

#define TCB0_BASE    0xFFFD0000    /* Timer Counter Block 0 */
#define TCB1_BASE    0xFFFD4000    /* Timer Counter Block 1 */

#define USART0_BASE  0xFFFC0000    /* USART 0 */
#define USART1_BASE  0xFFFC4000    /* USART 1 */
#define USART2_BASE  0xFFFC8000    /* USART 2 */

#define SPI_BASE     0xFFFBC000    /* SPI */

#define RTC_BASE     0xFFFB8000    /* Real Time Clock */

#define WD_BASE      0xFFFF8000    /* Watchdog Timer */

#define SF_BASE      0xFFF00000    /* Special Functions */

#define ADC0_BASE    0xFFFB0000    /* Analog/Digital Converter 0 */
#define ADC1_BASE    0xFFFB4000    /* Analog/Digital Converter 1 */

#define DAC0_BASE    0xFFFA8000    /* Digital/Analog Converter 0 */
#define DAC1_BASE    0xFFFAC000    /* Digital/Analog Converter 1 */


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
#include "APMC.h"  /* Advanced Power Management Controller */
#include "AIC.h"   /* Advanced Interrupt Controller */
#include "PIO.h"   /* Parallel I/O Controller */
#include "TC.h"    /* Timer Counter */
#include "USART.h" /* USART */
#include "SPI.h"   /* SPI */
#include "RTC.h"   /* Real Time Clock */
#include "WD.h"    /* Watchdog Timer */
#include "SF.h"    /* Special Functions */
#include "ADC.h"   /* Analog/Digital Converter */
#include "DAC.h"   /* Digital/Analog Converter */


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
#define PIOIRQ4    3       /* External Interrupt 4 */
#define PIOIRQ5    4       /* External Interrupt 5 */

#define PIOAD0TRIG 6       /* ADC 0 External trigger */
#define PIOAD1TRIG 7       /* ADC 1 External trigger */

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


#endif /* __91M55800_H */
