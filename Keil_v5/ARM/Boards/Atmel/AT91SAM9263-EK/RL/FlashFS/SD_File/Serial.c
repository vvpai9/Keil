/*----------------------------------------------------------------------------
 *      RL-ARM - FlashFS
 *----------------------------------------------------------------------------
 *      Name:    SERIAL.C
 *      Purpose: Serial Input Output for Atmel AT91SAM9263
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <AT91SAM9263.H>

#define MCK_CLOCK         100024589           /* Master clock frequency      */
#define BAUDRATE          115200              /* UART Baudrate               */

/*----------------------------------------------------------------------------
 *       init_serial:  Initialize Serial Interface
 *---------------------------------------------------------------------------*/
void init_serial (void) {
  /* Initialize the serial interface */

  /* Configure Debug Unit pins (PC30 and PC31). */
  AT91C_BASE_PMC->PMC_PCER    = (1 << AT91C_ID_PIOCDE);
  AT91C_BASE_PIOC->PIO_IDR    = AT91C_PC30_DRXD | AT91C_PC31_DTXD;
  AT91C_BASE_PIOC->PIO_PPUDR  = AT91C_PC30_DRXD | AT91C_PC31_DTXD;
  AT91C_BASE_PIOC->PIO_ASR    = AT91C_PC30_DRXD | AT91C_PC31_DTXD;
  AT91C_BASE_PIOC->PIO_PDR    = AT91C_PC30_DRXD | AT91C_PC31_DTXD;

  /* Configure Debug Unit for 115200 baud, no parity. */
  AT91C_BASE_DBGU->DBGU_CR    = AT91C_US_RSTTX | AT91C_US_RSTRX;
  AT91C_BASE_DBGU->DBGU_IDR   = 0xFFFFFFFF;
  AT91C_BASE_DBGU->DBGU_BRGR  = ((MCK_CLOCK + 8*BAUDRATE)/(16*BAUDRATE));
  AT91C_BASE_DBGU->DBGU_MR    = AT91C_US_PAR_NONE;
  AT91C_BASE_DBGU->DBGU_CR    = AT91C_US_TXEN  | AT91C_US_RXEN;
}

/*----------------------------------------------------------------------------
 *       sendchar:  Write a character to Serial Port
 *---------------------------------------------------------------------------*/
int sendchar (int ch) {
  if (ch == '\n')  {
    while (!(AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_TXEMPTY));
    AT91C_BASE_DBGU->DBGU_THR = '\r';        /* output CR                    */
  }
  while (!(AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_TXEMPTY));
  AT91C_BASE_DBGU->DBGU_THR = ch;
  return (ch);
}

/*----------------------------------------------------------------------------
 *       getkey:  Read a character from Serial Port
 *---------------------------------------------------------------------------*/
int getkey (void) {
  while (!(AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_RXRDY));
  return (AT91C_BASE_DBGU->DBGU_RHR);
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
