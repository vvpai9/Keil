/***********************************************************************
 * $Id:: lh7a404_kmi.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 KMI definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         Keyboard and mouse (PS2) interface
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

#ifndef LH7A404_KMI_H
#define LH7A404_KMI_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * KMI Register Structure
 **********************************************************************/

/* KMI Module Register Structure */ 
typedef struct 
{
    volatile UNS_32 mkictrl;      /* KMI control register */ 
    volatile UNS_32 mkistatus;    /* KMI status register */ 
    volatile UNS_32 mkidata;      /* KMI data register */ 
    volatile UNS_32 mkiclkdiv;    /* KMI clock divider register */ 
    volatile UNS_32 mkiint;       /* KMI interrupt status register */ 
} KMI_REGS_T;

/***********************************************************************
 * KMI control register definitions
 **********************************************************************/

/* KMI control register PS2 type select */
#define KMI_PS2_TYPE     0x00000000
/* KMI control register no line control type select */
#define KMI_NLC_TYPE     0x00000020
/* KMI control register enable receiver interrupr bit */
#define KMI_RXINT_EN     0x00000010
/* KMI control register enable transmitter interrupt bit */
#define KMI_TXINT_EN     0x00000008
/* KMI control register interface enable interrupt bit */
#define KMI_ENABLE       0x00000004
/* KMI control register force data signal low bit */
#define KMI_FDATA_LOW    0x00000002
/* KMI control register force clock signal low bit */
#define KMI_FCLOCK_LOW   0x00000001

/***********************************************************************
 * KMI status register definitions
 **********************************************************************/

/* KMI status register transmit register empty bit */
#define KMI_TX_REG_EMPTY 0x00000040
/* KMI status register transmitter busy bit */
#define KMI_TX_BUSY      0x00000020
/* KMI status register receive register full bit */
#define KMI_RX_REG_FULL  0x00000010
/* KMI status register receiver busy bit */
#define KMI_RX_BUSY      0x00000008
/* KMI status register receiver parity was odd bit */
#define KMI_RX_PAR_ODD   0x00000004
/* KMI status register clock line state mask bit */
#define KMI_CLK_ST_MSK   0x00000002
/* KMI status register data line state mask bit */
#define KMI_DATA_ST_MSK  0x00000001

/***********************************************************************
 * KMI data register definitions
 **********************************************************************/

/* KMI data register value load macro */
#define KMI_DATA(n)      ((n) & 0x000000FF)

/***********************************************************************
 * KMI clock divider register definitions
 **********************************************************************/

/* KMI clock divider register value load macro */
#define KMI_CLKDIV(n)    ((n) & 0x0000000F)

/***********************************************************************
 * KMI interrupt status register definitions
 **********************************************************************/

/* KMI interrupt status register transmit interrupt pending bit */
#define KMI_TX_INT       0x00000002
/* KMI interrupt status register receive interrupt pending bit */
#define KMI_RX_INT       0x00000001

/* Macro pointing to KMI registers */
#define KMI    ((KMI_REGS_T *)(KMI_BASE))

#endif /* LH7A404_KMI_H */ 
