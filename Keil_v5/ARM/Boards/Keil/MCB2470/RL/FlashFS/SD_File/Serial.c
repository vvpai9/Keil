/*----------------------------------------------------------------------------
 *      RL-ARM - FlashFS
 *----------------------------------------------------------------------------
 *      Name:    SERIAL.C
 *      Purpose: Serial Input Output for Philips LPC24xx
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <LPC23xx.H>                    /* LPC23xx definitions               */

/*----------------------------------------------------------------------------
 *       init_serial:  Initialize Serial Interface
 *---------------------------------------------------------------------------*/
void init_serial (void) {
  /* Initialize the serial interface */

  /* Configure UART2 for 115200 baud. */
  PCONP   |= (1 <<24);                       /* Enable UART2 power           */
  PINSEL0 &= ~0x00F00000;
  PINSEL0 |=  0x00500000;                    /* Enable TxD2 and RxD2         */
  U2LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit*/
  U2DLL = 3;                                 /* for 12MHz PCLK Clock         */
  U2FDR = 0x67;                              /* Fractional Divider           */
  U2LCR = 0x03;                              /* DLAB = 0                     */
}

/*----------------------------------------------------------------------------
 *       sendchar:  Write a character to Serial Port
 *---------------------------------------------------------------------------*/
int sendchar (int ch) {
  if (ch == '\n') {
    while (!(U2LSR & 0x20));
    U2THR = '\r';
  }
  while (!(U2LSR & 0x20));
  return (U2THR = ch);
}

/*----------------------------------------------------------------------------
 *       getkey:  Read a character from Serial Port
 *---------------------------------------------------------------------------*/
int getkey (void) {
  while (!(U2LSR & 0x01));
  return (U2RBR);
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
