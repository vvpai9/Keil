/**************************************************************************//**
 * @file     NUC501.h
 * @brief    Peripheral Access Layer Header File for 
 *           for the Nuvoton NUC501 Device Series
 * @version  V1.00
 * @date     11. May 2010
 *
 * @note
 * Copyright (C) 2010 ARM Limited. All rights reserved.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __NUC501_H__
#define __NUC501_H__

#ifdef __cplusplus
 extern "C" {
#endif 

#include <stdint.h>                           /* Include standard types */

/**
 * IO definitions
 *
 * define access restrictions to peripheral registers
 */

#ifdef __cplusplus
  #define     __I     volatile                /*!< defines 'read only' permissions      */
#else
  #define     __I     volatile const          /*!< defines 'read only' permissions      */
#endif
#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */


/** @addtogroup NUC501_Definitions NUC501 Definitions
  This file defines all structures and symbols for NUC501:
    - Registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
  @{
*/



/******************************************************************************/
/*                Device Specific Peripheral Registers structures             */
/******************************************************************************/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/*------------- System Manager Control (GCR) ---------------------------------*/
/** @addtogroup NUC501_GCR NUC501 System Manager Control Block 
  @{
*/
typedef struct {
  __I  uint32_t PDID;                   /*!< Offset: 0x000 (R/ ) Product Identification Register */
  __IO uint32_t SPOCR;                  /*!< Offset: 0x004 (R/W) System Power-On Configuration Register */
  __IO uint32_t CPUCR;                  /*!< Offset: 0x008 (R/W) CPU Control Register */
  __IO uint32_t MISCR;                  /*!< Offset: 0x00C (R/W) Miscellaneous Control Register */
       uint32_t RESERVED0[1];
  __IO uint32_t IPRST;                  /*!< Offset: 0x014 (R/W) IP Reset Control Resister */
       uint32_t RESERVED1[2];
  __IO uint32_t AHB_CTRL;               /*!< Offset: 0x020 (R/W) AHB Bus Control register */
       uint32_t RESERVED2[3];
  __IO uint32_t PAD_REG[3];             /*!< Offset: 0x030 (R/W) PAD function */
       uint32_t RESERVED3[14];
  __IO uint32_t GP_DS;                  /*!< Offset: 0x074 (R/W) GPIO pads driving strength control */
} NUC_GCR_TypeDef;
/*@}*/ /* end of group NUC501_GCR */


/*------------- Clock Control (CLK) ------------------------------------------*/
/** @addtogroup NUC501_CLK NUC501 Clock Control Block 
  @{
*/
typedef struct {
  __IO uint32_t PWRCON;                 /*!< Offset: 0x000 (R/W) System Power Down Control Register */
  __IO uint32_t AHBCLK;                 /*!< Offset: 0x004 (R/W) AHB Device Clock Enable Control Register */
  __IO uint32_t APBCLK;                 /*!< Offset: 0x008 (R/W) APB Device Clock Enable Control Register */
       uint32_t RESERVED0[1];
  __IO uint32_t CLKSEL;                 /*!< Offset: 0x010 (R/W) Clock Source Select Control Register */
  __IO uint32_t CLKDIV0;                /*!< Offset: 0x014 (R/W) Clock Divider Number Register 0 */
  __IO uint32_t CLKDIV1;                /*!< Offset: 0x018 (R/W) Clock Divider Number Register 1 */
       uint32_t RESERVED1[1];
  __IO uint32_t MPLLCON;                /*!< Offset: 0x020 (R/W) MPLL Control Register */
} NUC_CLK_TypeDef;
/*@}*/ /* end of group NUC501_CLK */


/*------------- SRAM Control (SRAMCTL) ------------------------------------------*/
/** @addtogroup NUC501_SRAMCTL NUC501 SRAM Control 
  @{
*/
typedef struct {
  __IO uint32_t CR[16];                 /*!< Offset: 0x000 (R/W) SRAM Control Register */
} NUC_SRAMCTL_TypeDef;
/*@}*/ /* end of group NUC501_SRAMCTL */


/*------------- Serial Peripheral Interface Master Mode (SPIM) ----------------------------*/
/** @addtogroup NUC501_SPIM NUC501 Serial Peripheral Interface Master Mode
  @{
*/
typedef struct
{
  __IO uint32_t CNTRL;                  /*!< Offset: 0x000 (R/W) Control and Status Register */
  __IO uint32_t DIVIDER;                /*!< Offset: 0x004 (R/W) Clock Divider Register */
  __IO uint32_t SSR;                    /*!< Offset: 0x008 (R/W) Slave Select Register */
       uint32_t RESERVED0[1];
  __I  uint32_t RX[4];                  /*!< Offset: 0x010 (R/ ) Data Receive Register */
  __O  uint32_t TX[4];                  /*!< Offset: 0x020 ( /W) Data Transmit Register */
  __IO uint32_t AHB_ADDR;               /*!< Offset: 0x030 (R/W) AHB memory address */
  __IO uint32_t CODE_LEN;               /*!< Offset: 0x034 (R/W) Boot code length */
       uint32_t RESERVED1[2];
  __IO uint32_t SPIM_ADDR;              /*!< Offset: 0x040 (R/W) SPI Flash Start Address */
} NUC_SPIM_TypeDef;
/*@}*/ /* end of group NUC501_SPIM */


/*------------- Audio Processing Unit (APU) ------------------------------------------*/
/** @addtogroup NUC501_APU NUC501 Audio Processing Unit 
  @{
*/
typedef struct {
  __IO uint32_t APUCON;                 /*!< Offset: 0x000 (R/W) APU Control Register */
  __IO uint32_t PARCON;                 /*!< Offset: 0x004 (R/W) Parameter Control Register */
  __IO uint32_t PDCON;                  /*!< Offset: 0x008 (R/W) Power Down Control Register */
  __IO uint32_t APUINT;                 /*!< Offset: 0x00C (R/W) APU Interrupt Register */
  __IO uint32_t RAMBSAD;                /*!< Offset: 0x010 (R/W) RAM Base Address Register */
  __IO uint32_t THAD1;                  /*!< Offset: 0x014 (R/W) Threshold 1 Address Register */
  __IO uint32_t THAD2;                  /*!< Offset: 0x018 (R/W) Threshold 2 Address Register */
  __I  uint32_t CURAD;                  /*!< Offset: 0x01C (R/ ) Current Access RAM Address Register */
} NUC_APU_TypeDef;
/*@}*/ /* end of group NUC501_APU */


/*------------- USB Device Control (USB) ------------------------------------------*/
/** @addtogroup NUC501_USB NUC501 USB Device Control Block 
  @{
*/
typedef struct {

  __IO uint32_t BUFSEG;                 /*!< Offset: +0x00 (R/W) Buffer Segmentation of endpoint */
  __IO uint32_t MXPLD;                  /*!< Offset: +0x04 (R/W) Maximal payload of endpoint */
  __IO uint32_t CFG;                    /*!< Offset: +0x08 (R/W) Configuration of endpoint */
  __IO uint32_t CFGP;                   /*!< Offset: +0x0C (R/W) In ready clear flag of endpoint */
} NUC_USB_EP_TypeDef;

typedef struct {
  __IO uint32_t IEF;                    /*!< Offset: 0x000 (R/W) Interrupt Enable Flag */
  __IO uint32_t EFV;                    /*!< Offset: 0x004 (R/W) Interrupt Event Flag */
  __IO uint32_t FADDR;                  /*!< Offset: 0x008 (R/W) Function Address */
  __IO uint32_t STS;                    /*!< Offset: 0x00C (R/ ) System state */
  __IO uint32_t ATTR;                   /*!< Offset: 0x010 (R/W) Bus state & attribution */
  __I  uint32_t FLODET;                 /*!< Offset: 0x014 (R/ ) Floating detect */
  __IO uint32_t BUFSEG;                 /*!< Offset: 0x018 (R/W) Buffer Segmentation */
       uint32_t RESERVED0[1];
  NUC_USB_EP_TypeDef EP[6];             /*!< Offset: 0x020       EndPoint register block */
       uint32_t RESERVED1[4];
  __IO uint32_t USBSE0;                 /*!< Offset: 0x090 (R/W) Set D+ and D- bus to idle state */
} NUC_USB_TypeDef;
/*@}*/ /* end of group NUC501_USB */


/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/
/** @addtogroup NUC501_ADC NUC501 Analog-to-Digital Converter 
  @{
*/
typedef struct
{
  __IO uint32_t CON;                    /*!< Offset: 0x000 (R/W) ADC control register */
       uint32_t RESERVED0[2];
  __I  uint32_t XDATA;                  /*!< Offset: 0x00C (R/ ) ADC XDATA register */
       uint32_t RESERVED1[1];
  __IO uint32_t LV_CON;                 /*!< Offset: 0x014 (R/W) Low Voltage Detector Control register */
  __IO uint32_t LV_STS;                 /*!< Offset: 0x018 (R/W) Low Voltage Detector Status register */
  __IO uint32_t AUDIO_CON;              /*!< Offset: 0x01C (R/W) Audio control register */
  __IO uint32_t AUDIO_BUF[4];           /*!< Offset: 0x020 (R/W) Audio data buffer register */
} NUC_ADC_TypeDef;
/*@}*/ /* end of group NUC501_ADC */


/*------------- Advanced Interrupt Controller (AIC) ----------------------------*/
/** @addtogroup NUC501_AIC NUC501 Advanced Interrupt Controller 
  @{
*/
typedef struct
{
  __IO uint32_t SCR[8];                 /*!< Offset: 0x000 (R/W) Source Control Register */
       uint32_t RESERVED0[56];
  __I  uint32_t IRSR;                   /*!< Offset: 0x100 (R/ ) Interrupt Raw Status Register */
  __I  uint32_t IASR;                   /*!< Offset: 0x104 (R/ ) Interrupt Active Status Register */
  __I  uint32_t ISR;                    /*!< Offset: 0x108 (R/ ) Interrupt Status Register */
  __I  uint32_t IPER;                   /*!< Offset: 0x10C (R/ ) Interrupt Priority Encoding Register */
  __I  uint32_t ISNR;                   /*!< Offset: 0x110 (R/ ) Interrupt Source Number Register */
  __I  uint32_t IMR;                    /*!< Offset: 0x114 (R/ ) Interrupt Mask Register */
  __I  uint32_t OISR;                   /*!< Offset: 0x118 (R/ ) Output Interrupt Status Register */
       uint32_t RESERVED1[1];
  __O  uint32_t MECR;                   /*!< Offset: 0x120 ( /W) Mask Enable Command Register */
  __O  uint32_t MDCR;                   /*!< Offset: 0x124 ( /W) Mask Disable Command Register */
  __O  uint32_t SSCR;                   /*!< Offset: 0x128 ( /W) Source Set Command Register */
  __O  uint32_t SCCR;                   /*!< Offset: 0x12C ( /W) Source Clear Command Register */
  __O  uint32_t EOSCR;                  /*!< Offset: 0x130 ( /W) End of Service Command Register */
  __IO uint32_t TEST;                   /*!< Offset: 0x134 (R/W) ICE/Debug mode Register */
} NUC_AIC_TypeDef;


#define NUC_INT_WDT        1            /*!< IRQ Channel  1: Watch Dog Timer Interrupt */
#define NUC_INT_GPIO0      3            /*!< IRQ Channel  3: GPIO Interrupt0 */
#define NUC_INT_GPIO1      4            /*!< IRQ Channel  4: GPIO Interrupt1 */
#define NUC_INT_GPIO2      5            /*!< IRQ Channel  5: GPIO Interrupt2 */
#define NUC_INT_GPIO3      6            /*!< IRQ Channel  6: GPIO Interrupt3 */
#define NUC_INT_APU        7            /*!< IRQ Channel  7: Audio Processing Unit Interrupt */
#define NUC_INT_ADC       10            /*!< IRQ Channel 10: AD Converter Interrupt */
#define NUC_INT_RTC       11            /*!< IRQ Channel 11: RTC Interrupt */
#define NUC_INT_UART0     12            /*!< IRQ Channel 12: UART-0 Interrupt */
#define NUC_INT_UART1     13            /*!< IRQ Channel 13: UART-1 Interrupt */
#define NUC_INT_TMR1      14            /*!< IRQ Channel 14: Timer-1 Interrupt */
#define NUC_INT_TMR0      15            /*!< IRQ Channel 15: Timer-0 Interrupt */
#define NUC_INT_USB       19            /*!< IRQ Channel 19: USB Device Interrupt */
#define NUC_INT_PWM0      22            /*!< IRQ Channel 22: PWM Interrupt0 */
#define NUC_INT_PWM1      23            /*!< IRQ Channel 23: PWM Interrupt1 */
#define NUC_INT_PWM2      24            /*!< IRQ Channel 24: PWM Interrupt2 */
#define NUC_INT_PWM3      25            /*!< IRQ Channel 25: PWM Interrupt3 */
#define NUC_INT_I2C       26            /*!< IRQ Channel 26: I2C Interface Interrupt */
#define NUC_INT_SPIMS     27            /*!< IRQ Channel 27: SPI (Master/Slave) Serial Interface Interrupt */
#define NUC_INT_PWR       29            /*!< IRQ Channel 29: System Wake-Up Interrupt */
#define NUC_INT_SPIM      30            /*!< IRQ Channel 30: SPIM0/1 Interrupt*/

/*@}*/ /* end of group NUC501_AIC */


/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** @addtogroup NUC501_GPIO NUC501 General Purpose Input/Output 
  @{
*/
typedef struct
{
  __IO uint32_t OMD;                    /*!< Offset: +0x00 (R/W) GPIO Port Bit Output Mode Enable */
  __IO uint32_t PUEN;                   /*!< Offset: +0x04 (R/W) GPIO Port Bit Pull-up Resistor Enable */
  __IO uint32_t DOUT;                   /*!< Offset: +0x08 (R/W) GPIO Port Data Output Value */
  __I  uint32_t PIN;                    /*!< Offset: +0x0C (R/ ) GPIO Port Pin Value */
} NUC_GPIO_PORT_TypeDef;     

typedef struct
{
  NUC_GPIO_PORT_TypeDef PORT[3];        /*!< Offset: 0x000       GPIO Port # Register */
       uint32_t RESERVED0[16];
  __IO uint32_t DBNCECON;               /*!< Offset: 0x070 (R/W) External Interrupt De-bounce Control */
       uint32_t RESERVED1[3];
  __IO uint32_t IRQSRC[3];              /*!< Offset: 0x080 (R/W) GPIO Port # IRQ Source Grouping */
       uint32_t RESERVED2[1];
  __IO uint32_t IRQEN[3];               /*!< Offset: 0x090 (R/W) GPIO Port # Interrupt Enable */
       uint32_t RESERVED3[1];
  __IO uint32_t IRQLHSEL;               /*!< Offset: 0x0A0 (R/W) Interrupt Latch Trigger Selection Register*/ 
  __I  uint32_t IRQLH[3];               /*!< Offset: 0x0A4 (R/ ) GPIO Port # Interrupt Latch Value */
       uint32_t RESERVED4[1];
  __IO uint32_t IRQTGSRC0;              /*!< Offset: 0x0B4 (R/C) IRQ0~3 Interrupt Trigger Source Indicator from GPIO Port A and GPIO Port B */
  __IO uint32_t IRQTGSRC1;              /*!< Offset: 0x0B8 (R/C) IRQ0~3 Interrupt Trigger Source Indicator from GPIO Port C */
} NUC_GPIO_TypeDef;     
/*@}*/ /* end of group NUC501_GPIO */


/*------------- I2C Serial Interface (I2C) ----------------------------*/
/** @addtogroup NUC501_I2C NUC501 I2C Serial Interface 
  @{
*/
typedef struct
{
  __IO uint32_t CSR;                    /*!< Offset: 0x000 (R/W) Control and Status Register */
  __IO uint32_t DIVIDER;                /*!< Offset: 0x004 (R/W) Clock Pre-scale Register */
  __IO uint32_t CMDR;                   /*!< Offset: 0x008 (R/W) Command Register */
  __IO uint32_t SWR;                    /*!< Offset: 0x00C (R/W) Software Mode Control Register */
  __I  uint32_t RX;                     /*!< Offset: 0x010 (R/ ) Data Receive Register */
  __IO uint32_t TX;                     /*!< Offset: 0x014 (R/W) Data Transmit Register */
} NUC_I2C_TypeDef;
/*@}*/ /* end of group NUC501_I2C */


/*------------- PWM Generator and Capture Timer (PWM) ----------------------------*/
/** @addtogroup NUC501_PWM NUC501 PWM Generator and Capture Timer 
  @{
*/
typedef struct
{
  __IO uint32_t CNR;                    /*!< Offset: +0x00 (R/W) PWM Counter Register */
  __IO uint32_t CMR;                    /*!< Offset: +0x04 (R/W) PWM Comparator Register */
  __I  uint32_t PDR;                    /*!< Offset: +0x08 (R/ ) PWM Data Register */
} NUC_PWM_CNT_TypeDef;

typedef struct
{
  __IO uint32_t CRLR;                   /*!< Offset: +0x00 (R/W) Capture Rising Latch Register */
  __IO uint32_t CFLR;                   /*!< Offset: +0x04 (R/W) Capture Falling Latch Register */
} NUC_PWM_CHN_TypeDef;

typedef struct
{
  __IO uint32_t PPR;                    /*!< Offset: 0x000 (R/W) PWM Prescaler Register */
  __IO uint32_t CSR;                    /*!< Offset: 0x004 (R/W) PWM Clock Select Register */
  __IO uint32_t PCR;                    /*!< Offset: 0x008 (R/W) PWM Control Register */
  NUC_PWM_CNT_TypeDef CNT[4];           /*!< Offset: 0x00C       PWM Counter Register Block */
       uint32_t RESERVED0[1];
  __IO uint32_t PIER;                   /*!< Offset: 0x040 (R/W) PWM Interrupt Enable Register */
  __IO uint32_t PIIR;                   /*!< Offset: 0x044 (R/C) PWM Interrupt Indication Register */
       uint32_t RESERVED1[2];
  __IO uint32_t CCR0;                   /*!< Offset: 0x050 (R/W) Capture Control Register 0 */
  __IO uint32_t CCR1;                   /*!< Offset: 0x054 (R/W) Capture Control Register 1 */
  NUC_PWM_CHN_TypeDef CHN[4];           /*!< Offset: 0x058       PWM Channel Register Block */
  __IO uint32_t CAPENR;                 /*!< Offset: 0x078 (R/W) Capture Input Enable Register */
  __IO uint32_t POE;                    /*!< Offset: 0x07C (R/W) PWM Output Enable */
} NUC_PWM_TypeDef;
/*@}*/ /* end of group NUC501_PWM */


/*------------- Real Time Clock (RTC) ----------------------------*/
/** @addtogroup NUC501_RTC NUC501 Real Time Clock 
  @{
*/
typedef struct
{
  __IO uint32_t INIR;                   /*!< Offset: 0x000 (R/W) RTC Initiation Register */
  __IO uint32_t AER;                    /*!< Offset: 0x004 (R/W) RTC Access Enable Register */
  __IO uint32_t FCR;                    /*!< Offset: 0x008 (R/W) RTC Frequency Compensation Register */
  __IO uint32_t TLR;                    /*!< Offset: 0x00C (R/W) Time Loading Register */
  __IO uint32_t CLR;                    /*!< Offset: 0x010 (R/W) Calendar Loading Register */
  __IO uint32_t TSSR;                   /*!< Offset: 0x014 (R/W) Time Scale Selection Register */
  __IO uint32_t DWR;                    /*!< Offset: 0x018 (R/W) Day of the Week Register */
  __IO uint32_t TAR;                    /*!< Offset: 0x01C (R/W) Time Alarm Register */
  __IO uint32_t CAR;                    /*!< Offset: 0x020 (R/W) Calendar Alarm Register */
  __IO uint32_t LIR;                    /*!< Offset: 0x024 (R/W) Leap year Indicator Register */
  __IO uint32_t RIER;                   /*!< Offset: 0x028 (R/W) RTC Interrupt Enable Register */
  __IO uint32_t RIIR;                   /*!< Offset: 0x02C (R/C) RTC Interrupt Indicator Register */
  __IO uint32_t TTR;                    /*!< Offset: 0x030 (R/W) RTC Time Tick Register */
} NUC_RTC_TypeDef;
/*@}*/ /* end of group NUC501_RTC */


/*------------- Serial Peripheral Interface (SPI) ----------------------------*/
/** @addtogroup NUC501_SPI NUC501 Serial Peripheral Interface 
  @{
*/
typedef struct
{
  __IO uint32_t CNTRL;                  /*!< Offset: 0x000 (R/W) Control and Status Register */
  __IO uint32_t DIVIDER;                /*!< Offset: 0x004 (R/W) Clock Divider Register */
  __IO uint32_t SSR;                    /*!< Offset: 0x008 (R/W) Slave Select Register */
       uint32_t RESERVED0[1];
  union {
  __I  uint32_t RX[4];                  /*!< Offset: 0x010 (R/ ) Data Receive Register */
  __O  uint32_t TX[4];                  /*!< Offset: 0x010 ( /W) Data Transmit Register */
  };
} NUC_SPI_TypeDef;
/*@}*/ /* end of group NUC501_SPI */


/*------------- Timer (TMR) ----------------------------*/
/** @addtogroup NUC501_TMR NUC501 Timer 
  @{
*/
typedef struct
{
  __IO uint32_t TCSR0;                  /*!< Offset: 0x000 (R/W) Timer Control and Status Register 0 */
  __IO uint32_t TCSR1;                  /*!< Offset: 0x004 (R/W) Timer Control and Status Register 1 */
  __IO uint32_t TICR0;                  /*!< Offset: 0x008 (R/W) Timer Initial Control Register 0 */
  __IO uint32_t TICR1;                  /*!< Offset: 0x00C (R/W) Timer Initial Control Register 1 */
  __I  uint32_t TDR0;                   /*!< Offset: 0x010 (R/ ) Timer Data Register 0 */
  __I  uint32_t TDR1;                   /*!< Offset: 0x014 (R/ ) Timer Data Register 1 */
  __IO uint32_t TISR;                   /*!< Offset: 0x018 (R/W) Timer Interrupt Status Register */
} NUC_TMR_TypeDef;
/*@}*/ /* end of group NUC501_TMR */


/*------------- Watchdog Timer (WDT) ----------------------------*/
/** @addtogroup NUC501_TIM NUC501 Watchdog Timer 
  @{
*/
typedef struct
{
  __IO uint32_t CR;                     /*!< Offset: 0x000 (R/W) Watchdog Timer Control Register */
} NUC_WDT_TypeDef;
/*@}*/ /* end of group NUC501_WDT */


/*------------- UART Interface (UART) ----------------------------*/
/** @addtogroup NUC501_UART NUC501 UART Interface 
  @{
*/
typedef struct
{
  union {
  __I  uint32_t RBR;                    /*!< Offset: 0x000 (R/ ) Receive Buffer Register (DLAB = 0) */
  __O  uint32_t THR;                    /*!< Offset: 0x000 ( /W) Transmit Holding Register (DLAB = 0) */
  __IO uint32_t DLL;                    /*!< Offset: 0x000 (R/W) Divisor Latch Register (LS) (DLAB = 1) */
  };
  union {
  __IO uint32_t IER;                    /*!< Offset: 0x004 (R/W) Interrupt Enable Register (DLAB = 0) */
  __IO uint32_t DLM;                    /*!< Offset: 0x004 (R/W) Divisor Latch Register (MS) (DLAB = 1) */
  };
  union {
  __I  uint32_t IIR;                    /*!< Offset: 0x008 (R/ ) Interrupt Identification Register */
  __O  uint32_t FCR;                    /*!< Offset: 0x008 ( /W) FIFO Control Register */
  };
  __IO uint32_t LCR;                    /*!< Offset: 0x00C (R/W) Line Control Register */
  __IO uint32_t MCR;                    /*!< Offset: 0x010 (R/W) Modem Control Register */
  __I  uint32_t LSR;                    /*!< Offset: 0x014 (R/ ) Line Status Register */
  __IO uint32_t MSR;                    /*!< Offset: 0x018 (R/W) Modem Status Register */
  __IO uint32_t TOR;                    /*!< Offset: 0x01C (R/W) Time Out Register */
} NUC_UART_TypeDef;
/*@}*/ /* end of group NUC501_UART */


#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Base addresses                                                             */
#define NUC_FLASH_BASE          ((     uint32_t)0x40000000)
#define NUC_SRAM_BASE           ((     uint32_t)0x00000000)
#define NUC_AHB_BASE            ((     uint32_t)0xB1000000)
#define NUC_APB_BASE            ((     uint32_t)0xB8000000)

/* AHB peripherals                                                            */	
#define NUC_GCR_BASE            (NUC_AHB_BASE       + 0x00000)
#define NUC_CLK_BASE            (NUC_AHB_BASE       + 0x00200)
#define NUC_SRAMCTL_BASE        (NUC_AHB_BASE       + 0x04000)
#define NUC_SPIM_BASE           (NUC_AHB_BASE       + 0x07000)
#define NUC_APU_BASE            (NUC_AHB_BASE       + 0x08000)
#define NUC_USB_BASE            (NUC_AHB_BASE       + 0x09000)

/* APB1 peripherals                                                            */	
#define NUC_ADC_BASE            (NUC_APB_BASE       + 0x01000)
#define NUC_AIC_BASE            (NUC_APB_BASE       + 0x02000)
#define NUC_GPIO_BASE           (NUC_APB_BASE       + 0x03000)
#define NUC_I2C_BASE            (NUC_APB_BASE       + 0x04000)
#define NUC_PWM_BASE            (NUC_APB_BASE       + 0x07000)
#define NUC_RTC_BASE            (NUC_APB_BASE       + 0x08000)
#define NUC_SPI_BASE            (NUC_APB_BASE       + 0x0A000)
#define NUC_TMR_BASE            (NUC_APB_BASE       + 0x0B000)  
#define NUC_WDT_BASE            (NUC_APB_BASE       + 0x0B01C)  
#define NUC_UART0_BASE          (NUC_APB_BASE       + 0x0C000)
#define NUC_UART1_BASE          (NUC_APB_BASE       + 0x0C100)


/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define NUC_GCR               ((NUC_GCR_TypeDef    *) NUC_GCR_BASE    )
#define NUC_CLK               ((NUC_CLK_TypeDef    *) NUC_CLK_BASE    )
#define NUC_SRAMCTL           ((NUC_SRAMCTL_TypeDef*) NUC_SRAMCTL_BASE)
#define NUC_SPIM              ((NUC_SPIM_TypeDef   *) NUC_SPIM_BASE   )
#define NUC_APU               ((NUC_APU_TypeDef    *) NUC_APU_BASE    )
#define NUC_USB               ((NUC_USB_TypeDef    *) NUC_USB_BASE    )

#define NUC_ADC       	      ((NUC_ADC_TypeDef    *) NUC_ADC_BASE    )
#define NUC_AIC               ((NUC_AIC_TypeDef    *) NUC_AIC_BASE    )
#define NUC_GPIO              ((NUC_GPIO_TypeDef   *) NUC_GPIO_BASE   ) 
#define NUC_I2C               ((NUC_I2C_TypeDef    *) NUC_I2C_BASE    )
#define NUC_PWM               ((NUC_PWM_TypeDef    *) NUC_PWM_BASE    )
#define NUC_RTC               ((NUC_RTC_TypeDef    *) NUC_RTC_BASE    )
#define NUC_SPI               ((NUC_SPI_TypeDef    *) NUC_SPI_BASE    )
#define NUC_TMR               ((NUC_TMR_TypeDef    *) NUC_TMR_BASE    )
#define NUC_WDT               ((NUC_WDT_TypeDef    *) NUC_WDT_BASE    )
#define NUC_UART0             ((NUC_UART_TypeDef   *) NUC_UART0_BASE  )
#define NUC_UART1             ((NUC_UART_TypeDef   *) NUC_UART1_BASE  )


#ifdef __cplusplus
}
#endif

#endif  /* __NUC501_H__ */
