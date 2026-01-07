/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    FTP_DEMO.C 
 *      Purpose: FTP Server demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <LPC214x.H>                          /* LPC214x definitions         */

#define MCLK 60000000                         /* Master Clock 60 MHz         */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT (MCLK/TCLK/4)                    /* Timer Counts                */

BOOL tick;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  /* Timer 1 reload to 100ms */
  T1TCR = 1;
  T1MCR = 3;
  T1MR0 = TCNT - 1;                          /* Timer 1 Period               */

  IODIR1 = 0xFF0000;                         /* P1.16..23 defined as Outputs */

  PINSEL0 = 0x00000005;                      /* Enable RxD0 and TxD0         */
  U0LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit*/
  U0DLL = 6;                                 /* 115200 Baud 15MHz VPB Clock  */
  U0DLM = 0;
  U0FDR = 15<<4 | 5;                         /* Mul = 15, Div = 5            */
  U0LCR = 0x03;                              /* DLAB = 0                     */
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {
  val  <<= 16;
  IOSET1 = val;
  IOCLR1 = ~val;
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (T1IR & 1) {
    T1IR = 1;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}


/*--------------------------- sendchar --------------------------------------*/

int sendchar (int ch)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(U0LSR & 0x20));
    U0THR = '\r';                            /* output CR                    */
  }
  while (!(U0LSR & 0x20));
  return (U0THR = ch);
}


/*--------------------------- getkey ----------------------------------------*/

int getkey (void) {
  /* A dummy function for 'retarget.c' */
  return (0);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LED on Keil MCB2130 board */
  const U8 led_val[16] = { 0x48,0x88,0x84,0x44,0x42,0x22,0x21,0x11,
                           0x12,0x0A,0x0C,0x14,0x18,0x28,0x30,0x50 };
  static U32 cnt;

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

  /* Enable PPP server to accept incomming connections. */
  ppp_listen ("Keil", "test");

  while (1) {
    timer_poll ();
    main_TcpNet ();
    blink_led ();
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
