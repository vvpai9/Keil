/******************************************************************************/
/* IAP In-System Application Programming Demo                                 */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <LPC21xx.H>


// Clock Frequency

#define XTAL    12000000                   // Oscillator Frequency

#ifdef BYPASS_PLL
#define CPUCLK  XTAL                       // CPU Clock without PLL
#else
#define CPUCLK (XTAL*5)                    // CPU Clock with PLL
#endif

#define CCLK   (CPUCLK / 1000)             // CPU Clock in kHz


// Phase Locked Loop (PLL) definitions
#define PLL_BASE        0xE01FC080         // PLL Base Address 
#define PLLCON_OFS      0x00               // PLL Control Offset
#define PLLSTAT_OFS     0x08               // PLL Status Offset 
#define PLLFEED_OFS     0x0C               // PLL Feed Offset 
#define PLLCON_PLLE     0x01               // PLL Enable 
#define PLLCON_PLLD     0x00               // PLL Disable
#define PLLCON_PLLC     0x03               // PLL Connect
#define PLLSTAT_PLOCK   0x0400             // PLL Lock Status


struct iap_in {
  unsigned int cmd;
  unsigned int par[4];  
};

typedef void (*IAP)(struct iap_in *in, unsigned int *result);
#define iap_entry ((IAP) 0x7FFFFFF1)       // IAP Entry Point


/* Default Interrupt Function: may be called when interrupts are disabled */
void def_isr (void) __irq  {
 ;
}


#ifdef BYPASS_PLL

/* 
 * PLL Feed Sequence
 */
void feed_pll (void) {
  unsigned int adr, r1, r2;

  adr = PLL_BASE;
  __asm {
    MOV     r1, #0xAA
    MOV     r2, #0x55
    STR     r1, [adr, #PLLFEED_OFS]
    STR     r2, [adr, #PLLFEED_OFS]
  }
}

/*
 * Switch CPU to PLL clock
 */
void start_pll (void) {

  PLLCON = PLLCON_PLLE;
  feed_pll();
  while ((PLLSTAT & PLLSTAT_PLOCK) == 0);
  PLLCON = PLLCON_PLLC;
  feed_pll();
}

/*
 * Switch CPU to standard XTAL
 */
void stop_pll(void) {

  PLLCON = PLLCON_PLLD;
  feed_pll();
}

#endif


/*
 * Convert 'addr' to Sector Number
 */
unsigned int get_secnum (unsigned int addr) {
  unsigned int n;

  n = ((unsigned int) addr >> 13) & 0x1F;  // Pseudo Sector Number

  if (n >= (0x30000 >> 13))  {
    n -= 14;                               // High Small 8kB Sectors
  }
  else if (n >= (0x10000 >> 13))  {
    n  = 7 + (n >> 3);                     // Large 64kB Sectors
  }
  return (n);                              // Sector Number
}


/*
 * Erase Sector between 'start' and 'end'
 * Return: IAP Error Code (0 when OK)
 */
unsigned int erase (unsigned int start, unsigned int end) {
  struct iap_in iap;                       // IAP Input Parameters
  unsigned int  result[16];                // IAP Results
  unsigned int  save_VicInt;               // for saving VICIntEnable

  save_VicInt = VICIntEnable;              // Save Interrupt Enable Status
  VICIntEnClr = 0xFFFFFFFF;                // Disable all Interrupts

#ifdef BYPASS_PLL
  stop_pll();                              // IAP requires to run without PLL
#endif

  iap.cmd = 50;                            // IAP Command: Prepare Sectors for Write
  iap.par[0] = get_secnum (start);         // Start Sector
  iap.par[1] = get_secnum (end);           // End Sector
  iap_entry (&iap, result);                // Call IAP Function
  if (result[0]) goto exit;                // Error occured?

  iap.cmd = 52;                            // IAP Command: Erase Flash
  iap.par[0] = get_secnum (start);         // Start Sector
  iap.par[1] = get_secnum (end);           // End Sector
  iap.par[2] = CCLK;                       // CPU Clock
  iap_entry (&iap, result);                // Call IAP Function

exit:

#ifdef BYPASS_PLL
  start_pll();                             // Start PLL
#endif

  VICIntEnable = save_VicInt;              // Restore Interrupt Enable Status

  return (result[0]);
}


/*
 * Program *data to addr, number of bytes specified by size
 * Return: IAP Error Code (0 when OK)
 * NOTES:  size should be 512, 1024, 4096 or 8192
 */
unsigned int program (unsigned int addr, unsigned char *data, unsigned int size) {
  struct iap_in iap;                       // IAP Input Parameters
  unsigned int  result[16];                // IAP Results
  unsigned int  save_VicInt;               // for saving VICIntEnable

  save_VicInt = VICIntEnable;              // Save Interrupt Enable Status
  VICIntEnClr = 0xFFFFFFFF;                // Disable all Interrupts

#ifdef BYPASS_PLL
  stop_pll();                              // IAP requires to run without PLL
#endif

  iap.cmd = 50;                            // IAP Command: Prepare Sectors for Write
  iap.par[0] = get_secnum (addr);         // Start Sector
  iap.par[1] = iap.par[0];                 // End Sector
  iap_entry (&iap, result);                // Call IAP Function
  if (result[0]) goto exit;                // Error occured?

  iap.cmd = 51;                            // IAP Command: Copy RAM to Flash
  iap.par[0] = addr;                       // Destination Address
  iap.par[1] = (unsigned int) data;        // Source Address
  iap.par[2] = size;                       // Number of Bytes
  iap.par[3] = CCLK;                       // CPU Clock
  iap_entry (&iap, result);                // Call IAP Function

exit:

#ifdef BYPASS_PLL
  start_pll();                             // Start PLL
#endif

  VICIntEnable = save_VicInt;              // Restore Interrupt Enable Status

  return (result[0]);
}


unsigned char vals[512];


void main (void)  {
  unsigned int i;

  unsigned int volatile start;

  for (start = 0; start < 1000000; start++) {
    ;  // wait for debugger connection (about 0.3 sec)
  }

  VICDefVectAddr = (unsigned int) def_isr; // for Spurious Interrupts

  for (i = 0; i < sizeof (vals); i++)  {
    vals[i] = (unsigned char) i;
  }

  erase   (0x30000, 0x33FFF);
  program (0x30000, vals, sizeof (vals));
  program (0x31000, vals, sizeof (vals));
  program (0x32000, vals, sizeof (vals));
  erase   (0x30000, 0x31FFF);
  erase   (0x32000, 0x33FFF);

  while (1);
}
