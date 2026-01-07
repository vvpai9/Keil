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
#include <iMX27.h>

#define LED_PIN  (1 << 18)

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

  /* General Purpose Timer 1 as interval timer, reload to 100ms. */
  GPT1_TCTL   = 0x0412;
  GPT1_TPRER  = 0;                           /* prescaler 1                  */
  GPT1_TCMP   = 1400000;                     /* 100mSec & PCLK1 = 14 MHz     */
  GPT1_TCTL  |= 0x0001;
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

  if (GPT1_TSTAT & 1) {
    /* GPT1 Timer irq pending, clear pending interrupt. */
    GPT1_TSTAT = 1;

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

  /* Configure UART1 for 115200 baud, 8 data bits, no parity, 1 stop bit.   */
  /* ipg_perclk1 = 266/19 = 14 MHz                                          */
  /* baud rate   = 14 MHz / (16*4375/576) = 115200 baud                     */
  UART1_UFCR    |= (5 << 7);                /* ref_clk = ipg_perclk1        */
  UART1_UBIR     = 576 - 1;
  UART1_UBMR    |= 4375 - 1;
  UART1_UCR2    |= (1 << 5);
}


/*--------------------------- fputc -----------------------------------------*/

int fputc(int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(UART1_USR2 & (1 << 3)));
    UART1_UTXD = '\r';
  }
  while (!(UART1_USR2 & (1 << 3)));
  return (UART1_UTXD = ch);
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
  }
}


/*--------------------------- blink_led -------------------------------------*/

#ifndef RTX_KERNEL

static void blink_led () {
  /* Blink the LEDs on phyCore board */
  static U32 cnt = 0;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    if (LEDrun == __TRUE) {
      if (++cnt == 5) cnt = 0;
      LED_out (cnt >> 2);
     }
  }
}

#else

__task void blink_led () {
  /* Blink the LEDs on phyCore board */
  U32 cnt = 0;

  LEDrun = __TRUE;
  while(1) {
    /* Every 100 ms */
    if (LEDrun == __TRUE) {
      if (++cnt == 5) cnt = 0;
      LED_out (cnt >> 2);
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
