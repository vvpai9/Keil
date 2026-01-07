/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  GPIO.H:  Header file for General Purpose Input/Output (GPIO)              */
/*           Sharp LH754xx                                                    */
/*                                                                            */
/******************************************************************************/

#ifndef __GPIO_H
#define __GPIO_H


/* GPIO Base Addresses */
#define GPIO0_BASE  0xFFFDF000
#define GPIO1_BASE  0xFFFDE000
#define GPIO2_BASE  0xFFFDD000
#define GPIO3_BASE  0xFFFDC000
#define GPIO4_BASE  0xFFFDB000

/* Port A */
#define PADR        REG8(GPIO0_BASE + 0x00) /* Port A Data Register */
#define PADDR       REG8(GPIO0_BASE + 0x08) /* Port A Data Direction Register */

/* Port B */
#define PBDR        REG8(GPIO0_BASE + 0x04) /* Port B Data Register */
#define PBDDR       REG8(GPIO0_BASE + 0x0C) /* Port B Data Direction Register */

/* Port C */
#define PCDR        REG8(GPIO1_BASE + 0x00) /* Port C Data Register */
#define PCDDR       REG8(GPIO1_BASE + 0x08) /* Port C Data Direction Register */

/* Port D */
#define PDDR        REG8(GPIO1_BASE + 0x04) /* Port D Data Register */
#define PDDDR       REG8(GPIO1_BASE + 0x0C) /* Port D Data Direction Register */

/* Port E */
#define PEDR        REG8(GPIO2_BASE + 0x00) /* Port E Data Register */
#define PEDDR       REG8(GPIO2_BASE + 0x08) /* Port E Data Direction Register */

/* Port F */
#define PFDR        REG8(GPIO2_BASE + 0x04) /* Port F Data Register */
#define PFDDR       REG8(GPIO2_BASE + 0x0C) /* Port F Data Direction Register */

/* Port G */
#define PGDR        REG8(GPIO3_BASE + 0x00) /* Port G Data Register */
#define PGDDR       REG8(GPIO3_BASE + 0x08) /* Port G Data Direction Register */

/* Port H */
#define PHDR        REG8(GPIO3_BASE + 0x04) /* Port H Data Register */
#define PHDDR       REG8(GPIO3_BASE + 0x0C) /* Port H Data Direction Register */

/* Port I */
#define PIDR        REG8(GPIO4_BASE + 0x00) /* Port I Data Register */
#define PIDDR       REG8(GPIO4_BASE + 0x08) /* Port I Data Direction Register */

/* Port J */
#define PJDR        REG8(GPIO4_BASE + 0x04) /* Port J Data Register */


#endif /* __GPIO_H */
