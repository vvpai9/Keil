/***********************************************************************
 * $Id:: lh7a404_uart_driver.h 14 2007-08-28 16:08:18Z kevinw          $
 *
 * Project: LH7A404 UART driver
 *
 * Description:
 *     This file contains driver support for the UART modules on the
 *     LH7A404.
 *
 * Notes:
 *     This driver supports polling and interrupt driven modes of
 *     operation. In interrupt driven modes, a ring buffer is used to
 *     handle the buffering of data to/from the UARTs during the
 *     interrupts and the uart_read_data, uart_send_data, and
 *     uart_check_data functions will read from the ring buffers. In
 *     polling mode, the uart_read_data, uart_send_data, and
 *     uart_check_data functions read/write directly to the UART FIFOs
 *     and the polling program needs to poll fast or lose data. This
 *     driver does not manage the error status bits.
 *
 *     Defines in this file control how the code is compiled and is
 *     used to adjust ring buffer sizes, active UARTs, etc.
 *     Care should be taken to not overflow the ring buffers. This means
 *     that the receive ring buffers should be emptied before they
 *     overflow. The transmit buffers will not overflow. The ring
 *     buffers use a large amount of data - if using polling mode only,
 *     they can be removed from this driver.
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

#ifndef LH7A404_UART_DRIVER_H
#define LH7A404_UART_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_uart.h"

/***********************************************************************
 * UART driver compiler options
 **********************************************************************/

#ifndef UART_RING_BUFSIZE
/* Default UART ring buffer size in bytes. For each enabled UART, a
   transmit and receive ring buffer of this size will be defined */
#define UART_RING_BUFSIZE 256
#endif

#ifndef UART_1_ENABLE
/* The UART_1_ENABLE define enables support for UART 1 when set to 1 */
#define UART_1_ENABLE 1
#endif

#ifndef UART_2_ENABLE
/* The UART_2_ENABLE define enables support for UART 2 when set to 1 */
#define UART_2_ENABLE 1
#endif

#ifndef UART_3_ENABLE
/* The UART_3_ENABLE define enables support for UART 3 when set to 1 */
#define UART_3_ENABLE 1
#endif

/***********************************************************************
 * UART device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* UART device commands (IOCTL commands) */
typedef enum {
    UART_ENABLE,      /* Enable or disable a UART, use arg = 0 to
                         disable, use arg = 1 to enable */
    SIR_ENABLE,       /* Enable or disable UART infrared mode, use
                         arg = 0 to disable, use arg = 1 to enable */
    UART_SET_BAUD_RATE, /* Set UART baud rate, use an argument type
                         of UART_BAUD_RATE_T to set the rate */
    UART_SET_DATA_BITS, /* Set UART data bits, use an arg value of 5
                           to 8 to set the data bit width */
    UART_SET_PARITY , /* Set UART data bits, use an argument type
                         of UART_PARITY_T to set the parity */
    UART_SET_STOP_BITS, /* Set UART stop bits, use an arg value of 1
                           or 2 to set the number of stop bits */
    UART_ENABLE_FIFO, /* Enable or disable UART FIFOs, use arg = 0
                         to disable, use arg = 1 to enable */
    UART_ENABLE_INTS, /* Enable UART interrupts, use arg as an 'OR'ed
                         value of UART_INTR_RTI (RX timeout),
                         UART_INTR_MI (modem interrupt, UART_INTR_TI
                         (transmitter FIFO empty), and UART_INTR_RI
                         (receive FIFO interrupt */
    UART_DISABLE_INTS, /* Disable UART interrupts, use arg as an 'OR'ed
                          value of UART_INTR_RTI (RX timeout),
                          UART_INTR_MI (modem interrupt, UART_INTR_TI
                          (transmitter FIFO empty), and UART_INTR_RI
                          (receive FIFO interrupt */
    UART_ASSERT_BREAK, /* Assert or de-assert a break, use arg = 1 to
                          assert, use arg = 0 to de-assert */
    UART_SET_LOOPBACK, /* Enable or disable loopback mode, use arg = 0
                          to disable, use arg = 1 to enable */
    UART_SET_MDM_POL,  /* Set modem signal polarity, use arg = 1 to 
                          set modem signal active high, use arg = 0 to
                          modem signal active low */
    UART_SET_TX_POL,   /* Set TX signal polarity, use arg = 1 to set
                          TX active high, use arg = 0 to set TX
                          active low */
    UART_SET_RX_POL,   /* Set RX signal polarity, use arg = 1 to set
                          RX active *low*, use arg = 0 to set RX
                          active *high* */
    SIR_SET_BLANKING,  /* Enable or disable SIR blanking, use arg = 1
                          to disable, use arg = 0 to enable */
    SIR_SET_LOWPOWER,  /* Enables or disables SIR low power mode, use
                          arg = 1 to enable low power mode, use arg = 0
                          to disable low power mode */
    UART_GET_STATUS    /* Returns UART status for the selected arg type
                          of UART_IOCTL_STS_T */
} UART_IOCTL_CMD_T;

/* UART device arguments for UART_SET_BAUD_RATE command (IOCTL
   arguments) */
typedef enum
{
    BPS_2400,                 /* 2.4 Kbps */
    BPS_4800,                 /* 4.8 Kbps */
    BPS_9600,                 /* 9.6 Kbps */
    BPS_19200,                /* 19.2 Kbps */
    BPS_28800,                /* 28.8 Kbps */
    BPS_38400,                /* 38.4 Kbps */
    BPS_57600,                /* 57.6 Kbps */
    BPS_115200,               /* 115.2 Kbps */
    BPS_153600,               /* 153.6 Kbps */
    BPS_230400,               /* 230.4 Kbps */
    BPS_460800,               /* 460.8 Kbps */
    BPS_921600                /* 921.6 Kbps */
} UART_BAUD_RATE_T;

/* UART device arguments for UART_SET_PARITY command (IOCTL 
   arguments) */
typedef enum
{
    UART_PARITY_NONE = 0,     /* No parity */
    UART_PARITY_ODD,          /* Odd parity */
    UART_PARITY_EVEN          /* Even parity */
} UART_PARITY_T;

/* UART device arguments for UART_GET_STATUS command (IOCTL
   arguments) */
typedef enum {
    UART_ENABLE_ST,  /* Returns UART enabled status (1 = UART
                        enabled, 0 = UART disabled */
    SIR_ENABLE_ST,   /* Returns SIR enabled status (1 = SIR
                        enabled, 0 = SIR disabled */
    UART_BAUD_RATE,  /* Returns bps rate, an enumeration of type
                        UART_BAUD_RATE_T */
    UART_DATA_BITS,  /* Returns the number of data bits (5 to 8) */
    UART_PARITY,     /* Returns parity, an enumeration of type
                        UART_PARITY_T */
    UART_STOP_BITS,  /* Returns the number of stop bits (1 or 2) */
    UART_INT_ST,     /* Returns the enabled interrupts, an 'OR'ed
                        value of UART_INTR_RTI (RX timeout),
                        UART_INTR_MI (modem interrupt, UART_INTR_TI
                        (transmitter FIFO empty), and UART_INTR_RI
                        (receive FIFO interrupt */
    UART_LOOPBACK_ST, /* Returns Loopback mode enabled status
                         (1 = enabled, 0 = disabled */
    UART_MDM_POL_ST, /* Returns modem polarity bit status (1 = modem
                        signal active high, 0 = modem signal active
                        low */
    UART_TX_POL_ST,  /* Returns TX signal polarity status (1 = TX signal
                        active high, 0 = TX signal active low */
    UART_RX_POL_ST,  /* Returns RX signal polarity status (1 = RX signal
                        active *low*, 0 = RX signal active *high* */
    SIR_BLANKING_ST, /* Returns SIR blanking bit status (1 = SIR
                        blanking disabled, 0 = SIR blanking enabled) */
    SIR_LOWPOWER_ST  /* Returns SIR low power mode status (1 = SIR
                        power mode enabled, 0 = SIR power mode
                        disabled) */
} UART_IOCTL_STS_T;

/***********************************************************************
 * UART driver API functions
 **********************************************************************/

/* Open a UART */
INT_32 uart_open(void *ipbase, INT_32 arg);

/* Close a UART */
STATUS uart_close(INT_32 devid);

/* UART configuration block */
STATUS uart_ioctl(INT_32 devid,
                   INT_32 cmd,
                   INT_32 arg);

/* UART read function for polled mode */
INT_32 uart_read_polled(INT_32 devid,
                        void *buffer,
                        INT_32 max_bytes);

/* UART write function for polled mode */
INT_32 uart_write_polled(INT_32 devid,
                         void *buffer,
                         INT_32 n_bytes);

/* UART read function for interrupt mode (using ring buffers) */
INT_32 uart_read_ring(INT_32 devid,
                      void *buffer,
                      INT_32 max_bytes);

/* UART write function for interrupt mode (using ring buffers) */
INT_32 uart_write_ring(INT_32 devid,
                       void *buffer,
                       INT_32 n_bytes);

/***********************************************************************
 * UART driver support functions
 **********************************************************************/

#if UART_1_ENABLE == 1
/* UART 1 interrupt function */
void uart1_isr(void);
#endif
#if UART_2_ENABLE == 1
/* UART 2 interrupt function */
void uart2_isr(void);
#endif
#if UART_3_ENABLE == 1
/* UART 3 interrupt function */
void uart3_isr(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_UART_DRIVER_H */
