/* ----------------------------------------------------------------------
 * Copyright (C) 2013 ARM Limited. All rights reserved.
 *  
 * $Date:        12. Sept 2013
 * $Revision:    V1.10
 *  
 * Project:      Ethernet MAC Driver for Middleware
 * -------------------------------------------------------------------- */

/* History:
 *  Version 1.10
 *    Namespace prefix ARM_ added
 *  Version 1.01
 *    Renamed capabilities items for checksum offload
 *  Version 1.00
 *    Initial release
 */ 

#ifndef __DRIVER_ETH_MAC_H
#define __DRIVER_ETH_MAC_H

#include "Driver_ETH.h"

#define ARM_ETH_MAC_API_VERSION ARM_DRV_VERSION_MAJOR_MINOR(1,10) /* API version */


#define _ARM_Driver_ETH_MAC_(n)      Driver_ETH_MAC##n
#define  ARM_Driver_ETH_MAC_(n) _ARM_Driver_ETH_MAC_(n)


/**
\brief Ethernet MAC Event
*/
typedef enum _ARM_ETH_MAC_EVENT {
  ARM_ETH_MAC_EVENT_RX_FRAME,           ///< Packet Received
} ARM_ETH_MAC_EVENT;


// Function documentation
/**
  \fn          ARM_DRV_VERSION ARM_ETH_MAC_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRV_VERSION
*/
/**
  \fn          ARM_ETH_MAC_CAPABILITIES ARM_ETH_MAC_GetCapabilities (void)
  \brief       Get driver capabilities.
  \return      \ref ARM_ETH_MAC_CAPABILITIES
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_Initialize (ARM_ETH_MAC_SignalEvent_t cb_event,
                                                      ARM_ETH_MAC_ADDR         *mac_address)
  \brief       Initialize Ethernet MAC Device.
  \param[in]   cb_event       Pointer to \ref ARM_ETH_MAC_SignalEvent
  \param[in,out] mac_address  Pointer to MAC address
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_Uninitialize (void)
  \brief       De-initialize Ethernet MAC Device.
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_PowerControl (ARM_POWER_STATE state)
  \brief       Control Ethernet MAC Device Power.
  \param[in]   state  Power state
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_SetMulticastAddr (uint32_t          num_addr,
                                                            ARM_ETH_MAC_ADDR *ptr_addr)
  \brief       Configure Ethernet multicast address filtering.
  \param[in]   num_addr   Number of multicast addresses to configure
  \param[in]   ptr_addr   Pointer to multicast addresses
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_SetMode (ARM_ETH_DUPLEX duplex, 
                                                   ARM_ETH_SPEED  speed)
  \brief       Set the Ethernet MAC speed and duplex mode.
  \param[in]   duplex  \ref ARM_ETH_DUPLEX
  \param[in]   speed   \ref ARM_ETH_SPEED
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_EnableTx (bool enable)
  \brief       Enable the Ethernet MAC transmit engine.
  \param[in]   enable  Action
               - \b true Enable
               - \b false Disable
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_EnableRx (bool enable)
  \brief       Enable the Ethernet MAC receive engine.
  \param[in]   enable  Action
               - \b true Enable
               - \b false Disable
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_SendFrame (uint8_t *buf, uint32_t len)
  \brief       Send Ethernet frame.
  \param[in]   buf  Pointer to frame buffer with data to send
  \param[in]   len  Frame buffer length in bytes
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          int32_t ARM_ETH_MAC_ReadFrame (uint8_t *buf, uint32_t len)
  \brief       Read data of received Ethernet frame.
  \param[in]   buf  Pointer to frame buffer for data to read into
  \param[in]   len  Frame buffer length in bytes
  \return      number of data bytes read or execution status
                 - value >= 0: number of data bytes read
                 - value < 0: error occurred, -value is execution status as defined with \ref ARM_ETH_STATUS 
*/
/**
  \fn          int32_t ARM_ETH_MAC_GetRxFrameSize (void)
  \brief       Get size of received Ethernet frame.
  \return      number of bytes in received frame or execution status
                 - value >= 0: number of bytes in received frame
                 - value < 0: error occurred, -value is execution status as defined with \ref ARM_ETH_STATUS 
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_PHY_Read (uint8_t phy_addr, uint8_t reg_addr, uint16_t *data)
  \brief       Read Ethernet PHY Register through Management Interface.
  \param[in]   phy_addr  5-bit device address
  \param[in]   reg_addr  5-bit register address
  \param[out]  data      Pointer where the result is written to
  \return      execution status \ref ARM_ETH_STATUS
*/
/**
  \fn          ARM_ETH_STATUS ARM_ETH_MAC_PHY_Write (uint8_t phy_addr, uint8_t reg_addr, uint16_t data)
  \brief       Write Ethernet PHY Register through Management Interface.
  \param[in]   phy_addr  5-bit device address
  \param[in]   reg_addr  5-bit register address
  \param[in]   data      16-bit data to write
  \return      execution status \ref ARM_ETH_STATUS
*/

/**
  \fn          void ARM_ETH_MAC_SignalEvent (ARM_ETH_MAC_EVENT event)
  \brief       Callback function that signals a Ethernet Event.
  \param[in]   event \ref ARM_ETH_MAC_EVENT
  \return      none
*/

typedef void (*ARM_ETH_MAC_SignalEvent_t) (ARM_ETH_MAC_EVENT event);  ///< Pointer to \ref ARM_ETH_MAC_SignalEvent : Signal Ethernet Event.


/**
\brief Ethernet MAC Capabilities
*/
typedef struct _ARM_ETH_MAC_CAPABILITIES {
  uint32_t rx_checksum_offload_ip   :  1;       ///< 1 = Receive IP header checksum verified
  uint32_t rx_checksum_offload_udp  :  1;       ///< 1 = Receive UDP payload checksum verified
  uint32_t rx_checksum_offload_tcp  :  1;       ///< 1 = Receive TCP payload checksum verified
  uint32_t rx_checksum_offload_icmp :  1;       ///< 1 = Receive ICMP payload checksum verified
  uint32_t tx_checksum_offload_ip   :  1;       ///< 1 = Transmit IP header checksum generated
  uint32_t tx_checksum_offload_udp  :  1;       ///< 1 = Transmit UDP payload checksum generated
  uint32_t tx_checksum_offload_tcp  :  1;       ///< 1 = Transmit TCP payload checksum generated
  uint32_t tx_checksum_offload_icmp :  1;       ///< 1 = Transmit ICMP payload checksum generated
  uint32_t media_interface          :  2;       ///< Ethernet Media Interface type (see \ref ARM_ETH_INTERFACE)
  uint32_t mac_address              :  1;       ///< 1 = driver provides serialized MAC address
  uint32_t event_rx_frame           :  1;       ///< 1 = callback event \ref ARM_ETH_MAC_EVENT_RX_FRAME generated
  uint32_t reserved                 : 20;       ///< reserved for future extensions
} ARM_ETH_MAC_CAPABILITIES;


/**
\brief  Access structure of the Ethernet MAC Driver
*/
typedef struct _ARM_DRIVER_ETH_MAC {
  ARM_DRV_VERSION          (*GetVersion)      (void);                                                ///< Pointer to \ref ARM_ETH_MAC_GetVersion : Get driver version.
  ARM_ETH_MAC_CAPABILITIES (*GetCapabilities) (void);                                                ///< Pointer to \ref ARM_ETH_MAC_GetCapabilities : Get driver capabilities.
  ARM_ETH_STATUS           (*Initialize)      (ARM_ETH_MAC_SignalEvent_t cb_event,
                                               ARM_ETH_MAC_ADDR         *mac_address);               ///< Pointer to \ref ARM_ETH_MAC_Initialize : Initialize Ethernet MAC Device.
  ARM_ETH_STATUS           (*Uninitialize)    (void);                                                ///< Pointer to \ref ARM_ETH_MAC_Uninitialize : De-initialize Ethernet MAC Device.
  ARM_ETH_STATUS           (*PowerControl)    (ARM_POWER_STATE state);                               ///< Pointer to \ref ARM_ETH_MAC_PowerControl : Control Ethernet MAC Device Power.
  ARM_ETH_STATUS           (*SetMultiCastAddr)(uint32_t num_addr, ARM_ETH_MAC_ADDR *ptr_addr);       ///< Pointer to \ref ARM_ETH_MAC_SetMulticastAddr : Configure Ethernet multicast address filtering.
  ARM_ETH_STATUS           (*SetMode)         (ARM_ETH_DUPLEX duplex, ARM_ETH_SPEED speed);          ///< Pointer to \ref ARM_ETH_MAC_SetMode : Set the Ethernet MAC speed and duplex mode.
  ARM_ETH_STATUS           (*EnableTx)        (bool enable);                                         ///< Pointer to \ref ARM_ETH_MAC_EnableTx : Enable the Ethernet MAC transmit engine.
  ARM_ETH_STATUS           (*EnableRx)        (bool enable);                                         ///< Pointer to \ref ARM_ETH_MAC_EnableRx : Enable the Ethernet MAC receive engine.
  ARM_ETH_STATUS           (*SendFrame)       (uint8_t *buf, uint32_t len);                          ///< Pointer to \ref ARM_ETH_MAC_SendFrame : Send Ethernet frame.
  int32_t                  (*ReadFrame)       (uint8_t *buf, uint32_t len);                          ///< Pointer to \ref ARM_ETH_MAC_ReadFrame : Read data of received Ethernet frame.
  int32_t                  (*GetRxFrameSize)  (void);                                                ///< Pointer to \ref ARM_ETH_MAC_GetRxFrameSize : Get size of received Ethernet frame.
  ARM_ETH_STATUS           (*PHY_Read)        (uint8_t phy_addr, uint8_t reg_addr, uint16_t *data);  ///< Pointer to \ref ARM_ETH_MAC_PHY_Read : Read Ethernet PHY Register through Management Interface.
  ARM_ETH_STATUS           (*PHY_Write)       (uint8_t phy_addr, uint8_t reg_addr, uint16_t  data);  ///< Pointer to \ref ARM_ETH_MAC_PHY_Write : Write Ethernet PHY Register through Management Interface.
} const ARM_DRIVER_ETH_MAC;

#endif /* __DRIVER_ETH_MAC_H */
