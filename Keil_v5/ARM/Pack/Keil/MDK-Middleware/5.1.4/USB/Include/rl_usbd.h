/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Device
 * Copyright (c) 2004-2013 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    rl_usbd.h
 * Purpose: USB Device header file
 * Rev.:    V5.10
 *----------------------------------------------------------------------------*/

#ifndef __RL_USBD_H__
#define __RL_USBD_H__

#include <stdint.h>
#include "usb_cdc.h"
#include "usb_msc.h"
#include "Driver_USBD.h"


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

//  ==== USB Device Constants and Defines ====

/// USB Custom Class API enumerated constants
typedef enum {
  usbdRequestNotProcessed = 0,              ///< request not processed
  usbdRequestOK,                            ///< request processed and OK
  usbdRequestStall,                         ///< request processed but unsupported
  usbdRequestNAK                            ///< request processed but busy
} usbdRequestStatus;

/// USB HID Class API enumerated constants
typedef enum {
  USBD_HID_REQ_EP_CTRL = 0,                 ///< request from control endpoint
  USBD_HID_REQ_EP_INT,                      ///< request from interrupt endpoint
  USBD_HID_REQ_PERIOD_UPDATE                ///< request from periodic update
} USBD_HID_REQ_t;


//  ==== USB Device Structures ====

/// Structure used for Control Endpoint 0 communication
typedef struct _usbd_ep_data_t {
  uint8_t              *data;               ///< data buffer for send or receive
  uint16_t              cnt;                ///< number of bytes in data buffer (to send or received)
} usbd_ep_data_t;

/// Structure containing device information
typedef struct _usbd_data_t {
  uint16_t              device_status;      ///< device status (remote wakeup, self powered)
  uint8_t               device_address;     ///< device address on the bus
  uint8_t               configuration;      ///< active configuration
  uint8_t               interface;          ///< active interface
  uint32_t              endpoint_mask;      ///< mask containing active endpoints
  uint32_t              endpoint_halt;      ///< mask containing halted endpoints 
  uint32_t              endpoint_stall;     ///< mask containing stalled endpoints
  uint8_t               num_interfaces;     ///< number of available interfaces
  union {
    uint8_t             flags;              ///< status flags
    struct {
      uint8_t           high_speed : 1;     ///< information if device is in high speed
      uint8_t           zlp        : 1;     ///< zero length packet flag
      uint8_t           ext_handle : 1;     ///< externally habdled request
    };
  };

  usbd_ep_data_t        ep0_data;           ///< Control Endpoint 0 structure
  USB_SETUP_PACKET      setup_packet;       ///< Setup Packet structure
  uint8_t              *buf;                ///< Buffer for in/out data
  int32_t               len;                ///< Length for in/out data
  int32_t               len_cur;            ///< Currently transferred bytes for in/out data
} usbd_data_t;

/// Structure containing controller instance information for stack
typedef struct _usbd_dev_t {
  ARM_DRIVER_USBD      *driver;             ///< pointer to driver
  uint8_t              *alt_setting;        ///< pointer to alternate settings
  uint8_t              *ep0_buf;            ///< pointer to Control Endpoint 0 buffer 
  usbd_data_t          *data_ptr;           ///< pointer to structure containing device information
  uint8_t               bmattributes;       ///< bmAttributes configuration setting
  uint8_t               hs;                 ///< high-speed capability setting
  uint16_t              if_num;             ///< number of interfaces
  uint8_t               ep_num;             ///< number of endpoints
  uint8_t               max_packet0;        ///< maximum packet size for Control Endpoint 0
} const usbd_dev_t;

/// Structure containing configuration values for Custom Class device instance
typedef struct _usbd_custom_class_t {
  uint8_t               dev_num;            ///< device instance configuration setting
  uint8_t               if0_num;            ///< interface 0 number
  uint8_t               if1_num;            ///< interface 1 number
  uint8_t               if2_num;            ///< interface 2 number
  uint8_t               if3_num;            ///< interface 3 number
  uint8_t               ep_msk;             ///< mask of used endpoints
  uint8_t               if0_ep_bulk_out;    ///< interface 0 bulk out endpoint number
  uint8_t               if0_ep_bulk_in;     ///< interface 0 bulk in endpoint number
  uint8_t               if0_ep_int_out;     ///< interface 0 interrupt out endpoint number
  uint8_t               if0_ep_int_in;      ///< interface 0 interrupt in endpoint number
  uint8_t               if0_ep_iso_out;     ///< interface 0 isochronous out endpoint number
  uint8_t               if0_ep_iso_in;      ///< interface 0 isochronous in endpoint number
  uint8_t               if1_ep_bulk_out;    ///< interface 1 bulk out endpoint number
  uint8_t               if1_ep_bulk_in;     ///< interface 1 bulk in endpoint number
  uint8_t               if1_ep_int_out;     ///< interface 1 interrupt out endpoint number
  uint8_t               if1_ep_int_in;      ///< interface 1 interrupt in endpoint number
  uint8_t               if1_ep_iso_out;     ///< interface 1 isochronous out endpoint number
  uint8_t               if1_ep_iso_in;      ///< interface 1 isochronous in endpoint number
  uint8_t               if2_ep_bulk_out;    ///< interface 2 bulk out endpoint number
  uint8_t               if2_ep_bulk_in;     ///< interface 2 bulk in endpoint number
  uint8_t               if2_ep_int_out;     ///< interface 2 interrupt out endpoint number
  uint8_t               if2_ep_int_in;      ///< interface 2 interrupt in endpoint number
  uint8_t               if2_ep_iso_out;     ///< interface 2 isochronous out endpoint number
  uint8_t               if2_ep_iso_in;      ///< interface 2 isochronous in endpoint number
  uint8_t               if3_ep_bulk_out;    ///< interface 3 bulk out endpoint number
  uint8_t               if3_ep_bulk_in;     ///< interface 3 bulk in endpoint number
  uint8_t               if3_ep_int_out;     ///< interface 3 interrupt out endpoint number
  uint8_t               if3_ep_int_in;      ///< interface 3 interrupt in endpoint number
  uint8_t               if3_ep_iso_out;     ///< interface 3 isochronous out endpoint number
  uint8_t               if3_ep_iso_in;      ///< interface 3 isochronous in endpoint number
} const usbd_custom_class_t;

/// Structure containing runtime values for ADC device instance
typedef struct _usbd_adc_data_t {
  uint16_t              vol_cur;            ///< volume current value
  uint16_t              vol_min;            ///< volume minimum value
  uint16_t              vol_max;            ///< volume maximum value
  uint16_t              vol_res;            ///< volume resolution
  uint8_t               mute;               ///< mute state
  uint32_t              volume;             ///< volume level
  uint16_t              data_out;           ///< data out index
  uint16_t              data_in;            ///< data in index
  uint8_t               data_run;           ///< data stream run state
} usbd_adc_data_t;

/// Structure containing configuration values for ADC device instance
typedef struct _usbd_adc_t {
  int16_t              *data_buf;           ///< data buffer for audio samples
  usbd_adc_data_t      *data_ptr;           ///< pointer to structure containing runtime values
  uint8_t               dev_num;            ///< device instance configuration setting
  uint8_t               cif_num;            ///< audio control interface number
  uint8_t               sif_num;            ///< audio streaming (zero bandwidth) interface number (operational is next)
  uint8_t               ep_iso_out;         ///< isochronous out endpoint number
  uint32_t              cfg_data_freq;      ///< data frequency configuration setting
  uint32_t              cfg_p_s;            ///< sample packet size
  uint32_t              cfg_p_c;            ///< sample packet count
  uint32_t              cfg_b_s;            ///< sample resolution configuration settings
} const usbd_adc_t;

/// Structure containing runtime values for CDC device instance
typedef struct _usbd_cdc_data_t {
  struct {
    uint32_t            data_send_active    : 1;      ///< flag active while data is being sent
    uint32_t            data_send_zlp       : 1;      ///< flag active when zero length packet needs to be sent
    uint32_t            data_receive_active : 1;      ///< flag active while data is being received
    uint32_t            notify_active       : 1;      ///< flag active while notification is being sent
  };
  uint8_t              *ptr_data_to_send;             ///< pointer to send intermediate buffer to data to be sent
  uint8_t              *ptr_data_sent;                ///< pointer to send intermediate buffer to data already sent
  uint8_t              *ptr_data_received;            ///< pointer to the receive intermediate buffer to the received unread data
  uint8_t              *ptr_data_read;                ///< pointer to the receive intermediate buffer to the received read data
  int32_t               data_to_send_wr;              ///< number of bytes written to the send intermediate buffer
  int32_t               data_to_send_rd;              ///< number of bytes read from the send intermediate buffer
  uint16_t              control_line_state;           ///< control line state settings bitmap (bit 0: DTR state, bit 1: - RTS state)
  CDC_LINE_CODING       line_coding;                  ///< communication settings */
} usbd_cdc_data_t;

/// Structure containing configuration values for CDC device instance
typedef struct _usbd_cdc_t {
  uint8_t              *send_buf;                     ///< send data buffer
  uint8_t              *receive_buf;                  ///< receive data buffer
  uint8_t              *notify_buf;                   ///< notify data buffer
  usbd_cdc_data_t      *data_ptr;                     ///< pointer to structure containing runtime values
  uint8_t               dev_num;                      ///< device instance configuration setting
  uint8_t               cif_num;                      ///< communication class interface number
  uint8_t               dif_num;                      ///< data class interface number
  uint8_t               ep_int_in;                    ///< interrupt in endpoint number
  uint8_t               ep_bulk_in;                   ///< bulk in endpoint number
  uint8_t               ep_bulk_out;                  ///< bulk out endpoint number
  uint16_t              send_buf_sz;                  ///< maximum size of send buffer
  uint16_t              receive_buf_sz;               ///< maximum size of receive buffer
  uint16_t              max_packet_size [2];          ///< maximum packet size for interrupt endpoint (for LS/FS and HS)
  uint16_t              max_packet_size1[2];          ///< maximum packet size for bulk endpoints (for LS/FS and HS)
} const usbd_cdc_t;

/// Structure containing runtime values for HID device instance
typedef struct _usbd_hid_data_t {
  uint8_t               protocol;                           ///< active protocol
  bool                  data_out_async_req;                 ///< request to asynchronously send data flag
  uint32_t              data_out_update_req_mask;           ///< request to update send data flag
  uint8_t              *ptr_data_out;                       ///< send data buffer
  volatile uint16_t     data_out_to_send_len;               ///< length of data to be sent
  uint16_t              data_out_sent_len;                  ///< length of data already sent
  bool                  data_out_end_with_short_packet;     ///< data send ended with short packet flag 
  uint8_t              *ptr_data_in;                        ///< receive data buffer
  uint16_t              data_in_rece_len;                   ///< length of received data
  uint8_t              *ptr_data_feat;                      ///< feature data buffer
  uint16_t              data_feat_rece_len;                 ///< length of received feature data
  uint16_t              polling_count;                      ///< polling count used for data update
} usbd_hid_data_t;

/// Structure containing configuration values for HID device instance
typedef struct _usbd_hid_t {
  uint16_t             *idle_count;         ///< pointer to idle count data for each report
  uint16_t             *idle_reload;        ///< pointer to idle reload data for each report
  uint8_t              *idle_set;           ///< pointer to idle set data (using SetIdle) for each report
  uint8_t              *in_report;          ///< input report data buffer for each report
  uint8_t              *out_report;         ///< output report data buffer for each report
  uint8_t              *feat_report;        ///< feature report data buffer for each report
  usbd_hid_data_t      *data_ptr;           ///< pointer to structure containing runtime values for each report
  uint8_t               dev_num;            ///< device instance configuration setting
  uint8_t               if_num;             ///< interface number
  uint8_t               ep_int_in;          ///< interrupt in endpoint number 
  uint8_t               ep_int_out;         ///< interrupt out endpoint number (0 if not used)
  uint16_t              interval       [2]; ///< polling interval configuration setting (for LS/FS and HS)
  uint16_t              max_packet_size[2]; ///< maximum packet size interrupt endpoints (for LS/FS and HS)
  uint8_t               in_report_num;      ///< number of input reports
  uint8_t               out_report_num;     ///< number of output reports
  uint16_t              in_report_max_sz;   ///< maximum input report size
  uint16_t              out_report_max_sz;  ///< maximum output report size
  uint16_t              feat_report_max_sz; ///< maximum feature report size
} const usbd_hid_t;

/// Structure containing runtime values for MSC device instance
typedef struct _usbd_msc_data_t {
  MSC_CBW               cbw;                ///< command block wrapper
  MSC_CSW               csw;                ///< command status wrapper
  uint32_t              block;              ///< read/write operation block
  uint32_t              offset;             ///< read/write operation offset
  uint32_t              length;             ///< read write operation remaining length
  bool                  mem_ok;             ///< memory verify status
  uint8_t               bulk_stage;         ///< bulk stage
  uint32_t              bulk_len;           ///< bulk in/out length
  uint32_t              bulk_req_len;       ///< bulk in/out requested length
  bool                  media_ready;        ///< media ready flag
  bool                  read_only;          ///< media read only flag
  uint32_t              memory_size;        ///< media memory size
  uint32_t              block_size;         ///< media block size
  uint32_t              block_group;        ///< blocks available size in cache
  uint32_t              block_count;        ///< media total number of blocks
  uint8_t              *block_buf;          ///< data buffer for media data read/write 
  bool                  media_ready_ex;     ///< previous state of media ready flag
} usbd_msc_data_t;

/// Structure containing configuration values for MSC device instance
typedef struct _usbd_msc_t {
  uint8_t              *bulk_buf;           ///< data buffer for bulk transfers
  usbd_msc_data_t      *data_ptr;           ///< pointer to structure containing runtime values
  uint8_t               dev_num;            ///< device instance configuration setting
  uint8_t               if_num;             ///< interface number
  uint8_t               ep_bulk_in;         ///< bulk in endpoint number
  uint8_t               ep_bulk_out;        ///< bulk out endpoint number
  uint32_t              bulk_buf_sz;        ///< size of bulk buffer
  uint16_t              max_packet_size[2]; ///< maximum packet size for bulk endpoints (for LS/FS and HS)
  uint8_t              *inquiry_data;       ///< data returned upon SCSI Inquiry request
} const usbd_msc_t;

/// Structure containing values for HID descriptor
typedef struct _usbd_hid_desc_t {
  uint8_t              *report_descriptor;            ///< report descriptor
  uint16_t              report_descriptor_size;       ///< report descriptor size
  uint16_t              hid_descriptor_offset;        ///< HID descriptor offset in device descriptor
} usbd_hid_desc_t;

/// Structure containing all descriptors (except report descriptor)
typedef struct _usbd_desc_t {
  uint8_t              *ep0_descriptor;                     ///< Control Endpoint 0 descriptor
  uint8_t              *device_descriptor;                  ///< device descriptor
  uint8_t              *device_qualifier_fs;                ///< device qualifier for low/full-speed
  uint8_t              *device_qualifier_hs;                ///< device qualifier for high-speed
  uint8_t              *config_descriptor_fs;               ///< configuration descriptor for low/full-speed
  uint8_t              *config_descriptor_hs;               ///< configuration descriptor for high-speed
  uint8_t              *other_speed_config_descriptor_fs;   ///< other speed configuration descriptor for low/full-speed
  uint8_t              *other_speed_config_descriptor_hs;   ///< other speed configuration descriptor for high-speed
  uint8_t              *string_descriptor;                  ///< string descriptors
} usbd_desc_t;

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

#endif
