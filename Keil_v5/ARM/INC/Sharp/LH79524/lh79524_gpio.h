/**********************************************************************
 * $Id:: lh79524_gpio.h 27 2007-08-31 19:35:06Z kevinw                 $
 *
 *  Project: LH79524 GPIO controller header file
 *
 *  Description:
 *      This file contains the definition for GPIO controller on
 *      LH79524.
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

#ifndef LH79524_GPIO_H
#define LH79524_GPIO_H

#include "lh79524_chip.h"

/* GPIO Register Structures */ 
typedef struct 
{
  volatile UNS_32   dr;
  volatile UNS_32   reserveda1;
  volatile UNS_32   ddr;
  volatile UNS_32   reserveda2;
} GPIO_REGS_T;


/*
 * The names and usage of the bit fields in these registers is
 * implementation specific, so no bit field constants are defined.
 */ 

/* Macro pointing to GPIO A registers */
#define GPIOA   ((GPIO_REGS_T *)(GPIOAB_BASE))
/* Macro pointing to GPIO B registers */
#define GPIOB   ((GPIO_REGS_T *)(GPIOAB_BASE+4))
/* Macro pointing to GPIO C registers */
#define GPIOC   ((GPIO_REGS_T *)(GPIOCD_BASE))
/* Macro pointing to GPIO D registers */
#define GPIOD   ((GPIO_REGS_T *)(GPIOCD_BASE+4))
/* Macro pointing to GPIO E registers */
#define GPIOE   ((GPIO_REGS_T *)(GPIOEF_BASE))
/* Macro pointing to GPIO F registers */
#define GPIOF   ((GPIO_REGS_T *)(GPIOEF_BASE+4))
/* Macro pointing to GPIO G registers */
#define GPIOG   ((GPIO_REGS_T *)(GPIOGH_BASE))
/* Macro pointing to GPIO H registers */
#define GPIOH   ((GPIO_REGS_T *)(GPIOGH_BASE+4))
/* Macro pointing to GPIO I registers */
#define GPIOI   ((GPIO_REGS_T *)(GPIOIJ_BASE))
/* Macro pointing to GPIO J registers */
#define GPIOJ   ((GPIO_REGS_T *)(GPIOIJ_BASE+4))
/* Macro pointing to GPIO K registers */
#define GPIOK   ((GPIO_REGS_T *)(GPIOKL_BASE))
/* Macro pointing to GPIO L registers */
#define GPIOL   ((GPIO_REGS_T *)(GPIOKL_BASE+4))
/* Macro pointing to GPIO M registers */
#define GPIOM   ((GPIO_REGS_T *)(GPIOMN_BASE))
/* Macro pointing to GPIO N registers */
#define GPION   ((GPIO_REGS_T *)(GPIOMN_BASE+4))


/***********************************************************************
 * GPIO data and direction Register
 **********************************************************************/

/* GPIO ports bit 0 bit */
#define GPIO_PORT_BIT0        0x0000001
/* GPIO ports bit 1 bit */
#define GPIO_PORT_BIT1        0x0000002
/* GPIO ports bit 2 bit */
#define GPIO_PORT_BIT2        0x0000004
/* GPIO ports bit 3 bit */
#define GPIO_PORT_BIT3        0x0000008
/* GPIO ports bit 4 bit */
#define GPIO_PORT_BIT4        0x0000010
/* GPIO ports bit 5 bit */
#define GPIO_PORT_BIT5        0x0000020
/* GPIO ports bit 6 bit */
#define GPIO_PORT_BIT6        0x0000040
/* GPIO ports bit 7 bit */
#define GPIO_PORT_BIT7        0x0000080

 
#endif /* LH79524_GPIO_H */ 
