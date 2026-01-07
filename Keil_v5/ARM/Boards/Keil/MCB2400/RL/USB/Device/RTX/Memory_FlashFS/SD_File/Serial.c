/*-----------------------------------------------------------------------------
 * Name:    Serial.c
 * Purpose: Serial Input Output functions
 * Note(s):
 *-----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <LPC24xx.H>                    /* LPC24xx definitions                */
#include <stdint.h>
#include "Serial.h"


/*-----------------------------------------------------------------------------
 *       SER_Init:  Initialize Serial Interface
 *----------------------------------------------------------------------------*/
void SER_Init (void) {
  /* Configure UART1 for 115200 baud. */
  PINSEL7 |=  0x30003FFF;               /* Enable UART1 pins                  */

  U1LCR = 0x83;                         /* 8 bits, no Parity, 1 Stop bit      */
  U1DLL = 3;                            /* for 12MHz PCLK Clock               */
  U1FDR = 0x67;                         /* Fractional Divider                 */
  U1LCR = 0x03;                         /* DLAB = 0                           */
}


/*-----------------------------------------------------------------------------
 *       SER_PutChar:  Write a character to the Serial Port
 *----------------------------------------------------------------------------*/
int32_t SER_PutChar (int32_t ch) {
  while (!(U1LSR & 0x20));
  return (U1THR = ch);
}


/*-----------------------------------------------------------------------------
 *       SER_GetChar:  Read a character from the Serial Port
 *----------------------------------------------------------------------------*/
int32_t SER_GetChar (void) {
  
  if (U1LSR & 0x01) {
    return (U1RBR);
  }
  return (-1);
}

/*-----------------------------------------------------------------------------
 * End of file
 *----------------------------------------------------------------------------*/
