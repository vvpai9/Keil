/*------------------------------------------------------------------------------
 *      RL-ARM
 *------------------------------------------------------------------------------
 *      Name:    Serial.c
 *      Purpose: Serial Input Output for NXP LPC23xx
 *      Note(s): Possible defines to select the used communication interface:
 *               RT_AGENT    - Real Time Agent interface (USART is used by default)
 *                           - UART1 interface  (default)
 *------------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2013 KEIL - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <LPC23xx.h>
#include "Serial.h"
#include "RT_Agent.h"


/*------------------------------------------------------------------------------
 *       SER_Init:  Initialize Serial Interface
 *----------------------------------------------------------------------------*/

void SER_Init (void) {

#ifdef RT_AGENT
  RTA_Init();
#else
  /* Configure UART1 for 115200 baud. */
  PINSEL0 &= ~0xC0000000;
  PINSEL0 |=  0x40000000;                    /* Enable TxD1 pin               */
  PINSEL1 &= ~0x00000003;
  PINSEL1 |=  0x00000001;                    /* Enable RxD1 pin               */

  U1LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit */
  U1DLL = 3;                                 /* for 12MHz PCLK Clock          */
  U1FDR = 0x67;                              /* Fractional Divider            */
  U1LCR = 0x03;                              /* DLAB = 0                      */
#endif
}


/*------------------------------------------------------------------------------
 *       SER_PutChar:  Write a character to the Serial Port
 *----------------------------------------------------------------------------*/

int SER_PutChar (int ch) {

#ifdef RT_AGENT
  RTA_TermPutChar(ch);
#else
  while (!(U1LSR & 0x20));
  U1THR = ch;
#endif
  return (ch);
}


/*------------------------------------------------------------------------------
 *       SER_GetChar:  Read a character from the Serial Port (non-blocking)
 *----------------------------------------------------------------------------*/

int SER_GetChar (void) {

#ifdef RT_AGENT
  if (RTA_TermIsKey())
    return (RTA_TermGetChar());
#else
  if (U1LSR & 0x01) 
    return (U1RBR);
#endif
  return (-1);
}

/*------------------------------------------------------------------------------
 * End of file
 *----------------------------------------------------------------------------*/
