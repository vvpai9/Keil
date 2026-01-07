/* ----------------------------------------------------------------------
 * Copyright (C) 2013 ARM Limited. All rights reserved.
 *  
 * $Date:        12. Sept 2013
 * $Revision:    V1.10
 *  
 * Project:      Common Driver definitions
 * -------------------------------------------------------------------- */

#ifndef __DRIVER_COMMON_H
#define __DRIVER_COMMON_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define ARM_DRV_VERSION_MAJOR_MINOR(major,minor) (((major) << 8) | (minor))

/**
\brief  Driver Version
*/
typedef struct _ARM_DRV_VERSION {
  uint16_t api;                         ///< API version
  uint16_t drv;                         ///< Driver version
} ARM_DRV_VERSION;

/**
\brief General power states
*/ 
typedef enum _ARM_POWER_STATE {
  ARM_POWER_OFF,                        ///< Power off: no operation possible
  ARM_POWER_LOW,                        ///< Low Power mode: retain state, detect and signal wake-up events
  ARM_POWER_FULL                        ///< Power on: full operation at maximum performance
} ARM_POWER_STATE;

#endif /* __DRIVER_COMMON_H */
