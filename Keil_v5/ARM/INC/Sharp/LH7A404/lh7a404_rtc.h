/***********************************************************************
 * $Id:: lh7a404_rtc.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 RTC definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         Real Time Clock
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

#ifndef LH7A404_RTC_H
#define LH7A404_RTC_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * Real Time Clock Module Register Structure
 **********************************************************************/

/* RTC Module Register Structure */ 
typedef struct 
{
    volatile UNS_32 dr;             /* RTC data register */ 
    volatile UNS_32 clr;            /* RTC counter load register */ 
    volatile UNS_32 mr;             /* RTC match register */ 
    volatile UNS_32 reserved;
    volatile UNS_32 stat_eoi;       /* RTC interrupt status and end
                                       of interrupt register */
    volatile UNS_32 cr;             /* RTC control register */ 
} RTC_REGS_T;

/***********************************************************************
 * RTC Register Bit Fields
 **********************************************************************/

#define  RTC_STAT_INTR 0x00000001   /* RTC interrupt status */
#define  RTC_CR_MIE    0x00000001   /* RTC match interrupt enable bit */

/* Macro pointing to RTC registers */
#define RTC    ((RTC_REGS_T *)(RTC_BASE))

#endif /* LH7A404_RTC_H */ 
