/******************************************************************************/
/* :   Include file for Hardware Layer Flash Programming functions  */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2010 Keil Software. All rights reserved.                     */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/
#include <AT91SAM9G35.H>

#include "Error.h"                      // Error definitions
#define SYS_CLOCK    64500000           // System Clock (in Hz)
#define SPI_CLOCK    1000000            // Expected SPI clock speed (in Hz)

#define SPI_PCS0_DF  0x0E               // Chip Select 0 : NPCS0 %1110
#define SPI_PCS1_DF  0x0D               // Chip Select 1 : NPCS1 %1101
#define SPI_PCS2_DF  0x0B               // Chip Select 2 : NPCS2 %1011
#define SPI_PCS3_DF  0x07               // Chip Select 3 : NPCS3 %0111

// ----------------- Page Size  528, CS0 used ----------------------------------
#ifdef P256_CS0
#define PAGE_SIZE    256                // Size of page
#define ADDR_BITS     9                 // Bits for addressing inside page
#define CHIP_SIZE    0x400000           // Chip size (in bytes)
#define SPI_PCS_DF   SPI_PCS0_DF
#define CS_INDEX     0
#endif

// ----------------- Page Size 1056, CS0 used ----------------------------------
#ifdef P1056_CS0
#define PAGE_SIZE    1056               // Size of page
#define ADDR_BITS    11                 // Bits for addressing inside page
#define CHIP_SIZE    0x840000           // Chip size (in bytes) = 8MB
#define SPI_PCS_DF   SPI_PCS0_DF
#define CS_INDEX     0
#endif

// ----------------- Page Size 1056, CS1 used ----------------------------------
#ifdef P1056_CS1
#define PAGE_SIZE    1056               // Size of page
#define ADDR_BITS    11                 // Bits for addressing inside page
#define CHIP_SIZE    0x840000           // Chip size (in bytes) = 8MB
#define SPI_PCS_DF   SPI_PCS1_DF
#define CS_INDEX     1
#endif

#define BLOCK_SIZE   0x10000            // Block size (used for erase)

// AT25DF321 COMMANDS
#define AT25_READ_ARRAY_LF        0x03  // Continuous array read
#define AT25_BLOCK_ERASE_64K      0xD8  // Block Erase                   
#define AT25_BYTE_PAGE_PROGRAM    0x02  // Program
#define AT25_READ_STATUS          0x05  // Read status register command code
#define AT25_WRITE_STATUS         0x01  // Write status register command code
#define AT25_WRITE_ENABLE         0x06  // Write enable command code

// AT25 Status definition
#define AT25_STATUS_RDYBSY          (1 << 0)  // Device is Busy
#define AT25_STATUS_SWP             (3 << 2)  // SW protection bit field
#define AT25_STATUS_SWP_PROTALL     (3 << 2)  // Device is SW protected
#define AT25_STATUS_EPE             (1 << 5)  // Program Error

/** SPI chip select configuration value. */
#define SPID_CSR_SCBR(mck, spck)    SPI_CSR_SCBR((mck) / (spck))
/** Calculates the value of the DLYBS field of the Chip Select Register given delay in ns and MCK.*/
#define SPID_CSR_DLYBS(mck, delay)  SPI_CSR_DLYBS((((delay) * ((mck) / 1000000)) / 1000) + 1)
/** Calculates the value of the DLYBCT field of the Chip Select Register given delay in ns and MCK.*/
#define SPID_CSR_DLYBCT(mck, delay) SPI_CSR_DLYBCT((((delay) / 32 * ((mck) / 1000000)) / 1000) + 1)
#define SPI_PCS(npcs)   ((~(1 << npcs) & 0xF) << 16)
#define CSR             (SPI_CSR_NCPHA | \
                         SPI_CSR_CSAAT | \
                         SPID_CSR_DLYBCT(SYS_CLOCK, 100) | \
                         SPID_CSR_DLYBS(SYS_CLOCK, 5) | \
                         SPID_CSR_SCBR(SYS_CLOCK, SPI_CLOCK))


static unsigned int    command;         // Command for DataFlash
static unsigned char    status;         // Status of Data Flash
                                        // Module's local functions prototypes
static unsigned long   SwapU32            (unsigned long to_swap);
static          int    SendCommandDF      (unsigned char cmd, unsigned char cmd_sz, unsigned long adr, unsigned char *buf, unsigned long sz);


/************************* Module Exported Functions ***************************/

/*- InitFlashController_HW (...) -----------------------------------------------
 *
 *  Initialize Flash Controller
 *    Parameter:  bus_width:  Bus Width (8, 16 bit)
 *               adr_cycles:  Addressing Cycles (3, 4, 5)
 *                page_type:  Page Type (0 -Small Page, 1 - Large Page)
 *                      clk:  Clock Frequency (Hz)
 *    Return Value:           ERROR code
 */


int InitFlashController_HW (unsigned char bus_width, unsigned char adr_cycles, unsigned char page_type, unsigned long clk) {

  /* 1. Initialize pins for SPI functionality                                 */
  /* Enable clocks                                                            */
  PMC->PMC_PCER       |= (1 << ID_PIOA);
  PMC->PMC_PCER       |= (1 << ID_PIOB);
  PMC->PMC_PCER       |= (1 << ID_SPI0);

  /* MISO  pin: int disable, not pull-up, alt func A select, enable alt func  */
  PIOA->PIO_IDR       |= PIO_PA11A_SPI0_MISO; 
  PIOA->PIO_PUDR      |= PIO_PA11A_SPI0_MISO; 
  PIOA->PIO_ABCDSR[0] &= ~PIO_PA11A_SPI0_MISO; 
  PIOA->PIO_ABCDSR[1] &= ~PIO_PA11A_SPI0_MISO; 
  PIOA->PIO_PDR       |= PIO_PA11A_SPI0_MISO; 
  /* MOSI  pin: int disable, not pull-up, alt func A select, enable alt func  */
  PIOA->PIO_IDR       |= PIO_PA12A_SPI0_MOSI; 
  PIOA->PIO_PUDR      |= PIO_PA12A_SPI0_MOSI; 
  PIOA->PIO_ABCDSR[0] &= ~PIO_PA12A_SPI0_MOSI; 
  PIOA->PIO_ABCDSR[1] &= ~PIO_PA12A_SPI0_MOSI; 
  PIOA->PIO_PDR       |= PIO_PA12A_SPI0_MOSI; 
  /* SPCK  pin: int disable, not pull-up, alt func A select, enable alt func  */
  PIOA->PIO_IDR       |= PIO_PA13A_SPI0_SPCK; 
  PIOA->PIO_PUDR      |= PIO_PA13A_SPI0_SPCK; 
  PIOA->PIO_ABCDSR[0] &= ~PIO_PA13A_SPI0_SPCK; 
  PIOA->PIO_ABCDSR[1] &= ~PIO_PA13A_SPI0_SPCK; 
  PIOA->PIO_PDR       |= PIO_PA13A_SPI0_SPCK; 
  /* NPCS0 pin: int disable, not pull-up, alt func A select, enable alt func  */
  PIOA->PIO_IDR       |= PIO_PA14A_SPI0_NPCS0;
  PIOA->PIO_PUDR      |= PIO_PA14A_SPI0_NPCS0;
  PIOA->PIO_ABCDSR[0] &= ~PIO_PA14A_SPI0_NPCS0; 
  PIOA->PIO_ABCDSR[1] &= ~PIO_PA14A_SPI0_NPCS0; 
  PIOA->PIO_PDR       |= PIO_PA14A_SPI0_NPCS0;
  /* NPCS1 pin: int disable, not pull-up, alt func B select, enable alt func  */
  PIOB->PIO_IDR       |= PIO_PA7B_SPI0_NPCS1;
  PIOB->PIO_PUDR      |= PIO_PA7B_SPI0_NPCS1;
  PIOB->PIO_ABCDSR[0] |=  PIO_PA7B_SPI0_NPCS1; 
  PIOB->PIO_ABCDSR[1] &= ~PIO_PA7B_SPI0_NPCS1; 
  PIOB->PIO_PDR       |= PIO_PA7B_SPI0_NPCS1;
  /* 2. Initialize SPI0 controller                                            */
  SPI0->SPI_CR         = SPI_CR_SWRST;
  SPI0->SPI_CR         = SPI_CR_SWRST;
  SPI0->SPI_MR         = SPI_MR_MSTR | SPI_MR_MODFDIS | SPI_MR_PCS_Msk;

  SPI0->SPI_CSR[0]     = CSR;
  SPI0->SPI_MR        &= ~SPI_MR_PCS_Msk;
  SPI0->SPI_MR        |= ((SPI_PCS_DF << 16) & SPI_MR_PCS_Msk);

  SPI0->SPI_CR        |= SPI_CR_SPIEN;

  // Wait for DataFlash to become ready
  do { SendCommandDF(AT25_READ_STATUS, 1, 0, &status, 1); }  while ((status & AT25_STATUS_RDYBSY));

  if ((status & 0x0C) == 0x00) return (OK);	 // Data Flash is not protected

  SendCommandDF(AT25_WRITE_ENABLE, 1, 0, 0, 0);
  status = 0;
  SendCommandDF(AT25_WRITE_STATUS, 1, 0, &status, 1);
  return (OK);
}
/*- UnInit_HW (...) ------------------------------------------------------------
 *
 *  Uninitialize Hardware to leave it in reset state
 *    Parameter:
 *    Return Value:           ERROR code
 */

int UnInit_HW (void) {

  /* Disable SPI controller                                                   */
  SPI0->SPI_CR     |= SPI_CR_SPIDIS;

  /* Disable SPI pins                                                            */
  PIOA->PIO_PER    |= PIO_PA11A_SPI0_MISO; 
  PIOA->PIO_PER    |= PIO_PA12A_SPI0_MOSI; 
  PIOA->PIO_PER    |= PIO_PA13A_SPI0_SPCK; 
#if   (CS_INDEX == 0)
  PIOA->PIO_PER    |= PIO_PA14A_SPI0_NPCS0;
#elif (CS_INDEX == 1)
  PIOB->PIO_PER    |= PIO_PA7B_SPI0_NPCS1;
#endif

  /* Disable clocks                                                           */
  PMC->PMC_PCDR    |= (1 << ID_PIOA);
  PMC->PMC_PCDR    |= (1 << ID_PIOB);
  PMC->PMC_PCDR    |= (1 << ID_SPI0);

  /* Leave PIOC enabled as SDRAM is connected to it                           */

  return (OK);
}


/*- GetPageSize_HW (...) -------------------------------------------------------
 *
 *  Get Size of Page
 *    Parameter:
 *    Return Value:           page size in bytes
 */

int GetPageSize_HW (void) {

  return (PAGE_SIZE);
}


/*- EraseBlock_HW (...) ---------------------------------------------------------
 *
 *  Erase a Block
 *    Parameter:        adr:  Block Start Address
 *    Return Value:           ERROR code
 */

int EraseBlock_HW (unsigned long adr) {

  // Enable critical write operation
  SendCommandDF(AT25_WRITE_ENABLE, 1, 0, 0, 0);

  if (SendCommandDF(AT25_BLOCK_ERASE_64K, 4, adr, 0, 0) != OK)
    return (ERROR_ERASE);

  // Wait for operation to finish
  do { SendCommandDF(AT25_READ_STATUS, 1, 0, &status, 1); }  while ((status & AT25_STATUS_RDYBSY));

  return (OK);
}


/*- EraseChip_HW (...) ---------------------------------------------------------
 *
 *  Erase Full Flash Memory
 *    Parameter:
 *    Return Value:           ERROR code
 */

int EraseChip_HW (void) {

  unsigned long i;

  for (i = 0; i < CHIP_SIZE; i += BLOCK_SIZE) {
    if (SendCommandDF(AT25_BLOCK_ERASE_64K, 4, i, 0, 0) != OK)
      return (ERROR_ERASE);

  // Wait for DataFlash to become ready
  do { SendCommandDF(AT25_READ_STATUS, 1, 0, &status, 1); }  while ((status & AT25_STATUS_RDYBSY));
  }

  return (OK);
}


/*- ReadPage_HW (...) ----------------------------------------------------------
 *
 *  Initialize Flash Programming Functions
 *    Parameter:        adr:  Page Start Address
 *                       sz:  Page Size
 *                      buf:  Page Data
 *    Return Value:           ERROR code
 */

int ReadPage_HW (unsigned long adr, unsigned long sz, unsigned char *buf) {

  if (SendCommandDF(AT25_READ_ARRAY_LF, 4, adr, buf, sz) != OK)
    return (ERROR_READ);

  // Wait for DataFlash to become ready
  do { SendCommandDF(AT25_READ_STATUS, 1, 0, &status, 1); }  while ((status & AT25_STATUS_RDYBSY));

  return (OK);
}


/*- ProgramPage_HW (...) -------------------------------------------------------
 *
 *  Initialize Flash Programming Functions
 *    Parameter:        adr:  Page Start Address
 *                       sz:  Page Size
 *                      buf:  Page Data
 *    Return Value:           ERROR code
 */

int ProgramPage_HW (unsigned long adr, unsigned long sz, unsigned char *buf) {

  if (SendCommandDF(AT25_WRITE_ENABLE, 1, 0, 0, 0) != OK)
    return (ERROR_WRITE);

  // Write Buf1 to DataFlash
  if (SendCommandDF(AT25_BYTE_PAGE_PROGRAM, 4, adr, buf, PAGE_SIZE) != OK)
    return (ERROR_WRITE);

  // Wait for DataFlash to become ready
  do { SendCommandDF(AT25_READ_STATUS, 1, 0, &status, 1); }  while ((status & AT25_STATUS_RDYBSY));

  // Wait for DataFlash to become ready
  do { SendCommandDF(AT25_READ_STATUS, 1, 0, &status, 1); }  while ((status & AT25_STATUS_RDYBSY));
  if ((status & AT25_STATUS_EPE)) return(ERROR_WRITE);

  return (OK);
}


/*- CheckBlock_HW (...) --------------------------------------------------------
 *
 *  Check if block at requested address is valid
 *    Parameter:        adr:  Block Start Address
 *    Return Value:           ERROR code
 */

int CheckBlock_HW (unsigned long adr) {

  return (ERROR_NOT_IMPLEMENTED);
}


/*- MarkBlockBad_HW (...) ------------------------------------------------------
 *
 *  Mark the block as being bad
 *    Parameter:        adr:  Block Start Address
 *    Return Value:           ERROR code
 */

int MarkBlockBad_HW (unsigned long adr) {

  return (ERROR_NOT_IMPLEMENTED);
}


/**************************** Auxiliary Functions ******************************/

/*- SwapU32 (...) --------------------------------------------------------------
 *
 *  Swap big <-> little-endian for 32 bit value
 *    Parameter:
 *    Return Value:           swapped value
 */

static unsigned long SwapU32(unsigned long to_swap)
{
  const unsigned long mask = 0x00FF00FF;
  unsigned long temp;

  __asm {
    AND temp,    mask,    to_swap
    AND to_swap, mask,    to_swap, ROR #24
    ORR to_swap, to_swap, temp,    ROR #8
  }

  return (to_swap);
} 


/*- SPI_Read (...) --------------------------------------------------------
 *  Reads and returns the last word of data received by a SPI peripheral.
 *    Parameter:        
 *    Return Value:   readed data
 */
static unsigned int SPI_Read(void)
{
    while ( (SPI0->SPI_SR & SPI_SR_RDRF) == 0 ) ;

    return SPI0->SPI_RDR & 0xFFFF ;
}

/*- SPI_Write (...) --------------------------------------------------------
 * Sends data through a SPI peripheral. If the SPI is configured to use a fixed
 * \param data  Word of data to send.
 */
static void SPI_Write(uint32_t dwNpcs, uint16_t wData )
{
    /* Send data */
    while ( (SPI0->SPI_SR & SPI_SR_TXEMPTY) == 0 ) ;
    SPI0->SPI_TDR = wData | SPI_PCS( dwNpcs ) ;
    while ( (SPI0->SPI_SR & SPI_SR_TDRE) == 0 ) ;
}

/*- SendCommandDF (...) --------------------------------------------------------
 *
 *  Send command to DataFlash
 *    Parameter:        cmd:  Command to be Sent
 *                   cmd_sz:  Command Size (in bytes)
 *                      adr:  Address in DataFlash
 *                      buf:  Data to be Sent (or Received)
 *                       sz:  Size of Data
 *    Return Value:           ERROR code
 */

static int SendCommandDF (unsigned char cmd, unsigned char cmd_sz, unsigned long adr, unsigned char *buf, unsigned long sz) {

  int i;
  unsigned char * cmdPtr;

  command = (SwapU32(adr) & 0xFFFFFF00) | cmd;
  
  SPI0->SPI_MR |= SPI_MR_PCS_Msk ;
  SPI0->SPI_MR &= ~(((1 << 16) & SPI_MR_PCS_Msk)) ;
  SPI0->SPI_CR =  SPI_CR_SPIEN;

  cmdPtr = (unsigned char *)&command;
  /* Transfer command */
  for (i = 0; i < cmd_sz; i ++)
  {
    SPI_Write( 0, (*cmdPtr++));
    SPI_Read();
  }
  /* Transfer data */
  for (i = 0; i < sz; i ++)
  {
    SPI_Write(0, buf[i]);
    buf[i] = SPI_Read();
  }
  SPI0->SPI_CR = SPI_CR_LASTXFER ;
  return (OK);
}


/*******************************************************************************/
