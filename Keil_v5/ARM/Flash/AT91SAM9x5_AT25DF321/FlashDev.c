/******************************************************************************/
/*  This file is part of the ARM Toolchain package                            */
/*  Copyright KEIL ELEKTRONIK GmbH 2005 - 2010                                */
/******************************************************************************/
/*                                                                            */
/*  FlashDev.C:  Device Description for flash algorithm using Atmel           */
/*               AT91SAM9Gxx Device for Programming AT25DF321 SerialFlash       */
/*                                                                            */
/******************************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef AT91SAM9G15
  #ifdef P256_CS0                // Page Size 528 Bytes, Chip Select 0
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "AT91SAM9G15 AT25DF321 Page256 CS0",    // Device Name
   EXTSPI,                     // Device Type
   0x20000000,                 // Device Start Address
   0x00400000,                 // Device Size in Bytes (4MB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   2000,                       // Program Page Timeout 1000 mSec
   2000,                       // Erase Sector Timeout 1000 mSec
// Specify Size and Address of Sectors
   0x10000, 0x000000,          // Sector Size 64 Kbytes
   SECTOR_END
};
  #endif
#endif

#ifdef AT91SAM9G25
  #ifdef P256_CS0                // Page Size 528 Bytes, Chip Select 0
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "AT91SAM9G25 AT25DF321 Page256 CS0",    // Device Name
   EXTSPI,                     // Device Type
   0x20000000,                 // Device Start Address
   0x00400000,                 // Device Size in Bytes (4MB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   2000,                       // Program Page Timeout 1000 mSec
   2000,                       // Erase Sector Timeout 1000 mSec
// Specify Size and Address of Sectors
   0x10000, 0x000000,          // Sector Size 64 Kbytes
   SECTOR_END
};
  #endif
#endif

#ifdef AT91SAM9G35
  #ifdef P256_CS0                // Page Size 528 Bytes, Chip Select 0
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "AT91SAM9G35 AT25DF321 Page256 CS0",    // Device Name
   EXTSPI,                     // Device Type
   0x20000000,                 // Device Start Address
   0x00400000,                 // Device Size in Bytes (4MB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   2000,                       // Program Page Timeout 1000 mSec
   2000,                       // Erase Sector Timeout 1000 mSec
// Specify Size and Address of Sectors
   0x10000, 0x000000,          // Sector Size 64 Kbytes
   SECTOR_END
};
  #endif
#endif

#ifdef AT91SAM9X25
  #ifdef P256_CS0                // Page Size 528 Bytes, Chip Select 0
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "AT91SAM9X25 AT25DF321 Page256 CS0",    // Device Name
   EXTSPI,                     // Device Type
   0x20000000,                 // Device Start Address
   0x00400000,                 // Device Size in Bytes (4MB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   2000,                       // Program Page Timeout 1000 mSec
   2000,                       // Erase Sector Timeout 1000 mSec
// Specify Size and Address of Sectors
   0x10000, 0x000000,          // Sector Size 64 Kbytes
   SECTOR_END
};
  #endif
#endif

#ifdef AT91SAM9X35
  #ifdef P256_CS0                // Page Size 528 Bytes, Chip Select 0
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "AT91SAM9X35 AT25DF321 Page256 CS0",    // Device Name
   EXTSPI,                     // Device Type
   0x20000000,                 // Device Start Address
   0x00400000,                 // Device Size in Bytes (4MB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   2000,                       // Program Page Timeout 1000 mSec
   2000,                       // Erase Sector Timeout 1000 mSec
// Specify Size and Address of Sectors
   0x10000, 0x000000,          // Sector Size 64 Kbytes
   SECTOR_END
};
  #endif
#endif
#ifdef SAM9x5_CM
  #ifdef P256_CS0                // Page Size 528 Bytes, Chip Select 0
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "SAM9X5-CM AT25DF321 Page256 CS0",    // Device Name
   EXTSPI,                     // Device Type
   0x20000000,                 // Device Start Address
   0x00400000,                 // Device Size in Bytes (4MB)
   256,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   2000,                       // Program Page Timeout 1000 mSec
   2000,                       // Erase Sector Timeout 1000 mSec
// Specify Size and Address of Sectors
   0x10000, 0x000000,          // Sector Size 64 Kbytes
   SECTOR_END
};
  #endif
#endif
