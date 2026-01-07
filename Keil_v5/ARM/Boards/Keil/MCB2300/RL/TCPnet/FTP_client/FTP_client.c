/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    FTP_CLIENT.C 
 *      Purpose: FTP Client demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2012 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <LPC23xx.H>                    /* LPC23xx definitions               */
#include "LCD.h"

#define MCLK 48000000                         /* Master Clock 48 MHz         */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT (MCLK/TCLK/4)                    /* Timer Counts                */

/* Enter your valid FTP Server IP address here. */
U8 srv_ip[4] = { 192,168,0,253 };

BOOL tick;
BOOL tick2;
BOOL active;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  /* I/O Ports configured as Output (Push-pull) */
  FIO2DIR  = 0x000000FF;
  FIO2MASK = 0x00000000;
  FIO2PIN  = 0x00000000;
  PINSEL10 = 0;

  /* Timer 1 as interval timer, reload to 100ms. */
  T1TCR = 1;
  T1MCR = 3;
  T1MR0 = TCNT - 1;

  /* Configure UART1 for 115200 baud. */
  PINSEL0 = 0x40000000;                      /* Enable TxD1 pin              */
  PINSEL1 = 0x00000001;                      /* Enable RxD1 pin              */
  U1LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit*/
  U1DLL = 3;                                 /* for 12MHz PCLK Clock         */
  U1FDR = 0x67;                              /* Fractional Divider           */
  U1LCR = 0x03;                              /* DLAB = 0                     */
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {
  FIO2SET =  val;
  FIO2CLR = ~val;
}


/*--------------------------- init_display ----------------------------------*/

static void init_display () {
  /* LCD Module.2x16 init*/

  LCD_init ();
  LCD_cur_off ();
  LCD_puts ("    RL-ARM      "
            "  FTPC example  ");
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (T1IR & 1) {
    T1IR = 1;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick  = __TRUE;
    tick2 = __TRUE;
  }
}


/*--------------------------- sendchar --------------------------------------*/

int sendchar (int ch)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(U1LSR & 0x20));
    U1THR = '\r';                            /* output CR                    */
  }
  while (!(U1LSR & 0x20));
  return (U1THR = ch);
}


/*--------------------------- getkey ----------------------------------------*/

int getkey (void) {
  /* A dummy function for 'retarget.c' */
  return (0);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LEDs on MCB2300 board */
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


void ftpc_notify (U8 event) {
  /* Result notification function. */

  active = __FALSE;
  switch (event) {
    case FTPC_EVT_SUCCESS:
      printf ("Command successful\n");
      break;

    case FTPC_EVT_TIMEOUT:
      printf ("Failed, timeout expired\n");
      break;

    case FTPC_EVT_LOGINFAIL:
      printf ("Failed, username/password invalid\n");
      break;

    case FTPC_EVT_NOACCESS:
      printf ("Failed, operation not allowed\n");
      break;

    case FTPC_EVT_NOTFOUND:
      printf ("Failed, file or path not found\n");
      break;

    case FTPC_EVT_NOPATH:
      printf ("Failed, working directory not found\n");
      break;

    case FTPC_EVT_ERRLOCAL:
      printf ("Failed, local file open error\n");
      break;

    case FTPC_EVT_ERROR:
      printf ("Failed, unspecified protocol error\n");
      break;
  }
}


/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */
  int delay = 0;

  init ();
  init_display ();
  init_TcpNet ();
  finit (NULL);

  printf ("FTP Client demo\n");
  active = __FALSE;
  while (1) {
    timer_poll ();
    main_TcpNet ();
    blink_led ();
    if (tick2 == __FALSE) {
      continue;
    }
    tick2 = __FALSE;
    if (active == __TRUE) {
      continue;
    }
    delay++;
    if (delay == 50) {
      /* After 5 seconds connect to FTP server. */
      printf("\nSend a file to server...\n");
      ftpc_connect (srv_ip, 0, FTPC_CMD_PUT, ftpc_notify);
      active = __TRUE;
      continue;
    }
    if (delay == 52) {
      /* Make a directory on FTP server. */
      printf ("\nMake a directory on server...\n");
      ftpc_connect (srv_ip, 0, FTPC_CMD_MKDIR, ftpc_notify);
      active = __TRUE;
      continue;
    }

    if (delay == 54) {
      /* List directory content on FTP server. */
      printf ("\nListing directory...\n");
      ftpc_connect (srv_ip, 0, FTPC_CMD_LIST, ftpc_notify);
      active = __TRUE;
      continue;
    }
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
