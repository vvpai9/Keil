/***********************************************************************
 * $Id:: lh7a404_aci.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 ACI definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for LH7A404 component:
 *         Audio Codec Interface
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

#ifndef LH7A404_ACI_H
#define LH7A404_ACI_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * ACI Module Register Structure
 **********************************************************************/

/* ACI Module Register Structure */ 
typedef struct 
{
    volatile UNS_32 aci_data_reg; /* ACI Data register */ 
    volatile UNS_32 aci_ctrl_reg; /* ACI Control register */ 
    volatile UNS_32 aci_stat_reg; /* ACI Status register */
    volatile UNS_32 aci_eoi_reg;  /* ACI End Of Interrupt register */
    volatile UNS_32 clk_divide;   /* ACI Clock Divide register */
} ACI_REGS_T;

/***********************************************************************
 * Data Register Bit Field 
 **********************************************************************/

/* ACI data register load macro */
#define ACI_DATA_REG(n)          _SBF(0, (n & 0xFF))

/***********************************************************************
 * Control Register Bit Fields
 **********************************************************************/

#define ACI_TX_ENABLE            0x00000001 /* ACI Tx enable bit */
#define ACI_RX_ENABLE            0x00000002 /* ACI Rx enable bit */
/* ACI Tx interrupt enable bit */
#define ACI_RX_INT_ENABLE        0x00000004
/* ACI Rx interrupt enable bit */
#define ACI_TX_INT_ENABLE        0x00000008
#define ACI_LOOPBACK_ENABLE      0x00000010 /* ACI loopback mode bit */
/* ACI stop clock on Tx FIFO empty bit */
#define ACI_TXFE_STOP_CLK_ENABLE 0x00000020

/***********************************************************************
 * Status Register Bit Fields
 **********************************************************************/

#define ACI_RX_FIFO_EMPTY        0x00000001 /* ACI Rx FIFO empty bit */
#define ACI_TX_FIFO_FULL         0x00000002 /* ACI Tx FIFO empty bit */
#define ACI_RX_FIFO_FULL         0x00000004 /* ACI Rx FIFO full bit */
#define ACI_TX_FIFO_EMPTY        0x00000008 /* ACI Tx FIFO full bit */
/* ACI Rx interrupt bit (8 or more bytes of data in the Rx FIFO) */
#define ACI_RX_INT_STATUS        0x00000010
/* ACI Tx interrupt bit (8 or less bytes of data in the Tx FIFO) */
#define ACI_TX_INT_STATUS        0x00000020
#define ACI_RX_BUSY              0x00000040 /* ACI Rx busy bit */
#define ACI_TX_BUSY              0x00000080 /* ACI Tx busy bit */

/***********************************************************************
 * Clock Divider Register Bit Field
 **********************************************************************/

/* ACI clock divisor load macro */
#define ACI_CLK_DIV(n)           _SBF(0, (n & 0x3FF))

/* Macro pointing to ACI registers */
#define ACI  ((ACI_REGS_T *)(ACI_BASE))

#endif /* LH7A404_ACI_H */ 
