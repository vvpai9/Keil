/***********************************************************************
 * $Id:: lh79524_wdt_driver.h 27 2007-08-31 19:35:06Z kevinw           $
 *
 * Project: LH79524 WDT driver
 *
 * Description:
 *     This file contains driver support for the WDT module on the
 *     LH79524
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

#ifndef LH79524_WDT_DRIVER_H
#define LH79524_WDT_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh79524_wdt.h"

/***********************************************************************
 * WDT device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* WDT device commands (IOCTL commands) */
typedef enum {
    WDT_ENABLE,     /* Enable watchdog timer, no args */
    WDT_DISABLE,    /* Disable watchdog timer, no args */
    WDT_FREEZE,     /* Freeze and enable watchdog timer, no args */
    WDT_RESET,      /* Perform a watchdog reset to prevent time out,
                       no args */
    WDT_RESET_ON_TIMEOUT,   /* Set watchdog timer RESET the chip on 
                               time out, no args */                
    WDT_INT_ON_TIMEOUT,  /* Set watchdog timer generate interrupt
                            on first time out, no args */
    WDT_SET_COUNT,      /* Set watchdog count value, arg = 0 to 15, which
                       represents 2**16 to 2**31 PCLKS per WDT tick */
    WDT_CLEAR_INT,  /* Clear the interrupt caused by WDT time out */
    WDT_GET_STATUS  /* Get a watchdog status, use an argument type of
                       WDT_IOCTL_STS_T as the argument to return the
                       correct status */
} WDT_IOCTL_CMD_T;

/* WDT device arguments for WDT_GET_STATUS command (IOCTL arguments) */
typedef enum {
    WDT_GET_ENABLE, /* Returns watchdog enable status (TRUE = enabled, 
                       FALSE = disabled */
    WDT_GET_FREEZE, /* Returns watchdog freeze status (TRUE = frozen, 
                       FALSE = not frozen */
    WDT_GET_INT_FIRST, /* Returns interrupt first state (TRUE = 
                       interrupt first mode enabled, FALSE = interrupt 
                       first mode disabled */
    WDT_GET_RESET_TRIGGERED,  /* Returns watchdog system reset status 
                       (TRUE = system reset has not occurred, FALSE = 
                       system reset has occurred */
    WDT_GET_INT_TRIGGERED,     /* Returns WDTINT status (TRUE = INT has 
                       occurred, FALSE = INT has not occured */
    WDT_GET_COUNT  /* Return watchdog count value, a value between 0
                       and 15, which represents 2**16 to 2**31 PCLKS
                       per WDT tick */
} WDT_IOCTL_STS_T;

/***********************************************************************
 * WDT device configuration structure
 **********************************************************************/

/* WDT device configuration structure */
typedef struct
{
    INT_32 init;       /* Device initialized flag */
    WDT_REGS_T *regptr; /* Pointer to WDT registers */
} WDT_CFG_T;

/***********************************************************************
 * WDT driver functions
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

#endif /* LH79524_WDT_DRIVER_H */
