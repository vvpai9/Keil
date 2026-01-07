/***********************************************************************
 * $Id:: lh7a404_bmi.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 BMI definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for LH7A404 component:
 *         Battery Monitor Interface
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

#ifndef LH7A404_BMI_H
#define LH7A404_BMI_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
* Battery Monitor Module Register Structure
***********************************************************************/

/* BMI Single Wire Interface Module Register Structure */
typedef struct
{
    volatile UNS_32 swidr;       /* SWI data register */
    volatile UNS_32 swicr;       /* SWI control register */
    volatile UNS_32 swisr;       /* SWI status register */
    volatile UNS_32 swirisr_eoi; /* SWI raw int status/clear register */
    volatile UNS_32 swiisr;      /* SWI interrupt status register */
    volatile UNS_32 swiie;       /* SWI interrupt enable register */
    volatile UNS_32 switr;       /* SWI timing register */
    volatile UNS_32 swibr;       /* SWI break register */
} BMI_SWI_REGS_T;

/* BMI Smart Battery Interface Module Register Structure */
typedef struct
{
    volatile UNS_32 sbidr;       /* SBI data register */
    volatile UNS_32 sbicr;       /* SBI control register */
    volatile UNS_32 sbicount;     /* SBI count register */
    volatile UNS_32 sbisr;       /* SBI status register */
    volatile UNS_32 sbirisr_eoi; /* SBI raw int status/clear register */
    volatile UNS_32 sbiisr;      /* SBI interrupt status register */
    volatile UNS_32 sbiie;       /* SBI interrupt enable register */
} BMI_SBI_REGS_T;

/***********************************************************************
 * SWI control register definitions
 **********************************************************************/

/* SWI control register start/stop invert bit */
#define  BMI_SWICR_SP_INVERT      0x00010000
/* SWI control register transfer reset bit */
#define  BMI_SWICR_T_RST          0x00008000
/* SWI control register read data size select load macro */
#define  BMI_SWICR_RDSS(n)        _SBF(9, ((n) & 0x000003F))
/* SWI control register write data/command size load macro */
#define  BMI_SWICR_WDCS(n)        _SBF(3, ((n) & 0x000003F))
/* SWI control register data invert bit */
#define  BMI_SWICR_SWIDINV        0x00000004
/* SWI control register generate break sequence bit */
#define  BMI_SWICR_GBS            0x00000002
/* SWI control register enable bit */
#define  BMI_SWICR_SWIEN          0x00000001

/***********************************************************************
 * SWI status register definitions
 **********************************************************************/

/* SWI status register collision bit */
#define  BMI_SWISR_COL            0x00000800
/* SWI status register transmit error flag bit */
#define  BMI_SWISR_TEF            0x00000400
/* SWI status register receive busy bit */
#define  BMI_SWISR_RXB            0x00000200
/* SWI status register break recovered flag bit */
#define  BMI_SWISR_BRF            0x00000100
/* SWI status register break recovery status bit */
#define  BMI_SWISR_BRS            0x00000080
/* SWI status register break status bit */
#define  BMI_SWISR_BKS            0x00000040
/* SWI status register received flag bit */
#define  BMI_SWISR_WRF            0x00000020
/* SWI status register transmitted flag bit */
#define  BMI_SWISR_WTF            0x00000010
/* SWI status register stop bit status bit */
#define  BMI_SWISR_PBS            0x00000008
/* SWI status register data bit status bit */
#define  BMI_SWISR_DBS            0x00000004
/* SWI status register start bit status bit */
#define  BMI_SWISR_SBS            0x00000002
/* SWI status register transmit busy bit */
#define  BMI_SWISR_TXB            0x00000001

/***********************************************************************
 * SWI interrupt status register definitions
 **********************************************************************/

/* SWI Interrupt Status Registers break recovered bit */
#define  BMI_SWIRISR_RBRIS        0x00000004
/* SWI Interrupt Status Register word received bit */
#define  BMI_SWIRISR_RWRIS        0x00000002
/* SWI Interrupt Status Register word transmitted bit */
#define  BMI_SWIRISR_RWTIS        0x00000001

/***********************************************************************
 * SWI timing register definitions
 **********************************************************************/

/* SWI Timing Register load macro */
#define  BMI_SWITR_BTG(n)         ((n) & 0x0000FFFF)

/***********************************************************************
 * SWI break register definitions
 **********************************************************************/

/* SWI Break Register break time load macro */
#define  BMI_SWIBR_BT(n)          _SBF(12, ((n) & 0x00000FFF))
/* SWI Break Register break recovery time load macro */
#define  BMI_SWIBR_BRT(n)         ((n) & 0x00000FFF)

/***********************************************************************
 * SBI control register definitions
 **********************************************************************/

/* SBI control register packet error code enabled flag bit */
#define  BMI_SBICR_PEF            0x02000000
/* SBI control register block read flag bit */
#define  BMI_SBICR_BRF            0x01000000
/* SBI control register timeout count value load macro */
#define  BMI_SBICR_TOC(n)         _SBF(13, ((n) & (_BITMASK(12))))
/* SBI control register receive FIFO disable bit */
#define  BMI_SBICR_RX_FDIS        0x00000800
/* SBI control register transmit FIFO disable bit */
#define  BMI_SBICR_TX_FDIS        0x00000400
/* SBI control register divisor factor load macro */
#define  BMI_SBICR_DIVFACT(n)     _SBF(2, ((n) & (_BITMASK(8))))
/* SBI control register transmit FIFO flush bit */
#define  BMI_SBICR_FFLUSH         0x00000002
/* SBI control register enable bit */
#define  BMI_SBICR_SMB_EN         0x00000001

/***********************************************************************
 * SBI interface count register definitions
 **********************************************************************/

/* SBI Interface Count register read byte count load macro */
#define  BMI_SBICOUNT_READ(n)     _SBF(10, ((n) & (_BITMASK(5))))
/* SBI Interface Count register repeat count load macro */
#define  BMI_SBICOUNT_REP(n)      _SBF(5, ((n) & (_BITMASK(5))))
/* SBI Interface Count register prewrite count load macro */
#define  BMI_SBICOUNT_PRE(n)      ((n) & (_BITMASK(5)))

/***********************************************************************
 * SBI status register definitions
 **********************************************************************/

/* SBI Status Register slave bus hold bit */
#define  BMI_SBISR_SBH            0x00001000
/* SBI Status Register clock low timeout bit */
#define  BMI_SBISR_CLT            0x00000800
/* SBI Status Register transmit underrun bit */
#define  BMI_SBISR_TXUE           0x00000400
/* SBI Status Register receive overrun bit */
#define  BMI_SBISR_RXOE           0x00000200
/* SBI Status Register acknowledge fail bit */
#define  BMI_SBISR_ACKFAIL        0x00000100
/* SBI Status Register read/not write (direction) bit */
#define  BMI_SBISR_RnW            0x00000080
/* SBI Status Register slave mode bit */
#define  BMI_SBISR_SLV            0x00000040
/* SBI Status Register master mode bit */
#define  BMI_SBISR_MSTR           0x00000020
/* SBI Status Register transmit busy bit */
#define  BMI_SBISR_TXBUSY         0x00000010
/* SBI Status Register transmit FIFO full bit */
#define  BMI_SBISR_TXFF           0x00000008
/* SBI Status Register receive FIFO full bit */
#define  BMI_SBISR_RXFF           0x00000004
/* SBI Status Register transmit FIFO empty bit */
#define  BMI_SBISR_TXFE           0x00000002
/* SBI Status Register receive FIFO empty bit */
#define  BMI_SBISR_RXFE           0x00000001

/***********************************************************************
 * SBI interrupt status register definitions
 **********************************************************************/

/* SBI Interrupt Status Register clock low timeout bit */
#define  BMI_SBIRISR_RCLTIS       0x00000080
/* SBI Interrupt Status Register slave transfer complete bit */
#define  BMI_SBIRISR_RSTCIS       0x00000040
/* SBI Interrupt Status Register arbitration lost bit */
#define  BMI_SBIRISR_RALIS        0x00000020
/* SBI Interrupt Status Register acknowledge failed bit */
#define  BMI_SBIRISR_RAFIS        0x00000010
/* SBI Interrupt Status Register receive interrupt bit */
#define  BMI_SBIRISR_RRIS         0x00000008
/* SBI Interrupt Status Register transmit interrupt bit */
#define  BMI_SBIRISR_RTIS         0x00000004
/* SBI Interrupt Status Register receive timeout interrupt bit */
#define  BMI_SBIRISR_RRTIS        0x00000002
/* SBI Interrupt Status Register transmit complete interrupt bit */
#define  BMI_SBIRISR_RMTCIS       0x00000001

/* Macro pointing to SWI registers */
#define BMI_SWI ((BMI_SWI_REGS_T *)(BMISWI_BASE))
/* Macro pointing to SBI registers */
#define BMI_SBI ((BMI_SBI_REGS_T *)(BMISBI_BASE))

#endif /* LH7A404_BMI_H */
