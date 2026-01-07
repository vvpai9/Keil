/**********************************************************************
 * $Id:: lh79524_i2s.h 27 2007-08-31 19:35:06Z kevinw                  $
 *
 *  Project: LH79520 I2S controller header file
 *
 *  Description:
 *      This file contains definition for I2S controller on
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

#if !defined LH79524_I2S_H
#define LH79524_I2S_H

#include "lh79524_chip.h"

/***********************************************************************
 * I2SC Module Register Structures
 **********************************************************************/ 
/* typedef for I2S convertor */
typedef struct 
{
    volatile UNS_32 ctrl;    /* Control register */
    volatile UNS_32 stat;    /* Status register */
    volatile UNS_32 imsc;    /* Interrupt mask set and clear register */ 
    volatile UNS_32 ris;     /* Raw interrupt status register */ 
    volatile UNS_32 mis;     /* Masked interrupt status register */       
    volatile UNS_32 icr;     /* Interrupt clear register */ 
} I2S_REGS_T;

/***********************************************************************
 * ctrl - Control Register Bit Field
 **********************************************************************/ 
/* I2S control register bit - loopback mode */
#define I2S_CTRL_I2SLBM             _BIT(0)     
/* I2S control register bit - enable */
#define I2S_CTRL_I2SEN              _BIT(1)     
/* I2S control register bit - invert WS status bit */
#define I2S_CTRL_WSINV              _BIT(2)     
/* I2S control register bit - WS delay */
#define I2S_CTRL_WSDEL              _BIT(3)     
/* I2S control register bit - master clock invert */
#define I2S_CTRL_MCLKINV            _BIT(4)     

/***********************************************************************
 * status - Status Register Bit Field
 **********************************************************************/ 
/* I2S status register bit - I2S loopback mode */
#define I2S_STATUS_LBM              _BIT(0)     
/* I2S status register bit - WS value at pin */
#define I2S_STATUS_WS               _BIT(1)     
/* I2S status register bit - WS value for RX word */
#define I2S_STATUS_RXWS             _BIT(2)     
/* I2S status register bit - WS value for TX word */
#define I2S_STATUS_TXWS             _BIT(3)     
/* I2S status register bit - transmit FIFO empty */
#define I2S_STATUS_TFE              _BIT(4)     
/* I2S status register bit - transmit FIFO full */
#define I2S_STATUS_TFF              _BIT(5)     
/* I2S status register bit - receive FIFO empty */
#define I2S_STATUS_RFE              _BIT(6)     
/* I2S status register bit - receive FIFO full */
#define I2S_STATUS_RFF              _BIT(7)     
/* I2S status register bit - master or slave mode select */
#define I2S_STATUS_MS               _BIT(8)     

/***********************************************************************
 * IMSC - Interrupt Mask Register Bit Field
 **********************************************************************/ 
/* I2S IMSC register bit - receive overrun interrupt mask */
#define I2S_IMSC_RORIM              _BIT(0)     
/* I2S IMSC register bit - receive timeout interrupt mask */
#define I2S_IMSC_RTIM               _BIT(1)     
/* I2S IMSC register bit - receive FIFO interrupt mask */
#define I2S_IMSC_RXIM               _BIT(2)     
/* I2S IMSC register bit - transmit FIFO interrupt mask */
#define I2S_IMSC_TXIM               _BIT(3)     
/* I2S IMSC register bit - transmit underrun error mask */
#define I2S_IMSC_TXUEM              _BIT(4)     
/* I2S IMSC register bit - external codec protocol error mask */
#define I2S_IMSC_ECPEM              _BIT(5)     
/* I2S IMSC register bit - ssp protocol error mask */
#define I2S_IMSC_SSPPEM             _BIT(6)     

/***********************************************************************
 * RIS - Raw Interrupt Status Register Bit Field
 **********************************************************************/ 
/* I2S RIS register bit - receive overrun raw interrupt status */
#define I2S_RIS_RORRIS             _BIT(0)     /* Enable bit */ 
/* I2S RIS register bit - receive timeout raw interrupt status */
#define I2S_RIS_RTRIS              _BIT(1)     /* Source Reg inc.bit */ 
/* I2S RIS register bit - receive FIFO raw interrupt status */
#define I2S_RIS_RXRIS              _BIT(2)     /* Dest Reg inc.bit */ 
/* I2S RIS register bit - transmit FIFO raw interrupt status */
#define I2S_RIS_TXRIS              _BIT(3)     /* Dest Reg inc.bit */ 
/* I2S RIS register bit - transmit underrun error raw interrupt status */
#define I2S_RIS_TXUERIS            _BIT(4)     /* Dest Reg inc.bit */ 
/* I2S RIS register bit - external codec protocol error raw interrupt */
#define I2S_RIS_ECPERIS            _BIT(5)     /* Dest Reg inc.bit */ 
/* I2S RIS register bit - ssp protocol error raw interrupt status */
#define I2S_RIS_SSPPERIS           _BIT(6)     /* Dest Reg inc.bit */ 

/***********************************************************************
 * MIS - Masked Register Bit Field
 **********************************************************************/ 
/* I2S MIS register bit - receive overrun masked interrupt */
#define I2S_MIS_RORMIS             _BIT(0)     
/* I2S MIS register bit - receive timeout masked interrupt */
#define I2S_MIS_RTMIS              _BIT(1)     
/* I2S MIS register bit - receive FIFO masked interrupt */
#define I2S_MIS_RXMIS              _BIT(2)     
/* I2S MIS register bit - transmit FIFO masked interrupt */
#define I2S_MIS_TXMIS              _BIT(3)     
/* I2S MIS register bit - transmit underrun error masked interrupt */
#define I2S_MIS_TXUEMIS            _BIT(4)     
/* I2S MIS register bit - external codec protocol error masked interrupt */
#define I2S_MIS_ECPEMIS            _BIT(5)     
/* I2S MIS register bit - ssp protocol error masked interrupt status */
#define I2S_MIS_SSPPEMIS           _BIT(6)     

/***********************************************************************
 * ICR - Interrupt Clear Register Bit Field
 **********************************************************************/ 
/* I2S ICR register bit - transmit underrun error interrupt */
#define I2S_ICR_TXUEC              _BIT(4)     
/* I2S ICR register bit - external codec protocol error interrupt */
#define I2S_ICR_ECPEC              _BIT(5)     
/* I2S ICR register bit - ssp protocol error interrupt clear */
#define I2S_ICR_SSPPEC             _BIT(6)     

/* Macro pointing to I2SC registers */
#define I2S    ((I2S_REGS_T *)(I2S_BASE))
                        
#endif /* LH79520_I2S_H */ 
