/***********************************************************************
 * $Id:: lh7a404_gpio_driver.h 14 2007-08-28 16:08:18Z kevinw          $
 *
 * Project: LH7A404 GPIO driver
 *
 * Description:
 *     This file contains driver support for the GPIO module on the
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

#ifndef LH7A404_GPIO_DRIVER_H
#define LH7A404_GPIO_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lh7a404_gpio.h"

/***********************************************************************
 * GPIO driver types and defines
 **********************************************************************/

/* Enumerations for each data port */
typedef enum
{
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,
    GPIO_PORT_G,
    GPIO_PORT_H
} GPIO_PORT_T;

/* Possible directions for GPIO pins */
typedef enum
{
    GPIO_INPUT,
    GPIO_OUTPUT
} GPIO_DIR_T;

/* Possible keyboard columns/states that can be driven */
typedef enum
{
    GPIO_KB_HIGH = GPIO_KSCAN_ALL_HIGH,   /* Drive column high */
    GPIO_KB_LOW = GPIO_KSCAN_ALL_LOW,     /* Drive column low */
    GPIO_KB_HIZ = GPIO_KSCAN_HI_Z,        /* No drive on column */
    GPIO_KB_COL0 = GPIO_KSCAN_COL_ENABLE,
    GPIO_KB_COL1,
    GPIO_KB_COL2,
    GPIO_KB_COL3,
    GPIO_KB_COL4,
    GPIO_KB_COL5,
    GPIO_KB_COL6,
    GPIO_KB_COL7
} GPIO_KB_COL_T;

/* Possible LCD signal multiplexing states */
typedef enum
{
    GPIO_LCDV_0_3 = 0,
    GPIO_LCDV_0_7 = GPIO_PINMUX_PEOCON,
    GPIO_LCDV_0_15 = (GPIO_PINMUX_PEOCON | GPIO_PINMUX_PDOCON)
} GPIO_LCD_MP_T;
    
/* Possible synchronous clock enable select states */
typedef enum
{
    GPIO_NO_SCLKE = 0,
    GPIO_SCKE_0 = GPIO_PINMUX_CLK0EN,
    GPIO_SCKE_1_2 = GPIO_PINMUX_CLK12EN,
    GPIO_SCKE_0_1_2 = (GPIO_PINMUX_CLK0EN | GPIO_PINMUX_CLK12EN)
} GPIO_SCLKE_T;

/* GPIO port F external interrupt input enumerations */
typedef enum
{
    GPIO_INT_F0 = GPIO_PFINT(0),
    GPIO_INT_F1 = GPIO_PFINT(1),
    GPIO_INT_F2 = GPIO_PFINT(2),
    GPIO_INT_F3 = GPIO_PFINT(3),
    GPIO_INT_F4 = GPIO_PFINT(4),
    GPIO_INT_F5 = GPIO_PFINT(5),
    GPIO_INT_F6 = GPIO_PFINT(6),
    GPIO_INT_F7 = GPIO_PFINT(7)
} GPIO_INT_T;

/***********************************************************************
 * GPIO driver functions
 **********************************************************************/

/* Set a GPIO data port's bits as inputs or outputs */
void gpio_set_data_dir(GPIO_PORT_T port,
                       UNS_8 pins,
                       GPIO_DIR_T dir);

/* Get a GPIO data port's data direction status */
UNS_8 gpio_get_data_dir(GPIO_PORT_T port);

/* Write to a GPIO data register (output) */
void gpio_data_write(GPIO_PORT_T port,
                     UNS_8 data);

/* Read a GPIO data register (input) */
UNS_8 gpio_data_read(GPIO_PORT_T port);

/* Drive a keyboard column high, low, or hi-z */
void gpio_kbcol_drive(GPIO_KB_COL_T col);

/* Select UART3 (TRUE) or GPIO signals */
void gpio_uart3_select(BOOL_32 select);

/* Select LCD data signal multiplexing */
void gpio_lcd_signal_select(GPIO_LCD_MP_T lcdm);

/* Select AC97 CODEC (TRUE) or ACI CODEC interface */
void gpio_codec_ac97_select(BOOL_32 select);

/* Select states of synchronous clocks enables 0/1/2 and cs6/cs7 */
void gpio_sclke_select(GPIO_SCLKE_T sclke);

/* Set an external interrupt's level/edge and high/low active mode */
void gpio_ext_int_config(GPIO_INT_T intr,
                         BOOL_32 edge,
                         BOOL_32 high);

/* Clear a pending external (edge) interrupt */
void gpio_clear_int(GPIO_INT_T intr);

/* Enable or disable an external interrupt */
void gpio_ext_int_enable(GPIO_INT_T intr,
                         BOOL_32 enable);

/* Return pending state of an external interrupt */
BOOL_32 gpio_interrupt_pending(GPIO_INT_T intr);

/* Enable or disable signal debouncing for an external interrupt */
void gpio_enable_int_debounce(GPIO_INT_T intr,
                              BOOL_32 enable);

#ifdef __cplusplus
}
#endif

#endif /* LH7A404_GPIO_DRIVER_H */
