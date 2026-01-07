/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network:Service
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    TCP_Socket_Server.c
 * Purpose: TCP Socket Server Code Template
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/
//! [code_TCP_Socket_Server]
#include "rl_net.h"
 
#define BLINK_LED   1
#define PORT_NUM    2000
 
int32_t tcp_sock;
 
// Notify the user application about TCP socket events.
uint32_t tcp_cb_func (int32_t socket, tcpEvent event, const uint8_t *buf, uint32_t len) {

  switch (event) {
    case tcpEventConnect:
      // Connect request received
      /* Example
      if (buf[0] == 192  &&
          buf[1] == 168  &&
          buf[2] == 0    &&
          buf[3] == 1) {
        // Accept connection.
        return (1);
      }
      // Deny connection.
      return (0);
      */
      return (1);

    case tcpEventEstablished:
      // Connection established
      break;

    case tcpEventClosed:
      // Connection was properly closed
      break;

    case tcpEventAbort:
      // Connection is for some reason aborted
      break;

    case tcpEventACK:
      // Previously sent data acknowledged
      break;

    case tcpEventData:
      // Data received
      /* Example
      if ((buf[0] == BLINK_LED) && (len == 2)) {
        // Switch LEDs on and off
        // LED_out (buf[1]);
      }
      */
      break;
  }
  return (0);
}
 
// Allocate and initialize the socket.
/* Example
int main (void) {

  net_initialize ();

  // Initialize TCP Socket and start listening.
  tcp_sock = tcp_get_socket (TCP_TYPE_SERVER, 0, 10, tcp_cb_func);
  if (tcp_sock > 0) {
    tcp_listen (tcp_sock, PORT_NUM);
  }

  while(1) {
    net_main ();
    osThreadYield ();
  }
}
*/
//! [code_TCP_Socket_Server]
