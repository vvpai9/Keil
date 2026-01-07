/***********************************************************************
 * $Id:: lh7a404_gpio.h 14 2007-08-28 16:08:18Z kevinw                 $
 *
 * Project: LH7A404 GPIO definitions
 *
 * Description:
 *     This file contains the structure definitions and manifest
 *     constants for the LH7A404 component:
 *         General Purpose Input/Output controller
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

#ifndef LH7A404_GPIO_H
#define LH7A404_GPIO_H

#include "lpc_types.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * GPIO Module Register Structure
 **********************************************************************/

/* GPIO Module Register Structure */
typedef struct 
{
    volatile UNS_32 padr;      /* GPIO port A data register */
    volatile UNS_32 pbdr;      /* GPIO port B data register */
    volatile UNS_32 pcdr;      /* GPIO port C data register */
    volatile UNS_32 pddr;      /* GPIO port D data register */
    volatile UNS_32 paddr;     /* GPIO port A data direction register */
    volatile UNS_32 pbddr;     /* GPIO port B data direction register */
    volatile UNS_32 pcddr;     /* GPIO port C data direction register */
    volatile UNS_32 pdddr;     /* GPIO port D data direction register */
    volatile UNS_32 pedr;      /* GPIO port E data register */
    volatile UNS_32 peddr;     /* GPIO port E data direction register */
    volatile UNS_32 kscan;     /* GPIO keyboard scan register */
    volatile UNS_32 pinmux;    /* GPIO pinmux register */
    volatile UNS_32 pfdr;      /* GPIO port F data register */
    volatile UNS_32 pfddr;     /* GPIO port F data direction register */
    volatile UNS_32 pgdr;      /* GPIO port G data register */
    volatile UNS_32 pgddr;     /* GPIO port G data direction register */
    volatile UNS_32 phdr;      /* GPIO port H data register */
    volatile UNS_32 phddr;     /* GPIO port H data direction register */
    volatile UNS_32 reserved1; /* GPIO reserved */
    volatile UNS_32 inttype1;  /* GPIO interrupt type 1 register */
    volatile UNS_32 inttype2;  /* GPIO interrupt type 2 register */
    volatile UNS_32 gpiofeoi;  /* GPIO end of interrupt register */
    volatile UNS_32 gpiointen; /* GPIO interrupt enable register */
    volatile UNS_32 intstatus; /* GPIO interrupt status register */
    /* GPIO raw interrupt status register */
    volatile UNS_32 rawintstatus;
    volatile UNS_32 gpiodb;    /* GPIO debounce register */
    volatile UNS_32 papindr;   /* GPIO port A pin data register */
    volatile UNS_32 pbpindr;   /* GPIO port B pin data register */
    volatile UNS_32 pcpindr;   /* GPIO port C pin data register */
    volatile UNS_32 pdpindr;   /* GPIO port D pin data register */
    volatile UNS_32 pepindr;   /* GPIO port E pin data register */
    volatile UNS_32 pfpindr;   /* GPIO port F pin data register */
    volatile UNS_32 pgpindr;   /* GPIO port G pin data register */
    volatile UNS_32 phpindr;   /* GPIO port H pin data register */
} GPIO_REGS_T;

/*
 * The names and usage of bit fields in many of these registers is
 * implementation specific.
 */

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

/***********************************************************************
 * GPIO PINMUX Register
 **********************************************************************/

/* GPIO pinmux port E enable of LCD data 4..7 signals */
#define GPIO_PINMUX_PEOCON    0x00000001
/* GPIO pinmux port D enable of LCD data 8..15 signals */
#define GPIO_PINMUX_PDOCON    0x00000002
/* GPIO pinmux port H6 enable of ACI */
#define GPIO_PINMUX_CODECON   0x00000004
/* GPIO pinmux port B enable of UART 3 signals */
#define GPIO_PINMUX_UART3ON   0x00000008
/* GPIO pinmux pin B10 enable of synchronous interface SCKE1_2 signal */
#define GPIO_PINMUX_CLK12EN   0x00000010
/* GPIO pinmux pin C10 enable of synchronous interface SCKE0 signal */
#define GPIO_PINMUX_CLK0EN    0x00000020

/***********************************************************************
 * GPIO Port F Interrupts (used for all Port F Interrupt registers)
 **********************************************************************/

/* GPIO port F interrupt set/clear/status bit macro */
#define GPIO_PFINT(n)         (_BIT(n) & 0xFF)

/***********************************************************************
 * GPIO KSCAN register
 **********************************************************************/

#define GPIO_KSCAN_ALL_HIGH   0          /* GPIO keyboard all high */
#define GPIO_KSCAN_ALL_LOW    1          /* GPIO keyboard all low */
#define GPIO_KSCAN_HI_Z       2          /* GPIO keyboard all high-z */
 /* GPIO keyboard column 0 enable */
#define GPIO_KSCAN_COL_ENABLE 0x00000008

/* Macro pointing to GPIO registers */
#define GPIO  ((GPIO_REGS_T *)(GPIO_BASE))

#endif /* LH7A404_GPIO_H */ 
