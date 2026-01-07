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
#include <AT91SAM9263.H>                      /* AT91SAM9263 definitions     */
#include "Board.h"

#define TCNT    (MCK/16)/10                   /* Timer Counts for 100ms      */

BOOL tick;
BOOL LEDrun;

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

  LEDrun = __TRUE;
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


/*--------------------------- AD_in -----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */

  /* This device does not have Analog inputs. */
  return (10*ch + 1);
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */
  volatile U32 val;

  if (pPITC->PITC_PISR & 1) {
    val = pPITC->PITC_PIVR;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
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
  /* Blink the LEDs on AT91SAM9263 board */
  const U8 led_val[4] = { 0x01,0x00,0x02,0x00};
  static U32 cnt;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    if (LEDrun == __TRUE) {
      LED_out (led_val[cnt]);
      if (++cnt >= sizeof(led_val)) {
        cnt = 0;
      }
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
