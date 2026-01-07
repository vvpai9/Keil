/******************************************************************************/
/* :   Include file for Hardware Layer Flash Programming functions  */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2012 Keil Software. All rights reserved.                     */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/
#include <AT91SAM9X35.H>

#include "Error.h"                      // Error definitions
#define SYS_CLOCK    64500000           // System Clock (in Hz)
#define SPI_CLOCK    1000000            // Expected SPI clock speed (in Hz)

#define SPI_PCS0_DF  0x0E               // Chip Select 0 : NPCS0 %1110
#define SPI_PCS1_DF  0x0D               // Chip Select 1 : NPCS1 %1101
#define SPI_PCS2_DF  0x0B               // Chip Select 2 : NPCS2 %1011
#define SPI_PCS3_DF  0x07               // Chip Select 3 : NPCS3 %0111

// ----------------- Page Size  528, CS0 used ----------------------------------

#ifdef P528_CS0
 #define PAGE_SIZE    528                // Size of page
 #define ADDR_BITS    10                 // Bits for addressing inside page
 #define CHIP_SIZE    0x420000           // Chip size (in bytes)
 #define SPI_PCS_DF   SPI_PCS0_DF
 #define CS_INDEX     0
 #define BLOCK_SIZE   0x4200             // Block size (used for erase)
#endif



// READ COMMANDS
#define DB_CONTINUOUS_ARRAY_READ  0xE8  // Continuous array read
#define DB_BURST_ARRAY_READ       0xE8  // Burst array read
#define DB_PAGE_READ              0xD2  // Main memory page read
#define DB_BUF1_READ              0xD4  // Buffer 1 read
#define DB_BUF2_READ              0xD6  // Buffer 2 read
#define DB_STATUS                 0xD7  // Status Register

// PROGRAM and ERASE COMMANDS
#define DB_PAGE_WRITE_BUF1        0x82
#define DB_BUF1_WRITE             0x84  // Buffer 1 write
#define DB_BUF2_WRITE             0x87  // Buffer 2 write
#define DB_BUF1_PAGE_ERS_PGM      0x83  // Buf 1 to main mem page prg w built-In erase               
#define DB_BUF1_PAGE_ERS_FASTPGM  0x93  // Buf 1 to main mem page prg w built-In erase, Fast program 
#define DB_BUF2_PAGE_ERS_PGM      0x86  // Buf 2 to main mem page prg w built-In erase               
#define DB_BUF2_PAGE_ERS_FASTPGM  0x96  // Buf 2 to main mem page prg w built-In erase, Fast program 
#define DB_BUF1_PAGE_PGM          0x88  // Buf 1 to main mem page prg wo built-In erase              
#define DB_BUF1_PAGE_FASTPGM      0x98  // Buf 1 to main mem page prg wo built-In erase, Fast program
#define DB_BUF2_PAGE_PGM          0x89  // Buf 2 to main mem page prg wo built-In erase              
#define DB_BUF2_PAGE_FASTPGM      0x99  // Buf 2 to main mem page prg wo built-In erase, Fast program
#define DB_PAGE_ERASE             0x81  // Page Erase                    
#define DB_BLOCK_ERASE            0x50  // Block Erase                   
#define DB_PAGE_PGM_BUF1          0x82  // Main mem page thru buf 1      
#define DB_PAGE_FASTPGM_BUF1      0x92  // Main mem page thru buf 1, Fast
#define DB_PAGE_PGM_BUF2          0x85  // Main mem page thru buf 2      
#define DB_PAGE_FastPGM_BUF2      0x95  // Main mem page thru buf 2, Fast

// ADDITIONAL COMMANDS
#define DB_PAGE_2_BUF1_TRF        0x53  // Main mem page to buf 1 transfer
#define DB_PAGE_2_BUF2_TRF        0x55  // Main mem page to buf 2 transfer
#define DB_PAGE_2_BUF1_CMP        0x60  // Main mem page to buf 1 compare
#define DB_PAGE_2_BUF2_CMP        0x61  // Main mem page to buf 2 compare
#define DB_AUTO_PAGE_PGM_BUF1     0x58  // Auto page rewrite thru buf 1
#define DB_AUTO_PAGE_PGM_BUF2     0x59  // Auto page rewrite thru buf 2

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


static unsigned int    command[2];         // Command for DataFlash
static unsigned char    status;            // Status of Data Flash

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
  do { SendCommandDF(DB_STATUS, 1, 0, (unsigned char *)&status, 1); }  while (!(status & 0x80));
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

  if (SendCommandDF(DB_BLOCK_ERASE, 4, adr, 0, 0) != OK)
    return (ERROR_ERASE);

  // Wait for operation to finish
  do { SendCommandDF(DB_STATUS, 1, 0, (unsigned char *)&status, 1); }  while (!(status & 0x80));

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

  // Because Chip Erase Command (0xC7) in documentation is said not to 
  // be reliable on some chips, chip is erased with multiply Block Erase 
  // Commands (0x50)

  for (i = 0; i < CHIP_SIZE; i += BLOCK_SIZE) {
    if (SendCommandDF(DB_BLOCK_ERASE, 4, i, 0, 0) != OK)
      return (ERROR_ERASE);

    // Wait for operation to finish
    do { SendCommandDF(DB_STATUS, 1, 0, (unsigned char *)&status, 1); }  while (!(status & 0x80));
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

  if (SendCommandDF(DB_CONTINUOUS_ARRAY_READ, 8, adr, buf, sz) != OK)
    return (ERROR_READ);

  // Wait for operation to finish
  do { SendCommandDF(DB_STATUS, 1, 0, (unsigned char *)&status, 1); }  while (!(status & 0x80));

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

  unsigned int i;

  // Clear (0xFF) rest of a page if not full page is requested for program 
  // because always a whole page must be programmed
  if (sz < PAGE_SIZE) 
    for (i = sz; i < PAGE_SIZE; i++)
      buf[i] = 0xFF;

  // Write Data to Buf1
  if (SendCommandDF(DB_PAGE_WRITE_BUF1, 4, adr, buf, PAGE_SIZE) != OK)
    return (ERROR_WRITE);

  // Wait for operation to finish
  do { SendCommandDF(DB_STATUS, 1, 0, (unsigned char *)&status, 1); }  while (!(status & 0x80));

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


  adr = ((adr / (PAGE_SIZE)) << ADDR_BITS) + (adr % (PAGE_SIZE));
  command[0]                  = (SwapU32(adr) & 0xFFFFFF00) | cmd;
  command[1]                  = 0;
  
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
