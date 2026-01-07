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
#include <LPC23xx.H>                    /* LPC23xx definitions               */

#define MCLK 48000000                         /* Master Clock 48 MHz         */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT (MCLK/TCLK/4)                    /* Timer Counts                */

#define I2C_AA     0x00000004
#define I2C_SI     0x00000008
#define I2C_STO    0x00000010
#define I2C_STA    0x00000020
#define I2C_I2EN   0x00000040

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


/*--------------------------- LED_out ---------------------------------------*/

static void LED_out (U32 val) {
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

/*--------------------------- fputc -----------------------------------------*/

int fputc(int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(U2LSR & 0x20));
    U2THR = '\r';                            /* output CR                    */
  }
  while (!(U2LSR & 0x20));
  return (U2THR = ch);
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
        LED_out (p2val);
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
