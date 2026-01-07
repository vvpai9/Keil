/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  AIC.H:  Header file for Advanced Interrupt Controller              */
/*                                                                     */
/***********************************************************************/

#ifndef __AIC_H
#define __AIC_H


/*---------------*/
/* AIC Registers */
/*---------------*/

/* Source Mode Registers */
#define AIC_SMR0   REG(AIC_BASE + 0x00)
#define AIC_SMR1   REG(AIC_BASE + 0x04)
#define AIC_SMR2   REG(AIC_BASE + 0x08)
#define AIC_SMR3   REG(AIC_BASE + 0x0C)
#define AIC_SMR4   REG(AIC_BASE + 0x10)
#define AIC_SMR5   REG(AIC_BASE + 0x14)
#define AIC_SMR6   REG(AIC_BASE + 0x18)
#define AIC_SMR7   REG(AIC_BASE + 0x1C)
#define AIC_SMR8   REG(AIC_BASE + 0x20)
#define AIC_SMR9   REG(AIC_BASE + 0x24)
#define AIC_SMR10  REG(AIC_BASE + 0x28)
#define AIC_SMR11  REG(AIC_BASE + 0x2C)
#define AIC_SMR12  REG(AIC_BASE + 0x30)
#define AIC_SMR13  REG(AIC_BASE + 0x34)
#define AIC_SMR14  REG(AIC_BASE + 0x38)
#define AIC_SMR15  REG(AIC_BASE + 0x3C)
#define AIC_SMR16  REG(AIC_BASE + 0x40)
#define AIC_SMR17  REG(AIC_BASE + 0x44)
#define AIC_SMR18  REG(AIC_BASE + 0x48)
#define AIC_SMR19  REG(AIC_BASE + 0x4C)
#define AIC_SMR20  REG(AIC_BASE + 0x50)
#define AIC_SMR21  REG(AIC_BASE + 0x54)
#define AIC_SMR22  REG(AIC_BASE + 0x58)
#define AIC_SMR23  REG(AIC_BASE + 0x5C)
#define AIC_SMR24  REG(AIC_BASE + 0x60)
#define AIC_SMR25  REG(AIC_BASE + 0x64)
#define AIC_SMR26  REG(AIC_BASE + 0x68)
#define AIC_SMR27  REG(AIC_BASE + 0x6C)
#define AIC_SMR28  REG(AIC_BASE + 0x70)
#define AIC_SMR29  REG(AIC_BASE + 0x74)
#define AIC_SMR30  REG(AIC_BASE + 0x78)
#define AIC_SMR31  REG(AIC_BASE + 0x7C)

/* Source Vector Registers */
#define AIC_SVR0   REG(AIC_BASE + 0x80)
#define AIC_SVR1   REG(AIC_BASE + 0x84)
#define AIC_SVR2   REG(AIC_BASE + 0x88)
#define AIC_SVR3   REG(AIC_BASE + 0x8C)
#define AIC_SVR4   REG(AIC_BASE + 0x90)
#define AIC_SVR5   REG(AIC_BASE + 0x94)
#define AIC_SVR6   REG(AIC_BASE + 0x98)
#define AIC_SVR7   REG(AIC_BASE + 0x9C)
#define AIC_SVR8   REG(AIC_BASE + 0xA0)
#define AIC_SVR9   REG(AIC_BASE + 0xA4)
#define AIC_SVR10  REG(AIC_BASE + 0xA8)
#define AIC_SVR11  REG(AIC_BASE + 0xAC)
#define AIC_SVR12  REG(AIC_BASE + 0xB0)
#define AIC_SVR13  REG(AIC_BASE + 0xB4)
#define AIC_SVR14  REG(AIC_BASE + 0xB8)
#define AIC_SVR15  REG(AIC_BASE + 0xBC)
#define AIC_SVR16  REG(AIC_BASE + 0xC0)
#define AIC_SVR17  REG(AIC_BASE + 0xC4)
#define AIC_SVR18  REG(AIC_BASE + 0xC8)
#define AIC_SVR19  REG(AIC_BASE + 0xCC)
#define AIC_SVR20  REG(AIC_BASE + 0xD0)
#define AIC_SVR21  REG(AIC_BASE + 0xD4)
#define AIC_SVR22  REG(AIC_BASE + 0xD8)
#define AIC_SVR23  REG(AIC_BASE + 0xDC)
#define AIC_SVR24  REG(AIC_BASE + 0xE0)
#define AIC_SVR25  REG(AIC_BASE + 0xE4)
#define AIC_SVR26  REG(AIC_BASE + 0xE8)
#define AIC_SVR27  REG(AIC_BASE + 0xEC)
#define AIC_SVR28  REG(AIC_BASE + 0xF0)
#define AIC_SVR29  REG(AIC_BASE + 0xF4)
#define AIC_SVR30  REG(AIC_BASE + 0xF8)
#define AIC_SVR31  REG(AIC_BASE + 0xFC)

#define AIC_IVR    REG(AIC_BASE + 0x100) /* IRQ Vector Register */
#define AIC_FVR    REG(AIC_BASE + 0x104) /* FIQ Vector Register */
#define AIC_ISR    REG(AIC_BASE + 0x108) /* Interrupt Status Register */
#define AIC_IPR    REG(AIC_BASE + 0x10C) /* Interrupt Pending Register */
#define AIC_IMR    REG(AIC_BASE + 0x110) /* Interrupt Mask Register */
#define AIC_CISR   REG(AIC_BASE + 0x114) /* Core Interrupt Status Register */
#define AIC_IECR   REG(AIC_BASE + 0x120) /* Interrupt Enable Command Register */
#define AIC_IDCR   REG(AIC_BASE + 0x124) /* Interrupt Disable Command Register */
#define AIC_ICCR   REG(AIC_BASE + 0x128) /* Interrupt Clear Command Register */
#define AIC_ISCR   REG(AIC_BASE + 0x12C) /* Interrupt Set Command Register */
#define AIC_EOICR  REG(AIC_BASE + 0x130) /* End of Interrupt Command Register */
#define AIC_SPU    REG(AIC_BASE + 0x134) /* Spurious Vector Register */


/*--------------------------------*/
/* AIC_SMR: Source Mode Registers */
/*--------------------------------*/

#define AIC_PRIOR                        (7<<0)  /* Priority */

#define AIC_SRCTYPE                      (3<<5)  /* Source Type Definition */

/* Internal Interrupts */
#define AIC_SRCTYPE_INT_LEVEL_SENSITIVE  (0<<5)  /* Level Sensitive */
#define AIC_SRCTYPE_INT_EDGE_TRIGGERED   (1<<5)  /* Edge Triggered */

/* External Interrupts */
#define AIC_SRCTYPE_EXT_LOW_LEVEL        (0<<5)  /* Low Level */
#define AIC_SRCTYPE_EXT_NEGATIVE_EDGE    (1<<5)  /* Negative Edge */
#define AIC_SRCTYPE_EXT_HIGH_LEVEL       (2<<5)  /* High Level */
#define AIC_SRCTYPE_EXT_POSITIVE_EDGE    (3<<5)  /* Positive Edge */

/*------------------------------------*/
/* AIC_ISR: Interrupt Status Register */
/*------------------------------------*/
#define AIC_IRQID                        0x1F    /* Current Source Interrupt */

/*------------------------------------------*/
/* AIC_CISR: Interrupt Core Status Register */
/*------------------------------------------*/
#define AIC_NFIQ                         (1<<0)  /* Core FIQ Status */
#define AIC_NIRQ                         (1<<1)  /* Core IRQ Status */


#endif /* __AIC_H */
