/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Drivers:NOR
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    NOR_Device.h
 * Purpose: NOR Flash Device Description - Template
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/

#define NOR_FLASH_NAME  Template            /* Flash Device Name */

#define NOR_FLASH_SIZE  0x100000            /* Flash Device Size in bytes 1MB */
#define NOR_FLASH_EVAL  0xFF                /* Contents of Erased Memory */

#define NOR_FLASH_SECTORS                                          \
  ARM_NOR_SECTOR_INFO(0x000000, 0x08000),   /* Sector Size 32kB */ \
  ARM_NOR_SECTOR_INFO(0x008000, 0x04000),   /* Sector Size 16kB */ \
  ARM_NOR_SECTOR_INFO(0x00C000, 0x02000),   /* Sector Size  8kB */ \
  ARM_NOR_SECTOR_INFO(0x00E000, 0x02000)    /* Sector Size  8kB */

#define NOR_FLASH_SECTOR_NUM    4           /* Number of Sectors */
