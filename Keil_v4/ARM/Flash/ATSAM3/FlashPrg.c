/******************************************************************************/
/*  This file is part of the ARM Toolchain package                            */
/*  Copyright KEIL ELEKTRONIK GmbH 2003 - 2009                                */
/******************************************************************************/
/*                                                                            */
/*  FlashDev.C:  Flash Programming Functions adapted for ATSAM3 Flashes       */
/*                                                                            */
/******************************************************************************/

#include "..\FlashOS.H"        // FlashOS Structures
#include <SAM3U.H>

#define KEY                    (0x37   << 16)
#define FKEY                   (0x5AUL << 24)
#define FLASH_PAGE_SIZE_BYTE   256

#define STACK_SIZE   64        // Stack Size


unsigned long base_adr;        // Base Address


/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {
  AT91PS_EFC      pEFC;

  base_adr = adr;

#if SIZE_128k_B1
  pEFC = AT91C_BASE_EFC1;
#else
  pEFC = AT91C_BASE_EFC0;
#endif

  if (fnc == 1) {
    // Set Flash Waite State to maximum
    pEFC->EFC_FMR = AT91C_EFC_FWS;

    // Disable Watchdog
    *AT91C_WDTC_WDMR = AT91C_WDTC_WDDIS;

    // Enable the Main Oscillator:
    // SCK Period = 1/32768 = 30.51 us
    // Start-up Time = 8 * 15 / SCK = 120 * 30.51us = 3.6612 ms
    *AT91C_PMC_MOR = (AT91C_CKGR_MOSCSEL | KEY | (AT91C_CKGR_MOSCXTST & (0x0F << 8) | AT91C_CKGR_MOSCXTEN));

    // Wait the Start-up Time
    while(!(*AT91C_PMC_SR & AT91C_PMC_MOSCXTS));

    // Select Main Clock (CSS field)
    *AT91C_PMC_MCKR = (*AT91C_PMC_MCKR & ~AT91C_PMC_CSS) | AT91C_PMC_CSS_MAIN_CLK;

    // Wait for Clock ready
    while (!(*AT91C_PMC_SR & AT91C_PMC_MCKRDY));

    // Select Main Clock
    *AT91C_PMC_MCKR = AT91C_PMC_CSS_MAIN_CLK;

    // Wait for Clock ready
    while (!(*AT91C_PMC_SR & AT91C_PMC_MCKRDY));
  }

  return (0);
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {
  unsigned long   FRR;
  AT91PS_EFC      pEFC;

#if SIZE_128k_B1
  pEFC = AT91C_BASE_EFC1;
#else
  pEFC = AT91C_BASE_EFC0;
#endif

  if (fnc == 2) {
    // Get GPNVM bit 2
    pEFC->EFC_FCR = FKEY | (2 << 8) | AT91C_EFC_FCMD_GFB;

    // Wait until the end of Command
    while (!(pEFC->EFC_FSR & AT91C_EFC_FRDY_S));

    FRR = pEFC->EFC_FRR;
    if ((pEFC == AT91C_BASE_EFC0) && (FRR != 2)) {
      // Set GPNVM bit 2 for booting from Flash
      pEFC->EFC_FCR = FKEY | (1 << 8) | AT91C_EFC_FCMD_SFB;

      // Wait until the end of Command
      while (!(pEFC->EFC_FSR & AT91C_EFC_FRDY_S));

      // Clear GPNVM bit 2 for booting from Flash
      pEFC->EFC_FCR = FKEY | (2 << 8) | AT91C_EFC_FCMD_CFB;

      // Wait until the end of Command
      while (!(pEFC->EFC_FSR & AT91C_EFC_FRDY_S));
    }

    if ((pEFC == AT91C_BASE_EFC1) && (FRR != 6)) {
      // Set GPNVM bit 2 for booting from Flash
      pEFC->EFC_FCR = FKEY | (1 << 8) | AT91C_EFC_FCMD_SFB;

      // Wait until the end of Command
      while (!(pEFC->EFC_FSR & AT91C_EFC_FRDY_S));

      // Clear GPNVM bit 2 for booting from Flash
      pEFC->EFC_FCR = FKEY | (2 << 8) | AT91C_EFC_FCMD_SFB;

      // Wait until the end of Command
      while (!(pEFC->EFC_FSR & AT91C_EFC_FRDY_S));
    }
  }

  return (0);
}


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseChip (void) {
  AT91PS_EFC      pEFC;

#if SIZE_128k_B1
  pEFC = AT91C_BASE_EFC1;
#else
  pEFC = AT91C_BASE_EFC0;
#endif

  // Erase All Command
  pEFC->EFC_FCR = FKEY | AT91C_EFC_FCMD_EA;

  // Wait until the end of Command
  while (!(pEFC->EFC_FSR & AT91C_EFC_FRDY_S));

  return (0);
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {
  return (0);                  // Automatic Erase during Program Cycle
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
  unsigned long   page;
  unsigned long * Flash;
  AT91PS_EFC      pEFC;

#if SIZE_128k_B1
  pEFC = AT91C_BASE_EFC1;
#else
  pEFC = AT91C_BASE_EFC0;
#endif

  Flash = (unsigned long *)adr;
  page  = (adr - base_adr) / FLASH_PAGE_SIZE_BYTE;

  // Unlock Page Command
  pEFC->EFC_FCR = FKEY | AT91C_EFC_FCMD_CLB | (AT91C_EFC_FARG & (page << 8));

  // Wait until the end of Command
  while (!(pEFC->EFC_FSR & AT91C_EFC_FRDY_S));

  // Copy to the Write Buffer
  for (sz = (sz + 3) & ~3; sz; sz -= 4, buf += 4) {
	*Flash++ = *((unsigned long *)buf);
  }
  //* Start Programming Command
  pEFC->EFC_FCR = FKEY | AT91C_EFC_FCMD_EWP | (AT91C_EFC_FARG & (page << 8));

  // Wait until the end of Command
  while (!(pEFC->EFC_FSR & AT91C_EFC_FRDY_S));

  // Check for Errors
  if (pEFC->EFC_FSR & (AT91C_EFC_FCMDE | AT91C_EFC_LOCKE)) return (1);

  return (0);
}
