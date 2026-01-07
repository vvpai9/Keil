/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright (c) 2006-2011 Keil - An ARM Company.                            */
/*  All rights reserved.                                                      */
/******************************************************************************/
/*                                                                            */
/*  FlashDev.C:  Flash Programming Functions adapted for NXP LPC29xx          */
/*                                                                            */
/******************************************************************************/

#include "..\FlashOS.H"                        // FlashOS Structures

typedef volatile unsigned long    vu32;
typedef          unsigned long     u32;

#define M32(adr)     (*((vu32 *) (adr)))

// Flash Memory Map
#define FLASH_BASE        (0x20000000)         // Flash Base Address

// Peripheral Memory Map
#define CGU_BASE          (0xFFFF8000)
#define FMC_BASE          (0x20200000)

#define CGU               ((CGU_TypeDef *) CGU_BASE)
#define FMC               ((FMC_TypeDef *) FMC_BASE)


// Clock Generation Unit (CGU) Registers
typedef struct {
  vu32 RESERVED0[5];
  vu32 FREQ_MON;             // offset 0x014 R/W  Frequency monitor register
  vu32 RDET;                 // offset 0x018 R/   Clock detection register
  vu32 XTAL_OSC_STATUS;      // offset 0x01C R/   Crystal-oscillator status register
  vu32 XTAL_OSC_CONTROL;     // offset 0x020 R/W  Crystal-oscillator control register
  vu32 PLL_STATUS;           // offset 0x024 R/   PLL status register
  vu32 PLL_CONTROL;          // offset 0x028 R/W  PLL control register
  vu32 FDIV_STATUS_0;        // offset 0x02C R/   FDIV 0 frequency-divider status register
  vu32 FDIV_CONF_0;          // offset 0x030 R/W  FDIV 0 frequency-divider control register
  vu32 FDIV_STATUS_1;        // offset 0x034 R/   FDIV 1 frequency-divider status register
  vu32 FDIV_CONF_1;          // offset 0x038 R/W  FDIV 1 frequency-divider control register
  vu32 FDIV_STATUS_2;        // offset 0x03C R/   FDIV 2 frequency-divider status register
  vu32 FDIV_CONF_2;          // offset 0x040 R/W  FDIV 2 frequency-divider control register
  vu32 FDIV_STATUS_3;        // offset 0x044 R/   FDIV 3 frequency-divider status register
  vu32 FDIV_CONF_3;          // offset 0x048 R/W  FDIV 3 frequency-divider control register
  vu32 FDIV_STATUS_4;        // offset 0x04C R/   FDIV 4 frequency-divider status register
  vu32 FDIV_CONF_4;          // offset 0x050 R/W  FDIV 4 frequency-divider control register
  vu32 FDIV_STATUS_5;        // offset 0x054 R/   FDIV 5 frequency-divider status register
  vu32 FDIV_CONF_5;          // offset 0x058 R/W  FDIV 5 frequency-divider control register
  vu32 FDIV_STATUS_6;        // offset 0x05C R/   FDIV 6 frequency-divider status register
  vu32 FDIV_CONF_6;          // offset 0x060 R/W  FDIV 6 frequency-divider control register
  vu32 SAFE_CLK_STATUS;      // offset 0x064 R/   Output-clock status register for BASE_SAFE_CLK
  vu32 SAFE_CLK_CONF;        // offset 0x068 R/W  Output-clock configuration register for BASE_SAFE_CLK
  vu32 SYS_CLK_STATUS;       // offset 0x06C R/   Output-clock status register for BASE_SYS_CLK
  vu32 SYS_CLK_CONF;         // offset 0x070 R/W  Output-clock configuration register for BASE_SYS_CLK
  vu32 PCR_CLK_STATUS;       // offset 0x074 R/   Output-clock status register for BASE_PCR_CLK
  vu32 PCR_CLK_CONF;         // offset 0x078 R/W  Output-clock configuration register for BASE_PCR_CLK
  vu32 IVNSS_CLK_STATUS;     // offset 0x07C R/   Output-clock status register for BASE_IVNSS_CLK
  vu32 IVNSS_CLK_CONF;       // offset 0x080 R/W  Output-clock configuration register for BASE_IVNSS_CLK
  vu32 MSCSS_CLK_STATUS;     // offset 0x084 R/   Output-clock status register for BASE_MSCSS_CLK
  vu32 MSCSS_CLK_CONF;       // offset 0x088 R/W  Output-clock configuration register for BASE_MSCSS_CLK
  vu32 ICLK0_CLK_STATUS;     // offset 0x08C R/   Output-clock status register for BASE_ICLK0_CLK
  vu32 ICLK0_CLK_CONF;       // offset 0x090 R/W  Output-clock configuration register for BASE_ICLK0_CLK
  vu32 UART_CLK_STATUS;      // offset 0x094 R/   Output-clock status register for BASE_UART_CLK
  vu32 UART_CLK_CONF;        // offset 0x098 R/W  Output-clock configuration register for BASE_UART_CLK
  vu32 SPI_CLK_STATUS;       // offset 0x09C R/   Output-clock status register for BASE_SPI_CLK
  vu32 SPI_CLK_CONF;         // offset 0x0A0 R/W  Output-clock configuration register for BASE_SPI_CLK
  vu32 TMR_CLK_STATUS;       // offset 0x0A4 R/   Output-clock status register for BASE_TMR_CLK
  vu32 TMR_CLK_CONF;         // offset 0x0A8 R/W  Output-clock configuration register for BASE_TMR_CLK
  vu32 ADC_CLK_STATUS;       // offset 0x0AC R/   Output-clock status register for BASE_ADC_CLK
  vu32 ADC_CLK_CONF;         // offset 0x0B0 R/W  Output-clock configuration register for BASE_ADC_CLK
  vu32 RESERVED1[2];
  vu32 ICLK1_CLK_STATUS;     // offset 0x0BC R/   Output-clock status register for BASE_ICLK1_CLK
  vu32 ICLK1_CLK_CONF;       // offset 0x0C0 R/W  Output-clock configuration register for BASE_ICLK1_CLK
  vu32 RESERVED2[965];
  vu32 INT_CLR_ENABLE;       // offset 0xFD8  /W  Interrupt clear-enable register
  vu32 INT_SET_ENABLE;       // offset 0xFDC  /W  Interrupt set-enable register
  vu32 INT_STATUS;           // offset 0xFE0 R/   Interrupt status register
  vu32 INT_ENABLE;           // offset 0xFE4 R/   interrupt enable register
  vu32 INT_CLR_STATUS;       // offset 0xFE8  /W  Interrupt clear-status register
  vu32 INT_SET_STATUS;       // offset 0xFEC  /W  Interrupt set-status register
  vu32 RESERVED3[1];
  vu32 BUS_DISABLE;          // offset R/W 0xFF4 Bus disable register
} CGU_TypeDef;

// FLASH Memory Controller (FMC) Registers
typedef struct {
  vu32 FCTR;                 // offset 0x000 R/W  Flash control register
  vu32 RESERVED0[1];
  vu32 FPTR;                 // offset 0x008 R/W  Flash program-time register
  vu32 FTCTR;                // offset 0x00C R/W  Flash test control register
  vu32 FBWST;                // offset 0x010 R/W  Flash bridge wait-state register
  vu32 RESERVED1[2];
  vu32 FCRA;                 // offset 0x01C R/W  Flash clock divider register
  vu32 FMSSTART;             // offset 0x020 R/W  Flash Built-In Self Test (BIST) start-address register
  vu32 FMSSTOP;              // offset 0x024 R/W  Flash BIST stop-address register
  vu32 FMS16;                // offset 0x028 R/   Flash 16-bit signature register
  vu32 FMSW0;                // offset 0x02C R/   Flash 128-bit signature Word 0 register
  vu32 FMSW1;                // offset 0x030 R/   Flash 128-bit signature Word 1 register
  vu32 FMSW2;                // offset 0x034 R/   Flash 128-bit signature Word 2 register
  vu32 FMSW3;                // offset 0x038 R/   Flash 128-bit signature Word 3 register
  vu32 RESERVED2[17];
  // EEPROM registers
  vu32 EECMD;                // offset 0x080 R/W  EEPROM command register
  vu32 EEADDR;               // offset 0x084 R/W  EEPROM address register
  vu32 EEWDATA;              // offset 0x088  /W  EEPROM write data register
  vu32 EERDATA;              // offset 0x08C R/   EEPROM read data register
  vu32 EEWSTATE;             // offset 0x090 R/W  EEPROM wait state register
  vu32 EECLKDIV;             // offset 0x094 R/W  EEPROM clock divider register
  vu32 EEPWRDWN;             // offset 0x098 R/W  EEPROM power-down/start register
  vu32 EEMSSTART;            // offset 0x09C R/W  EEPROM BIST start address register
  vu32 EEMSSTOP;             // offset 0x0A0 R/W  EEPROM BIST stop address register
  vu32 EEMSSIG;              // offset 0x0A4 R/   EEPROM 24-bit BIST signature register
  vu32 RESERVED3[972];
  // Registers shared by flash and EEPROM
  vu32 INT_CLR_ENABLE;       // offset 0xFD8  /W  Flash/EEPROM interrupt clear- enable register
  vu32 INT_SET_ENABLE;       // offset 0xFDC  /W  Flash/EEPROM interrupt set- enable register
  vu32 INT_STATUS;           // offset 0xFE0 R/   Flash/EEPROM interrupt status register
  vu32 INT_ENABLE;           // offset 0xFE4 R/   Flash/EEPROM interrupt enable register
  vu32 INT_CLR_STATUS;       // offset 0xFE8  /W  Flash/EEPROM interrupt clear-status register
  vu32 INT_SET_STATUS;       // offset 0xFEC  /W  Flash/EEPROM interrupt set-status register
} FMC_TypeDef;

#define   FS_LOADREQ         (1 << 15)
#define   FS_PROGREQ         (1 << 12)
#define   FS_PDL             (1 << 10)
#define   FS_PD              (1 <<  9)
#define   FS_WPB             (1 <<  7)
#define   FS_DCR             (1 <<  4)
#define   FS_WEB             (1 <<  2)
#define   FS_WRE             (1 <<  1)
#define   FS_CS              (1 <<  0)



/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {
  int i;

  // clk is the ext. oscillator frequenzy configured in uVision Target settings

  // Setup clock to use crystal oscillator
  CGU->SYS_CLK_CONF = ((1UL << 24)  );       // select Crystal oscillator

#if 0  // skip PLL configuration. Needs to be checked if crystal is 20MHz!
  CGU->PLL_CONTROL  = ((1UL <<  2) |         // P23EN
                       (1UL <<  0)  );       // Power Down Mode
  CGU->PLL_CONTROL  = ((1UL << 24) |         // select Crystal oscillator 
                       (15  << 16) |         // Feedback-divider division ratio (M) = 15
                       (0   <<  8) |         // Post-divider division ratio (2P) = 0
                       (1UL <<  2) |         // P23EN
                       (1UL <<  0)  );       // Power Down Mode
  CGU->PLL_CONTROL  = ((1UL << 24) |         // select Crystal oscillator 
                       (15  << 16) |         // Feedback-divider division ratio (M) = 15
                       (0   <<  8) |         // Post-divider division ratio (2P) = 0
                       (1UL <<  2)  );       // P23EN
  while (!(CGU->PLL_STATUS & (1UL <<  0)));  // Wait for PLL Lock
  while (!(CGU->RDET       & (1UL <<  2)));  // Wait for Clock Present
  CGU->SYS_CLK_CONF = ((2UL << 24) |         // select PLL
                       (1UL << 11) |         // AUTOBLOK
                       (1UL <<  2)  );       // IDIV = 1 -> clk / 2
#endif

  FMC->FCTR         = FS_CS + FS_DCR + FS_WPB;
  FMC->FBWST        = ((1UL << 15) |         // Second buffer line is enabled
                       (1UL << 14) |         // Speculative reading is always performed
                       (4UL <<  0)  );       // 4 wait states
  FMC->FCRA         = ((clk/3)/66000)-1;     // clk is the core frequency

  // Unprotect all sectors
  for (i = 0; i < 0x10000; i += 0x2000) {
    M32(i+FLASH_BASE)  = 2;
    FMC->FCTR          = FS_CS + FS_WRE + FS_WEB + FS_DCR + FS_WPB + FS_LOADREQ;
  }

#ifdef SIZE_128kB
  for (i = 0x10000; i < 0x20000; i += 0x10000) {
    M32(i+FLASH_BASE)  = 2;
    FMC->FCTR          = FS_CS + FS_WRE + FS_WEB + FS_DCR + FS_WPB + FS_LOADREQ;
  }
#elif SIZE_256kB
  for (i = 0x10000; i < 0x40000; i += 0x10000) {
    M32(i+FLASH_BASE)  = 2;
    FMC->FCTR          = FS_CS + FS_WRE + FS_WEB + FS_DCR + FS_WPB + FS_LOADREQ;
  }
#elif SIZE_512kB
  for (i = 0x10000; i < 0x80000; i += 0x10000) {
    M32(i+FLASH_BASE)  = 2;
    FMC->FCTR          = FS_CS + FS_WRE + FS_WEB + FS_DCR + FS_WPB + FS_LOADREQ;
  }
#elif  SIZE_768kB
  for (i = 0x10000; i < 0xC0000; i += 0x10000) {
    M32(i+FLASH_BASE)  = 2;
    FMC->FCTR          = FS_CS + FS_WRE + FS_WEB + FS_DCR + FS_WPB + FS_LOADREQ;
  }
#endif

  return (0);   // Success
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {
  return (0);
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {

  FMC->INT_CLR_STATUS = 0x01;                // Clear End of Erase flag

  // Start erase procedure
  M32(adr)  = 0;
  FMC->FCTR = FS_CS +          FS_WEB + FS_DCR + FS_WPB + FS_LOADREQ;

  // Set Erase Timer value
  FMC->FPTR = ((105 * 80000) / 512) | (1 << 15);
  
  // Triger sector erase
  FMC->FCTR = FS_CS +                 + FS_DCR + FS_WPB + FS_PROGREQ;

  while (!(FMC->INT_STATUS & 0x01));         // Wait for erase to finish

  return (0);   // Success
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {

  unsigned char rest, sz_add;

  FMC->INT_CLR_STATUS = 0x02;          // Clear End of Burn flag

  // Preset data latches
  FMC->FCTR = FS_CS + FS_WRE + FS_WEB + FS_DCR + FS_PDL;
  FMC->FCTR = FS_CS + FS_WRE + FS_WEB + FS_DCR;

  if (sz >= 512) {
    rest   = 0;
    sz_add = 0;
    sz     = 512;
  }  else {
    rest   = sz & 0x03;
    sz_add = (16 - (sz & 0x0F)) >> 2;
    sz    -= rest;
  }

  // Load whole words to data latches
  while (sz) {
    M32(adr) = *((unsigned long *)buf);
    adr += 4;
    buf += 4;
    sz  -= 4;
  }

  // Load remaining word to data latches (if rest != 0)
  if (rest != 0) {
    M32(adr) = *((unsigned long *)buf) | (0xFFFFFFFF << (rest << 3));
    adr     += 4;
  }

  // Load additional words if number of loaded words is not a round number of 4 words
  while (sz_add--) {
    M32(adr) = 0xFFFFFFFF;
    adr     += 4;
  }

  // Set Program Timer value
  FMC->FPTR = ((105 * 800) / 512) | (1 << 15);

  // Triger programming
  FMC->FCTR = FS_CS + FS_WRE +          FS_DCR + FS_WPB + FS_PROGREQ;

  while (!(FMC->INT_STATUS & 0x02));     // Wait for burn to finish

  return (0);   // Success
}
