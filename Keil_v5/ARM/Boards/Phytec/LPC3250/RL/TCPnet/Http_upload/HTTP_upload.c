/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    HTTP_UPLOAD.C
 *      Purpose: HTTP File Upload example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <Net_Config.h>
#include <LPC325x.h>

#define LED_1    0x0002
#define LED_2    0x4000
#define LED_ALL  0x4002

BOOL tick;
U32  dhcp_tout;

extern LOCALM localm[];                       /* Local Machine Settings      */
#define MY_IP localm[NETIF_ETH].IpAdr
#define DHCP_TOUT   50                        /* DHCP timeout 5 seconds      */

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
  /* A dummy function for 'retarget.c' */
  return (ch);
}


/*--------------------------- getkey ----------------------------------------*/

int getkey (void) {
  /* A dummy function for 'retarget.c' */
  return (0);
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {
  U32 out = 0;

  if (val & 1) out |= LED_1;
  if (val & 2) out |= LED_2;
  P3_OUTP_SET = out;
  P3_OUTP_CLR = out ^ LED_ALL;
}


/*--------------------------- dhcp_check ------------------------------------*/

static void dhcp_check () {
  /* Monitor DHCP IP address assignment. */

  if (tick == __FALSE || dhcp_tout == 0) {
    return;
  }
  if (mem_test (&MY_IP, 0, IP_ADRLEN) == __FALSE) {
    /* Success, DHCP has already got the IP address. */
    dhcp_tout = 0;
    return;
  }
  if (--dhcp_tout == 0) {
    /* A timeout, disable DHCP and use static IP address. */
    dhcp_disable ();
    return;
  }
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

  dhcp_tout = DHCP_TOUT;
  while (1) {
    timer_poll ();
    main_TcpNet ();
    dhcp_check ();
    blink_led ();
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
