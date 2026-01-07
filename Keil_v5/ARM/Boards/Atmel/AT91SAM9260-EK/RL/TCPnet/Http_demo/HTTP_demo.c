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
#include <AT91SAM9260.H>                      /* AT91SAM9260 definitions     */
#include "Board.h"

#define TCNT    (MCK/16)/10                   /* Timer Counts for 100ms      */

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
  /* PITC Timer interval timer, reload to 100ms */
  pPITC->PITC_PIMR = (TCNT - 1) | AT91C_PITC_PITEN;
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
  volatile U32 val;

  if (pPITC->PITC_PISR & 1) {
    val = pPITC->PITC_PIVR;
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
  /* I/O Ports configured as Output. */
  pPMC->PMC_PCER  = (1 << AT91C_ID_PIOB) |  /* Enable Clock for PIO         */
                    (1 << AT91C_ID_PIOA);   /* (LEDs, DBGU, Push Buttons)   */
  pPIOA->PIO_IDR  = 
  pPIOA->PIO_PER  = LED_MASK | PB_MASK;     /* Enable PIO for LEDs and PBs  */
  pPIOA->PIO_ODR  = PB_MASK;                /* PBs are Inputs               */
  pPIOA->PIO_OER  = LED_MASK;               /* LEDs are Outputs             */
  pPIOA->PIO_SODR = LED1;                   /* Turn off LED ("1")           */

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


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {

  val ^= 0x02;                                /* LED2 output is inverted      */
  pPIOA->PIO_SODR = LED_MASK;
  if (val & 1) {
    pPIOA->PIO_CODR = LED1;                  /* Turn LED1 On                 */
  }
  if (val & 2) {
    pPIOA->PIO_CODR = LED2;                  /* Turn LED2 On                 */
  }
}


/*--------------------------- get_button ------------------------------------*/

U8 get_button (void) {
  /* Read ARM Digital Input */
  U32 key,val = 0;

  key = pPIOA->PIO_PDSR;
  if ((key & PB1) == 0) {
    /* Check if PB1 is pressed */
    val |= 0x01;
  }
  if ((key & PB2) == 0) {
    /* Check if PB2 is pressed */
    val |= 0x02;
  }
  return (val);
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
  /* Blink the LED on AT91SAM9260 board */
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

#else

__task void blink_led () {
  /* Blink the LED on AT91SAM9260 board */
  const U8 led_val[10] = { 0x03,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00 };
  U32 cnt = 0;

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
