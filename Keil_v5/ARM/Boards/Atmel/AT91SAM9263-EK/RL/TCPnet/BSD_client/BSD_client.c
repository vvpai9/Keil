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
#include <AT91SAM9263.H>                      /* AT91SAM9263 definitions     */
#include "Board.h"

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
}


/*--------------------------- fputc -----------------------------------------*/

int fputc (int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(pDBGU->DBGU_CSR & AT91C_US_TXRDY));
    pDBGU->DBGU_THR = '\r';                 /* output CR                    */
  }
  while (!(pDBGU->DBGU_CSR & AT91C_US_TXRDY));
  pDBGU->DBGU_THR = ch;
  return (ch);
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
      if (p2val & 1) {
        pPIOB->PIO_CODR = LED1;                  /* Turn LED1 On             */
      }
      else {
        pPIOB->PIO_SODR = LED1;
      }
      if (p2val & 2) {
        pPIOC->PIO_CODR = LED2;                  /* Turn LED2 On             */
      }
      else {
        pPIOC->PIO_SODR = LED2;
      }
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
