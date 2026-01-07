/* ----------------------------------------------------------------------
 * Copyright (C) 2013 ARM Limited. All rights reserved.
 *  
 * $Date:        12. Sept 2013
 * $Revision:    V1.10
 *  
 * Project:      Ethernet PHY and MAC Driver common definitions
 * -------------------------------------------------------------------- */

/* History:
 *  Version 1.10
 *    Namespace prefix ARM_ added
 *  Version 1.00
 *    Initial release
 */ 

#ifndef __DRIVER_ETH_H
#define __DRIVER_ETH_H

#include "Driver_Common.h"


/**
\brief Status code for Ethernet functions
*/
typedef enum _ARM_ETH_STATUS {
  ARM_ETH_OK                =  0,       ///< Operation succeeded
  ARM_ETH_ERROR             =  1,       ///< Unspecified error
  ARM_ETH_ERROR_UNSUPPORTED =  2        ///< Operation not supported
} ARM_ETH_STATUS;

/**
\brief Ethernet Media Interface type
*/
typedef enum _ARM_ETH_INTERFACE {
  ARM_ETH_INTERFACE_MII,                ///< Media Independent Interface (MII)
  ARM_ETH_INTERFACE_RMII,               ///< Reduced Media Independent Interface (RMII)
  ARM_ETH_INTERFACE_SMII                ///< Serial Media Independent Interface (SMII)
} ARM_ETH_INTERFACE;

/**
\brief Ethernet duplex operating mode
*/
typedef enum _ARM_ETH_DUPLEX {
  ARM_ETH_DUPLEX_HALF,                  ///< Half duplex link
  ARM_ETH_DUPLEX_FULL                   ///< Full duplex link
} ARM_ETH_DUPLEX;

/**
\brief Ethernet speed
*/
typedef enum _ARM_ETH_SPEED {
  ARM_ETH_SPEED_10M,                    ///< 10 Mbps link speed
  ARM_ETH_SPEED_100M,                   ///< 100 Mbps link speed
  ARM_ETH_SPEED_1G                      ///< 1 Gpbs link speed
} ARM_ETH_SPEED;

/**
\brief Ethernet mode
*/
typedef enum _ARM_ETH_MODE {
  ARM_ETH_MODE_AUTO_NEGOTIATE,          ///< Auto Negotiation mode
  ARM_ETH_MODE_10M_FULL_DUPLEX,         ///< 10 MBit full duplex mode
  ARM_ETH_MODE_10M_HALF_DUPLEX,         ///< 10 MBit half duplex mode
  ARM_ETH_MODE_100M_FULL_DUPLEX,        ///< 100 MBit full duplex mode
  ARM_ETH_MODE_100M_HALF_DUPLEX,        ///< 100 MBit half duplex mode
  ARM_ETH_MODE_1G_FULL_DUPLEX,          ///< 1 GBit full duplex mode
  ARM_ETH_MODE_1G_HALF_DUPLEX,          ///< 1 GBit half duplex mode
  ARM_ETH_MODE_LOOPBACK,                ///< Loop-back test mode 
  ARM_ETH_MODE_ISOLATE                  ///< Isolate PHY from MII interface
} ARM_ETH_MODE;

/**
\brief Ethernet link state
*/
typedef enum _ARM_ETH_LINK_STATE {
  ARM_ETH_LINK_DOWN,                    ///< Link is down
  ARM_ETH_LINK_UP                       ///< Link is up
} ARM_ETH_LINK_STATE;

/**
\brief  Ethernet link information
*/
typedef struct _ARM_ETH_LINK_INFO {
  uint8_t duplex : 1;                   ///< Duplex mode: 0= Half, 1= Full (see \ref ARM_ETH_DUPLEX)
  uint8_t speed  : 2;                   ///< Link speed: 0= 10 MBit, 1= 100 MBit, 2= 1 GBit (see \ref ARM_ETH_SPEED)
} ARM_ETH_LINK_INFO;


/**
\brief Ethernet MAC Address
*/
typedef struct _ARM_ETH_MAC_ADDR {
  uint8_t b[6];                         ///< MAC Address (6 bytes), MSB first
} ARM_ETH_MAC_ADDR;


#endif /* __DRIVER_ETH_H */
