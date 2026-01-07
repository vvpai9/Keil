/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    TFTP_DEMO.C 
 *      Purpose: TFTP Server demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <LPC325x.h>

#define LED_1    0x0002
#define LED_2    0x4000
#define LED_ALL  0x4002

BOOL tick;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  /* High Speed Timer as interval timer, reload to 100ms. */
  TIMCLK_CTRL   = 0x02;
  HSTIM_MATCH2  = 100000 - 1;                /* 100 mSec                     */
  HSTIM_PMATCH  = 13 - 1;                    /* prescaler 13                 */
  HSTIM_PCOUNT  = 0;
  HSTIM_COUNTER = 0;
  HSTIM_INT     = 0x04;
  HSTIM_MCTRL   = 0xC0;
  HSTIM_CTRL    = 0x01;

  /* Configure UART5 for 115200 baud. */
  U5LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit*/
  U5DLM = 0;
  U5DLL = 7;                                 /* for 13MHz PERIPH_CLK Clock   */
  U5LCR = 0x03;                              /* DLAB = 0                     */
  U5CLK = 0x0101;                            /* X/Y Divider set to 1         */
  UART_CLKMODE = 0x0200;                     /* UART5 Clock ON mode          */
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {
  U32 out = 0;

  if (val & 1) out |= LED_1;
  if (val & 2) out |= LED_2;
  P3_OUTP_SET = out;
  P3_OUTP_CLR = out ^ LED_ALL;
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (HSTIM_INT & 4) {
    /* HS Timer irq pending, clear pending interrupt. */
    HSTIM_INT = 4;

    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}


/*--------------------------- sendchar --------------------------------------*/

int sendchar (int ch)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(U5LSR & 0x20));
    U5THR = '\r';                            /* output CR                    */
  }
  while (!(U5LSR & 0x20));
  return (U5THR = ch);
}


/*--------------------------- getkey ----------------------------------------*/

int getkey (void) {
  /* A dummy function for 'retarget.c' */
  return (0);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LEDs on phyCore board */
  const U8 led_val[6] = { 0x01,0x00,0x00, 0x02, 0x00,0x00 };
  static U32 cnt = 0;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    LED_out (led_val[cnt]);
    if (++cnt >= sizeof(led_val)) {
      cnt = 0;
    }
  }
}


/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  init_TcpNet ();
  finit (NULL);
  fformat ("");

  while (1) {
    timer_poll ();
    main_TcpNet ();
    blink_led ();
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
