/**********************************************************************
 * $Id:: lh79524_wdt.h 27 2007-08-31 19:35:06Z kevinw                  $
 *
 *  Project: LH79524 WDT controller header file
 *
 *  Description:
 *      This file contains the definitions for WDT controller on
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

#if !defined LH79524_WDT_H
#define LH79524_WDT_H

#include "lh79524_chip.h"

/***********************************************************************
 * Watchdog Timer Module Register Structure
 **********************************************************************/
typedef struct 
{
    volatile UNS_32 wdctlr;     /* Control */ 
    volatile UNS_32 wdcntr;     /* Counter Reset */ 
    volatile UNS_32 wdtstr;     /* Status */ 
    volatile UNS_32 wdcnt0;     /* Counter Bits [7:0] */ 
    volatile UNS_32 wdcnt1;     /* Counter Bits [15:8] */ 
    volatile UNS_32 wdcnt2;     /* Counter Bits [23:16] */ 
    volatile UNS_32 wdcnt3;     /* Counter Bits [31:24] */ 
} WDT_REGS_T;

/**********************************************************************
 * Watchdog Timer Register Bit Fields
 *********************************************************************/ 

/**********************************************************************
 * Watchdog Control Register Bit Fields
 *********************************************************************/ 
/* WDT control register bit fields - enable */
#define WDT_CTRL_ENABLE     _SBF(0,1)
/* WDT control register bit fields - disable */
#define WDT_CTRL_DISABLE    ~WDT_CTRL_ENABLE
/* WDT control register bit fields - time out response as interruption */
#define WDT_CTRL_RSP_INT    _SBF(1,1)       
/* WDT control register bit fields - time out response as reset */
#define WDT_CTRL_RSP_RESET  ~WDT_CTRL_RSP_INT
/* WDT control register bit fields - lock the enable bit */
#define WDT_CTRL_FRZ_ENABLE _BIT(3)
/* WDT control register bit fields - time out number of click tick */
#define WDT_CTRL_TOP(n)     _SBF(4,((n)&_BITMASK(4)))

/**********************************************************************
 * Watchdog Counter Reset Register Bit Fields
 *********************************************************************/ 
/* constant - special value to clear the WDT timer */
#define WDT_WDCNTR          (0x1984)

/**********************************************************************
 * Watchdog Status Register Bit Fields
 *********************************************************************/ 
/* WDT status register bit field - interruption happen */
#define WDT_WD_NWDINT           _BIT(7)
/* WDT status register bit field - reset happen */
#define WDT_WD_NWDRES           _BIT(6)
/* WDT status register bit field - response, a copy of WDCTLR:RSP */
#define WDT_WD_RSP              _SBF(4,3)

/* Macro pointing to WDT registers */
#define WDTIMER    ((WDT_REGS_T *)(WDTIMER_BASE))

#endif /* LH79524_WDT_H */ 
