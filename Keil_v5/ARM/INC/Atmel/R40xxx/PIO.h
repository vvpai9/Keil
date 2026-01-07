/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  PIO.H:  Header file for Parallel I/O Controller                    */
/*                                                                     */
/***********************************************************************/

#ifndef __PIO_H
#define __PIO_H


/*---------------*/
/* PIO Registers */
/*---------------*/
#define PIO_PER    REG(PIO_BASE + 0x00)    /* PIO Enable Register */
#define PIO_PDR    REG(PIO_BASE + 0x04)    /* PIO Disable Register */
#define PIO_PSR    REG(PIO_BASE + 0x08)    /* PIO Status Register */
#define PIO_OER    REG(PIO_BASE + 0x10)    /* Output Enable Register */
#define PIO_ODR    REG(PIO_BASE + 0x14)    /* Output Disable Register */
#define PIO_OSR    REG(PIO_BASE + 0x18)    /* Output Status Register */
#define PIO_IFER   REG(PIO_BASE + 0x20)    /* Input Filter Enable Register */
#define PIO_IFDR   REG(PIO_BASE + 0x24)    /* Input Filter Disable Register */
#define PIO_IFSR   REG(PIO_BASE + 0x28)    /* Input Filter Status Register */
#define PIO_SODR   REG(PIO_BASE + 0x30)    /* Set Output Data Register */
#define PIO_CODR   REG(PIO_BASE + 0x34)    /* Clear Output Data Register */
#define PIO_ODSR   REG(PIO_BASE + 0x38)    /* Output Data Status Register */
#define PIO_PDSR   REG(PIO_BASE + 0x3C)    /* Pin Data Status Register */
#define PIO_IER    REG(PIO_BASE + 0x40)    /* Interrupt Enable Register */
#define PIO_IDR    REG(PIO_BASE + 0x44)    /* Interrupt Disable Register */
#define PIO_IMR    REG(PIO_BASE + 0x48)    /* Interrupt Mask Register */
#define PIO_ISR    REG(PIO_BASE + 0x4C)    /* Interrupt Status Register */
#define PIO_MDER   REG(PIO_BASE + 0x50)    /* Multi Driver Enable Register */
#define PIO_MDDR   REG(PIO_BASE + 0x54)    /* Multi Driver Disable Register */
#define PIO_MDSR   REG(PIO_BASE + 0x58)    /* Multi Driver Status Register */

/*----------------*/
/* PIOA Registers */
/*----------------*/
#define PIOA_PER   REG(PIOA_BASE + 0x00)   /* PIO Enable Register */
#define PIOA_PDR   REG(PIOA_BASE + 0x04)   /* PIO Disable Register */
#define PIOA_PSR   REG(PIOA_BASE + 0x08)   /* PIO Status Register */
#define PIOA_OER   REG(PIOA_BASE + 0x10)   /* Output Enable Register */
#define PIOA_ODR   REG(PIOA_BASE + 0x14)   /* Output Disable Register */
#define PIOA_OSR   REG(PIOA_BASE + 0x18)   /* Output Status Register */
#define PIOA_IFER  REG(PIOA_BASE + 0x20)   /* Input Filter Enable Register */
#define PIOA_IFDR  REG(PIOA_BASE + 0x24)   /* Input Filter Disable Register */
#define PIOA_IFSR  REG(PIOA_BASE + 0x28)   /* Input Filter Status Register */
#define PIOA_SODR  REG(PIOA_BASE + 0x30)   /* Set Output Data Register */
#define PIOA_CODR  REG(PIOA_BASE + 0x34)   /* Clear Output Data Register */
#define PIOA_ODSR  REG(PIOA_BASE + 0x38)   /* Output Data Status Register */
#define PIOA_PDSR  REG(PIOA_BASE + 0x3C)   /* Pin Data Status Register */
#define PIOA_IER   REG(PIOA_BASE + 0x40)   /* Interrupt Enable Register */
#define PIOA_IDR   REG(PIOA_BASE + 0x44)   /* Interrupt Disable Register */
#define PIOA_IMR   REG(PIOA_BASE + 0x48)   /* Interrupt Mask Register */
#define PIOA_ISR   REG(PIOA_BASE + 0x4C)   /* Interrupt Status Register */
#define PIOA_MDER  REG(PIOA_BASE + 0x50)   /* Multi Driver Enable Register */
#define PIOA_MDDR  REG(PIOA_BASE + 0x54)   /* Multi Driver Disable Register */
#define PIOA_MDSR  REG(PIOA_BASE + 0x58)   /* Multi Driver Status Register */

/*----------------*/
/* PIOB Registers */
/*----------------*/
#define PIOB_PER   REG(PIOB_BASE + 0x00)   /* PIO Enable Register */
#define PIOB_PDR   REG(PIOB_BASE + 0x04)   /* PIO Disable Register */
#define PIOB_PSR   REG(PIOB_BASE + 0x08)   /* PIO Status Register */
#define PIOB_OER   REG(PIOB_BASE + 0x10)   /* Output Enable Register */
#define PIOB_ODR   REG(PIOB_BASE + 0x14)   /* Output Disable Register */
#define PIOB_OSR   REG(PIOB_BASE + 0x18)   /* Output Status Register */
#define PIOB_IFER  REG(PIOB_BASE + 0x20)   /* Input Filter Enable Register */
#define PIOB_IFDR  REG(PIOB_BASE + 0x24)   /* Input Filter Disable Register */
#define PIOB_IFSR  REG(PIOB_BASE + 0x28)   /* Input Filter Status Register */
#define PIOB_SODR  REG(PIOB_BASE + 0x30)   /* Set Output Data Register */
#define PIOB_CODR  REG(PIOB_BASE + 0x34)   /* Clear Output Data Register */
#define PIOB_ODSR  REG(PIOB_BASE + 0x38)   /* Output Data Status Register */
#define PIOB_PDSR  REG(PIOB_BASE + 0x3C)   /* Pin Data Status Register */
#define PIOB_IER   REG(PIOB_BASE + 0x40)   /* Interrupt Enable Register */
#define PIOB_IDR   REG(PIOB_BASE + 0x44)   /* Interrupt Disable Register */
#define PIOB_IMR   REG(PIOB_BASE + 0x48)   /* Interrupt Mask Register */
#define PIOB_ISR   REG(PIOB_BASE + 0x4C)   /* Interrupt Status Register */
#define PIOB_MDER  REG(PIOB_BASE + 0x50)   /* Multi Driver Enable Register */
#define PIOB_MDDR  REG(PIOB_BASE + 0x54)   /* Multi Driver Disable Register */
#define PIOB_MDSR  REG(PIOB_BASE + 0x58)   /* Multi Driver Status Register */


/* Port Pins */
#define P0         (1<<0)
#define P1         (1<<1)
#define P2         (1<<2)
#define P3         (1<<3)
#define P4         (1<<4)
#define P5         (1<<5)
#define P6         (1<<6)
#define P7         (1<<7)
#define P8         (1<<8)
#define P9         (1<<9)
#define P10        (1<<10)
#define P11        (1<<11)
#define P12        (1<<12)
#define P13        (1<<13)
#define P14        (1<<14)
#define P15        (1<<15)
#define P16        (1<<16)
#define P17        (1<<17)
#define P18        (1<<18)
#define P19        (1<<19)
#define P20        (1<<20)
#define P21        (1<<21)
#define P22        (1<<22)
#define P23        (1<<23)
#define P24        (1<<24)
#define P25        (1<<25)
#define P26        (1<<26)
#define P27        (1<<27)
#define P28        (1<<28)
#define P29        (1<<29)
#define P30        (1<<30)
#define P31        (1<<31)


#endif /* __PIO_H */
