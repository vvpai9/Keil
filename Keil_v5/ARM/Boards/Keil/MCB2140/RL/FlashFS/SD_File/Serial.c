/*----------------------------------------------------------------------------
 *      RL-ARM - FlashFS
 *----------------------------------------------------------------------------
 *      Name:    SERIAL.C
 *      Purpose: Serial Input Output for Philips LPC214x
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <LPC214x.H>                    /* LPC214x definitions               */

/*----------------------------------------------------------------------------
 *       init_serial:  Initialize Serial Interface
 *---------------------------------------------------------------------------*/
void init_serial (void) {
  /* Initialize the serial interface */

  /* Enable RxD1 and TxD1 pins. */
  PINSEL0 &= ~0x000F0000;
  PINSEL0 |=  0x00050000;
  /* 8-bits, no parity, 1 stop bit */
  U1LCR = 0x83;
  /* 115200 Baud Rate @ 15MHz VPB Clock */
  U1DLL = 6;
  U1DLM = 0;
  U1FDR = 15<<4 | 5;
  U1LCR = 0x03;
  /* Enable FIFO with 8-byte trigger level. */
  U1FCR = 0x87;
}

/*----------------------------------------------------------------------------
 *       sendchar:  Write a character to Serial Port
 *---------------------------------------------------------------------------*/
int sendchar (int ch) {
  if (ch == '\n') {
    while (!(U1LSR & 0x20));
    U1THR = '\r';
  }
  while (!(U1LSR & 0x20));
  return (U1THR = ch);
}

/*----------------------------------------------------------------------------
 *       getkey:  Read a character from Serial Port
 *---------------------------------------------------------------------------*/
int getkey (void) {
  while (!(U1LSR & 0x01));
  return (U1RBR);
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
