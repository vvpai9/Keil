/***********************************************************************
 * $Id:: lh7a404_wdt_driver.h 14 2007-08-28 16:08:18Z kevinw           $
 *
 * Project: LH7A404 WDT driver
 *
 * Description:
 *     This file contains driver support for the WDT module on the
 *     LH7A404
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

#ifndef LH7A404_WDT_DRIVER_H
#define LH7A404_WDT_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_wdt.h"

/***********************************************************************
 * WDT device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* WDT device commands (IOCTL commands) */
typedef enum {
    WDT_ENABLE,     /* Enable or disable watchdog timer, use arg = 0
                       to disable, arg = 1 to enable */
    WDT_FREEZE,     /* Freeze and enable watchdog timer, no args */
    WDT_RESET,      /* Perform a watchdog reset, no args */
    WDT_INT_FIRST,  /* Enable or disable Interrupt first mode, use arg
                       = 0 to disable, arg = 1 to enable */
    WDT_COUNT,      /* Set watchdog count value, arg = 0 to 15, which
                       represents 2**16 to 2**31 PCLKS per WDT tick */
    WDT_GET_STATUS  /* Get a watchdog status, use an argument type of
                       WDT_IOCTL_STS_T as the argument to return the
                       correct status */
} WDT_IOCTL_CMD_T;

/* WDT device arguments for WDT_GET_STATUS command (IOCTL arguments) */
typedef enum {
    WDT_ENABLE_ST,  /* Returns watchdog enable status (1 = enabled, 0
                       = disabled */
    WDT_FREEZE_ST,  /* Returns watchdog freeze status (1 = frozen, 0
                       = not frozen */
    WDT_RESET_ST,   /* Returns watchdog system reset status (1 = system
                       reset has not occurred, 0 = system reset has
                       occurred */
    WDT_INT_FIRST_ST, /* Returns interrupt first state (1 = interrupt
                         first mode enabled, 0 = interrupt first mode
                         disabled */
    WDT_COUNT_ST,   /* Return watchdog count value, a value between 0
                       and 15, which represents 2**16 to 2**31 PCLKS
                       per WDT tick */
    WDT_FIQ_ST      /* Returns FIQ status (1 = FIQ has occurred, 0 =
                       FIQ is pending */
} WDT_IOCTL_STS_T;

/***********************************************************************
 * WDT driver API functions
 **********************************************************************/

/* Open the watchdog timer */
INT_32 wdt_open(void *ipbase, INT_32 arg);

/* Close the watchdog timer */
STATUS wdt_close(INT_32 devid);

/* Watchdog timer configuration block */
STATUS wdt_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* WDT read function (stub only) */
INT_32 wdt_read(INT_32 devid,
                void *buffer,
                INT_32 max_bytes);

/* WDT write function (stub only) */
INT_32 wdt_write(INT_32 devid,
                 void *buffer,
                 INT_32 n_bytes);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_WDT_DRIVER_H */
