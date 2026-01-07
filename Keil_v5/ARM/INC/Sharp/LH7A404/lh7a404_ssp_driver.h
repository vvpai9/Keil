/***********************************************************************
 * $Id:: lh7a404_ssp_driver.h 14 2007-08-28 16:08:18Z kevinw           $
 *
 * Project: LH7A404 SSP driver
 *
 * Description:
 *     This file contains driver support for the SSP module on the
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

#ifndef LH7A404_SSP_DRIVER_H
#define LH7A404_SSP_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_ssp.h"

/***********************************************************************
 * SSP device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* SSP device commands (IOCTL commands) */
typedef enum {
    SSP_ENABLE,        /* Enable or disable the SSP, use arg = 0 to
                          disable, arg = 1 to enable */
    SSP_SET_PROTOCOL,  /* Set the SSP protocol type, use arg type of
                          SSP_FRAME_T as the argument */
    SSP_SET_CLOCK,     /* Set the SSP clock rate in Hz, use arg as the
                          desired clock rate in Hz */
    SSP_SET_DATA_BITS, /* Set the SSP data word bit size, use arg as a
                          value between 4 and 16 */
    SSP_ENABLE_FIFO,   /* Enable or disable the SSP FIFOs, use arg = 0
                          to disable, arg = 1 to enable */
    SSP_ENABLE_LOOPB,  /* Enable or disable the SSP loopback mode, use
                          arg = 0 to disable, arg = 1 to enable */
    SSP_ENABLE_INTS,   /* Enable selected SSP interrupts, use arg as an
                          'OR'ed combination of (SSP_CR1_RIE,
                          SSP_CR1_TIE, SSP_CR1_RORIE, and
                          SSP_CR1_TXIDLE) */
    SSP_DISABLE_INTS,  /* Disable selected SSP interrupts, use arg as an
                          'OR'ed combination of (SSP_CR1_RIE,
                          SSP_CR1_TIE, SSP_CR1_RORIE, and
                          SSP_CR1_TXIDLE) */
    SSP_CLEAR_OVR_INT, /* Clear the SSP receive overrun interrupt, no
                          argument */
    SSP_SET_SPI_PHASE, /* Set SPI phase, use arg = 0 to set SPH to 0,
                          use arg = 1 to set SPH to 1 */
    SSP_SET_SPI_POL,   /* Set SPI polarity, use arg = 0 to set SPO to 0,
                          use arg = 1 to set SPO to 1 */
    SSP_GET_STATUS     /* Get a SSP status, use an argument type of
                         SSP_IOCTL_STS_T as the argument to return
                         the correct status */
} SSP_IOCTL_CMD_T;

/* SSP device arguments for SSP_SET_PROTOCOL command (IOCTL
   arguments) */
typedef enum {
    SSP_MOTOROLA_SPI,  /* Set SSP port in SPI mode */
    SSP_TI_SSI,        /* Set SSP port in SSI mode */
    SSP_MICROWIRE      /* Set SSP port in MicroWire mode */
} SSP_FRAME_T;

/* SSP device arguments for SSP_GET_STATUS command (IOCTL arguments) */
typedef enum {
    SSP_ENABLED_ST,    /* Returns watchdog enable status (1 = enabled,
                          0 = disabled) */
    SSP_PROTOCOL_ST,   /* Returns watchdog enable status (a value of
                          type SSP_FRAME_T) */
    SSP_CLOCK_ST,      /* Returns SSP clock rate in Hz */
    SSP_DATA_BITS,     /* Returns number of data bits in SSP data
                          words */
    SSP_FIFO_ENABLE_ST, /* Returns FIFO enable status (1 = enabled,
                          0 = disabled) */
    SSP_LOOPB_ST,      /* Returns loopback mode enable status (1 =
                          enabled, 0 = disabled) */
    SSP_INTS_ST,       /* Returns enabled interrupts (a combination of
                          SSP_CR1_RIE, SSP_CR1_TIE, SSP_CR1_RORIE, and
                          SSP_CR1_TXIDLE) */
    SSP_SPI_PHASE_ST,  /* Returns state of SPH bit (1 or 0) */
    SSP_SPI_POL_ST     /* Returns state of SPO bit (1 or 0) */
} SSP_IOCTL_STS_T;

/***********************************************************************
 * SSP driver API functions
 **********************************************************************/

/* Open the SSP */
INT_32 ssp_open(void *ipbase, INT_32 arg);

/* Close the SSP */
STATUS ssp_close(INT_32 devid);

/* SSP configuration block */
STATUS ssp_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* SSP read function */
INT_32 ssp_read_polled(INT_32 devid,
                       void *buffer,
                       INT_32 max_fifo);

/* SSP write function */
INT_32 ssp_write_polled(INT_32 devid,
                        void *buffer,
                        INT_32 n_fifo);

/* SSP ring buffer (interrupt) read function */
INT_32 ssp_read_ring(INT_32 devid,
                     void *buffer,
                     INT_32 max_fifo);

/* SSP ring buffer (interrupt) write function */
INT_32 ssp_write_ring(INT_32 devid,
                      void *buffer,
                      INT_32 n_fifo);

/***********************************************************************
 * Other SSP driver functions
 **********************************************************************/

/* Default SSP interupt */
void ssp_isr(void);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_SSP_DRIVER_H */
