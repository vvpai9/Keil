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
#include <LPC23xx.H>                    /* LPC23xx definitions               */

#define MCLK 48000000                         /* Master Clock 48 MHz         */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT (MCLK/TCLK/4)                    /* Timer Counts                */

#define I2C_AA     0x00000004
#define I2C_SI     0x00000008
#define I2C_STO    0x00000010
#define I2C_STA    0x00000020
#define I2C_I2EN   0x00000040

U8 socket_tcp;
U8 socket_udp;

#define PORT_NUM 1001
#define BLINKLED 0x01  // Command for blink the leds on board

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


/*--------------------------- Process received data  ------------------------*/

void procrec (U8 *buf) {
  switch (buf[0]) {
    case BLINKLED:
      LED_out (buf[1]);
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
