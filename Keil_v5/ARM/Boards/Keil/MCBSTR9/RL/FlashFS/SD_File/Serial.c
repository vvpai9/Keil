/*----------------------------------------------------------------------------
 *      RL-ARM - FlashFS
 *----------------------------------------------------------------------------
 *      Name:    SERIAL.C
 *      Purpose: Serial Input Output for STmicroelectronics STR91x
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <91x_lib.h>                    /* STR91x definitions                */

/*----------------------------------------------------------------------------
 *       init_serial:  Initialize Serial Interface
 *---------------------------------------------------------------------------*/
void init_serial (void) {
  /* Initialize the serial interface */

  /* Enable TX1 and RX1 pins      */
  SCU->GPIOOUT[3] &= 0xFF3F;
  SCU->GPIOOUT[3] |= 0x0080;
  SCU->GPIOIN[3]  |= 0x04;
  /* 115200 Baud Rate */
  UART1->IBRD = 0x1A;
  UART1->FBRD = 0x03;
  /* 8-bits, no parity, 1 stop bit */
  UART1->LCR  = 0x0060;
  /* Enable UART1 */
  UART1->CR   = 0x0301;
}

/*----------------------------------------------------------------------------
 *       sendchar:  Write a character to Serial Port
 *---------------------------------------------------------------------------*/
int sendchar (int ch) {
  if (ch == '\n')  {
    while (!(UART1->FR & 0x0080));
    UART1->DR = '\r';
  }
  while (!(UART1->FR & 0x0080));
  return (UART1->DR = ch);
}

/*----------------------------------------------------------------------------
 *       getkey:  Read a character from Serial Port
 *---------------------------------------------------------------------------*/
int getkey (void) {
  while ((UART1->FR & 0x10));
  return (UART1->DR);
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
