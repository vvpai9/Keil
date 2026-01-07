/******************************************************************************/
/*  This file is part of the ARM Toolchain package                            */
/*  Copyright KEIL ELEKTRONIK GmbH 2005 - 2012                                */
/******************************************************************************/
/*                                                                            */
/*  FlashDev.C:  Flash Programming Functions adapted for External DataFlash   */
/*               AT45DB321D programming with SAM9X5-CM                        */
/*                                                                            */
/******************************************************************************/

#include "..\FlashOS.H"                 // FlashOS Structures
#include "FlashHW.h"                    // Low level flash declarations
#include "Error.h"                      // Error definitions

#include <AT91SAM9G35.H>

#define STACK_SIZE   128                // Stack Size
#define PAGE_SIZE    528                // Page Size

#define DF_OFFSET    0x4200             // User Program offset in DataFlash
#define SDRAM_START  0x20000000         // Start of External SDRAM

unsigned char rd_buf[PAGE_SIZE];              // Global buffer for reading


/************************* Flash Algorithm Functions ***************************/

/*- Init (...) -----------------------------------------------------------------
 *
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */
           
int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

  switch (fnc)  {
    case 1:  
      REG_WDT_MR   = 0x00008000;       // Disable watchdog
      InitFlashController_HW(0, 0, 0, clk);
      break;
    case 2:                            // Erase   Init
    case 3:                            // Verify  Init
      break;
  }

  return (0);
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {
  return (0);
}


/*- BlankCheck (...) -----------------------------------------------------------
 *
 *  Blank Check Checks if Memory is Blank
 *    Parameter:      adr:  Block Start Address
 *                    sz:   Block Size (in bytes)
 *                    pat:  Block Pattern
 *    Return Value:   0 - OK,  1 - Failed
 */

int BlankCheck (unsigned long adr, unsigned long sz, unsigned char pat) {

  unsigned long i, j, k;

  // Recalculate address for External SDRAM addresses
  if (adr >= SDRAM_START)
    adr = adr - SDRAM_START + DF_OFFSET;

  for (i = 0; i < sz; i += PAGE_SIZE) {
    // Read PAGE_SIZE bytes
    ReadPage_HW (adr+i, PAGE_SIZE, &rd_buf[0]);

    // Determine size to compare
    if ((sz-i) >= PAGE_SIZE) k = PAGE_SIZE;
    else               k = (sz-i);

    // Check up to PAGE_SIZE bytes if equal to pattern "pat"
    for (j = 0; j < k; j++)
      if (rd_buf[j] != pat) return (1); // Memory is not blank
  }

  return (0);                           // Memory is blank
}


/*- EraseSector (...) ----------------------------------------------------------
 *
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {

  // Recalculate address for External SDRAM addresses
  if (adr >= SDRAM_START)
    adr = adr - SDRAM_START + DF_OFFSET;

  if ((EraseBlock_HW (adr)) != OK) return (1);

  return (0);
}


/*- EraseChip (...) ------------------------------------------------------------
 *
 *  Erase Complete Flash Memory
 *    Parameter:
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseChip (void) {

  if ((EraseChip_HW ()) != OK) return (1);

  return (0);
}


/*- ProgramPage (...) ----------------------------------------------------------
 *
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {

  // Recalculate address for External SDRAM addresses
  if (adr >= SDRAM_START)
    adr = adr - SDRAM_START + DF_OFFSET;

  if ((ProgramPage_HW (adr, sz, buf)) != OK) return (1);

  return (0);
}

/*- Verify (...) ---------------------------------------------------------------
 *
 *  Verify Flash Contents
 *    Parameter:      adr:  Start Address
 *                    sz:   Size (in bytes)
 *                    buf:  Data
 *    Return Value:   (adr+sz) - OK, Failed Address
 */

unsigned long Verify (unsigned long adr, unsigned long sz, unsigned char *buf) {

  unsigned long i, j, k, adr_req;

  // Remember requested address
  adr_req = adr;

  // Recalculate address for External SDRAM addresses
  if (adr >= SDRAM_START)
    adr = adr - SDRAM_START + DF_OFFSET;
  for (i = 0; i < sz; i += PAGE_SIZE) {
    // Read PAGE_SIZE bytes
    ReadPage_HW (adr+i, PAGE_SIZE, &rd_buf[0]);

    // Determine size to compare
    if ((sz-i) >= PAGE_SIZE) k = PAGE_SIZE;
    else               k = (sz-i);

    // Check up to PAGE_SIZE bytes
    for (j = 0; j < k; j++)
      if (buf[i+j] != rd_buf[j]) return (adr_req+i+j);
  }
  return (adr_req+sz);                  // Verification was successful
}


/*******************************************************************************/
