/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    LEDSWITCH.C
 *      Purpose: LED Control Server demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <stdio.h>
#include <AT91SAM9G20.H>                      /* AT91SAM9G20 definitions     */
#include "Board.h"

#define TCNT    (MCK/16)/10                   /* Timer Counts for 100ms      */

U8 socket_tcp;
U8 socket_udp;

#define PORT_NUM 1001
#define BLINKLED 0x01  // Command for blink the leds on board

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
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */
  volatile U32 val;

  if (pPITC->PITC_PISR & 1) {
    val = pPITC->PITC_PIVR;
    /* Timer tick every 100 ms */
    timer_tick ();
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


/*--------------------------- Process received data  ------------------------*/

void procrec (U8 *buf) {
  switch (buf[0]) {
    case BLINKLED:
      pPIOA->PIO_SODR = LED_MASK;
      if (buf[1] & 1) {
        pPIOA->PIO_CODR = LED1;                  /* Turn LED1 On             */
      }
      if (!(buf[1] & 2)) {
        pPIOA->PIO_CODR = LED2;                  /* Turn LED2 Off (inverted) */
      }
      break;
  }
}

/*--------------------------- UDP socket ------------------------------------*/

U16 udp_callback (U8 soc, U8 *rip, U16 rport, U8 *buf, U16 len) {
  rip  = rip;
  rport= rport;
  len  = len;

  if (soc != socket_udp) {
    /* Check if this is the socket we are connected to */
    return (0);
  }
  procrec(buf);
  return (0);
}

/*--------------------------- TCP socket ------------------------------------*/

U16 tcp_callback (U8 soc, U8 evt, U8 *ptr, U16 par) {
  /* This function is called by the TCP module on TCP event */
  /* Check the 'Net_Config.h' for possible events.          */
  par = par;

  if (soc != socket_tcp) {
    return (0);
  }

  switch (evt) {
    case TCP_EVT_DATA:
      /* TCP data frame has arrived, data is located at *par1, */
      /* data length is par2. Allocate buffer to send reply.   */
      procrec(ptr);
      break;

    case TCP_EVT_CONREQ:
      /* Remote peer requested connect, accept it */
      return (1);

    case TCP_EVT_CONNECT:
      /* The TCP socket is connected */
      return (1);
  }
  return (0);
}


/*--------------------------- main ------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */

  init ();
  init_TcpNet ();

  /* Initialize UDP Socket and start listening */
  socket_udp = udp_get_socket (0, UDP_OPT_SEND_CS | UDP_OPT_CHK_CS, udp_callback);
  if (socket_udp != 0) {
    udp_open (socket_udp, PORT_NUM);
  }

  /* Initialize TCP Socket and start listening */
  socket_tcp = tcp_get_socket (TCP_TYPE_SERVER, 0, 10, tcp_callback);
  if (socket_tcp != 0) {
    tcp_listen (socket_tcp, PORT_NUM);
  }

  while (1) {
    timer_poll ();
    main_TcpNet ();
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
