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
#include <LPC325x.h>

#define LED_1    0x0002
#define LED_2    0x4000
#define LED_ALL  0x4002

#define PORT_NUM 1001
#define BLINKLED 0x01                   /* Command for blink the leds        */

U64 stack[3][600/8];                    /* Stack for networking tasks        */


/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  /* Configure UART5 for 115200 baud. */
  U5LCR = 0x83;                              /* 8 bits, no Parity, 1 Stop bit*/
  U5DLM = 0;
  U5DLL = 7;                                 /* for 13MHz PERIPH_CLK Clock   */
  U5LCR = 0x03;                              /* DLAB = 0                     */
  U5CLK = 0x0101;                            /* X/Y Divider set to 1         */
  UART_CLKMODE = 0x0200;                     /* UART5 Clock ON mode          */
}


/*--------------------------- fputc -----------------------------------------*/

int fputc (int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(U5LSR & 0x20));
    U5THR = '\r';                            /* output CR                    */
  }
  while (!(U5LSR & 0x20));
  return (U5THR = ch);
}


/*--------------------------- procrec ---------------------------------------*/

void procrec (U8 *buf) {
  /* Process received data */
  switch (buf[0]) {
    case BLINKLED:
      if (buf[1] & 1) {
        P3_OUTP_SET = LED_1;
      }
      else {
        P3_OUTP_CLR = LED_1;
      }
      if (buf[1] & 2) {
        P3_OUTP_SET = LED_2;
      }
      else {
        P3_OUTP_CLR = LED_2;
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
