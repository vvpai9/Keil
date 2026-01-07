/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    CLIENT.C
 *      Purpose: LED Control Client demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <RTL.h>
#include <stdio.h>
#include <AT91SAM7X256.H>                     /* AT91SAM7X256 definitions    */
#include "AT91SAM7X-EK.h"

/* Clock Definitions */
#define EXT_OSC 18432000                      /*  External Oscillator MAINCK */
#define MCK     47923200                      /*  Master Clock               */
#define BAUD(b) ((MCK + 8*b)/(16*b))
#define TCNT    (MCK/16)/10                   /* Timer Counts for 100ms      */

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

//   <o>Communication Protocol <0=> TCP <1=> UDP
//   <i> Selecet a protocol for sending data.
#define PROTOCOL       1

//   <o>LED Blinking speed <1-100>
//   <i> Blinking speed = SPEED * 100ms
//   <i> Default: 2
#define SPEED          2


//------------- <<< end of configuration section >>> -----------------------


#define BLINKLED 0x01  /* Command for blink the leds on board */
#define SENDLEN  2     /* Number of bytes to send */
#define TCP      0
#define UDP      1

BOOL tick;
U8 socket_tcp;
U8 socket_udp;
U8 Rem_IP[4] = {IP1,IP2,IP3,IP4};


/*--------------------------- init ------------------------------------------*/

static void init () {
  /* Add System initialisation code here */

  *AT91C_PMC_PCER  = (1 << AT91C_ID_PIOB);   /* Enable Clock for PIO         */
  *AT91C_PIOB_PER  = AT91B_LED_MASK;         /* Enable PIO for LED1..4       */
  *AT91C_PIOB_OER  = AT91B_LED_MASK;         /* LED1..4 are Outputs          */
  *AT91C_PIOB_SODR = AT91B_LED_MASK;         /* Turn off LED's ("1")         */

  /* Timer 1 reload to 100ms */
  *AT91C_PITC_PIMR = (TCNT - 1) | AT91C_PITC_PITEN;

  /* Configure DBGU for 115200 baud. */
  *AT91C_PIOA_IDR  =
  *AT91C_PIOA_PPUDR=
  *AT91C_PIOA_ASR  =
  *AT91C_PIOA_PDR  = AT91C_PA27_DRXD | AT91C_PA28_DTXD;

  *AT91C_DBGU_CR   = AT91C_US_RSTRX   | AT91C_US_RSTTX;
  *AT91C_DBGU_IDR  = 0xFFFFFFFF;
  *AT91C_DBGU_BRGR = BAUD(115200);
  *AT91C_DBGU_MR   = AT91C_US_PAR_NONE;
  *AT91C_DBGU_PTCR = AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS;
  *AT91C_DBGU_CR   = AT91C_US_RXEN    | AT91C_US_TXEN;
}


/*--------------------------- timer_poll ------------------------------------*/

static void timer_poll () {
  /* System tick timer running in poll mode */
  volatile U32 val;

  if (*AT91C_PITC_PISR & 1) {
    val = *AT91C_PITC_PIVR;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}


/*--------------------------- fputc -----------------------------------------*/

int fputc(int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(*AT91C_DBGU_CSR & AT91C_US_TXRDY));
    *AT91C_DBGU_THR = '\r';                 /* output CR                    */
  }
  while (!(*AT91C_DBGU_CSR & AT91C_US_TXRDY));
  *AT91C_DBGU_THR = ch;
  return (ch);
}


/*--------------------------- UDP socket ------------------------------------*/

U16 udp_callback (U8 soc, U8 *rip, U16 rport, U8 *buf, U16 len) {
  /* This function is called by the UDP module when UDP packet is received. */

  /* Make a reference to suppress compiler warnings. */
  buf  = buf;
  rip  = rip;
  rport= rport;
  len  = len;
  soc  = soc;
  return (0);
}


/*--------------------------- TCP socket ------------------------------------*/

U16 tcp_callback (U8 soc, U8 evt, U8 *ptr, U16 par) {
  /* This function is called by the TCP module on TCP event */
  /* Check the Net_Config.h for possible events.            */

  /* Make a reference to suppress compiler warnings. */
  soc = soc;
  par = par;
  evt = evt;
  ptr = ptr;
  return (0);
}


/*--------------------------- TCP send --------------------------------------*/

void send_data (U8 p2val) {
  U8 *sendbuf;
  U8 p2;

  /* UDP */
  if (socket_udp != 0) {
    /* Start Connection */
    sendbuf = udp_get_buf (SENDLEN);
    sendbuf[0] = BLINKLED;
    sendbuf[1] = p2val;
    udp_send (socket_udp, Rem_IP, 1001, sendbuf, SENDLEN);
  }

  /* TCP */
  if (socket_tcp != 0) {
    /* Start Connection */
    p2 = p2val;
    switch (tcp_get_state(socket_tcp)) {
      case TCP_STATE_FREE:
      case TCP_STATE_CLOSED:
        tcp_connect (socket_tcp, Rem_IP, PORT_NUM, 0);
        break;
      case TCP_STATE_CONNECT:
        if (tcp_check_send (socket_tcp) == __TRUE) {
          sendbuf = tcp_get_buf(SENDLEN);
          sendbuf[0] = BLINKLED;
          sendbuf[1] = p2;
          tcp_send (socket_tcp, sendbuf, SENDLEN);
        }
        break;
    }
  }
}


/*--------------------------- main ------------------------------------------*/

int main (void) {
  /* Main Thread of the TcpNet */
  U8 p2val, cnt, lshf;
  U8 protocol;

  init ();
  init_TcpNet ();

  protocol = PROTOCOL;
  switch (protocol) {
    case TCP:
      socket_tcp = tcp_get_socket (TCP_TYPE_CLIENT, 0, 10, tcp_callback);
      break;
    case UDP:
      socket_udp = udp_get_socket (0, UDP_OPT_SEND_CS | UDP_OPT_CHK_CS, udp_callback);
      if (socket_udp != 0) {
        udp_open (socket_udp, PORT_NUM);
      }
      break;
  }

  p2val = 1;
  cnt   = 0;
  lshf  = 1;  /* left shift */
  while (1) {
    timer_poll ();
    main_TcpNet ();
    if (tick == __TRUE) {
      if (++cnt == SPEED) {
        *AT91C_PIOB_SODR = AT91B_LED_MASK;
        if (p2val & 1) {
          *AT91C_PIOB_CODR = AT91B_LED4;           /* Turn LED4 On           */
        }
        if (p2val & 2) {
          *AT91C_PIOB_CODR = AT91B_LED3;           /* Turn LED3 On           */
        }
        if (p2val & 4) {
          *AT91C_PIOB_CODR = AT91B_LED2;           /* Turn LED2 On           */
        }
        if (p2val & 8) {
          *AT91C_PIOB_CODR = AT91B_LED1;           /* Turn LED1 On           */
        }
        send_data(p2val);
        p2val = lshf ? (p2val << 1) : (p2val >> 1);
        if (p2val == 0x80) lshf = 0;
        if (p2val == 0x01) lshf = 1;
        cnt = 0;
      }
      tick = __FALSE;
    }
  }
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
