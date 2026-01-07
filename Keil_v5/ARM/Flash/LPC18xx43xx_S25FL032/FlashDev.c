/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2012 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for                                */
/*               S25FL032P0XMFI010 populated on MCB1800 / MCB4300      */
/*                                                                     */
/***********************************************************************/

#include "../FlashOS.H"        // FlashOS Structures

struct FlashDevice const FlashDevice = {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "LPC18xx/43xx S25FL032 SPIFI", // Device Name 
   EXTSPI,                     // Device Type
   0x14000000,                 // Device Start Address
   0x00400000,                 // Device Size is 4MB
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   500,                        // Program Page Timeout 100 mSec
   5000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x010000, 0,                // sectors are 64 KB
   SECTOR_END
};
