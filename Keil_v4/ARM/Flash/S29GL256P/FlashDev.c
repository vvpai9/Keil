/******************************************************************************/
/*  This file is part of the ARM Toolchain package                            */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2008                                */
/******************************************************************************/
/*                                                                            */
/*  FlashDev.C:  Device Description for Spansion S29GL256P (16-bit bus)       */
/*                                                                            */
/******************************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef S29GL256P
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "S29GL256P Flash",          // Device Name 
   EXT16BIT,                   // Device Type
   0x0000000,                  // Device Start Address
   0x2000000,                  // Device Size in Bytes (32MB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   600,                        // Erase Sector Timeout 600 mSec

// Specify Size and Address of Sectors
   0x20000,     0x00000,       // Sector Size 128kB (256 Sectors)
   SECTOR_END
};
#endif

#ifdef S29GL128P
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "S29GL128P Flash",          // Device Name 
   EXT16BIT,                   // Device Type
   0x0000000,                  // Device Start Address
   0x1000000,                  // Device Size in Bytes (32MB)
   1024,                       // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   600,                        // Erase Sector Timeout 600 mSec

// Specify Size and Address of Sectors
   0x20000,     0x00000,       // Sector Size 128kB (256 Sectors)
   SECTOR_END
};
#endif
