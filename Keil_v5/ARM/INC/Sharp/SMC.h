/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  SMC.H:  Header file for Static Memory Controller (SMC)                    */
/*          Sharp LH754xx                                                     */
/*                                                                            */
/******************************************************************************/

#ifndef __SMC_H
#define __SMC_H


#define SMCM_BASE   0x40000000               /* SMC Memory Base */
#define SMCMR_BASE  0x00000000               /* SMC Memory (when Remapped) */

#define SMCB0_BASE  0x00000000               /* SMC Memory Bank 0 Offset */
#define SMCB1_BASE  0x04000000               /* SMC Memory Bank 1 Offset */
#define SMCB2_BASE  0x08000000               /* SMC Memory Bank 2 Offset */
#define SMCB3_BASE  0x0C000000               /* SMC Memory Bank 3 Offset */

#define SMCR_BASE   0xFFFF1000               /* SMC Register Base Address */

#define SMCBCR0     REG32(SMCR_BASE + 0x00)  /* Memory Bank 0 Configuration */
#define SMCBCR1     REG32(SMCR_BASE + 0x04)  /* Memory Bank 1 Configuration */
#define SMCBCR2     REG32(SMCR_BASE + 0x08)  /* Memory Bank 2 Configuration */
#define SMCBCR3     REG32(SMCR_BASE + 0x0C)  /* Memory Bank 3 Configuration */


#endif /* __SMC_H */
