/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Device
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    USBD_User_CustomClass_%Instance%.c
 * Purpose: USB Device Custom Class User module
 * Rev.:    V5.10
 *----------------------------------------------------------------------------*/
/**
 * \addtogroup usbd_custom_classFunctions
 *
 */


//! [code_USBD_User_CustomClass]

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "rl_usbd.h"

// \brief Called during USBD_Initialize to initialize the USB Custom class Device
void USBD_CustomClass%Instance%_Initialize (void) {
  // Handle Custom Class Initialization
}

// \brief Called during USBD_Uninitialize to un-initialize the USB Custom class Device
void USBD_CustomClass%Instance%_Uninitialize (void) {
  // Handle Custom Class Uninitialization
}

// \brief Custom Class Reset Event handling
void USBD_CustomClass%Instance%_EventReset (void) {
  // Handle USB Bus Reset Event
}

// \brief Custom Class Endpoint Start Event handling
// \param[in]     ep_addr       endpoint address.
void USBD_CustomClass%Instance%_EventEndpointStart (uint8_t ep_addr) {
  // Start communication on Endpoint
}

// \brief Custom Class Endpoint Stop Event handling
// \param[in]     ep_addr       endpoint address.
void USBD_CustomClass%Instance%_EventEndpointStop (uint8_t ep_addr) {
  // Handle Endpoint communication stopped
}

// \brief Callback function called when a SETUP PACKET was received on Control Endpoint 0
// \param[in]     setup_packet            pointer to received setup packet.
// \param[out]    buf                     pointer to data buffer used for data stage requested by setup packet.
// \param[out]    len                     pointer to number of data bytes in data stage requested by setup packet.
// \return        usbdRequestStatus       enumerator value indicating the function execution status
// \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
// \return        usbdRequestOK:          request was processed successfully (send Zero-Length Packet if no data stage)
// \return        usbdRequestStall:       request was processed but is not supported (stall Endpoint 0)
usbdRequestStatus USBD_CustomClass%Instance%_Endpoint0_SetupPacketReceived (const USB_SETUP_PACKET *setup_packet, uint8_t **buf, int32_t *len) {

  switch (setup_packet->bmRequestType.Type & 3) {
    case USB_REQUEST_STANDARD:
      break;
    case USB_REQUEST_CLASS:
      switch (setup_packet->bmRequestType.Recipient) {
        case USB_REQUEST_TO_DEVICE:
          break;
        case USB_REQUEST_TO_INTERFACE:
          break;
        case USB_REQUEST_TO_ENDPOINT:
          break;
        default:
          break;
      }
      break;
    case USB_REQUEST_VENDOR:
      break;
    case USB_REQUEST_RESERVED:
      break;
  }

  return usbdRequestNotProcessed;
}

// \brief Callback function called when a SETUP PACKET was processed by USB library
// \param[in]     setup_packet            pointer to processed setup packet.
void USBD_CustomClass%Instance%_Endpoint0_SetupPacketProcessed (const USB_SETUP_PACKET *setup_packet) {
  switch (setup_packet->bmRequestType.Type & 3) {
    case USB_REQUEST_STANDARD:
      break;
    case USB_REQUEST_CLASS:
      switch (setup_packet->bmRequestType.Recipient) {
        case USB_REQUEST_TO_DEVICE:
          break;
        case USB_REQUEST_TO_INTERFACE:
          break;
        case USB_REQUEST_TO_ENDPOINT:
          break;
        default:
          break;
      }
      break;
    case USB_REQUEST_VENDOR:
      break;
    case USB_REQUEST_RESERVED:
      break;
  }
}

// \brief Callback function called when OUT DATA was received on Control Endpoint 0
// \param[in]     len                     number of received data bytes.
// \return        usbdRequestStatus       enumerator value indicating the function execution status
// \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
// \return        usbdRequestOK:          request was processed successfully (send Zero-Length Packet)
// \return        usbdRequestStall:       request was processed but is not supported (stall Endpoint 0)
// \return        usbdRequestNAK:         request was processed but the device is busy (return NAK)
usbdRequestStatus USBD_CustomClass%Instance%_Endpoint0_OutDataReceived (int32_t len) {
  return usbdRequestNotProcessed;
}

// \brief Callback function called when IN DATA was sent on Control Endpoint 0
// \param[in]     len                     number of sent data bytes.
// \return        usbdRequestStatus       enumerator value indicating the function execution status
// \return        usbdRequestNotProcessed:request was not processed; processing will be done by USB library
// \return        usbdRequestOK:          request was processed successfully (return ACK)
// \return        usbdRequestStall:       request was processed but is not supported (stall Endpoint 0)
// \return        usbdRequestNAK:         request was processed but the device is busy (return NAK)
usbdRequestStatus USBD_CustomClass%Instance%_Endpoint0_InDataSent (int32_t len) {
  return usbdRequestNotProcessed;
}

// \brief Callback function called when DATA was sent or received on Endpoint n
// \param[in]     event                   event on Endpoint:
//                                          - ARM_USBD_EP_EVENT_OUT = data OUT received
//                                          - ARM_USBD_EP_EVENT_IN  = data IN  sent
void USBD_CustomClass%Instance%_Endpoint1_Event  (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 1 events
};
void USBD_CustomClass%Instance%_Endpoint2_Event  (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 2 events
};
void USBD_CustomClass%Instance%_Endpoint3_Event  (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 3 events
};
void USBD_CustomClass%Instance%_Endpoint4_Event  (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 4 events
};
void USBD_CustomClass%Instance%_Endpoint5_Event  (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 5 events
};
void USBD_CustomClass%Instance%_Endpoint6_Event  (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 6 events
};
void USBD_CustomClass%Instance%_Endpoint7_Event  (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 7 events
};
void USBD_CustomClass%Instance%_Endpoint8_Event  (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 8 events
};
void USBD_CustomClass%Instance%_Endpoint9_Event  (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 9 events
};
void USBD_CustomClass%Instance%_Endpoint10_Event (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 10 events
};
void USBD_CustomClass%Instance%_Endpoint11_Event (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 11 events
};
void USBD_CustomClass%Instance%_Endpoint12_Event (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 12 events
};
void USBD_CustomClass%Instance%_Endpoint13_Event (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 13 events
};
void USBD_CustomClass%Instance%_Endpoint14_Event (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 14 events
};
void USBD_CustomClass%Instance%_Endpoint15_Event (ARM_USBD_EP_EVENT event) {
  // Handle Endpoint 15 events
};

//! [code_USBD_User_CustomClass]
