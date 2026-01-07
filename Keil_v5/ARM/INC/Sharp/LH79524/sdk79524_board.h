/***********************************************************************
 * $Id:: sdk79524_board.h 27 2007-08-31 19:35:06Z kevinw               $
 *
 *   Project: EVB79524 Board
 *
 *   Description:
 *      This file contains the following information for the
 *      EVB79524 Hardware Platform:
 *
 *         Includes the LH79524 chip header file
 *         Declares for board-specific typedefs
 *         Defines for board-specific manifest constants
 *         Defines for board-specific manifest macros
 *         Defines for board-specific conditional constants
 *
 *   References:
 *      (1) LH79524 SoC User's Guide
 *      (2) EVB79524 board Schematics
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
#ifndef SDK79524_BOARD_H
#define SDK79524_BOARD_H

/***********************************************************************
 * Library header files (#include)
 **********************************************************************/

/***********************************************************************
 * User header files (#include)
 **********************************************************************/
#include "lpc_types.h"
#include "lh79524_chip.h"

/***********************************************************************
 * Constant definitions (#define)
 **********************************************************************/

/***********************************************************************
 * Clock Frequencies
 **********************************************************************/
#define SDK79524_XTAL_IN         (11289600)

/* Define standard console device.*/
#define STDOUT_DEVICE            (UART0)

/***********************************************************************
 * Memory base addresses
 **********************************************************************/
#define FLASH_PHYS_BASE     EMC_STATIC_CS1_BASE
#define FLASH_PHYS_SIZE     (0x00400000)        /* 4MB */

#define SDRAM_PHYS_BASE     EMC_SDRAMC_DCS0_BASE
#define SDRAM_PHYS_SIZE     (0x02000000)        /* 32MB */

#define SDRAM1_PHYS_BASE    EMC_SDRAMC_DCS1_BASE
#define SDRAM1_PHYS_SIZE    (0x02000000)        /* 32MB */

#define CPLD_BASE           (EMC_STATIC_CS3_BASE)

/***********************************************************************
 * CPLD Register structures and Constants
 **********************************************************************/

#define CPLD_CONTROL	*((unsigned short *)(CPLD_BASE + 0x100000))
#define CPLD_MASK		*((unsigned short *)(CPLD_BASE + 0x400000))
#define CPLD_EEP_SPI	*((unsigned short *)(CPLD_BASE + 0x500000))
#define CPLD_INT		*((unsigned short *)(CPLD_BASE + 0x600000))
#define CPLD_FLASH		*((unsigned short *)(CPLD_BASE + 0x800000))
#define CPLD_LED		*((unsigned short *)(CPLD_BASE + 0xB00000))
#define CPLD_GPIO_DATA	*((unsigned short *)(CPLD_BASE + 0xC00000))
#define CPLD_GPIO_DIR	*((unsigned short *)(CPLD_BASE + 0xD00000))


/***********************************************************************
 * CPLD CONTROL Register bit definition
 **********************************************************************/
#define SDK79524_CPLD_CONTROL_VIDEO_NCS     	_BIT(3)
#define SDK79524_CPLD_CONTROL_USB1P     		_BIT(1)
#define SDK79524_CPLD_CONTROL_WLPE     			_BIT(0)

/***********************************************************************
 * CPLD MASK Register bit definition
 **********************************************************************/
#define SDK79524_CPLD_MASK_IRQD     		_BIT(3)
#define SDK79524_CPLD_MASK_IRQC     		_BIT(2)
#define SDK79524_CPLD_MASK_OVRCNT     		_BIT(1)
#define SDK79524_CPLD_MASK_WRLEN     		_BIT(0)

/***********************************************************************
 * CPLD EEPROM SPI Register bit definition
 **********************************************************************/
#define SDK79524_CPLD_EEP_SPI_COD_NCS  			_BIT(5)
#define SDK79524_CPLD_EEP_SPID_EE_CS2   		_BIT(4)
#define SDK79524_CPLD_EEP_SPI_EE_CS1     		_BIT(3)
#define SDK79524_CPLD_EEP_SPI_CLK	     		_BIT(2)
#define SDK79524_CPLD_EEP_SPI_TX	     		_BIT(1)
#define SDK79524_CPLD_EEP_SPI_RX    	 		_BIT(0)

/***********************************************************************
 * CPLD INT Register bit definition
 **********************************************************************/
#define SDK79524_CPLD_INT_SWINT  				_BIT(7)
#define SDK79524_CPLD_INT_SWRST  				_BIT(6)
#define SDK79524_CPLD_INT_STANDBY  				_BIT(5)
#define SDK79524_CPLD_INT_SUSPEND  				_BIT(4)
#define SDK79524_CPLD_INT_IRQD  				_BIT(3)
#define SDK79524_CPLD_INT_IRQC  				_BIT(2)
#define SDK79524_CPLD_INT_OVRCNT  				_BIT(1)
#define SDK79524_CPLD_INT_WRLAN  				_BIT(0)

/***********************************************************************
 * CPLD FLASH Register bit definition
 **********************************************************************/
#define SDK79524_CPLD_FLASH_FPOP  				_BIT(3)
#define SDK79524_CPLD_FLASH_RDNBSY  			_BIT(2)
#define SDK79524_CPLD_FLASH_STS1  				_BIT(1)
#define SDK79524_CPLD_FLASH_FL_VPEN  			_BIT(0)

/***********************************************************************
 * CPLD LED Register bit definition
 **********************************************************************/
#define SDK79524_CPLD_LED_LED2  				_BIT(2)
#define SDK79524_CPLD_LED_LED1  				_BIT(1)

/***********************************************************************
 * CPLD GPIO DATA Register bit definition
 **********************************************************************/
#define SDK79524_CPLD_GPIO_DATA_GPIO2			_BIT(2)
#define SDK79524_CPLD_GPIO_DATA_GPIO1			_BIT(1)

/***********************************************************************
 * CPLD GPIO DIR Register bit definition
 **********************************************************************/
#define SDK79524_CPLD_GPIO_DIR_GPIO2			_BIT(2)
#define SDK79524_CPLD_GPIO_DIR_GPIO1			_BIT(1)

/***********************************************************************
 * Put User Entries below this line
 **********************************************************************/

#endif /* SDK79524_BOARD_H */
