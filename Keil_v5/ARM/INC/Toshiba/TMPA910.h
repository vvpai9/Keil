/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL - An ARM Company 2002-2008                                 */
/******************************************************************************/
/*                                                                            */
/*  TMPA910.h:  Header file for Toshiba TMPA910 Device Series                 */
/*                                                                            */
/******************************************************************************/

#ifndef __TMPA910_H
#define __TMPA910_H

#define _REG8(adr)                      (*((volatile unsigned char  *) (adr)))
#define _REG16(adr)                     (*((volatile unsigned short *) (adr)))
#define _REG32(adr)                     (*((volatile unsigned long  *) (adr)))

/* Modules Base Addresses ----------------------------------------------------*/  

#define SYSCTRL_BASE                    0xF0000000
#define WDT_BASE                        0xF0010000
#define PMC_BASE                        0xF0020000
#define RTCMLD_BASE                     0xF0030000
#define TIMER_BASE                      0xF0040000
#define PLLCG_BASE                      0xF0050000
#define TSI_BASE                        0xF0060000
#define I2C_BASE                        0xF0070000
#define ADC_BASE                        0xF0080000
#define EBI_BASE                        0xF00A0000
#define LCDCOP_BASE                     0xF00B0000
#define PORT_BASE                       0xF0800000
#define UART_BASE                       0xF2000000
#define SSP_BASE                        0xF2002000
#define NDFC_BASE                       0xF2010000
#define CMSI_BASE                       0xF2020000
#define SDHC_BASE                       0xF2030000
#define I2S_BASE                        0xF2040000
#define LCDDA_BASE                      0xF2050000
#define INTC_BASE                       0xF4000000
#define DMAC_BASE                       0xF4100000
#define LCDC_BASE                       0xF4200000
#define MPMC0_BASE                      0xF4300000
#define MPMC1_BASE                      0xF4310000
#define USB_BASE                        0xF4400000


/* Register Definitions ------------------------------------------------------*/

/* System Control (SC) Registers                                              */  
#define REMAP                           _REG32 (SYSCTRL_BASE  + 0x000004)

/* PLL CG Registers                                                           */  
#define SYSCR0                          _REG32 (PLLCG_BASE    + 0x000000)
#define SYSCR1                          _REG32 (PLLCG_BASE    + 0x000004)
#define SYSCR2                          _REG32 (PLLCG_BASE    + 0x000008)
#define SYSCR3                          _REG32 (PLLCG_BASE    + 0x00000C)
#define SYSCR4                          _REG32 (PLLCG_BASE    + 0x000010)
#define SYSCR5                          _REG32 (PLLCG_BASE    + 0x000014)
#define SYSCR6                          _REG32 (PLLCG_BASE    + 0x000018)
#define SYSCR7                          _REG32 (PLLCG_BASE    + 0x00001C)
#define CLKCR5                          _REG32 (PLLCG_BASE    + 0x000054)

/* Watchdog Registers                                                         */
#define WDOGLOAD                        _REG32 (WDT_BASE      + 0x000000)
#define WDOGVALUE                       _REG32 (WDT_BASE      + 0x000004)
#define WDOGCONTROL                     _REG32 (WDT_BASE      + 0x000008)
#define WDOGINTCLR                      _REG32 (WDT_BASE      + 0x00000C)
#define WDOGRIS                         _REG32 (WDT_BASE      + 0x000010)
#define WDOGMIS                         _REG32 (WDT_BASE      + 0x000014)
#define WDOGLOCK                        _REG32 (WDT_BASE      + 0x000C00)

/* Power Management Circuit (PMC) Registers                                   */
#define BPADATA                         _REG32 (PMC_BASE      + 0x000000)
#define BPBDATA                         _REG32 (PMC_BASE      + 0x000004)
#define BPCDATA                         _REG32 (PMC_BASE      + 0x000008)
#define BPDDATA                         _REG32 (PMC_BASE      + 0x00000C)
#define BPFDATA                         _REG32 (PMC_BASE      + 0x000014)
#define BPGDATA                         _REG32 (PMC_BASE      + 0x000018)
#define BPHDATA                         _REG32 (PMC_BASE      + 0x00001C)
#define BPJDATA                         _REG32 (PMC_BASE      + 0x000024)
#define BPKDATA                         _REG32 (PMC_BASE      + 0x000028)
#define BPLDATA                         _REG32 (PMC_BASE      + 0x00002C)
#define BPMDATA                         _REG32 (PMC_BASE      + 0x000030)
#define BPNDATA                         _REG32 (PMC_BASE      + 0x000034)
#define BPPDATA                         _REG32 (PMC_BASE      + 0x00003C)
#define BPRDATA                         _REG32 (PMC_BASE      + 0x000044)
#define BPTDATA                         _REG32 (PMC_BASE      + 0x00004C)
#define BPBOE                           _REG32 (PMC_BASE      + 0x000084)
#define BPCOE                           _REG32 (PMC_BASE      + 0x000088)
#define BPDOE                           _REG32 (PMC_BASE      + 0x00008C)
#define BPEOE                           _REG32 (PMC_BASE      + 0x000090)
#define BPFOE                           _REG32 (PMC_BASE      + 0x000094)
#define BPGOE                           _REG32 (PMC_BASE      + 0x000098)
#define BPHOE                           _REG32 (PMC_BASE      + 0x00009C)
#define BPJOE                           _REG32 (PMC_BASE      + 0x0000A4)
#define BPKOE                           _REG32 (PMC_BASE      + 0x0000A8)
#define BPLOE                           _REG32 (PMC_BASE      + 0x0000AC)
#define BPMOE                           _REG32 (PMC_BASE      + 0x0000B0)
#define BPNOE                           _REG32 (PMC_BASE      + 0x0000B4)
#define BPPOE                           _REG32 (PMC_BASE      + 0x0000BC)
#define BPROE                           _REG32 (PMC_BASE      + 0x0000C4)
#define BPTOE                           _REG32 (PMC_BASE      + 0x0000CC)
#define BSADATA                         _REG32 (PMC_BASE      + 0x000100)
#define BSBDATA                         _REG32 (PMC_BASE      + 0x000104)
#define BSCDATA                         _REG32 (PMC_BASE      + 0x000108)
#define BSDDATA                         _REG32 (PMC_BASE      + 0x00010C)
#define BSEDATA                         _REG32 (PMC_BASE      + 0x000110)
#define BSFDATA                         _REG32 (PMC_BASE      + 0x000114)
#define BSGDATA                         _REG32 (PMC_BASE      + 0x000118)
#define BSHDATA                         _REG32 (PMC_BASE      + 0x00011C)
#define BSJDATA                         _REG32 (PMC_BASE      + 0x000124)
#define BSKDATA                         _REG32 (PMC_BASE      + 0x000128)
#define BSLDATA                         _REG32 (PMC_BASE      + 0x00012C)
#define BSMDATA                         _REG32 (PMC_BASE      + 0x000130)
#define BSTDATA                         _REG32 (PMC_BASE      + 0x00014C)
#define BSUDATA                         _REG32 (PMC_BASE      + 0x000150)
#define BSVDATA                         _REG32 (PMC_BASE      + 0x000154)
#define BSWDATA                         _REG32 (PMC_BASE      + 0x000158)
#define BSAOE                           _REG32 (PMC_BASE      + 0x000180)
#define BSBOE                           _REG32 (PMC_BASE      + 0x000184)
#define BSCOE                           _REG32 (PMC_BASE      + 0x000188)
#define BSDOE                           _REG32 (PMC_BASE      + 0x00018C)
#define BSEOE                           _REG32 (PMC_BASE      + 0x000190)
#define BSFOE                           _REG32 (PMC_BASE      + 0x000194)
#define BSGOE                           _REG32 (PMC_BASE      + 0x000198)
#define BSHOE                           _REG32 (PMC_BASE      + 0x00019C)
#define BSJOE                           _REG32 (PMC_BASE      + 0x0001A4)
#define BSKOE                           _REG32 (PMC_BASE      + 0x0001A8)
#define BSLOE                           _REG32 (PMC_BASE      + 0x0001AC)
#define BSMOE                           _REG32 (PMC_BASE      + 0x0001B0)
#define BSTOE                           _REG32 (PMC_BASE      + 0x0001CC)
#define BSUOE                           _REG32 (PMC_BASE      + 0x0001D0)
#define BSVOE                           _REG32 (PMC_BASE      + 0x0001D4)
#define BSWOE                           _REG32 (PMC_BASE      + 0x0001D8)
#define BPARELE                         _REG32 (PMC_BASE      + 0x000200)
#define BPDRELE                         _REG32 (PMC_BASE      + 0x000204)
#define BPPRELE                         _REG32 (PMC_BASE      + 0x000208)
#define BRTRELE                         _REG32 (PMC_BASE      + 0x000210)
#define BPAEDGE                         _REG32 (PMC_BASE      + 0x000220)
#define BPDEDGE                         _REG32 (PMC_BASE      + 0x000224)
#define BPPEDGE                         _REG32 (PMC_BASE      + 0x000228)
#define BPARINT                         _REG32 (PMC_BASE      + 0x000240)
#define BPDRINT                         _REG32 (PMC_BASE      + 0x000244)
#define BPPRINT                         _REG32 (PMC_BASE      + 0x000248)
#define BRTRINT                         _REG32 (PMC_BASE      + 0x000250)
#define PMCDRV                          _REG32 (PMC_BASE      + 0x000260)
#define DMCCKECTL                       _REG32 (PMC_BASE      + 0x000280)
#define PMCCTL                          _REG32 (PMC_BASE      + 0x000300)

/* Real-Time Clock/Melody Alarm Generator (RTCMLD) Registers                  */  
#define RTCDATA                         _REG32 (RTCMLD_BASE   + 0x000000)
#define RTCCOMP                         _REG32 (RTCMLD_BASE   + 0x000004)
#define RTCPRST                         _REG32 (RTCMLD_BASE   + 0x000008)
#define MLDALMINV                       _REG32 (RTCMLD_BASE   + 0x000100)
#define MLDALMSEL                       _REG32 (RTCMLD_BASE   + 0x000104)
#define ALMCNTCR                        _REG32 (RTCMLD_BASE   + 0x000108)
#define ALMPATTERN                      _REG32 (RTCMLD_BASE   + 0x00010C)
#define MLDCNTCR                        _REG32 (RTCMLD_BASE   + 0x000110)
#define MLDFRQ                          _REG32 (RTCMLD_BASE   + 0x000114)
#define RTCALMINTCTR                    _REG32 (RTCMLD_BASE   + 0x000200)
#define RTCALMMIS                       _REG32 (RTCMLD_BASE   + 0x000204)

/* 16-bit Timer/PWM 0 Registers                                               */  
#define TIMER0LOAD                      _REG32 (TIMER_BASE    + 0x000000)
#define TIMER0VALUE                     _REG32 (TIMER_BASE    + 0x000004)
#define TIMER0CONTROL                   _REG32 (TIMER_BASE    + 0x000008)
#define TIMER0INTCLR                    _REG32 (TIMER_BASE    + 0x00000C)
#define TIMER0RIS                       _REG32 (TIMER_BASE    + 0x000010)
#define TIMER0MIS                       _REG32 (TIMER_BASE    + 0x000014)
#define TIMER0BGLOAD                    _REG32 (TIMER_BASE    + 0x000018)
#define TIMER0MODE                      _REG32 (TIMER_BASE    + 0x00001C)
#define TIMER0COMPARE1                  _REG32 (TIMER_BASE    + 0x0000A0)
#define TIMER0CMPINTCLR1                _REG32 (TIMER_BASE    + 0x0000C0)
#define TIMER0CMPEN                     _REG32 (TIMER_BASE    + 0x0000E0)
#define TIMER0CMPRIS                    _REG32 (TIMER_BASE    + 0x0000E4)
#define TIMER0CMPMIS                    _REG32 (TIMER_BASE    + 0x0000E8)
#define TIMER0BGCMP                     _REG32 (TIMER_BASE    + 0x0000EC)

/* 16-bit Timer 1 Registers                                                   */  
#define TIMER1LOAD                      _REG32 (TIMER_BASE    + 0x000100)
#define TIMER1VALUE                     _REG32 (TIMER_BASE    + 0x000104)
#define TIMER1CONTROL                   _REG32 (TIMER_BASE    + 0x000108)
#define TIMER1INTCLR                    _REG32 (TIMER_BASE    + 0x00010C)
#define TIMER1RIS                       _REG32 (TIMER_BASE    + 0x000110)
#define TIMER1MIS                       _REG32 (TIMER_BASE    + 0x000114)
#define TIMER1BGLOAD                    _REG32 (TIMER_BASE    + 0x000118)
#define TIMER1COMPARE1                  _REG32 (TIMER_BASE    + 0x0001A0)
#define TIMER1CMPINTCLR1                _REG32 (TIMER_BASE    + 0x0001C0)
#define TIMER1CMPEN                     _REG32 (TIMER_BASE    + 0x0001E0)
#define TIMER1CMPRIS                    _REG32 (TIMER_BASE    + 0x0001E4)
#define TIMER1CMPMIS                    _REG32 (TIMER_BASE    + 0x0001E8)

/* 16-bit Timer/PWM 2 Registers                                               */  
#define TIMER2LOAD                      _REG32 (TIMER_BASE    + 0x001000)
#define TIMER2VALUE                     _REG32 (TIMER_BASE    + 0x001004)
#define TIMER2CONTROL                   _REG32 (TIMER_BASE    + 0x001008)
#define TIMER2INTCLR                    _REG32 (TIMER_BASE    + 0x00100C)
#define TIMER2RIS                       _REG32 (TIMER_BASE    + 0x001010)
#define TIMER2MIS                       _REG32 (TIMER_BASE    + 0x001014)
#define TIMER2BGLOAD                    _REG32 (TIMER_BASE    + 0x001018)
#define TIMER2MODE                      _REG32 (TIMER_BASE    + 0x00101C)
#define TIMER2COMPARE1                  _REG32 (TIMER_BASE    + 0x0010A0)
#define TIMER2CMPINTCLR1                _REG32 (TIMER_BASE    + 0x0010C0)
#define TIMER2CMPEN                     _REG32 (TIMER_BASE    + 0x0010E0)
#define TIMER2CMPRIS                    _REG32 (TIMER_BASE    + 0x0010E4)
#define TIMER2CMPMIS                    _REG32 (TIMER_BASE    + 0x0010E8)
#define TIMER2BGCMP                     _REG32 (TIMER_BASE    + 0x0010EC)

/* 16-bit Timer 3 Registers                                                   */  
#define TIMER3LOAD                      _REG32 (TIMER_BASE    + 0x001100)
#define TIMER3VALUE                     _REG32 (TIMER_BASE    + 0x001104)
#define TIMER3CONTROL                   _REG32 (TIMER_BASE    + 0x001108)
#define TIMER3INTCLR                    _REG32 (TIMER_BASE    + 0x00110C)
#define TIMER3RIS                       _REG32 (TIMER_BASE    + 0x001110)
#define TIMER3MIS                       _REG32 (TIMER_BASE    + 0x001114)
#define TIMER3BGLOAD                    _REG32 (TIMER_BASE    + 0x001118)
#define TIMER3COMPARE1                  _REG32 (TIMER_BASE    + 0x0011A0)
#define TIMER3CMPINTCLR1                _REG32 (TIMER_BASE    + 0x0011C0)
#define TIMER3CMPEN                     _REG32 (TIMER_BASE    + 0x0011E0)
#define TIMER3CMPRIS                    _REG32 (TIMER_BASE    + 0x0011E4)
#define TIMER3CMPMIS                    _REG32 (TIMER_BASE    + 0x0011E8)

/* 16-bit Timer 4 Registers                                                   */  
#define TIMER4LOAD                      _REG32 (TIMER_BASE    + 0x002000)
#define TIMER4VALUE                     _REG32 (TIMER_BASE    + 0x002004)
#define TIMER4CONTROL                   _REG32 (TIMER_BASE    + 0x002008)
#define TIMER4INTCLR                    _REG32 (TIMER_BASE    + 0x00200C)
#define TIMER4RIS                       _REG32 (TIMER_BASE    + 0x002010)
#define TIMER4MIS                       _REG32 (TIMER_BASE    + 0x002014)
#define TIMER4BGLOAD                    _REG32 (TIMER_BASE    + 0x002018)
#define TIMER4COMPARE1                  _REG32 (TIMER_BASE    + 0x0020A0)
#define TIMER4CMPINTCLR1                _REG32 (TIMER_BASE    + 0x0020C0)
#define TIMER4CMPEN                     _REG32 (TIMER_BASE    + 0x0020E0)
#define TIMER4CMPRIS                    _REG32 (TIMER_BASE    + 0x0020E4)
#define TIMER4CMPMIS                    _REG32 (TIMER_BASE    + 0x0020E8)
#define TIMER4BGCMP                     _REG32 (TIMER_BASE    + 0x0020EC)

/* 16-bit Timer 5 Registers                                                   */  
#define TIMER5LOAD                      _REG32 (TIMER_BASE    + 0x002100)
#define TIMER5VALUE                     _REG32 (TIMER_BASE    + 0x002104)
#define TIMER5CONTROL                   _REG32 (TIMER_BASE    + 0x002108)
#define TIMER5INTCLR                    _REG32 (TIMER_BASE    + 0x00210C)
#define TIMER5RIS                       _REG32 (TIMER_BASE    + 0x002110)
#define TIMER5MIS                       _REG32 (TIMER_BASE    + 0x002114)
#define TIMER5BGLOAD                    _REG32 (TIMER_BASE    + 0x002118)
#define TIMER5COMPARE1                  _REG32 (TIMER_BASE    + 0x0021A0)
#define TIMER5CMPINTCLR1                _REG32 (TIMER_BASE    + 0x0021C0)
#define TIMER5CMPEN                     _REG32 (TIMER_BASE    + 0x0021E0)
#define TIMER5CMPRIS                    _REG32 (TIMER_BASE    + 0x0021E4)
#define TIMER5CMPMIS                    _REG32 (TIMER_BASE    + 0x0021E8)

/* Touch Screen Interface (TSI) Registers                                     */  
#define TSICR0                          _REG32 (TSI_BASE      + 0x0001F0)
#define TSICR1                          _REG32 (TSI_BASE      + 0x0001F4)

/* Inter-Integrated Circuit 0 (I2C0) Registers                                */  
#define I2C0CR1                         _REG32 (I2C_BASE      + 0x000000)
#define I2C0DBR                         _REG32 (I2C_BASE      + 0x000004)
#define I2C0AR                          _REG32 (I2C_BASE      + 0x000008)
#define I2C0CR2                         _REG32 (I2C_BASE      + 0x00000C)
#define I2C0SR                          _REG32 (I2C_BASE      + 0x00000C)
#define I2C0PRS                         _REG32 (I2C_BASE      + 0x000010)
#define I2C0IE                          _REG32 (I2C_BASE      + 0x000014)
#define I2C0IR                          _REG32 (I2C_BASE      + 0x000018)

/* Inter-Integrated Circuit 1 (I2C1) Registers                                */  
#define I2C1CR1                         _REG32 (I2C_BASE      + 0x001000)
#define I2C1DBR                         _REG32 (I2C_BASE      + 0x001004)
#define I2C1AR                          _REG32 (I2C_BASE      + 0x001008)
#define I2C1CR2                         _REG32 (I2C_BASE      + 0x00100C)
#define I2C1SR                          _REG32 (I2C_BASE      + 0x00100C)
#define I2C1PRS                         _REG32 (I2C_BASE      + 0x001010)
#define I2C1IE                          _REG32 (I2C_BASE      + 0x001014)
#define I2C1IR                          _REG32 (I2C_BASE      + 0x001018)

/* Analog to Digital Converter (ADC) Registers                                */  
#define ADREG0L                         _REG32 (ADC_BASE      + 0x000000)
#define ADREG0H                         _REG32 (ADC_BASE      + 0x000004)
#define ADREG1L                         _REG32 (ADC_BASE      + 0x000008)
#define ADREG1H                         _REG32 (ADC_BASE      + 0x00000C)
#define ADREG2L                         _REG32 (ADC_BASE      + 0x000010)
#define ADREG2H                         _REG32 (ADC_BASE      + 0x000014)
#define ADREG3L                         _REG32 (ADC_BASE      + 0x000018)
#define ADREG3H                         _REG32 (ADC_BASE      + 0x00001C)
#define ADREG4L                         _REG32 (ADC_BASE      + 0x000020)
#define ADREG4H                         _REG32 (ADC_BASE      + 0x000024)
#define ADREG5L                         _REG32 (ADC_BASE      + 0x000028)
#define ADREG5H                         _REG32 (ADC_BASE      + 0x00002C)
#define ADREGSPL                        _REG32 (ADC_BASE      + 0x000040)
#define ADREGSPH                        _REG32 (ADC_BASE      + 0x000044)
#define ADCOMREGL                       _REG32 (ADC_BASE      + 0x000048)
#define ADCOMREGH                       _REG32 (ADC_BASE      + 0x00004C)
#define ADMOD0                          _REG32 (ADC_BASE      + 0x000050)
#define ADMOD1                          _REG32 (ADC_BASE      + 0x000054)
#define ADMOD2                          _REG32 (ADC_BASE      + 0x000058)
#define ADMOD3                          _REG32 (ADC_BASE      + 0x00005C)
#define ADMOD4                          _REG32 (ADC_BASE      + 0x000060)
#define ADCLK                           _REG32 (ADC_BASE      + 0x000070)
#define ADIE                            _REG32 (ADC_BASE      + 0x000074)
#define ADIS                            _REG32 (ADC_BASE      + 0x000078)
#define ADIC                            _REG32 (ADC_BASE      + 0x00007C)

/* External Bus Interface (EBI) Registers                                     */  
#define SMC_TIMEOUT                     _REG32 (EBI_BASE      + 0x000050)

/* LCD Controller Option Function (LCDCOP) Registers                          */
#define PR0CR                           _REG32 (LCDCOP_BASE   + 0x000000)
#define PR1CR                           _REG32 (LCDCOP_BASE   + 0x000004)
#define PR2CR                           _REG32 (LCDCOP_BASE   + 0x000008)

/* Port A Registers                                                           */
#define GPIOADATA                       _REG32 (PORT_BASE     + 0x0003FC)
#define GPIOAIS                         _REG32 (PORT_BASE     + 0x000804)
#define GPIOAIBE                        _REG32 (PORT_BASE     + 0x000808)
#define GPIOAIEV                        _REG32 (PORT_BASE     + 0x00080C)
#define GPIOAIE                         _REG32 (PORT_BASE     + 0x000810)
#define GPIOARIS                        _REG32 (PORT_BASE     + 0x000814)
#define GPIOAMIS                        _REG32 (PORT_BASE     + 0x000818)
#define GPIOAIC                         _REG32 (PORT_BASE     + 0x00081C)

/* Port B Registers                                                           */
#define GPIOBDATA                       _REG32 (PORT_BASE     + 0x0013FC)
#define GPIOBODE                        _REG32 (PORT_BASE     + 0x001C00)

/* Port C Registers                                                           */
#define GPIOCDATA                       _REG32 (PORT_BASE     + 0x0023FC)
#define GPIOCDIR                        _REG32 (PORT_BASE     + 0x002400)
#define GPIOCFR1                        _REG32 (PORT_BASE     + 0x002424)
#define GPIOCFR2                        _REG32 (PORT_BASE     + 0x002428)
#define GPIOCIS                         _REG32 (PORT_BASE     + 0x002804)
#define GPIOCIBE                        _REG32 (PORT_BASE     + 0x002808)
#define GPIOCIEV                        _REG32 (PORT_BASE     + 0x00280C)
#define GPIOCIE                         _REG32 (PORT_BASE     + 0x002810)
#define GPIOCRIS                        _REG32 (PORT_BASE     + 0x002814)
#define GPIOCMIS                        _REG32 (PORT_BASE     + 0x002818)
#define GPIOCIC                         _REG32 (PORT_BASE     + 0x00281C)
#define GPIOCODE                        _REG32 (PORT_BASE     + 0x002C00)

/* Port D Registers                                                           */
#define GPIODDATA                       _REG32 (PORT_BASE     + 0x0033FC)
#define GPIODFR1                        _REG32 (PORT_BASE     + 0x003424)
#define GPIODFR2                        _REG32 (PORT_BASE     + 0x003428)
#define GPIODIS                         _REG32 (PORT_BASE     + 0x003804)
#define GPIODIBE                        _REG32 (PORT_BASE     + 0x003808)
#define GPIODIEV                        _REG32 (PORT_BASE     + 0x00380C)
#define GPIODIE                         _REG32 (PORT_BASE     + 0x003810)
#define GPIODRIS                        _REG32 (PORT_BASE     + 0x003814)
#define GPIODMIS                        _REG32 (PORT_BASE     + 0x003818)
#define GPIODIC                         _REG32 (PORT_BASE     + 0x00381C)

/* Port E Registers                                                           */
#define GPIOEDATA                       _REG32 (PORT_BASE     + 0x0043FC)
#define GPIOEFR1                        _REG32 (PORT_BASE     + 0x004424)

/* Port F Registers                                                           */
#define GPIOFDATA                       _REG32 (PORT_BASE     + 0x0053FC)
#define GPIOFDIR                        _REG32 (PORT_BASE     + 0x005400)
#define GPIOFFR1                        _REG32 (PORT_BASE     + 0x005424)
#define GPIOFIS                         _REG32 (PORT_BASE     + 0x005804)
#define GPIOFIBE                        _REG32 (PORT_BASE     + 0x005808)
#define GPIOFIEV                        _REG32 (PORT_BASE     + 0x00580C)
#define GPIOFIE                         _REG32 (PORT_BASE     + 0x005810)
#define GPIOFRIS                        _REG32 (PORT_BASE     + 0x005814)
#define GPIOFMIS                        _REG32 (PORT_BASE     + 0x005818)
#define GPIOFIC                         _REG32 (PORT_BASE     + 0x00581C)
#define GPIOFODE                        _REG32 (PORT_BASE     + 0x005C00)

/* Port G Registers                                                           */
#define GPIOGDATA                       _REG32 (PORT_BASE     + 0x0063FC)
#define GPIOGDIR                        _REG32 (PORT_BASE     + 0x006400)
#define GPIOGFR1                        _REG32 (PORT_BASE     + 0x006424)

/* Port H Registers                                                           */
#define GPIOHDATA                       _REG32 (PORT_BASE     + 0x0073FC)
#define GPIOHDIR                        _REG32 (PORT_BASE     + 0x007400)
#define GPIOHFR1                        _REG32 (PORT_BASE     + 0x007424)

/* Port J Registers                                                           */
#define GPIOJDATA                       _REG32 (PORT_BASE     + 0x0083FC)
#define GPIOJFR1                        _REG32 (PORT_BASE     + 0x008424)

/* Port K Registers                                                           */
#define GPIOKDATA                       _REG32 (PORT_BASE     + 0x0093FC)
#define GPIOKFR1                        _REG32 (PORT_BASE     + 0x009424)

/* Port L Registers                                                           */
#define GPIOLDATA                       _REG32 (PORT_BASE     + 0x00A3FC)
#define GPIOLDIR                        _REG32 (PORT_BASE     + 0x00A400)
#define GPIOLFR1                        _REG32 (PORT_BASE     + 0x00A424)
#define GPIOLFR2                        _REG32 (PORT_BASE     + 0x00A428)

/* Port M Registers                                                           */
#define GPIOMDATA                       _REG32 (PORT_BASE     + 0x00B3FC)
#define GPIOMDIR                        _REG32 (PORT_BASE     + 0x00B400)
#define GPIOMFR1                        _REG32 (PORT_BASE     + 0x00B424)

/* Port N Registers                                                           */
#define GPIONDATA                       _REG32 (PORT_BASE     + 0x00C3FC)
#define GPIONDIR                        _REG32 (PORT_BASE     + 0x00C400)
#define GPIONFR1                        _REG32 (PORT_BASE     + 0x00C424)
#define GPIONFR2                        _REG32 (PORT_BASE     + 0x00C428)
#define GPIONIS                         _REG32 (PORT_BASE     + 0x00C804)
#define GPIONIBE                        _REG32 (PORT_BASE     + 0x00C808)
#define GPIONIEV                        _REG32 (PORT_BASE     + 0x00C80C)
#define GPIONIE                         _REG32 (PORT_BASE     + 0x00C810)
#define GPIONRIS                        _REG32 (PORT_BASE     + 0x00C814)
#define GPIONMIS                        _REG32 (PORT_BASE     + 0x00C818)
#define GPIONIC                         _REG32 (PORT_BASE     + 0x00C81C)

/* Port P Registers                                                           */
#define GPIOPDATA                       _REG32 (PORT_BASE     + 0x00D3FC)
#define GPIOPDIR                        _REG32 (PORT_BASE     + 0x00D400)
#define GPIOPIS                         _REG32 (PORT_BASE     + 0x00D804)
#define GPIOPIBE                        _REG32 (PORT_BASE     + 0x00D808)
#define GPIOPIEV                        _REG32 (PORT_BASE     + 0x00D80C)
#define GPIOPIE                         _REG32 (PORT_BASE     + 0x00D810)
#define GPIOPRIS                        _REG32 (PORT_BASE     + 0x00D814)
#define GPIOPMIS                        _REG32 (PORT_BASE     + 0x00D818)
#define GPIOPIC                         _REG32 (PORT_BASE     + 0x00D81C)

/* Port R Registers                                                           */
#define GPIORDATA                       _REG32 (PORT_BASE     + 0x00E3FC)
#define GPIORDIR                        _REG32 (PORT_BASE     + 0x00E400)
#define GPIORFR1                        _REG32 (PORT_BASE     + 0x00E424)
#define GPIORFR2                        _REG32 (PORT_BASE     + 0x00E428)
#define GPIORIS                         _REG32 (PORT_BASE     + 0x00E804)
#define GPIORIBE                        _REG32 (PORT_BASE     + 0x00E808)
#define GPIORIEV                        _REG32 (PORT_BASE     + 0x00E80C)
#define GPIORIE                         _REG32 (PORT_BASE     + 0x00E810)
#define GPIORRIS                        _REG32 (PORT_BASE     + 0x00E814)
#define GPIORMIS                        _REG32 (PORT_BASE     + 0x00E818)
#define GPIORIC                         _REG32 (PORT_BASE     + 0x00E81C)

/* Port T Registers                                                           */
#define GPIOTDATA                       _REG32 (PORT_BASE     + 0x00F3FC)
#define GPIOTDIR                        _REG32 (PORT_BASE     + 0x00F400)
#define GPIOTFR1                        _REG32 (PORT_BASE     + 0x00F424)

/* UART0 Registers                                                            */
#define UART0DR                         _REG32 (UART_BASE     + 0x000000)
#define UART0SR                         _REG32 (UART_BASE     + 0x000004)
#define UART0ECR                        _REG32 (UART_BASE     + 0x000004)
#define UART0FR                         _REG32 (UART_BASE     + 0x000018)
#define UART0ILPR                       _REG32 (UART_BASE     + 0x000020)
#define UART0IBRD                       _REG32 (UART_BASE     + 0x000024)
#define UART0FBRD                       _REG32 (UART_BASE     + 0x000028)
#define UART0LCR_H                      _REG32 (UART_BASE     + 0x00002C)
#define UART0CR                         _REG32 (UART_BASE     + 0x000030)
#define UART0IFLS                       _REG32 (UART_BASE     + 0x000034)
#define UART0IMSC                       _REG32 (UART_BASE     + 0x000038)
#define UART0RIS                        _REG32 (UART_BASE     + 0x00003C)
#define UART0MIS                        _REG32 (UART_BASE     + 0x000040)
#define UART0ICR                        _REG32 (UART_BASE     + 0x000044)
#define UART0DMACR                      _REG32 (UART_BASE     + 0x000048)

/* UART1 Registers                                                            */
#define UART1DR                         _REG32 (UART_BASE     + 0x001000)
#define UART1SR                         _REG32 (UART_BASE     + 0x001004)
#define UART1ECR                        _REG32 (UART_BASE     + 0x001004)
#define UART1FR                         _REG32 (UART_BASE     + 0x001018)
#define UART1IBRD                       _REG32 (UART_BASE     + 0x001024)
#define UART1FBRD                       _REG32 (UART_BASE     + 0x001028)
#define UART1LCR_H                      _REG32 (UART_BASE     + 0x00102C)
#define UART1CR                         _REG32 (UART_BASE     + 0x001030)
#define UART1IFLS                       _REG32 (UART_BASE     + 0x001034)
#define UART1IMSC                       _REG32 (UART_BASE     + 0x001038)
#define UART1RIS                        _REG32 (UART_BASE     + 0x00103C)
#define UART1MIS                        _REG32 (UART_BASE     + 0x001040)
#define UART1ICR                        _REG32 (UART_BASE     + 0x001044)

/* Synchronous Serial Peripheral 0 (SSP0) Registers                           */
#define SSP0CR0                         _REG32 (SSP_BASE      + 0x000000)
#define SSP0CR1                         _REG32 (SSP_BASE      + 0x000004)
#define SSP0DR                          _REG32 (SSP_BASE      + 0x000008)
#define SSP0SR                          _REG32 (SSP_BASE      + 0x00000C)
#define SSP0CPSR                        _REG32 (SSP_BASE      + 0x000010)
#define SSP0IMSC                        _REG32 (SSP_BASE      + 0x000014)
#define SSP0RIS                         _REG32 (SSP_BASE      + 0x000018)
#define SSP0MIS                         _REG32 (SSP_BASE      + 0x00001C)
#define SSP0ICR                         _REG32 (SSP_BASE      + 0x000020)

/* Synchronous Serial Peripheral 1 (SSP1) Registers                           */
#define SSP1CR0                         _REG32 (SSP_BASE      + 0x001000)
#define SSP1CR1                         _REG32 (SSP_BASE      + 0x001004)
#define SSP1DR                          _REG32 (SSP_BASE      + 0x001008)
#define SSP1SR                          _REG32 (SSP_BASE      + 0x00100C)
#define SSP1CPSR                        _REG32 (SSP_BASE      + 0x001010)
#define SSP1IMSC                        _REG32 (SSP_BASE      + 0x001014)
#define SSP1RIS                         _REG32 (SSP_BASE      + 0x001018)
#define SSP1MIS                         _REG32 (SSP_BASE      + 0x00101C)
#define SSP1ICR                         _REG32 (SSP_BASE      + 0x001020)

/* NAND-Flash Controller (NDFC) Registers                                     */
#define NDFMCR0                         _REG32 (NDFC_BASE     + 0x000000)
#define NDFMCR1                         _REG32 (NDFC_BASE     + 0x000004)
#define NDFMCR2                         _REG32 (NDFC_BASE     + 0x000008)
#define NDFINTC                         _REG32 (NDFC_BASE     + 0x00000C)
#define NDFDTR                          _REG32 (NDFC_BASE     + 0x000010)
#define NDECCRD0                        _REG32 (NDFC_BASE     + 0x000020)
#define NDECCRD1                        _REG32 (NDFC_BASE     + 0x000024)
#define NDECCRD2                        _REG32 (NDFC_BASE     + 0x000028)
#define NDRSCA0                         _REG32 (NDFC_BASE     + 0x000030)
#define NDRSCD0                         _REG32 (NDFC_BASE     + 0x000034)
#define NDRSCA1                         _REG32 (NDFC_BASE     + 0x000038)
#define NDRSCD1                         _REG32 (NDFC_BASE     + 0x00003C)
#define NDRSCA2                         _REG32 (NDFC_BASE     + 0x000040)
#define NDRSCD2                         _REG32 (NDFC_BASE     + 0x000044)
#define NDRSCA3                         _REG32 (NDFC_BASE     + 0x000048)
#define NDRSCD3                         _REG32 (NDFC_BASE     + 0x00004C)

/* CMOS Image Sensor Interface (CMSI) Registers                               */
#define CMSCR                           _REG32 (CMSI_BASE     + 0x000000)
#define CMSCV                           _REG32 (CMSI_BASE     + 0x000004)
#define CMSCVP0                         _REG32 (CMSI_BASE     + 0x000008)
#define CMSCVP1                         _REG32 (CMSI_BASE     + 0x00000C)
#define CMSYD                           _REG32 (CMSI_BASE     + 0x000010)
#define CMSUD                           _REG32 (CMSI_BASE     + 0x000014)
#define CMSVD                           _REG32 (CMSI_BASE     + 0x000018)
#define CMSFPT                          _REG32 (CMSI_BASE     + 0x000020)
#define CMSCSTR                         _REG32 (CMSI_BASE     + 0x000024)
#define CMSTS                           _REG32 (CMSI_BASE     + 0x000030)
#define CMSTE                           _REG32 (CMSI_BASE     + 0x000034)
#define CMSSCDMA                        _REG32 (CMSI_BASE     + 0x000040)

/* Inter-IC Sound (I2S) Registers                                             */
#define I2STCON                         _REG32 (I2S_BASE      + 0x000000)
#define I2STSLVON                       _REG32 (I2S_BASE      + 0x000004)
#define I2STFCLR                        _REG32 (I2S_BASE      + 0x000008)
#define I2STMS                          _REG32 (I2S_BASE      + 0x00000C)
#define I2STMCON                        _REG32 (I2S_BASE      + 0x000010)
#define I2STMSTP                        _REG32 (I2S_BASE      + 0x000014)
#define I2STDMA1                        _REG32 (I2S_BASE      + 0x000018)
#define I2SRCON                         _REG32 (I2S_BASE      + 0x000020)
#define I2SRSLVON                       _REG32 (I2S_BASE      + 0x000024)
#define I2SFRFCLR                       _REG32 (I2S_BASE      + 0x000028)
#define I2SRMS                          _REG32 (I2S_BASE      + 0x00002C)
#define I2SRMCON                        _REG32 (I2S_BASE      + 0x000030)
#define I2SRMSTP                        _REG32 (I2S_BASE      + 0x000034)
#define I2SRDMA1                        _REG32 (I2S_BASE      + 0x000038)
#define I2SCOMMON                       _REG32 (I2S_BASE      + 0x000044)
#define I2STST                          _REG32 (I2S_BASE      + 0x000048)
#define I2SRST                          _REG32 (I2S_BASE      + 0x00004C)
#define I2SINT                          _REG32 (I2S_BASE      + 0x000050)
#define I2SINTMSK                       _REG32 (I2S_BASE      + 0x000054)

/* LCD Data Process Accelerator (LCDDA) Registers                             */
#define LDACR0                          _REG32 (LCDDA_BASE    + 0x000000)
#define LDADRSRC1                       _REG32 (LCDDA_BASE    + 0x000004)
#define LDADRSRC0                       _REG32 (LCDDA_BASE    + 0x000008)
#define LDAFCPSRC1                      _REG32 (LCDDA_BASE    + 0x00000C)
#define LDAEFCPSRC1                     _REG32 (LCDDA_BASE    + 0x000010)
#define LDADVSRC1                       _REG32 (LCDDA_BASE    + 0x000014)
#define LDACR2                          _REG32 (LCDDA_BASE    + 0x000018)
#define LDADXDST                        _REG32 (LCDDA_BASE    + 0x00001C)
#define LDADYDST                        _REG32 (LCDDA_BASE    + 0x000020)
#define LDASSIZE                        _REG32 (LCDDA_BASE    + 0x000024)
#define LDADSIZE                        _REG32 (LCDDA_BASE    + 0x000028)
#define LDAS0AD                         _REG32 (LCDDA_BASE    + 0x00002C)
#define LDADAD                          _REG32 (LCDDA_BASE    + 0x000030)
#define LDACR1                          _REG32 (LCDDA_BASE    + 0x000034)
#define LDADVSRC0                       _REG32 (LCDDA_BASE    + 0x000038)

/* Interrupt Controller (INTC) Registers                                      */
#define VICIRQSTATUS                    _REG32 (INTC_BASE     + 0x000000)
#define VICFIQSTATUS                    _REG32 (INTC_BASE     + 0x000004)
#define VICRAWINTR                      _REG32 (INTC_BASE     + 0x000008)
#define VICINTSELECT                    _REG32 (INTC_BASE     + 0x00000C)
#define VICINTENABLE                    _REG32 (INTC_BASE     + 0x000010)
#define VICINTENCLEAR                   _REG32 (INTC_BASE     + 0x000014)
#define VICSOFTINT                      _REG32 (INTC_BASE     + 0x000018)
#define VICSOFTINTCLEAR                 _REG32 (INTC_BASE     + 0x00001C)
#define VICPROTECTION                   _REG32 (INTC_BASE     + 0x000020)
#define VICSWPRIORITYMASK               _REG32 (INTC_BASE     + 0x000024)
#define VICVECTADDR0                    _REG32 (INTC_BASE     + 0x000100)
#define VICVECTADDR1                    _REG32 (INTC_BASE     + 0x000104)
#define VICVECTADDR2                    _REG32 (INTC_BASE     + 0x000108)
#define VICVECTADDR3                    _REG32 (INTC_BASE     + 0x00010C)
#define VICVECTADDR4                    _REG32 (INTC_BASE     + 0x000110)
#define VICVECTADDR5                    _REG32 (INTC_BASE     + 0x000114)
#define VICVECTADDR6                    _REG32 (INTC_BASE     + 0x000118)
#define VICVECTADDR7                    _REG32 (INTC_BASE     + 0x00011C)
#define VICVECTADDR8                    _REG32 (INTC_BASE     + 0x000120)
#define VICVECTADDR10                   _REG32 (INTC_BASE     + 0x000128)
#define VICVECTADDR11                   _REG32 (INTC_BASE     + 0x00012C)
#define VICVECTADDR12                   _REG32 (INTC_BASE     + 0x000130)
#define VICVECTADDR13                   _REG32 (INTC_BASE     + 0x000134)
#define VICVECTADDR14                   _REG32 (INTC_BASE     + 0x000138)
#define VICVECTADDR15                   _REG32 (INTC_BASE     + 0x00013C)
#define VICVECTADDR16                   _REG32 (INTC_BASE     + 0x000140)
#define VICVECTADDR17                   _REG32 (INTC_BASE     + 0x000144)
#define VICVECTADDR18                   _REG32 (INTC_BASE     + 0x000148)
#define VICVECTADDR20                   _REG32 (INTC_BASE     + 0x000150)
#define VICVECTADDR21                   _REG32 (INTC_BASE     + 0x000154)
#define VICVECTADDR22                   _REG32 (INTC_BASE     + 0x000158)
#define VICVECTADDR23                   _REG32 (INTC_BASE     + 0x00015C)
#define VICVECTADDR26                   _REG32 (INTC_BASE     + 0x000168)
#define VICVECTADDR27                   _REG32 (INTC_BASE     + 0x00016C)
#define VICVECTADDR28                   _REG32 (INTC_BASE     + 0x000170)
#define VICVECTADDR29                   _REG32 (INTC_BASE     + 0x000174)
#define VICVECTADDR30                   _REG32 (INTC_BASE     + 0x000178)
#define VICVECTADDR31                   _REG32 (INTC_BASE     + 0x00017C)
#define VICVECTPRIORITY0                _REG32 (INTC_BASE     + 0x000200)
#define VICVECTPRIORITY1                _REG32 (INTC_BASE     + 0x000204)
#define VICVECTPRIORITY2                _REG32 (INTC_BASE     + 0x000208)
#define VICVECTPRIORITY3                _REG32 (INTC_BASE     + 0x00020C)
#define VICVECTPRIORITY4                _REG32 (INTC_BASE     + 0x000210)
#define VICVECTPRIORITY5                _REG32 (INTC_BASE     + 0x000214)
#define VICVECTPRIORITY6                _REG32 (INTC_BASE     + 0x000218)
#define VICVECTPRIORITY7                _REG32 (INTC_BASE     + 0x00021C)
#define VICVECTPRIORITY8                _REG32 (INTC_BASE     + 0x000220)
#define VICVECTPRIORITY10               _REG32 (INTC_BASE     + 0x000228)
#define VICVECTPRIORITY11               _REG32 (INTC_BASE     + 0x00022C)
#define VICVECTPRIORITY12               _REG32 (INTC_BASE     + 0x000230)
#define VICVECTPRIORITY13               _REG32 (INTC_BASE     + 0x000234)
#define VICVECTPRIORITY14               _REG32 (INTC_BASE     + 0x000238)
#define VICVECTPRIORITY15               _REG32 (INTC_BASE     + 0x00023C)
#define VICVECTPRIORITY16               _REG32 (INTC_BASE     + 0x000240)
#define VICVECTPRIORITY17               _REG32 (INTC_BASE     + 0x000244)
#define VICVECTPRIORITY18               _REG32 (INTC_BASE     + 0x000248)
#define VICVECTPRIORITY20               _REG32 (INTC_BASE     + 0x000250)
#define VICVECTPRIORITY21               _REG32 (INTC_BASE     + 0x000254)
#define VICVECTPRIORITY22               _REG32 (INTC_BASE     + 0x000258)
#define VICVECTPRIORITY23               _REG32 (INTC_BASE     + 0x00025C)
#define VICVECTPRIORITY26               _REG32 (INTC_BASE     + 0x000268)
#define VICVECTPRIORITY27               _REG32 (INTC_BASE     + 0x00026C)
#define VICVECTPRIORITY28               _REG32 (INTC_BASE     + 0x000270)
#define VICVECTPRIORITY29               _REG32 (INTC_BASE     + 0x000274)
#define VICVECTPRIORITY30               _REG32 (INTC_BASE     + 0x000278)
#define VICVECTPRIORITY31               _REG32 (INTC_BASE     + 0x00027C)
#define VICADDRESS                      _REG32 (INTC_BASE     + 0x000F00)

/* DMA Controller (DMAC) Registers                                            */
#define DMACINTSTAUS                    _REG32 (DMAC_BASE     + 0x000000)
#define DMACINTTCSTATUS                 _REG32 (DMAC_BASE     + 0x000004)
#define DMACINTTCCLEAR                  _REG32 (DMAC_BASE     + 0x000008)
#define DMACINTERRORSTATUS              _REG32 (DMAC_BASE     + 0x00000C)
#define DMACINTERRCLR                   _REG32 (DMAC_BASE     + 0x000010)
#define DMACRAWINTTCSTATUS              _REG32 (DMAC_BASE     + 0x000014)
#define DMACRAWINTERRORSTATUS           _REG32 (DMAC_BASE     + 0x000018)
#define DMACENBLDCHNS                   _REG32 (DMAC_BASE     + 0x00001C)
#define DMACSOFTBREQ                    _REG32 (DMAC_BASE     + 0x000020)
#define DMACSOFTSREQ                    _REG32 (DMAC_BASE     + 0x000024)
#define DMACCONFIGURATION               _REG32 (DMAC_BASE     + 0x000030)
#define DMACC0SRCADDR                   _REG32 (DMAC_BASE     + 0x000100)
#define DMACC0DESTADDR                  _REG32 (DMAC_BASE     + 0x000104)
#define DMACC0LLI                       _REG32 (DMAC_BASE     + 0x000108)
#define DMACC0CONTROL                   _REG32 (DMAC_BASE     + 0x00010C)
#define DMACC0CONFIGURATION             _REG32 (DMAC_BASE     + 0x000110)
#define DMACC1SRCADDR                   _REG32 (DMAC_BASE     + 0x000120)
#define DMACC1DESTADDR                  _REG32 (DMAC_BASE     + 0x000124)
#define DMACC1LLI                       _REG32 (DMAC_BASE     + 0x000128)
#define DMACC1CONTROL                   _REG32 (DMAC_BASE     + 0x00012C)
#define DMACC1CONFIGURATION             _REG32 (DMAC_BASE     + 0x000130)
#define DMACC2SRCADDR                   _REG32 (DMAC_BASE     + 0x000140)
#define DMACC2DESTADDR                  _REG32 (DMAC_BASE     + 0x000144)
#define DMACC2LLI                       _REG32 (DMAC_BASE     + 0x000148)
#define DMACC2CONTROL                   _REG32 (DMAC_BASE     + 0x00014C)
#define DMACC2CONFIGURATION             _REG32 (DMAC_BASE     + 0x000150)
#define DMACC3SRCADDR                   _REG32 (DMAC_BASE     + 0x000160)
#define DMACC3DESTADDR                  _REG32 (DMAC_BASE     + 0x000164)
#define DMACC3LLI                       _REG32 (DMAC_BASE     + 0x000168)
#define DMACC3CONTROL                   _REG32 (DMAC_BASE     + 0x00016C)
#define DMACC3CONFIGURATION             _REG32 (DMAC_BASE     + 0x000170)
#define DMACC4SRCADDR                   _REG32 (DMAC_BASE     + 0x000180)
#define DMACC4DESTADDR                  _REG32 (DMAC_BASE     + 0x000184)
#define DMACC4LLI                       _REG32 (DMAC_BASE     + 0x000188)
#define DMACC4CONTROL                   _REG32 (DMAC_BASE     + 0x00018C)
#define DMACC4CONFIGURATION             _REG32 (DMAC_BASE     + 0x000190)
#define DMACC5SRCADDR                   _REG32 (DMAC_BASE     + 0x0001A0)
#define DMACC5DESTADDR                  _REG32 (DMAC_BASE     + 0x0001A4)
#define DMACC5LLI                       _REG32 (DMAC_BASE     + 0x0001A8)
#define DMACC5CONTROL                   _REG32 (DMAC_BASE     + 0x0001AC)
#define DMACC5CONFIGURATION             _REG32 (DMAC_BASE     + 0x0001B0)
#define DMACC6SRCADDR                   _REG32 (DMAC_BASE     + 0x0001C0)
#define DMACC6DESTADDR                  _REG32 (DMAC_BASE     + 0x0001C4)
#define DMACC6LLI                       _REG32 (DMAC_BASE     + 0x0001C8)
#define DMACC6CONTROL                   _REG32 (DMAC_BASE     + 0x0001CC)
#define DMACC6CONFIGURATION             _REG32 (DMAC_BASE     + 0x0001D0)
#define DMACC7SRCADDR                   _REG32 (DMAC_BASE     + 0x0001E0)
#define DMACC7DESTADDR                  _REG32 (DMAC_BASE     + 0x0001E4)
#define DMACC7LLI                       _REG32 (DMAC_BASE     + 0x0001E8)
#define DMACC7CONTROL                   _REG32 (DMAC_BASE     + 0x0001EC)
#define DMACC7CONFIGURATION             _REG32 (DMAC_BASE     + 0x0001F0)

/* LCD Controller (LCDC) Registers                                            */
#define LCDTIMING0                      _REG32 (LCDC_BASE     + 0x000000)
#define LCDTIMING1                      _REG32 (LCDC_BASE     + 0x000004)
#define LCDTIMING2                      _REG32 (LCDC_BASE     + 0x000008)
#define LCDTIMING3                      _REG32 (LCDC_BASE     + 0x00000c)
#define LCDUPBASE                       _REG32 (LCDC_BASE     + 0x000010)
#define LCDLPBASE                       _REG32 (LCDC_BASE     + 0x000014)
#define LCDIMSC                         _REG32 (LCDC_BASE     + 0x000018)
#define LCDCONTROL                      _REG32 (LCDC_BASE     + 0x00001c)
#define LCDRIS                          _REG32 (LCDC_BASE     + 0x000020)
#define LCDMIS                          _REG32 (LCDC_BASE     + 0x000024)
#define LCDICR                          _REG32 (LCDC_BASE     + 0x000028)
#define LCDUPCURR                       _REG32 (LCDC_BASE     + 0x00002c)
#define LCDLPCURR                       _REG32 (LCDC_BASE     + 0x000030)
#define LCDPALETTE                      _REG32 (LCDC_BASE     + 0x000200)

/* Dynamic Memory Controller (DMC) Registers on MPMC0                         */
#define DMC_MEMC_STATUS_3               _REG32 (MPMC0_BASE    + 0x000000)
#define DMC_MEMC_CMD_3                  _REG32 (MPMC0_BASE    + 0x000004)
#define DMC_DIRECT_CMD_3                _REG32 (MPMC0_BASE    + 0x000008)
#define DMC_MEMORY_CFG_3                _REG32 (MPMC0_BASE    + 0x00000C)
#define DMC_REFRESH_PRD_3               _REG32 (MPMC0_BASE    + 0x000010)
#define DMC_CAS_LATENCY_3               _REG32 (MPMC0_BASE    + 0x000014)
#define DMC_T_DQSS_3                    _REG32 (MPMC0_BASE    + 0x000018)
#define DMC_T_MRD_3                     _REG32 (MPMC0_BASE    + 0x00001C)
#define DMC_T_RAS_3                     _REG32 (MPMC0_BASE    + 0x000020)
#define DMC_T_RC_3                      _REG32 (MPMC0_BASE    + 0x000024)
#define DMC_T_RCD_3                     _REG32 (MPMC0_BASE    + 0x000028)
#define DMC_T_RFC_3                     _REG32 (MPMC0_BASE    + 0x00002C)
#define DMC_T_RP_3                      _REG32 (MPMC0_BASE    + 0x000030)
#define DMC_T_RRD_3                     _REG32 (MPMC0_BASE    + 0x000034)
#define DMC_T_WR_3                      _REG32 (MPMC0_BASE    + 0x000038)
#define DMC_T_WTR_3                     _REG32 (MPMC0_BASE    + 0x00003C)
#define DMC_T_XP_3                      _REG32 (MPMC0_BASE    + 0x000040)
#define DMC_T_XSR_3                     _REG32 (MPMC0_BASE    + 0x000044)
#define DMC_T_ESR_3                     _REG32 (MPMC0_BASE    + 0x000048)
#define DMC_ID_0_CFG_3                  _REG32 (MPMC0_BASE    + 0x000100)
#define DMC_ID_1_CFG_3                  _REG32 (MPMC0_BASE    + 0x000104)
#define DMC_ID_2_CFG_3                  _REG32 (MPMC0_BASE    + 0x000108)
#define DMC_ID_3_CFG_3                  _REG32 (MPMC0_BASE    + 0x00010C)
#define DMC_CHIP_0_CFG_3                _REG32 (MPMC0_BASE    + 0x000200)
#define DMC_USER_CONFIG_3               _REG32 (MPMC0_BASE    + 0x000304)

/* Static Memory Controller (SMC) Registers on MPMC0                          */
#define SMC_MEMC_STATUS_3               _REG32 (MPMC0_BASE    + 0x001000)
#define SMC_MEMIF_CFG_3                 _REG32 (MPMC0_BASE    + 0x001004)
#define SMC_DIRECT_CMD_3                _REG32 (MPMC0_BASE    + 0x001010)
#define SMC_SET_CYCLES_3                _REG32 (MPMC0_BASE    + 0x001014)
#define SMC_SET_OPMODE_3                _REG32 (MPMC0_BASE    + 0x001018)
#define SMC_SRAM_CYCLES0_0_3            _REG32 (MPMC0_BASE    + 0x001100)
#define SMC_SRAM_CYCLES0_1_3            _REG32 (MPMC0_BASE    + 0x001120)
#define SMC_SRAM_CYCLES0_2_3            _REG32 (MPMC0_BASE    + 0x001140)
#define SMC_SRAM_CYCLES0_3_3            _REG32 (MPMC0_BASE    + 0x001160)
#define SMC_OPMODE0_0_3                 _REG32 (MPMC0_BASE    + 0x001104)
#define SMC_OPMODE0_1_3                 _REG32 (MPMC0_BASE    + 0x001124)
#define SMC_OPMODE0_2_3                 _REG32 (MPMC0_BASE    + 0x001144)
#define SMC_OPMODE0_3_3                 _REG32 (MPMC0_BASE    + 0x001164)

/* Dynamic Memory Controller (DMC) Registers on MPMC1                         */
#define DMC_MEMC_STATUS_5               _REG32 (MPMC1_BASE    + 0x000000)
#define DMC_MEMC_CMD_5                  _REG32 (MPMC1_BASE    + 0x000004)
#define DMC_DIRECT_CMD_5                _REG32 (MPMC1_BASE    + 0x000008)
#define DMC_MEMORY_CFG_5                _REG32 (MPMC1_BASE    + 0x00000C)
#define DMC_REFRESH_PRD_5               _REG32 (MPMC1_BASE    + 0x000010)
#define DMC_CAS_LATENCY_5               _REG32 (MPMC1_BASE    + 0x000014)
#define DMC_T_DQSS_5                    _REG32 (MPMC1_BASE    + 0x000018)
#define DMC_T_MRD_5                     _REG32 (MPMC1_BASE    + 0x00001C)
#define DMC_T_RAS_5                     _REG32 (MPMC1_BASE    + 0x000020)
#define DMC_T_RC_5                      _REG32 (MPMC1_BASE    + 0x000024)
#define DMC_T_RCD_5                     _REG32 (MPMC1_BASE    + 0x000028)
#define DMC_T_RFC_5                     _REG32 (MPMC1_BASE    + 0x00002C)
#define DMC_T_RP_5                      _REG32 (MPMC1_BASE    + 0x000030)
#define DMC_T_RRD_5                     _REG32 (MPMC1_BASE    + 0x000034)
#define DMC_T_WR_5                      _REG32 (MPMC1_BASE    + 0x000038)
#define DMC_T_WTR_5                     _REG32 (MPMC1_BASE    + 0x00003C)
#define DMC_T_XP_5                      _REG32 (MPMC1_BASE    + 0x000040)
#define DMC_T_XSR_5                     _REG32 (MPMC1_BASE    + 0x000044)
#define DMC_T_ESR_5                     _REG32 (MPMC1_BASE    + 0x000048)
#define DMC_ID_0_CFG_5                  _REG32 (MPMC1_BASE    + 0x000100)
#define DMC_ID_1_CFG_5                  _REG32 (MPMC1_BASE    + 0x000104)
#define DMC_ID_2_CFG_5                  _REG32 (MPMC1_BASE    + 0x000108)
#define DMC_ID_3_CFG_5                  _REG32 (MPMC1_BASE    + 0x00010C)
#define DMC_ID_4_CFG_5                  _REG32 (MPMC1_BASE    + 0x000110)
#define DMC_ID_5_CFG_5                  _REG32 (MPMC1_BASE    + 0x000114)
#define DMC_CHIP_0_CFG_5                _REG32 (MPMC1_BASE    + 0x000200)
#define DMC_USER_CONFIG_5               _REG32 (MPMC1_BASE    + 0x000304)

/* Static Memory Controller (SMC) Registers on MPMC1                          */
#define SMC_MEMC_STATUS_5               _REG32 (MPMC1_BASE    + 0x001000)
#define SMC_MEMIF_CFG_5                 _REG32 (MPMC1_BASE    + 0x001004)
#define SMC_DIRECT_CMD_5                _REG32 (MPMC1_BASE    + 0x001010)
#define SMC_SET_CYCLES_5                _REG32 (MPMC1_BASE    + 0x001014)
#define SMC_SET_OPMODE_5                _REG32 (MPMC1_BASE    + 0x001018)
#define SMC_SRAM_CYCLES0_0_5            _REG32 (MPMC1_BASE    + 0x001100)
#define SMC_SRAM_CYCLES0_1_5            _REG32 (MPMC1_BASE    + 0x001120)
#define SMC_SRAM_CYCLES0_2_5            _REG32 (MPMC1_BASE    + 0x001140)
#define SMC_SRAM_CYCLES0_3_5            _REG32 (MPMC1_BASE    + 0x001160)
#define SMC_OPMODE0_0_5                 _REG32 (MPMC1_BASE    + 0x001104)
#define SMC_OPMODE0_1_5                 _REG32 (MPMC1_BASE    + 0x001124)
#define SMC_OPMODE0_2_5                 _REG32 (MPMC1_BASE    + 0x001144)
#define SMC_OPMODE0_3_5                 _REG32 (MPMC1_BASE    + 0x001164)

/* Universal Serial Bus Device Controller                                     */
/* USB-Spec2.0 Device Controller (UDC2) and UDC2 to AHB Registers             */
#define UDINTSTS                        _REG32 (USB_BASE      + 0x000000)
#define UDINTENB                        _REG32 (USB_BASE      + 0x000004)
#define UDMWTOUT                        _REG32 (USB_BASE      + 0x000008)
#define UDC2STSET                       _REG32 (USB_BASE      + 0x00000C)
#define UDMSTSET                        _REG32 (USB_BASE      + 0x000010)
#define DMACRDREQ                       _REG32 (USB_BASE      + 0x000014)
#define DMACRDVL                        _REG32 (USB_BASE      + 0x000018)
#define UDC2RDREQ                       _REG32 (USB_BASE      + 0x00001C)
#define UDC2RDVL                        _REG32 (USB_BASE      + 0x000020)
#define ARBTSET                         _REG32 (USB_BASE      + 0x00003C)
#define UDMWSADR                        _REG32 (USB_BASE      + 0x000040)
#define UDMWEADR                        _REG32 (USB_BASE      + 0x000044)
#define UDMWCADR                        _REG32 (USB_BASE      + 0x000048)
#define UDMWAHBADR                      _REG32 (USB_BASE      + 0x00004C)
#define UDMRSADR                        _REG32 (USB_BASE      + 0x000050)
#define UDMREADR                        _REG32 (USB_BASE      + 0x000054)
#define UDMRCADR                        _REG32 (USB_BASE      + 0x000058)
#define UDMRAHBADR                      _REG32 (USB_BASE      + 0x00005C)
#define UDPWCTL                         _REG32 (USB_BASE      + 0x000080)
#define UDMSTSTS                        _REG32 (USB_BASE      + 0x000084)
#define UDTOUTCNT                       _REG32 (USB_BASE      + 0x000088)
#define UD2ADR                          _REG32 (USB_BASE      + 0x000200)
#define UD2FRM                          _REG32 (USB_BASE      + 0x000204)
#define UD2TMD                          _REG32 (USB_BASE      + 0x000208)
#define UD2CMD                          _REG32 (USB_BASE      + 0x00020C)
#define UD2BRQ                          _REG32 (USB_BASE      + 0x000210)
#define UD2WVL                          _REG32 (USB_BASE      + 0x000214)
#define UD2WIDX                         _REG32 (USB_BASE      + 0x000218)
#define UD2WLGTH                        _REG32 (USB_BASE      + 0x00021C)
#define UD2INT                          _REG32 (USB_BASE      + 0x000220)
#define UD2INTEP                        _REG32 (USB_BASE      + 0x000224)
#define UD2INTEPMSK                     _REG32 (USB_BASE      + 0x000228)
#define UD2INTRX0                       _REG32 (USB_BASE      + 0x00022C)
#define UD2EP0MSZ                       _REG32 (USB_BASE      + 0x000230)
#define UD2EP0STS                       _REG32 (USB_BASE      + 0x000234)
#define UD2EP0DSZ                       _REG32 (USB_BASE      + 0x000238)
#define UD2EP0FIFO                      _REG32 (USB_BASE      + 0x00023C)
#define UD2EP1MSZ                       _REG32 (USB_BASE      + 0x000240)
#define UD2EP1STS                       _REG32 (USB_BASE      + 0x000244)
#define UD2EP1DSZ                       _REG32 (USB_BASE      + 0x000248)
#define UD2EP1FIFO                      _REG32 (USB_BASE      + 0x00024C)
#define UD2EP2MSZ                       _REG32 (USB_BASE      + 0x000250)
#define UD2EP2STS                       _REG32 (USB_BASE      + 0x000254)
#define UD2EP2DSZ                       _REG32 (USB_BASE      + 0x000258)
#define UD2EP2FIFO                      _REG32 (USB_BASE      + 0x00025C)
#define UD2EP3MSZ                       _REG32 (USB_BASE      + 0x000260)
#define UD2EP3STS                       _REG32 (USB_BASE      + 0x000264)
#define UD2EP3DSZ                       _REG32 (USB_BASE      + 0x000268)
#define UD2EP3FIFO                      _REG32 (USB_BASE      + 0x00026C)
#define UD2INTNAK                       _REG32 (USB_BASE      + 0x000330)
#define UD2INTNAKMSK                    _REG32 (USB_BASE      + 0x000334)


/* Constants Definitions -----------------------------------------------------*/

/* Interrupt sources                                                          */
#define INT_WDT                         0
#define INT_RTC                         1
#define INT_TIMER01                     2
#define INT_TIMER23                     3
#define INT_TIMER45                     4
#define INT_GPIOD                       5
#define INT_I2S0                        6
#define INT_I2S1                        7
#define INT_ADC                         8
#define INT_UART0                       10
#define INT_UART1                       11
#define INT_SSP0                        12
#define INT_SSP1                        13
#define INT_NDFC                        14
#define INT_CMSIF                       15
#define INT_DMA_ERR                     16
#define INT_DMA_END                     17
#define INT_LCDC                        18
#define INT_LCDDA                       20
#define INT_USB                         21
#define INT_SDHC                        22
#define INT_I2S                         23
#define INT_GPIOR                       26
#define INT_GPIOP                       27
#define INT_GPION                       28
#define INT_GPIOF                       29
#define INT_GPIOC                       30
#define INT_GPIOA                       31

/* DMA request numbers                                                        */
#define DMA_UTART0_TX                   0
#define DMA_UTART0_RX                   1
#define DMA_NANDC0                      4
#define DMA_CMSI                        5
#define DMA_SDHC_WR_REQ                 8
#define DMA_SDHC_RD_REQ                 9
#define DMA_I2S0                        10
#define DMA_I2S1                        11
#define DMA_LCDDA                       14

#endif  // __TMPA910_H

