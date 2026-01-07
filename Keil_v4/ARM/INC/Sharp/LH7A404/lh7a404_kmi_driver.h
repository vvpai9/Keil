/***********************************************************************
 * $Id:: lh7a404_kmi_driver.h 14 2007-08-28 16:08:18Z kevinw           $
 *
 * Project: LH7A404 KMI driver
 *
 * Description:
 *     This file contains driver support for the KMI module on the
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

#ifndef LH7A404_KMI_DRIVER_H
#define LH7A404_KMI_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_kmi.h"
    
/***********************************************************************
 * KMI device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* KMI device commands (IOCTL commands) */
typedef enum
{
    KMI_ENABLE_IF,     /* Enable or disable the SSP, use arg = 0 to
                          disable, arg = 1 to enable */
    KMI_FORCE_CLK_LOW, /* Set KMI clock to normal mode or force low,
                          use arg = 0 for normal mode, arg = 1 to force
                          clock low */
    KMI_FORCE_DAT_LOW, /* Set KMI data to normal mode or force low,
                          use arg = 0 for normal mode, arg = 1 to force
                          data signal low */
    KMI_SET_PS2_KB,    /* Disable or enable PS2/AT keyboard interface
                          type, use arg = 0 to disable (no line control
                          bit), arg = 1 to enable */
    KMI_ENABLE_INTS,   /* Enable KMI interrupts, use arg as an 'OR'ed
                          value of KMI_RXINT_EN or KMI_TXINT_EN */
    KMI_DISABLE_INTS,  /* Disable KMI interrupts, use arg as an 'OR'ed
                          value of KMI_RXINT_EN or KMI_TXINT_EN */
    KMI_UPDATE_DIVIDER, /* Sets the KMI clock divider, use arg = 0, this
                           function should be called whenever the system
                           clocks change */
    KMI_GET_STATUS     /* Get a KMI status, use an argument type of
                          KMI_IOCTL_STS_T as the argument to return
                          the correct status */
} KMI_IOCTL_CMD_T;

/* KMI device arguments for KMI_GET_STATUS command (IOCTL arguments) */
typedef enum
{
    KMI_ENABLED_ST,    /* Returns KMI enabled status (1 = enabled,
                          0 = disabled) */
    KMI_TX_BUSY_ST,    /* Returns transmitter busy status (1 = busy,
                          0 = idle) */
    KMI_RX_BUSY_ST,    /* Returns receiver busy status (1 = busy,
                          0 = idle) */
    KMI_CLK_ST,        /* Returns state of clock line */
    KMI_DATA_ST        /* Returns state of data line */
} KMI_IOCTL_STS_T;

/***********************************************************************
 * KMI driver API functions
 **********************************************************************/

/* Open the KMI interface */
INT_32 kmi_open(void *ipbase,
                INT_32 arg);

/* Close the KMI interface */
STATUS kmi_close(INT_32 devid);

/* KMI configuration block */
STATUS kmi_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* KMI read function for polled mode */
INT_32 kmi_read_polled(INT_32 devid,
                       void *buffer,
                       INT_32 max_bytes);

/* KMI write function for polled mode */
INT_32 kmi_write_polled(INT_32 devid,
                        void *buffer,
                        INT_32 n_bytes);

/* KMI ring buffer (interrupt) read function */
INT_32 kmi_read_ring(INT_32 devid,
                     void *buffer,
                     INT_32 max_bytes);

/* KMI ring buffer (interrupt) write function */
INT_32 kmi_write_ring(INT_32 devid,
                      void *buffer,
                      INT_32 n_bytes);

/***********************************************************************
 * Other KMI driver functions
 **********************************************************************/

/* Default KMI interupt */
void kmi_isr(void);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_KMI_DRIVER_H */
