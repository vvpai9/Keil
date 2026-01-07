/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  ARM.H:  Header file for ARM7TDMI                                          */
/*                                                                            */
/******************************************************************************/

#ifndef __ARM_H
#define __ARM_H


#define REG8(x)  (*((volatile unsigned char  *)(x)))
#define REG16(x) (*((volatile unsigned short *)(x)))
#define REG32(x) (*((volatile unsigned long  *)(x)))

typedef volatile unsigned char  reg8;
typedef volatile unsigned short reg16;
typedef volatile unsigned long  reg32;


/*--------------------------*/
/* ARM Mode and Status Bits */
/*--------------------------*/

#define ARM_MODE_USER   0x10
#define ARM_MODE_FIQ    0x11
#define ARM_MODE_IRQ    0x12
#define ARM_MODE_SVC    0x13
#define ARM_MODE_ABORT  0x17
#define ARM_MODE_UNDEF  0x1B
#define ARM_MODE_SYS    0x1F

#define I_BIT           0x80
#define F_BIT           0x40
#define T_BIT           0x20


#endif /* __ARM_H */
