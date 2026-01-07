/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    TELNET_DEMO.C
 *      Purpose: Telnet Server demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <iMX27.h>

#define LED_PIN  (1 << 18)

BOOL tick;
BOOL LEDrun;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  /* General Purpose Timer 1 as interval timer, reload to 100ms. */
  GPT1_TCTL   = 0x0412;
  GPT1_TPRER  = 0;                           /* prescaler 1                  */
  GPT1_TCMP   = 1400000;                     /* 100mSec & PCLK1 = 14 MHz     */
  GPT1_TCTL  |= 0x0001;

  /* Configure GPIO for LED output. */
  PLLCLK_PCCR0  |=  1 << 25;
  GPIO_PTE_DDIR |=  LED_PIN;
  GPIO_PTE_GPR  &= ~LED_PIN;
  GPIO_PTE_OCR2 |=  3 << 4;
  GPIO_PTE_GIUS |=  LED_PIN;
  GPIO_PTE_DR   &= ~LED_PIN;

  /* Configure UART1 for 115200 baud. */
  PLLCLK_PCCR1  |= (1UL << 31) | (1 << 10);
  UART1_UCR1    |= 1;
  UART1_UCR2    |= (1 << 14) | (1 << 2) | (1 << 1) | (1 << 0);
  UART1_UCR3    |= (7 <<  8) | (1 << 2);

  /* Configure UART1 for 115200 baud, 8 data bits, no parity, 1 stop bit.    */
  /* ipg_perclk1 = 266/19 = 14 MHz                                           */
  /* baud rate   = 14 MHz / (16*4375/576) = 115200 baud                      */
  UART1_UFCR    |= (5 << 7);                 /* ref_clk = ipg_perclk1        */
  UART1_UBIR     = 576 - 1;
  UART1_UBMR    |= 4375 - 1;
  UART1_UCR2    |= (1 << 5);
  LEDrun = __TRUE;
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {

  if (val & 1) {
    GPIO_PTE_DR |= LED_PIN;
  }
  else {
    GPIO_PTE_DR &= ~LED_PIN;
  }
}


/*--------------------------- AD_in -----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */

  /* There is no POT on this board, return something. */
  return (ch + 10);
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (GPT1_TSTAT & 1) {
    /* GPT1 Timer irq pending, clear pending interrupt. */
    GPT1_TSTAT = 1;

    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}


/*--------------------------- fputc -----------------------------------------*/

int fputc (int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(UART1_USR2 & (1 << 3)));
    UART1_UTXD = '\r';
  }
  while (!(UART1_USR2 & (1 << 3)));
  return (UART1_UTXD = ch);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LED on phyCore board */
  static U32 cnt = 0;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    if (LEDrun == __TRUE) {
      if (++cnt == 5) cnt = 0;
      LED_out (cnt >> 2);
    }
  }
}


/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  init_TcpNet ();

  while (1) {
    timer_poll ();
    main_TcpNet ();
    blink_led ();
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
