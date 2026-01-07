 /**********************************************************************
 * $Id:: lh7a404_pwm_driver.h 14 2007-08-28 16:08:18Z kevinw           $
 *
 * Project: LH7A404 PWM driver
 *
 * Description:
 *     This file contains driver support for the PWM module on the
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

#ifndef LH7A404_PWM_DRIVER_H
#define LH7A404_PWM_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_pwm.h"


/***********************************************************************
 * PWM device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* PWM device commands (IOCTL commands) */
typedef enum {
    PWM1_ENABLE,   /* Enables or disables PWM1, use arg = 0 to
                      disable, arg = 1 to enable */
    PWM2_ENABLE,   /* Enables or disables PWM2, use arg = 0 to
                      disable, arg = 1 to enable */
    PWM1_INVERT,   /* Enables or disables signal inversion on PWM1, use
                      arg = 0 to disable, arg = 1 to enable */
    PWM2_INVERT,   /* Enables or disables signal inversion on PWM2, use
                      arg = 0 to disable, arg = 1 to enable */
    PWM1_SETTC,    /* Set PWM1 terminal count, use arg as terminal
                      count value */
    PWM2_SETTC,    /* Set PWM2 terminal count, use arg as terminal
                      count value */
    PWM1_SETDT,    /* Set PWM1 duty cycle, use arg as duty cycle
                      value */
    PWM2_SETDT,    /* Set PWM2 duty cycle, use arg as duty cycle
                      value */
    PWM1_SETFREQ,  /* Set PWM1 frequency, use arg as target frequency
                      in Hz */
    PWM2_SETFREQ,  /* Set PWM2 frequency, use arg as target frequency
                      in Hz */
    PWM1_SETDUTY,  /* Set PWM1 duty cycle, use arg as a value between
                      0 and 100 (for 0% to 100%) */
    PWM2_SETDUTY,  /* Set PWM2 duty cycle, use arg as a value between
                      0 and 100 (for 0% to 100%) */
    PWM1_SET_SYNC, /* Enable or disable PWM1 sync, use arg = 0 to
                      disable SYNC (normal), arg = 1 to enable SYNC */
    PWM2_SET_SYNC, /* Enable or disable PWM2 sync, use arg = 0 to
                      disable SYNC (normal), arg = 1 to enable SYNC */
    PWM_GET_STATUS /* Get a PWM status, use an argument type of
                      PWM_IOCTL_STS_T as the argument to return the
                      correct status */
} DCDC_IOCTL_CMD_T;

/* PWM device arguments for PWM_GET_STATUS command (IOCTL arguments) */
typedef enum {
    PWM1_ENABLED,  /* Returns 1 if PWM1 is enabled, otherwise 0 */
    PWM2_ENABLED,  /* Returns 1 if PWM2 is enabled, otherwise 0 */
    PWM1_INVERTED, /* Returns 1 if PWM1 is inverted, otherwise 0 */
    PWM2_INVERTED, /* Returns 2 if PWM2 is inverted, otherwise 0 */
    PWM1_TC,       /* Returns PWM1 terminal count */
    PWM2_TC,       /* Returns PWM2 terminal count */
    PWM1_DT,       /* Returns PWM1 duty cycle value */
    PWM2_DT,       /* Returns PWM2 duty cycle value */
    PWM1_SYNCD,    /* Returns 1 if PWM1 uses SYNC signal, otherwise
                      returns 0 */
    PWM2_SYNCD     /* Returns 1 if PWM2 uses SYNC signal, otherwise
                      returns 0 */
} DCDC_IOCTL_STS_T;

/***********************************************************************
 * PWM driver API functions
 **********************************************************************/

/* Open the pulse width modulators */
INT_32 pwm_open(void *ipbase,
                INT_32 arg);

/* Close the pulse width modulators */
STATUS pwm_close(INT_32 devid);

/* Pulse width modulators configuration block */
STATUS pwm_ioctl(INT_32 devid,
                 INT_32 cmd,
                 INT_32 arg);

/* Pulse width modulators read function (stub only) */
INT_32 pwm_read(INT_32 devid,
                void *buffer,
                INT_32 max_bytes);

/* Pulse width modulators write function (stub only) */
INT_32 pwm_write(INT_32 devid,
                 void *buffer,
                 INT_32 n_bytes);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_PWM_DRIVER_H */
