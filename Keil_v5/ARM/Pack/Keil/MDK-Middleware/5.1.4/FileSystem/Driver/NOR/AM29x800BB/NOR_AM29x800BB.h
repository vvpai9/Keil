/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Drivers:NOR
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    NOR_AM29x800BB.h
 * Purpose: NOR Flash Device Description for AM29x800BB (16-bit Bus)
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/

#define NOR_FLASH_NAME  AM29x800BB          /* Flash Device Name */

#define NOR_FLASH_SIZE  0x100000            /* Flash Device Size in bytes 1MB */
#define NOR_FLASH_EVAL  0xFF                /* Contents of Erased Memory */

#define NOR_FLASH_SECTORS                                          \
  ARM_NOR_SECTOR_INFO(0x000000, 0x04000),   /* Sector Size 16kB */ \
  ARM_NOR_SECTOR_INFO(0x004000, 0x08000),   /* Sector Size 32kB */ \
  ARM_NOR_SECTOR_INFO(0x00C000, 0x02000),   /* Sector Size  8kB */ \
  ARM_NOR_SECTOR_INFO(0x00E000, 0x02000),   /* Sector Size  8kB */ \
  ARM_NOR_SECTOR_INFO(0x010000, 0x02000),   /* Sector Size  8kB */ \
  ARM_NOR_SECTOR_INFO(0x012000, 0x02000),   /* Sector Size  8kB */ \
  ARM_NOR_SECTOR_INFO(0x014000, 0x08000),   /* Sector Size 32kB */ \
  ARM_NOR_SECTOR_INFO(0x01C000, 0x04000),   /* Sector Size 16kB */ \
  ARM_NOR_SECTOR_INFO(0x020000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x030000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x040000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x050000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x060000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x070000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x080000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x090000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x0A0000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x0B0000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x0C0000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x0D0000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x0E0000, 0x10000),   /* Sector Size 64kB */ \
  ARM_NOR_SECTOR_INFO(0x0F0000, 0x10000)    /* Sector Size 64kB */

#define NOR_FLASH_SECTOR_NUM    22          /* Number of Sectors */
