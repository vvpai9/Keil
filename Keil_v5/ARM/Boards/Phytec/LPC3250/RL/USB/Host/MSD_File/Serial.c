/*------------------------------------------------------------------------------
 *      RL-ARM
 *------------------------------------------------------------------------------
 *      Name:    Serial.c
 *      Purpose: Serial Input Output for NXP LPC325x
 *      Note(s): Possible defines to select the used communication interface:
 *                           - UART5 interface  (default)
 *------------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <LPC325x.h>

/*------------------------------------------------------------------------------
 *       SER_Init:  Initialize Serial Interface
 *----------------------------------------------------------------------------*/

void SER_Init (void) {

  /* Configure UART5 for 115200 baud. */
  UARTCLK_CTRL |=  (1 << 2);             /* Enable UART5 clock                */
  U5LCR         =  0x83;                 /* DLAB = 1                          */
  U5DLL         =  1;                    /* Low divisor latch = 1             */
  U5DLM         =  0;                    /* High divisor latch = 0            */
  U5LCR         =  0x03;                 /* DLAB = 0                          */
  U5CLK         =  (19 << 8) | 134;      /* Source is PERIPH_CLK, X=19, Y=134 */
  UART_CLKMODE |=  (1 << 8);             /* UART5 clock on                    */
  UART_CTRL    &= ~(1 << 0);             /* UART5 functions as UART only      */
  P3_MUX_SET    =  (1 << 20);            /* GPI_20 alternate function U5_RX   */
}


/*------------------------------------------------------------------------------
 *       SER_PutChar:  Write a character to the Serial Port
 *----------------------------------------------------------------------------*/

int SER_PutChar (int ch) {

  while (!(U5LSR & 0x20));
  return (U5THR = ch);
}


/*------------------------------------------------------------------------------
 *       SER_GetChar:  Read a character from the Serial Port (non-blocking)
 *----------------------------------------------------------------------------*/

int SER_GetChar (void) {

  if (U5LSR & 0x01) 
    return (U5RBR);
  return (-1);
}

/*------------------------------------------------------------------------------
 * End of file
 *----------------------------------------------------------------------------*/
