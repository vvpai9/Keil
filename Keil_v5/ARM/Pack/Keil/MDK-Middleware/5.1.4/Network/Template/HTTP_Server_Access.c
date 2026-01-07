/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network:Service
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    HTTP_Server_Access.c
 * Purpose: HTTP Server Access Interface
 * Rev.:    V5.04
 *----------------------------------------------------------------------------*/
//! [code_HTTP_Server_Access]
#include "rl_net.h"
 
// Accept or deny connection from remote HTTP client.
// If this function is missing, all remote clients are accepted.
bool http_accept_client (const uint8_t *ip_addr, uint16_t port) {
  /* Example
  if (ip_addr[0] == 192  &&
      ip_addr[1] == 168  &&
      ip_addr[2] == 0    &&
      ip_addr[3] == 1) {
    // Accept connection.
    return (true);
  }
  // Deny connection.
  return (false);
  */
  return (true);
}
//! [code_HTTP_Server_Access]
