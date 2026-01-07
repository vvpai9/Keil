/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    TFTP_DEMO.C 
 *      Purpose: TFTP Server demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <LPC23xx.H>                    /* LPC23xx definitions               */

#define MCLK 48000000                         /* Master Clock 48 MHz         */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT (MCLK/TCLK/4)                    /* Timer Counts                */

#define I2C_AA     0x00000004
#define I2C_SI     0x00000008
#define I2C_STO    0x00000010
#define I2C_STA    0x00000020
#define I2C_I2EN   0x00000040

BOOL tick;

/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  PCONP    |=  (1 << 7);                     /* Enable clock for I2C0        */

  /* Configure I2C */
  PCONP    |=  0x00000080;                   /* Enable clock for I2C0        */
  PINSEL1  &= ~0x03C00000;
  PINSEL1  |=  0x01400000;
  I20CONCLR =  I2C_AA | I2C_SI | I2C_STA | I2C_I2EN;
  I20SCLL   =  0x80;                         /* Set I2C Clock speed          */
  I20SCLH   =  0x80;
  I20CONSET =  I2C_I2EN;
  I20CONSET =  I2C_STO;

  /* Timer 1 as interval timer, reload to 100ms. */
  T1TCR = 1;
  T1MCR = 3;
  T1MR0 = TCNT - 1;

  /* Configure UART2 for 115200 baud. */
  PCONP   |= (1 <<24);                       /* Enable UART2 power           */
  PINSEL0 &= ~0x00F00000;
  PINSEL0 |=  0x00500000;                    /* Enable TxD2 and RxD2         */
  U2LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit*/
  U2DLL = 3;                                 /* for 12MHz PCLK Clock         */
  U2FDR = 0x67;                              /* Fractional Divider           */
  U2LCR = 0x03;                              /* DLAB = 0                     */
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {
  U32 v;

  v = (val & 0x01) | ((val << 1) & 0x04) | ((val << 2) & 0x10) | ((val << 3) & 0x40);
  I20CONCLR =  I2C_AA | I2C_SI | I2C_STA | I2C_STO;
  I20CONSET =  I2C_STA;
  while (!(I20CONSET & I2C_SI));        /* Wait for START                    */
  I20DAT    =  0xC0;
  I20CONCLR =  I2C_SI | I2C_STA;
  while (!(I20CONSET & I2C_SI));        /* Wait for ADDRESS send             */
  I20DAT    =  0x18;
  I20CONCLR =  I2C_SI;
  while (!(I20CONSET & I2C_SI));        /* Wait for DATA send                */
  I20DAT    =  v;
  I20CONCLR =  I2C_SI;
  while (!(I20CONSET & I2C_SI));        /* Wait for DATA send                */
  I20CONSET =  I2C_STO;
  I20CONCLR =  I2C_SI;
  while (I20CONSET & I2C_STO);          /* Wait for STOP                     */
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


/*--------------------------- sendchar --------------------------------------*/

int sendchar (int ch)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(U2LSR & 0x20));
    U2THR = '\r';                            /* output CR                    */
  }
  while (!(U2LSR & 0x20));
  return (U2THR = ch);
}


/*--------------------------- getkey ----------------------------------------*/

int getkey (void) {
  /* A dummy function for 'retarget.c' */
  return (0);
}


/*--------------------------- blink_led -------------------------------------*/

static void blink_led () {
  /* Blink the LEDs on MCB2470 board */
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


/*---------------------------------------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  init_TcpNet ();
  finit (NULL);
  fformat ("");

  while (1) {
    timer_poll ();
    main_TcpNet ();
    blink_led ();
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
