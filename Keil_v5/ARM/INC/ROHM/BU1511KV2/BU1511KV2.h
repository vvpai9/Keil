/**************************************************************************//**
 * @file     BU1511KV2.h
 * @brief    Peripheral Access Layer Header File for 
 *           ROHM U1511KV2 Device Series
 * @version  V1.00
 * @date     25. March 2010
 *
 * @note
 * Copyright (C) 2010 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __BU1511KV2_H__
#define __BU1511KV2_H__

#include <stdint.h>                     /* Include standard types */

#ifdef __cplusplus
 extern "C" {
#endif 

/**
 * IO definitions
 *
 * define access restrictions to peripheral registers
 */

#ifdef __cplusplus
  #define     __I     volatile          /*!< defines 'read only' permissions */
#else
  #define     __I     volatile const    /*!< defines 'read only' permissions */
#endif
#define     __O     volatile            /*!< defines 'write only' permissions */
#define     __IO    volatile            /*!< defines 'read / write' permissions */


/******************************************************************************/
/*                Device Specific Peripheral Registers structures             */
/******************************************************************************/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/
/** @addtogroup BU1511KV2_UART BU1511KV2 Universal Asynchronous Receiver/Transmitter 
  @{
*/
typedef struct
{
  union {
  __I  uint32_t  RBR;                   /*!< Offset: 0x000 Receiver Buffer  Register (R/ ) */
  __O  uint32_t  THR;                   /*!< Offset: 0x000 Transmit Holding Register ( /W) */
  __IO uint32_t  DLL;                   /*!< Offset: 0x000 Divisor Latch (Low) (R/W) */
  };
  union {
  __IO uint32_t  DLH;                   /*!< Offset: 0x004 Divisor Latch (High) (R/W) */
  __IO uint32_t  IER;                   /*!< Offset: 0x004 Interrupt Enable Register (R/W) */
  };
  union {
  __I  uint32_t  IIR;                   /*!< Offset: 0x008 Interrupt Identification Register (R/ ) */
  __O  uint32_t  FCR;                   /*!< Offset: 0x008 FIFO Control Register ( /W) */
  };
  __IO uint32_t  LCR;                   /*!< Offset: 0x00C Line Control Register (R/W) */
  __IO uint32_t  MCR;                   /*!< Offset: 0x010 Modem control Register (R/W) */
  __I  uint32_t  LSR;                   /*!< Offset: 0x014 Line Status Register (R/ ) */
  __I  uint32_t  MSR;                   /*!< Offset: 0x018 Modem status Register (R/ ) */
  __IO uint32_t  SCR;                   /*!< Offset: 0x01C Scratchpad Register (R/W) */
       uint32_t  RESERVED0[20];
  __IO uint32_t  FAR;                   /*!< Offset: 0x070 FIFO Access Register (R/W) */
  __I  uint32_t  TFR;                   /*!< Offset: 0x074 Transmit FIFO Read Register (R/ ) */
  __O  uint32_t  RFW;                   /*!< Offset: 0x078 Receive FIFO Write Register ( /W) */
  __I  uint32_t  USR;                   /*!< Offset: 0x07C UART Status Register (R/ ) */
  __I  uint32_t  TFL;                   /*!< Offset: 0x080 Transmit FIFO Level Register (R/ ) */
  __I  uint32_t  RFL;                   /*!< Offset: 0x084 Receive  FIFO Level Register (R/ ) */
       uint32_t  RESERVED1[7];
  __IO uint32_t  HTX;                   /*!< Offset: 0x0A4 Halt TX Register (R/W) */
} ROHM_UART_TypeDef;
/*@}*/ /* end of group BU1511KV2_UART */


/*------------- Timer (TMR) --------------------------------------------------*/
/** @addtogroup BU1511KV2_TMR BU1511KV2 32-bit Counter/Timer 
  @{
*/
typedef struct
{
  __IO uint32_t LoadCount;              /*!< Offset: 0x000 Initial Counter Value Register (R/W) */
  __I  uint32_t CurrentValue;           /*!< Offset: 0x004 Current Counter Value Register (R/ ) */
  __IO uint32_t ControlReg;             /*!< Offset: 0x008 Control Register (R/W) */
  __I  uint32_t EOI;                    /*!< Offset: 0x00C Interrupt Clear  Register (R/ ) */
  __IO uint32_t STAT;                   /*!< Offset: 0x010 Interrupt Status Register (R/ ) */
} ROHM_TMR_TypeDef;
/*@}*/ /* end of group BU1511KV2_TMR */


/*------------- Watchdog Timer (WDT) -----------------------------------------*/
/** @addtogroup BU1511KV2_WDT BU1511KV2 32-bit WatchDog Timer 
  @{
*/
typedef struct
{
  __IO uint32_t CR;                     /*!< Offset: 0x000 Control Register (R/W) */
  __IO uint32_t TORR;                   /*!< Offset: 0x004 Timeout Range Register (R/W) */
  __I  uint32_t CCVR;                   /*!< Offset: 0x008 Current Counter Value Register (R/ ) */
  __O  uint32_t CRR;                    /*!< Offset: 0x00C Counter Restart Register ( /W) */
  __I  uint32_t STAT;                   /*!< Offset: 0x010 Interrupt Status Register (R/ ) */
  __I  uint32_t EOI;                    /*!< Offset: 0x014 Interrupt Clear  Register (R/ ) */
} ROHM_WDT_TypeDef;
/*@}*/ /* end of group BU1511KV2_WDT */


/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** @addtogroup BU1511KV2_GPIO BU1511KV2 General Purpose Input/Output 
  @{
*/
typedef struct
{
  __IO uint32_t swporta_dr;             /*!< Offset: 0x000 Port Output Data Register (R/W) */
  __IO uint32_t swporta_ddr;            /*!< Offset: 0x004 Port Data Direction Register (R/W) */
       uint32_t RESERVED0[10];
  __IO uint32_t inten;                  /*!< Offset: 0x030 Interrupt Enable Register  (R/W) */
  __IO uint32_t intmask;                /*!< Offset: 0x034 Interrupt Mask Register (R/W) */
  __IO uint32_t inttype_level;          /*!< Offset: 0x038 Interrupt Input Type Register (R/W) */
  __IO uint32_t int_polarity;           /*!< Offset: 0x03C Interrupt Polarity Register (R/W) */
  __I  uint32_t intstatus;              /*!< Offset: 0x040 Interrupt Status Register (after  mask filter) (R/ ) */
  __I  uint32_t rawintstatus;           /*!< Offset: 0x044 Interrupt Status Register (before mask filter) (R/ ) */
       uint32_t RESERVED1[1];
  __O  uint32_t porta_eoi;              /*!< Offset: 0x04C Interrupt Status Clear Register ( /W) */
  __I  uint32_t ext_porta;              /*!< Offset: 0x050 Input Data Register (R/ ) */
} ROHM_GPIO_TypeDef;
/*@}*/ /* end of group BU1511KV2_GPIO */


/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/
/** @addtogroup BU1511KV2_ADC BU1511KV2 Analog-to-Digital Converter 
  @{
*/
typedef struct
{
       uint32_t RESERVED0[1];
  __IO uint32_t MOD;                    /*!< Offset: 0x004 Operation mode Register (R/W) */
  __IO uint32_t TRIGEN;                 /*!< Offset: 0x008 Sampling Trigger Enable Register (R/W) */
  __IO uint32_t SOFTTRIG[4];            /*!< Offset: 0x010 Sampling Trigger Channel 0..3 Register (R/W) */
       uint32_t RESERVED1[8];
  __I  uint32_t DATA[4];                /*!< Offset: 0x040 Sampling Channel 0..3 Data Register (R/ ) */
       uint32_t RESERVED2[9];
  __IO uint32_t INTMASK;                /*!< Offset: 0x074 Interrupt Mask   Register (R/W) */
  __I  uint32_t INTRSTATUS;             /*!< Offset: 0x078 Interrupt Status Register (before mask filter) (R/ ) */
  __I  uint32_t INTSTATUS;              /*!< Offset: 0x07C Interrupt Status Register (after  mask filter) (R/ ) */
  __I  uint32_t INTCLR;                 /*!< Offset: 0x080 Interrupt Status Clear Register (R/ ) */
} ROHM_ADC_TypeDef;
/*@}*/ /* end of group BU1511KV2_ADC */


/*------------- System Control (SYS) --------------------------------------*/
/** @addtogroup BU1511KV2_SYSCON BU1511KV2 System Control Block 
  @{
*/
typedef struct
{
  __IO uint32_t CLKCNT;                 /*!< Offset: 0x000 Clock Control Register (R/W) */
  __IO uint32_t PLLCNT;                 /*!< Offset: 0x004 PLL   Control Register (R/W) */
       uint32_t RESERVED0[2];
  __IO uint32_t CLKARM;                 /*!< Offset: 0x010 System Clock Register (R/W) */
  __IO uint32_t CLKADC;                 /*!< Offset: 0x014 ADC Clock Register (R/W) */
  __IO uint32_t CLKIMG;                 /*!< Offset: 0x018 IMG Clock Register (R/W) */
  __IO uint32_t CLKTVE;                 /*!< Offset: 0x01C TVE Clock Register (R/W) */
  __IO uint32_t CLKSDC;                 /*!< Offset: 0x020 SDC Clock Register (R/W) */
  __IO uint32_t CLKAUD;                 /*!< Offset: 0x024 AUD Clock Register (R/W) */
       uint32_t RESERVED1[2];
  __IO uint32_t RST;                    /*!< Offset: 0x030 Soft Reset Register (R/W) */
       uint32_t RESERVED2[3];
  __IO uint32_t WPB;                    /*!< Offset: 0x040 Active Level Register (R/W) */
} ROHM_SYS_TypeDef;
/*@}*/ /* end of group BU1511KV2_SYSCON */


/*------------- Interrupt Controller (INT) --------------------------------------*/
/** @addtogroup BU1511KV2_INT BU1511KV2 Interrupt Controller Block 
  @{
*/
typedef struct
{
  __IO uint32_t irq_inten_I;            /*!< Offset: 0x000 IRQ interrupt source enable (R/W) */
       uint32_t RESERVED0[1];
  __IO uint32_t irq_intmask_I;          /*!< Offset: 0x008 IRQ interrupt source mask (R/W) */
       uint32_t RESERVED1[3];
  __I  uint32_t irq_rawstatus_I;        /*!< Offset: 0x018 IRQ Interrupt Status Register (before mask filter) (R/ ) */
       uint32_t RESERVED2[1];
  __I  uint32_t irq_status_I;           /*!< Offset: 0x020 IRQ Interrupt Status Register (after  mask filter) (R/ ) */
       uint32_t RESERVED3[1];
  __I  uint32_t irq_maskstatus_I;       /*!< Offset: 0x028 IRQ Interrupt Mask Status Register (R/ ) */
       uint32_t RESERVED4[1];
  __I  uint32_t irq_finalstatus_I;      /*!< Offset: 0x030 IRQ Interrupt Final Status Register (R/ ) */
       uint32_t RESERVED5[35];
  __IO uint32_t fiq_inten_;             /*!< Offset: 0x0C0 FIQ interrupt source enable (R/W) */
  __IO uint32_t fiq_intmask;            /*!< Offset: 0x0C4 FIQ interrupt source mask (R/W) */
       uint32_t RESERVED6[1];
  __I  uint32_t fiq_rawstatus;          /*!< Offset: 0x0CC FIQ Interrupt Status Register (before mask filter) (R/ ) */
  __I  uint32_t fiq_status;             /*!< Offset: 0x0D0 FIQ Interrupt Status Register (after  mask filter) (R/ ) */
  __I  uint32_t fiq_finalstatus;        /*!< Offset: 0x0D4 FIQ Interrupt Final Status Register (R/ ) */
  __IO uint32_t irq_plevel;             /*!< Offset: 0x0D8 IRQ interrupt source enable (R/W) */
} ROHM_INTCTL_TypeDef;

/* Interrupt Number Definitions */
#define ROHM_INTCTL_TIM1_IRQn    (0)
#define ROHM_INTCTL_TIM2_IRQn    (1)
#define ROHM_INTCTL_TIMC_IRQn    (2)
#define ROHM_INTCTL_SPI_IRQn     (3)
#define ROHM_INTCTL_UART1_IRQn   (4)
#define ROHM_INTCTL_UART2_IRQn   (5)
#define ROHM_INTCTL_GPIO_IRQn    (6)
#define ROHM_INTCTL_ADC_IRQn     (7)
#define ROHM_INTCTL_AVM_IRQn     (8)

/*@}*/ /* end of group BU1511KV2_INT */


/*------------- Synchronous Serial Interface (SSI) -----------------------*/
/** @addtogroup BU1511KV2_SSI BU1511KV2 Synchronous Serial Interface 
  @{
*/
typedef struct
{
  __IO uint32_t CTRLR0;                 /*!< Offset: 0x000 Control Register 0 (R/W) */
  __IO uint32_t CTRLR1;                 /*!< Offset: 0x004 Control Register 1 (R/W) */
  __IO uint32_t SSIENR;                 /*!< Offset: 0x008 SSI enable/Disable Register (R/W) */
  __IO uint32_t MWCR;                   /*!< Offset: 0x00C Micrwire Control Register (R/W) */
  __IO uint32_t SER;                    /*!< Offset: 0x010 Slave Select Register (R/W) */
  __IO uint32_t BAUDR;                  /*!< Offset: 0x014 SSI Clock Devider Register (R/W) */
  __IO uint32_t TXFTLR;                 /*!< Offset: 0x018 Transmit FIFO Theshold Register (R/W) */
  __IO uint32_t RXFTLR;                 /*!< Offset: 0x01C Receive FIFO Theshold Register (R/W) */
  __I  uint32_t TXFLR;                  /*!< Offset: 0x020 Transmit FIFO Level Register (R/ ) */
  __I  uint32_t RXFLR;                  /*!< Offset: 0x024 Receive FIFO Level Register (R/ ) */
  __I  uint32_t SR;                     /*!< Offset: 0x028 Status Register (R/ ) */
  __IO uint32_t IMR;                    /*!< Offset: 0x02C Interrupt Mask Register (R/W) */
  __I  uint32_t ISR;                    /*!< Offset: 0x030 Interrupt Status Register (R/ ) */
  __I  uint32_t RISR;                   /*!< Offset: 0x034 Interrupt Raw Status Register (R/ ) */
  __I  uint32_t TXOICR;                 /*!< Offset: 0x038 Clear Transmit FIFO Overflow Interrupt Register (R/ ) */
  __I  uint32_t RXOICR;                 /*!< Offset: 0x03C Clear Receive FIFO Overflow Interrupt Register (R/ ) */
  __I  uint32_t RXUICR;                 /*!< Offset: 0x040 Clear Receive FIFO Underrun Interrupt Register (R/ ) */
  __I  uint32_t MSTICR;                 /*!< Offset: 0x044 Clear Multi-Master Contention Interrupt Register (R/ ) */
  __I  uint32_t ICR;                    /*!< Offset: 0x048 Interrupt Clear Register (R/ ) */
       uint32_t RESERVED0[3];
  __I  uint32_t IDR;                    /*!< Offset: 0x058 Identification Code Register (R/ ) */
  __I  uint32_t SSI_COMP_VERSION;       /*!< Offset: 0x05C Synopsis Component Register (R/ ) */
  __IO uint32_t DR;                     /*!< Offset: 0x060 Data Register (R/W) */
} LPC_SSP_TypeDef;
/*@}*/ /* end of group BU1511KV2_SSI */


/*------------- PWM Function of GPIO (PWM) -----------------------------------------*/
/** @addtogroup BU1511KV2_PWM BU1511KV2 Pulse Width Modulation 
  @{
*/
typedef struct
{
  __IO uint32_t BSCKDV;                 /*!< Offset: 0x00C Base clock Register (R/W) */
  __IO uint32_t LCNT;                   /*!< Offset: 0x010 Low Level pulse count Register (R/W) */
  __IO uint32_t HCNT;                   /*!< Offset: 0x014 High Level pulse count Register (R/W) */
  __IO uint32_t PULSE_NUM;              /*!< Offset: 0x018 Output pulse cycle Register (R/W) */
} ROHM_PWMCHN_TypeDef;

typedef struct
{
  __IO uint32_t EN;                     /*!< Offset: 0x000 Function enable Register (R/W) */
  __IO uint32_t MOD;                    /*!< Offset: 0x004 Mode stetting Register (R/W) */
  __IO uint32_t CNT;                    /*!< Offset: 0x008 Control Register (R/W) */
  ROHM_PWMCHN_TypeDef CHN[4];           /*!< Offset: 0x00C Channel Register (R/W) */
} ROHM_PWM_TypeDef;
/*@}*/ /* end of group BU1511KV2_PWM */


/*------------- External Memory Controller (EMC) --------------------------------------*/
/** @addtogroup BU1511KV2_EMC BU1511KV2 External Memory Controller Block 
  @{
*/
typedef struct
{
       uint32_t RESERVED0[5];
  __IO uint32_t SCSLR0_LOW;             /*!< Offset: 0x014 Chip Select (CS0|CS2) Addressing Register (R/W) */
  __IO uint32_t SCSLR1_LOW;             /*!< Offset: 0x018 Chip Select (CS1|CS3) Addressing Register (R/W) */
       uint32_t RESERVED1[14];
  __IO uint32_t SMSKR0;                 /*!< Offset: 0x054 Chip Select (CS0|CS2) Mask Register (R/W) */
  __IO uint32_t SMSKR1;                 /*!< Offset: 0x058 Chip Select (CS1|CS3) Mask Register (R/W) */
       uint32_t RESERVED2[6];
  __IO uint32_t CSALIAS0_LOW;           /*!< Offset: 0x074 Chip Select (CS0|CS2) Alias Register (R/W) */
  __IO uint32_t CSALIAS1_LOW;           /*!< Offset: 0x078 Chip Select (CS1|CS3) Alias Register (R/W) */
       uint32_t RESERVED3[6];
  __IO uint32_t SMTMGR_SET0;            /*!< Offset: 0x094 Chip Select (CS0) Timing Register (R/W) */
  __IO uint32_t SMTMGR_SET1;            /*!< Offset: 0x098 Chip Select (CS1) Timing Register (R/W) */
  __IO uint32_t SMTMGR_SET2;            /*!< Offset: 0x09C Chip Select (CS2) Timing Register (R/W) */
  __IO uint32_t FLASH_TRPDR;            /*!< Offset: 0x0A0 Flash Waiting Time Register (R/W) */
  __IO uint32_t SMCTLR;                 /*!< Offset: 0x0A4 Bus Access Control Register (R/W) */
} ROHM_EMC_TypeDef;
/*@}*/ /* end of group BU1511KV2_EMC */


/*-------------  Audio/Video and Multimedia Interface Mega-Block (AVM) ----------------*/
/** @addtogroup BU1511KV2_AVM Audio/Video and Multimedia Interface Mega-Block 
  @{
*/
typedef struct
{
       uint16_t RESERVED0[4];
  __IO uint16_t IDX;                    /*!< Offset: 0x004 Access to Index Register (R/W) */
       uint16_t RESERVED1[1];
  __IO uint16_t DAT;                    /*!< Offset: 0x00C Access to Other Register (R/W) */
} ROHM_AVM_TypeDef;

/* AVM Register Definitions */
#define ROHM_AVM_CLKCNT              (0x00D0)    /*!< Clock Control Register (R/W) */ 
#define ROHM_AVM_CLKDIV1             (0x00D1)    /*!< Clock Division Register1 (R/W) */ 
#define ROHM_AVM_CLKDIV3             (0x00D3)    /*!< Clock Division Register3 (R/W) */ 
#define ROHM_AVM_CLKDIV4             (0x00D4)    /*!< Clock Division Register4 (R/W) */ 
#define ROHM_AVM_HWMODE              (0x00D8)    /*!< Hardware operation mode setting Register (R/W) */ 
#define ROHM_AVM_INTCNT              (0x00D9)    /*!< Interrupt control Register (R/W) */ 
#define ROHM_AVM_INTST1              (0x00DA)    /*!< Interrupt status Register 1 (R/W) */ 
#define ROHM_AVM_INTST2              (0x00DC)    /*!< Interrupt status Register 2 (R/W) */ 
#define ROHM_AVM_INTMSK1             (0x00DB)    /*!< Interrupt mask Register 1 (R/W) */ 
#define ROHM_AVM_INTMSK2             (0x00DD)    /*!< Interrupt mask Register 2 (R/W) */

/* AVM Register Definitions for Camera Module Interface */
#define ROHM_AVM_CAMIF               (0x0010)    /*!< Camera signal logic setting register     (R/W) */
#define ROHM_AVM_CAMTIM              (0x0017)    /*!< Camera signal frame start pixel position register (R/W) */
#define ROHM_AVM_CAMFLT              (0x0011)    /*!< Camera image filter processing selection register (R/W) */
#define ROHM_AVM_FLTTHD              (0x0012)    /*!< Camera image 2 gradation processing threshold value register (R/W) */
#define ROHM_AVM_FLTSEP              (0x0013)    /*!< Camera image sepia processing coefficient register (R/W) */
#define ROHM_AVM_SEPRNG              (0x0014)    /*!< Camera image sepia processing coefficient register (R/W) */
#define ROHM_AVM_FLTCOEF             (0x0015)    /*!< Camera image edge enhancement1 processing coefficient register (R/W) */
#define ROHM_AVM_FLTEDG2             (0x0016)    /*!< Camera image edge enhancement2 processing coefficient register (R/W) */
#define ROHM_AVM_CXSIZE              (0x0018)    /*!< X direction camera image size register (R/W) */
#define ROHM_AVM_CYSIZE              (0x0019)    /*!< Y direction camera image size register (R/W) */
#define ROHM_AVM_CAMRSX              (0x001B)    /*!< X direction cropping start position register (R/W) */
#define ROHM_AVM_CAMRSY              (0x001C)    /*!< Y direction cropping start position register (R/W) */
#define ROHM_AVM_CAMREX              (0x001D)    /*!< X direction cropping end position register (R/W) */
#define ROHM_AVM_CAMREY              (0x001E)    /*!< Y direction cropping end position register (R/W) */
#define ROHM_AVM_CAMYD               (0x001F)    /*!< Brightness factor enlargement setting register (R/W) */
#define ROHM_AVM_CXSRK               (0x0021)    /*!< Reduction ratio in X direction setting register (R/W) */
#define ROHM_AVM_CYSRK               (0x0022)    /*!< Reduction ratio in Y direction setting register (R/W) */
#define ROHM_AVM_SRKTYPE             (0x0023)    /*!< Reduction algorithm setting register (R/W) */
#define ROHM_AVM_SRKTYPE             (0x0023)    /*!< Reduction algorithm setting register (R/W) */
 
/* AVM Register Definitions for Two-wire serial setting control(I2C) */
#define ROHM_AVM_SERICNT             (0x0060)    /*!< Serial interface control register (R/W) */
#define ROHM_AVM_SERIDEVADR          (0x0061)    /*!< Serial transfer device address setting register (R/W) */
#define ROHM_AVM_SERI2NDADR          (0x0062)    /*!< Serial transfer register address setting register (R/W) */
#define ROHM_AVM_SERIBYTECNT         (0x0063)    /*!< Serial interface byte control register (R/W) */
#define ROHM_AVM_SERIBYTECNT         (0x0063)    /*!< Serial interface byte control register (R/W) */
 
/* AVM Register Definitions for Memory interface */
#define ROHM_AVM_IMGHSIZE            (0x0043)    /*!< Frame memory horizontal size setting register (R/W) */
#define ROHM_AVM_IMGVSIZE            (0x0044)    /*!< Frame memory vertical size setting register (R/W) */
#define ROHM_AVM_MEMCNT              (0x0030)    /*!< Memory control register (R/W) */
#define ROHM_AVM_MEMCSTAX            (0x0031)    /*!< Camera image storage start X position setting register (R/W) */
#define ROHM_AVM_MEMCSTAY            (0x0032)    /*!< Camera image storage start Y position setting register (R/W) */
#define ROHM_AVM_MEMACS_YUV          (0x0033)    /*!< Memory access register YUV (R/W) */
#define ROHM_AVM_MEMACS_RGB          (0x0034)    /*!< Memory access register RGB (R/W) */
#define ROHM_AVM_MEMACS_ABS          (0x0036)    /*!< Memory access register ABS (R/W) */
#define ROHM_AVM_MEM_ADR_STX         (0x0037)    /*!< Memory rectangular access start X position setting register (R/W) */
#define ROHM_AVM_MEM_ADR_STY         (0x0038)    /*!< Memory rectangular access start Y position setting register (R/W) */
#define ROHM_AVM_MEM_ADR_EDX         (0x0039)    /*!< Memory rectangular access end X position setting register (R/W) */
#define ROHM_AVM_MEM_ADR_EDY         (0x003A)    /*!< Memory rectangular access end Y position setting register (R/W) */
#define ROHM_AVM_MEM_ADR_ABS1        (0x003B)   /*!< Memory absolute address setting 1 register (R/W) */
#define ROHM_AVM_MEM_ADR_ABS2        (0x003C)   /*!< Memory absolute address setting 2 register (R/W) */
#define ROHM_AVM_MEMTRANS            (0x003D)   /*!< Memory data transparent color setting register (R/W) */
#define ROHM_AVM_MEMTRMSK            (0x003E)   /*!< Memory data transparent color mask register (R/W) */
 
/* AVM Register Definitions for TV encoder interface and TV encoder */
#define ROHM_AVM_TE_CNT              (0x00B0)   /*!< TV encoder interface control register (R/W) */
#define ROHM_AVM_TE_CNT2             (0x00BD)   /*!< TV encoder interface control register 2 (R/W) */
#define ROHM_AVM_TE_STX              (0x00B1)   /*!< Frame Memory Transfer X Start Position register (R/W) */
#define ROHM_AVM_TE_STY              (0x00B2)   /*!< Frame Memory Transfer Y Start Position register (R/W) */
#define ROHM_AVM_TE_EDX              (0x00B3)   /*!< Frame Memory Transfer X End Position register (R/W) */
#define ROHM_AVM_TE_EDY              (0x00B4)   /*!< Frame Memory Transfer Y End Position register (R/W) */
#define ROHM_AVM_TE_EXPH             (0x00B5)   /*!< H Direction Expansion Configuration register (R/W) */
#define ROHM_AVM_TE_EXPV             (0x00B6)   /*!< V Direction Expansion Configuration register (R/W) */
#define ROHM_AVM_TE_OUTSTH           (0x00B7)   /*!< TV Encoder Output H Direction Start Position Configuration register (R/W) */
#define ROHM_AVM_TE_OUTSTV           (0x00B8)   /*!< TV Encoder Output V Direction Start Position Configuration register (R/W) */
#define ROHM_AVM_TE_OUTSTV           (0x00B8)   /*!< TV Encoder Output V Direction Start Position Configuration register (R/W) */
#define ROHM_AVM_PARAMSET            (0x1011)   /*!< Parameter update register (R/W) */
#define ROHM_AVM_MODE                (0x1012)   /*!< Mode register (R/W) */
#define ROHM_AVM_YUVIFSET            (0x1013)   /*!< Input interface format specification register (R/W) */
#define ROHM_AVM_XSIZE_L             (0x1014)   /*!< X direction pixel size setting register Low (R/W) */
#define ROHM_AVM_XSIZE_H             (0x1015)   /*!< X direction pixel size setting register High (R/W) */
#define ROHM_AVM_YSIZE_L             (0x1016)   /*!< Y direction pixel size setting register Low (R/W) */
#define ROHM_AVM_YSIZE_H             (0x1017)   /*!< Y direction pixel size setting register High (R/W) */
#define ROHM_AVM_PWD                 (0x1041)   /*!< TV encoder Reset register ( R/W) */
#define ROHM_AVM_DISP                (0x1043)   /*!< TV encoder display mode register ( R/W) */
#define ROHM_AVM_VIDEO               (0x1045)   /*!< TV encoder video format register ( R/W) */
#define ROHM_AVM_CVBS                (0x1046)   /*!< TV encoder video mode register ( R/W) */
#define ROHM_AVM_BGCOL               (0x1047)   /*!< TV encoder BGCOLOR register ( R/W) */
#define ROHM_AVM_COLBAR              (0x1048)   /*!< TV encoder color bar test register ( R/W) */
#define ROHM_AVM_SETUP               (0x1055)   /*!< TV encoder setup register ( R/W) */
#define ROHM_AVM_GM_A0               (0x10D0)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_A1               (0x10D1)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_A2               (0x10D2)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_X0               (0x10D3)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_X1               (0x10D4)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_X2               (0x10D5)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_X3               (0x10D6)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_Y0               (0x10D7)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_Y1               (0x10D8)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_Y2               (0x10D9)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_GM_Y3               (0x10DA)   /*!< TV Encordagamma correction register ( R/W) */
#define ROHM_AVM_OFS_H               (0x10E0)   /*!< Effective start input pixel offset setting register High ( R/W) */
#define ROHM_AVM_OFS_L               (0x10E1)   /*!< Effective start input pixel offset setting register Low ( R/W) */
#define ROHM_AVM_WID_VD_H            (0x10E2)   /*!< TV encoder effective data width setting register ( R/W) */
#define ROHM_AVM_WID_VD_L            (0x10E3)   /*!< TV encoder effective data width setting register Low (R/W) */
#define ROHM_AVM_HT_VD               (0x10E4)   /*!< TV encoder effective line width setting register (R/W) */
#define ROHM_AVM_H_POS               (0x10E5)   /*!< TV encoder horizontal display position offset register (R/W) */
#define ROHM_AVM_V_POS               (0x10E6)   /*!< TV encoder vertical display position offset register (R/W) */
#define ROHM_AVM_V_OFS               (0x10E7)   /*!< TV encoder effective start input line off set setting register (R/W) */
#define ROHM_AVM_SRST                (0x10FF)   /*!< Initialization register (R/W) */
 
/* AVM Register Definitions for JPEG Codec */
#define ROHM_AVM_JPG_CNT             (0x0080)   /*!< JPEG control register (R/W) */
#define ROHM_AVM_JPG_ST1             (0x0083)   /*!< JPEG status 1 register (R/W) */
#define ROHM_AVM_JPG_ST2             (0x0084)   /*!< JPEG status 2 register (R/W) */
#define ROHM_AVM_JPG_ST3             (0x0085)   /*!< JPEG status 3 register (R/W) */
#define ROHM_AVM_JE_CNT              (0x0090)   /*!< JPEG compression control register (R/W) */
#define ROHM_AVM_JE_CSIZE1           (0x0091)   /*!< JPEG code size register 1 (R/W) */
#define ROHM_AVM_JE_CSIZE2           (0x0092)   /*!< JPEG code size register 2 (R/W) */
#define ROHM_AVM_JE_CSIZE1_PRE       (0x0093)   /*!< JPEG code size pre register 1 (R/W) */
#define ROHM_AVM_JE_CSIZE2_PRE       (0x0094)   /*!< JPEG code size pre register 2 (R/W) */
#define ROHM_AVM_JD_PICTYPE          (0x00A0)   /*!< JPEG code YUV format setting register (R/W) */
#define ROHM_AVM_JD_INTERVAL         (0x00A1)   /*!< JPEG restart interval setting register (R/W) */
#define ROHM_AVM_JD_XSIZE            (0x00A2)   /*!< JPEG code X direction size setting register (R/W) */
#define ROHM_AVM_JD_YSIZE            (0x00A3)   /*!< JPEG code Y direction size setting register (R/W) */
#define ROHM_AVM_JD_HUF_Y_DC1        (0x00A4)   /*!< Brightness DC component Huffman table 1 setting register (R/W) */
#define ROHM_AVM_JD_HUF_Y_AC1        (0x00A6)   /*!< Brightness AC component Huffman table 1 setting register (R/W) */
#define ROHM_AVM_JD_HUF_C_DC1        (0x00A8)   /*!< Color difference DC component Huffman table 1 setting register (R/W) */
#define ROHM_AVM_JD_HUF_C_AC1        (0x00AA)   /*!< Color difference AC component Huffman table 1 setting register (R/W) */
#define ROHM_AVM_RING_CNT            (0x0086)   /*!< RING_INT occurrence control register (R/W) */
#define ROHM_AVM_RING_COUNT          (0x008F)   /*!< Number of RING_INT occurrence count register (R/W) */
#define ROHM_AVM_RING_RD             (0x003F)   /*!< Ring buffer read data register (R/W) */
 
/* AVM Register Definitions for ADPCM/PCM codec and I2S interface */
#define ROHM_AVM_COMMON_SET_UP1      (0x0100)   /*!< Common setup register 1 (R/W) */
#define ROHM_AVM_COMMON_SET_UP2      (0x0101)   /*!< Common setup register 2 (R/W) */
#define ROHM_AVM_ADPCM_CH_VOL        (0x0103)   /*!< ADPCM cannel volume register (R/W) */
#define ROHM_AVM_ADPCM_M_LR_VOL      (0x0104)   /*!< ADPCM master channel volume register (R/W) */
#define ROHM_AVM_ADPCM_S_LR_VOL      (0x0105)   /*!< ADPCM slave channel volume register (R/W) */
#define ROHM_AVM_ADPCM_INT_STATUS    (0x0106)   /*!< ADPCM interrupt status register (R/ ) */
#define ROHM_AVM_ADPCM_M_FIFO_STATUS (0x0108)   /*!< ADPCM master FIFO status register (R/W) */
#define ROHM_AVM_ADPCM_S_FIFO_STATUS (0x0109)   /*!< ADPCM slave FIFO status register (R/W) */
#define ROHM_AVM_ADPCM_FIFO_SETUP    (0x010C)   /*!< ADPCM FIFO setup register ( /W) */
#define ROHM_AVM_ADPCM_EXT_VOL       (0x010D)   /*!< ADPCM record volume register ( /W) */
#define ROHM_AVM_ADPCM_M_SETUP       (0x010E)   /*!< ADPCM master setup register ( /W) */
#define ROHM_AVM_ADPCM_S_SETUP       (0x010F)   /*!< ADPCM slave setup register ( /W) */
#define ROHM_AVM_ADPCM_CH_CONTROL    (0x0110)   /*!< ADPCM channel control register ( /W) */
#define ROHM_AVM_PCMIF_FORMAT        (0x0111)   /*!< PCMIF format register ( /W) */
#define ROHM_AVM_ADPCM_FORMAT        (0x0115)   /*!< Digital I/F input register ( /W) */
#define ROHM_AVM_INTERVAL_SETTING    (0x0116)   /*!< Interval setting register ( /W) */
#define ROHM_AVM_ADPCM_REC_MODE      (0x0119)   /*!< ADPCM recode mode register ( /W) */
#define ROHM_AVM_ADPCM_M_FIFO_WND    (0x011B)   /*!< ADPCM master FIFO access register ( /W) */
#define ROHM_AVM_ADPCM_ENC_FIFO_WND  (0x011B)   /*!< ADPCM master FIFO access register (R/ ) */
#define ROHM_AVM_ADPCM_S_FIFO_WND    (0x011C)   /*!< ADPCM slave FIFO access register ( /W) */
#define ROHM_AVM_SMP_TIMING_SETUP    (0x0120)   /*!< Sampling timing setup register ( /W) */
#define ROHM_AVM_SEQUENCE_CONTROL1   (0x0140)   /*!< Sequence control register (R/W) */
 
/* AVM Register Definitions for SD Card interface / controller */
#define ROHM_AVM_INTST2              (0x00DC)   /*!< Interrupt status register 2 (R/W) */
#define ROHM_AVM_INTMSK2             (0x00DD)   /*!< Interrupt mask register 2 (R/W) */
#define ROHM_AVM_SD_CARD_CNT         (0x00BA)   /*!< SD card control register (R/W) */
#define ROHM_AVM_SD_CLK_CNT          (0x00BC)   /*!< SD Clock control register (R/W) */
#define ROHM_AVM_SD_CMD              (0x0200)   /*!< Command register (R/W) */
#define ROHM_AVM_SD_PORTSEL          (0x0201)   /*!< SD Port selection register (R/W) */
#define ROHM_AVM_SD_ARG0             (0x0202)   /*!< SD Command Argument register 0 (R/W) */
#define ROHM_AVM_SD_ARG1             (0x0203)   /*!< SD Command Argument register 1 (R/W) */
#define ROHM_AVM_SD_STOP             (0x0204)   /*!< Data STOP register (R/W) */
#define ROHM_AVM_SD_SECCNT           (0x0205)   /*!< Transfer Sector Count Register (R/W) */
#define ROHM_AVM_SD_RSP0             (0x0206)   /*!< SD Memory Card Information Register 0 (R/W) */
#define ROHM_AVM_SD_RSP1             (0x0207)   /*!< SD Memory Card Information Register 1 (R/W) */
#define ROHM_AVM_SD_RSP2             (0x0208)   /*!< SD Memory Card Information Register 2 (R/W) */
#define ROHM_AVM_SD_RSP3             (0x0209)   /*!< SD Memory Card Information Register 3 (R/W) */
#define ROHM_AVM_SD_RSP4             (0x020A)   /*!< SD Memory Card Information Register 4 (R/W) */
#define ROHM_AVM_SD_RSP5             (0x020B)   /*!< SD Memory Card Information Register 5 (R/W) */
#define ROHM_AVM_SD_RSP6             (0x020C)   /*!< SD Memory Card Information Register 6 (R/W) */
#define ROHM_AVM_SD_RSP7             (0x020D)   /*!< SD Memory Card Information Register 7 (R/W) */
#define ROHM_AVM_SD_INFO1            (0x020E)   /*!< SD Memory Card Buffer Control & Error Register (R/W) */
#define ROHM_AVM_SD_INFO2            (0x020F)   /*!< SD Memory Card Information Mask Register (R/W) */
#define ROHM_AVM_SD_INFO1_MASK       (0x0210)   /*!< SD Memory Card Information Mask Register (R/W) */
#define ROHM_AVM_SD_INFO2_MASK       (0x0211)   /*!< SD Memory Card Buffer & Error Mask Register (R/W) */
#define ROHM_AVM_SD_CLK_CTRL         (0x0212)   /*!< SD Clock Control Register (R/W) */
#define ROHM_AVM_SD_SIZE             (0x0213)   /*!< Transfer data length register (R/W) */
#define ROHM_AVM_SD_OPTION           (0x0214)   /*!< SD Memory Card Access Control Option Register (R/W) */
#define ROHM_AVM_SD_ERR_STS1         (0x0216)   /*!< SD error interrupt (CMD, CRC, END) status register (R/W) */
#define ROHM_AVM_SD_ERR_STS2         (0x0217)   /*!< SD error interrupt (Time out) status register (R/W) */
#define ROHM_AVM_SD_BUF0             (0x0218)   /*!< Buffer Read/Write Port Register (R/W) */
#define ROHM_AVM_SOFT_RST            (0x0270)   /*!< Soft Reset Register (R/W) */
#define ROHM_AVM_VERSION             (0x0271)   /*!< Soft Reset Register (R/ ) */
 
/* AVM Register Definitions for AVM Setup */
#define ROHM_AVM_SETUPCNT            (0x00F8)   /*!< Setup-sequence control register (R/W) */
#define ROHM_AVM_SETUPSET            (0x00FE)   /*!< Setup sequence setting register (R/W) */
#define ROHM_AVM_PRODUCT_ID          (0x0000)   /*!< Product ID register (R/ ) */
#define ROHM_AVM_REV_NO              (0x0001)   /*!< Revision No. register (R/ ) */

/*@}*/ /* end of group BU1511KV2_AVM */


#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Base addresses                                                             */
#define ROHM_FLASH_BASE        (0x00000000UL)
#define ROHM_RAM_BASE          (0x10000000UL)
#define ROHM_AVM_BASE          (0x30000000UL)
#define ROHM_EMC1_BASE         (0x90000000UL)
#define ROHM_EMC2_BASE         (0xA0000000UL)
#define ROHM_APB_BASE          (0xC0000000UL)

/* APB peripherals                                                            */
#define ROHM_UART1_BASE        (ROHM_APB_BASE + 0x00000)
#define ROHM_UART2_BASE        (ROHM_APB_BASE + 0x01000)
#define ROHM_TMR1_BASE         (ROHM_APB_BASE + 0x02000)
#define ROHM_TMR2_BASE         (ROHM_APB_BASE + 0x02014)
#define ROHM_TMRC_BASE         (ROHM_APB_BASE + 0x02028)
#define ROHM_WDT_BASE          (ROHM_APB_BASE + 0x03000)
#define ROHM_GPIO_BASE         (ROHM_APB_BASE + 0x04000)
#define ROHM_ADC_BASE          (ROHM_APB_BASE + 0x05000)
#define ROHM_SYS_BASE          (ROHM_APB_BASE + 0x06000)
#define ROHM_INTCTL_BASE       (ROHM_APB_BASE + 0x07000)
#define ROHM_SSI_BASE          (ROHM_APB_BASE + 0x08000)
#define ROHM_PWM_BASE          (ROHM_APB_BASE + 0x09000)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define ROHM_UART1             ((ROHM_UART_TypeDef   *) ROHM_UART1_BASE )
#define ROHM_UART2             ((ROHM_UART_TypeDef   *) ROHM_UART2_BASE )
#define ROHM_TMR1              ((ROHM_TMR_TypeDef    *) ROHM_TMR1_BASE  )
#define ROHM_TMR2              ((ROHM_TMR_TypeDef    *) ROHM_TMR2_BASE  )
#define ROHM_TMRC              ((ROHM_TMR_TypeDef    *) ROHM_TMRC_BASE  )
#define ROHM_WDT               ((ROHM_WDT_TypeDef    *) ROHM_WDT_BASE   )
#define ROHM_GPIO              ((ROHM_GPIO_TypeDef   *) ROHM_GPIO_BASE  )
#define ROHM_ADC               ((ROHM_ADC_TypeDef    *) ROHM_ADC_BASE   )
#define ROHM_SYS               ((ROHM_SYS_TypeDef    *) ROHM_SYS_BASE   )
#define ROHM_INTCTL            ((ROHM_INTCTL_TypeDef *) ROHM_INTCTL_BASE)
#define ROHM_SSI               ((ROHM_SSI_TypeDef    *) ROHM_SSI_BASE   )
#define ROHM_PWM               ((ROHM_PWM_TypeDef    *) ROHM_PWM_BASE   )

#define ROHM_EMC1              ((ROHM_EMC_TypeDef    *) ROHM_EMC1_BASE  )
#define ROHM_EMC2              ((ROHM_EMC_TypeDef    *) ROHM_EMC2_BASE  )

#define ROHM_AVM               ((ROHM_AVM_TypeDef    *) ROHM_AVM_BASE   )

#ifdef __cplusplus
}
#endif

#endif  /* __BU1511KV2_H__ */
