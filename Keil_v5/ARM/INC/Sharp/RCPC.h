/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  RCPC.H:  Header file for Reset, Clock and Power Controller (RCPC)         */
/*           Sharp LH754xx                                                    */
/*                                                                            */
/******************************************************************************/

#ifndef __RCPC_H
#define __RCPC_H


#define RCPC_BASE          0xFFFE2000               /* RCPC Base Address */

#define RCPCCtrl           REG16(RCPC_BASE + 0x00)  /* RCPC Control */
#define Identification     REG16(RCPC_BASE + 0x04)  /* ID Register */
#define Remap              REG16(RCPC_BASE + 0x08)  /* Remap Control */
#define SoftReset          REG16(RCPC_BASE + 0x0C)  /* Soft Reset */
#define ResetStatus        REG16(RCPC_BASE + 0x10)  /* Reset Status */
#define ResetStatusClr     REG16(RCPC_BASE + 0x14)  /* Reset Status Clear */
#define SysClkPrescaler    REG16(RCPC_BASE + 0x18)  /* System Clock Prescaler */
#define APBPeriphClkCtrl0  REG16(RCPC_BASE + 0x24)  /* Per. Clock Control 0 */
#define APBPeriphClkCtrl1  REG16(RCPC_BASE + 0x28)  /* Per. Clock Control 1 */
#define AhbClkCtrl         REG16(RCPC_BASE + 0x2C)  /* AHB Clock Control */
#define LCDPrescaler       REG8 (RCPC_BASE + 0x40)  /* LCD Prescaler */
#define SSPPrescaler       REG8 (RCPC_BASE + 0x44)  /* SSP Prescaler */
#define IntConfig          REG16(RCPC_BASE + 0x80)  /* Ext. Interrupt Config. */
#define IntClear           REG16(RCPC_BASE + 0x84)  /* Ext. Interrupt Clear */


#endif /* __RCPC_H */
