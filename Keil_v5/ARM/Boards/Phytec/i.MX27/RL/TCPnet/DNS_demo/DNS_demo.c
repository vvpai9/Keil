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
#include <iMX27.h>

#define LED_PIN  (1 << 18)

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


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (GPT1_TSTAT & 1) {
    /* GPT1 Timer irq pending, clear pending interrupt. */
    GPT1_TSTAT = 1;

    /* Timer tick every 100 ms */
    timer_tick ();
    tick  = __TRUE;
    tick2 = __TRUE;
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
  /* Blink the LEDs on phyCore board */
  static U32 cnt = 0;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    if (++cnt == 5) cnt = 0;
    LED_out (cnt >> 2);
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
