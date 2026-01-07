/******************************************************************************/
/*  This file is part of the ARM Toolchain package                            */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2009                                */
/******************************************************************************/
/*                                                                            */
/*  FlashDev.C:  Device Description for Dual Spansion S29GL032 (32-bit bus)   */
/*                                                                            */
/******************************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures


struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "S29GL032 Flash",           // Device Name 
   EXT16BIT,                   // Device Type
   0x10000000,                 // Device Start Address
   0x00400000,                 // Device Size in Bytes (4MB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   4000,                       // Erase Sector Timeout 4000 mSec

// Specify Size and Address of Sectors
// Union of top and bottom boot sector
   0x02000,     0x00000,       // Sector Size 8kB  ( 8 Sectors)
   0x10000,  1 *0x10000,       // Sector Size 64kB (62 Sectors)
   0x02000, 63 *0x10000,       // Sector Size 8kB  ( 8 Sectors)
   SECTOR_END
};
