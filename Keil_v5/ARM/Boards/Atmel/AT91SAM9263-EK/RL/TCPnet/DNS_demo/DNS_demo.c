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
#include <AT91SAM9263.H>                      /* AT91SAM9263 definitions     */
#include "Board.h"

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

  /* I/O Ports configured as Output. */
  pPMC->PMC_PCER  = (1 << AT91C_ID_PIOB) |  /* Enable Clock for PIO         */
                    (1 << AT91C_ID_PIOCDE); /* (LEDs, DBGU, Push Buttons)   */
  pPIOB->PIO_IDR  =
  pPIOB->PIO_PER  =                         /* Enable PIO for LEDs and PBs  */
  pPIOB->PIO_OER  =                         /* LEDs are Outputs             */
  pPIOB->PIO_SODR = LED1;                   /* Turn off LED ("1")           */
  pPIOC->PIO_IDR  = 
  pPIOC->PIO_PER  = LED2 | PB_MASK;         /* Enable PIO for LEDs and PBs  */
  pPIOC->PIO_ODR  = PB_MASK;                /* PBs are Inputs               */
  pPIOC->PIO_OER  =                         /* LEDs are Outputs             */
  pPIOC->PIO_SODR = LED2;                   /* Turn off LED ("1")           */

  /* PITC Timer interval timer, reload to 100ms */
  pPITC->PITC_PIMR = (TCNT - 1) | AT91C_PITC_PITEN;

  /* Configure DBGU for 115200 baud. */
  pPIOC->PIO_IDR  =
  pPIOC->PIO_PPUDR=
  pPIOC->PIO_ASR  =
  pPIOC->PIO_PDR  = AT91C_PC30_DRXD  | AT91C_PC31_DTXD;

  pDBGU->DBGU_CR  = AT91C_US_RSTRX   | AT91C_US_RSTTX;
  pDBGU->DBGU_IDR = 0xFFFFFFFF;
  pDBGU->DBGU_BRGR= BAUD(115200);
  pDBGU->DBGU_MR  = AT91C_US_PAR_NONE;
  pDBGU->DBGU_PTCR= AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS;
  pDBGU->DBGU_CR  = AT91C_US_RXEN    | AT91C_US_TXEN;
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {

  if (val & 1) {
    pPIOB->PIO_CODR = LED1;                  /* Turn LED1 On                 */
  }
  else {
    pPIOB->PIO_SODR = LED1;
  }
  if (val & 2) {
    pPIOC->PIO_CODR = LED2;                  /* Turn LED2 On                 */
  }
  else {
    pPIOC->PIO_SODR = LED2;
  }
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */
  volatile U32 val;

  if (pPITC->PITC_PISR & 1) {
    val = pPITC->PITC_PIVR;
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
    while (!(pDBGU->DBGU_CSR & AT91C_US_TXRDY));
    pDBGU->DBGU_THR = '\r';                 /* output CR                    */
  }
  while (!(pDBGU->DBGU_CSR & AT91C_US_TXRDY));
  pDBGU->DBGU_THR = ch;
  return (ch);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LED on AT91SAM9263 board */
  const U8 led_val[4] = { 0x01,0x00,0x02,0x00};
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
