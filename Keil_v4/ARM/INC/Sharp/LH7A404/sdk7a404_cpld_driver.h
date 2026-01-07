/***********************************************************************
 * $Id:: sdk7a404_cpld_driver.h 14 2007-08-28 16:08:18Z kevinw         $
 *
 * Project: LogicPD SDKA404 CPLD driver
 *
 * Description:
 *     This file contains driver support for the CPLD module on the
 *     SDKA404 EVB.
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

#ifndef SDK7A404_CPLD_DRIVER_H
#define SDK7A404_CPLD_DRIVER_H

#include "lpc_types.h"
#include "sdk7a404_board.h"

/***********************************************************************
 * CPLD driver enumerations and defines
 **********************************************************************/

/* Flash status bit enumerations */
typedef enum {CPLD_STS1, CPLD_STS2} CPLD_FLASH_STS_T;

/* CPLD GPIO bit selection enumeration */
typedef enum
{
    CPLD_GPIO_BITS_2 = 0,    /* CPLD GPIO bit 2 */
    CPLD_GPIO_BITS_3         /* CPLD GPIO bit 3 */
} CPLD_GPIO_BITS_T;

/* CPLD GPIO data direction control */
typedef enum {CPLD_GPIO_OUTPUT, CPLD_GPIO_INPUT} CPLD_GPIO_DIR_T;

/***********************************************************************
 * CPLD driver functions
 **********************************************************************/

/* Initializes the CPLD driver */
void cpld_init(void);

/* Enable or disable LAN power */
void cpld_enable_lan_power(BOOL_32 enable);

/* Disable or enable the LAN interrupt */
void cpld_lan_int_enable(BOOL_32 enable);

/* Return LAN interrupt pending status */
BOOL_32 cpld_lan_int_pending(void);

/* Enable or disable FLASH programming */
void cpld_enable_flash_prog(BOOL_32 enable);

/* Read FLASH STS1 or STS2 bit */
BOOL_32 cpld_get_flash_sts(CPLD_FLASH_STS_T flash_sts);

/* Set or disable an application board GPIO LED */
void cpld_enable_led(BOOL_32 set);

/* Set direction of CPLD GPIO data register */
void cpld_set_gpio_dir(CPLD_GPIO_BITS_T gpio_bit_group,
                       CPLD_GPIO_DIR_T gpio_dir);

/* Set the CPLD GPIO data register */
void cpld_set_gpio_data(UNS_8);

/* Get the CPLD GPIO data register */
UNS_8 cpld_get_gpio_data(void);

#endif /* SDK7A404_CPLD_DRIVER_H */
