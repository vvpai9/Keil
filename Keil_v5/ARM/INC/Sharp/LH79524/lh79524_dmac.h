/**********************************************************************
 * $Id:: lh79524_dmac.h 27 2007-08-31 19:35:06Z kevinw                 $
 *
 *  Project: LH79520 DMA controller header file
 *
 *  Description:
 *      This file contains definition for DMA controller on
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

#if !defined LH79520_DMAC_H
#define LH79520_DMAC_H

#include "lh79524_chip.h"

/***********************************************************************
 * DMAC Module Register Structures
 **********************************************************************/ 
/* typedef for DMA stream */
typedef struct 
{
    volatile UNS_32 sourcelo; /* Source base addr, lo 16 bits */
    volatile UNS_32 sourcehi; /* Source base addr, hi 16 bits */
    volatile UNS_32 destlo;   /* Dest base addr, lo 16 bits */ 
    volatile UNS_32 desthi;   /* Dest base addr, hi 16 bits */ 
    volatile UNS_32 max;      /* Maximum Count */       
    volatile UNS_32 ctrl;     /* Control */ 
    volatile UNS_32 socurrhi; /* Current src addr, hi 16 bits*/ 
    volatile UNS_32 socurrlo; /* Current src addr, lo 16 bits*/ 
    volatile UNS_32 decurrhi; /* Curr dest addr, hi 16 bits*/ 
    volatile UNS_32 decurrlo; /* Curr src addr, lo 16 bits*/ 
    volatile UNS_32 tcnt;     /* Terminal Count */      
} DATA_STREAM_REG_TYPE;

/* typedef for DMA controller */
typedef struct 
{
    DATA_STREAM_REG_TYPE  stream0;    /* Data Stream 0 */ 
    volatile UNS_32 reserved0[5];
    DATA_STREAM_REG_TYPE  stream1;    /* Data Stream 1 */ 
    volatile UNS_32 reserved1[5];
    DATA_STREAM_REG_TYPE  stream2;    /* Data Stream 2 */ 
    volatile UNS_32 reserved2[5];
    DATA_STREAM_REG_TYPE  stream3;    /* Data Stream 3 */ 
    volatile UNS_32 reserved3;
    volatile UNS_32 mask;
    volatile UNS_32 clear;
    volatile UNS_32 status;
    volatile UNS_32 reserved4;
} DMAC_REGS_T;

/***********************************************************************
 * ctrl - Control Register Bit Field
 **********************************************************************/ 
/* DMA control register bit - enable */
#define DMAC_CTRL_ENABLE            _BIT(0)     /* Enable bit */ 
/* DMA control register bit - source increase */
#define DMAC_CTRL_SOINC             _BIT(1)     /* Source Reg inc.bit */ 
/* DMA control register bit - destination increase */
#define DMAC_CTRL_DEINC             _BIT(2)     /* Dest Reg inc.bit */ 

/* DMA control register source size - 1 byte */ 
#define DMAC_CTRL_SOSIZE_1BYTE      _SBF(3,0)
/* DMA control register source size - 2 byte */ 
#define DMAC_CTRL_SOSIZE_2BYTE      _SBF(3,1)
/* DMA control register source size - 4 byte */ 
#define DMAC_CTRL_SOSIZE_4BYTE      _SBF(3,2)

/* DMA control register destination size - 1 byte */ 
#define DMAC_CTRL_DESIZE_1BYTE      _SBF(7,0)
/* DMA control register destination size - 2 byte */ 
#define DMAC_CTRL_DESIZE_2BYTE      _SBF(7,1)
/* DMA control register destination size - 4 byte */ 
#define DMAC_CTRL_DESIZE_4BYTE      _SBF(7,2)

/* DMA control register peripheral burst size - 1 byte */ 
#define DMAC_CTRL_SOBURST_SINGLE    _SBF(5,0)   /* Single */ 
/* DMA control register peripheral burst size - 4 byte */ 
#define DMAC_CTRL_SOBURST_4INC      _SBF(5,1)   /* 4 incrementing */ 
/* DMA control register peripheral burst size - 8 byte */ 
#define DMAC_CTRL_SOBURST_8INC      _SBF(5,2)   /* 8 incrementing */ 
/* DMA control register peripheral burst size - 16 byte */ 
#define DMAC_CTRL_SOBURST_16INC     _SBF(5,3)   /* 16 incrementing */ 

/* DMA control register address mode - wrap mode */ 
#define DMAC_CTRL_ADDR_MODE_WRAP    _SBF(9,0)
/* DMA control register address mode - increase mode */ 
#define DMAC_CTRL_ADDR_MODE_INCR    _SBF(9,1)

/* DMA control register mem to mem transer bit */ 
#define DMAC_CTRL_MEM2MEM           _BIT(11)    /* Memory to Memory */ 

/* DMA control register transfer direction bit */ 
#define DMAC_CTRL_PERIPH_SOURCE     _SBF(13,0)
#define DMAC_CTRL_PERIPH_DEST       _SBF(13,1)

/***********************************************************************
 * mask - Mask Register Bit Fields
 * clear - Clear Register Bit Fields
 * status - Clear Register Bit Fields
 * DMAC_xN_BIT are the bit positions
 * Writing DMAC_xN to mask register enables corresponding interrupt
 * Writing DMAC_xN to clear register disables corresponding interrupt
 * AND'ing DMAC_xN with status register yields status
 * Note: "ACTIVEx" constants are only applicable to Status Register
 **********************************************************************/ 
#define DMAC_EOT0_BIT    0     /* DMA Stream 0 End of Transfer Flag */ 
#define DMAC_EOT1_BIT    1     /* DMA Stream 1 End of Transfer Flag */ 
#define DMAC_EOT2_BIT    2     /* DMA Stream 2 End of Transfer Flag */ 
#define DMAC_EOT3_BIT    3     /* DMA Stream 3 End of Transfer Flag */ 
#define DMAC_ERROR0_BIT  4     /* DMA Stream 0 Error Flag */
#define DMAC_ERROR1_BIT  5     /* DMA Stream 1 Error Flag */ 
#define DMAC_ERROR2_BIT  6     /* DMA Stream 2 Error Flag */ 
#define DMAC_ERROR3_BIT  7     /* DMA Stream 3 Error Flag */ 
#define DMAC_ACTIVE0_BIT 8     /* DMA Stream 0 Active */ 
#define DMAC_ACTIVE1_BIT 9     /* DMA Stream 1 Active */ 
#define DMAC_ACTIVE2_BIT 10    /* DMA Stream 2 Active */ 
#define DMAC_ACTIVE3_BIT 11    /* DMA Stream 3 Active */ 


/* DMA status bit Stream 0 End of Transfer Flag */ 
#define DMAC_EOT0    _BIT(DMAC_EOT0_BIT)
/* DMA status bit Stream 1 End of Transfer Flag */     
#define DMAC_EOT1    _BIT(DMAC_EOT1_BIT)
/* DMA status bit Stream 2 End of Transfer Flag */ 
#define DMAC_EOT2    _BIT(DMAC_EOT2_BIT)
/* DMA status bit Stream 3 End of Transfer Flag */ 
#define DMAC_EOT3    _BIT(DMAC_EOT3_BIT)
/* DMA status bit Stream 0 Error Flag */
#define DMAC_ERROR0  _BIT(DMAC_ERROR0_BIT)  /* Stream 0 Error Flag */
/* DMA status bit Stream 1 Error Flag */ 
#define DMAC_ERROR1  _BIT(DMAC_ERROR1_BIT)  /* Stream 1 Error Flag */ 
/* DMA status bit Stream 2 Error Flag */ 
#define DMAC_ERROR2  _BIT(DMAC_ERROR2_BIT)  /* Stream 2 Error Flag */ 
/* DMA status bit Stream 3 Error Flag */ 
#define DMAC_ERROR3  _BIT(DMAC_ERROR3_BIT)  /* Stream 3 Error Flag */ 
/* DMA status bit Stream 0 Active */ 
#define DMAC_ACTIVE0 _BIT(DMAC_ACTIVE0_BIT) /* Stream 0 Active */ 
/* DMA status bit Stream 1 Active */ 
#define DMAC_ACTIVE1 _BIT(DMAC_ACTIVE1_BIT) /* Stream 1 Active */ 
/* DMA status bit Stream 2 Active */ 
#define DMAC_ACTIVE2 _BIT(DMAC_ACTIVE2_BIT) /* Stream 2 Active */ 
/* DMA status bit Stream 3 Active */ 
#define DMAC_ACTIVE3 _BIT(DMAC_ACTIVE3_BIT) /* Stream 3 Active */ 

/* DMA status bit every bit enable */ 
#define DMAC_ALL_FLAGS (DMAC_EOT0 | DMAC_EOT1 | DMAC_EOT2 | DMAC_EOT3 \
                        | DMAC_ERROR0 | DMAC_ERROR1 | DMAC_ERROR2 \
                        | DMAC_ERROR3)

/* Macro pointing to DMAC registers */
#define DMAC    ((DMAC_REGS_T *)(DMAC_BASE))
                        
#endif /* LH79520_DMAC_H */ 
