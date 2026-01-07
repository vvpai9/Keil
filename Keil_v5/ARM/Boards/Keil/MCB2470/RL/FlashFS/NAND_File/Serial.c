/*----------------------------------------------------------------------------
 *      RL-ARM - FlashFS
 *----------------------------------------------------------------------------
 *      Name:    Serial.C
 *      Purpose: Serial Input Output for NXP LPC24xx
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2012 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/
#include <stdint.h>
#include <LPC24xx.H>                    /* LPC24xx definitions               */
#include "Serial.h"

/*-----------------------------------------------------------------------------
 *       SER_Init:  Initialize Serial Interface
 *----------------------------------------------------------------------------*/
void SER_Init (void) {

  /* Configure UART0 (P0.2 - TXD0, P0.3 - RXD0) for 115200 baud. */
  PINSEL0 &= ~((3 << 6) | (3 << 4));
  PINSEL0 |=  ((1 << 6) | (1 << 4));

  U0LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit*/
  U0DLL = 8;                                 /* for 18MHz PCLK Clock         */
  U0FDR = 0x92;                              /* Fractional Divider           */
  U0LCR = 0x03;                              /* DLAB = 0                     */
}


/*-----------------------------------------------------------------------------
 *       SER_PutChar:  Write a character to Serial Port
 *----------------------------------------------------------------------------*/
int32_t SER_PutChar (int32_t ch) {
  while (!(U0LSR & 0x20));
  return (U0THR = ch);
}

/*-----------------------------------------------------------------------------
 *       SER_GetChar:  Read a character from Serial Port
 *----------------------------------------------------------------------------*/
int32_t SER_GetChar (void) {
  if (U0LSR & 0x01) {
    return (U0RBR);
  }
  return (-1);
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
