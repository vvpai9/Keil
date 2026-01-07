/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    HTTP_DEMO.C
 *      Purpose: HTTP Server demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <RTL.h>
#include <Net_Config.h>
#include <LPC23xx.H>                          /* LPC23xx definitions         */

#define MCLK 48000000                         /* Master Clock 48 MHz         */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT (MCLK/TCLK/4)                    /* Timer Counts                */

#define I2C_AA     0x00000004
#define I2C_SI     0x00000008
#define I2C_STO    0x00000010
#define I2C_STA    0x00000020
#define I2C_I2EN   0x00000040

BOOL LEDrun;
BOOL tick;
U32  dhcp_tout;
extern LOCALM localm[];                       /* Local Machine Settings      */
#define MY_IP localm[NETIF_ETH].IpAdr
#define DHCP_TOUT   50                        /* DHCP timeout 5 seconds      */

static void init_io (void);

#ifdef RTX_KERNEL
 U64 tcp_stack[800/8];                        /* A bigger stack for tcp_task */

 /* Forward references */
 __task void init       (void);
 __task void blink_led  (void);
 __task void timer_task (void);
 __task void tcp_task   (void);
#endif

/*--------------------------- init ------------------------------------------*/

#ifndef RTX_KERNEL

static void init () {
   /* Add System initialisation code here */ 

   init_io ();
   init_TcpNet ();
   /* Timer 1 as interval timer, reload to 100ms. */
   T1TCR = 1;
   T1MCR = 3;
   T1MR0 = TCNT - 1;
}

#else

__task void init (void) {
  /* Add System initialisation code here */ 

  init_io ();
  init_TcpNet ();

  /* Initialize Tasks */
  os_tsk_prio_self (100);
  os_tsk_create (blink_led, 20);
  os_tsk_create (timer_task, 30);
  os_tsk_create_user (tcp_task, 0, &tcp_stack, sizeof(tcp_stack));
  os_tsk_delete_self();
}

#endif

/*--------------------------- timer_poll ------------------------------------*/

#ifndef RTX_KERNEL

static void timer_poll () {
  /* System tick timer running in poll mode */

  if (T1IR & 1) {
    T1IR = 1;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}

#else

__task void timer_task (void) {
  /* System tick timer task */
  os_itv_set (10);
  while (1) {
    timer_tick ();
    tick = __TRUE;
    os_itv_wait ();
  }
}

#endif


/*--------------------------- init_io ---------------------------------------*/

static void init_io () {
  PCONP    |=  (1 << 7);                     /* Enable clock for I2C0        */

  /* Configure I2C */
  PCONP    |=  0x00000080;                   /* Enable clock for I2C0        */
  PINSEL1  |=  0x01400000;
  I20CONCLR =  I2C_AA | I2C_SI | I2C_STA | I2C_I2EN;
  I20SCLL   =  0x80;                         /* Set I2C Clock speed          */
  I20SCLH   =  0x80;
  I20CONSET =  I2C_I2EN;
  I20CONSET =  I2C_STO;

  /* Configure UART1 for 115200 baud. */
  PINSEL7  |=  0x30003FFF;                   /* Enable UART1 pins            */
  U1LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit*/
  U1DLL = 3;                                 /* for 12MHz PCLK Clock         */
  U1FDR = 0x67;                              /* Fractional Divider           */
  U1LCR = 0x03;                              /* DLAB = 0                     */

  /* Configure AD0.0, AD0.1 inputs. */
  PCONP   |= 0x00001000;                     /* Enable clock for AD block    */
  PINSEL1 |= 0x00014000;                     /* AD0.0,1 pin function select  */
}


/*--------------------------- fputc -----------------------------------------*/

int fputc(int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(U1LSR & 0x20));
    U1THR = '\r';                            /* output CR                    */
  }
  while (!(U1LSR & 0x20));
  return (U1THR = ch);
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {
  U32 v;

  v = (val & 0x01) | ((val<<1) & 0x04) | ((val<<2) & 0x10) | ((val<<3) & 0x40);
  I20CONCLR = I2C_AA | I2C_SI | I2C_STA | I2C_STO;
  I20CONSET = I2C_STA;
  while (!(I20CONSET & I2C_SI));             /* Wait for START               */
  I20DAT    = 0xC0;
  I20CONCLR = I2C_SI | I2C_STA;
  while (!(I20CONSET & I2C_SI));             /* Wait for ADDRESS send        */
  I20DAT    = 0x18;
  I20CONCLR = I2C_SI;
  while (!(I20CONSET & I2C_SI));             /* Wait for DATA send           */
  I20DAT    = v;
  I20CONCLR = I2C_SI;
  while (!(I20CONSET & I2C_SI));             /* Wait for DATA send           */
  I20CONSET = I2C_STO;
  I20CONCLR = I2C_SI;
  while (I20CONSET & I2C_STO);               /* Wait for STOP                */
}

/*--------------------------- AD_in -----------------------------------------*/

U16 AD_in (U32 ch) {
  /* Read ARM Analog Input */
  U32 val = 0;
  U32 adcr;

  if (ch < 8) {
    adcr = 0x01000000 | (1 << ch);
    AD0CR = adcr | 0x00200C00;               /* Setup A/D: 10-bit @ 4MHz     */

    do {
      val = AD0GDR;                          /* Read A/D Data Register       */
    } while ((val & 0x80000000) == 0);       /* Wait for end of A/D Conv.    */
    AD0CR &= ~adcr;                          /* Stop A/D Conversion          */
    val = (val >> 6) & 0x03FF;               /* Extract AINx Value           */
  }
  return (val);
}


/*--------------------------- get_button ------------------------------------*/

U8 get_button (void) {
  /* Read ARM Digital Inputs */
  U32 val;

  I20CONCLR = I2C_AA | I2C_SI | I2C_STA | I2C_STO;
  I20CONSET = I2C_STA;
  while (!(I20CONSET & I2C_SI));             /* Wait for START               */
  I20DAT    = 0xC0;
  I20CONCLR = I2C_SI | I2C_STA;
  while (!(I20CONSET & I2C_SI));             /* Wait for ADDRESS send        */
  I20DAT    = 0x00;                          /* Select input register 0      */
  I20CONCLR = I2C_SI;
  while (!(I20CONSET & I2C_SI));             /* Wait for DATA send           */
  I20CONSET = I2C_STA;
  I20CONCLR = I2C_SI;
  while (!(I20CONSET & I2C_SI));             /* Wait for START               */
  I20DAT    = 0xC1;                          /* Read from device 0xC0        */
  I20CONCLR = I2C_SI | I2C_STA;
  while (!(I20CONSET & I2C_SI));             /* Wait for ADDRESS send        */
  I20CONCLR = I2C_SI;
  while (!(I20CONSET & I2C_SI));             /* Wait for DATA received       */
  val = I20DAT;                              /* Read data                    */

  I20CONSET = I2C_STO;
  I20CONCLR = I2C_SI;
  while (I20CONSET & I2C_STO);               /* Wait for STOP                */

  return (~val & 0x0F);
}


/*--------------------------- dhcp_check ------------------------------------*/

static void dhcp_check () {
  /* Monitor DHCP IP address assignment. */

  if (tick == __FALSE || dhcp_tout == 0) {
    return;
  }
#ifdef RTX_KERNEL
  tick = __FALSE;
#endif
  if (mem_test (&MY_IP, 0, IP_ADRLEN) == __FALSE) {
    /* Success, DHCP has already got the IP address. */
    dhcp_tout = 0;
    return;
  }
  if (--dhcp_tout == 0) {
    /* A timeout, disable DHCP and use static IP address. */
    dhcp_disable ();
    return;
  }
}


/*--------------------------- blink_led -------------------------------------*/

#ifndef RTX_KERNEL

static void blink_led () {
  /* Blink the LEDs on MCB2400 board */
  const U8 led_val[8] = { 0x01,0x03,0x07,0x0F,0x0E,0x0C,0x08,0x00 };
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

#else

__task void blink_led () {
  /* Blink the LEDs on MCB2400 board */
  const U8 led_val[8] = { 0x01,0x03,0x07,0x0F,0x0E,0x0C,0x08,0x00 };
  static U32 cnt;

  LEDrun = __TRUE;
  while(1) {
    /* Every 100 ms */
    if (LEDrun == __TRUE) {
      LED_out (led_val[cnt]);
      if (++cnt >= sizeof(led_val)) {
        cnt = 0;
      }
    }
    os_dly_wait(10);
  }
}

#endif


/*---------------------------------------------------------------------------*/

#ifndef RTX_KERNEL

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  LEDrun = __TRUE;
  dhcp_tout = DHCP_TOUT;
  while (1) {
    timer_poll ();
    main_TcpNet ();
    dhcp_check ();
    blink_led ();
  }
}

#else

__task void tcp_task (void) {
  /* Main Thread of the TcpNet. This task should have */
  /* the lowest priority because it is always READY. */
  dhcp_tout = DHCP_TOUT;
  while (1) {
    main_TcpNet();
    dhcp_check ();
    os_tsk_pass();
  }
}


int main (void) {
  /* Start with 'init' task. */
  os_sys_init(init);
  while(1);
}

#endif


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
