/***********************************************************************
 * $Id:: lh79524_gpio_driver.h 27 2007-08-31 19:35:06Z kevinw          $
 *
 * Project: LH79524 GPIO driver
 *
 * Description:
 *     This file contains driver support for the GPIO module on the
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

#ifndef LH79524_GPIO_DRIVER_H
#define LH79524_GPIO_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh79524_gpio.h"

/* GPIO external interrupt pin configuration type */
typedef enum {
    EXT_INT0,
    EXT_INT1,
    EXT_INT2,
    EXT_INT3,
    EXT_INT4,
    EXT_INT5,
    EXT_INT6,
    EXT_INT7
} EXT_INT_T;

/* Possible directions for GPIO pins */
typedef enum
{
    GPIO_INPUT,
    GPIO_OUTPUT
} GPIO_DIR_T;

/* Set data direction for GPIO pins */
void gpio_set_data_dir(GPIO_REGS_T * gpio_port, UNS_8 pins, GPIO_DIR_T dir);

/* Set GPIO pin as input and read value */
UNS_8 gpio_rget_data_dir(GPIO_REGS_T * gpio_port);

/* Write a byte to the GPIO port */
void gpio_write_byte(GPIO_REGS_T * gpio_port, UNS_8 data);

/* Write a byte to the GPIO port */
UNS_8 gpio_read_byte(GPIO_REGS_T * gpio_port);

/* Configure external interrupt INTn pin */
void gpio_ext_int_init(INT_32 source, INT_32 trigger);

/* Clear interrupt status cause by INTn pin */
void gpio_ext_int_clear(INT_32 source);
 
#ifdef __cplusplus
}
#endif

#endif /* LH79524_GPIO_DRIVER_H */
