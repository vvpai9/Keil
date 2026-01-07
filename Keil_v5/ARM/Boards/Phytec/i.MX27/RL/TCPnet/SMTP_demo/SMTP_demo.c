/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    SMTP_DEMO.C
 *      Purpose: SMTP Client demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <iMX27.h>

#define LED_PIN  (1 << 18)

/* Enter your valid SMTP Server IP address here. */
U8 srv_ip[4] = { 192,168,0,253 };

BOOL tick;
BOOL tick2;
BOOL sent;
U32  delay;

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
  /* Blink the LED on phyCore board */
  static U32 cnt = 0;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    if (++cnt == 5) cnt = 0;
    LED_out (cnt >> 2);
  }
}


/*--------------------------- AD_in ----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */

  /* There is no POT on this board, return something. */
  return (ch + 10);
}


/*---------------------------------------------------------------------------*/

static void smtp_cback (U8 code) {
  /* This function is called by TcpNet to inform about SMTP status. */
  switch (code) {
    case SMTP_EVT_SUCCESS:
      printf ("Email successfully sent\n");
      sent = __TRUE;
      break;
    case SMTP_EVT_TIMEOUT:
      /* Timeout, try again. */
      printf ("Mail Server timeout.\n");
      delay = 0;
      break;
    case SMTP_EVT_ERROR:
      /* Error, try again. */
      printf ("Error sending email.\n");
      delay = 0;
      break;
  }
}

/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  init_TcpNet ();

  delay = 0;
  sent  = __FALSE;
  while (1) {
    timer_poll ();
    main_TcpNet ();
    blink_led ();
    if (tick2 == __FALSE) {
      continue;
    }
    tick2 = __FALSE;
    if (sent == __TRUE) {
      continue;
    }
    if (++delay == 100) {
      /* After 10 seconds send an email. */
      printf ("Sending email...\n");
      smtp_connect ((U8 *)&srv_ip,25,smtp_cback);
    }
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
