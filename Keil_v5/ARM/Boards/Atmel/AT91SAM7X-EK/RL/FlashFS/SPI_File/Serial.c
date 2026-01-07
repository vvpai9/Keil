/*----------------------------------------------------------------------------
 *      RL-ARM - FlashFS
 *----------------------------------------------------------------------------
 *      Name:    SERIAL.C
 *      Purpose: Serial Input Output for Atmel AT91SAM7X
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <AT91SAM7X256.H>                     /* AT91SAM7X256 definitions    */
#include "..\..\..\AT91SAM7X-EK.h"

#define COM0    AT91C_BASE_US0

/*----------------------------------------------------------------------------
 *       init_serial:  Initialize Serial Interface
 *---------------------------------------------------------------------------*/
void init_serial (void) {
  /* Initialize the serial interface */

  /* UART1 configured for 115200 baud. */
  AT91C_BASE_PIOA->PIO_ASR     = AT91C_PA0_RXD0 | AT91C_PA1_TXD0 |
                                 AT91C_PA3_RTS0 | AT91C_PA4_CTS0 ;
  AT91C_BASE_PIOA->PIO_PDR     = AT91C_PA0_RXD0 | AT91C_PA1_TXD0 |
                                 AT91C_PA3_RTS0 | AT91C_PA4_CTS0 ;
  AT91C_BASE_PMC->PMC_PCER     = 1 << AT91C_ID_US0;
  COM0->US_IDR                 = 0xFFFFFFFF;
  COM0->US_CR                  = AT91C_US_RSTRX | AT91C_US_RSTTX | 
                                 AT91C_US_RXDIS | AT91C_US_TXDIS;
  COM0->US_BRGR                = (AT91B_MCK + 115200 *8) / (115200 * 16);
  COM0->US_TTGR                = 0;

  /* Clear PDC */
  AT91C_BASE_PDC_US0->PDC_PTCR = AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS;
  AT91C_BASE_PDC_US0->PDC_TNPR = 0;
  AT91C_BASE_PDC_US0->PDC_TNCR = 0;
  AT91C_BASE_PDC_US0->PDC_RNPR = 0;
  AT91C_BASE_PDC_US0->PDC_RNCR = 0;
  AT91C_BASE_PDC_US0->PDC_TPR  = 0;
  AT91C_BASE_PDC_US0->PDC_TCR  = 0;
  AT91C_BASE_PDC_US0->PDC_RPR  = 0;
  AT91C_BASE_PDC_US0->PDC_RCR  = 0;
  AT91C_BASE_PDC_US0->PDC_PTCR = AT91C_PDC_RXTEN  | AT91C_PDC_TXTEN;

  COM0->US_MR                  = AT91C_US_USMODE_NORMAL | 
                                 AT91C_US_NBSTOP_1_BIT  | 
                                 AT91C_US_PAR_NONE      | 
                                 AT91C_US_CHRL_8_BITS   | 
                                 AT91C_US_CLKS_CLOCK    ;
  COM0->US_CR                  = AT91C_US_RXEN | AT91C_US_TXEN;

  COM0->US_IER                 = AT91C_US_TIMEOUT | AT91C_US_FRAME | 
                                 AT91C_US_OVRE    | AT91C_US_RXRDY ;
}

/*----------------------------------------------------------------------------
 *       sendchar:  Write a character to Serial Port
 *---------------------------------------------------------------------------*/
int sendchar (int ch) {
  if (ch == '\n')  {
    while (!(COM0->US_CSR & AT91C_US_TXRDY));
    COM0->US_THR = '\r';                     /* output CR                    */
  }
  while (!(COM0->US_CSR & AT91C_US_TXRDY));
  COM0->US_THR = ch & 0x1FF;
  return (ch);
}

/*----------------------------------------------------------------------------
 *       getkey:  Read a character from Serial Port
 *---------------------------------------------------------------------------*/
int getkey (void) {
  while (!(COM0->US_CSR & AT91C_US_RXRDY));
  return ((COM0->US_RHR) & 0x1FF);
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
