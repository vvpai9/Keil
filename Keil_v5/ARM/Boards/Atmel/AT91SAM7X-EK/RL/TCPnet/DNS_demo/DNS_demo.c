/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    DNS_DEMO.C
 *      Purpose: DNS Resolver demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2012 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <AT91SAM7X256.H>                     /* AT91SAM7X256 definitions    */
#include "AT91SAM7X-EK.h"

/* Clock Definitions */
#define EXT_OSC 18432000                      /* External Oscillator MAINCK  */
#define MCK     47923200                      /* Master Clock                */
#define BAUD(b) ((MCK + 8*b)/(16*b))
#define TCNT    (MCK/16)/10                   /* Timer Counts for 100ms      */

BOOL tick;
BOOL tick2;

char const *hosts[] = {
  "www.google.com",
  "www.keil.com",
  "www.microsoft.com",
  "www.yahoo.com",
  "www.notexisting.site",
  "192.168.0.253",
  "www.google-.com",
  "goble"
};
unsigned int index;
unsigned int delay;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  *AT91C_PMC_PCER  = (1 << AT91C_ID_PIOB);   /* Enable Clock for PIO         */
  *AT91C_PIOB_PER  = AT91B_LED_MASK;         /* Enable PIO for LED1..4       */
  *AT91C_PIOB_OER  = AT91B_LED_MASK;         /* LED1..4 are Outputs          */
  *AT91C_PIOB_SODR = AT91B_LED_MASK;         /* Turn off LED's ("1")         */

  /* Timer 1 reload to 100ms */
  *AT91C_PITC_PIMR = (TCNT - 1) | AT91C_PITC_PITEN;

  /* Configure DBGU for 115200 baud. */
  *AT91C_PIOA_IDR  =
  *AT91C_PIOA_PPUDR=
  *AT91C_PIOA_ASR  =
  *AT91C_PIOA_PDR  = AT91C_PA27_DRXD | AT91C_PA28_DTXD;

  *AT91C_DBGU_CR   = AT91C_US_RSTRX   | AT91C_US_RSTTX;
  *AT91C_DBGU_IDR  = 0xFFFFFFFF;
  *AT91C_DBGU_BRGR = BAUD(115200);
  *AT91C_DBGU_MR   = AT91C_US_PAR_NONE;
  *AT91C_DBGU_PTCR = AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS;
  *AT91C_DBGU_CR   = AT91C_US_RXEN    | AT91C_US_TXEN;
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {

  *AT91C_PIOB_SODR = AT91B_LED_MASK;
  if (val & 1) {
    *AT91C_PIOB_CODR = AT91B_LED4;           /* Turn LED4 On                 */
  }
  if (val & 2) {
    *AT91C_PIOB_CODR = AT91B_LED3;           /* Turn LED3 On                 */
  }
  if (val & 4) {
    *AT91C_PIOB_CODR = AT91B_LED2;           /* Turn LED2 On                 */
  }
  if (val & 8) {
    *AT91C_PIOB_CODR = AT91B_LED1;           /* Turn LED1 On                 */
  }
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */
  volatile U32 val;

  if (*AT91C_PITC_PISR & 1) {
    val = *AT91C_PITC_PIVR;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick  = __TRUE;
    tick2 = __TRUE;
  }
}


/*--------------------------- fputc -----------------------------------------*/

int fputc(int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(*AT91C_DBGU_CSR & AT91C_US_TXRDY));
    *AT91C_DBGU_THR = '\r';                 /* output CR                    */
  }
  while (!(*AT91C_DBGU_CSR & AT91C_US_TXRDY));
  *AT91C_DBGU_THR = ch;
  return (ch);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LEDs on AT91SAM7X board */
  const U8 led_val[8] = { 0x01,0x03,0x07,0x0F,0x0E,0x0C,0x08,0x00 };
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


/*--------------------------- next_host -------------------------------------*/

static void next_host () {
  /* Select next host from the table. */

  if (++index == sizeof(hosts)/sizeof(hosts[0])) {
    index = 0;
  }
}


/*--------------------------- dns_cbfunc ------------------------------------*/

static void dns_cbfunc (unsigned char event, unsigned char *ip) {
  /* This function is called by the DNS Client when dns event occurs. */

  switch (event) {
    case DNS_EVT_SUCCESS:
      /* Host Address successfully resolved. When IP address is already */
      /* cached, there is no DNS Request sent to remote DNS Server.     */
      printf("IP Address    : %d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
      break;

    case DNS_EVT_NONAME:
      /* Host Name does not exist in DNS record database. */
      printf("Host name does not exist.\n");
      break;

    case DNS_EVT_TIMEOUT:
      /* All DNS Resolver retries used up and timeouts expired. */
      printf("DNS Resolver Timeout expired, Host Address not resolved.\n");
      break;

    case DNS_EVT_ERROR:
      /* DNS Protocol Error, invalid or corrupted reply received. */
      printf("DNS Resolver Protocol Error, Host Address not resolved.\n");
      delay = 0;
      return;
  }
  next_host();
  delay = 30;
}


/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */
  int res;

  init ();
  init_TcpNet ();

  printf ("\nDNS Resolver Demo Example\n");

  index = 0;
  delay = 0;
  while (1) {
    timer_poll ();
    main_TcpNet ();
    blink_led ();
    if (tick2 == __FALSE) {
      continue;
    }
    tick2 = __FALSE;
    if (++delay == 50) {
      /* After 5 seconds start DNS Resolver. */
      printf ("\nResolving host: %s\n",hosts[index]);
      res = get_host_by_name ((U8 *)hosts[index],dns_cbfunc);
      switch (res) {
        case DNS_RES_OK:
          /* Resolver started, wait for callback event. */
          break;

        case DNS_ERROR_BUSY:
          /* Busy, retry on next tick. */
          delay--;
          break;

        case DNS_ERROR_LABEL:
          printf ("Invalid label specified!\n");
          next_host();
          delay = 30;
          break;

        case DNS_ERROR_NAME:
          printf ("Hostname is not valid!\n");
          next_host();
          delay = 30;
          break;

        case DNS_ERROR_NOSRV:
          printf ("DNS Server unknown!\n");
          delay = 0;
          break;

        case DNS_ERROR_PARAM:
          printf ("Invalid parameters!\n");
          delay = 0;
          break;
      }
    }
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
