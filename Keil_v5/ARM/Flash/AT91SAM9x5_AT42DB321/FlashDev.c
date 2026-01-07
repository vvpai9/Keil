/******************************************************************************/
/*  This file is part of the ARM Toolchain package                            */
/*  Copyright KEIL ELEKTRONIK GmbH 2005 - 2012                                */
/******************************************************************************/
/*                                                                            */
/*  FlashDev.C:  Device Description for flash algorithm using Atmel           */
/*               SAM9X5-CM for Programming AT45DB321D SerialFlash             */
/*                                                                            */
/******************************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures
#ifdef P528_CS0                // Page Size 528 Bytes, Chip Select 0
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "SAM9X5-CM AT42DB321D Page528 CS0",    // Device Name
   EXTSPI,                     // Device Type
   0x20000000,                 // Device Start Address
   0x00420000,                 // Device Size in Bytes (4.125MB)
   528,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   1000,                       // Erase Sector Timeout 1000 mSec
// Specify Size and Address of Sectors
   0x1080, 0x000000,           // Sector Size 4224 bytes (block = 8*page)
   SECTOR_END
};
#endif
