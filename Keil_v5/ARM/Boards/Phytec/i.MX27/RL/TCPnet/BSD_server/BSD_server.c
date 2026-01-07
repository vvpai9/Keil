/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    BSD_SERVER.C
 *      Purpose: LED Server demo example using BSD socket interface
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <stdio.h>
#include <iMX27.h>

#define LED_PIN  (1 << 18)

#define PORT_NUM 1001
#define BLINKLED 0x01                   /* Command for blink the leds        */

U64 stack[3][600/8];                    /* Stack for networking tasks        */


/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

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


/*--------------------------- procrec ---------------------------------------*/

void procrec (U8 *buf) {
  /* Process received data */
  switch (buf[0]) {
    case BLINKLED:
      if (buf[1] & 1) {
        GPIO_PTE_DR |= LED_PIN;
      }
      else {
        GPIO_PTE_DR &= ~LED_PIN;
      }
      break;
  }
}


/*--------------------------- server ----------------------------------------*/

__task void server (void *argv) {
  /* Server task runs in 2 instances. */
  SOCKADDR_IN addr;
  int sock, sd, res;
  int type = (int)argv;
  char dbuf[4];

  while (1) {
    sock = socket (AF_INET, type, 0);

    addr.sin_port        = htons(PORT_NUM);
    addr.sin_family      = PF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;

    bind (sock, (SOCKADDR *)&addr, sizeof(addr));

    if (type == SOCK_STREAM) {
      listen (sock, 1);
      sd = accept (sock, NULL, NULL);
      closesocket (sock);
      sock = sd;
    }

    while (1) {
      res = recv (sock, dbuf, sizeof (dbuf), 0);
      if (res <= 0) {
        break;
      }
      procrec ((U8 *)dbuf);
    }
    closesocket (sock);
  }
}


/*--------------------------- timer_task ------------------------------------*/

__task void timer_task (void) {
  /* TCPnet timebase task. */

  os_itv_set (10);
  while (1) {
    /* 100 ms interval */
    timer_tick ();
    os_itv_wait ();
  }
}


/*--------------------------- net_task --------------------------------------*/

__task void net_task (void) {
  /* TCPnet engine task */

  /* Init peripherals and TCPnet stack. */
  init ();
  init_TcpNet ();

  /* Create networking tasks. */
  os_tsk_create (timer_task, 10);

  /* Server task is created in 2 instances */
  os_tsk_create_user_ex (server, 2, &stack[1], sizeof(stack[1]), (void *)SOCK_STREAM);
  os_tsk_create_user_ex (server, 2, &stack[2], sizeof(stack[2]), (void *)SOCK_DGRAM);

  while (1) {
    main_TcpNet ();
    os_tsk_pass ();
  }
}

/*--------------------------- main ------------------------------------------*/

int main (void) {

  os_sys_init_user (net_task, 1, &stack[0], sizeof(stack[0]));
  for (;;);
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
