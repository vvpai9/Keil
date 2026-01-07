/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  ADC.H:  Header file for Analog-to-Digital Converter (ADC)                 */
/*            with integrated Touch Screen Controller                         */
/*          Sharp LH754xx                                                     */
/*                                                                            */
/******************************************************************************/

#ifndef __ADC_H
#define __ADC_H


#define ADC_BASE    0xFFFC3000              /* ADC Base Address */

#define TSCHWR      REG32(ADC_BASE + 0x00)  /* High Word Register */
#define TSCLWR      REG32(ADC_BASE + 0x04)  /* Low Word Register */
#define TSCRR       REG32(ADC_BASE + 0x08)  /* Result Register */
#define TSCIMR      REG32(ADC_BASE + 0x0C)  /* Interrupt Masking Register */
#define TSCPCR      REG32(ADC_BASE + 0x10)  /* Power Configuration Register */
#define TSCGCR      REG32(ADC_BASE + 0x14)  /* General Configuration Register */
#define TSCGSR      REG32(ADC_BASE + 0x18)  /* General Status Register */
#define TSCISR      REG32(ADC_BASE + 0x1C)  /* Interrupt Status Register */
#define TSCFSR      REG32(ADC_BASE + 0x20)  /* FIFO Status Register */
#define HWCB0       REG32(ADC_BASE + 0x24)  /* High Word Control Bank Reg. 0 */
#define HWCB1       REG32(ADC_BASE + 0x28)  /* High Word Control Bank Reg. 1 */
#define HWCB2       REG32(ADC_BASE + 0x2C)  /* High Word Control Bank Reg. 2 */
#define HWCB3       REG32(ADC_BASE + 0x30)  /* High Word Control Bank Reg. 3 */
#define HWCB4       REG32(ADC_BASE + 0x34)  /* High Word Control Bank Reg. 4 */
#define HWCB5       REG32(ADC_BASE + 0x38)  /* High Word Control Bank Reg. 5 */
#define HWCB6       REG32(ADC_BASE + 0x3C)  /* High Word Control Bank Reg. 6 */
#define HWCB7       REG32(ADC_BASE + 0x40)  /* High Word Control Bank Reg. 7 */
#define HWCB8       REG32(ADC_BASE + 0x44)  /* High Word Control Bank Reg. 8 */
#define HWCB9       REG32(ADC_BASE + 0x48)  /* High Word Control Bank Reg. 9 */
#define HWCB10      REG32(ADC_BASE + 0x4C)  /* High Word Control Bank Reg. 10 */
#define HWCB11      REG32(ADC_BASE + 0x50)  /* High Word Control Bank Reg. 11 */
#define HWCB12      REG32(ADC_BASE + 0x54)  /* High Word Control Bank Reg. 12 */
#define HWCB13      REG32(ADC_BASE + 0x58)  /* High Word Control Bank Reg. 13 */
#define HWCB14      REG32(ADC_BASE + 0x5C)  /* High Word Control Bank Reg. 14 */
#define HWCB15      REG32(ADC_BASE + 0x60)  /* High Word Control Bank Reg. 15 */
#define LWCB0       REG32(ADC_BASE + 0x24)  /* Low Word Control Bank Reg. 0 */
#define LWCB1       REG32(ADC_BASE + 0x28)  /* Low Word Control Bank Reg. 1 */
#define LWCB2       REG32(ADC_BASE + 0x2C)  /* Low Word Control Bank Reg. 2 */
#define LWCB3       REG32(ADC_BASE + 0x30)  /* Low Word Control Bank Reg. 3 */
#define LWCB4       REG32(ADC_BASE + 0x34)  /* Low Word Control Bank Reg. 4 */
#define LWCB5       REG32(ADC_BASE + 0x38)  /* Low Word Control Bank Reg. 5 */
#define LWCB6       REG32(ADC_BASE + 0x3C)  /* Low Word Control Bank Reg. 6 */
#define LWCB7       REG32(ADC_BASE + 0x40)  /* Low Word Control Bank Reg. 7 */
#define LWCB8       REG32(ADC_BASE + 0x44)  /* Low Word Control Bank Reg. 8 */
#define LWCB9       REG32(ADC_BASE + 0x48)  /* Low Word Control Bank Reg. 9 */
#define LWCB10      REG32(ADC_BASE + 0x4C)  /* Low Word Control Bank Reg. 10 */
#define LWCB11      REG32(ADC_BASE + 0x50)  /* Low Word Control Bank Reg. 11 */
#define LWCB12      REG32(ADC_BASE + 0x54)  /* Low Word Control Bank Reg. 12 */
#define LWCB13      REG32(ADC_BASE + 0x58)  /* Low Word Control Bank Reg. 13 */
#define LWCB14      REG32(ADC_BASE + 0x5C)  /* Low Word Control Bank Reg. 14 */
#define LWCB15      REG32(ADC_BASE + 0x60)  /* Low Word Control Bank Reg. 15 */
#define TSCIHWR     REG32(ADC_BASE + 0xA4)  /* Idle High Word Register */
#define TSCILWR     REG32(ADC_BASE + 0xA8)  /* Idle Low Word Register */
#define TSCMSIR     REG32(ADC_BASE + 0xAC)  /* Masked Interrupt Status Reg. */
#define TSCICR      REG32(ADC_BASE + 0xB0)  /* Interrupt Clear Register */


#endif /* __ADC_H */
