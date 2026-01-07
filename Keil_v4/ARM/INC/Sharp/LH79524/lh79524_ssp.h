/**********************************************************************
 * $Id:: lh79524_ssp.h 27 2007-08-31 19:35:06Z kevinw                  $
 *
 *  Project: LH79520 SSP controller header file
 *
 *  Description:
 *      This file contains the definitions for SSP controller on
 *      LH79520
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
 *********************************************************************/

#if !defined LH79520_SSP_H
#define LH79520_SSP_H

#include "lh79524_chip.h"

/**********************************************************************
 * Synchronous Serial Port Register Structure
 *********************************************************************/ 
typedef struct 
{
    volatile UNS_32 ctrl0;		/* control register 0 */
    volatile UNS_32 ctrl1;		/* control register 1 */
    volatile UNS_32 dr;			/* data register */
    volatile UNS_32 sr;			/* status register */
    volatile UNS_32 cpsr;		/* clock prescale register */
    volatile UNS_32 imsc;		/* interrupt mask set and clear register */
    volatile UNS_32 ris;		/* raw interrupt status register */
    volatile UNS_32 mis;		/* masked interrupt status register */
    volatile UNS_32 icr;		/* interrupt clear register */
    volatile UNS_32 dmacr;		/* DMA control register */
    
} SSP_REGS_T;

/**********************************************************************
 * Synchronous Serial Port Register Bit Fields
 *********************************************************************/ 

/**********************************************************************
 * SSP Control 0 Register Bit Fields
 *********************************************************************/ 
/* Valid range for argument to SSP_CR0_DSS(n) is [4-16] */ 
/* SSP control 0 register bit - Data Size Select */ 
#define SSP_CR0_DSS(n)  _SBF(0,(n)-1)   /* Data Size Select */ 
/* SSP control 0 register bit - Motorola SPI frame */ 
#define SSP_CR0_FRF_MOT _SBF(4,0)   /* Motorola SPI frame */ 
/* SSP control 0 register bit - TI synchronous serial frame */ 
#define SSP_CR0_FRF_TI  _SBF(4,1)   /* TI synchronous serial frame */ 
/* SSP control 0 register bit - National Microwire frame */ 
#define SSP_CR0_FRF_NS  _SBF(4,2)   /* National Microwire frame */ 
/* SSP control 0 register bit - SPI Polarity */ 
#define SSP_CR0_SPO     _BIT(6)     /* SPI Polarity */ 
/* SSP control 0 register bit - SPI Phase */ 
#define SSP_CR0_SPH     _BIT(7)     /* SPI Phase */ 
/* SSP control 0 register bit - Serial Clock Rate */ 
#define SSP_CR0_SCR(n)  _SBF(8,(n)) /* Serial Clock Rate */ 

/**********************************************************************
 * SSP Control 1 Register Bit Fields
 *********************************************************************/ 
/* SSP control 1 register bit - =1 Loopback mode enabled */ 
#define SSP_CR1_LBM     _BIT(0)     /* Loopback Mode is enabled */ 
/* SSP control 1 register bit - =1 SSP operation is enabled */
#define SSP_CR1_SSE     _BIT(1)     /* SSE operation is enabled */
/* SSP control 1 register bit - =1 device is slave, =0 device is master */ 
#define SSP_CR1_MS   	_BIT(2)     /* Master or Slave Mode Select */ 
/* SSP control 1 register bit - =1 SSPTX output disable in slave mode */ 
#define SSP_CR1_SOD     _BIT(3)     /* Slave Mode Output Disable */ 

/**********************************************************************
 * SSP Status Register Bit Fields
 *********************************************************************/ 
/* SSP status register bit field -  TX FIFO Empty */ 
#define SSP_SR_TFE      _BIT(0)     /* TX FIFO Empty */ 
/* SSP status register bit field -  TX FIFO not full */
#define SSP_SR_TNF      _BIT(1)     /* TX FIFO not full */
/* SSP status register bit field -  RX FIFO not empty */ 
#define SSP_SR_RNE      _BIT(2)     /* RX FIFO not empty */ 
/* SSP status register bit field -  RX FIFO full */ 
#define SSP_SR_RFF      _BIT(3)     /* RX FIFO full */ 
/* SSP status register bit field -  Busy flag */ 
#define SSP_SR_BSY      _BIT(4)     /* Busy flag */ 

/**********************************************************************
 * SSP Clock Prescale Divisor Register Bit Fields
 *********************************************************************/ 
#define SSP_CPSR_CPDVSR(n) _SBF(0,(n)&0xFE) /* Clock prescale divisor */

/**********************************************************************
 * SSP Interrupt Mask Set and Clear Register Bit Fields
 *********************************************************************/ 
/* SSP status register bit field -  =1 Receive Overrun interrupt not masked */ 
#define SSP_IMSC_RORIM  _BIT(0)     /* receive overrun interrupt mask bit */ 
/* SSP status register bit field -  =1 Recived Timeout interrupt not masked */
#define SSP_IMSC_RTIM   _BIT(1)     /* receive timeout interrupt mask bit */
/* SSP status register bit field -  =1 Receive FIFO interrupt not masked */ 
#define SSP_IMSC_RXIM   _BIT(2)     /* recieve FIFO interrupt mask bit */ 
/* SSP status register bit field -  =1 Transmit FIFO interrupt not masked */ 
#define SSP_IMSC_TXIM   _BIT(3)     /* transmit FIFO interrupt mask bit */ 

/**********************************************************************
 * SSP Raw Intrrupt Status Register Bit Fields
 *********************************************************************/ 
/* SSP status register bit field -  =1 Receive overrun raw interrupt asserted */ 
#define SSP_RIS_RORRIS  _BIT(0)     
/* SSP status register bit field -  =1 Recived Timeout raw interrupt asserted */
#define SSP_RIS_RTRIS   _BIT(1)     
/* SSP status register bit field -  =1 Receive FIFO raw interrupt asserted */ 
#define SSP_RIS_RXRIS   _BIT(2)     
/* SSP status register bit field -  =1 Transmit FIFO raw interrupt asserted */ 
#define SSP_RIS_TXRIS   _BIT(3)     

/**********************************************************************
 * SSP Masked Intrrupt Status Register Bit Fields
 *********************************************************************/ 
/* SSP status register bit field -  =1 Receive overrun masked interrupt asserted */ 
#define SSP_MIS_RORMIS  _BIT(0)     
/* SSP status register bit field -  =1 Recived Timeout masked interrupt asserted */
#define SSP_MIS_RTMIS   _BIT(1)     
/* SSP status register bit field -  =1 Receive FIFO masked interrupt asserted */ 
#define SSP_MIS_RXMIS   _BIT(2)     
/* SSP status register bit field -  =1 Transmit FIFO masked interrupt asserted */ 
#define SSP_MIS_TXMIS   _BIT(3)     

/**********************************************************************
 * SSP Intrrupt Clear Register Bit Fields
 *********************************************************************/ 
/* SSP status register bit field -  =1 Clear receive overrun interrupt */ 
#define SSP_ICR_RORIC  _BIT(0)     
/* SSP status register bit field -  =1 Clear received timeout interrupt */
#define SSP_ICR_RTIC   _BIT(1)     

/**********************************************************************
 * SSP DMA Control Register Bit Fields
 *********************************************************************/ 
/* SSP status register bit field -  =1 Receive DMA Enable */ 
#define SSP_DMACR_TXDMAE   _BIT(1)     
/* SSP status register bit field -  =1 Transmit DMA Enable */
#define SSP_DMACR_RXDMAE   _BIT(0)     

/* Macro pointing to SSP registers */
#define SSP    ((SSP_REGS_T *)(SSP_BASE))

#endif /* LH79520_SSP_H */ 
