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
#include <LPC23xx.H>                    /* LPC23xx definitions               */
#include "LCD.h"

#define MCLK 48000000                         /* Master Clock 48 MHz         */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT (MCLK/TCLK/4)                    /* Timer Counts                */


BOOL tick;
BOOL LEDrun;
BOOL LCDupdate;
U8   lcd_text[2][16+1] = {"    RL-ARM",       /* Buffer for LCD text         */
                          " Telnet example"};


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

  /* Enable AD Converter. */
  PCONP  |= 0x00001000;
  PINSEL1|= 0x002A4000;                      /* AD0.0..3 pin function select */
  PINSEL3|= 0x00000000;                      /* AD0.4..5 pin function select */
  PINSEL0|= 0x0F000000;                      /* AD0.6..7 pin function select */

  LEDrun = __TRUE;
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {
  FIO2SET =  val;
  FIO2CLR = ~val;
}


/*--------------------------- upd_display -----------------------------------*/

static void upd_display () {
  /* Update LCD Module display text. */

  LCD_cls ();
  LCD_puts (lcd_text[0]);
  LCD_gotoxy (1,2);
  LCD_puts (lcd_text[1]);
  LCDupdate =__FALSE;
}


/*--------------------------- init_display ----------------------------------*/

static void init_display () {
  /* LCD Module.2x16 init*/

  LCD_init ();
  LCD_cur_off ();
  upd_display ();
}


/*--------------------------- AD_in -----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */
  U32 val = 0;
  U32 adcr;

  if (ch < 8) {
    adcr = 0x01000000 | (1 << ch);
    AD0CR = adcr | 0x00200C00;                /* Setup A/D: 10-bit @ 4MHz  */

    do {
      val = AD0GDR;                           /* Read A/D Data Register    */
    } while ((val & 0x80000000) == 0);        /* Wait for end of A/D Conv. */
    AD0CR &= ~adcr;                           /* Stop A/D Conversion       */
    val = (val >> 6) & 0x03FF;                /* Extract AINx Value        */
  }
  return (val);
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


/*--------------------------- fputc -----------------------------------------*/

int fputc (int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(U1LSR & 0x20));
    U1THR = '\r';                            /* output CR                    */
  }
  while (!(U1LSR & 0x20));
  return (U1THR = ch);
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
    if (LEDrun == __TRUE) {
      LED_out (led_val[cnt]);
      if (++cnt >= sizeof(led_val)) {
        cnt = 0;
      }
    }
    if (LCDupdate == __TRUE) {
      upd_display ();
    }
  }
}


/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  init_display ();
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
