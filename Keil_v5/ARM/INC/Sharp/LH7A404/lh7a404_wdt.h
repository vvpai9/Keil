/***********************************************************************
 * $Id:: lh7a404_wdt.h 14 2007-08-28 16:08:18Z kevinw                  $
 *
 * Project: LH7A404 WDT definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for LH7A404 component:
 *         Watchdog Timer
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

#ifndef LH7A404_WDT_H
#define LH7A404_WDT_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * Watchdog Timer Module Register Structure
 **********************************************************************/

/* Watchdog Timer Module Register Structure */ 
typedef struct 
{
    volatile UNS_32 wdctlr;  /* WDT Control register */ 
    volatile UNS_32 wdcntr;  /* WDT Counter Reset register */ 
    volatile UNS_32 wdtstat; /* WDT status register */ 
} WDT_REGS_T;

/***********************************************************************
 * WDT control register defines
 **********************************************************************/
#define WDT_CTRL_DISABLE    0x00000000  /* WDT disable */
#define WDT_CTRL_ENABLE     0x00000001  /* WDT enable */
#define WDT_CTRL_RSP_RESET  0x00000000  /* WDT 1rst timeout interrupt */
#define WDT_CTRL_RSP_FIQ    0x00000002  /* WDT 2nd timeout interrupt */
#define WDT_CTRL_FRZ        0x00000008  /* WDT freeze bit */
/* WDT timeout code load macro */
#define WDT_CTRL_TOP(n)     _SBF(4, ((n) & 0xF))
#define WDT_TO_MASK         0x000000F0  /* WDT timeout mask */

/***********************************************************************
 * WDT reset register defines
 **********************************************************************/

#define WDT_WDCNTR          0x1984      /* WDT reset value */

/***********************************************************************
 * WDT status register defines
 **********************************************************************/

#define WDT_WD_NWDFIQ       0x00000080  /* WDT FIQ status mask bit */
#define WDT_WD_NWDRES       0x00000040  /* WDT system reset mask bit */
#define WDT_WD_RSP          0x00000030  /* WDT timeout status mask */

/* Macro pointing to WDT registers */
#define WDTIMER ((WDT_REGS_T *)(WDTIMER_BASE))

#endif /*LH7A404_WDT_H */
