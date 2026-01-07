/***********************************************************************
 * $Id:: lh79524_rtc_driver.h 27 2007-08-31 19:35:06Z kevinw           $
 *
 * Project: LH79524 RTC driver
 *
 * Description:
 *     This file contains driver support for the RTC module on the
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

#ifndef LH79524_RTC_DRIVER_H
#define LH79524_RTC_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh79524_rtc.h"

/***********************************************************************
 * RTC device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* RTC device commands (IOCTL commands) */
typedef enum {
    RTC_START,          /* Start the RTC timer, arg = start load value */
    RTC_SET_TIME_SECOND,    /* Set the RTC time out, arg = second to 
                           time out */
    RTC_ENABLE_MATCH_INT,   /* Enable RTC time out interruption, no arg */
    RTC_DISABLE_MATCH_INT,  /* Disable RTC time out interrupt, no arg */
    RTC_CLEAR_MATCH_INT,    /* Clear the RTC time out intrrupt bit, no arg */
    RTC_GET_STATUS     /* Get a RTC status, use an argument type of
                          RTC_IOCTL_STS_T as the argument to return the
                          correct status */
} RTC_IOCTL_CMD_T;

/* RTC device arguments for RTC_GET_STATUS command (IOCTL arguments) */
typedef enum {
    RTC_GET_LOAD,     /* Returns the RTC load value */
    RTC_GET_CURRENT,  /* Returns the current RTC value */
    RTC_GET_MATCH,    /* Returns the RTC match value */
    GET_INT_PENDING   /* Returns the RTC interrupt pending status, (1 =
                         interrupt pending, 0 = interrupt not
                         pending) */
} RTC_IOCTL_STS_T;

/***********************************************************************
 * RTC device configuration structure
 **********************************************************************/

/* RTC device configuration structure */
typedef struct
{
    INT_32 init;       /* Device initialized flag */
    RTC_REGS_T *regptr; /* Pointer to RTC registers */
} RTC_CFG_T;

/***********************************************************************
 * RTC driver functions
 **********************************************************************/

/* Open the RTC */
INT_32 rtc_open(void *ipbase, INT_32 arg);

/* Close the RTC */
STATUS rtc_close(INT_32 devid);

/* RTC configuration block */
STATUS rtc_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* RTC read function (stub only) */
INT_32 rtc_read(INT_32 devid,
                void *buffer,
                INT_32 max_bytes);

/* RTC write function (stub only) */
INT_32 rtc_write(INT_32 devid,
                 void *buffer,
                 INT_32 n_bytes);

#ifdef __cplusplus
}
#endif

#endif /* LH79524_RTC_DRIVER_H */
