/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  ADC.H:  Header file for A/D Converter                                     */
/*          Samsung S3C44B0X                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef __ADC_H
#define __ADC_H


#define ADC_BASE    0x01D40000  // A/D Converter Base Address


// A/D Converter Registers
typedef struct {
  reg32 ADCCON;     // ADC Control
  reg32 ADCPSR;     // ADC Prescaler
  reg32 ADCDAT;     // ADC Data
} regADC;

#define pADC ((regADC *)ADC_BASE)


// ADCCON: ADC Control Register
#define ENABLE_START    0x00000001
#define READ_START      0x00000002
#define INPUT_AIN0      0x00000000
#define INPUT_AIN1      0x00000004
#define INPUT_AIN2      0x00000008
#define INPUT_AIN3      0x0000000C
#define INPUT_AIN4      0x00000010
#define INPUT_AIN5      0x00000014
#define INPUT_AIN6      0x00000018
#define INPUT_AIN7      0x0000001C
#define ADC_SLEEP       0x00000020
#define ADC_FLAG        0x00000040


#endif /* __ADC_H */
