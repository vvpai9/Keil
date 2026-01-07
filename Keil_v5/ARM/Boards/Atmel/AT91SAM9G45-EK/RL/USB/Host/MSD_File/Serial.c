/*------------------------------------------------------------------------------
 *      RL-ARM
 *------------------------------------------------------------------------------
 *      Name:    Serial.c
 *      Purpose: Serial Input Output for Atmel AT91SAM9G20
 *------------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <AT91SAM9G45.H>
#include "Serial.h"

#define MCK_CLOCK         133333333           /* Master clock frequency      */
#define BAUDRATE          115200              /* UART Baudrate               */

/*------------------------------------------------------------------------------
 *       SER_Init:  Initialize Serial Interface
 *----------------------------------------------------------------------------*/

void SER_Init (void) {

  /* Configure Debug Unit pins (PB12 and PB13). */
  AT91C_BASE_PMC->PMC_PCER   |= (1 << AT91C_ID_PIOB);
  AT91C_BASE_PIOB->PIO_IDR    = AT91C_PB12_DRXD | AT91C_PB13_DTXD;
  AT91C_BASE_PIOB->PIO_PPUDR  = AT91C_PB12_DRXD | AT91C_PB13_DTXD;
  AT91C_BASE_PIOB->PIO_ASR    = AT91C_PB12_DRXD | AT91C_PB13_DTXD;
  AT91C_BASE_PIOB->PIO_PDR    = AT91C_PB12_DRXD | AT91C_PB13_DTXD;

  /* Configure Debug Unit for 115200 baud, no parity. */
  AT91C_BASE_DBGU->DBGU_CR    = AT91C_US_RSTTX | AT91C_US_RSTRX;
  AT91C_BASE_DBGU->DBGU_IDR   = 0xFFFFFFFF;
  AT91C_BASE_DBGU->DBGU_BRGR  = ((MCK_CLOCK + 8*BAUDRATE)/(16*BAUDRATE));
  AT91C_BASE_DBGU->DBGU_MR    = AT91C_US_PAR_NONE;
  AT91C_BASE_DBGU->DBGU_CR    = AT91C_US_TXEN  | AT91C_US_RXEN;
}


/*------------------------------------------------------------------------------
 *       SER_PutChar:  Write a character to the Serial Port
 *----------------------------------------------------------------------------*/

int32_t SER_PutChar (int32_t ch) {

  while (!(AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_TXEMPTY));
  AT91C_BASE_DBGU->DBGU_THR = ch;
  return (ch);
}


/*------------------------------------------------------------------------------
 *       SER_GetChar:  Read a character from the Serial Port (non-blocking)
 *----------------------------------------------------------------------------*/

int32_t SER_GetChar (void) {

  if (AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_RXRDY) 
    return (AT91C_BASE_DBGU->DBGU_RHR);
  return (-1);
}

/*------------------------------------------------------------------------------
 * End of file
 *----------------------------------------------------------------------------*/
