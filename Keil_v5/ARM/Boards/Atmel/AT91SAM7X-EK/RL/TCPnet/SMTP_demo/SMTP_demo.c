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
#include <AT91SAM7X256.H>                     /* AT91SAM7X256 definitions    */
#include "AT91SAM7X-EK.h"

/* Clock Definitions */
#define EXT_OSC 18432000                      /*  External Oscillator MAINCK */
#define MCK     47923200                      /*  Master Clock               */
#define BAUD(b) ((MCK + 8*b)/(16*b))
#define TCNT    (MCK/16)/10                   /* Timer Counts for 100ms      */

/* Enter your valid SMTP Server IP address here. */
U8 srv_ip[4] = { 192,168,0,253 };

BOOL tick;
BOOL tick2;
BOOL sent;
U32  delay;

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

  /* Configure ADC for 8 analog inputs. */
  *AT91C_PMC_PCER = (1 << AT91C_ID_ADC);     /* Enable Clock for ADC         */
  *AT91C_ADC_MR   = AT91C_ADC_LOWRES_10_BIT     |
                    AT91C_ADC_TRGEN_DIS         |
                    AT91C_ADC_SLEEP_NORMAL_MODE |
                    (0x01 << 24)                |
                    (0x01 << 16)                |
                    (0x01 << 8);
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


/*--------------------------- AD_in ----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */
  U32 adsr,val = 0;

  if (ch < 8) {
    *AT91C_ADC_CHER = 1 << ch;
    *AT91C_ADC_CR   = AT91C_ADC_START;        /* Start A/D conversion        */
    do {
      adsr = *AT91C_ADC_SR;                   /* Read A/D Status Register    */
    } while ((adsr & AT91C_ADC_DRDY) == 0);   /* Wait for end of A/D Conv.   */
    *AT91C_ADC_CR   = 0;                      /* Stop A/D Conversion         */
    *AT91C_ADC_CHDR = 0xFF;
    val = *AT91C_ADC_LCDR & 0x03FF;           /* Extract AINx Value          */
  }
  return (val);
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
