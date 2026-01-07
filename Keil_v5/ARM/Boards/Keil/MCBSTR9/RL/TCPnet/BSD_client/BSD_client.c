/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    BSD_CLIENT.C
 *      Purpose: LED Client demo example using BSD socket interface
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <stdio.h>
#include <91x_lib.h>                    /* STR912F definitions               */
#include "LCD.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

//   <h>Remote IP Address
//   ====================
//
//     <o>IP1: Address byte 1 <0-255>
//     <i> Default: 192
#define IP1            192

//     <o>IP2: Address byte 2 <0-255>
//     <i> Default: 168
#define IP2            168

//     <o>IP3: Address byte 3 <0-255>
//     <i> Default: 0
#define IP3            0

//     <o>IP4: Address byte 4 <0-255>
//     <i> Default: 100
#define IP4            100

//   </h>

//   <o>Remote Port <1-65535>
//   <i> Do not set number of port too small,
//   <i> maybe it is already used.
//   <i> Default: 1001
#define PORT_NUM       1001

//   <o>Communication Protocol <0=> Stream (TCP) <1=> Datagram (UDP)
//   <i> Selecet a protocol for sending data.
#define PROTOCOL       1

//   <o>LED Blinking speed <1-100>
//   <i> Blinking speed = SPEED * 100ms
//   <i> Default: 2
#define SPEED          2

//------------- <<< end of configuration section >>> -----------------------

#define BLINKLED 0x01                   /* Command for blink the leds        */
#if (PROTOCOL == 0)
 #define SOCKTYPE   SOCK_STREAM
#else
 #define SOCKTYPE   SOCK_DGRAM
#endif

U64 stack[2][600/8];                    /* Stack for networking tasks        */


/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  /* I/O Ports configured as Output (Push-pull) */
  SCU->GPIOOUT[7]  = 0x5555;
  GPIO7->DDR       = 0xFF;
  GPIO7->DR[0x3FC] = 0x00;

  /* UART1 configured for 115200 baud. */
  SCU->GPIOOUT[3] &= 0xFF3F;                 /* Enable TX1 and RX1 pins      */
  SCU->GPIOOUT[3] |= 0x0080;
  SCU->GPIOIN[3]  |= 0x04;
  UART1->IBRD = 0x1A;                        /* Integer divider for 115kBaud */
  UART1->FBRD = 0x03;                        /* Fractional divider           */
  UART1->LCR  = 0x0060;                      /* 8 bits, no Parity, 1 Stop bit*/
  UART1->CR   = 0x0301;                      /* Enable UART                  */
}


/*--------------------------- init_display ----------------------------------*/

static void init_display () {
  /* LCD Module.2x16 init*/

  LCD_init ();
  LCD_cur_off ();
  LCD_puts ("    RL-ARM      "
            "BSD Client exam.");
}


/*--------------------------- fputc -----------------------------------------*/

int fputc (int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(UART1->FR & 0x0080));
    UART1->DR = '\r';                        /* output CR                    */
  }
  while (!(UART1->FR & 0x0080));
  return (UART1->DR = ch);
}


/*--------------------------- client ----------------------------------------*/

__task void client (void) {
  /* LED Control client task. */
  SOCKADDR_IN addr;
  int sock, res;
  char dbuf[4];
  U8 p2val,lshf;

  while (1) {
    sock = socket (AF_INET, SOCKTYPE, 0);

    addr.sin_port      = htons(PORT_NUM);
    addr.sin_family    = PF_INET;
    addr.sin_addr.s_b1 = IP1;
    addr.sin_addr.s_b2 = IP2;
    addr.sin_addr.s_b3 = IP3;
    addr.sin_addr.s_b4 = IP4;

    connect (sock, (SOCKADDR *)&addr, sizeof (addr));

    lshf  = 1;
    p2val = 0x01;
    while (1) {
      /* Shift the LEDs */
      GPIO7->DR[0x3FC] = p2val;
      p2val = lshf ? (p2val << 1) : (p2val >> 1);
      if (p2val == 0x80) lshf = 0;
      if (p2val == 0x01) lshf = 1;
    
      /* Send the data to LED Server. */
      dbuf[0] = BLINKLED;
      dbuf[1] = p2val;
      res = send (sock, (char *)&dbuf, 2, 0);
      if (res < 0) {
        break;
      }
      os_dly_wait (10 * SPEED);
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
  init_display ();
  init_TcpNet ();

  /* Create networking tasks. */
  os_tsk_create (timer_task, 10);
  os_tsk_create_user (client, 2, &stack[1], sizeof(stack[1]));

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
