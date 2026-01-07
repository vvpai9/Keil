/***********************************************************************/
/*  This file is part of the uVision/ARM development tools             */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2003                           */
/***********************************************************************/
/*                                                                     */
/*  ARM.H:  Header file for ARM7TDMI                                   */
/*                                                                     */
/***********************************************************************/

#ifndef __ARM_H
#define __ARM_H


#define REG(x) (*((volatile unsigned int *)(x)))


/*--------------------------*/
/* ARM Mode and Status Bits */
/*--------------------------*/

#define ARM_MODE_USER      0x10
#define ARM_MODE_FIQ       0x11
#define ARM_MODE_IRQ       0x12
#define ARM_MODE_SVC       0x13
#define ARM_MODE_ABORT     0x17
#define ARM_MODE_UNDEF     0x1B
#define ARM_MODE_SYS       0x1F

#define I_BIT              0x80
#define F_BIT              0x40
#define T_BIT              0x20


#endif /* __ARM_H */
