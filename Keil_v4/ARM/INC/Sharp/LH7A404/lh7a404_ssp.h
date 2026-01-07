/***********************************************************************
 * $Id:: lh7a404_ssp.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 SSP definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for LH7A404 component:
 *         Synchronous Serial Port
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

#ifndef LH7A404_SSP_H
#define LH7A404_SSP_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * SSP Module Register Structure
 **********************************************************************/

/* Watchdog Timer Module Register Structure */ 
typedef struct 
{
    volatile UNS_32 cr0;     /* SSP control register 0 */
    volatile UNS_32 cr1;     /* SSP control register 1 */
    volatile UNS_32 iir_icr; /* SSP interrupt identification register
                                and Rx overrrun end of int register */
    volatile UNS_32 dr;      /* SSP data register */
    volatile UNS_32 cpsr;    /* SSP clock prescale register */
    volatile UNS_32 sr;      /* SSP status register */
} SSP_REGS_T;

/***********************************************************************
 * SSP control 0 register definitions
 **********************************************************************/

/* SSP data size load macro */
#define SSP_CR0_DSS(n)   _SBF(0, (((n) - 1) & 0xF)) // Data Size Select
/* SSP control 0 Motorola SPI mode */
#define SSP_CR0_FRF_MOT  0x00000000
/* SSP control 0 TI synchronous serial mode */
#define SSP_CR0_FRF_TI   0x00000010
/* SSP control 0 National Microwire mode */
#define SSP_CR0_FRF_NS   0x00000020
/* SSP control 0 protocol mask */
#define SSP_CR0_PRT_MSK  0x00000030
#define SSP_CR0_SSE      0x00000080   /* SSP control 0 enable bit */
/* SSP serial clock rate value load macro */
#define SSP_CR0_SCR(n)   _SBF(8, ((n) & 0xFF))

/***********************************************************************
 * SSP control 1 register definitions
 **********************************************************************/

/* SSP control 1 RX FIFO interrupt enable bit */
#define SSP_CR1_RIE      0x00000001
/* SSP control 1 TX FIFO interrupt enable bit */
#define SSP_CR1_TIE      0x00000002
/* SSP control 1 loopback mode enable bit */
#define SSP_CR1_LBM      0x00000004
/* SSP control 1 SCLK polarity bit */
#define SSP_CR1_SPO      0x00000008
/* SSP control 1 SCLK phase bit */
#define SSP_CR1_SPH      0x00000010
/* SSP control 1 RX Overrun Interrupt Enable bit */
#define SSP_CR1_RORIE    0x00000020
/* SSP control 1 FIFO Enable bit */
#define SSP_CR1_FEN      0x00000040
/* SSP control 1 TX Idle Interrupt Enable bit */
#define SSP_CR1_TXIDLE   0x00000080

/***********************************************************************
 * SSP interrupt identification register definitions
 **********************************************************************/

/* SSP interrupt identification Tx FIFO empty bit */
#define SSP_IIR_RIS      0x00000001
/* SSP interrupt identification Tx FIFO not full bit */
#define SSP_IIR_TIS      0x00000002
/* SSP interrupt identification RX FIFO overrun bit */
#define SSP_IIR_RORIS    0x00000040
/* SSP interrupt identification Tx idle bit */
#define SSP_IIR_TXIDLE   0x00000080

/***********************************************************************
 * SSP data register definitions
 **********************************************************************/

/* SSP data load macro */
#define SSP_DATAMASK(n)   ((n) & 0xFFFF)

/***********************************************************************
 * SSP clock prescaler register definitions
 **********************************************************************/

/* SSP clock prescaler load macro */
#define   SSP_CPSR_CPDVSR(n) _SBF(0, (n) & 0xFE)

/***********************************************************************
 * SSP status register definitions
 **********************************************************************/

/* SSP status TX FIFO not full bit */
#define SSP_SR_TNF      0x00000002
/* SSP status RX FIFO not empty bit */
#define SSP_SR_RNE      0x00000004
/* SSP status SSP Busy bit */
#define SSP_SR_BSY      0x00000008
/* SSP status TX FIFO Half-empty bit */
#define SSP_SR_THE      0x00000010
/* SSP status RX FIFO Half-full bit */
#define SSP_SR_RHF      0x00000020
/* SSP status RX Overrun bit */
#define SSP_SR_ROR      0x00000040
/* SSP status TX FIFO Empty bit */
#define SSP_SR_TFE      0x00000080
/* SSP status RX FIFO full bit */
#define SSP_SR_RFF      0x00000100

/* Macro pointing to SSP registers */
#define SSP  ((SSP_REGS_T *)(SSP_BASE))

#endif /* LH7A404_SSP_H */ 
