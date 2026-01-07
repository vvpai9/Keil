/***********************************************************************
 * $Id:: lh79524_chip.h 27 2007-08-31 19:35:06Z kevinw                 $
 *
 * Project: LH79524 chip definitions
 *
 * Description:
 *      This file contains the Map of the LH79524 System on Chip.
 *      This file depends on the include files which describe the
 *      specific modules on the LH79524.
 *
 *      This file is intended to be included by a target or board
 *      specific include file.  Use the generic names in this file to
 *      define target specific constants in the target specific include
 *      file(s), or in the source files.
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
#ifndef LH79524_CHIP_H
#define LH79524_CHIP_H

#include "lpc_types.h"

/**********************************************************************
 * AHB BASES
 *********************************************************************/
#define AHB_BASE            (0xFFFF0000)
#define EMC_REGS_BASE       (AHB_BASE + 0x1000)
#define LCD_BASE            (AHB_BASE + 0x4000)
#define USB_BASE            (AHB_BASE + 0x5000)
#define VIC_BASE            (AHB_BASE + 0xF000)

/**********************************************************************
 * APB BASES
 *********************************************************************/
#define APB_BASE            (0xFFFC0000)
#define UART0_BASE          (APB_BASE + 0x00000)
#define UART1_BASE          (APB_BASE + 0x01000)
#define UART2_BASE          (APB_BASE + 0x02000)
#define ADC_BASE            (APB_BASE + 0x03000)
#define TIMER0_BASE         (APB_BASE + 0x04000)
#define TIMER1_BASE         (APB_BASE + 0x04030)
#define TIMER2_BASE         (APB_BASE + 0x04050)
#define I2C_BASE            (APB_BASE + 0x05000)
#define SSP_BASE            (APB_BASE + 0x06000)
#define ETHERNET_BASE       (APB_BASE + 0x07000)
#define I2S_BASE			(APB_BASE + 0x08000)
#define GPIOMN_BASE         (APB_BASE + 0x19000)
#define GPIOKL_BASE         (APB_BASE + 0x1A000) 
#define GPIOIJ_BASE         (APB_BASE + 0x1B000) 
#define GPIOGH_BASE         (APB_BASE + 0x1C000) 
#define GPIOEF_BASE         (APB_BASE + 0x1D000) 
#define GPIOCD_BASE         (APB_BASE + 0x1E000) 
#define GPIOAB_BASE         (APB_BASE + 0x1F000) 
#define RTC_BASE            (APB_BASE + 0x20000)
#define DMAC_BASE           (APB_BASE + 0x21000)
#define RCPC_BASE           (APB_BASE + 0x22000)
#define WDTIMER_BASE        (APB_BASE + 0x23000)
#define ALI_BASE            (APB_BASE + 0x24000)
#define IOCON_BASE          (APB_BASE + 0x25000)
#define BOOTCTLR_BASE       (APB_BASE + 0x26000)


#define INTERNAL_SRAM_BASE  (0x60000000)
#define INTERNAL_SRAM_SIZE  (0x00004000)
#define INTERNAL_SRAM_END   (INTERNAL_SRAM_BASE + INTERNAL_SRAM_SIZE)

/**********************************************************************
 * EMC Static Memory Bank Address Space Bases
 *********************************************************************/
#define EMC_STATIC_MEM_BASE        (0x40000000)
#define EMC_STATIC_CS0_BASE        (EMC_STATIC_MEM_BASE + 0x00000000)
#define EMC_STATIC_CS1_BASE        (EMC_STATIC_MEM_BASE + 0x04000000)
#define EMC_STATIC_CS2_BASE        (EMC_STATIC_MEM_BASE + 0x08000000)
#define EMC_STATIC_CS3_BASE        (EMC_STATIC_MEM_BASE + 0x0C000000)
/**********************************************************************
 * EMC SDRAM Memory Bank Address Space Bases
 *********************************************************************/
#define EMC_SDRAMC_DCS0_BASE        (0x20000000)
#define EMC_SDRAMC_DCS1_BASE        (0x30000000)


#endif /* LH79524_CHIP_H */
