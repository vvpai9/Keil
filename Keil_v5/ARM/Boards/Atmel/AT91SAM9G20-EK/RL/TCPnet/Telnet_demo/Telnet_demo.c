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
#include <AT91SAM9G20.H>                      /* AT91SAM9G20 definitions     */
#include "Board.h"

#define TCNT    (MCK/16)/10                   /* Timer Counts for 100ms      */

BOOL tick;
BOOL LEDrun;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  /* I/O Ports configured as Output. */
  pPMC->PMC_PCER  = (1 << AT91C_ID_PIOB) |  /* Enable Clock for PIO         */
                    (1 << AT91C_ID_PIOA);   /* (LEDs, DBGU, Push Buttons)   */
  pPIOA->PIO_IDR  = 
  pPIOA->PIO_PER  = LED_MASK | PB_MASK;     /* Enable PIO for LEDs and PBs  */
  pPIOA->PIO_ODR  = PB_MASK;                /* PBs are Inputs               */
  pPIOA->PIO_OER  = LED_MASK;               /* LEDs are Outputs             */
  pPIOA->PIO_SODR = LED1;                   /* Turn off LED ("1")           */

  /* PITC Timer interval timer, reload to 100ms */
  pPITC->PITC_PIMR = (TCNT - 1) | AT91C_PITC_PITEN;

  /* Configure DBGU for 115200 baud. */
  pPIOB->PIO_IDR  =
  pPIOB->PIO_PPUDR=
  pPIOB->PIO_ASR  =
  pPIOB->PIO_PDR  = AT91C_PB14_DRXD  | AT91C_PB15_DTXD;

  pDBGU->DBGU_CR  = AT91C_US_RSTRX   | AT91C_US_RSTTX;
  pDBGU->DBGU_IDR = 0xFFFFFFFF;
  pDBGU->DBGU_BRGR= BAUD(115200);
  pDBGU->DBGU_MR  = AT91C_US_PAR_NONE;
  pDBGU->DBGU_PTCR= AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS;
  pDBGU->DBGU_CR  = AT91C_US_RXEN    | AT91C_US_TXEN;

  /* Configure ADC for 4 analog inputs. */
  pPMC->PMC_PCER  = (1 << AT91C_ID_ADC);     /* Enable Clock for ADC         */
  pADC->ADC_MR    = AT91C_ADC_LOWRES_10_BIT     |
                    AT91C_ADC_TRGEN_DIS         |
                    AT91C_ADC_SLEEP_NORMAL_MODE |
                    (0x01 << 24)                |
                    (0x01 << 16)                |
                    (0x01 << 8);

  LEDrun = __TRUE;
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {

  val ^= 0x02;                               /* LED2 output is inverted      */
  pPIOA->PIO_SODR = LED_MASK;
  if (val & 1) {
    pPIOA->PIO_CODR = LED1;                  /* Turn LED1 On                 */
  }
  if (val & 2) {
    pPIOA->PIO_CODR = LED2;                  /* Turn LED2 On                 */
  }
}


/*--------------------------- AD_in -----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */
  U32 adsr,val = 0;

  if (ch < 4) {
    pADC->ADC_CHER = 1 << ch;
    pADC->ADC_CR   = AT91C_ADC_START;         /* Start A/D conversion        */
    do {
      adsr = pADC->ADC_SR;                    /* Read A/D Status Register    */
    } while ((adsr & AT91C_ADC_DRDY) == 0);   /* Wait for end of A/D Conv.   */
    pADC->ADC_CR   = 0;                       /* Stop A/D Conversion         */
    pADC->ADC_CHDR = 0xFF;
    val = pADC->ADC_LCDR & 0x03FF;            /* Extract AINx Value          */
  }
  return (val);
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
  /* Blink the LEDs on AT91SAM9G20 board */
  const U8 led_val[10] = { 0x03,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00 };
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
