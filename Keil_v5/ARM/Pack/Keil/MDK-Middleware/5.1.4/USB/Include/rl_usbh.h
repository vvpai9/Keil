/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Host
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    rl_usbh.h
 * Purpose: USB Host header file
 * Rev.:    V5.10
 *----------------------------------------------------------------------------*/

#ifndef __RL_USBH_H__
#define __RL_USBH_H__

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"
#include "rl_usb.h"
#include "usb_def.h"
#include "Driver_USBH.h"


//  ==== USB Host Constants and Defines ====

/// Endianess handling macros
#ifdef __BIG_ENDIAN
 #define U32_LE(v)      (uint32_t)(__rev(v))
 #define U16_LE(v)      (uint16_t)(__rev(v) >> 16)
 #define U32_BE(v)      (uint32_t)(v)
 #define U16_BE(v)      (uint16_t)(v)
#else
 #define U32_BE(v)      (uint32_t)(__rev(v))
 #define U16_BE(v)      (uint16_t)(__rev(v) >> 16)
 #define U32_LE(v)      (uint32_t)(v)
 #define U16_LE(v)      (uint16_t)(v)
#endif

/// Macro for preparing URB to send Setup Packet
#define PREPARE_SETUP_PACKET(ptr_urb, ptr_data)                                \
  ptr_urb->buf                    =  ptr_data;                                 \
  ptr_urb->len                    =  8;                                        \
  ptr_urb->packet_type            =  USB_PID_SETUP;                            \
  ptr_urb->toggle_bit             =  0;                                        \
  ptr_urb->toggle_force           =  1;

/// Macro for preparing Setup Packet
#define PREPARE_SETUP_PACKET_DATA(ptr_sp, dir, typ, rcpnt, req, val, idx, len) \
  ptr_sp->bmRequestType.Dir       =  dir;                                      \
  ptr_sp->bmRequestType.Type      =  typ;                                      \
  ptr_sp->bmRequestType.Recipient =  rcpnt;                                    \
  ptr_sp->bRequest                =  req;                                      \
  ptr_sp->wValue                  =  U16_LE(val);                              \
  ptr_sp->wIndex                  =  U16_LE(idx);                              \
  ptr_sp->wLength                 =  U16_LE(len);

/// Macro for preparing URB to start reception with Data 1 In Packet
#define PREPARE_IN_DATA1_PACKET(ptr_urb, ptr_data, data_len)                   \
  ptr_urb->buf                    =  ptr_data;                                 \
  ptr_urb->len                    =  data_len;                                 \
  ptr_urb->packet_type            =  USB_PID_IN;                               \
  ptr_urb->toggle_bit             =  1;                                        \
  ptr_urb->toggle_force           =  1;

/// Macro for preparing URB to start reception with Data alternated In Packet
#define PREPARE_IN_DATAx_PACKET(ptr_urb, ptr_data, data_len)                   \
  ptr_urb->buf                    =  ptr_data;                                 \
  ptr_urb->len                    =  data_len;                                 \
  ptr_urb->packet_type            =  USB_PID_IN;                               \
  ptr_urb->toggle_force           =  0;

/// Macro for preparing URB to start transmission with Data 1 Out Packet
#define PREPARE_OUT_DATA1_PACKET(ptr_urb, ptr_data, data_len)                  \
  ptr_urb->buf                    =  ptr_data;                                 \
  ptr_urb->len                    =  data_len;                                 \
  ptr_urb->packet_type            =  USB_PID_OUT;                              \
  ptr_urb->toggle_bit             =  1;                                        \
  ptr_urb->toggle_force           =  1;

/// Macro for preparing URB to start transmission with Data alternated Out Packet
#define PREPARE_OUT_DATAx_PACKET(ptr_urb, ptr_data, data_len)                  \
  ptr_urb->buf                    =  ptr_data;                                 \
  ptr_urb->len                    =  data_len;                                 \
  ptr_urb->packet_type            =  USB_PID_OUT;                              \
  ptr_urb->toggle_force           =  0;

/// Macro for preparing URB to do Ping
#define PREPARE_PING_PACKET(ptr_urb)                                           \
  ptr_urb->len                    =  0;                                        \
  ptr_urb->packet_type            =  USB_PID_PING;                             \
  ptr_urb->toggle_force           =  0;

/// Macro for preparing Mass Storage Control Block Wrapper (CBW)
#define PREPARE_MSC_CBW(ptr_cbw, sig, tag, len, flg, lun, cb_len, cb0, cb1, cb2, cb3, cb4, cb5, cb6, cb7, cb8, cb9, cb10, cb11, cb12, cb13, cb14, cb15)\
  ptr_cbw->dSignature             =  U32_LE(sig);                              \
  ptr_cbw->dTag                   =  U32_LE(++tag);                            \
  ptr_cbw->dDataLength            =  len;                                      \
  ptr_cbw->bmFlags                =  flg;                                      \
  ptr_cbw->bLUN                   =  lun;                                      \
  ptr_cbw->bCBLength              =  cb_len;                                   \
  ptr_cbw->CB[0]                  =  cb0;                                      \
  ptr_cbw->CB[1]                  =  cb1;                                      \
  ptr_cbw->CB[2]                  =  cb2;                                      \
  ptr_cbw->CB[3]                  =  cb3;                                      \
  ptr_cbw->CB[4]                  =  cb4;                                      \
  ptr_cbw->CB[5]                  =  cb5;                                      \
  ptr_cbw->CB[6]                  =  cb6;                                      \
  ptr_cbw->CB[7]                  =  cb7;                                      \
  ptr_cbw->CB[8]                  =  cb8;                                      \
  ptr_cbw->CB[9]                  =  cb9;                                      \
  ptr_cbw->CB[10]                 =  cb10;                                     \
  ptr_cbw->CB[11]                 =  cb11;                                     \
  ptr_cbw->CB[12]                 =  cb12;                                     \
  ptr_cbw->CB[13]                 =  cb13;                                     \
  ptr_cbw->CB[14]                 =  cb14;                                     \
  ptr_cbw->CB[15]                 =  cb15;


//  ==== USB Host Structures ====

/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif

/// Endpoint (EP) settings structure
typedef struct {
  osThreadId   thread_id;               ///< thread ID of thread that uses URB
  ARM_USBH_URB       urb;               ///< URB used for endpoint communication
  ARM_USBH_EP_HANDLE handle;            ///< handle to endpoint
  __packed struct {
    uint8_t    address           : 8;   ///< endpoint communication address
    uint8_t    speed             : 8;   ///< endpoint communication speed
  };
  USB_ENDPOINT_DESCRIPTOR descriptor;   ///< endpoint descriptor
} USBH_EP;

/// Structure containing configuration values for OHCI Compliant Hardware
typedef struct _USBH_OHCI_t {
  uint32_t    *ptr_OHCI;                ///< pointer to mem mapped reg base address
  uint32_t     port_mask;               ///< ports (bits 0..15)
  uint16_t     max_ED;                  ///< maximum Endpoint Descriptors
  uint16_t     max_TD;                  ///< maximum Transfer Descriptors
  uint16_t     max_ITD;                 ///< maximum Iso Transfer Descriptors
  uint32_t    *ptr_HCCA;                ///< pointer to HCCA memory start
  uint32_t    *ptr_ED;                  ///< pointer to ED memory start
  uint32_t    *ptr_TD;                  ///< pointer to TD memory start
  uint32_t    *ptr_ITD;                 ///< pointer to ITD memory start
  uint32_t    *ptr_TDURB;               ///< pointer to TDURB memory start
} const USBH_OHCI_t;

/// Structure containing configuration values for EHCI Compliant Hardware
typedef struct _USBH_EHCI_t {
  uint32_t    *ptr_EHCI;                ///< pointer to mem mapped reg base address
  uint32_t     port_mask;               ///< ports (bits 0..15)
  uint16_t     max_qH;                  ///< maximum queue Heads
  uint16_t     max_qTD;                 ///< maximum queue Transfer Descriptors
  uint16_t     max_iTD;                 ///< maximum iso Transfer Descriptors
  uint16_t     max_siTD;                ///< maximum split iso Transfer Descs
  uint16_t     max_FSTN;                ///< maximum peri Frame Span Trav Nodes
  uint32_t    *ptr_PFL;                 ///< pointer to Periodic Frame List mem
  uint32_t    *ptr_qH;                  ///< pointer to qH memory start
  uint32_t    *ptr_qTD;                 ///< pointer to qTD memory start
  uint32_t    *ptr_iTD;                 ///< pointer to iTD memory start
  uint32_t    *ptr_siTD;                ///< pointer to siTD memory start
  uint32_t    *ptr_FSTN;                ///< pointer to FSTN memory start
  uint32_t    *ptr_qTDURB;              ///< pointer to qTDURB memory start
} const USBH_EHCI_t;

/// Host Controller Instance (HCI) structure
typedef struct {
  uint32_t     port_con_phy;            ///< port connected map physically
  uint32_t     port_con_phy_ex;         ///< port connected map physically (previous state)
  uint32_t     port_con;                ///< port connected map in software
  uint32_t     port_act;                ///< port active map
  uint32_t     port_oc;                 ///< port overcurrent
  uint16_t     debounce_countdown;      ///< debounce countdown counter
  uint16_t     debounce_max_countdown;  ///< debounce maximum countdown counter
  uint8_t      last_dev_addr;           ///< last addressed device address
  uint32_t     dev_addr_mask[4];        ///< mask of addressed device addresses
  USBH_EP      ep0;                     ///< Control Endpoint 0
  usbStatus    last_error;              ///< last error
} USBH_HCI;

/// Device Class Instance (DCI) structure
typedef struct {
  uint8_t      class;                   ///< class
  uint8_t      subclass;                ///< subclass
  uint8_t      protocol;                ///< class protocol
  uint8_t      ctrl;                    ///< controller index
  uint8_t      port;                    ///< port index
  uint8_t      address;                 ///< device address
  uint8_t      speed;                   ///< device speed
  struct {
    uint8_t    configured        : 1;   ///< device configured status
    uint8_t    initialized       : 1;   ///< device initialized status
  };
  usbStatus    last_error;              ///< last error
} USBH_DEV;

/// Mass Storage Class (MSC) instance structure
typedef struct {
  USBH_DEV    *ptr_dev;                 ///< pointer to device structure
  USBH_EP      bulk_in_ep;              ///< bulk in endpoint
  USBH_EP      bulk_out_ep;             ///< bulk out endpoint
  uint8_t      do_ping;                 ///< do Ping on next out packet
  uint8_t      max_lun;                 ///< maximum logical units
  uint32_t     tag;                     ///< tag command/data/status protocol
  bool         media_ok;                ///< physical media ready status
} USBH_MSC;

/// Human Interface Device (HID) instance structure
typedef struct {
  USBH_DEV    *ptr_dev;                 ///< pointer to device structure
  ARM_USBH_URB int_in_urb;              ///< interrupt in URB
  ARM_USBH_URB int_out_urb;             ///< interrupt out URB
  USBH_EP      int_in_ep;               ///< interrupt in endpoint
  USBH_EP      int_out_ep;              ///< interrupt out endpoint
  uint8_t     *ptr_int_in_buf;          ///< pointer to interrupt in buffer
  uint8_t      report_desc_type;        ///< report descriptor type
  uint16_t     report_desc_len;         ///< report descriptor length
  uint8_t      report_in_data_buf[8];   ///< report input data buffer
  uint16_t     report_in_data_len;      ///< report input data bytes received
  usbHID_MouseState mouse_state;        ///< current mouse position and state
} USBH_HID;

/// Custom Class (CLS) instance structure
typedef struct {                        
  USBH_DEV    *ptr_dev;                 ///< pointer to device structure
  ///< Add further needed variables for the Custom Class implementation
} USBH_CLS;

/// Device Class Driver (DCD) structure
typedef struct {
  uint8_t      ClassID;                           ///< ID of the class according to USB ORG
                                                  ///< configuration of resources for attached device 
  int8_t     (*Configure   ) (uint8_t ctrl, uint8_t port, uint8_t speed, int8_t address, USB_CONFIGURATION_DESCRIPTOR *ptr_cfg_desc);
  usbStatus  (*Unconfigure ) (int8_t instance);   ///< un-configuration of resources for device
  usbStatus  (*Initialize  ) (int8_t instance);   ///< initialization of attached device
  usbStatus  (*Uninitialize) (int8_t instance);   ///< un-initialization of device
} USBH_DCD;

/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif


//  ==== USB Host Library Functions ====

/// \brief Send Setup Packet on Control Endpoint 0
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     ptr_data          pointer to setup packet.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_SendSetup (uint8_t ctrl, uint8_t *ptr_data);

/// \brief Send Data on Control Endpoint 0
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     ptr_data          pointer to data to be sent.
/// \param[in]     data_len          number of bytes to be sent.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_SendData (uint8_t ctrl, uint8_t *ptr_data, uint32_t data_len);

/// \brief Receive Data on Control Endpoint 0
/// \param[in]     ctrl              index of USB Host controller.
/// \param[out]    ptr_data          pointer to where data should be received.
/// \param[in]     data_len          number of bytes to be received.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_ReceiveData (uint8_t ctrl, uint8_t *ptr_data, uint32_t data_len);

/// \brief Standard Device Request - GET_STATUS
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     recipient         recipient.
/// \param[in]     index             interface or endpoint index.
/// \param[out]    ptr_stat_dat      pointer to where status data should be received.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_GetStatus (uint8_t ctrl, uint8_t recipient, uint8_t index, uint8_t *ptr_stat_dat);

/// \brief Standard Device Request - CLEAR_FEATURE
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     recipient         recipient.
/// \param[in]     index             interface or endpoint index.
/// \param[in]     feature_selector  feature selector.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_ClearFeature (uint8_t ctrl, uint8_t recipient, uint8_t index, uint8_t feature_selector);

/// \brief Standard Device Request - SET_FEATURE
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     recipient         recipient.
/// \param[in]     index             interface or endpoint index.
/// \param[in]     feature_selector  feature selector.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_SetFeature (uint8_t ctrl, uint8_t recipient, uint8_t index, uint8_t feature_selector);

/// \brief Standard Device Request - SET_ADDRESS
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     device_address    device address.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_SetAddress (uint8_t ctrl, uint8_t device_address);

/// \brief Standard Device Request - GET_DESCRIPTOR
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     recipient         recipient.
/// \param[in]     descriptor_type   descriptor type.
/// \param[in]     descriptor_index  descriptor index.
/// \param[in]     language_id       language ID.
/// \param[out]    descriptor_data   pointer to where descriptor data will be read.
/// \param[in]     descriptor_length descriptor length.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_GetDescriptor (uint8_t ctrl, uint8_t recipient, uint8_t descriptor_type, uint8_t descriptor_index, uint8_t language_id, uint8_t *descriptor_data, uint16_t descriptor_length);

/// \brief Standard Device Request - SET_DESCRIPTOR
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     recipient         recipient.
/// \param[in]     descriptor_type   descriptor type.
/// \param[in]     descriptor_index  descriptor index.
/// \param[in]     language_id       language ID.
/// \param[in]     descriptor_data   pointer to descriptor data to be written.
/// \param[in]     descriptor_length descriptor length.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_SetDescriptor (uint8_t ctrl, uint8_t recipient, uint8_t descriptor_type, uint8_t descriptor_index, uint8_t language_id, uint8_t *descriptor_data, uint16_t descriptor_length);

/// \brief Standard Device Request - GET_CONFIGURATION
/// \param[in]     ctrl              index of USB Host controller.
/// \param[out]    ptr_configuration pointer to where configuration will be read.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_GetConfiguration (uint8_t ctrl, uint8_t *ptr_configuration);

/// \brief Standard Device Request - SET_CONFIGURATION
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     configuration     configuration.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_SetConfiguration (uint8_t ctrl, uint8_t configuration);

/// \brief Standard Device Request - GET_INTERFACE
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     index             interface index.
/// \param[out]    ptr_alternate     pointer to where alternate setting data will be read.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_GetInterface (uint8_t ctrl, uint8_t  idx, uint8_t *ptr_alternate);

/// \brief Standard Device Request - SET_INTERFACE
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     index             interface index.
/// \param[in]     alternate         alternate setting.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_SetInterface (uint8_t ctrl, uint8_t index, uint8_t alternate);

/// \brief Standard Device Request - SYNC_FRAME
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     index             interface or endpoint index.
/// \param[out]    ptr_frame_number  pointer to where frame number data will be read.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_SyncFrame (uint8_t ctrl, uint8_t index, uint8_t *ptr_frame_number);

/// \brief Allocate a chunk of memory from the initialized pool to be used by USB Host controller
/// \param[in]     ctrl              index of USB Host controller.
/// \param[out]    ptr               pointer to pointer to allocated memory chunk.
/// \param[in]     size              size of memory chunk to be allocated.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_MemoryAllocate (uint8_t ctrl, uint8_t **ptr, uint32_t size);

/// \brief Release a piece of memory back to memory pool used by USB Host controller
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     ptr               pointer to allocated memory chunk to be released.
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_MemoryFree (uint8_t ctrl, uint8_t *ptr);

/// \brief Transfer URB on requested endpoint
/// \param[in]     ctrl              index of USB Host controller.
/// \param[in]     ptr_ep            pointer to endpoint used for transfer.
/// \param[in]     timeout           timeout for transfer (in ms).
/// \return                          status code that indicates the execution status of the function.
extern usbStatus USBH_Transfer (uint8_t ctrl, USBH_EP *ptr_ep, uint32_t timeout);

/// \brief Callback function called for parsing of the Human Interface Device report descriptor
/// \param[in]     instance            instance index.
/// \param[in]     ptr_hid_report_desc pointer to HID report descriptor.
/// \return                            none.
extern void USBH_HID_ParseReportDescriptor (int8_t instance, uint8_t *ptr_hid_report_desc);

/// \brief Callback function called when data is received from the Human Interface Device. 
/// \param[in]     instance          instance index.
/// \param[in]     len               length of received data.
/// \return                          none.
extern void USBH_HID_DataReceived (int8_t instance, uint16_t len);

#endif
