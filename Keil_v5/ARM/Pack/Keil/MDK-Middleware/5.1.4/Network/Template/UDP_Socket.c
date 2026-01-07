/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network:Service
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    UDP_Socket.c
 * Purpose: UDP Socket Code Template
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/
//! [code_UDP_Socket]
#include "rl_net.h"
 
#define BLINK_LED   1
#define PORT_NUM    2000
 
int32_t udp_sock;
 
// Destination IP address
uint8_t dest_ip[4] = { 192, 168, 0 ,100 };
 
// Notify the user application about UDP socket events.
uint32_t udp_cb_func (int32_t socket, const uint8_t *ip_addr, uint16_t port, const uint8_t *buf, uint32_t len) {

  // Data received
  /* Example
  if ((buf[0] == BLINK_LED) && (len == 2)) {
    // Switch LEDs on and off
    // LED_out (buf[1]);
  }
  */
  return (0);
}
 
// Send UDP data to destination client
void send_data (void) {

  if (udp_sock > 0) {
    /* Example
    uint8_t *sendbuf;
    sendbuf = udp_get_buf (2);
    sendbuf[0] = BLINK_LED;
    sendbuf[1] = 0xAA;
    udp_send (udp_sock, dest_ip, PORT_NUM, sendbuf, 2);
    */
  }
}
 
// Allocate and initialize the socket.
/* Example
int main (void) {

  net_initialize ();

  // Allocate a free UDP socket.
  udp_sock = udp_get_socket (0, UDP_OPT_SEND_CHECKSUM | UDP_OPT_VERIFY_CHECKSUM, udp_cb_func);
  if (udp_sock > 0) {
    udp_open (udp_sock, PORT_NUM);
  }

  while(1) {
    net_main ();
    osThreadYield ();
  }
}
*/
//! [code_UDP_Socket]
