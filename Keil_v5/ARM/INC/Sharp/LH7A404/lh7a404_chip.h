/***********************************************************************
 * $Id:: lh7a404_chip.h 14 2007-08-28 16:08:18Z kevinw                 $
 *
 * Project: LH7A404 chip definitions
 *
 * Description:
 *     This file contains chip specific information such as the
 *     physical addresses defines for the LH7A404 registers, clock
 *     frequencies, and other chip information.
 *
 * Notes:
 *    BOOTMODE by default is set to 0, which identifies that the
 *    system mapping is with asynchronous chip select 0 at address
 *    0x00000000 and synchronous chip select 3 is at address 0xF0000000.
 *    Setting BOOTMODE to any other value besides 0 (by overring the
 *    define value in the compiler) will swap the address of
 *    asynchronous chip select 0 and synchronous chip select 3. This
 *    is useful for systems that boot from Syncronous Flash devices.
 *
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 **********************************************************************/
#ifndef LH7A404_CHIP_H
#define LH7A404_CHIP_H

#include "lpc_types.h"

/***********************************************************************
 * AHB BASES
 **********************************************************************/

#define AHB_BASE        (0x80002000)        /* AHB registers base */
#define SMC_REGS_BASE   (AHB_BASE)          /* SMC registers base */
#define SDRAM_REGS_BASE (AHB_BASE + 0x400)  /* SDRAM registers base */
#define DMA_REGS_BASE   (AHB_BASE + 0x800)  /* DMA register base */
#define LCD_BASE        (AHB_BASE + 0x1000) /* LCD registers base */
#define VIC1_BASE       (AHB_BASE + 0x6000) /* VIC1 registers base */
#define USBH_BASE       (AHB_BASE + 0x7000) /* USB host regs base */
#define VIC2_BASE       (AHB_BASE + 0x8000) /* VIC1 registers base */
#define IRAM_BASE       (0xB0000000)        /* Internal SRAM address */

/***********************************************************************
 * APB BASES
 **********************************************************************/

#define APB_BASE        (0x80000000)        /* APB registers base */
#define AAC_BASE        (APB_BASE)          /* AAC registers base */
#define SDMMC_BASE      (APB_BASE + 0x0100) /* SDMMC registers base */
#define USBC_BASE       (APB_BASE + 0x0200) /* USB client regs base */
#define SCI_BASE        (APB_BASE + 0x0300) /* SCI registers base */
#define CLKSC_BASE      (APB_BASE + 0x0400) /* CSC registers base */
#define UART1_BASE      (APB_BASE + 0x0600) /* UART1 registers base */
#define SIR_BASE        (APB_BASE + 0x0600) /* SIR registers base */
#define UART2_BASE      (APB_BASE + 0x0700) /* UART2 registers base */
#define UART3_BASE      (APB_BASE + 0x0800) /* UART3 registers base */
#define DCDC_BASE       (APB_BASE + 0x0900) /* DCDC registers base */
#define ACI_BASE        (APB_BASE + 0x0A00) /* ACI registers base */
#define SSP_BASE        (APB_BASE + 0x0B00) /* SSP registers base */
#define TIMER1_BASE     (APB_BASE + 0x0C00) /* Timer 1 registers base */
#define TIMER2_BASE     (APB_BASE + 0x0C20) /* Timer 2 registers base */
#define TIMER3_BASE     (APB_BASE + 0x0C80) /* Timer 3 registers base */
#define BZCONT_BASE     (APB_BASE + 0x0C40) /* BZCONT registers base */
#define RTC_BASE        (APB_BASE + 0x0D00) /* RTC registers base */
#define GPIO_BASE       (APB_BASE + 0x0E00) /* GPIO registers base */
#define KBD_BASE        (APB_BASE + 0x0E00) /* KBD registers base */
#define BMISWI_BASE     (APB_BASE + 0x0F00) /* BMISWI registers base */
#define BMISBI_BASE     (APB_BASE + 0x0F40) /* BMISBI registers base */
#define LCDICP_BASE     (APB_BASE + 0x1000) /* LCDICP registers base */
#define PWM_BASE        (APB_BASE + 0x1100) /* PWM registers base */
#define KMI_BASE        (APB_BASE + 0x1200) /* KMI registers base */
#define ADC_BASE        (APB_BASE + 0x1300) /* ADC registers base */
#define WDTIMER_BASE    (APB_BASE + 0x1400) /* WDT registers base */

/***********************************************************************
 * SMC Memory Bank Address Space Bases
 **********************************************************************/

#ifndef BOOTMODE
#define SMC_CS0_BASE    (0x00000000)        /* SMC CS0 base address */
#else
#if BOOTMODE == 0
#define SMC_CS0_BASE    (0x00000000)        /* SMC CS0 base address */
#else
#define SMC_CS0_BASE    (0xF0000000)        /* SMC CS0 base address */
#endif
#endif
#define SMC_CS1_BASE    (0x10000000)        /* SMC CS1 base address */
#define SMC_CS2_BASE    (0x20000000)        /* SMC CS2 base address */
#define SMC_CS3_BASE    (0x30000000)        /* SMC CS3 base address */
#define SMC_CS4_BASE    (0x40000000)        /* SMC CS4 base address */
#define SMC_CS5_BASE    (0x50000000)        /* SMC CS5 base address */
#define SMC_CS6_BASE    (0x60000000)        /* SMC CS6 base address */
#define SMC_CS7_BASE    (0x70000000)        /* SMC CS7 base address */

/***********************************************************************
 * Internal memory Base
 **********************************************************************/

#define IRAM_BASE             (0xB0000000)  /* Internal RAM address */

/***********************************************************************
 * SDRAMC Memory Bank Address Space Bases
 **********************************************************************/

#define SDRAM_SDCE0_BASE      (0xC0000000)  /* SDC CS0 base address */
#define SDRAM_SDCE1_BASE      (0xD0000000)  /* SDC CS1 base address */
#define SDRAM_SDCE2_BASE      (0xE0000000)  /* SDC CS2 base address */
#ifndef BOOTMODE
#define SDRAM_SDCE3_BASE      (0xF0000000)  /* SDC CS3 base address */
#else
#if BOOTMODE == 0
#define SDRAM_SDCE3_BASE      (0xF0000000)  /* SDC CS3 base address */
#else
#define SDRAM_SDCE3_BASE      (0x00000000)  /* SDC CS3 base address */
#endif
#endif

/***********************************************************************
 * Clock and crystal information
 **********************************************************************/

#define CLOCK_32KHZ           32768         /* 32KHz clock frequency */
#define CLOCK_MAINOSC         14745600      /* Main clock frequency */

#endif /* LH7A404_CHIP_H */
