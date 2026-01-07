/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2008                         */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Flash Programming Functions adapted                   */
/*               for ST Microelectronics STM32F10x Flash               */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures

typedef volatile unsigned char  vu8;
typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;

#define M8(adr)  (*((vu8  *) (adr)))
#define M16(adr) (*((vu16 *) (adr)))
#define M32(adr) (*((vu32 *) (adr)))

// Peripheral Memory Map
#define IWDG_BASE       0x40003000
#define FLASH_BASE      0x40022000

#define IWDG            ((IWDG_TypeDef *) IWDG_BASE)
#define FLASH           ((FLASH_TypeDef*) FLASH_BASE)

// Independent WATCHDOG
typedef struct {
  vu32 KR;
  vu32 PR;
  vu32 RLR;
  vu32 SR;
} IWDG_TypeDef;

// Flash Registers
typedef struct {
  vu32 ACR;
  vu32 KEYR;
  vu32 OPTKEYR;
  vu32 SR;
  vu32 CR;
  vu32 AR;
  vu32 RESERVED;
  vu32 OBR;
  vu32 WRPR;
} FLASH_TypeDef;


// Flash Keys
#define RDPRT_KEY       0x5AA5
#define FLASH_KEY1      0x45670123
#define FLASH_KEY2      0xCDEF89AB

// Flash Control Register definitions
#define FLASH_PG        0x00000001
#define FLASH_PER       0x00000002
#define FLASH_MER       0x00000004
#define FLASH_OPTPG     0x00000010
#define FLASH_OPTER     0x00000020
#define FLASH_STRT      0x00000040
#define FLASH_LOCK      0x00000080
#define FLASH_OPTWRE    0x00000100

// Flash Status Register definitions
#define FLASH_BSY       0x00000001
#define FLASH_PGERR     0x00000004
#define FLASH_WRPRTERR  0x00000010
#define FLASH_EOP       0x00000020


/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  // Zero Wait State
  FLASH->ACR  = 0x00000000;

  // Unlock Flash    
  FLASH->KEYR = FLASH_KEY1;
  FLASH->KEYR = FLASH_KEY2;

  // Test if IWDG is running (IWDG in HW mode)
  if ((FLASH->OBR & 0x04) == 0x00) {
    // Set IWDG time out to ~32.768 second
    IWDG->KR  = 0x5555; // Enable write access to IWDG_PR and IWDG_RLR     
    IWDG->PR  = 0x06;   // Set prescaler to 256  
    IWDG->RLR = 4095;   // Set reload value to 4095
  }

  return (0);
}
#endif

#ifdef FLASH_OPT
int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  // Zero Wait State
  FLASH->ACR  = 0x00000000;

  // Unlock Flash    
  FLASH->KEYR = FLASH_KEY1;
  FLASH->KEYR = FLASH_KEY2;

  // Unlock Option Bytes
  FLASH->OPTKEYR = FLASH_KEY1;
  FLASH->OPTKEYR = FLASH_KEY2;

  // Test if IWDG is running (IWDG in HW mode)
  if ((FLASH->OBR & 0x04) == 0x00) {
    // Set IWDG time out to ~32.768 second
    IWDG->KR  = 0x5555; // Enable write access to IWDG_PR and IWDG_RLR     
    IWDG->PR  = 0x06;   // Set prescaler to 256  
    IWDG->RLR = 4095;   // Set reload value to 4095
  }

  return (0);
}
#endif


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int UnInit (unsigned long fnc) {

  // Lock Flash
  FLASH->CR |=  FLASH_LOCK;

  return (0);
}
#endif

#ifdef FLASH_OPT
int UnInit (unsigned long fnc) {

  // Lock Flash & Option Bytes
  FLASH->CR &= ~FLASH_OPTWRE;
  FLASH->CR |=  FLASH_LOCK;

  return (0);
}
#endif


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int EraseChip (void) {

  FLASH->CR |=  FLASH_MER;                      // Mass Erase Enabled
  FLASH->CR |=  FLASH_STRT;                     // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                          // Reload IWDG
  }

  FLASH->CR &= ~FLASH_MER;                      // Mass Erase Disabled

  return (0);                                   // Done
}
#endif

#ifdef FLASH_OPT
int EraseChip (void) {

  FLASH->CR |=  FLASH_OPTER;                    // Option Byte Erase Enabled 
  FLASH->CR |=  FLASH_STRT;                     // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                          // Reload IWDG
  }

  FLASH->CR &= ~FLASH_OPTER;                    // Option Byte Erase Disabled 

  // Unprotect Flash

  FLASH->CR |=  FLASH_OPTPG;                    // Option Byte Programming Enabled

  M16(0x1FFFF800) = RDPRT_KEY;                  // Program Half Word: RDPRT Key
  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                          // Reload IWDG
  }

  FLASH->CR &= ~FLASH_OPTPG;                    // Option Byte Programming Disabled

  // Check for Errors
  if (FLASH->SR & (FLASH_PGERR | FLASH_WRPRTERR)) {
    FLASH->SR |= FLASH_PGERR | FLASH_WRPRTERR;
    return (1);                                 // Failed
  }

  return (0);                                   // Done
}
#endif


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int EraseSector (unsigned long adr) {

  FLASH->CR |=  FLASH_PER;                      // Page Erase Enabled 
  FLASH->AR  =  adr;                            // Page Address
  FLASH->CR |=  FLASH_STRT;                     // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                          // Reload IWDG
  }

  FLASH->CR &= ~FLASH_PER;                      // Page Erase Disabled 

  return (0);                                   // Done
}
#endif

#ifdef FLASH_OPT
int EraseSector (unsigned long adr) {

  FLASH->CR |=  FLASH_OPTER;                    // Option Byte Erase Enabled 
  FLASH->CR |=  FLASH_STRT;                     // Start Erase

  while (FLASH->SR & FLASH_BSY) {
    IWDG->KR = 0xAAAA;                          // Reload IWDG
  }

  FLASH->CR &= ~FLASH_OPTER;                    // Option Byte Erase Disabled 

  return (0);                                   // Done
}
#endif


/*  
 *  Blank Check Checks if Memory is Blank
 *    Parameter:      adr:  Block Start Address
 *                    sz:   Block Size (in bytes)
 *                    pat:  Block Pattern
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_OPT
int BlankCheck (unsigned long adr, unsigned long sz, unsigned char pat) {
  return (1);                                   // Always Force Erase
}
#endif


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {

  sz = (sz + 1) & ~1;                           // Adjust size for Half Words
  
  while (sz) {

    FLASH->CR |=  FLASH_PG;                     // Programming Enabled

    M16(adr) = *((unsigned short *)buf);        // Program Half Word
    while (FLASH->SR & FLASH_BSY);

    FLASH->CR &= ~FLASH_PG;                     // Programming Disabled

    // Check for Errors
    if (FLASH->SR & (FLASH_PGERR | FLASH_WRPRTERR)) {
      FLASH->SR |= FLASH_PGERR | FLASH_WRPRTERR;
      return (1);                               // Failed
    }

    // Go to next Half Word
    adr += 2;
    buf += 2;
    sz  -= 2;
   
  }

  return (0);                                   // Done
}
#endif

#ifdef FLASH_OPT
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {

  sz = (sz + 1) & ~1;                           // Adjust size for Half Words
  
  while (sz) {

    FLASH->CR |=  FLASH_OPTPG;                  // Option Byte Programming Enabled

    M16(adr) = *((unsigned short *)buf);        // Program Half Word
    while (FLASH->SR & FLASH_BSY) {
      IWDG->KR = 0xAAAA;                        // Reload IWDG
    }

    FLASH->CR &= ~FLASH_OPTPG;                  // Option Byte Programming Disabled

    // Check for Errors
    if (FLASH->SR & (FLASH_PGERR | FLASH_WRPRTERR)) {
      FLASH->SR |= FLASH_PGERR | FLASH_WRPRTERR;
      return (1);                               // Failed
    }

    // Go to next Half Word
    adr += 2;
    buf += 2;
    sz  -= 2;
   
  }

  return (0);                                   // Done
}
#endif
