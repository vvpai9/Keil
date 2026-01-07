/***********************************************************************
 * $Id:: lh7a404_aac.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 AAC definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         Advanced Audio Codec Controller
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

#ifndef LH7A404_AAC_H
#define LH7A404_AAC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * AAC Module Register Structure
 **********************************************************************/

/* AAC Module FIFOs Register Structure */ 
typedef struct
{
    volatile UNS_32 dr;      /* AAC data register */
    volatile UNS_32 rxcr;    /* AAC receive control register */
    volatile UNS_32 txcr;    /* AAC transmit control register */
    volatile UNS_32 sr;      /* AAC status register */
    volatile UNS_32 risr;    /* AAC raw interrupt status register */
    volatile UNS_32 isr;     /* AAC interrupt status register */
    volatile UNS_32 ie;      /* AAC interrupt enable register */
    volatile UNS_32 reserved;
} AAC_FIFO_REGS_T;

/* AAC possible channels enumeration */
typedef enum {CH_1 = 0, CH_2, CH_3, CH_4, CH_NONE} AC97_CHANNEL_ID_T;

/* AAC Module Register Structure */ 
typedef struct
{
    /* AAC FIFO register sets */
    AAC_FIFO_REGS_T fifo[CH_4 + 1];
    volatile UNS_32 s1data;  /* AAC data Rx/Tx on SLOT1 */
    volatile UNS_32 s2data;  /* AAC data Rx/Tx on SLOT2 */
    volatile UNS_32 s12data; /* AAC data Rx/Tx on SLOT12 */
    volatile UNS_32 rgis;    /* AAC raw global int status register */
    volatile UNS_32 gis;     /* AAC global int status register */
    volatile UNS_32 ie;      /* AAC interrupt enable register */
    volatile UNS_32 eoi;     /* AAC end-of-interrupt register */
    volatile UNS_32 gcr;     /* AAC global control register */
    volatile UNS_32 reset;   /* AAC reset control register */
    volatile UNS_32 sync;    /* AAC sync control register */
    volatile UNS_32 gcis;    /* AAC global FIFO int status register */
} AAC_REGS_T;

/***********************************************************************
 * AAC data register definitions
 **********************************************************************/

/* AAC data register load macro */
#define DR_DATA(n)          ((n) & 0x000FFFFF)

/***********************************************************************
 * AAC receive and transmit control register definitions
 **********************************************************************/

/* AAC receive/transmit register receive enable bit */
#define RXTXCR_REN          0x00000001
/* AAC receive/transmit register slot FIFO assignment macro */
#define RXTXR_RX(n)         _BIT(n)
/* AAC receive/transmit register data sizing macro */
#define RXTXCR_RSIZE(n)     _SBF(13, 0x00000003 & (n))
/* AAC receive/transmit register compact mode enable bit */
#define RXTXCR_CM           0x00008000
/* AAC receive/transmit register FIFO disable bit */
#define RXTXCR_FDIS         0x00010000
/* AAC receive register timeout count load macro */
#define RXCR_TOC(n)         _SBF(17, 0x00000FFF & (n))

/***********************************************************************
 * AAC controller status register definitions
 **********************************************************************/

/* AAC status register receive FIFO empty bit */
#define SR_RXFE            0x00000001
/* AAC status register transmit FIFO empty bit */
#define SR_TXFE            0x00000002
/* AAC status register receive FIFO full bit */
#define SR_RXFF            0x00000004
/* AAC status register transmit FIFO full bit */
#define SR_TXFF            0x00000008
/* AAC status register transmit busy bit */
#define SR_TXBUSY          0x00000010
/* AAC status register receive overrun error bit */
#define SR_RXOE            0x00000020
/* AAC status register transmit underrun error bit */
#define SR_TXUE            0x00000040

/***********************************************************************
 * AAC interrupt status and enable register definitions
 **********************************************************************/

/* AAC interrupt transmit complete bit */
#define ISR_TCIS           0x00000001
/* AAC interrupt receive timeout bit */
#define ISR_RCIS           0x00000002
/* AAC interrupt transmit interrupt bit */
#define ISR_TIS            0x00000004
/* AAC interrupt receive interrupt bit */
#define ISR_RIS            0x00000008
/* AAC interrupt (all) bit mask */
#define ISR_MASK           0x0000000F

/***********************************************************************
 * AAC slot 1, slot2, and slot12 register definitions
 **********************************************************************/

/* AAC Slot1 data register bit mask */
#define S1DATA_MASK        0x0000007F
/* AAC Slot2 data register bit mask */
#define S2DATA_MASK        0x0000FFFF
/* AAC Slot12 data register bit mask */
#define S12DATA_MASK       0x000FFFFF

/***********************************************************************
 * AAC global interrupt status and enable register definitions
 **********************************************************************/

/* AAC interrupt status slot 1 transmit complete bit */
#define GIS_SLOT1TXCOMPLETE      0x00000001
/* AAC interrupt status slot 2 receive valid bit */
#define GIS_SLOT2RXVALID         0x00000002
/* AAC interrupt status GPIO transmission complete bit */
#define GIS_GPIOTXCOMPLETE       0x00000004
/* AAC interrupt status GPIO receive complete bit */
#define GIS_GPIOINTRX            0x00000008
/* AAC interrupt status raw wakeup bit */
#define GIS_RWIS                 0x00000010
/* AAC interrupt status CODEC ready bit */
#define GIS_CODECREADY           0x00000020

/***********************************************************************
 * AAC global end-of-interrupt register definitions
 **********************************************************************/

/* AAC end of interrupt wakeup interrupt status clear bit */
#define EOI_WISC                0x00000001
/* AAC CODEC ready interrupt status clear bit */
#define EOI_CODECREADY          0x00000002

/***********************************************************************
 * AAC global control register definitions
 **********************************************************************/

/* AAC global control AC97 enable bit */
#define GCR_AACIFE              0x00000001
/* AAC global control loopback mode enable bit */
#define GCR_LOOP                0x00000002
/* AAC global control override CODEC ready bit */
#define GCR_OCR                 0x00000004

/***********************************************************************
 * AAC reset register register definitions
 **********************************************************************/

/* AAC reset/sync registers timed reset bit */
#define RS_TIMEDRESET           0x00000001
/* AAC reset/sync registers forced reset bit */
#define RS_FORCEDRESET          0x00000002
/* AAC reset/sync registers enable forced reset bit */
#define RS_EFORCER              0x00000004

/***********************************************************************
 * AAC global control and interrupt status register definitions
 **********************************************************************/

/* AAC global control interrupt status FIFO 1 ISR copy mask */
#define GCIS_AACISR1            0x0000000F
/* AAC global control interrupt status FIFO 2 ISR copy mask */
#define GCIS_AACISR2            0x000000F0
/* AAC global control interrupt status FIFO 3 ISR copy mask */
#define GCIS_AACISR3            0x00000F00
/* AAC global control interrupt status FIFO 4 ISR copy mask */
#define GCIS_AACISR4            0x0000F000
/* AAC global control interrupt status global interrupt status copy
   mask */
#define GCIS_AACGIS             0x003F0000

/* Macro pointing to AAC registers */
#define AAC    ((AAC_REGS_T *)(AAC_BASE))

#endif /* LH7A404_AAC_H */
