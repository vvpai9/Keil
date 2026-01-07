/***********************************************************************
 * $Id:: lh7a404_timer_driver.h 14 2007-08-28 16:08:18Z kevinw         $
 *
 * Project: LH7A404 timer driver
 *
 * Description:
 *     This file contains driver support for the timer modules on the
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

#ifndef LH7A404_TIMER_DRIVER_H
#define LH7A404_TIMER_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_timer.h"

/***********************************************************************
 * Timer device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* Timer device commands (IOCTL commands) */
typedef enum {
    TIMER_ENABLE,     /* Enable or disable the timer, use arg = 0 to
                         disable, use arg = 1 to enable */
    TIMER_MODE,       /* Set the timer count mode, use an argument type
                         of TIMER_RUN_MODE_T to set the mode */
    TIMER_CLOCK,      /* Set timer clock source (timers 1 and 2), use
                         an argument type of TIMER_CLOCK_T to set the
                         clock source */
    TIMER_SET_COUNT,  /* Sets an initial timer count value, arg should
                         be a value between 0 to 65535 */
    TIMER_SET_USECS,  /* Sets up a timer to underflow based on the
                         passed microsecond value in arg - this will
                         overridethe TIMER_CLOCK and TIMER_SET_COUNT
                         commands */
    TIMER_INT_CLEAR,  /* Clears a pending timer interrupt, no
                         argument */
    TIMER_SET_BZCONT, /* Set timer 1 buzzer output state, use an
                         argument type of TIMER_BZCONT_T to set the
                         state */
    TIMER_GET_STATUS  /* Get a timer status, use an argument type of
                         TIMER_IOCTL_STS_T as the argument to return
                         the correct status */
} TIMER_IOCTL_CMD_T;

/* Timer device arguments for TIMER_MODE command (IOCTL arguments) */
typedef enum {
    TIMER_FREERUN,     /* Set timer in freerun mode */
    TIMER_PERIODIC     /* Set timer in periodic mode */
} TIMER_RUN_MODE_T;

/* Timer device arguments for TIMER_CLOCK command (IOCTL arguments) */
typedef enum {
    TIMER_CLOCK_2K,    /* Set timer 1/2 clock source to 2KHz */
    TIMER_CLOCK_508K   /* Set timer 1/2 clock source to 508KHz */
} TIMER_CLOCK_T;

/* Timer device arguments for TIMER_SET_BZCONT command (IOCTL
   arguments) */
typedef enum
{
    TIMER_BZTOG_LOW,  /* BZTOG out is driven low */
    TIMER_BZTOG_HIGH, /* BZTOG out is driven high */
    TIMER_BZTOG_TOGGLE /* BZTOG out is toggled high or low by the
                          timer 1 underflow state */
} TIMER_BZCONT_T;

/* Timer device arguments for TIMER_GET_STATUS command (IOCTL
   arguments) */
typedef enum {
    TIMER_ENABLE_ST,  /* Returns timer enabled status (1 = timer
                         enabled, 0 = timer disabled */
    TIMER_MODE_ST,    /* Returns timer clock mode (TIMER_FREERUN or
                         TIMER_PERIODIC) */
    TIMER_CLOCK_ST,   /* Returns timer clock source (TIMER_CLOCK_2K or
                         TIMER_CLOCK_508K) */
    TIMER_COUNT_ST,   /* Returns timer count value (value initially
                         load with TIMER_SET_COUNT command) */
    TIMER_VALUE_ST,   /* Returns current timer count value */
    TIMER_BZCONT_ST   /* Returns BZTOG output state (TIMER_BZTOG_LOW,
                         TIMER_BZTOG_HIGH, or TIMER_BZTOG_TOGGLE) */
} TIMER_IOCTL_STS_T;

/* Predefined timer driver macro value for 1 microSecond delay */
#define TIMER_USEC 1

/* Predefined timer driver macro value for 1 milliSecond delay */
#define TIMER_MSEC (1000 * TIMER_USEC)

/***********************************************************************
 * Timer driver API functions
 **********************************************************************/

/* Open the timer */
INT_32 timer_open(void *ipbase, INT_32 arg);

/* Close the timer */
STATUS timer_close(INT_32 devid);

/* Timer configuration block */
STATUS timer_ioctl(INT_32 devid,
                   INT_32 cmd,
                   INT_32 arg);

/* Timer read function (stub only) */
INT_32 timer_read(INT_32 devid,
                  void *buffer,
                  INT_32 max_bytes);

/* Timer write function (stub only) */
INT_32 timer_write(INT_32 devid,
                   void *buffer,
                   INT_32 n_bytes);

/***********************************************************************
 * Other Timer driver functions
 **********************************************************************/

/* Delay for usec microSeconds */
void timer_wait_us(TIMER_REGS_T *timer,
                   UNS_32 usec);

/* Delay for msec microSeconds */
void timer_wait_ms(TIMER_REGS_T *timer, 
                   UNS_32 msec);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_TIMER_DRIVER_H */
