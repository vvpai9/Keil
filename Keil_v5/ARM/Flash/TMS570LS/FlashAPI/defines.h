#ifndef _DEFINES_H
#define _DEFINES_H

#define Antares
#define CONST_FREQ 8                                 // Value is half of HCLK,
												      // Run from Oscillator, HCLK should be 16MHz

#include "flash470.h"

typedef struct Sectors
{ void * start;
  unsigned int length;  // number of 32-bit words
  FLASH_CORE bank;
  unsigned int sectorNumber;
  unsigned int FlashBaseAddress;
} SECTORS;
typedef struct Banks
{ void * start;
  unsigned int length;  // number of 32-bit words
  unsigned int bankNumber;
  unsigned int FlashBaseAddress;
  unsigned int psa;  
} BANKS;


#ifdef Antares
#define F035
#ifndef _startup_
#define NUMBEROFSECTORS 22
const SECTORS sector[NUMBEROFSECTORS]=
{
  (void *)0x00000000, 0x08000>>2, FLASH_CORE0, 0, 0xfff87000,
  (void *)0x00008000, 0x08000>>2, FLASH_CORE0, 1, 0xfff87000,
  (void *)0x00010000, 0x08000>>2, FLASH_CORE0, 2, 0xfff87000,
  (void *)0x00018000, 0x02000>>2, FLASH_CORE0, 3, 0xfff87000,
  (void *)0x0001A000, 0x02000>>2, FLASH_CORE0, 4, 0xfff87000,
  (void *)0x0001C000, 0x04000>>2, FLASH_CORE0, 5, 0xfff87000,
  (void *)0x00020000, 0x10000>>2, FLASH_CORE0, 6, 0xfff87000,
  (void *)0x00030000, 0x10000>>2, FLASH_CORE0, 7, 0xfff87000,
  (void *)0x00040000, 0x20000>>2, FLASH_CORE0, 8, 0xfff87000,
  (void *)0x00060000, 0x20000>>2, FLASH_CORE0, 9, 0xfff87000,
  (void *)0x00080000, 0x20000>>2, FLASH_CORE1, 0, 0xfff87000,
  (void *)0x000A0000, 0x20000>>2, FLASH_CORE1, 1, 0xfff87000,
  (void *)0x000C0000, 0x20000>>2, FLASH_CORE1, 2, 0xfff87000,
  (void *)0x000E0000, 0x20000>>2, FLASH_CORE1, 3, 0xfff87000,
  (void *)0x00100000, 0x20000>>2, FLASH_CORE2, 0, 0xfff87000,
  (void *)0x00120000, 0x20000>>2, FLASH_CORE2, 1, 0xfff87000,
  (void *)0x00140000, 0x20000>>2, FLASH_CORE2, 2, 0xfff87000,
  (void *)0x00160000, 0x20000>>2, FLASH_CORE2, 3, 0xfff87000,
  (void *)0x00180000, 0x20000>>2, FLASH_CORE3, 0, 0xfff87000,
  (void *)0x001A0000, 0x20000>>2, FLASH_CORE3, 1, 0xfff87000,
  (void *)0x001C0000, 0x20000>>2, FLASH_CORE3, 2, 0xfff87000,
  (void *)0x001E0000, 0x20000>>2, FLASH_CORE3, 3, 0xfff87000

};
#define NUMBEROFBANKS 4
const BANKS bank[NUMBEROFBANKS]=
{
  (void *) 0x00000000, 0x80000>>2, 0, 0xfff87000, 0x00000000,
  (void *) 0x00080000, 0x80000>>2, 1, 0xfff87000, 0x00000000,
  (void *) 0x00100000, 0x80000>>2, 2, 0xfff87000, 0x00000000,
  (void *) 0x00180000, 0x80000>>2, 3, 0xfff87000, 0x00000000
};

#define NUMBEROFECC_PARITYBANKS 4
const BANKS ecc_parity[NUMBEROFECC_PARITYBANKS]=
{
  (void *) 0x00400000, 0x40000>>2, 0, 0xfff87000, 0x00000000,
  (void *) 0x00440000, 0x40000>>2, 1, 0xfff87000, 0x00000000,
  (void *) 0x00480000, 0x40000>>2, 2, 0xfff87000, 0x00000000,
  (void *) 0x004C0000, 0x40000>>2, 3, 0xfff87000, 0x00000000
};

#endif   /* _startup_*/
#endif   /* Antares */

#endif   /* _DEFINES_H */
