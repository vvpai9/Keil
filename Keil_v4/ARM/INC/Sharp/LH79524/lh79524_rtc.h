/**********************************************************************
 * $Id:: lh79524_rtc.h 27 2007-08-31 19:35:06Z kevinw                  $
 *
 *  Project: LH79524 RTC controller header file
 *
 *  Description:
 *      This file contains the definitions for RTC controller on 
 *      LH79524
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

#if !defined LH79524_RTC_H
#define LH79524_RTC_H

#include "lh79524_chip.h"

/**********************************************************************
 * Real Time Clock Module Register Structure
 *********************************************************************/ 
typedef struct 
{
    volatile UNS_32 dr;         /* Data */ 
    volatile UNS_32 mr;         /* Match */ 
    volatile UNS_32 lr;   		/* Load */ 
    volatile UNS_32 cr;   		/* Control */ 
    volatile UNS_32 imsc;       /* Interrupt Mask Set and Clear */ 
    volatile UNS_32 ris;        /* Raw Interrupt Status */ 
    volatile UNS_32 mis;        /* Masked Interrupt Status */ 
    volatile UNS_32 icr;        /* Interrupt Clear */ 
} RTC_REGS_T;

/**********************************************************************
 * Real Time Clock Register Bit Fields
 *********************************************************************/ 

/**********************************************************************
 * RTC Control Register (cr) Bit Fields
 *********************************************************************/ 
#define RTC_CR_START      _BIT(0)

/**********************************************************************
 * RTC Interrupt Mask Set and Clear Register (cr) Bit Fields
 *********************************************************************/ 
#define RTC_IMSC_MASKED   _BIT(0)

/**********************************************************************
 * RTC Raw Interrupt Status Register (cr) Bit Fields
 *********************************************************************/ 
#define RTC_RIS_INT       _BIT(0)

/**********************************************************************
 * RTC Masked Interrupt Status Register (cr) Bit Fields
 *********************************************************************/ 
#define RTC_MIS_INT       _BIT(0)

/**********************************************************************
 * RTC Interrupt Clear Register (cr) Bit Fields
 *********************************************************************/ 
#define RTC_ICR_CLEAR     _BIT(0)

/* Macro pointing to RTC registers */
#define RTC    ((RTC_REGS_T *)(RTC_BASE))

#endif /* LH79524_RTC_H */ 
