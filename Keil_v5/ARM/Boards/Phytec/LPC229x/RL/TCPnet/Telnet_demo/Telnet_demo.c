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
#include <LPC22xx.h>

#define MCLK 60000000                         /* Master Clock 60 MHz         */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT (MCLK/TCLK/4)                    /* Timer Counts                */


BOOL tick;
BOOL LEDrun;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  /* Timer 1 reload to 100ms */
  T1TCR = 1;
  T1MCR = 3;
  T1MR0 = TCNT - 1;                          /* Timer 1 Period               */

  IODIR0 = 0x00000100;                       /* P0.8 defined as Output       */

  PINSEL0 = 0x00000005;                      /* Enable RxD0 and TxD0         */
  U0LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit*/
  U0DLL = 49;                                /* 19200 Baud @ 15MHz VPB Clock */
  U0LCR = 0x03;                              /* DLAB = 0                     */
  LEDrun = __TRUE;
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {

  if (val & 1) {
    IOCLR0 = 0x00000100;                     /* Turn LED On  (P0.8 = 0)      */
  }
  else {
    IOSET0 = 0x00000100;                     /* Turn LED Off (P0.8 = 1)      */
  }
}


/*--------------------------- AD_in -----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */
  U32 val = 0;
  U32 adcr;

  if (ch < 4) {
    adcr = 0x01000000 | (1 << ch);
    ADCR = adcr | 0x002E0400;                 /* Setup A/D: 10-bit @ 3MHz  */

    do {
      val = ADDR;                             /* Read A/D Data Register    */
    } while ((val & 0x80000000) == 0);        /* Wait for end of A/D Conv. */
    ADCR &= ~adcr;                            /* Stop A/D Conversion       */
    val = (val >> 6) & 0x03FF;                /* Extract AINx Value        */
  }
  return (val);
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (T1IR & 1) {
    /* Timer 1 interrupt rq pending, clear pending interrupt. */
    T1IR = 1;

    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}


/*--------------------------- fputc -----------------------------------------*/

int fputc (int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(U0LSR & 0x20));
    U0THR = '\r';                            /* output CR                    */
  }
  while (!(U0LSR & 0x20));
  return (U0THR = ch);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LED on phyCore board */
  static U32 LEDstat = 1;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    if (LEDrun == __TRUE) {
      LEDstat = ~LEDstat & 0x01;
      LED_out (LEDstat);
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
