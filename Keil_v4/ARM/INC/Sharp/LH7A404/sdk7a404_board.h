/***********************************************************************
 * $Id:: sdk7a404_board.h 14 2007-08-28 16:08:18Z kevinw               $
 *
 * Project: LogicPD SDK7A404 board definitions
 *
 * Description:
 *     This file contains board specific information such as the
 *     chip select wait states, and other board specific information.
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

#ifndef SDK7A404_BOARD_H
#define SDK7A404_BOARD_H

#include "lpc_types.h"
#include "lh7a404_smc.h"
#include "lh7a404_sdramc.h"
#include "lh7a404_chip.h"

/***********************************************************************
 * Chip select configurations (per LogicPD)
 **********************************************************************/

/* Static Memory Controller chip select 0 load value for FLASH */
#define SMC_BCR0_INIT   (SMC_BCR_MW32 | SMC_BCR_WST2(31) | \
                         SMC_BCR_WST1(31) | SMC_BCR_IDCY(1)) 

/* Static Memory Controller chip selects 1, 2, and 3 are not used */

/* Static Memory Controller chip selects 4 through 5 are used for
   the SDK7A404 PC Card slots and are not configured here */

/* Static Memory Controller chip select 6 load value for slow CPLD
   peripherals */
#define SMC_BCR6_INIT   (SMC_BCR_MW16 | SMC_BCR_WST2(31)| \
                         SMC_BCR_WST1(31) | SMC_BCR_IDCY(1))

/* Static Memory Controller chip select 7 load value for fast CPLD
   peripherals */
#define SMC_BCR7_INIT   (SMC_BCR_MW16 | SMC_BCR_WST2(31) |  \
                         SMC_BCR_WST1(31)| SMC_BCR_IDCY(1))

/***********************************************************************
 * CPLD register addresses
 **********************************************************************/

/* Base address of slow CPLD registers and remapping selects */
#define CPLD_SLOW_BASE          SMC_CS6_BASE

/* Base address of fast CPLD registers and remapping selects */
#define CPLD_FAST_BASE          SMC_CS7_BASE

/* LAN device (chip select) base address */
#define LAN_BASE                (CPLD_FAST_BASE + 0x00000000)

/* CompactFlash (memory mode)(chip select) device base address */
#define CF_BASE                 (CPLD_SLOW_BASE + 0x00200000)

/* ISA/EISA IO (chip select) base address */
#define EISA_BASE               (CPLD_SLOW_BASE + 0x00400000)

/***********************************************************************
 * Card engine general control register and bits
 *  Bit 0 = read/write
 *    0 = LAN power enabled
 *    1 = LAN power disabled
 **********************************************************************/

/* Card engine general control register address */
#define CARDE_REG_BASE          (CPLD_FAST_BASE + 0x00200000)

/* Card engine LAN power disable bit */
#define CARDE_LAN_PWR_DISABLE   0x0001

/***********************************************************************
 * EEPROM SPI register and bits
 *  Bit 0 = read only of SPI data bit (RX)
 *  Bit 1 = read/write of SPI data (TX)
 *  Bit 2 = read/write of SPI clock
 *  Bit 3 = read/write of EEPROM chip select
 **********************************************************************/

/* EEPROM SPI register address */
#define EE2SPI_REG_BASE         (CPLD_FAST_BASE + 0x00A00000)

/* EEPROM SPI RX data bit */
#define EE2SPI_RXDAT            0x0001

/* EEPROM SPI TX data bit */
#define EE2SPI_TXDAT            0x0002

/* EEPROM SPI clock data bit */
#define EE2SPI_CLK              0x0004

/* EEPROM SPI chip select data bit */
#define EE2SPI_CS               0x0008

/***********************************************************************
 * Interrupt/mask register and bits
 *  Bit 0 = read only
 *    0 = LAN interrupt NOT pending
 *    1 = LAN interrupt pending
 *  Bit 2 = read/write
 *    0 = LAN interrupt is enabled
 *    1 = LAN interrupt is disabled
 **********************************************************************/

/* Interrupt/mask register address */
#define INTMSK_REG_BASE         (CPLD_FAST_BASE + 0x00C00000)

/* Interrupt/mask LAN interrupt pending bit */
#define INTMSK_LAN_PENDING      0x0001

/* Interrupt/mask LAN interrupt disable bit */
#define INTMSK_LAN_DISABLE      0x0004

/***********************************************************************
 * Mode register and bits
 *  Bits 0..1 = read only
 *    01 = 8-bit boot bus width
 *    10 = 16-bit boot bus width
 *    11 = 32-bit boot bus width
 *  Bit 2 = read only
 *    0 = Big endian operation
 *    1 = Little endian operation
 *  Bit 3 = read only
 *    0 = Boot device was an external device
 *    1 = Boot device was an internal device
 **********************************************************************/

/* Mode register address */
#define MODE_REG_BASE           (CPLD_FAST_BASE + 0x00E00000)

/* Mode register, bus width is 8-bits value */
#define MODE_BUS_8_WIDTH        0x0001

/* Mode register, bus width is 16-bits value */
#define MODE_BUS_16_WIDTH       0x0002

/* Mode register, bus width is 32-bits value */
#define MODE_BUS_32_WIDTH       0x0003

/* Mode register, bus width value mask */
#define MODE_BUS_WIDTH_MASK     0x0003

/* Mode register little endian mask bit */
#define MODE_LITTLE_ENDIAN      0x0004

/* Mode register boot device internal mask bit */
#define MODE_BOOTDEV_INT        0x0008

/***********************************************************************
 * Flash register and bits
 *  Bit 0 = read/write
 *    0 = Normal FLASH operation
 *    1 = Allow FLASH programming
 *  Bit 1 = read only
 *    Returns state of FLASH_STS1 signal
 *  Bit 2 = read only
 *    Returns state of FLASH_STS2 signal
 *  Bit 3 = read/write
 *    0 = FLASH populated
 *    1 = No FLASH populated
 **********************************************************************/

/* Flash register address */
#define FLASH_REG_BASE          (CPLD_FAST_BASE + 0x01000000)

/* Flash register enable programming bit */
#define FLASH_PROG_ENABLE       0x0001

/* Flash register STS1 mask bit */
#define FLASH_STS1_MASK         0x0002

/* Flash register STS2 mask bit */
#define FLASH_STS2_MASK         0x0004

/* Flash register populated bit */
#define FLASH_POP_BIT           0x0008

/***********************************************************************
 * Power management register and bits
 *  Bit 2 = read only returns state of suspend signal
 **********************************************************************/

/* Power management register address */
#define PWMAN_REG_BASE          (CPLD_FAST_BASE + 0x01200000)

/* Power management register suspend signal bit mask */
#define PWMAN_SUSPEND_BIT       0x0004

/***********************************************************************
 * CPLD revision register and bits
 *  Bits 0..7 = read only returns 8-bit CPLD revision code
 **********************************************************************/

/* CPLD revision register address */
#define CPREV_REG_BASE          (CPLD_FAST_BASE + 0x01400000)

/***********************************************************************
 * LED register and bits
 *  Bit 0 = read/write
 *    0 = Turn GPIO app board LED on
 *    1 = Turn GPIO app board LED off
 **********************************************************************/

/* LED register address */
#define LED_REG_BASE            (CPLD_FAST_BASE + 0x01600000)

/* LED register GPIO app board LED disable bit */
#define LED_GPIO_DISABLE        0x0001

/***********************************************************************
 * GPIO data register and bits
 *  Bits 0..7 = read/write of GPIO data value
 **********************************************************************/

/* GPIO data register address */
#define GPDAT_REG_BASE          (CPLD_FAST_BASE + 0x01800000)

/***********************************************************************
 * GPIO data direction register and bits
 *  Bits 0..1 = read/write
 *    0 = GPIO data register is an input
 *    1 = GPIO data register is an output
 **********************************************************************/

/* GPIO data direction register address */
#define GPDIR_REG_BASE          (CPLD_FAST_BASE + 0x01A00000)

/* GPIO data register is 'input' bit (1 = input, 0 = output) */
#define GPDIR_INPUT_SEL         0x0001

/***********************************************************************
 * SDRAM interface specific defines
 **********************************************************************/

#define SDRAM1_SEG1_ADDR  0xC0000000   /* SDRAM 1 segment 1 address */
#define SDRAM1_SEG2_ADDR  0xC1000000   /* SDRAM 1 segment 2 address */
#define SDRAM1_SEG3_ADDR  0xC4000000   /* SDRAM 1 segment 3 address */
#define SDRAM1_SEG4_ADDR  0xC5000000   /* SDRAM 1 segment 4 address */
#define SDRAM1_SEG5_ADDR  0xC8000000   /* SDRAM 1 segment 5 address */
#define SDRAM1_SEG6_ADDR  0xC9000000   /* SDRAM 1 segment 6 address */
#define SDRAM1_SEG7_ADDR  0xCC000000   /* SDRAM 1 segment 7 address */
#define SDRAM1_SEG8_ADDR  0xCD000000   /* SDRAM 1 segment 8 address */

/* The following SDRAM segments are only available on 64MByte card
   engines */
#define SDRAM2_SEG1_ADDR  0xD0000000   /* SDRAM 2 segment 1 address */
#define SDRAM2_SEG2_ADDR  0xD1000000   /* SDRAM 2 segment 2 address */
#define SDRAM2_SEG3_ADDR  0xD4000000   /* SDRAM 2 segment 3 address */
#define SDRAM2_SEG4_ADDR  0xD5000000   /* SDRAM 2 segment 4 address */
#define SDRAM2_SEG5_ADDR  0xD8000000   /* SDRAM 2 segment 5 address */
#define SDRAM2_SEG6_ADDR  0xD9000000   /* SDRAM 2 segment 6 address */
#define SDRAM2_SEG7_ADDR  0xDC000000   /* SDRAM 2 segment 7 address */
#define SDRAM2_SEG8_ADDR  0xDD000000   /* SDRAM 2 segment 8 address */

/* Size of sn SDRAM segment, 16 segments total */
#define SDRAM_SEG_SIZE    (4 * 1024 * 1024)

/* SDRAM chip select 0 configuration values */
#define SDRAM_CS_CONFIG (SDRAM_NSDCS_RASTOCAS_RASL2 | \
    SDRAM_NSDCS_CASLAT3 | SDRAM_NSDCS_BANKCOUNT4 | SDRAM_NSDCS_EBW32)

/* SDRAM mode word for burst size of 4 words, non-interleaved */
#define SDRAM_MODE_WORD   0x32

/* Refresh interval reciprocal value used to determine optimal refresh
   value (64000 = 1 / 15.625uS) */
#define SDRAM_REFRESH_INTERVAL 64000

#endif /* SDK7A404_BOARD_H */
