 /**********************************************************************
 * $Id:: lh7a404_dcdc_driver.h 14 2007-08-28 16:08:18Z kevinw          $
 *
 * Project: LH7A404 DCDC driver
 *
 * Description:
 *     This file contains driver support for the DCDC module on the
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

#ifndef LH7A404_DCDC_DRIVER_H
#define LH7A404_DCDC_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_dcdc.h"


/***********************************************************************
 * DCDC device configuration commands (IOCTL commands and arguments)
 **********************************************************************/

/* DCDC device commands (IOCTL commands) */
typedef enum {
    DCDC1_SET_DUTYL, /* Sets the DCDC1 modulator duty cycle for when the
                        nPWREXT signal is low, use arg value of
                        DCDC_OFF to MAX_DUTYCYCLE */
    DCDC1_SET_PSCL,  /* Sets the DCDC1 modulator clock prescaler for
                        when the nPWREXT signal is low, use arg value
                        of SEVEN_POINT_TWO_KHZ to NINE_TWENTY_ONE_KHZ */
    DCDC1_SET_DUTYH, /* Sets the DCDC1 modulator duty cycle for when the
                        nPWREXT signal is high, use arg value of
                        DCDC_OFF to MAX_DUTYCYCLE */
    DCDC1_SET_PSCH,  /* Sets the DCDC1 modulator clock prescaler for
                        when the nPWREXT signal is high, use arg value
                        of SEVEN_POINT_TWO_KHZ to NINE_TWENTY_ONE_KHZ */
    DCDC2_SET_DUTYL, /* Sets the DCDC2 modulator duty cycle for when the
                        nPWREXT signal is low, use arg value of
                        DCDC_OFF to MAX_DUTYCYCLE */
    DCDC2_SET_PSCL,  /* Sets the DCDC2 modulator clock prescaler for
                        when the nPWREXT signal is low use arg value
                        of SEVEN_POINT_TWO_KHZ to NINE_TWENTY_ONE_KHZ */
    DCDC2_SET_DUTYH, /* Sets the DCDC2 modulator duty cycle for when the
                        nPWREXT signal is high, use arg value of
                        DCDC_OFF to MAX_DUTYCYCLE */
    DCDC2_SET_PSCH,  /* Sets the DCDC2 modulator clock prescaler for
                        when the nPWREXT signal is high use arg value
                        of SEVEN_POINT_TWO_KHZ to NINE_TWENTY_ONE_KHZ */
    DCDC_GET_STATUS /* Get a DCDC status, use an argument type of
                       DCDC_IOCTL_STS_T as the argument to return the
                       correct status */
} DCDC_IOCTL_CMD_T;

/* DCDC device arguments for WDT_GET_STATUS command (IOCTL arguments) */
typedef enum {
    DCDC1_DUTYL,     /* Returns the DCDC1 modulator duty cycle for when
                        the nPWREXT signal is low */
    DCDC1_PSCL,      /* Returns the DCDC1 modulator clock prescaler for
                        when the nPWREXT signal is low */
    DCDC1_DUTYH,     /* Returns the DCDC1 modulator duty cycle for when
                        the nPWREXT signal is high */
    DCDC1_PSCH,      /* Returns the DCDC1 modulator clock prescaler for
                        when the nPWREXT signal is high */
    DCDC2_DUTYL,     /* Returns the DCDC2 modulator duty cycle for when
                        the nPWREXT signal is low */
    DCDC2_PSCL,      /* Returns the DCDC2 modulator clock prescaler for
                        when the nPWREXT signal is low */
    DCDC2_DUTYH,     /* Returns the DCDC2 modulator duty cycle for when
                        the nPWREXT signal is high */
    DCDC2_PSCH       /* Returns the DCDC2 modulator clock prescaler for
                        when the nPWREXT signal is high */
} DCDC_IOCTL_STS_T;

/***********************************************************************
 * DCDC driver defines
 **********************************************************************/

/* Fixed Output duty cycle macros */
#define DCDC_OFF        0   /* DCDC no duty cycle value macro */
#define MIN_DUTYCYCLE   1   /* DCDC 1/16 duty cycle value macro */
#define ONE_EIGTH       2   /* DCDC 1/8 duty cycle value macro */
#define ONE_FOURTH      4   /* DCDC 1/4 duty cycle value macro */
#define THREE_EIGTHS    6   /* DCDC 3/8 duty cycle value macro */
#define NOM_DUTYCYCLE   7   /* DCDC 7/16 duty cycle value macro */
#define ONE_HALF        8   /* DCDC 1/2 duty cycle value macro */
#define FIVE_EIGTHS    10   /* DCDC 5/8 duty cycle value macro */
#define SIX_EIGTHS     12   /* DCDC 3/4 duty cycle value macro */
#define SEVEN_EIGTHS   14   /* DCDC 7/8 duty cycle value macro */
#define MAX_DUTYCYCLE  15   /* DCDC 15/16 duty cycle value macro */

/* Fixed Output frequency macros */
#define NINE_TWENTY_ONE_KHZ           0 /* DCDC 921KHz clock macro */
#define FOUR_SIXTY_KHZ                1 /* DCDC 460KHz clock macro */
#define TWO_THIRTY_KHZ                2 /* DCDC 230KHz clock macro */
#define ONE_FIFTEEN_KHZ               3 /* DCDC 115KHz clock macro */
#define FIFTY_SEVEN_POINT_SIX_KHZ     4 /* DCDC 57.6KHz clock macro */
#define TWENTY_EIGHT_POINT_EIGHT_KHZ  5 /* DCDC 28.8KHz clock macro */
#define FOURTEEN_POINT_FOUR_KHZ       6 /* DCDC 14.4KHz clock macro */
#define SEVEN_POINT_TWO_KHZ           7 /* DCDC 7.2Hz clock macro */

/***********************************************************************
 * DCDC driver API functions
 **********************************************************************/

/* Open the DCDC pulse width modulators */
INT_32 dcdc_open(void *ipbase, INT_32 arg);

/* Close the DCDC pulse width modulators */
STATUS dcdc_close(INT_32 devid);

/* DCDC pulse width modulators configuration block */
STATUS dcdc_ioctl(INT_32 devid,
                  INT_32 cmd,
                  INT_32 arg);

/* DCDC pulse width modulators read function (stub only) */
INT_32 dcdc_read(INT_32 devid,
                 void *buffer,
                 INT_32 max_bytes);

/* DCDC pulse width modulators write function (stub only) */
INT_32 dcdc_write(INT_32 devid,
                  void *buffer,
                  INT_32 n_bytes);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_DCDC_DRIVER_H */
